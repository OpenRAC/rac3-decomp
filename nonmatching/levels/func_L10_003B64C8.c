/* func_L10_003B64C8: Opus handoff (prep by Sonnet worker w6, 2026-11-08)
   Size: 8408 bytes, places: 1 level (10), file: src/levels/10_zeldrin_starport/L10_003B5B48.c
   flags: the file's own line (-O2 -G8 -fopt-stack -mno-check-zero-division, NO @ps2as); retail has 128 mtc1 (inline float constants) and 2 lq/sq:
     a file with an estimated flag line and no C yet: try --as ps2as first (Ps2EeAs inline constants), then check with --all-modes.
   Step 0: one function; 2 jump tables (jtbl_002BD350, jtbl_002BD370), 26 `case`s in the m2c. a level-10 boss/enemy moby update (calls moby_set_state x40, L10_003B9078 x26, vec_distance_xy x26, moby_anim_blend x24, angle_spring, atan2, vec_spring).
   rac2 twin: none: best opcode 0.296 (func_L13_0040A720); same-level and cross-level rac3 siblings <= 0.17 (fam.out: L05_003560C8/L20_003FB6A8 0.16-0.17); callees have no rac2 twins (callfp: mapped=0).
   Mapping / identical / changed: no twin to map. Hot callees have names in config/names.tsv (moby_set_state, moby_anim_blend,
     vec_set_length, angle_add/sub, atan2, rand_*), so the m2c is readable as moby-AI code.
   No COP2 instructions: a plain-C MATCH is possible in principle.
   Draft: no compiling draft (m2c converted: 741 lines; compiles except 2 spots: `sp90 = (u128_t)(float)` stack vector assignments (declare `f32 sp90[4]`, build with plain stores) and a few pointer/int mixes (warnings at lines 323-379: func_0038CF38 arg 2, func_L01_00448340 arg 2).). The fenced block is the mechanically converted m2c (M2C_FIELD ->
     byte-offset casts, M2C_UNK -> s32, s128 -> u128_t TI typedef). Not measured.
   Left for Opus: (1) type the object (moby: pos +0x10, state +0x20 u8, class ptr +0x24, flags +0x34 u16; the +0x68 pointer is the
     per-moby vars block); (2) turn float-hex arguments back into f32; (3) get it to compile, measure, then register/scheduling work.
   Tool note: tools in out/tools-w6/ (m2c2.py: restores the `.word`-hidden lq/sq and appends the jump tables so m2c runs at all;
     conv.py: M2C_FIELD -> casts; iter.py: compile loop dropping conflicting prototypes).
*/
#if 0 /* does not compile yet: m2c2 draft mechanically converted (tools in worker w6 scratch), prototypes unverified */
typedef int u128_t __attribute__((mode(TI)));
s32 func_00382498(s32, s32);                /* extern */
s32 func_0038CB00(void *);                          /* extern */
f32 func_0038CF00(void *, u128_t *);                  /* extern */
f32 func_0038CF38(void *, void *);                  /* extern */
s32 func_0038CF68(s32 *, void *, f32);      /* extern */
f32 func_0038D160(f32, f32, f32);                   /* extern */
f32 func_0038DBA0(f32, f32);                        /* extern */
s32 func_003A52A0(s32, s32, void *);    /* extern */
s32 func_003C2880(void *);                      /* extern */
s32 func_003C2F58(void *, s32, u128_t *);     /* extern */
s32 func_003C3A10(void *, s32, s32, s32); /* extern */
f32 func_003C3D30(void *, s32, s32, s32); /* extern */
s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
f32 func_L01_004395E0(void *);                      /* extern */
s32 func_L01_004450F0(void *, s32, s32); /* extern */
f32 func_L01_00447878(u128_t *, void *, s32, f32, s32); /* extern */
s32 func_L01_004482A0(void *, void *, void *, f32, s32, s32, s32); /* extern */
s32 func_L01_00448340(void *, u128_t *, void *, s32, s32, s32); /* extern */
s32 func_L01_00448728(void *, void *, s32, f32, s32, s32, s32); /* extern */
s32 func_L01_0044E1B8(void *, s32);             /* extern */
s32 func_L01_00454370(void *, void *);              /* extern */
s32 func_L01_004561B8(void *);                      /* extern */
s32 func_L01_004561E0(void *);                      /* extern */
s32 func_L01_0045A748(void *, void *);          /* extern */
s32 func_L01_0045A898(void *, void *, f32);     /* extern */
s32 func_L01_0045A9F0(void *);                  /* extern */
s32 func_L01_0045BD10(void *, f32);             /* extern */
s32 func_L01_0045BD78(void *, s32, s32, s32, s32); /* extern */
s32 func_L01_0045BDE8(void *, s32);                 /* extern */
s32 func_L01_0045C150(void *, s32, s32, s32);   /* extern */
s32 func_L01_0045C2A0(void *, f32, f32, f32);       /* extern */
s32 func_L05_0032B880(u128_t *, s32 *, void *, s32); /* extern */
s32 func_L10_003B85A0(void *);                      /* extern */
s32 func_L10_003B8ED0(void *, s32);         /* extern */
s32 func_L10_003B8F50(void *);                  /* extern */
s32 func_L10_003B9078(void *, s32, s32, s32); /* extern */
s32 func_L10_003B9D28(void *);                      /* extern */
extern s32 D_L10_0021D1C0;

