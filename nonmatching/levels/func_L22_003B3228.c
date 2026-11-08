/* func_L22_003B3228: Opus handoff (prep by Sonnet worker w7, 2026-11-08)
   Size: 11472 bytes, places: 2 levels (22 27), file: src/levels/shared/L22_003B3228.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: one function (addiu sp,-0xC0), 2 switches / 2 jump tables (32 entries): +0x95, +0x20; also placed in level 27 (0039B560).
   Twin: none (rac2 index best func_L11_00425F10 at 0.20). Checked: callee fingerprint (callfp: 1 callee mapped); whole-corpus opcode search over every rac3 and rac2 function >= 600 B (best rac2:func_L20_00440598 0.19; rac3 siblings func_L01_00353EA0 0.39, func_L01_00350750 0.37); names.tsv/NAMES.md (no entry); matched rac3 siblings in src/ (only the scaffold is shared).
   Mapping: Common enemy/boss scaffold (matches the tools' names): arg0 = moby; +0x20 = state byte (func_L01_004450F0 = moby_set_state(moby, state, sub)), +0x95 = phase byte, +0x68 = per-object data, func_L01_004561B8 = animation-done test, func_003C3A10 = moby_anim_blend(moby, anim, 0, 8), func_0038CB00 = timer_tick_short, D_1A4BE0 = hero/global struct (+0x25C0 hero moby, +0x25C4 hero state, +0xC08 pad bits). $gp loads are named D_<0x1DC8B0+offset> (D_LNN_ when >= 0x1D9900) in the draft. func_00382468 (x33) is a small int helper (purpose not identified); func_L22_003B6B90/6D30/6EE8/71D0/8100/83A0 are L22 helpers. D_001D52FC is read via $gp (pointer-sized).
   Identical / changed / added / removed: n/a (no twin). Siblings func_L01_00353EA0 (0.39) and func_L01_00350750 (0.37) are unmatched too.
   VU0: 12 vadd.xyz/vsub.xyz ops in the retail asm; inline-asm VU0 is banned since 2026-11-06 (Matching-Patterns), so this function cannot reach MATCH unless the ops come from plain C; the lq/sq copies are fine (u128_t).
   Draft: compiles (m2c draft cleaned by tools/post.py (real repo prototypes where known, m2c gotos kept)); 2801 diff; opcode-equal 1614 of 2869 (mine 2559), ratio 0.59.
     Retail rows yours=2559 retail=2869 equalrows=68.
   Left for Opus:
     1. Check both places (22, 27) once near.
     2. Several m2c temps are really f32 vectors on the stack (sp10..); retail passes &sp+0x?? to func_003C4098/func_003C41A0.
     3. 12 VU0 ops: near miss only.
*/
extern f32 func_003824E0(f32, f32);
extern f32 func_0038CF38();
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_L01_0040E570(void *, void *);
extern int func_L01_004561B8(u8 *);
extern int func_L01_004561E0(void *a0);
extern s32 func_00382468();
extern s32 func_00382498(s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_003A52A0();
extern s32 func_L01_0041A5B0(s32, s32);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_0045A9F0(void *);
extern s32 func_L01_0045BD10(u8 *, f32);
extern s32 func_L01_00511A98(void);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C2EC0();
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern void func_L01_00315900(s32, s32, s32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern void func_L01_00404808(void *, s32);
extern void func_L01_0041A6E0(void);
extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00456230(u8 *, s32);
extern void func_L01_0045AA10(u8 *);
extern void func_L01_0045BD78(u8 *a0, f32 a, f32 b, f32 c, f32 d);
extern void func_L01_005003D0(s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_L22_003B6EE8(s32, s32);
s32 func_003C4098();  /* extern, call arities [5, 6], m2c proto was (f32 *, f32 *, f32 *, f32, f32, s32) */
s32 func_L01_004028B0(void *);                  /* extern */
f32 func_L01_004395E0(void *);                      /* extern */
s32 func_L01_004450F0(void *, u8, s32);     /* extern */
s32 func_L01_00446058(void *, s32, s32); /* extern */
s32 func_L01_004468C8(void *, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_L01_0044E1B8(void *, s32);             /* extern */
s32 func_L01_00454370(void *, void *);              /* extern */
s32 func_L01_0045A748(void *, f32 *);               /* extern */
s32 func_L01_0045A7A8();  /* K&R: prototype dropped, mismatch with m2c calls */
s32 func_L01_0045AA30(void *, f32 *);           /* extern */
s32 func_L01_0045BDE8(void *, s32);                 /* extern */
s32 func_L02_003A5010(void *);                  /* extern */
f32 func_L05_00441508(f32, f32, s32);           /* extern */
s32 func_L22_003B5EF8();                            /* extern */
s32 func_L22_003B6B90(void *);                  /* extern */
s32 func_L22_003B6D30(void *, void *);              /* extern */
s32 func_L22_003B71D0(void *, void *);              /* extern */
s32 func_L22_003B8100(void *);                  /* extern */
s32 func_L22_003B83A0(void *);                  /* extern */
s32 func_L22_0041FCC8(s32, s32);        /* extern */
extern s32 D_1A4BE0;
extern f32 D_1A4C60;
extern s32 D_1A7E18;
extern s32 D_1BBE90;
extern s32 D_1CCFD0;
extern s32 D_L22_001D6694;
extern s32 D_L22_001DE528;
extern s32 D_L22_001DFD9C;
extern s32 D_L22_001DFE80;
extern s32 D_L22_001E1FB8;
extern s32 D_L22_001E1FC0;
extern s32 D_L22_001E2000;
extern s32 D_L22_001E2040;
extern s32 D_L22_001E2080;
extern s32 D_L22_001E2084;
extern s32 D_L22_002BA430;
extern s32 D_L22_002E79F0;
extern s32 func_L22_003B7150;

extern void * D_001D52FC;
extern s32 D_001D545C;
extern s32 D_001D6694;
extern s32 D_L22_001DFE80;
extern s32 D_L22_001E1FB8;
extern s32 D_L22_001E2080;

void func_L22_003B3228(void *arg0) {
    s32 sp[8]; /* m2c: stack-slot base, size unknown */
    f32 sp24; /* m2c stack slot */
    s32 sp4; /* m2c stack slot */
    s32 sp44; /* m2c stack slot */
    f32 sp50; /* m2c stack slot */
    f32 sp54; /* m2c stack slot */
    f32 sp0;
    f32 sp8;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp20;
    f32 sp28;
    f32 sp30;
    f32 sp40;
    s32 var_4_3;
    s32 var_5_6;
    f32 *var_16;
    f32 temp_7_3;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f12;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f20_6;
    f32 var_f13;
    s16 temp_3;
    s16 temp_3_14;
    s16 temp_3_15;
    s16 temp_3_4;
    s32 *temp_16_2;
    s32 *var_12;
    s32 *var_14;
    s32 temp_16;
    s32 temp_2_10;
    s32 temp_2_11;
    s32 temp_2_14;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_2_7;
    s32 temp_2_8;
    s32 temp_2_9;
    s32 temp_3_10;
    s32 temp_3_11;
    s32 temp_3_12;
    s32 temp_3_5;
    s32 temp_3_6;
    s32 temp_4;
    s32 temp_4_4;
    s32 temp_4_5;
    s32 temp_5;
    s32 temp_5_2;
    s32 temp_5_3;
    s32 temp_5_8;
    s32 temp_5_9;
    s32 temp_6;
    s32 temp_6_2;
    s32 temp_6_4;
    s32 temp_7;
    s32 temp_7_4;
    s32 temp_7_5;
    s32 temp_8;
    s32 temp_8_2;
    s32 var_11;
    s32 var_16_2;
    s32 var_16_3;
    s32 var_16_4;
    s32 var_2_2;
    s32 var_2_5;
    s32 var_4;
    s32 var_5_2;
    s32 var_5_3;
    s32 var_5_5;
    s32 var_6;
    s32 var_6_2;
    s32 var_7;
    s32 var_8;
    s32 var_8_2;
    s32 var_8_3;
    s32 var_8_4;
    s32 var_9;
    s32 var_condition_bit;
    s32 var_condition_bit_2;
    s32 var_condition_bit_3;
    u16 temp_3_13;
    u16 temp_4_3;
    u8 *var_3_3;
    u8 *var_6_3;
    u8 temp_16_4;
    u8 temp_3_2;
    u8 temp_3_3;
    u8 temp_3_7;
    u8 temp_3_8;
    u8 temp_5_4;
    u8 temp_5_5;
    u8 temp_5_6;
    u8 temp_5_7;
    u8 var_2_3;
    u8 var_2_4;
    u8 var_5;
    u8 var_5_4;
    u8 *temp_13;
    u8 *temp_16_3;
    u8 *temp_16_5;
    u8 *temp_18;
    u8 *temp_19;
    u8 *temp_19_2;
    u8 *temp_2;
    u8 *temp_2_12;
    u8 *temp_2_13;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_3_9;
    u8 *temp_4_2;
    u8 *temp_6_3;
    u8 *temp_6_5;
    u8 *temp_6_6;
    u8 *temp_7_2;
    u8 *var_10;
    u8 *var_2;
    u8 *var_3;
    u8 *var_3_2;
    u8 *var_4_2;

    temp_18 = (*(void **)((u8 *)(arg0) + 0x68));
    if (func_L22_003B5EF8() != 0) {
        func_L01_004028B0(arg0);
        return;
    }
    if ((D_001D545C == 0x16) && ((*(s32 *)((u8 *)(temp_18) + 0x538)) == 0)) {
        func_L01_00446058(arg0, 0x1BA0, 0x1A4E);
        (*(s32 *)((u8 *)(temp_18) + 0x538)) = 1;
    }
    if (((*(s32 *)((u8 *)(temp_18) + 0x460)) == 0) && ((*(s16 *)((u8 *)(temp_18) + 0x234)) == 1)) {
        temp_2 = *(void **)0x1A71A0;
        if ((temp_2 != 0) && ((temp_3 = (*(s16 *)((u8 *)(temp_2) + 0xAA)), (temp_3 == 0x173B)) || (temp_3 == 0x1A4E))) {
            (*(s16 *)((u8 *)(temp_18) + 0x234)) = 0;
        }
    }
    temp_3_2 = (*(u8 *)((u8 *)(arg0) + 0x95));
    switch (temp_3_2) {                             /* switch 1 */
    case 0:                                         /* switch 1 */
        if (func_L01_00456250(D_L22_001DFD9C + ((*(s32 *)((u8 *)(temp_18) + 0x470)) << 8)) != 0) {
            func_L01_004450F0(arg0, 4U, 1);
            if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                func_003C3A10(arg0, 0, func_00382468(), 8);
            }
        }
    default:                                        /* switch 1 */
block_68:
        temp_3_3 = (*(u8 *)((u8 *)(arg0) + 0x20));
        switch (temp_3_3) {                         /* switch 2 */
        case 4:                                     /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                if ((*(u8 *)((u8 *)(arg0) + 0x94)) != 0x1D) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                        func_003C3A10(arg0, 0, func_00382468(), 8);
                    }
                } else if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 2) {
                    func_003C3A10(arg0, 2, 0, 8);
                }
            }
            func_L01_0045AA10(arg0);
            if (((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43))) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                if (((*(void **)((u8 *)(temp_18) + 0x230)) != 0) && (((*(void **)((u8 *)(&D_1A4BE0) + 0x25C0)) == 0) || ((temp_3_4 = (*(s16 *)((u8 *)((*(void **)((u8 *)(&D_1A4BE0) + 0x25C0))) + 0xAA)), (temp_3_4 != 0x173B)) && (temp_3_4 != 0x1A4E)))) {
                    func_00382468();
                    temp_16 = (func_00382468() != 0) ? 1 : 2;
                    func_003C3A10(arg0, temp_16, 0, (s32) ((func_00382498(6, 0xC) * 5) + 2) / 6);
                } else if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                    func_003C3A10(arg0, 0, func_00382468(), 8);
                default:                            /* switch 2 */
                }
            }
            break;
        case 2:                                     /* switch 2 */
            if (func_L01_004561E0(arg0) != 0) {
                (*(f32 *)((u8 *)(temp_18) + 0x4E8)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x18));
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x42)) == 5) {
                temp_f0 = func_L01_004395E0(arg0);
                if ((temp_f0 > 2.0f) && (temp_f0 < 10.0f)) {
                    func_0038CF68(&sp20, arg0 + 0xC0, 0.0f);
                    0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                    sp0 = (*(f32 *)((u8 *)(arg0) + 0x10));
                }
                var_condition_bit = temp_f0 > 2.0f;
                if (temp_f0 > 2.0f) {
                    func_003C41A0(&sp8, temp_18 + 0x440, (*(f32 *)((u8 *)(temp_18) + 0x4E8)) + 1.2f, 0.112500004f, 0.1875f, 0.075000003f);
                    var_condition_bit = temp_f0 > 2.0f;
                }
                if (var_condition_bit && (temp_f0 < 10.0f)) {
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                    sp10 = sp0;
                    func_L01_0045AA30(arg0, &sp10);
                    func_L01_0045BD10(arg0, func_0038D160((*(f32 *)((u8 *)(temp_18) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_18) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))));
                }
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                (*(s32 *)((u8 *)(temp_18) + 0x440)) = 0;
                var_5 = 3;
