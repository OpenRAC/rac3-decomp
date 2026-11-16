#!/usr/bin/env python3
"""check_return_types.py: functions whose definition and declarations disagree on the return type.

    python3 tools/check_return_types.py                      # both versions, every .c in src/
    python3 tools/check_return_types.py --version pal        # one version (pal, us or both)
    python3 tools/check_return_types.py --summary            # the counts only
    python3 tools/check_return_types.py --tsv build/rt.tsv   # every declaration of every conflict
    python3 tools/check_return_types.py --strict             # exit 1 when there is a conflict
    python3 tools/check_return_types.py src/levels/shared/L01_002F7800.c ...   # some files only

Report-only (docs/build/return-types.md): the exit code is 0 whatever it finds, unless --strict.

Each file in src/ matches retail on its own, so a caller may declare a function with another return
type than its definition has and still compile to the right bytes. A tool that links all the C
together (OpenRAC's port) then reads the result from the wrong register: rac2-decomp's
`float snd_compute_voice_volume_from_distance`, declared `int` by its callers, silenced every 3D
sound there (rac2-decomp 005bfc4dd, whose tests/check_return_types.py this tool follows).

Every .c under src/ is parsed by clang (`-fsyntax-only -Xclang -ast-dump=json`, MIPS target,
`-I include -I .`). Every function declaration (file scope, block scope, header prototypes, and
C89 implicit declarations at a call) and every definition is reduced to the class in which the EE
ABI returns it:

    void; int32 (char, short, int, enum: $v0); int64 (long and long long, 64-bit on the EE: $v0);
    int128 (mode TI: $v0); float ($f0); double (software floating point, 64 bits in $v0);
    pointer ($v0); aggregate (struct or union).

Static functions (internal linkage) and data names (`D_...`, `jtbl_...`) are left out. A
declaration's linker name is its asm label when it has one (`__asm__("func_003ECDC0")`), else its
name. Names are grouped as each version's build resolves them:

- an address name's suffixes are dropped: `func_003ABE48_A6520` and the per-caller aliases
  (`func_L01_00451388_002FB7D8`, `<name>_<caller>`, docs/build/levels.md) are their base's function.
  tools/resolve_symbols.py gives a core alias its base's address (it reads 1 to 8 hex digits, so
  `func_11F0A0` is `func_0011F0A0`); tools/level_symbols.py gives a level alias its base's place in
  level NN and, in the other levels, the place of a copy with the same code;
- each program has its own addresses: frontbin, boot_elf (the engine core and its own copy of the
  front end), i5bootn, and the levels (catalogue names `func_LNN_XXXXXXXX`). An address below
  0x1D5680 is boot_elf's resident engine core in every program but i5bootn;
- level C is read as a level's tree has it (tools/level_tree.py): a front-end name becomes
  `fe_func_XXXXXXXX`, frontbin's function (the level's copy of it); a bare address in a level's
  own file (src/levels/<NN_name>/) is that level's function there (tools/level_symbols.py; its
  catalogue name), and one in a shared file stays `shared:func_XXXXXXXX`;
- PAL: the C of src/ outside src/us/;
- NTSC-U: src/'s shared C under the names config/us/map.tsv gives it on NTSC-U (what the port
  reads, docs/build/versions.md), and src/us/'s own C, whose names are NTSC-U's (`func_U_XXXXXXXX`
  is `func_XXXXXXXX`: tools/version_map.py us_name()), except the PAL front-end names some of
  src/us/levels/ uses (its build reads both from the bytes), which go through the map. A PAL
  definition of a function whose code differs on NTSC-U (map status `differs` or `none`) is not
  NTSC-U code and is left out there; a name with no NTSC-U twin keeps its PAL name, marked `pal:`.

A group whose classes differ is a conflict: definition against declarations, or, for a function
with no C definition (assembly), declarations against each other.

clang parses a copy of each file in a temporary directory (the sources are never changed): asm
statements are blanked (VU0 operands and EE-only constraints do not pass the MIPS target's checks;
asm labels stay), multi-line string literals are split into concatenated ones, and the system
headers libgcc includes are empty stubs. A file that keeps clang errors still gives its
declarations; those files are listed with their first error. func_L01_0045AA30's 600-cast chain
needs more than 8 MB of clang's stack: on POSIX clang gets the hard limit; where clang still
crashes (Windows gives a program a fixed stack), the line it was parsing is blanked and the file
parsed again, and the report says so.
"""
import argparse
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
from collections import Counter, defaultdict
from concurrent.futures import ProcessPoolExecutor
from functools import partial
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
RESIDENT_END = 0x1D5680           # below: the resident engine core, the same on both discs
PROGRAMS = ("boot_elf", "frontbin", "i5bootn", "levels")
CLASSES = ("void", "int32", "int64", "int128", "float", "double", "pointer", "aggregate")
CLANG_FLAGS = ["--target=mipsel-unknown-linux-gnu", "-fsyntax-only", "-std=gnu89", "-nostdlibinc",
               "-ferror-limit=0", "-fno-caret-diagnostics", "-fno-color-diagnostics",
               # warnings off, and the ones newer clangs make errors by default (gcc 2.95 takes them)
               "-w", "-Wno-unknown-warning-option", "-Wno-int-conversion", "-Wno-incompatible-pointer-types",
               "-Wno-incompatible-function-pointer-types", "-Wno-return-mismatch", "-Wno-return-type",
               "-Wno-implicit-function-declaration", "-Wno-implicit-int",
               "-Xclang", "-ast-dump=json"]
