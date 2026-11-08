/* func_L01_00350750: Opus handoff (prep by Sonnet worker w7, 2026-11-08)
   Size: 8704 bytes, places: 9 levels (01 04 09 12 13 16 18 22 29), file: src/levels/shared/L01_003500B8.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as
   Step 0: one function (addiu sp,-0xE0), 2 switches / 2 jump tables (26 entries): +0x95, +0x20; flags include @ps2as (file L01_003500B8.c).
   Twin: rac3 sibling func_L01_00353EA0 (same switch skeleton, opcode ratio 0.50, 1038 equal opcodes of 2176/1977). rac2 best func_L13_00406F18 0.25. Corpus: rac3:func_L02_003484D8 0.25, func_L08_003A4E60 0.24.
   Mapping: Common enemy/boss scaffold (matches the tools' names): arg0 = moby; +0x20 = state byte (func_L01_004450F0 = moby_set_state(moby, state, sub)), +0x95 = phase byte, +0x68 = per-object data, func_L01_004561B8 = animation-done test, func_003C3A10 = moby_anim_blend(moby, anim, 0, 8), func_0038CB00 = timer_tick_short, D_1A4BE0 = hero/global struct (+0x25C0 hero moby, +0x25C4 hero state, +0xC08 pad bits). $gp loads are named D_<0x1DC8B0+offset> (D_LNN_ when >= 0x1D9900) in the draft. Own callees: func_L01_0045A898 (arg1/arg2 are f32 vectors), func_L01_00446780, func_L01_00511A40. Shared in 9 levels (01 04 09 12 13 16 18 22 29): the draft is checked at level 01.
   Identical / changed / added / removed: vs func_L01_00353EA0 (ratio 0.50): identical runs 00350BEC-00350C60/00353F90-00354004 (29), 0035122C-00351428/003542E8-003544E4 (127), 00351464-003515BC/003547C4-0035491C (86), 003515C0-00351644/00354920-003549A4 (33), 00351914-00351988/00354B44-00354BB8 (29), 00351A74-00351B3C/00354D08-00354DD0 (50), 00351D18-00351DF4/0035562C-00355708 (55), 00351EC4-00351F50/003557CC-00355858 (35). Do one well, then port to the other.
   VU0: 9 vadd.xyz/vsub.xyz ops in the retail asm; inline-asm VU0 is banned since 2026-11-06 (Matching-Patterns), so this function cannot reach MATCH unless the ops come from plain C; the lq/sq copies are fine (u128_t).
   Draft: compiles (m2c draft cleaned by tools/post.py (real repo prototypes where known, m2c gotos kept)); 2166 diff; opcode-equal 543 of 2177 (mine 2095), ratio 0.25.
     Retail rows yours=2095 retail=2177 equalrows=11.
   Left for Opus:
     1. @ps2as is the file's profile: the draft was compiled with it, expect $gp-vs-lui differences to be assembler-driven (see Matching-Patterns, Option A).
     2. The positional diff shows only 11 equal rows: the draft's argument/stack layout is off from the start (sp vectors); fix the f32 vector locals first.
     3. Check all 9 places once near.
     4. 9 VU0 ops: near miss only.
*/
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF38();
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern int func_L01_004561B8(u8 *);
extern int func_L01_004561E0(void *a0);
extern s32 func_00382468();
extern s32 func_00382498(s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern s32 func_L01_003FB640(f32 *, s32, s32, f32);
extern s32 func_L01_0041A4F0(void);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_0045A9F0(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C2880(s32 p);
extern void func_003C2EC0();
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern void func_003C7C38();
extern void func_L01_00315900(s32, s32, s32);
extern void func_L01_00409598(u8 *, u8 *, u8 *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044E740(void *);
extern void func_L01_00456230(u8 *, s32);
extern void func_L01_00459188(u8 *, u8 *, u8 *);
extern void func_L01_004591B8(void *, void *, void *);
extern void func_L01_0045AA10(u8 *);
extern void func_L01_0045BD78(u8 *a0, f32 a, f32 b, f32 c, f32 d);
extern void func_L01_004AA7E8(s32, s32);
extern void func_L01_004AADE8(s32, s32, void *, s32);
f32 *func_00382348(void *, s32);                    /* extern */
s32 func_003C4098(f32 *, f32 *, f32 *, f32);    /* extern */
s32 func_L01_00352950(void *);                      /* extern */
s32 func_L01_003534C0(void *);                  /* extern */
s32 func_L01_003535F0(void *);                  /* extern */
s32 func_L01_003537A0(void *, s32);         /* extern */
s32 func_L01_00353A88(void *, void *, f32);     /* extern */
s32 func_L01_00353DC8(void *, void *);              /* extern */
f32 func_L01_004395E0(void *);                      /* extern */
s32 func_L01_004450F0(void *, u8, s32);     /* extern */
s32 func_L01_00446058(void *, s32, s32);    /* extern */
s32 func_L01_00446780();  /* K&R: prototype dropped, mismatch with m2c calls */
s32 func_L01_004468C8(void *, s32, s32, s32, s32, s32, s32, f32, s32); /* extern */
s32 func_L01_00446A70(void *, void *, s32, void *, f32 *, s32); /* extern */
s32 func_L01_00448890(void *, void *, s32, f32, s32, s32, s32); /* extern */
s32 func_L01_0044E318(void *, void *);          /* extern */
s32 func_L01_0044E340(void *, s32, s32, f32); /* extern */
s32 func_L01_0044E468(void *, s32);             /* extern */
s32 func_L01_00454370(void *, void *);              /* extern */
s32 func_L01_00456500(s32 *, s32);              /* extern */
s32 func_L01_00458F78(void *, void *, s32, s32); /* extern */
void *func_L01_004592A8(void *, void *, s32, void *); /* extern */
void *func_L01_004593B8(void *, void *, void *, void *, f32 *); /* extern */
s32 func_L01_0045A748(void *, void *);          /* extern */
s32 func_L01_0045A898();  /* K&R: prototype dropped, mismatch with m2c calls */
s32 func_L01_0045AA30(void *, f32 *);           /* extern */
s32 func_L01_0045BDE8(void *, s32);                 /* extern */
extern s32 D_1A4BE0;
extern s32 D_1BBC40;
extern s32 D_L01_001D6694;
extern f32 D_L01_001D66B0;
extern s32 D_L01_001E001C;
extern s32 D_L01_001E29C0;
extern s32 D_L01_001EAA18;
extern s32 func_L01_00353880;

extern s32 D_001D545C;
extern s32 D_001D6694;
extern f32 D_L01_001DD4C4;
extern f32 D_L01_001DD4CC;
extern f32 D_L01_001DD4D0;
extern f32 D_L01_001DD4D4;
extern s32 D_L01_001DD4D8;
extern s32 D_L01_001DD5A4;
extern s32 D_L01_001E001C;

void func_L01_00350750(void *arg0) {
    f32 sp44; /* m2c stack slot */
    f32 sp70; /* m2c stack slot */
    f32 sp74; /* m2c stack slot */
    f32 sp10;
    f32 sp20;
    f32 sp28;
    f32 sp30;
    f32 sp34;
    s32 sp38;
    f32 sp40;
    f32 sp50;
    s32 *temp_17;
    s32 *temp_17_2;
    s32 *temp_20;
    s32 var_4;
    s32 var_5_4;
    s32 var_6;
    f32 *temp_4_4;
    f32 *var_17;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f20_6;
    f32 temp_f20_7;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f21_3;
    f32 temp_f21_4;
    f32 temp_f2;
    s16 temp_3_7;
    s16 temp_3_8;
    s32 temp_16_7;
    s32 temp_2_6;
    s32 temp_2_7;
    s32 temp_3_2;
    s32 temp_4_5;
    s32 temp_5;
    s32 temp_5_2;
    s32 temp_5_3;
    s32 temp_5_5;
    s32 var_17_2;
    s32 var_2;
    s32 var_3;
    s32 var_5;
    s32 var_condition_bit;
    u16 temp_3;
    u16 temp_3_11;
    u16 temp_3_12;
    u16 temp_3_4;
    u8 temp_16;
    u8 temp_3_10;
    u8 temp_3_3;
    u8 temp_3_5;
    u8 temp_3_6;
    u8 temp_3_9;
    u8 var_5_2;
    u8 var_5_3;
    u8 *temp_14;
    u8 *temp_16_2;
    u8 *temp_16_3;
    u8 *temp_16_4;
    u8 *temp_16_5;
    u8 *temp_16_6;
    u8 *temp_16_8;
    u8 *temp_19;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_4;
    u8 *temp_4_2;
    u8 *temp_4_3;
    u8 *temp_5_4;
    u8 *var_20;

    temp_19 = (*(void **)((u8 *)(arg0) + 0x68));
    if (((*(s32 *)((u8 *)(temp_19) + 0x5D8)) != 0) && (*((*(u8 *)((u8 *)(arg0) + 0xB0)) + (D_001D545C * 0x10) + &D_1BBC40) & 0x80) && ((*(u8 *)((u8 *)(arg0) + 0x31)) == 0)) {
        func_003C2880(arg0);
        return;
    }
    temp_5 = (*(s32 *)((u8 *)(temp_19) + 0x5D0));
    if (temp_5 != -1) {
        if ((*(u8 *)((u8 *)(arg0) + 0x95)) != 7) {
            if ((*(u8 *)((u8 *)(arg0) + 0x20)) != 0) {
                if (func_L01_00456500(&D_L01_001E29C0, temp_5) != 0) {
                    temp_4 = (*(void **)((u8 *)(arg0) + 0x24));
                    temp_3 = (*(u16 *)((u8 *)(arg0) + 0x34)) & 0xFFBE;
                    (*(u16 *)((u8 *)(arg0) + 0x34)) = temp_3;
                    (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (temp_3 | ((*(u16 *)((u8 *)(temp_4) + 0x44)) & 0x1000));
                    (*(s32 *)((u8 *)(arg0) + 0x98)) = (s32) (*(s32 *)((u8 *)(temp_4) + 0x10));
                    goto block_12;
                }
                (*(s32 *)((u8 *)(arg0) + 0x98)) = 0;
                (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x41) & 0xEFFF);
                func_L01_004AA7E8(arg0, 1);
                return;
            }
            goto block_12;
        }
        goto block_13;
    }
block_12:
block_13:
    if (((D_L01_001DD5A4 != 0) || (*(u8 *)0x14275C != 0)) && ((*(s32 *)((u8 *)(temp_19) + 0x5E0)) == 0)) {
        temp_3_2 = D_001D545C;
        if (func_L01_00446058(arg0, 0x1BA0, 0x16BD) != 0) {
            if ((temp_3_2 == 0x10) || (temp_3_2 == 4) || (temp_3_2 == 9)) {
                (*(s16 *)((u8 *)(temp_19) + 0x34)) = 6;
                (*(u8 *)((u8 *)(temp_19) + 0x44)) = 0x19U;
                if (func_L01_0041A4F0() != 0) {
                    if (*(s32 *)0x1D545C == 7) {
                        if (*(u8 *)0x14275B == 0) {

                        }
                    }
                    (*(s16 *)((u8 *)(temp_19) + 0x34)) = (s16)((f32) (*(s16 *)((u8 *)(temp_19) + 0x34)));
                    if ((*(s32 *)0x1D545C != 7) || (*(s32 *)0x14275B == 0)) {

                    }
                    (*(u8 *)((u8 *)(temp_19) + 0x44)) = (u8)((f32) (*(u8 *)((u8 *)(temp_19) + 0x44)));
                }
                temp_3_3 = (*(u8 *)((u8 *)(temp_19) + 0x44));
                (*(u8 *)((u8 *)(temp_19) + 0x46)) = temp_3_3;
                (*(u8 *)((u8 *)(temp_19) + 0x45)) = temp_3_3;
                (*(f32 *)((u8 *)(temp_19) + 0x30)) = (f32) (*(s16 *)((u8 *)(temp_19) + 0x34));
            }
            (*(s16 *)((u8 *)(arg0) + 0xAA)) = 0x16BD;
            (*(s32 *)((u8 *)(temp_19) + 0x5E0)) = 1;
            (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x1000);
            (*(s8 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x24))) + 0x46)) = 5;
        }
    } else if (((D_001D545C == 0xD) || (D_001D545C == 0x10) || (D_001D545C == 0x1D) || (D_001D545C == 0xC)) && ((*(s32 *)((u8 *)(temp_19) + 0x5EC)) == 0) && (*(s32 *)0x14275C == 0)) {
        (*(s32 *)((u8 *)(temp_19) + 0x5EC)) = 1;
        func_L01_00446058(arg0, 0x1ED8, 0x16BD);
        (*(s16 *)((u8 *)(arg0) + 0xAA)) = 0x16BD;
        (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) ((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x1000);
        (*(s8 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x24))) + 0x46)) = 5;
    }
    if (((*(u8 *)((u8 *)(arg0) + 0x95)) != 4) && ((*(f32 *)((u8 *)(temp_19) + 0x30)) <= 0.0f)) {
        (*(s32 *)((u8 *)(arg0) + 0x98)) = (s32) (*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x24))) + 0x10));
        func_003C7C38();
        sp10 = D_L01_001D66B0;
        func_L01_00446A70(arg0, arg0, 0x10000, arg0 + 0x10, &D_L01_001D66B0, 0x42C80000);
    }
    if ((*(u8 *)((u8 *)(arg0) + 0x20)) != 0x13) {
        (*(f32 *)((u8 *)(arg0) + 0x2C)) = (f32) ((*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x24))) + 0x24)) * (*(f32 *)((u8 *)(temp_19) + 0x5D4)));
    }
    if (func_L01_00352950(arg0) != 0) {
        func_L01_003537A0(arg0, 1);
        return;
    }
    sp10 = (*(f32 *)((u8 *)(arg0) + 0x10));
    var_3 = D_001D6694;
    if ((*(s16 *)((u8 *)(temp_19) + 0x234)) == 1) {
        if ((*(s16 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x230))) + 0xAA)) == 0x173B) {
            (*(s16 *)((u8 *)(temp_19) + 0x234)) = 0;
        }
        var_3 = D_L01_001D6694;
    }
    if (var_3 != 2) {
        if ((*(s32 *)((u8 *)(temp_19) + 0x5E8)) != 0) {
            temp_4_2 = (*(void **)((u8 *)(arg0) + 0x24));
            temp_3_4 = (*(u16 *)((u8 *)(arg0) + 0x34)) & 0xFFBE;
            (*(u16 *)((u8 *)(arg0) + 0x34)) = temp_3_4;
            (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (temp_3_4 | ((*(u16 *)((u8 *)(temp_4_2) + 0x44)) & 0x1000));
            (*(s32 *)((u8 *)(arg0) + 0x98)) = (s32) (*(s32 *)((u8 *)(temp_4_2) + 0x10));
            (*(s32 *)((u8 *)(temp_19) + 0x5E8)) = 0;
        }
        temp_3_5 = (*(u8 *)((u8 *)(arg0) + 0x95));
        switch (temp_3_5) {                         /* switch 1 */
        case 0:                                     /* switch 1 */
            if (((*(s16 *)((u8 *)(temp_19) + 0x346)) == 0) && ((*(s32 *)((u8 *)(temp_19) + 0x2E8)) != 0)) {
                (*(s32 *)((u8 *)(arg0) + 0x98)) = (s32) (*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x24))) + 0x10));
                func_L01_00353A88(arg0, arg0 + 0x10, (*(f32 *)((u8 *)(temp_19) + 0x350)));
            } else if (func_L01_00456250(D_L01_001E001C + ((*(s32 *)((u8 *)(temp_19) + 0x334)) << 8)) != 0) {
                func_L01_004450F0(arg0, 4U, 1);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 3) {
                    func_003C3A10(arg0, 3, func_00382498(0, 0xA), 0);
                }
            }
        default:                                    /* switch 1 */
