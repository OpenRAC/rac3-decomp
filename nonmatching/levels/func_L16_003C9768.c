/* func_L16_003C9768: Opus handoff (prep by Sonnet worker w7, 2026-11-08)
   Size: 7348 bytes, places: 1 levels (16), file: src/levels/16_kerwan/L16_003C9768.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: one function (addiu sp,-0xD0), 3 switches / 1 jump table (12 entries): +0x95, +0x20, +0x95 again at the end.
   Its one `blezl $x, 1f; neg $x, $x` pair is the game's integer abs: abs_asm() from include/vu0.h.
   Twin: none (rac2 index best func_L01_003CC930 at 0.19). Checked: callee fingerprint (callfp: 0 callees mapped); whole-corpus opcode search over every rac3 and rac2 function >= 600 B (best rac3:func_L39_00525690 0.16); names.tsv/NAMES.md (no entry); matched rac3 siblings in src/ (only the scaffold is shared).
   Mapping: Common enemy/boss scaffold (matches the tools' names): arg0 = moby; +0x20 = state byte (func_L01_004450F0 = moby_set_state(moby, state, sub)), +0x95 = phase byte, +0x68 = per-object data, func_L01_004561B8 = animation-done test, func_003C3A10 = moby_anim_blend(moby, anim, 0, 8), func_0038CB00 = timer_tick_short, D_1A4BE0 = hero/global struct (+0x25C0 hero moby, +0x25C4 hero state, +0xC08 pad bits). $gp loads are named D_<0x1DC8B0+offset> (D_LNN_ when >= 0x1D9900) in the draft. Own callees: func_L16_003CBC88 (x12 calls), func_L16_003E8580.
   Identical / changed / added / removed: n/a (no twin).
   VU0: 12 vadd.xyz/vsub.xyz ops in the retail asm; inline-asm VU0 is banned since 2026-11-06 (Matching-Patterns), so this function cannot reach MATCH unless the ops come from plain C; the lq/sq copies are fine (u128_t).
   Draft: compiles (m2c draft cleaned by tools/post.py (real repo prototypes where known, m2c gotos kept)); 1780 diff; opcode-equal 1257 of 1838 (mine 1644), ratio 0.72.
     Retail rows yours=1644 retail=1838 equalrows=58.
   Left for Opus:
     1. Frame 0xD0 vs mine 0xA0: retail keeps more values live across calls (extra s-regs); look at the prologue sd order first.
     2. 12 VU0 ops (10 vadd/vsub.xyz + 2 lqc2): near miss only.
*/
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF38();
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_L01_0040E570(void *, void *);
extern int func_L01_004561B8(u8 *);
extern int func_L01_004561E0(void *a0);
extern s32 func_00382468();
extern s32 func_00382498(s32, s32);
extern s32 func_003A52A0();
extern s32 func_L01_0044C108(void *a);
extern s32 func_L01_00456250(void *);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_00456230(u8 *, s32);
s32 func_L01_004028B0(void *);                  /* extern */
f32 func_L01_004395E0(void *);                      /* extern */
s32 func_L01_004450F0(void *, u8, s32);     /* extern */
s32 func_L01_0044E1B8(void *, f32);                 /* extern */
s32 func_L16_003CB420(void *);                  /* extern */
s32 func_L16_003CBBF0(void *);                  /* extern */
s32 func_L16_003CBC88(void *, void *, s32, f32); /* extern */
s32 func_L16_003CBF50(void *, f32 *, void *, f32 *, f32); /* extern */
s32 func_L16_003CC0A8(void *);                  /* extern */
s32 func_L16_003CC150(void *, f32 *);           /* extern */
s32 func_L16_003CC1A8(void *);                  /* extern */
void *func_L16_003E6C48(void *, f32 *, s32, f32); /* extern */
s32 func_L16_003E7280(void *, f32 *, void *, s32); /* extern */
s32 func_L16_003E7300(void *, f32 *, void *, f32); /* extern */
s32 func_L16_003E8580(void *, f32 *, f32 *, void *, s32, f32); /* extern */
extern s32 D_1A4BE0;
extern f32 D_1A4C60;
extern s32 D_L16_001DFC40;
extern s32 D_L16_001E015C;

extern s32 D_L16_001DE91C;
extern s32 D_L16_001DE92C;
extern s32 D_L16_001DE930;
extern f32 D_L16_001DE934;
extern f32 D_L16_001DE938;
extern f32 D_L16_001DE93C;
extern f32 D_L16_001DE940;
extern s32 D_L16_001DE944;
extern s32 D_L16_001DE948;
extern s32 D_L16_001DE94C;
extern s32 D_L16_001DE950;
extern s32 D_L16_001DE954;
extern s32 D_L16_001DE958;
extern s32 D_L16_001DE95C;
extern s32 D_L16_001DE960;
extern s32 D_L16_001DFC40;
extern s32 D_L16_001E015C;