STUBS = ".sysstub"                 # empty system headers (libgcc's <stdlib.h>, <unistd.h>)
CLANG_HEADERS = {"stddef.h", "stdarg.h", "float.h", "limits.h", "stdbool.h", "stdint.h", "iso646.h",
                 "stdalign.h", "stdnoreturn.h", "varargs.h"}

INT32 = {"char", "short", "int", "signed", "unsigned", "_Bool", "__signed", "__signed__"}
INT128 = {"__int128", "__int128_t", "__uint128_t"}
QUALIFIERS = {"const", "volatile", "restrict", "__restrict", "__restrict__", "__const", "__volatile__",
              "register", "static", "extern", "inline", "__inline", "__inline__", "__extension__"}
ANON = re.compile(r"\((?:unnamed|anonymous)[^()]*\)")
ATTR = re.compile(r"__attribute__\s*\(\((?:[^()]|\((?:[^()]|\([^()]*\))*\))*\)\)")


# --- clang ---------------------------------------------------------------------------------------

def find_clang():
    """$CLANG, else clang on PATH (or a versioned clang-NN), else LLVM's default Windows folder."""
    names = [os.environ.get("CLANG"), "clang"] + ["clang-%d" % v for v in range(23, 13, -1)]
    for name in names:
        if name and shutil.which(name):
            return shutil.which(name)
    for path in (r"C:\Program Files\LLVM\bin\clang.exe",):
        if os.path.exists(path):
            return path
    return None


# --- parser copies -------------------------------------------------------------------------------

TOKEN = re.compile(r"""
    (?P<comment>//[^\n]*|/\*.*?\*/)
  | (?P<string>"(?:\\.|[^"\\])*")
  | (?P<char>'(?:\\.|[^'\\\n])*')
  | (?P<ident>[A-Za-z_]\w*)
  | (?P<space>\s+)
  | (?P<punct>.)
""", re.S | re.X)
ASM = {"asm", "__asm", "__asm__"}
ASM_QUALIFIERS = {"volatile", "__volatile", "__volatile__", "goto", "inline", "__inline", "__inline__"}
KEYWORDS = {"else", "do", "return", "case", "default", "goto", "sizeof"}
CONTROL = {"if", "while", "for", "switch"}


def blank(text):
    """Spaces for text, keeping its newlines (and line continuations, inside a macro)."""
    return re.sub(r"[^\r\n\\]|\\(?!\r?\n)", " ", text)


