/* func_L23_003AD800: Opus handoff (prep by Sonnet worker w6, 2026-11-08)
   Size: 7912 bytes, places: 1 level (23, Holostar Studios Clank), file: src/levels/23_holostar_studios_clank/L23_003AD800.c
   flags: the file's own line (-O2 -G8 -fopt-stack -mno-check-zero-division, NO @ps2as); retail has 69 mtc1 (inline float constants) and 12 lq/sq:
     a file with an estimated flag line and no C yet: try --as ps2as first (Ps2EeAs inline constants), then check with --all-modes.
   Step 0: one function; 5 jump tables (jtbl_002C0150/01A0/01C0/01E0/0200), ~50 cases in the m2c. a Clank-level moby update (moby_anim_blend x27, moby_set_state x19, L01_004561B8 x19, rand_below x16, L23_003B0110 x13, atan2).
   rac2 twin: none: best opcode 0.251 (func_L16_0040ECC0); same-level sibling func_L23_003B1490 only 0.15-0.17; one callee twin.
   Mapping / identical / changed: no twin to map. Hot callees have names in config/names.tsv (moby_set_state, moby_anim_blend,
     vec_set_length, angle_add/sub, atan2, rand_*), so the m2c is readable as moby-AI code.
   VU0 note: 32 COP2 instructions: with the 2026-11-06 rule (no VU0 inline asm in matched C) this cannot be a MATCH unless a
     TI-mode/scalar-C form produces them; keep as a near miss.
   Draft: no compiling draft (m2c converted (960 lines), not compiled yet: 32 COP2 instrs are M2C_ERROR placeholders.). The fenced block is the mechanically converted m2c (M2C_FIELD ->
     byte-offset casts, M2C_UNK -> s32, s128 -> u128_t TI typedef). Not measured.
   Left for Opus: (1) type the object (moby: pos +0x10, state +0x20 u8, class ptr +0x24, flags +0x34 u16; the +0x68 pointer is the
     per-moby vars block); (2) turn float-hex arguments back into f32; (3) get it to compile, measure, then register/scheduling work.
   Tool note: tools in out/tools-w6/ (m2c2.py: restores the `.word`-hidden lq/sq and appends the jump tables so m2c runs at all;
     conv.py: M2C_FIELD -> casts; iter.py: compile loop dropping conflicting prototypes).
*/
#if 0 /* does not compile yet: m2c2 draft mechanically converted (tools in worker w6 scratch), prototypes unverified */
typedef int u128_t __attribute__((mode(TI)));
s32 func_00382380(s32, s32, s32);               /* extern */
u32 func_00382468(u8);                              /* extern */
s32 func_00382498(s32, s32);                /* extern */
f32 func_003824E0(s32, s32);                /* extern */
f32 func_00382538();                                /* extern */
s32 func_0038CAD0(void *);                      /* extern */
s32 func_0038CE20(u128_t *, f32 *, f32);          /* extern */
s32 func_0038CF68(u128_t *, u128_t *, s32);     /* extern */
f32 func_0038D098(f32);                             /* extern */
f32 func_0038D0B0(f32);                             /* extern */
f32 func_0038D160(f32, f32, f32);                   /* extern */
f32 func_0038DAB8(s32, f32);                    /* extern */
f32 func_0038DB00(f32, f32);                        /* extern */
f32 func_0038DB48(f32);                             /* extern */
f32 func_0038DBA0(f32, f32);                        /* extern */
s32 func_003C2880(void *);                      /* extern */
s32 func_003C2F58(void *, s32, u128_t *);     /* extern */
s32 func_003C3A10(void *, s32, u32, s32); /* extern */
f32 func_003C3D30(u128_t *, s32, s32, s32); /* extern */
s32 func_003C41A0(void *, void *, s32, s32, s32, s32); /* extern */
f32 func_L01_0040E570(void *, s32 *);           /* extern */
f32 func_L01_004395E0(void *);                      /* extern */
s32 func_L01_004450F0(void *, s32, s32); /* extern */
s32 func_L01_00446780(void *, u128_t *, s32, s32, s32, s32, f32, s32, s32); /* extern */
s32 func_L01_004468C8(void *, s32, s32, s32, s32, s32, f32, f32, s32); /* extern */
s32 func_L01_0044C108(s32);                         /* extern */
s32 func_L01_0044E1B8(void *, s32);             /* extern */
s32 func_L01_004561B8(void *);                      /* extern */
s32 func_L01_004561E0(void *);                      /* extern */
s32 func_L01_0045AA30(void *, u128_t *);          /* extern */
s32 func_L01_0045BD78(void *, f32, f32, s32, s32); /* extern */
s32 func_L01_00463378(void *, f32 *, u128_t *, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_L01_004AA7E8(void *, s32);         /* extern */
s32 func_L06_003584D0(void *, u128_t *, u128_t *, void *, s32, s32, f32); /* extern */
s32 func_L23_003AF6E8(void *);                  /* extern */
s32 func_L23_003AFAF0(void *);                  /* extern */
s32 func_L23_003AFC40(void *);                  /* extern */
s32 func_L23_003AFE10(void *);                  /* extern */
s32 func_L23_003B0110(void *, s32 *, s32, f32); /* extern */
s32 func_L23_003B08E0(void *);                  /* extern */
extern s32 D_1A4BE0;
extern s32 D_1A4C60;
extern void *D_L23_001DE2D0;
extern s32 D_L23_001DED4C;
extern s32 D_L23_001DF15C;
extern s32 D_L23_001DF198;
extern s32 D_L23_001DF240;
extern s32 D_L23_001E1A40;
extern s32 D_L23_0021C0E0;

void func_L23_003AD800(void *arg0) {
    f32 sp10;                                       /* compiler-managed */
    f32 sp14;
    f32 sp18;
    f32 sp1C;
    u128_t sp20;
    f32 sp2C;
    s32 *var_16_2;
    s32 *var_17_2;
    s32 var_5;
    s32 var_5_2;
    s32 var_5_3;
    s32 var_5_4;
    s32 var_5_5;
    s32 var_5_6;
    s32 var_5_7;
    s32 var_f20;
    f32 temp_f0;
    f32 temp_f0_10;
    f32 temp_f0_11;
    f32 temp_f0_12;
    f32 temp_f0_13;
    f32 temp_f0_14;
    f32 temp_f0_15;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f0_9;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f2;
    f32 temp_f3;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    f32 var_f0_5;
    f32 var_f12;
    f32 var_f1;
    f32 var_f20_2;
    s16 temp_2_11;
    s32 temp_21;
    s32 temp_2_2;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_2_7;
    s32 temp_2_8;
    s32 temp_2_9;
    s32 temp_3_5;
    s32 temp_3_6;
    s32 var_17;
    s32 var_20;
    s32 var_23;
    s32 var_2_2;
    s32 var_4;
    u16 *var_16;
    u16 temp_3_3;
    u16 var_2;
    u32 temp_2_10;
    u32 var_6;
    u8 temp_2;
    u8 temp_2_3;
    u8 temp_3;
    u8 temp_3_2;
    u8 temp_3_4;
    u8 temp_3_7;
    u8 temp_3_8;
    u8 temp_3_9;
    void *temp_17;
    void *temp_19;
    void *temp_4;
    void *temp_fp;
    void *var_2_3;
    void *var_4_2;

    if ((func_L01_0044C108(arg0 + 0x10) != 0) && (temp_19 = (*(void **)((u8 *)(arg0) + 0x68)), ((*(u8 *)((u8 *)(arg0) + 0x20)) != 1))) {
        func_L23_003AF6E8(arg0);
        temp_3 = (*(u8 *)((u8 *)(arg0) + 0x95));
        switch (temp_3) {                           /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            (*(s32 *)((u8 *)(arg0) + 0x98)) = 0;
            (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x41) & 0xEFFF);
            func_L01_004AA7E8(arg0, 1);
        default:                                    /* switch 1 */
block_35:
            temp_2 = (*(u8 *)((u8 *)(arg0) + 0x20));
            switch (temp_2) {                       /* switch 2 */
            case 4:                                 /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                        func_003C3A10(arg0, 0, func_00382468((*(u8 *)((u8 *)((*(void **)((u8 *)((*(void **)((u8 *)(arg0) + 0x24))) + 0x48))) + 0x10))), 8);
                    }
                    (*(s32 *)((u8 *)(temp_19) + 0x214)) = func_00382498(0xFA, 0x1F4);
                }
                if (((*(s32 *)((u8 *)(temp_19) + 0x214)) <= 0) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 1)) {
                    func_003C3A10(arg0, 1, 0U, 8);
                }
                temp_3_2 = (*(u8 *)((u8 *)(arg0) + 0x42));
                if ((temp_3_2 == (*(u8 *)((u8 *)(arg0) + 0x43))) && (temp_3_2 == 1) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                    func_003C3A10(arg0, 0, func_00382468((*(u8 *)((u8 *)((*(void **)((u8 *)((*(void **)((u8 *)(arg0) + 0x24))) + 0x48))) + 0x10))), 8);
                    (*(s32 *)((u8 *)(temp_19) + 0x214)) = func_00382498(0xFA, 0x1F4);
                }
            default:                                /* switch 2 */
block_394:
                func_L23_003AFAF0(arg0);
                func_L23_003B08E0(arg0);
                break;
            case 2:                                 /* switch 2 */
                if ((((*(s64 *)((u8 *)(arg0) + 0x30)) & (0x8208 << 0x1D)) != (0x8200 << 0x17)) || ((*(s32 *)((u8 *)(arg0) + 0x98)) != 0) || !(func_L01_0040E570(arg0 + 0x10, &D_1A4C60) < 100.0f)) {
                    if (func_L01_004561B8(arg0) != 0) {
                        (*(s16 *)((u8 *)(arg0) + 0x96)) = 0;
                        temp_3_3 = (*(u16 *)((u8 *)(arg0) + 0x34)) & 0xFFBE;
                        temp_4 = (*(void **)((u8 *)(arg0) + 0x24));
                        (*(u16 *)((u8 *)(arg0) + 0x34)) = temp_3_3;
                        (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (temp_3_3 | ((*(u16 *)((u8 *)(temp_4) + 0x44)) & 0x1000));
                        (*(s32 *)((u8 *)(arg0) + 0x98)) = (s32) (*(s32 *)((u8 *)(temp_4) + 0x10));
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x20) {
                            func_003C3A10(arg0, 0x20, 0U, 0);
                        }
                    }
                    if (((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) && ((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43)))) {
                        func_L01_004450F0(arg0, 4, 2);
                    }
                    if ((*(u8 *)((u8 *)(arg0) + 0x31)) != 0) {
                        var_17 = 4;
                        do {
                            var_17 -= 1;
                            temp_f21 = func_00382538();
                            temp_f20 = func_003824E0(0, 0x3DF5C290);
                            sp10 = temp_f20 * func_0038D098(temp_f21);
                            sp14 = temp_f20 * func_0038D0B0(temp_f21);
                            temp_f0 = func_003824E0(0x3DF5C290, 0x3EA3D70B) - temp_f20;
                            sp1C = 1.5f;
                            sp18 = temp_f0;
                            func_0038CE20(&sp20, &sp10, 0.3f);
                            sp2C = 2.0f;
                            func_L01_00463378(arg0 + 0x10, &sp10, &sp20, 0x80808080, 0x60808080, 0xC, 0x19, 0xC, -1);
                        } while (var_17 >= 0);
                    }
                }
                goto block_394;
            case 3:                                 /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    temp_2_2 = (*(s32 *)((u8 *)(temp_19) + 0x2B0));
                    if (temp_2_2 == 0) {
block_63:
                        func_003C2880(arg0);
                        return;
                    }
                    (*(s32 *)((u8 *)(temp_19) + 0x2B0)) = (s32) (temp_2_2 - 1);
                    goto block_65;
                }
