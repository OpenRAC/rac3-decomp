#!/usr/bin/env python3
"""build.py: the Makefile's `check` target in Python, for Linux and macOS.

On Windows, use the Makefile (SN's make.exe). This script runs the same steps
for systems where make.exe's cmd.exe syntax doesn't work, running the Windows
toolchain through wibo (https://github.com/decompals/wibo):

  1. assemble the raw header blobs and the data segments (bin/ee-as.exe):
     every build/.../*.s.o object the target's linker script names
  2. build each code section's sources with tools/build_text.py (per-file,
     per-function flags)
  3. link with the target's linker script, objcopy to a flat binary (a level first gets
     the values of the names its C uses, tools/level_symbols.py)
  4. tools/check_match.py: prints MATCH or the first differing offsets

    python3 tools/build.py --toolchain ~/sn --runner ~/bin/wibo
    python3 tools/build.py --target boot_elf --toolchain ~/sn --runner ~/bin/wibo
    python3 tools/build.py --target all --toolchain ~/sn --runner ~/bin/wibo

The toolchain folder must have the Windows layout (bin/ee-gcc2953.exe,
bin/ee-as.exe, bin/ee-ld.exe, bin/ee-objcopy.exe, ee/bin/Ps2EeAs.exe).
build_text.py derives the toolchain root from the compiler path, so this
script writes small wrapper scripts into build/wrap/ that call wibo.

Unchanged work is reused (since 2026-11-28, tools/objcache.py): the objects of steps 1 and 2 are
kept in build/objcache/ under a key of everything that can change them, so a build after a
one-file change compiles and assembles only what that change reaches; linking, flattening and the
check always run. --no-cache (or UYA_NO_CACHE=1) builds everything again; the output is byte for
byte the same either way (docs/build/incremental.md).
"""
import argparse, os, re, stat, subprocess, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))
import objcache  # noqa: E402
import targets  # noqa: E402
ASFLAGS = ["-I", "include", "-EL", "-mips3", "-mcpu=5900", "-mabi=eabi"]


def run(cmd, **kw):
    print("+", " ".join(cmd))
    p = subprocess.run(cmd, cwd=ROOT, **kw)
    if p.returncode:
        sys.exit(f"failed: {' '.join(cmd)}")


def assemble(cache, cmd, obj, src, tools):
    """Assemble SRC into OBJ with CMD (ee-as.exe), or put back the object an earlier run made
    from the same inputs (tools/objcache.py): the command, the .s file's bytes and every file its
    `.include`s reach, the toolchain TOOLS (folders and programs) and the tools of this build."""
    key = None
    if cache.enabled:
        key = objcache.Key("ee-as").common([os.path.abspath(__file__)])
        for t in tools:
            key.tree("tool", t)
        key.text("command", cmd)
        key.file("source", os.path.join(ROOT, src))
        with open(os.path.join(ROOT, src), "rb") as f:
            data = f.read()
        if not objcache.add_asm_includes(key, data, os.path.dirname(os.path.join(ROOT, src))):
            key = None
    if key is not None and cache.fetch(key.hexdigest(), os.path.join(ROOT, obj)):
        return
    run(cmd)
    if key is not None and not key.changed():
        cache.store(key.hexdigest(), os.path.join(ROOT, obj))