def neutralize(text):
    """The parser copy of a C file: asm statements blanked (asm labels kept), multi-line string
    literals split into concatenated ones. Line numbers stay the same."""
    if "asm" not in text and not re.search(r'"(?:\\.|[^"\\\n])*\n', text):
        return text
    tokens = [(m.lastgroup, m.start(), m.end()) for m in TOKEN.finditer(text)]
    edits = []                                     # (start, end, replacement)
    prev = None                                    # (kind, text) of the last token that counts
    opened = []                                    # the token before each open '('
    i = 0
    while i < len(tokens):
        kind, start, end = tokens[i]
        word = text[start:end]
        if kind == "string" and "\n" in word:
            edits.append((start, end, re.sub(r"(?<!\\)\r?\n", lambda m: '\\n"' + m.group(0) + '"', word)))
        if kind == "ident" and word in ASM:
            j, qualified = i + 1, False
            while j < len(tokens) and (tokens[j][0] in ("space", "comment") or
                                       (tokens[j][0] == "ident" and text[tokens[j][1]:tokens[j][2]] in ASM_QUALIFIERS)):
                qualified |= tokens[j][0] == "ident"
                j += 1
            if j < len(tokens) and text[tokens[j][1]:tokens[j][2]] == "(":
                depth, k = 0, j
                inside = []
                while k < len(tokens):
                    t = text[tokens[k][1]:tokens[k][2]]
                    if tokens[k][0] == "punct" and t == "(":
                        depth += 1
                    elif tokens[k][0] == "punct" and t == ")":
                        depth -= 1
                        if depth == 0:
                            break
                    elif depth >= 1 and tokens[k][0] not in ("space", "comment"):
                        inside.append(tokens[k][0])
                    k += 1
                if k < len(tokens):
                    # an asm label follows a declarator: `f(int) __asm__("name")`, `x __asm__("name")`
                    label = (not qualified and inside == ["string"] and prev is not None and
                             (prev[0] == "ident" and prev[1] not in KEYWORDS or prev[1] == "]" or
                              prev[1] == ")" and prev[2] not in CONTROL))
                    if not label:
                        edits = [e for e in edits if e[0] < start]
                        edits.append((start, tokens[k][2], blank(text[start:tokens[k][2]])))
                        prev = ("punct", ";", None)
                        i = k + 1
                        continue
        if kind == "punct" and word == "(":
            opened.append(prev[1] if prev else None)
        if kind not in ("space", "comment"):
            prev = (kind, word, opened.pop() if kind == "punct" and word == ")" and opened else None)
        i += 1
    out, pos = [], 0
    for start, end, repl in sorted(edits):
        out.append(text[pos:start])
        out.append(repl)
        pos = end
    out.append(text[pos:])
    return "".join(out)


def make_mirror(root, mirror):
    """The headers of include/ and src/, neutralized, under `mirror` at their paths; empty stubs for
    the system headers the sources include that clang does not have itself."""
    system = set()
    for top in ("include", "src"):
        for d, _, files in os.walk(os.path.join(root, top)):
            for f in files:
                if not f.endswith((".h", ".c")):
                    continue
                path = os.path.join(d, f)
                text = read(path)
                system |= set(re.findall(r"^\s*#\s*include\s*<([^>]+)>", text, re.M))
                if f.endswith(".h"):
                    write(os.path.join(mirror, os.path.relpath(path, root)), neutralize(text))
    for name in system - CLANG_HEADERS:
        write(os.path.join(mirror, STUBS, name), "/* empty: tools/check_return_types.py */\n")


def read(path):
    with open(path, encoding="utf-8", errors="replace", newline="") as f:
        return f.read()


def write(path, text):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", encoding="utf-8", newline="") as f:
        f.write(text)


# --- the AST -------------------------------------------------------------------------------------

JSON_TOKEN = re.compile(r'\s*(?:([\[\]{}:,])|("(?:[^"\\]|\\.)*")|(-?\d+(?:\.\d+)?(?:[eE][-+]?\d+)?)'
                        r'|(true|false|null))', re.S)


def loads_deep(text):
    """json.loads for a document nested deeper than Python's recursion allows (a long expression)."""
    holder, stack, keys, pos = [], [], [], 0
    stack.append(holder)
    keys.append(None)

    def add(value):
        top = stack[-1]
        if isinstance(top, list):
            top.append(value)
        else:
            top[keys[-1]] = value
            keys[-1] = None

    while True:
        m = JSON_TOKEN.match(text, pos)
        if not m:
            if text[pos:].strip():
                raise ValueError("bad JSON at offset %d" % pos)
            break
        pos = m.end()
        punct, string, number, literal = m.groups()
        if punct in ("[", "{"):
            new = [] if punct == "[" else {}
            add(new)
            stack.append(new)
            keys.append(None)
        elif punct in ("]", "}"):
            stack.pop()
            keys.pop()
        elif punct:
            continue
        elif string is not None:
            value = json.loads(string)
            if isinstance(stack[-1], dict) and keys[-1] is None:
                keys[-1] = value
            else:
                add(value)
        elif number is not None:
            add(float(number) if any(c in number for c in ".eE") else int(number))
        else:
            add({"true": True, "false": False, "null": None}[literal])
    return holder[0]


def return_part(function_type):
    """'float (char *, s32)' -> 'float'; 'void (*(int))(void)' (a function pointer) -> 'void (*)'."""
    t = ATTR.sub("", ANON.sub("ANON", function_type)).strip()
    depth = 0
    for i in range(len(t) - 1, -1, -1):
        if t[i] == ")":
            depth += 1
        elif t[i] == "(":
            depth -= 1
            if depth == 0:
                head = t[:i].rstrip()
                return head + ")" if "(" in head else head
    return t


