/* func_L01_00353EA0: Opus handoff (prep by Sonnet worker w7, 2026-11-08)
   Size: 7908 bytes, places: 1 levels (01), file: src/levels/01_veldin/L01_00353EA0.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: one function (addiu sp,-0x90), 2 switches / 2 jump tables (25 entries): +0x95, +0x20.
   Twin: rac3 sibling func_L01_00350750 (ratio 0.50, see its dossier for the identical runs, columns swapped), func_L22_003B3228 0.39. rac2 best func_L03_003C1BF0 0.27; corpus rac3:func_L08_003A4E60 0.29.
   Mapping: Common enemy/boss scaffold (matches the tools' names): arg0 = moby; +0x20 = state byte (func_L01_004450F0 = moby_set_state(moby, state, sub)), +0x95 = phase byte, +0x68 = per-object data, func_L01_004561B8 = animation-done test, func_003C3A10 = moby_anim_blend(moby, anim, 0, 8), func_0038CB00 = timer_tick_short, D_1A4BE0 = hero/global struct (+0x25C0 hero moby, +0x25C4 hero state, +0xC08 pad bits). $gp loads are named D_<0x1DC8B0+offset> (D_LNN_ when >= 0x1D9900) in the draft.
   Identical / changed / added / removed: see func_L01_00350750: the identical runs are 00353F90, 003542E8, 003547C4, 00354920, 00354B44, 00354D08, 0035562C, 003557CC (starts in this function).
   VU0: 21 vadd.xyz/vsub.xyz ops in the retail asm; inline-asm VU0 is banned since 2026-11-06 (Matching-Patterns), so this function cannot reach MATCH unless the ops come from plain C; the lq/sq copies are fine (u128_t).
   Draft: compiles (m2c draft cleaned by tools/post.py (real repo prototypes where known, m2c gotos kept)); 1891 diff; opcode-equal 223 of 1978 (mine 1807), ratio 0.12.
     Retail rows yours=1807 retail=1978 equalrows=87.
   Left for Opus:
     1. Do func_L01_00350750 first (its 127-insn block 003542E8-003544E4 here is the biggest shared piece), then diff this one against the matched result.
     2. 21 VU0 ops (11 vadd + 10 vsub .xyz): near miss only; the most VU0-heavy of the slate.
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
extern s32 func_00382498(s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern s32 func_003A52A0();
extern s32 func_L01_00456250(void *);
extern s32 func_L01_0045A9F0(void *);
extern s32 func_L01_0045BD10(u8 *, f32);
extern u8 *func_003C24B0(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern void func_L01_00315900(s32, s32, s32);
extern void func_L01_003564D0(void *, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_L01_00459188(u8 *, u8 *, u8 *);
extern void func_L01_004591B8(void *, void *, void *);
extern void func_L01_0045AA10(u8 *);
extern void func_L01_0045BD78(u8 *a0, f32 a, f32 b, f32 c, f32 d);
s32 func_L01_00355D88();                            /* extern */
s32 func_L01_00356588(void *);                  /* extern */
s32 func_L01_003565E0(void *);                  /* extern */
s32 func_L01_003569A0(void *, void *, f32);     /* extern */
s32 func_L01_003CD878(s32, f32 *, f32 *, s32, s32, f32); /* extern */
f32 func_L01_004395E0(void *);                      /* extern */
s32 func_L01_004450F0(void *, u8, s32);     /* extern */
s32 func_L01_004468C8(void *, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_L01_00448890(void *, void *, s32, f32, s32, s32, s32); /* extern */
s32 func_L01_0044E1B8(void *, s32);             /* extern */
s32 func_L01_00454370(void *, void *);              /* extern */
s32 func_L01_00456500(void *, s32);                 /* extern */
s32 func_L01_00458F78(void *, void *, s32, s32); /* extern */
void *func_L01_004592A8(void *, void *, s32, void *); /* extern */
void *func_L01_004593B8(void *, void *, void *, void *, f32 *); /* extern */
s32 func_L01_0045A7A8();  /* K&R: prototype dropped, mismatch with m2c calls */
s32 func_L01_0045A898();  /* K&R: prototype dropped, mismatch with m2c calls */
s32 func_L01_0045AA30(void *, f32 *);           /* extern */
s32 func_L01_0045BDE8(void *, s32);                 /* extern */
s32 func_L01_0045C2A0(void *, f32, f32, f32);       /* extern */
extern s32 D_1A4BE0;
extern s32 D_L01_001E001C;
extern s32 func_L01_00356568;

extern f32 D_L01_001DD5B4;
extern f32 D_L01_001DD5B8;
extern f32 D_L01_001DD5BC;
extern f32 D_L01_001DD5D4;
extern f32 D_L01_001DD5DC;
extern f32 D_L01_001DD5E0;
extern f32 D_L01_001DD5E4;
extern s32 D_L01_001DD5E8;

void func_L01_00353EA0(void *arg0) {
    f32 sp0;
    f32 sp10;
    s32 sp18;
    f32 sp20;
    f32 sp30;
    s32 var_4;
    s32 var_5;
    s32 var_5_3;
    s32 var_5_4;
    s32 var_5_5;
    f32 *temp_4_2;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f0_9;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f20_6;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f21_3;
    f32 temp_f21_4;
    s32 temp_2;
    s32 temp_2_6;
    s32 temp_3;
    s32 temp_5;
    s32 temp_5_2;
    s32 var_6;
    s32 var_condition_bit;
    s32 var_condition_bit_2;
    s32 var_condition_bit_3;
    s32 var_condition_bit_4;
    s32 var_condition_bit_5;
    u8 temp_3_2;
    u8 temp_4;
    u8 var_5_2;
    u8 *temp_16;
    u8 *temp_16_2;
    u8 *temp_16_3;
    u8 *temp_16_4;
    u8 *temp_17;
    u8 *temp_17_2;
    u8 *temp_17_3;
    u8 *temp_17_4;
    u8 *temp_19;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *temp_4_3;

    temp_19 = (*(void **)((u8 *)(arg0) + 0x68));
    if (func_L01_00355D88() != 0) {
        func_L01_003564D0(arg0, 1);
        return;
    }
    temp_4 = (*(u8 *)((u8 *)(arg0) + 0x95));
    sp0 = (*(f32 *)((u8 *)(arg0) + 0x10));
    switch (temp_4) {                               /* switch 1 */
    case 0:                                         /* switch 1 */
        if ((*(s32 *)((u8 *)(temp_19) + 0x2F8)) != 0) {
            temp_3 = *(s32 *)0x1D545C;
            if (((temp_3 == 1) || (temp_3 == 0x60)) && ((*(s32 *)((u8 *)(temp_19) + 0x360)) == 0)) {
                temp_2 = func_003C24B0(0x1AA2, 0x80);
                (*(s32 *)((u8 *)(temp_19) + 0x360)) = temp_2;
                func_L01_00456160(temp_2, arg0);
                (*(s32 *)((u8 *)(temp_19) + 0x240)) = (s32) (*(s32 *)((u8 *)(temp_19) + 0x360));
            }
            (*(s32 *)((u8 *)(arg0) + 0x98)) = (s32) (*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x24))) + 0x10));
            func_L01_003569A0(arg0, arg0 + 0x10, (*(f32 *)((u8 *)(temp_19) + 0x35C)));
        } else if (func_L01_00456250(D_L01_001E001C + ((*(s32 *)((u8 *)(temp_19) + 0x344)) << 8)) != 0) {
            func_L01_004450F0(arg0, 7U, 1);
            if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x12) {
                func_003C3A10(arg0, 0x12, func_00382498(0, 0xA), 0);
            }
        }
    default:                                        /* switch 1 */