block_65:
                func_0038CAD0(temp_19 + 0x210);
                if ((*(s32 *)((u8 *)(temp_19) + 0x210)) == 0) {
                    sp10 = (*(u128_t *)((u8 *)(temp_19) + 0x290));
                    temp_fp = D_L23_001DED4C + (((*(s32 *)((u8 *)(temp_19) + 0x23C)) * 0x30) + 0x20);
                    var_20 = 0;
                    if ((*(s16 *)((u8 *)(temp_fp) + 0x12)) > 0) {
loop_68:
                        temp_21 = *((var_20 * 4) + (*(s32 *)((u8 *)(temp_fp) + 0x20)));
                        temp_17 = D_L23_001DF240 + (temp_21 << 7);
                        if ((var_20 != (*(s32 *)((u8 *)(saved_reg_gp) + 0x19C8))) && (temp_f0_2 = func_L01_0040E570(temp_17 + 0x30, &D_1A4C60), temp_f0_3 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x19BC)), !(temp_f0_2 < (temp_f0_3 * temp_f0_3))) && (temp_f0_4 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x19C0)), !((temp_f0_4 * temp_f0_4) < temp_f0_2)) && !(fabsf(func_0038DB00((*(f32 *)((u8 *)(&D_1A4BE0) + 0x98)), func_0038D160((*(f32 *)((u8 *)(temp_17) + 0x30)) - (*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)), (*(f32 *)((u8 *)(temp_17) + 0x34)) - (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84))))) > 1.5707964f)) {
                            temp_3_4 = (*(u8 *)((u8 *)(arg0) + 0x21));
                            var_23 = 1;
                            var_16 = *((temp_3_4 * 4) + &D_L23_0021C0E0);
                            if ((temp_3_4 != 0xFF) && (D_L23_001DF198 >= (s32) temp_3_4) && (var_16 != ((void *)0))) {
                                var_2 = *var_16;
loop_76:
                                temp_3_5 = D_L23_001DF15C + ((var_2 & 0x7FFF) << 8);
                                if (temp_3_5 != 0) {
                                    if (temp_3_5 != arg0) {
                                        if (func_00382380(temp_3_5 + 0x10, temp_21, 0) != 0) {
                                            var_23 = 0;
                                        } else {
                                            goto block_81;
                                        }
                                    } else {
block_81:
                                        temp_2_3 = (*(u8 *)((u8 *)(arg0) + 0x21));
                                        var_16 += 2;
                                        if ((temp_2_3 != 0xFF) && (D_L23_001DF198 >= (s32) temp_2_3) && (var_16 != ((void *)0))) {
                                            if ((*(s16 *)((u8 *)(var_16) + -2)) >= 0) {
                                                var_2 = (*(u16 *)((u8 *)(var_16) + 0));
                                                goto loop_76;
                                            }
                                            if (var_16 == *((temp_2_3 * 4) + &D_L23_0021C0E0)) {
                                                var_2 = (*(u16 *)((u8 *)(var_16) + 0));
                                                goto loop_76;
                                            }
                                        }
                                    }
                                }
                            }
                            if (var_23 != 0) {
                                sp10 = (u128_t)((*(f32 *)((u8 *)(temp_17) + 0x30)));
                                sp18 = func_003C3D30(&sp10, 0, 0, 0x3F000000);
                            } else {
                                goto block_92;
                            }
                        } else {
block_92:
                            var_20 += 1;
                            if (var_20 < (*(s16 *)((u8 *)(temp_fp) + 0x12))) {
                                goto loop_68;
                            }
                        }
                    }
                    (*(u128_t *)((u8 *)(arg0) + 0xF0)) = 0;
                    (*(f32 *)((u8 *)(arg0) + 0x10)) = sp10;
                    (*(u128_t *)((u8 *)(temp_19) + 0x250)) = sp10;
                    (*(f32 *)((u8 *)(temp_19) + 0x30)) = (f32) (*(s16 *)((u8 *)(temp_19) + 0x34));
                    temp_f0_5 = func_0038D160((f32)(&D_1A4BE0), (*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)) - (*(f32 *)((u8 *)(arg0) + 0x14)));
                    (*(s32 *)((u8 *)(temp_19) + 0x2BC)) = 0;
                    (*(s32 *)((u8 *)(temp_19) + 0x218)) = 0;
                    (*(s32 *)((u8 *)(temp_19) + 0x244)) = 0;
                    (*(s32 *)((u8 *)(temp_19) + 0x21C)) = 0;
                    (*(s32 *)((u8 *)(temp_19) + 0x240)) = 0;
                    (*(s32 *)((u8 *)(temp_19) + 0x228)) = 0;
                    (*(f32 *)((u8 *)(temp_19) + 0x24C)) = temp_f0_5;
                    func_L01_004450F0(arg0, 2, 1);
                }
                goto block_394;
            case 5:                                 /* switch 2 */
                if ((func_L01_004561B8(arg0) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 1)) {
                    func_003C3A10(arg0, 1, func_00382468((*(u8 *)((u8 *)((*(void **)((u8 *)((*(void **)((u8 *)(arg0) + 0x24))) + 0x4C))) + 0x10))), 8);
                }
                goto block_394;
            case 6:                                 /* switch 2 */
                if (func_L01_004561B8(arg0) == 0) {
                    var_17_2 = temp_19 + 0x250;
                    if (((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43))) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                        var_5 = 7;
block_254:
                        func_L01_004450F0(arg0, var_5, -1);
                    }
                } else {
                    var_17_2 = temp_19 + 0x250;
                    if ((*(s32 *)((u8 *)(temp_19) + 0x218)) == 0) {
                        temp_f20_2 = func_L01_0040E570(arg0 + 0x10, var_17_2);
                        temp_f1 = fabsf(func_0038DBA0((*(f32 *)((u8 *)(&D_L23_001E1A40) + 0x18)), func_0038D160((*(f32 *)((u8 *)(arg0) + 0x10)) - (*(f32 *)((u8 *)(&D_L23_001E1A40) + 0)), (*(f32 *)((u8 *)(arg0) + 0x14)) - (*(f32 *)((u8 *)(&D_L23_001E1A40) + 4)))));
                        if ((*(s32 *)((u8 *)(temp_19) + 0x220)) != 0) {
                            if (temp_f20_2 > 200.0f) {
                                (*(s32 *)((u8 *)(temp_19) + 0x218)) = (s32) ((func_00382468(2U) != 0) ? 5 : 4);
                            } else {
                                var_2_2 = 1;
                                if (!(temp_f1 > 0.5235988f)) {
                                    if (func_00382468(2U) != 0) {
                                        var_4 = ((*(s32 *)((u8 *)(temp_19) + 0x244)) != 0) ? 5 : 2;
                                    } else {
                                        var_4 = 4;
                                    }
                                    (*(s32 *)((u8 *)(temp_19) + 0x218)) = var_4;
                                } else {
                                    goto block_113;
                                }
                            }
                        } else {
                            var_2_2 = 3;
                            if (temp_f20_2 > 100.0f) {
                                var_2_2 = 4;
                            }
block_113:
                            (*(s32 *)((u8 *)(temp_19) + 0x218)) = var_2_2;
                        }
                        (*(f32 *)((u8 *)(temp_19) + 0x224)) = temp_f20_2;
                    }
                    temp_2_4 = (*(s32 *)((u8 *)(temp_19) + 0x218)) * 4;
                    func_L01_0045BD78(arg0, *(temp_2_4 + (saved_reg_gp + 0x1958)), *(temp_2_4 + (saved_reg_gp + 0x1940)), 0x3BA4B5BF, 0x3E00ADFD);
                    temp_2_5 = (*(s32 *)((u8 *)(temp_19) + 0x218));
                    switch (temp_2_5) {             /* switch 3 */
                    case 1:                         /* switch 3 */
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 8) {
                            var_5_2 = 8;
block_124:
                            func_003C3A10(arg0, var_5_2, 0U, 5);
                        }
                        break;
                    case 2:                         /* switch 3 */
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x1D) {
                            var_5_2 = 0x1D;
                            goto block_124;
                        }
                        break;
                    case 3:                         /* switch 3 */
                    case 4:                         /* switch 3 */
                        var_5_3 = 7;