def classify(type_text, lookup, depth=0):
    """The EE ABI return class of a C type, typedef names resolved through lookup(name)."""
    t = ATTR.sub("", ANON.sub("ANON", type_text)).strip()
    if any(c in t for c in "*[("):
        return "pointer"
    words = [w for w in t.split() if w not in QUALIFIERS]
    if not words:
        return "unknown:" + type_text
    if words[0] in ("struct", "union"):
        return "aggregate"
    if words[0] == "enum":
        return "int32"
    if words == ["void"]:
        return "void"
    if "float" in words:
        return "float"
    if "double" in words:
        return "double"
    if INT128 & set(words):
        return "int128"
    if "long" in words:
        return "int64"
    if all(w in INT32 for w in words):
        return "int32"
    if len(words) == 1 and depth < 20:
        target = lookup(words[0])
        if target is None:
            target = BUILTIN_TYPEDEFS.get(words[0])
        if target is not None:
            return classify(target, lookup, depth + 1)
    return "unknown:" + " ".join(words)


BUILTIN_TYPEDEFS = {"__size_t": "unsigned int", "__signed_size_t": "int", "__ptrdiff_t": "int",
                    "__ssize_t": "int"}       # clang's predefined sugar for library prototypes


def declarations(tree, path):
    """Every function declaration of one translation unit (clang's JSON AST), in source order."""
    last = {"file": path, "line": 0}

    def at(loc):
        """clang writes a location's file and line only when they differ from the location written
        before (in the order: loc, range begin, range end; spelling before expansion)."""
        if not loc:
            return None
        for bare in ([loc.get("spellingLoc") or {}, loc.get("expansionLoc") or {}]
                     if "spellingLoc" in loc or "expansionLoc" in loc else [loc]):
            if "file" in bare:
                last["file"] = bare["file"]
            if "line" in bare:
                last["line"] = bare["line"]
        return clean(last["file"]), last["line"]

    out, internal, seen, builtins = [], set(), set(), {}
    stack = [(tree, None, [{}], None)]           # node, parent kind, typedef scopes, function
    while stack:
        node, parent, scopes, function = stack.pop()
        kind = node.get("kind")
        place = at(node.get("loc"))
        span = node.get("range") or {}
        begin = at(span.get("begin"))
        at(span.get("end"))
        child_scopes, child_function = scopes, function

        def lookup(name, scopes=scopes):
            for scope in reversed(scopes):
                if name in scope:
                    return scope[name]
            return None

        if kind == "TypedefDecl" and "name" in node:
            ty = node.get("type") or {}
            scopes[-1][node["name"]] = ty.get("desugaredQualType") or ty.get("qualType", "")
        elif kind == "FunctionDecl" and "name" in node:
            seen.add(node.get("id"))
            ty = node.get("type") or {}
            text = ty.get("qualType", "")
            if "(" not in ANON.sub("", text):    # declared through a typedef of a function type
                text = ty.get("desugaredQualType") or lookup(text.strip()) or text
            ret = return_part(text)
            defined = any(c.get("kind") == "CompoundStmt" for c in node.get("inner") or [])
            file, line = place or begin or (path, 0)
            entry = {"name": node["name"], "link": linker_name(node),
                     "ret": ret, "class": classify(ret, lookup),
                     "kind": "definition" if defined else "declaration",
                     "scope": "file" if parent == "TranslationUnitDecl" else "block",
                     "file": file, "line": line, "function": function}
            if parent == "TranslationUnitDecl" and node.get("storageClass") == "static":
                internal.add(entry["link"])
            if node.get("isImplicit"):
                entry["kind"] = "implicit"         # a library function clang declares at a call
                builtins[node.get("id")] = entry
            else:
                out.append(entry)
            if defined:
                child_scopes, child_function = scopes + [{}], node["name"]
        elif kind == "CompoundStmt":
            child_scopes = scopes + [{}]
        elif kind == "DeclRefExpr":
            ref = node.get("referencedDecl") or {}
            if ref.get("kind") == "FunctionDecl":
                rid = ref.get("id")
                if rid in builtins:
                    out.append(builtins.pop(rid))
                elif rid not in seen and not ref.get("name", "").startswith("__builtin"):
                    # a C89 implicit declaration: clang dumps it nowhere but in the reference
                    seen.add(rid)
                    ret = return_part((ref.get("type") or {}).get("qualType", "int ()"))
                    file, line = begin or (path, 0)
                    out.append({"name": ref["name"], "link": linker_name(ref),
                                "ret": ret, "class": classify(ret, lookup), "kind": "implicit",
                                "scope": "block", "file": file, "line": line, "function": function})
        for child in reversed(node.get("inner") or []):
            stack.append((child, kind, child_scopes, child_function))
    return [e for e in out if e["link"] not in internal]


