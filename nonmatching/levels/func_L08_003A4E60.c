/* func_L08_003A4E60: Opus handoff (prep by Sonnet worker w8, 2026-11-08)
   Size: 8420 bytes, places: 1 level (08, Aquatos), file: src/levels/08_aquatos/L08_003A4E60.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: one function (one prologue addiu sp,-0x1D0), 2061 instr, 222 jal; jump table jtbl_002BE8F0 (16 entries, 16 distinct = one case per state). spimdisasm tags it "Handwritten function" only because of 7 `neg $2,$2` instructions. Each is the second half of a `blezl $2, 1f; neg $2, $2` pair, the game's integer abs: write it abs_asm() (include/vu0.h; SN cc1 never emits the trapping `neg` itself). It is compiled C, not hand-written asm.
   rac2 twin: none. part3 best func_L04_0044DB18 at 0.25; 2 callees map to rac2 twins, no rac2 function shares them. Aquatos boss AI (moby_set_state x28, moby_anim_blend x21, vec_distance_xy x16, atan2 x13, vec_set_length x8, local L08_003A6F48 x11).
   Mapping: n/a. Globals: D_L08_001DEECC x14, D_L08_001DF300 x6.
   Identical / changed / added / removed: not applicable (no twin).
   Draft: none. m2c fails: "Cannot find jtbl target .L00000000" (a zero entry in the table is a no-case slot).
   Left for Opus: the 7 negations come from `-x` on ints; write the 16-case dispatch first. Also check that the state machine reuses L08_003A6F48 (a local helper called 11 times) with matched siblings.
*/
#if 0
/* no compiling draft; see the notes above */
#endif
