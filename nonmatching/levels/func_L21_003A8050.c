/* func_L21_003A8050: Opus handoff (prep by Sonnet worker w7, 2026-11-08)
   Size: 6036 bytes, places: 1 levels (21), file: src/levels/21_obani_draco/L21_003A8050.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: one function (one prologue addiu sp,-0x90, one epilogue), 3 switches / 2 jump tables (23 entries): switch(+0x95) (phase), switch(+0x20) (state), a third on a local.
   Twin: none (rac2 index best func_L15_003DBB08 at 0.25). Checked: callee fingerprint (callfp: 2 callees mapped, no family); whole-corpus opcode search over every rac3 and rac2 function >= 600 B (best rac2:func_L12_003E0BF0 0.22); names.tsv/NAMES.md (no entry); matched rac3 siblings in src/ (only the scaffold is shared).
   Mapping: Common enemy/boss scaffold (matches the tools' names): arg0 = moby; +0x20 = state byte (func_L01_004450F0 = moby_set_state(moby, state, sub)), +0x95 = phase byte, +0x68 = per-object data, func_L01_004561B8 = animation-done test, func_003C3A10 = moby_anim_blend(moby, anim, 0, 8), func_0038CB00 = timer_tick_short, D_1A4BE0 = hero/global struct (+0x25C0 hero moby, +0x25C4 hero state, +0xC08 pad bits). $gp loads are named D_<0x1DC8B0+offset> (D_LNN_ when >= 0x1D9900) in the draft. Own callees: func_L21_003A97E8 (pre-check bool), func_L21_003A9B20 (prep), func_L21_003AA068 (matched: hp <= 0), func_L21_003AA090 (matched: state == 0x18), func_L21_00339190/00339248/00339258/003392E0/003393C0 (L21 helpers).
   Identical / changed / added / removed: n/a (no twin). Per-state shared tails are m2c block_104/111/167/223 (the 'if (+0x60 & 2) set_state(1,-1)' tail of states 3/4/5/9-12).
   VU0: 3 vadd.xyz/vsub.xyz ops in the retail asm; inline-asm VU0 is banned since 2026-11-06 (Matching-Patterns), so this function cannot reach MATCH unless the ops come from plain C; the lq/sq copies are fine (u128_t).
   Draft: compiles (m2c draft cleaned by tools/post.py (real repo prototypes where known, m2c gotos kept)); 1458 diff; opcode-equal 375 of 1510 (mine 1322), ratio 0.26.
     Retail rows yours=1322 retail=1510 equalrows=52.
   Left for Opus:
     1. Turn the m2c gotos (block_104, 111, 167, 223) back into retail's structure (phase switch falls into the state switch; most cases end in the shared +0x60&2 tail).
     2. The frame matches (0x90) but s-register order differs: retail keeps moby, +0x68 object and hero ptr live; mine uses extra temps.
     3. sp10..sp28 are an f32[] vector local passed as &sp to func_L21_00339190 / func_L21_003B1118 / 1518.
     4. 3 VU0 ops (vsub.xyz at 003A8B58, 003A8C44, vadd at 003A8E54 region) cannot be written in plain C.
*/
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038CF38();
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern int func_L01_004561B8(u8 *);
extern int func_L01_004561E0(void *a0);
extern s32 func_00382468();
extern s32 func_00382498(s32, s32);
extern s32 func_0038CB00(void *);
extern s32 func_L01_0045A7A8(void *, f32 *, f32);
extern s32 func_L01_004BA800(void);
extern s32 func_L21_003AA068(void *arg0);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_00404A10(void *a0, s32 a1);
extern void func_L01_004443E8(s32, s32, s32);
extern void func_L01_0045BD78(u8 *a0, f32 a, f32 b, f32 c, f32 d);
extern void func_L01_004AA7E8(s32, s32);
f32 func_L01_004395E0(void *);                      /* extern */
s32 func_L01_004450F0();  /* extern, call arities [3, 4], m2c proto was (void *, s32, s32, s32) */
s32 func_L01_00445170(void *, s32);         /* extern */
s32 func_L01_004468C8(void *, s32, s32, s32, s32, s32, s32, f32, s32); /* extern */
s8 func_L01_00448070(s32, s32, f32);        /* extern */
s32 func_L01_00448890(void *, void *, s32, f32, f32, f32, f32); /* extern */
s32 func_L01_0044E1B8(void *, s32);             /* extern */
s32 func_L01_00454370(void *, void *);              /* extern */
s32 func_L01_0045A748(void *, void *);          /* extern */
s32 func_L01_0045AA30(void *, f32 *);           /* extern */
s32 func_L01_0046C470(f32 *, f32 *, s32, s32, s32, s32, s32, s32, f32); /* extern */
s32 func_L21_00339190(void *, void *, s32);     /* extern */
s32 func_L21_00339248(s32);                         /* extern */
s32 func_L21_00339258(s32, s32, s32);       /* extern */
s32 func_L21_003392E0(s32);                     /* extern */
s32 func_L21_003393C0(s32);                         /* extern */
s32 func_L21_003A97E8();                            /* extern */
s32 func_L21_003A9B20(void *);                  /* extern */
s32 func_L21_003B1118(void *, s32, f32 *, f32 *, s32, f32); /* extern */
s32 func_L21_003B1518(void *, s32, f32 *, f32 *, s32, f32); /* extern */
s32 func_L21_003B1A00(void *, f32 *, f32, f32); /* extern */
extern s32 D_142660;
extern s32 D_1A4BE0;
extern s32 D_L21_001D66B0;
extern f32 D_L21_001DCF40;
extern f32 D_L21_001DCF44;
extern s32 D_L21_001EC4C0;
extern s32 func_L21_003A9E88;