block_47:
        temp_3_2 = (*(u8 *)((u8 *)(arg0) + 0x20));
        switch (temp_3_2) {                         /* switch 2 */
        case 6:                                     /* switch 2 */
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                func_L01_004450F0(arg0, 7U, -1);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x12) {
                    var_5 = 0x12;
block_159:
                    func_003C3A10(arg0, var_5, 0, 8);
                }
            }
            break;
        case 7:                                     /* switch 2 */
            temp_17 = temp_19 + 0x330;
            if (func_L01_004561B8(arg0) != 0) {
                temp_f20 = func_00382538();
                temp_f21 = func_003824E0(2.0f, 6.0f);
                (*(f32 *)((u8 *)(temp_19) + 0x330)) = 0.0f;
                (*(f32 *)((u8 *)(temp_19) + 0x330)) = (f32) (func_0038D098(temp_f20) * temp_f21);
                (*(f32 *)((u8 *)(temp_19) + 0x334)) = (f32) (func_0038D0B0(temp_f20) * temp_f21);
                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                (*(f32 *)((u8 *)(temp_19) + 0x330)) = (f32) (*(f32 *)((u8 *)(temp_19) + 0x330));
                temp_5 = (*(s32 *)((u8 *)(temp_19) + 0x34C));
                if ((temp_5 != -1) && (func_L01_00456500(temp_17, temp_5) == 0)) {
                    (*(f32 *)((u8 *)(temp_19) + 0x330)) = (f32) (*(f32 *)((u8 *)(temp_19) + 0x320));
                }
                (*(s32 *)((u8 *)(temp_19) + 0x340)) = func_00382498(0x12C, 0x212);
                func_L01_0045BD78(arg0, 0.00360000017f, 0.0300000012f, 0.00181514258f, 0.125663713f);
            }
            func_L01_0045A898(arg0, temp_17, (*(f32 *)((u8 *)(arg0) + 0xF8)));
            func_L01_00448890(arg0 + 0xF8, temp_19 + 0x31C, 0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x330)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x334)) - (*(f32 *)((u8 *)(arg0) + 0x14))), 0x3AEDEA14, 0x3AEDEA14, 0x3D0EFA36);
            if (func_0038CF38() < 0.75f) {
                temp_f20_2 = func_00382538();
                temp_f21_2 = func_003824E0(2.0f, 6.0f);
                (*(f32 *)((u8 *)(temp_19) + 0x330)) = 0.0f;
                (*(f32 *)((u8 *)(temp_19) + 0x330)) = (f32) (func_0038D098(temp_f20_2) * temp_f21_2);
                (*(f32 *)((u8 *)(temp_19) + 0x334)) = (f32) (func_0038D0B0(temp_f20_2) * temp_f21_2);
                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                (*(f32 *)((u8 *)(temp_19) + 0x330)) = (f32) (*(f32 *)((u8 *)(temp_19) + 0x330));
                temp_5_2 = (*(s32 *)((u8 *)(temp_19) + 0x34C));
                if ((temp_5_2 != -1) && (func_L01_00456500(temp_17, temp_5_2) == 0)) {
                    (*(f32 *)((u8 *)(temp_19) + 0x330)) = (f32) (*(f32 *)((u8 *)(temp_19) + 0x320));
                }
            }
            if (func_0038CAD0(temp_19 + 0x340) != 0) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xB) {
                    func_003C3A10(arg0, 0xB, 0, 8);
                }
                var_5_2 = 6;