block_147:
                func_L01_004450F0(arg0, var_5, -1);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 8) {
                    var_5_2 = 8;
block_149:
                    func_003C3A10(arg0, var_5_2, 0, 0);
                }
            }
            break;
        case 3:                                     /* switch 2 */
            temp_f0_2 = func_L01_004395E0(arg0);
            if (temp_f0_2 < 22.0f) {
                func_0038CF68(&sp20, arg0 + 0xC0, 0.0f);
                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                sp0 = (*(f32 *)((u8 *)(arg0) + 0x10));
            }
            if (temp_f0_2 < 15.0f) {
                func_L01_0045BD10(arg0, func_0038D160((*(f32 *)((u8 *)(temp_18) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_18) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))));
                func_003C41A0(&sp8, temp_18 + 0x440, func_003C3D30(arg0 + 0x10, 0, 0, 0.5f), 0.0600000024f, 0.50000006f, 0.0600000024f);
            }
            if (temp_f0_2 < 22.0f) {
                0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                sp10 = sp0;
                func_L01_0045AA30(arg0, &sp10);
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                (*(s32 *)((u8 *)(temp_18) + 0x440)) = 0;
                func_L01_004450F0(arg0, 8U, -1);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                    var_6 = func_00382468();
                    var_5_3 = 4;
block_166:
                    func_003C3A10(arg0, var_5_3, var_6, 7);
                }
            }
            break;
        case 5:                                     /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                func_L01_0045BD78(arg0, 0.00320000015f, 0.0500000045f, 0.0100530973f, 0.251327425f);
            }
            func_L01_0045BD78(arg0, 0.00320000015f, 0.0500000045f, 0.0100530973f, 0.251327425f);
            if ((func_L01_0045BDE8(arg0, (*(s32 *)((u8 *)(temp_18) + 0x474))) != 0) || (func_0038CF38() < 6.0f)) {
                var_5_4 = 8;
block_469:
                func_L01_004450F0(arg0, var_5_4, -1);
            }
            break;
        case 8:                                     /* switch 2 */
            var_16 = temp_18 + 0x220;
            if (func_L01_004561B8(arg0) != 0) {
                func_L01_0045BD78(arg0, 0.00320000015f, 0.0500000045f, 0.0100530973f, 0.251327425f);
                var_16 = temp_18 + 0x220;
            }
            func_L01_0045A7A8(arg0, var_16, (*(f32 *)((u8 *)(temp_18) + 0x448)));
            if (func_0038CF38() < 1.85f) {
                if (func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xF8)), func_0038D160((*(f32 *)((u8 *)(temp_18) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_18) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14)))) < 0.34906584f) {
                    func_L01_004450F0(arg0, 0xAU, -1);
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 5) {
                        var_5_5 = 5;
block_179:
                        func_003C3A10(arg0, var_5_5, 1, 3);
                    }
                }
            }
            break;
        case 10:                                    /* switch 2 */
            if (func_L01_004561E0(arg0) != 0) {
                (*(f32 *)((u8 *)(temp_18) + 0x4E8)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x18));
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x42)) != 5) {
                func_L01_0045AA10(arg0);
            } else {
                temp_f0_3 = func_L01_004395E0(arg0);
                if ((temp_f0_3 > 2.0f) && (temp_f0_3 < 10.0f)) {
                    func_0038CF68(&sp20, arg0 + 0xC0, 0.09375f);
                    0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                    sp0 = (*(f32 *)((u8 *)(arg0) + 0x10));
                }
                if (temp_f0_3 > 5.0f) {
                    sp20 = (*(f32 *)((u8 *)(arg0) + 0x10));
                    if ((*(u8 *)((u8 *)(temp_18) + 0x5F)) != 0) {
                        func_L01_004468C8(arg0, 1, 0x10000, 0, 1, 0, 0x3F000000, 0x3F800000, 0x3F400000);
                    } else {
                        func_L01_004468C8(arg0, 1, 1, 0, 1, 0, 0x3F000000, 0x3F800000, 0x3F400000);
                    }
                    func_003C41A0(&sp8, temp_18 + 0x440, (*(f32 *)((u8 *)(temp_18) + 0x4E8)) + 0.6f, 0.112500004f, 0.1875f, 0.075000003f);
                }
                if (!(temp_f0_3 > 2.0f)) {
                    goto block_140;
                }
                if (!(temp_f0_3 < 10.0f)) {
block_140:
                    func_L01_0045AA10(arg0);
                } else {
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                    sp10 = sp0;
                    func_L01_0045AA30(arg0, &sp10);
                }
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                (*(s32 *)((u8 *)(temp_18) + 0x440)) = 0;
                if ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x2808)) == arg0) {
                    func_L01_004450F0(arg0, 0xCU, -1);
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 6) {
                        var_5_2 = 6;
                        goto block_149;
                    }
                } else {
                    var_5 = 0xB;
                    goto block_147;
                }
            }
            break;
        case 11:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                (*(f32 *)((u8 *)(temp_18) + 0x444)) = 0.083333336f;
            }
            temp_f0_4 = func_L01_004395E0(arg0);
            if (temp_f0_4 > 15.0f) {
                (*(f32 *)((u8 *)(temp_18) + 0x444)) = (f32) ((*(f32 *)((u8 *)(temp_18) + 0x444)) - 0.004f);
            }
            if (temp_f0_4 < 22.0f) {
                func_0038CF68(&sp20, arg0 + 0xC0, (*(f32 *)((u8 *)(temp_18) + 0x444)));
                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                sp0 = (*(f32 *)((u8 *)(arg0) + 0x10));
            }
            if (temp_f0_4 < 15.0f) {
                func_003C41A0(&sp8, temp_18 + 0x440, func_003C3D30(arg0 + 0x10, 0, 0, 0.5f), 0.0600000024f, 0.50000006f, 0.0600000024f);
            }
            if (!(temp_f0_4 < 22.0f)) {
                func_L01_0045AA10(arg0);
            } else {
                0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                sp10 = sp0;
                func_L01_0045AA30(arg0, &sp10);
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                (*(s32 *)((u8 *)(temp_18) + 0x440)) = 0;
                func_L01_004450F0(arg0, 0xDU, -1);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 1) {
                    var_5_3 = 1;
                    var_6 = 8;
                    goto block_166;
                }
            }
            break;
        case 12:                                    /* switch 2 */
            temp_f0_5 = func_L01_004395E0(arg0);
            var_condition_bit_2 = temp_f0_5 < 7.0f;
            if (temp_f0_5 < 7.0f) {
                func_0038CF68(&sp20, arg0 + 0xC0, 0.0f);
                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                sp0 = (*(f32 *)((u8 *)(arg0) + 0x10));
                var_condition_bit_2 = temp_f0_5 < 7.0f;
            }
            if (var_condition_bit_2) {
                func_003C41A0(&sp8, temp_18 + 0x440, func_003C3D30(arg0 + 0x10, 0, 0, 0.5f), 0.0285714287f, 0.128571436f, 0.0571428575f);
            }
            if (!(temp_f0_5 < 7.0f)) {
                func_L01_0045AA10(arg0);
            } else {
                0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                sp10 = sp0;
                func_L01_0045AA30(arg0, &sp10);
            }
            if (func_L01_0044E1B8(arg0, 0x41200000) != 0) {
                (*(s32 *)((u8 *)(temp_18) + 0x440)) = 0;
                func_L01_004450F0(arg0, 0xEU, -1);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 7) {
                    var_5_5 = 7;
                    goto block_179;
                }
            }
            break;
        case 14:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                (*(f32 *)((u8 *)(temp_18) + 0x4E8)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x18));
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x42)) == 7) {
                temp_f0_6 = func_L01_004395E0(arg0);
                var_condition_bit_3 = temp_f0_6 > 2.0f;
                if (temp_f0_6 > 2.0f) {
                    if (temp_f0_6 < 18.0f) {
                        func_0038CF68(&sp20, arg0 + 0xC0, -0.084375f);
                        0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                        sp0 = (*(f32 *)((u8 *)(arg0) + 0x10));
                    }
                    var_condition_bit_3 = temp_f0_6 > 2.0f;
                }
                if (var_condition_bit_3) {
                    if (temp_f0_6 < 12.0f) {
                        func_003C41A0(&sp8, temp_18 + 0x440, (*(f32 *)((u8 *)(temp_18) + 0x4E8)) + 1.0f, 0.100000001f, 0.200000003f, 0.100000001f);
                    }
                }
                if (temp_f0_6 == 12.0f) {
                    (*(s32 *)((u8 *)(temp_18) + 0x440)) = 0;
                }
                if ((temp_f0_6 > 12.0f) && (temp_f0_6 < 18.0f)) {
                    func_003C41A0(&sp8, temp_18 + 0x440, func_003C3D30(arg0 + 0x10, 0, 0, 0.5f), 0.027777778f, 0.333333343f, 0.25f);
                }
                if (!(temp_f0_6 > 2.0f)) {
                    goto block_203;
                }
                if (!(temp_f0_6 < 18.0f)) {
block_203:
                    func_L01_0045AA10(arg0);
                } else {
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                    sp10 = sp0;
                    func_L01_0045AA30(arg0, &sp10);
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    if (func_00382468() == 0) {
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xD) {
                            func_003C3A10(arg0, 0xD, 0, 7);
                        }
                        var_5_4 = 0xF;
                        goto block_469;
                    }
                    func_L01_004450F0(arg0, 8U, -1);
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                        var_6_2 = 0;
block_214:
                        func_003C3A10(arg0, 4, var_6_2, 5);
                    }
                }
            }
            break;
        case 15:                                    /* switch 2 */
            func_L01_0045AA10(arg0);
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                func_L01_004450F0(arg0, 8U, -1);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                    var_6_2 = func_00382468();
                    goto block_214;
                }
            }
            break;
        case 13:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                (*(s32 *)((u8 *)(temp_18) + 0x458)) = 0;
            }
            func_L01_0045AA10(arg0);
            if ((*(u8 *)((u8 *)(arg0) + 0x42)) == 1) {
                func_003C2EC0();
                temp_f20 = func_0038D160(sp50, sp54);
                if (func_0038DBA0(temp_f20, func_0038D160((*(f32 *)((u8 *)(temp_18) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_18) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14)))) < 0.43633232f) {
                    (*(s32 *)((u8 *)(temp_18) + 0x458)) = (s32) ((*(u16 *)((u8 *)(arg0) + 0x96)) + 5);
                }
                temp_3_5 = (*(s32 *)((u8 *)(temp_18) + 0x458));
                if (((temp_3_5 != 0) && ((*(u16 *)((u8 *)(arg0) + 0x96)) == temp_3_5)) || ((*(f32 *)((u8 *)(&D_1A4BE0) + 0x174)) > 0.040000003f)) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                        func_003C3A10(arg0, 4, func_00382468(), 5);
                    }
                    func_L01_004450F0(arg0, 8U, -1);
                }
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 2) {
                    func_003C3A10(arg0, 2, 0, 5);
                }
                func_L01_004450F0(arg0, 0x10U, -1);
            }
            /* fallthrough */
        case 16:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                (*(s32 *)((u8 *)(temp_18) + 0x458)) = 0;
            }
            func_L01_0045AA10(arg0);
            if ((*(u8 *)((u8 *)(arg0) + 0x42)) == 2) {
                func_003C2EC0();
                temp_f20_2 = func_0038D160(sp20, sp24);
                if (func_0038DBA0(temp_f20_2, func_0038D160((*(f32 *)((u8 *)(temp_18) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_18) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14)))) < 0.43633232f) {
                    (*(s32 *)((u8 *)(temp_18) + 0x458)) = (s32) ((*(u16 *)((u8 *)(arg0) + 0x96)) + 5);
                }
                if (((*(s16 *)((u8 *)(temp_18) + 0x234)) == 1) && (((temp_3_6 = (*(s32 *)((u8 *)(temp_18) + 0x458)), (temp_3_6 != 0)) && ((*(u16 *)((u8 *)(arg0) + 0x96)) == temp_3_6)) || ((*(f32 *)((u8 *)(&D_1A4BE0) + 0x174)) > 0.040000003f))) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                        func_003C3A10(arg0, 4, func_00382468(), 5);
                    }
                    func_L01_004450F0(arg0, 8U, -1);
                }
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                    func_003C3A10(arg0, 0, func_00382468(), 7);
                }
                var_5_4 = 4;
                goto block_469;
            }
            break;
        case 18:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                (*(s32 *)((u8 *)(temp_18) + 0x454)) = func_00382498(0x19, 0x2A);
            }
            temp_2_2 = (*(void **)((u8 *)(temp_18) + 0x230));
            temp_2_3 = (*(void **)((u8 *)(temp_18) + 0x230));
            temp_f20_3 = func_0038D160((*(f32 *)((u8 *)(temp_2_2) + 0x10)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_2_2) + 0x14)) - (*(f32 *)((u8 *)(arg0) + 0x14)));
            func_L01_0045AA10(arg0);
            var_f13 = 0.0f;
            if ((*(f32 *)((u8 *)(arg0) + 0xF8)) > 0.08726646f) {
                var_f13 = 1.0f;
            }
            if (func_0038DBA0(temp_f20_3, var_f13) == 0.0f) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                    func_003C3A10(arg0, 0, func_00382468(), 8);
                }
            } else if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 3) {
                func_003C3A10(arg0, 3, func_00382468(), 8);
            }
            if (func_0038CAD0(temp_18 + 0x454) != 0) {
                var_5_4 = 0x13;
                goto block_469;
            }
            break;
        case 19:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x17) {
                    func_003C3A10(arg0, 0x17, 0, 8);
                }
                (*(f32 *)((u8 *)(arg0) + 0x48)) = func_003824E0(0.800000012f, 1.20000005f);
            }
            temp_2_4 = (*(void **)((u8 *)(temp_18) + 0x230));
            func_L01_0045AA10(arg0);
            temp_3_7 = (*(u8 *)((u8 *)(arg0) + 0x43));
            if (((*(s32 *)((u8 *)(temp_18) + 0x4C0)) > 0) && ((*(s32 *)((u8 *)(temp_18) + 0x4A0)) == 0)) {
                if (temp_3_7 == 0x17) {
                    if (((*(u8 *)((u8 *)(arg0) + 0x42)) == temp_3_7) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                        func_003C3A10(arg0, 0, func_00382468(), 7);
                        func_L22_003B6EE8(arg0, 1);
                        var_5_4 = 0x14;
                        goto block_469;
                    }
                }
            } else if (temp_3_7 == 0x17) {
                if (((*(u8 *)((u8 *)(arg0) + 0x42)) == temp_3_7) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                    func_003C3A10(arg0, 0, func_00382468(), 7);
                    func_L01_004450F0(arg0, 4U, 1);
                }
            }
            break;
        case 20:                                    /* switch 2 */
            sp0 = (*(f32 *)((u8 *)((((*(s32 *)((u8 *)(temp_18) + 0x4B4)) << 7) + D_L22_001DFE80)) + 0x30));
            temp_6 = (*(s32 *)((u8 *)(&D_1A7E18) + 0x2B4)) & (1 << *(s32 *)0x1D545C);
            sp10 = (*(f32 *)((u8 *)((((*(s32 *)((u8 *)(temp_18) + 0x4B8)) << 7) + D_L22_001DFE80)) + 0x30));
            if (temp_6 == 0) {
                func_L01_0041A5B0(0xB96, 0x39);
            }
            func_L22_0041FCC8(0, 1);
            if (func_L01_004561B8(arg0) == 0) {
                temp_3_8 = (*(u8 *)((u8 *)(arg0) + 0x43));
                var_16_2 = 0;
                if (temp_3_8 == 0x17) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x42)) == temp_3_8) {
                        if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                            func_003C3A10(arg0, 0, func_00382468(), 7);
                        }
                    }
                } else {
                    temp_4 = D_L22_001DFE80;
                    if (func_L01_0040E570(sp, arg0 + 0x10) < 0.1f) {
                        sp20 = (*(f32 *)((u8 *)((((*(s32 *)((u8 *)(temp_18) + 0x4B4)) << 7) + temp_4)) + 0x30));
                        sp30 = (*(f32 *)((u8 *)((((*(s32 *)((u8 *)(temp_18) + 0x4B8)) << 7) + temp_4)) + 0x30));
                        sp40 = (*(f32 *)((u8 *)((((*(s32 *)((u8 *)(temp_18) + 0x4BC)) << 7) + temp_4)) + 0x30));
                        temp_f20_4 = func_0038D160((f32)(temp_4), sp30 - sp20);
                        temp_f20_5 = func_L05_00441508(temp_f20_4, func_0038D160(sp40 - sp20, sp44 - sp24), 0x3E800000);
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                            func_003C3A10(arg0, 0, func_00382468(), 7);
                        }
                        func_L01_0045AA10(arg0);
                        var_16_2 = 1;
                    } else {
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 3) {
                            func_003C3A10(arg0, 3, func_00382468(), 7);
                        }
                        func_L01_0045A748(arg0, sp);
                    }
                }
                if ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) == 0x58) {
                    var_16_2 += 1;
                    goto block_296;
                }
                var_2 = D_001D52FC;
                if (func_L01_00511A98() == 2) {
                    func_L01_005003D0(0x58, 1);
block_296:
                    var_2 = *(void **)0x1D52FC;
                }
                temp_2_5 = (*(s32 *)((u8 *)(var_2) + 0x1A0));
                if (temp_2_5 & 0x10) {
                    (*(s16 *)((u8 *)(&D_1A7E18) + 0x2AC)) = 0xFFFF;
                    func_L01_0041A6E0();
                    var_5_4 = 0x1D;
                    goto block_469;
                }
                if (temp_2_5 & 0x40) {
                    if (var_16_2 >= 2) {
                        (*(s16 *)((u8 *)(&D_1A7E18) + 0x2AC)) = 0xFFFF;
                        func_L01_0041A6E0();
                        (*(s32 *)((u8 *)(temp_18) + 0x498)) = 0;
                        var_5_4 = 0x15;
                        goto block_469;
                    }
                }
            } else {
                (*(s32 *)((u8 *)(temp_18) + 0x4AC)) = 0;
                (*(s32 *)((u8 *)(temp_18) + 0x4A4)) = 0;
            }
            break;
        case 21:                                    /* switch 2 */
            temp_19 = ((*(s32 *)((u8 *)((temp_18 + ((*(s32 *)((u8 *)(temp_18) + 0x498)) * 4))) + 0x4C0)) * 0x188) + &D_L22_002BA430;
            if (func_L01_004561B8(arg0) != 0) {
                sp30 = (*(f32 *)((u8 *)(arg0) + 0x10));
                sp0 = (*(f32 *)((u8 *)((((*(s32 *)((u8 *)(temp_18) + 0x4BC)) << 7) + D_L22_001DFE80)) + 0x30));
                sp40 = D_1A4C60;
                func_003C4098(&sp20, &sp30, &sp40, D_1A4C60, 0.75f);
                sp10 = 0.0f;
                sp28 += 0.25f;
                sp14 = -func_0038D160(func_0038CF38(), sp28 - sp8);
                sp18 = func_0038D160(sp20 - sp0, sp24 - sp4);
                func_L01_003EB350(0, sp);
                func_L01_003EB3C0(0, &sp10);
                (*(s32 *)((u8 *)(temp_18) + 0x484)) = 1;
                (*(s32 *)((u8 *)(temp_18) + 0x49C)) = -0x64;
                (*(s32 *)((u8 *)(temp_18) + 0x490)) = 0;
                D_L22_001E2080 = -1;
                D_L22_001E2084 = -1;
                D_L22_001E1FB8 = -1;
                func_L22_003B8100(arg0);
            }
            temp_2_6 = (*(s32 *)((u8 *)(temp_18) + 0x49C)) + 1;
            (*(s32 *)((u8 *)(temp_18) + 0x49C)) = temp_2_6;
            if (temp_2_6 >= -0x18) {
                temp_2_7 = func_L22_003B71D0(arg0, (*(void **)((u8 *)(temp_18) + 0x230)));
                var_16_3 = temp_2_7;
                temp_6_2 = D_L22_001E2080;
                if (var_16_3 >= 0) {
                    var_4 = D_L22_001E2080;
                    if (temp_6_2 <= 0) {
                        if (D_L22_001E1FB8 >= 0) {
                            var_16_3 = ((*(s32 *)((u8 *)(temp_18) + 0x49C)) >= ((&D_L22_001E2000)[D_L22_001E1FB8] + 8)) ? temp_2_7 : temp_6_2;
                        }
                        goto block_309;
                    }
                } else {
block_309:
                    var_4 = D_L22_001E2080;
                }
                if (var_16_3 != var_4) {
                    if (var_16_3 > 0) {
                        temp_5 = D_L22_001E1FB8 + 1;
                        (*(s32 *)((u8 *)(temp_18) + 0x480)) = 1;
                        temp_8 = temp_5 * 4;
                        temp_6_3 = temp_19 + temp_8;
                        (&D_L22_001E1FC0)[temp_5] = (*(s32 *)((u8 *)(temp_18) + 0x49C));
                        temp_7 = (*(s32 *)((u8 *)(temp_6_3) + 0x84));
                        (&D_L22_001E2000)[temp_5] = (*(s32 *)((u8 *)(temp_18) + 0x49C));
                        *(temp_8 + &D_L22_001E2040) = var_16_3;
                        D_L22_001E1FB8 = temp_5;
                        if (temp_7 == 0) {
                            if (var_16_3 != (*(s32 *)((u8 *)(temp_6_3) + 4))) {
                                D_L22_001E2080 = var_16_3;
                            } else {
                                func_003A52A0();
                                D_L22_001E2080 = var_16_3;
                            }
                        } else {
                            goto block_322;
                        }
                    } else if ((*(s32 *)((u8 *)((temp_19 + (D_L22_001E1FB8 * 4))) + 0x84)) <= 0) {
                        D_L22_001E2080 = var_16_3;
                    } else {
                        if (var_4 > 0) {
                            func_003A52A0();
                        }
block_322:
                        D_L22_001E2080 = var_16_3;
                    }
                } else {
                    temp_2_8 = D_L22_001E1FB8;
                    if ((var_16_3 > 0) && ((*(s32 *)((u8 *)((temp_19 + (temp_2_8 * 4))) + 0x84)) != 0)) {
                        (&D_L22_001E2000)[temp_2_8] = (*(s32 *)((u8 *)(temp_18) + 0x49C));
                    }
                }
                var_11 = 0;
                if ((*(s32 *)((u8 *)(temp_19) + 4)) > 0) {
                    temp_13 = temp_19 + 0x84;
                    var_8 = D_L22_001E2084;
                    var_10 = temp_13;
                    var_14 = &D_L22_001E2000;
                    var_9 = 0;
                    var_12 = &D_L22_001E1FC0;
                    do {
                        var_4_2 = temp_19 + 4;
                        if (D_L22_001E1FB8 < var_11) {
                            var_8 = ((*(s32 *)((u8 *)(var_10) + -0x40)) < ((*(s32 *)((u8 *)(temp_18) + 0x49C)) - 0xA)) ? var_11 : var_8;
                        } else {
                            temp_7_2 = temp_19 + 0x44;
                            temp_6_4 = *var_14;
                            var_8_2 = ((*var_12 + 0xA) < (*(s32 *)((u8 *)(var_10) + -0x40))) ? var_11 : var_8;
                            if (temp_6_4 != (*(s32 *)((u8 *)(temp_18) + 0x49C))) {
                                var_8_2 = ((temp_6_4 + 0xA) < (*(temp_7_2 + var_9) + *(temp_13 + var_9))) ? var_11 : var_8_2;
                            }
                            var_4_2 = temp_19 + 4;
                            var_8 = ((*(var_9 + &D_L22_001E2040) ^ *(temp_19 + 4 + var_9)) != 0) ? var_11 : (((*(temp_7_2 + var_9) + (*(s32 *)((u8 *)(var_10) + 0))) < (temp_6_4 - 0xA)) ? var_11 : var_8_2);
                        }
                        var_9 += 4;
                        var_10 += 4;
                        var_14 += 4;
                        var_12 += 4;
                        var_11 += 1;
                    } while (*(var_4_2 + var_9) > 0);
                    D_L22_001E2084 = var_8;
                }
                if (D_L22_001E2084 >= 0) {
                    func_003A52A0();
                    var_5_4 = 0x17;
                    goto block_469;
                }
                if ((D_L22_001E2080 == 0) && ((D_L22_001E1FB8 + 1) >= var_11)) {
                    var_5_4 = 0x16;
                    goto block_469;
                }
            }
            break;
        case 22:                                    /* switch 2 */
            temp_16_2 = ((*(s32 *)((u8 *)((temp_18 + ((*(s32 *)((u8 *)(temp_18) + 0x498)) * 4))) + 0x4C0)) * 0x188) + &D_L22_002BA430;
            if (func_L01_004561B8(arg0) != 0) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                    func_003C3A10(arg0, 0, func_00382468(), 8);
                }
                (*(s32 *)((u8 *)(temp_18) + 0x4B0)) = (s32) (func_00382468() + 1);
                (*(s32 *)((u8 *)(temp_18) + 0x4AC)) = (s32) *temp_16_2;
                func_L22_003B8100(arg0);
            }
            if ((*(u16 *)((u8 *)(arg0) + 0x96)) == 0x32) {
                func_L22_003B8100(arg0);
                if ((*(s32 *)((u8 *)(temp_18) + 0x4B0)) > 0) {
                    func_L01_0050FB40(func_00382468() + 6, 0, 10.0f);
                    (*(s32 *)((u8 *)(temp_18) + 0x4B0)) = (s32) ((*(s32 *)((u8 *)(temp_18) + 0x4B0)) - 1);
                    (*(u16 *)((u8 *)(arg0) + 0x96)) = (u16) ((s32) ((func_00382498(0, 0x1E) * 5) + 2) / 6);
                } else {
                    func_L01_0050FB40(1, 0, 10.0f);
                }
            }
            temp_4_2 = *(s32 *)0x1D52FC;
            (*(s32 *)((u8 *)(temp_18) + 0x49C)) = (s32) ((*(s32 *)((u8 *)(temp_18) + 0x49C)) + 1);
            if (((*(s32 *)((u8 *)(temp_4_2) + 0x1A0)) & 0x40) && !((*(s32 *)((u8 *)(temp_4_2) + 0x1AC)) & 0x40)) {
                var_5_4 = 0x18;
                goto block_469;
            }
            break;
        case 25:                                    /* switch 2 */
            temp_16_3 = ((*(s32 *)((u8 *)((temp_18 + ((*(s32 *)((u8 *)(temp_18) + 0x498)) * 4))) + 0x4C0)) * 0x188) + &D_L22_002BA430;
            if (func_L01_004561B8(arg0) != 0) {
                func_L01_0050FB40(1, 0, 10.0f);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                    func_003C3A10(arg0, 0, func_00382468(), 8);
                }
                (*(s32 *)((u8 *)(temp_18) + 0x4AC)) = (s32) (*(s32 *)((u8 *)(temp_16_3) + 0xC4));
                func_L22_003B8100(arg0);
            }
            temp_3_9 = *(s32 *)0x1D52FC;
            if ((*(s32 *)((u8 *)(temp_3_9) + 0x1A0)) & 0x40) {
                if (!((*(s32 *)((u8 *)(temp_3_9) + 0x1AC)) & 0x40)) {
                    var_5_4 = 0x1C;
                    goto block_469;
                }
            }
            break;
        case 23:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                (*(s32 *)((u8 *)(temp_18) + 0x4B0)) = (s32) (func_00382468() + 1);
                func_L01_0050FB40(func_00382498(0, 3) + 0xE, 0, 10.0f);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                    func_003C3A10(arg0, 0, func_00382468(), 8);
                }
                (*(s32 *)((u8 *)(temp_18) + 0x4AC)) = (s32) (func_00382498(0, 8) + 0xA28);
                func_L22_003B8100(arg0);
                var_3 = D_001D52FC;
            } else if ((((*(s32 *)((u8 *)(&D_1A4BE0) + 0xC08)) & 2) && ((*(u8 *)((u8 *)((*(void **)((u8 *)(&D_1A4BE0) + 0x25C0))) + 0x43)) != 0)) || ((var_3 = D_001D52FC, (((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) != 0)) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0))) {
                temp_3_10 = (*(s32 *)((u8 *)(temp_18) + 0x4B0));
                if (temp_3_10 >= 2) {
                    func_L01_0050FB40(func_00382498(0, 3) + 0xE, 0, 10.0f);
                    goto block_371;
                }
                if (temp_3_10 == 1) {
                    func_L01_0050FB40(1, 0, 10.0f);
                    temp_16_4 = (*(u8 *)((u8 *)(arg0) + 0x43));
                    if (temp_16_4 != func_00382498(0x13, 0x16)) {
                        func_003C3A10(arg0, func_00382498(0x13, 0x16), 0, 8);
                    }
block_371:
                    (*(s32 *)((u8 *)(temp_18) + 0x4B0)) = (s32) ((*(s32 *)((u8 *)(temp_18) + 0x4B0)) - 1);
                    goto block_374;
                }
                func_L01_0050FB40(1, 0, 10.0f);
                var_3 = D_001D52FC;
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                    func_003C3A10(arg0, 0, func_00382468(), 8);
block_374:
                    var_3 = *(s32 *)0x1D52FC;
                }
            }
            if ((*(s32 *)((u8 *)(var_3) + 0x1A0)) & 0x40) {
                if (!((*(s32 *)((u8 *)(var_3) + 0x1AC)) & 0x40)) {
                    var_5_4 = 0x1A;
                    goto block_469;
                }
            }
            break;
        case 26:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                func_L01_0050FB40(1, 0, 10.0f);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                    func_003C3A10(arg0, 0, func_00382468(), 8);
                }
                (*(s32 *)((u8 *)(temp_18) + 0x4AC)) = 0x15F3;
                func_L22_003B8100(arg0);
                var_3_2 = D_001D52FC;
                if (((s32) ((*(s32 *)((u8 *)(temp_18) + 0x4A4)) + 1) % 5) == 0) {
                    if (((*(s32 *)((u8 *)((temp_18 + ((*(s32 *)((u8 *)(temp_18) + 0x498)) * 4))) + 0x4C0)) < 4) && ((*(s32 *)((u8 *)(&D_L22_002E79F0) + 0)) == 0)) {
                        var_3_2 = D_001D52FC;
                        if ((*(s32 *)((u8 *)(&D_L22_002E79F0) + 0x24)) == -1) {
                            var_3_2 = D_001D52FC;
                            if (((*(s32 *)((u8 *)(&D_1CCFD0) + 0x6C)) == 0) && ((*(s32 *)((u8 *)(&D_1CCFD0) + 0x24)) == (*(s32 *)((u8 *)(&D_L22_002E79F0) + 0x24))) && ((*(s32 *)((u8 *)(&D_1CCFD0) + 0x94)) == 0)) {
                                (*(s32 *)((u8 *)(&D_L22_002E79F0) + 0x28)) = 0x39;
                                (*(s32 *)((u8 *)(&D_L22_002E79F0) + 0x24)) = 0xB96;
                                goto block_389;
                            }
                        }
                    } else {
                        goto block_389;
                    }
                }
            } else {
block_389:
                var_3_2 = *(s32 *)0x1D52FC;
            }
            if (((*(s32 *)((u8 *)(var_3_2) + 0x1A0)) & 0x40) && !((*(s32 *)((u8 *)(var_3_2) + 0x1AC)) & 0x40)) {
                var_5_4 = 0x1B;
                goto block_469;
            }
            if (((*(s32 *)((u8 *)(var_3_2) + 0x1A0)) & 0x10) && !((*(s32 *)((u8 *)(var_3_2) + 0x1AC)) & 0x10)) {
                var_5_4 = 0x1D;
                goto block_469;
            }
            break;
        case 24:                                    /* switch 2 */
            temp_19_2 = ((*(s32 *)((u8 *)((temp_18 + ((*(s32 *)((u8 *)(temp_18) + 0x498)) * 4))) + 0x4C0)) * 0x188) + &D_L22_002BA430;
            if (func_L01_004561B8(arg0) != 0) {
                func_L01_0050FB40(1, 0, 10.0f);
                (*(s32 *)((u8 *)(temp_18) + 0x4AC)) = (s32) (*(s32 *)((u8 *)(temp_19_2) + 0xC4));
                temp_7_3 = (*(f32 *)((u8 *)((((*(s32 *)((u8 *)(temp_18) + 0x4BC)) << 7) + D_L22_001DFE80)) + 0x30));
                sp0 = temp_7_3;
                sp30 = (*(f32 *)((u8 *)(arg0) + 0x10));
                sp40 = D_1A4C60;
                func_003C4098(&sp20, &sp30, &sp40, temp_7_3, D_1A4C60, 0x3E800000);
                sp10 = 0.0f;
                sp28 += 0.25f;
                sp14 = -func_0038D160(func_0038CF38(), sp28 - sp8);
                sp18 = func_0038D160(sp20 - sp0, sp24 - sp4);
                func_L01_003EB350(0, sp);
                func_L01_003EB3C0(0, &sp10);
                (*(s32 *)((u8 *)(temp_18) + 0x494)) = 0;
                (*(s32 *)((u8 *)(temp_18) + 0x49C)) = 0;
                func_L22_003B8100(arg0);
            }
            var_8_3 = 0;
            temp_7_4 = (*(s32 *)((u8 *)(temp_18) + 0x49C)) + 1;
            (*(s32 *)((u8 *)(temp_18) + 0x49C)) = temp_7_4;
            temp_6_5 = temp_19_2 + ((*(s32 *)((u8 *)(temp_18) + 0x494)) * 4);
            temp_5_2 = (*(s32 *)((u8 *)(temp_6_5) + 0x108));
            temp_2_9 = temp_5_2 + (*(s32 *)((u8 *)(temp_6_5) + 0x148));
            if (temp_7_4 >= temp_5_2) {
                if (temp_2_9 >= temp_7_4) {
                    var_8_3 = (*(s32 *)((u8 *)(temp_6_5) + 0xC8));
                } else {
                    goto block_402;
                }
                goto block_403;
            }
            var_2_2 = 0xA;
            if (temp_2_9 < temp_7_4) {
block_402:
                (*(s32 *)((u8 *)(temp_18) + 0x494)) = (s32) ((*(s32 *)((u8 *)(temp_18) + 0x494)) + 1);
block_403:
                var_2_2 = var_8_3 + 0xA;
            }
            temp_5_3 = (var_8_3 != 0) ? var_2_2 : 0;
            if ((*(u8 *)((u8 *)(arg0) + 0x43)) != temp_5_3) {
                func_003C3A10(arg0, temp_5_3, 0, 0xA);
            }
            if ((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 0x65U) {
                if ((*(s32 *)((u8 *)(*(s32 *)0x1D52FC) + 0x1A0)) & 0x40) {
                    var_5_4 = 0x1C;
                    goto block_469;
                }
            }
            break;
        case 27:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                (*(s32 *)((u8 *)(temp_18) + 0x4A4)) = (s32) ((*(s32 *)((u8 *)(temp_18) + 0x4A4)) + 1);
                func_L01_0050FB40(1, 0, 17.0f);
                func_L22_003B8100(arg0);
            }
            if ((*(s32 *)((u8 *)(temp_18) + 0x468)) == 0) {
                var_5_4 = 0x15;
                if ((*(s32 *)((u8 *)(temp_18) + 0x4A4)) >= 5) {
                    var_5_4 = 0x1D;
                }
            } else {
                var_5_4 = 0x15;
            }
            goto block_469;
        case 28:                                    /* switch 2 */
            if ((func_L01_004561B8(arg0) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0)) {
                func_003C3A10(arg0, 0, func_00382468(), 8);
            }
            func_L01_0050FB40(1, 0, 17.0f);
            func_L22_003B8100(arg0);
            (*(s32 *)((u8 *)(temp_18) + 0x4A4)) = 0;
            temp_3_11 = (*(s32 *)((u8 *)(temp_18) + 0x498)) + 1;
            (*(s32 *)((u8 *)(temp_18) + 0x498)) = temp_3_11;
            if ((temp_3_11 < 8) && ((*(s32 *)((u8 *)((temp_18 + (temp_3_11 * 4))) + 0x4C0)) > 0)) {
                var_5_4 = 0x15;
            } else {
                (*(s32 *)((u8 *)(temp_18) + 0x4A0)) = (s32) ((*(s32 *)((u8 *)(temp_18) + 0x4A0)) + 1);
                temp_4_3 = (*(u16 *)((u8 *)(arg0) + 0xB2));
                temp_3_12 = D_001D545C;
                if (temp_4_3 & 1) {
                    var_6_3 = ((s32) (temp_4_3 << 0x10) >> 0x11) + (temp_3_12 << 0xA) + &D_1BBE90;
                    temp_5_4 = *var_6_3;
                    var_2_3 = temp_5_4 + 0x10;
                    if (((temp_5_4 >> 4) & 7) != 7) {
                        goto block_425;
                    }
                } else {
                    var_6_3 = ((s32) (temp_4_3 << 0x10) >> 0x11) + (temp_3_12 << 0xA) + &D_1BBE90;
                    temp_5_5 = *var_6_3;
                    var_2_3 = temp_5_5 + 1;
                    if ((temp_5_5 & 7) != 7) {
block_425:
                        *var_6_3 = var_2_3;
                    }
                }
                if (*(s32 *)0x1D545C == 0x16) {
                    temp_3_13 = (*(u16 *)((u8 *)(arg0) + 0xB2));
                    temp_2_10 = temp_3_13 << 0x10;
                    if (temp_3_13 & 1) {
                        var_3_3 = (temp_2_10 >> 0x11) + 0x5800 + &D_1BBE90;
                        temp_5_6 = *var_3_3;
                        var_2_4 = temp_5_6 + 0x10;
                        if (((temp_5_6 >> 4) & 7) != 7) {
                            goto block_431;
                        }
                    } else {
                        var_3_3 = (temp_2_10 >> 0x11) + 0x5800 + &D_1BBE90;
                        temp_5_7 = *var_3_3;
                        var_2_4 = temp_5_7 + 1;
                        if ((temp_5_7 & 7) != 7) {
block_431:
                            *var_3_3 = var_2_4;
                        }
                    }
                }
                temp_4_4 = (*(s32 *)((u8 *)(temp_18) + 0x4A8));
                (*(s8 *)((u8 *)(temp_18) + 0x3E)) = 1;
                if (temp_4_4 >= 0) {
                    func_L01_00456230(D_L22_001DFD9C + (temp_4_4 << 8), 1);
                }
                var_5_4 = 0x1D;
            }
            goto block_469;
        case 29:                                    /* switch 2 */
            func_L22_003B6EE8(arg0, 0);
            break;
        case 6:                                     /* switch 2 */
            if ((func_L01_004561B8(arg0) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0)) {
                func_003C3A10(arg0, 0, func_00382468(), 5);
            }
            temp_f12 = (*(f32 *)((u8 *)(temp_18) + 0x528));
            if (fabsf(temp_f12 - (*(f32 *)((u8 *)(arg0) + 0xF8))) < 0.08726646f) {
                temp_7_5 = (*(s32 *)((u8 *)(temp_18) + 0x49C)) + 1;
                (*(s32 *)((u8 *)(temp_18) + 0x49C)) = temp_7_5;
                var_8_4 = 0;
                temp_16_5 = ((*(s32 *)((u8 *)(temp_18) + 0x498)) * 0x188) + &D_L22_002BA430;
                temp_6_6 = temp_16_5 + ((*(s32 *)((u8 *)(temp_18) + 0x494)) * 4);
                temp_5_8 = (*(s32 *)((u8 *)(temp_6_6) + 0x44));
                temp_2_11 = temp_5_8 + (*(s32 *)((u8 *)(temp_6_6) + 0x84));
                if (temp_7_5 >= temp_5_8) {
                    if (temp_2_11 >= temp_7_5) {
                        var_8_4 = (*(s32 *)((u8 *)(temp_6_6) + 4));
                    } else {
                        goto block_445;
                    }
                    goto block_446;
                }
                var_2_5 = D_001D6694;
                if (temp_2_11 < temp_7_5) {
block_445:
                    (*(s32 *)((u8 *)(temp_18) + 0x494)) = (s32) ((*(s32 *)((u8 *)(temp_18) + 0x494)) + 1);
block_446:
                    var_2_5 = D_L22_001D6694;
                }
                temp_8_2 = ((u32) (var_2_5 - 1) <= 1U) ? 0 : var_8_4;
                var_7 = 0;
                temp_5_9 = (temp_8_2 != 0) ? (temp_8_2 + 0xA) : 0;
                if ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) != 0x58) {
                    var_7 = (((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) ^ 0x74) == 0) ? 0 : 1;
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != temp_5_9) {
                    func_L01_00444F38(arg0, temp_5_9, 0, 0xA, (var_7 != 0) ? 0 : 0x10);
                }
                if (((*(s32 *)((u8 *)((temp_16_5 + ((*(s32 *)((u8 *)(temp_18) + 0x494)) * 4))) + 4)) < 0) || ((temp_2_12 = (*(void **)((u8 *)(temp_18) + 0x47C)), (temp_2_12 != 0)) && ((*(u8 *)((u8 *)(temp_2_12) + 0x95)) != 1))) {
                    var_5_4 = 4;
                    goto block_469;
                }
            } else {
block_465:
                func_L01_0045BD10(arg0, (*(f32 *)((u8 *)(temp_18) + 0x528)));
            }
            break;
        case 30:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 3) {
                    func_003C3A10(arg0, 3, func_00382468(), 8);
                }
            }
            if (func_L01_0045A748(arg0, temp_18 + 0x510) == 0x80) {
                var_5_4 = 0x1F;
                goto block_469;
            }
            break;
        case 31:                                    /* switch 2 */
            if ((func_L01_004561B8(arg0) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 3)) {
                func_003C3A10(arg0, 3, func_00382468(), 8);
            }
            if (!(fabsf((*(f32 *)((u8 *)(temp_18) + 0x528)) - (*(f32 *)((u8 *)(arg0) + 0xF8))) < 0.08726646f)) {
                goto block_465;
            }
