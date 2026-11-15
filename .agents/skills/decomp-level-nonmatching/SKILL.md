---
name: decomp-level-nonmatching
description: Retry the remaining nonmatching functions of a rac3-decomp PAL level after a previous matching pass, using saved drafts and failed-attempt evidence.
---

# Retry a level's remaining functions

Use this workflow when the user asks for another pass on functions left after level matching. Creating or editing the skill does not start matching. Respond in Portuguese; write artifacts in English.

Input: a level number, optionally specific catalogue functions or an attempt limit. Default to one bounded research pass over every eligible remaining function in that level. Do not inherit the first-pass minimum of 20 matches: the objective is to improve or resolve previous failures, with no guaranteed match count.

## Establish scope and baseline

Read [the existing level workflow](../decomp-level/SKILL.md) for preparation, repository rules, toolchain discovery, closed batches, integration, review, and publication boundaries. Reuse those safeguards, but replace its candidate selection and first-attempt/escalation loop with this skill. Do not invoke its whole first-pass workflow, create a fresh branch automatically, or restart already successful functions.

Read AGENTS.md and its required documentation before changing anything. Check coordination issue #3 before selecting a level scope. Do not post or edit the user's coordination comment. Inspect the current branch and preserve prior integrated matches and all unrelated work. Resume the level's existing branch when appropriate; if first-pass work is already merged, start a retry branch from current master without recreating the original patch. Use an isolated worktree when needed and ensure the local skill/agent files are accessible there.

Verify the full PAL level build prints MATCH before integration. Capture the baseline repository-check results so later reports distinguish existing problems from new ones. The user has confirmed this machine has no NTSC-U disc: do not repeatedly request it or attempt carry_us.sh when its retail inputs are absent. Continue PAL research and PAL builds, reporting US carry as unavailable and version-map synchronization errors as a known limitation. Do not claim NTSC-U validation, report the repository check as passing, or waive unrelated failures. Follow AGENTS.md's commit/push requirements; local PAL progress can remain reviewable without claiming an all-green result.

## Build the retry queue

Cross-reference all three sources rather than trusting old draft filenames alone:

1. Current INCLUDE_ASM markers in `src/levels/<level>/`, with owners and flags from the catalogue/configuration.
2. `nonmatching/levels/func_LNN_XXXXXXXX.c`, their header comments, and corresponding rows of nonmatching/README.md.
3. The level's wiki Open problems, prior experiment notes available in scratch or Git history, and current `tools/todo.py --target level_NN` output.

Default scope is functions owned by the requested level, still represented by INCLUDE_ASM. Prioritize saved near misses, but include eligible remaining markers without drafts so failed first-pass work is not silently lost. Shared functions owned by another level require the user's expanded scope. Exclude already integrated C even if an old draft remains; report stale/orphaned drafts separately without deleting them. Treat obsolete function splits and missing catalogue mappings as evidence to investigate, not names to guess.

For each candidate record: catalogue name, owner and flags, retail assembly/size, best draft, old difference count and its provenance, prior approaches, documented blocker, and a plausible new route. Missing history does not prevent a retry: reproduce the current assembly-to-C comparison and mark unknown history explicitly.

Order by likely payoff: small localized residuals, newly available matched twins or recipes, missing padding/declarations, then harder scheduling/allocation and large reconstructions. Do not silently drop documented Open problems; re-evaluate each against current evidence and record a reason for any structural skip.

## Research with a dedicated retry agent

Delegate one function at a time to `.codex/agents/rac3-rematcher.toml` (`gpt-6.1-sol`, high). This skill explicitly requests delegation. Use the client's custom agent type, or pass that file's developer_instructions and model/effort through a supported generic spawn with fresh context. Do not run the initial rac3-matcher followed by rac3-matcher-fable again by default: a saved failed draft is sufficient prior evidence for the rematcher.

Use closed batches bounded by available session slots, with one private scratch directory per worker. No src/ or config/ integration while workers are reading the shared context. Only the coordinator updates tables or runs full builds; delegate an exclusive build slot to rac3-checker at the end. If delegation/models are unavailable, state that limitation and continue serially with the same research rules when feasible.

Brief each worker with the assembly, owning C (read-only), file flags, saved draft and README entry, failed approaches, current relevant wiki headings, symbol/catalogue lookup, and exact scratch path. Ask it to:

- Copy and recheck the best draft before editing; old diff counts may be stale.
- Identify new evidence and state a concrete hypothesis before compiling a new wording.
- Inspect current twins, prototypes, address forms, aliasing, register allocation, and documented recipes according to the residual, rather than repeating a blind search.
- Keep a compact ledger of hypotheses, exact commands, baseline/best differences, and rejected forms. Preserve the best candidate through regressions.
- Respect the repository stop rules: about ten compiles without improvement, three wordings yielding the same wrong bytes, or proof of a structural/nonfunction blocker. More reasoning does not authorize ordinary EE asm, artificial barriers, volatile on game data, hardcoded addresses, or per-function flags.
- Return a candidate MATCH, improved NEAR, unchanged NEAR/FAIL, or structural SKIP, with evidence and a next-retry condition. A snippet MATCH remains provisional.

For remaining markers without a usable draft, reconstruct a baseline from retail and label it as newly reconstructed; do not pretend it improved an older attempt. Fix missing divs_nops evidence between batches and recheck before attributing progress to C changes. Keep flags per file and apply vector helpers at all file sites or none, as the base workflow requires.

## Preserve improvements and integrate proven matches

Independently rerun each best candidate. Compare against the reproduced baseline, not only the historical reported score. Integrate only a candidate matching the owning file's flags, then run the complete level build and require MATCH before counting it. If integration fails, correct or revert only this pass's integration; preserve the scratch candidate and previous working PAL matches.

For an improved near miss, update the saved draft and README row with the command, current flags, baseline-to-best difference counts, residuals, new approaches, and stopping reason. Preserve useful prior-attempt notes and provenance. Keep the existing draft when the new candidate is worse or unchanged; add concise new negative evidence only when it prevents wasted future work. Do not churn files solely to say they were retried.

Never delete a draft or README row you did not create. If a function now integrates and an older draft remains, report it as resolved historical material and follow the repository's approved cleanup process rather than silently removing another person's file. Ensure draft/README consistency after any permitted cleanup.

Update the existing level wiki section only with genuinely new findings, resolving obsolete open-problem descriptions where warranted. Run symbol resolution, progress regeneration, PAL builds, and relevant tests as the base workflow requires. Give rac3-checker the retry baseline, changed functions, expected marker count, config evidence, and the confirmed missing-disc limitation. Ask it to distinguish PAL success, unavailable US verification, and any new regressions.

## Finish one bounded pass

Track every queued function as integrated MATCH, improved NEAR, unchanged attempt, structural SKIP, or unavailable input. A worker's stop condition ends that attempt; do not immediately restart the same function under another agent name to evade it. Stop after one pass over the selected queue or the user's attempt limit. Later invocations start from the improved drafts and recorded negative evidence, rather than resetting the same search.

Report counts in each category and a compact per-function table with baseline/best differences, result, and remaining blocker. Include exact PAL build results, tests, known US limitation, artifact paths, and unattempted functions/reasons. Do not commit, push, or open a PR solely because this skill was loaded; preserve the user's actual authorization and all publication limits from the base workflow.
