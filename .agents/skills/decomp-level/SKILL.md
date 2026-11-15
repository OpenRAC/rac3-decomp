---
name: decomp-level
description: Coordinate matching a rac3-decomp PAL level with scratch-only matchers and independent verification. Invoke explicitly with $decomp-level and a level number.
---

# Match a PAL level

Adapted from this project's Claude/Kilo decomp-level workflow for Codex. Respond to the user in Portuguese; write repository artifacts, comments, notes, and commits in English. Start this workflow only when explicitly invoked. Creating or editing this skill does not invoke it.

Input: level number, optional minimum new matches (default 20), and any scope or publication limits. Work only on remaining `func_LNN_XXXXXXXX` markers owned by `src/levels/<level>/`; exclude shared functions owned elsewhere. If fewer eligible functions remain than requested, attempt them all. Report attempted functions separately from integrated matches.

## Prepare

1. Read the root AGENTS.md completely and its required README, CONTRIBUTING, build-fidelity, and wiki pages. Also read docs/build/levels.md and docs/build/globals.md. The current repository rules take precedence over older matching recipes, including historical per-function flag advice.
2. Read coordination issue #3 at https://github.com/OpenRAC/rac3-decomp/issues/3 before selecting matching work. Confirm the contributor's comment and unclaimed scope. The user reserves their own scope: do not post or edit comments. If their comment is missing or the scope is held by someone else, explain what they must resolve before matching.
3. Inspect Git status and remotes. Preserve all existing uncommitted work, including local agent/skill files. Never delete, stash, commit, or overwrite unrelated work. Prefer an isolated worktree if necessary; remember untracked local agent/skill files do not automatically follow into it. Confirm `fork` before any operation that depends on it.
4. For a new matching branch use `match/level-NN-small` based on fetched `origin/master`. Resume an existing branch instead of recreating it. Inspect local/remote divergence before updating. Merge newer master rather than rebasing published work; regenerate conflicting generated reports and ask the user about conflicts in other people's source/config/docs. The requested minimum counts new work only.
5. Discover the actual Python environment, retail inputs, and toolchains. Prefer `venv/bin/python` if present. Existing local defaults are `UYA_TOOLCHAIN=~/sn`, `UYA_RUNNER=~/bin/wibo`, and `UYA_EE29=~/ee-gcc2.9-991111-win`; verify them rather than assuming another machine has them. Use the repository's documented toolchain bundle for carry_us.sh.
6. Verify a baseline with `timeout 1200 venv/bin/python tools/build_levels.py --setup NN -j 4 --toolchain ~/sn --runner ~/bin/wibo --ee29 ~/ee-gcc2.9-991111-win`, substituting discovered paths. Require the level's `MATCH` before integrating. Report baseline failures without silently repairing unrelated code.
7. Read docs/wiki/Matching-Patterns.md completely as the coordinator, saving its heading index with `rg -n '^#'`. Subagents read only relevant sections. Locate recipes by current heading, never fixed line numbers. If a referenced heading changed, pass the new heading in briefings. Verify required tools and tables exist before using them.

Give a short plan with branch/baseline state, eligible candidates, existing/new match counts, selected documentation sections, and batch size. Continue through all eligible candidates with escalation where useful; a requested minimum is not a guarantee that functions will match.

## Team and batches

Use the project agents in `.codex/agents/`:

| Agent | Role | Model |
| --- | --- | --- |
| rac3-matcher | First attempt on one function in private scratch | gpt-6.1-terra, medium |
| rac3-matcher-fable | Second attempt after an actual NEAR/FAIL; legacy name | gpt-6.1-sol, high |
| rac3-checker | Independent integrated-work review | gpt-6.1-terra, high |
| rac3-haiku | Bounded mechanical joins, lookup helpers, log summaries | gpt-6-luna, high |

This skill explicitly requests delegation. Select the corresponding custom agent type when the client exposes it. If only generic spawning is available, read the TOML's developer_instructions and pass them with the briefing, plus its configured model/effort when supported. Use a fresh context (`fork_turns="none"` where available) and a unique scratch directory for each function. If delegation or a configured model is unavailable, report the limitation; do not pretend the specialized agent ran or switch to a different provider silently.

Run closed batches of up to six matchers, bounded by the actual session's available slots. Wait for the whole batch before modifying src/ or config/. Checkers and the coordinator must never run full builds concurrently. No subagent may integrate source, change tables, or make commits. The coordinator owns planning, integration, escalation, and final decisions.