block_468:
            var_5_4 = 0x21;
            goto block_469;
        case 32:                                    /* switch 2 */
            if ((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 0x19U) {
                func_L01_00456230(arg0, 1);
                goto block_468;
            }
            break;
        case 33:                                    /* switch 2 */
            if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                func_003C3A10(arg0, 0, func_00382468(), 7);
            }
            func_L01_0045A9F0(arg0);
            func_L01_004450F0(arg0, 4U, 1);
            break;
        }
        temp_2_13 = ((*(s32 *)((u8 *)(temp_18) + 0x4B8)) << 7) + D_L22_001DFE80;
        temp_f20_6 = func_0038D160((*(f32 *)((u8 *)(temp_2_13) + 0x30)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_2_13) + 0x34)) - (*(f32 *)((u8 *)(arg0) + 0x14)));
        temp_f0_7 = func_0038D160((*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)) - (*(f32 *)((u8 *)(arg0) + 0x14)));
        if (((u32) ((*(u8 *)((u8 *)(arg0) + 0x95)) - 1) < 2U) && ((*(s32 *)((u8 *)(temp_18) + 0x4C0)) > 0) && ((*(s32 *)((u8 *)(temp_18) + 0x4A0)) == 0) && ((*(void **)((u8 *)(&D_1A4BE0) + 0x25C0)) != 0) && ((temp_3_14 = (*(s16 *)((u8 *)((*(void **)((u8 *)(&D_1A4BE0) + 0x25C0))) + 0xAA)), (temp_3_14 == 0x173B)) || (temp_3_14 == 0x1A4E)) && (func_0038DBA0(temp_f0_7, temp_f20_6) < 2.0943952f) && (func_0038CF38() < 5.0f)) {
            func_L01_00404808(&func_L22_003B7150, arg0);
        }
        if ((*(u8 *)((u8 *)(arg0) + 0x95)) == 5) {
            func_L22_003B83A0(arg0);
        }
        func_L22_003B6B90(arg0);
        return;
    case 1:                                         /* switch 1 */
        if ((func_L01_004561E0(arg0) != 0) && ((*(s32 *)((u8 *)(temp_18) + 0x458)) == 0)) {
            (*(s32 *)((u8 *)(temp_18) + 0x458)) = (s32) ((s32) ((func_00382498(0, 0x14) * 5) + 2) / 6);
        }
        if (((*(s16 *)((u8 *)(temp_18) + 0x234)) == 1) && (func_0038CAD0(temp_18 + 0x458) != 0) && (D_001D545C != 0x16)) {
            if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                func_003C3A10(arg0, 4, func_00382468(), 8);
            }
            func_L01_004450F0(arg0, 8U, 3);
            if ((*(s32 *)((u8 *)(temp_18) + 0x474)) != -1) {
                func_L01_004450F0(arg0, 5U, -1);
            }
        } else if (((*(s32 *)((u8 *)(temp_18) + 0x45C)) != 0) && (func_0038CAD0(temp_18 + 0x458) != 0)) {
            func_L01_004450F0(arg0, (*(u8 *)((u8 *)(arg0) + 0x20)), 2);
            (*(s32 *)((u8 *)(temp_18) + 0x45C)) = 0;
            if ((*(s32 *)((u8 *)(temp_18) + 0x450)) < 0xFA) {
                (*(s32 *)((u8 *)(temp_18) + 0x450)) = (s32) ((s32) ((func_00382498(0x1E0, 0x258) * 5) + 2) / 6);
            }
        }
        temp_4_5 = (*(s32 *)((u8 *)(temp_18) + 0x534));
        var_16_4 = 1;
        if ((temp_4_5 != -1) && (*(s32 *)0x1D545C == 0x16)) {
            var_16_4 = ((*(s32 *)((u8 *)((*(void **)((u8 *)((D_L22_001DFD9C + (temp_4_5 << 8))) + 0x68))) + 0x130)) != 0) ? 0 : 1;
        }
        if ((func_L22_003B6D30(arg0, (*(void **)((u8 *)(temp_18) + 0x230))) != 0) && (var_16_4 != 0)) {
block_45:
            if (D_001D545C == 0x16) {
                func_L01_0041A6E0();
            }
            func_L01_004450F0(arg0, 0x12U, 5);
        }
        goto block_68;
    case 2:                                         /* switch 1 */
        if ((*(s16 *)((u8 *)(temp_18) + 0x234)) != 1) {
            if ((*(s32 *)((u8 *)(temp_18) + 0x450)) == 0) {
                func_L01_004450F0(arg0, (*(u8 *)((u8 *)(arg0) + 0x20)), 1);
            }
        } else {
            if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                func_003C3A10(arg0, 4, func_00382468(), 8);
            }
            func_L01_004450F0(arg0, 8U, 3);
        }
        if (func_L22_003B6D30(arg0, (*(void **)((u8 *)(temp_18) + 0x230))) != 0) {
            goto block_45;
        }
        goto block_68;
    case 3:                                         /* switch 1 */
        if (((*(s16 *)((u8 *)(temp_18) + 0x234)) != 1) && (func_L01_004561E0(arg0) == 0)) {
            func_L01_004450F0(arg0, 0x10U, 2);
            if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 1) {
                func_003C3A10(arg0, 1, 0, 8);
            }
            var_4_3 = 0x30C;
            var_5_6 = 0x384;
