/* func_L20_003D0910: Opus handoff (prep by Sonnet worker w8, 2026-11-08)
   Size: 22240 bytes, places: 1 level (20), file: src/levels/20_final_boss/L20_003CE2D0.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division (float constants inline: needs --as ps2as)
   Step 0: one function (one prologue addiu sp,-0x150, shared epilogue .L003D5FA8), 5381 instr, 510 jal, 4 jump-table uses: jtbl_002C8C90 (8 entries, selector a0->0x95) and jtbl_002C8CB0 (36 entries, 31 distinct targets, selector a0->0x20-2); 88 lq/sq.
   rac2 twin: none. part3 best func_L11_00420C88 at opcode ratio 0.17; callee-set search (jal targets mapped to rac2 twins) found 0 mapped callees, so no rac2 routine shares its calls. It is the final-boss (Dr. Nefarious) AI/state machine: moby_set_state x52, moby_anim_blend x57, rand_range_signed x46, rand_range x23, atan2 x19, moby_point_position x18, anim_frame_reached x13, particle_spawn_sprite x10. rac3 siblings of this shape (boss update loops: L06_0034A7A8, L08_003A4E60, L24_00352060, L01_003A0778) are in the same slate and share the callees but not the code.
   Mapping: n/a (no twin). Globals: D_1A4BE0 x32 (game state), D_L20_001D66B0 x22, D_1A4C60 x21, D_L20_00220258 x16, D_L20_001E2E80 x12, D_L20_002203C8 x12. gp ops 27 (0x2344($gp), 0x233C($gp), -0x621C($gp), -0x6108($gp)).
   Identical / changed / added / removed: not applicable (no twin).
   Draft: none. m2c fails on this function (delay slot: jal func_003C3938 followed by b). The earlier API job (rac3-api/jobs/func_L20_003D0910/RESULTS.md) gave up because its brief forbade 128-bit copies; here `u128_t` copies are allowed (88 lq/sq = `*(u128_t*)d = *(u128_t*)s;`, e.g. 003D0C28: copy of D_L20_0021E880[idx]->0x10 into a0->0x10).
   Left for Opus: split by switch case and write one case at a time through chk.sh with the full retail range (003D0910-003D5FF0); decide the lq/sq via u128_t first (check one 16-byte copy at 003D0C28); the 36-entry table is a state dispatch (a0->0x20 - 2): start with the shared prologue + dispatch and the epilogue, then the 8-entry sub-dispatch. Expect hours: not a candidate for a quick MATCH.
*/
#if 0
/* no compiling draft; see the notes above */
#endif
