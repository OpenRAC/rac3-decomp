/* func_L09_003B8580: Opus handoff (prep by Sonnet worker w7, 2026-11-08)
   Size: 13784 bytes, places: 1 levels (09), file: src/levels/09_tyhrranosis/L09_003B8580.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: one function (addiu sp,-0x120, one epilogue .L003BBB10, ~330 calls), 3 switches / 3 jump tables (14 entries listed): switch(+0x95) 10 cases (jtbl_002BF660), switch(+0x20 - 2) 22 cases (jtbl_002BF690), switch(+0xBC - 1) 14 cases (jtbl_002BF6F0); previous attempt notes in rac3-api/jobs/func_L09_003B8580/RESULTS.md.
   Twin: none (rac2 index best func_L04_0044DB18 at 0.18). Checked: callee fingerprint (callfp: 0 callees mapped); whole-corpus opcode search over every rac3 and rac2 function >= 600 B (best rac3:func_L01_00350750 0.16); names.tsv/NAMES.md (no entry); matched rac3 siblings in src/ (only the scaffold is shared).
   Mapping: Common enemy/boss scaffold (matches the tools' names): arg0 = moby; +0x20 = state byte (func_L01_004450F0 = moby_set_state(moby, state, sub)), +0x95 = phase byte, +0x68 = per-object data, func_L01_004561B8 = animation-done test, func_003C3A10 = moby_anim_blend(moby, anim, 0, 8), func_0038CB00 = timer_tick_short, D_1A4BE0 = hero/global struct (+0x25C0 hero moby, +0x25C4 hero state, +0xC08 pad bits). $gp loads are named D_<0x1DC8B0+offset> (D_LNN_ when >= 0x1D9900) in the draft. Tyhrranosis boss: s5 = D_L09_001E009C[0] + (v->fCD0 << 8); v = +0x68 (boss state); func_L09_003BBF10(s) pre-check returns early; func_L09_003BF0E0(&t[0], &t[1], 1) takes stack pairs; func_0038CB00(&v->hD30) timer test.
   Identical / changed / added / removed: n/a (no twin). Tail (retail .L003BBA90): f1 = v->f30 <= 0 -> hero-hp check then func_L09_003BC288; func_003C7C38(s); bD41==1 -> s->f8 += v->fC30 * 0.5f.
   VU0: 9 vadd.xyz/vsub.xyz ops in the retail asm; inline-asm VU0 is banned since 2026-11-06 (Matching-Patterns), so this function cannot reach MATCH unless the ops come from plain C; the lq/sq copies are fine (u128_t).
   Draft: compiles (m2c draft cleaned by tools/post.py (real repo prototypes where known, m2c gotos kept)); 3365 diff; opcode-equal 846 of 3447 (mine 2986), ratio 0.26.
     Retail rows yours=2986 retail=3447 equalrows=82.
   Left for Opus:
     1. Biggest uncertainty is the case index order of the three tables (the m2c switch recovers it now: check jtbl_002BF660/690/6F0 target addresses against the m2c case numbers).
     2. ~68 m2c gotos remain; many are the per-case common tail .L003B9770 (v->bD42 handling) and .L003BAF6C.
     3. Argument lists of func_L09_003BEB30/BEC20/BED10/BF038/BF0E0 are inferred from the stack pairs (t at 0x70/0x74, 0x78/0x7C, ...).
     4. 9 VU0 ops: near miss only.
*/
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CF38();
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern int func_L01_004561B8(u8 *);
extern int func_L01_004561E0(void *a0);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_00382468();
extern s32 func_00382498(s32, s32);
extern s32 func_0038CB00(void *);
extern s32 func_0039EF28();
extern s32 func_003A52A0();
extern s32 func_L01_0041A5B0(s32, s32);
extern s32 func_L01_0045A9F0(void *);
extern s32 func_L01_0045BE38(void *a0, s32 a1);
extern void func_003A4F28(u32);
extern void func_003C2880(s32 p);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C3FC0(void *, void *);
extern void func_003C7C38();
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_0045BD78(u8 *a0, f32 a, f32 b, f32 c, f32 d);
extern void func_L01_0045C150(void *, void *, s32, s32);
extern void func_L01_004AA760(s32, s32);
extern void func_L01_004AA7E8(s32, s32);
extern void func_L01_004F50C8(u8 *, u8 *, s32, s32);
extern void func_L01_00511AE8(void);
extern void func_L02_003A0200();
s32 func_003C4098(void *, f32 *, f32 *, f32, f32); /* extern */
s32 func_L01_003EC9E0(s32);                     /* extern */
s32 func_L01_003ECA10(s32);                         /* extern */
f32 func_L01_004395E0(void *);                      /* extern */
s32 func_L01_004450F0(void *, u8, s32);     /* extern */
s32 func_L01_00445170(void *, s32);         /* extern */
s32 func_L01_00445188(void *, s32);         /* extern */
s32 func_L01_00448890(f32 *, void *, s32, f32, s32, s32, s32); /* extern */
s32 func_L01_0044E1B8(void *, s32);             /* extern */
s32 func_L01_00454370(void *, void *);              /* extern */
s32 func_L01_00456208(void *);                      /* extern */
s32 func_L01_00456500(f32 *, s32);                  /* extern */
s32 func_L01_0045A748(void *, f32 *);               /* extern */
s32 func_L01_00511A40(void *, s32, f32);    /* extern */
s32 func_L02_003A02D8(s32, s32);            /* extern */
s32 func_L02_003C5DC0(s32);                     /* extern */
s32 func_L08_003D0D08();  /* extern, call arities [1, 2], m2c proto was (s32, s32) */
s32 func_L09_003BBF10();                            /* extern */
s32 func_L09_003BC288(void *);                  /* extern */
s32 func_L09_003BC450(void *, void *, s32, s32 *, s32); /* extern */
s32 func_L09_003BD860(void *);                      /* extern */
s32 func_L09_003BDB90(void *, void *, s32, s32 *); /* extern */
s32 func_L09_003BDED0(void *);                  /* extern */
s32 func_L09_003BE168(void *);                  /* extern */
s32 func_L09_003BE228(void *);                  /* extern */
s32 func_L09_003BE330(void *, f32 *);               /* extern */
s32 func_L09_003BE450(void *);                      /* extern */
s32 func_L09_003BE5D0(void *, s32, s32, s32, s32); /* extern */
s32 func_L09_003BE910(void *, s32, s32);    /* extern */
s32 func_L09_003BEB30(void *, void *, s32, s32 *); /* extern */
s32 func_L09_003BEC20(void *, void *, s32, s32 *, s32); /* extern */
s32 func_L09_003BED10(void *);                      /* extern */
s32 func_L09_003BF038(void *, void *, s32, s32 *, s32); /* extern */
s32 func_L09_003BF0E0(void *, void *, s32, s32 *, f32 *, f32 *, s32); /* extern */
s32 func_L09_003BF3E0(void *);                  /* extern */
s32 func_L09_003BF5F0(void *, s32 *);       /* extern */
s32 func_L09_003BF890(void *);                  /* extern */
s32 func_L09_003BF9B8(void *);                      /* extern */
s32 func_L09_003BFA48(void *);                  /* extern */
s32 func_L09_003BFC90(void *, s32, f32, f32); /* extern */
s32 func_L09_003CD998(s32, s32);            /* extern */
s32 func_L09_003CD9F0(s32);                     /* extern */
s32 func_L09_003CDA30(s32);                     /* extern */
s32 func_L09_00403E40(s32, s32);        /* extern */
extern s32 D_142660;
extern s32 D_1426E0;
extern s32 D_1A4BE0;
extern f32 D_1A4C60;
extern s32 D_1A7E18;
extern f32 D_L09_001D66B0;
extern s32 D_L09_001E009C;
extern s32 D_L09_001E00D8;
extern s32 D_L09_001E0180;
extern s32 D_L09_001E2B80;
extern s32 D_L09_0021CDA0;
extern s32 D_L09_0021E640;
extern s32 D_L09_002BB230;
extern s32 D_L09_002BB280;

extern s32 D_L09_001DE6A0;
extern f32 D_L09_001DE6B0;  /* also s32 */
extern s32 D_L09_001DE6D0;
extern f32 D_L09_001DE6E0;
extern f32 D_L09_001DE6E4;
extern f32 D_L09_001DE6E8;
extern f32 D_L09_001DE6EC;
extern s32 D_L09_001E009C;
extern s32 D_L09_001E00D8;