void func_L16_003C9768(void *arg0) {
    s32 sp[8]; /* m2c: stack-slot base, size unknown */
    f32 sp8;
    f32 sp10;
    f32 sp18;
    f32 sp20;
    f32 sp24;
    f32 sp28;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 *sp40;
    u8 *sp44;
    u8 *sp48;
    s32 var_5_3;
    s32 var_f0;
    f32 *temp_17;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f21_3;
    f32 temp_f22;
    f32 var_f12;
    f32 var_f12_2;
    f32 var_f12_3;
    f32 var_f12_4;
    f32 var_f12_5;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f20;
    f32 var_f20_2;
    f32 var_f21;
    f32 var_f23;
    s16 temp_2_2;
    s16 temp_2_7;
    s16 temp_3_16;
    s16 temp_3_9;
    s16 var_2_5;
    s16 var_2_6;
    s32 *var_2_7;
    s32 *var_2_8;
    s32 *var_2_9;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_3_10;
    s32 temp_3_11;
    s32 temp_3_13;
    s32 temp_3_15;
    s32 temp_3_7;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_4_8;
    s32 temp_5;
    s32 temp_5_2;
    s32 var_16;
    s32 var_16_2;
    s32 var_16_4;
    s32 var_17;
    s32 var_18;
    s32 var_18_2;
    s32 var_18_3;
    s32 var_21;
    s32 var_22;
    s32 var_2;
    s32 var_2_10;
    s32 var_2_3;
    s32 var_2_4;
    s32 var_3;
    s32 var_3_2;
    s32 var_3_3;
    s32 var_3_6;
    s32 var_3_7;
    s32 var_4;
    u16 temp_3_2;
    u16 temp_3_3;
    u16 var_2_2;
    u8 temp_2;
    u8 temp_3;
    u8 temp_3_12;
    u8 temp_3_14;
    u8 temp_3_17;
    u8 temp_3_18;
    u8 temp_3_19;
    u8 temp_3_4;
    u8 temp_3_5;
    u8 temp_3_6;
    u8 temp_3_8;
    u8 temp_4_7;
    u8 var_5;
    u8 var_5_2;
    u8 var_5_5;
    void **var_16_3;
    u8 *temp_16;
    u8 *temp_16_2;
    u8 *temp_16_3;
    u8 *temp_17_2;
    u8 *temp_18;
    u8 *temp_19;
    u8 *temp_22;
    u8 *temp_4;
    u8 *temp_4_10;
    u8 *temp_4_4;
    u8 *temp_4_5;
    u8 *temp_4_6;
    u8 *temp_4_9;
    u8 *var_16_5;
    u8 *var_23;
    u8 *var_3_4;
    u8 *var_3_5;
    u8 *var_4_2;
    u8 *var_5_4;
    u8 *var_5_6;

    if (func_L01_0044C108(arg0 + 0x10) != 0) {
        temp_19 = (*(void **)((u8 *)(arg0) + 0x68));
        func_L16_003CB420(arg0);
        temp_3 = (*(u8 *)((u8 *)(arg0) + 0x95));
        switch (temp_3) {                           /* switch 1; irregular */
        case 2:                                     /* switch 1 */
            temp_4 = (*(void **)((u8 *)(arg0) + 0x24));
            temp_3_2 = (*(u16 *)((u8 *)(arg0) + 0x34)) & 0xFFBE;
            (*(u16 *)((u8 *)(arg0) + 0x34)) = temp_3_2;
            temp_3_3 = temp_3_2 | ((*(u16 *)((u8 *)(temp_4) + 0x44)) & 0x1000);
            (*(u16 *)((u8 *)(arg0) + 0x34)) = temp_3_3;
            (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (temp_3_3 & 0xFF7F);
            (*(s32 *)((u8 *)(arg0) + 0x98)) = (s32) (*(s32 *)((u8 *)(temp_4) + 0x10));
            break;
        case 1:                                     /* switch 1 */
            if (func_L01_004561E0(arg0) != 0) {
                (*(s32 *)((u8 *)(temp_19) + 0x224)) = 0;
                (*(s32 *)((u8 *)(temp_19) + 0x220)) = (s32) *(s32 *)0x1A7430;
            }
            break;
        }
        temp_2 = (*(u8 *)((u8 *)(arg0) + 0x20));
        switch (temp_2) {                           /* switch 2 */
        case 2:                                     /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                if ((*(s32 *)((u8 *)(temp_19) + 0x1BC)) != 2) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                        func_003C3A10(arg0, 0, 0, 0xA);
                    }
                } else {
                    (*(s32 *)((u8 *)(temp_19) + 0x198)) = (s32) D_L16_001DE91C;
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 6) {
                        func_003C3A10(arg0, 6, 0, 0xA);
                    }
                }
            }
            func_L16_003CBC88(arg0, arg0 + 0x10, -1, (*(f32 *)((u8 *)(arg0) + 0xF8)));
            var_5 = 0xA;