def linker_name(node):
    """The name the linker sees: an asm label's (clang marks it with \x01 where the target has a
    user label prefix; MIPS ELF has none), else the declared name."""
    return (node.get("mangledName") or node["name"]).lstrip("\x01")


def clean(name):
    name = name.replace("\\", "/")
    while name.startswith("./"):
        name = name[2:]
    return name


ERROR = re.compile(r"(?:^|: )(?:fatal )?error: ")
CRASH_AT = re.compile(r"^\s*\d+\.\s+(.+?):(\d+):\d+: current parser token")


def raise_stack():
    """POSIX: clang's parser recurses into nested expressions, and one function's 600-deep cast
    chain (func_L01_0045AA30) needs more than the usual 8 MB of stack; give clang the hard limit."""
    import resource
    soft, hard = resource.getrlimit(resource.RLIMIT_STACK)
    want = (1 << 30) if hard == resource.RLIM_INFINITY else hard
    if soft != resource.RLIM_INFINITY and soft < want:
        resource.setrlimit(resource.RLIMIT_STACK, (want, hard))


def run_clang(clang, rel, mirror):
    command = [clang, *CLANG_FLAGS, "-isystem", STUBS, "-I", "include", "-I", ".", rel]
    return subprocess.run(command, capture_output=True, cwd=mirror,
                          preexec_fn=raise_stack if os.name == "posix" else None)


def scan(rel, root, mirror, clang, fe=frozenset()):
    """Parse one source file (its parser copy in `mirror`); its declarations and clang's errors.
    Where clang crashes (a stack overflow: Windows gives a program a fixed stack), the line it was
    parsing is blanked in the parser copy and the file parsed again (result["blanked"])."""
    text = read(os.path.join(root, rel))
    if rel.startswith("src/levels/"):
        text = level_names(text, fe)
    copy = neutralize(text)
    result = {"path": rel, "decls": [], "errors": [], "failed": None, "blanked": []}
    for attempt in range(4):
        write(os.path.join(mirror, rel), copy)
        done = run_clang(clang, rel, mirror)
        stderr = done.stderr.decode("utf-8", "replace")
        result["errors"] = [clean(line) for line in stderr.splitlines() if ERROR.search(line)]
        output = done.stdout.decode("utf-8", "replace")
        try:
            try:
                tree = json.loads(output)
            except RecursionError:
                tree = loads_deep(output)
        except ValueError:
            at = [m for m in map(CRASH_AT.match, stderr.splitlines()) if m and clean(m.group(1)) == rel]
            if at and attempt < 3:
                lines = copy.split("\n")
                number = int(at[0].group(2))
                lines[number - 1] = blank(lines[number - 1])
                copy = "\n".join(lines)
                result["blanked"].append(number)
                continue
            crashed = done.returncode < 0 or done.returncode > 255 or "Stack dump" in stderr
            result["failed"] = "clang exit %d (%s)" % (done.returncode, "crashed" if crashed else "no AST")
            break
        result["decls"] = declarations(tree, rel)
        break
    os.remove(os.path.join(mirror, rel))
    return result


FRONT_END = re.compile(r"\b(func_[0-9A-F]{8})(?:_[A-Za-z0-9]+)*\b")     # tools/level_tree.py's


def level_names(text, fe):
    """PAL level C as a level's tree has it (tools/level_tree.py level_names()): front-end names
    become fe_func_XXXXXXXX, so a call written func_XXXXXXXX reaches the fe_ declaration."""
    return FRONT_END.sub(lambda m: "fe_" + m.group(0) if m.group(1) in fe else m.group(0), text)


# --- names ---------------------------------------------------------------------------------------

CATALOGUE = re.compile(r"^(?:fe_)?func_L(\d\d)_([0-9A-F]{8})(?:_[0-9A-Za-z]+)*$")
NATIVE = re.compile(r"^func_U_([0-9A-F]{8})(?:_[0-9A-Za-z]+)*$")
ADDRESS = re.compile(r"^(fe_)?func_([0-9A-Fa-f]{1,8})(?:_[0-9A-Za-z]+)*$")
DATA = re.compile(r"^(?:fe_)?(?:D|jtbl)_")
LEVEL_DIR = re.compile(r"^src/(?:us/)?levels/(\d\d)_")             # src/levels/<NN_name>/: level NN only
NATIVE_LEVEL = re.compile(r"^src/us/levels/func_L(\d\d)_")         # src/us/levels/func_LNN_XXXXXXXX.c