def main():
    t = targets.from_argv(allow_all=True)
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--toolchain", default=os.environ.get("UYA_TOOLCHAIN"), required="UYA_TOOLCHAIN" not in os.environ)
    ap.add_argument("--runner", default=os.environ.get("UYA_RUNNER", "wibo"))
    ap.add_argument("--ee29", default=os.environ.get("UYA_EE29"),
                    help="Sony ee-gcc 2.9-ee-991111 folder for @ee29 ranges (tools/ee29.py)")
    ap.add_argument("--ee296", default=os.environ.get("UYA_EE296"),
                    help="Sony ee-gcc 2.96-ee-001003-1 folder for @ee296 ranges (tools/ee296.py)")
    ap.add_argument("--eeas", default=os.environ.get("UYA_EEAS"),
                    help="Sony's ee-as 2.10-ee-001003-1 program for @eeas ranges (tools/eeas.py)")
    ap.add_argument("-j", "--jobs", type=int, default=int(os.environ.get("UYA_JOBS", "1")),
                    help="source files compiled at a time (default: env UYA_JOBS, else 1)")
    ap.add_argument("--no-cache", action="store_true",
                    help="compile and assemble everything again, reusing nothing (tools/objcache.py); "
                         "also env UYA_NO_CACHE=1")
    args = ap.parse_args()
    tc = os.path.abspath(os.path.expanduser(args.toolchain))
    runner = args.runner
    exe = lambda name: [runner, os.path.join(tc, "bin", name)]
    cache = objcache.Cache(enabled=not args.no_cache)
    as_tools = [tc, objcache.which(runner)]

    build = os.path.join(ROOT, t.build_dir)
    os.makedirs(os.path.join(build, "src"), exist_ok=True)

    # 1. the asm-built objects are whatever the linker script links:
    #    <build_dir>/<path of the .s>.o
    script = open(t.path("ld")).read()
    prefix = t.build_dir.replace("\\", "/").rstrip("/") + "/"
    for obj in dict.fromkeys(re.findall(r"(%s(?:asm/\S+?\.s)\.o)" % re.escape(prefix), script)):
        src = obj[len(prefix):-2]
        os.makedirs(os.path.join(ROOT, os.path.dirname(obj)), exist_ok=True)
        assemble(cache, exe("ee-as.exe") + ASFLAGS + ["-o", obj, src], obj, src, as_tools)

    # Wrappers live inside a fake toolchain tree (wrap/bin/...) with ee/ linked
    # to the real one, so build_text.py's "<root>/ee/bin/Ps2Ee" still resolves.
    wrap = os.path.join(ROOT, "build", "wrap")
    os.makedirs(os.path.join(wrap, "bin"), exist_ok=True)
    ee_link = os.path.join(wrap, "ee")
    if not os.path.exists(ee_link):
        try:
            os.symlink(os.path.join(tc, "ee"), ee_link)
        except FileExistsError:      # another build (tools/build_levels.py runs several) made it
            pass
    wrappers = {}
    for name, target in (("cc", "ee-gcc2953.exe"), ("ld", "ee-ld.exe")):
        path = os.path.join(wrap, "bin", name)
        tmp = "%s.%d" % (path, os.getpid())
        with open(tmp, "w") as f:
            f.write(f'#!/bin/sh\nexec "{runner}" "{os.path.join(tc, "bin", target)}" "$@"\n')
        os.chmod(tmp, os.stat(tmp).st_mode | stat.S_IEXEC)
        os.replace(tmp, path)        # whole or not at all, for the builds running beside this one
        wrappers[name] = path

    # 2. one relocatable object per code section
    cflags = ("-I include -I . -Wa,-I,include,-mips3,-mcpu=5900,-mabi=eabi "
              "-DINCLUDE_ASM_USE_MACRO_INC=1 -B" + os.path.join(tc, "bin", "ee-"))
    for u in t.units:
        # @ee29 ranges (tools/ee29.py) run Sony's 2.9-ee driver from --ee29 / UYA_EE29 through the runner,
        # @ee296 ranges (tools/ee296.py) Sony's 2.96-ee from --ee296 / UYA_EE296, and @eeas ranges are
        # assembled by Sony's ee-as from --eeas / UYA_EEAS (tools/eeas.py)
        run([sys.executable, "tools/build_text.py", "--target", t.name, "--unit", u.name,
             "--cc", wrappers["cc"], "--ld", wrappers["ld"], "--cflags", cflags, "--runner", runner,
             "--toolchain", tc] + (["--no-cache"] if not cache.enabled else [])
            + (["--ee29", args.ee29] if args.ee29 else []) + (["--ee296", args.ee296] if args.ee296 else [])
            + (["--eeas", args.eeas] if args.eeas else [])
            + ["-j", str(args.jobs), "-o", t.obj(u)])

    # a level's C: the values of the names it uses, from the level's bytes (tools/level_symbols.py),
    # and, when its C has switch jump tables, a linker script that puts them in their places
    # (<build_dir>/<target>.ld, its data cut around them in <build_dir>/pieces/)
    ld = t.ld
    if targets.is_level(t):
        run([sys.executable, "tools/level_symbols.py", "--target", t.name])
        derived = os.path.join(t.build_dir, t.name + ".ld")
        if os.path.exists(os.path.join(ROOT, derived)):
            pieces = re.findall(r"(%spieces/\S+?\.s)\.o" % re.escape(prefix), open(os.path.join(ROOT, derived)).read())
            for src in dict.fromkeys(pieces):
                assemble(cache, exe("ee-as.exe") + ASFLAGS + ["-o", src + ".o", src], src + ".o", src, as_tools)
            ld = derived

    # a core C object's literal pools (read-only data): a linker script that puts them where retail
    # has them, its blob cut around them (tools/core_rodata.py)
    if not targets.is_level(t):
        derived = os.path.join(t.build_dir, t.name + ".ld")
        if os.path.exists(os.path.join(ROOT, derived)):
            os.remove(os.path.join(ROOT, derived))
        import core_rodata
        if core_rodata.derive(t):
            pieces = re.findall(r"(%spieces/\S+?\.s)\.o" % re.escape(prefix), open(os.path.join(ROOT, derived)).read())
            for src in dict.fromkeys(pieces):
                assemble(cache, exe("ee-as.exe") + ASFLAGS + ["-o", src + ".o", src], src + ".o", src, as_tools)
            ld = derived

    print("assembled from asm/: " + cache.summary(), flush=True)

    # 3. link, flatten, compare
    elf = os.path.join(t.build_dir, t.name + ".elf")
    binf = os.path.join(t.build_dir, t.bin_name)
    run(exe("ee-ld.exe") + ["-T", ld, "-o", elf])
    if getattr(t, "flatten", "objcopy") == "elf2bin":
        run([sys.executable, "tools/elf2bin.py", elf, binf])
    else:
        run(exe("ee-objcopy.exe") + ["-O", "binary", elf, binf])
    run([sys.executable, "tools/check_match.py", "--target", t.name, binf, t.elf, t.yaml])


if __name__ == "__main__":
    main()
