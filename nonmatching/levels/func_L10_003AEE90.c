/* func_L10_003AEE90: Opus handoff (prep by Sonnet worker w7, 2026-11-08)
   Size: 6388 bytes, places: 4 levels (10 19 23 27), file: src/levels/shared/L10_003AEE90.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: one function (addiu sp,-0x100), 1 switch / 1 jump table (10 entries) on +0x20; 4 places (10, 19, 23, 27).
   Twin: none (rac2 index best func_L18_003F5650 at 0.27). Checked: callee fingerprint (callfp: 0 callees mapped); whole-corpus opcode search over every rac3 and rac2 function >= 600 B (best rac3:func_L01_003AF290 0.21); names.tsv/NAMES.md (no entry); matched rac3 siblings in src/ (only the scaffold is shared).
   Mapping: Common enemy/boss scaffold (matches the tools' names): arg0 = moby; +0x20 = state byte (func_L01_004450F0 = moby_set_state(moby, state, sub)), +0x95 = phase byte, +0x68 = per-object data, func_L01_004561B8 = animation-done test, func_003C3A10 = moby_anim_blend(moby, anim, 0, 8), func_0038CB00 = timer_tick_short, D_1A4BE0 = hero/global struct (+0x25C0 hero moby, +0x25C4 hero state, +0xC08 pad bits). $gp loads are named D_<0x1DC8B0+offset> (D_LNN_ when >= 0x1D9900) in the draft. Own callees: func_L01_0045A748/A7A8/AA10/AA30/BD10/BD78 (helpers, purpose not identified), func_L01_0040E570, func_L01_004395E0.
   Identical / changed / added / removed: n/a (no twin). The four places should be checked with chkall.sh; draft is checked at level 10 only.
   VU0: 9 vadd.xyz/vsub.xyz ops in the retail asm; inline-asm VU0 is banned since 2026-11-06 (Matching-Patterns), so this function cannot reach MATCH unless the ops come from plain C; the lq/sq copies are fine (u128_t).
   Draft: compiles (m2c draft cleaned by tools/post.py (real repo prototypes where known, m2c gotos kept)); 1561 diff; opcode-equal 973 of 1598 (mine 1358), ratio 0.66.
     Retail rows yours=1358 retail=1598 equalrows=37.
   Left for Opus:
     1. Several m2c calls pass a pointer where retail passes f32 bits (func_L01_0045BD78(arg0, x, y, c, d)); the draft reinterprets with *(f32 *)&p. Re-derive the real types from the callee's matched prototype.
     2. Frame is 0x100 in retail and mine; opcode ratio 0.66 so the bulk of the structure is right; work through the first diverging rows.
     3. Check all 4 places (10, 19, 23, 27) with chkall.sh once it is near.
*/
extern f32 func_003824E0(f32, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF38();
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_L01_0040E570(void *, void *);
extern int func_L01_004561B8(u8 *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_00382498(s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_003D3CB0();
extern s32 func_L01_0044C108(void *a);
extern s32 func_L01_0045A9F0(void *);
extern s32 func_L01_0045BD10(u8 *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C2880(s32 p);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0045AA10(u8 *);
extern void func_L01_0045BD78(u8 *a0, f32 a, f32 b, f32 c, f32 d);
f32 func_L01_004395E0();  /* extern, call arities [1, 2], m2c proto was (void *, f32 *) */
s32 func_L01_004450F0();  /* extern, call arities [3, 4], m2c proto was (void *, s32, s32, f32) */
s32 func_L01_0044FD88(void *, void *, s32, s32); /* extern */
s32 func_L01_00454370(void *, void *);              /* extern */
s32 func_L01_0045A748(void *, f32 *);           /* extern */
s32 func_L01_0045AA30(void *, f32 *);           /* extern */
s32 func_L10_003A7160(void *);                  /* extern */
s32 func_L10_003B0788(void *);                  /* extern */
s32 func_L10_003B0B50(void *);                  /* extern */
s32 func_L10_003B0F78();  /* extern, call arities [2, 3], m2c proto was (void *, void *, s32) */
s32 func_L10_003B10C8(void *, s32, f32 *, void *, void *, s32); /* extern */
extern s32 D_1A4BE0;
extern f32 D_1A4C60;
extern s32 D_L10_001DBDD4;
extern s32 D_L10_001DEE40;
extern s32 D_L10_001DF29C;
extern s32 D_L10_001DF2D8;
extern s32 D_L10_001E8918;
extern s32 D_L10_0021BF20;
extern s32 D_L10_0021D1C0;

extern s32 D_L10_001DE584;
extern s32 D_L10_001DF2D8;

void func_L10_003AEE90(void *arg0) {
    s32 sp[8]; /* m2c: stack-slot base, size unknown */
    f32 sp34; /* m2c stack slot */
    f32 sp0;
    f32 sp4;
    f32 sp8;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp20;
    f32 sp24;
    f32 sp28;
    f32 sp30;
    f32 sp38;
    f32 *sp40;
    f32 *sp44;
    s32 sp50;
    s32 sp60;
    s32 *sp70;
    s32 sp80;
    s32 *var_9;
    s32 var_5_2;
    s32 var_5_4;
    s32 var_6;
    f32 *temp_17;
    f32 *temp_2_2;
    f32 *temp_2_7;
    f32 *temp_3_4;
    f32 *var_16;
    f32 *var_2_4;
    f32 *var_2_5;
    f32 temp_5_7;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f12;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f21;
    f32 temp_f2;
    f32 temp_f3;
    f32 var_f0;
    f32 var_f20;
    s32 *temp_16_2;
    s32 *temp_19;
    s32 temp_17_4;
    s32 temp_23;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_4_3;
    s32 temp_5;
    s32 temp_5_2;
    s32 temp_5_5;
    s32 temp_6;
    s32 temp_6_2;
    s32 temp_7;
    s32 temp_cond;
    s32 var_10;
    s32 var_19;
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_2_6;
    s32 var_3;
    s32 var_5;
    s32 var_5_3;
    s32 var_7;
    s32 var_8;
    u8 temp_2;
    u8 temp_2_4;
    u8 *temp_16;
    u8 *temp_17_2;
    u8 *temp_17_3;
    u8 *temp_20;
    u8 *temp_2_3;
    u8 *temp_3;
    u8 *temp_4;
    u8 *temp_4_2;
    u8 *temp_4_4;
    u8 *temp_5_3;
    u8 *temp_5_4;
    u8 *temp_5_6;
    u8 *temp_5_8;
    u8 *var_16_2;
    u8 *var_16_3;
    u8 *var_19_2;
    u8 *var_19_3;

    if (func_L01_0044C108(arg0 + 0x10) != 0) {
        temp_20 = (*(void **)((u8 *)(arg0) + 0x68));
        func_L10_003B0788(arg0);
        temp_2 = (*(u8 *)((u8 *)(arg0) + 0x20));
        switch (temp_2) {
        case 1:
            if (func_L01_004561B8(arg0) != 0) {
                func_003C3A10(arg0, ((*(s32 *)((u8 *)(temp_20) + 0x4EC)) == 0) ? 8 : 7, 0, 8);
                func_003824E0(5.0f, 15.0f);
                (*(s32 *)((u8 *)(temp_20) + 0x3B0)) = 0x42480000;
            }
            if (func_0038CAD0(temp_20 + 0x3B0) != 0) {
                if (func_00382498(0, 8) == 0) {
                    var_5 = 6;
                    var_2 = 0xA;
                } else {
                    var_5 = 4;
                    var_2 = 9;
                }
                temp_5 = ((*(s32 *)((u8 *)(temp_20) + 0x4EC)) != 0) ? var_2 : var_5;
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != temp_5) {
                    func_003C3A10(arg0, temp_5, 0, 8);
                }
                func_003824E0(5.0f, 15.0f);
                (*(s32 *)((u8 *)(temp_20) + 0x3B0)) = 0x42480000;
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                func_003C3A10(arg0, ((*(s32 *)((u8 *)(temp_20) + 0x4EC)) == 0) ? 8 : 7, 0, 8);
            }
            func_L01_0045A9F0(arg0);
            if (((s32) D_L10_001DEE40 % 30) == 0) {
                temp_f1 = (*(f32 *)((u8 *)(temp_20) + 0x4E0));
                temp_2_2 = &D_1A4C60 - 0x80;
                if (func_L01_0040E570(&D_1A4C60, arg0 + 0x10) < (temp_f1 * temp_f1)) {
                    (*(void **)((u8 *)(temp_20) + 0x3BC)) = (void *) (*(void **)((u8 *)(temp_2_2) + 0x25C0));
                    (*(f32 *)((u8 *)(temp_20) + 0x4F8)) = func_0038D160((*(f32 *)((u8 *)(temp_2_2) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_2_2) + 0x84)) - (*(f32 *)((u8 *)(arg0) + 0x14)));
                    D_L10_001DBDD4 = 1;
                    D_L10_001DE584 = (s32) (D_L10_001DE584 + 1);
                    var_5_2 = 2;
                    var_6 = -1;
block_17:
                    func_L01_004450F0(arg0, var_5_2, var_6);
                }
            }
block_18:
            if ((*(u8 *)((u8 *)(temp_20) + 0x61)) != 0) {
block_75:
                func_L01_004450F0(arg0, 9, 3);
            }
        default:
block_277:
            (*(u8 *)((u8 *)(temp_20) + 0x61)) = 0U;
            break;
        case 2:
            if (func_L01_004561B8(arg0) != 0) {
                func_003C3A10(arg0, ((*(s32 *)((u8 *)(temp_20) + 0x4EC)) == 0) ? 8 : 7, 0, 8);
                func_003824E0(5.0f, 15.0f);
                (*(s32 *)((u8 *)(temp_20) + 0x3B0)) = 0x42480000;
            }
            if (func_0038CAD0(temp_20 + 0x3B0) != 0) {
                if (func_00382498(0, 8) == 0) {
                    var_5_3 = 6;
                    var_2_2 = 0xA;
                } else {
                    var_5_3 = 4;
                    var_2_2 = 9;
                }
                temp_5_2 = ((*(s32 *)((u8 *)(temp_20) + 0x4EC)) != 0) ? var_2_2 : var_5_3;
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != temp_5_2) {
                    func_003C3A10(arg0, temp_5_2, 0, 8);
                }
                func_003824E0(5.0f, 15.0f);
                (*(s32 *)((u8 *)(temp_20) + 0x3B0)) = 0x42480000;
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                func_003C3A10(arg0, ((*(s32 *)((u8 *)(temp_20) + 0x4EC)) == 0) ? 8 : 7, 0, 8);
            }
            if (!(func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xF8)), (*(f32 *)((u8 *)(temp_20) + 0x4F8))) > 0.34906584f)) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 8) {
                    func_003C3A10(arg0, 8, 0, 8);
                }
            } else {
                sp0 = func_0038D098((*(f32 *)((u8 *)(temp_20) + 0x4F8))) * 4.0f;
                temp_f0 = func_0038D0B0((*(f32 *)((u8 *)(temp_20) + 0x4F8))) * 4.0f;
                sp8 = 0.0f;
                sp4 = temp_f0;
                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                (*(f32 *)((u8 *)(temp_20) + 0x240)) = sp0;
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x10) {
                    func_003C3A10(arg0, 0x10, 0, 8);
                }
            }
            func_L01_0045AA10(arg0);
            func_L10_003B0B50(arg0);
            if ((((*(s16 *)((u8 *)(temp_20) + 0x3B8)) != 0) && (func_L01_0040E570(arg0 + 0x10, temp_20 + 0x550) > 0.040000003f)) || ((*(s16 *)((u8 *)(temp_20) + 0x3BA)) != 0)) {
                var_5_2 = 4;
                var_6 = 2;
                goto block_17;
            }
            goto block_18;
        case 3:
            if (func_L01_004561B8(arg0) != 0) {
                if ((*(s32 *)((u8 *)(temp_20) + 0x4EC)) != 0) {
                    func_L01_004450F0(arg0, 2, 1);
                    return;
                }
                if ((*(void **)((u8 *)(&D_1A4BE0) + 0x1A50)) != 0) {
                    func_L10_003A7160((*(void **)((u8 *)(&D_1A4BE0) + 0x1A50)));
                    (*(void **)((u8 *)(&D_1A4BE0) + 0x1A50)) = 0;
                    (*(s32 *)((u8 *)(temp_20) + 0x3D8)) = 0;
                    (*(s16 *)((u8 *)(temp_20) + 0x3BA)) = 0;
                }
                (*(s32 *)((u8 *)(temp_20) + 0x3B0)) = 0;
                goto block_48;
            }