def origin(rel):
    """(version, program) of a source file: src/us/<program>/ is NTSC-U's own C."""
    parts = rel.split("/")
    if len(parts) > 2 and parts[0] == "src" and parts[1] == "us":
        return "us", parts[2]
    return "pal", parts[1] if len(parts) > 2 and parts[0] == "src" else "boot_elf"


class Catalogue:
    """A version's level catalogue (config/levels/functions.tsv, config/us/levels/functions.tsv):
    each function's kind and its place in each level."""

    def __init__(self, path):
        self.kind, self.at, self.front_end = {}, {}, set()
        if not os.path.exists(path):
            return
        for line in read(path).splitlines():
            f = line.rstrip("\n").split("\t")
            if line.startswith("#") or len(f) < 7:
                continue
            self.kind[f[0]] = f[1]
            for place in f[6].split(","):
                if ":" in place:
                    number, address = place.split(":")
                    self.at[(int(number), int(address, 16))] = f[0]
        self.front_end = {n for n, k in self.kind.items() if k in ("frontbin", "boot_elf")}


class Names:
    """What a linker name in a source file stands for, as that version's build resolves it."""

    def __init__(self, root):
        self.catalogue = {"pal": Catalogue(os.path.join(root, "config", "levels", "functions.tsv")),
                          "us": Catalogue(os.path.join(root, "config", "us", "levels", "functions.tsv"))}

    def key(self, link, rel):
        """(program, function) of the function `link` names in `rel` (in the names of rel's own
        version, except as pal_name() says); None for data and builtins."""
        version, program = origin(rel)
        if DATA.match(link) or link.startswith("__builtin_"):
            return None
        m = CATALOGUE.match(link)
        if m:
            return "levels", "func_L%s_%s" % m.groups()
        if self.pal_name(link, rel):
            return "frontbin", "func_%08X" % int(ADDRESS.match(link).group(2), 16)
        m = NATIVE.match(link)
        fe, address = (None, int(m.group(1), 16)) if m else (None, None)
        m = ADDRESS.match(link)
        if m:
            fe, address = m.group(1), int(m.group(2), 16)
        if address is None:
            return ("i5bootn" if program == "i5bootn" else "boot_elf"), link     # a named symbol
        name = "func_%08X" % address
        if program == "i5bootn":
            return "i5bootn", name
        if address < RESIDENT_END:
            return "boot_elf", name
        if program != "levels":
            return program, name
        catalogue = self.catalogue[version]
        if fe or name in catalogue.front_end:
            return "frontbin", name          # the front-end function (the level's copy of it)
        # a bare address in level C: that level's own function there (tools/level_symbols.py)
        m = LEVEL_DIR.match(rel) or NATIVE_LEVEL.match(rel)
        if not m:
            return "levels", "shared:" + name
        number = int(m.group(1))
        found = catalogue.at.get((number, address))
        if found is None:
            return "levels", "L%02d:%s" % (number, name)
        return ("frontbin" if found in catalogue.front_end else "levels"), found

    def pal_name(self, link, rel):
        """NTSC-U level C (src/us/levels/) mostly names a front-end function by its NTSC-U name,
        but some of it by the PAL one (the build reads both from the bytes): a name that is a PAL
        front-end function's and no NTSC-U one's is PAL's."""
        if not rel.startswith("src/us/levels/"):
            return False
        m = ADDRESS.match(link)
        if not m or int(m.group(2), 16) < RESIDENT_END:
            return False
        name = "func_%08X" % int(m.group(2), 16)
        return name in self.catalogue["pal"].front_end and name not in self.catalogue["us"].front_end


class UsNames:
    """config/us/map.tsv: each PAL function's NTSC-U name, and the PAL C that is not NTSC-U code."""

    def __init__(self, root):
        self.us, self.status = {}, defaultdict(set)
        path = os.path.join(root, "config", "us", "map.tsv")
        self.present = os.path.exists(path)
        if not self.present:
            return
        for line in read(path).splitlines():
            if line.startswith("#") or not line.strip():
                continue
            f = line.rstrip("\n").split("\t")
            if f[0] != "-" and f[2] != "-":
                self.us[(f[1], f[0])] = f[2]
            if f[0] != "-" and f[5] == "C":
                self.status[(f[1], f[0])].add(f[6])

    def name(self, k):
        """The NTSC-U key of a PAL key."""
        program, name = k
        if (program, name) in self.us:
            return program, self.us[(program, name)]
        if "func_" not in name:
            return k                               # a named symbol
        if program == "boot_elf" and re.match(r"^func_[0-9A-F]{8}$", name) and int(name[5:], 16) < RESIDENT_END:
            return k                               # the resident core: the same address
        return program, "pal:" + name

    def not_us_code(self, k):
        s = self.status.get(k)
        return bool(s) and not (s & {"match", "nomatch"})


