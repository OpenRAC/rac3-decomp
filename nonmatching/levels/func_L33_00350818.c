/* func_L33_00350818: Opus handoff (prep by Sonnet worker w6, 2026-11-08)
   Size: 7076 bytes, places: 1 level (33, Vidcomic 2), file: src/levels/33_vidcomic_2/L33_0034FC00.c
   flags: the file's own line (-O2 -G8 -fopt-stack -mno-check-zero-division, NO @ps2as); retail has 76 mtc1 (inline float constants) and 26 lq/sq:
     a file with an estimated flag line and no C yet: try --as ps2as first (Ps2EeAs inline constants), then check with --all-modes.
   Step 0: one function; 1 jump table (jtbl_002BE8A0), 16 cases. a Vidcomic-2 moby update (L33_00352ED0 x17, L30_0034D1E8 x17 [a level-30 routine!], L01_004561B8 x11, rand_range, angle_sub, timer_tick).
   rac2 twin: none: best opcode 0.215 (func_L17_003E7068); no rac3 sibling above 0.07-0.17; it calls level-30 code (func_L30_0034D1E8, func_L30_0034C8A8), so levels 30-33 (the Vidcomic set) are the family to read first.
   Mapping / identical / changed: no twin to map. Hot callees have names in config/names.tsv (moby_set_state, moby_anim_blend,
     vec_set_length, angle_add/sub, atan2, rand_*), so the m2c is readable as moby-AI code.
   No COP2 instructions: a plain-C MATCH is possible in principle.
   Draft: no compiling draft (m2c converted (924 lines): two classes of errors left: `*(void *)expr` dereferences (give the pointers types; lines 331-391) and callee arity (func_L33_00352ED0 takes more args than m2c guessed).). The fenced block is the mechanically converted m2c (M2C_FIELD ->
     byte-offset casts, M2C_UNK -> s32, s128 -> u128_t TI typedef). Not measured.
   Left for Opus: (1) type the object (moby: pos +0x10, state +0x20 u8, class ptr +0x24, flags +0x34 u16; the +0x68 pointer is the
     per-moby vars block); (2) turn float-hex arguments back into f32; (3) get it to compile, measure, then register/scheduling work.
   Tool note: tools in out/tools-w6/ (m2c2.py: restores the `.word`-hidden lq/sq and appends the jump tables so m2c runs at all;
     conv.py: M2C_FIELD -> casts; iter.py: compile loop dropping conflicting prototypes).
*/
#if 0 /* does not compile yet: m2c2 draft mechanically converted (tools in worker w6 scratch), prototypes unverified */
typedef int u128_t __attribute__((mode(TI)));
s32 func_00382380(u128_t *, s32, s32);            /* extern */
s32 func_00382498(s32, s32);                /* extern */
f32 func_003824E0(void *, s32, s32);        /* extern */
s32 func_0038CAD0(void *);                          /* extern */
f32 func_0038CEA8(void *);                          /* extern */
f32 func_0038CF00(void *, void *);                  /* extern */
f32 func_0038D098(f32);                             /* extern */
f32 func_0038DB00(f32, f32);                        /* extern */
f32 func_0038DB48(void *, f32, s16, f32);           /* extern */
s32 func_003A52A0(s32, s32, void *);        /* extern */
s32 func_003C2880(void *);                      /* extern */
s32 func_003C3A10(void *, s32, s32, s32); /* extern */
f32 func_003C4088(f32, f32, f32);                   /* extern */
s32 func_003C4098(void *, u128_t *, u128_t *, s32, f32); /* extern */
s32 func_003D3CB0(u128_t *, u128_t *, s32, s32, s32); /* extern */
f32 func_L01_004395E0(void *);                      /* extern */
s32 func_L01_00448890(void *, void *, s32, f32, f32, f32, f32); /* extern */
s32 func_L01_004561B8(void *);                      /* extern */
s32 func_L01_00456230(s32, s32);            /* extern */
s32 func_L01_00456250(void *);                      /* extern */
s32 func_L01_004AA7E8(void *, s32);         /* extern */
s32 func_L03_0034B248(s32 *, void *);       /* extern */
s32 func_L30_0034C8A8(s32 *, void *);       /* extern */
s32 func_L30_0034CB68(void *, void *, s32, s32, s32, s32, f32, f32); /* extern */
s32 func_L30_0034CDC0(s32, s32, s32, f32 *, s32); /* extern */
s32 func_L30_0034D1E8(void *, void *, void *, u128_t *, s32, s32, s32, s32, f32, f32, s32, f32, f32, f32); /* extern */
s32 func_L30_0034D8D8(u128_t *, s32);             /* extern */
s32 func_L31_00346798(f32, f32, f32);               /* extern */
s32 func_L31_00346B10(void *, void *, f32, f32, f32, f32, f32); /* extern */
s32 func_L32_00349630(void *, void *, f32 *, f32, f32, f32, f32, f32, s32, s32); /* extern */
s32 func_L33_00352760(s32, s16, s32);   /* extern */
f32 func_L33_003527C0(void *);                      /* extern */
s32 func_L33_00352908(void *);                  /* extern */
s32 func_L33_00352A08(void *);                  /* extern */
s32 func_L33_00352E08(void *, s32, s32, s32);   /* extern */
s32 func_L33_00352ED0(void *, s32, s16);    /* extern */
s32 func_L33_003532D8(void *);                  /* extern */
s32 func_L33_003534E0(void *);                      /* extern */
s32 func_L33_00353800(void *, f32 *, s32, s32, s32, s32, s32); /* extern */
extern s32 D_1A4BE0;
extern u128_t D_1A4C60;
extern f32 D_L33_001DD950;
extern s32 D_L33_001DFB1C;
extern void *D_L33_001DFC00;
extern s32 D_L33_001E1858;
extern s32 D_L33_001E1898;
extern s32 D_L33_001E18B8;
extern s32 D_L33_001E9620;