block_48:
            if (func_0038CAD0(temp_20 + 0x3B0) != 0) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xB) {
                    func_003C3A10(arg0, 0xB, 0, 8);
                }
                func_003824E0(5.0f, 15.0f);
                (*(s32 *)((u8 *)(temp_20) + 0x3B0)) = 0x42480000;
            }
            if (((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 8)) {
                func_003C3A10(arg0, 8, 0, 8);
            }
            func_L01_0045AA10(arg0);
            func_L10_003B0B50(arg0);
            if ((*(s16 *)((u8 *)(temp_20) + 0x3BA)) == 0) {
                if (((*(u8 *)((u8 *)(arg0) + 0x43)) == 8) && (((s32) D_L10_001DEE40 % 30) == 0)) {
                    (*(f32 *)((u8 *)(temp_20) + 0x4F8)) = func_0038D160((f32)(D_L10_001DEE40), (*(f32 *)((u8 *)(temp_20) + 0x550)) - (*(f32 *)((u8 *)(arg0) + 0x10)));
                    if (func_L01_0040E570(arg0 + 0x10, temp_20 + 0x550) < 64.0f) {
                        sp0 = (*(f32 *)((u8 *)(arg0) + 0x10));
                        sp8 += 0.5f;
                        sp10 = (*(f32 *)((u8 *)(temp_20) + 0x550));
                        sp18 += 0.5f;
                        if (func_003D3CB0() != 0) {
                            if (D_L10_001E8918 == *(s32 *)0x1A71A0) {
                                goto block_262;
                            }
                        } else {
                            goto block_262;
                        }
                    }
                }
            } else {
block_262:
block_263:
                func_L01_004450F0(arg0, 4, 2);
            }
            goto block_277;
        case 5:
            if (func_L01_004561B8(arg0) != 0) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 5) {
                    func_003C3A10(arg0, 5, 0, 8);
                }
                (*(f32 *)((u8 *)(temp_20) + 0x4F8)) = func_0038D160((*(f32 *)((u8 *)((*(void **)((u8 *)(&D_1A4BE0) + 0x1A50))) + 0x10)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)((*(void **)((u8 *)(&D_1A4BE0) + 0x1A50))) + 0x14)) - (*(f32 *)((u8 *)(arg0) + 0x14)));
                (*(void **)((u8 *)(temp_20) + 0x4FC)) = (void *) (*(void **)((u8 *)(&D_1A4BE0) + 0x1A50));
                (*(void **)((u8 *)(&D_1A4BE0) + 0x1A50)) = 0;
                (*(s32 *)((u8 *)(temp_20) + 0x3D8)) = 0;
                (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_20) + 0x4FC))) + 0x98)) = 0;
            }
            temp_5_3 = (*(void **)((u8 *)(temp_20) + 0x4FC));
            if ((temp_5_3 != 0) && (func_L01_0040E570(arg0 + 0x10, temp_5_3 + 0x10) > 3.0f)) {
                func_L10_003A7160((*(void **)((u8 *)(temp_20) + 0x4FC)));
                (*(void **)((u8 *)(temp_20) + 0x4FC)) = 0;
                (*(s16 *)((u8 *)(temp_20) + 0x3BA)) = 0;
                func_L01_004450F0(arg0, 3, 1);
            }
            if ((*(u8 *)((u8 *)(temp_20) + 0x61)) == 0) {
                func_L01_0045AA10(arg0);
                temp_5_4 = (*(void **)((u8 *)(temp_20) + 0x4FC));
                temp_f20 = func_L01_004395E0(arg0);
                if (temp_5_4 != 0) {
                    if (temp_f20 > 25.0f) {
                        func_L01_0044FD88(arg0, temp_5_4, 0, 0);
                    }
                    temp_2_3 = (*(void **)((u8 *)(temp_20) + 0x4FC));
                    if (temp_2_3 != 0) {
                        if ((temp_f20 >= 53.0f) && (temp_f20 <= 60.0f)) {
                            (*(f32 *)((u8 *)(temp_2_3) + 0x2C)) = (f32) ((*(f32 *)((u8 *)(temp_2_3) + 0x2C)) * 0.9f);
                        }
                        temp_4 = (*(void **)((u8 *)(temp_20) + 0x4FC));
                        if ((temp_4 != 0) && (temp_f20 > 60.0f)) {
                            func_003C2880(temp_4);
                            (*(void **)((u8 *)(temp_20) + 0x4FC)) = 0;
                            (*(s16 *)((u8 *)(temp_20) + 0x3BA)) = 0;
                        }
                    }
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    (*(f32 *)((u8 *)(temp_20) + 0x550)) = (f32) (*(f32 *)((u8 *)((*(void **)((u8 *)(temp_20) + 0x3BC))) + 0x10));
                    func_L01_004450F0(arg0, 2, -1);
                }
            } else {
                temp_4_2 = (*(void **)((u8 *)(temp_20) + 0x4FC));
                if (temp_4_2 != 0) {
                    func_L10_003A7160(temp_4_2);
                    (*(void **)((u8 *)(temp_20) + 0x4FC)) = 0;
                    (*(s16 *)((u8 *)(temp_20) + 0x3BA)) = 0;
                }
                goto block_75;
            }
            goto block_277;
        case 4:
            func_L10_003B0B50(arg0);
            if ((*(s32 *)((u8 *)(temp_20) + 0x4EC)) == 0) {
                sp0 = (*(f32 *)((u8 *)(temp_20) + 0x550));
                if (func_L10_003B10C8(arg0, (*(s32 *)((u8 *)(temp_20) + 0x50C)), sp, temp_20 + 0x530, temp_20 + 0x510, 0) == 0) {
                    if (fabsf((*(f32 *)((u8 *)(temp_20) + 0x558)) - (*(f32 *)((u8 *)(arg0) + 0x18))) > 2.5f) {
                        func_L01_004450F0(arg0, 3, 1);
                    }
                }
                temp_f0_2 = func_0038D160(sp0 - (*(f32 *)((u8 *)(arg0) + 0x10)), sp4 - (*(f32 *)((u8 *)(arg0) + 0x14)));
                (*(f32 *)((u8 *)(temp_20) + 0x4F8)) = temp_f0_2;
                var_16 = arg0 + 0x10;
                if (func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xF8)), temp_f0_2) > 0.17453292f) {
                    sp10 = func_0038D098((*(f32 *)((u8 *)(temp_20) + 0x4F8))) * 4.0f;
                    temp_f0_3 = func_0038D0B0((*(f32 *)((u8 *)(temp_20) + 0x4F8))) * 4.0f;
                    sp18 = 0.0f;
                    sp14 = temp_f0_3;
                    0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                    (*(f32 *)((u8 *)(temp_20) + 0x240)) = sp10;
                    var_16 = arg0 + 0x10;
                }
                temp_17 = temp_20 + 0x550;
                temp_f21 = func_L01_0040E570(var_16, temp_17);
                sp44 = var_16;
                sp40 = temp_17;
                if (temp_f21 > 0.040000003f) {
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                    sp10 = sp0;
                    sp18 = 0.0f;
                    var_f0 = 1.5f;
                    if (func_0038CEA8(&sp10) < 1.5f) {
                        var_f0 = func_0038CEA8(&sp10);
                    }
                    func_0038CF68(&sp10, &sp10, var_f0);
                    0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                    sp20 = 0.5f;
                    sp28 += 0.5f;
                    sp30 = sp20;
                    sp38 -= 1.5f;
                    var_19 = func_003D3CB0();
                    var_3 = 0;
                    if (var_19 != 0) {
                        temp_17_2 = temp_20 + 0x3C0;
                        var_10 = 0xFF;
loop_117:
                        temp_5_5 = var_3 * 4;
                        temp_4_3 = *(temp_17_2 + temp_5_5);
                        temp_23 = var_3 + 1;
                        if ((temp_4_3 != var_10) && (var_16_2 = *((temp_4_3 * 4) + &D_L10_0021BF20), ((temp_4_3 & 0xFF) != var_10))) {
                            var_3 = temp_23;
                            if (D_L10_001DF2D8 >= temp_4_3) {
                                var_2_3 = var_3 < 4;
                                if (var_16_2 != 0) {
                                    var_9 = &D_L10_0021BF20;
                                    var_8 = 0xFE;
                                    var_7 = 0xFD;
loop_122:
                                    if (((*(s16 *)((u8 *)(var_16_2) + -2)) >= 0) || (var_3 = temp_23, (var_16_2 == *((*(temp_17_2 + temp_5_5) * 4) + var_9)))) {
                                        temp_3 = D_L10_001DF29C + (((*(u16 *)((u8 *)(var_16_2) + 0)) & 0x7FFF) << 8);
                                        if (temp_3 != 0) {
                                            temp_2_4 = (*(u8 *)((u8 *)(temp_3) + 0x20));
                                            if (temp_2_4 != var_8) {
                                                if (temp_2_4 != var_7) {
                                                    sp50 = var_7;
                                                    sp60 = var_8;
                                                    sp70 = var_9;
                                                    sp80 = var_10;
                                                    temp_cond = func_L01_0040E570(&sp20, temp_3 + 0x10) < 9.0f;
                                                    var_7 = sp50;
                                                    var_8 = sp60;
                                                    var_9 = sp70;
                                                    var_10 = sp80;
                                                    if (temp_cond) {
                                                        (*(f32 *)((u8 *)(temp_20) + 0x110)) = 0.0f;
                                                        var_19 = 0;
                                                    }
                                                }
                                            }
                                            temp_3_2 = *(temp_17_2 + temp_5_5);
                                            var_16_2 += 2;
                                            if ((temp_3_2 & 0xFF) != 0xFF) {
                                                var_3 = temp_23;
                                                if (D_L10_001DF2D8 >= temp_3_2) {
                                                    if (var_16_2 == 0) {
                                                        goto block_133;
                                                    }
                                                    goto loop_122;
                                                }
                                            } else {
                                                goto block_133;
                                            }
                                        } else {
                                            goto block_133;
                                        }
                                    }
                                    goto block_134;
                                }
                            } else {
                                goto block_134;
                            }
                        } else {
block_133:
                            var_3 = temp_23;
block_134:
                            var_2_3 = var_3 < 4;
                        }
                        if ((var_2_3 != 0) && (var_19 != 0)) {
                            goto loop_117;
                        }
                        if (var_19 != 0) {
                            if ((*(s16 *)((u8 *)(temp_20) + 0x3BA)) != 0) {
                                func_L01_0045BD78(arg0, temp_5_5, *(f32 *)&temp_17_2 /* m2c: pointer passed as f32 */, 0.0064000003f, 0.120000005f);
                                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                                    func_003C3A10(arg0, 0, 0, 7);
                                }
                                (*(f32 *)((u8 *)(temp_20) + 0x70)) = 0.6f;
                            } else if (!(temp_f21 > 12.25f)) {
                                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x11) {
                                    func_L01_0045BD78(arg0, temp_5_5, *(f32 *)&temp_17_2 /* m2c: pointer passed as f32 */, 0.0064000003f, 0.0200000014f);
                                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x10) {
                                        func_003C3A10(arg0, 0x10, 0, 8);
                                    }
                                }
                            } else {
                                func_L01_0045BD78(arg0, temp_5_5, *(f32 *)&temp_17_2 /* m2c: pointer passed as f32 */, 0.0064000003f, 0.100000009f);
                                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x11) {
                                    func_003C3A10(arg0, 0x11, 0, 8);
                                }
                            }
                            func_L01_0045A748(arg0, sp);
                            if ((*(s32 *)((u8 *)(temp_20) + 0xF0)) >= 0x33) {
                                func_L01_004450F0(arg0, 3, 1);
                            }
                            if ((*(s16 *)((u8 *)(temp_20) + 0x3BA)) != 0) {
                                temp_f0_4 = func_0038CF38();
                                if (!(temp_f0_4 < (*(f32 *)((u8 *)(temp_20) + 0x3DC)))) {
                                    temp_2_5 = (*(s32 *)((u8 *)(temp_20) + 0x3B4)) + 1;
                                    (*(s32 *)((u8 *)(temp_20) + 0x3B4)) = temp_2_5;
                                    if (temp_2_5 >= 0xFB) {
                                        var_5_4 = 3;
                                        goto block_275;
                                    }
                                } else {
                                    (*(f32 *)((u8 *)(temp_20) + 0x3DC)) = temp_f0_4;
                                }
                            }
                        } else {
                            goto block_163;
                        }
                    } else {
block_163:
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 8) {
                            func_003C3A10(arg0, 8, 0, 5);
                        }
                        var_19_2 = *(((*(s32 *)((u8 *)(temp_20) + 0x4F4)) * 4) + &D_L10_0021BF20);