block_252:
                        func_L01_004450F0(arg0, var_5_3, -1);
                        break;
                    case 5:                         /* switch 3 */
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xB) {
                            var_5_2 = 0xB;
                            goto block_124;
                        }
                        break;
                    }
                }
block_255:
                func_L23_003B0110(arg0, var_17_2, (*(s32 *)((u8 *)(temp_19) + 0x218)), (*(f32 *)((u8 *)(temp_19) + 0x24C)));
                goto block_394;
            case 7:                                 /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x94)) != 6) {
                        var_5_4 = 6;
                        goto block_375;
                    }
                    temp_2_6 = (*(s32 *)((u8 *)(temp_19) + 0x218));
                    switch (temp_2_6) {             /* switch 4 */
                    case 1:                         /* switch 4 */
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 9) {
                            var_5_5 = 9;
block_137:
                            func_003C3A10(arg0, var_5_5, 0U, 0);
                        }
                        goto block_145;
                    case 2:                         /* switch 4 */
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x1E) {
                            var_5_5 = 0x1E;
                            goto block_137;
                        }
                        goto block_145;
                    case 3:                         /* switch 4 */
                        var_16_2 = temp_19 + 0x250;
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 6) {
                            var_6 = func_00382468((*(u8 *)((u8 *)((*(void **)((u8 *)((*(void **)((u8 *)(arg0) + 0x24))) + 0x60))) + 0x10)));
                            var_5_6 = 6;
block_142:
                            func_003C3A10(arg0, var_5_6, var_6, 5);
                            goto block_145;
                        }
                        break;
                    case 4:                         /* switch 4 */
                        var_16_2 = temp_19 + 0x250;
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 7) {
                            var_6 = func_00382468((*(u8 *)((u8 *)((*(void **)((u8 *)((*(void **)((u8 *)(arg0) + 0x24))) + 0x64))) + 0x10)));
                            var_5_6 = 7;
                            goto block_142;
                        }
                        break;
                    case 5:                         /* switch 4 */
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xC) {
                            func_003C3A10(arg0, 0xC, 0U, 0);
                        }
                        goto block_145;
                    }
                    goto block_146;
                }
            default:                                /* switch 4 */
