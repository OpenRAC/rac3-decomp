/* func_L39_004ECE38: Opus handoff (prep by Sonnet worker w8, 2026-11-08)
   Size: 8376 bytes, places: 1 level (39), file: src/levels/39_multiplayer_menu/L39_004ECE38.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: NOT ONE FUNCTION: the 0x20B8 bytes hold 11 separate functions (each with its own prologue and jr ra), the catalogue entry only names the first. Starts (frame): 004ECE38 (0xA0, ends jr ra at 004ED214, about 0x3E0 B), 004ED228 (0x160), 004ED578 (0xB0), 004ED6A8 (0xA0, three jr ra), 004ED888 (0x60), 004EDE58 (0x130), 004EE378 (0x40), 004EE670 (0x2F0), 004EE958 (0xD0), 004EEBC0 (0xE0), 004EED58 (0xB0, ends jr ra at 004EEEE8; padding to 004EEEF0). No switch, no float memory ops, 115 jal in total.
   rac2 twin: no whole-function twin (part3 best func_L13_0040A720 at 0.08, meaningless for a merged chunk). They are multiplayer-menu UI routines (callees func_L39_004BC6C8 x10, 004FC1A0 x10, 004FC370 x8, 004FC780, 004FFAF0, 004FC228, 004EA5A8, 004BEED8, 004BEF28, 004F9340; func_11D534 = memset-like x4). Each is a few hundred bytes: the right unit of work.
   Mapping: n/a.
   Identical / changed / added / removed: not applicable (no twin).
   Draft: none. The earlier API job (rac3-api/jobs/func_L39_004ECE38/RESULTS.md) came to the same finding.
   Left for Opus: LEAD ACTION: split the catalogue entry into 11 functions at the starts above (config/levels/functions.tsv + the asm split) so each can be checked on its own; the 11 are small, no-float, no-switch menu routines and likely quick wins for phase 2 once split. Until then none can be matched.
*/
#if 0
/* no compiling draft; see the notes above */
#endif
