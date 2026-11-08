/* func_L24_00352060: Opus handoff (prep by Sonnet worker w8, 2026-11-08)
   Size: 10468 bytes, places: 1 level (24, Insomniac Museum), file: src/levels/24_insomniac_museum/L24_003519E8.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: one function (one prologue addiu sp,-0xB0), 2585 instr, 250 jal; jump tables jtbl_002BCC80 (8 entries, 6 distinct) and jtbl_002BCCA0 (28 entries, 21 distinct); 57 $gp operations (many small gp globals).
   rac2 twin: none. part3 best func_L13_00406F18 at 0.22 (rac3 L13 ai file); no rac2 callee overlap. Museum boss/enemy AI (moby_anim_blend x45, moby_set_state x44, vec_distance_xy x22, walker_set_params x9, atan2 x9, rand_range x9, local L24 helpers 003554A8 x7, 003556A8 x4).
   Mapping: n/a. Globals: D_L24_001DF600 x6, D_L24_0021D600 x4, D_L24_001DF0C0 x4; D_L24 small gp-addressed variables (declare them sized: Matching-Patterns "Globals: gp vs lui").
   Identical / changed / added / removed: not applicable (no twin).
   Draft: none; m2c fails (jtbl target / delay-slot).
   Left for Opus: split by dispatch case; settle the $gp globals first (57 gp ops), since a wrong sized/unsized extern shifts every address.
*/
#if 0
/* no compiling draft; see the notes above */
#endif