block_145:
                var_16_2 = temp_19 + 0x250;
block_146:
                var_4_2 = arg0 + 0x10;
                if (func_L23_003B0110(arg0, var_16_2, (*(s32 *)((u8 *)(temp_19) + 0x218)), (*(f32 *)((u8 *)(temp_19) + 0x24C))) == 0) {
                    func_L01_004450F0(arg0, 0xF, 4);
                    var_4_2 = arg0 + 0x10;
                }
                temp_f2 = func_L01_0040E570(var_4_2, var_16_2);
                if ((*(s32 *)((u8 *)(temp_19) + 0xF4)) != *(s32 *)0x1A71A0) {
                    temp_f0_6 = (*(f32 *)((u8 *)(temp_19) + 0xA4));
                    if (!(temp_f2 < (temp_f0_6 * temp_f0_6))) {
                        if ((temp_f2 - (*(f32 *)((u8 *)(temp_19) + 0x224))) > 16.0f) {
                            var_5_4 = 8;
                            goto block_375;
                        }
                    } else {
                        goto block_152;
                    }
                } else {
block_152:
                    var_5_4 = 8;
block_375:
                    func_L01_004450F0(arg0, var_5_4, -1);
                }
                goto block_394;
            case 8:                                 /* switch 2 */
                temp_3_6 = (*(s32 *)((u8 *)(temp_19) + 0x218));
                if (((temp_3_6 != 2) && (temp_3_6 != 5)) || ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                    if (func_L01_004561B8(arg0) == 0) {
                        if (((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43))) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                            temp_3_7 = (*(u8 *)((u8 *)(arg0) + 0x95));
                            switch (temp_3_7) {     /* switch 6; irregular */
                            case 2:                 /* switch 6 */
                                var_5_7 = 4;
block_181:
                                func_L01_004450F0(arg0, var_5_7, -1);
                                break;
                            case 3:                 /* switch 6 */
                                var_5_7 = 5;
                                goto block_181;
                            case 4:                 /* switch 6 */
                                var_5_7 = 0xB;
                                goto block_181;
                            default:                /* switch 6 */
                                func_L01_004450F0(arg0, 4, 2);
                                break;
                            }
                        }
                    } else {
                        temp_2_7 = (*(s32 *)((u8 *)(temp_19) + 0x218));
                        switch (temp_2_7) {         /* switch 5 */
                        case 1:                     /* switch 5 */
                            if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xA) {
                                func_003C3A10(arg0, 0xA, 0U, 5);
                                (*(s32 *)((u8 *)(temp_19) + 0x218)) = 0;
                            } else {
                            default:                /* switch 5 */
                            case 3:                 /* switch 5 */
                            case 4:                 /* switch 5 */
block_169:
                                (*(s32 *)((u8 *)(temp_19) + 0x218)) = 0;
                            }
                            break;
                        case 2:                     /* switch 5 */
                            if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x1F) {
                                func_003C3A10(arg0, 0x1F, 0U, 0);
                                (*(s32 *)((u8 *)(temp_19) + 0x218)) = 0;
                            } else {
                                goto block_169;
                            }
                            break;
                        case 5:                     /* switch 5 */
                            if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xD) {
                                func_003C3A10(arg0, 0xD, 0U, 0);
                            }
                            goto block_169;
                        }
                    }
                    func_L23_003B0110(arg0, arg0 + 0x10, (*(s32 *)((u8 *)(temp_19) + 0x218)), (*(f32 *)((u8 *)(temp_19) + 0x24C)));
                }
                goto block_394;
            case 9:                                 /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xE) {
                        func_003C3A10(arg0, 0xE, 0U, 8);
                    }
                    (*(s32 *)((u8 *)(temp_19) + 0x240)) = 0;
                }
                func_L23_003B0110(arg0, arg0 + 0x10, (*(s32 *)((u8 *)(temp_19) + 0x218)), (*(f32 *)((u8 *)(temp_19) + 0x24C)));
                if ((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43))) {
                    if (func_L01_0044E1B8(arg0, 0x41400000) != 0) {
                        (*(s32 *)((u8 *)(temp_19) + 0x244)) = 1;
                    }
                    if (((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43))) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                        temp_3_8 = (*(u8 *)((u8 *)(arg0) + 0x95));
                        switch (temp_3_8) {         /* switch 7; irregular */
                        case 2:                     /* switch 7 */
                            var_5_4 = 4;
                            goto block_375;
                        case 3:                     /* switch 7 */
                            var_5_4 = 5;
                            goto block_375;
                        }
                    }
                }
                goto block_394;
            case 10:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x12) {
                        func_003C3A10(arg0, 0x12, 0U, 8);
                    }
                    (*(s32 *)((u8 *)(temp_19) + 0x240)) = 0;
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43))) {
                    if (func_L01_0044E1B8(arg0, 0x41D80000) != 0) {
                        (*(s32 *)((u8 *)(temp_19) + 0x244)) = 0;
                    }
                    if (((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43))) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                        temp_3_9 = (*(u8 *)((u8 *)(arg0) + 0x95));
                        switch (temp_3_9) {         /* switch 8; irregular */
                        case 2:                     /* switch 8 */
                            var_5_4 = 4;
                            goto block_375;
                        case 3:                     /* switch 8 */
                            var_5_4 = 5;
                            goto block_375;
                        }
                    }
                }
                goto block_394;
            case 11:                                /* switch 2 */
                var_17_2 = temp_19 + 0x250;
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_19) + 0x22C)) = 0;
                    (*(s32 *)((u8 *)(temp_19) + 0x240)) = (s32) (*(s32 *)((u8 *)(temp_19) + 0x21C));
                    temp_f21_2 = func_L01_0040E570(arg0 + 0x10, var_17_2);
                    temp_f20_3 = func_0038DBA0((*(f32 *)((u8 *)(&D_1A4BE0) + 0x98)), func_0038D160((*(f32 *)((u8 *)(arg0) + 0x10)) - (*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)), (*(f32 *)((u8 *)(arg0) + 0x14)) - (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84))));
                    if ((temp_f21_2 > 40.0f) && ((*(s32 *)((u8 *)(temp_19) + 0x244)) == 0)) {
                        if (func_00382468(3U) != 0) {
                            var_5_3 = 0x10;
                            goto block_252;
                        }
                        goto block_222;
                    }