block_128:
            temp_3_6 = (*(u8 *)((u8 *)(arg0) + 0x20));
            var_17 = &sp20;
            switch (temp_3_6) {                     /* switch 2 */
            case 2:                                 /* switch 2 */
                func_L01_0045AA10(arg0);
                var_17 = &sp20;
                if (((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) && ((*(s32 *)((u8 *)(temp_19) + 0x340)) == 0)) {
                    func_L01_004450F0(arg0, 4U, -1);
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 3) {
                        var_5 = 3;
block_207:
                        func_003C3A10(arg0, var_5, 0, 8);
                    }
                }
                break;
            case 3:                                 /* switch 2 */
                var_17 = &sp20;
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                        func_003C3A10(arg0, 4, 0, 8);
                    }
                    func_L01_004450F0(arg0, 8U, 3);
                }
                break;
            case 4:                                 /* switch 2 */
                temp_17 = temp_19 + 0x320;
                if (func_L01_004561B8(arg0) != 0) {
                    temp_f20 = func_00382538();
                    temp_f21 = func_003824E0(2.0f, 6.0f);
                    (*(f32 *)((u8 *)(temp_19) + 0x320)) = 0.0f;
                    (*(f32 *)((u8 *)(temp_19) + 0x320)) = (f32) (func_0038D098(temp_f20) * temp_f21);
                    (*(f32 *)((u8 *)(temp_19) + 0x324)) = (f32) (func_0038D0B0(temp_f20) * temp_f21);
                    0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                    (*(f32 *)((u8 *)(temp_19) + 0x320)) = (f32) (*(f32 *)((u8 *)(temp_19) + 0x320));
                    temp_5_2 = (*(s32 *)((u8 *)(temp_19) + 0x33C));
                    if ((temp_5_2 != -1) && (func_L01_00456500(temp_17, temp_5_2) == 0)) {
                        (*(f32 *)((u8 *)(temp_19) + 0x320)) = (f32) (*(f32 *)((u8 *)(temp_19) + 0x310));
                    }
                    (*(s32 *)((u8 *)(temp_19) + 0x330)) = func_00382498(0x12C, 0x212);
                    func_L01_0045BD78(arg0, 0.00219999999f, 0.0300000012f, 0.00181514258f, 0.125663713f);
                }
                func_L01_0045A898(arg0, temp_17, (*(f32 *)((u8 *)(arg0) + 0xF8)));
                func_L01_00448890(arg0 + 0xF8, temp_19 + 0x30C, 0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x320)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x324)) - (*(f32 *)((u8 *)(arg0) + 0x14))), 0x3AEDEA14, 0x3AEDEA14, 0x3D0EFA36);
                if (func_0038CF38() < 0.75f) {
                    temp_f20_2 = func_00382538();
                    temp_f21_2 = func_003824E0(2.0f, 6.0f);
                    (*(f32 *)((u8 *)(temp_19) + 0x320)) = 0.0f;
                    (*(f32 *)((u8 *)(temp_19) + 0x320)) = (f32) (func_0038D098(temp_f20_2) * temp_f21_2);
                    (*(f32 *)((u8 *)(temp_19) + 0x324)) = (f32) (func_0038D0B0(temp_f20_2) * temp_f21_2);
                    0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                    (*(f32 *)((u8 *)(temp_19) + 0x320)) = (f32) (*(f32 *)((u8 *)(temp_19) + 0x320));
                    temp_5_3 = (*(s32 *)((u8 *)(temp_19) + 0x33C));
                    if ((temp_5_3 != -1) && (func_L01_00456500(temp_17, temp_5_3) == 0)) {
                        (*(f32 *)((u8 *)(temp_19) + 0x320)) = (f32) (*(f32 *)((u8 *)(temp_19) + 0x310));
                    }
                }
                var_17 = &sp20;
                if (func_0038CAD0(temp_19 + 0x330) != 0) {
                    temp_16 = (*(u8 *)((u8 *)(arg0) + 0x43));
                    if (temp_16 != (func_00382468() + 1)) {
                        func_003C3A10(arg0, func_00382468() + 1, 0, 8);
                    }
                    var_5_2 = 2;
block_336:
                    func_L01_004450F0(arg0, var_5_2, -1);
                }
                break;
            case 5:                                 /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    temp_f20_3 = func_0038DAB8((*(f32 *)((u8 *)(arg0) + 0xF8)), func_L01_00443A18(60.0f, 80.0f) * 0.017453292f);
                    temp_f21_3 = func_003824E0(3.0f, 4.0f);
                    (*(f32 *)((u8 *)(temp_19) + 0x2F0)) = 0.0f;
                    (*(f32 *)((u8 *)(temp_19) + 0x2F0)) = (f32) (func_0038D098(temp_f20_3) * temp_f21_3);
                    (*(f32 *)((u8 *)(temp_19) + 0x2F4)) = (f32) (func_0038D0B0(temp_f20_3) * temp_f21_3);
                    0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                    (*(f32 *)((u8 *)(temp_19) + 0x2F0)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x10));
                    func_L01_0045BD78(arg0, 0.00219999999f, 0.0300000012f, 0.00181514258f, 0.125663713f);
                }
                temp_17_2 = temp_19 + 0x2F0;
                func_L01_0045A898(arg0, temp_17_2, (*(f32 *)((u8 *)(arg0) + 0xF8)));
                func_L01_00448890(arg0 + 0xF8, temp_19 + 0x30C, 0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x2F0)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x2F4)) - (*(f32 *)((u8 *)(arg0) + 0x14))), 0x3AEDEA14, 0x3AEDEA14, 0x3D0EFA36);
                if (func_0038CF38() < 0.75f) {
                    temp_f20_4 = func_0038DAB8((*(f32 *)((u8 *)(arg0) + 0xF8)), func_L01_00443A18(60.0f, 80.0f) * 0.017453292f);
                    temp_f21_4 = func_003824E0(3.0f, 4.0f);
                    (*(f32 *)((u8 *)(temp_19) + 0x2F0)) = 0.0f;
                    (*(f32 *)((u8 *)(temp_19) + 0x2F0)) = (f32) (func_0038D098(temp_f20_4) * temp_f21_4);
                    (*(f32 *)((u8 *)(temp_19) + 0x2F4)) = (f32) (func_0038D0B0(temp_f20_4) * temp_f21_4);
                    0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                    (*(f32 *)((u8 *)(temp_19) + 0x2F0)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x10));
                }
                var_17 = &sp20;
                if (((*(s16 *)((u8 *)(temp_19) + 0x234)) == 1) && ((func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xF8)), func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14)))) < 1.9198622f) || (*(f32 *)0x1A4D54 > 0.030000001f))) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                        func_003C3A10(arg0, 4, 0, 5);
                    }
                    var_5_3 = 8;
                    var_6 = -1;
