/* func_L39_0055B4D8: Opus handoff (prep by Sonnet worker w7, 2026-11-08)
   Size: 8384 bytes, places: 15 levels (39 40 41 42 43 44 45 46 47 48 49 50 51 52 53), file: src/levels/shared/L39_0055B418.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses
   Step 0: one function (addiu sp,-0x110), 2 switches on local temps (state and +0x42), no jump table; file flags -mno-split-addresses; contains ~8 inlined obfuscated-variable readers (see func_L39_00656F28).
   Twin: rac3 near-sibling func_L01_003386E0 (ratio 0.41, 931 equal opcodes). rac2 best func_L16_0040ECC0 0.17. Corpus: rac3:func_L39_00662C90 0.31, func_L40_0051E8E0 0.30.
   Mapping: Multiplayer-menu code (level 39 and its 14 sister menu levels). The `D_L39_004997E0` table reader is the same inline decoder as in func_L39_00656F28 (see the prior job's `Dec_00656F28`, rac3-api/jobs/func_L39_00656F28/func.c, matches retail's loop body instruction by instruction): n = *p; h = ((u32)p - n) & 7; for k in 0..40 step 5: *b++ = T[n+1 + ((h+k)&7)*255]; w[0] ^= (u32)p; w[1] ^= w[0]; result w[1]. m2c prints it as `*sp = T[..]; sp0 ^ p; sp4 ^ ...`; the draft keeps m2c's unrolled-looking form with a (u32) cast fix (hand edit in d2).
   Identical / changed / added / removed: vs func_L01_003386E0: identical runs 0055B784-0055B814/00339478 (36), 0055BDB8-0055BE44/003396B0 (35), 0055C024-0055C088/003397C0 (25), 0055CBA0-0055CC48/0033A550 (42), 0055CEE0-0055CF68/0033A6E0 (34), 0055D274-0055D2E4/0033A900 (28).
   VU0: 10 vadd.xyz/vsub.xyz ops in the retail asm; inline-asm VU0 is banned since 2026-11-06 (Matching-Patterns), so this function cannot reach MATCH unless the ops come from plain C; the lq/sq copies are fine (u128_t).
   Draft: compiles (m2c draft cleaned by tools/post.py (real repo prototypes where known, m2c gotos kept)); 2056 diff; opcode-equal 1095 of 2097 (mine 1557), ratio 0.60.
     Retail rows yours=1557 retail=2097 equalrows=41.
   Left for Opus:
     1. Replace every m2c decoder expansion with an inline reader (the prior job's helper) so the 8 reads become small blocks.
     2. Frame retail 0x110.
     3. 10 VU0 ops: near miss only.
*/
extern f32 func_0038CEA8(void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_0038CAD0(void *);
extern s32 func_003D3CB0();
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern s32 func_003D5630(void);
extern s32 func_L39_005B8928(u8 *);
extern s32 func_L39_005F33E0(s32, s32, s32);
extern s32 func_L39_00648AE0(u8 *, s32);
extern u8 *func_L39_0061D1D8(s32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CFB8(void);
extern void func_003C2880(s32 p);
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern void func_003C3938(void *a0, s32 a1, s32 a2);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_00404A10(void *a0, s32 a1);
extern void func_L01_0044E740(void *);
extern void func_L39_005F3088(s32);
extern void func_L39_0063A030(u8 *a0, s32 a1, s32 a2);
void *func_00382348(void *);                        /* extern */
s32 func_003C4098(s32 *, s32 *, s32 *, s32); /* extern */
s32 func_L01_00337EA8();                            /* extern */
s32 func_L01_00337EF8();                            /* extern */
s32 func_L01_00348160(void *);                  /* extern */
s32 func_L01_003F6F20(u8, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_L01_00446760(s32 *, void *, s32, s32 *, f32); /* extern */
s32 func_L01_00446A70(void *, void *, s32, void *, f32 *, s32); /* extern */
s32 func_L01_00446BF0(s32 *, s32 *, void *, void *, void *, s32 *, s32); /* extern */
s32 func_L01_0044AEB8(void *);                      /* extern */
s32 func_L01_0044E298(void *, s32, s32, s32); /* extern */
s32 func_L01_0044E468(void *, s32);         /* extern */
s32 func_L01_00450E48(void *, s32 *, f32, s32, s32); /* extern */
s32 func_L01_00511158(void *, s32 *, s32 *, s32); /* extern */
s32 func_L39_0055AD78(void *);                  /* extern */
s32 func_L39_0055AF88(s32 *, s32);          /* extern */
s32 func_L39_0055B178(void *, void *);          /* extern */
s32 func_L39_0055B418(void *, s32 *);           /* extern */
s32 func_L39_0062B728(void *, s32);         /* extern */
s32 func_L39_00632C48(void *, s32);             /* extern */
extern s32 D_1FE020;
extern s32 D_L39_0025F740;
extern void *D_L39_002637C0;
extern s32 D_L39_0047A8A8;
extern s32 D_L39_004997E0;
extern s32 D_L39_0049C890;
extern s32 func_L39_0055A880;

extern s32 D_001D4BC0;

void func_L39_0055B4D8(void *arg0) {
    s32 sp[8]; /* m2c: stack-slot base, size unknown */
    s32 unksp29; /* m2c stack slot */
    s32 unksp2A; /* m2c stack slot */
    s32 sp0;                                        /* compiler-managed */
    s32 sp4;
    f32 sp8;
    f32 spC;
    s32 sp10;                                       /* compiler-managed */
    s32 sp14;
    s8 sp18;                                        /* compiler-managed */
    s8 sp19;
    u16 sp1A;
    f32 sp1C;
    s32 sp20;                                       /* compiler-managed */
    s32 sp24;                                       /* compiler-managed */
    s32 sp28;                                       /* compiler-managed */
    f32 sp30;
    f32 sp34;
    s32 sp38;
    s32 sp40;                                       /* compiler-managed */
    s32 sp44;
    f32 sp50;
    s32 sp60;
    s32 sp64;
    s32 sp70;
    s32 sp80;
    u8 *sp84;
    s32 *sp88;
    s32 *sp8C;
    s32 *sp90;
    s32 var_5;
    s32 var_f12;
    s32 var_f13;
    s32 var_f21;
    f32 temp_3_25;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f12;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f23;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f20;
    f32 var_f20_2;
    f32 var_f20_3;
    f32 var_f23;
    s32 *temp_2_29;
    s32 *temp_3_28;
    s32 *temp_6;
    s32 *temp_6_2;
    s32 *var_23_2;
    s32 temp_2_10;
    s32 temp_2_11;
    s32 temp_2_12;
    s32 temp_2_13;
    s32 temp_2_14;
    s32 temp_2_15;
    s32 temp_2_16;
    s32 temp_2_17;
    s32 temp_2_18;
    s32 temp_2_19;
    s32 temp_2_20;
    s32 temp_2_21;
    s32 temp_2_22;
    s32 temp_2_24;
    s32 temp_2_26;
    s32 temp_2_27;
    s32 temp_2_2;
    s32 temp_2_30;
    s32 temp_2_31;
    s32 temp_2_32;
    s32 temp_2_33;
    s32 temp_2_34;
    s32 temp_2_35;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_2_7;
    s32 temp_2_8;
    s32 temp_2_9;
    s32 temp_4;
    s32 temp_4_4;
    s32 temp_4_6;
    s32 temp_6_3;
    s32 temp_6_4;
    s32 var_11;
    s32 var_11_2;
    s32 var_19;
    s32 var_21;
    s32 var_2;
    s32 var_2_2;
    s32 var_3;
    s32 var_3_10;
    s32 var_3_11;
    s32 var_3_12;
    s32 var_3_13;
    s32 var_3_14;
    s32 var_3_15;
    s32 var_3_16;
    s32 var_3_17;
    s32 var_3_18;
    s32 var_3_19;
    s32 var_3_20;
    s32 var_3_22;
    s32 var_3_23;
    s32 var_3_24;
    s32 var_3_25;
    s32 var_3_26;
    s32 var_3_27;
    s32 var_3_28;
    s32 var_3_29;
    s32 var_3_2;
    s32 var_3_30;
    s32 var_3_3;
    s32 var_3_4;
    s32 var_3_5;
    s32 var_3_6;
    s32 var_3_7;
    s32 var_3_8;
    s32 var_3_9;
    s32 var_5_2;
    u8 temp_2_23;
    u8 temp_3;
    u8 temp_3_10;
    u8 temp_3_11;
    u8 temp_3_12;
    u8 temp_3_13;
    u8 temp_3_14;
    u8 temp_3_16;
    u8 temp_3_17;
    u8 temp_3_18;
    u8 temp_3_19;
    u8 temp_3_20;
    u8 temp_3_21;
    u8 temp_3_22;
    u8 temp_3_23;
    u8 temp_3_24;
    u8 temp_3_26;
    u8 temp_3_27;
    u8 temp_3_29;
    u8 temp_3_2;
    u8 temp_3_30;
    u8 temp_3_31;
    u8 temp_3_32;
    u8 temp_3_33;
    u8 temp_3_34;
    u8 temp_3_3;
    u8 temp_3_4;
    u8 temp_3_5;
    u8 temp_3_6;
    u8 temp_3_7;
    u8 temp_3_8;
    u8 temp_3_9;
    u8 temp_4_3;
    u8 *temp_10;
    u8 *temp_20;
    u8 *temp_2;
    u8 *temp_2_25;
    u8 *temp_2_28;
    u8 *temp_2_36;
    u8 *temp_2_37;
    u8 *temp_3_15;
    u8 *temp_4_2;
    u8 *temp_4_5;
    u8 *temp_4_7;
    u8 *temp_4_8;
    u8 *temp_4_9;
    u8 *temp_5;
    u8 *temp_5_2;
    u32 temp_9;
    u32 temp_9_2;
    u32 temp_fp;
    u8 *var_20;
    u8 *var_23;
    u8 *var_2_3;
    u8 *var_2_4;
    u8 *var_3_21;
    u32 var_9;

    temp_2 = func_L39_0061D1D8((*(s32 *)((u8 *)(arg0) + 0x90)));
    if (temp_2 != 0) {
        temp_20 = (*(void **)((u8 *)(arg0) + 0x68));
        (*(s8 *)((u8 *)(temp_2) + 0x46C)) = 0;
        if ((*(s32 *)((u8 *)(temp_2) + 0x474)) != 3) {
            temp_3 = (*(u8 *)((u8 *)(arg0) + 0x20));
            if (temp_3 == 0) {
                temp_9 = temp_2 + 0x19E4;
                (*(void **)((u8 *)(arg0) + 0xB8)) = (void *) (*(void **)((u8 *)(temp_2) + 0x2524));
                var_3 = 0;
                if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                    temp_3_2 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                    *sp = (u8) *(temp_3_2 + 1 + (((temp_9 - temp_3_2) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                    temp_2_2 = sp0 ^ (s32) temp_9;
                    var_3 = sp4 ^ temp_2_2;
                    sp0 = temp_2_2;
                    sp4 = var_3;
                }
                if ((var_3 ^ 1) != 0) {
                    var_3_2 = 0;
                    if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                        temp_3_3 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                        *sp = (u8) *(temp_3_3 + 1 + (((temp_9 - temp_3_3) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                        temp_2_3 = sp0 ^ (s32) temp_9;
                        var_3_2 = sp4 ^ temp_2_3;
                        sp0 = temp_2_3;
                        sp4 = var_3_2;
                    }
                    if ((var_3_2 ^ 0x1D) == 0) {
                        goto block_18;
                    }
                } else {
block_18:
                    if (((*(u16 *)((u8 *)((*(void **)((u8 *)(temp_2) + 0x2524))) + 0x34)) & 1) && ((*(u8 *)((u8 *)(temp_2) + 0x1A14)) != 0)) {
                        func_L01_003F6F20((*(u8 *)((u8 *)(temp_2) + 0x24C9)), arg0, 0xFF917267, 0, 0x25, -1, 4, 0x3F800000, 0, 0x42B40000, 0x3F000000, 0x3F000000, 0x42200000, 0x42200000);
                    }
                }
                var_2 = D_001D4BC0;
                if ((temp_20 != 0) && ((*(f32 *)((u8 *)(temp_20) + 0x70)) != 0.0f)) {
                    func_L01_00404A10(&func_L39_0055A880, arg0);
                    var_2 = *(s32 *)0x2402D0;
                }
                if (var_2 != 0) {
                    (*(s32 *)((u8 *)(arg0) + 0x78)) = 0x80909090;
                    (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x10);
                } else {
                    (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x34)) & 0xFFEF);
                }
                temp_3_4 = (*(u8 *)((u8 *)(arg0) + 0x43));
                temp_4 = temp_3_4 & 0xFF;
                switch (temp_4) {                   /* switch 1; irregular */
                case 14:                            /* switch 1 */
                    if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                        var_5 = 1;
block_43:
                        func_003C3A10(arg0, var_5, 0, 4);
                    }
                    break;
                default:                            /* switch 1 */
                    temp_2_4 = temp_3_4 - 0xF;
                    if ((*(u8 *)((u8 *)(temp_2) + 0x1A10)) != 0) {
                        if ((u32) (temp_2_4 & 0xFF) < 2U) {
                            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                                if (temp_4 == 0xF) {
                                    var_5 = 0x10;
                                    goto block_43;
                                }
                            }
                        } else {
                            func_003C3A10(arg0, 0xF, 0, 3);
                        }
                    } else if ((u32) (temp_2_4 & 0xFF) < 2U) {
                        func_003C3A10(arg0, 0xE, 0, 2);
                    } else {
                    case 0:                         /* switch 1 */
                        temp_fp = temp_2 + 0x19E6;
                        if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                            var_3_3 = 0;
                            if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                                temp_3_5 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                                *sp = (u8) *(temp_3_5 + 1 + (((temp_9 - temp_3_5) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                temp_2_5 = sp0 ^ (s32) temp_9;
                                var_3_3 = sp4 ^ temp_2_5;
                                sp0 = temp_2_5;
                                sp4 = var_3_3;
                            }
                            if ((var_3_3 ^ 0x37) != 0) {
                                var_3_4 = 0;
                                if ((*(u8 *)((u8 *)(temp_2) + 0x19E6)) != 0) {
                                    temp_3_6 = (*(u8 *)((u8 *)(temp_2) + 0x19E6));
                                    *sp = (u8) *(temp_3_6 + 1 + (((temp_fp - temp_3_6) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                    temp_2_6 = sp0 ^ (s32) temp_fp;
                                    var_3_4 = sp4 ^ temp_2_6;
                                    sp0 = temp_2_6;
                                    sp4 = var_3_4;
                                }
                                if (((var_3_4 ^ 0x22) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 1)) {
                                    func_003C3A10(arg0, 1, 0, 4);
                                }
                            }
                        }
                        if ((*(u8 *)((u8 *)(arg0) + 0x42)) == 6) {
                            func_003C3938(arg0, 1, 0);
                        }
                        func_L39_0055AD78(arg0);
                        var_3_5 = 0;
                        if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                            temp_3_7 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                            *sp = (u8) *(temp_3_7 + 1 + (((temp_9 - temp_3_7) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                            temp_2_7 = sp0 ^ (s32) temp_9;
                            var_3_5 = sp4 ^ temp_2_7;
                            sp0 = temp_2_7;
                            sp4 = var_3_5;
                        }
                        if ((var_3_5 ^ 0x13) != 0) {
                            var_3_6 = 0;
                            if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                                temp_3_8 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                                *sp = (u8) *(temp_3_8 + 1 + (((temp_9 - temp_3_8) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                temp_2_8 = sp0 ^ (s32) temp_9;
                                var_3_6 = sp4 ^ temp_2_8;
                                sp0 = temp_2_8;
                                sp4 = var_3_6;
                            }
                            if ((var_3_6 ^ 0x20) != 0) {
                                var_3_7 = 0;
                                if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                                    temp_3_9 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                                    *sp = (u8) *(temp_3_9 + 1 + (((temp_9 - temp_3_9) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                    temp_2_9 = sp0 ^ (s32) temp_9;
                                    var_3_7 = sp4 ^ temp_2_9;
                                    sp0 = temp_2_9;
                                    sp4 = var_3_7;
                                }
                                if ((var_3_7 ^ 0x2A) != 0) {
                                    var_3_8 = 0;
                                    if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                                        temp_3_10 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                                        *sp = (u8) *(temp_3_10 + 1 + (((temp_9 - temp_3_10) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                        temp_2_10 = sp0 ^ (s32) temp_9;
                                        var_3_8 = sp4 ^ temp_2_10;
                                        sp0 = temp_2_10;
                                        sp4 = var_3_8;
                                    }
                                    if ((var_3_8 ^ 0x6F) != 0) {
                                        var_3_9 = 0;
                                        if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                                            temp_3_11 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                                            *sp = (u8) *(temp_3_11 + 1 + (((temp_9 - temp_3_11) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                            temp_2_11 = sp0 ^ (s32) temp_9;
                                            var_3_9 = sp4 ^ temp_2_11;
                                            sp0 = temp_2_11;
                                            sp4 = var_3_9;
                                        }
                                        if ((var_3_9 ^ 0x14) != 0) {
                                            temp_3_12 = (*(u8 *)((u8 *)(arg0) + 0x43));
                                            if ((temp_3_12 >= 3U) && (temp_3_12 < 6U)) {
                                                func_003C3A10(arg0, 1, 0, 3);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        temp_4_2 = (*(void **)((u8 *)(temp_2) + 0x2524));
                        if (((*(u8 *)((u8 *)(temp_4_2) + 0x43)) != (*(u8 *)((u8 *)(temp_4_2) + 0x42))) || (((*(u8 *)((u8 *)(temp_4_2) + 0x41)) - (*(u8 *)((u8 *)(temp_4_2) + 0x40))) >= 3)) {
                            (*(u16 *)((u8 *)(temp_20) + 0x74)) = (u16) ((*(u16 *)((u8 *)(temp_20) + 0x74)) + 1);
                        }
                        (*(f32 *)((u8 *)(arg0) + 0x48)) = (f32) (*(f32 *)((u8 *)(temp_2) + 0x610));
                        temp_3_13 = (*(u8 *)((u8 *)(temp_2) + 0x19E6));
                        temp_10 = ((*(s16 *)((u8 *)(temp_2) + 0x107C)) * 0x2C) + &D_L39_0047A8A8;
                        if (temp_3_13 == 0) {
                            var_3_10 = 0;
                        } else {
                            *sp = (u8) *(temp_3_13 + 1 + (((temp_fp - temp_3_13) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                            temp_2_12 = sp0 ^ (s32) temp_fp;
                            var_3_10 = sp4 ^ temp_2_12;
                            sp0 = temp_2_12;
                            sp4 = var_3_10;
                        }
                        if ((var_3_10 ^ 6) != 0) {
                            var_3_11 = 0;
                            if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                                temp_3_14 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                                *sp = (u8) *(temp_3_14 + 1 + (((temp_9 - temp_3_14) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                temp_2_13 = sp0 ^ (s32) temp_9;
                                var_3_11 = sp4 ^ temp_2_13;
                                sp0 = temp_2_13;
                                sp4 = var_3_11;
                            }
                            if ((var_3_11 ^ 0x2A) == 0) {
                                goto block_85;
                            }
                        } else {
block_85:
                            var_21 = 1;
                            if (((*(s32 *)((u8 *)(temp_2) + 0x61C)) != 0) || (temp_f1 = (*(f32 *)((u8 *)(temp_2) + 0x628)), (temp_f1 < (f32) (*(s32 *)((u8 *)(temp_10) + 0x1C)))) || ((f32) (*(s32 *)((u8 *)(temp_10) + 0x20)) < temp_f1)) {
                                var_21 = 0;
                            }
                            var_5_2 = 0;
                            if ((*(s16 *)((u8 *)(temp_20) + 0x7C)) != (s16) (*(u16 *)((u8 *)(temp_20) + 0x74))) {
                                temp_3_15 = (*(void **)((u8 *)(temp_2) + 0x2524));
                                temp_4_3 = (*(u8 *)((u8 *)(temp_3_15) + 0x42));
                                if (temp_4_3 == (*(u8 *)((u8 *)(temp_3_15) + 0x43))) {
                                    switch (temp_4_3) { /* switch 2; irregular */
                                    case 23:        /* switch 2 */
                                        var_f0 = 0.0f;
                                        var_2_2 = 1;
block_99:
                                        if (!(var_f0 <= (*(f32 *)((u8 *)(temp_2) + 0x628)))) {
                                            var_2_2 = 0;
                                        }
                                        var_5_2 = var_2_2;
                                        break;
                                    case 24:        /* switch 2 */
                                        var_f0 = 0.0f;
                                        var_2_2 = 1;
                                        goto block_99;
                                    case 25:        /* switch 2 */
                                        var_f0 = 12.0f;
                                        var_2_2 = 1;
                                        goto block_99;
                                    default:        /* switch 2 */
                                        var_2_2 = 1;
                                        if (temp_4_3 == 0x27) {
                                            var_f0 = 23.0f;
                                            goto block_99;
                                        }
                                        break;
                                    }
                                }
                            }
                            if (var_5_2 != 0) {
                                (*(f32 *)((u8 *)(temp_20) + 0x70)) = 1.0f;
                                (*(s16 *)((u8 *)(temp_20) + 0x7C)) = (s16) (*(u16 *)((u8 *)(temp_20) + 0x74));
                            }
                            temp_6 = temp_2 + 0xFF0;
                            sp8C = temp_6;
                            (*(f32 *)((u8 *)(temp_2) + 0x1010)) = (f32) (*(f32 *)((u8 *)(temp_2) + 0xFF0));
                            (*(f32 *)((u8 *)(temp_2) + 0x1000)) = (f32) (*(f32 *)((u8 *)(temp_2) + 0xFE0));
                            var_f23 = (*(f32 *)((u8 *)(temp_2) + 0xB8));
                            func_003C2F58(arg0, 1, temp_6);
                            var_f20 = 0.0f;
                            temp_6_2 = temp_2 + 0xFE0;
                            sp88 = temp_6_2;
                            func_003C2F58((*(void **)((u8 *)(temp_2) + 0x2524)), 0, temp_6_2);
                            var_3_12 = 0;
                            if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                                temp_3_16 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                                *sp = (u8) *(temp_3_16 + 1 + (((temp_9 - temp_3_16) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                temp_2_14 = sp0 ^ (s32) temp_9;
                                var_3_12 = sp4 ^ temp_2_14;
                                sp0 = temp_2_14;
                                sp4 = var_3_12;
                            }
                            if ((var_3_12 ^ 0x13) != 0) {
                                var_3_13 = 0;
                                if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                                    temp_3_17 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                                    *sp = (u8) *(temp_3_17 + 1 + (((temp_9 - temp_3_17) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                    temp_2_15 = sp0 ^ (s32) temp_9;
                                    var_3_13 = sp4 ^ temp_2_15;
                                    sp0 = temp_2_15;
                                    sp4 = var_3_13;
                                }
                                if ((var_3_13 ^ 0x6F) != 0) {
                                    var_3_14 = 0;
                                    if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                                        temp_3_18 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                                        *sp = (u8) *(temp_3_18 + 1 + (((temp_9 - temp_3_18) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                        temp_2_16 = sp0 ^ (s32) temp_9;
                                        var_3_14 = sp4 ^ temp_2_16;
                                        sp0 = temp_2_16;
                                        sp4 = var_3_14;
                                    }
                                    if ((var_3_14 ^ 0x2A) == 0) {
                                        goto block_113;
                                    }
                                } else {
                                    goto block_113;
                                }
                            } else {
block_113:
                                temp_4_4 = (*(s16 *)((u8 *)(temp_2) + 0x107C)) * 0x2C;
                                var_f13 = 0x3FC90FDB;
                                temp_f23 = func_0038D160((*(f32 *)((u8 *)(temp_2) + 0xFF0)) - (*(f32 *)((u8 *)(temp_2) + 0xA0)), (*(f32 *)((u8 *)(temp_2) + 0xFF4)) - (*(f32 *)((u8 *)(temp_2) + 0xA4)));
                                if ((*(s32 *)((u8 *)((&D_L39_0047A8A8 + temp_4_4)) + 4)) == 1) {
                                    var_f13 = 0xBFC90FDB;
                                }
                                var_f23 = func_0038DAB8(temp_4_4, 1);
                            }
                            0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                            sp0 = (*(f32 *)((u8 *)(temp_2) + 0xFF0));
                            func_0038CF68(sp, sp, func_0038CEA8(sp) + 0.17f);
                            var_3_15 = 0;
                            if ((*(u8 *)((u8 *)(temp_2) + 0x19E6)) != 0) {
                                temp_3_19 = (*(u8 *)((u8 *)(temp_2) + 0x19E6));
                                sp10 = (u8) *(temp_3_19 + 1 + (((temp_fp - temp_3_19) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                temp_2_17 = sp10 ^ (s32) temp_fp;
                                var_3_15 = sp14 ^ temp_2_17;
                                sp10 = temp_2_17;
                                sp14 = var_3_15;
                            }
                            if ((var_3_15 ^ 0xF) != 0) {
                                var_3_16 = 0;
                                if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                                    temp_3_20 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                                    sp10 = (u8) *(temp_3_20 + 1 + (((temp_9 - temp_3_20) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                    temp_2_18 = sp10 ^ (s32) temp_9;
                                    var_3_16 = sp14 ^ temp_2_18;
                                    sp10 = temp_2_18;
                                    sp14 = var_3_16;
                                }
                                if ((var_3_16 ^ 0x6F) != 0) {
                                    var_3_17 = 0;
                                    if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                                        temp_3_21 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                                        sp10 = (u8) *(temp_3_21 + 1 + (((temp_9 - temp_3_21) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                        temp_2_19 = sp10 ^ (s32) temp_9;
                                        var_3_17 = sp14 ^ temp_2_19;
                                        sp10 = temp_2_19;
                                        sp14 = var_3_17;
                                    }
                                    if ((var_3_17 ^ 0x14) != 0) {
                                        var_f20 = func_0038DBA0((*(f32 *)((u8 *)(temp_2) + 0xB8)), func_0038D160((*(f32 *)((u8 *)(temp_2) + 0xFF0)) - (*(f32 *)((u8 *)(temp_2) + 0xA0)), (*(f32 *)((u8 *)(temp_2) + 0xFF4)) - (*(f32 *)((u8 *)(temp_2) + 0xA4))));
                                        if (var_f20 > 1.5707964f) {
                                            var_21 = 0;
                                        }
                                        func_L39_0055B418(temp_2, sp);
                                    }
                                }
                            }
                            0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                            (*(f32 *)((u8 *)(temp_2) + 0xFF0)) = (f32) (*(f32 *)((u8 *)(temp_2) + 0xFE0));
                            var_3_18 = 0;
                            if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                                temp_3_22 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                                *sp = (u8) *(temp_3_22 + 1 + (((temp_9 - temp_3_22) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                temp_2_20 = (s32)(sp0) ^ (s32) temp_9;
                                var_3_18 = sp4 ^ temp_2_20;
                                sp0 = temp_2_20;
                                sp4 = var_3_18;
                            }
                            if ((var_3_18 ^ 0x2A) != 0) {
                                var_3_19 = 0;
                                if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                                    temp_3_23 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                                    *sp = (u8) *(temp_3_23 + 1 + (((temp_9 - temp_3_23) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                    temp_2_21 = sp0 ^ (s32) temp_9;
                                    var_3_19 = sp4 ^ temp_2_21;
                                    sp0 = temp_2_21;
                                    sp4 = var_3_19;
                                }
                                if (((var_3_19 ^ 0x6F) != 0) && (var_f20 < 1.2217305f) && ((*(s32 *)((u8 *)(temp_2) + 0x2F0)) >= 9)) {
                                    sp0 = (*(f32 *)((u8 *)(temp_2) + 0xA0));
                                    func_L01_00511158(temp_2, sp, sp, 0x3F000000);
                                    temp_f20 = func_0038D160((*(f32 *)((u8 *)(temp_2) + 0xFF0)) - (*(f32 *)((u8 *)(temp_2) + 0xA0)), (*(f32 *)((u8 *)(temp_2) + 0xFF4)) - (*(f32 *)((u8 *)(temp_2) + 0xA4)));
                                    sp10 = (*(f32 *)((u8 *)(temp_2) + 0xA0));
                                    func_L01_00511158(temp_2, &sp10, &sp10, 0x3F000000);
                                    sp20 = func_0038D098(temp_f20) * 1.4f;
                                    temp_f0 = func_0038D0B0(temp_f20) * 1.4f;
                                    sp28 = 0;
                                    sp24 = temp_f0;
                                    func_L39_0055B418(temp_2, (s32 *) &sp20);
                                    0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                                    if (((*(s16 *)((u8 *)(temp_2) + 0x107E)) == 0) && (func_003D3CB0() != 0) && (func_003D5630() != 0) && (((*(void **)((u8 *)(&D_L39_0025F740) + 0x18)) == 0) || (func_L01_0044AEB8((*(void **)((u8 *)(&D_L39_0025F740) + 0x18))) != 0))) {
                                        (*(s16 *)((u8 *)(temp_2) + 0x107E)) = 1;
                                        func_L39_005F33E0(2, 0, arg0);
                                        func_L39_0055B178(arg0, temp_2);
                                        if ((*(void **)((u8 *)(&D_L39_0025F740) + 0x18)) != 0) {
                                            if ((*(u8 *)((u8 *)(temp_2) + 0x1A06)) != 0) {
                                                sp30 = (*(f32 *)((u8 *)(temp_2) + 0x20));
                                            } else {
                                                sp30 = func_0038D098(var_f23);
                                                sp34 = func_0038D0B0(var_f23);
                                                sp38 = 0;
                                            }
                                            func_L01_00446A70((*(void **)((u8 *)(&D_L39_0025F740) + 0x18)), arg0, 0x10001, &D_L39_0025F740 + 0x20, &sp30, 0x3F800000);
                                        }
                                    }
                                }
                            }
                            var_3_20 = 0;
                            if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                                temp_3_24 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                                *sp = (u8) *(temp_3_24 + 1 + (((temp_9 - temp_3_24) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                temp_2_22 = (s32)(sp0) ^ (s32) temp_9;
                                var_3_20 = sp4 ^ temp_2_22;
                                sp0 = temp_2_22;
                                sp4 = var_3_20;
                            }
                            if (((var_3_20 ^ 0x14) == 0) && (func_L39_00632C48(temp_2, 0x41D80000) != 0)) {
                                func_L39_005F33E0(2, 0, arg0);
                                temp_3_25 = (*(f32 *)((u8 *)(temp_2) + 0xFF0));
                                sp10 = temp_3_25;
                                sp0 = temp_3_25;
                                func_L01_00511158(temp_2, sp, sp, 0x3F333333);
                                func_L01_00511158(temp_2, (s32 *) &sp10, (s32 *) &sp10, 0xBF666666);
                                if (func_003D3CB0() != 0) {
                                    func_L39_0055B178(arg0, temp_2);
                                }
                            }
                            if (var_21 != 0) {
                                if (func_L39_00648AE0(temp_2, 0xA) != 0) {
                                    var_3_21 = ((*(s8 *)((u8 *)(&D_L39_0049C890) + 0x521)) << 7) + &D_L39_0049C890;
                                } else {
                                    var_3_21 = &D_L39_0049C890 + 0x500;
                                }
                                temp_2_23 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                                var_f21 = 0x3F800000;
                                var_f20_2 = (*(f32 *)((u8 *)(var_3_21) + 0x30));
                                if (temp_2_23 == 0) {
                                    var_3_22 = 0;
                                    var_23 = temp_2 + 0x1000;
                                    var_20 = temp_2 + 0x1010;
                                } else {
                                    var_23 = temp_2 + 0x1000;
                                    var_20 = temp_2 + 0x1010;
                                    sp40 = (u8) *(temp_2_23 + 1 + (((temp_9 - temp_2_23) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                    temp_2_24 = sp40 ^ (s32) temp_9;
                                    var_3_22 = sp44 ^ temp_2_24;
                                    sp40 = temp_2_24;
                                    sp44 = var_3_22;
                                }
                                if ((var_3_22 ^ 0x14) == 0) {
                                    if (func_L39_00648AE0(temp_2, 0xA) != 0) {
                                        var_2_3 = ((*(s8 *)((u8 *)(&D_L39_0049C890) + 0x521)) << 7) + &D_L39_0049C890;
                                    } else {
                                        var_2_3 = &D_L39_0049C890 + 0x500;
                                    }
                                    var_f20_2 = (*(f32 *)((u8 *)(var_2_3) + 0x34));
                                    var_f21 = 0x3FC66666;
                                }
                                sp30 = func_0038D098(var_f23);
                                sp34 = func_0038D0B0(var_f23);
                                sp38 = 0;
                                func_L01_00446760(sp, arg0, 0x10001, (s32 *) &sp30, var_f20_2);
                                func_0038CFB8();
                                sp19 = 1;
                                spC = 5627.925f;
                                sp1A = (*(u16 *)((u8 *)(arg0) + 0xAA));
                                sp8 = 1.0f;
                                sp18 = 0;
                                if ((*(u8 *)((u8 *)(temp_2) + 0x1A06)) != 0) {
                                    sp30 = 0.0f;
                                    func_L01_00450E48((*(void **)((u8 *)(temp_2) + 0x2524)), (s32 *) &sp30, 1.0f, 0, 0x3F800000);
                                }
                                if ((func_L01_00446BF0(sp88, sp8C, var_23, var_20, (*(void **)((u8 *)(temp_2) + 0x2524)), sp, 5) != 0) && ((*(void **)((u8 *)(&D_L39_0025F740) + 0x18)) != 0) && (func_L01_00337EF8() == 0) && ((*(s16 *)((u8 *)(temp_2) + 0x107E)) == 0) && (((*(void **)((u8 *)(&D_L39_0025F740) + 0x18)) == 0) || (temp_2_25 = (*(void **)((u8 *)((*(void **)((u8 *)(&D_L39_0025F740) + 0x18))) + 0x24)), (temp_2_25 == 0)) || ((*(u8 *)((u8 *)(temp_2_25) + 0x46)) != 0x14))) {
                                    (*(s16 *)((u8 *)(temp_2) + 0x107E)) = 1;
                                    func_L39_005F33E0(func_L01_00337EA8(), 0, arg0);
                                    func_L39_0055B178(arg0, temp_2);
                                }
                                temp_f1_2 = (*(f32 *)((u8 *)(temp_2) + 0xFF0));
                                0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                                sp50 = temp_f1_2;
                                func_0038CF68((s32 *) &sp50, (s32 *) &sp50, func_0038CEA8((s32 *) &sp50) - 0.085f);
                                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                                var_f12 = 0x3EB33333;
                                sp40 = temp_f1_2;
                                var_3_23 = 0;
                                if ((*(u8 *)((u8 *)(temp_2) + 0x19E6)) != 0) {
                                    temp_3_26 = (*(u8 *)((u8 *)(temp_2) + 0x19E6));
                                    sp60 = (u8) *(temp_3_26 + 1 + (((temp_fp - temp_3_26) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                    temp_2_26 = sp60 ^ (s32) temp_fp;
                                    var_3_23 = sp64 ^ temp_2_26;
                                    sp60 = temp_2_26;
                                    sp64 = var_3_23;
                                }
                                if ((var_3_23 ^ 0xF) == 0) {
                                    var_f12 = 0x3F333333;
                                }
                                var_3_24 = 0;
                                if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                                    temp_3_27 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                                    sp60 = (u8) *(temp_3_27 + 1 + (((temp_9 - temp_3_27) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                    temp_2_27 = sp60 ^ (s32) temp_9;
                                    var_3_24 = sp64 ^ temp_2_27;
                                    sp60 = temp_2_27;
                                    sp64 = var_3_24;
                                }
                                if ((var_3_24 ^ 0x14) == 0) {
                                    var_f12 = 0x3EF0A3D7;
                                }
                                if (func_003D4D00(&sp40, 0, (*(void **)((u8 *)(temp_2) + 0x2524)), sp, var_f12) != 0) {
                                    if (((D_L39_002637C0 == 0) || (temp_2_28 = (*(void **)((u8 *)(D_L39_002637C0) + 0x24)), (temp_2_28 == 0)) || ((*(u8 *)((u8 *)(temp_2_28) + 0x46)) != 0x12)) && (func_L01_00337EF8() == 0) && ((*(s16 *)((u8 *)(temp_2) + 0x107E)) == 0)) {
                                        (*(s16 *)((u8 *)(temp_2) + 0x107E)) = 1;
                                        func_L39_005F33E0(func_L01_00337EA8(), 0, arg0);
                                        func_L39_0055B178(arg0, temp_2);
                                    }
                                }
                            }
                        }
                    }
                    break;
                }
            } else if (((s32) temp_3 >= 0) && ((s32) temp_3 < 0xC)) {
                if ((s32) temp_3 >= 0xA) {
                    temp_4_5 = temp_2 + 0x1780;
                    sp84 = temp_4_5;
                    func_L01_0044E468(temp_4_5, 0);
                    (*(void **)((u8 *)(arg0) + 0xB8)) = (void *) (*(void **)((u8 *)(temp_2) + 0x2524));
                    (*(s8 *)((u8 *)(temp_2) + 0x46C)) = 2;
                    if (((*(u8 *)((u8 *)(arg0) + 0x20)) == 0xA) && ((temp_4_6 = (*(s32 *)((u8 *)(temp_2) + 0x2404)), (temp_4_6 == -1)) || (temp_4_7 = (temp_4_6 << 7) + &D_1FE020, ((*(s32 *)((u8 *)(temp_4_7) + 0xDC)) != (*(void **)((u8 *)(temp_2) + 0x2524)))) || ((*(u8 *)((u8 *)(temp_4_7) + 0xD0)) == 0))) {
                        (*(s32 *)((u8 *)(temp_2) + 0x2404)) = func_L39_005F33E0(0xB, 4, (*(void **)((u8 *)(temp_2) + 0x2524)));
                    }
                    func_L01_0044E298(arg0, 0, 0, 0x3EFA35DD);
                    if (((*(s16 *)((u8 *)(temp_2) + 0x107E)) != 0) && (func_0038CAD0(temp_20 + 0x6C) != 0)) {
                        (*(s16 *)((u8 *)(temp_2) + 0x107E)) = 0;
                    }
                    temp_3_28 = arg0 + 0x10;
                    sp90 = temp_3_28;
                    if ((*(u8 *)((u8 *)(temp_2) + 0x1A06)) == 0) {
                        temp_f0_2 = func_003C3D30(temp_3_28, 0, 0, 0.5f);
                        temp_f2 = (*(f32 *)((u8 *)(arg0) + 0x18));
                        if ((temp_f2 - temp_f0_2) < 0.8f) {
                            temp_f12 = temp_f0_2 + 0.55f;
                            if (temp_f2 < temp_f12) {
                                func_003C4138(arg0 + 0x18, temp_f12, 0.080000006f);
                            } else {
                                func_003C4138(arg0 + 0x18, temp_f12, 0.020000001f);
                            }
                        }
                    }
                    sp0 = (*(s32 *)((u8 *)(arg0) + 0x10));
                    if ((*(u8 *)((u8 *)(arg0) + 0x20)) == 0xA) {
                        sp10 = (*(s32 *)((u8 *)(temp_2) + 0x180));
                        func_0038CE20(&sp10, &sp10, 0.980000019f);
                        0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                        temp_2_29 = temp_20 + 0x40;
                        (*(s32 *)((u8 *)(arg0) + 0x10)) = (s32) (*(s32 *)((u8 *)(arg0) + 0x10));
                        var_23_2 = temp_2_29;
                        func_0038CF68((s32 *) &sp10, temp_2_29, (*(f32 *)((u8 *)(temp_20) + 0x60)));
                        0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                        (*(s32 *)((u8 *)(arg0) + 0x10)) = 0x3AB24207;
                        temp_f0_3 = (*(f32 *)((u8 *)(temp_20) + 0x64)) + 0.00136f;
                        (*(f32 *)((u8 *)(temp_20) + 0x64)) = temp_f0_3;
                        func_003C4138(temp_20 + 0x60, 0.0f, temp_f0_3);
                        if ((*(f32 *)((u8 *)(temp_20) + 0x60)) == 0.0f) {
                            (*(u8 *)((u8 *)(arg0) + 0x20)) = 0xBU;
                        }
                        temp_9_2 = temp_2 + 0x19E4;
                        var_11 = 0;
                        if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) == 0) {
                            var_3_25 = 0;
                        } else {
                            temp_3_29 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                            sp20 = (u8) *(temp_3_29 + 1 + (((temp_9_2 - temp_3_29) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                            temp_2_30 = (s32)(sp20) ^ (s32) temp_9_2;
                            var_3_25 = (s32)(sp24) ^ temp_2_30;
                            sp20 = temp_2_30;
                            sp24 = var_3_25;
                        }
                        if ((var_3_25 ^ 0x31) != 0) {
                            var_3_26 = 0;
                            if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                                temp_3_30 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                                sp20 = (u8) *(temp_3_30 + 1 + (((temp_9_2 - temp_3_30) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                temp_2_31 = sp20 ^ (s32) temp_9_2;
                                var_3_26 = sp24 ^ temp_2_31;
                                sp20 = temp_2_31;
                                sp24 = var_3_26;
                            }
                            if ((var_3_26 ^ 0x64) != 0) {
                                var_3_27 = 0;
                                if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                                    temp_3_31 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                                    sp20 = (u8) *(temp_3_31 + 1 + (((temp_9_2 - temp_3_31) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                    temp_2_32 = sp20 ^ (s32) temp_9_2;
                                    var_3_27 = sp24 ^ temp_2_32;
                                    sp20 = temp_2_32;
                                    sp24 = var_3_27;
                                }
                                if ((var_3_27 ^ 0x66) == 0) {
                                    goto block_218;
                                }
                            } else {
                                goto block_218;
                            }
                        } else {
block_218:
                            var_11 = 1;
                        }
                        if (var_11 != 0) {
                            (*(u8 *)((u8 *)(arg0) + 0x20)) = 0xBU;
                        }
                    } else {
                        sp10 = (*(s32 *)((u8 *)(temp_2) + 0x180));
                        func_0038CE20((f32 *) &sp10, (f32 *) &sp10, 0.980000019f);
                        0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                        (*(s32 *)((u8 *)(arg0) + 0x10)) = (s32) (*(s32 *)((u8 *)(arg0) + 0x10));
                        sp80 = 0;
                        func_L01_00348160(arg0);
                        0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                        sp10 = (*(s32 *)((u8 *)(temp_2) + 0x430));
                        temp_f0_4 = (*(f32 *)((u8 *)(temp_20) + 0x64)) + 0.00036f;
                        (*(f32 *)((u8 *)(temp_20) + 0x64)) = temp_f0_4;
                        (*(f32 *)((u8 *)(temp_20) + 0x60)) = (f32) ((*(f32 *)((u8 *)(temp_20) + 0x60)) + temp_f0_4);
                        temp_f0_5 = func_0038CEA8(&sp10);
                        if (((temp_f0_5 / (*(f32 *)((u8 *)(temp_20) + 0x60))) < 4.0f) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 1)) {
                            func_003C3A10(arg0, 1, 0, 4);
                        }
                        if (temp_f0_5 <= (*(f32 *)((u8 *)(temp_20) + 0x60))) {
                            (*(f32 *)((u8 *)(temp_20) + 0x60)) = temp_f0_5;
                            sp80 = 1;
                        }
                        func_0038CF68(&sp10, &sp10, (*(f32 *)((u8 *)(temp_20) + 0x60)));
                        0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                        (*(s32 *)((u8 *)(arg0) + 0x10)) = 0x40400000;
                        if ((temp_f0_5 / (*(f32 *)((u8 *)(temp_20) + 0x60))) < 3.0f) {
                            var_9 = temp_2 + 0x19E4;
                            if ((*(s32 *)((u8 *)(temp_2) + 0x630)) != -1) {
                                func_L39_0062B728(temp_2, 2);
                                temp_6_3 = (*(s32 *)((u8 *)(temp_2) + 0x2404));
                                (*(s32 *)((u8 *)(temp_2) + 0x634)) = 0xD;
                                if (temp_6_3 != -1) {
                                    temp_5 = (*(void **)((u8 *)(temp_2) + 0x2524));
                                    temp_4_8 = (temp_6_3 << 7) + &D_1FE020;
                                    if (((*(s32 *)((u8 *)(temp_4_8) + 0xDC)) == temp_5) && ((*(u8 *)((u8 *)(temp_4_8) + 0xD0)) != 0)) {
                                        func_L39_005F3088(temp_6_3);
                                    }
                                }
                                (*(s32 *)((u8 *)(temp_2) + 0x2404)) = -1;
                                goto block_234;
                            }
                        } else {
block_234:
                            var_9 = temp_2 + 0x19E4;
                        }
                        var_11_2 = 0;
                        if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) == 0) {
                            var_3_28 = 0;
                            var_23_2 = temp_20 + 0x40;
                        } else {
                            temp_3_32 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                            var_23_2 = temp_20 + 0x40;
                            sp20 = (u8) *(temp_3_32 + 1 + (((var_9 - temp_3_32) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                            temp_2_33 = sp20 ^ (s32) var_9;
                            var_3_28 = sp24 ^ temp_2_33;
                            sp20 = temp_2_33;
                            sp24 = var_3_28;
                        }
                        if ((var_3_28 ^ 0x31) != 0) {
                            var_3_29 = 0;
                            if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                                temp_3_33 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                                sp20 = (u8) *(temp_3_33 + 1 + (((var_9 - temp_3_33) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                temp_2_34 = sp20 ^ (s32) var_9;
                                var_3_29 = sp24 ^ temp_2_34;
                                sp20 = temp_2_34;
                                sp24 = var_3_29;
                            }
                            if ((var_3_29 ^ 0x64) != 0) {
                                var_3_30 = 0;
                                if ((*(u8 *)((u8 *)(temp_2) + 0x19E4)) != 0) {
                                    temp_3_34 = (*(u8 *)((u8 *)(temp_2) + 0x19E4));
                                    sp20 = (u8) *(temp_3_34 + 1 + (((var_9 - temp_3_34) & 7 & 7) * 0xFF) + &D_L39_004997E0);
                                    temp_2_35 = sp20 ^ (s32) var_9;
                                    var_3_30 = sp24 ^ temp_2_35;
                                    sp20 = temp_2_35;
                                    sp24 = var_3_30;
                                }
                                if (((var_3_30 ^ 0x66) == 0) || (temp_f0_5 > 32.0f)) {
                                    goto block_246;
                                }
                            } else {
                                goto block_246;
                            }
                        } else {
block_246:
                            var_11_2 = 1;
                        }
                        if ((sp80 != 0) || (var_11_2 != 0)) {
                            if (var_11_2 == 0) {
                                func_L39_0063A030(temp_2, 5, 0);
                            }
                            temp_6_4 = (*(s32 *)((u8 *)(temp_2) + 0x2404));
                            if (temp_6_4 != -1) {
                                temp_5_2 = (*(void **)((u8 *)(temp_2) + 0x2524));
                                temp_4_9 = (temp_6_4 << 7) + &D_1FE020;
                                if (((*(s32 *)((u8 *)(temp_4_9) + 0xDC)) == temp_5_2) && ((*(u8 *)((u8 *)(temp_4_9) + 0xD0)) != 0)) {
                                    func_L39_005F3088(temp_6_4);
                                }
                            }
                            (*(s32 *)((u8 *)(temp_2) + 0x2404)) = -1;
                            func_L01_0044E740(sp84);
                            (*(s8 *)((u8 *)(temp_2) + 0x46A)) = 0;
                            (*(u8 *)((u8 *)(arg0) + 0x20)) = 0U;
                        }
                    }
                    var_19 = 0;
                    if ((func_003D3CB0() != 0) && (func_003D5630() != 0) && (((*(void **)((u8 *)(&D_L39_0025F740) + 0x18)) == 0) || (func_L39_005B8928((*(void **)((u8 *)(&D_L39_0025F740) + 0x18))) == 0))) {
                        var_19 = (*(s32 *)((u8 *)(&D_L39_0025F740) + 0x1C)) != 0;
                    }
                    if ((var_19 != 0) || ((*(s16 *)((u8 *)(temp_20) + 0x76)) != 0)) {
                        (*(s16 *)((u8 *)(temp_20) + 0x76)) = 0;
                        if ((*(s16 *)((u8 *)(temp_2) + 0x107E)) == 0) {
                            (*(s32 *)((u8 *)(temp_20) + 0x6C)) = 0x19;
                            (*(s16 *)((u8 *)(temp_2) + 0x107E)) = 1;
                            func_L39_005F33E0(2, 0, arg0);
                        }
                        if ((*(u8 *)((u8 *)(arg0) + 0x20)) == 0xA) {
                            func_L39_0055B178(arg0, temp_2);
                            (*(f32 *)((u8 *)(temp_20) + 0x60)) = (f32) ((*(f32 *)((u8 *)(temp_20) + 0x60)) * 0.5f);
                            (*(u8 *)((u8 *)(arg0) + 0x20)) = 0xBU;
                        }
                    }
                    var_f20_3 = 1.2f;
                    if ((*(u8 *)((u8 *)(arg0) + 0x20)) == 0xB) {
                        var_f20_3 = -0.37f;
                    }
                    func_0038CF68((s32 *) &sp40, var_23_2, var_f20_3);
                    if (func_L39_00648AE0(temp_2, 0xA) != 0) {
                        var_2_4 = ((*(s8 *)((u8 *)(&D_L39_0049C890) + 0x521)) << 7) + &D_L39_0049C890;
                    } else {
                        var_2_4 = &D_L39_0049C890 + 0x500;
                    }
                    func_L01_00446760(&sp10, arg0, 0x10001, (s32 *) &sp40, (*(f32 *)((u8 *)(var_2_4) + 0x30)));
                    sp18 = 1.0f;
                    if ((*(u8 *)((u8 *)(temp_2) + 0x1A06)) != 0) {
                        sp10 = 0;
                        func_L01_00450E48((*(void **)((u8 *)(temp_2) + 0x2524)), &sp10, var_f20_3, 0, 0x3F800000);
                    }
                    unksp29 = 1;
                    sp1C = 5627.925f;
                    sp28 = 0;
                    unksp2A = (*(u16 *)((u8 *)(temp_2) + 0x108C)) + 1;
                    func_003C2F58(arg0, 1, (s32 *) &sp50);
                    if (((func_003D4D00((s32 *) &sp50, 0, (*(void **)((u8 *)(temp_2) + 0x2524)), &sp10, 0.400000006f) != 0) || (func_003C2F58(arg0, 0, (s32 *) &sp50), (func_003D4D00((s32 *) &sp50, 0, (*(void **)((u8 *)(temp_2) + 0x2524)), &sp10, 0.400000006f) != 0))) && ((*(s16 *)((u8 *)(temp_2) + 0x107E)) == 0) && ((*(void **)((u8 *)(&D_L39_0025F740) + 0x18)) != 0) && ((temp_2_36 = (*(void **)((u8 *)((*(void **)((u8 *)(&D_L39_0025F740) + 0x18))) + 0x24)), (temp_2_36 == 0)) || ((*(u8 *)((u8 *)(temp_2_36) + 0x46)) != 0x14))) {
                        temp_2_37 = func_00382348((*(void **)((u8 *)(&D_L39_0025F740) + 0x18)));
                        if ((temp_2_37 == 0) || ((*(s16 *)((u8 *)(temp_2_37) + 0x1C)) == 0) || ((*(s32 *)((u8 *)(temp_2_37) + 0x18)) != arg0)) {
                            sp70 = (*(s32 *)((u8 *)((*(void **)((u8 *)(&D_L39_0025F740) + 0x18))) + 0x10));
                            func_003C4098(&sp60, (s32 *) &sp50, &sp70, 0x3F000000);
                            func_L39_0055AF88(&sp60, 5);
                            (*(s32 *)((u8 *)(temp_20) + 0x6C)) = 0x19;
                            (*(s16 *)((u8 *)(temp_2) + 0x107E)) = 1;
                            func_L39_005F33E0(func_L01_00337EA8(), 0, arg0);
                        }
                    }
                }
            }
        }
    } else {
        func_003C2880(arg0);
    }
}