block_70:
            func_L01_004450F0(arg0, var_5, 2);
            break;
        case 3:                                     /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                if ((*(s32 *)((u8 *)(temp_19) + 0x1BC)) != 2) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 5) {
                        func_003C3A10(arg0, 5, 0, 0x11);
                    }
                    (*(s32 *)((u8 *)(arg0) + 0x48)) = (s32) D_L16_001DE944;
                } else if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 6) {
                    func_003C3A10(arg0, 6, 0, 0xA);
                }
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x43)) == 5) {
                if (func_L01_0044E1B8(arg0, D_L16_001DE940) != 0) {
                    (*(s32 *)((u8 *)(arg0) + 0x48)) = (s32) D_L16_001DE948;
                    (*(s32 *)((u8 *)(temp_19) + 0x1BC)) = 2;
                    (*(s32 *)((u8 *)(temp_19) + 0x198)) = 0;
                } else if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    temp_3_4 = (*(u8 *)((u8 *)(arg0) + 0x42));
                    if ((temp_3_4 == (*(u8 *)((u8 *)(arg0) + 0x43))) && (temp_3_4 != 6)) {
                        func_003C3A10(arg0, 6, 0, 0);
                    }
                }
            }
            func_L16_003CBC88(arg0, arg0 + 0x10, -1, (*(f32 *)((u8 *)(arg0) + 0xF8)));
            temp_3_5 = (*(u8 *)((u8 *)(arg0) + 0x43));
            if ((temp_3_5 == 6) && ((*(u8 *)((u8 *)(arg0) + 0x42)) == temp_3_5)) {
                var_5_2 = (*(u8 *)((u8 *)(arg0) + 0x94));
block_364:
                func_L01_004450F0(arg0, var_5_2, -1);
            }
            break;
        case 4:                                     /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                if (((*(s32 *)((u8 *)(temp_19) + 0x1BC)) != 2) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0)) {
                    func_003C3A10(arg0, 0, func_00382468(), 0xA);
                }
            }
            var_16 = 0;
            if (((*(s32 *)((u8 *)(temp_19) + 0x1BC)) == 2) && (func_L01_0040E570(arg0 + 0x10, temp_19 + 0x260) < 1.0f)) {
                var_16 = 1;
            }
            if (var_16 != 0) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xA) {
                    func_003C3A10(arg0, 0xA, 0, 0xA);
                }
                (*(s32 *)((u8 *)(arg0) + 0x48)) = (s32) D_L16_001DE94C;
                (*(s32 *)((u8 *)(temp_19) + 0x1BC)) = 0;
            }
            if ((*(s32 *)((u8 *)(temp_19) + 0x1BC)) == 2) {
                func_L16_003CBC88(arg0, temp_19 + 0x260, -1, func_0038D160((*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)) - (*(f32 *)((u8 *)(arg0) + 0x14))));
            } else {
                func_L16_003CBC88(arg0, arg0 + 0x10, -1, func_0038D160((*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)) - (*(f32 *)((u8 *)(arg0) + 0x14))));
            }
            temp_3_6 = (*(u8 *)((u8 *)(arg0) + 0x43));
            if ((temp_3_6 == 0xA) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) && ((*(u8 *)((u8 *)(arg0) + 0x42)) == temp_3_6)) {
                func_003C3A10(arg0, 0, func_00382468(), 0xA);
            }
            if (((*(u8 *)((u8 *)(arg0) + 0x43)) == 0) && ((*(u8 *)((u8 *)(arg0) + 0x42)) == 0)) {
                var_5_2 = (*(u8 *)((u8 *)(arg0) + 0x94));
                goto block_364;
            }
            break;
        case 6:                                     /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                (*(s32 *)((u8 *)(temp_19) + 0x198)) = 0;
                (*(s32 *)((u8 *)(temp_19) + 0x1BC)) = 2;
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 6) {
                    func_003C3A10(arg0, 6, 0, 8);
                }
                (*(f32 *)((u8 *)(temp_19) + 0x250)) = 0.0f;
                (*(f32 *)((u8 *)(temp_19) + 0x258)) = 1.618f;
                (*(s32 *)((u8 *)(temp_19) + 0x254)) = 0;
            }
            temp_2_2 = (*(s16 *)((u8 *)(temp_19) + 0x21A));
            if ((*(s16 *)((u8 *)(temp_19) + 0x218)) != 0) {
                var_3 = (*(s32 *)((u8 *)((temp_19 + (temp_2_2 * 4))) + 0x1FC));
            } else {
                var_3 = (*(s32 *)((u8 *)((temp_19 + (temp_2_2 * 4))) + 0x1F0));
            }
            temp_16 = temp_19 + 0x260;
            func_0038D000(temp_16, temp_19 + 0x250, D_L16_001E015C + (var_3 << 8) + 0xC0);
            0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
            (*(f32 *)((u8 *)(temp_19) + 0x260)) = (f32) (*(f32 *)((u8 *)(temp_19) + 0x260));
            func_L16_003CBC88(arg0, temp_16, -1, func_0038D160((*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)) - (*(f32 *)((u8 *)(arg0) + 0x14))));
            if (func_L01_0040E570(arg0 + 0x10, temp_16) < 5.0f) {
                var_5 = 7;
                goto block_70;
            }
            break;
        case 7:                                     /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                if ((*(s32 *)((u8 *)(temp_19) + 0x1BC)) != 2) {
                    temp_3_7 = (*(s32 *)((u8 *)(temp_19) + 0x1B8));
                    if (((temp_3_7 != 2) || ((*(s32 *)((u8 *)(temp_19) + 0x1D4)) < 0x65)) && ((temp_3_7 != 1) || ((*(s32 *)((u8 *)(temp_19) + 0x1D8)) < 0x65))) {
                        if ((*(s32 *)((u8 *)(temp_19) + 0x1B0)) == 0) {
                            if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                                func_003C3A10(arg0, 0, 0, 0xA);
                            }
                        } else {
                            goto block_84;
                        }
                    } else {
block_84:
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 1) {
                            var_5_3 = 1;
                            goto block_86;
                        }
                    }
                } else {
                    (*(s32 *)((u8 *)(temp_19) + 0x198)) = (s32) D_L16_001DE91C;
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 6) {
                        var_5_3 = 6;
block_86:
                        func_003C3A10(arg0, var_5_3, 0, 0xA);
                    }
                }
            }
            temp_3_8 = (*(u8 *)((u8 *)(arg0) + 0x42));
            if ((temp_3_8 == (*(u8 *)((u8 *)(arg0) + 0x43))) && (temp_3_8 == 1) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                func_003C3A10(arg0, 0, 0, 0xA);
                (*(s32 *)((u8 *)(temp_19) + 0x1B0)) = 0;
            }
            if ((*(s32 *)((u8 *)(temp_19) + 0x1B8)) == 0) {
                (*(s32 *)((u8 *)(temp_19) + 0x1B8)) = 2;
            }
            temp_f21 = func_0038D160((*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)) - (*(f32 *)((u8 *)(arg0) + 0x14)));
            if ((*(s32 *)((u8 *)(temp_19) + 0x1BC)) == 2) {
                func_L16_003CBC88(arg0, temp_19 + 0x260, -1, temp_f21);
            } else {
                func_L16_003CBC88(arg0, arg0 + 0x10, -1, temp_f21);
            }
            var_22 = 0;
            if (((*(s32 *)((u8 *)(temp_19) + 0x1BC)) == 2) && (func_L01_0040E570(arg0 + 0x10, temp_19 + 0x260) < 1.0f)) {
                var_22 = 1;
            }
            var_18 = 0;
            if ((*(s32 *)((u8 *)(temp_19) + 0x1B0)) == 0) {
                if (((u32) (*(s16 *)((u8 *)(temp_19) + 0x218)) == (*(u32 *)((u8 *)(temp_19) + 0x214))) || (D_L16_001DE95C < (*(s32 *)((u8 *)(temp_19) + 0x1AC)))) {
                    var_18 = 1;
                }
                temp_4_2 = (*(s32 *)((u8 *)(temp_19) + 0x1B8));
                if (temp_4_2 != 2) {

                } else if ((*(u8 *)((u8 *)(arg0) + 0x94)) != 5) {
                    temp_3_9 = (*(s16 *)((u8 *)(temp_19) + 0x216));
                    if (temp_3_9 != 1) {
                        var_18 = (((*(s16 *)((u8 *)(temp_19) + 0x212)) ^ (temp_4_2 - temp_3_9)) != 0) ? 1 : var_18;
                    } else {
                        if ((*(s16 *)((u8 *)(temp_19) + 0x218)) != 0) {
                            var_3_2 = (*(s32 *)((u8 *)((temp_19 + ((*(s16 *)((u8 *)(temp_19) + 0x21A)) * 4))) + 0x1FC));
                        } else {
                            var_3_2 = (*(s32 *)((u8 *)((temp_19 + ((*(s16 *)((u8 *)(temp_19) + 0x21A)) * 4))) + 0x1F0));
                        }
                        temp_f20 = func_L01_0040E570(&D_1A4C60, D_L16_001E015C + (var_3_2 << 8) + 0x10);
                        if ((*(s16 *)((u8 *)(temp_19) + 0x210)) == 0) {
                            var_3_3 = (*(s32 *)((u8 *)((temp_19 + ((2 - (*(s16 *)((u8 *)(temp_19) + 0x212))) * 4))) + 0x1F0));
                        } else {
                            var_3_3 = (*(s32 *)((u8 *)((temp_19 + ((2 - (*(s16 *)((u8 *)(temp_19) + 0x212))) * 4))) + 0x1FC));
                        }
                        if (temp_f20 < func_L01_0040E570(&D_1A4C60, D_L16_001E015C + (var_3_3 << 8) + 0x10)) {
                            var_18 = 1;
                        }
                    }
                }
                if (((*(s32 *)((u8 *)(temp_19) + 0x190)) == 2) && ((*(s32 *)((u8 *)(temp_19) + 0x1B0)) == 0) && (((var_22 != 0) && ((*(u8 *)((u8 *)(arg0) + 0x94)) != 5)) || ((*(s32 *)((u8 *)(temp_19) + 0x1BC)) == 0))) {
                    var_18 = 1;
                }
            }
            var_17 = 0;
            if (var_18 == 0) {
                temp_3_10 = (*(s32 *)((u8 *)(temp_19) + 0x190));
                if (temp_3_10 == 1) {
                    if (var_22 == 0) {
                        goto block_134;
                    }
                    goto block_137;
                }
block_134:
                if ((temp_3_10 == 3) && (var_22 != 0) && (func_00382468() != 0)) {
block_137:
                    var_17 = 1;
                }
                if ((*(s32 *)((u8 *)(temp_19) + 0x1B0)) != 0) {
                    var_17 = (var_22 != 0) ? 1 : var_17;
                }
            }
            var_16_2 = 0;
            if ((var_18 == 0) && (var_17 == 0) && ((*(s32 *)((u8 *)(temp_19) + 0x1B0)) == 0)) {
                temp_3_11 = (*(s32 *)((u8 *)(temp_19) + 0x1B8));
                if (temp_3_11 == 2) {
                    var_16_2 = (*(s32 *)((u8 *)(temp_19) + 0x1D4)) < 1;
                }
                if (temp_3_11 == 1) {
                    var_16_2 = (var_18 >= (*(s32 *)((u8 *)(temp_19) + 0x1D8))) ? temp_3_11 : var_16_2;
                }
                if (func_0038DBA0(temp_f21, (*(f32 *)((u8 *)(arg0) + 0xF8))) > 0.017453292f) {
                    var_16_2 = 0;
                }
                if ((*(s32 *)((u8 *)(temp_19) + 0x1BC)) == 2) {
                    var_16_2 = (((*(s32 *)((u8 *)(temp_19) + 0x190)) ^ 1) == 0) ? 0 : var_16_2;
                    if (var_22 == 0) {
                        var_16_2 = (((*(s32 *)((u8 *)(temp_19) + 0x1B8)) ^ 2) == 0) ? 0 : var_16_2;
                    }
                }
            }
            if ((*(s32 *)((u8 *)(temp_19) + 0x224)) != 0) {
                var_5_2 = 0xA;
                goto block_364;
            }
            var_5_2 = 4;
            if (var_17 == 0) {
                if (var_18 != 0) {
                    var_5_2 = 5;
                    goto block_364;
                }
                if (var_16_2 != 0) {
                    temp_4_3 = (*(s32 *)((u8 *)(temp_19) + 0x1B8));
                    if (temp_4_3 == 2) {
                        var_5_2 = 8;
                        goto block_364;
                    }
                    if (temp_4_3 == 1) {
                        var_5_2 = 9;
                        goto block_364;
                    }
                }
            } else {
                goto block_364;
            }
            break;
        case 8:                                     /* switch 2 */
            if ((*(s32 *)((u8 *)(temp_19) + 0x1E0)) == 0) {
                var_4 = 0;
                if ((*(s32 *)((u8 *)(temp_19) + 0x190)) == 3) {
                    var_4 = func_00382468() != 0;
                }
                (*(s32 *)((u8 *)(temp_19) + 0x1DC)) = 1;
                (*(s32 *)((u8 *)(temp_19) + 0x1E0)) = (s32) ((var_4 == 0) ? 3 : 2);
                (*(s32 *)((u8 *)(temp_19) + 0x1D0)) = var_4;
            }
            if (func_L01_004561B8(arg0) != 0) {
                temp_3_12 = (*(u8 *)((u8 *)(arg0) + 0x43));
                if ((*(s32 *)((u8 *)(temp_19) + 0x1BC)) == 2) {
                    if (temp_3_12 != 8) {
                        func_003C3A10(arg0, 8, 0, 0xA);
                    }
                } else if (temp_3_12 != 0xC) {
                    func_003C3A10(arg0, 0xC, 0, 0xA);
                }
            }
            var_23 = arg0 + 0x10;
            if ((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43))) {
                if ((*(void **)((u8 *)(temp_19) + 0x1C0)) != 0) {
                    goto block_200;
                }
                if ((*(void **)((u8 *)(temp_19) + 0x1C4)) != 0) {
                    goto block_200;
                }
                if ((*(void **)((u8 *)(temp_19) + 0x1C8)) != 0) {
                    goto block_200;
                }
                if ((*(void **)((u8 *)(temp_19) + 0x1CC)) != 0) {
block_200:
                    var_f12 = 7.0f;
                    if ((*(s32 *)((u8 *)(temp_19) + 0x1BC)) == 2) {
                        var_f12 = 15.0f;
                    }
                    if (func_L01_0044E1B8(arg0, var_f12) != 0) {
                        func_003A52A0();
                    }
                    temp_2_3 = (*(s32 *)((u8 *)(temp_19) + 0x1BC));
                    var_f20 = 5.0f;
                    if (temp_2_3 == 2) {
                        var_f20 = 14.0f;
                    }
                    var_f21 = 15.0f;
                    if (temp_2_3 == 2) {
                        var_f21 = 21.0f;
                    }
                    var_f23 = (func_L01_004395E0(arg0) - var_f20) / (var_f21 - var_f20);
                    if (var_f23 > 1.0f) {
                        var_f23 = 1.0f;
                    } else if (var_f23 < 0.0f) {
                        var_f23 = 0.0f;
                    }
                    func_003C2F58(arg0, 4, &sp10);
                    var_23 = arg0 + 0x10;
                    func_003C2F58(arg0, 5, &sp20);
                    0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                    func_0038CE20(sp, sp, 0.5f);
                    temp_4_4 = (*(void **)((u8 *)(temp_19) + 0x1C0));
                    if (temp_4_4 != 0) {
                        func_L16_003E7300(temp_4_4, sp, temp_19 + 0x240, var_f23);
                    }
                    if ((var_f23 >= 1.0f) || ((*(s32 *)((u8 *)(temp_19) + 0x1D0)) != 0)) {
                        var_16_3 = temp_19 + 0x1C0;
                        sp44 = temp_19 + 0x1FC;
                        var_21 = 0;
                        sp40 = &sp20;
                        sp48 = temp_19 + 0x1F0;
loop_241:
                        if ((*(s32 *)((u8 *)(temp_19) + 0x1D0)) != 0) {
                            if (var_21 < 4) {
                                goto block_217;
                            }
                        } else if (var_21 <= 0) {
block_217:
                            if ((*(s32 *)((u8 *)(temp_19) + 0x1D0)) != 0) {
                                if (!((2.0f * (var_f23 - 0.5f)) < 0.0f)) {
                                    if (var_21 <= 0x3DCCCCCD) {
                                        goto block_220;
                                    }
                                }
                            } else {
block_220:
                                temp_4_5 = *var_16_3;
                                if (temp_4_5 != 0) {
                                    func_L16_003E7300(temp_4_5, sp, temp_19 + 0x240, 1.0f);
                                    temp_22 = temp_19 + 0x240;
                                    0 /* unknown instruction: lqc2 $vf2, 0x4c60($s1) */;
                                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                                    sp20 = (*(f32 *)((u8 *)(arg0) + 0x10));
                                    if ((*(s32 *)((u8 *)(temp_19) + 0x1D0)) != 0) {
                                        var_f12_2 = D_L16_001DE938;
                                        if ((func_0038CEA8(sp40) * 0.5f) < var_f12_2) {
                                            var_f12_2 = func_0038CEA8(&sp20) * 0.5f;
                                        }
                                        func_0038CF68(&sp20, &sp20, var_f12_2);
                                        temp_f20_2 = func_00382538();
                                        temp_f21_2 = func_003824E0(0, D_L16_001DE938);
                                        sp30 = func_0038D098(temp_f20_2) * temp_f21_2;
                                        temp_f0 = func_0038D0B0(temp_f20_2) * temp_f21_2;
                                        sp38 = 0.0f;
                                        sp34 = temp_f0;
                                        var_f1 = sp20;
                                        0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                                    } else {
                                        var_f12_3 = D_L16_001DE938;
                                        if ((func_0038CEA8(sp40) * 0.5f) < var_f12_3) {
                                            var_f12_3 = func_0038CEA8(&sp20) * 0.5f;
                                        }
                                        func_0038CF68(&sp20, &sp20, var_f12_3);
                                        var_f1 = 0 /* second half of f64 */;
                                    }
                                    0 /* unknown instruction: lqc2 $vf1, 0x4c60($s1) */;
                                    0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                                    var_f20_2 = D_L16_001DE934;
                                    sp10 = var_f1;
                                    if ((*(s32 *)((u8 *)(temp_19) + 0x1D0)) != 0) {
                                        var_f20_2 *= func_003824E0(0.800000012f, 1.4f);
                                    }
                                    temp_f22 = func_0038CF38() / var_f20_2;
                                    func_L16_003CBF50(arg0, &sp10, temp_22, &sp10, temp_f22);
                                    var_3_4 = sp44;
                                    if ((s16) (*(u32 *)((u8 *)(temp_19) + 0x214)) != 0) {

                                    } else {
                                        var_3_4 = sp48;
                                    }
                                    temp_4_6 = D_L16_001E015C + (*(var_3_4 + ((*(s16 *)((u8 *)(temp_19) + 0x216)) * 4)) << 8);
                                    sp18 = (*(f32 *)((u8 *)(temp_4_6) + 0x18)) + 2.618f;
                                    temp_f20_3 = func_0038D160(*(f32 *)&temp_4_6, sp10 - (*(f32 *)((u8 *)(arg0) + 0x10)));
                                    temp_f21_3 = func_0038CF38() / temp_f22;
                                    sp20 = func_0038D098(temp_f20_3) * temp_f21_3;
                                    temp_f0_2 = func_0038D0B0(temp_f20_3) * temp_f21_3;
                                    sp28 = 0.0f;
                                    sp24 = temp_f0_2;
                                    sp28 = -fabsf((*(f32 *)((u8 *)(*var_16_3) + 0x18)) - sp18) / temp_f22;
                                    0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                                    var_3_5 = sp44;
                                    if ((s16) (*(u32 *)((u8 *)(temp_19) + 0x214)) != 0) {

                                    } else {
                                        var_3_5 = sp48;
                                    }
                                    func_L16_003E7280(*var_16_3, &sp20, temp_22, D_L16_001E015C + (*(var_3_5 + ((*(s16 *)((u8 *)(temp_19) + 0x216)) * 4)) << 8));
                                    *var_16_3 = 0;
                                    if (((*(s32 *)((u8 *)(temp_19) + 0x1D0)) == 0) || (var_21 == 3)) {
                                        (*(s32 *)((u8 *)(arg0) + 0x48)) = 0x3F800000;
                                    }
                                }
                            }
                            var_16_3 += 4;
                            var_21 += 1;
                            goto loop_241;
                        }
                    }
                } else {
                    var_f12_4 = 5.0f;
                    if ((*(s32 *)((u8 *)(temp_19) + 0x1BC)) == 2) {
                        var_f12_4 = 14.0f;
                    }
                    if (func_L01_0044E1B8(arg0, var_f12_4) != 0) {
                        var_f0 = D_L16_001DE930;
                        if ((*(s32 *)((u8 *)(temp_19) + 0x1D0)) == 0) {
                            var_f0 = D_L16_001DE92C;
                        }
                        (*(s32 *)((u8 *)(arg0) + 0x48)) = var_f0;
                        func_003C2F58(arg0, 4, &sp10);
                        func_003C2F58(arg0, 5, &sp20);
                        0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                        func_0038CE20(sp, sp, 0.5f);
                        if ((*(s32 *)((u8 *)(temp_19) + 0x1D0)) != 0) {
                            var_23 = arg0 + 0x10;
                            (*(void **)((u8 *)(temp_19) + 0x1C0)) = func_L16_003E6C48(arg0, sp, 0x3EAA7EFA, (f32) (*(u8 *)((u8 *)(temp_19) + 0x56)));
                            (*(void **)((u8 *)(temp_19) + 0x1C4)) = func_L16_003E6C48(arg0, sp, 0x3EAA7EFA, (f32) (*(u8 *)((u8 *)(temp_19) + 0x56)));
                            (*(void **)((u8 *)(temp_19) + 0x1C8)) = func_L16_003E6C48(arg0, sp, 0x3EAA7EFA, (f32) (*(u8 *)((u8 *)(temp_19) + 0x56)));
                            (*(void **)((u8 *)(temp_19) + 0x1CC)) = func_L16_003E6C48(arg0, sp, 0x3EAA7EFA, (f32) (*(u8 *)((u8 *)(temp_19) + 0x56)));
                        } else {
                            var_23 = arg0 + 0x10;
                            (*(void **)((u8 *)(temp_19) + 0x1C0)) = func_L16_003E6C48(arg0, sp, 0x3F800000, (f32) (*(u8 *)((u8 *)(temp_19) + 0x55)));
                            (*(void **)((u8 *)(temp_19) + 0x1CC)) = 0;
                            (*(void **)((u8 *)(temp_19) + 0x1C4)) = 0;
                            (*(void **)((u8 *)(temp_19) + 0x1C8)) = 0;
                        }
                    } else if (func_L01_0044E1B8(arg0, 35.0f) != 0) {
                        temp_2_4 = (*(s32 *)((u8 *)(temp_19) + 0x1E0)) - 1;
                        (*(s32 *)((u8 *)(temp_19) + 0x1E0)) = temp_2_4;
                        if (temp_2_4 == 0) {
                            temp_3_13 = (*(s32 *)((u8 *)(temp_19) + 0x1D8));
                            (*(s32 *)((u8 *)(temp_19) + 0x1D4)) = (s32) D_L16_001DE958;
                            (*(s32 *)((u8 *)(temp_19) + 0x1D8)) = (s32) ((temp_3_13 <= 0x31) ? 0x32 : temp_3_13);
                            (*(s32 *)((u8 *)(temp_19) + 0x1B0)) = 1;
                            (*(s32 *)((u8 *)(temp_19) + 0x1B8)) = 1;
                        } else {
                            (*(s32 *)((u8 *)(temp_19) + 0x1D4)) = 0x32;
                        }
                        if ((*(f32 *)((u8 *)(temp_19) + 0x1A0)) < 0.0f) {
                            (*(f32 *)((u8 *)(temp_19) + 0x1A0)) = 0.0f;
                        }
                        var_23 = arg0 + 0x10;
                        func_L01_004450F0(arg0, 7U, -1);
                    }
                }
            }