extern s32 D_001D6694;
extern s32 D_L21_001E1030;
extern s32 D_L21_001E1034;

void func_L21_003A8050(void *arg0) {
    s32 sp[8]; /* m2c: stack-slot base, size unknown */
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp20;
    f32 sp24;
    f32 sp28;
    s32 temp_17;
    s32 var_4;
    s32 var_5;
    s32 var_5_2;
    s32 var_5_4;
    s32 var_5_5;
    s32 var_5_6;
    s32 var_f12;
    f32 *var_5_3;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f0_9;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f21;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f12_2;
    s32 temp_16;
    s32 temp_17_2;
    s32 temp_3_8;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 var_20;
    s8 temp_3_11;
    s8 temp_3_9;
    u16 temp_3;
    u16 temp_3_10;
    u8 temp_2;
    u8 temp_2_2;
    u8 temp_2_3;
    u8 temp_3_2;
    u8 temp_3_6;
    u8 temp_3_7;
    u8 *temp_16_2;
    u8 *temp_19;
    u8 *temp_3_3;
    u8 *temp_3_4;
    u8 *temp_3_5;
    u8 *temp_4;
    u8 *temp_5;

    if (func_L21_003A97E8() == 0) {
        if ((*(u8 *)((u8 *)(arg0) + 0x95)) != 9) {
            if (D_001D6694 == 2) {
                (*(s32 *)((u8 *)(arg0) + 0x98)) = 0;
                (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x41) & 0xEFFF);
                func_L01_004AA7E8(arg0, 1);
            } else {
                if (func_L01_004BA800() == 0) {
                    temp_4 = (*(void **)((u8 *)(arg0) + 0x24));
                    temp_3 = (*(u16 *)((u8 *)(arg0) + 0x34)) & 0xFFBE;
                    (*(u16 *)((u8 *)(arg0) + 0x34)) = temp_3;
                    (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (temp_3 | ((*(u16 *)((u8 *)(temp_4) + 0x44)) & 0x1000));
                    (*(s32 *)((u8 *)(arg0) + 0x98)) = (s32) (*(s32 *)((u8 *)(temp_4) + 0x10));
                }
                goto block_6;
            }
        } else {
block_6:
            func_L21_003A9B20(arg0);
            temp_19 = (*(void **)((u8 *)(arg0) + 0x68));
            if (D_L21_001E1034 == 0) {
                D_L21_001E1034 = 1;
                D_L21_001E1030 = (s32) *(s32 *)0x1A7430;
            }
            temp_3_2 = (*(u8 *)((u8 *)(arg0) + 0x95));
            switch (temp_3_2) {                     /* switch 1 */
            case 0:                                 /* switch 1 */
            case 1:                                 /* switch 1 */
                if (((*(u8 *)((u8 *)(arg0) + 0x20)) != 0x18) && (func_L21_003AA068(arg0) == 0) && ((func_L01_004561E0(arg0) != 0) || ((*(u8 *)((u8 *)(arg0) + 0x20)) == 1))) {
                    if (func_00382468() != 0) {
                        func_L01_004450F0(arg0, 4, -1);
                    } else {
                        func_L01_004450F0(arg0, 5, -1);
                    }
                    temp_4_2 = (*(s32 *)((u8 *)(arg0) + 0xB8));
                    if ((temp_4_2 != 0) && (func_L21_00339248(temp_4_2) == 0)) {
                        (*(s16 *)((u8 *)(temp_19) + 0x306)) = 0x64;
                    }
                }
            default:                                /* switch 1 */
block_104:
                temp_2 = (*(u8 *)((u8 *)(arg0) + 0x20));
                switch (temp_2) {                   /* switch 3 */
                case 3:                             /* switch 3 */
                    if (func_L01_004561B8(arg0) != 0) {
                        func_003C3A10(arg0, 0, 0, 8);
                    }
block_111:
                    if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
block_223:
                        var_5 = 1;
block_224:
                        func_L01_004450F0(arg0, var_5, -1);
                    }
                    break;
                case 4:                             /* switch 3 */
                    if (func_L01_004561B8(arg0) != 0) {
                        func_L21_00339258((*(s32 *)((u8 *)(arg0) + 0xB8)), func_00382498(0xA, 0x10), 1);
                        func_003C3A10(arg0, 1, 0, 8);
                    }
                    if (func_0038CB00(temp_19 + 0x306) == 0) {
                        goto block_111;
                    }
                    goto block_223;
                case 5:                             /* switch 3 */
                    func_L01_004561B8(arg0);
                    func_L21_00339258((*(s32 *)((u8 *)(arg0) + 0xB8)), func_00382498(0xA, 0x10), 1);
                    func_003C3A10(arg0, 2, 0, 8);
                    goto block_111;
                case 9:                             /* switch 3 */
                    var_5_2 = 3;
                    if (func_L01_004561B8(arg0) != 0) {
block_167:
block_168:
                        func_003C3A10(arg0, var_5_2, 0, 8);
                    }
                    break;
                case 10:                            /* switch 3 */
                    var_5_2 = 3;
                    if (func_L01_004561B8(arg0) != 0) {
                        goto block_167;
                    }
                    break;
                case 11:                            /* switch 3 */
                    var_5_2 = 3;
                    if (func_L01_004561B8(arg0) != 0) {
                        goto block_167;
                    }
                    break;
                case 12:                            /* switch 3 */
                    if (func_L01_004561B8(arg0) != 0) {
                        func_L01_0045BD78(arg0, 0.00360000017f, 0.0600000024f, 0.0100530973f, 1.0053097f);
                        var_5_2 = 5;
                        goto block_168;
                    }
                    break;
                case 13:                            /* switch 3 */
                    if (func_L01_004561B8(arg0) != 0) {
                        func_L01_0045BD78(arg0, 0.0108000003f, 0.180000007f, 0.0100530973f, 1.0053097f);
                        var_5_2 = 6;
                        goto block_168;
                    }
                    break;
                case 14:                            /* switch 3 */
                    if (func_L01_004561B8(arg0) != 0) {
                        func_003C3A10(arg0, 0x19, 6, 8);
                    }
                    temp_f0 = func_L01_004395E0(arg0);
                    if ((temp_f0 >= 6.0f) && (temp_f0 <= 10.0f)) {
                        func_0038CF68(&sp10, arg0 + 0xD0, 0.13333334f);
                        func_L01_0045AA30(arg0, &sp10);
                    } else {
block_129:
                        if (func_L01_0044E1B8(arg0, 0x41300000) != 0) {
                            goto block_223;
                        }
                    }
                    break;
                case 15:                            /* switch 3 */
                    if (func_L01_004561B8(arg0) != 0) {
                        func_003C3A10(arg0, 0x1A, 6, 8);
                    }
                    temp_f0_2 = func_L01_004395E0(arg0);
                    if ((temp_f0_2 >= 6.0f) && (temp_f0_2 <= 10.0f)) {
                        var_f12 = 0x3E088889;
                        var_5_3 = arg0 + 0xD0;
block_141:
                        func_0038CF68(&sp10, var_5_3, var_f12);
                        0 /* unknown instruction: vsub.xyz $vf1, $vf0, $vf1 */;
                        func_L01_0045AA30(arg0, &sp10);
                    } else {
                        goto block_129;
                    }
                    break;
                case 16:                            /* switch 3 */
                    if (func_L01_004561B8(arg0) != 0) {
                        func_003C3A10(arg0, 0x14, 0, 8);
                        (*(s32 *)((u8 *)(temp_19) + 0x240)) = 0;
                        (*(s32 *)((u8 *)(temp_19) + 0x230)) = (s32) D_L21_001D66B0;
                    }
                    temp_f0_3 = func_L01_004395E0(arg0);
                    if ((temp_f0_3 > 9.0f) && (temp_f0_3 < 19.0f)) {
                        var_f12 = 0x3E23D70A;
                        var_5_3 = arg0 + 0xC0;
                        goto block_141;
                    }
                    break;
                case 17:                            /* switch 3 */
                    if (func_L01_004561B8(arg0) != 0) {
                        func_003C3A10(arg0, 0xA, 0, 8);
                    }
                    temp_3_3 = *(void **)0x1A71A0;
                    func_L01_00448890(arg0 + 0xF8, temp_19 + 0x244, 0, func_0038D160((*(f32 *)((u8 *)(temp_3_3) + 0x10)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_3_3) + 0x14)) - (*(f32 *)((u8 *)(arg0) + 0x14))), (*(f32 *)((u8 *)(temp_19) + 0x1A4)) * 5.0f, (*(f32 *)((u8 *)(temp_19) + 0x1A8)) * 5.0f, 2.0f * (*(f32 *)((u8 *)(temp_19) + 0x1AC)));
                    if (((*(u8 *)((u8 *)(arg0) + 0x43)) == 0xA) && (func_L01_0044E1B8(arg0, 0x41400000) != 0)) {
                        func_003C2F58(arg0, 3, &sp10);
                        if ((*(s16 *)((u8 *)(temp_19) + 0xC4)) == 1) {
                            0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                            sp20 = (*(f32 *)((u8 *)(temp_19) + 0xB0));
                            func_0038CF68(&sp20, &sp20, 0.400000036f);
                        } else {
                            sp20 = func_0038D098((*(f32 *)((u8 *)(arg0) + 0xF8))) * 0.40000004f;
                            temp_f0_4 = func_0038D0B0((*(f32 *)((u8 *)(arg0) + 0xF8))) * 0.40000004f;
                            sp28 = 0.0f;
                            sp24 = temp_f0_4;
                        }
                        func_L21_003B1118(arg0, (*(s32 *)((u8 *)(temp_19) + 0xC0)), &sp10, &sp20, 0, (f32) (*(u8 *)((u8 *)(temp_19) + 0x45)));
                    }
block_166:
                    var_5_2 = 0;
                    if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                        goto block_167;
                    }
                    break;
                case 18:                            /* switch 3 */
                    if (func_L01_004561B8(arg0) != 0) {
                        func_003C3A10(arg0, 0xB, 0, 8);
                    }
                    temp_3_4 = *(s32 *)0x1A71A0;
                    func_L01_00448890(arg0 + 0xF8, temp_19 + 0x244, 0, func_0038D160((*(f32 *)((u8 *)(temp_3_4) + 0x10)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_3_4) + 0x14)) - (*(f32 *)((u8 *)(arg0) + 0x14))), (*(f32 *)((u8 *)(temp_19) + 0x1A4)) * 5.0f, (*(f32 *)((u8 *)(temp_19) + 0x1A8)) * 5.0f, 2.0f * (*(f32 *)((u8 *)(temp_19) + 0x1AC)));
                    if (((*(u8 *)((u8 *)(arg0) + 0x43)) == 0xB) && (func_L01_0044E1B8(arg0, 0x41500000) != 0)) {
                        func_003C2F58(arg0, 3, &sp10);
                        sp18 -= 0.5f;
                        if ((*(s16 *)((u8 *)(temp_19) + 0xC4)) == 1) {
                            sp20 = func_0038D098(func_0038D160((*(f32 *)((u8 *)(temp_19) + 0xB0)) - sp10, (*(f32 *)((u8 *)(temp_19) + 0xB4)) - sp14)) * 0.40000004f;
                            var_f12_2 = func_0038D160((*(f32 *)((u8 *)(temp_19) + 0xB0)) - sp10, (*(f32 *)((u8 *)(temp_19) + 0xB4)) - sp14);
                        } else {
                            var_f12_2 = (*(f32 *)((u8 *)(arg0) + 0xF8));
                            sp20 = func_0038D098((*(f32 *)((u8 *)(arg0) + 0xF8))) * 0.40000004f;
                        }
                        temp_f0_5 = func_0038D0B0(var_f12_2) * 0.40000004f;
                        sp28 = 0.0f;
                        sp24 = temp_f0_5;
                        func_L21_003B1518(arg0, (*(s32 *)((u8 *)(temp_19) + 0xC0)), &sp10, &sp20, 0, (f32) (*(u8 *)((u8 *)(temp_19) + 0x45)));
                    }
                    goto block_166;
                case 19:                            /* switch 3 */
                    if (func_L01_004561B8(arg0) != 0) {
                        func_003C3A10(arg0, 0x1B, 0, 8);
                    }
                    temp_3_5 = *(s32 *)0x1A71A0;
                    func_L01_00448890(arg0 + 0xF8, temp_19 + 0x244, 0, func_0038D160((*(f32 *)((u8 *)(temp_3_5) + 0x10)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_3_5) + 0x14)) - (*(f32 *)((u8 *)(arg0) + 0x14))), (*(f32 *)((u8 *)(temp_19) + 0x1A4)) * 5.0f, (*(f32 *)((u8 *)(temp_19) + 0x1A8)) * 5.0f, 2.0f * (*(f32 *)((u8 *)(temp_19) + 0x1AC)));
                    if (((*(u8 *)((u8 *)(arg0) + 0x43)) == 0x1B) && (func_L01_0044E1B8(arg0, 0x41700000) != 0)) {
                        func_003C2F58(arg0, 3, &sp10);
                        sp18 -= 0.2f;
                        if ((*(s16 *)((u8 *)(temp_19) + 0xC4)) != 1) {
                            var_f0 = func_0038D160(D_L21_001DCF40 - sp10, D_L21_001DCF44 - sp14);
                        } else {
                            var_f0 = (*(f32 *)((u8 *)(arg0) + 0xF8));
                        }
                        func_L21_003B1A00(arg0, &sp10, var_f0, (f32) (*(u8 *)((u8 *)(temp_19) + 0x46)));
                    }
                    goto block_166;
                case 20:                            /* switch 3 */
                    if (func_L01_004561B8(arg0) != 0) {
                        (*(s32 *)((u8 *)(temp_19) + 0x1C8)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0x1C8)) & ~0x10);
                        func_L01_0045BD78(arg0, 0.0108000003f, 0.180000007f, 0.0100530973f, 1.0053097f);
                        temp_f0_6 = func_L01_00443A18(10.0f, 35.0f);
                        (*(s16 *)((u8 *)(temp_19) + 0x30C)) = 0;
                        (*(s16 *)((u8 *)(temp_19) + 0x306)) = 0x96;
                        (*(f32 *)((u8 *)(temp_19) + 0x318)) = (f32) (temp_f0_6 * 0.017453292f);
                        func_003C3A10(arg0, 7, 0, 4);
                    }
                    temp_2_2 = (*(u8 *)((u8 *)(arg0) + 0x43));
                    if (temp_2_2 == 7) {
                        var_5_4 = 8;
                        if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                            goto block_182;
                        }
                    }
                    if ((temp_2_2 & 0xFF) == 8) {
                        if (func_L01_004468C8(arg0, 4, 1, 0, 1, 0, 0x3E99999A, (f32) (*(u8 *)((u8 *)(temp_19) + 0x44)), 0x3F800000) > 0) {
                            if (D_L21_001EC4C0 == (*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C0))) {
                                (*(s16 *)((u8 *)(temp_19) + 0x30C)) = 1;
                            }
                        }
                        func_L01_0045A7A8(arg0, temp_19 + 0xB0, (*(f32 *)((u8 *)(temp_19) + 0x318)));
                        func_L01_00404A10(&func_L21_003A9E88, arg0);
                        if ((func_0038CB00(temp_19 + 0x306) != 0) || ((*(s16 *)((u8 *)(temp_19) + 0x30C)) != 0)) {
                            var_5_4 = 9;
                            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
block_182:
                                func_003C3A10(arg0, var_5_4, 0, 2);
                            }
                        }
                    }
                    break;
                case 21:                            /* switch 3 */
                    if (func_L01_004561B8(arg0) != 0) {
                        (*(s16 *)((u8 *)(temp_19) + 0x30C)) = 0;
                        func_003C3A10(arg0, 0xF, 0, 8);
                    }
                    temp_f0_7 = func_L01_004395E0(arg0);
                    if ((temp_f0_7 > 12.0f) && (temp_f0_7 < 18.0f) && (func_L01_004468C8(arg0, 3, 1, 0, 1, 0, 0x3E99999A, (f32) (*(u8 *)((u8 *)(temp_19) + 0x44)), 0x3F800000) > 0)) {
                        if (D_L21_001EC4C0 == (*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C0))) {
                            (*(s16 *)((u8 *)(temp_19) + 0x30C)) = 1;
                        }
                    }
                    break;
                case 22:                            /* switch 3 */
                    if (func_L01_004561B8(arg0) != 0) {
                        (*(s16 *)((u8 *)(temp_19) + 0x30C)) = 0;
                        func_003C3A10(arg0, 0x10, 0, 8);
                    }
                    temp_f0_8 = func_L01_004395E0(arg0);
                    if ((temp_f0_8 > 13.0f) && (temp_f0_8 < 16.0f) && (func_L01_004468C8(arg0, 1, 1, 0, 1, 0, 0x3E99999A, (f32) (*(u8 *)((u8 *)(temp_19) + 0x44)), 0x3F800000) > 0)) {
                        if (D_L21_001EC4C0 == (*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C0))) {
                            (*(s16 *)((u8 *)(temp_19) + 0x30C)) = 1;
                        }
                    }
                    break;
                case 23:                            /* switch 3 */
                    if (func_L01_004561B8(arg0) != 0) {
                        func_003C3A10(arg0, 4, 0, 8);
                    }
                    var_20 = 4;
                    do {
                        sp20 = 0.0f;
                        var_20 -= 1;
                        sp28 = func_003824E0(3.0f, 4.0f) * 0.020000001f;
                        temp_f20 = func_00382538();
                        temp_f21 = func_003824E0(0.25f, 0.5f);
                        sp10 = func_0038D098(temp_f20) * temp_f21;
                        temp_f0_9 = func_0038D0B0(temp_f20) * temp_f21;
                        sp18 = 0.0f;
                        sp14 = temp_f0_9;
                        0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                        temp_16 = (s32) ((func_00382498(0x1E, 0x3C) * 5) + 2) / 6;
                        temp_f20_2 = func_003824E0(0.100000001f, 0.300000012f);
                        temp_17 = (func_00382468() != 0) ? 0xFF4E2BFF : 0xFF4B2FFF;
                        func_L01_0046C470(&sp10, &sp20, temp_17, temp_16, func_00382468() & 0xFF, 0, 0x40, 0, temp_f20_2);
                    } while (var_20 >= 0);
                    break;
                case 24:                            /* switch 3 */
                    if (func_L01_004561B8(arg0) != 0) {
                        (*(s8 *)((u8 *)(arg0) + 0x23)) = 0x80;
                        temp_f2 = (*(f32 *)((u8 *)(temp_19) + 0x30));
                        if (!(temp_f2 <= 0.0f)) {
                            if (temp_f2 < ((f32) (*(s16 *)((u8 *)(temp_19) + 0x34)) * 0.1f)) {
                                func_L21_00339258((*(s32 *)((u8 *)(arg0) + 0xB8)), 1, 0);
                            } else if (func_00382468() == 0) {
                                func_L21_00339258((*(s32 *)((u8 *)(arg0) + 0xB8)), func_00382498(5, 9), 1);
                            }
                        } else {
                            func_L21_003392E0((*(s32 *)((u8 *)(arg0) + 0xB8)));
                            func_L21_00339258((*(s32 *)((u8 *)(arg0) + 0xB8)), 0, 1);
                        }
                    }
                    temp_17_2 = func_L01_00454370(arg0, temp_19 + 0xD0);
                    if ((*(f32 *)((u8 *)(temp_19) + 0x30)) <= 0.0f) {
                        func_L01_00448890(arg0 + 0xF8, temp_19 + 0x244, 0, func_0038DB00(func_0038D160(D_L21_001DCF40 - (*(f32 *)((u8 *)(arg0) + 0x10)), D_L21_001DCF44 - (*(f32 *)((u8 *)(arg0) + 0x14))), 0.52359879f), (*(f32 *)((u8 *)(temp_19) + 0x1A4)) * 3.0f, (*(f32 *)((u8 *)(temp_19) + 0x1A8)) * 3.0f, (*(f32 *)((u8 *)(temp_19) + 0x1AC)) * 3.0f);
                    }
                    if (temp_17_2 & 1) {
                        func_L01_004443E8(arg0, 0, 3);
                        if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                            (*(s32 *)((u8 *)(arg0) + 0x48)) = 0;
                        }
                        var_5 = 0x19;
                        goto block_224;
                    }
                    if (temp_17_2 & 2) {
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                            func_003C3A10(arg0, 0, 0, 2);
                        }
                        goto block_223;
                    }
                    break;
                case 25:                            /* switch 3 */
                    if (func_L21_003393C0((*(s32 *)((u8 *)(arg0) + 0xB8))) != 0) {
                        (*(s32 *)((u8 *)(arg0) + 0x98)) = 0;
                    }
                    if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                        (*(s32 *)((u8 *)(arg0) + 0x48)) = 0;
                    }
                    break;
                }
                temp_3_6 = (*(u8 *)((u8 *)(arg0) + 0x20));
                if ((u32) (temp_3_6 - 0x18) >= 2U) {
                    if (((f32) (*(s32 *)((u8 *)(&D_142660) + 8)) * 0.1f) <= (f32) (D_L21_001E1030 - (*(s32 *)((u8 *)(&D_1A4BE0) + 0x2850)))) {
                        if ((*(u8 *)((u8 *)(arg0) + 0x94)) == 0x17) {
                            goto block_237;
                        }
                        if (temp_3_6 != 0x17) {
                            func_L21_00339258((*(s32 *)((u8 *)(arg0) + 0xB8)), func_00382498(0x11, 0x12), 1);
                            D_L21_001E1030 = (s32) (*(s32 *)((u8 *)(&D_1A4BE0) + 0x2850));
                        } else {
                            goto block_237;
                        }
                    } else {
block_237:
                        if (((f32) (*(s32 *)((u8 *)(&D_1A4BE0) + 0x2850)) < ((f32) (*(s32 *)((u8 *)(&D_142660) + 8)) * 0.1f)) && ((*(u8 *)((u8 *)(arg0) + 0x94)) != 0x17) && (temp_3_6 != 0x17)) {
                            func_L21_00339258((*(s32 *)((u8 *)(arg0) + 0xB8)), 4, 0);
                        }
                    }
                }
                if ((*(s8 *)((u8 *)(temp_19) + 0x300)) == 3) {
                    func_L21_00339190(arg0, sp, (*(u8 *)((u8 *)(arg0) + 0x20)) == 0x18);
                }
                break;
            case 2:                                 /* switch 1 */
                if (((*(u8 *)((u8 *)(arg0) + 0x20)) != 0x18) && (func_L21_003AA068(arg0) == 0)) {
                    if (func_L01_004561E0(arg0) == 0) {
                        if ((*(u8 *)((u8 *)(arg0) + 0x20)) == 1) {
                            goto block_25;
                        }
                    } else {
block_25:
                        (*(s16 *)((u8 *)(temp_19) + 0x306)) = 0x64;
                        func_L01_004450F0(arg0, 0x13, -1);
                    }
                    if (((*(u8 *)((u8 *)(arg0) + 0x20)) == 0x13) && (func_0038CB00(temp_19 + 0x306) != 0)) {
block_101:
                        func_L01_004450F0(arg0, 1, 0);
                    }
                }
                goto block_104;
            case 3:                                 /* switch 1 */
                if (((*(u8 *)((u8 *)(arg0) + 0x20)) != 0x18) && (func_L21_003AA068(arg0) == 0)) {
                    if (func_L01_004561E0(arg0) == 0) {
                        if ((*(u8 *)((u8 *)(arg0) + 0x20)) == 1) {
                            goto block_34;
                        }
                    } else {
block_34:
                        (*(s16 *)((u8 *)(temp_19) + 0x306)) = 0x32;
                        func_L01_004450F0(arg0, 0x12, -1);
                    }
                    if (((*(u8 *)((u8 *)(arg0) + 0x20)) == 0x12) && (func_0038CB00(temp_19 + 0x306) != 0)) {
                        goto block_101;
                    }
                }
                goto block_104;
            case 4:                                 /* switch 1 */
                if (((*(u8 *)((u8 *)(arg0) + 0x20)) != 0x18) && (func_L21_003AA068(arg0) == 0)) {
                    if (func_L01_004561E0(arg0) == 0) {
                        if ((*(u8 *)((u8 *)(arg0) + 0x20)) == 1) {
                            goto block_43;
                        }
                    } else {
block_43:
                        (*(s16 *)((u8 *)(temp_19) + 0x306)) = 0x25;
                        func_L01_004450F0(arg0, 0x11, -1);
                    }
                    if (((*(u8 *)((u8 *)(arg0) + 0x20)) == 0x11) && (func_0038CB00(temp_19 + 0x306) != 0)) {
                        goto block_101;
                    }
                }
                goto block_104;
            case 5:                                 /* switch 1 */
                if (func_L21_003AA068(arg0) == 0) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x20)) == 0x18) {
                        temp_3_7 = (*(u8 *)((u8 *)(arg0) + 0x94));
                        if (((u32) (temp_3_7 - 0x15) < 2U) || (temp_3_8 = temp_3_7 & 0xFF, (temp_3_8 == 0x10)) || (temp_3_8 == 0xB)) {
                            func_L01_00445170(arg0, 0);
                        }
                    } else {
                        if (func_L01_004561E0(arg0) != 0) {
                            (*(s16 *)((u8 *)(temp_19) + 0x30C)) = 0;
                            (*(s16 *)((u8 *)(temp_19) + 0x306)) = 0x1F4;
                            var_5_5 = 0x14;
                            goto block_78;
                        }
                        temp_2_3 = (*(u8 *)((u8 *)(arg0) + 0x20));
                        temp_4_3 = temp_2_3 & 0xFF;
                        switch (temp_4_3) {         /* switch 2; irregular */
                        case 1:                     /* switch 2 */
                            var_5_5 = 0x14;
block_78:
                            func_L01_004450F0(arg0, var_5_5, -1);
                            break;
                        case 13:                    /* switch 2 */
                            if (func_0038CB00(temp_19 + 0x306) != 0) {
                                func_L01_004450F0(arg0, 0x10, -1);
                            }
                            temp_16_2 = temp_19 + 0xB0;
                            func_L01_0045A748(arg0, temp_16_2);
                            if (func_0038CF38() <= 5.0f) {
                                var_5_5 = 0x14;
                                goto block_78;
                            }
                            break;
                        case 20:                    /* switch 2 */
                            if ((*(u8 *)((u8 *)(arg0) + 0x43)) == 9) {
                                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                                    var_5_5 = 0x10;
                                    goto block_78;
                                }
                                goto block_67;
                            }
                        default:                    /* switch 2 */
block_67:
                            if ((temp_2_3 == 0x10) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                                if ((*(s16 *)((u8 *)(temp_19) + 0x30C)) != 0) {
                                    var_5_5 = 0xB;
                                    goto block_78;
                                }
                                goto block_101;
                            }
                            if ((temp_2_3 == 0xB) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                                goto block_101;
                            }
                            if (((u32) ((*(u8 *)((u8 *)(arg0) + 0x94)) - 0xE) < 2U) && (temp_2_3 == 1)) {
                                var_5_5 = 0xD;
                                goto block_78;
                            }
                            break;
                        }
                    }
                }
                goto block_104;
            case 7:                                 /* switch 1 */
                if (((*(u8 *)((u8 *)(arg0) + 0x20)) != 0x18) && (func_L21_003AA068(arg0) == 0)) {
                    if ((func_L01_004561E0(arg0) != 0) || ((*(u8 *)((u8 *)(arg0) + 0x20)) == 1)) {
                        (*(s16 *)((u8 *)(temp_19) + 0x306)) = 0x32;
                        (*(f32 *)((u8 *)(temp_19) + 0x308)) = 0.02f;
                        (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x808);
                        (*(s8 *)((u8 *)(temp_19) + 0xE2)) = 0xFF;
                        (*(s8 *)((u8 *)(temp_19) + 0xE1)) = 0xFF;
                        func_L01_004450F0(arg0, 0x17, -1);
                    }
                    if (func_0038CB00(temp_19 + 0x306) != 0) {
                        (*(s8 *)((u8 *)(arg0) + 0x23)) = 0;
                        (*(f32 *)((u8 *)(arg0) + 0x2C)) = (f32) (*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x24))) + 0x24));
                        (*(s8 *)((u8 *)(temp_19) + 0xE2)) = 0x17;
                        (*(s8 *)((u8 *)(temp_19) + 0xE1)) = 0x15;
                        (*(s32 *)((u8 *)(arg0) + 0x98)) = 0;
                        (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x41) & 0xEFFF);
                        func_L01_004AA7E8(arg0, 1);
                        (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x34)) | 2);
                        temp_3_9 = (*(s8 *)((u8 *)(temp_19) + 0x301));
                        if (temp_3_9 == 0) {
                            (*(s8 *)((u8 *)(temp_19) + 0x300)) = 0;
                        } else if (temp_3_9 == 1) {
                            (*(s8 *)((u8 *)(temp_19) + 0x300)) = temp_3_9;
                        }
                        (*(s8 *)((u8 *)(arg0) + 0xA8)) = 0xFF;
                        (*(s16 *)((u8 *)(temp_19) + 0x108)) = 0;
                        func_L01_004450F0(arg0, 1, 9);
                    } else {
                        var_4 = 0;
                        var_5_6 = 0x80;
block_103:
                        (*(s8 *)((u8 *)(arg0) + 0x23)) = func_L01_00448070(var_4, var_5_6, (f32) (*(s16 *)((u8 *)(temp_19) + 0x306)) * (*(f32 *)((u8 *)(temp_19) + 0x308)));
                        goto block_104;
                    }
                } else {
                    goto block_104;
                }
                break;
            case 8:                                 /* switch 1 */
                if (((*(u8 *)((u8 *)(arg0) + 0x20)) != 0x18) && (func_L21_003AA068(arg0) == 0)) {
                    if ((func_L01_004561E0(arg0) != 0) || ((*(u8 *)((u8 *)(arg0) + 0x20)) == 1)) {
                        (*(s16 *)((u8 *)(temp_19) + 0x306)) = 0x64;
                        (*(f32 *)((u8 *)(temp_19) + 0x308)) = 0.01f;
                        (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x808);
                        (*(s8 *)((u8 *)(temp_19) + 0xE2)) = 0xFF;
                        (*(s8 *)((u8 *)(temp_19) + 0xE1)) = 0xFF;
                        D_L21_001E1030 = (s32) *(s32 *)0x1A7430;
                        func_L01_004450F0(arg0, 0x17, -1, 0x1A0000);
                    }
                    temp_5 = (*(void **)((u8 *)(arg0) + 0x24));
                    temp_3_10 = (*(u16 *)((u8 *)(arg0) + 0x34)) & 0xFFBE;
                    (*(u16 *)((u8 *)(arg0) + 0x34)) = temp_3_10;
                    (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (temp_3_10 | ((*(u16 *)((u8 *)(temp_5) + 0x44)) & 0x1000));
                    (*(s32 *)((u8 *)(arg0) + 0x98)) = (s32) (*(s32 *)((u8 *)(temp_5) + 0x10));
                    if (func_0038CB00(temp_19 + 0x306) != 0) {
                        (*(s8 *)((u8 *)(arg0) + 0x23)) = 0x80;
                        (*(s8 *)((u8 *)(temp_19) + 0xE1)) = 0x15;
                        temp_3_11 = (*(s8 *)((u8 *)(temp_19) + 0x301));
                        (*(s8 *)((u8 *)(temp_19) + 0xE2)) = 0x17;
                        if ((temp_3_11 == 2) || (temp_3_11 == 3)) {
                            (*(s8 *)((u8 *)(temp_19) + 0x300)) = temp_3_11;
                        }
                        (*(s8 *)((u8 *)(arg0) + 0xA8)) = 0xFF;
                        (*(s16 *)((u8 *)(temp_19) + 0x108)) = 0;
                        goto block_101;
                    }
                    var_4 = 0x80;
                    var_5_6 = 0;
                    goto block_103;
                }
                goto block_104;
            }
        }
    }
}