void func_L10_003B64C8(void *arg0) {
    u128_t sp90;
    s32 spA0;
    f32 spA8;
    s32 var_4;
    s32 var_5;
    s32 var_5_3;
    s32 var_5_4;
    s32 var_5_5;
    f32 temp_4_2;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 var_f0;
    f32 var_f0_2;
    u128_t *temp_16_3;
    s32 *temp_16_6;
    s32 *temp_17_11;
    s32 *temp_17_3;
    s32 *temp_17_4;
    s32 *temp_17_5;
    s32 *temp_17_6;
    s32 temp_2_10;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_5;
    s32 temp_6_2;
    u32 temp_4;
    u8 temp_2;
    u8 temp_3;
    u8 temp_3_5;
    void *temp_16;
    void *temp_16_10;
    void *temp_16_11;
    void *temp_16_12;
    void *temp_16_13;
    void *temp_16_14;
    void *temp_16_15;
    void *temp_16_16;
    void *temp_16_17;
    void *temp_16_18;
    void *temp_16_19;
    void *temp_16_20;
    void *temp_16_21;
    void *temp_16_22;
    void *temp_16_2;
    void *temp_16_4;
    void *temp_16_5;
    void *temp_16_7;
    void *temp_16_8;
    void *temp_16_9;
    void *temp_17;
    void *temp_17_10;
    void *temp_17_2;
    void *temp_17_7;
    void *temp_17_8;
    void *temp_17_9;
    void *temp_19;
    void *temp_2_2;
    void *temp_2_7;
    void *temp_2_8;
    void *temp_2_9;
    void *temp_3_4;
    void *temp_4_3;
    void *temp_4_4;
    void *temp_4_5;
    void *temp_4_6;
    void *temp_4_7;
    void *temp_4_8;
    void *temp_4_9;
    void *temp_5_2;
    void *temp_6;
    void *var_16;
    void *var_21;
    void *var_21_2;
    void *var_21_3;
    void *var_2;
    void *var_5_2;

    temp_19 = (*(void **)((u8 *)(arg0) + 0x68));
    if ((((*(s32 *)((u8 *)(temp_19) + 0x33C)) == 0) || ((*(u8 *)((u8 *)(arg0) + 0x20)) != 0x1D)) && (func_L10_003B85A0(arg0) == 0)) {
        temp_3 = (*(u8 *)((u8 *)(arg0) + 0x95));
        switch (temp_3) {                           /* switch 1 */
        case 0:                                     /* switch 1 */
            if (func_L01_004561E0(arg0) != 0) {
                (*(s16 *)((u8 *)(temp_19) + 0x2D6)) = (s16) ((s32) ((func_00382498(0, 0x1E) * 5) + 2) / 6);
            }
            if ((*(s16 *)((u8 *)(temp_19) + 0x234)) != 1) {
                if (((*(s32 *)((u8 *)(temp_19) + 0x2D8)) != 0) && (func_0038CB00(temp_19 + 0x2D6) != 0)) {
                    (*(s32 *)((u8 *)(temp_19) + 0x2D8)) = 0;
                    if ((*(s32 *)((u8 *)(temp_19) + 0x2D0)) < 0xFA) {
                        var_4 = 0x1E0;
block_43:
                        (*(s32 *)((u8 *)(temp_19) + 0x2D0)) = (s32) ((s32) ((func_00382498(var_4, 0x258) * 5) + 2) / 6);
                    }
                }
            } else {
                func_L10_003B9078(arg0, 6, 0, 8);
                func_L01_004450F0(arg0, 9, 2);
                temp_3_2 = (*(s32 *)((u8 *)(temp_19) + 0x310));
                if (temp_3_2 != -1) {
                    func_L01_004450F0(arg0, 0xC, 2);
                    func_L10_003B9078(arg0, 6, 0, 8);
                    if ((*(s32 *)((u8 *)(temp_19) + 0x320)) != 0) {
                        func_003C3A10((*(void **)((u8 *)(temp_19) + 0x2DC)), 9, 0, 8);
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 6) {
                            func_003C3A10(arg0, 6, 0, 8);
                        }
                        func_L01_004450F0(arg0, 0x11, -1);
                    }
                } else if ((*(s32 *)((u8 *)(temp_19) + 0x314)) != temp_3_2) {
                    func_L01_004450F0(arg0, 0xD, 2);
                    func_L10_003B9078(arg0, 6, 0, 8);
                    if ((*(s32 *)((u8 *)(temp_19) + 0x320)) != 0) {
                        func_003C3A10((*(void **)((u8 *)(temp_19) + 0x2DC)), 9, 0, 8);
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 6) {
                            func_003C3A10(arg0, 6, 0, 8);
                        }
                        func_L01_004450F0(arg0, 0xF, -1);
                    }
                }
                if ((*(s32 *)((u8 *)(temp_19) + 0x328)) != 0) {
                    func_L01_004450F0(arg0, 0xE, -1);
                    func_L10_003B9078(arg0, 0xD, 0, 2);
                    func_003C3A10((*(void **)((u8 *)(temp_19) + 0x2DC)), 2, 0, 8);
                    if ((*(s32 *)((u8 *)(temp_19) + 0x320)) != 0) {
                        func_003C3A10((*(void **)((u8 *)(temp_19) + 0x2DC)), 9, 0, 8);
                        func_L01_004450F0(arg0, 0x10, -1);
                    }
                    if ((*(s32 *)((u8 *)(temp_19) + 0x310)) != -1) {
                        func_003C3A10((*(void **)((u8 *)(temp_19) + 0x2DC)), 2, 0, 8);
                        func_L01_004450F0(arg0, 0x10, -1);
                    }
                }
            }
        default:                                    /* switch 1 */
block_44:
            temp_2 = (*(u8 *)((u8 *)(arg0) + 0x20));
            temp_4 = temp_2 - 1;
            if (temp_4 < 0x1FU) {
                temp_4_2 = *((temp_4 * 4) + &jtbl_002BD370);
                switch (temp_2) {                   /* switch 2 */
                case 12:                            /* switch 2 */
                    func_L01_00448728((*(void **)((u8 *)(temp_19) + 0x2DC)) + 0xF8, temp_19 + 0x330, 0, (*(f32 *)((u8 *)(arg0) + 0xF8)), 0x3B494FE9, 0x3A5B9CFF, 0x3E1D466E);
                    if (func_L01_004561B8(arg0) != 0) {
                        (*(s32 *)((u8 *)(temp_19) + 0x2D8)) = 0;
                    }
                    if (func_L01_0045BDE8(arg0, (*(s32 *)((u8 *)(temp_19) + 0x310))) != 0) {
                        func_L10_003B9078(arg0, 9, 0, 8);
                        func_L01_004450F0(arg0, 0x1B, 2);
                    }
                    if ((func_0038CF38(arg0 + 0x10, (*(s32 *)((u8 *)(temp_19) + 0x230)) + 0x10) < 10.0f) && ((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 5U) && ((*(s32 *)((u8 *)(temp_19) + 0x348)) == 0)) {
block_158:
                        func_L10_003B9078(arg0, 9, 0, 8);
                        func_L01_004450F0(arg0, 0x1B, 2);
                    }
                    break;
                case 17:                            /* switch 2 */
                    if (func_L01_004561B8(arg0) != 0) {
                        (*(s32 *)((u8 *)(temp_19) + 0x2D8)) = 0;
                    }
                    temp_16 = (*(void **)((u8 *)(temp_19) + 0x2DC)) + 0xF8;
                    func_L01_00448728(temp_16, temp_19 + 0x330, 0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))), 0x3B494FE9, 0x3A5B9CFF, 0x3E1D466E);
                    if (func_L01_0045BDE8(arg0, (*(s32 *)((u8 *)(temp_19) + 0x310))) != 0) {
                        func_L10_003B9078(arg0, 9, 0, 8);
                        func_L01_004450F0(arg0, 0x1B, 2);
                    }
                    if (func_0038CF38(arg0 + 0x10, (*(s32 *)((u8 *)(temp_19) + 0x230)) + 0x10) < 8.0f) {
                        if ((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 5U) {
                            func_L10_003B9078(arg0, 9, 0, 8);
                            func_L01_004450F0(arg0, 0x1B, 2);
                        }
                    }
                    if (((*(u16 *)((u8 *)(arg0) + 0x96)) >= 0x5BU) && (func_L10_003B9D28(arg0) != 0)) {
                        func_003C3A10((*(void **)((u8 *)(temp_19) + 0x2DC)), 0xA, 0, 5);
                        var_5 = 0x13;
block_188:
                        func_L01_004450F0(arg0, var_5, -1);
                    }
                    break;
                case 19:                            /* switch 2 */
                    temp_16_2 = (*(void **)((u8 *)(temp_19) + 0x2DC)) + 0xF8;
                    func_L01_00448728(temp_16_2, temp_19 + 0x330, 0, func_0038D160(temp_4_2, (*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))), 0x3B494FE9, 0x3A5B9CFF, 0x3E1D466E);
                    if ((*(u8 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x2DC))) + 0x60)) & 2) {
                        func_L01_004450F0(arg0, 0x11, 2);
                        func_003C3A10((*(void **)((u8 *)(temp_19) + 0x2DC)), 9, 0, 5);
                    }
                    if ((func_L01_0045BDE8(arg0, (*(s32 *)((u8 *)(temp_19) + 0x310))) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 9)) {
                        func_003C3A10(arg0, 9, 0, 8);
                    }
                    if (func_L01_0044E1B8((*(void **)((u8 *)(temp_19) + 0x2DC)), 0x3F000000) != 0) {
                        temp_4_3 = (*(void **)((u8 *)(temp_19) + 0x2DC));
                        if ((*(u8 *)((u8 *)(temp_4_3) + 0x42)) == 0xA) {
                            func_003C2F58(temp_4_3, 0, &sp90);
                            if (!(fabsf((*(f32 *)((u8 *)(arg0) + 0x18)) - (*(f32 *)((u8 *)(temp_19) + 0x228))) < 2.0f)) {
block_176:
                                temp_17 = arg0 + 0x10;
                                var_f0 = func_0038CF38(temp_17, (*(s32 *)((u8 *)(temp_19) + 0x230)) + 0x10);
                                var_21 = temp_17;
                                var_5_2 = (*(void **)((u8 *)(temp_19) + 0x2DC)) + 0xC0;
block_177:
                                func_0038CF68(&spA0, var_5_2, (var_f0 / 1.3f) * 0.020000001f);
                            } else {
block_174:
                                temp_2_2 = arg0 + 0x10;
                                var_16 = (*(void **)((u8 *)(temp_19) + 0x2DC)) + 0xC0;
                                var_21 = temp_2_2;
                                var_f0_2 = func_0038CF38(temp_2_2, (*(s32 *)((u8 *)(temp_19) + 0x230)) + 0x10);
block_175:
                                func_0038CF68(&spA0, var_16, (var_f0_2 / 1.3f) * 0.020000001f);
                            }
block_178:
                            spA8 = func_L01_00447878(&sp90, temp_19 + 0x220, 0, func_0038CF38(var_21, (*(s32 *)((u8 *)(temp_19) + 0x230)) + 0x10) * 0.020000001f, 0xBB902DE0);
                            func_L05_0032B880(&sp90, &spA0, arg0, 0x40A00000);
                        }
                    }
                    break;
                case 14:                            /* switch 2 */
                    temp_17_2 = arg0 + 0x10;
                    temp_16_3 = *(((*(s32 *)((u8 *)(temp_19) + 0x314)) * 4) + &D_L10_0021D1C0) + 0x10;
                    func_L01_00448340(temp_17_2, temp_16_3, temp_19 + 0x2E8, 0x3B51B718, 0x3C6BEDFB, 0x3DA3D70B);
                    if (func_0038CF00(temp_17_2, temp_16_3) < 0.25f) {
                        if ((*(s32 *)((u8 *)(temp_19) + 0x32C)) != 0) {
                            func_003C3A10((*(void **)((u8 *)(temp_19) + 0x2DC)), 9, 0, 8);
                            var_5 = 0x1B;
                            goto block_188;
                        }
                        func_L10_003B9078(arg0, 0xE, 0, 8);
                        func_L01_004450F0(arg0, 8, -1);
                        (*(s32 *)((u8 *)(temp_19) + 0x334)) = 0;
                    }
                    break;
                case 16:                            /* switch 2 */
                    temp_16_4 = arg0 + 0x10;
                    temp_17_3 = *(((*(s32 *)((u8 *)(temp_19) + 0x310)) * 4) + &D_L10_0021D1C0);
                    func_L01_00448340(temp_16_4, temp_17_3 + (((*(s32 *)((u8 *)(temp_19) + 0x334)) * 0x10) + 0x10), temp_19 + 0x2E8, 0x3B51B718, 0x3C6BEDFB, 0x3DA3D70B);
                    if (func_0038CF00(temp_16_4, temp_17_3 + (((*(s32 *)((u8 *)(temp_19) + 0x334)) * 0x10) + 0x10)) < 0.25f) {
                        temp_2_3 = (*(s32 *)((u8 *)(temp_19) + 0x334)) + 1;
                        (*(s32 *)((u8 *)(temp_19) + 0x334)) = temp_2_3;
                        if (temp_2_3 >= *temp_17_3) {
                            if ((*(s32 *)((u8 *)(temp_19) + 0x32C)) != 0) {
                                func_003C3A10((*(void **)((u8 *)(temp_19) + 0x2DC)), 9, 0, 8);
                                func_L01_004450F0(arg0, 0x1B, -1);
                            } else {
                                func_L10_003B9078(arg0, 0xE, 0, 8);
                                func_L01_004450F0(arg0, 8, -1);
                                (*(s32 *)((u8 *)(temp_19) + 0x334)) = 0;
                            }
                        }
                    }
                    if (((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 0x5BU) && (func_L10_003B9D28(arg0) != 0) && ((*(u8 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x2DC))) + 0x42)) == 9)) {
                        var_5_3 = 0x14;
block_108:
                        func_L01_004450F0(arg0, var_5_3, -1);
                        func_003C3A10((*(void **)((u8 *)(temp_19) + 0x2DC)), 0xA, 0, 3);
                    }
                    break;
                case 20:                            /* switch 2 */
                    temp_16_5 = arg0 + 0x10;
                    temp_17_4 = *(((*(s32 *)((u8 *)(temp_19) + 0x310)) * 4) + &D_L10_0021D1C0);
                    var_21_2 = temp_16_5;
                    func_L01_00448340(temp_16_5, temp_17_4 + (((*(s32 *)((u8 *)(temp_19) + 0x334)) * 0x10) + 0x10), temp_19 + 0x2E8, 0x3B51B718, 0x3C6BEDFB, 0x3DA3D70B);
                    if (func_0038CF00(temp_16_5, temp_17_4 + (((*(s32 *)((u8 *)(temp_19) + 0x334)) * 0x10) + 0x10)) < 0.25f) {
                        temp_2_4 = (*(s32 *)((u8 *)(temp_19) + 0x334)) + 1;
                        (*(s32 *)((u8 *)(temp_19) + 0x334)) = temp_2_4;
                        temp_3_3 = *temp_17_4;
                        if (temp_2_4 >= temp_3_3) {
                            (*(s32 *)((u8 *)(temp_19) + 0x334)) = (s32) (temp_3_3 - 1);
                        }
                    }
                    if (func_L01_0044E1B8((*(void **)((u8 *)(temp_19) + 0x2DC)), 0x3F000000) != 0) {
                        temp_4_4 = (*(void **)((u8 *)(temp_19) + 0x2DC));
                        if ((*(u8 *)((u8 *)(temp_4_4) + 0x42)) == 0xA) {
                            func_003C2F58(temp_4_4, 0, &sp90);
                            if (!(fabsf((*(f32 *)((u8 *)(arg0) + 0x18)) - (*(f32 *)((u8 *)(temp_19) + 0x228))) < 2.0f)) {
block_116:
                                func_0038CF68(&spA0, (*(void **)((u8 *)(temp_19) + 0x2DC)) + 0xC0, (func_0038CF38(var_21_2, (*(s32 *)((u8 *)(temp_19) + 0x230)) + 0x10) / 1.3f) * 0.020000001f);
                            } else {
block_115:
                                func_0038CF68(&spA0, (*(void **)((u8 *)(temp_19) + 0x2DC)) + 0xC0, (func_0038CF38(var_21_2, (*(s32 *)((u8 *)(temp_19) + 0x230)) + 0x10) / 1.3f) * 0.020000001f);
                            }
block_117:
                            spA8 = func_L01_00447878(&sp90, temp_19 + 0x220, 0, func_0038CF38(var_21_2, (*(s32 *)((u8 *)(temp_19) + 0x230)) + 0x10) * 0.020000001f, 0xBB902DE0);
                            func_L05_0032B880(&sp90, &spA0, arg0, 0x40A00000);
                        }
                    }