block_293:
                    func_L01_004450F0(arg0, var_5_3, var_6);
                    var_17 = &sp20;
                }
                break;
            case 6:                                 /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_0045BD78(arg0, 0.00480000023f, 0.0800000057f, 0.0100530973f, 0.251327425f);
                }
                func_L01_0045BD78(arg0, 0.00480000023f, 0.0800000057f, 0.0100530973f, 0.251327425f);
                if (func_L01_0045BDE8(arg0, (*(s32 *)((u8 *)(temp_19) + 0x338))) == 0) {
                    var_17 = &sp20;
                    if (func_0038CF38() < 6.0f) {
                        goto block_166;
                    }
                } else {
block_166:
                    var_5_3 = 8;
                    var_6 = -1;
                    goto block_293;
                }
                break;
            case 8:                                 /* switch 2 */
                temp_16_2 = temp_19 + 0x360;
                if (func_L01_004561B8(arg0) != 0) {
                    (*(f32 *)((u8 *)(temp_19) + 0x308)) = (f32) (func_L01_00443A18(0, 15.0f) * 0.017453292f);
                    func_L01_00459188(arg0, (*(void **)((u8 *)(temp_19) + 0x230)), temp_16_2);
                    func_L01_0045BD78(arg0, 0.00480000023f, 0.0800000057f, 0.0100530973f, 0.251327425f);
                }
                temp_5_4 = (*(void **)((u8 *)(temp_19) + 0x230));
                if (temp_5_4 != (*(s32 *)((u8 *)(temp_19) + 0x3B0))) {
                    func_L01_00459188(arg0, temp_5_4, temp_16_2);
                }
                func_L01_00458F78(arg0, temp_16_2, 0, 0);
                func_L01_0045A748(arg0, temp_16_2);
                if ((*(f32 *)((u8 *)(temp_19) + 0x120)) < ((*(f32 *)((u8 *)(temp_19) + 0x98)) * 0.8f)) {
                    (*(s32 *)((u8 *)(temp_19) + 0x3A0)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0x3A0)) + 1);
                }
                sp20 = (*(f32 *)((u8 *)(arg0) + 0x10));
                temp_16_3 = arg0 + 0x10;
                temp_20 = temp_19 + 0x220;
                sp28 += 0.6f;
                if ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x25CC)) != 0x12) {
                    if (func_0038CF38() < 1.0f) {
                        if (func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xF8)), func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14)))) < 0.43633232f) {
                            func_L01_004450F0(arg0, 0xAU, -1);
                            if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xC) {
                                func_003C3A10(arg0, 0xC, 0, 8);
                            }
                        }
                    }
                }
                var_17 = &sp20;
                if ((func_L01_003FB640(&sp20, 1, arg0, 0.600000024f) != 0) && (D_L01_001EAA18 != 0) && (D_L01_001EAA18 == (*(void **)((u8 *)(temp_19) + 0x230))) && (D_L01_001EAA18 != (*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C0)))) {
                    func_L01_004450F0(arg0, 0xAU, -1);
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xC) {
                        func_003C3A10(arg0, 0xC, 0, 8);
                    }
                }
                if (func_0038CF38() < 2.5f) {
                    (*(f32 *)((u8 *)(temp_19) + 0x308)) = 0.0f;
                }
                if ((fabsf((*(f32 *)((u8 *)(arg0) + 0x18)) - (*(f32 *)((u8 *)(temp_19) + 0x228))) > 4.0f) && ((*(s32 *)((u8 *)(&D_1A4BE0) + 0x360)) != 0) && ((*(s32 *)((u8 *)(temp_19) + 0x478)) != 0)) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                        func_003C3A10(arg0, 4, 0, 8);
                    }
                    var_5_2 = 0xF;
                    goto block_336;
                }
                break;
            case 15:                                /* switch 2 */
                var_17 = &sp20;
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_19) + 0x474)) = 0;
                    (*(s32 *)((u8 *)(temp_19) + 0x470)) = 0;
                    temp_2 = func_L01_004592A8(arg0, temp_19 + 0x410, (*(s32 *)((u8 *)(temp_19) + 0x3E8)), temp_19 + 0x440);
                    (*(void **)((u8 *)(temp_19) + 0x3EC)) = temp_2;
                    sp20 = (*(f32 *)((u8 *)(temp_2) + 0x10));
                    func_L01_004591B8(arg0, var_17, temp_19 + 0x360);
                    func_L01_0045BD78(arg0, 0.00480000023f, 0.0800000057f, 0.0100530973f, 0.251327425f);
                }
                if ((*(s32 *)((u8 *)(temp_19) + 0x474)) != 0) {
                    if ((*(s32 *)((u8 *)(temp_19) + 0x3A0)) >= 9) {
                        func_L01_004450F0(arg0, 8U, -1);
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                            func_003C3A10(arg0, 4, 0, 8);
                        }
                    }
                    func_L01_0045A748(arg0, (*(void **)((u8 *)(temp_19) + 0x3EC)) + 0x10);
                } else {
                    temp_16_4 = temp_19 + 0x360;
                    func_L01_00458F78(arg0, temp_16_4, 0, 0);
                    func_L01_0045A748(arg0, temp_16_4);
                }
                if (func_0038CF38() <= 1.5f) {
                    (*(s32 *)((u8 *)(temp_19) + 0x474)) = 1;
                    sp20 = (*(f32 *)((u8 *)(temp_19) + 0x220));
                    temp_2_2 = func_L01_004593B8(arg0, (*(void **)((u8 *)(temp_19) + 0x3EC)), temp_19 + 0x440, temp_19 + 0x470, var_17);
                    (*(void **)((u8 *)(temp_19) + 0x3EC)) = temp_2_2;
                    if (temp_2_2 == 0) {
                        func_L01_004450F0(arg0, 8U, -1);
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                            var_5 = 4;
                            goto block_207;
                        }
                    }
                }
                break;
            case 10:                                /* switch 2 */
                temp_f0 = func_L01_004395E0(arg0);
                if ((temp_f0 > 6.0f) && (temp_f0 < 10.0f) && ((*(u8 *)((u8 *)(arg0) + 0x42)) == 0xC)) {
                    sp20 = (*(f32 *)((u8 *)(arg0) + 0x10));
                    if ((*(u8 *)((u8 *)(temp_19) + 0x5F)) != 0) {
                        func_L01_004468C8(arg0, 1, 0x10000, 0, 1, 0, 0x3F000000, (f32) (*(u8 *)((u8 *)(temp_19) + 0x44)), 0x3F400000);
                    } else {
                        func_L01_004468C8(arg0, 1, 1, 0, 1, 0, 0x3F000000, (f32) (*(u8 *)((u8 *)(temp_19) + 0x44)), 0x3F400000);
                    }
                }
                var_17 = &sp20;
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    func_L01_004450F0(arg0, 0xCU, -1);
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 6) {
                        func_003C3A10(arg0, 6, 1, 3);
                    }
                }
                break;
            case 12:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(f32 *)((u8 *)(temp_19) + 0x2F8)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x18));
                }
                var_17 = &sp20;
                if ((*(u8 *)((u8 *)(arg0) + 0x42)) == 6) {
                    temp_f0_2 = func_L01_004395E0(arg0);
                    var_condition_bit = temp_f0_2 > 2.0f;
                    if (temp_f0_2 > 2.0f) {
                        if (temp_f0_2 < 18.0f) {
                            func_0038CF68(&sp40, arg0 + 0xC0, -0.0843750015f);
                            0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                            sp20 = (*(f32 *)((u8 *)(arg0) + 0x10));
                        }
                        var_condition_bit = temp_f0_2 > 2.0f;
                    }
                    if (var_condition_bit) {
                        if (temp_f0_2 < 12.0f) {
                            func_003C41A0(&sp28, temp_19 + 0x300, (*(f32 *)((u8 *)(temp_19) + 0x2F8)) + 1.0f, 0.100000001f, 0.200000003f, 0.100000001f);
                        }
                    }
                    if (temp_f0_2 == 12.0f) {
                        (*(f32 *)((u8 *)(temp_19) + 0x300)) = 0.0f;
                    }
                    if ((temp_f0_2 > 12.0f) && (temp_f0_2 < 18.0f)) {
                        func_003C41A0(&sp28, temp_19 + 0x300, func_003C3D30(arg0 + 0x10, 0, 0, 0.5f), 0.027777778f, 0.333333343f, 0.25f);
                    }
                    if (!(temp_f0_2 > 2.0f)) {
                        goto block_240;
                    }
                    if (!(temp_f0_2 < 18.0f)) {
block_240:
                        func_L01_0045AA10(arg0);
                    } else {
                        0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                        sp30 = sp20;
                        func_L01_0045AA30(arg0, &sp30);
                    }
                    var_17 = &sp20;
                    if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                        if (func_00382468() == 0) {
                            if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 9) {
                                func_003C3A10(arg0, 9, 0, 7);
                            }
                            var_5_2 = 0xD;
                            goto block_336;
                        }