block_222:
                    temp_2_8 = (*(s32 *)((u8 *)(temp_19) + 0x244));
                    if (((*(f32 *)((u8 *)(saved_reg_gp) + 0x197C)) * (*(f32 *)((u8 *)(saved_reg_gp) + 0x197C))) < temp_f21_2) {
                        if ((temp_2_8 != 0) || (func_00382468(2U) != 0)) {
                            var_5_3 = 6;
                        } else {
                            var_5_3 = 9;
                        }
                        goto block_252;
                    }
                    temp_2_9 = (*(s32 *)((u8 *)(temp_19) + 0x220));
                    if (temp_2_8 != 0) {
                        if ((temp_2_9 != 0) && (temp_f20_3 < 0.5235988f) && (func_00382468(2U) != 0) && ((*(s32 *)((u8 *)(temp_19) + 0x240)) != 2)) {
                            var_5_3 = 0x11;
                        } else if (((*(s32 *)((u8 *)(temp_19) + 0x240)) == 0) && (func_00382468(2U) != 0)) {
                            var_5_3 = 0x12;
                        } else if (func_00382468(3U) != 0) {
                            var_5_3 = 0xE;
                        } else {
                            var_5_3 = 0xF;
                            if ((*(s32 *)((u8 *)(temp_19) + 0x240)) != 6) {

                            } else {
                                var_5_3 = 0xA;
                            }
                        }
                        goto block_252;
                    }
                    if ((temp_2_9 != 0) && (temp_f20_3 < 0.5235988f) && (func_00382468(2U) != 0) && ((*(s32 *)((u8 *)(temp_19) + 0x240)) != 2)) {
                        var_5_3 = 0x11;
                        goto block_252;
                    }
                    if (((*(s32 *)((u8 *)(temp_19) + 0x240)) == 0) && (func_00382468(2U) != 0)) {
                        var_5_3 = 0x12;
                        goto block_252;
                    }
                    if (func_00382468(3U) != 0) {
                        var_5_3 = 0xC;
                        goto block_252;
                    }
                    var_5_3 = 0xD;
                    if ((*(s32 *)((u8 *)(temp_19) + 0x240)) != 4) {
                        goto block_252;
                    }
                    var_5 = 9;
                    goto block_254;
                }
                goto block_255;
            case 12:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_19) + 0x21C)) = 3;
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x13) {
                        func_003C3A10(arg0, 0x13, 0U, 5);
                    }
                }
                func_L23_003B0110(arg0, temp_19 + 0x250, (*(s32 *)((u8 *)(temp_19) + 0x218)), (*(f32 *)((u8 *)(temp_19) + 0x24C)));
                if ((func_L01_004395E0(arg0) < 20.0f) && ((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43)))) {
                    if ((*(s32 *)((u8 *)(temp_19) + 0x220)) != 0) {
                        var_f0 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x1990));
                    } else {
                        var_f0 = 0.0f;
                    }
                    func_L01_004468C8(arg0, 4, 3, 0, 1, 0, (*(f32 *)((u8 *)(saved_reg_gp) + 0x1984)), (*(f32 *)((u8 *)(saved_reg_gp) + 0x1988)) + var_f0, 0x3F800000);
                }
                if ((func_L01_0044E1B8(arg0, 0x41A80000) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43)))) {
block_374:
                    var_5_4 = 0xB;
                    goto block_375;
                }
                goto block_394;
            case 13:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_19) + 0x21C)) = 4;
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x1C) {
                        func_003C3A10(arg0, 0x1C, 0U, 5);
                    }
                }
                func_L23_003B0110(arg0, temp_19 + 0x250, (*(s32 *)((u8 *)(temp_19) + 0x218)), (*(f32 *)((u8 *)(temp_19) + 0x24C)));
                if ((func_L01_004395E0(arg0) > 12.0f) && ((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43)))) {
                    if ((*(s32 *)((u8 *)(temp_19) + 0x220)) != 0) {
                        var_f0_2 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x1990));
                    } else {
                        var_f0_2 = 0.0f;
                    }
                    func_L01_004468C8(arg0, 9, 7, 0, 1, 0, (*(f32 *)((u8 *)(saved_reg_gp) + 0x1984)), (*(f32 *)((u8 *)(saved_reg_gp) + 0x1988)) + var_f0_2, 0x3F800000);
                    if ((*(s32 *)((u8 *)(temp_19) + 0x220)) != 0) {
                        var_f0_3 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x1990));
                    } else {
                        var_f0_3 = 0.0f;
                    }
                    func_L01_004468C8(arg0, 0xA, 7, 0, 1, 0, (*(f32 *)((u8 *)(saved_reg_gp) + 0x1984)), (*(f32 *)((u8 *)(saved_reg_gp) + 0x1988)) + var_f0_3, 0x3F800000);
                    if ((*(s32 *)((u8 *)(temp_19) + 0x220)) != 0) {
                        var_f0_4 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x1990));
                    } else {
                        var_f0_4 = 0.0f;
                    }
                    func_L01_004468C8(arg0, 8, 7, 0, 1, 0, (*(f32 *)((u8 *)(saved_reg_gp) + 0x1984)), (*(f32 *)((u8 *)(saved_reg_gp) + 0x1988)) + var_f0_4, 0x3F800000);
                }
                if ((func_L01_0044E1B8(arg0, 0x41F00000) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43)))) {
                    goto block_374;
                }
                goto block_394;
            case 14:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_19) + 0x21C)) = 5;
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xF) {
                        func_003C3A10(arg0, 0xF, 0U, 5);
                    }
                }
                func_L23_003B0110(arg0, temp_19 + 0x250, (*(s32 *)((u8 *)(temp_19) + 0x218)), (*(f32 *)((u8 *)(temp_19) + 0x24C)));
                if ((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43))) {
                    func_L23_003AFC40(arg0);
                }
                if ((func_L01_0044E1B8(arg0, 0x41A00000) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43)))) {
                    goto block_374;
                }
                goto block_394;
            case 15:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_19) + 0x230)) = 0;
                    (*(s32 *)((u8 *)(temp_19) + 0x21C)) = 5;
                    (*(f32 *)((u8 *)(temp_19) + 0x234)) = 0.0f;
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x1B) {
                        func_003C3A10(arg0, 0x1B, 0U, 5);
                    }
                }
                func_L23_003B0110(arg0, temp_19 + 0x250, (*(s32 *)((u8 *)(temp_19) + 0x218)), (*(f32 *)((u8 *)(temp_19) + 0x24C)));
                if ((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43))) {
                    temp_f0_7 = func_L01_004395E0(arg0);
                    if (temp_f0_7 > 16.0f) {
                        func_L23_003AFC40(arg0);
                    }
                    if (func_L01_0044E1B8(arg0, 0x41800000) != 0) {
                        (*(s32 *)((u8 *)(temp_19) + 0x230)) = 0;
                    }
                    if (func_L01_0044E1B8(arg0, 0x42040000) != 0) {
                        func_L01_004450F0(arg0, 0xB, -1);
                    }
                    if ((temp_f0_7 > 8.0f) && (temp_f0_7 < 16.0f)) {
                        func_003C41A0(temp_19 + 0x234, temp_19 + 0x230, 0x40A00000, 0x3FC80000, 0x3E800000, 0x3F880000);
                    }
                    if ((temp_f0_7 > 16.0f) && (temp_f0_7 < 24.0f)) {
                        func_003C41A0(temp_19 + 0x234, temp_19 + 0x230, 0, 0x3D555555, 0x3EA00000, 0x3F700000);
                    }
                    if ((temp_f0_7 > 8.0f) && (temp_f0_7 < 24.0f)) {
                        sp10 = (u128_t)((*(f32 *)((u8 *)(arg0) + 0x10)));
                        0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0x10($s2) */;
                        sp18 = func_003C3D30(&sp10, 0, 0, 0x3F000000) + (*(f32 *)((u8 *)(temp_19) + 0x234));
                        0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0x10($sp) */;
                        0 /* M2C_ERROR unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                        0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0x20($sp) */;
                        func_L01_0045AA30(arg0, &sp20);
                    }
                }
                goto block_394;
            case 16:                                /* switch 2 */
                if ((func_L01_004561B8(arg0) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x14)) {
                    func_003C3A10(arg0, 0x14, 0U, 5);
                }
                func_L23_003B0110(arg0, arg0 + 0x10, 0, func_0038D160((*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)) - (*(f32 *)((u8 *)(arg0) + 0x14))));
                if ((func_L01_0044E1B8(arg0, 0x41780000) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43)))) {
                    func_003C2F58(arg0, 4, &sp20);
                    0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0x250($s3) */;
                    0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0x20($sp) */;
                    0 /* M2C_ERROR unknown instruction: vsub.xyz $vf2, $vf2, $vf1 */;
                    0 /* M2C_ERROR unknown instruction: sqc2 $vf2, 0x10($sp) */;
                    func_0038CF68(&sp10, &sp10, 0x3F000001);
                    func_L06_003584D0(arg0, &sp10, &sp20, arg0 + 0xF0, 1, 0, (*(f32 *)((u8 *)(saved_reg_gp) + 0x198C)));
                }
                if ((func_L01_0044E1B8(arg0, 0x41A80000) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43)))) {
                    goto block_374;
                }
                goto block_394;
            case 18:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_19) + 0x21C)) = 1;
                    if ((*(s32 *)((u8 *)(temp_19) + 0x244)) != 0) {
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x10) {
                            func_003C3A10(arg0, 0x10, 0U, 5);
                        }
                    } else if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x15) {
                        func_003C3A10(arg0, 0x15, 0U, 5);
                    }
                }
                func_L23_003B0110(arg0, arg0 + 0x10, 0, (*(f32 *)((u8 *)(arg0) + 0xF8)));
                if (((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) && ((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43)))) {
                    goto block_374;
                }
                goto block_394;
            case 19:                                /* switch 2 */
                if ((func_L01_004561B8(arg0) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 2)) {
                    func_003C3A10(arg0, 2, 0U, 8);
                }
                if (((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) && ((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43)))) {
                    func_L01_004450F0(arg0, 4, 2);
                }
                func_L23_003B0110(arg0, arg0 + 0x10, 0, func_0038D160((*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)) - (*(f32 *)((u8 *)(arg0) + 0x14))));
                goto block_394;
            case 17:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    temp_2_10 = func_00382468(4U);
                    switch (temp_2_10) {            /* switch 9 */
                    case 0:                         /* switch 9 */
                    case 1:                         /* switch 9 */
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                            func_003C3A10(arg0, 4, 0U, 5);
                        }
                        var_f20 = 0x3FC90FDB;