Each briefing includes catalogue name, retail address/size, bucket, assembly path, owning C path (read-only), scratch path, level and .lit boundary, address-to-catalogue helper, relevant draft/twin, two to four current documentation headings, and previous attempts when escalating. The matcher already reads the general codegen and allocation sections: do not copy the whole wiki into its context.

## Candidates and matching evidence

- Cross-reference remaining markers, config/levels/functions.tsv, and `tools/todo.py --target level_NN --tsv <scratch-path>`. Start with small plain functions, then switches/MMI and genuine VU0, leaving very large reconstructions last. Skip proven handwritten code and invalid function splits. Use existing nonmatching drafts and matched twins before commissioning fresh reconstructions.
- Generate an address-to-catalogue lookup from the TSV's level places. Distinguish level data from resident core data using section boundaries, and use `_sda` slot names where appropriate; bare level addresses are not catalogue names.
- For missing division-padding rows, reuse tools/gen_divs_nops.py logic in a scratch helper. Validate against existing rows for generated assembly, excluding branch delay-slot nops. Never generate another level's assembly solely to test the helper. If no reference row is available, record that limitation for the checker. Only the coordinator updates config/levels/divs_nops.txt, between batches.
- Recheck a NEAR that only lacks padding before escalation. Send genuine NEAR/FAIL cases to rac3-matcher-fable with the best C, residuals, failed approaches, and recipes tried. Do not escalate structural nonfunctions or repeatedly documented unreachable forms. Keep localized near misses in nonmatching/levels/ with the corresponding README entry; retain INCLUDE_ASM.
- Stop an individual attempt after about ten compiles without improvement or three distinct wordings yielding identical wrong bytes. Record exact commands, counts, remaining differences, recipes, open-problem classes, and config evidence in scratch notes. Infrastructure failures are not matching failures: report them and retry within available, authorized models without inventing Kilo provider chains.

## Integrate and verify

Independently rerun each candidate's check.py command. Integrate only C that matches with the owning file's flags, wrapped in localdecomp markers. Remove its marker and obsolete jump-table INCLUDE_RODATA where appropriate. Check declaration conflicts in the actual file, not just a snippet. Flags remain per file; never invent per-function overrides or split files merely to isolate a stubborn function without original-object evidence.

Follow current AGENTS.md for permitted assembly, volatile memory, extern globals, source provenance, and vector helpers. Check all sites in a file before integrating a helper. Do not add a new vector-library helper without the user's approval and the required evidence.

Between batches run resolve_symbols.py for the level, progress.py --write, and the complete level build. A function counts only once that build prints `MATCH`. After any src/ change run the required `TOOLCHAINS=<verified-bundle> JOBS=32 sh tools/carry_us.sh` when its retail inputs are available. The user has confirmed this machine has no NTSC-U disc: skip the unavailable carry step, continue local PAL matching, and report US verification as unavailable. Record version-map synchronization errors against the baseline as a known limitation without treating the repository check as passing or claiming US validation. Do not waive unrelated failures or the repository's commit/push requirements.

Run unit tests and tests/check_repository.py before any commit, and the required core full build with its three MATCH lines for changes affecting that build. Preserve a green build and required checks; do not commit or push an unverified result merely to complete the workflow. Scope commits to this task, with a Conventional Commit subject and a body explaining changes and exact verification, without AI attribution trailers. Use an existing configured Git identity; do not change Git configuration or guess author details.

Update the existing level section of Matching-Patterns.md, or add one in the established format, with only new recipes and concrete unresolved drafts. Search for duplicates first. Explain variants/counterexamples and update older open problems that were resolved. Keep substantive research notes separate from matching implementation commits when appropriate.

After all workers and builds stop, delegate independent review to rac3-checker. Supply the comparison base, changed functions, expected marker count, config changes and evidence, baseline limitations, US carry result, and exclusive build-slot permission. Fix concrete findings and rerun affected checks. Report any remaining failure as a failure, not a match.

## Delivery and authorization

Report integrated matches, near misses, ineligible/unattempted functions, exact full-build MATCH lines, test results, US carry status, and remaining limitations. Produce any requested final research summary outside the repository only at an authorized location.

Keep publishing within the user's requested scope. Prepare a concrete verified branch before asking for any required publication approval. If a push to `fork` was authorized, use it; never infer that permission solely from loading this skill. Before publication, fetch master and check whether the reviewed branch includes it. If a separate PR branch is necessary, preserve unrelated changes and revalidate the actual proposed branch rather than relying on another branch's checker result.

Ask before opening the upstream PR, pushing to origin, force-pushing, changing Git configuration, editing issue #3, or deleting data. Do not change the original Claude/Kilo configuration as part of this Codex workflow.