block_398:
            var_5_4 = var_23;
block_399:
            func_L16_003CBC88(arg0, var_5_4, -1, (*(f32 *)((u8 *)(arg0) + 0xF8)));
            break;
        case 9:                                     /* switch 2 */
            if ((*(s32 *)((u8 *)(temp_19) + 0x1E0)) == 0) {
                (*(s32 *)((u8 *)(temp_19) + 0x1DC)) = 0;
                (*(s32 *)((u8 *)(temp_19) + 0x1E0)) = 4;
            }
            if ((*(s32 *)((u8 *)(temp_19) + 0x1DC)) == 0) {
                func_L16_003CC0A8(arg0);
                (*(s32 *)((u8 *)(temp_19) + 0x1DC)) = 0x14;
                (*(f32 *)((u8 *)(temp_19) + 0x1EC)) = (f32) D_L16_001DE93C;
            }
            if (func_L01_004561B8(arg0) != 0) {
                temp_3_14 = (*(u8 *)((u8 *)(arg0) + 0x43));
                if ((*(s32 *)((u8 *)(temp_19) + 0x1BC)) == 2) {
                    if (temp_3_14 != 7) {
                        func_003C3A10(arg0, 7, 0, 0xA);
                    }
                } else if (temp_3_14 != 0xB) {
                    func_003C3A10(arg0, 0xB, 0, 0xA);
                }
                (*(s32 *)((u8 *)(arg0) + 0x48)) = (s32) D_L16_001DE960;
            }
            temp_17 = &D_1A4C60 - 0x80;
            sp8 += 5.0f;
            temp_f0_3 = -func_0038D160(func_0038CF38(), (*(f32 *)((u8 *)(temp_17) + 0x88)) - sp8);
            (*(f32 *)((u8 *)(temp_19) + 0x354)) = temp_f0_3;
            (*(f32 *)((u8 *)(temp_19) + 0x2D4)) = temp_f0_3;
            if ((*(s32 *)((u8 *)(temp_19) + 0x1BC)) == 2) {
                func_L16_003CBC88(arg0, temp_19 + 0x260, -1, func_0038D160((*(f32 *)((u8 *)(temp_17) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_17) + 0x84)) - (*(f32 *)((u8 *)(arg0) + 0x14))));
            } else {
                func_L16_003CBC88(arg0, arg0 + 0x10, -1, (*(f32 *)((u8 *)(arg0) + 0xF8)));
            }
            var_16_4 = 0;
            if ((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43))) {
                var_f12_5 = 6.5f;
                if ((*(s32 *)((u8 *)(temp_19) + 0x1BC)) == 2) {
                    var_f12_5 = 8.0f;
                }
                if (func_L01_0044E1B8(arg0, var_f12_5) != 0) {
                    var_16_4 = 1;
                    func_003C2F58(arg0, 2, sp);
                } else if (func_L01_0044E1B8(arg0, 0.5f) != 0) {
                    var_16_4 = 1;
                    func_003C2F58(arg0, 3, sp);
                }
            }
            if (var_16_4 != 0) {
                temp_18 = temp_19 + 0x240;
                func_L16_003CC150(arg0, &sp20);
                0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                sp30 = (*(f32 *)((u8 *)(arg0) + 0x10));
                func_0038CF68(&sp30, &sp30, (*(f32 *)((u8 *)(temp_19) + 0x1EC)));
                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                func_L16_003CBF50(arg0, &sp20, temp_18, &sp10, func_0038CF38() / 0.8000001f);
                func_L16_003E8580(arg0, sp, &sp10, temp_18, 0x3F000000, (f32) (*(u8 *)((u8 *)(temp_19) + 0x54)));
                temp_2_5 = (*(s32 *)((u8 *)(temp_19) + 0x1DC)) - 1;
                (*(s32 *)((u8 *)(temp_19) + 0x1DC)) = temp_2_5;
                (*(f32 *)((u8 *)(temp_19) + 0x1EC)) = (f32) ((*(f32 *)((u8 *)(temp_19) + 0x1EC)) - 1.0f);
                if (temp_2_5 == 0) {
                    temp_2_6 = (*(s32 *)((u8 *)(temp_19) + 0x1E0)) - 1;
                    (*(s32 *)((u8 *)(temp_19) + 0x1E0)) = temp_2_6;
                    if (temp_2_6 == 0) {
                        temp_3_15 = (*(s32 *)((u8 *)(temp_19) + 0x1D4));
                        (*(s32 *)((u8 *)(temp_19) + 0x1D8)) = (s32) D_L16_001DE954;
                        (*(s32 *)((u8 *)(temp_19) + 0x1B8)) = 2;
                        (*(s32 *)((u8 *)(temp_19) + 0x1D4)) = (s32) ((temp_3_15 <= 0x31) ? 0x32 : temp_3_15);
                        (*(s32 *)((u8 *)(temp_19) + 0x1B0)) = 1;
                    } else {
                        (*(s32 *)((u8 *)(temp_19) + 0x1D8)) = 0x4B;
                    }
                    if ((*(f32 *)((u8 *)(temp_19) + 0x1A0)) < 0.0f) {
                        (*(f32 *)((u8 *)(temp_19) + 0x1A0)) = 0.0f;
                    }
block_362:
block_363:
                    var_5_2 = 7;
                    goto block_364;
                }
            }
            break;
        case 5:                                     /* switch 2 */
            var_18_2 = 0;
            if (func_L01_004561B8(arg0) != 0) {
                temp_4_7 = (*(u8 *)((u8 *)(arg0) + 0x94));
                if (temp_4_7 != 4) {
                    temp_5 = (*(s32 *)((u8 *)(temp_19) + 0x1BC));
                    if (temp_5 == 2) {
                        if ((u32) (*(s16 *)((u8 *)(temp_19) + 0x210)) != (*(u32 *)((u8 *)(temp_19) + 0x214))) {
                            if ((*(s16 *)((u8 *)(temp_19) + 0x210)) != (s16) (*(u32 *)((u8 *)(temp_19) + 0x214))) {
                                var_2 = (*(s16 *)((u8 *)(temp_19) + 0x212)) - (*(s16 *)((u8 *)(temp_19) + 0x216));
                                if (var_2 <= 0) {
                                    var_2 = -var_2;
                                }
                                if (var_2 != temp_5) {
                                    goto block_295;
                                }
                                goto block_297;
                            }
block_295:
                            if ((temp_4_7 == 3) || (temp_4_7 == 7)) {
                                goto block_297;
                            }
                        } else {
block_297:
                            var_18_2 = 1;
                        }
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 6) {
                            func_003C3A10(arg0, 6, func_00382468(), 0xA);
                        }
                    } else {
                        var_5_5 = 3;
                        goto block_289;
                    }
                } else {
                    var_5_5 = 7;
block_289:
                    func_L01_004450F0(arg0, var_5_5, -1);
                }
            }
            if ((*(s32 *)((u8 *)(temp_19) + 0x1B8)) == 2) {
                if (var_18_2 == 0) {

                } else {
                    if ((*(s32 *)((u8 *)(temp_19) + 0x1E8)) != 0) {
                        var_2_2 = 1 - (u16) (*(u32 *)((u8 *)(temp_19) + 0x214));
                    } else {
                        var_2_2 = (u16) (*(s16 *)((u8 *)(temp_19) + 0x210));
                    }
                    (*(s16 *)((u8 *)(temp_19) + 0x218)) = (s16) var_2_2;
                    if ((*(s16 *)((u8 *)(temp_19) + 0x216)) == 1) {
                        if ((*(s16 *)((u8 *)(temp_19) + 0x218)) == 0) {
                            var_2_3 = (*(s32 *)((u8 *)(temp_19) + 0x1F0));
                        } else {
                            var_2_3 = (*(s32 *)((u8 *)(temp_19) + 0x1FC));
                        }
                        temp_f20_4 = func_L01_0040E570(&D_1A4C60, D_L16_001E015C + (var_2_3 << 8) + 0x10);
                        if ((*(s16 *)((u8 *)(temp_19) + 0x218)) == 0) {
                            var_2_4 = (*(s32 *)((u8 *)(temp_19) + 0x1F8));
                        } else {
                            var_2_4 = (*(s32 *)((u8 *)(temp_19) + 0x204));
                        }
                        var_2_5 = 2;
                        if (!(temp_f20_4 < func_L01_0040E570(&D_1A4C60, D_L16_001E015C + (var_2_4 << 8) + 0x10))) {
                            (*(s16 *)((u8 *)(temp_19) + 0x21A)) = 0;
                        } else {
                            goto block_317;
                        }
                    } else {
                        var_2_5 = 2 - (u16) (*(s16 *)((u8 *)(temp_19) + 0x216));
block_317:
                        (*(s16 *)((u8 *)(temp_19) + 0x21A)) = var_2_5;
                    }
                    temp_3_16 = (*(s16 *)((u8 *)(temp_19) + 0x21A));
                    var_f1_2 = -6.0f;
                    if (temp_3_16 < (*(s16 *)((u8 *)(temp_19) + 0x216))) {
                        var_f1_2 = 6.0f;
                    }
                    (*(f32 *)((u8 *)(temp_19) + 0x250)) = var_f1_2;
                    (*(f32 *)((u8 *)(temp_19) + 0x258)) = 1.618f;
                    (*(s32 *)((u8 *)(temp_19) + 0x254)) = 0;
                    if ((*(s16 *)((u8 *)(temp_19) + 0x218)) != 0) {
                        var_3_6 = (*(s32 *)((u8 *)((temp_19 + (temp_3_16 * 4))) + 0x1FC));
                    } else {
                        var_3_6 = (*(s32 *)((u8 *)((temp_19 + (temp_3_16 * 4))) + 0x1F0));
                    }
                    var_16_5 = D_L16_001E015C + (var_3_6 << 8);
                    var_4_2 = temp_19 + 0x260;
                    var_5_6 = temp_19 + 0x250;
                    goto block_351;
                }
            } else {
                if (var_18_2 != 0) {
                    temp_17_2 = temp_19 + 0x1FC;
                    temp_16_2 = temp_19 + 0x1F0;
loop_326:
                    if ((*(s32 *)((u8 *)(temp_19) + 0x1E8)) != 0) {
                        var_2_6 = func_00382498(0, 1);
                    } else {
                        var_2_6 = 0;
                    }
                    (*(s16 *)((u8 *)(temp_19) + 0x218)) = var_2_6;
                    (*(s16 *)((u8 *)(temp_19) + 0x21A)) = func_00382498(0, 2);
                    (*(f32 *)((u8 *)(temp_19) + 0x250)) = func_003824E0(-6.0f, 6.0f);
                    (*(f32 *)((u8 *)(temp_19) + 0x258)) = 1.618f;
                    (*(s32 *)((u8 *)(temp_19) + 0x254)) = 0;
                    if ((*(s16 *)((u8 *)(temp_19) + 0x218)) != 0) {
                        var_2_7 = temp_17_2 + ((*(s16 *)((u8 *)(temp_19) + 0x21A)) * 4);
                    } else {
                        var_2_7 = temp_16_2 + ((*(s16 *)((u8 *)(temp_19) + 0x21A)) * 4);
                    }
                    if ((*(s16 *)((u8 *)(temp_19) + 0x210)) != 0) {
                        var_2_8 = temp_17_2 + ((*(s16 *)((u8 *)(temp_19) + 0x212)) * 4);
                    } else {
                        var_2_8 = temp_16_2 + ((*(s16 *)((u8 *)(temp_19) + 0x212)) * 4);
                    }
                    if ((D_L16_001E015C + (*var_2_7 << 8)) != (D_L16_001E015C + (*var_2_8 << 8))) {
                        temp_2_7 = (*(s16 *)((u8 *)(temp_19) + 0x21A));
                        if ((*(s16 *)((u8 *)(temp_19) + 0x218)) != 0) {
                            var_2_9 = temp_17_2 + (temp_2_7 * 4);
                        } else {
                            var_2_9 = temp_16_2 + (temp_2_7 * 4);
                        }
                        temp_5_2 = D_L16_001E015C + (*var_2_9 << 8);
                        if ((s16) (*(u32 *)((u8 *)(temp_19) + 0x214)) != 0) {
                            var_18_3 = 0;
                            if (temp_5_2 != (D_L16_001E015C + (*(temp_17_2 + ((*(s16 *)((u8 *)(temp_19) + 0x216)) * 4)) << 8))) {

                            } else {
                                goto block_343;
                            }
                        } else {
                            var_18_3 = 0;
                            if (temp_5_2 == (D_L16_001E015C + (*(temp_16_2 + ((*(s16 *)((u8 *)(temp_19) + 0x216)) * 4)) << 8))) {
                                goto block_343;
                            }
                        }
                    } else {
block_343:
                        var_18_3 = 1;
                    }
                    if (var_18_3 != 0) {
                        goto loop_326;
                    }
                }
                if ((*(s16 *)((u8 *)(temp_19) + 0x218)) != 0) {
                    var_3_7 = (*(s32 *)((u8 *)((temp_19 + ((*(s16 *)((u8 *)(temp_19) + 0x21A)) * 4))) + 0x1FC));
                } else {
                    var_3_7 = (*(s32 *)((u8 *)((temp_19 + ((*(s16 *)((u8 *)(temp_19) + 0x21A)) * 4))) + 0x1F0));
                }
                var_16_5 = D_L16_001E015C + (var_3_7 << 8);
                var_4_2 = temp_19 + 0x260;
                var_5_6 = temp_19 + 0x250;
block_351:
                func_0038D000(var_4_2, var_5_6, var_16_5 + 0xC0);
                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                (*(f32 *)((u8 *)(temp_19) + 0x260)) = (f32) (*(f32 *)((u8 *)(temp_19) + 0x260));
            }
            if ((*(s32 *)((u8 *)(temp_19) + 0x1BC)) != 2) {
                var_5_4 = arg0 + 0x10;
                goto block_399;
            }
            temp_16_3 = temp_19 + 0x260;
            func_L16_003CBC88(arg0, temp_16_3, -1, func_0038D160((*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)) - (*(f32 *)((u8 *)(arg0) + 0x14))));
            if (((*(s32 *)((u8 *)(temp_19) + 0x190)) == 1) || ((*(s32 *)((u8 *)(temp_19) + 0x1B8)) != 1)) {
                if (func_L01_0040E570(arg0 + 0x10, temp_16_3) < 1.0f) {
                    temp_4_8 = (*(s32 *)((u8 *)(temp_19) + 0x190));
                    if (temp_4_8 != 1) {
                        if (temp_4_8 == 3) {
                            if (func_00382468() != 0) {
                                goto block_361;
                            }
                            goto block_362;
                        }
                        goto block_363;
                    }
block_361:
                    var_5_2 = 4;
                    goto block_364;
                }
            } else {
                goto block_363;
            }
            break;
        case 10:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                if ((*(s32 *)((u8 *)(temp_19) + 0x1BC)) != 2) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 2) {
                        func_003C3A10(arg0, 2, 0, 0xA);
                    }
                    (*(s32 *)((u8 *)(temp_19) + 0x224)) = 0;
                    (*(s32 *)((u8 *)(temp_19) + 0x1E4)) = (s32) D_L16_001DE950;
                    (*(s32 *)((u8 *)(temp_19) + 0x1B0)) = 0;
                    *(s32 *)0x1A73E8 = 0;
                } else {
                    func_L01_004450F0(arg0, 4U, -1);
                }
            }
            temp_3_17 = (*(u8 *)((u8 *)(arg0) + 0x43));
            if ((temp_3_17 == 2) && ((*(u8 *)((u8 *)(arg0) + 0x42)) == temp_3_17) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                func_L01_004450F0(arg0, 7U, -1);
            }
            var_5_4 = arg0 + 0x10;
            goto block_399;
        case 11:                                    /* switch 2 */
            var_23 = arg0 + 0x10;
            if (func_L01_004561B8(arg0) != 0) {
                temp_4_9 = (*(void **)((u8 *)(temp_19) + 0x1C0));
                if (temp_4_9 != 0) {
                    func_L01_004028B0(temp_4_9);
                    (*(void **)((u8 *)(temp_19) + 0x1C0)) = 0;
                }
                temp_3_18 = (*(u8 *)((u8 *)(arg0) + 0x43));
                if ((*(s32 *)((u8 *)(temp_19) + 0x1BC)) == 2) {
                    if (temp_3_18 != 9) {
                        func_003C3A10(arg0, 9, 0, 7);
                        var_2_10 = D_L16_001DFC40;
                    } else {
                        goto block_387;
                    }
                } else {
                    if (temp_3_18 != 0xD) {
                        func_003C3A10(arg0, 0xD, 0, 7);
                    }
                    goto block_387;
                }
            } else {
block_387:
                var_2_10 = D_L16_001DFC40;
            }
            (*(s32 *)((u8 *)(temp_19) + 0x19C)) = (s32) (var_2_10 + 2);
            if ((*(u8 *)((u8 *)(arg0) + 0x43)) == 9) {
                if (func_L01_0044E1B8(arg0, 32.0f) == 0) {
                    goto block_391;
                }
                goto block_393;
            }