void func_L09_003B8580(void *arg0) {
    s32 sp[8]; /* m2c: stack-slot base, size unknown */
    f32 sp0;
    f32 sp4;
    f32 sp8;
    s32 spC;
    f32 sp10;
    f32 sp20;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp3C;
    f32 sp40;
    f32 sp44;
    s32 sp48;
    f32 sp50;
    f32 sp54;
    f32 sp58;
    f32 sp5C;
    f32 sp60;
    f32 sp64;
    s32 sp68;
    f32 sp70;
    f32 sp74;
    f32 sp78;
    f32 sp7C;
    f32 sp80;
    f32 sp84;
    s32 *var_7;
    s32 var_5_2;
    s32 var_5_7;
    s32 var_6;
    s32 var_8;
    f32 *var_3;
    f32 *var_3_2;
    f32 *var_5_3;
    f32 *var_5_4;
    f32 *var_5_5;
    f32 *var_5_6;
    f32 temp_7;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f20_6;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f21_3;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f2;
    f32 var_f23;
    f32 var_f23_2;
    s16 temp_3_10;
    s16 temp_3_11;
    s16 temp_3_12;
    s16 temp_3_13;
    s16 temp_3_14;
    s16 temp_3_15;
    s16 temp_4_9;
    s16 temp_6_2;
    s32 *temp_4_7;
    s32 *temp_5_4;
    s32 temp_16_3;
    s32 temp_16_7;
    s32 temp_16_8;
    s32 temp_2_2;
    s32 temp_2_6;
    s32 temp_2_7;
    s32 temp_3;
    s32 temp_3_4;
    s32 temp_4;
    s32 temp_4_10;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 temp_4_5;
    s32 temp_4_8;
    s32 temp_5_2;
    s32 temp_6;
    s32 var_16_2;
    s32 var_16_3;
    s32 var_16_4;
    s32 var_16_5;
    s32 var_2;
    s32 var_2_2;
    s32 var_4;
    s32 var_6_3;
    s32 var_7_2;
    s8 var_2_3;
    s8 var_2_4;
    u16 *var_17;
    u16 temp_3_6;
    u16 temp_3_7;
    u32 temp_2_5;
    u32 temp_3_3;
    u8 temp_2;
    u8 temp_2_11;
    u8 temp_2_13;
    u8 temp_2_15;
    u8 temp_2_17;
    u8 temp_2_19;
    u8 temp_2_4;
    u8 temp_2_8;
    u8 temp_2_9;
    u8 temp_3_2;
    u8 temp_3_8;
    u8 temp_3_9;
    u8 temp_5;
    u8 var_5;
    u8 var_5_10;
    u8 var_5_11;
    u8 var_5_12;
    u8 var_5_13;
    u8 var_5_14;
    u8 var_5_8;
    u8 var_5_9;
    u8 *temp_16;
    u8 *temp_16_10;
    u8 *temp_16_11;
    u8 *temp_16_12;
    u8 *temp_16_2;
    u8 *temp_16_4;
    u8 *temp_16_5;
    u8 *temp_16_6;
    u8 *temp_16_9;
    u8 *temp_18;
    u8 *temp_21;
    u8 *temp_2_10;
    u8 *temp_2_12;
    u8 *temp_2_14;
    u8 *temp_2_16;
    u8 *temp_2_18;
    u8 *temp_2_20;
    u8 *temp_2_3;
    u8 *temp_3_5;
    u8 *temp_4_6;
    u8 *temp_5_3;
    u8 *var_16;
    u8 *var_17_2;
    u8 *var_17_3;
    u8 *var_17_4;
    u8 *var_6_2;

    if (func_L09_003BBF10() == 0) {
        temp_18 = (*(void **)((u8 *)(arg0) + 0x68));
        temp_5 = (*(u8 *)((u8 *)(arg0) + 0x95));
        temp_21 = D_L09_001E009C + ((*(s32 *)((u8 *)(temp_18) + 0xCD0)) << 8);
        switch (temp_5) {                           /* switch 1 */
        case 0:                                     /* switch 1 */
            if (func_L01_004561E0(arg0) != 0) {
                var_16 = *(((*(s32 *)((u8 *)(temp_18) + 0xD28)) * 4) + &D_L09_0021CDA0);
loop_8:
                temp_4 = (*(s32 *)((u8 *)(temp_18) + 0xD28));
                if (((temp_4 & 0xFF) != 0xFF) && (D_L09_001E00D8 >= temp_4) && (var_16 != 0)) {
                    if ((*(s16 *)((u8 *)(var_16) + -2)) >= 0) {
                        goto block_6;
                    }
                    if (var_16 == *((temp_4 * 4) + &D_L09_0021CDA0)) {
block_6:
                        temp_4_2 = D_L09_001E009C + (((*(u16 *)((u8 *)(var_16) + 0)) & 0x7FFF) << 8);
                        if (temp_4_2 != 0) {
                            var_16 += 2;
                            func_L02_003A02D8(temp_4_2, 0);
                            goto loop_8;
                        }
                    }
                }
                (*(f32 *)((u8 *)(temp_18) + 0x12C)) = 1.5f;
                (*(f32 *)((u8 *)(arg0) + 0x18)) = 340.0f;
                func_L09_003CD998(D_L09_001E009C + ((*(s32 *)((u8 *)(temp_18) + 0xCF0)) << 8), 1);
                func_L09_003CD998(D_L09_001E009C + ((*(s32 *)((u8 *)(temp_18) + 0xCE8)) << 8), 1);
                (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x41);
                temp_6 = (*(s32 *)((u8 *)(temp_18) + 0xD20));
                var_17 = *((temp_6 * 4) + &D_L09_0021CDA0);
                if ((temp_6 & 0xFF) != 0xFF) {
                    if (D_L09_001E00D8 >= temp_6) {
                        if (var_17 != 0) {
loop_20:
                            temp_16 = D_L09_001E009C + ((*var_17 & 0x7FFF) << 8);
                            if ((temp_16 != 0) && ((*(s32 *)((u8 *)(temp_16) + 0x98)) = 0, var_17 += 2, (*(u16 *)((u8 *)(temp_16) + 0x34)) = (u16) (((*(u16 *)((u8 *)(temp_16) + 0x34)) | 0x41) & 0xEFFF), func_L01_004AA7E8(temp_16, 1), (*(u16 *)((u8 *)(temp_16) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_16) + 0x34)) | 2), temp_3 = (*(s32 *)((u8 *)(temp_18) + 0xD20)), ((temp_3 & 0xFF) != 0xFF))) {
                                if (D_L09_001E00D8 >= temp_3) {
                                    if (var_17 != 0) {
                                        if (((*(s16 *)((u8 *)(var_17) + -2)) < 0) && (var_17 != *((temp_3 * 4) + &D_L09_0021CDA0))) {

                                        } else {
                                            goto loop_20;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                var_5 = 2;
                var_6 = -1;
                (*(s32 *)((u8 *)(&D_1A4BE0) + 0x2850)) = (s32) (*(s32 *)((u8 *)(&D_142660) + 8));
block_102:
                func_L01_004450F0(arg0, var_5, var_6);
                func_L01_00445188(arg0, 0);
            }
        default:                                    /* switch 1 */
block_239:
            (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 0xF9);
            temp_3_2 = (*(u8 *)((u8 *)(arg0) + 0x20));
            switch (temp_3_2) {                     /* switch 2 */
            case 2:                                 /* switch 2 */
                temp_5_2 = (*(s32 *)((u8 *)(temp_18) + 0xCD4));
                if ((temp_5_2 != -1) && (func_L01_00456500(&D_1A4C60, temp_5_2) != 0)) {
                    if ((*(u8 *)((u8 *)(&D_1426E0) + 0x3C)) & 1) {
                        func_L01_003EC9E0((*(s32 *)((u8 *)(temp_18) + 0xCF4)));
                        func_L01_004450F0(arg0, 3U, -1);
                        var_16_2 = 0;
                    } else {
                        func_L02_003C5DC0((*(s32 *)((u8 *)(temp_18) + 0xCF8)));
                        func_L01_003EC9E0((*(s32 *)((u8 *)(temp_18) + 0xCF8)));
                        func_L01_004450F0(arg0, 4U, -1);
                        var_16_2 = 0;
                    }
                    var_2 = 0U < 8U;
loop_247:
                    if ((var_2 != 0) && (((s32) (*(u8 *)((u8 *)(&D_1426E0) + 0x3C)) >> var_16_2) & 1)) {
                        (*(u8 *)((u8 *)(&D_1426E0) + 0x3C)) = (u8) ((*(u8 *)((u8 *)(&D_1426E0) + 0x3C)) & ~(1 << var_16_2));
                        func_0039EF28();
                        temp_3_3 = var_16_2 + 1;
                        if (temp_3_3 < 8U) {
                            (*(u8 *)((u8 *)(&D_1426E0) + 0x3C)) = (u8) ((*(u8 *)((u8 *)(&D_1426E0) + 0x3C)) | (1 << temp_3_3));
                        }
                        func_0039EF28();
                    } else {
                        var_16_2 += 1;
                        var_2 = (u32) var_16_2 < 8U;
                        if (var_16_2 >= 7) {

                        } else {
                            goto loop_247;
                        }
                    }
                }
                break;
            case 3:                                 /* switch 2 */
                if ((((*(u8 *)((u8 *)(arg0) + 0xBE)) ^ 1) & 1) && (func_L08_003D0D08((*(s32 *)((u8 *)(temp_18) + 0xCF4))) != 0)) {
                    temp_4_3 = D_L09_001E0180 + ((*(s32 *)((u8 *)(temp_18) + 0xCFC)) << 7);
                    func_L01_004F50C8(temp_4_3 + 0x30, temp_4_3 + 0x70, 0x74, 0);
                    func_003A52A0();
                    func_L01_004561B8(arg0);
                } else if (func_L01_003ECA10((*(s32 *)((u8 *)(temp_18) + 0xCF4))) != 0) {
                    func_L09_003CD9F0(D_L09_001E009C + ((*(s32 *)((u8 *)(temp_18) + 0xCF0)) << 8));
                    func_L09_003CD9F0(D_L09_001E009C + ((*(s32 *)((u8 *)(temp_18) + 0xCE8)) << 8));
                    (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x34)) & 0xFFBE);
                    func_L01_004AA760(8, arg0);
                    if ((*(void **)((u8 *)(&D_L09_001E2B80) + 0x144)) == 0) {
                        (*(s32 *)((u8 *)(&D_L09_001E2B80) + 0x148)) = 0;
                        (*(void **)((u8 *)(&D_L09_001E2B80) + 0x144)) = arg0;
                    }
block_264:
                    func_L01_004450F0(arg0, 1U, 1);
                    func_L01_00445188(arg0, 0);
                }
                break;
            case 4:                                 /* switch 2 */
                if (func_L08_003D0D08((*(s32 *)((u8 *)(temp_18) + 0xCF8))) != 0) {
                    func_L09_003CD9F0(D_L09_001E009C + ((*(s32 *)((u8 *)(temp_18) + 0xCF0)) << 8));
                    func_L09_003CD9F0(D_L09_001E009C + ((*(s32 *)((u8 *)(temp_18) + 0xCE8)) << 8));
                    (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x34)) & 0xFFBE);
                    if ((*(void **)((u8 *)(&D_L09_001E2B80) + 0x144)) == 0) {
                        (*(s32 *)((u8 *)(&D_L09_001E2B80) + 0x148)) = 0;
                        (*(void **)((u8 *)(&D_L09_001E2B80) + 0x144)) = arg0;
                    }
                    temp_4_4 = D_L09_001E0180 + ((*(s32 *)((u8 *)(temp_18) + 0xCFC)) << 7);
                    func_L01_004F50C8(temp_4_4 + 0x30, temp_4_4 + 0x70, 0x74, 0);
                    goto block_264;
                }
                break;
            case 5:                                 /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 0xFE);
                    func_L02_003C5DC0((*(s32 *)((u8 *)(temp_18) + 0xD00)));
                    func_L01_003EC9E0((*(s32 *)((u8 *)(temp_18) + 0xD00)));
                    (*(s16 *)((u8 *)(temp_18) + 0xD36)) = 0x32;
                    (*(s32 *)((u8 *)(temp_18) + 0xD4C)) = 0x3F000000;
                } else if (func_0038CB00(temp_18 + 0xD36) != 0) {
                    func_L09_003CD998(D_L09_001E009C + ((*(s32 *)((u8 *)(temp_18) + 0xCE8)) << 8), 0);
                    func_L09_003CD998(D_L09_001E009C + ((*(s32 *)((u8 *)(temp_18) + 0xCEC)) << 8), 0);
                } else if ((((*(u8 *)((u8 *)(temp_18) + 0xD42)) ^ 1) & 1) && (func_L08_003D0D08((*(s32 *)((u8 *)(temp_18) + 0xD00)), 0) != 0)) {
                    func_L01_004AA7E8(arg0, 1);
                    temp_3_4 = D_L09_001E0180 + ((*(s32 *)((u8 *)(temp_18) + 0xD0C)) << 7);
                    func_L01_004F50C8(temp_3_4 + 0x30, temp_3_4 + 0x70, 0x74, 0);
                    temp_3_5 = D_L09_001E0180 + ((*(s32 *)((u8 *)(temp_18) + 0xD10)) << 7);
                    (*(f32 *)((u8 *)(arg0) + 0x10)) = (f32) (*(f32 *)((u8 *)(temp_3_5) + 0x30));
                    (*(s32 *)((u8 *)(arg0) + 0xF0)) = (s32) (*(s32 *)((u8 *)(temp_3_5) + 0x70));
                    func_003C3A10(arg0, 8, 0, 0);
                    (*(u8 *)((u8 *)(temp_18) + 0xD41)) = 0U;
                    (*(f32 *)((u8 *)(temp_18) + 0xC30)) = 0.0f;
                    (*(u8 *)((u8 *)(temp_18) + 0xD40)) = 1U;
                    func_003C3FC0(temp_18 + 0xC50, &D_L09_001D66B0);
                    var_6_2 = *(((*(s32 *)((u8 *)(temp_18) + 0xD20)) * 4) + &D_L09_0021CDA0);
loop_275:
                    temp_4_5 = (*(s32 *)((u8 *)(temp_18) + 0xD20));
                    if (((temp_4_5 & 0xFF) != 0xFF) && (D_L09_001E00D8 >= temp_4_5) && (var_6_2 != 0)) {
                        if ((*(s16 *)((u8 *)(var_6_2) + -2)) >= 0) {
                            goto block_273;
                        }
                        if (var_6_2 == *((temp_4_5 * 4) + &D_L09_0021CDA0)) {
block_273:
                            temp_5_3 = D_L09_001E009C + (((*(u16 *)((u8 *)(var_6_2) + 0)) & 0x7FFF) << 8);
                            var_6_2 += 2;
                            if (temp_5_3 != 0) {
                                temp_4_6 = (*(void **)((u8 *)(temp_5_3) + 0x24));
                                temp_3_6 = (*(u16 *)((u8 *)(temp_5_3) + 0x34)) & 0xFFBE;
                                (*(u16 *)((u8 *)(temp_5_3) + 0x34)) = temp_3_6;
                                temp_3_7 = temp_3_6 | ((*(u16 *)((u8 *)(temp_4_6) + 0x44)) & 0x1000);
                                (*(u16 *)((u8 *)(temp_5_3) + 0x34)) = temp_3_7;
                                (*(u16 *)((u8 *)(temp_5_3) + 0x34)) = (u16) (temp_3_7 & 0xFFFD);
                                (*(s32 *)((u8 *)(temp_5_3) + 0x98)) = (s32) (*(s32 *)((u8 *)(temp_4_6) + 0x10));
                                goto loop_275;
                            }
                        }
                    }
block_315:
                    (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) | 1);
                }
                break;
            case 6:                                 /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    func_003C3A10(arg0, 8, 0, 0);
                } else if ((*(u8 *)((u8 *)(arg0) + 0xBC)) == 1) {
                    (*(f32 *)((u8 *)(temp_18) + 0xBE8)) = 1.5707964f;
                    if (func_0038CB00(temp_18 + 0xD36) != 0) {
                        (*(s16 *)((u8 *)(temp_18) + 0xD36)) = 0x96;
                        func_L01_00445188(arg0, 0xB);
                    }
                }
                break;
            case 7:                                 /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_21) + 0xF8)) = 0;
                    func_L01_00511A40(&D_L09_001DE6D0, 0, -3.1400917f);
                    (*(f32 *)((u8 *)(temp_18) + 0xC30)) = 0.0f;
                    func_003C3FC0(temp_18 + 0xC50, &D_L09_001D66B0);
                    (*(s16 *)((u8 *)(temp_18) + 0xD34)) = 0x166;
                    (*(s16 *)((u8 *)(temp_18) + 0xD36)) = 0x11;
                    (*(s16 *)((u8 *)(temp_18) + 0xD30)) = 0x34;
                    (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) | 1);
                }
                func_L09_003BE5D0(arg0, 0, 0, 0, 1);
                *(s32 *)0x1A4E18 = 3;
                break;
            case 8:                                 /* switch 2 */
                temp_2 = (*(u8 *)((u8 *)(temp_18) + 0xD42));
                if (func_L01_004561B8(arg0) != 0) {
                    (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) (temp_2 & 0xFE);
                    func_L02_003C5DC0((*(s32 *)((u8 *)(temp_18) + 0xD18)));
                    func_L01_003EC9E0((*(s32 *)((u8 *)(temp_18) + 0xD18)));
                } else {
                    if (!((temp_2 ^ 1) & 1)) {
                        goto block_316;
                    }
                    if (func_L08_003D0D08((*(s32 *)((u8 *)(temp_18) + 0xD18))) == 0) {
block_316:
                        if (((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 1) && ((*(u8 *)((u8 *)(arg0) + 0xBC)) == 1)) {
                            (*(f32 *)((u8 *)(temp_18) + 0xBE8)) = 0.43633232f;
                            sp0 = D_L09_001D66B0;
                            sp4 = -0.017453292f;
                            sp0 = (*(f32 *)((u8 *)(temp_18) + 0xCDC));
                            temp_f20 = func_0038DB00((*(f32 *)((u8 *)(arg0) + 0xF8)), 1.701696f);
                            func_L01_00448890(sp, temp_18 + 0xCD8, 0, func_0038DB00(func_0038D160((*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(temp_21) + 0x10)), (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)) - (*(f32 *)((u8 *)(temp_21) + 0x14))), temp_f20), 0x3BA4B5BF, 0x3BA4B5BF, 0x3F00ADFD);
                            (*(f32 *)((u8 *)(temp_18) + 0xCDC)) = sp0;
                            func_003C3FC0(temp_18 + 0xC50, sp);
                            (*(s32 *)((u8 *)(&D_1A4BE0) + 0x238)) = 3;
                            if (func_0038CB00(temp_18 + 0xD34) != 0) {
                                func_L01_00445188(arg0, 0xC);
                            }
                        }
                    } else {
                        (*(s32 *)((u8 *)(temp_21) + 0xF8)) = 0;
                        func_L09_003CD9F0(D_L09_001E009C + ((*(s32 *)((u8 *)(temp_18) + 0xCEC)) << 8));
                        temp_2_2 = D_L09_001E0180 + ((*(s32 *)((u8 *)(temp_18) + 0xD14)) << 7);
                        func_L01_004F50C8(temp_2_2 + 0x30, temp_2_2 + 0x70, 0, 0);
                        temp_2_3 = D_L09_001E0180 + ((*(s32 *)((u8 *)(temp_18) + 0xD1C)) << 7);
                        func_L01_00511A40(temp_2_3 + 0x30, 0, (*(f32 *)((u8 *)(temp_2_3) + 0x78)));
                        temp_4_7 = *(((*(s32 *)((u8 *)(temp_18) + 0xC98)) * 4) + &D_L09_0021E640);
                        (*(f32 *)((u8 *)(arg0) + 0xF8)) = 4.712389f;
                        (*(f32 *)((u8 *)(arg0) + 0x10)) = (f32) *((*temp_4_7 * 0x10) + temp_4_7);
                        (*(s16 *)((u8 *)(temp_18) + 0xD34)) = 0x25;
                        (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x34)) & 0xFFBE);
                        (*(s8 *)((u8 *)(temp_18) + 0xD2C)) = 1;
                        (*(f32 *)((u8 *)(temp_18) + 0xCDC)) = 0.0f;
                        var_17_2 = *(((*(s32 *)((u8 *)(temp_18) + 0xD20)) * 4) + &D_L09_0021CDA0);
