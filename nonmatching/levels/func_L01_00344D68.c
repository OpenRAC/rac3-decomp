/* Exploratory PAL draft (W32, round 27; W18's m2c-style draft reworked). Level 01 with the owning
 * flags (-O2 -G8 -fopt-stack -mno-check-zero-division -fno-sched-interblock @ps2as -mvu0-use-
 * vf0-vf2): 284 aligned instruction edits (difflib over check.py's instruction lines), 907
 * positional word differences (W18: 602 / 934), frame 0xA0 like retail. What helped, in order: (1)
 * the float globals D_L01_001DF6E8/F0/F8/E0 and D_L01_001E1A00 were written and read as s32 (m2c
 * casts), which made cvt.w.s conversions; plain f32 accesses as retail (602 -> 551); (2)
 * D_L01_001A4BE0 / D_L01_001A7E18 declared as unsized arrays so gcse keeps the hi half in a
 * register (551 -> 530); (3) the level switch replaced by if (lvl == 1) / else if (lvl == 2) /
 * else if (lvl >= 3): retail leaves the field alone for level 0 and uses sltiu, no jump table (530
 * -> 516); (4) the three camera-reset arms sit physically BEFORE the long state body in retail: if
 * (state == 3) {reset} else if (f25C4 == 0x74 || D_6694 || func_L01_004BA800()) {reset2} else
 * {long body} (516 -> 379); (5) D_L01_001A4BE0 and D_L01_001A7E18 accessed as typed struct fields
 * (D_L01_001A4BE0_00344D68.f25C4, ...) through per-function aliases instead of (u8 *)&D + offset:
 * struct-member access keeps base register + offset (addiu x,$fp,0x4be0; lw 0x16b0(x)) as retail,
 * the cast form folds the offset into the symbol (379 -> 301); (6) a fourth 16-byte local sp0
 * (dead quadword copy of arg0 + 0x10 at the start of the long body, declared first) gives retail's
 * frame 0xA0 and moves sp20/sp30 to 0x20/0x30 (301 -> 284). Still differs: register numbers of the
 * hi halves (D_001A4BE0 hi is $fp in retail, $s7 here; D_001425C0 / D_002C5600 are s6/s7 in
 * retail), the order of the prologue's constant loads, small scheduling ties.
 */
#include "common.h"
#include "vu0.h"
#include "structs/weapon.h"

/* localdecomp:start func_L01_00344D68 */
extern u8 D_L01_001425C0[];
extern u8 D_L01_001439F4;
typedef struct {
    u8 p0[0x6F0];
    u8 f6F0;
    u8 p6F1[0x4E7];
    s32 fBD8;
    u8 pBDC[0x634];
    s32 f1210;
    u8 p1214[0x10];
    s32 f1224;
    u8 p1228[0x208];
    s32 f1430;
    u8 p1434[0x27C];
    s32 f16B0;
    u8 p16B4[0xF0C];
    void *f25C0;
    s32 f25C4;
    u8 p25C8[0x1D];
    u8 f25E5;
    u8 p25E6[0x3];
    u8 f25E9;
    u8 p25EA[0x3];
    u8 f25ED;
    u8 p25EE[0x286];
    s16 f2874;
    u8 p2876[0x46];
    s32 f28BC;
} GS_4BE0;
extern GS_4BE0 D_L01_001A4BE0_00344D68;
typedef struct { u8 p0[0x144]; u16 f144; u8 p146[0xF2E]; u16 f1074; } GS_7E18;
extern GS_7E18 D_L01_001A7E18_00344D68;
extern void *D_L01_001D52FC;
extern u8 D_L01_001A30B0[];
extern u8 D_L01_001F1B40[];
extern u8 D_L01_002B28F0[];
extern void func_L01_00346620(s32);
__asm__(".extern D_L01_001DD2A8, 4");
__asm__(".extern D_L01_001DD2AC, 4");
__asm__(".extern D_L01_001DD2B0, 4");
__asm__(".extern D_L01_001DD2B4, 4");
__asm__(".extern D_L01_001DD2B8, 4");
__asm__(".extern D_L01_001DD2BC, 1");
__asm__(".extern D_L01_001D52FC, 4");
extern s32 D_L01_001D6694;
extern s32 D_L01_001D7B88;
extern f32 D_L01_001DD2A8;
extern f32 D_L01_001DD2AC;
extern f32 D_L01_001DD2B0;
extern f32 D_L01_001DD2B4;
extern f32 D_L01_001DD2B8;
extern u8 D_L01_001DD2BC;
extern f32 D_L01_001DF6E0;
extern u8 D_L01_001DF6E8;
extern f32 D_L01_001DF6F0;
extern u8 D_L01_001DF6F8;
extern u8 D_L01_001DFB40;
extern u8 D_L01_001DFD38;
extern u8 D_L01_001E1A00;
extern u8 D_L01_001E2A40;
extern u8 D_L01_001E2DC0;
extern u8 D_L01_001E7630;
extern struct WeaponRow D_L01_002C5600[];
extern void *D_L01_001EAA18;

