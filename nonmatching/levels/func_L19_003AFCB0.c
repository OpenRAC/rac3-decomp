/* func_L19_003AFCB0: Opus handoff (prep by Sonnet worker w7, 2026-11-08)
   Size: 6784 bytes, places: 1 levels (19), file: src/levels/19_thran_asteroid_belt/L19_003AFB40.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: one function (addiu sp,-0x90), 4 switches / 1 jump table (33 entries): +0x95, +0x20, +0x94 and a second +0x20 switch.
   Twin: none (rac2 index best func_L13_00406F18 at 0.27). Checked: callee fingerprint (callfp: 1 callee mapped); whole-corpus opcode search over every rac3 and rac2 function >= 600 B (best rac2:func_L11_00435600 0.27); names.tsv/NAMES.md (no entry); matched rac3 siblings in src/ (only the scaffold is shared).
   Mapping: Common enemy/boss scaffold (matches the tools' names): arg0 = moby; +0x20 = state byte (func_L01_004450F0 = moby_set_state(moby, state, sub)), +0x95 = phase byte, +0x68 = per-object data, func_L01_004561B8 = animation-done test, func_003C3A10 = moby_anim_blend(moby, anim, 0, 8), func_0038CB00 = timer_tick_short, D_1A4BE0 = hero/global struct (+0x25C0 hero moby, +0x25C4 hero state, +0xC08 pad bits). $gp loads are named D_<0x1DC8B0+offset> (D_LNN_ when >= 0x1D9900) in the draft. Own callees: func_L01_00446780 (takes an index into D_L19_001DF800-based table), func_L01_00448728.
   Identical / changed / added / removed: n/a (no twin).
   VU0: 6 vadd.xyz/vsub.xyz ops in the retail asm; inline-asm VU0 is banned since 2026-11-06 (Matching-Patterns), so this function cannot reach MATCH unless the ops come from plain C; the lq/sq copies are fine (u128_t).
   Draft: compiles (m2c draft cleaned by tools/post.py (real repo prototypes where known, m2c gotos kept)); 1644 diff; opcode-equal 1142 of 1697 (mine 1438), ratio 0.73.
     Retail rows yours=1438 retail=1697 equalrows=53.
   Left for Opus:
     1. Hand-fixed in d2: one `*((idx*4)+ptr)` that m2c printed as a deref of an int (line 511 of the draft); recheck.
     2. 33-entry jump table: the state switch has gaps; m2c split it into switch 2/4, see which cases share bodies.
     3. 6 VU0 ops (1DBFC8, 1DCB38.. in file offsets): near miss only.
*/
extern f32 func_0038CF38();
extern f32 func_0038D160(f32, f32);
extern int func_L01_004561B8(u8 *);
extern int func_L01_004561E0(void *a0);
extern s32 func_00382468();
extern s32 func_0038CB00(void *);
extern s32 func_003D3CB0();
extern s32 func_L01_00456250(void *);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003C2880(s32 p);
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C7C38();
extern void func_L01_00409598(u8 *, u8 *, u8 *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00456230(u8 *, s32);
extern void func_L01_00459188(u8 *, u8 *, u8 *);
extern void func_L01_0045BD78(u8 *a0, f32 a, f32 b, f32 c, f32 d);
extern void func_L01_0045C150(void *, void *, s32, s32);
extern void func_L01_004AA7E8(s32, s32);
extern void func_L03_004330B8(s32, s32);
f32 *func_00382348(void *);                         /* extern */
s32 func_L01_004395E0(void *);                  /* extern */
s32 func_L01_004450F0(void *, s32, s32);    /* extern */
s32 func_L01_00445170(void *, s32);         /* extern */
s32 func_L01_00446780();  /* K&R: prototype dropped, mismatch with m2c calls */
s32 func_L01_00448728(void *, void *, s32, f32, s32, s32, s32); /* extern */
s32 func_L01_00454370(void *, void *);              /* extern */
s32 func_L01_00458F78(void *, void *, s32, s32); /* extern */
s32 func_L01_0045A748(void *, void *);          /* extern */
s32 func_L01_0045BDE8(void *, s32);                 /* extern */
s32 func_L05_00355C48(void *);                      /* extern */
s32 func_L05_00356018(void *);                  /* extern */
s32 func_L19_003AFA68(void *, void *);              /* extern */
s32 func_L19_003AFA88(void *);                  /* extern */
s32 func_L19_003AFB40(void *, s32);         /* extern */
s32 func_L19_003B1A80(void *);                  /* extern */
s32 func_L19_003B1E08(void *);                      /* extern */
s32 func_L19_003B2190(void *);                  /* extern */
s32 func_L19_003B2290(void *, s32);             /* extern */
s32 func_L19_003B2370(void *);                  /* extern */
s32 func_L19_003B2538(void *);                      /* extern */
s32 func_L19_003B2748(void *);                  /* extern */
s32 func_L19_003B2880(void *);                      /* extern */
extern s32 D_L19_001DF34C;
extern s32 D_L19_001DF71C;
extern s32 D_L19_001DF758;
extern s32 D_L19_001DF800;
extern void *D_L19_001E8E58;
extern s32 D_L19_0021C260;
extern s32 D_L19_0021D500;



void func_L19_003AFCB0(void *arg0) {
    f32 sp10;
    f32 sp18;
    f32 sp20;
    s32 var_5_4;
    s32 var_5_9;
    s32 var_6;
    s32 var_7;
    s32 var_f0;
    f32 *temp_4;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    s16 temp_23;
    s16 temp_2_5;
    s16 var_17;
    s32 *temp_17;
    s32 *temp_17_2;
    s32 *temp_5_4;
    s32 temp_2_3;
    s32 temp_3_5;
    s32 temp_4_3;
    s32 temp_8;
    s32 var_5;
    s32 var_5_10;
    s32 var_5_2;
    s32 var_5_3;
    s32 var_5_5;
    s32 var_5_6;
    s32 var_5_7;
    u16 temp_2_4;
    u16 temp_3_6;
    u8 temp_16;
    u8 temp_2_2;
    u8 temp_3;
    u8 temp_3_2;
    u8 temp_3_3;
    u8 temp_3_4;
    u8 temp_3_7;
    u8 temp_5;
    u8 temp_5_2;
    u8 temp_5_3;
    u8 *temp_16_2;
    u8 *temp_16_3;
    u8 *temp_16_4;
    u8 *temp_16_5;
    u8 *temp_16_6;
    u8 *temp_16_7;
    u8 *temp_19;
    u8 *temp_20;
    u8 *temp_22;
    u8 *temp_2;
    u8 *temp_2_6;
    u8 *temp_4_2;
    u8 *var_16;
    u8 *var_5_8;

    temp_19 = (*(void **)((u8 *)(arg0) + 0x68));
    temp_2 = (*(void **)((u8 *)(temp_19) + 0x39C));
    if (temp_2 != 0) {
        (*(s32 *)((u8 *)(temp_2) + 0x98)) = 0;
        func_003C7C38();
    }
    if (func_L19_003B1E08(arg0) == 0) {
        temp_16 = (*(u8 *)((u8 *)(arg0) + 0x95));
        switch (temp_16) {                          /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            (*(s32 *)((u8 *)(temp_19) + 0x398)) = 1;
            if (((*(s16 *)((u8 *)(temp_19) + 0x234)) == 1) || ((func_L01_00456250(arg0) != 0) && (func_0038CB00(temp_19 + 0x3A0) != 0))) {
                temp_5 = (*(u8 *)((u8 *)(arg0) + 0x21));
                if (((s32) temp_5 < D_L19_001DF758) && (*((temp_5 * 4) + &D_L19_0021C260) != 0)) {
                    func_L03_004330B8(temp_5, 1);
                }
                temp_3 = (*(u8 *)((u8 *)(arg0) + 0x20));
                switch (temp_3) {                   /* switch 2; irregular */
                case 4:                             /* switch 2 */
                    var_5 = 8;
block_30:
                    func_L01_004450F0(arg0, var_5, 6);
                    break;
                case 5:                             /* switch 2 */
                    var_5 = 9;
                    goto block_30;
                default:                            /* switch 2 */
                    if ((*(s16 *)((u8 *)(temp_19) + 0x3A6)) != 0) {
                        var_5 = 3;
                        goto block_30;
                    }
                    var_5_2 = 0xC;
                    if ((*(s16 *)((u8 *)(temp_19) + 0x234)) != 1) {
block_59:
                        func_L01_004450F0(arg0, var_5_2, 1);
                    } else {
                    case 1:                         /* switch 3 */
block_66:
                        var_5_3 = 0xC;
block_67:
                        func_L01_004450F0(arg0, var_5_3, 2);
                    }
                    break;
                }
            }
            break;
        case 3:                                     /* switch 1 */
            (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 0;
            if (func_L01_004561E0(arg0) != 0) {
                func_L05_00356018(arg0);
                temp_5_2 = (*(u8 *)((u8 *)(arg0) + 0x21));
                if (((s32) temp_5_2 < D_L19_001DF758) && (*((temp_5_2 * 4) + &D_L19_0021C260) != 0)) {
                    func_L03_004330B8(temp_5_2, 1);
                }
                (*(s32 *)((u8 *)(arg0) + 0x48)) = 0x3F800000;
            }
            if (func_L01_00454370(arg0, temp_19 + 0x160) & 2) {
                if ((*(s16 *)((u8 *)(temp_19) + 0x234)) != 0) {
                    temp_3_2 = (*(u8 *)((u8 *)(arg0) + 0x94));
                    switch (temp_3_2) {             /* switch 3; irregular */
                    case 5:                         /* switch 3 */
                        var_5_3 = 9;
                        goto block_67;
                    case 4:                         /* switch 3 */
                        goto block_66;
                    default:                        /* switch 3 */
                        func_L01_004450F0(arg0, (*(s32 *)((u8 *)(temp_19) + 0x398)), 2);
                        break;
                    }
                } else {
                    var_5_2 = 6;
                    goto block_59;
                }
            }
            break;
        case 1:                                     /* switch 1 */
            func_L01_00456230(arg0, 0);
            if ((*(s16 *)((u8 *)(temp_19) + 0x234)) == temp_16) {
                temp_5_3 = (*(u8 *)((u8 *)(arg0) + 0x21));
                if (((s32) temp_5_3 < D_L19_001DF758) && (*((temp_5_3 * 4) + &D_L19_0021C260) != 0)) {
                    func_L03_004330B8(temp_5_3, 1);
                }
                goto block_66;
            }
            break;
        case 2:                                     /* switch 1 */
            func_L01_00456230(arg0, 0);
            func_L19_003B2370(arg0);
            temp_3_3 = (*(u8 *)((u8 *)(arg0) + 0x20));
            if ((*(s16 *)((u8 *)(temp_19) + 0x234)) == 0) {
                if (temp_3_3 == 0xC) {
                    func_L01_004450F0(arg0, 6, 1);
                } else if (func_L01_004561B8(arg0) == 0) {
                    func_L01_00445170(arg0, 1);
                    (*(s32 *)((u8 *)(temp_19) + 0x398)) = 6;
                }
            } else if ((temp_3_3 != 0x13) && (temp_3_3 != 0x19) && (func_0038CF38() <= 4.0f) && (fabsf(((*(f32 *)((u8 *)(arg0) + 0x18)) + 1.0f) - (*(f32 *)((u8 *)(temp_19) + 0x228))) <= 1.5f)) {
                func_L05_00356018(arg0);
                func_L01_004450F0(arg0, 0x13, -1);
            }
            if ((*(s32 *)((u8 *)(temp_19) + 0x370)) != 0) {
                func_L01_00448728(arg0 + 0xF8, temp_19 + 0x390, 0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))), 0x3BC94FE9, 0x3B494FE9, 0x3F00ADFD);
            }
            break;
        }
        if (!((*(f32 *)((u8 *)(temp_19) + 0x30)) <= 0.0f)) {
            temp_2_2 = (*(u8 *)((u8 *)(arg0) + 0x20));
            switch (temp_2_2) {                     /* switch 4 */
            case 1:                                 /* switch 4 */
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    if ((*(s16 *)((u8 *)(temp_19) + 0x3A6)) != 0) {
                        (*(s32 *)((u8 *)(arg0) + 0x98)) = 0;
                        (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x41) & 0xEFFF);
                        func_L01_004AA7E8(arg0, 1);
                    }
                    func_003C3A10(arg0, 0, 0, 8);
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    if (func_00382468() == 0) {
                        var_5_4 = 1;
                    } else {
                        var_5_4 = 0;
                    }
                    func_003C3A10(arg0, var_5_4, 0, 0);
                }
                break;
            case 2:                                 /* switch 4 */
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 0;
                temp_16_2 = D_L19_001DF71C + ((*(s32 *)((u8 *)(temp_19) + 0x37C)) << 8);
                temp_4 = func_00382348(temp_16_2);
                if ((temp_16_2 == 0) || (temp_3_4 = (*(u8 *)((u8 *)(temp_16_2) + 0x20)), (temp_3_4 == 0xFE)) || (temp_3_4 == 0xFD) || ((temp_4 != 0) && (*temp_4 <= 0.0f)) || (((*(s16 *)((u8 *)(temp_16_2) + 0xAA)) == 0x1AB8) && ((*(u8 *)((u8 *)(temp_16_2) + 0x95)) == 5))) {
                    temp_3_5 = (*(s32 *)((u8 *)(temp_19) + 0x388)) - 1;
                    (*(s32 *)((u8 *)(temp_19) + 0x388)) = temp_3_5;
                    (*(f32 *)((u8 *)(temp_19) + 0x340)) = (f32) (*(f32 *)((u8 *)((((*(s32 *)((u8 *)(temp_19) + 0x37C)) << 8) + D_L19_001DF71C)) + 0x10));
                    if (temp_3_5 == 0) {
                        (*(s32 *)((u8 *)(temp_19) + 0x37C)) = -1;
                        func_L01_004450F0(arg0, 1, 0);
                        func_L01_00456230(arg0, 1);
                        func_L01_00409598(arg0, arg0 + 0x10, arg0 + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                    }
                }
                break;
            case 3:                                 /* switch 4 */
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 0;
                temp_2_3 = (*(s32 *)((u8 *)(temp_19) + 0x388)) - 1;
                (*(s32 *)((u8 *)(temp_19) + 0x388)) = temp_2_3;
                if (temp_2_3 == 0) {
                    if ((*(s16 *)((u8 *)(temp_19) + 0x234)) == 1) {
                        func_L01_004450F0(arg0, 0xC, 2);
                    } else {
                        func_L01_004450F0(arg0, 6, 1);
                    }
                    func_L01_00456230(arg0, 1);
                    func_L01_00409598(arg0, arg0 + 0x10, arg0 + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                    (*(s16 *)((u8 *)(temp_19) + 0x3A6)) = 0;
                }
                break;
            case 4:                                 /* switch 4 */
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    func_003C3A10(arg0, 2, 0, 0x19);
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    if ((*(s16 *)((u8 *)(temp_19) + 0x37A)) != 0) {
                        if ((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 0x191U) {
                            if (func_00382468() != 0) {
                                if ((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 0x3E9U) {
                                    goto block_106;
                                }
                                goto block_108;
                            }
block_106:
                            func_003C3A10(arg0, 1, 0, 0x11);
                            (*(u16 *)((u8 *)(arg0) + 0x96)) = 0U;
                        } else {
                            goto block_108;
                        }
                    } else {
block_108:
                        func_003C3A10(arg0, 2, 0, 0x19);
                    }
                }
                break;
            case 5:                                 /* switch 4 */
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 0;
                (*(f32 *)((u8 *)(temp_19) + 0x1B8)) = 2.0f;
                (*(s32 *)((u8 *)(arg0) + 0x98)) = 0;
                (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x34)) & 0xEFFF);
                if (func_L01_004561B8(arg0) != 0) {
                    func_003C3A10(arg0, 3, 0, 0);
                    (*(f32 *)((u8 *)(temp_19) + 0x340)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x10));
                    (*(f32 *)((u8 *)(temp_19) + 0x34C)) = 0.0f;
                    (*(s32 *)((u8 *)(arg0) + 0x48)) = 0;
                    (*(f32 *)((u8 *)(arg0) + 0x18)) = (f32) ((*(f32 *)((u8 *)(arg0) + 0x18)) - 4.0f);
                }
                break;
            case 6:                                 /* switch 4 */
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    (*(u16 *)((u8 *)(temp_19) + 0x394)) = 0x3E8U;
                    func_003C3A10(arg0, 1, 0, 8);
                }
                temp_2_4 = (*(u16 *)((u8 *)(temp_19) + 0x394)) - 1;
                (*(u16 *)((u8 *)(temp_19) + 0x394)) = temp_2_4;
                if ((temp_2_4 << 0x10) == 0) {
                    if ((*(s16 *)((u8 *)(temp_19) + 0x3AA)) != 0) {
                        var_5_5 = 4;
                    } else {
                        var_5_5 = 1;
                    }
                    func_L01_004450F0(arg0, var_5_5, 0);
                }
                break;
            case 8:                                 /* switch 4 */
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 0;
                if ((func_L01_004561B8(arg0) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x42)) == 2)) {
                    func_003C3A10(arg0, 3, 0, 0);
                    (*(s32 *)((u8 *)(arg0) + 0x48)) = 0x3F400000;
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    var_5_6 = 0xC;
                    var_6 = 2;
block_197:
                    func_L01_004450F0(arg0, var_5_6, var_6);
                    (*(s32 *)((u8 *)(arg0) + 0x48)) = 0x3F800000;
                }
                break;
            case 9:                                 /* switch 4 */
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    temp_4_2 = (*(void **)((u8 *)(arg0) + 0x24));
                    temp_3_6 = (*(u16 *)((u8 *)(arg0) + 0x34)) & 0xFFBE;
                    (*(u16 *)((u8 *)(arg0) + 0x34)) = temp_3_6;
                    (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (temp_3_6 | ((*(u16 *)((u8 *)(temp_4_2) + 0x44)) & 0x1000));
                    (*(s32 *)((u8 *)(arg0) + 0x48)) = 0x3F800000;
                    (*(s32 *)((u8 *)(arg0) + 0x98)) = (s32) (*(s32 *)((u8 *)(temp_4_2) + 0x10));
                    (*(f32 *)((u8 *)(temp_19) + 0x34C)) = 0.0f;
                }
                temp_f1 = (*(f32 *)((u8 *)(temp_19) + 0x34C)) + 0.02f;
                (*(f32 *)((u8 *)(temp_19) + 0x34C)) = temp_f1;
                (*(f32 *)((u8 *)(arg0) + 0x18)) = (f32) (((*(f32 *)((u8 *)(temp_19) + 0x348)) - 4.0f) + (temp_f1 * temp_f1 * 18.3f));
                if ((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 0x16U) {
                    func_L01_004450F0(arg0, 0xA, -1);
                    (*(f32 *)((u8 *)(temp_19) + 0x34C)) = 0.0f;
                }
                break;
            case 10:                                /* switch 4 */
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    temp_8 = (*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x24))) + 0x10));
                    (*(s32 *)((u8 *)(arg0) + 0x98)) = temp_8;
                    (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x1000);
                    func_003C3A10(arg0, 4, 0, 8);
                }
                temp_f20 = (*(f32 *)((u8 *)(temp_19) + 0x34C)) + 0.02f;
                (*(f32 *)((u8 *)(temp_19) + 0x34C)) = temp_f20;
                func_0038CE20(&sp10, arg0 + 0xC0, temp_f20 * 0.0f);
                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                (*(f32 *)((u8 *)(arg0) + 0x10)) = sp10;
                temp_f0 = (*(f32 *)((u8 *)(arg0) + 0x18)) + ((sp10 - (temp_f20 * (*(f32 *)((u8 *)(temp_19) + 0x340)))) * temp_f20);
                (*(f32 *)((u8 *)(arg0) + 0x18)) = temp_f0;
                temp_f1_2 = (*(f32 *)((u8 *)(temp_19) + 0x348));
                if (temp_f0 <= temp_f1_2) {
                    (*(f32 *)((u8 *)(arg0) + 0x18)) = temp_f1_2;
                    var_5_7 = 0xB;
block_272:
                    func_L01_004450F0(arg0, var_5_7, -1);
                }
                break;
            case 11:                                /* switch 4 */
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    (*(f32 *)((u8 *)(temp_19) + 0x1B8)) = 1.0f;
                    func_003C3A10(arg0, 5, 0, 0);
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    func_L01_004450F0(arg0, 0xC, 2);
                }
                break;
            case 12:                                /* switch 4 */
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 0;
                if ((*(s32 *)((u8 *)(temp_19) + 0x364)) != -1) {
                    var_5_7 = 0xD;
                    goto block_272;
                }