loop_305:
                        temp_4_8 = (*(s32 *)((u8 *)(temp_18) + 0xD20));
                        if (((temp_4_8 & 0xFF) != 0xFF) && (D_L09_001E00D8 >= temp_4_8) && (var_17_2 != 0)) {
                            if ((*(s16 *)((u8 *)(var_17_2) + -2)) >= 0) {
                                goto block_303;
                            }
                            if (var_17_2 == *((temp_4_8 * 4) + &D_L09_0021CDA0)) {
block_303:
                                temp_16_2 = D_L09_001E009C + (((*(u16 *)((u8 *)(var_17_2) + 0)) & 0x7FFF) << 8);
                                if (temp_16_2 != 0) {
                                    (*(s32 *)((u8 *)(temp_16_2) + 0x98)) = 0;
                                    var_17_2 += 2;
                                    (*(u16 *)((u8 *)(temp_16_2) + 0x34)) = (u16) (((*(u16 *)((u8 *)(temp_16_2) + 0x34)) | 0x41) & 0xEFFF);
                                    func_L01_004AA7E8(temp_16_2, 1);
                                    (*(u16 *)((u8 *)(temp_16_2) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_16_2) + 0x34)) | 2);
                                    goto loop_305;
                                }
                            }
                        }
                        (*(s32 **)((u8 *)(temp_18) + 0x254)) = 0;
                        func_003C3A10(arg0, 8, 0, 0);
                        (*(f32 *)((u8 *)(temp_18) + 0xC30)) = 0.0f;
                        func_003C3FC0(temp_18 + 0xC50, &D_L09_001D66B0);
                        goto block_315;
                    }
                }
                break;
            case 9:                                 /* switch 2 */
                if ((func_L01_004561B8(arg0) != 0) || ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                    func_003C3A10(arg0, 0, 0, 8);
                    (*(f32 *)((u8 *)(arg0) + 0x48)) = 1.0f;
block_441:
                    var_2_2 = (*(u8 *)((u8 *)(arg0) + 0x60)) & 2;
block_442:
                    if (var_2_2 != 0) {
block_443:
                        (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) | 2);
                    }
                }
                break;
            case 10:                                /* switch 2 */
                if ((func_L01_004561B8(arg0) != 0) || ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                    func_003C3A10(arg0, 8, 0, 8);
                    (*(f32 *)((u8 *)(arg0) + 0x48)) = 0.5f;
                    goto block_441;
                }
                break;
            case 11:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    func_003C3A10(arg0, 1, 0, 8);
                    (*(f32 *)((u8 *)(arg0) + 0x48)) = 1.0f;
                }
                func_L01_0045A9F0(arg0);
                if (func_L01_0044E1B8(arg0, 0x414D5555) != 0) {
                    func_003A52A0();
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    func_L01_004AA760(1, arg0);
                    (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) | 2);
                }
                /* fallthrough */
            case 12:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    func_003C3A10(arg0, 1, 0, 8);
                    (*(f32 *)((u8 *)(arg0) + 0x48)) = 1.0f;
                }
                temp_3_8 = (*(u8 *)((u8 *)(arg0) + 0x43));
                if (temp_3_8 == 1) {
                    func_L01_0045A9F0(arg0);
                    if (func_L01_0044E1B8(arg0, 0x414D5555) != 0) {
                        func_003A52A0();
                    }
                    if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                        (*(s32 *)((u8 *)(temp_18) + 0x1C8)) = (s32) ((*(s32 *)((u8 *)(temp_18) + 0x1C8)) & ~0x404);
                        func_L01_004AA760(1, arg0);
                        var_5_2 = 0xA;
block_353:
                        func_003C3A10(arg0, var_5_2, 0, 8);
                        (*(f32 *)((u8 *)(arg0) + 0x48)) = 1.0f;
                    }
                } else if (temp_3_8 == 0xA) {
                    temp_f0 = func_L01_004395E0(arg0);
                    if ((temp_f0 >= 14.0f) && (temp_f0 <= 22.0f)) {
                        (*(f32 *)((u8 *)(arg0) + 0x18)) = (f32) ((*(f32 *)((u8 *)(arg0) + 0x18)) + 0.6f);
                    }
                    if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                        func_003C3A10(arg0, 8, 0, 0);
                        (*(f32 *)((u8 *)(arg0) + 0x18)) = 340.0f;
                        goto block_443;
                    }
                }
                break;
            case 13:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_18) + 0x1C8)) = (s32) ((*(s32 *)((u8 *)(temp_18) + 0x1C8)) & ~0x404);
                    (*(f32 *)((u8 *)(arg0) + 0x18)) = 340.0f;
                    func_003C3A10(arg0, 6, 0, 8);
                    (*(f32 *)((u8 *)(arg0) + 0x48)) = 1.0f;
                }
                temp_3_9 = (*(u8 *)((u8 *)(arg0) + 0x43));
                if (temp_3_9 == 6) {
                    temp_f0_2 = func_L01_004395E0(arg0);
                    if ((temp_f0_2 >= 9.0f) && (temp_f0_2 <= 17.0f)) {
                        (*(f32 *)((u8 *)(arg0) + 0x18)) = (f32) ((*(f32 *)((u8 *)(arg0) + 0x18)) - 0.6f);
                    }
                    func_L09_003BFA48(arg0);
                    func_L09_003BE228(arg0);
                    if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                        var_5_2 = 1;
                        goto block_353;
                    }
                } else if (temp_3_9 == 1) {
                    func_L01_0045A9F0(arg0);
                    if (func_L01_0044E1B8(arg0, 0x414D5555) != 0) {
                        func_003A52A0();
                    }
                    if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                        func_L01_004AA760(1, arg0);
                        goto block_443;
                    }
                }
                break;
            case 14:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_18) + 0x1C8)) = (s32) ((*(s32 *)((u8 *)(temp_18) + 0x1C8)) & ~0x404);
                    func_L01_0045BD78(arg0, 0.00700000022f, 0.110000007f, 0.00502654864f, 0.0418879054f);
                    (*(f32 *)((u8 *)(temp_18) + 0x1B4)) = 1.0f;
                    func_003C3A10(arg0, 2, 0, 8);
                    (*(f32 *)((u8 *)(arg0) + 0x48)) = 1.0f;
                }
                func_L09_003BE168(arg0);
                func_L09_003BFC90(arg0, 0, D_L09_001DE6E4, D_L09_001DE6E0);