void func_L33_00350818(void *arg0) {
    f32 sp10;                                       /* compiler-managed */
    f32 sp18;
    u128_t sp20;                                      /* compiler-managed */
    u128_t sp30;                                      /* compiler-managed */
    f32 sp40;
    s32 sp44;
    s32 sp48;
    s32 sp4C;
    s32 sp50;
    s32 temp_20;
    s32 var_6;
    s32 var_6_2;
    s32 var_6_3;
    f32 *temp_22_3;
    f32 *temp_6;
    f32 *temp_6_2;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f12;
    f32 temp_f12_10;
    f32 temp_f12_11;
    f32 temp_f12_12;
    f32 temp_f12_13;
    f32 temp_f12_14;
    f32 temp_f12_15;
    f32 temp_f12_16;
    f32 temp_f12_17;
    f32 temp_f12_18;
    f32 temp_f12_19;
    f32 temp_f12_20;
    f32 temp_f12_2;
    f32 temp_f12_3;
    f32 temp_f12_4;
    f32 temp_f12_5;
    f32 temp_f12_6;
    f32 temp_f12_7;
    f32 temp_f12_8;
    f32 temp_f12_9;
    f32 temp_f13;
    f32 temp_f13_2;
    f32 temp_f15;
    f32 temp_f15_2;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f21;
    f32 temp_f22;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f3;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    f32 var_f12;
    f32 var_f12_2;
    f32 var_f12_3;
    f32 var_f12_4;
    f32 var_f13;
    f32 var_f15;
    f32 var_f15_2;
    f32 var_f15_3;
    f32 var_f20;
    f32 var_f20_2;
    f32 var_f20_3;
    f32 var_f21;
    u128_t temp_2_4;
    s16 temp_3_3;
    s16 temp_6_3;
    s32 temp_16;
    s32 temp_21;
    s32 temp_21_3;
    s32 temp_21_5;
    s32 temp_21_6;
    s32 temp_21_7;
    s32 temp_21_8;
    s32 temp_23;
    s32 temp_2;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_3;
    s32 temp_3_8;
    s32 temp_4;
    s32 temp_5;
    s32 temp_5_2;
    s32 temp_5_3;
    s32 temp_7;
    s32 var_2;
    s32 var_3;
    s32 var_fp;
    u16 temp_2_3;
    u16 temp_3_9;
    u8 temp_2_2;
    u8 temp_3_5;
    u8 temp_3_6;
    u8 temp_3_7;
    void *temp_16_2;
    void *temp_16_3;
    void *temp_16_4;
    void *temp_16_5;
    void *temp_17;
    void *temp_17_2;
    void *temp_17_3;
    void *temp_17_4;
    void *temp_19;
    void *temp_21_2;
    void *temp_21_4;
    void *temp_22;
    void *temp_22_2;
    void *temp_3_2;
    void *temp_3_4;
    void *temp_4_2;
    void *var_16;
    void *var_2_2;
    void *var_4;

    var_fp = 0;
    temp_19 = (*(void **)((u8 *)(arg0) + 0x68));
    temp_3 = 0x1761 - (*(s16 *)((u8 *)(arg0) + 0xAA));
    sp44 = temp_3;
    temp_23 = func_L31_00346798((*(f32 *)((u8 *)(saved_reg_gp) + 0x10CC)), (*(f32 *)((u8 *)(saved_reg_gp) + 0x10D0)), (*(f32 *)((u8 *)(saved_reg_gp) + 0x10C8))) != 0;
    temp_f3 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x1034));
    temp_f2 = (*(f32 *)((u8 *)(arg0) + 0x18));
    var_3 = temp_3;
    if ((*(f32 *)((u8 *)(&D_1A4BE0) + 0x88)) < (temp_f3 + temp_f2)) {
        if ((temp_f2 - temp_f3) < (*(f32 *)((u8 *)(&D_1A4BE0) + 0x88))) {
            var_fp = 1;
        } else {
            var_3 = sp44;
        }
    }
    temp_2 = var_3 * 4;
    temp_3_2 = saved_reg_gp + 0x1028;
    sp48 = 1;
    if (!(fabsf((*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10))) < *(temp_2 + temp_3_2))) {
        sp48 = 0;
    }
    temp_5 = (*(s32 *)((u8 *)(temp_19) + 0xA0));
    sp4C = 0;
    if ((temp_5 == -1) || (func_00382380(&D_1A4BE0 + 0x80, temp_5, 0) != 0)) {
        sp4C = (*(s32 *)((u8 *)(temp_19) + 0xB0)) == 0;
    }
    sp50 = 1;
    temp_f20 = fabsf(func_0038DB00((*(f32 *)((u8 *)(saved_reg_gp) + 0x10CC)), (*(f32 *)((u8 *)(arg0) + 0xF8))));
    if (!(temp_f20 < fabsf(func_0038DB00((*(f32 *)((u8 *)(saved_reg_gp) + 0x10D0)), (*(f32 *)((u8 *)(arg0) + 0xF8)))))) {
        sp50 = 0;
    }
    temp_f21 = func_L01_004395E0(arg0);
    temp_16 = (*(s16 *)((u8 *)(arg0) + 0xAA)) == 0x175F;
    if ((*(u8 *)((u8 *)(arg0) + 0x20)) == 0) {
        func_L33_003532D8(arg0);
        if ((*(s32 *)((u8 *)(temp_19) + 0x9C)) != -1) {
            func_L33_00352ED0(arg0, 0xF);
        } else {
            func_L33_00352ED0(arg0, 5);
        }
    }
    func_L33_00352A08(arg0);
    temp_2_2 = (*(u8 *)((u8 *)(arg0) + 0x20));
    switch (temp_2_2) {
    case 0x1:
        if (func_L01_004561B8(arg0) != 0) {
            (*(f32 *)((u8 *)(temp_19) + 0x60)) = 0.0f;
            (*(u128_t *)((u8 *)(temp_19) + 0x80)) = (u128_t) (*(u128_t *)((u8 *)(&D_1A4C60) + 0));
            (*(u16 *)((u8 *)(arg0) + 0x96)) = 0U;
        }
        temp_16_2 = temp_19 + 0x60;
        temp_f12 = *(temp_2 + (saved_reg_gp + 0x1248));
        temp_21 = func_L30_0034D1E8(arg0, arg0 + 0x10, temp_16_2, sp, 1, 1, 1, 0, temp_f12, temp_f12, 0x42C80000, 0.0f, 0.0f, (*(f32 *)((u8 *)(saved_reg_gp) + 0x10B8)));
        if ((*(temp_2 + (saved_reg_gp + 0xFF8)) <= temp_f21) && (temp_f21 <= *(temp_2 + (saved_reg_gp + 0x1008)))) {
            func_L30_0034CB68(arg0, temp_16_2, 1, 1, 0, 0, (f32) (*(u8 *)((u8 *)(temp_19) + 0x14)), *(temp_2 + (saved_reg_gp + 0x1018)));
        }
        temp_2_3 = (*(u16 *)((u8 *)(arg0) + 0x96)) + 1;
        (*(u16 *)((u8 *)(arg0) + 0x96)) = temp_2_3;
        if (((u32) (temp_2_3 & 0xFFFF) >= 0x15U) && (((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) || (*(temp_2 + (saved_reg_gp + 0xFD8)) <= temp_f21))) {
            if (temp_21 != 0) {
                if (temp_23 != 0) {
                    if (sp48 != 0) {
                        if (var_fp == 0) {
                            goto block_30;
                        }
block_247:
                        func_L33_00352ED0(arg0, 1);
                    } else {
                        goto block_31;
                    }
                } else {
block_30:
block_31:
                    if (func_00382498(0, 1) != 0) {
                        if (sp4C != 0) {
block_33:
                            if (var_fp != 0) {
block_34:
                                if (temp_23 == 0) {
block_255:
                                    (*(u128_t *)((u8 *)(temp_19) + 0x80)) = (u128_t) (*(u128_t *)((u8 *)(&D_1A4C60) + 0));
                                    func_L33_00352ED0(arg0, 0xE);
                                } else {
block_253:
                                    func_L33_00352ED0(arg0, 0xC);
                                }
                            } else {
                                goto block_257;
                            }
                        } else {
block_257:
                            func_L33_00352ED0(arg0, 5);
                        }
                    } else {
block_249:
                        func_L33_00352ED0(arg0, 0xD);
                    }
                }
            } else {
block_273:
                func_L33_00352ED0(arg0, 3);
            }
        }
    default:
        break;
    case 0x42:
        if (func_L01_004561B8(arg0) != 0) {
            (*(s32 *)((u8 *)(temp_19) + 0x78)) = (s32) *(temp_2 + (saved_reg_gp + 0x1220));
            (*(s32 *)((u8 *)(saved_reg_gp) + 0xFAC)) = (s32) (((*(s32 *)((u8 *)(saved_reg_gp) + 0xFAC)) + 3) - sp44);
        }
        temp_f0 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x1288));
        if (func_0038CAD0(temp_19 + 0x78) == 0) {
            func_L30_0034C8A8(&D_L33_001E1858, arg0);
            func_L30_0034C8A8(&D_L33_001E1898, arg0);
            (*(s8 *)((u8 *)(arg0) + 0x23)) = (s8)((f32) *(temp_2 + (saved_reg_gp + 0x1220)));
            temp_f12_2 = *(temp_2 + (saved_reg_gp + 0x1248));
            func_L30_0034D1E8(arg0, arg0 + 0x10, temp_19 + 0x60, sp, 1, 1, 1, 0, temp_f12_2, temp_f12_2, 0x42C80000, 0.0f, 0.0f, *(temp_2 + (saved_reg_gp + 0x1050)));
        } else {
            sp18 = temp_f0;
            temp_f0_2 = (*(temp_2 + (saved_reg_gp + 0x10E8)) * 5.0f) / (2.0f * temp_f0);
            temp_20 = (((*(s16 *)((u8 *)(arg0) + 0xAA)) ^ 0x1761) == 0) ? 1 : 2;
            sp10 = temp_f0_2;
            if ((*(f32 *)((u8 *)((&D_1A4BE0 + 0x4BE0)) + 0x80)) < (*(f32 *)((u8 *)(arg0) + 0x10))) {
                sp10 = -temp_f0_2;
            }
            temp_3_3 = (*(s16 *)((u8 *)(arg0) + 0xAA));
            if (temp_3_3 != 0x175F) {
                if (temp_3_3 == 0x1760) {
                    func_003A52A0(6, 0, arg0);
                } else {
                    func_003A52A0(7, 0, arg0);
                }
                temp_17 = arg0 + 0x10;
                sp10 *= func_003824E0((void *)0x3F4CCCCD, 0x3F99999A);
                func_L33_00353800(temp_17, &sp10, temp_20, -1, -1, -1, 1);
                sp10 *= func_003824E0((void *)0x3ECCCCCD, 0x3F19999A);
                func_L33_00353800(temp_17, &sp10, temp_20, -1, -1, -1, 1);
            }
            (*(f32 *)((u8 *)(temp_19) + 0x60)) = 0;
            func_L33_00352760(0, (*(s16 *)((u8 *)(arg0) + 0xAA)), 0);
            func_003C2880(arg0);
        }
        break;
    case 0x2:
        temp_22 = arg0 + 0x10;
        temp_21_2 = saved_reg_gp + 0x1050;
        temp_17_2 = temp_19 + 0x60;
        if (func_L01_004561B8(arg0) != 0) {
            (*(s32 *)((u8 *)(temp_19) + 0x78)) = (s32) *(temp_2 + (saved_reg_gp + 0x1220));
            func_003A52A0(temp_16 + 5, 0, arg0);
            temp_f12_3 = *(temp_2 + (saved_reg_gp + 0x1248));
            func_L30_0034D1E8(arg0, temp_22, temp_17_2, sp, 1, 1, 1, 1, temp_f12_3, temp_f12_3, 0x42C80000, 0.0f, 0.0f, *(temp_2 + temp_21_2));
        }
        if ((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43))) {
            temp_6 = temp_2 + (saved_reg_gp + 0x1088);
            func_L32_00349630(arg0, temp_22, temp_6, *(temp_2 + (saved_reg_gp + 0x1248)), (*(f32 *)((u8 *)(temp_19) + 0x68)), *(temp_2 + (saved_reg_gp + 0x10E8)), *(temp_2 + (saved_reg_gp + 0x1098)), *temp_6, 0, 0xBF800000);
        } else {
            (*(f32 *)((u8 *)(arg0) + 0x48)) = 1.0f;
        }
        if (func_0038CAD0(temp_19 + 0x78) == 0) {
            func_L30_0034C8A8(&D_L33_001E1858, arg0);
            func_L30_0034C8A8(&D_L33_001E1898, arg0);
        }
        temp_f12_4 = *(temp_2 + (saved_reg_gp + 0x1248));
        temp_21_3 = func_L30_0034D1E8(arg0, temp_22, temp_17_2, sp, 1, 1, 1, 1, temp_f12_4, temp_f12_4, 0x42C80000, 0.0f, 0.0f, *(temp_2 + temp_21_2));
        if (!((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
            if (sp44 == 2) {
                var_2 = sp44 < 2;
                if ((*(f32 *)((u8 *)(temp_19) + 0x68)) <= 0.0f) {
                    if (!(D_L33_001DD950 <= temp_f21)) {
                        goto block_60;
                    }
                    goto block_126;
                }
                goto block_61;
            }
block_60:
            var_2 = sp44 < 2;
block_61:
            if (var_2 != 0) {
                if (((*(f32 *)((u8 *)(temp_19) + 0x68)) <= 0.0f) && (*(temp_2 + (saved_reg_gp + 0x1098)) <= temp_f21) && (temp_21_3 != 0)) {
                    goto block_126;
                }
            }
        } else {
block_125:
block_126:
            func_L33_00352ED0(arg0, 0x42);
        }
        break;
    case 0x3:
        temp_f12_5 = *(temp_2 + (saved_reg_gp + 0x1248));
        if (func_L30_0034D1E8(arg0, arg0 + 0x10, temp_19 + 0x60, sp, 1, 1, 1, 0, temp_f12_5, temp_f12_5, 0x42C80000, 100.0f, 0.0f, (*(f32 *)((u8 *)(saved_reg_gp) + 0x10B8))) != 0) {
            func_L33_00352ED0(arg0, 0xB);
        }
        break;
    case 0x4:
        temp_22_2 = arg0 + 0x10;
        temp_21_4 = saved_reg_gp + 0x1130;
        temp_17_3 = temp_19 + 0x60;
        if (func_L01_004561B8(arg0) != 0) {
            (*(s32 *)((u8 *)(temp_19) + 0x78)) = (s32) *(temp_2 + (saved_reg_gp + 0x1220));
            func_003A52A0(temp_16 + 3, 0, arg0);
            func_003A52A0(temp_16 | 4, 0, arg0);
            temp_f12_6 = *(temp_2 + (saved_reg_gp + 0x1248));
            func_L30_0034D1E8(arg0, temp_22_2, temp_17_3, sp, 1, 1, 1, 0, temp_f12_6, temp_f12_6, 0x42C80000, 0.0f, 0.0f, *(temp_2 + temp_21_4));
        }
        if (func_0038CAD0(temp_19 + 0x78) == 0) {
            func_L30_0034C8A8(&D_L33_001E1858, arg0);
        }
        temp_f12_7 = *(temp_2 + (saved_reg_gp + 0x1248));
        temp_21_5 = func_L30_0034D1E8(arg0, temp_22_2, temp_17_3, sp, 1, 1, 1, 0, temp_f12_7, temp_f12_7, 0x42C80000, 0.0f, 0.0f, *(temp_2 + temp_21_4));
        if (!((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
            if (*(temp_2 + (saved_reg_gp + 0x1160)) < temp_f21) {
                if ((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43))) {
                    goto block_75;
                }
            }
        } else {
block_75:
            if (temp_21_5 != 0) {
                if (temp_23 != 0) {
                    if (sp48 != 0) {
                        if (var_fp == 0) {
                            goto block_79;
                        }
                        goto block_247;
                    }
                    goto block_80;
                }
block_79:
block_80:
                if (sp4C != 0) {
                    if (var_fp != 0) {
                        goto block_34;
                    }
block_258:
                    func_L33_00352ED0(arg0, 6);
                } else {
                    goto block_257;
                }
            } else {
                goto block_273;
            }
        }
        break;
    case 0x5:
        temp_f12_8 = *(temp_2 + (saved_reg_gp + 0x1248));
        if (func_L30_0034D1E8(arg0, arg0 + 0x10, temp_19 + 0x60, sp, 1, 1, 1, 0, temp_f12_8, temp_f12_8, 0x42C80000, 0.0f, (*(f32 *)((u8 *)(saved_reg_gp) + 0x1290)), (*(f32 *)((u8 *)(temp_19) + 0xB4))) != 0) {
            if (temp_23 != 0) {
                if (sp48 != 0) {
                    if (var_fp == 0) {
                        goto block_87;
                    }
                    goto block_247;
                }
                goto block_88;
            }
block_87:
block_88:
            if ((sp4C == 0) || (var_fp == 0)) {
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    (*(u128_t *)((u8 *)(temp_19) + 0x80)) = (u128_t)((*(f32 *)((u8 *)(arg0) + 0x10)));
                    temp_f20_2 = (f32)((*(u128_t *)((u8 *)(temp_19) + 0x80)));
                    var_f0 = -4.0f;
                    if (func_L33_003534E0(arg0) != 0) {
                        var_f0 = 4.0f;
                    }
                    (*(u128_t *)((u8 *)(temp_19) + 0x80)) = (f32) (temp_f20_2 + var_f0);
block_210:
                    func_L33_00352ED0(arg0, 0xE);
                }
            } else {
                goto block_34;
            }
        } else {
            goto block_273;
        }
        break;
    case 0x6:
        if (func_L01_004561B8(arg0) != 0) {
            func_L33_00352908(arg0);
            (*(s32 *)((u8 *)(temp_19) + 0x78)) = 0;
        }
        temp_16_3 = temp_19 + 0x60;
        temp_17_4 = arg0 + 0x10;
        sp10 = (*(u128_t *)((u8 *)(temp_19) + 0x80));
        temp_f0_3 = func_L33_003527C0(arg0);
        sp10 = temp_f0_3;
        temp_f15 = (*(f32 *)((u8 *)(temp_19) + 0xB4));
        func_L31_00346B10(arg0, temp_16_3, temp_f0_3, (*(f32 *)((u8 *)(saved_reg_gp) + 0x10C0)), (*(f32 *)((u8 *)(temp_19) + 0xB8)), temp_f15, temp_f15);
        temp_f12_9 = *(temp_2 + (saved_reg_gp + 0x1248));
        temp_21_6 = func_L30_0034D1E8(arg0, temp_17_4, temp_16_3, sp, 1, 1, 1, 0, temp_f12_9, temp_f12_9, 0x42C80000, (*(f32 *)((u8 *)(temp_19) + 0xB8)), (*(f32 *)((u8 *)(saved_reg_gp) + 0x1290)), 0.0f);
        temp_f1 = ((*(f32 *)((u8 *)(saved_reg_gp) + 0x118C)) * func_0038CEA8(temp_16_3)) / *(temp_2 + (saved_reg_gp + 0x1210));
        (*(f32 *)((u8 *)(arg0) + 0x48)) = temp_f1;
        if (temp_f1 > 5.0f) {
            (*(f32 *)((u8 *)(arg0) + 0x48)) = 5.0f;
        } else if (temp_f1 < 0.5f) {
            (*(f32 *)((u8 *)(arg0) + 0x48)) = 0.5f;
        }
        if (func_0038CAD0(temp_19 + 0x78) != 0) {
            if ((*(u8 *)((u8 *)(saved_reg_gp) + 0x72C)) == 0) {
                func_L03_0034B248(&D_L33_001E18B8, arg0);
            }
            (*(s32 *)((u8 *)(temp_19) + 0x78)) = (*(s32 *)((u8 *)(saved_reg_gp) + 0x13E0));
        }
        if (temp_21_6 != 0) {
            if (temp_23 != 0) {
                if (sp48 != 0) {
                    if (var_fp == 0) {
                        goto block_108;
                    }
                    goto block_247;
                }
                goto block_109;
            }
block_108:
block_109:
            if ((sp4C == 0) || (var_fp == 0)) {
                if (!(func_0038CF00(temp_19 + 0x80, temp_17_4) < (*(f32 *)((u8 *)(saved_reg_gp) + 0x10C0)))) {
                    if (func_L33_00352E08(arg0, sp50, temp_23, 0) != 0) {
                        goto block_257;
                    }
                } else {
                    goto block_257;
                }
            } else {
                goto block_34;
            }
        } else {
            goto block_273;
        }
        break;
    case 0x7:
        if (func_L01_004561B8(arg0) != 0) {
            (*(f32 *)((u8 *)(temp_19) + 0x60)) = 0;
        }
        temp_f0_4 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x123C));
        if (((*(f32 *)((u8 *)(saved_reg_gp) + 0x1240)) < temp_f21) && (temp_7 = (*(s32 *)((u8 *)(saved_reg_gp) + 0x3350)), (temp_f21 < temp_f0_4))) {
            sp10 = (*(u128_t *)((u8 *)(temp_19) + 0x50));
            sp20 = (*(u128_t *)((u8 *)((((*(s32 *)((u8 *)(temp_19) + 0x9C)) << 7) + temp_7)) + 0x30));
            func_003C4098(arg0 + 0x10, &sp10, &sp20, temp_7, (temp_f21 - (*(f32 *)((u8 *)(saved_reg_gp) + 0x1240))) / (temp_f0_4 - (*(f32 *)((u8 *)(saved_reg_gp) + 0x1240))));
            if (((*(f32 *)((u8 *)(saved_reg_gp) + 0x1240)) + (*(f32 *)((u8 *)(saved_reg_gp) + 0x123C))) < (2.0f * temp_f21)) {
                temp_4 = (*(s32 *)((u8 *)(temp_19) + 0x98));
                if (temp_4 != -1) {
                    func_L01_00456230((*(s32 *)((u8 *)(saved_reg_gp) + 0x326C)) + (temp_4 << 8), 1);
                }
            }
        } else if (temp_f0_4 < temp_f21) {
            temp_f12_10 = *(temp_2 + (saved_reg_gp + 0x1248));
            func_L30_0034D1E8(arg0, arg0 + 0x10, temp_19 + 0x60, sp, 1, 1, 1, 0, temp_f12_10, temp_f12_10, 0x42C80000, 0.0f, (*(f32 *)((u8 *)(saved_reg_gp) + 0x1290)), 0.0f);
        }
