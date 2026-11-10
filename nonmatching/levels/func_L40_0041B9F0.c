/* func_L40_0041B9F0: Opus handoff (prep by Sonnet worker w6, 2026-11-08)
   Size: 6700 bytes, places: 10 levels (40..45, 50..53), file: src/levels/shared/L40_0041B820.c
   flags: the file's own line (-O2 -G8 -fopt-stack -mno-check-zero-division, NO @ps2as); retail has 92 mtc1 (inline float constants) and 18 lq/sq:
     a file with an estimated flag line and no C yet: try --as ps2as first (Ps2EeAs inline constants), then check with --all-modes.
   Step 0: one function; 1 jump table (jtbl_003A76F0), 9 cases. a multiplayer-level object update using the anti-tamper protected values (9 reads with stride 0xFF into D_L40_003BFE20), angle_add/angle_sub x15, atan2, vec_set_length.
   rac2 twin: none: best opcode 0.177 (func_L01_003CC930); rac3 siblings <= 0.18; callee func_L40_0041B820 is the file neighbour.
   Mapping / identical / changed: no twin to map. Hot callees have names in config/names.tsv (moby_set_state, moby_anim_blend,
     vec_set_length, angle_add/sub, atan2, rand_*), so the m2c is readable as moby-AI code.
   Anti-tamper: this function reads protected values (handle byte, pool D_L40_003BFE20 stride 0xFF); use the Dec/DecEq
     shapes proven in func_L39_0065D0A0 (landing/queue) instead of the m2c expansion.
   VU0 note: 32 COP2 instructions: with the 2026-11-06 rule (no VU0 inline asm in matched C) this cannot be a MATCH unless a
     TI-mode/scalar-C form produces them; keep as a near miss.
   Draft: no compiling draft (m2c converted (841 lines) but not compiling: the `s3232 sp68` declaration (a mangled s128), `sp`/`unksp18` pseudo-variables for stack bytes/floats, and 9 inlined protected-value reads (see below).). The fenced block is the mechanically converted m2c (M2C_FIELD ->
     byte-offset casts, M2C_UNK -> s32, s128 -> u128_t TI typedef). Not measured.
   Left for Opus: (1) type the object (moby: pos +0x10, state +0x20 u8, class ptr +0x24, flags +0x34 u16; the +0x68 pointer is the
     per-moby vars block); (2) turn float-hex arguments back into f32; (3) get it to compile, measure, then register/scheduling work.
   Tool note: tools in out/tools-w6/ (m2c2.py: restores the `.word`-hidden lq/sq and appends the jump tables so m2c runs at all;
     conv.py: M2C_FIELD -> casts; iter.py: compile loop dropping conflicting prototypes).
*/
#if 0 /* does not compile yet: m2c2 draft mechanically converted (tools in worker w6 scratch), prototypes unverified */
typedef int u128_t __attribute__((mode(TI)));
f32 func_0038CE68(void *, u128_t *);                  /* extern */
f32 func_0038CED8(u128_t *);                          /* extern */
f32 func_0038CF00(void *, void *);                  /* extern */
f32 func_0038CF38(void *, void *);                  /* extern */
s32 func_0038CF68(u128_t *, f32 *, f32);          /* extern */
s32 func_0038D028(u128_t *, u128_t *, u128_t *);      /* extern */
f32 func_0038D098(f32);                             /* extern */
f32 func_0038D0B0(f32);                             /* extern */
f32 func_0038D160(f32, f32);                        /* extern */
s32 func_0038D328(u128_t *, u128_t *);              /* extern */
f32 func_0038DAB8(f32, f32, f32);                   /* extern */
f32 func_0038DB00(f32, f32);                        /* extern */
f32 func_0038DBA0(f32, f32);                        /* extern */
f32 func_003C3D30(void *, s32, s32, s32); /* extern */
s32 func_003D3CB0(u128_t *, u128_t *, s32, void *, s32); /* extern */
s32 func_L01_0040E408(u128_t *, u128_t *, f32);     /* extern */
s32 func_L01_004450F0(void *, s32, s32); /* extern */
s32 func_L01_004482A0(f32 *, void *, s32, s32, s32, s32); /* extern */
s32 func_L01_00448690(void *, s32, f32, s32); /* extern */
s32 func_L01_004606E8(s32, s32, s32, s32); /* extern */
s32 func_L39_005601F8(void *);                      /* extern */
s32 func_L39_0062B4A8(void *, s32, s32, s32, s32); /* extern */
s32 func_L39_0066C828(void *, s32, s32); /* extern */
s32 func_L40_0041B6B8(void *, s32, s32, s32, s32, s32, s32, s32 *, f32); /* extern */
s32 func_L40_0041B770(void *, s32);             /* extern */
s32 func_L40_0041B820(void *, s32, void *, s32, s32, s32, s32, s32 *); /* extern */
extern void *D_L40_00249330;
extern u128_t D_L40_0025B9A0;
extern s32 D_L40_003BFE20;

