/* func_L23_003B1490: Opus handoff (prep by Sonnet worker w7, 2026-11-08)
   Size: 8296 bytes, places: 1 levels (23), file: src/levels/23_holostar_studios_clank/L23_003AD800.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: one function (addiu sp,-0xF0), 6 switches / 1 jump table (14 entries); switches on +0x95 (x4), +0x20 and a +0x30C field of the +0x68 object; m2c mis-saw one rodata float table as a jump table (jtbl_002C0220, now D_L23_002C0220[]).
   Twin: none (rac2 index best func_L11_0042F018 at 0.22). Checked: callee fingerprint (callfp: 1 callee mapped); whole-corpus opcode search over every rac3 and rac2 function >= 600 B (best rac3:func_L23_003AD800 0.17); names.tsv/NAMES.md (no entry); matched rac3 siblings in src/ (only the scaffold is shared).
   Mapping: Common enemy/boss scaffold (matches the tools' names): arg0 = moby; +0x20 = state byte (func_L01_004450F0 = moby_set_state(moby, state, sub)), +0x95 = phase byte, +0x68 = per-object data, func_L01_004561B8 = animation-done test, func_003C3A10 = moby_anim_blend(moby, anim, 0, 8), func_0038CB00 = timer_tick_short, D_1A4BE0 = hero/global struct (+0x25C0 hero moby, +0x25C4 hero state, +0xC08 pad bits). $gp loads are named D_<0x1DC8B0+offset> (D_LNN_ when >= 0x1D9900) in the draft. Own callees: func_L23_003B3BB8 (x11). D_L23_001E1A40 conflicts with the file context (dropped).
   Identical / changed / added / removed: n/a (no twin).
   VU0: 11 vadd.xyz/vsub.xyz ops in the retail asm; inline-asm VU0 is banned since 2026-11-06 (Matching-Patterns), so this function cannot reach MATCH unless the ops come from plain C; the lq/sq copies are fine (u128_t).
   Draft: compiles (m2c draft cleaned by tools/post.py (real repo prototypes where known, m2c gotos kept)); 2045 diff; opcode-equal 1418 of 2075 (mine 1833), ratio 0.73.
     Retail rows yours=1833 retail=2075 equalrows=30.
   Left for Opus:
     1. D_L23_002C0220 is a rodata float table indexed by a local (m2c thought jump table): declare it right or it will not match.
     2. Opcode ratio 0.73 already; the diff is dominated by prologue order (retail 0xF0 frame, mine 0xD0).
     3. 11 VU0 ops (1 lqc2): near miss only.
*/
extern f32 func_003824E0(f32, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CED8(f32 *);
extern f32 func_0038CF38();
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_L01_00443A18(f32, f32);
extern int func_L01_004561B8(u8 *);
extern s32 func_00382498(s32, s32);
extern s32 func_0038CF68(void *, void *, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003C2EC0();
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern void func_003C3A10(void *, s32, s32, s32);
s32 func_00382580(f32 *, s32, f32);         /* extern */
s32 func_003C4098(f32 *, f32 *, f32 *, f32);    /* extern */
s32 func_L01_003A9928(void *);                  /* extern */
f32 func_L01_004395E0();  /* extern, call arities [1, 2], m2c proto was (void *, f32 *) */
s32 func_L01_004450F0(void *, u8, s32);     /* extern */
s32 func_L01_00446780();  /* K&R: prototype dropped, mismatch with m2c calls */
s32 func_L01_004468C8(void *, s32, s32, s32, s32, s32, f32, f32, s32); /* extern */
s32 func_L01_0044E1B8(void *, s32);             /* extern */
s32 func_L01_0045AA30(void *, f32 *);           /* extern */
s32 func_L23_003B34F8();                        /* extern */
s32 func_L23_003B3908(void *);                  /* extern */
s32 func_L23_003B3BB8(void *, f32 *, s32, f32); /* extern */
s32 func_L23_003B4108(void *, void *, s32, f32 *, s32, s32); /* extern */
s32 func_L23_003BB7C8(void *, f32 *, f32 *, s32, f32, f32); /* extern */
s32 func_L23_00456AA8(f32 *, f32 *, f32, s32, s32, f32); /* extern */
extern s32 D_1A4BE0;
extern f32 D_1A4C60;
extern f32 D_1A4CF0;
extern s32 D_L23_001DEC40;

extern s32 D_L23_001DE2D4;
extern f32 D_L23_001DE328;
extern f32 D_L23_001DE33C;
extern f32 D_L23_001DE340;
extern f32 D_L23_001DE344;
extern f32 D_L23_001DE348;
extern s32 D_L23_001DE34C;
extern f32 D_L23_001DE350;
extern f32 D_L23_001DE354;
extern f32 D_L23_001DE358;
extern s32 D_L23_001DE35C;
extern s32 D_L23_001DE360;
extern s32 D_L23_001DE364;
extern s32 D_L23_001DE368;
extern f32 D_L23_001DE36C;
extern s32 D_L23_001DE370;
extern f32 D_L23_001DE374;
extern f32 D_L23_001DE378;
extern f32 D_L23_001DE37C;
extern f32 D_L23_001DE380;
extern s32 D_L23_001DE384;
extern f32 D_L23_001DE388;
extern s32 D_L23_001DE38C;
extern s32 D_L23_001DE390;
extern f32 D_L23_001DE394;
extern f32 D_L23_001DE398;
extern s32 D_L23_001DE39C;
extern f32 D_L23_001DE3A0;
extern f32 D_L23_002C0220[];  /* rodata table m2c took for a jump table */

void func_L23_003B1490(void *arg0) {
    s32 sp[8]; /* m2c: stack-slot base, size unknown */
    s32 sp30; /* m2c stack slot */
    f32 sp0;
    f32 sp4;
    f32 sp8;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp20;
    f32 sp40;
    s32 sp48;
    f32 sp50;
    f32 sp54;
    s32 *var_4;
    s32 var_5;
    s32 var_5_5;
    s32 var_5_6;
    s32 var_5_9;
    s32 var_7;
    s32 var_f0_4;
    s32 var_f0_5;
    f32 *temp_16;
    f32 *temp_16_2;
    f32 *temp_2_2;
    f32 *temp_2_3;
    f32 *temp_2_4;
    f32 *var_5_10;
    f32 *var_5_2;
    f32 *var_5_8;
    f32 temp_17_2;
    f32 temp_f0;
    f32 temp_f0_10;
    f32 temp_f0_11;
    f32 temp_f0_12;
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
    f32 temp_f14;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f1_6;
    f32 temp_f1_7;
    f32 temp_f20;
    f32 temp_f20_10;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f20_6;
    f32 temp_f20_7;
    f32 temp_f20_8;
    f32 temp_f20_9;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f23;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_6;
    f32 var_f0_7;
    f32 var_f12;
    f32 var_f12_2;
    f32 var_f12_3;
    f32 var_f12_4;
    f32 var_f13;
    f32 var_f20;
    s32 temp_16_3;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_2_7;
    s32 temp_3_10;
    s32 temp_3_7;
    s32 temp_4;
    s32 temp_4_3;
    s32 temp_4_6;
    s32 temp_6;
    s32 var_16;
    s32 var_21;
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_3;
    s32 var_3_2;
    s32 var_3_3;
    s32 var_3_4;
    u32 temp_4_2;
    u8 temp_17;
    u8 temp_2;
    u8 temp_3;
    u8 temp_3_11;
    u8 temp_3_12;
    u8 temp_3_2;
    u8 temp_3_3;
    u8 temp_3_4;
    u8 temp_3_5;
    u8 temp_3_6;
    u8 temp_3_8;
    u8 temp_3_9;
    u8 temp_4_4;
    u8 temp_4_5;
    u8 temp_4_7;
    u8 var_5_11;
    u8 var_5_3;
    u8 var_5_4;
    u8 var_5_7;
    u8 *temp_19;

    temp_19 = (*(void **)((u8 *)(arg0) + 0x68));
    func_L23_003B34F8();
    temp_3 = (*(u8 *)((u8 *)(arg0) + 0x95));
    switch (temp_3) {                               /* switch 1; irregular */
    case 3:                                         /* switch 1 */
        temp_4 = (*(s32 *)((u8 *)(temp_19) + 0x30C));
        if (temp_4 == temp_3) {
            if ((*(s32 *)((u8 *)(temp_19) + 0x300)) == temp_4) {
                (*(f32 *)((u8 *)(temp_19) + 0x170)) = (f32) D_1A4C60;
                func_003C2F58(arg0, ((*(s32 *)((u8 *)(temp_19) + 0x304)) & 1) ^ 1, sp);
                (*(f32 *)((u8 *)(temp_19) + 0x344)) = (f32) -func_0038D160(func_0038CF38(), (*(f32 *)((u8 *)(temp_19) + 0x178)) - sp8);
            } else {
                temp_f12 = func_0038CF38() / D_L23_001DE344;
                var_f0 = D_L23_001DE358;
                if ((*(s32 *)((u8 *)(temp_19) + 0x398)) == 0) {
                    var_f0 = D_L23_001DE354;
                }
                func_0038CE20(sp, &D_1A4CF0, temp_f12 * var_f0);
                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                (*(f32 *)((u8 *)(temp_19) + 0x170)) = sp0;
            }
        }
        break;
    case 2:                                         /* switch 1 */
        if ((*(s32 *)((u8 *)(temp_19) + 0x300)) != 3) {
            func_L01_004450F0(arg0, 3U, -1);
        }
        break;
    }
    temp_2 = (*(u8 *)((u8 *)(arg0) + 0x20));
    temp_4_2 = temp_2 - 1;
    if (temp_4_2 < 0xEU) {
        switch (temp_2) {                           /* switch 2 */
        case 1:                                     /* switch 2 */
            if (func_L01_004561B8(arg0) == 0) {
                if ((*(s32 *)((u8 *)(temp_19) + 0x31C)) != 8) {
                    temp_17 = (*(u8 *)((u8 *)(arg0) + 0x43));
                    if ((temp_17 == 1) && (func_L01_0044E1B8(arg0, 0x42C80000) != 0)) {
                        (*(f32 *)((u8 *)(temp_19) + 0x360)) = (f32) (func_0038D098(func_0038D160((*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)) - (*(f32 *)((u8 *)(arg0) + 0x14)))) * 10.0f);
                        temp_f0 = func_0038D0B0(func_0038D160((*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)) - (*(f32 *)((u8 *)(arg0) + 0x14)))) * 10.0f;
                        (*(s32 *)((u8 *)(temp_19) + 0x368)) = 0;
                        (*(f32 *)((u8 *)(temp_19) + 0x364)) = temp_f0;
                        0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                        (*(f32 *)((u8 *)(temp_19) + 0x360)) = (f32) (*(f32 *)((u8 *)(temp_19) + 0x360));
                        (*(f32 *)((u8 *)(temp_19) + 0x308)) = func_0038D160((*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(temp_19) + 0x360)), (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)) - (*(f32 *)((u8 *)(temp_19) + 0x364)));
                        (*(s32 *)((u8 *)(temp_19) + 0x300)) = (s32) temp_17;
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xD) {
                            func_003C3A10(arg0, 0xD, 0, 0x11);
                        }
                    } else if ((*(s32 *)((u8 *)(temp_19) + 0x31C)) != 0xFA) {
                        if (((*(u8 *)((u8 *)(arg0) + 0x43)) == 2) && (func_L01_0044E1B8(arg0, 0x429C0000) != 0)) {
                            (*(s32 *)((u8 *)(temp_19) + 0x300)) = 0;
                            if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                                func_003C3A10(arg0, 0, 0, 8);
                            }
                        }
                    } else {
                        (*(f32 *)((u8 *)(temp_19) + 0x360)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x10));
                        (*(f32 *)((u8 *)(temp_19) + 0x308)) = func_0038D160((*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)) - (*(f32 *)((u8 *)(arg0) + 0x14)));
                        (*(s32 *)((u8 *)(temp_19) + 0x300)) = 0;
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 2) {
                            func_003C3A10(arg0, 2, 0, 8);
                        }
                    }
                } else {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 1) {
                        func_003C3A10(arg0, 1, 0, 8);
                    }
                    (*(s32 *)((u8 *)(temp_19) + 0x300)) = 0;
                }
            } else {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                    func_003C3A10(arg0, 0, 0, 8);
                }
                (*(s32 *)((u8 *)(temp_19) + 0x31C)) = 0;
                (*(f32 *)((u8 *)(temp_19) + 0x308)) = (f32) (*(f32 *)((u8 *)(arg0) + 0xF8));
                (*(s32 *)((u8 *)(temp_19) + 0x300)) = 0;
                (*(f32 *)((u8 *)(temp_19) + 0x360)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x10));
            }
            func_L23_003B3BB8(arg0, temp_19 + 0x360, (*(s32 *)((u8 *)(temp_19) + 0x300)), (*(f32 *)((u8 *)(temp_19) + 0x308)));
            break;
        case 2:                                     /* switch 2 */
            if ((func_L01_004561B8(arg0) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4)) {
                func_003C3A10(arg0, 4, 0, 5);
            }
            temp_2_2 = temp_19 + 0x360;
            temp_f20 = func_L01_0040E570(temp_2_2, (f32 *)0x1A0000);
            temp_f23 = func_L01_0040E570(arg0 + 0x10, (f32 *)0x1A0000);
            if (temp_f20 < 6400.0f) {
                0 /* unknown instruction: lqc2 $vf2, 0x4c60($s1) */;
                0 /* unknown instruction: vsub.xyz $vf2, $vf2, $vf1 */;
                sp0 = 0 /* Read from unset register $f2 */;
                temp_f20_2 = func_0038D160(sp0, sp4);
                0 /* unknown instruction: vsub.xyz $vf2, $vf2, $vf1 */;
                sp10 = (*(f32 *)((u8 *)(arg0) + 0x10));
                if (func_0038DBA0(func_0038D160(sp10, sp14), temp_f20_2) < 0.0f) {
                    var_f0_2 = func_0038DB00(temp_f20_2, 2.09439516f);
                } else {
                    var_f0_2 = func_0038DAB8(temp_f20_2, 2.0943952f);
                }
                temp_f20_3 = func_0038D098(var_f0_2);
                (*(f32 *)((u8 *)(temp_19) + 0x360)) = (f32) (temp_f20_3 * (100.0f - func_0038CEA8(sp)));
                temp_f20_4 = func_0038D0B0(var_f0_2);
                temp_f21 = 100.0f - func_0038CEA8(sp);
                (*(s32 *)((u8 *)(temp_19) + 0x368)) = 0;
                (*(f32 *)((u8 *)(temp_19) + 0x364)) = (f32) (temp_f20_4 * temp_f21);
                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                (*(f32 *)((u8 *)(temp_19) + 0x360)) = (f32) (*(f32 *)((u8 *)(temp_19) + 0x360));
            }
            if (temp_f23 < 900.0f) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 6) {
                    var_5 = 6;
                    var_7 = 0x19;
                    goto block_59;
                }
                goto block_60;
            }
            if ((*(f32 *)((u8 *)(temp_19) + 0xA4)) < (*(f32 *)((u8 *)(temp_19) + 0x13C))) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 5) {
                    func_003C3A10(arg0, 5, 0, 0x19);
                }
                var_f12 = (*(f32 *)((u8 *)(temp_19) + 0x360)) - (*(f32 *)((u8 *)(arg0) + 0x10));
                var_f13 = (*(f32 *)((u8 *)(temp_19) + 0x364)) - (*(f32 *)((u8 *)(arg0) + 0x14));
            } else {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                    var_5 = 4;
                    var_7 = 8;
block_59:
                    func_003C3A10(arg0, var_5, 0, var_7);
                }