def views(results, versions, us_names, names=None):
    """{version: {(program, name): [declaration, ...]}}, each declaration once."""
    names = names or Names(str(ROOT))
    out = {}
    for version in versions:
        groups, seen = defaultdict(list), set()
        for r in results:
            source, program = origin(r["path"])
            if version == "pal" and source != "pal":
                continue
            for d in r["decls"]:
                k = names.key(d["link"], r["path"])
                if k is None:
                    continue
                if version == "us" and source == "pal":
                    if d["kind"] == "definition" and us_names.not_us_code(k):
                        continue
                    k = us_names.name(k)
                elif version == "us" and names.pal_name(d["link"], r["path"]):
                    k = us_names.name(k)
                ident = (k, d["file"], d["line"], d["link"], d["kind"])
                if ident in seen:
                    continue
                seen.add(ident)
                groups[k].append(d)
        out[version] = groups
    return out


def conflicts(groups):
    """{key: declarations} of the groups whose classes differ, definitions first."""
    order = {"definition": 0, "declaration": 1, "implicit": 2}
    return {k: sorted(ds, key=lambda d: (order[d["kind"]], d["file"], d["line"]))
            for k, ds in groups.items() if len({d["class"] for d in ds}) > 1}


def class_order(c):
    return (CLASSES.index(c) if c in CLASSES else len(CLASSES), c)


def pair(decls):
    return " vs ".join(sorted({d["class"] for d in decls}, key=class_order))


# --- the report ----------------------------------------------------------------------------------

LABEL = {"pal": "PAL", "us": "NTSC-U"}


def describe(k, decls, details):
    head = "%s:%s  %s" % (k[0], k[1], pair(decls))
    if details:
        lines = [head]
        for d in decls:
            what = d["kind"] if d["scope"] == "file" or d["kind"] != "declaration" else "block declaration"
            lines.append("    %-9s %-17s %s:%d  (%s: %s)" % (d["class"], what, d["file"], d["line"], d["name"], d["ret"]))
        return "\n".join(lines)
    parts = []
    for c in sorted({d["class"] for d in decls}, key=class_order):
        ds = [d for d in decls if d["class"] == c]
        defs = [d for d in ds if d["kind"] == "definition"]
        rest = len(ds) - len(defs)
        bits = []
        if defs:
            bits.append("definition %s:%d" % (defs[0]["file"], defs[0]["line"]))
        if rest:
            first = next(d for d in ds if d["kind"] != "definition")
            implicit = sum(1 for d in ds if d["kind"] == "implicit")
            what = "%d %sdeclaration%s" % (rest, "implicit " if implicit == rest else "", "" if rest == 1 else "s")
            if 0 < implicit < rest:
                what += " (%d implicit)" % implicit
            bits.append("%s (%s:%d%s)" % (what, first["file"], first["line"], ", ..." if rest > 1 else ""))
        parts.append("%s: %s" % (c, ", ".join(bits)))
    return head + "\n    " + "; ".join(parts)


def report(results, by_version, args):
    lines = []
    failed = [r for r in results if r["failed"]]
    with_errors = [r for r in results if r["errors"] and not r["failed"]]
    totals = {}
    for version, groups in by_version.items():
        bad = conflicts(groups)
        totals[version] = len(bad)
        count = sum(len(ds) for ds in groups.values())
        unknown = Counter(d["class"] for ds in groups.values() for d in ds if d["class"].startswith("unknown:"))
        lines.append("%s: %d functions, %d declarations and definitions, %d conflicts"
                     % (LABEL[version], len(groups), count, len(bad)))
        pairs = Counter(pair(ds) for ds in bad.values())
        lines.append("  by classes: " + (", ".join("%s %d" % p for p in sorted(pairs.items(), key=lambda p: (-p[1], p[0])))
                                         or "-"))
        programs = Counter(k[0] for k in bad)
        lines.append("  by program: " + ", ".join("%s %d" % (p, programs.get(p, 0)) for p in PROGRAMS))
        if unknown:
            lines.append("  unclassified return types: " + ", ".join("%s %d" % u for u in unknown.most_common(10)))
        if not args.summary:
            for k in sorted(bad, key=lambda k: (k[0], k[1])):
                lines.append(describe(k, bad[k], args.details))
            lines.append("")
    blanked = [r for r in results if r.get("blanked")]
    lines.append("clang: %d files, %d with errors (their declarations are counted), %d parsed again after a "
                 "crash, %d without an AST" % (len(results), len(with_errors), len(blanked), len(failed)))
    for r in blanked:
        lines.append("  %s: clang crashed (out of stack) on line %s; parsed again with %s blanked"
                     % (r["path"], ", ".join(map(str, r["blanked"])), "it" if len(r["blanked"]) == 1 else "them"))
    for r in failed:
        lines.append("  %s: %s%s" % (r["path"], r["failed"], (": " + r["errors"][0]) if r["errors"] else ""))
    if not args.summary or args.details:
        for r in with_errors:
            lines.append("  %s: %d error%s, first: %s" % (r["path"], len(r["errors"]),
                                                         "" if len(r["errors"]) == 1 else "s", r["errors"][0]))
    print("\n".join(lines))
    return totals