block_59:
            (*(s32 *)((u8 *)(temp_18) + 0x450)) = (s32) ((s32) ((func_00382498(var_4_3, var_5_6) * 5) + 2) / 6);
        }
        goto block_68;
    case 4:                                         /* switch 1 */
        temp_2_14 = func_L01_00454370(arg0, temp_18 + 0x160);
        if (temp_2_14 & 1) {
            func_L02_003A5010(arg0);
            func_L01_00315900(arg0, 0, func_L01_004028B0);
            return;
        }
        if (temp_2_14 & 2) {
            if ((*(s16 *)((u8 *)(temp_18) + 0x234)) == 1) {
                func_L01_004450F0(arg0, 8U, 3);
            } else {
                func_L01_004450F0(arg0, 7U, 2);
                var_4_3 = 0x244;
                var_5_6 = 0x258;
                goto block_59;
            }
        }
        goto block_68;
    case 5:                                         /* switch 1 */
        if (((*(s16 *)((u8 *)(temp_18) + 0x234)) == 1) || ((*(void **)((u8 *)(&D_1A4BE0) + 0x25C0)) == 0) || ((temp_3_15 = (*(s16 *)((u8 *)((*(void **)((u8 *)(&D_1A4BE0) + 0x25C0))) + 0xAA)), (temp_3_15 != 0x173B)) && (temp_3_15 != 0x1A4E)) || (((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) == 0x52) && ((u8) (*(u8 *)((u8 *)(arg0) + 0x20)) >= 0x15U))) {
            func_L01_004450F0(arg0, 0x1DU, -1);
        }
        (*(s32 *)((u8 *)(temp_18) + 0x39C)) = (s32) (*(s32 *)((u8 *)(temp_18) + 0x388));
        func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
        goto block_68;
    }
}