block_60:
                var_f13 = (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)) - (*(f32 *)((u8 *)(arg0) + 0x14));
                var_f12 = (*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10));
            }
            (*(f32 *)((u8 *)(temp_19) + 0x308)) = func_0038D160(var_f12, var_f13);
            var_f12_2 = (*(f32 *)((u8 *)(temp_19) + 0x308));
            var_5_2 = temp_2_2;
block_125:
            func_L23_003B3BB8(arg0, var_5_2, 3, var_f12_2);
            break;
        case 3:                                     /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 3) {
                    func_003C3A10(arg0, 3, 0, 8);
                }
                (*(s32 *)((u8 *)(temp_19) + 0x300)) = 0;
                (*(f32 *)((u8 *)(temp_19) + 0x328)) = 0.0f;
                (*(s32 *)((u8 *)(temp_19) + 0x304)) = 0;
                (*(s32 *)((u8 *)(temp_19) + 0x30C)) = 0;
                (*(f32 *)((u8 *)(temp_19) + 0x34C)) = 0.0f;
                (*(s32 *)((u8 *)(temp_19) + 0x334)) = 0;
            }
            if (func_L01_0044E1B8(arg0, 0x41000000) != 0) {
                (*(s32 *)((u8 *)(temp_19) + 0x300)) = 3;
                (*(f32 *)((u8 *)(temp_19) + 0x324)) = (f32) D_L23_001DE3A0;
            }
            temp_3_2 = (*(u8 *)((u8 *)(arg0) + 0x42));
            if ((temp_3_2 == (*(u8 *)((u8 *)(arg0) + 0x43))) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                if (temp_3_2 != 4) {
                    func_003C3A10(arg0, 4, 0, 5);
                }
                temp_3_3 = (*(u8 *)((u8 *)(arg0) + 0x94));
                if (temp_3_3 == 6) {
                    var_5_3 = 6;
                    goto block_87;
                }
                if (temp_3_3 != 5) {
                    temp_3_4 = (*(u8 *)((u8 *)(arg0) + 0x95));
                    switch (temp_3_4) {             /* switch 3; irregular */
                    case 1:                         /* switch 3 */
                        var_5_3 = 1;
                        goto block_87;
                    case 2:                         /* switch 3 */
                        var_5_3 = 2;
                        goto block_87;
                    case 3:                         /* switch 3 */
                        var_5_3 = 7;
                        goto block_87;
                    default:                        /* switch 3 */
                        func_L01_004450F0(arg0, 1U, 1);
                        break;
                    }
                } else {
                    var_5_3 = 5;
block_87:
                    func_L01_004450F0(arg0, var_5_3, -1);
                }
            }
            func_L23_003B3BB8(arg0, arg0 + 0x10, (*(s32 *)((u8 *)(temp_19) + 0x300)), (*(f32 *)((u8 *)(arg0) + 0xF8)));
            break;
        case 4:                                     /* switch 2 */
            if (((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 0x97U) || (func_L01_004561B8(arg0) != 0)) {
                sp0 = (*(f32 *)((u8 *)(arg0) + 0x10));
                func_L23_003B4108(temp_19 + 0x360, arg0, (*(s32 *)((u8 *)(temp_19) + 0x310)), sp, 0x41F00000, 0x42480000);
                (*(u16 *)((u8 *)(arg0) + 0x96)) = 0U;
                (*(f32 *)((u8 *)(temp_19) + 0x34C)) = 0.0f;
                (*(s32 *)((u8 *)(temp_19) + 0x334)) = 0;
            }
            temp_f0_2 = func_0038D160((*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)) - (*(f32 *)((u8 *)(arg0) + 0x14)));
            (*(f32 *)((u8 *)(temp_19) + 0x308)) = temp_f0_2;
            temp_3_5 = (*(u8 *)((u8 *)(arg0) + 0x43));
            temp_2_3 = temp_19 + 0x360;
            if (temp_3_5 != 0x1A) {
                temp_f1 = (*(f32 *)((u8 *)(temp_19) + 0xA4));
                if (func_L01_0040E570(arg0 + 0x10, temp_2_3) < (temp_f1 * temp_f1)) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x1A) {
                        func_003C3A10(arg0, 0x1A, 0, 5);
                    }
                } else {
                    (*(s32 *)((u8 *)(temp_19) + 0x300)) = 3;
                    if (fabsf(func_0038DBA0(func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x360)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x364)) - (*(f32 *)((u8 *)(arg0) + 0x14))), (*(f32 *)((u8 *)(temp_19) + 0x308)))) > 1.5707964f) {
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 6) {
                            func_003C3A10(arg0, 6, 0, 8);
                        }
                    } else if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 5) {
                        func_003C3A10(arg0, 5, 0, 8);
                    }
                }
                var_f12_2 = (*(f32 *)((u8 *)(temp_19) + 0x308));
                var_5_2 = temp_2_3;
                goto block_125;
            }
            var_5_2 = temp_19 + 0x360;
            if ((*(u8 *)((u8 *)(arg0) + 0x42)) == temp_3_5) {
                temp_f0_3 = func_L01_004395E0(arg0, var_5_2);
                if (!(temp_f0_3 <= 5.0f)) {
                    func_L23_003B3BB8(arg0, arg0 + 0x10, 0, (*(f32 *)((u8 *)(arg0) + 0xF8)));
                } else {
                    temp_f14 = temp_f0_3 / 5.0f;
                    (*(f32 *)((u8 *)(temp_19) + 0x328)) = func_003C4088(0, (*(f32 *)((u8 *)(temp_19) + 0x39C)), 1.0f - (temp_f14 * temp_f14));
                    sp0 = (*(f32 *)((u8 *)(arg0) + 0x10));
                    sp8 = (*(f32 *)((u8 *)(temp_19) + 0x378)) + (*(f32 *)((u8 *)(temp_19) + 0x328));
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                    func_L01_0045AA30(arg0, sp);
                }
                if (func_L01_0044E1B8(arg0, 0x40A00000) != 0) {
                    (*(f32 *)((u8 *)(&D_L23_001E1A40) + 0x20)) = 0.3f;
                    (*(s32 *)((u8 *)(&D_L23_001E1A40) + 0x28)) = 0x21;
                    (*(s32 *)((u8 *)(&D_L23_001E1A40) + 0x2C)) = 0;
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                        func_003C3A10(arg0, 0, 0, 5);
                    }
                    temp_3_6 = (*(u8 *)((u8 *)(arg0) + 0x95));
                    switch (temp_3_6) {             /* switch 4; irregular */
                    case 1:                         /* switch 4 */
                        var_5_4 = 1;
block_236:
                        func_L01_004450F0(arg0, var_5_4, -1);
                        break;
                    case 2:                         /* switch 4 */
                        var_5_4 = 2;
                        goto block_236;
                    case 3:                         /* switch 4 */
                        var_5_4 = 7;
                        goto block_236;
                    default:                        /* switch 4 */
                        func_L01_004450F0(arg0, 1U, 1);
                        break;
                    }
                }
            } else {
                var_f12_2 = temp_f0_2;
                goto block_125;
            }
            break;
        case 5:                                     /* switch 2 */
            temp_2_4 = &D_1A4C60 - 0x80;
            (*(f32 *)((u8 *)(temp_19) + 0x360)) = (f32) D_1A4C60;
            (*(f32 *)((u8 *)(temp_19) + 0x308)) = func_0038D160(D_L23_002C0220[temp_4_2], (*(f32 *)((u8 *)(temp_2_4) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10)));
            if ((*(s32 *)((u8 *)(temp_19) + 0x300)) == 3) {
                if (fabsf(func_0038DBA0(func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x360)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x364)) - (*(f32 *)((u8 *)(arg0) + 0x14))), (*(f32 *)((u8 *)(temp_19) + 0x308)))) > 1.5707964f) {
                    var_5_5 = 6;
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 6) {
                        goto block_131;
                    }
                } else {
                    var_5_5 = 5;
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 5) {
block_131:
                        func_003C3A10(arg0, var_5_5, 0, 8);
                    }
                }
            } else if (((*(s16 *)((u8 *)(temp_19) + 0x184)) == 0) && ((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 0x33U)) {
                func_L01_004450F0(arg0, 3U, -1);
            } else {
                (*(s32 *)((u8 *)(temp_19) + 0x300)) = 2;
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x14) {
                    func_003C3A10(arg0, 0x14, 0, 8);
                }
            }
            func_L23_003B3BB8(arg0, temp_19 + 0x360, (*(s32 *)((u8 *)(temp_19) + 0x300)), (*(f32 *)((u8 *)(temp_19) + 0x308)));
            temp_f1_2 = (*(f32 *)((u8 *)(temp_19) + 0x32C));
            if (func_L01_0040E570(arg0 + 0x10, &D_1A4C60) <= (temp_f1_2 * temp_f1_2)) {
                var_5_4 = 7;
                goto block_236;
            }
            break;
        case 6:                                     /* switch 2 */
            if ((*(s32 *)((u8 *)(temp_19) + 0x300)) != 3) {
                var_5_4 = 3;
                goto block_236;
            }
            if (func_L01_004561B8(arg0) != 0) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 6) {
                    func_003C3A10(arg0, 6, 0, 8);
                }
                temp_f20_5 = func_L01_00443A18(0, 1.04719758f);
                (*(f32 *)((u8 *)(temp_19) + 0x360)) = (f32) (func_0038D098(func_0038DAB8(temp_f20_5, func_0038D160((*(f32 *)((u8 *)(arg0) + 0x10)) - (*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)), (*(f32 *)((u8 *)(arg0) + 0x14)) - (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84))))) * (*(f32 *)((u8 *)(temp_19) + 0x32C)));
                temp_f20_6 = func_L01_00443A18(0, 1.04719758f);
                temp_f0_4 = func_0038D0B0(func_0038DAB8(temp_f20_6, func_0038D160((*(f32 *)((u8 *)(arg0) + 0x10)) - (*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)), (*(f32 *)((u8 *)(arg0) + 0x14)) - (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)))));
                (*(s32 *)((u8 *)(temp_19) + 0x368)) = 0;
                (*(f32 *)((u8 *)(temp_19) + 0x364)) = (f32) (temp_f0_4 * (*(f32 *)((u8 *)(temp_19) + 0x32C)));
                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                (*(f32 *)((u8 *)(temp_19) + 0x360)) = (f32) (*(f32 *)((u8 *)(temp_19) + 0x360));
                (*(f32 *)((u8 *)(temp_19) + 0x308)) = func_0038D160((*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)) - (*(f32 *)((u8 *)(arg0) + 0x14)));
            }
            temp_16 = temp_19 + 0x360;
            func_L23_003B3BB8(arg0, temp_16, 3, (*(f32 *)((u8 *)(temp_19) + 0x308)));
            temp_f1_3 = (*(f32 *)((u8 *)(temp_19) + 0xA4));
            if ((func_L01_0040E570(arg0 + 0x10, temp_16) <= (temp_f1_3 * temp_f1_3)) || ((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 0xFBU)) {
                var_5_4 = 7;
                goto block_236;
            }
            break;
        case 7:                                     /* switch 2 */
            if (((*(s32 *)((u8 *)(temp_19) + 0x304)) == 0) && (func_L01_004561B8(arg0) != 0)) {
                temp_2_5 = (*(s32 *)((u8 *)(temp_19) + 0x334));
                if ((*(s32 *)((u8 *)(temp_19) + 0x300)) == 3) {
                    if (temp_2_5 != 0) {
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 8) {
                            var_5_6 = 8;
                            goto block_159;
                        }
                    } else if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                        var_5_6 = 4;
                        goto block_159;
                    }
                } else if (temp_2_5 != 0) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xF) {
                        var_5_6 = 0xF;
block_159:
                        func_003C3A10(arg0, var_5_6, 0, 5);
                    }
                } else if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                    func_003C3A10(arg0, 0, 0, 5);
                }
            }
            temp_16_2 = arg0 + 0x10;
            func_L23_003B3BB8(arg0, temp_16_2, (((*(s32 *)((u8 *)(temp_19) + 0x300)) ^ 3) == 0) ? 3 : 0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x170)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x174)) - (*(f32 *)((u8 *)(arg0) + 0x14))));
            temp_f20_7 = func_L01_0040E570(temp_16_2, &D_1A4C60);
            if (((*(s32 *)((u8 *)(temp_19) + 0x30C)) == 3) && (temp_f20_7 < 196.0f)) {
                (*(s32 *)((u8 *)(temp_19) + 0x304)) = 0;
            }
            if (temp_f20_7 > 100.0f) {
                (*(s32 *)((u8 *)(temp_19) + 0x38C)) = 0;
            }
            temp_4_3 = (*(s32 *)((u8 *)(temp_19) + 0x30C));
            if (temp_4_3 != 1) {
                goto block_174;
            }
            if ((*(s32 *)((u8 *)(temp_19) + 0x38C)) < 3) {
block_174:
                if ((*(s32 *)((u8 *)(temp_19) + 0x304)) <= 0) {
                    var_2 = D_L23_001DE2D4;
                    if (var_2 < 0) {
                        if ((*(s32 *)((u8 *)(temp_19) + 0x300)) == 3) {
                            if (temp_4_3 == 0) {
                                var_3 = D_L23_001DE368;
                                if ((*(s32 *)((u8 *)(temp_19) + 0x398)) == 0) {
                                    var_3 = D_L23_001DE364;
                                }
                                (*(s32 *)((u8 *)(temp_19) + 0x304)) = var_3;
                                (*(s32 *)((u8 *)(temp_19) + 0x30C)) = 3;
                            } else {
                                func_L01_004450F0(arg0, 4U, -1);
                                (*(s32 *)((u8 *)(temp_19) + 0x30C)) = 0;
                            }
                        } else {
                            if ((temp_f20_7 < 100.0f) && (temp_4_3 != 1)) {
                                if ((*(s32 *)((u8 *)(temp_19) + 0x398)) != 0) {
                                    var_3_2 = func_00382498(2, 4);
                                } else {
                                    var_3_2 = 2;
                                }
                                var_2 = 1;
                                (*(s32 *)((u8 *)(temp_19) + 0x304)) = var_3_2;
                                goto block_199;
                            }
                            if ((temp_f20_7 >= 196.0f) && ((*(s32 *)((u8 *)(temp_19) + 0x30C)) != 3)) {
                                var_3_3 = D_L23_001DE360;
                                if ((*(s32 *)((u8 *)(temp_19) + 0x398)) == 0) {
                                    var_3_3 = D_L23_001DE35C;
                                }
                                var_2 = 3;
                                (*(s32 *)((u8 *)(temp_19) + 0x304)) = var_3_3;
                                goto block_199;
                            }
                            var_2_2 = 2;
                            if ((*(s32 *)((u8 *)(temp_19) + 0x330)) <= 0) {
                                var_2_2 = 1;
                                if ((*(s32 *)((u8 *)(temp_19) + 0x398)) != 0) {
                                    var_3_4 = 2;
                                } else {
                                    var_2_2 = 2;
                                    goto block_197;
                                }
                            } else {
block_197:
                                var_3_4 = 1;
                            }
                            (*(s32 *)((u8 *)(temp_19) + 0x304)) = var_2_2;
                            (*(s32 *)((u8 *)(temp_19) + 0x30C)) = var_3_4;
                            goto block_200;
                        }
                    } else {
block_199:
                        (*(s32 *)((u8 *)(temp_19) + 0x30C)) = var_2;
                        goto block_200;
                    }
                } else {
block_200:
                    temp_3_7 = (*(s32 *)((u8 *)(temp_19) + 0x30C));
                    switch (temp_3_7) {             /* switch 5; irregular */
                    case 3:                         /* switch 5 */
                        if (temp_f20_7 < 196.0f) {
                            (*(f32 *)((u8 *)(temp_19) + 0x32C)) = 30.0f;
                            if ((*(s32 *)((u8 *)(temp_19) + 0x334)) != 0) {
                                var_5_4 = 9;
                            } else {
                                var_5_4 = 6;
                            }
                        } else {
                            temp_2_6 = (*(s32 *)((u8 *)(temp_19) + 0x334));
                            if (temp_f20_7 > 2500.0f) {
                                (*(f32 *)((u8 *)(temp_19) + 0x32C)) = 30.0f;
                                if (temp_2_6 != 0) {
                                    var_5_4 = 9;
                                } else {
                                    var_5_4 = 5;
                                }
                            } else if (temp_2_6 == 0) {
                                var_5_4 = 8;
                            } else {
                                var_5_4 = 0xA;
                            }
                        }
                        goto block_236;
                    case 2:                         /* switch 5 */
                        var_5_4 = 9;
                        if ((*(s32 *)((u8 *)(temp_19) + 0x334)) != 0) {
                            goto block_236;
                        }
                        var_5_7 = 6;
                        if (temp_f20_7 < 100.0f) {
                            var_f0_3 = 16.0f;
                            goto block_232;
                        }
                        if (!(temp_f20_7 > 324.0f)) {
                            if ((*(s32 *)((u8 *)(temp_19) + 0x300)) == 3) {
                                var_5_4 = 4;
                            } else {
                                var_5_4 = 0xC;
                            }
                            goto block_236;
                        }
                        var_f0_3 = 16.0f;
block_231:
                        var_5_7 = 5;
block_232:
                        (*(f32 *)((u8 *)(temp_19) + 0x32C)) = var_f0_3;
                        func_L01_004450F0(arg0, var_5_7, -1);
                        break;
                    case 1:                         /* switch 5 */
                        var_5_4 = 9;
                        if ((*(s32 *)((u8 *)(temp_19) + 0x334)) != 0) {
                            goto block_236;
                        }
                        if (!(temp_f20_7 > 100.0f)) {
                            if ((*(s32 *)((u8 *)(temp_19) + 0x300)) == 3) {
                                var_5_4 = 4;
                            } else {
                                var_5_4 = 0xB;
                            }
                            goto block_236;
                        }
                        var_f0_3 = 9.0f;
                        goto block_231;
                    }
                }
            } else {
                (*(s32 *)((u8 *)(temp_19) + 0x304)) = 0;
                var_5_4 = 6;
                (*(f32 *)((u8 *)(temp_19) + 0x32C)) = 30.0f;
                goto block_236;
            }
            break;
        case 8:                                     /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                temp_3_8 = (*(u8 *)((u8 *)(arg0) + 0x43));
                if ((*(s32 *)((u8 *)(temp_19) + 0x300)) == 3) {
                    if (temp_3_8 != 7) {
                        func_003C3A10(arg0, 7, 0, 5);
                    }
                } else if (temp_3_8 != 0xE) {
                    func_003C3A10(arg0, 0xE, 0, 5);
                }
            }
            temp_4_4 = (*(u8 *)((u8 *)(arg0) + 0x42));
            if ((temp_4_4 == (*(u8 *)((u8 *)(arg0) + 0x43))) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                if ((*(s32 *)((u8 *)(temp_19) + 0x300)) == 3) {
                    if (temp_4_4 != 8) {
                        func_003C3A10(arg0, 8, 0, 5);
                    }
                } else if (temp_4_4 != 0xF) {
                    func_003C3A10(arg0, 0xF, 0, 5);
                }
                (*(s32 *)((u8 *)(temp_19) + 0x334)) = 1;
                func_L01_004450F0(arg0, 7U, -1);
            }
            var_5_8 = arg0 + 0x10;
            var_f12_3 = func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x170)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x174)) - (*(f32 *)((u8 *)(arg0) + 0x14)));
            var_2_3 = (*(s32 *)((u8 *)(temp_19) + 0x300)) ^ 3;
