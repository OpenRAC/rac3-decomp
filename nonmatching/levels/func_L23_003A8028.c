/* func_L23_003A8028: Opus handoff (prep by Sonnet worker w8, 2026-11-08)
   Size: 6032 bytes, places: 1 level (23, Holostar Studios Clank), file: src/levels/23_holostar_studios_clank/L23_003A6688.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: one function (one prologue addiu sp,-0x1B0), 1448 instr, 128 jal, no switch, 165 float memory ops, heavy randomness (rand_range x39, rand_below x12, rand_int x10).
   rac2 twin: none. part3 best func_L04_003FA7E0 at 0.21; 1 callee maps to a rac2 twin. A Clank-level effect/spawn routine: randomised particle/colour code (colour_lerp x5, vec_set_length x6, vec_scale x3, local L23_00453470 x3, 13D3E0 x4).
   Mapping: n/a. Globals: D_L23_001DEC40 x8, D_L23_002BC7F8 x6, D_L23_001D66B0 x4, D_L23_001E1A40 x4, D_L23_001D676C/6764 x4.
   Identical / changed / added / removed: not applicable (no twin).
   Draft: none. m2c fails (label ._m2c_.L003A88D4before refers to a delay slot).
   Left for Opus: work-around for m2c: copy the delay-slot instruction to the jump sources; or write directly, it has no switch: straight-line randomised sequences, so the field offsets from the asm map 1:1 to a struct.
*/
#if 0
/* no compiling draft; see the notes above */
#endif