block_248:
                        func_L01_004450F0(arg0, 8U, -1);
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                            func_003C3A10(arg0, 4, 0, 5);
                        }
                    }
                }
                break;
            case 13:                                /* switch 2 */
                func_L01_0045AA10(arg0);
                var_17 = &sp20;
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    goto block_248;
                }
                break;
            case 11:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s16 *)((u8 *)(temp_19) + 0x2E6)) = 0;
                }
                func_L01_0045AA10(arg0);
                if ((*(u8 *)((u8 *)(arg0) + 0x42)) == 1) {
                    func_003C2EC0();
                    temp_f20_5 = func_0038D160(sp70, sp74);
                    if (func_0038DBA0(temp_f20_5, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14)))) < 0.43633232f) {
                        (*(s16 *)((u8 *)(temp_19) + 0x2E6)) = (s16) ((*(u16 *)((u8 *)(arg0) + 0x96)) + 5);
                    }
                    temp_3_7 = (*(s16 *)((u8 *)(temp_19) + 0x2E6));
                    if (((temp_3_7 != 0) && ((*(u16 *)((u8 *)(arg0) + 0x96)) == temp_3_7)) || (*(s32 *)0x1A4D54 > 0.040000003f)) {
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                            func_003C3A10(arg0, 4, 0, 5);
                        }
                        func_L01_004450F0(arg0, 8U, -1);
                    }
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 2) {
                        func_003C3A10(arg0, 2, 0, 5);
                    }
                    func_L01_004450F0(arg0, 0xEU, -1);
                }
                /* fallthrough */
            case 14:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s16 *)((u8 *)(temp_19) + 0x2E6)) = 0;
                }
                func_L01_0045AA10(arg0);
                var_17 = &sp20;
                if ((*(u8 *)((u8 *)(arg0) + 0x42)) == 2) {
                    func_003C2EC0();
                    temp_f20_6 = func_0038D160(sp40, sp44);
                    if (func_0038DBA0(temp_f20_6, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14)))) < 0.43633232f) {
                        (*(s16 *)((u8 *)(temp_19) + 0x2E6)) = (s16) ((*(u16 *)((u8 *)(arg0) + 0x96)) + 5);
                    }
                    if (((*(s16 *)((u8 *)(temp_19) + 0x234)) == 1) && (((temp_3_8 = (*(s16 *)((u8 *)(temp_19) + 0x2E6)), (temp_3_8 != 0)) && ((*(u16 *)((u8 *)(arg0) + 0x96)) == temp_3_8)) || (*(s32 *)0x1A4D54 > 0.040000003f))) {
                        if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                            func_003C3A10(arg0, 4, 0, 5);
                        }
                        func_L01_004450F0(arg0, 8U, -1);
                    }
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 3) {
                        func_003C3A10(arg0, 3, 0, 3);
                    }
                    var_5_2 = 5;
                    goto block_336;
                }
                break;
            case 21:                                /* switch 2 */
                if ((func_L01_004561B8(arg0) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0)) {
                    func_003C3A10(arg0, 0, 0, 8);
                }
                temp_2_3 = (*(void **)((u8 *)(temp_19) + 0x230));
                func_L01_0045AA10(arg0);
                var_17 = &sp20;
                if (func_L01_00353DC8(arg0, (*(void **)((u8 *)(temp_19) + 0x230))) == 0) {
                    var_5_2 = 0x16;
                    goto block_336;
                }
                break;
            case 22:                                /* switch 2 */
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 9) {
                    func_003C3A10(arg0, 9, 0, 8);
                }
                temp_2_4 = (*(void **)((u8 *)(temp_19) + 0x230));
                func_L01_0045AA10(arg0);
                var_17 = &sp20;
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                        func_003C3A10(arg0, 0, 0, 5);
                    }
                    var_5_2 = 0x17;
                    goto block_336;
                }
                break;
            case 23:                                /* switch 2 */
                var_5_3 = 2;
                var_6 = 1;
                goto block_293;
            case 19:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    (*(s32 *)((u8 *)(temp_19) + 0xA8)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0xA8)) | 0x400);
                }
                temp_f1 = (*(f32 *)((u8 *)(temp_19) + 0x34C));
                if (temp_f1 < 1.0f) {
                    temp_f0_3 = temp_f1 + D_L01_001DD4C4;
                    (*(f32 *)((u8 *)(temp_19) + 0x34C)) = temp_f0_3;
                    if (temp_f0_3 > 1.0f) {
                        (*(f32 *)((u8 *)(temp_19) + 0x34C)) = 1.0f;
                    }
                    (*(f32 *)((u8 *)(arg0) + 0x2C)) = (f32) ((*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x24))) + 0x24)) * (*(f32 *)((u8 *)(temp_19) + 0x34C)) * (*(f32 *)((u8 *)(temp_19) + 0x5D4)));
                }
                temp_f1_2 = (*(f32 *)((u8 *)(temp_19) + 0x118)) - 0.00392f;
                (*(f32 *)((u8 *)(temp_19) + 0x118)) = temp_f1_2;
                (*(f32 *)((u8 *)(temp_19) + 0x110)) = (f32) ((*(f32 *)((u8 *)(temp_19) + 0x110)) * 0.98800004f);
                (*(f32 *)((u8 *)(temp_19) + 0x114)) = (f32) ((*(f32 *)((u8 *)(temp_19) + 0x114)) * 0.98800004f);
                if (temp_f1_2 < -0.54f) {
                    (*(f32 *)((u8 *)(temp_19) + 0x118)) = -0.54f;
                }
                temp_2_5 = (*(void **)((u8 *)(temp_19) + 0x348));
                if (temp_2_5 != 0) {
                    (*(s32 *)((u8 *)(temp_2_5) + 0x98)) = 0;
                }
                func_L01_0045AA30(arg0, temp_19 + 0x110);
                temp_4_3 = (*(void **)((u8 *)(temp_19) + 0x348));
                if (temp_4_3 != 0) {
                    (*(s32 *)((u8 *)(temp_4_3) + 0x98)) = (s32) (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_4_3) + 0x24))) + 0x10));
                }
                var_17 = &sp20;
                if (((*(f32 *)((u8 *)(arg0) + 0x18)) - func_003C3D30(arg0 + 0x10, 0, 0, 0.5f)) < 0.25f) {
                    func_L01_0045A9F0(arg0);
                    var_5_2 = 0x14;
                    goto block_336;
                }
                break;
            case 20:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 5) {
                        func_003C3A10(arg0, 5, 0, 8);
                    }
                    (*(s32 *)((u8 *)(temp_19) + 0xA8)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0xA8)) & ~0x400);
                }
                func_L01_0045A9F0(arg0);
                var_17 = &sp20;
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    func_L01_004450F0(arg0, 8U, 3);
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                        func_003C3A10(arg0, 4, func_00382498(0, 0xA), 0);
                    }
                }
                break;
            case 24:                                /* switch 2 */
                if (func_L01_004561B8(arg0) != 0) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                        func_003C3A10(arg0, 4, 0, 5);
                    }
                    (*(f32 *)((u8 *)(temp_19) + 0x300)) = 0.080000006f;
                }
                temp_f0_4 = (*(f32 *)((u8 *)(temp_19) + 0x300)) + D_L01_001DD4D0;
                (*(f32 *)((u8 *)(temp_19) + 0x300)) = temp_f0_4;
                sp30 = (*(f32 *)((u8 *)(temp_19) + 0x2F0));
                var_17 = &sp20;
                sp40 = (*(f32 *)((u8 *)(temp_19) + 0x320));
                temp_f20_7 = 1.0f - ((temp_f0_4 + 0.080000006f) / 0.16000001f);
                func_003C4098(&sp20, &sp30, &sp40, temp_f20_7);
                sp28 = (*(f32 *)((u8 *)(arg0) + 0x18)) + (*(f32 *)((u8 *)(temp_19) + 0x300));
                (*(f32 *)((u8 *)(arg0) + 0xF4)) = (f32) (temp_f20_7 * 1.5707964f);
                0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                sp30 = sp20;
                func_L01_0045AA30(arg0, &sp30);
                if (temp_f20_7 >= 1.0f) {
                    var_5_2 = 0x19;
                    goto block_336;
                }
                break;
            case 25:                                /* switch 2 */
                var_20 = temp_19 + 0x480;
                if (func_L01_004561B8(arg0) != 0) {
                    (*(f32 *)((u8 *)(arg0) + 0x10)) = (f32) (*(f32 *)((u8 *)(temp_19) + 0x320));
                    (*(f32 *)((u8 *)(arg0) + 0xF4)) = 1.5707964f;
                    temp_3_9 = (*(u8 *)((u8 *)(arg0) + 0x43));
                    if (func_00382468() == 0) {
                        if (temp_3_9 != 9) {
                            func_003C3A10(arg0, 9, 0, 5);
                        }
                    } else if (temp_3_9 != 0xB) {
                        func_003C3A10(arg0, 0xB, 0, 5);
                    }
                    temp_16_5 = temp_19 + 0x480;
                    (*(f32 *)((u8 *)(temp_19) + 0x328)) = func_003C3D30(temp_19 + 0x320, 0, 0, 0.5f);
                    var_20 = temp_16_5;
                    func_L01_0044E318(arg0, temp_16_5);
                    func_L01_0044E340(temp_16_5, 0x20, 1, D_L01_001DD4D4);
                    func_L01_0044E340(temp_16_5, 0x18, 2, D_L01_001DD4D4);
                    func_L01_0044E340(temp_16_5, 0x10, 3, D_L01_001DD4D4);
                    func_L01_0044E340(temp_16_5, 8, 4, D_L01_001DD4D4);
                    if (*(s32 *)0x1D545C == 0xD) {
                        func_L01_004AADE8(0x13, 0, arg0, 0);
                    }
                }
                temp_f2 = D_L01_001DD4CC;
                temp_f0_5 = (*(f32 *)((u8 *)(temp_19) + 0x300)) + D_L01_001DD4D0;
                (*(f32 *)((u8 *)(temp_19) + 0x300)) = temp_f0_5;
                if (temp_f0_5 < temp_f2) {
                    (*(f32 *)((u8 *)(temp_19) + 0x300)) = temp_f2;
                }
                sp20 = 0.0f;
                var_17 = &sp20;
                sp28 = (*(f32 *)((u8 *)(temp_19) + 0x300));
                func_L01_0045AA30(arg0, &sp20);
                func_L01_0044E468(var_20, D_L01_001DD4D8);
                sp30 = func_0038D098((*(f32 *)((u8 *)(arg0) + 0xF8))) * 0.5f;
                temp_f0_6 = func_0038D0B0((*(f32 *)((u8 *)(arg0) + 0xF8))) * 0.5f;
                sp38 = 0;
                sp34 = temp_f0_6;
                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                if ((func_L01_00446780(arg0, &sp30, 0x02000001, 0, 1, 0, 0x3F000000, 0x3F800000, 0x3F800000) != 0) && (D_L01_001EAA18 == (*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C0)))) {
                    (*(s16 *)((u8 *)(&D_1A4BE0) + 0x1DE)) = 0x32;
                }
                if ((*(f32 *)((u8 *)(arg0) + 0x18)) <= (*(f32 *)((u8 *)(temp_19) + 0x328))) {
                    var_5_2 = 0x1A;
                    goto block_336;
                }
                break;
            case 26:                                /* switch 2 */
                var_17 = &sp20;
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_0044E740(temp_19 + 0x480);
                    func_L01_00315900(arg0, 0, &func_L01_00353880);
                }
                break;
            }
            0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
            sp20 = sp10;
            temp_2_6 = (*(s32 *)((u8 *)(temp_19) + 0x3A0));
            if (func_0038CEA8(var_17) < ((*(f32 *)((u8 *)(temp_19) + 0x98)) * 0.5f)) {
                var_2 = temp_2_6 + 1;
            } else {
                var_2 = temp_2_6 - 1;
            }
            (*(s32 *)((u8 *)(temp_19) + 0x3A0)) = var_2;
            func_L01_003535F0(arg0);
            break;
        case 1:                                     /* switch 1 */
            if ((func_L01_004561E0(arg0) != 0) && ((*(s16 *)((u8 *)(temp_19) + 0x2E6)) == 0)) {
                (*(s16 *)((u8 *)(temp_19) + 0x2E6)) = (s16) ((s32) ((func_00382498(0, 0x28) * 5) + 2) / 6);
            }
            temp_5_5 = (*(s32 *)((u8 *)(temp_19) + 0x3E0));
            var_17_2 = 0;
            if ((temp_5_5 == -1) || (temp_16_6 = D_L01_001E001C + (temp_5_5 << 8), temp_4_4 = func_00382348(temp_16_6, temp_5_5), (temp_16_6 == 0)) || (temp_3_10 = (*(u8 *)((u8 *)(temp_16_6) + 0x20)), (temp_3_10 == 0xFE)) || (temp_3_10 == 0xFD) || ((temp_4_4 != 0) && (*temp_4_4 <= 0.0f))) {
                var_17_2 = 1;
            }
            if (((*(s16 *)((u8 *)(temp_19) + 0x234)) == 1) && (func_0038CB00(temp_19 + 0x2E6) != 0) && (var_17_2 != 0)) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                    func_003C3A10(arg0, 4, 0, 8);
                }
                func_L01_004450F0(arg0, 8U, 3);
                if ((*(s32 *)((u8 *)(temp_19) + 0x338)) != -1) {
                    func_L01_004450F0(arg0, 6U, -1);
                }
            } else if (((*(s32 *)((u8 *)(temp_19) + 0x2E8)) != 0) && (func_0038CB00(temp_19 + 0x2E6) != 0)) {
                func_L01_004450F0(arg0, (*(u8 *)((u8 *)(arg0) + 0x20)), 2);
                (*(s32 *)((u8 *)(temp_19) + 0x2E8)) = 0;
                if ((*(s32 *)((u8 *)(temp_19) + 0x2E0)) < 0xFA) {
                    (*(s32 *)((u8 *)(temp_19) + 0x2E0)) = (s32) ((s32) ((func_00382498(0x1E0, 0x258) * 5) + 2) / 6);
                }
            }