loop_176:
                        if ((((*(s32 *)((u8 *)(temp_20) + 0x4F4)) & 0xFF) != 0xFF) && (D_L10_001DF2D8 >= (*(s32 *)((u8 *)(temp_20) + 0x4F4))) && (var_19_2 != 0)) {
                            if ((*(s16 *)((u8 *)(var_19_2) + -2)) >= 0) {
                                goto block_167;
                            }
                            if (var_19_2 == *(((*(s32 *)((u8 *)(temp_20) + 0x4F4)) * 4) + &D_L10_0021BF20)) {
block_167:
                                temp_17_3 = D_L10_001DF29C + (((*(u16 *)((u8 *)(var_19_2) + 0)) & 0x7FFF) << 8);
                                if (temp_17_3 != 0) {
                                    temp_16 = (*(void **)((u8 *)(temp_17_3) + 0x68));
                                    if ((func_00382380(sp44, (*(s32 *)((u8 *)(temp_16) + 0)), 0) == 0) || (func_00382380(sp40, (*(s32 *)((u8 *)(temp_16) + 4)), 0) == 0)) {
                                        if (((*(s32 *)((u8 *)(temp_16) + 0x10)) == 0) && (func_00382380(sp44, (*(s32 *)((u8 *)(temp_16) + 4)), 0) != 0)) {
                                            if (func_00382380(sp40, (*(s32 *)((u8 *)(temp_16) + 0)), 0) != 0) {
                                                (*(void **)((u8 *)(temp_20) + 0x4E8)) = temp_17_3;
                                                (*(s32 *)((u8 *)(temp_20) + 0x4F0)) = 0;
                                                goto block_162;
                                            }
                                            goto block_175;
                                        }
block_175:
                                        var_19_2 += 2;
                                        goto loop_176;
                                    }
                                    (*(void **)((u8 *)(temp_20) + 0x4E8)) = temp_17_3;
                                    (*(s32 *)((u8 *)(temp_20) + 0x4F0)) = 1;
block_162:
                                    func_L01_004450F0(arg0, 6, -1);
                                }
                            }
                        }
                        func_L01_0045AA10(arg0);
                        if ((*(void **)((u8 *)(temp_20) + 0x4E8)) == 0) {
                            var_5_4 = 3;
                            goto block_275;
                        }
                    }
                } else {
                    func_L01_0045AA10(arg0);
                    if ((*(s16 *)((u8 *)(temp_20) + 0x3BA)) != 0) {
                        var_5_4 = 5;
                    } else {
                        var_5_4 = 2;
                    }
block_275:
                    func_L01_004450F0(arg0, var_5_4, 1);
                }
            } else {
                if ((func_L01_004561B8(arg0) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xC)) {
                    func_003C3A10(arg0, 0xC, 0, 5);
                }
                temp_5_6 = (*(void **)((u8 *)((*(void **)((u8 *)(temp_20) + 0x4E8))) + 0x68));
                sp44 = arg0 + 0x10;
                temp_19 = *(((*(s32 *)((u8 *)(temp_5_6) + 0xC)) * 4) + &D_L10_0021D1C0);
                func_L10_003B0F78(arg0, temp_5_6);
                var_f20 = (*(f32 *)((u8 *)(temp_20) + 0x514));
                sp30 = 0.0f;
                do {
                    temp_3_3 = (*(s32 *)((u8 *)(temp_20) + 0x4E4));
                    temp_7 = (*(s32 *)((u8 *)(temp_20) + 0x4F0));
                    temp_6 = temp_3_3 - 1;
                    temp_5_7 = (*(f32 *)((u8 *)(((temp_3_3 * 0x10) + temp_19)) + 0x10));
                    temp_17_4 = (temp_7 == 0) ? temp_6 : (temp_3_3 + 1);
                    sp0 = temp_5_7;
                    sp10 = (*(f32 *)((u8 *)(((temp_17_4 * 0x10) + temp_19)) + 0x10));
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                    sp20 = sp10;
                    sp28 = 0.0f;
                    temp_f0_5 = func_0038CEA8(&sp20);
                    temp_f12 = var_f20;
                    if (temp_f0_5 < var_f20) {
                        0 /* unknown instruction: vadd.xyz $vf2, $vf2, $vf1 */;
                        var_f20 -= temp_f0_5;
                        temp_2_6 = (*(s32 *)((u8 *)(temp_20) + 0x4F0));
                        (*(s32 *)((u8 *)(temp_20) + 0x4E4)) = temp_17_4;
                        if (((temp_2_6 == 0) && (temp_17_4 <= 0)) || ((temp_2_6 == 1) && (temp_17_4 >= (*temp_19 - 1)))) {
                            var_f20 = 0.0f;
                            func_L01_004450F0(arg0, 7, -1, temp_f12);
                        }
                    } else {
                        var_f20 = 0.0f;
                        func_0038CF68(&sp20, &sp20, temp_f12);
                        0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                    }
                } while (var_f20 > 0.0f);
                func_L01_0045AA30(arg0, &sp30);
                if ((*(f32 *)((u8 *)(temp_20) + 0x514)) > 0.0f) {
                    func_L01_0045BD10(arg0, func_0038D160(sp30, sp34));
                }
                temp_f20_2 = func_0038CF38();
                (*(f32 *)((u8 *)(arg0) + 0x18)) = (f32) (func_003C4088(sp8, sp18, temp_f20_2 / func_0038CF38()) - (*(f32 *)((u8 *)(temp_20) + 0x518)));
            }
            goto block_277;
        case 6:
            if (func_L01_004561B8(arg0) != 0) {
                func_L01_0045BD78(arg0, 0.0064000003f, 0.100000009f, 0.00753982272f, 0.167551622f);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x11) {
                    func_003C3A10(arg0, 0x11, 0, 8);
                }
            }
            temp_5_8 = (*(void **)((u8 *)(temp_20) + 0x4E8));
            temp_6_2 = (*(s32 *)((u8 *)(temp_20) + 0x4F0));
            temp_16_2 = *(((*(s32 *)((u8 *)((*(void **)((u8 *)(temp_5_8) + 0x68))) + 0xC)) * 4) + &D_L10_0021D1C0);
            temp_3_4 = temp_16_2 + 0x10;
            var_2_4 = temp_3_4;
            if (temp_6_2 == 0) {
                var_2_4 = temp_3_4 + ((*temp_16_2 - 1) * 0x10);
            }
            sp0 = *var_2_4;
            sp8 -= 1.35f;
            if ((*(s32 *)((u8 *)(temp_20) + 0x4F0)) != 0) {
                var_2_5 = temp_16_2 + 0x20;
            } else {
                var_2_5 = temp_3_4 + ((*temp_16_2 - 2) * 0x10);
            }
            sp10 = *var_2_5;
            sp18 -= 1.35f;
            func_L10_003B0F78(arg0, temp_5_8, temp_6_2);
            (*(f32 *)((u8 *)(temp_20) + 0x240)) = sp0;
            if ((*(u8 *)((u8 *)(arg0) + 0x42)) == 3) {
                temp_f20_3 = func_L01_004395E0(arg0, sp);
                sp20 = (*(f32 *)((u8 *)(arg0) + 0x10));
                if (temp_f20_3 > 6.0f) {
                    if (temp_f20_3 < 20.0f) {
                        temp_f3 = (*(f32 *)((u8 *)(temp_20) + 0x540));
                        temp_f0_6 = 1.0f - ((*(f32 *)((u8 *)(arg0) + 0x10)) / 13.0f);
                        temp_f0_7 = 1.0f - (temp_f0_6 * temp_f0_6);
                        sp20 = temp_f3 + ((sp0 - temp_f3) * temp_f0_7);
                        temp_f1_2 = (*(f32 *)((u8 *)(temp_20) + 0x544));
                        sp24 = temp_f1_2 + ((sp4 - temp_f1_2) * temp_f0_7);
                        sp28 = (*(f32 *)((u8 *)(temp_20) + 0x548)) + ((sp8 - (*(f32 *)((u8 *)(temp_20) + 0x548))) * temp_f0_7);
                        0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                        sp30 = sp20;
                        func_L01_0045AA30(arg0, &sp30);
                    }
                }
                func_L01_0045BD10(arg0, func_0038D160(sp10 - sp0, sp14 - sp4));
                if (temp_f20_3 > 20.0f) {
                    (*(f32 *)((u8 *)(arg0) + 0x10)) = sp0;
                    (*(s32 *)((u8 *)(temp_20) + 0x4EC)) = 1;
                    if ((*(s32 *)((u8 *)(temp_20) + 0x4F0)) != 0) {
                        var_2_6 = 0;
                    } else {
                        var_2_6 = *temp_16_2 - 1;
                    }
                    (*(s32 *)((u8 *)(temp_20) + 0x4E4)) = var_2_6;
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xC) {
                        func_003C3A10(arg0, 0xC, 0, 5);
                    }
block_225:
                    func_L01_004450F0(arg0, 4, -1);
                }
            } else {
                func_L01_0045A748(arg0, sp);
                if (func_L01_0040E570(arg0 + 0x10, sp) <= 0.040000003f) {
                    (*(f32 *)((u8 *)(temp_20) + 0x540)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x10));
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 3) {
                        func_003C3A10(arg0, 3, 0, 5);
                    }
                }
            }
            goto block_277;
        case 7:
            if (func_L01_004561B8(arg0) != 0) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 1) {
                    func_003C3A10(arg0, 1, 0, 5);
                }
                (*(f32 *)((u8 *)(temp_20) + 0x540)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x10));
            } else if ((*(u8 *)((u8 *)(arg0) + 0x42)) == 1) {
                temp_f20_4 = func_L01_004395E0(arg0);
                sp0 = (*(f32 *)((u8 *)(arg0) + 0x10));
                if ((temp_f20_4 >= 0.0f) && (temp_f20_4 <= 5.0f)) {
                    temp_f2 = (*(f32 *)((u8 *)(arg0) + 0x10));
                    temp_f1_3 = (temp_f20_4 - 0.0f) / 5.0f;
                    sp8 = temp_f2 - ((temp_f2 - func_003C3D30(arg0 + 0x10, 0, 0, 0.5f)) * (temp_f1_3 * temp_f1_3));
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                    sp10 = sp0;
                    func_L01_0045AA30(arg0, &sp10);
                }
                if (temp_f20_4 > 10.0f) {
                    (*(s32 *)((u8 *)(temp_20) + 0x4EC)) = 0;
                    (*(void **)((u8 *)(temp_20) + 0x4E8)) = 0;
                    goto block_225;
                }
            }
            goto block_277;
        case 8:
            if (func_L01_004561B8(arg0) != 0) {
                (*(s32 *)((u8 *)(temp_20) + 0x508)) = 0x320;
                (*(s8 *)((u8 *)(temp_20) + 0x1A8)) = 0xFF;
                (*(s8 *)((u8 *)(temp_20) + 0x170)) = 0xFF;
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xB) {
                    func_003C3A10(arg0, 0xB, 0, 5);
                }
            } else if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                func_L01_004450F0(arg0, 9, -1);
            }
            func_L01_0045AA10(arg0);
            func_0038CAD0(temp_20 + 0x508);
            goto block_277;
        case 9:
            sp40 = temp_20 + 0x550;
            if (func_L01_004561B8(arg0) != 0) {
                var_19_3 = 0;
                var_16_3 = *(((*(s32 *)((u8 *)(temp_20) + 0x500)) * 4) + &D_L10_0021BF20);
loop_237:
                if ((((*(s32 *)((u8 *)(temp_20) + 0x500)) & 0xFF) != 0xFF) && (D_L10_001DF2D8 >= (*(s32 *)((u8 *)(temp_20) + 0x500))) && (var_16_3 != 0)) {
                    if ((*(s16 *)((u8 *)(var_16_3) + -2)) >= 0) {
                        goto block_234;
                    }
                    if (var_16_3 == *(((*(s32 *)((u8 *)(temp_20) + 0x500)) * 4) + &D_L10_0021BF20)) {
block_234:
                        var_19_3 = D_L10_001DF29C + (((*(u16 *)((u8 *)(var_16_3) + 0)) & 0x7FFF) << 8);
                        if (var_19_3 != 0) {
                            if (func_00382380(arg0 + 0x10, *(*(s32 **)((u8 *)(var_19_3) + 0x68)), 0) == 0) {
                                var_16_3 += 2;
                                goto loop_237;
                            }
                            goto block_246;
                        }
                        goto block_249;
                    }
                    goto block_246;
                }
block_246:
                if (var_19_3 != 0) {
                    (*(s32 *)((u8 *)(temp_20) + 0x4E4)) = 0;
                    (*(s32 *)((u8 *)(temp_20) + 0x504)) = (s32) (*(s32 *)((u8 *)((*(void **)((u8 *)(var_19_3) + 0x68))) + 0xC));
                } else {
block_249:
                    func_L01_004450F0(arg0, 4, 2);
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                    func_003C3A10(arg0, 0, 0, 0);
                }
                if ((*(void **)((u8 *)(&D_1A4BE0) + 0x1A50)) != 0) {
                    func_L10_003A7160((*(void **)((u8 *)(&D_1A4BE0) + 0x1A50)));
                    (*(void **)((u8 *)(&D_1A4BE0) + 0x1A50)) = 0;
                    (*(s32 *)((u8 *)(temp_20) + 0x3D8)) = 0;
                    (*(s16 *)((u8 *)(temp_20) + 0x3BA)) = 0;
                }
            }
            func_L10_003B0B50(arg0);
            func_L01_0045BD78(arg0, 0.0064000003f, 0.120000005f, 0.0100530973f, 0.251327425f);
            if ((*(s32 *)((u8 *)(temp_20) + 0xF0)) < 3) {
                (*(s32 *)((u8 *)(temp_20) + 0xA8)) = (s32) ((*(s32 *)((u8 *)(temp_20) + 0xA8)) | 0x10);
            }
            func_L01_0045A748(arg0, sp40);
            func_L01_0045BD10(arg0, func_0038D160((*(f32 *)((u8 *)(temp_20) + 0x110)), (*(f32 *)((u8 *)(temp_20) + 0x114))));
            (*(s32 *)((u8 *)(temp_20) + 0xA8)) = (s32) ((*(s32 *)((u8 *)(temp_20) + 0xA8)) & ~0x10);
            if (((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 0x191U) || ((*(u8 *)((u8 *)(temp_20) + 0x61)) == 0)) {
                if ((*(void **)((u8 *)(temp_20) + 0x3BC)) == 0) {
                    var_5_4 = 1;
                    if ((*(u8 *)((u8 *)(temp_20) + 0x61)) == 0) {
                        temp_f1_4 = (*(f32 *)((u8 *)(temp_20) + 0x4E0));
                        temp_2_7 = &D_1A4C60 - 0x80;
                        if (func_L01_0040E570(&D_1A4C60, arg0 + 0x10) < (temp_f1_4 * temp_f1_4 * 9.0f)) {
                            (*(void **)((u8 *)(temp_20) + 0x3BC)) = (void *) (*(void **)((u8 *)(temp_2_7) + 0x25C0));
                            (*(f32 *)((u8 *)(temp_20) + 0x4F8)) = func_0038D160((*(f32 *)((u8 *)(temp_2_7) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_2_7) + 0x84)) - (*(f32 *)((u8 *)(arg0) + 0x14)));
                            D_L10_001DBDD4 = 1;
                            goto block_262;
                        }
block_274:
                        var_5_4 = 1;
                        goto block_275;
                    }
                    goto block_275;
                }
                goto block_263;
            }
            goto block_277;
        case 10:
            if (func_L01_004561B8(arg0) != 0) {
                if ((*(s32 *)((u8 *)(temp_20) + 0x4EC)) != 0) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xD) {
                        func_003C3A10(arg0, 0xD, 0, 5);
                    }
                } else if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x12) {
                    func_003C3A10(arg0, 0x12, 0, 5);
                }
                temp_4_4 = (*(void **)((u8 *)(temp_20) + 0x4FC));
                if (temp_4_4 != 0) {
                    func_L10_003A7160(temp_4_4);
                    (*(void **)((u8 *)(temp_20) + 0x4FC)) = 0;
                    (*(s16 *)((u8 *)(temp_20) + 0x3BA)) = 0;
                }
            }
            func_L01_0045A9F0(arg0);
            if (func_L01_00454370(arg0, temp_20 + 0x160) & 2) {
                if ((*(void **)((u8 *)(temp_20) + 0x3BC)) == 0) {
                    goto block_274;
                }
                func_L01_004450F0(arg0, 2, 1);
            }
            goto block_277;
        }
    }
}