block_142:
        if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
block_254:
            goto block_255;
        }
        break;
    case 0x8:
        if (func_L01_004561B8(arg0) != 0) {
            temp_16_4 = &D_1A4BE0 + 0x4BE0;
            func_L30_0034CDC0(0, 0, 0, &sp40, 0x3F800000);
            temp_2_4 = (u128_t)((*(f32 *)((u8 *)(arg0) + 0x10)));
            sp20 = temp_2_4;
            sp30 = temp_2_4;
            temp_f2_2 = (*(f32 *)((u8 *)(temp_16_4) + 0x84));
            temp_f0_5 = (*(f32 *)((u8 *)((((*(s32 *)((u8 *)(temp_19) + 0x9C)) << 7) + D_L33_001DFC00)) + 0x30));
            unksp24 = temp_f2_2;
            sp20 = temp_f0_5;
            unksp28 = sp40;
            sp30 = temp_f0_5;
            unksp34 = temp_f2_2;
            if (func_003D3CB0(&sp20, &sp30, 2, 0, 0) == 0) {
                goto block_125;
            }
            temp_f0_6 = (*(f32 *)((u8 *)(&D_L33_001E9620) + 8)) + (*(f32 *)((u8 *)(saved_reg_gp) + 0x11D8));
            sp40 = temp_f0_6;
            (*(f32 *)((u8 *)(temp_19) + 0x60)) = 0;
            0 /* M2C_ERROR unknown instruction: c1 0x10044 */;
            (*(f32 *)((u8 *)(temp_19) + 0x68)) = fabsf(2.0f * (*(f32 *)((u8 *)(saved_reg_gp) + 0x10F4)) * (temp_f0_6 - (*(f32 *)((u8 *)(arg0) + 0x18))));
            temp_f1_2 = (*(f32 *)((u8 *)(arg0) + 0x18));
            0 /* M2C_ERROR unknown instruction: c1 0x4 */;
            (*(u16 *)((u8 *)(arg0) + 0x96)) = (u16)(temp_f1_2);
            (*(s32 *)((u8 *)(temp_19) + 0x78)) = (s32) ((s32)(temp_f1_2) & 0xFFFF);
            (*(s32 *)((u8 *)(temp_19) + 0x94)) = 0;
            (*(f32 *)((u8 *)(temp_19) + 0x60)) = (f32) (((*(f32 *)((u8 *)((((*(s32 *)((u8 *)(temp_19) + 0x9C)) << 7) + D_L33_001DFC00)) + 0x30)) - (f32)((*(u128_t *)((u8 *)(temp_19) + 0x50)))) / (f32) (*(u16 *)((u8 *)(arg0) + 0x96)));
            var_f12 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x10D0));
            if (!((*(f32 *)((u8 *)(arg0) + 0x10)) < (*(f32 *)((u8 *)((*(void **)((u8 *)(temp_16_4) + 0x25C0))) + 0x10)))) {
                var_f12 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x10CC));
            }
            (*(f32 *)((u8 *)(arg0) + 0xF8)) = func_0038DB48(D_L33_001DFC00, var_f12);
            goto block_130;
        }