block_350:
                        (*(f32 *)((u8 *)(temp_19) + 0x260)) = (f32) (func_0038D098(func_0038DAB8(var_f20, (*(f32 *)((u8 *)(arg0) + 0xF8)))) * (*(f32 *)((u8 *)(saved_reg_gp) + 0x19B4)));
                        var_f0_5 = func_0038DAB8(var_f20, (*(f32 *)((u8 *)(arg0) + 0xF8)));
block_351:
                        temp_f0_8 = func_0038D0B0(var_f0_5);
                        (*(f32 *)((u8 *)(temp_19) + 0x268)) = 0.0f;
                        (*(f32 *)((u8 *)(temp_19) + 0x264)) = (f32) (temp_f0_8 * (*(f32 *)((u8 *)(saved_reg_gp) + 0x19B4)));
                        0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0x260($s3) */;
                        0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0x10($s2) */;
                        0 /* M2C_ERROR unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                        0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0x260($s3) */;
                        (*(f32 *)((u8 *)(temp_19) + 0x268)) = func_003C3D30(temp_19 + 0x260, 0, 0, 0x3F000000);
                        break;
                    case 2:                         /* switch 9 */
                    case 3:                         /* switch 9 */
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 3) {
                            func_003C3A10(arg0, 3, 0U, 5);
                        }
                        (*(f32 *)((u8 *)(temp_19) + 0x260)) = (f32) (func_0038D098(func_0038DB00(1.5707964f, (*(f32 *)((u8 *)(arg0) + 0xF8)))) * (*(f32 *)((u8 *)(saved_reg_gp) + 0x19B4)));
                        var_f0_5 = func_0038DB00(1.5707964f, (*(f32 *)((u8 *)(arg0) + 0xF8)));
                        goto block_351;
                    case 4:                         /* switch 9 */
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 5) {
                            func_003C3A10(arg0, 5, 0U, 5);
                        }
                        var_f20 = 0x40490FDB;
                        goto block_350;
                    }
                    if (!(fabsf((*(f32 *)((u8 *)(temp_19) + 0x268)) - (*(f32 *)((u8 *)(arg0) + 0x18))) > 2.0f)) {
                        (*(s32 *)((u8 *)(temp_19) + 0x230)) = 0;
                        (*(s32 *)((u8 *)(temp_19) + 0x21C)) = 2;
                        (*(f32 *)((u8 *)(temp_19) + 0x234)) = 0.0f;
                        (*(u128_t *)((u8 *)(temp_19) + 0x270)) = (u128_t)((*(f32 *)((u8 *)(arg0) + 0x10)));
                        goto block_354;
                    }
                    goto block_374;
                }
