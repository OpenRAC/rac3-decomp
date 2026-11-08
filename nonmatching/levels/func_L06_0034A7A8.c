/* func_L06_0034A7A8: Opus handoff (prep by Sonnet worker w8, 2026-11-08)
   Size: 20168 bytes, places: 2 levels (06, ...), file: src/levels/shared/L06_0034A2B8.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: one function (one prologue addiu sp,-0x1C0, one real jr ra), 4884 instr, 454 jal; 1 jump table jtbl_002BD000 (40 entries, 38 distinct targets); 167 VU0 macro instructions (lqc2/sqc2/vadd.xyz/vsub.xyz) and 128-bit sq.
   rac2 twin: none. part3 best func_L11_00425F10 at 0.20; no callee-twin overlap. Boss/enemy AI state machine in the same family as the L20/L24/L08/L01 slate (moby_anim_blend x89, moby_set_state x72, vec_distance_xy x34, anim_frame_reached x25, atan2 x24, approach_eased x20, coll_line x16).
   Mapping: n/a. Globals: D_L06_001DEA4C x18, D_1A4BE0 x13, D_L06_001E8460 x12.
   Identical / changed / added / removed: not applicable (no twin).
   Draft: none compiled. m2c fails (jtbl target label inside a delay slot). The API job notes (rac3-api/jobs/func_L06_0034A7A8/RESULTS.md) already map the head: signature void f(Moby *m), s21=m, s22=m->vars (+0x68), func_L01_0044C108(m)==0 returns; func_L06_0034F670(m) nonzero or ld vars+0x908 nonzero -> func_003C2880(m) kill tail, a 30-argument call func_L01_003303B8 (prototype in src/levels/shared/L01_0035BF48.c line 54) reached from three places (goto or let cross-jumping merge); pre-switch switch(m->u95) cases 0-3 (retail tests ==1, <2, ==2, ==3).
   Left for Opus: VU0 sites need the j-form inline asm of Matching-Patterns.md (vadd.xyz/lqc2/sqc2 around u128_t copies); 128-bit sq $0 (sq $zero) cannot come from plain C: note it. Work the 40-case dispatch at jtbl_002BD000 case by case. Not a quick MATCH.
*/
#if 0
/* no compiling draft; see the notes above */
#endif
