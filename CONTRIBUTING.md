# Contributing

Thanks for helping. The guide is in [docs/wiki/](docs/wiki) and [AGENTS.md](AGENTS.md). The short
version:

1. **Set up** the SN ee-gcc 2.95.3 v1.36 toolchain, Sony's ee-gcc 2.9-ee-991111 and your own
   programs in `baserom/` ([README](README.md#quick-start), [Setup](docs/wiki/Setup.md)).
2. **Match** a function with `tools/check.py`, using its file's flags
   ([Workflow](docs/wiki/Workflow.md), [Matching patterns](docs/wiki/Matching-Patterns.md)). Many
   functions have a US draft in `nonmatching/` to start from.
3. **Check** with `python3 tests/check_repository.py`, `python3 -m unittest discover -s tests` and a
   full build that prints `MATCH` for every program.
4. **Open a pull request** against `master` from a branch of your fork
   ([Pull requests](docs/wiki/Pull-Requests.md)).

## Rules

- **Sources.** Use the retail programs of your own disc, SDK library *binaries*, open-source code
  under its licence, public decompilations and tools, and public hardware documentation. Never use
  Sony's SDK source, samples or headers, or leaked or NDA material, not even as a reference. If a
  function looks like SDK sample code, decode it from the assembly. AGENTS.md has the full rule.
- **Never commit game data**: the retail programs, level overlays, disc images, the generated `asm/`,
  build output, or the proprietary toolchains. They stay in ignored places.
- **Never post game data either**, not in an issue, a pull request, the Discord or anywhere else,
  including files a tool generated from your own copy of the disc. Describe what you see in words;
  a note about a function's behaviour or a screenshot of a disassembly is welcome, retail bytes are
  not. This is the rule the whole project rests on ([LEGAL.md](LEGAL.md)).
- Plain C. No inline assembly in a function, no register pins, no tricks to defeat the compiler.
- The full build must match byte for byte; a function that only compiles to the right bytes on its
  own is not matched.
- One flag set per source file; no per-function flags ([BUILD_FIDELITY](docs/BUILD_FIDELITY.md)).
- Variables in `src/` are always `extern`, never defined.
- Conventional commit subjects (`feat(levels):`, `fix(tools):`, `docs:`, ...) with a body that says
  what changed and what you verified.

## Working with other people

A decompilation is a big job: thousands of functions, each of which has to come out as exactly the
same bytes as the original. Nobody finishes that alone, and nobody is competing for a prize. When
another project figures out a function, it is not a point lost for us: it is one more piece of the
game that all of us now understand. So:

- **Disagree kindly.** Projects make different choices, and that is fine. Argue about the code,
  never about the person.
- **Credit what you reuse.** If you learned something from another project, a file or a function,
  say so in the source and in the commit, and name its licence
  ([THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md)).
- **Share what you find.** A symbol name, a structure, a compiler quirk: it helps everyone, whichever
  release or approach they work on.
- **Welcome newcomers.** Every one of us started out not knowing how any of this works. Reviewing,
  documenting function behaviour and improving the tooling all help, not just writing matches.
- **Be patient with people's work.** A pull request is someone's evening. Review it when you can,
  say why something does not match, and expect the same back.

## AI-assisted contributions

Tools that write code with a model's help are welcome here; several of the OpenRAC projects use
them, and AGENTS.md is written for them too. Two things follow from that:

- **You are responsible for what you contribute.** A pull request written with an AI is yours, the
  same as one written by hand: it has to match retail, it has to follow the rules above, and you
  have to be able to explain it.
- **The rules do not relax for generated code.** It is still your contribution, and the sourcing
  rules apply to it exactly as they apply to anything else.

## Questions, or a problem

The [OpenRAC Discord](https://discord.gg/Sfd2B54PDG) is open to everyone, and `info@openrac.dev`
reaches the maintainers privately. If you have a question, run into build issues, or want to
collaborate, either works. Please do not open a public issue to report a problem with someone; write
instead.