extern f32 *func_00382348(void *);                         /* extern */
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32); /* extern */
extern s32 func_0038CAD0(void *);                          /* extern */
extern s32 func_0038CB00(void *);                          /* extern */
extern s32 func_0038CBA0(s32 *, s32);          /* extern */
extern s32 func_0038CF68(void *, void *, f32);  /* extern */
extern f32 func_0038D160(s32, f32);                    /* extern */
extern s32 func_003A4F28(s32, s32);                    /* extern */
extern s32 func_003A52A0(s32, s32, void *);        /* extern */
extern s32 func_003C2F58(void *, s32, s32 *);  /* extern */
extern s32 func_003C3A10(void *, s32, s32, s32); /* extern */
extern s32 func_003C4B50(void *);                          /* extern */
extern s32 func_003D3CB0(void *, void *, s32, void *, s32); /* extern */
extern s32 func_L01_00345C08(void *);                  /* extern */
extern s32 func_L01_00348160(s32);                     /* extern */
extern s32 func_L01_003F2058(void *, void *);            /* extern */
extern s32 func_L01_003F2278(s32, s32);            /* extern */
extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32); /* extern */
extern void func_L01_00404AD8(void (*)(s32), void *);         /* extern */
extern s32 func_L01_0040E050(void *);                      /* extern */
extern s32 func_L01_0041A938();                        /* extern */
extern s32 func_L01_0041A990();                        /* extern */
extern s32 func_L01_0041BE28(s32, s32); /* extern */
extern s32 func_L01_00424B88(void *, s32, f32, f32); /* extern */
extern s32 func_L01_00424D88(s32);                     /* extern */
extern s32 func_L01_00444F38(void *, s32, s32, s32); /* extern */
extern s32 func_L01_004572B0(void *, s32, s32 *);      /* extern */
extern s32 *func_L01_00457410(s32 *);              /* extern */
extern s32 *func_L01_00457480(s16, s32);               /* extern */
extern void *func_L01_004574B0(s16, s32);                  /* extern */
extern s32 func_L01_004B14C8(s32);                 /* extern */
extern s32 func_L01_004BA800();                            /* extern */
extern s32 func_L01_004EA7D8(s32);                 /* extern */
extern s32 func_L01_005003D0(s32, s32);        /* extern */
extern s32 func_L01_005118D0(s32, s32);            /* extern */
extern s32 func_L01_005119E0(s32);                     /* extern */

