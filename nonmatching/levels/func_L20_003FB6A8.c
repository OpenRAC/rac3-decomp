/* func_L20_003FB6A8: Opus handoff (prep by Sonnet worker w7, 2026-11-08)
   Size: 10560 bytes, places: 1 levels (20), file: src/levels/20_final_boss/L20_003FB630.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: one function (addiu sp,-0x150), 7 switches / 3 jump tables (7+ entries): +0x95, +0x20, a +0x3E0 field, and TWO overlapping switches on the +0x3E4 sub-state (m2c 'irregular switch 5/6' with case labels inside nested ifs; the draft deletes the duplicate labels).
   Twin: rac3 near-sibling func_L05_003560C8 (opcode ratio 0.64, 3019 vs 2640 insns, 1823 equal opcodes; unmatched too, not in scope). rac2 best func_L13_00406F18 0.16. Corpus search otherwise empty.
   Mapping: Common enemy/boss scaffold (matches the tools' names): arg0 = moby; +0x20 = state byte (func_L01_004450F0 = moby_set_state(moby, state, sub)), +0x95 = phase byte, +0x68 = per-object data, func_L01_004561B8 = animation-done test, func_003C3A10 = moby_anim_blend(moby, anim, 0, 8), func_0038CB00 = timer_tick_short, D_1A4BE0 = hero/global struct (+0x25C0 hero moby, +0x25C4 hero state, +0xC08 pad bits). $gp loads are named D_<0x1DC8B0+offset> (D_LNN_ when >= 0x1D9900) in the draft. Own callees: func_L20_003FB3B0 (x19), func_L20_003FB570, func_L20_003FF170, func_L05_0035AA68 (x18, shared with the L05 sibling), func_L05_00355C48, func_L05_00355DD8. Globals D_L20_001DF5C0.. (float constants, lui+lwc1), D_L20_0021CFE0 (table).
   Identical / changed / added / removed: vs func_L05_003560C8: identical opcode runs at 003FBD9C-003FBE28/00356818 (35), 003FC12C-003FC1EC/00356D78 (48), 003FC698-003FC750/003572C4 (46), 003FC99C-003FCA78/00357648 (55), 003FCB9C-003FCC68/00357988 (51), 003FCD68-003FCE98/00357CB8 (76), 003FCEC0-003FCF74/00357E94 (45); the L20 function drops 003FB728-003FB870 (82) and 003FBAB0-003FBAF4 / 003FBBC8-003FBC80 (46), the L05 one has an extra 138-insn block at 00356198-003563C0.
   VU0: 0 vadd.xyz/vsub.xyz ops in the retail asm; inline-asm VU0 is banned since 2026-11-06 (Matching-Patterns), so this function cannot reach MATCH unless the ops come from plain C; the lq/sq copies are fine (u128_t). NO VU0 here: matchable in principle.
   Draft: compiles (m2c draft cleaned by tools/post.py (real repo prototypes where known, m2c gotos kept)); 2590 diff; opcode-equal 1746 of 2641 (mine 2342), ratio 0.70.
     Retail rows yours=2342 retail=2641 equalrows=51.
   Left for Opus:
     1. THIS ONE HAS NO VU0 OPS (only 55 lq/sq word copies), so it is the only one in the slate that can actually MATCH.
     2. Fix the overlapping +0x3E4 switches (draft lines ~952-1000): retail has one jump table (jtbl_002C8F30) over the sub-state with shared tail blocks; write it as a single switch with fall-through/gotos from the retail case addresses.
     3. Opcode ratio 0.70 and the first 'shape' differences are in the prologue (frame 0x150).
     4. func_L05_003560C8 is a 3 KB sibling: matching this one first gives the L05 one almost for free (and vice versa).
*/
extern f32 func_003824E0(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38();
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern int func_L01_004561B8(u8 *);
extern int func_L01_004561E0(void *a0);
extern s32 func_00382468();
extern s32 func_00382498(s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern s32 func_003A52A0();
extern s32 func_L01_00445AD0(s32, s32, s32);
extern s32 func_L01_0045A9F0(void *);
extern s32 func_L01_0045BD10(u8 *, f32);
extern s32 func_L01_004AAC98(s32, s32, s32, s32);
extern s32 func_L20_003FB3B0(void *);
extern void func_003C2880(s32 p);
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_00409598(u8 *, u8 *, u8 *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00445BE0(s32, s32);
extern void func_L01_00459188(u8 *, u8 *, u8 *);
extern void func_L01_004591B8(void *, void *, void *);
extern void func_L01_0045BD78(u8 *a0, f32 a, f32 b, f32 c, f32 d);
extern void func_L01_0045C150(void *, void *, s32, s32);
extern void func_L01_004AA7E8(s32, s32);
f32 *func_00382348(void *);                         /* extern */
s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
f32 func_L01_004395E0(void *);                      /* extern */
s32 func_L01_004450F0();  /* extern, call arities [3, 4], m2c proto was (void *, u8, s32, void *) */
s32 func_L01_00446630(f32 *, f32 *, f32 *, void *); /* extern */
s32 func_L01_00446780();  /* K&R: prototype dropped, mismatch with m2c calls */
s32 func_L01_00454370(void *, void *);              /* extern */
s32 func_L01_00458F78(void *, void *, s32, s32); /* extern */
s32 func_L01_0045A748(void *, void *);          /* extern */
s32 func_L01_0045A7A8();  /* K&R: prototype dropped, mismatch with m2c calls */
s32 func_L01_0045A898();  /* K&R: prototype dropped, mismatch with m2c calls */
s32 func_L01_0045BDE8(void *, s32);                 /* extern */
s32 func_L01_0045C2A0(void *, f32, f32, f32);       /* extern */
s32 func_L01_0045D218(void *, void *);          /* extern */
s32 func_L03_00449C30(void *, s32);                 /* extern */
s32 func_L05_00355AE8();  /* extern, call arities [1, 2], m2c proto was (void *, s32) */
s32 func_L05_00355C48(void *);                      /* extern */
s32 func_L05_00355C70(void *);                      /* extern */
f32 func_L05_00355C98();  /* extern, call arities [3, 5], m2c proto was (void *, f32 *, f32 *, s32 *, s32) */
f32 func_L05_00355D00(void *, f32 *);               /* extern */
f32 func_L05_00355D60(void *, s32);                 /* extern */
s32 func_L05_00355DD8(void *, f32 *);           /* extern */
s32 func_L20_003FB570(void *);                  /* extern */
s32 func_L20_003FB630(void *);                  /* extern */
s32 func_L20_003FDFE8(void *);                      /* extern */
s32 func_L20_003FE9C0(void *, s32);         /* extern */
s32 func_L20_003FEBA8(void *);                  /* extern */
s32 func_L20_003FEDF0(void *);                  /* extern */
s32 func_L20_003FEF08();  /* extern, call arities [1, 2], m2c proto was (void *, s32) */
s32 func_L20_003FF170();  /* extern, call arities [1, 2], m2c proto was (void *, s32) */
s32 func_L20_003FF1F8(void *);                  /* extern */
s32 func_L20_003FF358(void *);                  /* extern */
extern s32 D_L20_001DFD40;
extern s32 D_L20_001DFE4C;
extern s32 D_L20_001E029C;
extern s32 D_L20_001E02D8;
extern s32 D_L20_001E0380;
extern s32 D_L20_0021CFE0;
extern s32 D_L20_0021E880;

extern s32 D_L20_001DEBEC;
extern s32 D_L20_001DEBF0;
extern f32 D_L20_001DF5C0;
extern f32 D_L20_001DF5C4;
extern f32 D_L20_001DF5C8;
extern f32 D_L20_001DF5CC;
extern f32 D_L20_001DF5D0;
extern f32 D_L20_001DF5D4;
extern f32 D_L20_001DF5D8;
extern f32 D_L20_001DF5DC;
extern f32 D_L20_001DF5E0;
extern f32 D_L20_001DF5E4;
extern f32 D_L20_001DF5E8;
extern f32 D_L20_001DF5EC;
extern f32 D_L20_001DF610;
extern f32 D_L20_001DF618;
extern f32 D_L20_001DF61C;
extern f32 D_L20_001DF620;
extern s32 D_L20_001DF628;
extern f32 D_L20_001DF634;
extern s32 D_L20_001DF638;
extern f32 D_L20_001DF63C;
extern f32 D_L20_001DF640;
extern s32 D_L20_001DF644;
extern s32 D_L20_001DF648;
extern f32 D_L20_001DF64C;
extern f32 D_L20_001DF654;
extern f32 D_L20_001DF658;
extern f32 D_L20_001DF65C;
extern f32 D_L20_001DF660;
extern s32 D_L20_001DF664;
extern s32 D_L20_001DF668;
extern s32 D_L20_001DF66C;
extern f32 D_L20_001DF670;
extern s32 D_L20_001E029C;
extern s32 D_L20_001E02D8;

void func_L20_003FB6A8(void *arg0) {
    f32 sp90;
    f32 spA0;
    f32 spB0;
    f32 spC0;
    f32 spD0;
    f32 spE0;
    s32 var_10;
    s32 var_5_2;
    s32 var_5_3;
    s32 var_5_6;
    s32 var_5_7;
    s32 var_5_8;
    s32 var_6;
    s32 var_6_2;
    s32 var_7;
    s32 var_8;
    s32 var_9;
    s32 var_f12;
    s32 temp_f0_2;
    s32 var_f0;
    f32 *temp_4_3;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 var_f12_2;
    f32 var_f13;
    f32 var_f14;
    f32 var_f15;
    f32 var_f20;
    f32 var_f20_2;
    f32 var_f20_3;
    s32 *temp_7_2;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_3_12;
    s32 temp_3_13;
    s32 temp_4_8;
    s32 temp_4_9;
    s32 temp_5_16;
    s32 temp_5_2;
    s32 temp_5_5;
    s32 temp_5_6;
    s32 temp_5_7;
    s32 temp_5_8;
    s32 temp_5_9;
    s32 var_16;
    s32 var_17;
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_2_4;
    s32 var_2_5;
    s32 var_2_6;
    s32 var_2_7;
    s32 var_2_8;
    s32 var_2_9;
    u16 *temp_3_7;
    u16 temp_3_10;
    u32 temp_3_9;
    u8 temp_2;
    u8 temp_3;
    u8 temp_3_5;
    u8 temp_4_5;
    u8 temp_5_10;
    u8 temp_5_11;
    u8 temp_5_12;
    u8 temp_5_13;
    u8 temp_5_14;
    u8 temp_5_15;
    u8 temp_5_17;
    u8 temp_5_18;
    u8 var_5;
    u8 var_5_4;
    u8 var_5_9;
    u8 *temp_16;
    u8 *temp_16_10;
    u8 *temp_16_2;
    u8 *temp_16_3;
    u8 *temp_16_4;
    u8 *temp_16_5;
    u8 *temp_16_6;
    u8 *temp_16_7;
    u8 *temp_16_8;
    u8 *temp_16_9;
    u8 *temp_19;
    u8 *temp_21;
    u8 *temp_22;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_3_11;
    u8 *temp_3_14;
    u8 *temp_3_15;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_3_4;
    u8 *temp_3_6;
    u8 *temp_3_8;
    u8 *temp_4;
    u8 *temp_4_10;
    u8 *temp_4_11;
    u8 *temp_4_12;
    u8 *temp_4_13;
    u8 *temp_4_2;
    u8 *temp_4_4;
    u8 *temp_4_6;
    u8 *temp_4_7;
    u8 *temp_5;
    u8 *temp_5_3;
    u8 *temp_5_4;
    u8 *temp_7;
    u8 *var_4;
    u8 *var_4_2;
    u8 *var_5_5;

    temp_19 = (*(void **)((u8 *)(arg0) + 0x68));
    if (((*(s32 *)((u8 *)(temp_19) + 0x3C8)) == 0) || ((*(u8 *)((u8 *)(arg0) + 0x20)) != 7)) {
        if (func_L20_003FDFE8(arg0) == 0) {
            if (D_L20_001DEBEC != 0) {
                if (D_L20_001DEBF0 == 0) {
                    if ((*(s16 *)((u8 *)(temp_19) + 0x3DA)) != 0) {
                        (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x100);
                    }
                    if ((*(f32 *)((u8 *)(temp_19) + 0x30)) <= 0.0f) {
                        func_L01_004AAC98(9, 0, (*(void **)((u8 *)(temp_19) + 0x3EC)), 0x1610);
                        func_L20_003FE9C0(arg0, 0);
                        var_4 = arg0 + 0x10;
                        var_6 = 0x19;
                        var_7 = 0x14;
                        var_8 = 0x14;
                        var_f12 = 0x3F800000;
                        var_9 = 0x14;
                        var_10 = 0x2D;
                        goto block_49;
                    }
                    temp_3 = (*(u8 *)((u8 *)(arg0) + 0x95));
                    switch (temp_3) {               /* switch 1 */
                    case 0:                         /* switch 1 */
                        if ((func_L01_004561E0(arg0) != 0) && ((*(s16 *)((u8 *)(temp_19) + 0x3D6)) == 0)) {
                            (*(s16 *)((u8 *)(temp_19) + 0x3D6)) = (s16) ((s32) ((func_00382498(0, 0x1E) * 5) + 2) / 6);
                        }
                        if (((*(s32 *)((u8 *)(temp_19) + 0x3A0)) != 0) && (((u8) (*(u16 *)((u8 *)(arg0) + 0x34)) ^ 1) & 1)) {
                            (*(s32 *)((u8 *)(arg0) + 0x98)) = 0;
                            (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x41) & 0xEFFF);
                            func_L01_004AA7E8(arg0, 1);
                            temp_3_2 = (*(void **)((u8 *)(temp_19) + 0x3EC));
                            (*(u16 *)((u8 *)(temp_3_2) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_3_2) + 0x34)) | 0x41);
                            temp_4 = (*(void **)((u8 *)(temp_19) + 0x3EC));
                            (*(u16 *)((u8 *)(temp_4) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_4) + 0x34)) & 0xEFFF);
                            (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x98)) = 0;
                            func_L01_004AA7E8((*(void **)((u8 *)(temp_19) + 0x3EC)), 1);
                            temp_3_3 = (*(void **)((u8 *)(temp_19) + 0x3EC));
                            (*(u16 *)((u8 *)(temp_3_3) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_3_3) + 0x34)) | 2);
                            temp_4_2 = (*(void **)((u8 *)(temp_19) + 0x3EC));
                            (*(u16 *)((u8 *)(temp_4_2) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_4_2) + 0x34)) | 4);
                        }
                        if ((((*(s16 *)((u8 *)(temp_19) + 0x234)) == 1) && (func_0038CB00(temp_19 + 0x3D6) != 0)) || ((*(s16 *)((u8 *)(temp_19) + 0x3D8)) != 0)) {
                            temp_7 = (*(void **)((u8 *)(temp_19) + 0x3EC));
                            (*(u16 *)((u8 *)(temp_7) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_7) + 0x34)) & 0xFFFD);
                            temp_3_4 = (*(void **)((u8 *)(temp_19) + 0x3EC));
                            (*(u16 *)((u8 *)(temp_3_4) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_3_4) + 0x34)) & 0xFFFB);
                            func_L01_004450F0(arg0, 0xAU, 2, temp_7);
                            if ((*(s32 *)((u8 *)(temp_19) + 0x3A0)) != 0) {
                                func_L01_00409598(arg0, arg0 + 0x10, arg0 + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                                temp_5 = (*(void **)((u8 *)(temp_19) + 0x3EC));
                                func_L01_00409598((*(void **)((u8 *)(temp_19) + 0x3EC)), temp_5 + 0x10, temp_5 + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                                (*(s32 *)((u8 *)(temp_19) + 0x3A0)) = 0;
                            }
                        }
                    default:                        /* switch 1 */
block_55:
                        temp_2 = (*(u8 *)((u8 *)(arg0) + 0x20));
                        switch (temp_2) {           /* switch 2 */
                        case 1:                     /* switch 2 */
                            if (func_L01_004561B8(arg0) != 0) {
                                func_L01_0045BD78(arg0, D_L20_001DF5D4 * 0.00040000002f, D_L20_001DF5D0 * 0.020000001f, D_L20_001DF5DC * 0.017453292f * 0.00040000002f, D_L20_001DF5D8 * 0.017453292f * 0.020000001f);
                                if ((*(s32 *)((u8 *)(temp_19) + 0x390)) != -1) {
                                    func_L05_0035AA68(arg0, 4, 0, 8);
                                    temp_16 = *(((*(s32 *)((u8 *)(temp_19) + 0x390)) * 4) + &D_L20_0021E880);
                                    sp90 = (*(f32 *)((u8 *)(temp_16) + 0x10));
                                    temp_f20 = func_L05_00355D00(arg0, &sp90);
                                    spA0 = *(((*(s32 *)((u8 *)(temp_16) + 0)) * 0x10) + temp_16);
                                    var_2 = 1;
                                    if (!(func_L05_00355D00(arg0, &spA0) < temp_f20)) {
                                        var_2 = 0;
                                    }
                                    if (var_2 & 0xFF) {
                                        func_L01_0045C150(arg0, temp_16, 0, (*(s32 *)((u8 *)(temp_16) + 0)) - 1);
                                    } else {
                                        func_L01_0045C150(arg0, temp_16, (*(s32 *)((u8 *)(temp_16) + 0)) - 1, 0);
                                    }
                                } else if ((*(s32 *)((u8 *)(temp_19) + 0x3FC)) != 0) {
                                    func_003C3A10(arg0, 0x13, 0, 0);
                                    func_003C3A10((*(void **)((u8 *)(temp_19) + 0x3EC)), 2, 0, 0);
                                    (*(s32 *)((u8 *)(temp_19) + 0xA8)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0xA8)) | 0x404);
                                } else if ((*(u8 *)((u8 *)(arg0) + 0x95)) == 1) {
                                    func_L05_0035AA68(arg0, 0, 0, 8);
                                } else {
                                    func_L05_0035AA68(arg0, 2, 0, 8);
                                }
                            }
                            temp_5_2 = (*(s32 *)((u8 *)(temp_19) + 0x390));
                            if (temp_5_2 != -1) {
                                if ((*(s16 *)((u8 *)(temp_19) + 0x3DA)) != 0) {
                                    var_2_2 = func_L03_00449C30(arg0, temp_5_2);
                                } else {
                                    var_2_2 = func_L01_0045BDE8(arg0, temp_5_2);
                                }
                                if (var_2_2 != 0) {
                                    var_5 = 1;
                                    goto block_468;
                                }
                            } else if (func_00382468() == 0) {
                                var_5 = 2;
block_468:
                                func_L01_004450F0(arg0, var_5, -1);
                            }
                            break;
                        case 2:                     /* switch 2 */
                            if (func_L01_004561B8(arg0) != 0) {
                                if (func_L20_003FB3B0(arg0) != 0) {
                                    if ((*(u8 *)((u8 *)(arg0) + 0x95)) == 1) {
                                        var_5_2 = 1;
                                    } else {
                                        var_5_2 = 3;
                                    }
                                    func_003C3A10((*(void **)((u8 *)(temp_19) + 0x3EC)), var_5_2, 0, 8);
                                } else if ((*(u8 *)((u8 *)(arg0) + 0x95)) == 1) {
                                    func_L05_0035AA68(arg0, 1, 0, 8);
                                } else {
                                    func_L05_0035AA68(arg0, 3, 0, 8);
                                }
                            }
                            if ((*(u8 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x60)) & 2) {
block_466:
                                var_5 = (*(u8 *)((u8 *)(arg0) + 0x94));
                                goto block_468;
                            }
                            break;
                        case 3:                     /* switch 2 */
                            if ((D_L20_001DFD40 >= 3) && ((temp_16_2 = D_L20_001E029C + ((*(s32 *)((u8 *)(temp_19) + 0x3A4)) << 8), temp_4_3 = func_00382348(temp_16_2), (temp_16_2 == 0)) || (temp_3_5 = (*(u8 *)((u8 *)(temp_16_2) + 0x20)), (temp_3_5 == 0xFE)) || (temp_3_5 == 0xFD) || ((temp_4_3 != 0) && (*temp_4_3 <= 0.0f)))) {
                                (*(f32 *)((u8 *)(temp_19) + 0x350)) = (f32) (*(f32 *)((u8 *)((((*(s32 *)((u8 *)(temp_19) + 0x3A4)) << 8) + D_L20_001E029C)) + 0x10));
                                if (func_0038CAD0(temp_19 + 0x3C4) != 0) {
                                    (*(s32 *)((u8 *)(temp_19) + 0x3A0)) = 0;
                                    (*(s32 *)((u8 *)(temp_19) + 0x3A4)) = -1;
block_110:
                                    func_L01_004450F0(arg0, 1U, 0);
                                    func_L01_00409598(arg0, arg0 + 0x10, arg0 + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                                    temp_5_3 = (*(void **)((u8 *)(temp_19) + 0x3EC));
                                    func_L01_00409598((*(void **)((u8 *)(temp_19) + 0x3EC)), temp_5_3 + 0x10, temp_5_3 + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                                    temp_3_6 = (*(void **)((u8 *)(temp_19) + 0x3EC));
                                    (*(u16 *)((u8 *)(temp_3_6) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_3_6) + 0x34)) | 2);
                                    temp_4_4 = (*(void **)((u8 *)(temp_19) + 0x3EC));
                                    (*(u16 *)((u8 *)(temp_4_4) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_4_4) + 0x34)) | 4);
                                }
                            }
                            break;
                        case 4:                     /* switch 2 */
                            if ((D_L20_001DFD40 >= 3) && (func_L01_00445AD0((*(s32 *)((u8 *)(temp_19) + 0x3A8)), -1, 1) == 0)) {
block_108:
                                if (func_0038CAD0(temp_19 + 0x3C4) != 0) {
                                    (*(s32 *)((u8 *)(temp_19) + 0x3A0)) = 0;
                                    goto block_110;
                                }
                            }
                            break;
                        case 5:                     /* switch 2 */
                            if (func_L01_004561B8(arg0) != 0) {
                                (*(s32 *)((u8 *)(temp_19) + 0x3E4)) = 0;
                            }
                            if (D_L20_001DFD40 >= 3) {
                                if ((*(s32 *)((u8 *)(temp_19) + 0x3E4)) == 0) {
                                    if ((*(s32 *)((u8 *)(temp_19) + 0x39C)) > 0) {
                                        (*(s32 *)((u8 *)(temp_19) + 0x3E4)) = 1;
                                        temp_4_5 = (*(u8 *)((u8 *)(arg0) + 0x21));
                                        temp_3_7 = *((temp_4_5 * 4) + &D_L20_0021CFE0);
                                        if ((temp_3_7 != 0) && ((s32) temp_4_5 < D_L20_001E02D8)) {
                                            temp_4_6 = (*(void **)((u8 *)((((*temp_3_7 & 0x7FFF) << 8) + D_L20_001E029C)) + 0x68));
                                            (*(s32 *)((u8 *)(temp_4_6) + 0x39C)) = (s32) ((*(s32 *)((u8 *)(temp_4_6) + 0x39C)) - 1);
                                        }
                                    }
                                    if ((*(s32 *)((u8 *)(temp_19) + 0x3E4)) != 0) {
                                        goto block_108;
                                    }
                                } else {
                                    goto block_108;
                                }
                            }
                            break;
                        case 8:                     /* switch 2 */
                            if (func_L01_004561B8(arg0) != 0) {
                                (*(f32 *)((u8 *)(temp_19) + 0x1BC)) = 2.0f;
                                (*(s32 *)((u8 *)(temp_19) + 0x1B8)) = 0x40000000;
                            }
                            temp_f1 = (*(f32 *)((u8 *)(temp_19) + 0x3B0));
                            if (temp_f1 < 1.0f) {
                                temp_f0 = temp_f1 + D_L20_001DF610;
                                (*(f32 *)((u8 *)(temp_19) + 0x3B0)) = temp_f0;
                                if (temp_f0 > 1.0f) {
                                    (*(f32 *)((u8 *)(temp_19) + 0x3B0)) = 1.0f;
                                }
                                (*(f32 *)((u8 *)(arg0) + 0x2C)) = (f32) ((*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x24))) + 0x24)) * (*(f32 *)((u8 *)(temp_19) + 0x3B0)));
                                temp_3_8 = (*(void **)((u8 *)(temp_19) + 0x3EC));
                                (*(f32 *)((u8 *)(temp_3_8) + 0x2C)) = (f32) ((*(f32 *)((u8 *)((*(void **)((u8 *)(temp_3_8) + 0x24))) + 0x24)) * (*(f32 *)((u8 *)(temp_19) + 0x3B0)));
                            }
                            temp_2_2 = (*(void **)((u8 *)(temp_19) + 0x3F0));
                            if (temp_2_2 != 0) {
                                (*(s32 *)((u8 *)(temp_2_2) + 0x98)) = 0;
                            }
                            if (func_L01_0045C2A0(arg0, D_L20_001DF618, D_L20_001DF61C, D_L20_001DF620) != 0) {
                                (*(s32 *)((u8 *)(arg0) + 0x48)) = 0x3F800000;
                                (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x48)) = 0x3F800000;
                                func_L01_0045A9F0(arg0);
                                (*(f32 *)((u8 *)(temp_19) + 0x1BC)) = 0.3f;
                                (*(s32 *)((u8 *)(temp_19) + 0x1B8)) = 0;
                                if ((*(s16 *)((u8 *)(temp_19) + 0x3BA)) != 0) {
                                    func_L01_004450F0(arg0, 9U, 5);
                                    var_5_3 = 4;
                                } else {
                                    func_L01_004450F0(arg0, 1U, 0);
                                    var_5_3 = 0;
                                }
                                func_L05_0035AA68(arg0, var_5_3, 0, 8);
                            } else {
                                temp_2_3 = (*(void **)((u8 *)(temp_19) + 0x3EC));
                                if (temp_2_3 != 0) {
                                    (*(s32 *)((u8 *)(temp_2_3) + 0x48)) = (s32) (*(s32 *)((u8 *)(arg0) + 0x48));
                                }
                            }
                            temp_4_7 = (*(void **)((u8 *)(temp_19) + 0x3F0));
                            if (temp_4_7 != 0) {
                                (*(s32 *)((u8 *)(temp_4_7) + 0x98)) = (s32) (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_4_7) + 0x24))) + 0x10));
                            }
                            break;
                        case 9:                     /* switch 2 */
                            if (func_L01_004561B8(arg0) != 0) {
                                func_L01_0045BD78(arg0, D_L20_001DF5D4 * 0.00040000002f, D_L20_001DF5D0 * 0.020000001f, D_L20_001DF5DC * 0.017453292f * 0.00040000002f, D_L20_001DF5D8 * 0.017453292f * 0.020000001f);
                            }
                            temp_2_4 = arg0 + 0x10;
                            temp_5_4 = temp_19 + 0x360;
                            if (func_0038CF38() > 0.5f) {
                                func_L01_0045A748(arg0, temp_5_4);
                            } else {
                                func_L01_0045A898(arg0, temp_5_4, (*(f32 *)((u8 *)(temp_19) + 0x3B4)));
                            }
                            if ((*(s16 *)((u8 *)(temp_19) + 0x234)) == 1) {
                                func_L01_004450F0(arg0, 0xAU, 2);
                            } else if (func_0038CF38() <= (*(f32 *)((u8 *)(temp_19) + 0xA4))) {
                                if ((*(f32 *)((u8 *)(temp_19) + 0xA0)) < fabsf(func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xF8)), (*(f32 *)((u8 *)(temp_19) + 0x3B4))))) {
                                    func_L01_0045BD10(arg0, (*(f32 *)((u8 *)(temp_19) + 0x3B4)));
                                } else {
                                    func_L01_0045BD78(arg0, D_L20_001DF5C4 * 0.00040000002f, D_L20_001DF5C0 * 0.020000001f, D_L20_001DF5CC * 0.017453292f * 0.00040000002f, D_L20_001DF5C8 * 0.017453292f * 0.020000001f);
                                    func_L01_004450F0(arg0, 1U, 0);
                                    func_L05_0035AA68(arg0, 0, 0, 8);
                                }
                            }
                            break;
                        case 10:                    /* switch 2 */
                            if (func_L01_004561B8(arg0) != 0) {
                                (*(u8 *)((u8 *)(arg0) + 0xBE)) = (u8) ((*(u8 *)((u8 *)(arg0) + 0xBE)) & 0xFE);
                                func_L20_003FEDF0(arg0);
                                if ((*(s16 *)((u8 *)(temp_19) + 0x3F4)) != 0) {
                                    var_f14 = D_L20_001DF5DC * 0.017453292f;
                                    var_f15 = D_L20_001DF5D8 * 0.017453292f;
                                    var_f12_2 = D_L20_001DF5D4;
                                    var_f13 = D_L20_001DF5D0;
                                    goto block_144;
                                }
                                if (func_L20_003FB3B0(arg0) != 0) {
                                    var_f14 = D_L20_001DF5EC * 0.017453292f;
                                    var_f15 = D_L20_001DF5E8 * 0.017453292f;
                                    var_f12_2 = D_L20_001DF5E4;
                                    var_f13 = D_L20_001DF5E0;
block_144:
                                    func_L01_0045BD78(arg0, var_f12_2 * 0.00040000002f, var_f13 * 0.020000001f, var_f14 * 0.00040000002f, var_f15 * 0.020000001f);
                                } else {
                                    func_L01_0045BD78(arg0, D_L20_001DF5C4 * 0.00040000002f, D_L20_001DF5C0 * 0.020000001f, D_L20_001DF5CC * 0.017453292f * 0.00040000002f, D_L20_001DF5C8 * 0.017453292f * 0.020000001f);
                                }
                                (*(s32 *)((u8 *)(temp_19) + 0x3E4)) = 0;
                                var_f20 = func_003824E0(5.0f, 10.0f) * 0.017453292f;
                                if (func_00382468() != 0) {
                                    var_f20 = -var_f20;
                                }
                                (*(f32 *)((u8 *)(temp_19) + 0x3E8)) = var_f20;
                            }
                            temp_3_9 = (*(u32 *)((u8 *)(temp_19) + 0x3E0));
                            switch (temp_3_9) {     /* switch 3 */
                            case 0:                 /* switch 3 */
                                temp_16_3 = temp_19 + 0x250;
                                if (func_L01_004561B8(arg0) != 0) {
                                    func_L20_003FB630(arg0);
                                    func_L01_00459188(arg0, (*(s32 *)((u8 *)(temp_19) + 0x230)), temp_16_3);
                                }
                                temp_5_5 = (*(s32 *)((u8 *)(temp_19) + 0x230));
                                if (temp_5_5 != (*(s32 *)((u8 *)(temp_19) + 0x2A0))) {
                                    func_L01_00459188(arg0, temp_5_5, temp_16_3);
                                }
                                func_L01_00458F78(arg0, temp_16_3, 0, 0);
                                func_L01_0045A7A8(arg0, temp_16_3, (*(f32 *)((u8 *)(temp_19) + 0x3E8)));
                                if (func_L20_003FEF08(arg0) != 0) {
                                    temp_3_10 = (*(u16 *)((u8 *)(arg0) + 0x96));
                                    if ((temp_3_10 >= 0x33U) && ((temp_3_10 >= 0x65U) || (func_00382468() == 0)) && (func_L05_00355C70(arg0) != 0)) {
                                        var_5_4 = 0xB;
                                        if (func_L20_003FF170(arg0) != 0) {
block_255:
                                            func_L01_004450F0(arg0, var_5_4, -1);
                                        }
                                    }
                                }
                                break;
                            case 1:                 /* switch 3 */
                                if (func_L01_004561B8(arg0) != 0) {
                                    func_L20_003FB630(arg0);
                                    if ((*(s16 *)((u8 *)(temp_19) + 0x3DA)) == 0) {
                                        func_L01_00459188(arg0, (*(s32 *)((u8 *)(temp_19) + 0x230)), temp_19 + 0x250);
                                        goto block_165;
                                    }
                                    goto block_166;
                                }
block_165:
                                temp_5_6 = (*(s32 *)((u8 *)(temp_19) + 0x230));
                                if ((*(s16 *)((u8 *)(temp_19) + 0x3DA)) != 0) {
block_166:
                                    func_L01_0045D218(arg0, (*(s32 *)((u8 *)(temp_19) + 0x230)) + 0x10);
                                } else {
                                    temp_16_4 = temp_19 + 0x250;
                                    if (temp_5_6 != (*(s32 *)((u8 *)(temp_19) + 0x2A0))) {
                                        func_L01_00459188(arg0, temp_5_6, temp_16_4);
                                    }
                                    func_L01_00458F78(arg0, temp_16_4, 0, 0);
                                    func_L01_0045A7A8(arg0, temp_16_4, (*(f32 *)((u8 *)(temp_19) + 0x3E8)));
                                }
                                break;
                            case 4:                 /* switch 3 */
                                sp90 = (*(f32 *)((u8 *)(temp_19) + 0x350));
                                if (func_L05_00355D00(arg0, &sp90) < 0.75f) {
                                    if ((func_L20_003FB3B0(arg0) == 0) && (func_L05_00355C48(arg0) == 0)) {
                                        func_L01_004450F0(arg0, 0xDU, -1);
                                    } else {
                                        func_L01_004450F0(arg0, 0xBU, -1);
                                    }
                                    (*(s32 *)((u8 *)(arg0) + 0x48)) = 0;
                                    (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x48)) = 0;
                                    (*(s32 *)((u8 *)(temp_19) + 0x3DC)) = 0;
                                } else {
                                    if (func_L01_004561B8(arg0) != 0) {
                                        func_L20_003FB630(arg0);
                                        if ((*(s16 *)((u8 *)(temp_19) + 0x3DA)) == 0) {
                                            spA0 = (*(f32 *)((u8 *)(temp_19) + 0x350));
                                            func_L01_004591B8(arg0, &spA0, temp_19 + 0x250);
                                            goto block_179;
                                        }
                                        goto block_187;
                                    }
block_179:
                                    if ((*(s16 *)((u8 *)(temp_19) + 0x3DA)) == 0) {
                                        temp_16_5 = temp_19 + 0x250;
                                        func_L01_00458F78(arg0, temp_16_5, 0, 0);
                                        var_5_5 = temp_16_5;
block_248:
                                        func_L01_0045A748(arg0, var_5_5);
                                    } else {
block_187:
                                        func_L01_0045D218(arg0, temp_19 + 0x350);
                                    }
                                }
                                break;
                            case 5:                 /* switch 3 */
                                sp90 = (*(f32 *)((u8 *)(temp_19) + 0x350));
                                if (func_L05_00355D00(arg0, &sp90) < 0.75f) {
                                    (*(s32 *)((u8 *)(temp_19) + 0x388)) = -1;
                                    func_L20_003FF358(arg0);
                                    func_L01_004450F0(arg0, 0xAU, 2);
                                } else {
                                    if (func_L01_004561B8(arg0) != 0) {
                                        func_L20_003FB630(arg0);
                                        if ((*(s16 *)((u8 *)(temp_19) + 0x3DA)) == 0) {
                                            spA0 = (*(f32 *)((u8 *)(temp_19) + 0x350));
                                            func_L01_004591B8(arg0, &spA0, temp_19 + 0x250);
                                            goto block_186;
                                        }
                                        goto block_187;
                                    }
block_186:
                                    if ((*(s16 *)((u8 *)(temp_19) + 0x3DA)) != 0) {
                                        goto block_187;
                                    }
                                    temp_16_6 = temp_19 + 0x250;
                                    func_L01_00458F78(arg0, temp_16_6, 0, 0);
                                    var_5_5 = temp_16_6;
                                    goto block_248;
                                }
                                break;
                            case 3:                 /* switch 3 */
                                if (func_L01_004561B8(arg0) != 0) {
                                    func_L20_003FB630(arg0);
                                    temp_16_7 = *(((*(s32 *)((u8 *)(temp_19) + 0x380)) * 4) + &D_L20_0021E880);
                                    if ((*(s16 *)((u8 *)(temp_19) + 0x3F6)) != 0) {
                                        sp90 = (*(f32 *)((u8 *)(temp_16_7) + 0x10));
                                        temp_f20_2 = func_L05_00355D00(arg0, &sp90);
                                        spA0 = *(((*(s32 *)((u8 *)(temp_16_7) + 0)) * 0x10) + temp_16_7);
                                        var_2_3 = 1;
                                        if (!(func_L05_00355D00(arg0, &spA0) < temp_f20_2)) {
                                            var_2_3 = 0;
                                        }
                                        if (var_2_3 & 0xFF) {
                                            func_L01_0045C150(arg0, *(((*(s32 *)((u8 *)(temp_19) + 0x380)) * 4) + &D_L20_0021E880), 0, (*(s32 *)((u8 *)(temp_16_7) + 0)) - 1);
                                        } else {
                                            func_L01_0045C150(arg0, *(((*(s32 *)((u8 *)(temp_19) + 0x380)) * 4) + &D_L20_0021E880), (*(s32 *)((u8 *)(temp_16_7) + 0)) - 1, 0);
                                        }
                                        (*(s16 *)((u8 *)(temp_19) + 0x3F6)) = 0;
                                    }
                                }
                                temp_5_7 = (*(s32 *)((u8 *)(temp_19) + 0x380));
                                if ((*(s16 *)((u8 *)(temp_19) + 0x3DA)) != 0) {
                                    var_2_4 = func_L03_00449C30(arg0, temp_5_7);
                                } else {
                                    var_2_4 = func_L01_0045BDE8(arg0, temp_5_7);
                                }
                                if (var_2_4 != 0) {
                                    (*(s32 *)((u8 *)(temp_19) + 0x3DC)) = 0;
                                    (*(s16 *)((u8 *)(temp_19) + 0x3F6)) = 1;
                                    if (func_L05_00355C70(arg0) != 0) {
                                        if ((func_L20_003FB3B0(arg0) == 0) && (func_L05_00355C48(arg0) == 0)) {
                                            var_5_4 = 0xD;
                                        } else {
                                            var_5_4 = 0xB;
                                        }
                                    } else {
block_254:
                                        var_5_4 = 0xA;
                                    }
                                    goto block_255;
                                }
                                break;
                            case 2:                 /* switch 3 */
                                if (func_L01_004561B8(arg0) != 0) {
                                    if ((*(s32 *)((u8 *)(temp_19) + 0x3F8)) != 0) {
                                        if ((func_L20_003FB3B0(arg0) == 0) && ((*(s32 *)((u8 *)(temp_19) + 0x3FC)) == 0)) {
                                            func_L01_004450F0(arg0, 0x11U, -1);
                                        }
                                    } else {
                                        func_L20_003FB630(arg0);
                                    }
                                    temp_16_8 = *(((*(s32 *)((u8 *)(temp_19) + 0x384)) * 4) + &D_L20_0021E880);
                                    if (func_L20_003FB3B0(arg0) != 0) {
                                        func_L01_0045BD78(arg0, D_L20_001DF5E4 * 0.00040000002f, (*(f32 *)((u8 *)(temp_19) + 0x3BC)) * 0.020000001f, D_L20_001DF5EC * 0.017453292f * 0.00040000002f, D_L20_001DF5E8 * 0.017453292f * 0.020000001f);
                                    }
                                    if ((*(s16 *)((u8 *)(temp_19) + 0x3F6)) != 0) {
                                        sp90 = (*(f32 *)((u8 *)(temp_16_8) + 0x10));
                                        temp_f20_3 = func_L05_00355D00(arg0, &sp90);
                                        spA0 = *(((*(s32 *)((u8 *)(temp_16_8) + 0)) * 0x10) + temp_16_8);
                                        var_2_5 = 1;
                                        if (!(func_L05_00355D00(arg0, &spA0) < temp_f20_3)) {
                                            var_2_5 = 0;
                                        }
                                        if (var_2_5 & 0xFF) {
                                            func_L01_0045C150(arg0, *(((*(s32 *)((u8 *)(temp_19) + 0x384)) * 4) + &D_L20_0021E880), 0, (*(s32 *)((u8 *)(temp_16_8) + 0)) - 1);
                                        } else {
                                            func_L01_0045C150(arg0, *(((*(s32 *)((u8 *)(temp_19) + 0x384)) * 4) + &D_L20_0021E880), (*(s32 *)((u8 *)(temp_16_8) + 0)) - 1, 0);
                                        }
                                        (*(s16 *)((u8 *)(temp_19) + 0x3F6)) = 0;
                                    }
                                }
                                temp_5_8 = (*(s32 *)((u8 *)(temp_19) + 0x384));
                                if ((*(s16 *)((u8 *)(temp_19) + 0x3DA)) != 0) {
                                    var_2_6 = func_L03_00449C30(arg0, temp_5_8);
                                } else {
                                    var_2_6 = func_L01_0045BDE8(arg0, temp_5_8);
                                }
                                if (var_2_6 != 0) {
                                    (*(s16 *)((u8 *)(temp_19) + 0x3F6)) = 1;
                                    (*(s32 *)((u8 *)(temp_19) + 0x384)) = -1;
                                    func_L20_003FF358(arg0);
                                    func_L01_004450F0(arg0, 0xAU, 2);
                                    if (((*(s32 *)((u8 *)(temp_19) + 0x3F8)) != 0) && ((*(s32 *)((u8 *)(temp_19) + 0x3FC)) == 0)) {
                                        var_5_4 = 0x12;
                                        goto block_255;
                                    }
                                }
                                break;
                            case 6:                 /* switch 3 */
                                temp_22 = arg0 + 0x10;
                                temp_21 = temp_19 + 0x350;
                                if (func_L01_004561B8(arg0) != 0) {
                                    func_L20_003FB630(arg0);
                                    temp_4_8 = (*(s32 *)((u8 *)(temp_19) + 0x38C));
                                    if (temp_4_8 != -1) {
                                        temp_5_9 = temp_4_8 * 0x30;
                                        temp_3_11 = D_L20_001DFE4C + temp_5_9;
                                        if (((*(s16 *)((u8 *)(temp_3_11) + 0x32)) != 0) && ((*(s16 *)((u8 *)(temp_19) + 0x3F6)) != 0)) {
                                            (*(s16 *)((u8 *)(temp_19) + 0x3F6)) = 0;
                                            (*(f32 *)((u8 *)(temp_19) + 0x350)) = (f32) (*(f32 *)((u8 *)((D_L20_001E0380 + (*(*(s32 **)((u8 *)(temp_3_11) + 0x40)) << 7))) + 0x30));
                                            temp_4_9 = D_L20_001DFE4C;
                                            var_17 = 0;
                                            if ((*(s16 *)((u8 *)((temp_4_9 + temp_5_9)) + 0x32)) > 0) {
loop_234:
                                                temp_7_2 = (var_17 * 4) + (*(s32 *)((u8 *)((((*(s32 *)((u8 *)(temp_19) + 0x38C)) * 0x30) + temp_4_9)) + 0x40));
                                                temp_16_9 = D_L20_001E0380 + (*temp_7_2 << 7);
                                                sp90 = (*(f32 *)((u8 *)(temp_16_9) + 0x30));
                                                spA0 = (*(f32 *)((u8 *)(temp_19) + 0x220));
                                                temp_f20_4 = func_L05_00355C98(arg0, &sp90, &spA0, temp_7_2, D_L20_001E0380);
                                                spB0 = (*(f32 *)((u8 *)(temp_19) + 0x350));
                                                spC0 = (*(f32 *)((u8 *)(temp_19) + 0x220));
                                                if ((func_L05_00355C98(arg0, &spB0, &spC0) < temp_f20_4) || (spD0 = (*(f32 *)((u8 *)(temp_19) + 0x350)), var_2_7 = 0 & 0xFF, (func_L05_00355D00(arg0, &spD0) < 2.0f))) {
                                                    var_2_7 = 1 & 0xFF;
                                                }
                                                if (var_2_7 != 0) {
                                                    spE0 = (*(f32 *)((u8 *)(temp_16_9) + 0x30));
                                                    if (func_L05_00355D00(arg0, &spE0) > 2.0f) {
                                                        (*(f32 *)((u8 *)(temp_19) + 0x350)) = (f32) (*(f32 *)((u8 *)(temp_16_9) + 0x30));
                                                    }
                                                }
                                                var_17 += 1;
                                                if (var_17 < (*(s16 *)((u8 *)((D_L20_001DFE4C + ((*(s32 *)((u8 *)(temp_19) + 0x38C)) * 0x30))) + 0x32))) {
                                                    goto loop_234;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (func_L20_003FB3B0(arg0) != 0) {
                                    if (func_0038CF00(temp_22, temp_21) < 1.0f) {
                                        (*(s16 *)((u8 *)(temp_19) + 0x3F6)) = 1;
                                        if (func_L05_00355C70(arg0) != 0) {
                                            var_5_4 = 0xB;
                                        } else {
                                            goto block_254;
                                        }
                                        goto block_255;
                                    }
                                    var_5_5 = temp_21;
                                    goto block_248;
                                }
                                if (func_0038CF38() < 1.0f) {
                                    (*(s32 *)((u8 *)(temp_19) + 0x3DC)) = 0;
                                    (*(s16 *)((u8 *)(temp_19) + 0x3F6)) = 1;
                                    if (func_L05_00355C70(arg0) != 0) {
                                        if (func_L05_00355C48(arg0) == 0) {
                                            var_5_4 = 0xD;
                                        } else {
                                            var_5_4 = 0xB;
                                        }
                                    } else {
                                        goto block_254;
                                    }
                                    goto block_255;
                                }
                                if ((*(s16 *)((u8 *)(temp_19) + 0x3DA)) != 0) {
                                    func_L01_0045D218(arg0, temp_21);
                                } else {
                                    func_L01_0045A748(arg0, temp_21);
                                }
                                break;
                            }
                            if ((*(s32 *)((u8 *)(temp_19) + 0x394)) != 0) {
                                if ((*(s32 *)((u8 *)(temp_19) + 0x3FC)) != 0) {
                                    sp90 = (*(f32 *)((u8 *)(temp_19) + 0x220));
                                    func_L05_00355DD8(arg0, &sp90);
                                }
                                if ((*(s32 *)((u8 *)(temp_19) + 0x394)) != 0) {
                                    if (!((*(u8 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x60)) & 2)) {
                                        goto block_280;
                                    }
                                    if ((*(s32 *)((u8 *)(temp_19) + 0x3E4)) != 0) {
                                        goto block_280;
                                    }
                                    if (func_L20_003FEF08(arg0) == 0) {
block_280:
                                        switch ((*(s32 *)((u8 *)(temp_19) + 0x3E4))) { /* switch 4; irregular */
                                        case 1:     /* switch 4 */
                                            temp_4_10 = (*(void **)((u8 *)(temp_19) + 0x3EC));
                                            if ((*(u8 *)((u8 *)(temp_4_10) + 0x60)) & 2) {
                                                func_003C3A10(temp_4_10, 8, 0, 0);
                                                (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x48)) = (s32) D_L20_001DF644;
                                                (*(s32 *)((u8 *)(temp_19) + 0x3E4)) = 2;
                                                func_L20_003FF1F8(arg0);
                                            } else if (((*(s32 *)((u8 *)(temp_19) + 0x3E4)) == 2) && (temp_4_11 = (*(void **)((u8 *)(temp_19) + 0x3EC)), (((*(u8 *)((u8 *)(temp_4_11) + 0x60)) & 2) != 0))) {
                                                temp_2_5 = (*(s32 *)((u8 *)(temp_19) + 0x3DC)) + 1;
                                                (*(s32 *)((u8 *)(temp_19) + 0x3DC)) = temp_2_5;
                                                if (temp_2_5 >= 3) {
                                                    func_003C3A10(temp_4_11, 0xA, 0, 0);
                                                    (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x48)) = (s32) D_L20_001DF644;
                                                    (*(s32 *)((u8 *)(temp_19) + 0x3E4)) = 3;
                                                } else {
                                                    func_L20_003FF1F8(arg0);
                                                }
                                            } else if (((*(s32 *)((u8 *)(temp_19) + 0x3E4)) == 3) && ((*(u8 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x60)) & 2)) {
                                                var_5_6 = 2;
                                                if (func_L20_003FB3B0(arg0) != 0) {
                                                    goto block_294;
                                                }
                                                var_5_6 = 5;
                                                if ((*(s16 *)((u8 *)(temp_19) + 0x3F4)) != 0) {
block_294:
                                                    func_003C3A10((*(void **)((u8 *)(temp_19) + 0x3EC)), var_5_6, 0, 0);
                                                } else {
                                                    func_003C3A10((*(void **)((u8 *)(temp_19) + 0x3EC)), 6, 0, 0);
                                                }
                                                (*(s32 *)((u8 *)(temp_19) + 0x3E4)) = 0;
                                                (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x48)) = 0x3F800000;
                                                temp_5_10 = (*(u8 *)((u8 *)(arg0) + 0x21));
                                                if (((s32) temp_5_10 < D_L20_001E02D8) && (*((temp_5_10 * 4) + &D_L20_0021CFE0) != 0)) {
                                                    func_L01_00445BE0(temp_5_10, 0);
                                                }
                                            }
                                            break;
                                        }
                                    } else if (((((*(u8 *)((u8 *)(arg0) + 0xBC)) == 0) && (func_L20_003FF170(arg0) != 0)) || ((*(u8 *)((u8 *)(temp_19) + 0x5F)) != 0)) && (func_L05_00355C70(arg0) != 0)) {
                                        temp_5_11 = (*(u8 *)((u8 *)(arg0) + 0x21));
                                        if (((s32) temp_5_11 < D_L20_001E02D8) && (*((temp_5_11 * 4) + &D_L20_0021CFE0) != 0)) {
                                            func_L01_00445BE0(temp_5_11, 1);
                                            (*(u8 *)((u8 *)(arg0) + 0xBC)) = 0U;
                                        }
                                        func_003C3A10((*(void **)((u8 *)(temp_19) + 0x3EC)), 7, 0, 8);
                                        (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x48)) = (s32) D_L20_001DF644;
                                        (*(s32 *)((u8 *)(temp_19) + 0x3E4)) = 1;
                                        (*(s32 *)((u8 *)(temp_19) + 0x3DC)) = 0;
                                    }
                                }
                            }
                            if ((func_L20_003FB3B0(arg0) == 0) && (func_0038CF38() < D_L20_001DF64C)) {
                                var_5 = 0x10;
                                goto block_468;
                            }
                            break;
                        case 11:                    /* switch 2 */
                            if (func_L01_004561B8(arg0) != 0) {
                                if (func_L20_003FB3B0(arg0) != 0) {
                                    func_003C3A10((*(void **)((u8 *)(temp_19) + 0x3EC)), 7, 0, 8);
                                    goto block_315;
                                }
                                if (((func_0038CF38() < D_L20_001DF654) || (func_00382468() != 0)) && (func_L05_00355C48(arg0) != 0)) {
                                    if (func_L05_00355AE8(arg0) != 0) {
                                        func_003C3A10((*(void **)((u8 *)(temp_19) + 0x3EC)), 7, 0, 8);
                                        func_003C3A10(arg0, 0xC, 0, 8);
                                        goto block_314;
                                    }
                                    func_L05_0035AA68(arg0, 0xB, 0, 8);
                                } else {
                                    func_L05_0035AA68(arg0, 7, 0, 8);
block_314:
                                    (*(s32 *)((u8 *)(arg0) + 0x48)) = (s32) D_L20_001DF648;
block_315:
                                    (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x48)) = D_L20_001DF648;
                                }
                            }
                            var_f20_2 = 0.0f;
                            if (func_L20_003FB3B0(arg0) == 0) {
                                var_f20_2 = D_L20_001DF660 * 0.017453292f;
                            }
                            if (var_f20_2 < func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xF8)), func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))))) {
                                sp90 = (*(f32 *)((u8 *)(temp_19) + 0x220));
                                func_L05_00355DD8(arg0, &sp90);
                            } else {
                                func_L20_003FB570(arg0);
                            }
                            if ((*(u8 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x60)) & 2) {
                                func_L01_004450F0(arg0, 0xCU, -1);
                                if (func_L20_003FB3B0(arg0) == 0) {
block_480:
                                    (*(s32 *)((u8 *)(arg0) + 0x48)) = 0;
                                }
                                (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x48)) = 0;
                            }
                            break;
                        case 12:                    /* switch 2 */
                            if (func_L01_004561B8(arg0) != 0) {
                                if (func_L20_003FB3B0(arg0) != 0) {
                                    func_003C3A10((*(void **)((u8 *)(temp_19) + 0x3EC)), 8, 0, 0);
                                } else if (func_L05_00355AE8(arg0, 8) != 0) {
                                    func_L05_0035AA68(arg0, 0xC, 0, 0);
                                } else {
                                    func_L05_0035AA68(arg0, 8, 0, 0);
                                }
                                (*(s32 *)((u8 *)(arg0) + 0x48)) = 0x3F800000;
                                (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x48)) = 0x3F800000;
                            }
                            var_f20_3 = 0.0f;
                            if (func_L20_003FB3B0(arg0) == 0) {
                                var_f20_3 = D_L20_001DF660 * 0.017453292f;
                            }
                            if (var_f20_3 < func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xF8)), func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))))) {
                                sp90 = (*(f32 *)((u8 *)(temp_19) + 0x220));
                                func_L05_00355DD8(arg0, &sp90);
                            } else {
                                func_L20_003FB570(arg0);
                            }
                            if (((s32) ((D_L20_001DF66C * 5) + 2) / 6) >= (s32) (*(u16 *)((u8 *)(arg0) + 0x96))) {
                                goto block_347;
                            }
                            if ((*(u8 *)((u8 *)(temp_19) + 0x5F)) == 0) {
                                if ((*(u8 *)((u8 *)(arg0) + 0xBC)) == 0) {
                                    if (func_L20_003FF170(arg0, 0xE) != 0) {
                                        goto block_342;
                                    }
                                    goto block_346;
                                }
block_346:
block_347:
                                if ((((s32) ((D_L20_001DF668 * 5) + 2) / 6) < (s32) (*(u16 *)((u8 *)(arg0) + 0x96))) || (func_L20_003FEF08(arg0, (s32) (*(u16 *)((u8 *)(arg0) + 0x96))) == 0)) {
                                    func_L01_004450F0(arg0, 0xAU, 2);
                                    if ((*(u8 *)((u8 *)(arg0) + 0xBC)) == 0) {
                                        temp_5_12 = (*(u8 *)((u8 *)(arg0) + 0x21));
                                        if (((s32) temp_5_12 < D_L20_001E02D8) && (*((temp_5_12 * 4) + &D_L20_0021CFE0) != 0)) {
                                            func_L01_00445BE0(temp_5_12, 0);
                                        }
                                    }
                                } else if ((func_L20_003FB3B0(arg0) == 0) && (func_0038CF38() < D_L20_001DF64C)) {
                                    func_L01_004450F0(arg0, 0xAU, -1);
                                    var_5 = 0x10;
                                    goto block_468;
                                }
                            } else {
block_342:
                                func_L01_004450F0(arg0, 0xEU, -1);
                                temp_5_13 = (*(u8 *)((u8 *)(arg0) + 0x21));
                                if (((s32) temp_5_13 < D_L20_001E02D8) && (*((temp_5_13 * 4) + &D_L20_0021CFE0) != 0)) {
                                    func_L01_00445BE0(temp_5_13, 1);
                                    (*(u8 *)((u8 *)(arg0) + 0xBC)) = 0U;
                                }
                            }
                            break;
                        case 13:                    /* switch 2 */
                            if (func_L01_004561B8(arg0) != 0) {
                                if (func_L05_00355AE8(arg0) == 0) {
                                    (*(s32 *)((u8 *)(temp_19) + 0x3E4)) = 0;
                                    func_003C3A10(arg0, 0xB, 0, 8);
                                    func_003C3A10((*(void **)((u8 *)(temp_19) + 0x3EC)), 2, 0, 8);
                                } else {
                                    (*(s32 *)((u8 *)(temp_19) + 0x3E4)) = 1;
                                    func_003C3A10(arg0, 0xC, 0, 8);
                                    func_003C3A10((*(void **)((u8 *)(temp_19) + 0x3EC)), 2, 0, 8);
                                }
                            }
                            if ((D_L20_001DF660 * 0.017453292f) < func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xF8)), func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))))) {
                                sp90 = (*(f32 *)((u8 *)(temp_19) + 0x220));
                                func_L05_00355DD8(arg0, &sp90);
                            } else {
                                func_L20_003FB570(arg0);
                            }
                            temp_3_12 = (*(s32 *)((u8 *)(temp_19) + 0x3E4));
                            switch (temp_3_12) {    /* switch 5; irregular */
                            case 0:                 /* switch 5 */
                                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                                    (*(s32 *)((u8 *)(temp_19) + 0x3E4)) = 1;
                                    func_003C3A10(arg0, 0xC, 0, 8);
                                    var_4_2 = (*(void **)((u8 *)(temp_19) + 0x3EC));
                                    var_5_7 = 2;
block_475:
                                    func_003C3A10(var_4_2, var_5_7, 0, 8);
                                } else {
                                    switch (temp_3_12) { /* switch 6; irregular */
                                    case 1:         /* switch 5 */
                                        if ((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 0x65U) {
                                            if (((*(u8 *)((u8 *)(temp_19) + 0x5F)) != 0) || (((*(u8 *)((u8 *)(arg0) + 0xBC)) == 0) && (func_L20_003FF170(arg0) != 0))) {
                                                temp_5_14 = (*(u8 *)((u8 *)(arg0) + 0x21));
                                                if (((s32) temp_5_14 < D_L20_001E02D8) && (*((temp_5_14 * 4) + &D_L20_0021CFE0) != 0)) {
                                                    func_L01_00445BE0(temp_5_14, 1);
                                                    (*(u8 *)((u8 *)(arg0) + 0xBC)) = 0U;
                                                }
                                                if (func_L05_00355C48(arg0) != 0) {
                                                    if ((func_0038CF38() < D_L20_001DF654) || (func_00382468() == 0)) {
                                                        var_5_8 = 0xC;
                                                    } else {
                                                        goto block_379;
                                                    }
                                                } else {
block_379:
                                                    var_5_8 = 0xE;
                                                }
                                                func_003C3A10(arg0, var_5_8, 0, 8);
                                                func_003C3A10((*(void **)((u8 *)(temp_19) + 0x3EC)), 7, 0, 8);
                                                (*(s32 *)((u8 *)(temp_19) + 0x3E4)) = 3;
                                            }
                                        } else if (temp_3_12 == 2) {
                                        case 2:     /* switch 5 */
                                            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                                                func_L05_0035AA68(arg0, 8, 0, 8);
                                                var_f0 = D_L20_001DF648;
                                                (*(s32 *)((u8 *)(temp_19) + 0x3E4)) = 3;
block_455:
                                                (*(s32 *)((u8 *)(arg0) + 0x48)) = var_f0;
                                                (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x48)) = var_f0;
                                            } else {
                                                goto block_385;
                                            }
                                        } else {
block_385:
                                            if ((temp_3_12 == 3) && (((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) || ((*(u8 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x60)) & 2))) {
                                                var_5_9 = 0xC;
block_478:
                                                var_6_2 = -1;
block_479:
                                                func_L01_004450F0(arg0, var_5_9, var_6_2);
                                                goto block_480;
                                            }
                                        }
                                        break;
                                    }
                                }
                                break;
                            }
                            break;
                        case 14:                    /* switch 2 */
                            if (func_L01_004561B8(arg0) != 0) {
                                (*(s16 *)((u8 *)(temp_19) + 0x3D8)) = 0;
                                (*(s32 *)((u8 *)(temp_19) + 0x3DC)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0x3DC)) + 1);
                                func_L20_003FF1F8(arg0);
                                if (func_L20_003FB3B0(arg0) == 0) {
                                    func_003C3A10((*(void **)((u8 *)(temp_19) + 0x3EC)), 0xC, 0, 2);
                                    if (func_L05_00355AE8(arg0) != 0) {
                                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xD) {
                                            func_003C3A10(arg0, 0xD, 0, 2);
                                        }
                                    } else if (((*(u8 *)((u8 *)(arg0) + 0x42)) == 7) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 9)) {
                                        func_003C3A10(arg0, 9, 0, 2);
                                    }
                                }
                                temp_f0_2 = D_L20_001DF628;
                                (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x48)) = temp_f0_2;
                                (*(s32 *)((u8 *)(arg0) + 0x48)) = temp_f0_2;
                            }
                            func_L20_003FB570(arg0);
                            var_16 = 0;
                            if ((*(u8 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x60)) & 2) {
                                if ((func_L20_003FF170(arg0) != 0) && (((func_L05_00355AE8(arg0) != 0) && (func_L05_00355C48(arg0) != 0)) || (func_L05_00355C70(arg0) != 0))) {
                                    var_16 = 1;
                                }
                                if (((*(s32 *)((u8 *)(temp_19) + 0x3DC)) < 0xA) && (var_5 = 0xE, (var_16 != 0))) {

                                } else {
                                    (*(s16 *)((u8 *)(temp_19) + 0x3D8)) = 0;
                                    (*(s32 *)((u8 *)(temp_19) + 0x3DC)) = 0;
                                    var_5 = 0xF;
                                }
                                goto block_468;
                            }
                            break;
                        case 15:                    /* switch 2 */
                            if (func_L01_004561B8(arg0) != 0) {
                                if ((*(u8 *)((u8 *)(arg0) + 0xBC)) == 0) {
                                    temp_5_15 = (*(u8 *)((u8 *)(arg0) + 0x21));
                                    if (((s32) temp_5_15 < D_L20_001E02D8) && (*((temp_5_15 * 4) + &D_L20_0021CFE0) != 0)) {
                                        func_L01_00445BE0(temp_5_15, 0);
                                    }
                                }
                                if ((u32) ((*(u32 *)((u8 *)(temp_19) + 0x3E0)) - 4) < 2U) {
                                    if (func_L20_003FB3B0(arg0) != 0) {
                                        func_L01_004450F0(arg0, 0xCU, -1);
                                        goto block_426;
                                    }
                                    if (func_L05_00355AE8(arg0) != 0) {
                                        var_5 = 0xC;
                                    } else if (func_L05_00355C48(arg0) == 0) {
                                        var_5 = 0xD;
                                    } else {
                                        var_5 = 0xC;
                                    }
                                    goto block_468;
                                }
                                if (func_L20_003FB3B0(arg0) != 0) {
                                    func_003C3A10((*(void **)((u8 *)(temp_19) + 0x3EC)), 0xE, 0, 8);
                                } else if (func_L05_00355AE8(arg0, 0xE) != 0) {
                                    func_L05_0035AA68(arg0, 0xE, 0, 8);
                                } else {
                                    func_L05_0035AA68(arg0, 0xA, 0, 8);
                                }
                                goto block_426;
                            }
