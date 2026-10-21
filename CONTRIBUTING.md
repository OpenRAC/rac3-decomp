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

Hard rules:

- Never commit the retail programs, level overlays, disc images, or anything generated from them.
- Never post game data in an issue, a pull request or the Discord, and never use SDK source, samples, headers or leaked material ([Code of Conduct](CODE_OF_CONDUCT.md), [Sources](AGENTS.md#rules)).
- The full build must match byte for byte.
- One flag set per source file; no per-function flags ([BUILD_FIDELITY](docs/BUILD_FIDELITY.md)).
- Variables in `src/` are always `extern`, never defined.

Take part in good faith: [the Code of Conduct](CODE_OF_CONDUCT.md) says what we expect of each other. The [OpenRAC Discord](https://discord.gg/Sfd2B54PDG) is open to everyone, and `info@openrac.dev` reaches the maintainers privately.