block_142:
                func_L19_003B2190(arg0);
                break;
            case 13:                                /* switch 4 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_19) + 0x398)) = 0xD;
                    func_003C3A10(arg0, 0, 0, 0xC);
                    if ((*(s16 *)((u8 *)(temp_19) + 0x378)) != 0) {
                        temp_5_4 = *(((*(s32 *)((u8 *)(temp_19) + 0x364)) * 4) + &D_L19_0021D500);
                        func_L01_0045C150(arg0, temp_5_4, *temp_5_4 - 1, 0);
                        (*(s16 *)((u8 *)(temp_19) + 0x378)) = 0;
                    }
                }
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 1;
                if (func_L01_0045BDE8(arg0, (*(s32 *)((u8 *)(temp_19) + 0x364))) != 0) {
                    (*(s16 *)((u8 *)(temp_19) + 0x378)) = 1;
                    (*(s32 *)((u8 *)(temp_19) + 0x364)) = -1;
                    goto block_142;
                }
                break;
            case 16:                                /* switch 4 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_19) + 0x398)) = 0x10;
                    func_003C3A10(arg0, 0, 0, 0xC);
                    if ((*(s16 *)((u8 *)(temp_19) + 0x378)) != 0) {
                        temp_16_3 = arg0 + 0x10;
                        temp_17 = *(((*(s32 *)((u8 *)(temp_19) + 0x360)) * 4) + &D_L19_0021D500);
                        temp_f20_2 = func_0038CF38();
                        if (func_0038CF38() < temp_f20_2) {
                            func_L01_0045C150(arg0, temp_17, 0, *temp_17 - 1);
                        } else {
                            func_L01_0045C150(arg0, temp_17, *temp_17 - 1, 0);
                        }
                    }
                    (*(s16 *)((u8 *)(temp_19) + 0x378)) = 0;
                }
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 1;
                if (func_L01_0045BDE8(arg0, (*(s32 *)((u8 *)(temp_19) + 0x360))) != 0) {
                    func_L01_004450F0(arg0, 0xF, -1);
                    (*(s16 *)((u8 *)(temp_19) + 0x378)) = 1;
                }
                break;
            case 15:                                /* switch 4 */
                if (func_L19_003AFA68(arg0, temp_19) != 0) {
                    func_L19_003AFA88(arg0);
                    var_5_7 = 0xE;
                    goto block_272;
                }
                if (func_L01_004561B8(arg0) != 0) {
                    func_003C3A10(arg0, 6, 0, 8);
                }
                func_L01_00448728(arg0 + 0xF8, temp_19 + 0x390, 0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))), 0x3CA4B5BF, 0x3BC94FE9, 0x3F00ADFD);
                break;
            case 14:                                /* switch 4 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_19) + 0x398)) = 0xE;
                    func_003C3A10(arg0, 0, 0, 0xC);
                    if ((*(s16 *)((u8 *)(temp_19) + 0x378)) != 0) {
                        temp_16_4 = arg0 + 0x10;
                        temp_17_2 = *(((*(s32 *)((u8 *)(temp_19) + 0x360)) * 4) + &D_L19_0021D500);
                        temp_f20_3 = func_0038CF38();
                        if (func_0038CF38() < temp_f20_3) {
                            func_L01_0045C150(arg0, temp_17_2, 0, *temp_17_2 - 1);
                        } else {
                            func_L01_0045C150(arg0, temp_17_2, *temp_17_2 - 1, 0);
                        }
                    }
                    (*(s16 *)((u8 *)(temp_19) + 0x378)) = 0;
                }
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 1;
                if (func_L01_0045BDE8(arg0, (*(s32 *)((u8 *)(temp_19) + 0x360))) != 0) {
                    if ((*(s16 *)((u8 *)(temp_19) + 0x3AC)) != 0) {
                        (*(s32 *)((u8 *)(temp_19) + 0x398)) = 0x10;
                    }
                    (*(s16 *)((u8 *)(temp_19) + 0x378)) = 1;
                    var_5_7 = 0x14;
                    goto block_272;
                }
                break;
            case 17:                                /* switch 4 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_19) + 0x398)) = 0x11;
                    func_003C3A10(arg0, 0, 0, 0xC);
                }
                temp_16_5 = temp_19 + 0x340;
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 0;
                if (func_0038CF38() < 1.0f) {
                    var_5_7 = 0x14;
                    goto block_272;
                }
                var_5_8 = temp_16_5;
block_182:
                func_L01_0045A748(arg0, var_5_8);
                break;
            case 18:                                /* switch 4 */
                temp_22 = temp_19 + 0x340;
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_19) + 0x398)) = 0x12;
                    func_003C3A10(arg0, 0, 0, 0xC);
                    if ((*(u8 *)((u8 *)(arg0) + 0x94)) != 0x1D) {
                        var_17 = 0;
                        (*(f32 *)((u8 *)(temp_19) + 0x340)) = (f32) (*(f32 *)((u8 *)(temp_19) + 0x220));
                        temp_4_3 = D_L19_001DF34C;
                        temp_23 = (*(s16 *)((u8 *)(temp_19) + 0x380));
                        if ((*(s16 *)((u8 *)((temp_4_3 + ((*(s32 *)((u8 *)(temp_19) + 0x36C)) * 0x30))) + 0x32)) > 0) {
                            temp_20 = temp_19 + 0x220;
                            do {
                                if (var_17 != temp_23) {
                                    temp_16_6 = D_L19_001DF800 + ((*(s32 *)((*(s32 *)((u8 *)((((*(s32 *)((u8 *)(temp_19) + 0x36C)) * 0x30) + temp_4_3)) + 0x40)) + var_17 * 4)) << 7);
                                    temp_f20_4 = func_0038CF38();
                                    if (func_0038CF38() < temp_f20_4) {
                                        (*(s16 *)((u8 *)(temp_19) + 0x380)) = var_17;
                                        (*(f32 *)((u8 *)(temp_19) + 0x340)) = (f32) (*(f32 *)((u8 *)(temp_16_6) + 0x30));
                                    }
                                }
                                var_17 += 1;
                            } while (var_17 < (*(s16 *)((u8 *)((D_L19_001DF34C + ((*(s32 *)((u8 *)(temp_19) + 0x36C)) * 0x30))) + 0x32)));
                        }
                    }
                }
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 1;
                if (func_0038CF38() < 1.0f) {
                    var_5_7 = 0x14;
                    goto block_272;
                }
                var_5_8 = temp_22;
                goto block_182;
            case 20:                                /* switch 4 */
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s16 *)((u8 *)(temp_19) + 0x396)) = 0;
                    func_003C3A10(arg0, 8, 0, 8);
                }
                if (((*(u8 *)((u8 *)(arg0) + 0x43)) == 8) && (func_L05_00355C48(arg0) == 0)) {
                    func_003C3A10(arg0, 6, 0, 8);
                }
                func_L01_00448728(arg0 + 0xF8, temp_19 + 0x390, 0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))), 0x3CA4B5BF, 0x3BC94FE9, 0x3F00ADFD);
                if ((func_L19_003AFA68(arg0, temp_19) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                    func_L19_003AFA88(arg0);
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) == 6) {
                        var_5_7 = 0x16;
                    } else {
                        var_5_7 = 0x17;
                    }
                    goto block_272;
                }
                break;
            case 22:                                /* switch 4 */
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    func_003C3A10(arg0, 8, 0, 8);
                    (*(s32 *)((u8 *)(arg0) + 0x48)) = 0x41200000;
                }
                func_L01_00448728(arg0 + 0xF8, temp_19 + 0x390, 0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))), 0x3CA4B5BF, 0x3BC94FE9, 0x3F00ADFD);
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    var_5_6 = 0x17;
                    var_6 = -1;
                    goto block_197;
                }
                break;
            case 26:                                /* switch 4 */
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_19) + 0x38C)) = (s32) (*(s32 *)((u8 *)(temp_19) + 0x384));
                    func_003C3A10(arg0, 0xA, 0, 0);
                    (*(s32 *)((u8 *)(arg0) + 0x48)) = 0x3F800000;
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    var_5_7 = 0x18;
                    goto block_272;
                }
                break;
            case 23:                                /* switch 4 */
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    if (func_L19_003B2880(arg0) == 0) {
                        func_L05_00356018(arg0);
                        (*(s32 *)((u8 *)(temp_19) + 0x38C)) = (s32) (*(s32 *)((u8 *)(temp_19) + 0x384));
                        func_L01_004450F0(arg0, 0x18, -1);
                    }
                    if ((*(s16 *)((u8 *)(temp_19) + 0x396)) == 0) {
                        func_L19_003AFB40(arg0, 1);
                    }
                    temp_2_5 = (u16) (*(s16 *)((u8 *)(temp_19) + 0x396)) + 1;
                    (*(s16 *)((u8 *)(temp_19) + 0x396)) = temp_2_5;
                    if (temp_2_5 >= 4) {
                        var_5_9 = 8;
                        var_7 = 8;
                    } else {
                        var_5_9 = 9;
                        var_7 = 0;
                    }
                    func_003C3A10(arg0, var_5_9, 0, var_7);
                    (*(s32 *)((u8 *)(arg0) + 0x48)) = 0x40000000;
                }
                temp_2_6 = *(void **)0x1A73E8;
                if ((temp_2_6 != 0) && ((*(s32 *)((u8 *)(temp_2_6) + 0xB8)) != temp_2_6) && (4 != 0)) {
                    func_L01_004450F0(arg0, 0x1B, -1);
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x20)) != 0x1B) {
                    func_L01_00448728(arg0 + 0xF8, temp_19 + 0x390, 0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))), 0x3BC94FE9, 0x3B494FE9, 0x3F00ADFD);
                    if ((*(s16 *)((u8 *)(temp_19) + 0x396)) >= 4) {
                        goto block_223;
                    }
                    if (func_L19_003B2538(arg0) != 0) {
block_223:
                        if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                            if ((*(s16 *)((u8 *)(temp_19) + 0x396)) >= 4) {
                                var_5_7 = 0x1A;
                            } else {
                                var_5_7 = 0x17;
                            }
                            goto block_272;
                        }
                    } else {
                        (*(s16 *)((u8 *)(temp_19) + 0x396)) = 4;
                        var_5_7 = 0x17;
                        goto block_272;
                    }
                }
                break;
            case 27:                                /* switch 4 */
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_19) + 0x38C)) = (s32) (*(s32 *)((u8 *)(temp_19) + 0x384));
                    (*(s32 *)((u8 *)(arg0) + 0x48)) = 0x3F800000;
                    func_003C3A10(arg0, 0xB, 0, 0);
                    func_L19_003AFB40(arg0, 2);
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    var_5_7 = 0x18;
                    goto block_272;
                }
                break;
            case 24:                                /* switch 4 */
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 0;
                func_L05_00356018(arg0);
                (*(s32 *)((u8 *)(arg0) + 0x48)) = 0x3F800000;
                func_L01_004450F0(arg0, (*(s32 *)((u8 *)(temp_19) + 0x398)), -1);
                break;
            case 19:                                /* switch 4 */
                temp_16_7 = temp_19 + 0x240;
                if (func_L01_004561B8(arg0) != 0) {
                    func_003C3A10(arg0, 0, 0, 0xC);
                    func_L01_00459188(arg0, (*(s32 *)((u8 *)(temp_19) + 0x230)), temp_16_7);
                }
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 1;
                func_L01_00458F78(arg0, temp_16_7, 0, 0);
                func_L01_0045A748(arg0, temp_16_7);
                if ((func_0038CF38() <= 4.0f) && (fabsf(((*(f32 *)((u8 *)(arg0) + 0x18)) + 1.0f) - (*(f32 *)((u8 *)(temp_19) + 0x228))) <= 1.5f)) {
                    var_5_7 = 0x19;
                    goto block_272;
                }
                break;
            case 25:                                /* switch 4 */
                (*(s16 *)((u8 *)(temp_19) + 0x3AE)) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    func_003C3A10(arg0, 7, 0, 8);
                    func_L19_003AFB40(arg0, 1);
                }
                func_L01_00448728(arg0 + 0xF8, temp_19 + 0x390, 0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))), 0x3BC94FE9, 0x3B494FE9, 0x3F00ADFD);
                func_L01_004395E0(arg0);
                temp_f1_3 = (f32) (0 /* second half of f64 */);
                if ((temp_f1_3 >= 13.0f) && (temp_f1_3 <= 15.0f)) {
                    func_003C2F58(arg0, 3, &sp10);
                    0 /* unknown instruction: vsub.xyz $vf2, $vf2, $vf1 */;
                    func_0038CE20(&sp10, &sp10, 0.6f);
                    0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                    sp10 = 0.3f;
                    sp18 += 0.3f;
                    func_L01_00446780(arg0, &sp10, ((*(u8 *)((u8 *)(temp_19) + 0x5F)) == 0) ? 1 : 0x10001, 0, 1, 0, 1, 1.4f, (f32) (*(u8 *)((u8 *)(temp_19) + 0x45)), 0x4019999A);
                }
                if (*(s32 *)0x1A73E8 == arg0) {
                    func_L19_003AFB40(arg0, 2);
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    var_5_7 = (*(s32 *)((u8 *)(temp_19) + 0x398));
                    goto block_272;
                }
                break;
            case 30:                                /* switch 4 */
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_0045BD78(arg0, 0.0120000001f, 0.0300000012f, 0.00013962634f, 0.100530975f);
                    func_003C3A10(arg0, 0xE, 0, 8);
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    func_003C3A10(arg0, 0xF, 0, 0xA7);
                    var_f0 = 0x42C80000;
                    var_5_10 = 0x1F;