block_130:
        temp_16_5 = &D_1A4BE0 + 0x4BE0;
        temp_2_5 = (*(u16 *)((u8 *)(arg0) + 0x96)) - 1;
        temp_2_6 = (temp_2_5 <= -1) ? 0 : temp_2_5;
        (*(u16 *)((u8 *)(arg0) + 0x96)) = (u16) temp_2_6;
        (*(f32 *)((u8 *)(arg0) + 0x14)) = func_003C4088((*(f32 *)((u8 *)(temp_19) + 0x54)), (*(f32 *)((u8 *)(temp_16_5) + 0x84)), 1.0f - ((f32) (temp_2_6 & 0xFFFF) / (f32) (*(s32 *)((u8 *)(temp_19) + 0x78))));
        if ((*(f32 *)((u8 *)(temp_19) + 0x68)) < 0.0f) {
            (*(s32 *)((u8 *)(arg0) + 0x98)) = (s32) (*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x24))) + 0x10));
        }
        temp_6_2 = saved_reg_gp + 0x1248;
        temp_3_4 = arg0 + 0x10;
        func_L32_00349630(arg0, temp_3_4, temp_6_2, *(temp_2 + temp_6_2), (*(f32 *)((u8 *)(temp_19) + 0x68)), (*(f32 *)((u8 *)(saved_reg_gp) + 0x10F4)), (*(f32 *)((u8 *)(saved_reg_gp) + 0x11C8)), (*(f32 *)((u8 *)(saved_reg_gp) + 0x11CC)), 0, 0xBF800000);
        sp10 = 0;
        sp18 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x10F4));
        if ((*(f32 *)((u8 *)(saved_reg_gp) + 0x11CC)) <= temp_f21) {
            var_f12_2 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x10D0));
            if (!((*(f32 *)((u8 *)(arg0) + 0x10)) < (*(f32 *)((u8 *)(temp_16_5) + 0x80)))) {
                var_f12_2 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x10CC));
            }
            (*(f32 *)((u8 *)(temp_19) + 0x90)) = var_f12_2;
            if ((*(f32 *)((u8 *)(saved_reg_gp) + 0x10C8)) < fabsf(func_0038DB00(var_f12_2, (*(f32 *)((u8 *)(arg0) + 0xF8))))) {
                temp_f12_11 = (*(f32 *)((u8 *)(temp_19) + 0x90));
                temp_f2_3 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x12C0));
                var_6 = 1;
                temp_f13 = (*(f32 *)((u8 *)(temp_19) + 0xBC)) * temp_f2_3;
                if (temp_f12_11 == 0.0f) {
                    var_6 = -1;
                }
                func_L01_00448890(arg0 + 0xF8, temp_19 + 0x94, var_6, temp_f12_11, temp_f13, temp_f13, (*(f32 *)((u8 *)(temp_19) + 0xC0)) * temp_f2_3);
            }
            var_f15 = 0.0f;
        } else {
            var_f15 = 100.0f;
        }
        temp_f12_12 = *(temp_2 + (saved_reg_gp + 0x1248));
        func_L30_0034D1E8(arg0, temp_3_4, temp_19 + 0x60, &sp10, 1, 1, 1, 0, temp_f12_12, temp_f12_12, 0x42C80000, var_f15, (*(f32 *)((u8 *)(saved_reg_gp) + 0x1290)), 0.0f);
        if (!((*(f32 *)((u8 *)(saved_reg_gp) + 0x11D0)) <= temp_f21)) {
            goto block_142;
        }
        goto block_254;
    case 0x9:
        func_L01_004561B8(arg0);
        temp_f12_13 = *(temp_2 + (saved_reg_gp + 0x1248));
        if (func_L30_0034D1E8(arg0, arg0 + 0x10, temp_19 + 0x60, sp, 1, 1, 1, 0, temp_f12_13, temp_f12_13, 0x42C80000, (*(f32 *)((u8 *)(temp_19) + 0xB8)), (*(f32 *)((u8 *)(saved_reg_gp) + 0x1290)), 0.0f) != 0) {
            func_L33_00352ED0(arg0, 0xA);
        }
        break;
    case 0xA:
    case 0xB:
        if (func_L01_004561B8(arg0) != 0) {
            (*(s32 *)((u8 *)(temp_19) + 0x94)) = 0;
        }
        temp_f12_14 = *(temp_2 + (saved_reg_gp + 0x1248));
        temp_21_7 = func_L30_0034D1E8(arg0, arg0 + 0x10, temp_19 + 0x60, sp, 1, 1, 1, 0, temp_f12_14, temp_f12_14, 0x42C80000, 0.0f, (*(f32 *)((u8 *)(saved_reg_gp) + 0x1290)), 0.0f);
        if ((*(f32 *)((u8 *)(arg0) + 0x10)) < (*(f32 *)((u8 *)((&D_1A4BE0 + 0x4BE0)) + 0x80))) {
            var_f12_3 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x10D0));
        } else {
            var_f12_3 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x10CC));
        }
        (*(f32 *)((u8 *)(temp_19) + 0x90)) = var_f12_3;
        if ((*(f32 *)((u8 *)(saved_reg_gp) + 0x10C8)) < fabsf(func_0038DB00(var_f12_3, (*(f32 *)((u8 *)(arg0) + 0xF8))))) {
            temp_f12_15 = (*(f32 *)((u8 *)(temp_19) + 0x90));
            temp_f2_4 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x12C0));
            var_6_2 = 1;
            temp_f13_2 = (*(f32 *)((u8 *)(temp_19) + 0xBC)) * temp_f2_4;
            if (temp_f12_15 == 0.0f) {
                var_6_2 = -1;
            }
            func_L01_00448890(arg0 + 0xF8, temp_19 + 0x94, var_6_2, temp_f12_15, temp_f13_2, temp_f13_2, (*(f32 *)((u8 *)(temp_19) + 0xC0)) * temp_f2_4);
        }
        if (temp_21_7 == 0) {
            func_L33_00352ED0(arg0, 3);
        }
        if (!((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) && ((temp_3_5 = (*(u8 *)((u8 *)(arg0) + 0x20)), (temp_3_5 != 0xB)) || !(*(temp_2 + (saved_reg_gp + 0x11A0)) <= temp_f21))) {
            if (temp_3_5 == 0xA) {
                if ((*(f32 *)((u8 *)(saved_reg_gp) + 0x11C4)) <= temp_f21) {
                    goto block_162;
                }
            }
        } else {
block_162:
            if (temp_23 != 0) {
                if (sp48 != 0) {
                    if (var_fp == 0) {
                        goto block_165;
                    }
                    goto block_247;
                }
                goto block_166;
            }
block_165:
block_166:
            if (sp4C != 0) {
                goto block_33;
            }
            goto block_257;
        }
        break;
    case 0xC:
        if (func_L01_004561B8(arg0) != 0) {
            (*(s32 *)((u8 *)(temp_19) + 0x78)) = 0;
        }
        (*(u128_t *)((u8 *)(temp_19) + 0x80)) = (u128_t) (*(u128_t *)((u8 *)(&D_1A4C60) + 0));
        sp10 = (*(u128_t *)((u8 *)(&D_1A4C60) + 0));
        sp10 = func_L33_003527C0(arg0);
        temp_f2_5 = (*(f32 *)((u8 *)((*(void **)((u8 *)(&D_1A4C60) + 0x2540))) + 0xF8));
        var_f20 = (*(f32 *)((u8 *)(temp_19) + 0xB8));
        var_f15_2 = (*(f32 *)((u8 *)(temp_19) + 0xB4));
        if (((temp_f2_5 < 1.5707964f) && ((*(f32 *)((u8 *)(arg0) + 0x10)) < (*(f32 *)((u8 *)((*(void **)((u8 *)(&D_1A4C60) + 0x2540))) + 0x10)))) || ((var_16 = temp_19 + 0x60, (temp_f2_5 >= 1.5707964f)) && ((*(f32 *)((u8 *)((*(void **)((u8 *)(&D_1A4C60) + 0x2540))) + 0x10)) < (*(f32 *)((u8 *)(arg0) + 0x10))))) {
            var_f15_2 *= (*(f32 *)((u8 *)(saved_reg_gp) + 0x11FC));
            var_f20 *= (*(f32 *)((u8 *)(saved_reg_gp) + 0x11FC));
            var_16 = temp_19 + 0x60;
        }
        func_L31_00346B10(arg0, var_16, sp10, (*(f32 *)((u8 *)(saved_reg_gp) + 0x10C0)), var_f20, var_f15_2, var_f15_2);
        temp_22_3 = temp_2 + (saved_reg_gp + 0x1248);
        temp_f12_16 = *temp_22_3;
        temp_21_8 = func_L30_0034D1E8(arg0, arg0 + 0x10, var_16, sp, 1, 1, 1, 0, temp_f12_16, temp_f12_16, 0x42C80000, var_f20, (*(f32 *)((u8 *)(saved_reg_gp) + 0x1290)), 0.0f);
        if ((func_0038CEA8(var_16) < (*(f32 *)((u8 *)(saved_reg_gp) + 0x10C4))) && (fabsf(sp10 - (*(f32 *)((u8 *)(arg0) + 0x10))) < *temp_22_3)) {
            temp_3_6 = (*(u8 *)((u8 *)(arg0) + 0x43));
            if ((((u32) (temp_3_6 - 1) >= 2U) && (temp_3_6 != 9)) || ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                if (func_00382498(0, 2) == 0) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 1) {
                        func_003824E0(((void *)0), 0, 0x40800000);
                        func_003C3A10(arg0, 1, second half of f64, (*(s32 *)((u8 *)(saved_reg_gp) + 0x1298)));
                    }
                } else {
                    temp_3_7 = (*(u8 *)((u8 *)(arg0) + 0x43));
                    if (func_00382498(0, 1) == 0) {
                        if (temp_3_7 != 2) {
                            func_003824E0(((void *)0), 0x40800000);
                            func_003C3A10(arg0, 2, second half of f64, (*(s32 *)((u8 *)(saved_reg_gp) + 0x1298)));
                        }
                    } else if (temp_3_7 != 9) {
                        func_003824E0(((void *)0), 0x40800000);
                        func_003C3A10(arg0, 9, second half of f64, (*(s32 *)((u8 *)(saved_reg_gp) + 0x1298)));
                    }
                }
                var_f0_2 = 1.0f;
                goto block_194;
            }
        } else {
            if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 3) {
                func_003C3A10(arg0, 3, 0, (s32) (((*(s32 *)((u8 *)(saved_reg_gp) + 0x1298)) * 5) + 2) / 6);
            }
            temp_f1_3 = ((*(f32 *)((u8 *)(saved_reg_gp) + 0x118C)) * func_0038CEA8(var_16)) / *(temp_2 + (saved_reg_gp + 0x1210));
            (*(f32 *)((u8 *)(arg0) + 0x48)) = temp_f1_3;
            if (temp_f1_3 > 5.0f) {
                (*(f32 *)((u8 *)(arg0) + 0x48)) = 5.0f;
            } else {
                var_f0_2 = 0.5f;
                if (temp_f1_3 < 0.5f) {
block_194:
                    (*(f32 *)((u8 *)(arg0) + 0x48)) = var_f0_2;
                }
            }
        }
        if (func_0038CAD0(temp_19 + 0x78) != 0) {
            if ((*(u8 *)((u8 *)(saved_reg_gp) + 0x72C)) == 0) {
                func_L03_0034B248(&D_L33_001E18B8, arg0);
            }
            (*(s32 *)((u8 *)(temp_19) + 0x78)) = (*(s32 *)((u8 *)(saved_reg_gp) + 0x13E0));
        }
        if (func_L33_00352E08(arg0, sp50, temp_23, 1) != 0) {
            (*(s32 *)((u8 *)(temp_19) + 0xB0)) = (s32) (*(s32 *)((u8 *)(saved_reg_gp) + 0x10F8));
        }
        if (temp_21_8 != 0) {
            if (temp_23 != 0) {
                if (sp48 != 0) {
                    if (var_fp == 0) {
                        goto block_205;
                    }
                    goto block_247;
                }
                goto block_206;
            }
block_205:
block_206:
            if (sp4C != 0) {
                if ((sp48 == 0) || (var_fp != 0)) {
                    if (temp_23 == 0) {
                        goto block_210;
                    }
                } else {
                    goto block_257;
                }
            } else {
                goto block_257;
            }
        } else {
            goto block_273;
        }
        break;
    case 0xD:
        temp_f12_17 = *(temp_2 + (saved_reg_gp + 0x1248));
        if (func_L30_0034D1E8(arg0, arg0 + 0x10, temp_19 + 0x60, sp, 1, 1, 1, 0, temp_f12_17, temp_f12_17, 0x42C80000, 0.0f, (*(f32 *)((u8 *)(saved_reg_gp) + 0x1290)), 0.0f) != 0) {
            if ((temp_23 == 0) || (sp48 == 0) || (var_fp == 0)) {
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    if (sp4C != 0) {
                        goto block_33;
                    }
                    goto block_257;
                }
            } else {
                goto block_247;
            }
        } else {
            goto block_273;
        }
        break;
    case 0xE:
        if (func_L01_004561B8(arg0) != 0) {
            var_f0_3 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x10D0));
            if (!((*(f32 *)((u8 *)(arg0) + 0x10)) < (f32)((*(u128_t *)((u8 *)(temp_19) + 0x80))))) {
                var_f0_3 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x10CC));
            }
            (*(f32 *)((u8 *)(temp_19) + 0x90)) = var_f0_3;
            (*(f32 *)((u8 *)(temp_19) + 0x60)) = 0.0f;
            (*(s32 *)((u8 *)(temp_19) + 0x94)) = 0;
        }
        var_f21 = func_0038DB00((*(f32 *)((u8 *)(temp_19) + 0x90)), (*(f32 *)((u8 *)(arg0) + 0xF8)));
        var_f15_3 = (*(f32 *)((u8 *)(temp_19) + 0xC0));
        if (sp48 != 0) {
            var_f15_3 *= (*(f32 *)((u8 *)(saved_reg_gp) + 0x12C0));
        }
        var_f13 = (*(f32 *)((u8 *)(temp_19) + 0xBC));
        if (sp48 != 0) {
            var_f13 *= (*(f32 *)((u8 *)(saved_reg_gp) + 0x12C0));
        }
        var_4 = arg0 + 0xF8;
        if ((*(f32 *)((u8 *)(saved_reg_gp) + 0x10C8)) < fabsf(var_f21)) {
            temp_f12_18 = (*(f32 *)((u8 *)(temp_19) + 0x90));
            var_6_3 = 1;
            if (temp_f12_18 == 0.0f) {
                var_6_3 = -1;
            }
            func_L01_00448890(var_4, temp_19 + 0x94, var_6_3, temp_f12_18, var_f13, var_f13, var_f15_3);
            var_f0_4 = 2.0943952f;
            if ((var_f21 > 2.0943952f) || (var_f0_4 = -2.0943952f, var_2_2 = temp_19 + 0x60, (var_f21 < -2.0943952f))) {
                var_f21 = var_f0_4;
                var_2_2 = temp_19 + 0x60;
            }
            temp_f22 = func_0038CEA8(var_2_2) / *(temp_2 + (saved_reg_gp + 0x1210));
            var_f20_2 = func_0038D098(func_0038DB48(M2C_BITWISE(void *, var_f21)));
            if (var_f20_2 < 0.0f) {
                var_f20_2 = 0.0f;
            }
            (*(f32 *)((u8 *)(arg0) + 0x48)) = func_003C4088(temp_f22, (*(f32 *)((u8 *)(saved_reg_gp) + 0x12C0)), fabsf(var_f21) / 2.0943952f);
            var_f20_3 = (*(f32 *)((u8 *)(temp_19) + 0xB8)) * fabsf(var_f20_2);
            if (func_L33_00352E08(arg0, sp50, temp_23, 0) != 0) {
                var_f20_3 = 0.0f;
            }
            sp10 = (*(u128_t *)((u8 *)(temp_19) + 0x80));
            temp_f0_7 = func_L33_003527C0(arg0);
            sp10 = temp_f0_7;
            temp_f15_2 = (*(f32 *)((u8 *)(temp_19) + 0xB4));
            func_L31_00346B10(arg0, var_2_2, temp_f0_7, *(temp_2 + temp_3_2), (*(f32 *)((u8 *)(temp_19) + 0xB8)), temp_f15_2, temp_f15_2);
            temp_f1_4 = (*(f32 *)((u8 *)(temp_19) + 0x60));
            if (!(var_f20_3 < temp_f1_4)) {
                temp_f0_8 = -var_f20_3;
                if (temp_f1_4 < temp_f0_8) {
                    (*(f32 *)((u8 *)(temp_19) + 0x60)) = temp_f0_8;
                }
            } else {
                (*(f32 *)((u8 *)(temp_19) + 0x60)) = var_f20_3;
            }
            temp_f12_19 = *(temp_2 + (saved_reg_gp + 0x1248));
            if (func_L30_0034D1E8(arg0, arg0 + 0x10, var_2_2, sp, 1, 1, 1, 0, temp_f12_19, temp_f12_19, 0x42C80000, var_f20_3, (*(f32 *)((u8 *)(saved_reg_gp) + 0x1290)), (*(f32 *)((u8 *)(temp_19) + 0xB4))) == 0) {
                goto block_273;
            }
        } else {
            if ((temp_23 != 0) && (sp48 != 0)) {
                var_4 = arg0;
                if (var_fp != 0) {
                    goto block_247;
                }
            }
            if (func_003824E0(var_4, 0, 0x3F800000) < (*(f32 *)((u8 *)(saved_reg_gp) + 0x12C4))) {
                goto block_249;
            }
            if (sp4C != 0) {
                if (var_fp != 0) {
                    if (temp_23 != 0) {
                        goto block_253;
                    }
                    goto block_255;
                }
                goto block_258;
            }
            goto block_257;
        }
        break;
    case 0xF:
        temp_f12_20 = *(temp_2 + (saved_reg_gp + 0x1248));
        if (func_L30_0034D1E8(arg0, arg0 + 0x10, temp_19 + 0x60, sp, 0, 0, 0, 0, temp_f12_20, temp_f12_20, 0x42C80000, (*(f32 *)((u8 *)(temp_19) + 0xB8)), (*(f32 *)((u8 *)(saved_reg_gp) + 0x1290)), 0.0f) == 0) {
            (*(s32 *)((u8 *)(arg0) + 0x98)) = 0;
            (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x41) & 0xEFFF);
            func_L01_004AA7E8(arg0, 1);
        }
        if (func_L01_00456250(arg0) == 0) {
            temp_5_2 = (*(s32 *)((u8 *)(temp_19) + 0xAC));
            if (temp_5_2 != -1) {
                if (func_00382380(&D_1A4C60, temp_5_2, 0) == 0) {
                    if ((*(s32 *)((u8 *)(temp_19) + 0xAC)) == -1) {
                        goto block_265;
                    }
                } else {
                    goto block_270;
                }
            } else {
block_265:
                temp_5_3 = (*(s32 *)((u8 *)(temp_19) + 0xA0));
                if ((temp_5_3 == -1) || (func_00382380(&D_1A4C60, temp_5_3, 0) == 0)) {
                    temp_3_8 = (*(s32 *)((u8 *)(temp_19) + 0xAC));
                    if ((temp_3_8 == -1) && ((*(s32 *)((u8 *)(temp_19) + 0xA0)) == temp_3_8)) {
                        if (func_L30_0034D8D8(&D_1A4C60, 0x3FC00000) != 0) {
                            goto block_270;
                        }
                    }
                } else {
                    goto block_270;
                }
            }
        } else {
block_270:
            temp_4_2 = (*(void **)((u8 *)(arg0) + 0x24));
            temp_3_9 = (*(u16 *)((u8 *)(arg0) + 0x34)) & 0xFFBE;
            temp_6_3 = (*(s16 *)((u8 *)(arg0) + 0xAA));
            (*(u16 *)((u8 *)(arg0) + 0x34)) = temp_3_9;
            (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (temp_3_9 | ((*(u16 *)((u8 *)(temp_4_2) + 0x44)) & 0x1000));
            (*(s32 *)((u8 *)(arg0) + 0x98)) = (s32) (*(s32 *)((u8 *)(temp_4_2) + 0x10));
            if (temp_6_3 == 0x1761) {
                if ((*(s32 *)((u8 *)(temp_19) + 0x98)) != -1) {
                    func_L33_00352ED0(arg0, 7, temp_6_3);
                } else {
                    goto block_273;
                }
            } else if (temp_6_3 == 0x1760) {
                func_L33_00352ED0(arg0, 8, temp_6_3);
            } else {
                var_f12_4 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x10D0));
                if (!((*(f32 *)((u8 *)(arg0) + 0x10)) < (*(f32 *)((u8 *)((*(void **)((u8 *)((&D_1A4BE0 + 0x4BE0)) + 0x25C0))) + 0x10)))) {
                    var_f12_4 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x10CC));
                }
                (*(f32 *)((u8 *)(arg0) + 0xF8)) = func_0038DB48(temp_4_2, 8.387e-42f, temp_6_3, var_f12_4);
                func_L01_00456230(D_L33_001DFB1C + ((*(s32 *)((u8 *)(temp_19) + 0x98)) << 8), 1);
                func_L33_00352ED0(arg0, 9);
            }
        }
        break;
    }
}


#endif