def write_tsv(path, by_version):
    rows = ["version\tprogram\tfunction\tclasses\tclass\tkind\tscope\tfile\tline\tname\treturn type"]
    for version, groups in by_version.items():
        bad = conflicts(groups)
        for k in sorted(bad):
            for d in bad[k]:
                rows.append("\t".join([LABEL[version], k[0], k[1], pair(bad[k]), d["class"], d["kind"], d["scope"],
                                       d["file"], str(d["line"]), d["name"], d["ret"]]))
    os.makedirs(os.path.dirname(os.path.abspath(path)), exist_ok=True)
    with open(path, "w", encoding="utf-8", newline="\n") as f:
        f.write("\n".join(rows) + "\n")


def sources(root):
    return sorted(str(p.relative_to(root)).replace(os.sep, "/") for p in (Path(root) / "src").rglob("*.c"))


def collect(paths, root=ROOT, jobs=None, clang=None):
    """Parse `paths` (relative to root) with clang; one result per file."""
    clang = clang or find_clang()
    mirror = tempfile.mkdtemp(prefix="check_return_types-")
    try:
        make_mirror(str(root), mirror)
        fe = Catalogue(os.path.join(str(root), "config", "levels", "functions.tsv")).front_end
        work = partial(scan, root=str(root), mirror=mirror, clang=clang, fe=frozenset(fe))
        if jobs == 1 or len(paths) < 2:
            return [work(p) for p in paths]
        with ProcessPoolExecutor(max_workers=jobs or os.cpu_count() or 4) as pool:
            return list(pool.map(work, paths, chunksize=8))
    finally:
        shutil.rmtree(mirror, ignore_errors=True)


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("paths", nargs="*", help="files to parse, relative to the repository (default: every .c in src/)")
    ap.add_argument("--version", choices=("pal", "us", "both"), default="both")
    ap.add_argument("--jobs", "-j", type=int, default=os.cpu_count() or 4)
    ap.add_argument("--tsv", help="write every declaration of every conflict to this file")
    ap.add_argument("--summary", action="store_true", help="print the counts only")
    ap.add_argument("--details", action="store_true", help="print every declaration of each conflict")
    ap.add_argument("--strict", action="store_true", help="exit 1 when there is a conflict or a file without an AST")
    ap.add_argument("--save-scan", metavar="FILE", help="also write what clang found (JSON), for --from-scan")
    ap.add_argument("--from-scan", metavar="FILE", help="report from a saved scan instead of running clang")
    args = ap.parse_args()
    if args.from_scan:
        results = json.loads(read(args.from_scan))
    else:
        clang = find_clang()
        if clang is None:
            sys.exit("check_return_types: clang not found (install it or set $CLANG)")
        paths = [clean(os.path.relpath(os.path.abspath(p), ROOT)) for p in args.paths] or sources(ROOT)
        results = collect(paths, ROOT, args.jobs, clang)
    if args.save_scan:
        with open(args.save_scan, "w", encoding="utf-8", newline="\n") as f:
            json.dump(results, f)
    us_names = UsNames(str(ROOT))
    versions = ["pal", "us"] if args.version == "both" else [args.version]
    if "us" in versions and not us_names.present:
        print("config/us/map.tsv is missing: no NTSC-U report")
        versions.remove("us")
    by_version = views(results, versions, us_names)
    totals = report(results, by_version, args)
    if args.tsv:
        write_tsv(args.tsv, by_version)
    if args.strict and (any(totals.values()) or any(r["failed"] for r in results)):
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