block_426:
                            func_L20_003FB570(arg0);
                            if ((*(u8 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x60)) & 2) {
                                var_5_9 = 0xA;
                                var_6_2 = 2;
                                goto block_479;
                            }
                            break;
                        case 16:                    /* switch 2 */
                            if (func_L01_004561B8(arg0) != 0) {
                                func_L01_00459188(arg0, (*(s32 *)((u8 *)(temp_19) + 0x230)), temp_19 + 0x250);
                                if (func_L05_00355AE8(arg0) != 0) {
                                    (*(s32 *)((u8 *)(temp_19) + 0x3E4)) = 0;
                                    func_003C3A10(arg0, 0xE, 0, 8);
                                } else if (func_0038CF38() <= D_L20_001DF634) {
                                    (*(s32 *)((u8 *)(temp_19) + 0x3E4)) = 2;
                                    if (((*(u8 *)((u8 *)(arg0) + 0x42)) != 0xF) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xF)) {
                                        func_L05_0035AA68(arg0, 0xF, 0, 8);
                                    }
                                    (*(s32 *)((u8 *)(arg0) + 0x48)) = D_L20_001DF638;
                                    (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x48)) = D_L20_001DF638;
                                } else {
                                    (*(s32 *)((u8 *)(temp_19) + 0x3E4)) = 1;
                                    func_003C3A10(arg0, 6, 0, 8);
                                }
                            }
                            temp_3_13 = (*(s32 *)((u8 *)(temp_19) + 0x3E4));
                            switch (temp_3_13) {    /* switch 7; irregular */
                            case 0:                 /* switch 7 */
                                sp90 = (*(f32 *)((u8 *)(temp_19) + 0x220));
                                func_L05_00355DD8(arg0, &sp90);
                                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                                    sp90 = (*(f32 *)((u8 *)(temp_19) + 0x220));
                                    var_2_8 = 1;
                                    if (!(func_L05_00355D00(arg0, &sp90) <= D_L20_001DF634)) {
                                        var_2_8 = 0;
                                    }
                                    if (!(var_2_8 & 0xFF)) {
                                        (*(s32 *)((u8 *)(temp_19) + 0x3E4)) = 1;
                                        func_003C3A10(arg0, 6, 0, 0);
                                    } else {
block_454:
                                        (*(s32 *)((u8 *)(temp_19) + 0x3E4)) = 2;
                                        func_L05_0035AA68(arg0, 0xF, 0, 0);
                                        var_f0 = D_L20_001DF638;
                                        goto block_455;
                                    }
                                }
                                break;
                            case 1:                 /* switch 7 */
                                if ((*(s16 *)((u8 *)(temp_19) + 0x3DA)) != 0) {
                                    func_L01_0045D218(arg0, (*(s32 *)((u8 *)(temp_19) + 0x230)) + 0x10);
                                } else {
                                    temp_5_16 = (*(s32 *)((u8 *)(temp_19) + 0x230));
                                    temp_16_10 = temp_19 + 0x250;
                                    if (temp_5_16 != (*(s32 *)((u8 *)(temp_19) + 0x2A0))) {
                                        func_L01_00459188(arg0, temp_5_16, temp_16_10);
                                    }
                                    func_L01_00458F78(arg0, temp_16_10, 0, 0);
                                    func_L01_0045A748(arg0, temp_16_10);
                                }
                                sp90 = (*(f32 *)((u8 *)(temp_19) + 0x220));
                                var_2_9 = 1;
                                if (!(func_L05_00355D00(arg0, &sp90) <= D_L20_001DF634)) {
                                    var_2_9 = 0;
                                }
                                if (var_2_9 & 0xFF) {
                                    goto block_454;
                                }
                                break;
                            case 2:                 /* switch 7 */
                                temp_f20_5 = func_L01_004395E0(arg0);
                                sp90 = (*(f32 *)((u8 *)(temp_19) + 0x220));
                                func_L05_00355DD8(arg0, &sp90);
                                if ((D_L20_001DF658 < temp_f20_5) && (temp_f20_5 < D_L20_001DF65C)) {
                                    func_003C2F58((*(void **)((u8 *)(temp_19) + 0x3EC)), 0, &sp90);
                                    func_003C2F58((*(void **)((u8 *)(temp_19) + 0x3EC)), 1, &spA0);
                                    func_L01_00446630(&spB0, &sp90, &spA0, temp_19 + 0x220);
                                    func_L01_00446780(arg0, &spB0, 0x10001, 0, 1, 0, D_L20_001DF640, (f32) (*(u8 *)((u8 *)(temp_19) + 0x45)), D_L20_001DF63C);
                                }
                                if ((*(u8 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x60)) & 2) {
                                    goto block_466;
                                }
                                break;
                            }
                            break;
                        case 17:                    /* switch 2 */
                            if (func_L01_004561B8(arg0) != 0) {
                                func_003C3A10(arg0, 0x12, 0, 8);
                                func_003C3A10((*(void **)((u8 *)(temp_19) + 0x3EC)), 2, 0, 8);
                                (*(s32 *)((u8 *)(temp_19) + 0xA8)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0xA8)) | 0x404);
                            }
                            func_L20_003FB570(arg0);
                            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                                func_003C3A10(arg0, 0x13, 0, 8);
                                goto block_466;
                            }
                            break;
                        case 18:                    /* switch 2 */
                            if (func_L01_004561B8(arg0) != 0) {
                                func_003C3A10((*(void **)((u8 *)(temp_19) + 0x3EC)), 2, 0, 8);
                                (*(s32 *)((u8 *)(temp_19) + 0xA8)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0xA8)) & ~4 & ~0x400);
                            }
                            func_L20_003FB570(arg0);
                            if (((*(u8 *)((u8 *)(arg0) + 0x42)) != 0x14) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x14)) {
                                var_4_2 = arg0;
                                if (((*(f32 *)((u8 *)(arg0) + 0x18)) - (*(f32 *)((u8 *)(temp_19) + 0x100))) < D_L20_001DF670) {
                                    var_5_7 = 0x14;
                                    goto block_475;
                                }
                            } else if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                                var_5_9 = (*(u8 *)((u8 *)(arg0) + 0x94));
                                goto block_478;
                            }
                            break;
                        }
                        func_L20_003FEBA8(arg0);
                        break;
                    case 1:                         /* switch 1 */
                        if (((*(s16 *)((u8 *)(temp_19) + 0x234)) == 1) || ((*(s16 *)((u8 *)(temp_19) + 0x3D8)) != 0)) {
                            func_L01_004450F0(arg0, 0xAU, 2, (void *)0x1610);
                        }
                        goto block_55;
                    case 2:                         /* switch 1 */
                        if (func_L01_004561E0(arg0) == 0) {
                            if ((*(s16 *)((u8 *)(temp_19) + 0x234)) != 1) {
                                func_L01_004450F0(arg0, 1U, 1);
                                func_L05_0035AA68(arg0, 8, 0, 8);
                                (*(s32 *)((u8 *)(temp_19) + 0x3D0)) = (s32) ((s32) ((func_00382498(0x244, 0x258) * 5) + 2) / 6);
                                if ((*(u8 *)((u8 *)(arg0) + 0xBC)) == 0) {
                                    temp_5_17 = (*(u8 *)((u8 *)(arg0) + 0x21));
                                    if (((s32) temp_5_17 < D_L20_001E02D8) && (*((temp_5_17 * 4) + &D_L20_0021CFE0) != 0)) {
                                        func_L01_00445BE0(temp_5_17, 0);
                                    }
                                }
                            }
                        } else {
                            temp_3_14 = (*(void **)((u8 *)(temp_19) + 0x3EC));
                            (*(u16 *)((u8 *)(temp_3_14) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_3_14) + 0x34)) & 0xFFFD);
                            temp_4_12 = (*(void **)((u8 *)(temp_19) + 0x3EC));
                            (*(u16 *)((u8 *)(temp_4_12) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_4_12) + 0x34)) & 0xFFFB);
                            temp_3_15 = (*(void **)((u8 *)(temp_19) + 0x3EC));
                            (*(u16 *)((u8 *)(temp_3_15) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_3_15) + 0x34)) & 0xFFFE);
                            temp_4_13 = (*(void **)((u8 *)(temp_19) + 0x3EC));
                            (*(u16 *)((u8 *)(temp_4_13) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_4_13) + 0x34)) & 0xFFBF);
                            (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x34)) & 0xFFBA);
                        }
                        goto block_55;
                    case 3:                         /* switch 1 */
                        if (func_L01_004561E0(arg0) != 0) {
                            if ((*(u8 *)((u8 *)(arg0) + 0xBC)) == 0) {
                                temp_5_18 = (*(u8 *)((u8 *)(arg0) + 0x21));
                                if (((s32) temp_5_18 < D_L20_001E02D8) && (*((temp_5_18 * 4) + &D_L20_0021CFE0) != 0)) {
                                    func_L01_00445BE0(temp_5_18, 0);
                                }
                            }
                            if ((*(u8 *)((u8 *)(arg0) + 0x42)) != 0x10) {
                                if ((*(u8 *)((u8 *)(arg0) + 0x43)) == 0x10) {
                                    goto block_45;
                                }
                            } else {
block_45:
                                (*(s32 *)((u8 *)(arg0) + 0x48)) = D_L20_001DF664;
                                (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x3EC))) + 0x48)) = D_L20_001DF664;
                            }
                            func_003A52A0();
                        }
                        temp_2_6 = func_L01_00454370(arg0, temp_19 + 0x160);
                        if ((*(f32 *)((u8 *)(temp_19) + 0x30)) <= 0.0f) {
                            func_L20_003FE9C0(arg0, 0);
                            func_003A52A0();
                            var_4 = arg0 + 0x10;
                            var_6 = 0xA;
                            var_7 = 0xA;
                            var_8 = 0xA;
                            var_f12 = 0x3F000000;
                            var_9 = 0xA;
                            var_10 = 0x1E;
block_49:
                            func_L01_003303B8(var_4, 0, var_6, var_7, var_8, var_9, var_10, 0, var_f12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x3064FF, 0x3064FF, 0);
                            goto block_50;
                        }
                        if (temp_2_6 & 2) {
                            func_L01_004450F0(arg0, 0xAU, 2);
                            if ((func_L20_003FB3B0(arg0) == 0) && (func_L05_00355D60(arg0, (*(s32 *)((u8 *)(temp_19) + 0x230))) < D_L20_001DF64C)) {
                                func_L01_004450F0(arg0, 0x10U, -1);
                                func_L05_0035AA68(arg0, 0xF, 3, 2);
                            }
                        }
                        goto block_55;
                    }
                } else {
                    func_003C2880((*(void **)((u8 *)(temp_19) + 0x3EC)));
                    goto block_50;
                }
            }
        } else {
block_50:
            func_003C2880(arg0);
        }
    }
}