block_372:
                (*(f32 *)((u8 *)(temp_18) + 0x1C4)) = 4.0f;
                if (func_L01_0045BE38(arg0, (*(s32 **)((u8 *)(temp_18) + 0x254))) != 0) {
                    (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) | 2);
                }
                (*(f32 *)((u8 *)(temp_18) + 0x1C4)) = 1.0f;
                break;
            case 15:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_18) + 0x1C8)) = (s32) ((*(s32 *)((u8 *)(temp_18) + 0x1C8)) & ~0x404);
                    func_L01_0045BD78(arg0, 0.0144000007f, 0.24000001f, 0.0100530973f, 0.0837758109f);
                    (*(f32 *)((u8 *)(temp_18) + 0x1B4)) = 1.0f;
                    func_003C3A10(arg0, 3, 0, 8);
                    (*(f32 *)((u8 *)(arg0) + 0x48)) = 1.0f;
                }
                func_L09_003BE168(arg0);
                func_L09_003BFC90(arg0, 1, D_L09_001DE6EC, D_L09_001DE6E8);
                goto block_372;
            case 16:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_18) + 0x1C8)) = (s32) ((*(s32 *)((u8 *)(temp_18) + 0x1C8)) | 0x404);
                    func_L01_0045BD78(arg0, 0.0216000006f, 0.360000014f, 0.00502654864f, 0.0418879054f);
                    (*(f32 *)((u8 *)(temp_18) + 0x1B4)) = 1.0f;
                    func_003C3A10(arg0, 7, 0, 8);
                    (*(f32 *)((u8 *)(arg0) + 0x48)) = 1.0f;
                }
                goto block_372;
            case 17:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_18) + 0x1C8)) = (s32) ((*(s32 *)((u8 *)(temp_18) + 0x1C8)) | 0x404);
                    func_L01_0045BD78(arg0, 0.0216000006f, 0.360000014f, 0.00502654864f, 0.0418879054f);
                    (*(f32 *)((u8 *)(temp_18) + 0x1B4)) = 1.0f;
                    func_003C3A10(arg0, 7, 0, 8);
                    (*(f32 *)((u8 *)(arg0) + 0x48)) = 1.0f;
                }
                if ((*(s32 **)((u8 *)(temp_18) + 0x254)) != 0) {
                    goto block_372;
                }
                if ((*(u8 *)((u8 *)(temp_18) + 0xD41)) != 2) {
                    sp0 = (*(f32 *)((u8 *)(temp_18) + 0xCC8));
                    sp8 = 340.0f;
                    sp4 = (*(f32 *)((u8 *)(temp_18) + 0xCCC));
                    spC = 0;
                    var_2_2 = func_L01_0045A748(arg0, sp);
                    goto block_442;
                }
                break;
            case 18:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_18) + 0x1C8)) = (s32) ((*(s32 *)((u8 *)(temp_18) + 0x1C8)) | 0x404);
                    func_L01_0045BD78(arg0, 0.0216000006f, 0.360000014f, 0.00502654864f, 0.0418879054f);
                    (*(f32 *)((u8 *)(temp_18) + 0x1B4)) = 1.0f;
                    func_003C3A10(arg0, 7, 0, 8);
                    (*(f32 *)((u8 *)(arg0) + 0x48)) = 1.0f;
                    (*(f32 *)((u8 *)(temp_18) + 0xCC8)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x10));
                    (*(f32 *)((u8 *)(temp_18) + 0xCCC)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x14));
                }
                sp0 = (*(f32 *)((u8 *)(temp_18) + 0xCC8));
                sp8 = 340.0f;
                sp4 = (*(f32 *)((u8 *)(temp_18) + 0xCCC));
                spC = 0;
                if (func_0038CF38() < (*(f32 *)((u8 *)(temp_18) + 0x1C4))) {
                    temp_f20_2 = func_00382538();
                    temp_f21 = func_003824E0(5.0f, 10.0f);
                    sp0 = func_0038D098(temp_f20_2) * temp_f21;
                    sp4 = func_0038D0B0(temp_f20_2) * temp_f21;
                    0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                    if (func_L01_00456500(sp, (*(s32 *)((u8 *)(temp_18) + 0xD54))) == 0) {
                        sp0 = D_L09_001DE6B0;
                    }
                    (*(f32 *)((u8 *)(temp_18) + 0xCC8)) = sp0;
                    (*(f32 *)((u8 *)(temp_18) + 0xCCC)) = sp4;
                }
                func_L01_0045A748(arg0, sp);
                break;
            case 19:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_18) + 0x1C8)) = (s32) ((*(s32 *)((u8 *)(temp_18) + 0x1C8)) | 0x404);
                    func_L01_0045BD78(arg0, 0.0216000006f, 0.360000014f, 0.00502654864f, 0.0418879054f);
                    (*(f32 *)((u8 *)(temp_18) + 0x1B4)) = 1.0f;
                    func_003C3A10(arg0, 7, 0, 8);
                    (*(f32 *)((u8 *)(arg0) + 0x48)) = 1.0f;
                    temp_6_2 = (*(s16 *)((u8 *)(temp_18) + 0x258));
                    func_L01_0045C150(arg0, (*(s32 **)((u8 *)(temp_18) + 0x254)), temp_6_2, temp_6_2);
                    func_L01_0045BE38(arg0, (*(s32 **)((u8 *)(temp_18) + 0x254)));
                    (*(s16 *)((u8 *)(temp_18) + 0xD36)) = 8;
                    (*(f32 *)((u8 *)(temp_18) + 0xD3C)) = 0.125f;
                }
                if ((*(f32 *)((u8 *)(temp_18) + 0x1C4)) < (*(f32 *)((u8 *)(temp_18) + 0x25C))) {
                    func_L01_0045BE38(arg0, (*(s32 **)((u8 *)(temp_18) + 0x254)));
                } else if (func_0038CB00(temp_18 + 0xD36) == 0) {
                    temp_7 = (*(f32 *)((u8 *)((((*(s16 *)((u8 *)(temp_18) + 0x25A)) * 0x10) + (*(s32 **)((u8 *)(temp_18) + 0x254)))) + 0x10));
                    sp10 = (*(f32 *)((u8 *)(arg0) + 0x10));
                    sp0 = temp_7;
                    func_003C4098(arg0 + 0x10, sp, &sp10, temp_7, (f32) (*(s16 *)((u8 *)(temp_18) + 0xD36)) * (*(f32 *)((u8 *)(temp_18) + 0xD3C)));
                } else {
                    goto block_443;
                }
                break;
            case 20:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s8 *)((u8 *)(arg0) + 0x23)) = 0x80;
                    temp_5_4 = *(((*(s32 *)((u8 *)(temp_18) + 0xC98)) * 4) + &D_L09_0021E640);
                    func_L01_0045C150(arg0, temp_5_4, *temp_5_4 - 1, 0);
                    func_L01_003EB438(0, arg0 + 0x10, arg0 + 0xF0, 1, 0, 0);
                    func_L09_00403E40(0, 1);
                    (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x41);
                    (*(s8 *)((u8 *)(temp_18) + 0xD2C)) = 0;
                    (*(s32 *)((u8 *)(temp_18) + 0x1C8)) = (s32) ((*(s32 *)((u8 *)(temp_18) + 0x1C8)) | 0x404);
                    func_L01_0045BD78(arg0, 0.00700000022f, 0.110000007f, 0.00502654864f, 0.0418879054f);
                    (*(s16 *)((u8 *)(temp_18) + 0xD34)) = 0x64;
                    (*(u8 *)((u8 *)(temp_18) + 0xD2D)) = 0U;
                    (*(s16 *)((u8 *)(temp_18) + 0xD30)) = 0;
                    (*(u16 *)((u8 *)(&D_1A7E18) + 0x12480)) = 0U;
                    (*(u16 *)((u8 *)(&D_1A7E18) + 0x1248C)) = 0U;
                    (*(u16 *)((u8 *)(&D_1A7E18) + 0x12498)) = 0U;
                    func_003A52A0();
                    (*(s16 *)((u8 *)(temp_18) + 0xD5A)) = -1;
                    (*(s32 *)((u8 *)(temp_18) + 0xD60)) = (s32) (*(s32 *)((u8 *)(arg0) + 0xF0));
                }
                (*(s32 *)((u8 *)(&D_1A4BE0) + 0x238)) = 3;
                func_L09_003BF5F0(arg0, &D_1A4BE0);
                func_L09_003BF890(arg0);
                if ((*(u8 *)((u8 *)(arg0) + 0xBC)) != 0xA) {
                    func_L01_00445188(arg0, 0xA);
                }
                if (func_0038CB00(temp_18 + 0xD34) != 0) {
                    if ((*(s16 *)((u8 *)(temp_18) + 0xD5A)) == -1) {
                        func_L01_004AA760(1, arg0);
                        (*(s16 *)((u8 *)(temp_18) + 0xD5A)) = func_003A52A0();
                    }
                }
                if (((*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) > 265.0f) && (func_0038CB00(temp_18 + 0xD30) != 0)) {
                    if ((*(u16 *)((u8 *)(&D_1A7E18) + 0x1248C)) != 0) {
                        if ((*(u16 *)((u8 *)(&D_1A7E18) + 0x12498)) != 0) {
                            if (((*(u16 *)((u8 *)(&D_1A7E18) + 0x12480)) == 0) && !((*(s32 *)((u8 *)(&D_1A7E18) + 0x1034)) & (1 << *(s32 *)0x1D545C))) {
                                func_L01_0041A5B0(0x1860, 0x159);
                            }
                        } else if (!((*(s32 *)((u8 *)(&D_1A7E18) + 0x104C)) & (1 << *(s32 *)0x1D545C))) {
                            func_L01_0041A5B0(0x1862, 0x15B);
                        }
                    } else if (!((*(s32 *)((u8 *)(&D_1A7E18) + 0x1040)) & (1 << *(s32 *)0x1D545C))) {
                        func_L01_0041A5B0(0x1861, 0x15A);
                    }
                    (*(s16 *)((u8 *)(temp_18) + 0xD30)) = 0x96;
                }
                var_2_2 = func_L01_0045BE38(arg0, (*(s32 **)((u8 *)(temp_18) + 0x254)));
                goto block_442;
            case 21:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_18) + 0x1C8)) = (s32) ((*(s32 *)((u8 *)(temp_18) + 0x1C8)) & ~0x404);
                    func_L01_0045BD78(arg0, 0.00840000063f, 0.140000015f, 0.00502654864f, 0.0418879054f);
                    (*(f32 *)((u8 *)(temp_18) + 0x1B4)) = 1.0f;
                    func_003C3A10(arg0, 9, 0, 8);
                    (*(f32 *)((u8 *)(arg0) + 0x48)) = 0.75f;
                }
                var_16_3 = 0;
                temp_f2 = func_L01_004395E0(arg0);
                (*(f32 *)((u8 *)(temp_18) + 0x1C4)) = 4.0f;
                if (temp_f2 > 0.0f) {
                    if (temp_f2 < 31.0f) {
                        var_16_3 = func_L01_0045BE38(arg0, (*(s32 **)((u8 *)(temp_18) + 0x254)));
                        goto block_431;
                    }
                    goto block_422;
                }
