/* func_L01_003A0778: Opus handoff (prep by Sonnet worker w8, 2026-11-08)
   Size: 11336 bytes, places: 7 levels, file: src/levels/shared/L01_0039E1B0.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: one function (one prologue addiu sp,-0x130), 2791 instr, 248 jal; two jump tables jtbl_002BEE70 (12 entries, 8 distinct) and jtbl_002BEEA0 (20 entries, 15 distinct).
   rac2 twin: none. part3 best func_L13_0040A720 at opcode ratio 0.24 (a rac3 L13 *_ai matched file, not rac2); callee-set check: 4 callees map to rac2 twins, no rac2 function shares 3 of them. Enemy/boss AI of the Veldin level (moby_set_state x38, moby_anim_blend x30, vec_distance_xy x18, rand_int x11, rand_range x11, walker_set_params x8, particle_spawn_sprite x8). Check the matched L13/L02 *-ai.c files in rac3 src (src/levels/shared/L13_0040A720-ai.c) for the idioms before writing.
   Mapping: n/a. Globals: D_L01_001DFC4C x22, D_L01_001E0100 x10, D_L01_00221098 x8, D_1426E0 x5. gp ops 25.
   Identical / changed / added / removed: not applicable (no twin).
   Draft: none. m2c fails: "Label .L003A1BA4 refers to a delay slot" (a branch-likely target one instruction into a delay slot); add a nop at the jump sources in a copy of target.s to run m2c.
   Left for Opus: first work the two dispatches (12 and 20 entries, selector a0->0x20-style state) and the epilogue; write case by case; 122 fp load/stores so floats come via lui/mtc1 (try --as ps2as if consts differ).
*/
#if 0
/* no compiling draft; see the notes above */
#endif
