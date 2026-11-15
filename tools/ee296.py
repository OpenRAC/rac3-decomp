"""Sony's ee-gcc 2.96-ee-001003-1 for the `@ee296` pseudo-flag in text_parts.txt.

Level 39's DNAS2 library (its population B, docs/wiki/Matching-Patterns.md, "Code from another
compiler") was built with this compiler, and so were i5bootn's newlib `exit()` and boot_elf's
newlib region (docs/research/us/compiler_matrix_i5bootn.md): 8-byte save slots with `$ra` saved
last, sibling calls, argument moves hoisted above a branch, labels after a `b` 8-byte aligned
(an alignment `nop`) and two `nop`s before `div.s`, all by default. A text_parts.txt range whose
flags contain `@ee296` is compiled to assembly with it, like an @ee29 range with 2.9-ee
(tools/ee29.py), and the assembly is assembled by the project's normal assembling step.

The compiler exists only as i386 Linux programs (the SDK's Windows `cc1.exe` in the same
folder is SN's 2.95.3 v1.07, not 2.96), and there is no 2.96 driver, so this runs its
preprocessor and compiler directly: `cpp0` with the predefines its `specs` file gives, then
`cc1`. The range's flags go to cc1 (write only options 2.96 knows: `-O2 -G0`, not
`-fopt-stack` or `-mvu0-use-vf0-vf2`); the project's -I/-D/-U go to cpp0.

Assemble @ee296 ranges with `@newas` (SN's ee/bin/as.exe) on the same line: the default
bin/ee-as.exe puts load-delay `nop`s after `mtc1`/`mfc1` that the 2.96 objects don't have (the
native ee-as 2.10-ee-001003-1, the binutils of the same SDK release, gives what @newas gives).
Like @ee29, the assembly does not go through tools/asm_filter.py (SN's short-loop padding).

Where the compiler is:

  * env UYA_EE296: the folder holding lib/gcc-lib/ee/2.96-ee-001003-1/ (cpp0, cc1);
  * otherwise ~/Projects/RAC/rac3-toolchains/ee296.

A program in the folder's bin/ (bin/cpp0, bin/cc1) is used instead of the one in gcc-lib: a
wrapper that runs it through a 32-bit loader where the system has none (NixOS; on a Mac, a
linux/386 container), as rac3-toolchains/native-bin does for the binutils.
"""
import os
import subprocess
import tempfile

FLAG = "@ee296"
DEFAULT_ROOT = "~/Projects/RAC/rac3-toolchains/ee296"
VERSION = "2.96-ee-001003-1"

# what the driver would give cpp0 with this compiler's specs (*predefines, *cpp,
# *subtarget_cpp_spec, *subtarget_cpp_size_spec, *long_max_spec) for a C file
PREDEFINES = [
    "-lang-c", "-D__GNUC__=2", "-D__GNUC_MINOR__=96", "-D__GNUC_PATCHLEVEL__=0",
    "-Dmips", "-DMIPSEL", "-DR5900", "-D_mips", "-D_MIPSEL", "-D_R5900", "-D__ee__",
    "-D__mips__", "-D__MIPSEL__", "-D__R5900__", "-D__mips", "-D__MIPSEL", "-D__R5900",
    "-D__LANGUAGE_C", "-D_LANGUAGE_C", "-DLANGUAGE_C",
    "-D__SIZE_TYPE__=unsigned int", "-D__PTRDIFF_TYPE__=int", "-D__LONG_MAX__=9223372036854775807L",
    "-U__mips", "-D__mips=3", "-D__mips64", "-D__mips_eabi", "-D__mips_single_float",
]


def wanted(flags):
    """True if a text_parts.txt flag list asks for the 2.96-ee compiler."""
    return FLAG in flags


def root(path=None):
    return os.path.expanduser(path or os.environ.get("UYA_EE296") or DEFAULT_ROOT)


def program(name, path=None):
    """bin/<name> of the folder if there is one (a wrapper), else gcc-lib's own program."""
    r = root(path)
    for p in (os.path.join(r, "bin", name), os.path.join(r, "lib", "gcc-lib", "ee", VERSION, name)):
        if os.path.exists(p):
            return p
    raise FileNotFoundError("2.96-ee compiler not found: no %s in %s/lib/gcc-lib/ee/%s/ (set UYA_EE296 or "
                            "--ee296 to the ee296 folder)" % (name, r, VERSION))


def split_flags(flags, cflags=()):
    """(cpp0 options, cc1 options) for a range: the range's flags without pseudo-flags (@ee296,
    and an assembler choice, which only matters when assembling) and the project's compile
    options. -I/-D/-U (and -I DIR) go to cpp0, the rest to cc1; -B (the assembler choice) and
    -Wa (assembler options) are dropped. @ps2as adds -DNO_MACRO_INC as build_text.py does."""
    cpp, cc1 = [], []
    args = [f for f in flags if not f.startswith("@")] + list(cflags)
    if "@ps2as" in flags:
        cpp.append("-DNO_MACRO_INC")
    i = 0
    while i < len(args):
        f = args[i]
        if f in ("-I", "-D", "-U", "-include") and i + 1 < len(args):
            cpp += [f, args[i + 1]]
            i += 2
            continue
        if f.startswith(("-I", "-D", "-U")):
            cpp.append(f)
        elif not f.startswith(("-B", "-Wa,")):
            cc1.append(f)
        i += 1
    opt = [f for f in cc1 if f.startswith("-O")]
    if opt and opt[-1] != "-O0":
        cpp.append("-D__OPTIMIZE__")
    if opt and opt[-1] == "-Os":
        cpp.append("-D__OPTIMIZE_SIZE__")
    return cpp, cc1


def to_asm(flags, cflags, cpath, spath, cwd=None, path=None, capture=False):
    """Compile cpath to assembly spath: cpp0, then cc1. Returns the CompletedProcess of the
    step that failed, or of cc1."""
    cpp_opts, cc1_opts = split_flags(flags, cflags)
    tmp = tempfile.mkdtemp(prefix="ee296_")
    ipath = os.path.join(tmp, os.path.splitext(os.path.basename(cpath))[0] + ".i")
    steps = [[program("cpp0", path)] + PREDEFINES + cpp_opts + [cpath, ipath],
             [program("cc1", path), ipath, "-quiet", "-dumpbase", os.path.basename(cpath)] + cc1_opts
             + ["-o", spath]]
    try:
        for cmd in steps:
            if capture:
                p = subprocess.run(cmd, cwd=cwd, capture_output=True, text=True)
            else:
                print(" ".join(cmd), flush=True)
                p = subprocess.run(cmd, cwd=cwd)
            if p.returncode:
                return p
        return p
    finally:
        for f in os.listdir(tmp):
            os.remove(os.path.join(tmp, f))
        os.rmdir(tmp)
