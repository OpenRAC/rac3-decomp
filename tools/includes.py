r"""includes.py: every file a C source can include, for a reuse key (tools/c_objects.py).

A scan, not the preprocessor, and a superset of what it opens:

- every `#include "name"` / `#include <name>` directive in the text counts, whether or not an `#if`
  around it is taken, whether or not it sits in a comment (`#include_next`, `#import`, and the
  `%:` / `??=` spellings of `#` as well);
- a name counts in every folder the compilers search for it, not only the first that has it: for
  "name" the including file's folder, then `-I include` and `-I .` (tools/check.py's options, from
  the repository's root); for <name> those two, then the compilers' own folders. A folder without
  the file counts as "missing", so creating one there (which would change what the preprocessor
  opens) changes the result. The compilers' own folders (Scanner's SYSTEM, toolchain_dirs()) are
  every folder of the toolchains given: their files are in the key already, but a header found
  there is scanned like any other, since its own includes look in `-I include` and `-I .` first
  (creating include/stddef.h changes what a toolchain's <stddef.h> includes);
- a name counts in every spelling a compiler can open it by (spellings(), resolved by matches()).
  Under wibo (and on Windows) SN's ee-gcc 2.95.3 and Sony's 2.9-ee driver, and SN's assemblers
  (ee-as, as, Ps2EeAs), open a name without regard to case, take `\` as a folder separator and
  drop the dots at the end of each part (`Structs\Hero.h.` opens include/structs/hero.h); when
  both an exact and another-case file exist they open the exact one. Sony's 2.96 cpp0 and ee-as
  2.10 are Linux programs: exact case, `\` a character of the name (and so is any program on a
  case-insensitive disk, macOS's or Windows'). So every file whose name equals a part's in any
  case (with or without its end dots) counts, beside the name as written; the scan of
  scratch/orch/batch/FIXES.md, item 4, has what each compiler accepted. A name this scan cannot
  read so (not ASCII, a part of three or more dots, a Windows drive or root, an assembler
  `.include` with a `\`, which GNU as reads as an escape) gives None, as a macro does;
- the assembler's `.include "name"` the same way, in C text (`__asm__(".include \"...\"")`, as
  include/include_asm.h has for include/macro.inc and include/labels.inc) and in the files it
  names, searched in the including file's folder, the root and `include/`;
- each file found is scanned in turn.

An `#include` whose operand is neither "name" nor <name> (a macro) cannot be followed: scan() then
returns None, and the caller must take every header. The `.include` of INCLUDE_ASM, INCLUDE_RODATA
and ASM_FUNC builds its name from the macro's arguments (an empty name here): those name files
under asm/, which only a function's assembly reads; the C a check compiles has no such macro
(tests/test_reuse.py, scratch/orch/batch/REPORT.md).
"""
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DIRECTIVE = re.compile(r"^[ \t]*(?:#|%:|\?\?=)[ \t]*(?:include_next|include|import)\b[ \t]*(.*?)[ \t]*$", re.M)
# `.include "name"` in an assembler file, or `.include \"name\"` inside a C string
ASM_INCLUDE = re.compile(r'\.include[ \t]+(\\?)"([^"\n]*?)\1"')
OPERAND = re.compile(r'^(?:"([^"\n]+)"|<([^>\n]+)>)')


def directives(text):
    """[(kind, name)] of TEXT's includes: kind "quote", "angle" or "asm"; name None for an
    #include this scan cannot follow."""
    out = []
    for m in DIRECTIVE.finditer(text):
        o = OPERAND.match(m.group(1))
        out.append(("quote", o.group(1)) if o and o.group(1) else ("angle", o.group(2)) if o else ("quote", None))
    out += [("asm", m.group(2)) for m in ASM_INCLUDE.finditer(text) if m.group(2)]
    return out


def includes_of(text, here=None):
    """{(kind, name, HERE)} of TEXT's includes (directives()), HERE the folder of the file that
    has them (None: the translation unit, compiled from a temporary folder)."""
    return {(k, n, here) for k, n in directives(text)}


