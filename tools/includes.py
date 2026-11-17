"""includes.py: every file a C source can include, for a reuse key (tools/c_objects.py).

A scan, not the preprocessor, and a superset of what it opens:

- every `#include "name"` / `#include <name>` directive in the text counts, whether or not an `#if`
  around it is taken, whether or not it sits in a comment (`#include_next`, `#import`, and the
  `%:` / `??=` spellings of `#` as well);
- a name counts in every folder the compilers search for it, not only the first that has it: for
  "name" the including file's folder, then `-I include` and `-I .` (tools/check.py's options, from
  the repository's root); for <name> those two. A folder without the file counts as "missing", so
  creating one there (which would change what the preprocessor opens) changes the result. The
  compilers' own folders come after these; they are the toolchain's, hashed as a whole;
- the assembler's `.include "name"` the same way, in C text (`__asm__(".include \\"...\\"")`, as
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
ASM_INCLUDE = re.compile(r'\.include[ \t]+\\?"([^"\\\n]*)\\?"')
OPERAND = re.compile(r'^(?:"([^"\n]+)"|<([^>\n]+)>)')


def directives(text):
    """[(kind, name)] of TEXT's includes: kind "quote", "angle" or "asm"; name None for an
    #include this scan cannot follow."""
    out = []
    for m in DIRECTIVE.finditer(text):
        o = OPERAND.match(m.group(1))
        out.append(("quote", o.group(1)) if o and o.group(1) else ("angle", o.group(2)) if o else ("quote", None))
    out += [("asm", m.group(1)) for m in ASM_INCLUDE.finditer(text) if m.group(1)]
    return out


def includes_of(text, here=None):
    """{(kind, name, HERE)} of TEXT's includes (directives()), HERE the folder of the file that
    has them (None: the translation unit, compiled from a temporary folder)."""
    return {(k, n, here) for k, n in directives(text)}


def candidates(kind, name, here, root=ROOT):
    """The paths where an include of NAME (KIND as directives() gives it) from a file in folder
    HERE (None: the translation unit, compiled from a temporary folder) is looked for."""
    if os.path.isabs(name):
        return [name]
    inc = os.path.join(root, "include")
    dirs = {"quote": [here, inc, root], "angle": [inc, root], "asm": [here, root, inc]}[kind]
    return [os.path.normpath(os.path.join(d, name)) for d in dirs if d is not None]


class Scanner:
    """scan() with the files it read and the results kept, for many translation units of one tree."""

    def __init__(self, root=ROOT):
        self.root, self.texts, self.results = root, {}, {}

    def _directives(self, path):
        if path not in self.texts:
            with open(path, "rb") as f:
                self.texts[path] = directives(f.read().decode("latin-1"))
        return self.texts[path]

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
                if name is None:
                    out = None
                    break
                for p in candidates(kind, name, here, self.root):
                    if p not in out:
                        out[p] = os.path.isfile(p)
                        if out[p]:
                            todo += [(k, n, os.path.dirname(p)) for k, n in self._directives(p)]
            self.results[found] = None if out is None else tuple(sorted(out.items()))
        return self.results[found]
