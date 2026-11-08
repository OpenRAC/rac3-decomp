/* func_L01_003386E0: Opus handoff (prep by Sonnet worker w7, 2026-11-08)
   Size: 9592 bytes, places: 34 levels (01 02 03 04 05 06 07 08 09 10 11 12 13 14 16 17 18 19 20 21 22 23 24 26 27 28 29 30 31 32 33 34 35 36), file: src/levels/shared/L01_003386E0.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses
   Step 0: one function (addiu sp,-0x100), 3 switches (m2c) with no jump table (compare chains), 34 places (01-36 less a few); named `wrench_update` in names.tsv (wrench swing sweep points, hits, thrown wrench flight and return); file flags -mno-split-addresses.
   Twin: rac3 near-sibling func_L39_0055B4D8 (0.41; both mostly different code). rac2 best func_L00_003AE900 0.21 (no rac2 weapon-update twin by opcode). Corpus search: rac2:func_L00_003AE900 / func_L00_003DB118 0.21.
   Mapping: This is the hero wrench update: it reads hero state D_1A4BE0 +0x25C4 (hero state), +0x25C0 (hero moby), +0xB40..+0xB70 (sweep points), 54 calls to func_003824E0 and 28 to func_00382498 (float helpers, unidentified); func_L01_004C7D98 (x12), func_L01_00446BF0, func_L01_004669B0 (probably the hit tests). Because it is in 34 levels, every place must match: use chkall.sh.
   Identical / changed / added / removed: see func_L39_0055B4D8 for the 6 identical blocks (this function's ranges 00339478.., 003396B0.., 003397C0.., 0033A550.., 0033A6E0.., 0033A900..).
   VU0: 13 vadd.xyz/vsub.xyz ops in the retail asm; inline-asm VU0 is banned since 2026-11-06 (Matching-Patterns), so this function cannot reach MATCH unless the ops come from plain C; the lq/sq copies are fine (u128_t).
   Draft: compiles (m2c draft cleaned by tools/post.py (real repo prototypes where known, m2c gotos kept)); 2314 diff; opcode-equal 578 of 2399 (mine 1981), ratio 0.26.
     Retail rows yours=1981 retail=2399 equalrows=85.
   Left for Opus:
     1. Highest payoff of the slate by places (34): worth the Opus time even as a near miss.
     2. Draft passes pointer args where retail passes f32/vec; func_L01_004669B0 is called with s32* in m2c but takes vectors: K&R-declared in the draft: replace with real prototypes.
     3. 13 VU0 ops (2 lqc2 + 1 sqc2 + 7 vadd + 3 vsub): near miss only unless plain C yields them.
*/
extern f32 func_003824E0(f32, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_00382468();
extern s32 func_00382498(s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_003A52A0();
extern s32 func_003C4B50();
extern s32 func_003D3CB0();
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern s32 func_003D5630(void);
extern s32 func_L01_004EE7F8(f32);
extern u8 *func_003C24B0(s32, s32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CFB8(void);
extern void func_003A4F28(u32);
extern void func_003C2880(s32 p);
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern void func_003C3938(void *a0, s32 a1, s32 a2);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_00404A10(void *a0, s32 a1);
extern void func_L01_0044E740(void *);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_004C7D98(void *a, void *b);
void *func_00382348(void *);                        /* extern */
s32 func_003C4098(s32 *, f32 *, s32 *, s32); /* extern */
s32 func_L01_00337E10(void *);                  /* extern */
s32 func_L01_00337EA8(s32 *, s32);              /* extern */
s32 func_L01_00337EF8();                            /* extern */
s32 func_L01_00337F38(s32 *, s32);      /* extern */
s32 func_L01_00338230(void *);                  /* extern */
s32 func_L01_003384B0(void *);                  /* extern */
s32 func_L01_00338628(f32 *);                   /* extern */
s32 func_L01_003F6F20(s32, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_L01_00446760(f32 *, void *, s32, f32 *, f32); /* extern */
s32 func_L01_00446A70(void *, void *, s32, void *, f32 *, s32); /* extern */
s32 func_L01_00446BF0(void *, void *, void *, void *, void *, f32 *, s32); /* extern */
s32 func_L01_0044AEB8(void *);                      /* extern */
s32 func_L01_0044E298(void *, s32, s32, s32); /* extern */
s32 func_L01_0044FD88(void *, void *, s32, s32); /* extern */
s32 func_L01_00450E48(void *, f32 *, f32, s32, s32); /* extern */
void *func_L01_004669B0();  /* K&R: prototype dropped, mismatch with m2c calls */
void *func_L01_004713C8(f32 *, f32 *, s32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_L01_004F4E70(s32, s32);        /* extern */
s32 func_L01_0050FEE8(s32);                 /* extern */
s32 func_L01_00511158(f32 *, f32 *, s32);   /* extern */
extern s32 D_1425C0;
extern s32 D_1A30B0;
extern s32 D_1A4BE0;
extern s32 D_1A4D30;
extern s32 D_L01_001D6694;
extern s32 D_L01_001DFB40;
extern s32 D_L01_001EAA00;
extern void *D_L01_001EEA80;
extern s32 D_L01_00221098;
extern s32 D_L01_002C5600;
extern s32 D_L01_002F62D0;
extern s32 func_L01_00337880;



void func_L01_003386E0(void *arg0) {
    s32 sp[8]; /* m2c: stack-slot base, size unknown */
    s32 unksp19; /* m2c stack slot */
    s32 unksp1A; /* m2c stack slot */
    s32 unksp29; /* m2c stack slot */
    s32 unksp2A; /* m2c stack slot */
    f32 sp0;
    f32 sp4;
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp18;                                       /* compiler-managed */
    f32 sp1C;
    f32 sp20;
    f32 sp24;
    f32 sp28;                                       /* compiler-managed */
    f32 sp30;
    f32 sp34;
    s32 sp38;
    f32 sp40;
    f32 sp50;
    s32 sp60;
    s32 sp70;
    f32 *sp80;
    f32 *sp84;
    f32 *sp88;
    s32 *var_2_5;
    s32 var_5;
    s32 var_f12;
    s32 var_f13;
    s32 var_f21;
    f32 *temp_23;
    f32 *temp_23_2;
    f32 *temp_23_3;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f20_6;
    f32 temp_f20_7;
    f32 temp_f23;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f20;
    f32 var_f20_2;
    f32 var_f20_3;
    f32 var_f23;
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_16_3;
    s32 temp_16_4;
    s32 temp_16_5;
    s32 temp_16_6;
    s32 temp_16_7;
    s32 temp_16_8;
    s32 temp_2_15;
    s32 temp_3_3;
    s32 temp_3_4;
    s32 temp_4_7;
    s32 temp_5;
    s32 var_17;
    s32 var_17_2;
    s32 var_17_3;
    s32 var_19;
    s32 var_20;
    s32 var_20_2;
    s32 var_21;
    s32 var_21_2;
    s32 var_23;
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_2_4;
    s32 var_2_6;
    s32 var_3;
    s32 var_3_3;
    s32 var_3_5;
    s32 var_3_7;
    s32 var_4;
    s32 var_6;
    s8 var_3_2;
    s8 var_3_4;
    s8 var_3_6;
    s8 var_3_8;
    u8 temp_3;
    u8 temp_3_2;
    u8 temp_4_4;
    u8 temp_4_6;
    u8 *temp_16_9;
    u8 *temp_22;
    u8 *temp_2;
    u8 *temp_2_10;
    u8 *temp_2_11;
    u8 *temp_2_12;
    u8 *temp_2_13;
    u8 *temp_2_14;
    u8 *temp_2_16;
    u8 *temp_2_17;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_2_6;
    u8 *temp_2_7;
    u8 *temp_2_8;
    u8 *temp_2_9;
    u8 *temp_4;
    u8 *temp_4_2;
    u8 *temp_4_3;
    u8 *temp_4_5;
    u8 *temp_4_8;
    u8 *temp_4_9;
    u8 *temp_6;

    temp_22 = (*(void **)((u8 *)(arg0) + 0x68));
    (*(s8 *)((u8 *)(&D_1A4BE0) + 0x121C)) = 0;
    if ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x1224)) != 3) {
        if ((*(u8 *)0x1D5479 != 0) && ((*(void **)((u8 *)(&D_1A4BE0) + 0x28D0)) == 0) && ((*(u8 *)((u8 *)(&D_1A4BE0) + 0x25ED)) == 0)) {
            if ((D_L01_001D6694 != 2) && ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x1228)) != 0x7F)) {
                temp_2 = func_003C24B0(0x1B82, 0x630);
                (*(void **)((u8 *)(&D_1A4BE0) + 0x28D0)) = temp_2;
                if (temp_2 != 0) {
                    func_L01_00456160(temp_2, arg0);
                }
            }
        }
        if ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x234)) == 0) {
            if ((*(void **)((u8 *)(&D_1A4BE0) + 0x28CC)) != 0) {
                func_003C2880((*(void **)((u8 *)(&D_1A4BE0) + 0x28CC)));
                (*(void **)((u8 *)(&D_1A4BE0) + 0x28CC)) = 0;
            }
        } else if (((*(void **)((u8 *)(&D_1A4BE0) + 0x28CC)) == 0) && (D_L01_001DFB40 != 0)) {
            temp_2_2 = func_003C24B0(0x47, 0x80);
            (*(void **)((u8 *)(&D_1A4BE0) + 0x28CC)) = temp_2_2;
            if (temp_2_2 != 0) {
                func_L01_00456160(temp_2_2, arg0);
                (*(u16 *)((u8 *)((*(void **)((u8 *)(&D_1A4BE0) + 0x28CC))) + 0x34)) = (u16) ((*(u16 *)((u8 *)((*(void **)((u8 *)(&D_1A4BE0) + 0x28CC))) + 0x34)) | 0x8000);
                func_003C3938((*(void **)((u8 *)(&D_1A4BE0) + 0x28CC)), 1, 0);
                (*(u16 *)((u8 *)((*(void **)((u8 *)(&D_1A4BE0) + 0x28CC))) + 0x34)) = (u16) ((*(u16 *)((u8 *)((*(void **)((u8 *)(&D_1A4BE0) + 0x28CC))) + 0x34)) | 2);
                func_L01_0044FD88((*(void **)((u8 *)(&D_1A4BE0) + 0x25C0)), (*(void **)((u8 *)(&D_1A4BE0) + 0x28CC)), 0xE, 0);
            }
        } else {
            func_L01_0044FD88((*(void **)((u8 *)(&D_1A4BE0) + 0x25C0)), (*(void **)((u8 *)(&D_1A4BE0) + 0x28CC)), 0xE, 0);
        }
        temp_3 = (*(u8 *)((u8 *)(arg0) + 0x20));
        if (temp_3 != 0) {
            if (((s32) temp_3 >= 0) && ((s32) temp_3 < 0xC)) {
                if ((s32) temp_3 >= 0xA) {
                    temp_23 = arg0 + 0x10;
                    sp84 = &sp50;
                    sp80 = &sp40;
                    sp88 = temp_22 + 0x40;
                    if ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x234)) != 0) {
                        var_17 = 7;
                        do {
                            func_003C2F58(arg0, func_00382498(2, 9), sp);
                            sp0 += func_003824E0(-0.0199999996f, 0.0199999996f);
                            sp4 += func_003824E0(-0.0199999996f, 0.0199999996f);
                            sp8 += func_003824E0(-0.0199999996f, 0.0199999996f);
                            func_L01_004C7D98(temp_23, &sp10);
                            func_0038CE20(&sp10, &sp10, func_003824E0(0.400000006f, 1.0f) * 0.020000001f);
                            if (func_00382468() != 0) {
                                var_2 = func_00382498(0x40, 0x64);
                                var_3 = 0x5F404000;
                            } else {
                                var_2 = func_00382498(0x96, 0x64) << 0x10;
                                var_3 = 0x5F002C2C;
                            }
                            temp_2_3 = func_L01_004713C8(sp, &sp10, (s32) ((func_00382498(0xA, 0xF) * 5) + 2) / 6, var_2 | var_3, 1, 0x4F, 0, 0, 0x4765B000, 0x46D547FF, 0);
                            var_17 -= 1;
                            if (temp_2_3 != 0) {
                                (*(u8 *)((u8 *)(temp_2_3) + 2)) = (u8) *(*(u8 **)((u8 *)(&D_L01_00221098) + 0x16C));
                            }
                        } while (var_17 >= 0);
                        func_L01_004C7D98(temp_23, &sp10);
                        func_0038CE20(&sp10, &sp10, func_003824E0(0.400000006f, 1.0f) * 0.020000001f);
                        sp0 += func_003824E0(-0.0199999996f, 0.0199999996f);
                        sp4 += func_003824E0(-0.0199999996f, 0.0199999996f);
                        sp8 += func_003824E0(-0.0199999996f, 0.0199999996f);
                        temp_16 = func_00382468() + 1;
                        temp_f20 = func_003824E0(0.25f, 0.400000006f) * 210000.0f;
                        temp_2_4 = func_L01_004669B0(sp, temp_16, &sp10, func_00382498(0x40, 0x50) | 0x404000, 0, 0, 0x3F7D70A4, 0x3F7EB852, temp_f20);
                        if (temp_2_4 != 0) {
                            var_3_2 = 0x48;
                            if (func_00382468() != 0) {
                                var_3_2 = 0x44;
                            }
                            (*(s8 *)((u8 *)(temp_2_4) + 3)) = var_3_2;
                            (*(s16 *)((u8 *)(temp_2_4) + 0xA)) = 2;
                        }
                        if ((*(void **)((u8 *)(&D_1A4BE0) + 0x28CC)) != 0) {
                            var_21 = 7;
                            do {
                                func_003C2F58((*(void **)((u8 *)(&D_1A4BE0) + 0x28CC)), func_00382498(2, 9), &sp20);
                                sp20 += func_003824E0(-0.0199999996f, 0.0199999996f);
                                sp24 += func_003824E0(-0.0199999996f, 0.0199999996f);
                                sp28 += func_003824E0(-0.0199999996f, 0.0199999996f);
                                func_L01_004C7D98(temp_23, &sp30);
                                func_0038CE20(&sp30, &sp30, func_003824E0(0.400000006f, 1.0f) * 0.020000001f);
                                if (func_00382468() != 0) {
                                    var_2_2 = func_00382498(0x40, 0x64);
                                    var_3_3 = 0x5F404000;
                                } else {
                                    var_2_2 = func_00382498(0x96, 0x64) << 0x10;
                                    var_3_3 = 0x5F002C2C;
                                }
                                temp_2_5 = func_L01_004713C8(&sp20, &sp30, (s32) ((func_00382498(0xA, 0xF) * 5) + 2) / 6, var_2_2 | var_3_3, 1, 0x4F, 0, 0, 0x4765B000, 0x46D547FF, 0);
                                if (temp_2_5 != 0) {
                                    (*(u8 *)((u8 *)(temp_2_5) + 2)) = (u8) *(*(u8 **)((u8 *)(&D_L01_00221098) + 0x16C));
                                }
                                var_21 -= 1;
                            } while (var_21 >= 0);
                            func_L01_004C7D98(temp_23, &sp30);
                            func_0038CE20(&sp30, &sp30, func_003824E0(0.400000006f, 1.0f) * 0.020000001f);
                            sp20 += func_003824E0(-0.0199999996f, 0.0199999996f);
                            sp24 += func_003824E0(-0.0199999996f, 0.0199999996f);
                            sp28 += func_003824E0(-0.0199999996f, 0.0199999996f);
                            temp_16_2 = func_00382468() + 1;
                            temp_f20_2 = func_003824E0(0.25f, 0.400000006f) * 210000.0f;
                            temp_2_6 = func_L01_004669B0(&sp20, temp_16_2, &sp30, func_00382498(0x40, 0x50) | 0x404000, 0, 0, 0x3F7D70A4, 0x3F7EB852, temp_f20_2);
                            if (temp_2_6 != 0) {
                                var_3_4 = 0x48;
                                if (func_00382468() != 0) {
                                    var_3_4 = 0x44;
                                }
                                (*(s8 *)((u8 *)(temp_2_6) + 3)) = var_3_4;
                                (*(s16 *)((u8 *)(temp_2_6) + 0xA)) = 2;
                            }
                        }
                    }
                    (*(void **)((u8 *)(arg0) + 0xB8)) = (void *) (*(void **)((u8 *)(&D_1A4BE0) + 0x25C0));
                    (*(s8 *)((u8 *)(&D_1A4BE0) + 0x121C)) = 2;
                    if ((*(u8 *)((u8 *)(arg0) + 0x20)) == 0xA) {
                        if ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x2790)) != -1) {
                            temp_4 = ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x2790)) << 7) + &D_1A30B0;
                            if ((*(s32 *)((u8 *)(temp_4) + 0xDC)) == (*(void **)((u8 *)(&D_1A4BE0) + 0x25C0))) {
                                if ((*(u8 *)((u8 *)(temp_4) + 0xD0)) == 0) {
                                    goto block_228;
                                }
                            } else {
                                goto block_229;
                            }
                        } else {
block_228:
block_229:
                            (*(s32 *)((u8 *)(&D_1A4BE0) + 0x2790)) = func_003A52A0();
                        }
                    }
                    func_L01_0044E298(arg0, 0, 0, 0x3EFA35DD);
                    if ((*(s16 *)((u8 *)(&D_1A4BE0) + 0xBDE)) != 0) {
                        if (func_0038CAD0(temp_22 + 0x6C) != 0) {
                            (*(s16 *)((u8 *)(&D_1A4BE0) + 0xBDE)) = 0;
                        }
                    }
                    if ((*(u8 *)((u8 *)(&D_1A4BE0) + 0x25F4)) == 0) {
                        temp_f0 = func_003C3D30(temp_23, 0, 0, 0.5f);
                        temp_f2 = (*(f32 *)((u8 *)(arg0) + 0x18));
                        if ((temp_f2 - temp_f0) < 0.8f) {
                            temp_f12 = temp_f0 + 0.55f;
                            if (temp_f2 < temp_f12) {
                                func_003C4138(arg0 + 0x18, temp_f12, 0.080000006f);
                            } else {
                                func_003C4138(arg0 + 0x18, temp_f12, 0.020000001f);
                            }
                        }
                    }
                    sp0 = (*(f32 *)((u8 *)(arg0) + 0x10));
                    if ((*(u8 *)((u8 *)(arg0) + 0x20)) == 0xA) {
                        sp10 = (*(f32 *)((u8 *)(&D_1A4D30) + 0));
                        func_0038CE20(&sp10, &sp10, 0.98f);
                        0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                        (*(f32 *)((u8 *)(arg0) + 0x10)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x10));
                        func_0038CF68(&sp10, sp88, (*(f32 *)((u8 *)(temp_22) + 0x60)));
                        0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                        (*(f32 *)((u8 *)(arg0) + 0x10)) = 0.00136f;
                        temp_f0_2 = (*(f32 *)((u8 *)(temp_22) + 0x64)) + 0.00136f;
                        (*(f32 *)((u8 *)(temp_22) + 0x64)) = temp_f0_2;
                        func_003C4138(temp_22 + 0x60, 0.0f, temp_f0_2);
                        if ((*(f32 *)((u8 *)(temp_22) + 0x60)) == 0.0f) {
                            (*(u8 *)((u8 *)(arg0) + 0x20)) = 0xBU;
                        }
                    } else {
                        var_20 = 0;
                        sp10 = (*(f32 *)((u8 *)(&D_1A4D30) + 0));
                        func_0038CE20(&sp10, &sp10, 0.98f);
                        0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                        (*(f32 *)((u8 *)(arg0) + 0x10)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x10));
                        func_L01_003384B0(arg0);
                        0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                        sp10 = (*(f32 *)((u8 *)(&D_1A4D30) + 0x1090));
                        temp_f0_3 = (*(f32 *)((u8 *)(temp_22) + 0x64)) + 0.00036f;
                        (*(f32 *)((u8 *)(temp_22) + 0x64)) = temp_f0_3;
                        (*(f32 *)((u8 *)(temp_22) + 0x60)) = (f32) ((*(f32 *)((u8 *)(temp_22) + 0x60)) + temp_f0_3);
                        temp_f0_4 = func_0038CEA8(&sp10);
                        if (((temp_f0_4 / (*(f32 *)((u8 *)(temp_22) + 0x60))) < 4.0f) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 1)) {
                            func_003C3A10(arg0, 1, 0, 4);
                        }
                        if (temp_f0_4 <= (*(f32 *)((u8 *)(temp_22) + 0x60))) {
                            (*(f32 *)((u8 *)(temp_22) + 0x60)) = temp_f0_4;
                            var_20 = 1;
                        }
                        func_0038CF68(&sp10, &sp10, (*(f32 *)((u8 *)(temp_22) + 0x60)));
                        0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                        (*(f32 *)((u8 *)(arg0) + 0x10)) = 3.0f;
                        if ((temp_f0_4 / (*(f32 *)((u8 *)(temp_22) + 0x60))) < 3.0f) {
                            if ((*(s32 *)((u8 *)(&D_1A4BE0) + 0xC20)) != -1) {
                                func_L01_0050FEE8(2);
                                (*(s32 *)((u8 *)(&D_1A4BE0) + 0xC24)) = 0x1A;
                                if ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x2790)) != -1) {
                                    temp_4_2 = ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x2790)) << 7) + &D_1A30B0;
                                    if (((*(s32 *)((u8 *)(temp_4_2) + 0xDC)) == (*(void **)((u8 *)(&D_1A4BE0) + 0x25C0))) && ((*(u8 *)((u8 *)(temp_4_2) + 0xD0)) != 0)) {
                                        func_003A4F28((*(s32 *)((u8 *)(&D_1A4BE0) + 0x2790)));
                                    }
                                }
                                (*(s32 *)((u8 *)(&D_1A4BE0) + 0x2790)) = -1;
                            }
                        }
                        var_4 = 0;
                        if (((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) == 0x31) || ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) == 0x65) || (temp_f0_4 > 32.0f)) {
                            var_4 = 1;
                        }
                        if ((var_20 != 0) || (var_4 != 0)) {
                            if (var_4 == 0) {
                                func_L01_004F4E70(5, 0);
                            }
                            if ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x2790)) != -1) {
                                temp_4_3 = ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x2790)) << 7) + &D_1A30B0;
                                if (((*(s32 *)((u8 *)(temp_4_3) + 0xDC)) == (*(void **)((u8 *)(&D_1A4BE0) + 0x25C0))) && ((*(u8 *)((u8 *)(temp_4_3) + 0xD0)) != 0)) {
                                    func_003A4F28((*(s32 *)((u8 *)(&D_1A4BE0) + 0x2790)));
                                }
                            }
                            (*(s32 *)((u8 *)(&D_1A4BE0) + 0x2790)) = -1;
                            func_L01_0044E740(&D_1A4BE0 + 0x1CE0);
                            (*(s8 *)((u8 *)(&D_1A4BE0) + 0x121A)) = 0;
                            (*(u8 *)((u8 *)(arg0) + 0x20)) = 0U;
                        }
                    }
                    var_17_2 = 0;
                    if ((func_003D3CB0() != 0) && (func_003D5630() != 0) && (((*(void **)((u8 *)(&D_L01_001EAA00) + 0x18)) == 0) || (func_003C4B50() == 0))) {
                        var_17_2 = (*(s32 *)((u8 *)(&D_L01_001EAA00) + 0x1C)) != 0;
                    }
                    if ((var_17_2 != 0) || ((*(s16 *)((u8 *)(temp_22) + 0x76)) != 0)) {
                        (*(s16 *)((u8 *)(temp_22) + 0x76)) = 0;
                        if ((*(s16 *)((u8 *)(&D_1A4BE0) + 0xBDE)) == 0) {
                            (*(s32 *)((u8 *)(temp_22) + 0x6C)) = 0x19;
                            (*(s16 *)((u8 *)(&D_1A4BE0) + 0xBDE)) = 1;
                            func_003A52A0();
                        }
                        if ((*(u8 *)((u8 *)(arg0) + 0x20)) == 0xA) {
                            func_L01_00338230(arg0);
                            (*(f32 *)((u8 *)(temp_22) + 0x60)) = (f32) ((*(f32 *)((u8 *)(temp_22) + 0x60)) * 0.5f);
                            (*(u8 *)((u8 *)(arg0) + 0x20)) = 0xBU;
                        }
                    }
                    var_f20 = 1.2f;
                    if ((*(u8 *)((u8 *)(arg0) + 0x20)) == 0xB) {
                        var_f20 = -0.37f;
                    }
                    func_0038CF68(sp80, sp88, var_f20);
                    temp_f0_5 = (*(f32 *)((u8 *)((((*(u8 *)((u8 *)(&D_1425C0) + 9)) * 0xF0) + &D_L01_002C5600)) + 0x6C));
                    if ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x234)) != 0) {
                        func_L01_00446760(&sp10, arg0, 0x110000, sp80, temp_f0_5 * 50.0f);
                    } else {
                        func_L01_00446760(&sp10, arg0, 0x10000, sp80, temp_f0_5);
                    }
                    sp18 = 1.0f;
                    if ((*(u8 *)((u8 *)(&D_1A4BE0) + 0x25F4)) != 0) {
                        sp10 = 0.0f;
                        func_L01_00450E48((*(void **)((u8 *)(&D_1A4BE0) + 0x25C0)), &sp10, var_f20, 0, 0x3F800000);
                    }
                    unksp29 = 1;
                    sp1C = 5627.925f;
                    unksp2A = (*(u16 *)((u8 *)(&D_1A4BE0) + 0xBEC)) + 1;
                    sp28 = 0;
                    func_003C2F58(arg0, 1, sp84);
                    if ((func_003D4D00(sp84, 0, (*(void **)((u8 *)(&D_1A4BE0) + 0x25C0)), &sp10, 0.400000006f) != 0) || (func_003C2F58(arg0, 0, sp84), (func_003D4D00(sp84, 0, (*(void **)((u8 *)(&D_1A4BE0) + 0x25C0)), &sp10, 0.400000006f) != 0))) {
                        if (((*(s16 *)((u8 *)(&D_1A4BE0) + 0xBDE)) == 0) && ((*(void **)((u8 *)(&D_L01_001EAA00) + 0x18)) != 0)) {
                            temp_2_7 = (*(void **)((u8 *)((*(void **)((u8 *)(&D_L01_001EAA00) + 0x18))) + 0x24));
                            if ((temp_2_7 == 0) || ((*(u8 *)((u8 *)(temp_2_7) + 0x46)) != 0x14)) {
                                temp_2_8 = func_00382348((*(void **)((u8 *)(&D_L01_001EAA00) + 0x18)));
                                if ((temp_2_8 == 0) || ((*(s16 *)((u8 *)(temp_2_8) + 0x1C)) == 0) || ((*(s32 *)((u8 *)(temp_2_8) + 0x18)) != arg0)) {
                                    sp70 = (*(s32 *)((u8 *)((*(void **)((u8 *)(&D_L01_001EAA00) + 0x18))) + 0x10));
                                    func_003C4098(&sp60, sp84, &sp70, 0x3F000000);
                                    func_L01_00337F38(&sp60, 5);
                                    (*(s32 *)((u8 *)(temp_22) + 0x6C)) = 0x19;
                                    (*(s16 *)((u8 *)(&D_1A4BE0) + 0xBDE)) = 1;
                                    func_003A52A0();
                                }
                            }
                        }
                    }
                }
            }
        } else {
            (*(void **)((u8 *)(arg0) + 0xB8)) = (void *) (*(void **)((u8 *)(&D_1A4BE0) + 0x25C0));
            if (((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) == 1) || ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) == 0x1D)) {
                if ((*(u16 *)((u8 *)((*(void **)((u8 *)(&D_1A4BE0) + 0x25C0))) + 0x34)) & 1) {
                    func_L01_003F6F20(0, arg0, 0xFF917267, 0, 0x25, -1, 4, 0x3F800000, 0, 0x42B40000, 0x3F000000, 0x3F000000, 0x42200000, 0x42200000);
                }
            }
            if ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x234)) != 0) {
                if (((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) == 0x13) || ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) == 0x20) || ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) == 0x2A) || ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) == 0x72) || ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) == 0x14)) {
                    temp_23_2 = arg0 + 0x10;
                    var_20_2 = 5;
                    do {
                        var_20_2 -= 1;
                        func_003C2F58(arg0, func_00382498(2, 9), sp);
                        sp0 += func_003824E0(-0.0199999996f, 0.0199999996f);
                        sp4 += func_003824E0(-0.0199999996f, 0.0199999996f);
                        sp8 += func_003824E0(-0.0199999996f, 0.0199999996f);
                        func_L01_004C7D98(temp_23_2, &sp10);
                        func_0038CE20(&sp10, &sp10, func_003824E0(0.5f, 1.0f) * 0.020000001f);
                        temp_16_3 = func_00382498(0x40, 0x64) | 0x5F404000;
                        func_L01_004713C8(sp, &sp10, (s32) ((func_00382498(2, 5) * 5) + 2) / 6, temp_16_3, 1, 0x5F, 0, 0, 0x47A41000, 0x47241000, 0);
                    } while (var_20_2 >= 0);
                    func_L01_004C7D98(temp_23_2, &sp10);
                    func_0038CE20(&sp10, &sp10, func_003824E0(0.400000006f, 1.0f) * 0.020000001f);
                    sp0 += func_003824E0(-0.0199999996f, 0.0199999996f);
                    sp4 += func_003824E0(-0.0199999996f, 0.0199999996f);
                    sp8 += func_003824E0(-0.0199999996f, 0.0199999996f);
                    temp_16_4 = func_00382468() + 1;
                    temp_f20_3 = func_003824E0(0.25f, 0.400000006f) * 210000.0f;
                    temp_2_9 = func_L01_004669B0(sp, temp_16_4, &sp10, func_00382498(0x40, 0x50) | 0x404000, 0, 0, 0x3F7D70A4, 0x3F7EB852, temp_f20_3);
                    if (temp_2_9 != 0) {
                        (*(s16 *)((u8 *)(temp_2_9) + 0xA)) = 2;
                        (*(s8 *)((u8 *)(temp_2_9) + 3)) = 0x48;
                    }
                    if ((*(void **)((u8 *)(&D_1A4BE0) + 0x28CC)) != 0) {
                        var_21_2 = 5;
loop_41:
                        var_21_2 -= 1;
                        func_003C2F58((*(void **)((u8 *)(&D_1A4BE0) + 0x28CC)), func_00382498(2, 9), &sp20);
                        sp20 += func_003824E0(-0.0199999996f, 0.0199999996f);
                        sp24 += func_003824E0(-0.0199999996f, 0.0199999996f);
                        sp28 += func_003824E0(-0.0199999996f, 0.0199999996f);
                        func_L01_004C7D98(temp_23_2, &sp30);
                        func_0038CE20(&sp30, &sp30, func_003824E0(0.5f, 1.0f) * 0.020000001f);
                        temp_16_5 = func_00382498(0x40, 0x64) | 0x5F404000;
                        func_L01_004713C8(&sp20, &sp30, (s32) ((func_00382498(2, 5) * 5) + 2) / 6, temp_16_5, 1, 0x5F, 0, 0, 0x47A41000, 0x47241000, 0);
                        if (var_21_2 >= 0) {
                            goto loop_41;
                        }
                        func_L01_004C7D98(temp_23_2, &sp30);
                        func_0038CE20(&sp30, &sp30, func_003824E0(0.400000006f, 1.0f) * 0.020000001f);
                        sp20 += func_003824E0(-0.0199999996f, 0.0199999996f);
                        sp24 += func_003824E0(-0.0199999996f, 0.0199999996f);
                        sp28 += func_003824E0(-0.0199999996f, 0.0199999996f);
                        temp_16_6 = func_00382468() + 1;
                        temp_f20_4 = func_003824E0(0.25f, 0.400000006f) * 210000.0f;
                        temp_2_10 = func_L01_004669B0(&sp20, temp_16_6, &sp30, func_00382498(0x40, 0x50) | 0x404000, 0, 0, 0x3F7D70A4, 0x3F7EB852, temp_f20_4);
                        if (temp_2_10 != 0) {
                            (*(s8 *)((u8 *)(temp_2_10) + 3)) = 0x48;
                        }
                    }
                } else {
                    temp_23_3 = arg0 + 0x10;
                    var_17_3 = 7;
                    do {
                        func_003C2F58(arg0, func_00382498(2, 9), sp);
                        sp0 += func_003824E0(-0.0199999996f, 0.0199999996f);
                        sp4 += func_003824E0(-0.0199999996f, 0.0199999996f);
                        sp8 += func_003824E0(-0.0199999996f, 0.0199999996f);
                        func_L01_004C7D98(temp_23_3, &sp10);
                        func_0038CE20(&sp10, &sp10, func_003824E0(0.400000006f, 1.0f) * 0.020000001f);
                        if (func_00382468() != 0) {
                            var_2_3 = func_00382498(0x40, 0x64);
                            var_3_5 = 0x5F404000;
                        } else {
                            var_2_3 = func_00382498(0x96, 0x64) << 0x10;
                            var_3_5 = 0x5F002C2C;
                        }
                        temp_2_11 = func_L01_004713C8(sp, &sp10, (s32) ((func_00382498(0xA, 0xF) * 5) + 2) / 6, var_2_3 | var_3_5, 1, 0x4F, 0, 0, 0x4765B000, 0x46D547FF, 0);
                        var_17_3 -= 1;
                        if (temp_2_11 != 0) {
                            (*(u8 *)((u8 *)(temp_2_11) + 2)) = (u8) *(*(u8 **)((u8 *)(&D_L01_00221098) + 0x16C));
                        }
                    } while (var_17_3 >= 0);
                    func_L01_004C7D98(temp_23_3, &sp10);
                    func_0038CE20(&sp10, &sp10, func_003824E0(0.400000006f, 1.0f) * 0.020000001f);
                    sp0 += func_003824E0(-0.0199999996f, 0.0199999996f);
                    sp4 += func_003824E0(-0.0199999996f, 0.0199999996f);
                    sp8 += func_003824E0(-0.0199999996f, 0.0199999996f);
                    temp_16_7 = func_00382468() + 1;
                    temp_f20_5 = func_003824E0(0.25f, 0.400000006f) * 210000.0f;
                    temp_2_12 = func_L01_004669B0(sp, temp_16_7, &sp10, func_00382498(0x40, 0x50) | 0x404000, 0, 0, 0x3F7D70A4, 0x3F7EB852, temp_f20_5);
                    if (temp_2_12 != 0) {
                        var_3_6 = 0x48;
                        if (func_00382468() != 0) {
                            var_3_6 = 0x44;
                        }
                        (*(s8 *)((u8 *)(temp_2_12) + 3)) = var_3_6;
                        (*(s16 *)((u8 *)(temp_2_12) + 0xA)) = 2;
                    }
                    if ((*(void **)((u8 *)(&D_1A4BE0) + 0x28CC)) != 0) {
                        var_19 = 7;
                        do {
                            func_003C2F58((*(void **)((u8 *)(&D_1A4BE0) + 0x28CC)), func_00382498(2, 9), &sp20);
                            sp20 += func_003824E0(-0.0199999996f, 0.0199999996f);
                            sp24 += func_003824E0(-0.0199999996f, 0.0199999996f);
                            sp28 = (f32)(sp28) + func_003824E0(-0.0199999996f, 0.0199999996f);
                            func_L01_004C7D98(temp_23_3, &sp30);
                            func_0038CE20(&sp30, &sp30, func_003824E0(0.400000006f, 1.0f) * 0.020000001f);
                            if (func_00382468() != 0) {
                                var_2_4 = func_00382498(0x40, 0x64);
                                var_3_7 = 0x5F404000;
                            } else {
                                var_2_4 = func_00382498(0x96, 0x64) << 0x10;
                                var_3_7 = 0x5F002C2C;
                            }
                            temp_2_13 = func_L01_004713C8(&sp20, &sp30, (s32) ((func_00382498(0xA, 0xF) * 5) + 2) / 6, var_2_4 | var_3_7, 1, 0x4F, 0, 0, 0x4765B000, 0x46D547FF, 0);
                            if (temp_2_13 != 0) {
                                (*(u8 *)((u8 *)(temp_2_13) + 2)) = (u8) *(*(u8 **)((u8 *)(&D_L01_00221098) + 0x16C));
                            }
                            var_19 -= 1;
                        } while (var_19 >= 0);
                        func_L01_004C7D98(temp_23_3, &sp30);
                        func_0038CE20(&sp30, &sp30, func_003824E0(0.400000006f, 1.0f) * 0.020000001f);
                        sp20 += func_003824E0(-0.0199999996f, 0.0199999996f);
                        sp24 += func_003824E0(-0.0199999996f, 0.0199999996f);
                        sp28 += func_003824E0(-0.0199999996f, 0.0199999996f);
                        temp_16_8 = func_00382468() + 1;
                        temp_f20_6 = func_003824E0(0.25f, 0.400000006f) * 210000.0f;
                        temp_2_14 = func_L01_004669B0(&sp20, temp_16_8, &sp30, func_00382498(0x40, 0x50) | 0x404000, 0, 0, 0x3F7D70A4, 0x3F7EB852, temp_f20_6);
                        if (temp_2_14 != 0) {
                            var_3_8 = 0x48;
                            if (func_00382468() != 0) {
                                var_3_8 = 0x44;
                            }
                            (*(s8 *)((u8 *)(temp_2_14) + 3)) = var_3_8;
                            (*(s16 *)((u8 *)(temp_2_14) + 0xA)) = 2;
                        }
                    }
                }
            }
            if ((temp_22 != 0) && ((*(f32 *)((u8 *)(temp_22) + 0x70)) != 0.0f)) {
                func_L01_00404A10(&func_L01_00337880, arg0);
            }
            temp_4_4 = (*(u8 *)((u8 *)(arg0) + 0x43));
            (*(s32 *)((u8 *)(arg0) + 0x78)) = 0x80909090;
            temp_5 = temp_4_4 & 0xFF;
            (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x10);
            switch (temp_5) {                       /* switch 1; irregular */
            case 14:                                /* switch 1 */
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    var_5 = 1;
block_86:
                    func_003C3A10(arg0, var_5, 0, 4);
                }
                break;
            default:                                /* switch 1 */
                temp_2_15 = temp_4_4 - 0xF;
                if ((*(u8 *)((u8 *)(&D_1A4BE0) + 0x25EF)) != 0) {
                    if ((u32) (temp_2_15 & 0xFF) < 2U) {
                        if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                            if (temp_5 == 0xF) {
                                var_5 = 0x10;
                                goto block_86;
                            }
                        }
                    } else {
                        func_003C3A10(arg0, 0xF, 0, 3);
                    }
                } else if ((u32) (temp_2_15 & 0xFF) < 2U) {
                    func_003C3A10(arg0, 0xE, 0, 2);
                } else {
                case 0:                             /* switch 1 */
                    if ((((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) || ((*(u8 *)((u8 *)(arg0) + 0x43)) == 6)) && ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) != 0x37) && ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25CC)) != 0x22) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 1)) {
                        func_003C3A10(arg0, 1, 0, 4);
                    }
                    func_L01_00337E10(arg0);
                    switch ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4))) { /* switch 2; irregular */
                    default:                        /* switch 2 */
                        temp_3_2 = (*(u8 *)((u8 *)(arg0) + 0x43));
                        var_2_5 = &D_1A4BE0;
                        if (temp_3_2 >= 3U) {
                            if (temp_3_2 < 6U) {
                                func_003C3A10(arg0, 1, 0, 3);
                            }
                        case 0x13:                  /* switch 2 */
                        case 0x20:                  /* switch 2 */
                        case 0x2A:                  /* switch 2 */
                        case 0x72:                  /* switch 2 */
                        case 0x14:                  /* switch 2 */
                            var_2_5 = &D_1A4BE0;
                        }
                        break;
                    }
                    temp_4_5 = (*(void **)((u8 *)(var_2_5) + 0x25C0));
                    if (((*(u8 *)((u8 *)(temp_4_5) + 0x43)) != (*(u8 *)((u8 *)(temp_4_5) + 0x42))) || (((*(u8 *)((u8 *)(temp_4_5) + 0x41)) - (*(u8 *)((u8 *)(temp_4_5) + 0x40))) >= 3)) {
                        (*(u16 *)((u8 *)(temp_22) + 0x74)) = (u16) ((*(u16 *)((u8 *)(temp_22) + 0x74)) + 1);
                    }
                    (*(f32 *)((u8 *)(arg0) + 0x48)) = (f32) (*(f32 *)((u8 *)(&D_1A4BE0) + 0xC00));
                    temp_6 = ((*(s16 *)((u8 *)(&D_1A4BE0) + 0xBDC)) * 0x2C) + &D_L01_002F62D0;
                    if (((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25CC)) == 6) || ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) == 0x2A)) {
                        var_23 = 1;
                        if (((*(s32 *)((u8 *)(&D_1A4BE0) + 0xC0C)) != 0) || ((*(f32 *)((u8 *)(&D_1A4BE0) + 0xC18)) < (f32) (*(s32 *)((u8 *)(temp_6) + 0x1C))) || ((f32) (*(s32 *)((u8 *)(temp_6) + 0x20)) < (*(f32 *)((u8 *)(&D_1A4BE0) + 0xC18)))) {
                            var_23 = 0;
                        }
                        var_6 = 0;
                        if ((*(s16 *)((u8 *)(temp_22) + 0x7C)) != (s16) (*(u16 *)((u8 *)(temp_22) + 0x74))) {
                            temp_4_6 = (*(u8 *)((u8 *)((*(void **)((u8 *)(&D_1A4BE0) + 0x25C0))) + 0x42));
                            if (temp_4_6 == (*(u8 *)((u8 *)((*(void **)((u8 *)(&D_1A4BE0) + 0x25C0))) + 0x43))) {
                                switch (temp_4_6) { /* switch 3; irregular */
                                case 23:            /* switch 3 */
                                    var_f0 = 0.0f;
                                    var_2_6 = 1;
block_124:
                                    if (!(var_f0 <= (*(f32 *)((u8 *)(&D_1A4BE0) + 0xC18)))) {
                                        var_2_6 = 0;
                                    }
                                    var_6 = var_2_6;
                                    break;
                                case 24:            /* switch 3 */
                                    var_f0 = 0.0f;
                                    var_2_6 = 1;
                                    goto block_124;
                                case 25:            /* switch 3 */
                                    var_f0 = 12.0f;
                                    var_2_6 = 1;
                                    goto block_124;
                                default:            /* switch 3 */
                                    var_2_6 = 1;
                                    if (temp_4_6 == 0x28) {
                                        var_f0 = 23.0f;
                                        goto block_124;
                                    }
                                    break;
                                }
                            }
                        }
                        if (var_6 != 0) {
                            (*(f32 *)((u8 *)(temp_22) + 0x70)) = 1.0f;
                            (*(s16 *)((u8 *)(temp_22) + 0x7C)) = (s16) (*(u16 *)((u8 *)(temp_22) + 0x74));
                        }
                        var_f20_2 = 0.0f;
                        (*(f32 *)((u8 *)(&D_1A4BE0) + 0xB70)) = (f32) (*(f32 *)((u8 *)(&D_1A4BE0) + 0xB50));
                        (*(s32 *)((u8 *)(&D_1A4BE0) + 0xB60)) = (s32) (*(s32 *)((u8 *)(&D_1A4BE0) + 0xB40));
                        var_f23 = (*(f32 *)((u8 *)(&D_1A4BE0) + 0x98));
                        func_003C2F58(arg0, 1, &D_1A4BE0 + 0xB50);
                        func_003C2F58((*(void **)((u8 *)(&D_1A4BE0) + 0x25C0)), 0, &D_1A4BE0 + 0xB40);
                        var_f1 = 0 /* second half of f64 */;
                        if (((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) == 0x13) || ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) == 0x72) || ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) == 0x2A)) {
                            temp_4_7 = (*(s16 *)((u8 *)(&D_1A4BE0) + 0xBDC)) * 0x2C;
                            var_f13 = 0x3FC90FDB;
                            temp_f23 = func_0038D160((*(f32 *)((u8 *)(&D_1A4BE0) + 0xB50)) - (*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)), (*(f32 *)((u8 *)(&D_1A4BE0) + 0xB54)) - (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)));
                            if ((*(s32 *)((u8 *)((&D_L01_002F62D0 + temp_4_7)) + 4)) == 1) {
                                var_f13 = 0xBFC90FDB;
                            }
                            var_f1 = 0 /* second half of f64 */;
                            var_f23 = func_0038DAB8(temp_4_7, 1);
                        }
                        0 /* unknown instruction: lqc2 $vf1, 0x5730($v0) */;
                        0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                        sp0 = var_f1;
                        func_0038CF68(sp, sp, func_0038CEA8(sp) + 0.17f);
                        if (((*(s32 *)((u8 *)(-0xB50) + 0x1A25CC)) != 0xF) && (temp_3_3 = (*(s32 *)((u8 *)(-0xB50) + 0x1A25C4)), (temp_3_3 != 0x72))) {
                            if (temp_3_3 != 0x14) {
                                var_f20_2 = func_0038DBA0((*(f32 *)((u8 *)(-0xB50) + 0x1A0098)), func_0038D160((*(f32 *)((u8 *)(-0xB50) + 0x1A0B50)) - (*(f32 *)((u8 *)(-0xB50) + 0x1A0080)), (*(f32 *)((u8 *)(-0xB50) + 0x1A0B54)) - (*(f32 *)((u8 *)(-0xB50) + 0x1A0084))));
                                if (var_f20_2 > 1.5707964f) {
                                    var_23 = 0;
                                }
                                func_L01_00338628(sp);
                            }
                        }
                        temp_16_9 = (f32 *)0x1A0000 - 0xB50;
                        0 /* unknown instruction: vadd.xyz $vf2, $vf2, $vf1 */;
                        0 /* unknown instruction: sqc2 $vf2, 0x5730($s5) */;
                        temp_3_4 = (*(s32 *)((u8 *)(temp_16_9) + 0x25C4));
                        if (temp_3_4 != 0x2A) {
                            if ((temp_3_4 != 0x72) && (var_f20_2 < 1.2217305f) && ((*(s32 *)((u8 *)(temp_16_9) + 0x1B8)) >= 9)) {
                                sp0 = (*(f32 *)((u8 *)(temp_16_9) + 0x80));
                                sp8 += 0.5f;
                                temp_f20_7 = func_0038D160((*(f32 *)((u8 *)(temp_16_9) + 0xB50)) - (*(f32 *)((u8 *)(temp_16_9) + 0x80)), (*(f32 *)((u8 *)(temp_16_9) + 0xB54)) - (*(f32 *)((u8 *)(temp_16_9) + 0x84)));
                                temp_f12_2 = temp_f20_7;
                                sp10 = (*(f32 *)((u8 *)(temp_16_9) + 0x80));
                                sp18 += 0.5f;
                                sp20 = func_0038D098(temp_f12_2) * 1.4f;
                                temp_f0_6 = func_0038D0B0(temp_f20_7) * 1.4f;
                                sp28 = 0.0f;
                                sp24 = temp_f0_6;
                                func_L01_00338628(&sp20);
                                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                                if (((*(s16 *)((u8 *)(temp_16_9) + 0xBDE)) == 0) && (func_003D3CB0() != 0)) {
                                    if (func_003D5630() != 0) {
                                        if (((*(void **)((u8 *)(&D_L01_001EAA00) + 0x18)) == 0) || (func_L01_0044AEB8((*(void **)((u8 *)(&D_L01_001EAA00) + 0x18))) != 0)) {
                                            (*(s16 *)((u8 *)(temp_16_9) + 0xBDE)) = 1;
                                            if ((*(s32 *)((u8 *)(temp_16_9) + 0x1228)) != 0x7F) {
                                                func_003A52A0();
                                            }
                                            func_L01_00338230(arg0);
                                            if ((*(void **)((u8 *)(&D_L01_001EAA00) + 0x18)) != 0) {
                                                if ((*(u8 *)((u8 *)(temp_16_9) + 0x25F4)) != 0) {
                                                    sp30 = (*(f32 *)((u8 *)((f32 *)0x1A0000) + -0xB50));
                                                } else {
                                                    sp30 = func_0038D098(var_f23);
                                                    sp34 = func_0038D0B0(var_f23);
                                                    sp38 = 0;
                                                }
                                                func_L01_00446A70((*(void **)((u8 *)(&D_L01_001EAA00) + 0x18)), arg0, 0x10000, &D_L01_001EAA00 + 0x20, &sp30, 0x3F800000);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if (((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) == 0x14) && (func_L01_004EE7F8(27.0f) != 0)) {
                            if ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x1228)) != 0x7F) {
                                func_003A52A0();
                            }
                            sp10 = (*(f32 *)((u8 *)(&D_1A4BE0) + 0xB50));
                            sp0 = (*(f32 *)((u8 *)(&D_1A4BE0) + 0xB50));
                            func_L01_00511158(sp, sp, 0x3F333333);
                            func_L01_00511158(&sp10, &sp10, 0xBF666666);
                            if (func_003D3CB0() != 0) {
                                func_L01_00338230(arg0);
                            }
                        }
                        if (var_23 != 0) {
                            var_f21 = 0x3F800000;
                            temp_4_8 = (*(u8 *)0x1425C9 * 0xF0) + &D_L01_002C5600;
                            var_f20_3 = (*(f32 *)((u8 *)(temp_4_8) + 0x6C));
                            if ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) == 0x14) {
                                var_f20_3 = (*(f32 *)((u8 *)(temp_4_8) + 0x70));
                                var_f21 = 0x3FC66666;
                            }
                            if ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x234)) != 0) {
                                var_f20_3 *= 50.0f;
                            }
                            sp30 = func_0038D098(*(f32 *)&temp_4_8);
                            sp34 = func_0038D0B0(var_f23);
                            sp38 = 0;
                            if ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x234)) != 0) {
                                func_L01_00446760(sp, arg0, 0x110000, &sp30, var_f20_3);
                            } else {
                                func_L01_00446760(sp, arg0, 0x10000, &sp30, var_f20_3);
                            }
                            func_0038CFB8();
                            spC = 5627.925f;
                            unksp19 = 1;
                            unksp1A = (*(u16 *)((u8 *)(arg0) + 0xAA));
                            sp8 = 1.0f;
                            sp18 = 0;
                            if ((*(u8 *)((u8 *)(&D_1A4BE0) + 0x25F4)) != 0) {
                                sp30 = 0.0f;
                                func_L01_00450E48((*(void **)((u8 *)(&D_1A4BE0) + 0x25C0)), &sp30, 1.0f, 0, 0x3F800000);
                            }
                            var_f1_2 = 0 /* second half of f64 */;
                            if ((func_L01_00446BF0(&D_1A4BE0 + 0xB40, &D_1A4BE0 + 0xB50, &D_1A4BE0 + 0xB60, &D_1A4BE0 + 0xB70, (*(void **)((u8 *)(&D_1A4BE0) + 0x25C0)), sp, 5) != 0) && ((*(void **)((u8 *)(&D_L01_001EAA00) + 0x18)) != 0) && (var_f1_2 = 0 /* second half of f64 */, (func_L01_00337EF8() == 0)) && ((*(s16 *)((u8 *)(&D_1A4BE0) + 0xBDE)) == 0)) {
                                if (((*(void **)((u8 *)(&D_L01_001EAA00) + 0x18)) == 0) || (temp_2_16 = (*(void **)((u8 *)((*(void **)((u8 *)(&D_L01_001EAA00) + 0x18))) + 0x24)), (temp_2_16 == 0)) || ((*(u8 *)((u8 *)(temp_2_16) + 0x46)) != 0x14)) {
                                    (*(s16 *)((u8 *)(&D_1A4BE0) + 0xBDE)) = 1;
                                    if ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x1228)) != 0x7F) {
                                        func_003A52A0();
                                    }
                                    func_L01_00338230(arg0);
                                    var_f1_2 = 0 /* second half of f64 */;
                                }
                            }
                            0 /* unknown instruction: lqc2 $vf1, 0x5730($s5) */;
                            0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                            sp50 = var_f1_2;
                            func_0038CF68(&sp50, &sp50, func_0038CEA8(&sp50) - 0.085f);
                            temp_4_9 = (f32 *)0x1A0000 - 0xB50;
                            0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                            var_f12 = 0x3EB33333;
                            sp40 = sp50;
                            if ((*(s32 *)((u8 *)(temp_4_9) + 0x25CC)) == 0xF) {
                                var_f12 = 0x3F333333;
                            }
                            if ((*(s32 *)((u8 *)(temp_4_9) + 0x25C4)) == 0x14) {
                                var_f12 = 0x3EF0A3D7;
                            }
                            if (func_003D4D00(&sp40, 0, (*(void **)((u8 *)(temp_4_9) + 0x25C0)), sp, var_f12) != 0) {
                                if (((D_L01_001EEA80 == 0) || (temp_2_17 = (*(void **)((u8 *)(D_L01_001EEA80) + 0x24)), (temp_2_17 == 0)) || ((*(u8 *)((u8 *)(temp_2_17) + 0x46)) != 0x12)) && (func_L01_00337EF8() == 0)) {
                                    if ((*(s16 *)((u8 *)(&D_1A4BE0) + 0xBDE)) == 0) {
                                        (*(s16 *)((u8 *)(&D_1A4BE0) + 0xBDE)) = 1;
                                        func_003A52A0();
                                        func_L01_00338230(arg0);
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
        }
    }
}
