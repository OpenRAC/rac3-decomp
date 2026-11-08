/* func_L20_003AF880: Opus handoff (prep by Sonnet worker w6, 2026-11-08)
   Size: 9688 bytes, places: 1 level (20, final boss), file: src/levels/20_final_boss/L20_003AF880.c
   flags: the file's own line (-O2 -G8 -fopt-stack -mno-check-zero-division, NO @ps2as); retail has 158 mtc1 (inline float constants) and 36 lq/sq:
     a file with an estimated flag line and no C yet: try --as ps2as first (Ps2EeAs inline constants), then check with --all-modes.
   Step 0: one function; 2 jump tables (jtbl_002C8A90, jtbl_002C8AB0), 17 cases. final-boss moby update (rand_range_signed x23, rand_below x20, moby_set_state x14, vec_set_length x14, explosion/particle spawns, moby_play_sound x10, moby_joint_matrix x9).
   rac2 twin: none: best opcode 0.207 (func_L15_003DBB08); rac3 siblings <= 0.14 (func_L08_003A4E60, func_L01_003A0778); callees map to only 3 rac2 twins.
   Mapping / identical / changed: no twin to map. Hot callees have names in config/names.tsv (moby_set_state, moby_anim_blend,
     vec_set_length, angle_add/sub, atan2, rand_*), so the m2c is readable as moby-AI code.
   VU0 note: 64 COP2 instructions: with the 2026-11-06 rule (no VU0 inline asm in matched C) this cannot be a MATCH unless a
     TI-mode/scalar-C form produces them; keep as a near miss.
   Draft: no compiling draft (m2c converted (892 lines), not compiled yet: 64 COP2 instrs appear as M2C_ERROR placeholders.). The fenced block is the mechanically converted m2c (M2C_FIELD ->
     byte-offset casts, M2C_UNK -> s32, s128 -> u128_t TI typedef). Not measured.
   Left for Opus: (1) type the object (moby: pos +0x10, state +0x20 u8, class ptr +0x24, flags +0x34 u16; the +0x68 pointer is the
     per-moby vars block); (2) turn float-hex arguments back into f32; (3) get it to compile, measure, then register/scheduling work.
   Tool note: tools in out/tools-w6/ (m2c2.py: restores the `.word`-hidden lq/sq and appends the jump tables so m2c runs at all;
     conv.py: M2C_FIELD -> casts; iter.py: compile loop dropping conflicting prototypes).
*/
#if 0 /* does not compile yet: m2c2 draft mechanically converted (tools in worker w6 scratch), prototypes unverified */
typedef int u128_t __attribute__((mode(TI)));
f32 *func_00382348(s32);                            /* extern */
s32 func_00382468(s32);                         /* extern */
s32 func_00382498(s32, s32);                /* extern */
f32 func_003824E0(void *, u128_t, u128_t, s32, s32); /* extern */
s32 func_00382580(u128_t *, f32, f32);            /* extern */
s32 func_0038CAD0(void *);                          /* extern */
s32 func_0038CB00(void *);                          /* extern */
s32 func_0038CE20(u128_t *, u128_t *, s32);     /* extern */
s32 func_0038CF68(u128_t *, u128_t *, f32);         /* extern */
f32 func_0038D098(f32);                             /* extern */
f32 func_0038D0B0(f32);                             /* extern */
f32 func_0038D160(f32, f32, f32);                   /* extern */
f32 func_0038DAB8(f32, f32);                        /* extern */
s32 func_00392B20(s32 *, s32);          /* extern */
s32 func_00392C78(s32 *);                   /* extern */
s32 func_003A0EC0(s32, s32, s32, s32, s32); /* extern */
s32 func_003A1798(s32 *);                   /* extern */
s32 func_003A2B68(s32, s32);                /* extern */
s32 func_003A4F28(s32, s32);                    /* extern */
s32 func_003A52A0(s32, s32, void *);            /* extern */
s32 func_003C2880(void *);                      /* extern */
s32 func_003C2EC0(void *, s32, u128_t *, s32); /* extern */
s32 func_003C2F58(void *, s32, u128_t *);     /* extern */
s32 func_003C4098(u128_t *, u128_t *, u128_t *, f32); /* extern */
s32 func_003C7958(void *, s32, void *);     /* extern */
s32 func_003D3CB0(u128_t *, f32 *, s32, void *, s32); /* extern */
s32 func_L01_003303B8(u128_t *, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_L01_00356C90(void *);                  /* extern */
s32 func_L01_003B1350(void *);                  /* extern */
s32 func_L01_003B1DB8(void *);                  /* extern */
s32 func_L01_00404808(s32 *, void *);       /* extern */
f32 func_L01_004395E0(void *);                      /* extern */
f32 func_L01_00443A18(void *, s32, s32);    /* extern */
s32 func_L01_00443B88(u128_t *, s32, s32); /* extern */
s32 func_L01_004450F0(void *, s32, s32, void *, void *, void *); /* extern */
f32 func_L01_00447878(u128_t *, u128_t *, s32, f32, f32); /* extern */
s32 func_L01_0044E1B8(void *, s32, s32);    /* extern */
s32 func_L01_00454370(void *, void *);              /* extern */
s32 func_L01_004561B8(void *);                      /* extern */
s32 func_L01_004561E0(void *);                      /* extern */
s32 func_L01_00456250(void *);                      /* extern */
s32 func_L01_0045BD10(void *, f32);             /* extern */
void *func_L01_0046A610(f32 *, s32 *, s32, s32, s32, s32, f32, s32, s32, s32, s32); /* extern */
void *func_L01_004713C8(u128_t *, u128_t *, s32, s32, s32, s32, s32, s32, f32, f32, s32); /* extern */
s32 func_L01_004AA7E8(void *, s32);         /* extern */
s32 func_L01_004BA800(f32);                         /* extern */
s32 func_L03_00433C70(void *, u128_t *, void *, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_L07_003E3C90(void *, u128_t *, f32 *, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_L20_003B1E58();                            /* extern */
s32 func_L20_003B24B0(void *);                  /* extern */
s32 func_L20_003B24F0(void *);                  /* extern */
s32 func_L20_003B2618(void *, s32, s32, s32); /* extern */
s32 func_L20_003F21A8(void *, u128_t *, u128_t *, s32); /* extern */
s32 func_L20_003F27E8(void *, u128_t *, f32 *, s32, f32, s32); /* extern */
s32 func_L20_003F4320(void *, s32, s32); /* extern */
s32 func_L20_004026A0(u128_t *);                  /* extern */
extern s32 D_1A30B0;
extern s32 D_1A4BE0;
extern s32 D_1A4CB0;
extern s32 D_1CCFD0;
extern s32 D_L20_001D66B0;
extern f32 D_L20_001DFB50;
extern s32 D_L20_001DFD40;
extern s32 D_L20_001E029C;
extern s32 D_L20_001E2E80;
extern s32 D_L20_001E9980;
extern s32 D_L20_001E9BD8;
extern s32 D_L20_00220258;
extern void *D_L20_002203C8;
extern s32 D_L20_002C5280;
extern s32 func_L20_003B2698;
extern s32 func_L20_003B2960;

void func_L20_003AF880(void *arg0) {
    u128_t sp90;
    u128_t spA0;                                      /* compiler-managed */
    u128_t spB0;
    u128_t spC0;
    f32 spD0;
    f32 spD4;
    f32 spD8;
    u128_t spE0;
    f32 spF0;
    f32 spF4;
    f32 spF8;
    f32 sp100;
    f32 sp104;
    f32 sp108;
    u128_t sp110;
    u128_t sp150;
    s32 var_4;
    s32 var_5;
    s32 var_8;
    f32 *temp_2;
    f32 temp_4;
    f32 temp_f0;
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
    f32 temp_f12_3;
    f32 temp_f12_4;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f21;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 var_f20;
    f32 var_f22;
    u128_t *temp_16_3;
    u128_t *temp_16_4;
    s32 temp_17;
    s32 temp_4_6;
    s32 temp_4_9;
    s32 temp_5;
    s32 temp_5_2;
    s32 temp_5_3;
    s32 var_16;
    s32 var_16_2;
    s32 var_17;
    s32 var_18;
    s32 var_19;
    s32 var_2;
    s32 var_7;
    s32 var_condition_bit;
    s8 var_3_2;
    s8 var_3_3;
    s8 var_3_4;
    u16 temp_3_2;
    u8 temp_2_3;
    u8 temp_3;
    void *temp_16;
    void *temp_16_2;
    void *temp_17_2;
    void *temp_19;
    void *temp_2_10;
    void *temp_2_11;
    void *temp_2_12;
    void *temp_2_13;
    void *temp_2_14;
    void *temp_2_15;
    void *temp_2_2;
    void *temp_2_4;
    void *temp_2_5;
    void *temp_2_6;
    void *temp_2_7;
    void *temp_2_8;
    void *temp_2_9;
    void *temp_3_3;
    void *temp_3_4;
    void *temp_3_5;
    void *temp_3_6;
    void *temp_4_10;
    void *temp_4_11;
    void *temp_4_12;
    void *temp_4_2;
    void *temp_4_3;
    void *temp_4_4;
    void *temp_4_5;
    void *temp_4_7;
    void *temp_4_8;
    void *temp_6;
    void *temp_7;
    void *temp_7_2;
    void *temp_7_3;
    void *temp_8;
    void *temp_8_2;
    void *temp_9;
    void *var_3;
    void *var_4_2;
    void *var_4_3;

    temp_19 = (*(void **)((u8 *)(arg0) + 0x68));
    if (func_L20_003B1E58() != 0) {
        func_003C2880(arg0);
    } else {
        var_16 = 0;
        if ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x19E0)) != 0) {
            temp_2 = func_00382348((*(s32 *)((u8 *)(&D_1A4BE0) + 0x19E0)));
            if (temp_2 != NULL) {
                temp_f0 = *temp_2;
                temp_f1 = (*(f32 *)((u8 *)(temp_19) + 0x394));
                if (temp_f1 != temp_f0) {
                    if (temp_f0 < temp_f1) {
                        var_16 = 1;
                    }
                    (*(f32 *)((u8 *)(temp_19) + 0x394)) = temp_f0;
                }
            }
        } else {
            (*(f32 *)((u8 *)(temp_19) + 0x394)) = 0.0f;
        }
        if ((var_16 != 0) || (((*(s32 *)((u8 *)(&D_1A4BE0) + 0x2808)) != 0) && ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x19E0)) == 0))) {
            temp_3 = (*(u8 *)((u8 *)(arg0) + 0x95));
            if (func_00382468(0xA) == 0) {
                var_2 = temp_3 < 6U;
                if (temp_3 == 2) {
                    func_L01_003B1DB8(arg0);
                    goto block_15;
                }
            } else {
                goto block_16;
            }
        } else {
block_15:
block_16:
            var_2 = (*(u8 *)((u8 *)(arg0) + 0x95)) < 6U;
        }
        if (var_2 != 0) {
            temp_4 = *(((*(u8 *)((u8 *)(arg0) + 0x95)) * 4) + &jtbl_002C8A90);
            switch ((*(u8 *)((u8 *)(arg0) + 0x95))) {  /* switch 1 */
            case 5:                                 /* switch 1 */
                if (func_L01_004BA800(temp_4) == 0) {
                    func_003A0EC0(9, 1, 0, 0, 0);
                }
                break;
            case 4:                                 /* switch 1 */
                if (func_L01_00456250(arg0) != 0) {
                    func_L20_003B2618(arg0, 2, 0, 0);
                    temp_7 = (*(void **)((u8 *)(arg0) + 0x24));
                    temp_3_2 = (*(u16 *)((u8 *)(arg0) + 0x34)) & 0xFFBE;
                    (*(u16 *)((u8 *)(arg0) + 0x34)) = temp_3_2;
                    (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (temp_3_2 | ((*(u16 *)((u8 *)(temp_7) + 0x44)) & 0x1000));
                    (*(s32 *)((u8 *)(arg0) + 0x98)) = (s32) (*(s32 *)((u8 *)(temp_7) + 0x10));
                    temp_3_3 = (*(void **)((u8 *)(temp_19) + 0x2E4));
                    (*(u16 *)((u8 *)(temp_3_3) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_3_3) + 0x34)) & 0xFFBE);
                    temp_7_2 = (*(void **)((u8 *)(temp_19) + 0x2E4));
                    (*(u16 *)((u8 *)(temp_7_2) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_7_2) + 0x34)) | ((*(u16 *)((u8 *)((*(void **)((u8 *)(temp_7_2) + 0x24))) + 0x44)) & 0x1000));
                    temp_8 = (*(void **)((u8 *)(temp_19) + 0x2E4));
                    (*(s32 *)((u8 *)(temp_8) + 0x98)) = (s32) (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_8) + 0x24))) + 0x10));
                    temp_9 = (*(void **)((u8 *)(temp_19) + 0x2E0));
                    (*(u16 *)((u8 *)(temp_9) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_9) + 0x34)) & 0xFFBE);
                    temp_7_3 = (*(void **)((u8 *)(temp_19) + 0x2E0));
                    (*(u16 *)((u8 *)(temp_7_3) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_7_3) + 0x34)) | ((*(u16 *)((u8 *)((*(void **)((u8 *)(temp_7_3) + 0x24))) + 0x44)) & 0x1000));
                    temp_8_2 = (*(void **)((u8 *)(temp_19) + 0x2E0));
                    (*(s32 *)((u8 *)(temp_8_2) + 0x98)) = (s32) (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_8_2) + 0x24))) + 0x10));
                    func_L01_004450F0(arg0, 3, 2, temp_7_3, temp_8_2, temp_9);
                }
                break;
            case 0:                                 /* switch 1 */
                temp_2_2 = &D_1A4BE0 + 0x4BE0;
                func_L01_0045BD10(arg0, func_0038D160(temp_4, (*(f32 *)((u8 *)(temp_2_2) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_2_2) + 0x84)) - (*(f32 *)((u8 *)(arg0) + 0x14))));
                if (func_L01_004561E0(arg0) != 0) {
                    (*(s16 *)((u8 *)(temp_19) + 0x2D6)) = (s16) ((s32) ((func_00382498(0, 0x1E) * 5) + 2) / 6);
                }
                if (((*(s16 *)((u8 *)(temp_19) + 0x234)) != 1) || (func_0038CB00(temp_19 + 0x2D6) == 0)) {
                    if (((*(s32 *)((u8 *)(temp_19) + 0x2D8)) != 0) && (func_0038CB00(temp_19 + 0x2D6) != 0)) {
                        func_L01_004450F0(arg0, 2, 1);
                        (*(s32 *)((u8 *)(temp_19) + 0x2D8)) = 0;
                        if ((*(s32 *)((u8 *)(temp_19) + 0x2D0)) < 0xFA) {
                            var_4 = 0x1E0;
block_97:
                            (*(s32 *)((u8 *)(temp_19) + 0x2D0)) = (s32) ((s32) ((func_00382498(var_4, 0x258) * 5) + 2) / 6);
                        }
                    }
                } else {
block_95:
                    func_L01_004450F0(arg0, 4, 2);
                }
                break;
            case 1:                                 /* switch 1 */
                if ((*(s16 *)((u8 *)(temp_19) + 0x234)) != 1) {
                    if ((*(s32 *)((u8 *)(temp_19) + 0x2D0)) == 0) {
                        func_L01_004450F0(arg0, 1, 0);
                    }
                } else {
                    goto block_95;
                }
                break;
            case 2:                                 /* switch 1 */
                if (func_L01_004561E0(arg0) != 0) {
                    func_003A2B68(((*(s32 *)((u8 *)(temp_19) + 0x364)) & 0x3FFF) + 0x7D0, 0);
                    (*(s32 *)((u8 *)(temp_19) + 0x398)) = func_00382498(0xB4, 0x168);
                }
                if ((*(s32 *)((u8 *)(&D_1CCFD0) + 0x6C)) == 0) {
                    if ((*(s32 *)((u8 *)(&D_1CCFD0) + 0x24)) == -1) {
                        if (((*(s32 *)((u8 *)(&D_1CCFD0) + 0x94)) == 0) && ((*(s32 *)((u8 *)(temp_19) + 0x390)) == 0) && ((*(s32 *)((u8 *)((&D_1A4BE0 + 0x4BE0)) + 0x2850)) > 0) && (func_0038CAD0(temp_19 + 0x398) != 0)) {
                            func_L01_00356C90(arg0);
                        }
                    }
                    if (((*(s32 *)((u8 *)(&D_1CCFD0) + 0x6C)) == 0) && ((*(s32 *)((u8 *)(&D_1CCFD0) + 0x24)) == -1)) {
                        if (((*(s32 *)((u8 *)(&D_1CCFD0) + 0x94)) == 0) && ((*(s32 *)((u8 *)(temp_19) + 0x390)) == 0) && ((*(s32 *)((u8 *)((&D_1A4BE0 + 0x4BE0)) + 0x2850)) < 0)) {
                            func_L01_003B1350(arg0);
                        }
                    }
                }
                var_3 = &D_1A4BE0 + 0x4BE0;
                if ((*(s16 *)((u8 *)(&D_1CCFD0) + 0x76)) == 0) {
                    var_3 = &D_1A4BE0 + 0x4BE0;
                    if (((*(s16 *)((u8 *)(&D_1CCFD0) + 0x9E)) == 3) && ((*(s16 *)((u8 *)(&D_1CCFD0) + 0x98)) < 0x1B58)) {
                        func_003A1798(&D_1CCFD0);
                        (*(s32 *)((u8 *)(temp_19) + 0x390)) = 0;
                        var_3 = &D_1A4BE0 + 0x4BE0;
                    }
                }
                if ((*(s32 *)((u8 *)(var_3) + 0x19E0)) == 0) {
                    temp_3_4 = D_L20_001E029C + ((*(s32 *)((u8 *)(temp_19) + 0x2DC)) << 8);
                    func_L01_0045BD10(arg0, func_0038D160((*(f32 *)((u8 *)(temp_3_4) + 0x10)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_3_4) + 0x14)) - (*(f32 *)((u8 *)(arg0) + 0x14))));
                } else {
                    func_L01_0045BD10(arg0, func_0038D160((*(f32 *)((u8 *)(var_3) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(var_3) + 0x84)) - (*(f32 *)((u8 *)(arg0) + 0x14))));
                }
                if ((*(s16 *)((u8 *)(temp_19) + 0x234)) != 1) {
                    func_L01_004561E0(arg0);
                }
                break;
            case 3:                                 /* switch 1 */
                temp_17 = func_L01_00454370(arg0, temp_19 + 0x160);
                temp_f0_2 = (*(f32 *)((u8 *)(temp_19) + 0x30));
                if (func_L01_004561E0(arg0) != 0) {
                    var_condition_bit = temp_f0_2 <= 0.0f;
                    if (temp_f0_2 <= 0.0f) {
                        func_L20_003B2618(arg0, 0x11, 0, 0x11);
                        (*(f32 *)((u8 *)(arg0) + 0x48)) = 0.65f;
                        func_003C2F58(arg0, 0, &sp90);
                        func_003C2F58((*(void **)((u8 *)(temp_19) + 0x2E0)), 1, &spA0);
                        func_L01_003303B8(&spA0, 1, 0xA, 0xA, 0xA, 0xA, 0x14, 0, 0x41100000, 0.0f, 0.0f, 0x40000000, 1, 1, 1, 1, 0, 1, 0x01010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                        func_003A52A0(func_00382498(5, 9), 0, arg0);
                        (*(f32 *)((u8 *)(&D_L20_001E2E80) + 0x40)) = 0.1f;
                        (*(s32 *)((u8 *)(&D_L20_001E2E80) + 0x48)) = 0x4B;
                        (*(f32 *)((u8 *)(&D_L20_001E2E80) + 0x20)) = 0.2f;
                        (*(s32 *)((u8 *)(&D_L20_001E2E80) + 0x28)) = 0x9E;
                        (*(s32 *)((u8 *)(&D_L20_001E2E80) + 0x2C)) = 0;
                        goto block_65;
                    }
                } else {
block_65:
                    var_condition_bit = (*(f32 *)((u8 *)(temp_19) + 0x30)) <= 0.0f;
                }
                if (var_condition_bit) {
                    if ((*(u16 *)((u8 *)(arg0) + 0x96)) == 0x96) {
                        (*(f32 *)((u8 *)(arg0) + 0x48)) = 0.65f;
                    }
                    if ((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 0x96U) {
                        D_L20_001DFB50 = (f32) ((*(u16 *)((u8 *)(arg0) + 0x96)) - 0x96) / 60.0f;
                    }
                    if ((*(u16 *)((u8 *)(arg0) + 0x96)) == 0x7D) {
                        func_003C2F58(arg0, 0, &sp90);
                        func_003C2F58((*(void **)((u8 *)(temp_19) + 0x2E0)), 1, &spA0);
                        func_003A52A0(0xA, 0, arg0);
                        func_L01_003303B8(&spA0, 1, 0, 0, 0, 0, 0, 0, 0x41100000, 0.0f, 0.0f, 0x40000000, 1, 1, 1, 1, 0, 1, 0x01010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                    }
                    if ((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 0xB8U) {
                        func_L20_003B24B0(arg0);
                        (*(s32 *)((u8 *)(arg0) + 0x98)) = 0;
                        (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x41) & 0xEFFF);
                        func_L01_004AA7E8(arg0, 1);
                        temp_3_5 = (*(void **)((u8 *)(temp_19) + 0x2E4));
                        (*(u16 *)((u8 *)(temp_3_5) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_3_5) + 0x34)) | 0x41);
                        temp_4_2 = (*(void **)((u8 *)(temp_19) + 0x2E4));
                        (*(u16 *)((u8 *)(temp_4_2) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_4_2) + 0x34)) & 0xEFFF);
                        (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x2E4))) + 0x98)) = 0;
                        func_L01_004AA7E8((*(void **)((u8 *)(temp_19) + 0x2E4)), 1);
                        temp_3_6 = (*(void **)((u8 *)(temp_19) + 0x2E0));
                        (*(u16 *)((u8 *)(temp_3_6) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_3_6) + 0x34)) | 0x41);
                        temp_4_3 = (*(void **)((u8 *)(temp_19) + 0x2E0));
                        (*(u16 *)((u8 *)(temp_4_3) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_4_3) + 0x34)) & 0xEFFF);
                        (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x2E0))) + 0x98)) = 0;
                        func_L01_004AA7E8((*(void **)((u8 *)(temp_19) + 0x2E0)), 1);
                        func_L01_004450F0(arg0, 0x12, 5);
                        func_00392B20(&D_L20_001E9980, 0x16);
                        func_00392C78(&D_L20_001E9980);
                    } else {
                        (*(s16 *)((u8 *)((&D_1A4BE0 + 0x4BE0)) + 0x1DC)) = 3;
                        (*(u128_t *)((u8 *)(&spB0) + 0)) = (*(u128_t *)((u8 *)(&D_L20_002C5280) + 0));
                        (*(u128_t *)((u8 *)(&spB0) + 0x10)) = (u128_t) (*(u128_t *)((u8 *)(&D_L20_002C5280) + 0x10));
                        var_16_2 = 0;
                        spD4 = func_003824E0(&D_L20_002C5280 + 0x20, (*(u128_t *)((u8 *)(&D_L20_002C5280) + 0)), (*(u128_t *)((u8 *)(&D_L20_002C5280) + 0x10)), 0x40000000, 0x40A00000);
                        sp104 = 1.4f;
                        spD0 = 1.0f;
                        if (func_00382468(0x19) == 0) {
                            var_16_2 = 1;
                            func_003C2EC0((*(void **)((u8 *)(temp_19) + 0x2E0)), 1, &sp110);
                        }
                        if (func_00382468(0x19) == 0) {
                            var_16_2 = 1;
                            func_003C2EC0((*(void **)((u8 *)(temp_19) + 0x2E0)), 2, &sp110);
                        }
                        if (func_00382468(0x19) == 0) {
                            var_16_2 = 1;
                            func_003C2EC0((*(void **)((u8 *)(temp_19) + 0x2E4)), 2, &sp110);
                        }
                        if (func_00382468(0x19) == 0) {
                            var_16_2 = 1;
                            func_003C2EC0((*(void **)((u8 *)(temp_19) + 0x2E4)), 3, &sp110);
                        }
                        if (func_00382468(0x19) == 0) {
                            var_16_2 = 1;
                            func_003C2EC0(arg0, 1, &sp110);
                        }
                        if (func_00382468(0x19) == 0) {
                            var_16_2 = 1;
                            func_003C2EC0(arg0, 2, &sp110);
                        }
                        if (var_16_2 != 0) {
                            spB0 = sp140;
                            func_003C2F58(arg0, 0, &sp90);
                            var_f20 = -1.0f;
                            if (func_00382468(2) == 0) {
                                var_f20 = 1.0f;
                            }
                            func_0038CF68(&spC0, &(&sp110)[func_00382468(3)], var_f20);
                            0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0xb0($sp) */;
                            0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0x90($sp) */;
                            0 /* M2C_ERROR unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                            0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0xa0($sp) */;
                            func_0038CF68(&spA0, &spA0, 1.0f);
                            sp150 = spC0;
                            func_003C4098(&spC0, &spA0, &sp150, func_003824E0((void *)0x3DCCCCCD, 0x3F000000));
                            func_L20_004026A0(&spB0);
                            if (func_00382468(3) == 0) {
                                func_003A52A0(func_00382498(5, 9), 0, arg0);
                            }
                        }
                    }
                } else if ((temp_17 & 2) && ((*(f32 *)((u8 *)(temp_19) + 0x30)) > 0.0f)) {
                    if ((*(s16 *)((u8 *)(temp_19) + 0x234)) == 1) {
                        goto block_95;
                    }
                    func_L01_004450F0(arg0, 2, 1);
                    var_4 = 0x244;
                    goto block_97;
                }
                break;
            }
        }
        temp_2_3 = (*(u8 *)((u8 *)(arg0) + 0x20));
        switch (temp_2_3) {                         /* switch 2 */
        case 1:                                     /* switch 2 */
            func_003C2EC0((*(void **)((u8 *)(temp_19) + 0x2E0)), 1, &sp90);
            func_0038CF68(&spE0, &sp90, 3.0f);
            0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0xe0($sp) */;
            0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0xc0($sp) */;
            0 /* M2C_ERROR unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
            0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0xd0($sp) */;
            if (func_00382468(2) != 0) {
                func_L01_00443A18((void *)0x3F800000, 0xBF800000);
                temp_2_4 = func_L01_0046A610(&spD0, &D_L20_001D66B0, 0xC, 6, 0x7C0030, second half of f64, 1.008e7f, 0x43FA0000, 0x3F800000, 0, 0);
                if (temp_2_4 != NULL) {
                    (*(u8 *)((u8 *)(temp_2_4) + 2)) = (u8) (*(u8 *)((u8 *)(D_L20_002203C8) + 1));
                }
            }
            spF0 = spD0 + func_L01_00443A18(NULL, 0x3D23D70A);
            spF4 = spD4 + func_L01_00443A18(NULL, 0x3D23D70A);
            spF8 = spD8 + func_L01_00443A18(NULL, 0x3D23D70A);
            if (func_00382468(2) != 0) {
                func_L01_00443A18((void *)0x3F800000, 0xBF800000);
                temp_2_5 = func_L01_0046A610(&spF0, &D_L20_001D66B0, 0xC, 0x7F, 0x7C0030, 0 /* M2C_ERROR Read from unset register $f2 */, 1680000.0f * 2.4f, 0x43FA0000, 0x3F800000, 0, 0);
                if (temp_2_5 != NULL) {
                    var_3_2 = 0x44;
                    if (func_00382468(2) != 0) {
                        var_3_2 = 0x48;
                    }
                    (*(s8 *)((u8 *)(temp_2_5) + 3)) = var_3_2;
                    (*(u8 *)((u8 *)(temp_2_5) + 2)) = (u8) (*(u8 *)((u8 *)(D_L20_002203C8) + 0));
                }
            }
            var_19 = 0x13;
            do {
                func_00382580((u128_t *) &sp100, 5.0f, 8.0f);
                0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0xd0($sp) */;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0x100($sp) */;
                0 /* M2C_ERROR unknown instruction: vadd.xyz $vf2, $vf2, $vf1 */;
                0 /* M2C_ERROR unknown instruction: sqc2 $vf2, 0x110($sp) */;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0xd0($sp) */;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0x110($sp) */;
                0 /* M2C_ERROR unknown instruction: vsub.xyz $vf2, $vf2, $vf1 */;
                0 /* M2C_ERROR unknown instruction: sqc2 $vf2, 0x100($sp) */;
                func_0038CF68((u128_t *) &sp100, (u128_t *) &sp100, 0.24000001f);
                func_L01_00443A18((void *)0x40000000, 0x40A00000);
                temp_2_6 = func_L01_004713C8(&sp110, (u128_t *) &sp100, 0x19, 0, second half of f64, 0x7F, 0x7F, 6, func_003824E0((void *)0x3F4CCCCD, 0x3FA00000) * 210000.0f, 2100.0f, 0x3BBF5D79);
                if (temp_2_6 != NULL) {
                    (*(s8 *)((u8 *)(temp_2_6) + 3)) = 0x44;
                    (*(u8 *)((u8 *)(temp_2_6) + 2)) = (u8) *(*(u8 **)((u8 *)(&D_L20_00220258) + 0xD4));
                }
                func_L01_00443A18(temp_2_6, 0x40000000, 0x40A00000);
                temp_2_7 = func_L01_004713C8(&sp110, (u128_t *) &sp100, 0x19, 0, second half of f64, 0x30, 0x30, 0, func_003824E0((void *)0x3F4CCCCD, 0x3FA00000) * 210000.0f * 3.0f, 4200.0f, 0x3BBF5D79);
                var_19 -= 1;
                if (temp_2_7 != NULL) {
                    (*(s8 *)((u8 *)(temp_2_7) + 3)) = 0x44;
                    (*(u8 *)((u8 *)(temp_2_7) + 2)) = (u8) *(*(u8 **)((u8 *)(&D_L20_00220258) + 0xD4));
                }
            } while (var_19 >= 0);
            break;
        case 3:                                     /* switch 2 */
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                func_L01_004450F0(arg0, 6, -1);
                func_L20_003B2618(arg0, 0xC, 0, 7);
            }
            break;
        case 6:                                     /* switch 2 */
            temp_f0_3 = func_L01_004395E0(arg0);
            if ((temp_f0_3 > 13.0f) && (temp_f0_3 < 28.0f)) {
                func_003A52A0(2, 0, arg0);
                temp_16 = &D_1A4BE0 + 0x4BE0;
                func_003C2F58((*(void **)((u8 *)(temp_19) + 0x2E0)), 1, &sp90);
                temp_f21 = (*(f32 *)((u8 *)(arg0) + 0xF8));
                temp_f0_4 = func_0038DAB8(temp_f21, func_L01_00443A18((void *)0x41700000, 0x42820000) * 0.017453292f);
                spA0 = func_0038D098(temp_f0_4);
                temp_f0_5 = func_0038D0B0(temp_f0_4);
                unkspA8 = NULL;
                unkspA4 = temp_f0_5;
                unkspA8 = func_L01_00443A18(unkspA8, 0x42340000) * 0.017453292f;
                func_0038CF68(&spA0, &spA0, 1.0000001f);
                if ((*(s32 *)((u8 *)(temp_16) + 0x19E0)) != 0) {
                    var_7 = (*(s32 *)((u8 *)(temp_16) + 0x25C0));
                } else if (func_00382468(2) == 0) {
                    var_7 = D_L20_001E029C + ((*(s32 *)((u8 *)(temp_19) + 0x2DC)) << 8);
                } else {
                    var_7 = (*(s32 *)((u8 *)(temp_16) + 0x25C0));
                }
                func_L20_003F21A8((*(void **)((u8 *)(temp_19) + 0x2E0)), &sp90, &spA0, var_7);
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                func_L20_003B2618(arg0, 7, 0, 0xF);
                var_5 = 7;
block_173:
                func_L01_004450F0(arg0, var_5, -1);
            }
            break;
        case 7:                                     /* switch 2 */
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                func_L20_003B2618(arg0, 8, 0, 2);
                var_5 = 8;
                goto block_173;
            }
            break;
        case 8:                                     /* switch 2 */
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                func_L20_003B2618(arg0, 9, 0, 4);
                func_L01_004450F0(arg0, 9, -1);
            }
            if ((func_L01_0044E1B8(arg0, 0x3F000000) != 0) || (func_L01_0044E1B8(arg0, 0, 0x41700000) != 0)) {
                func_003A52A0(0, 0, arg0);
                func_L01_00443B88(&sp90, 0, 0x3F800000);
                func_003C2F58((*(void **)((u8 *)(temp_19) + 0x2E4)), 0, &spA0);
                func_0038CE20(&spB0, &sp90, 0x40400000);
                unkspB8 = 0.0f;
                var_4_2 = (*(void **)((u8 *)(&D_1A4CB0) + 0x1910));
                spC0 = (*(u128_t *)((u8 *)(&D_1A4CB0) + 0));
                if (var_4_2 == NULL) {
                    var_4_2 = D_L20_001E029C + ((*(s32 *)((u8 *)(temp_19) + 0x2DC)) << 8);
                    spC0 = (*(u128_t *)((u8 *)(var_4_2) + 0x10));
                }
                0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0xc0($sp) */;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0xb0($sp) */;
                0 /* M2C_ERROR unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0xb0($sp) */;
                temp_f20 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x1A48)) * 0.020000001f;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0xb0($sp) */;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0xa0($sp) */;
                0 /* M2C_ERROR unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0xd0($sp) */;
                var_f22 = func_003824E0(var_4_2, (u128_t) (*(void **)((u8 *)(saved_reg_gp) + 0x1A4C)), (u128_t) (*(f32 *)((u8 *)(saved_reg_gp) + 0x1A50))) * 0.00040000002f;
                spD8 = 0.0f;
                func_0038CF68((u128_t *) &spD0, (u128_t *) &spD0, temp_f20);
                spD8 = func_L01_00447878(&spA0, &spB0, 0, (*(f32 *)((u8 *)(saved_reg_gp) + 0x1A48)) * 0.020000001f, -var_f22);
                func_L01_003303B8(&spA0, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 0x3F800000, 0.0f, 0.0f, 0x40000000, 0, 1, 0, 1, 0, 0, 0x01010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
block_166:
                func_L20_003F27E8((*(void **)((u8 *)(temp_19) + 0x2E4)), &spA0, &spD0, 0, var_f22, 0x43160000);
            }
            break;
        case 11:                                    /* switch 2 */
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                func_L20_003B2618(arg0, 0xC, 0, 8);
                func_L01_004450F0(arg0, 6, -1);
            }
            if ((D_L20_001DFD40 & 5) == (((s32) arg0 >> 8) & 5)) {
                func_003A52A0(0, 0, arg0);
                func_L01_00443B88(&sp90, 0, 0x3F800000);
                func_003C2F58((*(void **)((u8 *)(temp_19) + 0x2E4)), 1, &spA0);
                temp_16_2 = &D_1A4CB0 - 0xD0;
                spC0 = (*(u128_t *)((u8 *)(&D_1A4CB0) + 0));
                if ((*(void **)((u8 *)(temp_16_2) + 0x19E0)) == NULL) {
                    spC0 = (*(u128_t *)((u8 *)((D_L20_001E029C + ((*(s32 *)((u8 *)(temp_19) + 0x2DC)) << 8))) + 0x10));
                }
                func_0038CE20(&spB0, &sp90, 0x40400000);
                temp_4_4 = (*(void **)((u8 *)(temp_16_2) + 0x19E0));
                unkspB8 = 0.0f;
                spB0 = spC0;
                if ((temp_4_4 != NULL) && ((*(s16 *)((u8 *)(temp_4_4) + 0xAA)) == 0x107E)) {
                    temp_16_3 = (*(s32 *)((u8 *)(temp_4_4) + 0x68)) + 0x290;
                    func_0038CF68((u128_t *) &spD0, temp_16_3, func_003824E0(temp_4_4, 0x40800000, 0x41200000));
                    0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0xd0($sp) */;
                    0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0xb0($sp) */;
                    0 /* M2C_ERROR unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                    0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0xb0($sp) */;
                }
                0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0xb0($sp) */;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0xa0($sp) */;
                0 /* M2C_ERROR unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0xd0($sp) */;
                func_0038CF68((u128_t *) &spD0, (u128_t *) &spD0, 1.6000001f);
                func_L01_003303B8(&spA0, 0, 0, 0, 0, 5, 0, 0, 0x40000000, 0.0f, 0.0f, 0x40000000, 0, 1, 0, 0, 0, 0, 0x01010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                var_4_3 = arg0;
                var_8 = 0xC8;
block_158:
                func_L07_003E3C90(var_4_3, &spA0, &spD0, 1, var_8, 0, 0x42340000, 0x40400000, 0);
            }
            break;
        case 10:                                    /* switch 2 */
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                func_L20_003B2618(arg0, 9, 0, 4);
                func_L01_004450F0(arg0, 0xB, -1);
            }
            if ((D_L20_001DFD40 & 5) == (((s32) arg0 >> 8) & 5)) {
                func_003A52A0(0, 0, arg0);
                func_L01_00443B88(&sp90, 0, 0x3F800000);
                func_003C2F58((*(void **)((u8 *)(temp_19) + 0x2E4)), 0, &spA0);
                func_0038CE20(&spB0, &sp90, 0x40400000);
                unkspB8 = 0.0f;
                spC0 = (*(u128_t *)((u8 *)(&D_1A4CB0) + 0));
                if ((*(void **)((u8 *)(&D_1A4CB0) + 0x1910)) == NULL) {
                    spC0 = (*(u128_t *)((u8 *)((D_L20_001E029C + ((*(s32 *)((u8 *)(temp_19) + 0x2DC)) << 8))) + 0x10));
                }
                spB0 = spC0;
                if (((*(void **)((u8 *)(&D_1A4CB0) + 0x1910)) != NULL) && ((*(s16 *)((u8 *)((*(void **)((u8 *)(&D_1A4CB0) + 0x1910))) + 0xAA)) == 0x107E)) {
                    temp_16_4 = (*(s32 *)((u8 *)((*(void **)((u8 *)(&D_1A4CB0) + 0x1910))) + 0x68)) + 0x290;
                    func_0038CF68((u128_t *) &spD0, temp_16_4, func_003824E0((void *)0x41600000, 0x41C00000));
                    0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0xd0($sp) */;
                    0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0xb0($sp) */;
                    0 /* M2C_ERROR unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                    0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0xb0($sp) */;
                }
                0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0xb0($sp) */;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0xa0($sp) */;
                0 /* M2C_ERROR unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0xd0($sp) */;
                func_0038CF68((u128_t *) &spD0, (u128_t *) &spD0, 1.6000001f);
                func_L01_003303B8(&spA0, 0, 0, 0, 0, 5, 0, 0, 0x40000000, 0.0f, 0.0f, 0x40000000, 0, 1, 0, 0, 0, 0, 0x01010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                var_4_3 = (*(void **)((u8 *)(temp_19) + 0x2E4));
                var_8 = 0x96;
                goto block_158;
            }
            break;
        case 9:                                     /* switch 2 */
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                func_L20_003B2618(arg0, 0xA, 0, 7);
                func_L01_004450F0(arg0, 0xC, -1);
            }
            if ((func_L01_0044E1B8(arg0, 0x40800000) != 0) || (func_L01_0044E1B8(arg0, 0, 0x41900000) != 0)) {
                func_003A52A0(0, 0, arg0);
                func_L01_00443B88(&sp90, 0, 0x3F800000);
                func_003C2F58((*(void **)((u8 *)(temp_19) + 0x2E4)), 1, &spA0);
                spC0 = (*(u128_t *)((u8 *)(&D_1A4CB0) + 0));
                if ((*(void **)((u8 *)(&D_1A4CB0) + 0x1910)) == NULL) {
                    spC0 = (*(u128_t *)((u8 *)((D_L20_001E029C + ((*(s32 *)((u8 *)(temp_19) + 0x2DC)) << 8))) + 0x10));
                }
                func_0038CE20(&spB0, &sp90, 0x40400000);
                unkspB8 = 0.0f;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0xc0($sp) */;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0xb0($sp) */;
                0 /* M2C_ERROR unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0xb0($sp) */;
                temp_f20_2 = (*(f32 *)((u8 *)(saved_reg_gp) + 0x1A48)) * 0.020000001f;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0xb0($sp) */;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0xa0($sp) */;
                0 /* M2C_ERROR unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0xd0($sp) */;
                var_f22 = func_003824E0((*(void **)((u8 *)(saved_reg_gp) + 0x1A4C)), (u128_t) (*(f32 *)((u8 *)(saved_reg_gp) + 0x1A50))) * 0.00040000002f;
                spD8 = 0.0f;
                func_0038CF68((u128_t *) &spD0, (u128_t *) &spD0, temp_f20_2);
                spD8 = func_L01_00447878(&spA0, &spB0, 0, (*(f32 *)((u8 *)(saved_reg_gp) + 0x1A48)) * 0.020000001f, -var_f22);
                func_L01_003303B8(&spA0, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 0x3F800000, 0.0f, 0.0f, 0x40000000, 0, 1, 0, 1, 0, 0, 0x01010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                goto block_166;
            }
            break;
        case 12:                                    /* switch 2 */
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                if ((*(u8 *)((u8 *)(arg0) + 0x42)) == 0xA) {
                    func_L20_003B2618(arg0, 0xB, 0, 7);
                }
                if (((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) && ((*(u8 *)((u8 *)(arg0) + 0x42)) == 0xB)) {
                    func_L20_003B2618(arg0, 8, 0, 0xC);
                    var_5 = 0xA;
                    goto block_173;
                }
            }
            break;
        case 13:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                (*(f32 *)((u8 *)(temp_19) + 0x2F4)) = 0.0f;
                (*(f32 *)((u8 *)(temp_19) + 0x2FC)) = 0.0f;
                (*(f32 *)((u8 *)(temp_19) + 0x2F8)) = 0.0f;
            }
            temp_f1_2 = (*(f32 *)((u8 *)(temp_19) + 0x2F4)) + 0.03f;
            (*(f32 *)((u8 *)(temp_19) + 0x2F4)) = temp_f1_2;
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                func_L20_003B2618(arg0, 0xD, 0, 0x11);
                func_L01_004450F0(arg0, 0xE, -1);
                func_003C2F58((*(void **)((u8 *)(temp_19) + 0x2E0)), 2, &sp90);
                (*(u128_t *)((u8 *)(temp_19) + 0x310)) = sp90;
                spA0 = (*(u128_t *)((u8 *)(&D_1A4CB0) + 0));
                if ((*(void **)((u8 *)(&D_1A4CB0) + 0x1910)) == NULL) {
                    spA0 = (*(u128_t *)((u8 *)((D_L20_001E029C + ((*(s32 *)((u8 *)(temp_19) + 0x2DC)) << 8))) + 0x10));
                }
                (*(u128_t *)((u8 *)(temp_19) + 0x300)) = spA0;
            } else {
                temp_f22 = temp_f1_2 * 262500.0f;
                func_003C2EC0((*(void **)((u8 *)(temp_19) + 0x2E0)), 1, &spB0, 0x11);
                func_0038CF68((u128_t *) &spF0, &spB0, 3.0f);
                0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0xe0($sp) */;
                0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0xf0($sp) */;
                0 /* M2C_ERROR unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0x90($sp) */;
                if (func_00382468(2) != 0) {
                    func_L01_00443A18((void *)0x3F800000, 0xBF800000);
                    temp_2_8 = func_L01_0046A610((f32 *) &sp90, &D_L20_001D66B0, 0xC, 6, 0x7C0030, second half of f64, temp_f22 * 6.0f, 0x43FA0000, 0x3F800000, 0, 0);
                    if (temp_2_8 != NULL) {
                        (*(u8 *)((u8 *)(temp_2_8) + 2)) = (u8) (*(u8 *)((u8 *)(D_L20_002203C8) + 1));
                    }
                }
                spA0 = (f32)(sp90) + func_L01_00443A18(NULL, 0x3D23D70A);
                unkspA4 = unksp94 + func_L01_00443A18(NULL, 0x3D23D70A);
                unkspA8 = unksp98 + func_L01_00443A18(NULL, 0x3D23D70A);
                if (func_00382468(2) != 0) {
                    func_L01_00443A18((void *)0x3F800000, 0xBF800000);
                    temp_2_9 = func_L01_0046A610(&spA0, &D_L20_001D66B0, 0xC, 0x7F, 0x7C0030, second half of f64, temp_f22 * 2.4f, 0x43FA0000, 0x3F800000, 0, 0);
                    if (temp_2_9 != NULL) {
                        var_3_3 = 0x44;
                        if (func_00382468(2) != 0) {
                            var_3_3 = 0x48;
                        }
                        (*(s8 *)((u8 *)(temp_2_9) + 3)) = var_3_3;
                        (*(u8 *)((u8 *)(temp_2_9) + 2)) = (u8) (*(u8 *)((u8 *)(D_L20_002203C8) + 0));
                    }
                }
                var_17 = 5;
                do {
                    temp_f0_6 = (*(f32 *)((u8 *)(temp_19) + 0x2F4));
                    func_00382580((u128_t *) &sp100, temp_f0_6 * 0.10000001f, temp_f0_6 * 0.14000002f);
                    func_L01_00443A18((void *)0x40000000, 0x40A00000);
                    temp_f12 = (*(f32 *)((u8 *)(temp_19) + 0x2F4));
                    temp_2_10 = func_L01_004713C8(&sp90, (u128_t *) &sp100, 0xC, 0, second half of f64, 0x7F, 0x7F, 6, func_003824E0((void *)0x3F4CCCCD, 0x3FA00000) * 210000.0f * temp_f12, temp_f12 * 2100.0f, 0x3BBF5D79);
                    if (temp_2_10 != NULL) {
                        (*(s8 *)((u8 *)(temp_2_10) + 3)) = 0x44;
                        (*(u8 *)((u8 *)(temp_2_10) + 2)) = (u8) *(*(u8 **)((u8 *)(&D_L20_00220258) + 0xD4));
                    }
                    func_L01_00443A18(temp_2_10, 0x40000000, 0x40A00000);
                    temp_f12_2 = (*(f32 *)((u8 *)(temp_19) + 0x2F4));
                    temp_2_11 = func_L01_004713C8(&sp90, (u128_t *) &sp100, 0xC, 0, second half of f64, 0x30, 0x30, 0, func_003824E0((void *)0x3F4CCCCD, 0x3FA00000) * 210000.0f * 3.0f * temp_f12_2, temp_f12_2 * 4200.0f, 0x3BBF5D79);
                    var_17 -= 1;
                    if (temp_2_11 != NULL) {
                        (*(s8 *)((u8 *)(temp_2_11) + 3)) = 0x44;
                        (*(u8 *)((u8 *)(temp_2_11) + 2)) = (u8) *(*(u8 **)((u8 *)(&D_L20_00220258) + 0xD4));
                    }
                } while (var_17 >= 0);
            }
            break;
        case 14:                                    /* switch 2 */
            func_L01_00404808(&func_L20_003B2698, arg0);
            temp_f0_7 = (*(f32 *)((u8 *)(temp_19) + 0x2FC)) + 0.060000002f;
            (*(f32 *)((u8 *)(temp_19) + 0x2FC)) = temp_f0_7;
            if (temp_f0_7 > 2.5f) {
                (*(f32 *)((u8 *)(temp_19) + 0x2FC)) = 2.5f;
            }
            temp_f0_8 = (*(f32 *)((u8 *)(temp_19) + 0x2F8)) + 0.020000001f;
            (*(f32 *)((u8 *)(temp_19) + 0x2F8)) = temp_f0_8;
            if (temp_f0_8 > 2.5f) {
                (*(f32 *)((u8 *)(temp_19) + 0x2F8)) = 2.5f;
            }
            func_003C2EC0((*(void **)((u8 *)(temp_19) + 0x2E0)), 1, (u128_t *) &spA0);
            temp_17_2 = temp_19 + 0x310;
            func_0038CF68(&spE0, (u128_t *) &spA0, 3.0f);
            0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0xe0($sp) */;
            0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0xd0($sp) */;
            0 /* M2C_ERROR unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
            0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0x90($sp) */;
            (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x2E4))) + 0x98)) = 0;
            (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x2E0))) + 0x98)) = 0;
            func_003C7958((*(void **)((u8 *)(temp_19) + 0x2E4)), 0x80807F7F);
            func_003C7958((*(void **)((u8 *)(temp_19) + 0x2E0)), 0x80807F7F);
            func_L03_00433C70(arg0, &sp90, temp_17_2, 1, 0, 1, 0, 0x42340000, 0x3F800000);
            temp_6 = (*(void **)((u8 *)(temp_19) + 0x2E4));
            (*(s32 *)((u8 *)(temp_6) + 0x98)) = (s32) (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_6) + 0x24))) + 0x10));
            temp_4_5 = (*(void **)((u8 *)(temp_19) + 0x2E0));
            (*(s32 *)((u8 *)(temp_4_5) + 0x98)) = (s32) (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_4_5) + 0x24))) + 0x10));
            func_003C7958((*(void **)((u8 *)(temp_19) + 0x2E4)), 0x80807F7F, temp_6);
            func_003C7958((*(void **)((u8 *)(temp_19) + 0x2E0)), 0x80807F7F);
            0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0x90($sp) */;
            0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0x300($s3) */;
            0 /* M2C_ERROR unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
            0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0xf0($sp) */;
            func_0038CF68((u128_t *) &spF0, (u128_t *) &spF0, (*(f32 *)((u8 *)(temp_19) + 0x2F8)) * 120.0f);
            0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0xf0($sp) */;
            0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0x90($sp) */;
            0 /* M2C_ERROR unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
            0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0xf0($sp) */;
            if (func_003D3CB0(&sp90, &spF0, 2, arg0, 0) != 0) {
                if (D_L20_001E9BD8 == 0) {
                    temp_4_6 = (*(s32 *)((u8 *)(temp_19) + 0x2EC));
                    if ((temp_4_6 == -1) || (temp_4_7 = (temp_4_6 << 7) + &D_1A30B0, ((*(s32 *)((u8 *)(temp_4_7) + 0xDC)) != arg0)) || ((*(u8 *)((u8 *)(temp_4_7) + 0xD0)) == 0)) {
                        (*(s32 *)((u8 *)(temp_19) + 0x2EC)) = func_003A52A0(4, 4, arg0);
                    }
                    func_L20_003F4320(temp_17_2, 0x40000000, 0x40400000);
                }
            } else {
                temp_5 = (*(s32 *)((u8 *)(temp_19) + 0x2EC));
                if (temp_5 != -1) {
                    temp_4_8 = (temp_5 << 7) + &D_1A30B0;
                    if (((*(s32 *)((u8 *)(temp_4_8) + 0xDC)) == arg0) && ((*(u8 *)((u8 *)(temp_4_8) + 0xD0)) != 0)) {
                        func_003A4F28(temp_5, temp_5);
                    }
                }
                (*(s32 *)((u8 *)(temp_19) + 0x2EC)) = -1;
            }
            temp_f22_2 = (*(f32 *)((u8 *)(temp_19) + 0x2F4)) * 262500.0f;
            if (func_00382468(2) != 0) {
                func_L01_00443A18((void *)0x3F800000, 0xBF800000);
                temp_2_12 = func_L01_0046A610((f32 *) &sp90, &D_L20_001D66B0, 0xC, 6, 0x7C0030, second half of f64, temp_f22_2 * 6.0f, 0x43FA0000, 0x3F800000, 0, 0);
                if (temp_2_12 != NULL) {
                    (*(u8 *)((u8 *)(temp_2_12) + 2)) = (u8) (*(u8 *)((u8 *)(D_L20_002203C8) + 1));
                }
            }
            sp100 = (f32)(sp90) + func_L01_00443A18(NULL, 0x3D23D70A);
            sp104 = unksp94 + func_L01_00443A18(NULL, 0x3D23D70A);
            sp108 = unksp98 + func_L01_00443A18(NULL, 0x3D23D70A);
            if (func_00382468(2) != 0) {
                func_L01_00443A18((void *)0x3F800000, 0xBF800000);
                temp_2_13 = func_L01_0046A610(&sp100, &D_L20_001D66B0, 0xC, 0x7F, 0x7C0030, second half of f64, temp_f22_2 * 2.4f, 0x43FA0000, 0x3F800000, 0, 0);
                if (temp_2_13 != NULL) {
                    var_3_4 = 0x44;
                    if (func_00382468(2) != 0) {
                        var_3_4 = 0x48;
                    }
                    (*(s8 *)((u8 *)(temp_2_13) + 3)) = var_3_4;
                    (*(u8 *)((u8 *)(temp_2_13) + 2)) = (u8) (*(u8 *)((u8 *)(D_L20_002203C8) + 0));
                }
            }
            var_18 = 5;
            do {
                temp_f0_9 = (*(f32 *)((u8 *)(temp_19) + 0x2F4));
                func_00382580(&sp110, temp_f0_9 * 0.10000001f, temp_f0_9 * 0.14000002f);
                func_L01_00443A18((void *)0x40000000, 0x40A00000);
                temp_f12_3 = (*(f32 *)((u8 *)(temp_19) + 0x2F4));
                temp_2_14 = func_L01_004713C8(&sp90, &sp110, 0xC, 0, second half of f64, 0x7F, 0x7F, 6, func_003824E0((void *)0x3F4CCCCD, 0x3FA00000) * 210000.0f * temp_f12_3, temp_f12_3 * 2100.0f, 0x3BBF5D79);
                if (temp_2_14 != NULL) {
                    (*(s8 *)((u8 *)(temp_2_14) + 3)) = 0x44;
                    (*(u8 *)((u8 *)(temp_2_14) + 2)) = (u8) *(*(u8 **)((u8 *)(&D_L20_00220258) + 0xD4));
                }
                func_L01_00443A18(temp_2_14, 0x40000000, 0x40A00000);
                temp_f12_4 = (*(f32 *)((u8 *)(temp_19) + 0x2F4));
                temp_2_15 = func_L01_004713C8(&sp90, &sp110, 0xC, 0, second half of f64, 0x30, 0x30, 0, func_003824E0((void *)0x3F4CCCCD, 0x3FA00000) * 210000.0f * 3.0f * temp_f12_4, temp_f12_4 * 4200.0f, 0x3BBF5D79);
                var_18 -= 1;
                if (temp_2_15 != NULL) {
                    (*(s8 *)((u8 *)(temp_2_15) + 3)) = 0x44;
                    (*(u8 *)((u8 *)(temp_2_15) + 2)) = (u8) *(*(u8 **)((u8 *)(&D_L20_00220258) + 0xD4));
                }
            } while (var_18 >= 0);
            temp_4_9 = (*(s32 *)((u8 *)(temp_19) + 0x2E8));
            if ((temp_4_9 == -1) || (temp_4_10 = (temp_4_9 << 7) + &D_1A30B0, ((*(s32 *)((u8 *)(temp_4_10) + 0xDC)) != arg0)) || ((*(u8 *)((u8 *)(temp_4_10) + 0xD0)) == 0)) {
                (*(s32 *)((u8 *)(temp_19) + 0x2E8)) = func_003A52A0(1, 4, arg0);
            }
            if ((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 0x97U) {
                temp_5_2 = (*(s32 *)((u8 *)(temp_19) + 0x2EC));
                if (temp_5_2 != -1) {
                    temp_4_11 = (temp_5_2 << 7) + &D_1A30B0;
                    if (((*(s32 *)((u8 *)(temp_4_11) + 0xDC)) == arg0) && ((*(u8 *)((u8 *)(temp_4_11) + 0xD0)) != 0)) {
                        func_003A4F28(temp_5_2, temp_5_2);
                    }
                }
                temp_5_3 = (*(s32 *)((u8 *)(temp_19) + 0x2E8));
                (*(s32 *)((u8 *)(temp_19) + 0x2EC)) = -1;
                if (temp_5_3 != -1) {
                    temp_4_12 = (temp_5_3 << 7) + &D_1A30B0;
                    if (((*(s32 *)((u8 *)(temp_4_12) + 0xDC)) == arg0) && ((*(u8 *)((u8 *)(temp_4_12) + 0xD0)) != 0)) {
                        func_003A4F28(temp_5_3, temp_5_3);
                    }
                }
                (*(f32 *)((u8 *)(temp_19) + 0x2F8)) = 0.0f;
                (*(f32 *)((u8 *)(temp_19) + 0x2F4)) = 0.0f;
                (*(f32 *)((u8 *)(temp_19) + 0x2FC)) = 0.0f;
                (*(s32 *)((u8 *)(temp_19) + 0x2E8)) = -1;
                func_L20_003B2618(arg0, 0xC, 0, 8);
                func_L01_004450F0(arg0, 6, -1);
            }
            break;
        }
        func_L20_003B24F0(arg0);
        if ((u32) ((*(u8 *)((u8 *)(arg0) + 0x95)) - 4) >= 2U) {
            func_L01_00404808(&func_L20_003B2960, arg0);
        }
    }
}


#endif