void func_L40_0041B9F0(void *arg0, void *arg2, s32 arg3, s32 arg4, s32 *arg7) {
    s32 sp0;                                        /* compiler-managed */
    s32 sp4;                                        /* compiler-managed */
    f32 sp8;
    u128_t sp10;                                      /* compiler-managed */
    u128_t sp20;
    u128_t sp40;                                      /* compiler-managed */
    u128_t sp50;
    f32 sp60;
    f32 sp64;
    s3232 sp68;
    u128_t sp70;
    u128_t sp80;                                      /* compiler-managed */
    u128_t sp90;
    f32 sp98;
    f32 spA0;
    f32 spA4;
    s32 *var_11;
    s32 var_5;
    s32 var_5_2;
    s32 var_5_3;
    s32 var_f12;
    s32 var_f12_2;
    f32 temp_f0;
    f32 temp_f0_10;
    f32 temp_f0_11;
    f32 temp_f0_12;
    f32 temp_f0_13;
    f32 temp_f0_14;
    f32 temp_f0_15;
    f32 temp_f0_16;
    f32 temp_f0_17;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f0_9;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f1;
    f32 temp_f1_10;
    f32 temp_f1_11;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f1_6;
    f32 temp_f1_7;
    f32 temp_f1_8;
    f32 temp_f1_9;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f25;
    f32 temp_f25_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    f32 var_f0_5;
    f32 var_f0_6;
    u128_t temp_3_4;
    u128_t var_2_3;
    s32 temp_16;
    s32 temp_2;
    s32 temp_2_10;
    s32 temp_2_11;
    s32 temp_2_13;
    s32 temp_2_15;
    s32 temp_2_17;
    s32 temp_2_2;
    s32 temp_2_4;
    s32 temp_2_6;
    s32 temp_2_8;
    s32 var_10_2;
    s32 var_10_3;
    s32 var_17;
    s32 var_21;
    s32 var_2;
    s32 var_2_2;
    s32 var_3;
    s32 var_3_2;
    s32 var_3_3;
    s32 var_3_4;
    s32 var_3_5;
    s32 var_3_6;
    s32 var_3_7;
    s32 var_3_8;
    s32 var_3_9;
    s32 var_7;
    s32 var_8;
    s32 var_fp;
    u16 temp_2_14;
    u8 temp_2_5;
    u8 temp_2_7;
    u8 temp_2_9;
    u8 temp_3;
    u8 temp_3_10;
    u8 temp_3_11;
    u8 temp_3_2;
    u8 temp_3_3;
    u8 temp_3_5;
    u8 temp_3_7;
    u8 temp_3_8;
    u8 temp_3_9;
    void **var_16;
    void *temp_18;
    void *temp_19;
    void *temp_23;
    void *temp_2_12;
    void *temp_2_16;
    void *temp_2_3;
    void *temp_3_6;
    void *temp_5;
    void *temp_8;
    void *temp_9;
    void *temp_9_2;
    void *temp_9_3;
    void *temp_9_4;
    void *temp_9_5;
    void *temp_9_6;
    void *temp_9_7;
    void *var_10;
    void *var_18;
    void *var_6;

    var_6 = arg2;
    var_7 = arg3;
    var_8 = arg4;
    var_11 = arg7;
    temp_19 = (*(void **)((u8 *)(arg0) + 0x68));
    if (temp_19 != ((void *)0)) {
        temp_2 = (*(s32 *)((u8 *)(temp_19) + 0x50));
        var_18 = ((void *)0);
        if (temp_2 >= 0) {
            var_18 = (&D_L40_00249330)[temp_2];
        }
        var_10 = var_18 + 0x19E4;
        if (var_18 != ((void *)0)) {
            temp_9 = var_10;
            var_3 = 0;
            if ((*(u8 *)((u8 *)(var_18) + 0x19E4)) != 0) {
                temp_3 = (*(u8 *)((u8 *)(var_18) + 0x19E4));
                var_11 = &D_L40_003BFE20;
                var_8 = temp_3 + 1;
                var_7 = (temp_9 - temp_3) & 7;
                *sp = (u8) *(var_8 + ((var_7 & 7) * 0xFF) + &D_L40_003BFE20);
                var_6 = sp + 1;
                temp_2_2 = sp0 ^ (s32) var_10;
                var_3 = sp4 ^ temp_2_2;
                sp0 = temp_2_2;
                sp4 = var_3;
            }
            if ((var_3 ^ 0x37) == 0) {
                temp_2_3 = (*(void **)((u8 *)(var_18) + 0x2530));
                var_10 = ((void *)0);
                if (temp_2_3 != ((void *)0)) {
                    var_2 = 0 & 0xFF;
                    if ((*(u8 *)((u8 *)(temp_2_3) + 0x27B)) != 0) {
                        var_3_2 = 0;
                        if ((*(u8 *)((u8 *)(var_18) + 0x19E4)) != 0) {
                            temp_3_2 = (*(u8 *)((u8 *)(var_18) + 0x19E4));
                            var_11 = &D_L40_003BFE20;
                            var_8 = temp_3_2 + 1;
                            var_7 = (temp_9 - temp_3_2) & 7;
                            *sp = (u8) *(var_8 + ((var_7 & 7) * 0xFF) + &D_L40_003BFE20);
                            var_6 = sp + 1;
                            temp_2_4 = sp0 ^ (s32) temp_9;
                            var_3_2 = sp4 ^ temp_2_4;
                            sp0 = temp_2_4;
                            sp4 = var_3_2;
                        }
                        if ((var_3_2 ^ 0x31) == 0) {
                            var_10 = (void *)1;
                        }
                        goto block_18;
                    }
                } else {
block_18:
                    var_2 = (s32) var_10 & 0xFF;
                }
                if (var_2 != 0) {
                    goto block_20;
                }
                if ((var_18 != ((void *)0)) && ((*(u8 *)((u8 *)(var_18) + 0x1A14)) != 0) && ((u32) ((*(u8 *)((u8 *)(arg0) + 0x20)) - 3) < 2U) && (0 /* M2C_ERROR Read from unset register $f2 */ != (s32)(((*(f32 *)((u8 *)(temp_19) + 0x58)) * 10.0f)))) {
                    func_L40_0041B6B8(arg0, 0, 0, 0xFA, var_8, (s32) temp_9, (s32) var_10, var_11, (*(f32 *)((u8 *)(temp_19) + 0)));
                }
                goto block_26;
            }
block_20:
            func_L40_0041B820(arg0, 1, var_6, var_7, var_8, (s32) temp_9, (s32) var_10, var_11);
        } else {
block_26:
            (*(f32 *)((u8 *)(temp_19) + 0x58)) = (f32) (*(f32 *)((u8 *)(temp_19) + 0));
            if ((var_18 == ((void *)0)) && ((*(s32 *)((u8 *)(temp_19) + 0x50)) >= 0)) {
                (*(s32 *)((u8 *)(temp_19) + 0x50)) = -1;
                if ((u32) ((*(u8 *)((u8 *)(arg0) + 0x20)) - 3) < 2U) {
                    func_L01_004450F0(arg0, 1, -1);
                }
            }
            temp_3_3 = (*(u8 *)((u8 *)(arg0) + 0x20));
            switch (temp_3_3) {                     /* switch 1 */
            case 0:                                 /* switch 1 */
                func_L39_0066C828(arg0, -1, 1);
                temp_3_4 = (*(u128_t *)((u8 *)(arg0) + 0x10));
                sp10 = temp_3_4;
                sp0 = temp_3_4;
                unksp18 -= 0.5f;
                sp8 += 0.5f;
                if (func_003D3CB0(sp, &sp10, 0x12, arg0, 0) != 0) {
                    (*(u128_t *)((u8 *)(arg0) + 0x10)) = (u128_t) D_L40_0025B9A0;
                    (*(f32 *)((u8 *)(arg0) + 0x18)) = (f32) ((*(f32 *)((u8 *)(arg0) + 0x18)) - 0.3f);
                }
                temp_f0 = (*(f32 *)((u8 *)(arg0) + 0x18));
                (*(f32 *)((u8 *)(temp_19) + 0x3C)) = temp_f0;
                (*(f32 *)((u8 *)(arg0) + 0x18)) = temp_f0;
                (*(s32 *)((u8 *)(temp_19) + 0xC)) = 0;
                (*(f32 *)((u8 *)(temp_19) + 4)) = (f32) (*(f32 *)((u8 *)(temp_19) + 0));
                func_L01_004450F0(arg0, 1, -1);
                (*(u128_t *)((u8 *)(temp_19) + 0x40)) = 0;
                (*(s32 *)((u8 *)(temp_19) + 0x50)) = -1;
                (*(s32 *)((u8 *)(temp_19) + 0x5C)) = -1;
                break;
            case 1:                                 /* switch 1 */
                temp_f1 = (*(f32 *)((u8 *)(arg0) + 0x18));
                if (temp_f1 < (*(f32 *)((u8 *)(temp_19) + 0x3C))) {
                    (*(f32 *)((u8 *)(arg0) + 0x18)) = (f32) (temp_f1 + 0.060000002f);
                }
                temp_f1_2 = (*(f32 *)((u8 *)(temp_19) + 0x3C));
                if (temp_f1_2 < (*(f32 *)((u8 *)(arg0) + 0x18))) {
                    (*(f32 *)((u8 *)(arg0) + 0x18)) = temp_f1_2;
                }
                var_fp = 0;
                var_2_2 = 0 * 4;
loop_40:
                temp_18 = *(var_2_2 + &D_L40_00249330);
                if ((temp_18 != ((void *)0)) && ((*(u8 *)((u8 *)(temp_18) + 0x1A14)) != 0)) {
                    temp_2_5 = (*(u8 *)((u8 *)(temp_18) + 0x19E4));
                    temp_9_2 = temp_18 + 0x19E4;
                    if (temp_2_5 == 0) {
                        var_3_3 = 0;
                    } else {
                        *sp = (u8) *(temp_2_5 + 1 + (((temp_9_2 - temp_2_5) & 7 & 7) * 0xFF) + &D_L40_003BFE20);
                        temp_2_6 = (s32) sp0 ^ (s32) temp_9_2;
                        var_3_3 = sp4 ^ temp_2_6;
                        sp0 = temp_2_6;
                        sp4 = var_3_3;
                    }
                    if (((var_3_3 ^ 0x31) != 0) && ((*(s32 *)((u8 *)(temp_18) + 0x254C)) == 0)) {
                        temp_2_7 = (*(u8 *)((u8 *)(temp_18) + 0x19E6));
                        temp_9_3 = temp_18 + 0x19E6;
                        if (temp_2_7 == 0) {
                            var_3_4 = 0;
                        } else {
                            *sp = (u8) *(temp_2_7 + 1 + (((temp_9_3 - temp_2_7) & 7 & 7) * 0xFF) + &D_L40_003BFE20);
                            temp_2_8 = sp0 ^ (s32) temp_9_3;
                            var_3_4 = sp4 ^ temp_2_8;
                            sp0 = temp_2_8;
                            sp4 = var_3_4;
                        }
                        if (((var_3_4 ^ 0x14) != 0) && ((*(s32 *)((u8 *)(temp_18) + 0x251C)) == 0) && (temp_23 = arg0 + 0x10, temp_f21 = func_0038DBA0((*(f32 *)((u8 *)(temp_18) + 0xB8)), func_0038D160((f32)((*(u128_t *)((u8 *)(arg0) + 0x10))) - (*(f32 *)((u8 *)(temp_18) + 0xA0)), (*(f32 *)((u8 *)(arg0) + 0x14)) - (*(f32 *)((u8 *)(temp_18) + 0xA4)))), temp_f20 = fabsf(((*(f32 *)((u8 *)(temp_18) + 0xA8)) - 0.3f) - (*(f32 *)((u8 *)(arg0) + 0x18))), temp_16 = func_L01_004606E8(0x80, 0xA, 0, (*(s32 *)((u8 *)(temp_18) + 0x2534))), (func_0038CF38(temp_23, temp_18 + 0xA0) < 3.0f)) && ((*(u8 *)((u8 *)(temp_18) + 0x46A)) == 0)) {
                            if ((temp_f21 < 1.9198622f) && (temp_f20 < 0.2f) && ((u32) (*(u32 *)((u8 *)(temp_19) + 0x14)) >= 0x4CU) && ((*(s32 *)((u8 *)(temp_18) + 0x478)) == 0xA) && ((*(s32 *)((u8 *)(temp_18) + 0x450)) != 0) && (temp_16 != 0) && (var_21 = 1, ((*(f32 *)((u8 *)(arg0) + 0x18)) == (*(f32 *)((u8 *)(temp_19) + 0x3C))))) {
                                (*(f32 *)((u8 *)(temp_19) + 0x54)) = 0.0f;
                                var_17 = 0;
                                var_16 = &D_L40_00249330;
loop_62:
                                temp_5 = *var_16;
                                if ((temp_5 != ((void *)0)) && (temp_5 != temp_18) && ((*(s32 *)((u8 *)(temp_5) + 0x2548)) != (*(s32 *)((u8 *)(temp_18) + 0x2548)))) {
                                    temp_2_9 = (*(u8 *)((u8 *)(temp_5) + 0x19E6));
                                    temp_8 = temp_5 + 0x19E6;
                                    if (temp_2_9 == 0) {
                                        var_3_5 = 0;
                                    } else {
                                        *sp = (u8) *(temp_2_9 + 1 + (((temp_8 - temp_2_9) & 7 & 7) * 0xFF) + &D_L40_003BFE20);
                                        temp_2_10 = sp0 ^ (s32) temp_8;
                                        var_3_5 = sp4 ^ temp_2_10;
                                        sp0 = temp_2_10;
                                        sp4 = var_3_5;
                                    }
                                    if ((var_3_5 ^ 0x14) != 0) {
                                        if (func_0038CF00(temp_23, temp_5 + 0xA0) < 4.5f) {
                                            var_21 = 0;
                                        } else {
                                            goto block_72;
                                        }
                                    } else {
                                        goto block_72;
                                    }
                                } else {
block_72:
                                    var_17 += 1;
                                    var_16 += 4;
                                    if (var_17 < 8) {
                                        goto loop_62;
                                    }
                                }
                                if (var_21 != 0) {
                                    if (func_L39_005601F8(arg0) == 0) {
                                        func_L40_0041B770(arg0, var_fp);
                                    }
                                } else {
                                    goto block_77;
                                }
                            } else {
                                goto block_77;
                            }
                        } else {
                            goto block_77;
                        }
                    } else {
                        goto block_77;
                    }
                } else {
block_77:
                    var_fp += 1;
                    var_2_2 = var_fp * 4;
                    if (var_fp < 8) {
                        goto loop_40;
                    }
                }
                if ((*(s32 *)((u8 *)(temp_19) + 0x50)) == -1) {
                    (*(u32 *)((u8 *)(temp_19) + 0x14)) = (u32) ((*(u32 *)((u8 *)(temp_19) + 0x14)) + 1);
                    return;
                }
                break;
            case 3:                                 /* switch 1 */
                if ((*(u8 *)((u8 *)(var_18) + 0x1A14)) == 0) {
                    temp_9_4 = var_18 + 0x19E4;
                    var_3_6 = 0;
                    if ((*(u8 *)((u8 *)(var_18) + 0x19E4)) != 0) {
                        temp_3_5 = (*(u8 *)((u8 *)(var_18) + 0x19E4));
                        *sp = (u8) *(temp_3_5 + 1 + (((temp_9_4 - temp_3_5) & 7 & 7) * 0xFF) + &D_L40_003BFE20);
                        temp_2_11 = sp0 ^ (s32) temp_9_4;
                        var_3_6 = sp4 ^ temp_2_11;
                        sp0 = temp_2_11;
                        sp4 = var_3_6;
                    }
                    if ((var_3_6 ^ 0x37) != 0) {
                        (*(s32 (**)(void *, s32, s32, s32, s32, void *))((u8 *)((*(void **)((u8 *)(var_18) + 0x14))) + 0x34))(var_18, 0x37, 1, 0, 1, temp_9_4);
                    }
                }
                temp_3_6 = (*(void **)((u8 *)(var_18) + 0x2524));
                (*(u16 *)((u8 *)(temp_3_6) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_3_6) + 0x34)) | 0x8000);
                sp80 = 0 /* M2C_ERROR unknown instruction: por $a1, $zero, $zero */;
                sp0 = 0;
                unksp88 = (*(f32 *)((u8 *)(var_18) + 0x23B8));
                sp70 = sp80;
                if ((*(u8 *)((u8 *)(var_18) + 0x1A14)) != 0) {
                    unksp78 = (*(f32 *)((u8 *)((*(void **)((u8 *)(var_18) + 0x2530))) + 0x18));
                }
                temp_f25 = func_0038D160((f32)((*(u128_t *)((u8 *)(arg0) + 0x10))) - (*(f32 *)((u8 *)(var_18) + 0xA0)), (*(f32 *)((u8 *)(arg0) + 0x14)) - (*(f32 *)((u8 *)(var_18) + 0xA4)));
                if (((func_L01_004606E8(0x80, 6, 0, (*(s32 *)((u8 *)(var_18) + 0x2534))) == 0) || ((*(s32 *)((u8 *)(var_18) + 0x2F0)) < 0x33)) && !(func_0038CF38(arg0 + 0x10, var_18 + 0xA0) >= 4.0f)) {
                    temp_2_12 = (*(void **)((u8 *)(var_18) + 0x2530));
                    var_10_2 = 0;
                    if (temp_2_12 != ((void *)0)) {
                        temp_9_5 = var_18 + 0x19E4;
                        if ((*(u8 *)((u8 *)(temp_2_12) + 0x27B)) != 0) {
                            var_3_7 = 0;
                            if ((*(u8 *)((u8 *)(var_18) + 0x19E4)) != 0) {
                                temp_3_7 = (*(u8 *)((u8 *)(var_18) + 0x19E4));
                                sp80 = (u8) *(temp_3_7 + 1 + (((temp_9_5 - temp_3_7) & 7 & 7) * 0xFF) + &D_L40_003BFE20);
                                temp_2_13 = (s32) sp80 ^ (s32) temp_9_5;
                                var_3_7 = unksp84 ^ temp_2_13;
                                sp80 = temp_2_13;
                                unksp84 = var_3_7;
                            }
                            if ((var_3_7 ^ 0x31) == 0) {
                                var_10_2 = 1;
                            }
                        }
                    }
                    if (var_10_2 & 0xFF) {
                        goto block_99;
                    }
                    goto block_103;
                }
block_99:
                if ((*(u8 *)((u8 *)(var_18) + 0x1A14)) != 0) {
                    func_L40_0041B820(arg0, 1);
                    if (((*(s32 *)((u8 *)(temp_19) + 0x34)) != 0) && (var_5 = 5, ((*(f32 *)((u8 *)(temp_19) + 0)) == 1.0f))) {

                    } else {
                        goto block_246;
                    }
                    goto block_247;
                }
block_103:
                if ((*(f32 *)((u8 *)(temp_19) + 0)) != 1.0f) {
                    sp0 = -(*(f32 *)((u8 *)(var_18) + 0x110));
                    sp4 = -(*(f32 *)((u8 *)(var_18) + 0x114));
                }
                temp_f0_2 = func_0038CED8(sp);
                if (temp_f0_2 > 1.0f) {
                    func_L01_0040E408(sp, sp, temp_f0_2);
                }
                func_0038D328(&sp20, &sp70);
                func_0038D028(sp, sp, &sp20);
                sp60 = func_0038D098((*(f32 *)((u8 *)((*(void **)((u8 *)(var_18) + 0x2524))) + 0xF8)));
                sp64 = func_0038D0B0((*(f32 *)((u8 *)((*(void **)((u8 *)(var_18) + 0x2524))) + 0xF8)));
                sp68 = 0;
                temp_f2 = (*(f32 *)((u8 *)(temp_19) + 0x1C));
                var_f0 = func_0038CE68(temp_19 + 0x40, sp) - temp_f2;
                if (var_f0 > 0.0022f) {
                    var_f0 = 0.0022f;
                }
                if (var_f0 < -0.0022f) {
                    var_f0 = -0.0022f;
                }
                temp_f0_3 = temp_f2 + var_f0;
                (*(f32 *)((u8 *)(temp_19) + 0x1C)) = temp_f0_3;
                (*(u128_t *)((u8 *)(temp_19) + 0x40)) = (u128_t)(sp0);
                if (temp_f0_3 > 0.07400001f) {
                    (*(f32 *)((u8 *)(temp_19) + 0x1C)) = 0.07400001f;
                }
                if ((*(f32 *)((u8 *)(temp_19) + 0x1C)) < 0.0f) {
                    (*(f32 *)((u8 *)(temp_19) + 0x1C)) = 0.0f;
                }
                if (fabsf((*(f32 *)((u8 *)(temp_19) + 0x1C))) < 0.00055f) {
                    (*(f32 *)((u8 *)(temp_19) + 0x1C)) = 0.0f;
                }
                func_0038CF68(&sp10, &sp60, (*(f32 *)((u8 *)(temp_19) + 0x1C)));
                if ((*(s32 *)((u8 *)(var_18) + 0x618)) & 2) {
                    if ((*(u8 *)((u8 *)((*(void **)((u8 *)(var_18) + 0x2524))) + 0x43)) == 0x33) {
                        func_L39_0062B4A8(var_18, 0x2F, 0, 0, 0x40C00000);
                        goto block_120;
                    }
                    goto block_121;
                }
block_120:
                if ((*(u8 *)((u8 *)((*(void **)((u8 *)(var_18) + 0x2524))) + 0x43)) != 0x33) {
block_121:
                    if ((*(s32 *)((u8 *)(var_18) + 0x61C)) == 0) {
                        temp_3_8 = (*(u8 *)((u8 *)((*(void **)((u8 *)(var_18) + 0x2524))) + 0x42));
                        if ((temp_3_8 == 0x30) && (fabsf((*(f32 *)((u8 *)(temp_19) + 0x1C))) == 0.0f)) {
                            var_f12 = 0x41400000;
                            var_5_2 = 0x2F;
                            goto block_138;
                        }
                        switch (temp_3_8) {         /* switch 2; irregular */
                        case 47:                    /* switch 2 */
                            if (((*(f32 *)((u8 *)(temp_19) + 0x1C)) > 0.0f) && ((*(f32 *)((u8 *)(temp_19) + 0)) != 1.0f)) {
                                var_f12 = 0x41400000;
block_137:
                                var_5_2 = 0x30;
block_138:
                                func_L39_0062B4A8(var_18, var_5_2, 0, 0, var_f12);
                            }
                            break;
                        case 48:                    /* switch 2 */
                            if ((*(f32 *)((u8 *)(temp_19) + 0x1C)) > 0.044400007f) {
                                var_f12 = 0x41400000;
                                var_5_2 = 0x31;
                                goto block_138;
                            }
                        default:                    /* switch 2 */
                            if (((*(u8 *)((u8 *)((*(void **)((u8 *)(var_18) + 0x2524))) + 0x42)) == 0x31) && ((*(f32 *)((u8 *)(temp_19) + 0x1C)) < 0.029600004f)) {
                                var_f12 = 0x41500000;
                                goto block_137;
                            }
                            if ((*(f32 *)((u8 *)(temp_19) + 0)) == 1.0f) {
                                func_L39_0062B4A8(var_18, 0x2F, 0, 0, 0x41400000);
                            }
                            break;
                        }
                    }
                }
                0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0x10($sp) */;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0xa0($s2) */;
                0 /* M2C_ERROR unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                temp_f22 = (*(f32 *)((u8 *)(var_18) + 0xA8));
                0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0xa0($s2) */;
                temp_f0_4 = func_0038D160((f32)((*(u128_t *)((u8 *)(arg0) + 0x10))) - (*(f32 *)((u8 *)(var_18) + 0xA0)), (*(f32 *)((u8 *)(arg0) + 0x14)) - (*(f32 *)((u8 *)(var_18) + 0xA4)));
                sp10 = func_0038D098(temp_f0_4) * -1.05f;
                temp_f0_5 = func_0038D0B0(temp_f0_4) * -1.05f;
                unksp18 = 0.0f;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0x10($s4) */;
                unksp14 = temp_f0_5;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0x10($sp) */;
                0 /* M2C_ERROR unknown instruction: vadd.xyz $vf2, $vf2, $vf1 */;
                0 /* M2C_ERROR unknown instruction: sqc2 $vf2, 0x80($sp) */;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0x80($sp) */;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0xa0($s2) */;
                0 /* M2C_ERROR unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0x90($sp) */;
                sp98 = 0.0f;
                spA0 = -func_0038CED8(&sp90);
                func_L01_004482A0(&spA0, temp_19 + 0x54, 0, 0x3CB0F27C, 0x3EDD2F1C, 0x3E0F5C2A);
                func_0038CF68(&sp90, (f32 *) &sp90, (*(f32 *)((u8 *)(temp_19) + 0x54)));
                0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0x90($sp) */;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0xa0($s2) */;
                0 /* M2C_ERROR unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0xa0($s2) */;
                (*(f32 *)((u8 *)(var_18) + 0xA8)) = temp_f22;
                temp_f0_6 = func_0038DAB8(1.5707964f, temp_f0_4);
                (*(f32 *)((u8 *)(var_18) + 0xFD0)) = temp_f0_6;
                func_L01_00448690(var_18 + 0xB8, 0, temp_f0_6, 0x3E00ADFD);
                temp_f1_3 = (*(f32 *)((u8 *)(temp_19) + 0x24)) + 0.00392f;
                (*(f32 *)((u8 *)(temp_19) + 0x24)) = temp_f1_3;
                (*(f32 *)((u8 *)(var_18) + 0xA8)) = (f32) ((*(f32 *)((u8 *)(var_18) + 0xA8)) - (temp_f1_3 - 2.0f));
                temp_f1_4 = func_003C3D30(var_18 + 0xA0, 0, 0, 0x3F000000);
                temp_f0_7 = (*(f32 *)((u8 *)(var_18) + 0xA8)) - 2.0f;
                (*(f32 *)((u8 *)(var_18) + 0xA8)) = temp_f0_7;
                if (temp_f0_7 < temp_f1_4) {
                    (*(f32 *)((u8 *)(var_18) + 0xA8)) = temp_f1_4;
                    (*(f32 *)((u8 *)(temp_19) + 0x24)) = 0.0f;
                }
                if ((*(u8 *)((u8 *)((*(void **)((u8 *)(var_18) + 0x2524))) + 0x43)) != 0x33) {
                    temp_f0_8 = func_0038DAB8(7.1e-44f, -0.2617994f, temp_f0_4);
                    func_L01_00448690(arg0 + 0xF8, 0, temp_f0_8, 0x3D80ADFD);
                    temp_f12 = (*(f32 *)((u8 *)(arg0) + 0xF8));
                    if (func_0038DB00((*(f32 *)((u8 *)(arg0) + 0xF8)), temp_f0_8) > 1.0471976f) {
                        var_f0_2 = func_0038DB00(temp_f12, 1.0471976f);
                        goto block_148;
                    }
                    if (func_0038DB00(temp_f12, temp_f0_8) < -1.0471976f) {
                        var_f0_2 = func_0038DAB8((*(f32 *)((u8 *)(arg0) + 0xF8)), 1.0471976f);
block_148:
                        (*(f32 *)((u8 *)(arg0) + 0xF8)) = var_f0_2;
                    }
                }
                temp_f1_5 = (*(f32 *)((u8 *)(temp_19) + 0x18)) + func_0038DBA0(temp_f0_4, temp_f25);
                (*(f32 *)((u8 *)(temp_19) + 0x18)) = temp_f1_5;
                temp_f1_6 = temp_f1_5 / ((*(f32 *)((u8 *)(temp_19) + 0x30)) * 6.2831855f);
                (*(f32 *)((u8 *)(temp_19) + 0)) = temp_f1_6;
                if (temp_f1_6 > 1.0f) {
                    (*(f32 *)((u8 *)(temp_19) + 0)) = 1.0f;
                }
                if ((*(f32 *)((u8 *)(temp_19) + 0)) < 0.0f) {
                    (*(f32 *)((u8 *)(temp_19) + 0)) = 0.0f;
                }
                if ((*(u8 *)((u8 *)(var_18) + 0x1A14)) == 0) {
                    temp_f0_9 = (*(f32 *)((u8 *)(temp_19) + 0));
                    if (temp_f0_9 == 1.0f) {
                        var_f0_3 = 0.999f;
                        goto block_158;
                    }
                    if (temp_f0_9 == 0.0f) {
                        var_f0_3 = 0.001f;
block_158:
                        (*(f32 *)((u8 *)(temp_19) + 0)) = var_f0_3;
                    }
                }
                (*(s32 (**)(void *))((u8 *)((*(void **)((u8 *)(var_18) + 0x14))) + 0x30))(var_18);
                if ((*(f32 *)((u8 *)(temp_19) + 0)) == 1.0f) {
                    (*(s32 *)((u8 *)(temp_19) + 0x5C)) = (s32) (*(s32 *)((u8 *)(temp_19) + 0x50));
                    temp_2_14 = (*(u16 *)((u8 *)(arg0) + 0x96)) + 1;
                    (*(u16 *)((u8 *)(arg0) + 0x96)) = temp_2_14;
                    if ((((s32) ((((((*(s32 *)((u8 *)(temp_19) + 0x34)) == 0) ? 0 : 0x78) + 0x3C) * 5) + 2) / 6) < (temp_2_14 & 0xFFFF)) && ((*(u8 *)((u8 *)(var_18) + 0x1A14)) != 0)) {
                        func_L40_0041B820(arg0, 1, (void *)6);
                        if ((*(s32 *)((u8 *)(temp_19) + 0x34)) != 0) {
                            var_5 = 5;
                        } else {
block_245:
block_246:
                            var_5 = 1;
                        }
block_247:
                        func_L01_004450F0(arg0, var_5, -1);
                    }
                }
                break;
            case 4:                                 /* switch 1 */
                var_2_3 = 0 /* M2C_ERROR unknown instruction: por $v0, $zero, $zero */;
                if ((*(u8 *)((u8 *)(var_18) + 0x1A14)) == 0) {
                    temp_9_6 = var_18 + 0x19E4;
                    var_3_8 = 0;
                    if ((*(u8 *)((u8 *)(var_18) + 0x19E4)) != 0) {
                        temp_3_9 = (*(u8 *)((u8 *)(var_18) + 0x19E4));
                        *sp = (u8) *(temp_3_9 + 1 + (((temp_9_6 - temp_3_9) & 7 & 7) * 0xFF) + &D_L40_003BFE20);
                        temp_2_15 = (s32)(sp0) ^ (s32) temp_9_6;
                        var_3_8 = (s32)(sp4) ^ temp_2_15;
                        sp0 = temp_2_15;
                        sp4 = var_3_8;
                    }
                    if ((var_3_8 ^ 0x37) != 0) {
                        (*(s32 (**)(void *, s32, s32, s32, s32, void *))((u8 *)((*(void **)((u8 *)(var_18) + 0x14))) + 0x34))(var_18, 0x37, 1, 0, 1, temp_9_6);
                    }
                    var_2_3 = 0 /* M2C_ERROR unknown instruction: por $v0, $zero, $zero */;
                }
                sp80 = var_2_3;
                sp40 = 0;
                unksp88 = (*(f32 *)((u8 *)(var_18) + 0x23B8));
                sp70 = var_2_3;
                if ((*(u8 *)((u8 *)(var_18) + 0x1A14)) != 0) {
                    unksp78 = (*(f32 *)((u8 *)((*(void **)((u8 *)(var_18) + 0x2530))) + 0x18));
                }
                temp_f25_2 = func_0038DAB8(func_0038D160((f32)((*(u128_t *)((u8 *)(arg0) + 0x10))) - (*(f32 *)((u8 *)(var_18) + 0xA0)), (*(f32 *)((u8 *)(arg0) + 0x14)) - (*(f32 *)((u8 *)(var_18) + 0xA4))), 3.1415927f);
                if (((func_L01_004606E8(0x80, 6, 0, (*(s32 *)((u8 *)(var_18) + 0x2534))) == 0) || ((*(s32 *)((u8 *)(var_18) + 0x2F0)) < 0x33)) && !(func_0038CF38(arg0 + 0x10, var_18 + 0xA0) >= 4.0f)) {
                    temp_2_16 = (*(void **)((u8 *)(var_18) + 0x2530));
                    var_10_3 = 0;
                    if (temp_2_16 != ((void *)0)) {
                        temp_9_7 = var_18 + 0x19E4;
                        if ((*(u8 *)((u8 *)(temp_2_16) + 0x27B)) != 0) {
                            var_3_9 = 0;
                            if ((*(u8 *)((u8 *)(var_18) + 0x19E4)) != 0) {
                                temp_3_10 = (*(u8 *)((u8 *)(var_18) + 0x19E4));
                                sp80 = (u8) *(temp_3_10 + 1 + (((temp_9_7 - temp_3_10) & 7 & 7) * 0xFF) + &D_L40_003BFE20);
                                temp_2_17 = (s32) sp80 ^ (s32) temp_9_7;
                                var_3_9 = unksp84 ^ temp_2_17;
                                sp80 = temp_2_17;
                                unksp84 = var_3_9;
                            }
                            if ((var_3_9 ^ 0x31) == 0) {
                                var_10_3 = 1;
                            }
                        }
                    }
                    if (var_10_3 & 0xFF) {
                        goto block_184;
                    }
                    goto block_185;
                }
block_184:
                if ((*(u8 *)((u8 *)(var_18) + 0x1A14)) == 0) {
block_185:
                    if ((*(f32 *)((u8 *)(temp_19) + 0)) > 0.0f) {
                        sp40 = (*(f32 *)((u8 *)(var_18) + 0x110));
                        unksp44 = (*(f32 *)((u8 *)(var_18) + 0x114));
                    }
                    temp_f0_10 = func_0038CED8(&sp40);
                    if (temp_f0_10 > 1.0f) {
                        func_L01_0040E408(&sp40, &sp40, temp_f0_10);
                    }
                    func_0038D328(sp, &sp70);
                    func_0038D028(&sp40, &sp40, sp);
                    sp60 = func_0038D098((*(f32 *)((u8 *)((*(void **)((u8 *)(var_18) + 0x2524))) + 0xF8)));
                    sp64 = func_0038D0B0((*(f32 *)((u8 *)((*(void **)((u8 *)(var_18) + 0x2524))) + 0xF8)));
                    sp68 = 0;
                    temp_f2_2 = (*(f32 *)((u8 *)(temp_19) + 0x1C));
                    var_f0_4 = func_0038CE68(temp_19 + 0x40, &sp40) - temp_f2_2;
                    if (var_f0_4 > 0.0022f) {
                        var_f0_4 = 0.0022f;
                    }
                    if (var_f0_4 < -0.0022f) {
                        var_f0_4 = -0.0022f;
                    }
                    temp_f0_11 = temp_f2_2 + var_f0_4;
                    (*(f32 *)((u8 *)(temp_19) + 0x1C)) = temp_f0_11;
                    (*(u128_t *)((u8 *)(temp_19) + 0x40)) = (u128_t)(sp40);
                    if (temp_f0_11 > 0.07400001f) {
                        (*(f32 *)((u8 *)(temp_19) + 0x1C)) = 0.07400001f;
                    }
                    if ((*(f32 *)((u8 *)(temp_19) + 0x1C)) < 0.0f) {
                        (*(f32 *)((u8 *)(temp_19) + 0x1C)) = 0.0f;
                    }
                    if (fabsf((*(f32 *)((u8 *)(temp_19) + 0x1C))) < 0.00055f) {
                        (*(f32 *)((u8 *)(temp_19) + 0x1C)) = 0.0f;
                    }
                    func_0038CF68(&sp50, &sp60, (*(f32 *)((u8 *)(temp_19) + 0x1C)));
                    if ((*(s32 *)((u8 *)(var_18) + 0x618)) & 2) {
                        if ((*(u8 *)((u8 *)((*(void **)((u8 *)(var_18) + 0x2524))) + 0x43)) == 0x33) {
                            func_L39_0062B4A8(var_18, 0x2F, 0, 0, 0x40C00000);
                            goto block_202;
                        }
                        goto block_203;
                    }
block_202:
                    if ((*(u8 *)((u8 *)((*(void **)((u8 *)(var_18) + 0x2524))) + 0x43)) != 0x33) {
block_203:
                        if ((*(s32 *)((u8 *)(var_18) + 0x61C)) == 0) {
                            temp_3_11 = (*(u8 *)((u8 *)((*(void **)((u8 *)(var_18) + 0x2524))) + 0x42));
                            if ((temp_3_11 == 0x30) && (fabsf((*(f32 *)((u8 *)(temp_19) + 0x1C))) == 0.0f)) {
                                var_f12_2 = 0x41400000;
                                var_5_3 = 0x2F;
                                goto block_220;
                            }
                            switch (temp_3_11) {    /* switch 3; irregular */
                            case 47:                /* switch 3 */
                                if (((*(f32 *)((u8 *)(temp_19) + 0x1C)) > 0.0f) && ((*(f32 *)((u8 *)(temp_19) + 0)) > 0.0f)) {
                                    var_f12_2 = 0x41400000;
block_219:
                                    var_5_3 = 0x30;
block_220:
                                    func_L39_0062B4A8(var_18, var_5_3, 0, 0, var_f12_2);
                                }
                                break;
                            case 48:                /* switch 3 */
                                if ((*(f32 *)((u8 *)(temp_19) + 0x1C)) > 0.044400007f) {
                                    var_f12_2 = 0x41400000;
                                    var_5_3 = 0x31;
                                    goto block_220;
                                }
                            default:                /* switch 3 */
                                if (((*(u8 *)((u8 *)((*(void **)((u8 *)(var_18) + 0x2524))) + 0x42)) == 0x31) && ((*(f32 *)((u8 *)(temp_19) + 0x1C)) < 0.029600004f)) {
                                    var_f12_2 = 0x41500000;
                                    goto block_219;
                                }
                                if ((*(f32 *)((u8 *)(temp_19) + 0)) == 0.0f) {
                                    func_L39_0062B4A8(var_18, 0x2F, 0, 0, 0x41400000);
                                }
                                break;
                            }
                        }
                    }
                    0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0x50($sp) */;
                    0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0xa0($s2) */;
                    0 /* M2C_ERROR unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                    temp_f22_2 = (*(f32 *)((u8 *)(var_18) + 0xA8));
                    0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0xa0($s2) */;
                    temp_f0_12 = func_0038DAB8(func_0038D160((f32)((*(u128_t *)((u8 *)(arg0) + 0x10))) - (*(f32 *)((u8 *)(var_18) + 0xA0)), (*(f32 *)((u8 *)(arg0) + 0x14)) - (*(f32 *)((u8 *)(var_18) + 0xA4))), 3.1415927f);
                    sp50 = func_0038D098(temp_f0_12) * 1.05f;
                    temp_f0_13 = func_0038D0B0(temp_f0_12) * 1.05f;
                    unksp58 = 0.0f;
                    0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0x10($s4) */;
                    unksp54 = temp_f0_13;
                    0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0x50($sp) */;
                    0 /* M2C_ERROR unknown instruction: vadd.xyz $vf2, $vf2, $vf1 */;
                    0 /* M2C_ERROR unknown instruction: sqc2 $vf2, 0x80($sp) */;
                    0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0x80($sp) */;
                    0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0xa0($s2) */;
                    0 /* M2C_ERROR unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                    0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0x90($sp) */;
                    sp98 = 0.0f;
                    spA4 = -func_0038CED8(&sp90);
                    func_L01_004482A0(&spA4, temp_19 + 0x54, 0, 0x3CB0F27C, 0x3EDD2F1C, 0x3E0F5C2A);
                    func_0038CF68(&sp90, (f32 *) &sp90, (*(f32 *)((u8 *)(temp_19) + 0x54)));
                    0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0x90($sp) */;
                    0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0xa0($s2) */;
                    0 /* M2C_ERROR unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                    0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0xa0($s2) */;
                    (*(f32 *)((u8 *)(var_18) + 0xA8)) = temp_f22_2;
                    temp_f0_14 = func_0038DAB8(1.5707964f, temp_f0_12);
                    (*(f32 *)((u8 *)(var_18) + 0xFD0)) = temp_f0_14;
                    func_L01_00448690(var_18 + 0xB8, 0, temp_f0_14, 0x3E00ADFD);
                    temp_f1_7 = (*(f32 *)((u8 *)(temp_19) + 0x24)) + 0.00392f;
                    (*(f32 *)((u8 *)(temp_19) + 0x24)) = temp_f1_7;
                    (*(f32 *)((u8 *)(var_18) + 0xA8)) = (f32) ((*(f32 *)((u8 *)(var_18) + 0xA8)) - (temp_f1_7 - 2.0f));
                    temp_f1_8 = func_003C3D30(var_18 + 0xA0, 0, 0, 0x3F000000);
                    temp_f0_15 = (*(f32 *)((u8 *)(var_18) + 0xA8)) - 2.0f;
                    (*(f32 *)((u8 *)(var_18) + 0xA8)) = temp_f0_15;
                    if (temp_f0_15 < temp_f1_8) {
                        (*(f32 *)((u8 *)(var_18) + 0xA8)) = temp_f1_8;
                        (*(f32 *)((u8 *)(temp_19) + 0x24)) = 0.0f;
                    }
                    if ((*(u8 *)((u8 *)((*(void **)((u8 *)(var_18) + 0x2524))) + 0x43)) != 0x33) {
                        temp_f0_16 = func_0038DAB8(7.1e-44f, 0.2617994f, temp_f0_12);
                        func_L01_00448690(arg0 + 0xF8, 0, temp_f0_16, 0x3D80ADFD);
                        temp_f12_2 = (*(f32 *)((u8 *)(arg0) + 0xF8));
                        if (func_0038DB00((*(f32 *)((u8 *)(arg0) + 0xF8)), temp_f0_16) > 1.0471976f) {
                            var_f0_5 = func_0038DB00(temp_f12_2, 1.0471976f);
                            goto block_230;
                        }
                        if (func_0038DB00(temp_f12_2, temp_f0_16) < -1.0471976f) {
                            var_f0_5 = func_0038DAB8((*(f32 *)((u8 *)(arg0) + 0xF8)), 1.0471976f);
block_230:
                            (*(f32 *)((u8 *)(arg0) + 0xF8)) = var_f0_5;
                        }
                    }
                    temp_f1_9 = (*(f32 *)((u8 *)(temp_19) + 0x18)) - func_0038DBA0(temp_f0_12, temp_f25_2);
                    (*(f32 *)((u8 *)(temp_19) + 0x18)) = temp_f1_9;
                    temp_f1_10 = temp_f1_9 / ((*(f32 *)((u8 *)(temp_19) + 0x30)) * 6.2831855f);
                    (*(f32 *)((u8 *)(temp_19) + 0)) = temp_f1_10;
                    if (temp_f1_10 > 1.0f) {
                        (*(f32 *)((u8 *)(temp_19) + 0)) = 1.0f;
                    }
                    if ((*(f32 *)((u8 *)(temp_19) + 0)) < 0.0f) {
                        (*(f32 *)((u8 *)(temp_19) + 0)) = 0.0f;
                    }
                    if ((*(u8 *)((u8 *)(var_18) + 0x1A14)) == 0) {
                        temp_f0_17 = (*(f32 *)((u8 *)(temp_19) + 0));
                        if (temp_f0_17 == 1.0f) {
                            var_f0_6 = 0.999f;
                            goto block_240;
                        }
                        if (temp_f0_17 == 0.0f) {
                            var_f0_6 = 0.001f;
block_240:
                            (*(f32 *)((u8 *)(temp_19) + 0)) = var_f0_6;
                        }
                    }
                    (*(s32 (**)(void *))((u8 *)((*(void **)((u8 *)(var_18) + 0x14))) + 0x30))(var_18);
                    if ((*(f32 *)((u8 *)(temp_19) + 0)) == 0.0f) {
                        (*(u16 *)((u8 *)(arg0) + 0x96)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x96)) + 1);
                        (*(s32 *)((u8 *)(temp_19) + 0x5C)) = (s32) (*(s32 *)((u8 *)(temp_19) + 0x50));
                        if (((s32) (*(u16 *)((u8 *)(arg0) + 0x96)) >= ((s32) ((((((*(s32 *)((u8 *)(temp_19) + 0x34)) == 0) ? 0 : 0x78) + 0x3C) * 5) + 2) / 6)) && ((*(u8 *)((u8 *)(var_18) + 0x1A14)) != 0)) {
                            goto block_244;
                        }
                    }
                } else {
block_244:
                    func_L40_0041B820(arg0, 1);
                    goto block_245;
                }
                break;
            case 5:                                 /* switch 1 */
                temp_f2_3 = (*(f32 *)((u8 *)(arg0) + 0x18));
                temp_f1_11 = (*(f32 *)((u8 *)(temp_19) + 0x3C)) - 0.5f;
                if (temp_f1_11 < temp_f2_3) {
                    (*(f32 *)((u8 *)(arg0) + 0x18)) = (f32) (temp_f2_3 - 0.060000002f);
                }
                if ((*(f32 *)((u8 *)(arg0) + 0x18)) < temp_f1_11) {
                    (*(f32 *)((u8 *)(arg0) + 0x18)) = temp_f1_11;
                }
                func_L40_0041B820(arg0, 0);
                break;
            }
        }
    } else {
        (*(f32 *)((u8 *)(arg0) + 0xF8)) = func_0038DAB8((*(f32 *)((u8 *)(arg0) + 0xF8)), 0.12566371f);
    default:                                        /* switch 1 */
    }
}


#endif