block_284:
                func_L01_004450F0(arg0, var_5_2, -1);
            }
            break;
        case 4:                                     /* switch 2 */
            if (func_L01_004561E0(arg0) != 0) {
                (*(f32 *)((u8 *)(temp_19) + 0x308)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x18));
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x42)) == 3) {
                temp_f0 = func_L01_004395E0(arg0);
                if ((temp_f0 > 2.0f) && (temp_f0 < 10.0f)) {
                    func_0038CF68(&sp30, arg0 + 0xC0, 0.0f);
                    0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                    sp10 = (*(f32 *)((u8 *)(arg0) + 0x10));
                }
                var_condition_bit = temp_f0 > 2.0f;
                if (temp_f0 > 2.0f) {
                    func_003C41A0(&sp18, temp_19 + 0x310, (*(f32 *)((u8 *)(temp_19) + 0x308)) + 1.0f, 0.09375f, 0.15625f, 0.0625f);
                    var_condition_bit = temp_f0 > 2.0f;
                }
                if (var_condition_bit && (temp_f0 < 10.0f)) {
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                    sp20 = sp10;
                    func_L01_0045AA30(arg0, &sp20);
                    func_L01_0045BD10(arg0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))));
                }
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                (*(s32 *)((u8 *)(temp_19) + 0x310)) = 0;
                func_L01_004450F0(arg0, 5U, -1);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 8) {
                    var_5_3 = 8;
block_186:
                    func_003C3A10(arg0, var_5_3, 0, 0);
                }
            }
            break;
        case 5:                                     /* switch 2 */
            temp_f0_2 = func_L01_004395E0(arg0);
            if (temp_f0_2 < 22.0f) {
                func_0038CF68(&sp30, arg0 + 0xC0, 0.0f);
                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                sp10 = (*(f32 *)((u8 *)(arg0) + 0x10));
            }
            if (temp_f0_2 < 15.0f) {
                func_L01_0045BD10(arg0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))));
                func_003C41A0(&sp18, temp_19 + 0x310, func_003C3D30(arg0 + 0x10, 0, 0, 0.5f), 0.0500000045f, 0.416666687f, 0.0500000045f);
            }
            if (temp_f0_2 < 22.0f) {
                0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                sp20 = sp10;
                func_L01_0045AA30(arg0, &sp20);
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                (*(s32 *)((u8 *)(temp_19) + 0x310)) = 0;
                func_L01_004450F0(arg0, 0xBU, -1);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x13) {
                    var_5_4 = 0x13;
                    var_6 = 0;
block_203:
                    func_003C3A10(arg0, var_5_4, var_6, 7);
                }
            }
            break;
        case 8:                                     /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                temp_f20_3 = func_0038DAB8((*(f32 *)((u8 *)(arg0) + 0xF8)), func_L01_00443A18(60.0f, 80.0f) * 0.017453292f);
                temp_f21_3 = func_003824E0(3.0f, 4.0f);
                (*(f32 *)((u8 *)(temp_19) + 0x300)) = 0.0f;
                (*(f32 *)((u8 *)(temp_19) + 0x300)) = (f32) (func_0038D098(temp_f20_3) * temp_f21_3);
                (*(f32 *)((u8 *)(temp_19) + 0x304)) = (f32) (func_0038D0B0(temp_f20_3) * temp_f21_3);
                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                (*(f32 *)((u8 *)(temp_19) + 0x300)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x10));
                func_L01_0045BD78(arg0, 0.00360000017f, 0.0300000012f, 0.00181514258f, 0.125663713f);
            }
            temp_17_2 = temp_19 + 0x300;
            func_L01_0045A898(arg0, temp_17_2, (*(f32 *)((u8 *)(arg0) + 0xF8)));
            func_L01_00448890(arg0 + 0xF8, temp_19 + 0x31C, 0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x300)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x304)) - (*(f32 *)((u8 *)(arg0) + 0x14))), 0x3AEDEA14, 0x3AEDEA14, 0x3D0EFA36);
            if (func_0038CF38() < 0.75f) {
                temp_f20_4 = func_0038DAB8((*(f32 *)((u8 *)(arg0) + 0xF8)), func_L01_00443A18(60.0f, 80.0f) * 0.017453292f);
                temp_f21_4 = func_003824E0(3.0f, 4.0f);
                (*(f32 *)((u8 *)(temp_19) + 0x300)) = 0.0f;
                (*(f32 *)((u8 *)(temp_19) + 0x300)) = (f32) (func_0038D098(temp_f20_4) * temp_f21_4);
                (*(f32 *)((u8 *)(temp_19) + 0x304)) = (f32) (func_0038D0B0(temp_f20_4) * temp_f21_4);
                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                (*(f32 *)((u8 *)(temp_19) + 0x300)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x10));
            }
            if ((func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xF8)), func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14)))) < 1.9198622f) || (*(f32 *)0x1A4D54 > 0.030000001f)) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x13) {
                    func_003C3A10(arg0, 0x13, 0, 5);
                }
                func_L01_004450F0(arg0, 0xBU, -1);
            }
            break;
        case 11:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                func_L01_00459188(arg0, (*(void **)((u8 *)(temp_19) + 0x230)), temp_19 + 0x370);
                func_L01_0045BD78(arg0, 0.00320000015f, 0.100000009f, 0.0100530973f, 0.251327425f);
            }
            temp_f20_5 = fabsf((*(f32 *)((u8 *)(arg0) + 0x18)) - (*(f32 *)((u8 *)(temp_19) + 0x228)));
            if ((*(s32 *)((u8 *)(temp_19) + 0x368)) == 0) {
                temp_16 = temp_19 + 0x370;
                func_L01_00458F78(arg0, temp_16, 0, 0);
                func_L01_0045A7A8(arg0, temp_16, (*(f32 *)((u8 *)(temp_19) + 0x318)));
            } else {
                func_L01_0045BD10(arg0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14))));
            }
            temp_16_2 = arg0 + 0x10;
            temp_17_3 = temp_19 + 0x220;
            if ((func_0038CF38() < 2.5f) && (func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xF8)), func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14)))) < 0.34906584f)) {
                func_L01_004450F0(arg0, 0x10U, -1);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 3) {
                    func_003C3A10(arg0, 3, 0, 8);
                }
            }
            if ((*(s32 *)((u8 *)(temp_19) + 0x360)) != 0) {
                if ((func_0038CF38() < 7.0f) && (func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xF8)), func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14)))) < 0.34906584f)) {
                    (*(s32 *)((u8 *)(temp_19) + 0x364)) = 0;
                    func_L01_004450F0(arg0, 0xCU, -1);
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xF) {
                        func_003C3A10(arg0, 0xF, 0, 8);
                    }
                }
                if (((*(s32 *)((u8 *)(temp_19) + 0x368)) != 0) && (func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xF8)), func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x220)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x224)) - (*(f32 *)((u8 *)(arg0) + 0x14)))) < 0.34906584f)) {
                    (*(s32 *)((u8 *)(temp_19) + 0x364)) = 0;
                    func_L01_004450F0(arg0, 0xCU, -1);
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xF) {
                        func_003C3A10(arg0, 0xF, 0, 8);
                    }
                }
            }
            if (temp_f20_5 > 5.0f) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x13) {
                    func_003C3A10(arg0, 0x13, 0, 8);
                }
                var_5_2 = 0x17;
                goto block_284;
            }
            break;
        case 23:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                (*(s32 *)((u8 *)(temp_19) + 0x458)) = 0;
                (*(s32 *)((u8 *)(temp_19) + 0x454)) = 0;
                temp_2_2 = func_L01_004592A8(arg0, temp_19 + 0x3F0, (*(s32 *)((u8 *)(temp_19) + 0x36C)), temp_19 + 0x420);
                (*(void **)((u8 *)(temp_19) + 0x450)) = temp_2_2;
                sp10 = (*(f32 *)((u8 *)(temp_2_2) + 0x10));
                func_L01_004591B8(arg0, &sp10, temp_19 + 0x370);
                func_L01_0045BD78(arg0, 0.00320000015f, 0.100000009f, 0.0100530973f, 0.251327425f);
            }
            if ((*(s32 *)((u8 *)(temp_19) + 0x458)) == 0) {
                temp_16_3 = temp_19 + 0x370;
                func_L01_00458F78(arg0, temp_16_3, 0, 0);
                func_L01_0045A7A8(arg0, temp_16_3, (*(f32 *)((u8 *)(temp_19) + 0x318)));
            } else {
                func_L01_0045A7A8(arg0, 0 /* Read from unset register $a1 */ + 0x10, (*(f32 *)((u8 *)(temp_19) + 0x318)));
            }
            if (func_0038CF38() <= 1.0f) {
                (*(s32 *)((u8 *)(temp_19) + 0x458)) = 1;
                sp10 = (*(f32 *)((u8 *)(temp_19) + 0x220));
                temp_2_3 = func_L01_004593B8(arg0, (*(void **)((u8 *)(temp_19) + 0x450)), temp_19 + 0x420, temp_19 + 0x454, &sp10);
                (*(void **)((u8 *)(temp_19) + 0x450)) = temp_2_3;
                if (temp_2_3 == 0) {
block_157:
                    func_L01_004450F0(arg0, 0xBU, -1);
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x13) {
                        var_5 = 0x13;
                        goto block_159;
                    }
                }
            }
            break;
        case 12:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                func_L01_0045BD78(arg0, 0.200000003f, 0.0300000012f, 0.00181514258f, 0.125663713f);
                (*(f32 *)((u8 *)(arg0) + 0x48)) = (f32) D_L01_001DD5E4;
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                func_L01_004450F0(arg0, 0xDU, -1);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x10) {
                    func_003C3A10(arg0, 0x10, 0, 3);
                }
            }
            temp_2_4 = (*(void **)((u8 *)(temp_19) + 0x230));
            func_L01_0045AA10(arg0);
            break;
        case 13:                                    /* switch 2 */
            if (((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) && (D_L01_001DD5E8 < (*(s32 *)((u8 *)(temp_19) + 0x364)))) {
                func_L01_004450F0(arg0, 0xEU, -1);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x11) {
                    func_003C3A10(arg0, 0x11, 0, 8);
                }
            }
            if ((func_L01_0044E1B8(arg0, 0x3F800000) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x42)) == 0x10)) {
                (*(f32 *)((u8 *)(arg0) + 0x48)) = 0.5f;
                (*(s32 *)((u8 *)(temp_19) + 0x364)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0x364)) + 1);
                func_003C2F58((*(s32 *)((u8 *)(temp_19) + 0x360)), 0, &sp10);
                if ((*(void **)((u8 *)(temp_19) + 0x230)) != (*(s32 *)((u8 *)(&D_1A4BE0) + 0x25C0))) {
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                    sp20 = (*(f32 *)((u8 *)(temp_19) + 0x220));
                } else {
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                    sp20 = (*(f32 *)((u8 *)(&D_1A4BE0) + 0xD0));
                    func_0038CF68(&sp20, &sp20, D_L01_001DD5E0);
                }
                func_003A52A0();
                func_L01_003CD878((*(s32 *)((u8 *)(temp_19) + 0x360)), &sp10, &sp20, 0, -1, (f32) (*(u8 *)((u8 *)(temp_19) + 0x44)));
            }
            func_L01_0045A9F0(arg0);
            break;
        case 14:                                    /* switch 2 */
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                goto block_157;
            }
            break;
        case 10:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                func_L01_0045BD78(arg0, 0.00320000015f, 0.100000009f, 0.0100530973f, 0.251327425f);
            }
            temp_16_4 = arg0 + 0x10;
            temp_17_4 = temp_19 + 0x220;
            if (func_0038CF38() < 5.0f) {
                func_L01_004450F0(arg0, 0xCU, -1);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xF) {
                    func_003C3A10(arg0, 0xF, 0, 8);
                }
            }
            if (func_L01_0045BDE8(arg0, (*(s32 *)((u8 *)(temp_19) + 0x348))) != 0) {
                if (func_0038CF38() < 5.0f) {
                    func_L01_004450F0(arg0, 0xCU, -1);
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xF) {
                        var_5 = 0xF;
                        goto block_159;
                    }
                } else {
                    goto block_157;
                }
            }
            break;
        case 16:                                    /* switch 2 */
            if (func_L01_004561E0(arg0) != 0) {
                (*(f32 *)((u8 *)(temp_19) + 0x308)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x18));
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x42)) != 3) {
                func_L01_0045AA10(arg0);
            } else {
                temp_f0_3 = func_L01_004395E0(arg0);
                var_condition_bit_2 = temp_f0_3 > 2.0f;
                if (temp_f0_3 > 2.0f) {
                    if (temp_f0_3 < 10.0f) {
                        func_0038CF68(&sp30, arg0 + 0xC0, 0.125f);
                        0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                        sp10 = (*(f32 *)((u8 *)(arg0) + 0x10));
                    }
                    var_condition_bit_2 = temp_f0_3 > 2.0f;
                }
                if (var_condition_bit_2) {
                    sp30 = (*(f32 *)((u8 *)(arg0) + 0x10));
                    if ((*(u8 *)((u8 *)(temp_19) + 0x5F)) != 0) {
                        func_L01_004468C8(arg0, 0, 0x10000, 0, 1, 0, 0x3F400000, 0x3F800000, 0x3F400000);
                    } else {
                        func_L01_004468C8(arg0, 0, 1, 0, 1, 0, 0x3F400000, 0x3F800000, 0x3F400000);
                    }
                    func_003C41A0(&sp18, temp_19 + 0x310, (*(f32 *)((u8 *)(temp_19) + 0x308)) + 0.5f, 0.09375f, 0.15625f, 0.0625f);
                }
                if (!(temp_f0_3 > 2.0f)) {
                    goto block_181;
                }
                if (!(temp_f0_3 < 10.0f)) {
block_181:
                    func_L01_0045AA10(arg0);
                } else {
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                    sp20 = sp10;
                    func_L01_0045AA30(arg0, &sp20);
                }
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                (*(s32 *)((u8 *)(temp_19) + 0x310)) = 0;
                func_L01_004450F0(arg0, 0x12U, -1);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 4) {
                    var_5_3 = 4;
                    goto block_186;
                }
            }
            break;
        case 17:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                (*(f32 *)((u8 *)(temp_19) + 0x314)) = 0.083333336f;
            }
            temp_f0_4 = func_L01_004395E0(arg0);
            if (temp_f0_4 > 15.0f) {
                (*(f32 *)((u8 *)(temp_19) + 0x314)) = (f32) ((*(f32 *)((u8 *)(temp_19) + 0x314)) - 0.004f);
            }
            if (temp_f0_4 < 22.0f) {
                func_0038CF68(&sp30, arg0 + 0xC0, (*(f32 *)((u8 *)(temp_19) + 0x314)));
                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                sp10 = (*(f32 *)((u8 *)(arg0) + 0x10));
            }
            if (temp_f0_4 < 15.0f) {
                func_003C41A0(&sp18, temp_19 + 0x310, func_003C3D30(arg0 + 0x10, 0, 0, 0.5f), 0.0500000045f, 0.416666687f, 0.0500000045f);
            }
            if (!(temp_f0_4 < 22.0f)) {
                func_L01_0045AA10(arg0);
            } else {
                0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                sp20 = sp10;
                func_L01_0045AA30(arg0, &sp20);
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                (*(s32 *)((u8 *)(temp_19) + 0x310)) = 0;
                func_L01_004450F0(arg0, 0x13U, -1);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0xB) {
                    var_5_4 = 0xB;
                    var_6 = 8;
                    goto block_203;
                }
            }
            break;
        case 18:                                    /* switch 2 */
            temp_f0_5 = func_L01_004395E0(arg0);
            var_condition_bit_3 = temp_f0_5 < 7.0f;
            if (temp_f0_5 < 7.0f) {
                func_0038CF68(&sp30, arg0 + 0xC0, -0.14285715f);
                0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                sp10 = (*(f32 *)((u8 *)(arg0) + 0x10));
                var_condition_bit_3 = temp_f0_5 < 7.0f;
            }
            if (var_condition_bit_3) {
                func_003C41A0(&sp18, temp_19 + 0x310, func_003C3D30(arg0 + 0x10, 0, 0, 0.5f), 0.0238095243f, 0.178571433f, 0.0476190485f);
            }
            if (!(temp_f0_5 < 7.0f)) {
                func_L01_0045AA10(arg0);
            } else {
                0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                sp20 = sp10;
                func_L01_0045AA30(arg0, &sp20);
            }
            if (func_L01_0044E1B8(arg0, 0x41200000) != 0) {
                (*(s32 *)((u8 *)(temp_19) + 0x310)) = 0;
                func_L01_004450F0(arg0, 0x14U, -1);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 6) {
                    func_003C3A10(arg0, 6, 1, 3);
                }
            }
            break;
        case 20:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                (*(f32 *)((u8 *)(temp_19) + 0x308)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x18));
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x42)) == 6) {
                temp_f0_6 = func_L01_004395E0(arg0);
                var_condition_bit_4 = temp_f0_6 > 4.0f;
                if (temp_f0_6 > 4.0f) {
                    if (temp_f0_6 < 18.0f) {
                        func_0038CF68(&sp30, arg0 + 0xC0, -0.071428575f);
                        0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                        sp10 = (*(f32 *)((u8 *)(arg0) + 0x10));
                    }
                    var_condition_bit_4 = temp_f0_6 > 4.0f;
                }
                if (var_condition_bit_4) {
                    if (temp_f0_6 < 12.0f) {
                        func_003C41A0(&sp18, temp_19 + 0x310, (*(f32 *)((u8 *)(temp_19) + 0x308)) + 0.75f, 0.09375f, 0.1875f, 0.09375f);
                    }
                }
                if (temp_f0_6 == 12.0f) {
                    (*(s32 *)((u8 *)(temp_19) + 0x310)) = 0;
                }
                if ((temp_f0_6 > 12.0f) && (temp_f0_6 < 18.0f)) {
                    func_003C41A0(&sp18, temp_19 + 0x310, func_003C3D30(arg0 + 0x10, 0, 0, 0.5f), 0.020833334f, 0.25f, 0.1875f);
                }
                if (!(temp_f0_6 > 4.0f)) {
                    goto block_239;
                }
                if (!(temp_f0_6 < 18.0f)) {
block_239:
                    func_L01_0045AA10(arg0);
                } else {
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                    sp20 = sp10;
                    func_L01_0045AA30(arg0, &sp20);
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
block_269:
block_270:
                    func_L01_004450F0(arg0, 0xBU, -1);
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x13) {
                        func_003C3A10(arg0, 0x13, 0, 5);
                    }
                }
            }
            break;
        case 1:                                     /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                (*(f32 *)((u8 *)(temp_19) + 0x308)) = (f32) (*(f32 *)((u8 *)(arg0) + 0x18));
            }
            if ((*(u8 *)((u8 *)(arg0) + 0x42)) == 6) {
                temp_f0_7 = func_L01_004395E0(arg0);
                var_condition_bit_5 = temp_f0_7 > 4.0f;
                if (temp_f0_7 > 4.0f) {
                    if (temp_f0_7 < 18.0f) {
                        func_0038CF68(&sp30, arg0 + 0xC0, -0.071428575f);
                        0 /* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 */;
                        sp10 = (*(f32 *)((u8 *)(arg0) + 0x10));
                    }
                    var_condition_bit_5 = temp_f0_7 > 4.0f;
                }
                if (var_condition_bit_5) {
                    if (temp_f0_7 < 12.0f) {
                        func_003C41A0(&sp18, temp_19 + 0x310, (*(f32 *)((u8 *)(temp_19) + 0x308)) + 0.75f, 0.09375f, 0.1875f, 0.09375f);
                    }
                }
                if (temp_f0_7 == 12.0f) {
                    (*(s32 *)((u8 *)(temp_19) + 0x310)) = 0;
                }
                if ((temp_f0_7 > 12.0f) && (temp_f0_7 < 18.0f)) {
                    (*(f32 *)((u8 *)(arg0) + 0x48)) = 0.5f;
                    func_003C41A0(&sp18, temp_19 + 0x310, func_003C3D30(arg0 + 0x10, 0, 0, 0.5f), 0.0625f, 0.625f, 0.5625f);
                }
                if (!(temp_f0_7 > 4.0f)) {
                    goto block_265;
                }
                if (!(temp_f0_7 < 18.0f)) {
block_265:
                    func_L01_0045AA10(arg0);
                } else {
                    0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                    sp20 = sp10;
                    func_L01_0045AA30(arg0, &sp20);
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    (*(f32 *)((u8 *)(arg0) + 0x48)) = 1.0f;
                    goto block_270;
                }
            }
            break;
        case 21:                                    /* switch 2 */
            func_L01_0045AA10(arg0);
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                goto block_269;
            }
            break;
        case 19:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                (*(s16 *)((u8 *)(temp_19) + 0x2F6)) = 0;
            }
            func_L01_0045AA10(arg0);
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x13) {
                    func_003C3A10(arg0, 0x13, 0, 5);
                }
                func_L01_004450F0(arg0, 0xBU, -1);
            }
            /* fallthrough */
        case 22:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                (*(s16 *)((u8 *)(temp_19) + 0x2F6)) = 0;
            }
            func_L01_0045AA10(arg0);
            if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x12) {
                    func_003C3A10(arg0, 0x12, 0, 3);
                }
                var_5_2 = 8;
                goto block_284;
            }
            break;
        case 25:                                    /* switch 2 */
            if (func_L01_004561B8(arg0) != 0) {
                (*(f32 *)((u8 *)(temp_19) + 0x1BC)) = 2.0f;
                (*(f32 *)((u8 *)(temp_19) + 0x1B8)) = 2.0f;
            }
            temp_f1 = (*(f32 *)((u8 *)(temp_19) + 0x358));
            if (temp_f1 < 1.0f) {
                temp_f0_8 = temp_f1 + D_L01_001DD5D4;
                (*(f32 *)((u8 *)(temp_19) + 0x358)) = temp_f0_8;
                if (temp_f0_8 > 1.0f) {
                    (*(f32 *)((u8 *)(temp_19) + 0x358)) = 1.0f;
                }
                (*(f32 *)((u8 *)(arg0) + 0x2C)) = (f32) ((*(f32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x24))) + 0x24)) * (*(f32 *)((u8 *)(temp_19) + 0x358)));
            }
            temp_4_2 = temp_19 + 0x110;
            temp_f20_6 = (*(f32 *)((u8 *)(temp_19) + 0x118));
            temp_f0_9 = (*(f32 *)((u8 *)(temp_19) + 0x120)) * D_L01_001DD5DC;
            (*(f32 *)((u8 *)(temp_19) + 0x118)) = 0.0f;
            (*(f32 *)((u8 *)(temp_19) + 0x120)) = temp_f0_9;
            func_0038CF68(temp_4_2, temp_4_2, temp_f0_9);
            (*(f32 *)((u8 *)(temp_19) + 0x118)) = temp_f20_6;
            (*(f32 *)((u8 *)(temp_19) + 0x9C)) = 0.00392f;
            if (temp_f20_6 > 0.0f) {
                (*(f32 *)((u8 *)(temp_19) + 0x9C)) = 0.00196f;
            }
            temp_2_5 = (*(void **)((u8 *)(temp_19) + 0x354));
            if (temp_2_5 != 0) {
                (*(s32 *)((u8 *)(temp_2_5) + 0x98)) = 0;
            }
            if (func_L01_0045C2A0(arg0, D_L01_001DD5B4, D_L01_001DD5B8, D_L01_001DD5BC) != 0) {
                (*(f32 *)((u8 *)(arg0) + 0x48)) = 1.0f;
                func_L01_0045A9F0(arg0);
                (*(f32 *)((u8 *)(temp_19) + 0x9C)) = 0.00392f;
                (*(f32 *)((u8 *)(temp_19) + 0x1BC)) = 0.75f;
                (*(f32 *)((u8 *)(temp_19) + 0x1B8)) = 0.2f;
                func_L01_004450F0(arg0, 0xBU, 3);
                if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x13) {
                    func_003C3A10(arg0, 0x13, func_00382498(0, 0x14), 0);
                }
            }
            temp_4_3 = (*(void **)((u8 *)(temp_19) + 0x354));
            if (temp_4_3 != 0) {
                (*(s32 *)((u8 *)(temp_4_3) + 0x98)) = (s32) (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_4_3) + 0x24))) + 0x10));
            }
            break;
        }
        0 /* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
        sp10 = sp0;
        if (func_0038CEA8(&sp10) < ((*(f32 *)((u8 *)(temp_19) + 0x98)) * 0.5f)) {
            (*(s32 *)((u8 *)(temp_19) + 0x3B0)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0x3B0)) + 1);
        }
        func_L01_003565E0(arg0);
        return;
    case 1:                                         /* switch 1 */
        if ((func_L01_004561E0(arg0) != 0) && ((*(s32 *)((u8 *)(temp_19) + 0x350)) == 0)) {
            (*(s16 *)((u8 *)(temp_19) + 0x2F6)) = (s16) ((s32) ((func_00382498(0, 0x28) * 5) + 2) / 6);
        }
        if (((*(s16 *)((u8 *)(temp_19) + 0x234)) == 1) && (func_0038CB00(temp_19 + 0x2F6) != 0)) {
            if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x13) {
                func_003C3A10(arg0, 0x13, 0, 8);
            }
            func_L01_004450F0(arg0, 0xBU, 3);
            if ((*(s32 *)((u8 *)(temp_19) + 0x348)) != -1) {
                func_L01_004450F0(arg0, 0xAU, -1);
            }
        } else if (((*(s32 *)((u8 *)(temp_19) + 0x2F8)) != 0) && (func_0038CB00(temp_19 + 0x2F6) != 0)) {
            func_L01_004450F0(arg0, (*(u8 *)((u8 *)(arg0) + 0x20)), 2);
            (*(s32 *)((u8 *)(temp_19) + 0x2F8)) = 0;
            if ((*(s32 *)((u8 *)(temp_19) + 0x2F0)) < 0xFA) {
                var_4 = 0x1E0;
block_45:
                var_5_5 = 0x258;
block_46:
                (*(s32 *)((u8 *)(temp_19) + 0x2F0)) = (s32) ((s32) ((func_00382498(var_4, var_5_5) * 5) + 2) / 6);
            }
        }
        goto block_47;
    case 2:                                         /* switch 1 */
        if ((*(s16 *)((u8 *)(temp_19) + 0x234)) != 1) {
            if ((*(s32 *)((u8 *)(temp_19) + 0x2F0)) == 0) {
                func_L01_004450F0(arg0, (*(u8 *)((u8 *)(arg0) + 0x20)), 1);
            }
        } else {
block_41:
            if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x13) {
                func_003C3A10(arg0, 0x13, 0, 8);
            }
            func_L01_004450F0(arg0, 0xBU, 3);
        }
        goto block_47;
    case 3:                                         /* switch 1 */
        if (((*(s16 *)((u8 *)(temp_19) + 0x234)) != 1) && (func_L01_004561E0(arg0) == 0) && ((*(u8 *)((u8 *)(arg0) + 0x20)) != 1)) {
            func_L01_004450F0(arg0, 7U, 2);
            if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 0x12) {
                func_003C3A10(arg0, 0x12, func_00382498(0, 0xA), 8);
            }
            var_4 = 0x30C;
            var_5_5 = 0x384;
            goto block_46;
        }
        goto block_47;
    case 7:                                         /* switch 1 */
        temp_2_6 = func_L01_00454370(arg0, temp_19 + 0x160);
        if ((temp_2_6 & 1) || (((u16) (*(u16 *)((u8 *)(arg0) + 0x96)) >= 0x65U) && ((*(f32 *)((u8 *)(temp_19) + 0x30)) <= 0.0f))) {
            func_L01_00356588(arg0);
            func_L01_00315900(arg0, 0, &func_L01_00356568);
            return;
        }
        if (temp_2_6 & 2) {
            if ((*(s16 *)((u8 *)(temp_19) + 0x234)) == 1) {
                goto block_41;
            }
            func_L01_004450F0(arg0, 9U, 2);
            var_4 = 0x244;
            goto block_45;
        }
        goto block_47;
    }
}