block_393:
            func_L23_003B3BB8(arg0, var_5_8, (var_2_3 != 0) ? 0 : 3, var_f12_3);
            break;
        case 9:                                     /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                temp_3_9 = (*(u8 *)((u8 *)(arg0) + 0x43));
                if ((*(s32 *)((u8 *)(temp_19) + 0x300)) == 3) {
                    if (temp_3_9 != 0xB) {
                        func_003C3A10(arg0, 0xB, 0, 5);
                    }
                } else if (temp_3_9 != 0x12) {
                    func_003C3A10(arg0, 0x12, 0, 5);
                }
            }
            temp_4_5 = (*(u8 *)((u8 *)(arg0) + 0x42));
            if ((temp_4_5 == (*(u8 *)((u8 *)(arg0) + 0x43))) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                if ((*(s32 *)((u8 *)(temp_19) + 0x300)) == 3) {
                    if (temp_4_5 != 4) {
                        func_003C3A10(arg0, 4, 0, 5);
                    }
                } else if (temp_4_5 != 0) {
                    func_003C3A10(arg0, 0, 0, 5);
                }
                (*(s32 *)((u8 *)(temp_19) + 0x334)) = 0;
                func_L01_004450F0(arg0, 7U, -1);
            }
            var_5_8 = arg0 + 0x10;
            var_f12_3 = func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x170)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x174)) - (*(f32 *)((u8 *)(arg0) + 0x14)));
            var_2_3 = (*(s32 *)((u8 *)(temp_19) + 0x300)) ^ 3;
            goto block_393;
        case 10:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                temp_2_7 = (*(s32 *)((u8 *)(temp_19) + 0x304));
                if ((*(s32 *)((u8 *)(temp_19) + 0x300)) == 3) {
                    if (temp_2_7 & 1) {
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xA) {
                            var_5_9 = 0xA;
                            goto block_277;
                        }
                    } else if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 9) {
                        var_5_9 = 9;
                        goto block_277;
                    }
                } else if (temp_2_7 & 1) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x11) {
                        var_5_9 = 0x11;
block_277:
                        func_003C3A10(arg0, var_5_9, 0, 5);
                    }
                } else if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x10) {
                    func_003C3A10(arg0, 0x10, 0, 5);
                }
                var_f0_4 = 0x3FC00000;
                if ((*(s32 *)((u8 *)(temp_19) + 0x398)) != 0) {
                    var_f0_4 = 0x40000000;
                }
                (*(s32 *)((u8 *)(arg0) + 0x48)) = var_f0_4;
            }
            temp_f0_5 = func_L01_004395E0(arg0);
            if (!(temp_f0_5 < 47.0f)) {
                if (!(temp_f0_5 > 52.0f)) {
                    func_L23_003B3BB8(arg0, arg0 + 0x10, (((*(s32 *)((u8 *)(temp_19) + 0x300)) ^ 3) != 0) ? 0 : 3, (*(f32 *)((u8 *)(arg0) + 0xF8)));
                } else {
                    goto block_287;
                }
            } else {
block_287:
                func_L23_003B3BB8(arg0, arg0 + 0x10, (((*(s32 *)((u8 *)(temp_19) + 0x300)) ^ 3) != 0) ? 0 : 3, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x170)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x174)) - (*(f32 *)((u8 *)(arg0) + 0x14))));
            }
            if (func_L01_0044E1B8(arg0, 0x423C0000) != 0) {
                func_003C2EC0();
                sp0 = sp50;
                if ((*(s32 *)((u8 *)(temp_19) + 0x300)) == 3) {
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                    sp10 = (*(f32 *)((u8 *)(temp_19) + 0x170));
                    temp_f20_8 = func_0038CED8(&sp10);
                    sp10 = func_0038D098((*(f32 *)((u8 *)(arg0) + 0xF8))) * temp_f20_8;
                    sp14 = func_0038D0B0((*(f32 *)((u8 *)(arg0) + 0xF8))) * temp_f20_8;
                    func_0038CF68(&sp10, &sp10, D_L23_001DE344);
                } else {
                    sp10 = func_0038D098(4e-45f) * D_L23_001DE344;
                    temp_f0_6 = func_0038D0B0((*(f32 *)((u8 *)(arg0) + 0xF8)));
                    sp18 = 0.0f;
                    sp14 = temp_f0_6 * D_L23_001DE344;
                }
                func_L23_003BB7C8(arg0, sp, &sp10, D_L23_001DE34C, D_L23_001DE348, D_L23_001DE350);
                (*(f32 *)((u8 *)(temp_19) + 0x34C)) = 0.0f;
            }
            if (func_L01_0044E1B8(arg0, 0x42800000) != 0) {
                (*(s32 *)((u8 *)(temp_19) + 0x304)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0x304)) - 1);
                func_L01_004450F0(arg0, 7U, -1);
            }
            break;
        case 11:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                if ((*(s32 *)((u8 *)(temp_19) + 0x304)) & 1) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x15) {
                        func_003C3A10(arg0, 0x15, 0, 5);
                    }
                } else if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x16) {
                    func_003C3A10(arg0, 0x16, 0, 5);
                }
                var_f0_5 = 0x3FC00000;
                if ((*(s32 *)((u8 *)(temp_19) + 0x398)) != 0) {
                    var_f0_5 = 0x40000000;
                }
                (*(s32 *)((u8 *)(arg0) + 0x48)) = var_f0_5;
            }
            temp_f0_7 = func_L01_004395E0(arg0);
            if (temp_f0_7 >= 23.0f) {
                var_4 = &D_1A4BE0;
                if (temp_f0_7 <= 26.0f) {
                    temp_f12_2 = D_L23_001DE36C;
                    if ((*(s32 *)((u8 *)(temp_19) + 0x304)) & 1) {
                        func_L01_004468C8(arg0, 4, D_L23_001DE370, 0, 1, 0, temp_f12_2, D_L23_001DE374, 0x3F800000);
                    } else {
                        func_L01_004468C8(arg0, 3, D_L23_001DE370, 0, 1, 0, temp_f12_2, D_L23_001DE374, 0x3F800000);
                    }
                    goto block_311;
                }
            } else {
block_311:
                var_4 = &D_1A4BE0;
            }
            if ((*(s32 *)((u8 *)(var_4) + 0x2808)) == arg0) {
                (*(s32 *)((u8 *)(temp_19) + 0x38C)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0x38C)) + 1);
                (*(s32 *)((u8 *)(var_4) + 0x2808)) = 0;
                if ((*(s32 *)((u8 *)(temp_19) + 0x38C)) >= 3) {
                    (*(s32 *)((u8 *)(temp_19) + 0x304)) = 1;
                }
            }
            if ((temp_f0_7 >= 23.0f) && (temp_f0_7 <= 25.0f)) {
                temp_f20_9 = temp_f0_7 - 23.0f;
                (*(f32 *)((u8 *)(temp_19) + 0x110)) = (f32) (func_0038D098(*(f32 *)&var_4) * (D_L23_001DE378 * temp_f20_9 * 0.5f));
                temp_f0_8 = func_0038D0B0((*(f32 *)((u8 *)(arg0) + 0xF8)));
                (*(s32 *)((u8 *)(temp_19) + 0x118)) = 0;
                (*(f32 *)((u8 *)(temp_19) + 0x114)) = (f32) (temp_f0_8 * (D_L23_001DE378 * temp_f20_9 * 0.5f));
            }
            if (func_L01_0044E1B8(arg0, 0x422C0000) != 0) {
                (*(s32 *)((u8 *)(arg0) + 0x48)) = 0x3F800000;
                (*(s32 *)((u8 *)(temp_19) + 0x304)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0x304)) - 1);
                func_L01_004450F0(arg0, 7U, -1);
                (*(f32 *)((u8 *)(temp_19) + 0x34C)) = 0.0f;
            }
            if ((*(s32 *)((u8 *)(temp_19) + 0x398)) != 0) {
                var_5_10 = arg0 + 0x10;
                var_f12_4 = func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x170)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x174)) - (*(f32 *)((u8 *)(arg0) + 0x14)));
