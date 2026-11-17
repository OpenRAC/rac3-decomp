"""Sony's assembler, ee-as 2.10-ee-001003-1, for the `@eeas` pseudo-flag in text_parts.txt.

Sony assembled its library objects with the binutils of its own SDK release, not with SN's
assemblers. The difference shows where the compiler's `.s` leaves a `jal` or `jr` delay slot to
the assembler (`.set reorder`) and the instruction before it is a macro that expands to several
instructions (`lw $4,67268($16)`, `la`, `dli`): ee-as 2.10-ee moves the expansion's last
instruction into the delay slot, while SN's bin/ee-as.exe and ee/bin/as.exe (`@newas`, both
2.9-ee-991111b) leave a `nop` there. Level 39's Sony libraries (`@ee29`, `@ee296` files) have
the filled slots.

A range whose flags contain `@eeas` is compiled as usual (SN's compiler, or Sony's with `@ee29` /
`@ee296`), and its assembly is then assembled by this program instead of the driver's `-c`
step, with the options the driver would have given it (as_options()). It takes the place of
`@newas` and `@ps2as`, so a line may hold only one of the three. As for @ee29, the assembly does
not go through tools/asm_filter.py: the short-loop and divide padding it adds are SN's
assembler's, not this one's.

The program exists only as an i386 Linux binary (rac3-toolchains/native-ee/bin/ee-as), run
through a wrapper where the system has no 32-bit loader (rac3-toolchains/native-bin/ee-as, or
mac-bin/ee-as on a Mac). Where it is: --eeas PROGRAM, else env UYA_EEAS. There is no default:
a file that asks for @eeas without either stops with an error saying so.
"""
import os
import subprocess

FLAG = "@eeas"
ENV = "UYA_EEAS"
VERSION = "2.10-ee-001003-1"
# the other assembler choices; a range may name only one assembler
OTHER_ASSEMBLERS = ("@newas", "@ps2as")


def wanted(flags):
    """True if a text_parts.txt flag list asks for Sony's ee-as."""
    return FLAG in flags


def check_flags(flags):
    """Raise ValueError when a flag list names Sony's ee-as and another assembler."""
    if wanted(flags):
        other = [f for f in flags if f in OTHER_ASSEMBLERS]
        if other:
            raise ValueError("%s and %s both choose the assembler; use one" % (FLAG, " ".join(other)))


def program(path=None):
    """The ee-as program: `path`, else env UYA_EEAS."""
    p = path or os.environ.get(ENV)
    if not p:
        raise FileNotFoundError("Sony's ee-as %s is needed for an %s range: set %s (or --eeas) to the "
                                "program, e.g. rac3-toolchains/native-bin/ee-as" % (VERSION, FLAG, ENV))
    p = os.path.expanduser(p)
    if not os.path.isfile(p):
        raise FileNotFoundError("Sony's ee-as not found: %s (from --eeas or %s)" % (p, ENV))
    return p


def as_options(flags, cflags=()):
    """The options gcc's driver gives the assembler for a range (its specs' *asm and
    *subtarget_asm_optimizing_spec, the same in SN 2.95.3 and Sony 2.96): -G as given, -EL,
    -O2 for -O/-O1/-O2 and -O3 for -O3 (nothing for -O0 or -Os), -mabi=eabi, then the
    project's -Wa,... options split at their commas."""
    out = []
    g = [f for f in flags if f.startswith("-G")]
    if g:
        out.append(g[-1])
    out.append("-EL")
    opt = [f for f in flags if f.startswith("-O")]
    if opt and opt[-1] in ("-O", "-O1", "-O2"):
        out.append("-O2")
    elif opt and opt[-1] == "-O3":
        out.append("-O3")
    out.append("-mabi=eabi")
    for f in cflags:
        if f.startswith("-Wa,"):
            out += [w for w in f[4:].split(",") if w]
    return out


def assemble(flags, cflags, spath, opath, cwd=None, path=None, capture=False):
    """Assemble spath into opath with Sony's ee-as. Returns the CompletedProcess."""
    cmd = [program(path)] + as_options(flags, cflags) + ["-o", opath, spath]
    if capture:
        return subprocess.run(cmd, cwd=cwd, capture_output=True, text=True)
    print(" ".join(cmd), flush=True)
    return subprocess.run(cmd, cwd=cwd)