def search_dirs(kind, here, root=ROOT, system=()):
    """The folders an include of KIND (as directives() gives it) from a file in folder HERE (None:
    the translation unit, compiled from a temporary folder) is looked for in, in order; SYSTEM the
    compilers' own (toolchain_dirs()), after the project's (an assembler has none)."""
    inc = os.path.join(root, "include")
    dirs = {"quote": [here, inc, root] + list(system), "angle": [inc, root] + list(system),
            "asm": [here, root, inc]}[kind]
    return [d for d in dirs if d is not None]


def toolchain_dirs(paths):
    """Every folder of the toolchain folders PATHS (None or missing ones left out), sorted: a superset
    of the folders their compilers search after -I (SN's ee-gcc 2.95.3: lib/gcc-lib/ee/2.95.3;
    Sony's 2.9-ee: its gcc-lib's include/, before -I, when it has one; Sony's 2.96 cpp0: none)."""
    out = set()
    for path in paths:
        if path and os.path.isdir(path):
            for d, ds, _ in os.walk(os.path.abspath(path), followlinks=True):
                ds[:] = [x for x in ds if x != "__pycache__"]
                out.add(d)
    return sorted(out)


def spellings(kind, name):
    """The ways a compiler can read NAME: lists of its parts, as written (a Linux program's) and with
    each `\\` a separator (a Windows program's); None when this scan cannot say (the module's
    docstring)."""
    if not name.isascii() or re.match(r"[A-Za-z]:|\\", name) or (kind == "asm" and "\\" in name):
        return None
    forms = [name] + ([name.replace("\\", "/")] if "\\" in name else [])
    out = []
    for form in forms:
        parts = form.split("/")
        if any(p.strip(".") == "" and p not in ("", ".", "..") for p in parts):
            return None
        if parts not in out:
            out.append(parts)
    return out


class Scanner:
    """scan() with the files it read and the results kept, for many translation units of one tree."""

    def __init__(self, root=ROOT, system=()):
        self.root, self.system = root, list(system)
        self.texts, self.results, self.listings = {}, {}, {}

    def _directives(self, path):
        if path not in self.texts:
            with open(path, "rb") as f:
                self.texts[path] = directives(f.read().decode("latin-1"))
        return self.texts[path]

    def _listing(self, folder):
        if folder not in self.listings:
            try:
                self.listings[folder] = sorted(os.listdir(folder))
            except OSError:
                self.listings[folder] = []
        return self.listings[folder]

    def matches(self, base, parts):
        """Every existing file a compiler can open as BASE/PARTS (BASE a folder as it is, PARTS
        spellings()'s): each part matched in its folder's listing without regard to case, with or
        without the dots at its end; "." and ".." as written."""
        here = [base]
        for i, part in enumerate(parts):
            last = i == len(parts) - 1
            if part in ("", "."):
                continue
            if part == "..":
                here = [os.path.dirname(h) for h in here]
                continue
            want = {part.lower(), part.rstrip(".").lower()}
            found = []
            for h in here:
                for entry in self._listing(h):
                    if entry.lower() in want:
                        p = os.path.join(h, entry)
                        if os.path.isfile(p) if last else os.path.isdir(p):
                            found.append(p)
            here = found
        return here

    def scan(self, texts):
        """((path, True if it exists, else False), ...) of every file (and missing candidate) the C
        texts TEXTS (each (text, its folder or None)) can include, transitively, sorted; None when
        an #include cannot be followed."""
        found = set()
        for text, here in texts:
            found |= includes_of(text, here)
        return self.resolve(frozenset(found))

    def resolve(self, found):
        """scan()'s result for a set of (kind, name, folder) includes."""
        if found not in self.results:
            out, todo = {}, list(found)
            while todo:
                kind, name, here = todo.pop()
                forms = None if name is None else spellings(kind, name)
                if forms is None:
                    out = None
                    break
                if os.path.isabs(name):
                    tries = [(os.sep, [p for p in name.split("/") if p])]
                else:
                    tries = [(d, parts) for d in search_dirs(kind, here, self.root, self.system) for parts in forms]
                for d, parts in tries:
                    for p in [os.path.normpath(os.path.join(d, *parts))] + self.matches(d, parts):
                        if p not in out:
                            out[p] = os.path.isfile(p)
                            if out[p]:
                                todo += [(k, n, os.path.dirname(p)) for k, n in self._directives(p)]
            self.results[found] = None if out is None else tuple(sorted(out.items()))
        return self.results[found]