block_422:
                if (!(temp_f2 > 31.0f) || !(temp_f2 < 40.0f)) {
                    if (temp_f2 > 40.0f) {
                        if (temp_f2 < 54.0f) {
                            var_16_3 = func_L01_0045BE38(arg0, (*(s32 **)((u8 *)(temp_18) + 0x254)));
                            goto block_431;
                        }
                        goto block_428;
                    }
block_428:
                    if (temp_f2 > 54.0f) {
                        if (temp_f2 < 71.0f) {
                            goto block_430;
                        }
                        goto block_433;
                    }
block_433:
                    if (temp_f2 > 71.0f) {
                        var_16_3 = func_L01_0045BE38(arg0, (*(s32 **)((u8 *)(temp_18) + 0x254)));
                        func_L09_003BE168(arg0);
                    }
                } else {
block_430:
                    func_L01_0045A9F0(arg0);
                    func_L09_003BDED0(arg0);
block_431:
                    func_L09_003BE168(arg0);
                }
                if (var_16_3 != 0) {
                    temp_2_4 = (*(u8 *)((u8 *)(arg0) + 0x95));
                    temp_2_5 = temp_2_4 & 0xFF;
                    if (temp_2_5 < 4U) {
                        var_7 = &D_L09_002BB230;
                    } else {
                        var_7 = &D_L09_002BB280;
                    }
                    func_L09_003BDB90(arg0, (temp_2_5 <= 3U) ? (temp_18 + 0xC80) : (temp_18 + 0xC9C), (temp_2_4 > 3U) ? 0xA : 5, var_7);
                }
                (*(f32 *)((u8 *)(temp_18) + 0x1C4)) = 1.0f;
                goto block_441;
            case 22:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(f32 *)((u8 *)(temp_18) + 0x12C)) = 1.5f;
                }
                temp_2_6 = func_L01_00454370(arg0, temp_18 + 0xD0);
                if ((!(temp_2_6 & 1) && !((*(f32 *)((u8 *)(temp_18) + 0x30)) <= 0.0f)) || ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x2850)) <= 0) || ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) == 0x6A) || ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) == 0x7D)) {
                    if (temp_2_6 & 2) {
                        (*(f32 *)((u8 *)(temp_18) + 0x12C)) = 0.05f;
                        func_L01_004450F0(arg0, (*(u8 *)((u8 *)(arg0) + 0x94)), -1);
                    }
                } else {
block_457:
                    func_L09_003BC288(arg0);
                }
                break;
            case 23:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(f32 *)((u8 *)(temp_18) + 0x12C)) = 1.5f;
                }
                temp_2_7 = func_L01_00454370(arg0, temp_18 + 0xD0);
                if ((temp_2_7 & 1) || ((*(f32 *)((u8 *)(temp_18) + 0x30)) <= 0.0f)) {
                    goto block_457;
                }
                if (temp_2_7 & 2) {
                    (*(f32 *)((u8 *)(temp_18) + 0x12C)) = 0.05f;
                    func_L01_004450F0(arg0, (*(u8 *)((u8 *)(arg0) + 0x94)), -1);
                }
                break;
            }
            temp_2_8 = (*(u8 *)((u8 *)(arg0) + 0xBC));
            switch (temp_2_8) {                     /* switch 3 */
            case 1:                                 /* switch 3 */
                if ((func_L01_00456208(arg0) != 0) || ((*(u8 *)((u8 *)(temp_21) + 0x60)) & 2)) {
                    func_003C3A10(temp_21, 0, 0, 4);
                }
                break;
            case 2:                                 /* switch 3 */
                if ((func_L01_00456208(arg0) != 0) || ((*(u8 *)((u8 *)(temp_21) + 0x60)) & 2)) {
                    func_003C3A10(temp_21, 0, 0, 4);
                }
                if (func_L09_003BE450(arg0) != 0) {
                    (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) | 4);
                    func_L01_00445188(arg0, 1);
                }
                break;
            case 3:                                 /* switch 3 */
            case 4:                                 /* switch 3 */
                if (func_L01_00456208(arg0) != 0) {
                    (*(s16 *)((u8 *)(temp_18) + 0xD36)) = 2;
                    (*(u8 *)((u8 *)(temp_18) + 0xD2E)) = 0U;
                    if ((*(u8 *)((u8 *)(temp_18) + 0xD41)) == 0) {
                        (*(f32 *)((u8 *)(temp_18) + 0xCDC)) = 0.0f;
                    }
                    0 /* unknown instruction: lqc2 $vf2, 0x4c60($v0) */;
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                    sp0 = (*(f32 *)((u8 *)(temp_21) + 0x10));
                    var_2_3 = 1;
                    if (func_0038CE68(temp_21 + 0xD0, sp) > 0.0f) {
                        var_2_3 = -1;
                    }
                    (*(s8 *)((u8 *)(temp_18) + 0xD2F)) = var_2_3;
                    func_003C3A10(temp_21, 0, 0, 8);
                }
                var_5_3 = 0;
                if ((*(u8 *)((u8 *)(temp_18) + 0xD41)) == 2) {
                    sp0 = D_L09_001D66B0;
                    sp4 = -0.017453292f;
                    sp0 = (*(f32 *)((u8 *)(temp_18) + 0xCDC));
                    temp_f20_3 = func_0038DB00((*(f32 *)((u8 *)(arg0) + 0xF8)), 1.5707964f);
                    func_L01_00448890(sp, temp_18 + 0xCD8, 0, func_0038DB00(func_0038D160((*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(temp_21) + 0x10)), (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)) - (*(f32 *)((u8 *)(temp_21) + 0x14))), temp_f20_3), 0x3BA4B5BF, 0x3BA4B5BF, 0x3F00ADFD);
                    var_5_3 = sp;
                    (*(f32 *)((u8 *)(temp_18) + 0xCDC)) = sp0;
                }
                if (func_L09_003BE330(arg0, var_5_3) != 0) {
                    func_L09_003BF3E0(arg0);
                    func_L09_003BE910(arg0, (*(u8 *)((u8 *)(arg0) + 0xBC)) == 4, 0);
block_537:
                    (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) | 4);
                }
                break;
            case 5:                                 /* switch 3 */
            case 6:                                 /* switch 3 */
                if (func_L01_00456208(arg0) != 0) {
                    (*(s16 *)((u8 *)(temp_18) + 0xD36)) = 2;
                    (*(u8 *)((u8 *)(temp_18) + 0xD2E)) = 0U;
                    if ((*(u8 *)((u8 *)(temp_18) + 0xD41)) == 0) {
                        (*(f32 *)((u8 *)(temp_18) + 0xCDC)) = 0.0f;
                    }
                    func_003C3A10(temp_21, 0, 0, 8);
                }
                var_5_4 = 0;
                if ((*(u8 *)((u8 *)(temp_18) + 0xD41)) == 2) {
                    sp0 = D_L09_001D66B0;
                    if ((u8) (*(u8 *)((u8 *)(arg0) + 0x95)) < 4U) {
                        var_3 = &D_L09_001DE6A0;
                    } else {
                        var_3 = &D_L09_001DE6B0;
                    }
                    sp10 = *var_3;
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                    var_f23 = 0.0f;
                    sp40 = (*(f32 *)((u8 *)(temp_21) + 0x10));
                    var_16_4 = 0;
                    sp50 = (*(f32 *)((u8 *)(temp_18) + 0xCC8));
                    sp58 = 340.0f;
                    sp54 = (*(f32 *)((u8 *)(temp_18) + 0xCCC));
                    sp5C = 0.0f;
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
loop_490:
                    temp_f22 = (f32) var_16_4;
                    temp_f21_2 = temp_f22 * 90.0f * 0.017453292f;
                    sp60 = func_0038D098(temp_f21_2);
                    sp64 = func_0038D0B0(temp_f21_2);
                    sp68 = 0;
                    temp_f20_4 = func_0038CE68(&sp60, &sp40);
                    temp_f0_3 = func_0038CE68(&sp60, &sp50);
                    if (temp_f20_4 > 0.0f) {
                        if (temp_f0_3 > 0.0f) {
                            var_f23 = temp_f21_2;
                        } else {
                            goto block_494;
                        }
                    } else {
block_494:
                        var_16_4 += 1;
                        if (!(temp_f20_4 < 0.0f) || !(temp_f0_3 < 0.0f)) {
                            if (var_16_4 < 4) {
                                goto loop_490;
                            }
                        } else {
                            var_f23 = func_0038DAB8(temp_f22 * 90.0f * 0.017453292f, 3.14159274f);
                        }
                    }
                    sp4 = -0.017453292f;
                    sp0 = (*(f32 *)((u8 *)(temp_18) + 0xCDC));
                    func_L01_00448890(sp, temp_18 + 0xCD8, 0, func_0038DB00((*(f32 *)((u8 *)(arg0) + 0xF8)), var_f23), 0x3BA4B5BF, 0x3BA4B5BF, 0x3F00ADFD);
                    var_5_4 = sp;
                    (*(f32 *)((u8 *)(temp_18) + 0xCDC)) = sp0;
                }
                if (func_L09_003BE330(arg0, var_5_4) != 0) {
                    func_L09_003BE910(arg0, (*(u8 *)((u8 *)(arg0) + 0xBC)) == 6, 0);
                    goto block_537;
                }
                break;
            case 7:                                 /* switch 3 */
                if (func_L01_00456208(arg0) != 0) {
                    (*(s16 *)((u8 *)(temp_18) + 0xD36)) = 0x25;
                    (*(u8 *)((u8 *)(temp_18) + 0xD2D)) = 0U;
                    if ((*(u8 *)((u8 *)(temp_18) + 0xD41)) == 0) {
                        (*(f32 *)((u8 *)(temp_18) + 0xCDC)) = 0.0f;
                    }
                    func_003C3A10(temp_21, 0, 0, 8);
                }
                sp0 = D_L09_001D66B0;
                sp4 = -0.017453292f;
                sp0 = (*(f32 *)((u8 *)(temp_18) + 0xCDC));
                func_L01_00448890(sp, temp_18 + 0xCD8, 0, func_0038DB00(func_0038D160(0.0f /* m2c: &D_L09_001D66B0 bits as f32 */, (*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(temp_21) + 0x10))), (*(f32 *)((u8 *)(arg0) + 0xF8))), 0x3BA4B5BF, 0x3BA4B5BF, 0x3F00ADFD);
                (*(f32 *)((u8 *)(temp_18) + 0xCDC)) = sp0;
                if (func_L09_003BE330(arg0, sp) != 0) {
                    func_003C3FC0(temp_18 + 0xC50, sp);
block_535:
                    var_8 = 0;
block_536:
                    func_L09_003BE5D0(arg0, 0, 0, 0, var_8);
                    goto block_537;
                }
                break;
            case 8:                                 /* switch 3 */
                if (func_L01_00456208(arg0) != 0) {
                    (*(s16 *)((u8 *)(temp_18) + 0xD36)) = 0x25;
                    (*(u8 *)((u8 *)(temp_18) + 0xD2E)) = 0U;
                    if ((*(u8 *)((u8 *)(temp_18) + 0xD41)) == 0) {
                        (*(f32 *)((u8 *)(temp_18) + 0xCDC)) = 0.0f;
                    }
                    0 /* unknown instruction: lqc2 $vf2, 0x4c60($v0) */;
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                    sp0 = (*(f32 *)((u8 *)(temp_21) + 0x10));
                    var_2_4 = 1;
                    if (func_0038CE68(temp_21 + 0xD0, sp) > 0.0f) {
                        var_2_4 = -1;
                    }
                    (*(s8 *)((u8 *)(temp_18) + 0xD2F)) = var_2_4;
                    func_003C3A10(temp_21, 0, 0, 8);
                }
                var_5_5 = 0;
                if ((*(u8 *)((u8 *)(temp_18) + 0xD41)) == 2) {
                    sp0 = D_L09_001D66B0;
                    sp4 = -0.017453292f;
                    sp0 = (*(f32 *)((u8 *)(temp_18) + 0xCDC));
                    temp_f20_5 = func_0038DB00((*(f32 *)((u8 *)(arg0) + 0xF8)), 1.5707964f);
                    func_L01_00448890(sp, temp_18 + 0xCD8, 0, func_0038DB00(func_0038D160((*(f32 *)((u8 *)(&D_1A4BE0) + 0x80)) - (*(f32 *)((u8 *)(temp_21) + 0x10)), (*(f32 *)((u8 *)(&D_1A4BE0) + 0x84)) - (*(f32 *)((u8 *)(temp_21) + 0x14))), temp_f20_5), 0x3BA4B5BF, 0x3BA4B5BF, 0x3F00ADFD);
                    var_5_5 = sp;
                    (*(f32 *)((u8 *)(temp_18) + 0xCDC)) = sp0;
                }
                if (func_L09_003BE330(arg0, var_5_5) != 0) {
                    func_L09_003BF3E0(arg0);
                    var_8 = 1;
                    goto block_536;
                }
                break;
            case 9:                                 /* switch 3 */
                if (func_L01_00456208(arg0) != 0) {
                    (*(s16 *)((u8 *)(temp_18) + 0xD36)) = 0x25;
                    if ((*(u8 *)((u8 *)(temp_18) + 0xD41)) == 0) {
                        (*(f32 *)((u8 *)(temp_18) + 0xCDC)) = 0.0f;
                    }
                    func_003C3A10(temp_21, 0, 0, 8);
                }
                var_5_6 = 0;
                if ((*(u8 *)((u8 *)(temp_18) + 0xD41)) == 2) {
                    sp0 = D_L09_001D66B0;
                    if ((u8) (*(u8 *)((u8 *)(arg0) + 0x95)) < 4U) {
                        var_3_2 = &D_L09_001DE6A0;
                    } else {
                        var_3_2 = &D_L09_001DE6B0;
                    }
                    sp10 = *var_3_2;
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                    var_f23_2 = 0.0f;
                    sp20 = (*(f32 *)((u8 *)(temp_21) + 0x10));
                    var_16_5 = 0;
                    sp30 = (*(f32 *)((u8 *)(temp_18) + 0xCC8));
                    sp38 = 340.0f;
                    sp34 = (*(f32 *)((u8 *)(temp_18) + 0xCCC));
                    sp3C = 0.0f;
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
loop_526:
                    temp_f22_2 = (f32) var_16_5;
                    temp_f21_3 = temp_f22_2 * 90.0f * 0.017453292f;
                    sp40 = func_0038D098(temp_f21_3);
                    sp44 = func_0038D0B0(temp_f21_3);
                    sp48 = 0;
                    temp_f20_6 = func_0038CE68(&sp40, &sp20);
                    temp_f0_4 = func_0038CE68(&sp40, &sp30);
                    if (temp_f20_6 > 0.0f) {
                        if (temp_f0_4 > 0.0f) {
                            var_f23_2 = temp_f21_3;
                        } else {
                            goto block_530;
                        }
                    } else {
block_530:
                        var_16_5 += 1;
                        if (!(temp_f20_6 < 0.0f) || !(temp_f0_4 < 0.0f)) {
                            if (var_16_5 < 4) {
                                goto loop_526;
                            }
                        } else {
                            var_f23_2 = func_0038DAB8(temp_f22_2 * 90.0f * 0.017453292f, 3.14159274f);
                        }
                    }
                    sp4 = -0.017453292f;
                    sp0 = (*(f32 *)((u8 *)(temp_18) + 0xCDC));
                    func_L01_00448890(sp, temp_18 + 0xCD8, 0, func_0038DB00((*(f32 *)((u8 *)(arg0) + 0xF8)), var_f23_2), 0x3BA4B5BF, 0x3BA4B5BF, 0x3F00ADFD);
                    var_5_6 = sp;
                    (*(f32 *)((u8 *)(temp_18) + 0xCDC)) = sp0;
                }
                if (func_L09_003BE330(arg0, var_5_6) != 0) {
                    goto block_535;
                }
                break;
            case 10:                                /* switch 3 */
                if (func_L01_00456208(arg0) != 0) {
                    (*(u8 *)((u8 *)(temp_18) + 0xD2D)) = 0U;
                    (*(s16 *)((u8 *)(temp_18) + 0xD36)) = 0x25;
                    func_003C3A10(temp_21, 4, 0, 0);
                }
                if (((u8) (*(u8 *)((u8 *)(temp_18) + 0xD2D)) >= 2U) && ((temp_16_3 = func_L09_003BF9B8(arg0), (func_00382468() != 0)) || (temp_16_3 != 0))) {
                    var_7_2 = temp_16_3;
                    var_6_3 = (temp_16_3 ^ 1) & 0xFF;
                    var_5_7 = 0;
block_548:
                    func_L09_003BE5D0(arg0, var_5_7, var_6_3, var_7_2, 0);
                } else {
block_555:
                    func_L09_003BE5D0(arg0, 0, 0, 0, 1);
                }
                break;
            case 11:                                /* switch 3 */
                if (func_L01_00456208(arg0) != 0) {
                    func_003C3A10(temp_21, 0, 0, 8);
                }
                (*(f32 *)((u8 *)(temp_18) + 0xBE8)) = 1.5707964f;
                if (func_L01_0044E1B8(temp_21, 0x40000000) != 0) {
                    var_5_7 = 1;
                    var_6_3 = 0;
                    var_7_2 = 0;
                    goto block_548;
                }