block_258:
                    (*(s32 *)((u8 *)(arg0) + 0x48)) = var_f0;
                    func_L01_004450F0(arg0, var_5_10, -1);
                }
                break;
            case 31:                                /* switch 4 */
                if ((func_L01_004561B8(arg0) != 0) && ((u32) ((*(u8 *)((u8 *)(arg0) + 0x42)) - 0xE) >= 2U)) {
                    temp_3_7 = (*(u8 *)((u8 *)(arg0) + 0x43));
                    if ((temp_3_7 != 0xF) && (temp_3_7 != 0xE)) {
                        func_003C3A10(arg0, 0xF, 0, 8);
                        (*(s32 *)((u8 *)(arg0) + 0x48)) = 0x40000000;
                    }
                }
                if (((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) && ((*(s16 *)((u8 *)(temp_19) + 0x234)) == 1)) {
                    var_f0 = 0x3F800000;
                    var_5_10 = 0x20;
                    goto block_258;
                }
                break;
            case 32:                                /* switch 4 */
                if (func_L01_004561B8(arg0) != 0) {
                    func_003C3A10(arg0, 0x10, 0, 8);
                    func_L01_00459188(arg0, (*(s32 *)((u8 *)(temp_19) + 0x230)), temp_19 + 0x240);
                }
                if ((*(s16 *)((u8 *)(temp_19) + 0x234)) == 0) {
                    func_003C3A10(arg0, 0xF, 0, 8);
                    func_L01_004450F0(arg0, 0x1F, -1);
                }
                sp10 = (*(f32 *)((u8 *)(arg0) + 0x10));
                sp18 += 0.1f;
                func_0038CE20(&sp20, arg0 + 0xC0, 1.0f);
                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                if (func_003D3CB0() != 0) {
                    var_16 = temp_19 + 0x220;
                    if ((D_L19_001E8E58 != 0) && ((*(s16 *)((u8 *)(D_L19_001E8E58) + 0xAA)) == 0x1D61)) {
                        (*(f32 *)((u8 *)(arg0) + 0x18)) = (f32) ((*(f32 *)((u8 *)(arg0) + 0x18)) + 0.020000001f);
                        goto block_267;
                    }
                } else {
block_267:
                    var_16 = temp_19 + 0x220;
                }
                func_L01_0045A748(arg0, var_16);
                if ((func_0038CF38() <= 2.8f) && (fabsf(((*(f32 *)((u8 *)(arg0) + 0x18)) + 1.0f) - (*(f32 *)((u8 *)(temp_19) + 0x228))) <= 1.5f) && (func_L19_003B2290(arg0, 0x3E4CCCCD) != 0)) {
                    var_5_7 = 0x21;
                    goto block_272;
                }
                break;
            case 33:                                /* switch 4 */
                if (func_L01_004561B8(arg0) != 0) {
                    func_L19_003AFB40(arg0, 1);
                    func_003C3A10(arg0, 0x11, 0, 8);
                }
                func_L01_00448728(arg0 + 0xF8, temp_19 + 0x390, 0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))), 0x3BC94FE9, 0x3B494FE9, 0x3F00ADFD);
                func_L01_004395E0(arg0);
                temp_f1_4 = (f32) (0 /* second half of f64 */);
                if ((temp_f1_4 >= 9.0f) && (temp_f1_4 <= 13.0f)) {
                    func_003C2F58(arg0, 2, &sp10);
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                    sp20 = sp10;
                    func_0038CE20(&sp20, &sp20, 0.7f);
                    0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                    sp10 = sp20;
                    func_L01_00446780(arg0, &sp10, 1, 0, 1, 0, 0x3F4CCCCD, (f32) (*(u8 *)((u8 *)(temp_19) + 0x45)), 2.4f);
                }
                if (*(s32 *)0x1A73E8 == arg0) {
                    func_L19_003AFB40(arg0, 2);
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    func_L01_004450F0(arg0, 0x1F, -1);
                }
                break;
            }
            func_L19_003B1A80(arg0);
        } else {
            func_L19_003B2748(arg0);
            func_003C2880(arg0);
        }
    }
}