block_118:
                    if ((*(u8 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x2DC))) + 0x60)) & 2) {
                        func_L01_004450F0(arg0, 0x10, 2);
                        func_003C3A10((*(void **)((u8 *)(temp_19) + 0x2DC)), 9, 0, 5);
                    }
                    break;
                case 24:                            /* switch 2 */
                    (*(s32 *)((u8 *)(temp_19) + 0xA8)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0xA8)) | 4);
                    temp_16_6 = *(((*(s32 *)((u8 *)(temp_19) + 0x314)) * 4) + &D_L10_0021D1C0);
                    temp_6 = temp_16_6 + ((*(s32 *)((u8 *)(temp_19) + 0x334)) * 0x10);
                    func_L01_004482A0(arg0 + 0x18, temp_19 + 0x2E8, temp_6, (*(f32 *)((u8 *)(temp_6) + 0x18)), 0x3B51B718, 0x3C6BEDFB, 0x3DA3D70B);
                    if (func_L01_0045BDE8(arg0, (*(s32 *)((u8 *)(temp_19) + 0x314))) != 0) {
                        temp_2_5 = (*(s32 *)((u8 *)(temp_19) + 0x334)) + 1;
                        (*(s32 *)((u8 *)(temp_19) + 0x334)) = temp_2_5;
                        if (temp_2_5 >= *temp_16_6) {
                            func_003C3A10((*(void **)((u8 *)(temp_19) + 0x2DC)), 9, 0, 8);
                            var_5 = 0x1B;
                            goto block_188;
                        }
                    }
                    break;
                case 25:                            /* switch 2 */
                    temp_6_2 = (*(s32 *)((u8 *)(temp_19) + 0x334)) * 0x10;
                    func_L01_004482A0(arg0 + 0x18, temp_19 + 0x2E8, (void *) temp_6_2, (*(f32 *)((u8 *)((*(((*(s32 *)((u8 *)(temp_19) + 0x314)) * 4) + &D_L10_0021D1C0) + temp_6_2)) + 0x18)), 0x3B51B718, 0x3C6BEDFB, 0x3DA3D70B);
                    (*(s32 *)((u8 *)(temp_19) + 0xA8)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0xA8)) | 4);
                    temp_16_7 = arg0 + 0x10;
                    if (func_L01_0045BDE8(arg0, (*(s32 *)((u8 *)(temp_19) + 0x314))) != 0) {
                        temp_17_5 = *(((*(s32 *)((u8 *)(temp_19) + 0x314)) * 4) + &D_L10_0021D1C0);
                        temp_f20 = func_0038CF38(temp_16_7, temp_17_5 + 0x10);
                        if (func_0038CF38(temp_16_7, temp_17_5 + (*temp_17_5 * 0x10)) < temp_f20) {
                            func_L01_0045C150(arg0, *(((*(s32 *)((u8 *)(temp_19) + 0x314)) * 4) + &D_L10_0021D1C0), 0, *temp_17_5 - 1);
                        } else {
                            func_L01_0045C150(arg0, *(((*(s32 *)((u8 *)(temp_19) + 0x314)) * 4) + &D_L10_0021D1C0), *temp_17_5 - 1, 0);
                        }
                    }
                    if (((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 0x5BU) && (func_L10_003B9D28(arg0) != 0)) {
                        var_5_3 = 0x1A;
                        goto block_108;
                    }
                    break;
                case 26:                            /* switch 2 */
                    (*(s32 *)((u8 *)(temp_19) + 0xA8)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0xA8)) | 4);
                    temp_17_6 = *(((*(s32 *)((u8 *)(temp_19) + 0x314)) * 4) + &D_L10_0021D1C0);
                    temp_16_8 = arg0 + 0x10;
                    var_21_2 = temp_16_8;
                    func_L01_00448340(temp_16_8, temp_17_6 + (((*(s32 *)((u8 *)(temp_19) + 0x334)) * 0x10) + 0x10), temp_19 + 0x2E8, 0x3B51B718, 0x3C6BEDFB, 0x3DA3D70B);
                    if (func_0038CF00(temp_16_8, temp_17_6 + (((*(s32 *)((u8 *)(temp_19) + 0x334)) * 0x10) + 0x10)) < 0.25f) {
                        temp_2_6 = (*(s32 *)((u8 *)(temp_19) + 0x334)) + 1;
                        (*(s32 *)((u8 *)(temp_19) + 0x334)) = temp_2_6;
                        temp_5 = *temp_17_6;
                        if (temp_2_6 >= temp_5) {
                            (*(s32 *)((u8 *)(temp_19) + 0x334)) = (s32) (temp_5 - 1);
                        }
                    }
                    if (func_L01_0044E1B8((*(void **)((u8 *)(temp_19) + 0x2DC)), 0x3F000000) != 0) {
                        temp_4_5 = (*(void **)((u8 *)(temp_19) + 0x2DC));
                        if ((*(u8 *)((u8 *)(temp_4_5) + 0x42)) == 0xA) {
                            func_003C2F58(temp_4_5, 0, &sp90);
                            if (fabsf((*(f32 *)((u8 *)(arg0) + 0x18)) - (*(f32 *)((u8 *)(temp_19) + 0x228))) < 2.0f) {
                                goto block_115;
                            }
                            goto block_116;
                            goto block_117;
                        }
                    }
                    goto block_118;
                case 3:                             /* switch 2 */
                    if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                        (*(s32 *)((u8 *)(temp_19) + 0x338)) = 1;
                        if ((*(s32 *)((u8 *)(temp_19) + 0x314)) != -1) {
                            func_L01_004450F0(arg0, 0x18, -1);
                            func_L10_003B9078(arg0, 0xD, 0, 5);
                            (*(s32 *)((u8 *)(temp_19) + 0x334)) = 1;
                        }
                    }
                    break;
                case 8:                             /* switch 2 */
                    if (func_L01_0044E1B8(arg0, 0x41000000) != 0) {
                        (*(s32 *)((u8 *)(temp_19) + 0x338)) = 0;
                        func_L01_004450F0(arg0, 0x1B, -1);
                        func_L10_003B9078(arg0, 9, 0, 8);
                    }
                    temp_16_9 = arg0 + 0x10;
                    if (func_L01_004395E0(arg0) > 4.0f) {
                        temp_f0 = func_003C3D30(temp_16_9, 0, 0, 0x3F000000);
                        sp90 = (u128_t)((*(f32 *)((u8 *)(arg0) + 0x10)));
                        unksp98 = temp_f0;
                        func_L01_00448340(temp_16_9, &sp90, temp_19 + 0x2E8, 0x3BEBEDFB, 0x3C2A64C4, 0x3E8F5C2A);
                    }
                    break;
                case 13:                            /* switch 2 */
                    func_L01_00448728((*(void **)((u8 *)(temp_19) + 0x2DC)) + 0xF8, temp_19 + 0x330, 0, (*(f32 *)((u8 *)(arg0) + 0xF8)), 0x3B494FE9, 0x3A5B9CFF, 0x3E1D466E);
                    if (func_L01_004561B8(arg0) != 0) {
                        (*(s32 *)((u8 *)(temp_19) + 0x2D8)) = 0;
                    }
                    temp_17_7 = arg0 + 0x10;
                    temp_16_10 = *(((*(s32 *)((u8 *)(temp_19) + 0x314)) * 4) + &D_L10_0021D1C0) + 0x10;
                    func_L01_0045A748(arg0, temp_16_10);
                    if (func_0038CF38(temp_17_7, temp_16_10) < 0.5f) {
                        func_L10_003B9078(arg0, 9, 0, 8);
                        func_L01_004450F0(arg0, 0x1B, 2);
                    }
                    if ((func_0038CF38(temp_17_7, (*(s32 *)((u8 *)(temp_19) + 0x230)) + 0x10) < 10.0f) && ((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 5U)) {
                        goto block_158;
                    }
                    break;
                case 15:                            /* switch 2 */
                    if (func_L01_004561B8(arg0) != 0) {
                        (*(s32 *)((u8 *)(temp_19) + 0x2D8)) = 0;
                    }
                    temp_17_8 = arg0 + 0x10;
                    temp_16_11 = (*(void **)((u8 *)(temp_19) + 0x2DC)) + 0xF8;
                    func_L01_00448728(temp_16_11, temp_19 + 0x330, 0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))), 0x3B494FE9, 0x3A5B9CFF, 0x3E1D466E);
                    temp_16_12 = *(((*(s32 *)((u8 *)(temp_19) + 0x314)) * 4) + &D_L10_0021D1C0) + 0x10;
                    func_L01_0045A748(arg0, temp_16_12);
                    if (func_0038CF38(temp_17_8, temp_16_12) < 0.5f) {
                        func_L10_003B9078(arg0, 9, 0, 8);
                        func_L01_004450F0(arg0, 0x1B, 2);
                    }
                    if (func_0038CF38(temp_17_8, (*(s32 *)((u8 *)(temp_19) + 0x230)) + 0x10) < 8.0f) {
                        if ((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 5U) {
                            func_L10_003B9078(arg0, 9, 0, 8);
                            func_L01_004450F0(arg0, 0x1B, 2);
                        }
                    }
                    if (((*(u16 *)((u8 *)(arg0) + 0x96)) >= 0x5BU) && (func_L10_003B9D28(arg0) != 0)) {
                        func_003C3A10((*(void **)((u8 *)(temp_19) + 0x2DC)), 0xA, 0, 5);
                        var_5 = 0x12;
                        goto block_188;
                    }
                    break;
                case 18:                            /* switch 2 */
                    temp_16_13 = (*(void **)((u8 *)(temp_19) + 0x2DC)) + 0xF8;
                    func_L01_00448728(temp_16_13, temp_19 + 0x330, 0, func_0038D160(temp_4_2, (*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))), 0x3B494FE9, 0x3A5B9CFF, 0x3E1D466E);
                    if ((*(u8 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x2DC))) + 0x60)) & 2) {
                        func_L01_004450F0(arg0, 0xF, 2);
                        func_003C3A10((*(void **)((u8 *)(temp_19) + 0x2DC)), 9, 0, 5);
                    }
                    temp_17_9 = arg0 + 0x10;
                    var_21 = temp_17_9;
                    temp_16_14 = *(((*(s32 *)((u8 *)(temp_19) + 0x314)) * 4) + &D_L10_0021D1C0) + 0x10;
                    func_L01_0045A748(arg0, temp_16_14);
                    if ((func_0038CF38(temp_17_9, temp_16_14) < 0.5f) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 9)) {
                        func_003C3A10(arg0, 9, 0, 8);
                    }
                    if (func_L01_0044E1B8((*(void **)((u8 *)(temp_19) + 0x2DC)), 0x3F000000) != 0) {
                        temp_4_6 = (*(void **)((u8 *)(temp_19) + 0x2DC));
                        if ((*(u8 *)((u8 *)(temp_4_6) + 0x42)) == 0xA) {
                            func_003C2F58(temp_4_6, 0, &sp90);
                            if (fabsf((*(f32 *)((u8 *)(arg0) + 0x18)) - (*(f32 *)((u8 *)(temp_19) + 0x228))) < 2.0f) {
                                var_16 = (*(void **)((u8 *)(temp_19) + 0x2DC)) + 0xC0;
                                var_f0_2 = func_0038CF38(var_21, (*(s32 *)((u8 *)(temp_19) + 0x230)) + 0x10);
                                goto block_175;
                            }
                            temp_16_15 = (*(void **)((u8 *)(temp_19) + 0x2DC)) + 0xC0;
                            var_f0 = func_0038CF38(var_21, (*(s32 *)((u8 *)(temp_19) + 0x230)) + 0x10);
                            var_5_2 = temp_16_15;
                            goto block_177;
                            goto block_178;
                        }
                    }
                    break;
                case 21:                            /* switch 2 */
                    func_L01_00448728((*(void **)((u8 *)(temp_19) + 0x2DC)) + 0xF8, temp_19 + 0x330, 0, (*(f32 *)((u8 *)(arg0) + 0xF8)), 0x3B494FE9, 0x3A5B9CFF, 0x3E1D466E);
                    if (func_L01_004561B8(arg0) != 0) {
                        (*(s32 *)((u8 *)(temp_19) + 0x2D8)) = 0;
                    }
                    func_0038CF38(arg0 + 0x10, (*(s32 *)((u8 *)(temp_19) + 0x230)) + 0x10);
                    if (func_L01_0045BDE8(arg0, (*(s32 *)((u8 *)(temp_19) + 0x314))) != 0) {
                        goto block_158;
                    }
                    break;
                case 22:                            /* switch 2 */
                    if (func_L01_004561B8(arg0) != 0) {
                        (*(s32 *)((u8 *)(temp_19) + 0x2D8)) = 0;
                    }
                    temp_16_16 = (*(void **)((u8 *)(temp_19) + 0x2DC)) + 0xF8;
                    func_L01_00448728(temp_16_16, temp_19 + 0x330, 0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))), 0x3B494FE9, 0x3A5B9CFF, 0x3E1D466E);
                    if (func_L01_0045BDE8(arg0, (*(s32 *)((u8 *)(temp_19) + 0x314))) != 0) {
                        func_L10_003B9078(arg0, 9, 0, 8);
                        func_L01_004450F0(arg0, 0x1B, 2);
                    }
                    if (((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 0x5BU) && (func_L10_003B9D28(arg0) != 0)) {
                        func_003C3A10((*(void **)((u8 *)(temp_19) + 0x2DC)), 0xA, 0, 5);
                        var_5 = 0x17;
                        goto block_188;
                    }
                    break;
                case 23:                            /* switch 2 */
                    temp_16_17 = (*(void **)((u8 *)(temp_19) + 0x2DC)) + 0xF8;
                    func_L01_00448728(temp_16_17, temp_19 + 0x330, 0, func_0038D160(temp_4_2, (*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))), 0x3B494FE9, 0x3A5B9CFF, 0x3E1D466E);
                    if ((*(u8 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x2DC))) + 0x60)) & 2) {
                        func_L01_004450F0(arg0, 0x16, 2);
                        func_003C3A10((*(void **)((u8 *)(temp_19) + 0x2DC)), 9, 0, 5);
                    }
                    if ((func_L01_0045BDE8(arg0, (*(s32 *)((u8 *)(temp_19) + 0x314))) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 9)) {
                        func_003C3A10(arg0, 9, 0, 8);
                    }
                    if (func_L01_0044E1B8((*(void **)((u8 *)(temp_19) + 0x2DC)), 0x3F000000) != 0) {
                        temp_4_7 = (*(void **)((u8 *)(temp_19) + 0x2DC));
                        if ((*(u8 *)((u8 *)(temp_4_7) + 0x42)) == 0xA) {
                            func_003C2F58(temp_4_7, 0, &sp90);
                            if (fabsf((*(f32 *)((u8 *)(arg0) + 0x18)) - (*(f32 *)((u8 *)(temp_19) + 0x228))) < 2.0f) {
                                goto block_174;
                            }
                            goto block_176;
                            goto block_178;
                        }
                    }
                    break;
                case 27:                            /* switch 2 */
                    temp_16_18 = (*(void **)((u8 *)(temp_19) + 0x2DC)) + 0xF8;
                    func_L01_00448728(temp_16_18, temp_19 + 0x330, 0, func_0038D160(temp_4_2, (*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))), 0x3BA4B5BF, 0x3BA4B5BF, 0x3E80ADFD);
                    if (((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 0x5BU) && (func_L10_003B9D28(arg0) != 0)) {
                        if ((*(u8 *)((u8 *)(arg0) + 0x42)) == 0xD) {
                            func_003C3A10((*(void **)((u8 *)(temp_19) + 0x2DC)), 0xA, 0, 8);
                        } else {
block_186:
                            func_L10_003B9078(arg0, 0xA, 0, 8);
                        }
                        var_5 = 0xA;
                        goto block_188;
                    }
                    break;
                case 9:                             /* switch 2 */
                    func_L10_003B9078(arg0, 6, 0, 8);
                    func_L01_00448728((*(void **)((u8 *)(temp_19) + 0x2DC)) + 0xF8, temp_19 + 0x330, 0, (*(f32 *)((u8 *)(arg0) + 0xF8)), 0x3B494FE9, 0x3A5B9CFF, 0x3E1D466E);
                    func_L01_0045A748(arg0, temp_19 + 0x220);
                    if (((func_0038CF38(arg0 + 0x10, (*(s32 *)((u8 *)(temp_19) + 0x230)) + 0x10) < 14.0f) || (fabsf((*(f32 *)((u8 *)(arg0) + 0x18)) - (*(f32 *)((u8 *)(temp_19) + 0x228))) > 3.0f)) && (func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xF8)), func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14)))) < 0.5235988f)) {
                        goto block_186;
                    }
                    break;
                case 10:                            /* switch 2 */
                    temp_16_19 = (*(void **)((u8 *)(temp_19) + 0x2DC)) + 0xF8;
                    func_L01_00448728(temp_16_19, temp_19 + 0x330, 0, func_0038D160(temp_4_2, (*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))), 0x3BA4B5BF, 0x3BA4B5BF, 0x3E80ADFD);
                    if (func_L01_0044E1B8((*(void **)((u8 *)(temp_19) + 0x2DC)), 0x40A00000) != 0) {
                        func_003C2F58((*(void **)((u8 *)(temp_19) + 0x2DC)), 0, &sp90);
                        temp_2_7 = arg0 + 0x10;
                        if (fabsf((*(f32 *)((u8 *)(arg0) + 0x18)) - (*(f32 *)((u8 *)(temp_19) + 0x228))) < 2.0f) {
                            temp_16_20 = (*(void **)((u8 *)(temp_19) + 0x2DC)) + 0xC0;
                            var_21_3 = temp_2_7;
                            func_0038CF68(&spA0, temp_16_20, (func_0038CF38(temp_2_7, (*(s32 *)((u8 *)(temp_19) + 0x230)) + 0x10) / 1.3f) * 0.020000001f);
                        } else {
                            temp_17_10 = arg0 + 0x10;
                            temp_16_21 = (*(void **)((u8 *)(temp_19) + 0x2DC)) + 0xC0;
                            var_21_3 = temp_17_10;
                            func_0038CF68(&spA0, temp_16_21, (func_0038CF38(temp_17_10, (*(s32 *)((u8 *)(temp_19) + 0x230)) + 0x10) / 1.3f) * 0.020000001f);
                        }
                        spA8 = func_L01_00447878(&sp90, temp_19 + 0x220, 0, func_0038CF38(var_21_3, (*(s32 *)((u8 *)(temp_19) + 0x230)) + 0x10) * 0.020000001f, 0xBB902DE0);
                        func_L05_0032B880(&sp90, &spA0, arg0, 0x40A00000);
                    }
                    temp_4_8 = (*(void **)((u8 *)(temp_19) + 0x2DC));
                    if ((*(u8 *)((u8 *)(temp_4_8) + 0x60)) & 2) {
                        if ((*(s32 *)((u8 *)(temp_19) + 0x32C)) == 0) {
                            func_L10_003B9078(arg0, 9, 0, 8);
                            func_L01_004450F0(arg0, 0x1B, 2);
                        } else {
                            func_003C3A10(temp_4_8, 9, 0, 8);
                            func_L01_004450F0(arg0, 0x1B, 2);
                        }
                        if ((*(s32 *)((u8 *)(temp_19) + 0x314)) != -1) {
                            temp_16_22 = arg0 + 0x10;
                            func_L01_004450F0(arg0, 0x15, -1);
                            func_L10_003B9078(arg0, 6, 0, 8);
                            temp_17_11 = *(((*(s32 *)((u8 *)(temp_19) + 0x314)) * 4) + &D_L10_0021D1C0);
                            temp_f20_2 = func_0038CF38(temp_16_22, temp_17_11 + 0x10);
                            if (func_0038CF38(temp_16_22, temp_17_11 + (*temp_17_11 * 0x10)) < temp_f20_2) {
                                func_L01_0045C150(arg0, *(((*(s32 *)((u8 *)(temp_19) + 0x314)) * 4) + &D_L10_0021D1C0), 0, *temp_17_11 - 1);
                            } else {
                                func_L01_0045C150(arg0, *(((*(s32 *)((u8 *)(temp_19) + 0x314)) * 4) + &D_L10_0021D1C0), *temp_17_11 - 1, 0);
                            }
                            if ((*(s32 *)((u8 *)(temp_19) + 0x324)) != 0) {
                                func_003C3A10((*(void **)((u8 *)(temp_19) + 0x2DC)), 9, 0, 8);
                                func_L01_004450F0(arg0, 0x16, -1);
                            }
                            if ((*(s32 *)((u8 *)(temp_19) + 0x32C)) != 0) {
                                if ((*(s32 *)((u8 *)(temp_19) + 0x338)) == 0) {
                                    func_L01_004450F0(arg0, 3, -1);
                                    var_5_4 = 0xC;
                                } else {
                                    func_L01_004450F0(arg0, 0x18, -1);
                                    var_5_4 = 0xD;
                                }
                                func_L10_003B9078(arg0, var_5_4, 0, 5);
                                (*(s32 *)((u8 *)(temp_19) + 0x334)) = 1;
                            }
                        }
                    }
                    break;
                case 30:                            /* switch 2 */
                    if (func_L01_004561B8(arg0) != 0) {
                        (*(f32 *)((u8 *)(temp_19) + 0x1BC)) = 2.0f;
                        (*(f32 *)((u8 *)(temp_19) + 0x1B8)) = 2.0f;
                    }
                    temp_f1 = (*(f32 *)((u8 *)(temp_19) + 0x2F8));
                    if (temp_f1 < 1.0f) {
                        temp_f0_2 = temp_f1 + (*(f32 *)((u8 *)(saved_reg_gp) + 0x1EAC));
                        (*(f32 *)((u8 *)(temp_19) + 0x2F8)) = temp_f0_2;
                        if (temp_f0_2 > 1.0f) {
                            (*(f32 *)((u8 *)(temp_19) + 0x2F8)) = 1.0f;
                        }
                        (*(f32 *)((u8 *)(arg0) + 0x2C)) = (f32) ((*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x24))) + 0x24)) * (*(f32 *)((u8 *)(temp_19) + 0x2F8)));
                        temp_3_4 = (*(void **)((u8 *)(temp_19) + 0x2DC));
                        (*(f32 *)((u8 *)(temp_3_4) + 0x2C)) = (f32) ((*(f32 *)((u8 *)((*(void **)((u8 *)(temp_3_4) + 0x24))) + 0x24)) * (*(f32 *)((u8 *)(temp_19) + 0x2F8)));
                    }
                    temp_2_8 = (*(void **)((u8 *)(temp_19) + 0x2F4));
                    if (temp_2_8 != ((void *)0)) {
                        (*(s32 *)((u8 *)(temp_2_8) + 0x98)) = 0;
                    }
                    if (func_L01_0045C2A0(arg0, (*(f32 *)((u8 *)(saved_reg_gp) + 0x1EB4)), (*(f32 *)((u8 *)(saved_reg_gp) + 0x1EB8)), (*(f32 *)((u8 *)(saved_reg_gp) + 0x1EBC))) != 0) {
                        (*(f32 *)((u8 *)(arg0) + 0x48)) = 1.0f;
                        (*(f32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x2DC))) + 0x48)) = 1.0f;
                        func_L01_0045A9F0(arg0);
                        (*(f32 *)((u8 *)(temp_19) + 0x1BC)) = 0.75f;
                        (*(f32 *)((u8 *)(temp_19) + 0x1B8)) = 0.2f;
                        if ((*(s32 *)((u8 *)(temp_19) + 0x2F0)) != 0) {
                            func_L01_004450F0(arg0, 0x1F, 5);
                            var_5_5 = 4;
                        } else {
                            func_L01_004450F0(arg0, 1, 0);
                            var_5_5 = 0;
                        }
                        func_L10_003B9078(arg0, var_5_5, 0, 8);
                    } else {
                        temp_2_9 = (*(void **)((u8 *)(temp_19) + 0x2DC));
                        if (temp_2_9 != ((void *)0)) {
                            (*(f32 *)((u8 *)(temp_2_9) + 0x48)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x48));
                        }
                    }
                    temp_4_9 = (*(void **)((u8 *)(temp_19) + 0x2F4));
                    if (temp_4_9 != ((void *)0)) {
                        (*(s32 *)((u8 *)(temp_4_9) + 0x98)) = (s32) (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_4_9) + 0x24))) + 0x10));
                    }
                    break;
                case 31:                            /* switch 2 */
                    var_2 = arg0 + 0x10;
                    if (func_L01_004561B8(arg0) != 0) {
                        func_L01_0045BD78(arg0, 0x3BD1B718, 0x3D75C290, 0x3C24B5BF, 0x3E80ADFD);
                        var_2 = arg0 + 0x10;
                    }
                    temp_5_2 = temp_19 + 0x300;
                    if (func_0038CF38(var_2, temp_5_2) > 0.5f) {
                        func_L01_0045A748(arg0, temp_5_2);
                    } else {
                        func_L01_0045A898(arg0, temp_5_2, (*(f32 *)((u8 *)(temp_19) + 0x2FC)));
                    }
                    if ((*(s16 *)((u8 *)(temp_19) + 0x234)) == 1) {
                        func_L01_0045BD78(arg0, 0x3BD1B718, 0x3DF5C290, 0x3C24B5BF, 0x3E80ADFD);
                        func_L01_004450F0(arg0, 2, 1);
                        func_L10_003B9078(arg0, 0, 0, 8);
                        (*(s32 *)((u8 *)(temp_19) + 0x2D0)) = (s32) ((s32) ((func_00382498(0x244, 0x258) * 5) + 2) / 6);
                    } else if (func_0038CF38(var_2, temp_5_2) <= (*(f32 *)((u8 *)(temp_19) + 0xA4))) {
                        if ((*(f32 *)((u8 *)(temp_19) + 0xA0)) < fabsf(func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xF8)), (*(f32 *)((u8 *)(temp_19) + 0x2FC))))) {
                            func_L01_0045BD10(arg0, (*(f32 *)((u8 *)(temp_19) + 0x2FC)));
                        } else {
                            func_L01_0045BD78(arg0, 0x3BD1B718, 0x3DF5C290, 0x3C24B5BF, 0x3E80ADFD);
                            func_L01_004450F0(arg0, 1, 0);
                            func_L10_003B9078(arg0, 0, 0, 8);
                        }
                    }
                    break;
                }
            }
            func_L10_003B8F50(arg0);
            break;
        case 1:                                     /* switch 1 */
            if ((*(s16 *)((u8 *)(temp_19) + 0x234)) != 1) {
                if ((*(s32 *)((u8 *)(temp_19) + 0x2D0)) == 0) {
                    func_L01_004450F0(arg0, 1, 0);
                }
            } else {
block_41:
                func_L01_004450F0(arg0, 9, 2);
            }
            goto block_44;
        case 2:                                     /* switch 1 */
            if ((*(s16 *)((u8 *)(temp_19) + 0x234)) != 1) {
                temp_3_5 = (*(u8 *)((u8 *)(arg0) + 0x20));
                if ((temp_3_5 != 0x10) && (temp_3_5 != 0xE)) {
block_42:
                    func_L10_003B9078(arg0, 0, 0, 8);
                    func_L01_004450F0(arg0, 2, 1);
                    var_4 = 0x244;
                    goto block_43;
                }
            }
            goto block_44;
        case 3:                                     /* switch 1 */
            temp_2_10 = func_L01_00454370(arg0, temp_19 + 0x160);
            if ((*(f32 *)((u8 *)(temp_19) + 0x30)) <= 0.0f) {
                func_L10_003B8ED0(arg0, 0);
                func_003A52A0(4, 0, arg0);
                func_L01_003303B8(arg0 + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 0x3F800000, 0, 0, 0x40000000, 1, 1, 1, 0, 1, 0, 0x01010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                func_003C2880(arg0);
            } else {
                if (temp_2_10 & 2) {
                    if ((*(s16 *)((u8 *)(temp_19) + 0x234)) == 1) {
                        func_L10_003B9078(arg0, 6, 0, 8);
                        goto block_41;
                    }
                    goto block_42;
                }
                goto block_44;
            }
            break;
        }
    }
}


#endif