block_556:
                if (func_L01_0044E1B8(temp_21, 0x41200000) != 0) {
                    func_003C3A10(temp_21, (((*(u8 *)((u8 *)(temp_21) + 0x42)) ^ 3) != 0) ? 3 : 4, 0, 8);
                }
                break;
            case 12:                                /* switch 3 */
                if (func_L01_00456208(arg0) != 0) {
                    (*(u8 *)((u8 *)(temp_18) + 0xD2E)) = 0U;
                    (*(s8 *)((u8 *)(temp_18) + 0xD2F)) = -1;
                    func_003C3A10(temp_21, 3, 0, 8);
                }
                if ((*(u8 *)((u8 *)(temp_18) + 0xD2E)) != 0) {
                    sp0 = D_L09_001D66B0;
                    sp4 = 0.0f;
                    sp0 = (*(f32 *)((u8 *)(temp_18) + 0xCDC));
                    func_L01_00448890(sp, temp_18 + 0xCD8, 0, sp4, 0x3BA4B5BF, 0x3BA4B5BF, 0x3F00ADFD);
                    (*(f32 *)((u8 *)(temp_18) + 0xCDC)) = sp0;
                    func_003C3FC0(temp_18 + 0xC50, sp);
                } else {
                    (*(f32 *)((u8 *)(temp_18) + 0xBE8)) = 0.43633232f;
                    func_L09_003BF3E0(arg0);
                    if (func_L01_0044E1B8(temp_21, 0x40000000) != 0) {
                        goto block_555;
                    }
                    goto block_556;
                }
                break;
            }
            if (((*(f32 *)((u8 *)(temp_18) + 0x30)) <= 0.0f) && ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x2850)) > 0) && ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) != 0x6A) && ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) != 0x7D)) {
                func_L09_003BC288(arg0);
            }
            func_003C7C38();
            if ((*(u8 *)((u8 *)(temp_18) + 0xD41)) == 1) {
                (*(f32 *)((u8 *)(arg0) + 8)) = (f32) ((*(f32 *)((u8 *)(arg0) + 8)) + ((*(f32 *)((u8 *)(temp_18) + 0xC30)) * 0.5f));
            }
            break;
        case 1:                                     /* switch 1 */
            sp70 = 4e-45f;
            sp74 = 6e-45f;
            if (func_L01_004561E0(arg0) != 0) {
                var_5_8 = 0xD;
                (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 0xFE);
                (*(s32 *)((u8 *)(temp_18) + 0xD4C)) = 0x3F59999A;
                goto block_39;
            }
            temp_2_9 = (*(u8 *)((u8 *)(arg0) + 0x20));
            if ((temp_2_9 == 0xD) && ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 2)) {
                if (func_L09_003BEB30(arg0, temp_18 + 0xC80, 5, &D_L09_002BB230) != 0) {
                    var_5_8 = 0xE;
                    goto block_38;
                }
            } else if ((temp_2_9 == 0xC) && ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 2)) {
                func_L09_003BEC20(arg0, temp_18 + 0xC80, 5, &D_L09_002BB230, 1);
                var_5_8 = 0x10;
block_38:
block_39:
                func_L01_004450F0(arg0, var_5_8, -1);
                func_L01_00445188(arg0, 1);
            } else if (func_L09_003BED10(arg0) == 0) {
                temp_16_4 = temp_18 + 0xC80;
                if (func_L09_003BF038(arg0, temp_16_4, 5, &D_L09_002BB230, 6) == 0) {
                    func_L09_003BF0E0(arg0, temp_16_4, 5, &D_L09_002BB230, &sp70, &sp74, 1);
                }
            }
            if ((func_0038CB00(temp_18 + 0xD30) != 0) || ((temp_2_10 = *(void **)0x1A73E8, (temp_2_10 != 0)) && ((temp_3_10 = (*(s16 *)((u8 *)(temp_2_10) + 0xAA)), (temp_3_10 == 0x19DF)) || (temp_3_10 == 0x1B33))) || (func_L09_003BD860(arg0) != 0)) {
                (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) | 1);
            }
            if (func_L09_003BD860(arg0) != 0) {
                func_L01_00445170(arg0, 2);
                (*(s32 *)((u8 *)(temp_18) + 0xD4C)) = 0x3F266666;
            }
            goto block_239;
        case 2:                                     /* switch 1 */
            sp78 = 4e-45f;
            sp7C = 6e-45f;
            if (func_L01_004561E0(arg0) == 0) {
                temp_2_11 = (*(u8 *)((u8 *)(arg0) + 0x20));
                if ((temp_2_11 == 0xD) && ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 2)) {
                    if (func_L09_003BEB30(arg0, temp_18 + 0xC80, 5, &D_L09_002BB230) != 0) {
                        var_5_9 = 0xF;
                        goto block_62;
                    }
                } else if ((temp_2_11 == 0xC) && ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 2)) {
                    func_L09_003BEC20(arg0, temp_18 + 0xC80, 5, &D_L09_002BB230, 1);
                    var_5_9 = 0x10;
block_62:
                    func_L01_004450F0(arg0, var_5_9, -1);
                    func_L01_00445188(arg0, 1);
                } else if (func_L09_003BED10(arg0) == 0) {
                    temp_16_5 = temp_18 + 0xC80;
                    if (func_L09_003BF038(arg0, temp_16_5, 5, &D_L09_002BB230, 5) == 0) {
                        func_L09_003BF0E0(arg0, temp_16_5, 5, &D_L09_002BB230, &sp78, &sp7C, 1);
                    }
                }
            } else {
                (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 0xFE);
            }
            if (((*(u8 *)((u8 *)(arg0) + 0xBC)) != 5) && ((func_0038CB00(temp_18 + 0xD30) != 0) || ((temp_2_12 = *(s32 *)0x1A73E8, (temp_2_12 != 0)) && ((temp_3_11 = (*(s16 *)((u8 *)(temp_2_12) + 0xAA)), (temp_3_11 == 0x19DF)) || (temp_3_11 == 0x1B33))) || (func_L09_003BD860(arg0) != 0))) {
                (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) | 1);
            }
            if (func_L09_003BD860(arg0) != 0) {
                func_L01_00445170(arg0, 3);
                (*(s32 *)((u8 *)(temp_18) + 0xD4C)) = 0x3F000000;
            }
            goto block_239;
        case 3:                                     /* switch 1 */
            sp80 = 4e-45f;
            sp84 = 6e-45f;
            if (func_L01_004561E0(arg0) == 0) {
                temp_2_13 = (*(u8 *)((u8 *)(arg0) + 0x20));
                if ((temp_2_13 == 0xD) && ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 2)) {
                    if (func_L09_003BEB30(arg0, temp_18 + 0xC80, 5, &D_L09_002BB230) != 0) {
                        var_5_10 = 0xF;
                        goto block_86;
                    }
                } else if ((temp_2_13 == 0xC) && ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 2)) {
                    func_L09_003BEC20(arg0, temp_18 + 0xC80, 5, &D_L09_002BB230, 1);
                    var_5_10 = 0x10;
block_86:
                    func_L01_004450F0(arg0, var_5_10, -1);
                    func_L01_00445188(arg0, 1);
                } else if (func_L09_003BED10(arg0) == 0) {
                    temp_16_6 = temp_18 + 0xC80;
                    if (func_L09_003BF038(arg0, temp_16_6, 5, &D_L09_002BB230, 4) == 0) {
                        func_L09_003BF0E0(arg0, temp_16_6, 5, &D_L09_002BB230, &sp80, &sp84, 1);
                    }
                }
            } else {
                (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 0xFE);
            }
            if (((*(u8 *)((u8 *)(arg0) + 0xBC)) != 5) && ((func_0038CB00(temp_18 + 0xD30) != 0) || ((temp_2_14 = *(s32 *)0x1A73E8, (temp_2_14 != 0)) && ((temp_3_12 = (*(s16 *)((u8 *)(temp_2_14) + 0xAA)), (temp_3_12 == 0x19DF)) || (temp_3_12 == 0x1B33))) || (func_L09_003BD860(arg0) != 0))) {
                (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) | 1);
            }
            if ((func_L09_003BD860(arg0) != 0) && ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x2850)) > 0) && ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) != 0x6A) && ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C4)) != 0x7D)) {
                var_5 = 1;
                var_6 = 4;
                goto block_102;
            }
            goto block_239;
        case 4:                                     /* switch 1 */
            if (func_L01_004561E0(arg0) != 0) {
                temp_4_9 = (*(s16 *)((u8 *)(temp_18) + 0xD5A));
                if (temp_4_9 != -1) {
                    func_003A4F28(temp_4_9);
                    (*(s16 *)((u8 *)(temp_18) + 0xD5A)) = -1;
                }
                var_5_11 = 5;
                goto block_126;
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x20)) == 5) {
                if (func_L01_003ECA10((*(s32 *)((u8 *)(temp_18) + 0xD00))) != 0) {
                    var_5_11 = 6;
                    (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 0xFE);
                    goto block_127;
                }
                goto block_111;
            }