void func_L01_00344D68(void *arg0) {
    vu0_v4 sp0;
    vu0_v4 sp10;
    vu0_v4 sp20;
    s32 sp30;
    s32 *temp_v0_4;
    s32 *temp_v0_5;
    s32 *temp_v0_6;
    s32 *var_s0;
    s32 *var_v0_2;
    f32 *temp_s1;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f3;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f2;
    s16 temp_v0_2;
    s16 temp_v1_3;
    s16 var_v0;
    s32 temp_a0_10;
    s32 temp_a0_11;
    s32 temp_a0_12;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_5;
    s32 temp_a0_9;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_v0_3;
    s32 temp_v0_7;
    s32 temp_v0_9;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 var_s0_2;
    s32 var_v1;
    u8 temp_a0;
    u8 temp_v1_4;
    void *temp_a0_4;
    void *temp_a0_6;
    void *temp_a0_7;
    void *temp_a0_8;
    void *temp_s0;
    void *temp_s2;
    void *temp_s4;
    void *temp_v0;
    void *temp_v0_8;
    void *var_a0;

    var_f0 = 0.34906584f;
    temp_s2 = (*(void **)((u8 *)(arg0) + (0x68)));
    if ((u8) D_L01_002C5600[D_L01_001425C0[0x6F]].level >= 2U) {
        var_f0 = 0.17453292f;
    }
    *(f32 *)&D_L01_001E1A00 = var_f0;
    if (D_L01_001A7E18_00344D68.f144 == 0) {
        if ((D_L01_002C5600[D_L01_001425C0[0x6F]].level == 0) && (D_L01_001A4BE0_00344D68.f16B0 == 0)) {
            func_L01_0041BE28(0xB78, 0x1B);
        }
    }
    if (D_L01_001A7E18_00344D68.f1074 == 0) {
        if (D_L01_002C5600[D_L01_001425C0[0x6F]].level == 0) {
            if (D_L01_001A4BE0_00344D68.f16B0 > 0) {
                func_L01_0041BE28(0x186F, 0x15F);
            }
        }
    }
    temp_a0 = D_L01_002C5600[D_L01_001425C0[0x6F]].level;
    if (temp_a0 == 1) {
        (*(s16 *)((u8 *)(arg0) + (0x7C))) = (s16) temp_a0;
    } else if (temp_a0 == 2) {
        (*(s16 *)((u8 *)(arg0) + (0x7C))) = 3;
    } else if (temp_a0 >= 3) {
        (*(s16 *)((u8 *)(arg0) + (0x7C))) = 7;
    }
    if (((*(u8 *)((u8 *)(arg0) + (0x42))) == (*(u8 *)((u8 *)(arg0) + (0x43)))) && ((*(u8 *)((u8 *)(arg0) + (0x60))) & 2)) {
        func_L01_00444F38(arg0, 1, 0, 2);
    }
    if (D_L01_001A4BE0_00344D68.f1224 == 3) {
        if ((*(u8 *)((u8 *)(arg0) + (0x20))) != 0) {
            *(f32 *)&D_L01_001DF6E8 = (f32) (*(f32 *)&D_L01_001DD2A8);
            *(f32 *)&D_L01_001DF6F0 = (f32) (*(f32 *)&D_L01_001DD2AC);
            *(f32 *)&D_L01_001DF6F8 = (f32) (*(f32 *)&D_L01_001DD2B0);
            (*(f32 *)&D_L01_001DF6E0) = (f32) (*(f32 *)&D_L01_001DD2B4);
            func_00382810(0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
            temp_a0_12 = (*(s32 *)((u8 *)(temp_s2) + (0x10)));
            if (temp_a0_12 >= 0) {
                func_L01_00424D88(temp_a0_12);
            }
            (*(s32 *)((u8 *)(temp_s2) + (0x10))) = -1;
            (*(s32 *)&D_L01_001D7B88) = 0xE0;
            func_L01_004B14C8(1);
        }
    } else if ((D_L01_001A4BE0_00344D68.f25C4 == 0x74) || ((*(s32 *)&D_L01_001D6694) != 0) || (func_L01_004BA800() != 0)) {
            if ((*(u8 *)((u8 *)(arg0) + (0x20))) != 4) {
                (*(u8 *)((u8 *)(arg0) + (0x20))) = 4U;
                temp_a0_11 = (*(s32 *)((u8 *)(temp_s2) + (0x10)));
                if (temp_a0_11 >= 0) {
                    func_L01_00424D88(temp_a0_11);
                }
                (*(s32 *)((u8 *)(temp_s2) + (0x10))) = -1;
                *(f32 *)&D_L01_001DF6E8 = (*(f32 *)&D_L01_001DD2A8);
                *(f32 *)&D_L01_001DF6F0 = (f32) (*(f32 *)&D_L01_001DD2AC);
                *(f32 *)&D_L01_001DF6F8 = (f32) (*(f32 *)&D_L01_001DD2B0);
                (*(f32 *)&D_L01_001DF6E0) = (f32) (*(f32 *)&D_L01_001DD2B4);
                func_00382810(0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
                func_L01_004B14C8(1);
            }
    } else {
                if ((*(u8 *)((u8 *)(arg0) + (0x20))) == 4) {
                    (*(u8 *)((u8 *)(arg0) + (0x20))) = 0U;
                }
                sp0 = *(vu0_v4 *)((u8 *)arg0 + 0x10);
                temp_v1 = D_L01_001A4BE0_00344D68.f25C4;
                if (((temp_v1 == 1) || (temp_v1 == 0x1D)) && (D_L01_001A4BE0_00344D68.f25E5 != 0)) {
                    func_L01_0041A938();
                    (*(u8 *)&D_L01_001DD2BC) = 1U;
                } else if ((*(u8 *)&D_L01_001DD2BC) != 0) {
                    func_L01_0041A990();
                    (*(u8 *)&D_L01_001DD2BC) = 0U;
                }
                temp_v1_2 = D_L01_001A4BE0_00344D68.f25C4;
                if (((temp_v1_2 == 1) || (temp_v1_2 == 0x1D)) && (D_L01_001A4BE0_00344D68.f25E5 != 0) && ((*(u8 *)((u8 *)(arg0) + (0x20))) != 0)) {
                    (*(s8 *)((u8 *)(arg0) + (0x31))) = 0;
                    (*(u16 *)((u8 *)(arg0) + (0x34))) = (u16) ((*(u16 *)((u8 *)(arg0) + (0x34))) | 1);
                    func_L01_00404AD8(func_L01_00346620, arg0);
                    *(s32 *)&D_L01_001DFD38 = 1;
                    if ((*(s32 *)&D_L01_001DFB40 & 4) && ((*(void **)((u8 *)(temp_s2) + (0x2C))) = 0, (*(s16 *)((u8 *)(temp_s2) + (0x28))) = 0, func_0038CF68(&sp10, (void *)&D_L01_001E2DC0, 128.0f), vec_add_ab(&sp10, &sp10, (void *)&D_L01_001E2DC0), (func_003D3CB0(&D_L01_001E2A40, &sp10, 0x10, D_L01_001A4BE0_00344D68.f25C0, 0) != 0))) {
                        temp_s0 = D_L01_001EAA18;
                        if ((temp_s0 != 0) && ((*(u8 *)((u8 *)(temp_s0) + (0x31))) != 0)) {
                            temp_s1 = func_00382348(temp_s0);
                            if (func_003C4B50(temp_s0) == 0) {
                                if ((temp_s1 != 0) && (*temp_s1 > 0.0f)) {
                                    temp_v0 = (*(void **)((u8 *)(temp_s0) + (0x24)));
                                    if (temp_v0 != 0) {
                                        if ((*(u8 *)((u8 *)(temp_v0) + (0x46))) == 5) {
                                            temp_v1_3 = (*(s16 *)((u8 *)(temp_s0) + (0xAA)));
                                            if (temp_v1_3 != 0x19C0) {
                                                if (temp_v1_3 != 0x1AE6) {
                                                    goto block_62;
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
block_62:
                                (*(s16 *)((u8 *)(temp_s2) + (0x28))) = 1;
                                (*(void **)((u8 *)(temp_s2) + (0x2C))) = temp_s0;
                            }
                        }
                    }
                    if ((D_L01_001A4BE0_00344D68.f28BC == 0) && ((*(s16 *)((u8 *)(temp_s2) + (0x28))) != 0)) {
                        temp_v0_2 = (*(u16 *)((u8 *)(temp_s2) + (0x2A))) + 1;
                        (*(u16 *)((u8 *)(temp_s2) + (0x2A))) = (u16) temp_v0_2;
                        if (temp_v0_2 >= 0x1A) {
                            (*(u16 *)((u8 *)(temp_s2) + (0x2A))) = 0U;
                        }
                        if (((*(f32 *)((u8 *)(temp_s2) + (4))) <= 0.0f) && (func_L01_005119E0(-1) != 0) && ((s16) (*(u16 *)((u8 *)(temp_s2) + (0x2A))) >= 0xD)) {
                            func_L01_003F6F20(0, arg0, 0x200000FF, 0, 0x20, -1, 4, 0.8f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
                        }
                    }
                } else {
                    *(s32 *)&D_L01_001DFD38 = 0;
                }
                temp_v1_4 = (*(u8 *)((u8 *)(arg0) + (0x20)));
                switch (temp_v1_4) {                /* switch 2; irregular */
                case 0:                             /* switch 2 */
                    (*(s16 *)((u8 *)(temp_s2) + (0))) = 0;
                    (*(f32 *)((u8 *)(temp_s2) + (4))) = 0.36666667f;
                    (*(u8 *)((u8 *)(arg0) + (0x20))) = 3U;
                    temp_f0 = 2.0f * func_0038D160(1.0f, *(f32 *)&D_L01_001E7630);
                    (*(f32 *)((u8 *)(temp_s2) + (8))) = temp_f0;
                    (*(f32 *)&D_L01_001DD2A8) = (f32) *(f32 *)&D_L01_001DF6E8;
                    (*(f32 *)&D_L01_001DD2AC) = (f32) *(f32 *)&D_L01_001DF6F0;
                    (*(f32 *)&D_L01_001DD2B0) = (f32) *(f32 *)&D_L01_001DF6F8;
                    (*(f32 *)&D_L01_001DD2B8) = (f32) (temp_f0 + ((*(f32 *)&D_L01_001E1A00 - temp_f0) * 0.25f));
                    (*(f32 *)&D_L01_001DD2B4) = (f32) *(f32 *)&D_L01_001DF6E0;
                    (*(s32 *)((u8 *)(temp_s2) + (0x14))) = 0;
                    (*(s16 *)((u8 *)(temp_s2) + (0x28))) = 0;
                    (*(u16 *)((u8 *)(temp_s2) + (0x2A))) = 0U;
                    (*(void **)((u8 *)(temp_s2) + (0x2C))) = 0;
                    (*(s32 *)((u8 *)(temp_s2) + (0x10))) = -1;
                    temp_v0_3 = func_L01_004572B0(arg0, 0, &sp30);
                    (*(s32 *)((u8 *)(temp_s2) + (0x18))) = temp_v0_3;
                    if (sp30 == 0) {
                        temp_v0_4 = func_L01_00457480((*(s16 *)((u8 *)(arg0) + (0xAA))), temp_v0_3);
                        (*(s32 **)((u8 *)(temp_s2) + (0x20))) = temp_v0_4;
                        temp_s4 = func_L01_004574B0((*(s16 *)((u8 *)(arg0) + (0xAA))), (*(s32 *)((u8 *)(temp_s2) + (0x18))));
                        var_s0 = func_L01_00457410(temp_v0_4 + 0xC);
                        var_v1 = 2;
                        var_v0_2 = temp_v0_4;
                        do {
                            *var_v0_2 = var_s0;
                            var_v1 -= 1;
                            var_s0 += 0xF00;
                            var_v0_2 += 4;
                        } while (var_v1 >= 0);
                        temp_v0_5 = func_L01_00457410(var_s0);
                        (*(s32 *)((u8 *)(temp_s4) + (0))) = (s32) (temp_v0_5 - temp_v0_4);
                        func_0038CBA0(temp_v0_5, 0x120);
                        temp_v0_6 = func_L01_00457410(temp_v0_5 + 0x120);
                        (*(s32 *)((u8 *)(temp_s4) + (4))) = (s32) (temp_v0_6 - temp_v0_4);
                        func_0038CBA0(temp_v0_6, 0x1E00);
                    }
                    temp_a0_2 = (*(s32 *)((u8 *)(temp_s2) + (0x18)));
                    if (temp_a0_2 >= 0) {
                        func_L01_00348160(temp_a0_2);
                    }
                    break;
                case 1:                             /* switch 2 */
                    if (D_L01_001A4BE0_00344D68.f25C4 != 1) {
                        goto block_90;
                    }
                    func_L01_005003D0(0x1D, 1);
                    if (D_L01_001A4BE0_00344D68.f25C4 != 1) {
block_90:
                        if (D_L01_001A4BE0_00344D68.f25C4 == 0x1D) {
                            goto block_92;
                        }
                    } else {
block_92:
                        if (D_L01_001A4BE0_00344D68.f25E5 != 0) {
                            if ((*(s16 *)((u8 *)(temp_s2) + (0))) == 0) {
                                (*(s32 *)&D_L01_001D7B88) = 0;
                            }
                            (*(s16 *)((u8 *)(temp_s2) + (0))) = 1;
                        }
                    }
                    temp_v0_7 = D_L01_001A4BE0_00344D68.f1430;
                    if (temp_v0_7 != 0) {
                        D_L01_001A4BE0_00344D68.fBD8 = temp_v0_7;
                    }
                    temp_v1_5 = D_L01_001A4BE0_00344D68.f25C4;
                    if (((temp_v1_5 == 1) || (temp_v1_5 == 0x1D)) && (D_L01_001A4BE0_00344D68.f25E5 != 0)) {
                        temp_v0_8 = D_L01_001D52FC;
                        if (*(u8 *)&D_L01_001439F4 != 0) {
                            var_f0_2 = (*(f32 *)((u8 *)(temp_v0_8) + (0x10C)));
                            goto block_104;
                        }
                        var_f0_2 = (*(f32 *)((u8 *)(temp_v0_8) + (0x13C)));
                        var_f2 = (*(f32 *)((u8 *)(temp_v0_8) + (0x134)));
                        if (var_f2 < var_f0_2) {
block_104:
                            var_f2 = -var_f0_2;
                        }
                        if (var_f2 > 0.0f) {
                            if (*(f32 *)&D_L01_001E1A00 < (*(f32 *)&D_L01_001DD2B8)) {
                                temp_a0_3 = (*(s32 *)((u8 *)(temp_s2) + (0x30)));
                                if ((temp_a0_3 == -1) || (temp_a0_4 = (temp_a0_3 << 7) + D_L01_001A30B0, (*(void **)((u8 *)temp_a0_4 + 0xDC) != arg0)) || ((*(u8 *)((u8 *)(temp_a0_4) + (0xD0))) == 0)) {
                                    (*(s32 *)((u8 *)(temp_s2) + (0x30))) = func_003A52A0(2, 4, arg0);
                                }
                                (*(f32 *)&D_L01_001DD2B8) = (f32) ((*(f32 *)&D_L01_001DD2B8) - 0.01f);
                            } else {
                                goto block_113;
                            }
                        } else {
block_113:
                            if ((var_f2 < 0.0f) && ((*(f32 *)&D_L01_001DD2B8) < (*(f32 *)((u8 *)(temp_s2) + (8))))) {
                                temp_a0_5 = (*(s32 *)((u8 *)(temp_s2) + (0x30)));
                                if ((temp_a0_5 == -1) || (temp_a0_6 = (temp_a0_5 << 7) + D_L01_001A30B0, (*(void **)((u8 *)temp_a0_6 + 0xDC) != arg0)) || ((*(u8 *)((u8 *)(temp_a0_6) + (0xD0))) == 0)) {
                                    (*(s32 *)((u8 *)(temp_s2) + (0x30))) = func_003A52A0(3, 4, arg0);
                                }
                                (*(f32 *)&D_L01_001DD2B8) = (f32) ((*(f32 *)&D_L01_001DD2B8) + 0.01f);
                            } else {
                                temp_a1 = (*(s32 *)((u8 *)(temp_s2) + (0x30)));
                                if (temp_a1 != -1) {
                                    temp_a0_7 = (temp_a1 << 7) + D_L01_001A30B0;
                                    if (((*(void **)((u8 *)temp_a0_7 + 0xDC)) == arg0) && ((*(u8 *)((u8 *)(temp_a0_7) + (0xD0))) != 0)) {
                                        func_003A4F28(temp_a1, temp_a1);
                                    }
                                }
                                (*(s32 *)((u8 *)(temp_s2) + (0x30))) = -1;
                            }
                        }
                        temp_f1 = (*(f32 *)&D_L01_001DD2B8);
                        var_f0_3 = (*(f32 *)((u8 *)(temp_s2) + (8)));
                        if ((var_f0_3 < temp_f1) || (var_f0_3 = *(f32 *)&D_L01_001E1A00, (temp_f1 < var_f0_3))) {
                            (*(f32 *)&D_L01_001DD2B8) = var_f0_3;
                        }
                        func_00382810(0, 0, 3, (*(f32 *)&D_L01_001DD2B8), 0.02f, 0.2f, 0.0f);
                        func_L01_004B14C8(0);
                    } else {
                        if ((*(s16 *)((u8 *)(temp_s2) + (0))) != 0) {
                            temp_f1_2 = (*(f32 *)((u8 *)(temp_s2) + (8)));
                            (*(f32 *)&D_L01_001DD2B8) = (f32) (temp_f1_2 + ((*(f32 *)&D_L01_001E1A00 - temp_f1_2) * 0.25f));
                            func_00382810(0, 0, 3, temp_f1_2, 0.005f, 0.2f, 0.0f);
                            (*(s16 *)((u8 *)(temp_s2) + (0))) = 0;
                            *(s32 *)&D_L01_001D7B88 = 0xE0;
                            func_L01_004B14C8(1);
                        }
                        temp_a1_2 = (*(s32 *)((u8 *)(temp_s2) + (0x30)));
                        if (temp_a1_2 != -1) {
                            temp_a0_8 = (temp_a1_2 << 7) + D_L01_001A30B0;
                            if (((*(void **)((u8 *)temp_a0_8 + 0xDC)) == arg0) && ((*(u8 *)((u8 *)(temp_a0_8) + (0xD0))) != 0)) {
                                func_003A4F28(temp_a1_2, temp_a1_2);
                            }
                        }
                        (*(s32 *)((u8 *)(temp_s2) + (0x30))) = -1;
                    }
                    temp_f1_3 = *(f32 *)&D_L01_001E1A00;
                    var_s0_2 = 1;
                    temp_f3 = ((*(f32 *)&D_L01_001DD2B8) - temp_f1_3) / ((*(f32 *)((u8 *)(temp_s2) + (8))) - temp_f1_3);
                    temp_v1_6 = D_L01_001A4BE0_00344D68.f25C4;
                    *(f32 *)&D_L01_001DF6E8 = (f32) ((((*(f32 *)&D_L01_001DD2A8) - 0.03f) * temp_f3) + 0.03f);
                    *(f32 *)&D_L01_001DF6E0 = (f32) ((((*(f32 *)&D_L01_001DD2B4) - 0.010471975f) * temp_f3) + 0.010471975f);
                    (*(f32 *)&D_L01_001DF6F0) = (f32) ((((*(f32 *)&D_L01_001DD2AC) - 0.4f) * temp_f3) + 0.4f);
                    if (((temp_v1_6 == 1) || (temp_v1_6 == 0x1D)) && (D_L01_001A4BE0_00344D68.f25E5 != 0)) {
                        var_s0_2 = (func_0038CAD0((void *)&D_L01_001A4BE0_00344D68.f28BC) == 0) ? 0 : 1;
                    } else {
                        D_L01_001A4BE0_00344D68.f28BC = 0x21;
                    }
                    if ((D_L01_001A4BE0_00344D68.f25ED == 0) && ((*(s32 *)((u8 *)(D_L01_001D52FC) + (0x1A4))) & D_L01_001A4BE0_00344D68.f1210) && (var_s0_2 != 0)) {
                        if (func_L01_005118D0(-1, 1) == 0) {
                            func_003A52A0(1, 0, arg0);
                            var_a0 = D_L01_001D52FC;
                        } else {
                            func_L01_004EA7D8(-1);
                            (*(s32 *)((u8 *)(temp_s2) + (0x1C))) = func_L01_003F2058(D_L01_002B28F0, 0);
                            (*(s16 *)((u8 *)(temp_s2) + (2))) = 2;
                            (*(u8 *)((u8 *)(arg0) + (0x20))) = 2U;
                            func_003C3A10(arg0, 2, 0, 0);
                            var_a0 = D_L01_001D52FC;
                        }
                        if (!((*(s32 *)((u8 *)(var_a0) + (0x1A0))) & D_L01_001A4BE0_00344D68.f1210) || (func_L01_005119E0(-1) == 0) || (D_L01_001A4BE0_00344D68.f25E9 == 0)) {
                            temp_a0_9 = (*(s32 *)((u8 *)(temp_s2) + (0x1C)));
                            if (temp_a0_9 >= 0) {
                                func_L01_003F2278(temp_a0_9, 0);
                                (*(s32 *)((u8 *)(temp_s2) + (0x1C))) = -1;
                            }
                        }
                    }
                    break;
                case 2:                             /* switch 2 */
                    temp_v0_9 = D_L01_001A4BE0_00344D68.f1430;
                    if (temp_v0_9 != 0) {
                        D_L01_001A4BE0_00344D68.fBD8 = temp_v0_9;
                    }
                    if ((func_0038CB00(temp_s2 + 2) != 0) || ((*(s16 *)((u8 *)(temp_s2) + (0))) != 0)) {
                        func_003A52A0(0, 0, arg0);
                        func_L01_00345C08(arg0);
                        *(f32 *)((u8 *)temp_s2 + 4) = 1.0f / D_L01_002C5600[D_L01_001425C0[0x6F]].shots_per_second;
                        (*(u8 *)((u8 *)(arg0) + (0x20))) = 3U;
                    }
                    break;
                case 3:                             /* switch 2 */
                    if (func_L01_0040E050(temp_s2 + 4) != 0) {
                        (*(u8 *)((u8 *)(arg0) + (0x20))) = 1U;
                    }
                    break;
                }
                if ((*(s32 *)((u8 *)(temp_s2) + (0x14))) != 0) {
                    if (func_0038CAD0(temp_s2 + 0x14) == 0) {
                        if ((*(s32 *)((u8 *)(temp_s2) + (0x10))) == -1) {
                            (*(s32 *)((u8 *)(temp_s2) + (0x10))) = func_L01_00424B88(arg0 + 0x10, 0xFF0000FF, 10.0f, 0.0f);
                        }
                        if ((*(s32 *)((u8 *)(temp_s2) + (0x10))) >= 0) {
                            if (D_L01_001A4BE0_00344D68.f2874 == 1) {
                                func_003C2F58(arg0, 1, &sp10);
                                func_0038CF68(&sp20, arg0 + 0xD0, -1.5f);
                            } else {
                                func_003C2F58(arg0, 1, &sp10);
                                func_0038CF68(&sp20, (void *)&D_L01_001A4BE0_00344D68.f6F0, 1.5f);
                            }
                            vec_add_ab(temp_v0_8, &sp10, &sp20);
                            (*(f32 *)((u8 *)((((*(s32 *)((u8 *)(temp_s2) + (0x10))) << 5) + D_L01_001F1B40)) + (0x1C))) = 10.0f;
                            temp_f0_2 = (f32) (*(s32 *)((u8 *)(temp_s2) + (0x14))) / 25.0f;
                            (*(f32 *)(D_L01_001F1B40 + (*(s32 *)((u8 *)temp_s2 + 0x10) << 5))) = temp_f0_2;
                            (*(f32 *)((u8 *)((((*(s32 *)((u8 *)(temp_s2) + (0x10))) << 5) + D_L01_001F1B40)) + (4))) = (f32) (temp_f0_2 * 0.7f);
                            (*(s32 *)((u8 *)((((*(s32 *)((u8 *)(temp_s2) + (0x10))) << 5) + D_L01_001F1B40)) + (8))) = 0;
                        }
                    } else {
                        temp_a0_10 = (*(s32 *)((u8 *)(temp_s2) + (0x10)));
                        if (temp_a0_10 >= 0) {
                            func_L01_00424D88(temp_a0_10);
                        }
                        (*(s32 *)((u8 *)(temp_s2) + (0x10))) = -1;
                    }
                }
    }
}
/* localdecomp:end func_L01_00344D68 */