block_93:
            if (func_L01_00353DC8(arg0, (*(void **)((u8 *)(temp_19) + 0x230))) != 0) {
                func_L01_004450F0(arg0, 0x15U, 8);
            }
            goto block_128;
        case 2:                                     /* switch 1 */
            if ((*(s16 *)((u8 *)(temp_19) + 0x234)) != 1) {
                if ((*(s32 *)((u8 *)(temp_19) + 0x2E0)) == 0) {
                    func_L01_004450F0(arg0, (*(u8 *)((u8 *)(arg0) + 0x20)), 1);
                }
            } else {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                    func_003C3A10(arg0, 4, 0, 8);
                }
                func_L01_004450F0(arg0, 8U, 3);
            }
            goto block_93;
        case 3:                                     /* switch 1 */
            if (((*(s16 *)((u8 *)(temp_19) + 0x234)) != 1) && (func_L01_004561E0(arg0) == 0) && (func_00382468() == 0)) {
                func_L01_004450F0(arg0, 4U, 2);
                var_4 = 0x30C;
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 3) {
                    temp_16_7 = func_00382468();
                    func_003C3A10(arg0, 3, temp_16_7, (s32) ((func_00382498(8, 0xC) * 5) + 2) / 6);
                    var_4 = 0x30C;
                }
                var_5_4 = 0x384;