block_354:
                if ((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43))) {
                    temp_f0_9 = func_L01_004395E0(arg0);
                    temp_f0_10 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x19A4));
                    var_f12 = (temp_f0_9 - temp_f0_10) / ((*(f32 *)((u8 *)(saved_reg_gp) + 0x19AC)) - temp_f0_10);
                    if (var_f12 > 1.0f) {
                        var_f12 = 1.0f;
                    } else if (var_f12 < 0.0f) {
                        var_f12 = 0.0f;
                    }
                    temp_f1_2 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x19A8));
                    if (((*(f32 *)((u8 *)(saved_reg_gp) + 0x19A4)) < temp_f0_9) && (temp_f0_9 <= temp_f1_2)) {
                        0 /* M2C_ERROR unknown instruction: c1 0x4 */;
                        var_f1 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x19B8)) * ((temp_f0_9 - (*(f32 *)((u8 *)(saved_reg_gp) + 0x19A4))) / (temp_f1_2 - (*(f32 *)((u8 *)(saved_reg_gp) + 0x19A4))));
                        goto block_366;
                    }
                    temp_f3 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x19AC));
                    if ((temp_f1_2 < temp_f0_9) && (temp_f0_9 <= temp_f3)) {
                        temp_f0_11 = (temp_f0_9 - temp_f1_2) / (temp_f3 - temp_f1_2);
                        var_f1 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x19B8)) * (1.0f - (temp_f0_11 * temp_f0_11));
block_366:
                        (*(f32 *)((u8 *)(temp_19) + 0x234)) = var_f1;
                    }
                    if (!((*(f32 *)((u8 *)(temp_19) + 0x234)) > 0.0f)) {
                        func_L23_003B0110(arg0, temp_19 + 0x250, 0, (*(f32 *)((u8 *)(temp_19) + 0x24C)));
                    } else {
                        0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0x270($s3) */;
                        0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0x260($s3) */;
                        0 /* M2C_ERROR unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                        0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0x10($sp) */;
                        func_0038CE20(&sp10, (f32 *) &sp10, var_f12);
                        0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0x270($s3) */;
                        0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0x10($sp) */;
                        0 /* M2C_ERROR unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                        0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0x10($s2) */;
                        0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0x10($sp) */;
                        sp18 = (*(f32 *)((u8 *)(temp_19) + 0x268)) + (*(f32 *)((u8 *)(temp_19) + 0x234));
                        0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0x10($sp) */;
                        0 /* M2C_ERROR unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                        0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0x20($sp) */;
                        func_L01_0045AA30(arg0, &sp20);
                    }
                    if (func_L01_0044E1B8(arg0, 0x42080000) != 0) {
                        goto block_374;
                    }
                }
                goto block_394;
            case 20:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    if (!((*(f32 *)((u8 *)(temp_19) + 0x30)) <= 0.0f)) {
                        if ((*(f32 *)((u8 *)(saved_reg_gp) + 0x1970)) <= (*(f32 *)((u8 *)(temp_19) + 0x2B8))) {
                            if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x18) {
                                func_003C3A10(arg0, 0x18, 0U, 3);
                            }
                        } else if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x18) {
                            func_003C3A10(arg0, 0x18, 0U, 3);
                        }
                        if ((*(s32 *)((u8 *)(temp_19) + 0x220)) != 0) {
                            (*(f32 *)((u8 *)(arg0) + 0x48)) = 1.5f;
                        }
                        goto block_388;
                    }
                    func_L23_003AFE10(arg0);
                    func_L01_004450F0(arg0, 3, 0);
                    return;
                }