block_111:
            if (((*(u8 *)((u8 *)(arg0) + 0x20)) == 6) && ((*(u8 *)((u8 *)(arg0) + 0xBC)) == 0xB) && (func_L01_003ECA10((*(s32 *)((u8 *)(temp_18) + 0xD04))) != 0)) {
                var_5_11 = 7;
                (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 0xFE);
                goto block_127;
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x20)) != 7) {
                goto block_122;
            }
            if (func_L01_003ECA10((*(s32 *)((u8 *)(temp_18) + 0xD08))) == 0) {
block_122:
                if (((*(u8 *)((u8 *)(arg0) + 0x20)) == 0x14) && (((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 2) || (func_00382380(&D_1A4C60, (*(s32 *)((u8 *)(temp_18) + 0xD14)), 0) != 0))) {
                    func_L01_004AA760(8, arg0);
                    var_5_11 = 8;
block_126:
                    goto block_127;
                }
                if (((*(u8 *)((u8 *)(arg0) + 0x20)) == 8) && (func_L01_003ECA10((*(s32 *)((u8 *)(temp_18) + 0xD18))) != 0)) {
                    var_17_3 = *(((*(s32 *)((u8 *)(temp_18) + 0xD50)) * 4) + &D_L09_0021CDA0);
loop_134:
                    var_4 = (*(s32 *)((u8 *)(temp_18) + 0xD50));
                    if (((var_4 & 0xFF) != 0xFF) && (D_L09_001E00D8 >= var_4) && (var_17_3 != 0)) {
                        if ((*(s16 *)((u8 *)(var_17_3) + -2)) >= 0) {
                            goto block_132;
                        }
                        var_4 = *((var_4 * 4) + &D_L09_0021CDA0);
                        if (var_17_3 == var_4) {
block_132:
                            temp_16_7 = D_L09_001E009C + (((*(u16 *)((u8 *)(var_17_3) + 0)) & 0x7FFF) << 8);
                            var_4 = temp_16_7;
                            if (temp_16_7 != 0) {
                                (*(s32 *)((u8 *)(temp_16_7) + 0x98)) = 0;
                                var_17_3 += 2;
                                (*(u16 *)((u8 *)(temp_16_7) + 0x34)) = (u16) (((*(u16 *)((u8 *)(temp_16_7) + 0x34)) | 0x41) & 0xEFFF);
                                func_L01_004AA7E8((void *) var_4, 1);
                                (*(s32 *)((u8 *)(temp_16_7) + 0x98)) = 0;
                                (*(u16 *)((u8 *)(temp_16_7) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_16_7) + 0x34)) | 2);
                                goto loop_134;
                            }
                        }
                    }
                    temp_16_8 = D_L09_001E0180 + ((*(s32 *)((u8 *)(temp_18) + 0xD1C)) << 7);
                    func_L01_00511AE8();
                    func_L01_004F50C8(temp_16_8 + 0x30, temp_16_8 + 0x70, 0, 0);
                    (*(f32 *)((u8 *)(temp_18) + 0xC30)) = 0.0f;
                    func_003C3FC0(temp_18 + 0xC50, &D_L09_001D66B0);
                    func_L01_004450F0(arg0, 1U, 5);
                    func_L01_00445188(arg0, 0);
                    (*(s32 *)((u8 *)(temp_18) + 0xD4C)) = 0x3EB33333;
                }
            } else {
                func_L01_00511AE8();
                var_5_11 = 0x14;
                (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 0xFE);
block_127:
                func_L01_004450F0(arg0, var_5_11, -1);
                func_L01_00445188(arg0, 1);
            }
            goto block_239;
        case 5:                                     /* switch 1 */
            0 /* unknown instruction: ldl $a0, 0x7($a3) */;
            0 /* unknown instruction: ldr $a0, ($a3) */;
            0 /* unknown instruction: sdl $a0, 0x7($sp) */;
            0 /* unknown instruction: sdr $a0, ($sp) */;
            0 /* unknown instruction: ldl $v0, 0x7($a3) */;
            0 /* unknown instruction: ldr $v0, ($a3) */;
            0 /* unknown instruction: sdl $v0, 0x17($sp) */;
            0 /* unknown instruction: sdr $v0, 0x10($sp) */;
            if (func_L01_004561E0(arg0) != 0) {
                var_5_12 = 0xD;
                (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 0xFE);
                goto block_154;
            }
            temp_2_15 = (*(u8 *)((u8 *)(arg0) + 0x20));
            if ((temp_2_15 == 0xD) && ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 2)) {
                if (func_L09_003BEB30(arg0, temp_18 + 0xC9C, 0xA, &D_L09_002BB280) != 0) {
                    var_5_12 = 0xF;
                    goto block_153;
                }
            } else if ((temp_2_15 == 0xC) && ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 2)) {
                func_L09_003BEC20(arg0, temp_18 + 0xC9C, 0xA, &D_L09_002BB280, 1);
                var_5_12 = 0x10;
block_153:
block_154:
                func_L01_004450F0(arg0, var_5_12, -1);
                func_L01_00445188(arg0, 1);
            } else if (func_L09_003BED10(arg0) == 0) {
                temp_16_9 = temp_18 + 0xC9C;
                if (func_L09_003BF038(arg0, temp_16_9, 0xA, &D_L09_002BB280, 3) == 0) {
                    func_L09_003BF0E0(arg0, temp_16_9, 0xA, &D_L09_002BB280, sp, &sp10, 2);
                }
            }
            if (((*(u8 *)((u8 *)(arg0) + 0xBC)) != 6) && ((func_0038CB00(temp_18 + 0xD30) != 0) || ((temp_2_16 = *(s32 *)0x1A73E8, (temp_2_16 != 0)) && ((temp_3_13 = (*(s16 *)((u8 *)(temp_2_16) + 0xAA)), (temp_3_13 == 0x19DF)) || (temp_3_13 == 0x1B33) || (temp_3_13 == 0x1C0C))) || (func_L09_003BD860(arg0) != 0))) {
                (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) | 1);
            }
            if (func_L09_003BD860(arg0) != 0) {
                func_L01_00445170(arg0, 6);
                (*(s32 *)((u8 *)(temp_18) + 0xD4C)) = 0x3E19999A;
            }
            goto block_239;
        case 6:                                     /* switch 1 */
            0 /* unknown instruction: ldl $a0, 0x7($a3) */;
            0 /* unknown instruction: ldr $a0, ($a3) */;
            0 /* unknown instruction: sdl $a0, 0x7($sp) */;
            0 /* unknown instruction: sdr $a0, ($sp) */;
            0 /* unknown instruction: ldl $v0, 0x7($a3) */;
            0 /* unknown instruction: ldr $v0, ($a3) */;
            0 /* unknown instruction: sdl $v0, 0x27($sp) */;
            0 /* unknown instruction: sdr $v0, 0x20($sp) */;
            if (func_L01_004561E0(arg0) == 0) {
                temp_2_17 = (*(u8 *)((u8 *)(arg0) + 0x20));
                if ((temp_2_17 == 0xD) && ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 2)) {
                    if (func_L09_003BEB30(arg0, temp_18 + 0xC9C, 0xA, &D_L09_002BB280) != 0) {
                        var_5_13 = 0xF;
                        goto block_179;
                    }
                } else if ((temp_2_17 == 0xC) && ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 2)) {
                    func_L09_003BEC20(arg0, temp_18 + 0xC9C, 0xA, &D_L09_002BB280, 1);
                    var_5_13 = 0x10;
block_179:
                    func_L01_004450F0(arg0, var_5_13, -1);
                    func_L01_00445188(arg0, 1);
                } else if (func_L09_003BED10(arg0) == 0) {
                    temp_16_10 = temp_18 + 0xC9C;
                    if (func_L09_003BF038(arg0, temp_16_10, 0xA, &D_L09_002BB280, 2) == 0) {
                        func_L09_003BF0E0(arg0, temp_16_10, 0xA, &D_L09_002BB280, sp, &sp20, 2);
                    }
                }
            } else {
                (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 0xFE);
            }
            if (((*(u8 *)((u8 *)(arg0) + 0xBC)) != 6) && ((func_0038CB00(temp_18 + 0xD30) != 0) || ((temp_2_18 = *(s32 *)0x1A73E8, (temp_2_18 != 0)) && ((temp_3_14 = (*(s16 *)((u8 *)(temp_2_18) + 0xAA)), (temp_3_14 == 0x19DF)) || (temp_3_14 == 0x1B33) || (temp_3_14 == 0x1C0C))) || (func_L09_003BD860(arg0) != 0))) {
                (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) | 1);
            }
            if (func_L09_003BD860(arg0) != 0) {
                func_L01_00445170(arg0, 7);
                (*(s32 *)((u8 *)(temp_18) + 0xD4C)) = 0;
            }
            goto block_239;
        case 7:                                     /* switch 1 */
            0 /* unknown instruction: ldl $a0, 0x7($a3) */;
            0 /* unknown instruction: ldr $a0, ($a3) */;
            0 /* unknown instruction: sdl $a0, 0x7($sp) */;
            0 /* unknown instruction: sdr $a0, ($sp) */;
            0 /* unknown instruction: ldl $v0, 0x7($a3) */;
            0 /* unknown instruction: ldr $v0, ($a3) */;
            0 /* unknown instruction: sdl $v0, 0x37($sp) */;
            0 /* unknown instruction: sdr $v0, 0x30($sp) */;
            if (func_L01_004561E0(arg0) == 0) {
                temp_2_19 = (*(u8 *)((u8 *)(arg0) + 0x20));
                if ((temp_2_19 == 0xD) && ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 2)) {
                    func_L09_003BC450(arg0, temp_18 + 0xC9C, 0xA, &D_L09_002BB280, 0);
                    func_00382498(5, 0xA);
                    (*(s16 *)((u8 *)(temp_18) + 0xD38)) = (s16) (0 /* second half of f64 */);
                    temp_f0_5 = (f32) func_00382498(0xF, 0x19);
                    (*(s16 *)((u8 *)(temp_18) + 0xD34)) = 0;
                    (*(u8 *)((u8 *)(temp_18) + 0xD40)) = 0U;
                    (*(s16 *)((u8 *)(temp_18) + 0xD30)) = (s16) (0 /* second half of f64 */);
                    if ((*(void **)((u8 *)(&D_L09_001E2B80) + 0x144)) == temp_21) {
                        (*(void **)((u8 *)(&D_L09_001E2B80) + 0x144)) = 0;
                    }
                    if ((*(void **)((u8 *)(&D_L09_001E2B80) + 0x144)) == 0) {
                        (*(s32 *)((u8 *)(&D_L09_001E2B80) + 0x148)) = 0;
                        (*(void **)((u8 *)(&D_L09_001E2B80) + 0x144)) = arg0;
                    }
                    var_5_14 = 0xE;
                    goto block_207;
                }
                if (temp_2_19 == 0xC) {
                    if ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 2) {
                        func_L09_003BEC20(arg0, temp_18 + 0xC9C, 0xA, &D_L09_002BB280, 1);
                        var_5_14 = 0x10;
block_207:
                        func_L01_004450F0(arg0, var_5_14, -1);
                        func_L01_00445188(arg0, 1);
                    } else {
                        goto block_209;
                    }
                } else {
block_209:
                    temp_16_11 = temp_18 + 0xC9C;
                    if (func_L09_003BF038(arg0, temp_16_11, 0xA, &D_L09_002BB280, 1) == 0) {
                        func_L09_003BF0E0(arg0, temp_16_11, 0xA, &D_L09_002BB280, sp, &sp30, 2);
                    }
                }
            } else {
                (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) & 0xFE);
            }
            if (((*(u8 *)((u8 *)(arg0) + 0xBC)) != 6) && ((func_0038CB00(temp_18 + 0xD30) != 0) || ((temp_2_20 = *(s32 *)0x1A73E8, (temp_2_20 != 0)) && ((temp_3_15 = (*(s16 *)((u8 *)(temp_2_20) + 0xAA)), (temp_3_15 == 0x19DF)) || (temp_3_15 == 0x1B33) || (temp_3_15 == 0x1C0C))) || (func_L09_003BD860(arg0) != 0))) {
                (*(u8 *)((u8 *)(temp_18) + 0xD42)) = (u8) ((*(u8 *)((u8 *)(temp_18) + 0xD42)) | 1);
            }
            goto block_239;
        case 9:                                     /* switch 1 */
            if (func_L01_004561E0(arg0) != 0) {
                if ((*(u8 *)((u8 *)(temp_18) + 0xD40)) == 0) {
                    func_003C3A10(arg0, 4, 0, 4);
                } else {
                    func_003C3A10(arg0, 5, 0, 4);
                }
                func_003C3A10(temp_21, 0, 0, 4);
            }
            (*(u8 *)((u8 *)(arg0) + 0xBC)) = 0U;
            (*(u8 *)((u8 *)(arg0) + 0x20)) = 1U;
            if (*(s32 *)0x142C38 & 0x01000000) {
                func_L09_003CDA30(D_L09_001E009C + ((*(s32 *)((u8 *)(temp_18) + 0xCE0)) << 8));
                func_L09_003CDA30(D_L09_001E009C + ((*(s32 *)((u8 *)(temp_18) + 0xCE4)) << 8));
                func_L09_003CD9F0(D_L09_001E009C + ((*(s32 *)((u8 *)(temp_18) + 0xCE0)) << 8));
                var_17_4 = *(((*(s32 *)((u8 *)(temp_18) + 0xD28)) * 4) + &D_L09_0021CDA0);
loop_229:
                temp_4_10 = (*(s32 *)((u8 *)(temp_18) + 0xD28));
                if (((temp_4_10 & 0xFF) != 0xFF) && (D_L09_001E00D8 >= temp_4_10) && (var_17_4 != 0)) {
                    if ((*(s16 *)((u8 *)(var_17_4) + -2)) >= 0) {
                        goto block_227;
                    }
                    if (var_17_4 == *((temp_4_10 * 4) + &D_L09_0021CDA0)) {
block_227:
                        temp_16_12 = D_L09_001E009C + (((*(u16 *)((u8 *)(var_17_4) + 0)) & 0x7FFF) << 8);
                        if (temp_16_12 != 0) {
                            var_17_4 += 2;
                            func_L02_003A0200();
                            (*(s32 *)((u8 *)(temp_16_12) + 0x98)) = 0;
                            (*(u16 *)((u8 *)(temp_16_12) + 0x34)) = (u16) (((*(u16 *)((u8 *)(temp_16_12) + 0x34)) | 0x41) & 0xEFFF);
                            func_L01_004AA7E8(temp_16_12, 1);
                            goto loop_229;
                        }
                    }
                }
                func_003C2880(arg0);
                return;
            }
            goto block_239;
        }
    }
}