block_113:
                (*(s32 *)((u8 *)(temp_19) + 0x2E0)) = (s32) ((s32) ((func_00382498(var_4, var_5_4) * 5) + 2) / 6);
            }
            goto block_128;
        case 4:                                     /* switch 1 */
            temp_2_7 = func_L01_00454370(arg0, temp_19 + 0x160);
            if (temp_2_7 & 1) {
                func_L01_003534C0(arg0);
                func_L01_00315900(arg0, 0, &func_L01_00353880);
                return;
            }
            if (temp_2_7 & 2) {
                if ((*(s16 *)((u8 *)(temp_19) + 0x234)) != 1) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                        func_003C3A10(arg0, 0, 0, 8);
                    }
                    func_L01_004450F0(arg0, 7U, 2);
                    var_4 = 0x244;
                    var_5_4 = 0x258;
                    goto block_113;
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                    func_003C3A10(arg0, 4, 0, 8);
                }
                func_L01_004450F0(arg0, 8U, 3);
            }
            goto block_128;
        case 7:                                     /* switch 1 */
            if (((*(s16 *)((u8 *)(temp_19) + 0x346)) != 0) && (((temp_4_5 = (*(s32 *)((u8 *)(temp_19) + 0x334)), (temp_4_5 != -1)) && (func_L01_00456250(D_L01_001E001C + (temp_4_5 << 8)) != 0) && (func_0038CB00(temp_19 + 0x2E6) != 0)) || (((*(s16 *)((u8 *)(temp_19) + 0x234)) == 1) && (func_0038CB00(temp_19 + 0x2E6) != 0)))) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0) {
                    func_003C3A10(arg0, 0, func_00382498(0, 0xA), 0);
                }
                func_L01_00456230(arg0, 1);
                temp_16_8 = arg0 + 0x10;
                (*(f32 *)((u8 *)(arg0) + 0x18)) = func_003C3D30(temp_16_8, 0, 0, 0.5f);
                if ((*(u8 *)((u8 *)(arg0) + 0x95)) == 9) {
                    func_L01_004450F0(arg0, 0x18U, -1);
                } else {
                    func_L01_004450F0(arg0, 2U, 1);
                }
                temp_14 = (*(void **)((u8 *)(arg0) + 0x24));
                temp_3_11 = (*(u16 *)((u8 *)(arg0) + 0x34)) & 0xFFBE;
                (*(u16 *)((u8 *)(arg0) + 0x34)) = temp_3_11;
                temp_3_12 = temp_3_11 | ((*(u16 *)((u8 *)(temp_14) + 0x44)) & 0x1000);
                (*(u16 *)((u8 *)(arg0) + 0x34)) = temp_3_12;
                (*(u8 *)((u8 *)(arg0) + 0x31)) = 0U;
                (*(s32 *)((u8 *)(arg0) + 0x98)) = (s32) (*(s32 *)((u8 *)(temp_14) + 0x10));
                (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (temp_3_12 | 1);
                func_L01_00409598(arg0, temp_16_8, arg0 + 0xF0, 0, 2, 3, 0x25, 0x25, 0x80FF40, 0x108F10);
            }
            goto block_128;
        case 8:                                     /* switch 1 */
            if ((*(s16 *)((u8 *)(temp_19) + 0x234)) == 1) {
                func_L01_004450F0(arg0, 2U, 1);
            }
            goto block_128;
        }
    } else if (((u8) (*(u16 *)((u8 *)(arg0) + 0x34)) ^ 1) & 1) {
        (*(s32 *)((u8 *)(arg0) + 0x98)) = 0;
        (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x41) & 0xEFFF);
        func_L01_004AA7E8(arg0, 1);
        (*(s32 *)((u8 *)(temp_19) + 0x5E8)) = 1;
    }
}