block_388:
                temp_f1_3 = (*(f32 *)((u8 *)(temp_19) + 0x2B8));
                temp_f0_12 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x1974));
                var_f20_2 = temp_f0_12;
                if (temp_f1_3 < temp_f0_12) {
                    var_f20_2 = temp_f1_3;
                }
                (*(f32 *)((u8 *)(temp_19) + 0x2B8)) = (f32) (temp_f1_3 - var_f20_2);
                sp10 = func_0038D098((*(f32 *)((u8 *)(temp_19) + 0x2B4))) * var_f20_2;
                temp_f0_13 = func_0038D0B0((*(f32 *)((u8 *)(temp_19) + 0x2B4))) * var_f20_2;
                sp18 = 0.0f;
                sp14 = temp_f0_13;
                func_L01_0045AA30(arg0, (u128_t *) &sp10);
                sp20 = func_0038D098((*(f32 *)((u8 *)(temp_19) + 0x2B4))) * (*(f32 *)((u8 *)(saved_reg_gp) + 0x1998));
                temp_f0_14 = func_0038D0B0((*(f32 *)((u8 *)(temp_19) + 0x2B4)));
                temp_f1_4 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x1998));
                0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0x10($s2) */;
                unksp28 = 0.0f;
                unksp24 = temp_f0_14 * temp_f1_4;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0x20($sp) */;
                0 /* M2C_ERROR unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0x20($sp) */;
                unksp28 += temp_f1_4;
                func_L01_00446780(arg0, &sp20, 3, 0, 1, 0, temp_f1_4, 0x41A00000, 0x3F800000);
                if (((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43))) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                    func_L01_004450F0(arg0, 5, 3);
                }
                func_L23_003B0110(arg0, arg0 + 0x10, 0, func_0038DB48((*(f32 *)((u8 *)(temp_19) + 0x2B4)) + 3.1415927f));
                goto block_394;
            }
            break;
        case 2:                                     /* switch 1 */
            if ((func_L01_004561E0(arg0) != 0) && ((*(s32 *)((u8 *)(temp_19) + 0x244)) != 0)) {
                func_L01_004450F0(arg0, 0xA, -1);
            }
            if ((*(s16 *)((u8 *)(temp_19) + 0x184)) == 1) {
                func_L01_004450F0(arg0, 5, 3);
            }
            goto block_35;
        case 3:                                     /* switch 1 */
            if ((func_L01_004561E0(arg0) != 0) && ((*(s32 *)((u8 *)(temp_19) + 0x244)) != 0)) {
                func_L01_004450F0(arg0, 0xA, -1);
            }
            if ((*(s16 *)((u8 *)(temp_19) + 0x184)) == 1) {
                func_L01_004450F0(arg0, 0xB, 4);
            }
            goto block_35;
        case 4:                                     /* switch 1 */
            if (func_L01_004561E0(arg0) != 0) {
                (*(s32 *)((u8 *)(temp_19) + 0x240)) = 0;
                (*(s32 *)((u8 *)(temp_19) + 0x21C)) = 0;
            }
            temp_2_11 = (*(s16 *)((u8 *)(temp_19) + 0x184));
            if (temp_2_11 == 1) {
                sp10 = func_0038D098(func_0038D160((*(f32 *)((u8 *)(arg0) + 0x10)) - (*(f32 *)((u8 *)(temp_19) + 0x170)), (*(f32 *)((u8 *)(arg0) + 0x14)) - (*(f32 *)((u8 *)(temp_19) + 0x174)))) * (*(f32 *)((u8 *)(saved_reg_gp) + 0x1978));
                temp_f0_15 = func_0038D0B0(func_0038D160((*(f32 *)((u8 *)(arg0) + 0x10)) - (*(f32 *)((u8 *)(temp_19) + 0x170)), (*(f32 *)((u8 *)(arg0) + 0x14)) - (*(f32 *)((u8 *)(temp_19) + 0x174))));
                sp18 = 0.0f;
                sp14 = temp_f0_15 * (*(f32 *)((u8 *)(saved_reg_gp) + 0x1978));
                0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0x170($s3) */;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0x10($sp) */;
                0 /* M2C_ERROR unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0x250($s3) */;
                (*(f32 *)((u8 *)(temp_19) + 0x24C)) = func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x170)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x174)) - (*(f32 *)((u8 *)(arg0) + 0x14)));
                goto block_30;
            }
            var_2_3 = (*(void **)((u8 *)(saved_reg_gp) + 0x1A20));
            if (temp_2_11 == 0) {
                var_2_3 = (*(void **)((u8 *)(saved_reg_gp) + 0x1A20));
                if (func_L01_004561E0(arg0) == 0) {
                    if (*(s32 *)0x1A7430 <= 0) {
                        func_L01_004450F0(arg0, 0x13, 2);
                        var_2_3 = (*(void **)((u8 *)(saved_reg_gp) + 0x1A20));
                    } else {
                        func_L01_004450F0(arg0, 5, 3);
block_30:
                        var_2_3 = D_L23_001DE2D0;
                    }
                }
            }
            if ((var_2_3 != ((void *)0)) && ((*(f32 *)((u8 *)((*(void **)((u8 *)(var_2_3) + 0x68))) + 0x30)) <= 0.0f)) {
                func_L23_003AFE10(arg0);
                goto block_63;
            }
            goto block_35;
        }
    }
    /* bug: did not emit code for node #197; contents below: */
    /* bug: did not emit code for node #198; contents below: */
    /* bug: did not emit code for node #215; contents below: */
    func_L01_004450F0(arg0, 4, 2);
}


#endif