block_391:
            if (((*(u8 *)((u8 *)(arg0) + 0x43)) == 0xD) && (func_L01_0044E1B8(arg0, 25.0f) != 0)) {
block_393:
                temp_3_19 = (*(u8 *)((u8 *)(arg0) + 0x95));
                switch (temp_3_19) {                /* switch 3; irregular */
                case 1:                             /* switch 3 */
                    func_L01_004450F0(arg0, 2U, -1);
                    /* fallthrough */
                case 2:                             /* switch 3 */
                    func_L01_004450F0(arg0, 5U, -1);
                    break;
                }
            }
            goto block_398;
        case 12:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                temp_4_10 = (*(void **)((u8 *)(temp_19) + 0x1C0));
                if (temp_4_10 != 0) {
                    func_L01_004028B0(temp_4_10);
                    (*(void **)((u8 *)(temp_19) + 0x1C0)) = 0;
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xE) {
                    func_003C3A10(arg0, 0xE, 0, 0xA);
                }
            }
            if (func_L01_00456250(arg0) == 0) {
                *(s16 *)0x1A4DBC = 2;
            }
            if (((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) && ((*(u8 *)((u8 *)(arg0) + 0x42)) == (*(u8 *)((u8 *)(arg0) + 0x43)))) {
                (*(s32 *)((u8 *)(arg0) + 0x48)) = 0;
                func_L01_00456230(arg0, 1);
            }
            func_L16_003CBC88(arg0, arg0 + 0x10, -1, (*(f32 *)((u8 *)(arg0) + 0xF8)));
            break;
        }
        func_L16_003CC1A8(arg0);
        func_L16_003CBBF0(arg0);
    }
}