block_359:
            } else {
                var_f12_4 = (*(f32 *)((u8 *)(arg0) + 0xF8));
                var_5_10 = arg0 + 0x10;
            }
            func_L23_003B3BB8(arg0, var_5_10, 0, var_f12_4);
            break;
        case 12:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                (*(u8 *)((u8 *)(arg0) + 0xBC)) = 1U;
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x17) {
                    func_003C3A10(arg0, 0x17, 0, 5);
                }
                *(s32 *)0x1A73E8 = 0;
                (*(s32 *)((u8 *)(temp_19) + 0x348)) = 0;
            }
            if (((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43))) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                if ((*(u8 *)((u8 *)(arg0) + 0xBC)) == 1) {
                    (*(s32 *)((u8 *)(temp_19) + 0x330)) = (s32) D_L23_001DE390;
                    (*(u8 *)((u8 *)(arg0) + 0xBC)) = 2U;
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x18) {
                        func_003C3A10(arg0, 0x18, 0, 0);
                    }
                }
            }
            if ((*(u8 *)((u8 *)(arg0) + 0xBC)) == 2) {
                func_003C2EC0();
                var_16 = 0;
                do {
                    temp_6 = var_16 * 4;
                    temp_3_10 = D_L23_001DEC40 + temp_6;
                    temp_f1_4 = (f32) (D_L23_001DE390 - (*(s32 *)((u8 *)(temp_19) + 0x330))) / 50.0f;
                    var_f0_6 = (f32) (temp_3_10 - (((s32) ((temp_3_10 > -1) ? temp_3_10 : (temp_3_10 + 0xF)) >> 4) * 0x10));
                    if (!(temp_f1_4 > 1.0f)) {
                        var_f0_6 *= temp_f1_4;
                    }
                    temp_f20_10 = var_f0_6 / 15.0f;
                    func_0038CE20(&sp40, sp, (f32)(temp_6));
                    sp48 = 0;
                    0 /* unknown instruction: vadd.xyz $vf2, $vf2, $vf1 */;
                    sp50 = sp30;
                    func_003C4098(&sp40, &sp50, &sp40, temp_f20_10);
                    temp_f0_9 = func_003C4088(1.0f, D_L23_001DE380, temp_f20_10);
                    if ((*(s32 *)((u8 *)(temp_19) + 0x348)) != 0) {
                        var_16 += 1;
                    } else {
                        var_16 += 1;
                        if ((func_L01_00446780(arg0, &sp40, D_L23_001DE384, 5, 1, 0, temp_f0_9, D_L23_001DE388, 0) != 0) && ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x2808)) == arg0)) {
                            (*(s32 *)((u8 *)(temp_19) + 0x348)) = 1;
                            (*(s32 *)((u8 *)(temp_19) + 0x330)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0x330)) - 0x32);
                        }
                    }
                } while (var_16 < 4);
                var_21 = 0;
                if (D_L23_001DE39C > 0) {
                    do {
                        sp40 = sp30;
                        temp_4_6 = D_L23_001DE390 - (*(s32 *)((u8 *)(temp_19) + 0x330));
                        var_f0_7 = (f32) temp_4_6 / 17.0f;
                        if (var_f0_7 > 1.0f) {
                            var_f0_7 = 1.0f;
                        }
                        var_21 += 1;
                        temp_f21_2 = func_003824E0(temp_4_6, 0);
                        func_00382580(&sp50, 0, D_L23_001DE398);
                        sp50 += sp0;
                        sp54 += sp4;
                        temp_17_2 = func_0038CF68(&sp50, &sp50, D_L23_001DE394);
                        temp_16_3 = func_00382498(0x11, 0x19);
                        func_L23_00456AA8(&sp40, &sp50, temp_17_2, temp_16_3, func_00382498(0x11, 0x19), ((temp_f21_2 * 0.5f) + 0.5f) * 4.0f);
                    } while (var_21 < D_L23_001DE39C);
                }
                if ((*(s32 *)((u8 *)(temp_19) + 0x330)) <= 0) {
                    (*(u8 *)((u8 *)(arg0) + 0xBC)) = 3U;
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x19) {
                        func_003C3A10(arg0, 0x19, 0, 5);
                    }
                }
            }
            temp_4_7 = (*(u8 *)((u8 *)(arg0) + 0x42));
            if ((temp_4_7 == (*(u8 *)((u8 *)(arg0) + 0x43))) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) && ((*(u8 *)((u8 *)(arg0) + 0xBC)) == 3)) {
                if (temp_4_7 != 0) {
                    func_003C3A10(arg0, 0, 0, 5);
                }
                (*(s32 *)((u8 *)(temp_19) + 0x304)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0x304)) - 1);
                (*(s32 *)((u8 *)(temp_19) + 0x330)) = (s32) D_L23_001DE38C;
                func_L01_004450F0(arg0, 7U, -1);
                (*(f32 *)((u8 *)(temp_19) + 0x34C)) = 0.0f;
            }
            var_f12_4 = (*(f32 *)((u8 *)(arg0) + 0xF8));
            var_5_10 = arg0 + 0x10;
            goto block_359;
        case 13:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                temp_3_11 = (*(u8 *)((u8 *)(arg0) + 0x43));
                if ((*(s32 *)((u8 *)(temp_19) + 0x300)) == 3) {
                    if (temp_3_11 != 0xC) {
                        func_003C3A10(arg0, 0xC, 0, 3);
                    }
                } else {
                    if (temp_3_11 != 0x13) {
                        func_003C3A10(arg0, 0x13, 0, 3);
                    }
                    (*(s32 *)((u8 *)(arg0) + 0x48)) = 0x40000000;
                }
                temp_f2 = (*(f32 *)((u8 *)(temp_19) + 0x30));
                temp_f1_5 = (*(f32 *)((u8 *)(temp_19) + 0x338)) - temp_f2;
                (*(f32 *)((u8 *)(temp_19) + 0x338)) = temp_f2;
                (*(s32 *)((u8 *)(temp_19) + 0x30C)) = -1;
                (*(s32 *)((u8 *)(temp_19) + 0x304)) = 0;
                (*(f32 *)((u8 *)(temp_19) + 0x34C)) = (f32) ((*(f32 *)((u8 *)(temp_19) + 0x34C)) + temp_f1_5);
                if ((*(u8 *)((u8 *)(arg0) + 0x94)) == 0xC) {
                    (*(s32 *)((u8 *)(temp_19) + 0x330)) = (s32) D_L23_001DE38C;
                }
            }
            temp_f1_6 = (*(f32 *)((u8 *)(temp_19) + 0x380));
            temp_f0_10 = D_L23_001DE33C;
            var_f20 = temp_f0_10;
            if (temp_f1_6 < temp_f0_10) {
                var_f20 = temp_f1_6;
            }
            (*(f32 *)((u8 *)(temp_19) + 0x380)) = (f32) (temp_f1_6 - var_f20);
            sp0 = func_0038D098((*(f32 *)((u8 *)(temp_19) + 0x384))) * var_f20;
            temp_f0_11 = func_0038D0B0((*(f32 *)((u8 *)(temp_19) + 0x384))) * var_f20;
            sp8 = 0.0f;
            sp4 = temp_f0_11;
            func_L01_0045AA30(arg0, sp);
            sp10 = func_0038D098((*(f32 *)((u8 *)(temp_19) + 0x384))) * D_L23_001DE328;
            temp_f0_12 = func_0038D0B0((*(f32 *)((u8 *)(temp_19) + 0x384)));
            temp_f1_7 = D_L23_001DE328;
            sp18 = 0.0f;
            sp14 = temp_f0_12 * temp_f1_7;
            0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
            sp18 += sp10;
            func_L01_00446780(arg0, &sp10, D_L23_001DE370, 0, 1, 0, temp_f1_7, 100.0f, 0x3F800000);
            (*(s32 *)((u8 *)(temp_19) + 0x33C)) = (s32) (D_L23_001DEC40 + 2);
            if ((((*(u8 *)((u8 *)(arg0) + 0x43)) == 0x13) && (func_L01_0044E1B8(arg0, 0x41900000) != 0)) || ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                temp_3_12 = (*(u8 *)((u8 *)(arg0) + 0x95));
                (*(s32 *)((u8 *)(arg0) + 0x48)) = 0x3F800000;
                switch (temp_3_12) {                /* switch 6; irregular */
                case 1:                             /* switch 6 */
                    var_5_11 = 1;
block_387:
                    func_L01_004450F0(arg0, var_5_11, -1);
                    break;
                case 2:                             /* switch 6 */
                    var_5_11 = 2;
                    goto block_387;
                case 3:                             /* switch 6 */
                    if ((*(s32 *)((u8 *)(temp_19) + 0x300)) != temp_3_12) {
                        if (D_L23_001DE340 <= (*(f32 *)((u8 *)(temp_19) + 0x34C))) {
                            (*(f32 *)((u8 *)(temp_19) + 0x32C)) = 30.0f;
                            func_L01_004450F0(arg0, 6U, -1);
                        } else {
                            func_L01_004450F0(arg0, (*(u8 *)((u8 *)(arg0) + 0x94)), -1);
                        }
                    } else {
                        var_5_11 = 7;
                        goto block_387;
                    }
                    break;
                }
            }
            var_f12_3 = (*(f32 *)((u8 *)(arg0) + 0xF8));
            var_2_3 = (*(s32 *)((u8 *)(temp_19) + 0x300)) ^ 3;
            var_5_8 = arg0 + 0x10;
            goto block_393;
        case 14:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x1B) {
                    func_003C3A10(arg0, 0x1B, 0, 8);
                }
            } else if (func_L01_0044E1B8(arg0, 0x42A80000) != 0) {
                (*(s32 *)((u8 *)(arg0) + 0x48)) = 0;
                func_L01_003A9928(arg0);
            }
            break;
        }
    }
    func_L23_003B3908(arg0);
}
