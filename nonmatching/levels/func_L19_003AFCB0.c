/* func_L19_003AFCB0 (6,784 B, level 19 only, file L19_003AFB40.c): boss/enemy state machine, no twin.
   Draft status: 137 aligned diff rows of 1,699 (difflib over check.py's two columns, branch / jal targets masked),
   compiles with the file's flags plus `-mvu0-use-vf0-vf2` (vf17 spills without it; text_parts line would change like L01_00353EA0's) and
   `typedef int u128_t __attribute__((mode(TI)))` for the lq/sq copies; w22 round 30, from the old m2c draft (1076 aligned).
   What matched it from the m2c draft: callee prototypes (func_0038CF38(void *, void *) distance; func_00448728(void *, f32, void *, s32,
   f32, f32, f32) with the atan2 result as the FIRST float: it makes the nested call evaluate before p + 0x390), array indexing instead of
   `*(i*4 + &D)`, if-chains for the phase-0 state test, cases in jump-table order, f32 stores for +0x48, u128_t quad copies, plain calls
   (f(a0, N, -1)) in every arm instead of m2c's shared `goto` (cross-jumping rebuilds the shared tail), the D_001A73E8 linked-list walk
   (5 steps over +0xB8) in state 23, vec_*_ab/ba helpers for the 6 vadd/vsub.xyz, `if (p->30 <= 0.0f) {exit} else {switch}`.
   Still differs (all small): cross-jump layout of phase 0 / phase 3 tails (6,1 and 12,2 call blocks), register numbering in states 2, 18
   (loop: p->36c * 0x30 reload, $a1 vs $a0/$v1 temps), 23 (loop temps) and 31 (retail keeps `x != 15 && x != 14` as two compares; ours
   folds it to a range test), a few v0/v1 swaps.  NOT a match; nothing here is steering. The 4 switches of the m2c draft are really: phase
   (4 cases, compare chain) + state jump table (33 entries, case bodies in address order) .
*/
#include "common.h"
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern int func_L01_004561B8(u8 *);
extern int func_L01_004561E0(void *a0);
extern s32 func_00382468(s32);
extern s32 func_0038CB00(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_00456250(void *);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003C2880(void *p);
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C7C38(void *);
extern void func_L01_00409598(u8 *, u8 *, u8 *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00456230(u8 *, s32);
extern void func_L01_00459188(u8 *, u8 *, u8 *);
extern void func_L01_0045BD78(u8 *a0, f32 a, f32 b, f32 c, f32 d);
extern void func_L01_0045C150(void *, void *, s32, s32);
extern void func_L01_004AA7E8(s32, s32);
extern void func_L03_004330B8(s32, s32);
f32 *func_00382348(void *);                         /* extern */
f32 func_L01_004395E0(void *);                  /* extern */
s32 func_L01_004450F0(void *, s32, s32);    /* extern */
s32 func_L01_00445170(void *, s32);         /* extern */
void func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);
s32 func_L01_00448728(void *, f32, void *, s32, f32, f32, f32); /* extern */
s32 func_L01_00454370(void *, void *);              /* extern */
s32 func_L01_00458F78(void *, void *, s32, s32); /* extern */
s32 func_L01_0045A748(void *, void *);          /* extern */
s32 func_L01_0045BDE8(void *, s32);                 /* extern */
s32 func_L05_00355C48(void *);                      /* extern */
s32 func_L05_00356018(void *);                  /* extern */
s32 func_L19_003AFA68(void *, void *);              /* extern */
s32 func_L19_003AFA88(void *);                  /* extern */
s32 func_L19_003AFB40(void *, s32);         /* extern */
s32 func_L19_003B1A80(void *);                  /* extern */
s32 func_L19_003B1E08(void *);                      /* extern */
s32 func_L19_003B2190(void *);                  /* extern */
s32 func_L19_003B2290(void *, f32);             /* extern */
s32 func_L19_003B2370(void *);                  /* extern */
s32 func_L19_003B2538(void *);                      /* extern */
s32 func_L19_003B2748(void *);                  /* extern */
s32 func_L19_003B2880(void *);                      /* extern */
extern u8 *D_L19_001DF34C;
extern u8 *D_L19_001DF71C;
extern s32 D_L19_001DF758;
extern u8 *D_001A73E8[];
extern u8 *D_L19_001DF800;
extern u8 *D_L19_001E8E58;
extern s32 D_L19_0021C260[];
extern s32 *D_L19_0021D500[];



static __inline__ void aim_L19(u8 *a0, u8 *p, f32 c1, f32 c2) {
    func_L01_00448728(a0 + 0xF8, func_0038D160(*(f32 *)(p + 0x220) - *(f32 *)(a0 + 0x10), *(f32 *)(p + 0x224) - *(f32 *)(a0 + 0x14)), p + 0x390, 0, c1, c2, 0.50265485f);
}

void func_L19_003AFCB0(void *arg0) {
    vu0_v4 v10;
    vu0_v4 v20;
    s32 var_5_4;
    s32 var_5_9;
    s32 var_6;
    s32 var_7;
    f32 var_f0;
    f32 *temp_4;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    s16 temp_23;
    s16 temp_2_5;
    s32 var_17;
    s32 *temp_17;
    s32 *temp_17_2;
    s32 *temp_5_4;
    s32 temp_2_3;
    s32 temp_3_5;
    s32 temp_4_3;
    s32 temp_8;
    s32 var_5;
    s32 var_5_10;
    s32 var_5_2;
    s32 var_5_3;
    s32 var_5_5;
    s32 var_5_6;
    s32 var_5_7;
    s32 temp_2_4;
    u16 temp_3_6;
    u8 temp_16;
    u8 temp_2_2;
    u8 temp_3;
    u8 temp_3_2;
    u8 temp_3_3;
    u8 temp_3_4;
    u8 temp_3_7;
    u8 temp_5;
    u8 temp_5_2;
    u8 temp_5_3;
    u8 *temp_16_2;
    u8 *temp_16_3;
    u8 *temp_16_4;
    u8 *temp_16_5;
    u8 *temp_16_6;
    u8 *temp_16_7;
    u8 *temp_19;
    u8 *temp_20;
    u8 *temp_22;
    u8 *temp_2;
    u8 *temp_2_6;
    u8 *temp_4_2;
    u8 *var_16;
    u8 *var_5_8;

    temp_19 = *(void* *)(arg0 + 0x68);
    temp_2 = *(void* *)(temp_19 + 0x39C);
    if (temp_2 != 0) {
        *(s32 *)(temp_2 + 0x98) = 0;
        func_003C7C38(*(void* *)(temp_19 + 0x39C));
    }
    if (func_L19_003B1E08(arg0) == 0) {
        temp_16 = *(u8 *)(arg0 + 0x95);
        switch (temp_16) {                          /* switch 1; irregular */
        case 0:
            *(s32 *)(temp_19 + 0x398) = 1;
            if (*(s16 *)(temp_19 + 0x234) == 1 || (func_L01_00456250(arg0) != 0 && func_0038CB00(temp_19 + 0x3A0) != 0)) {
                temp_5 = *(u8 *)(arg0 + 0x21);
                if ((s32) temp_5 < D_L19_001DF758 && D_L19_0021C260[temp_5] != 0) {
                    func_L03_004330B8(temp_5, 1);
                }
                temp_3 = *(u8 *)(arg0 + 0x20);
                if (temp_3 == 4) {
                    func_L01_004450F0(arg0, 8, 6);
                } else if (temp_3 == 5) {
                    func_L01_004450F0(arg0, 9, 6);
                } else if (*(s16 *)(temp_19 + 0x3A6) != 0) {
                    func_L01_004450F0(arg0, 3, 6);
                } else if (*(s16 *)(temp_19 + 0x234) == 1) {
                    func_L01_004450F0(arg0, 0xC, 2);
                } else {
                    func_L01_004450F0(arg0, 6, 1);
                }
            }
            break;
        case 1:
            func_L01_00456230(arg0, 0);
            if (*(s16 *)(temp_19 + 0x234) == temp_16) {
                temp_5_3 = *(u8 *)(arg0 + 0x21);
                if ((s32) temp_5_3 < D_L19_001DF758 && D_L19_0021C260[temp_5_3] != 0) {
                    func_L03_004330B8(temp_5_3, 1);
                }
                func_L01_004450F0(arg0, 0xC, 2);
            }
            break;
        case 2:                                     /* switch 1 */
            func_L01_00456230(arg0, 0);
            func_L19_003B2370(arg0);
            temp_3_3 = *(u8 *)(arg0 + 0x20);
            if (*(s16 *)(temp_19 + 0x234) == 0) {
                if (temp_3_3 == 0xC) {
                    func_L01_004450F0(arg0, 6, 1);
                } else if (func_L01_004561B8(arg0) == 0) {
                    func_L01_00445170(arg0, 1);
                    *(s32 *)(temp_19 + 0x398) = 6;
                }
            } else if ((temp_3_3 != 0x13) && (temp_3_3 != 0x19) && (func_0038CF38(arg0 + 0x10, temp_19 + 0x220) <= 4.0f) && (fabs_asm((*(f32 *)(arg0 + 0x18) + 1.0f) - *(f32 *)(temp_19 + 0x228)) <= 1.5f)) {
                func_L05_00356018(arg0);
                func_L01_004450F0(arg0, 0x13, -1);
            }
            if (*(s32 *)(temp_19 + 0x370) != 0) {
                aim_L19(arg0, temp_19, 0.0061435592f, 0.0030717796f);
            }
            break;
        case 3:
            *(s16 *)(temp_19 + 0x3AE) = 0;
            if (func_L01_004561E0(arg0) != 0) {
                func_L05_00356018(arg0);
                temp_5_2 = *(u8 *)(arg0 + 0x21);
                if ((s32) temp_5_2 < D_L19_001DF758 && D_L19_0021C260[temp_5_2] != 0) {
                    func_L03_004330B8(temp_5_2, 1);
                }
                *(f32 *)(arg0 + 0x48) = 1.0f;
            }
            if (func_L01_00454370(arg0, temp_19 + 0x160) & 2) {
                if (*(s16 *)(temp_19 + 0x234) != 0) {
                    temp_3_2 = *(u8 *)(arg0 + 0x94);
                    if (temp_3_2 == 5) {
                        func_L01_004450F0(arg0, 9, 2);
                    } else if (temp_3_2 == 1 || temp_3_2 == 4) {
                        func_L01_004450F0(arg0, 0xC, 2);
                    } else {
                        func_L01_004450F0(arg0, *(s32 *)(temp_19 + 0x398), 2);
                    }
                } else {
                    func_L01_004450F0(arg0, 6, 1);
                }
            }
            break;
        }
        if (*(f32 *)(temp_19 + 0x30) <= 0.0f) {
            func_L19_003B2748(arg0);
            func_003C2880(arg0);
        } else {
            temp_2_2 = *(u8 *)(arg0 + 0x20);
            switch (temp_2_2) {                     /* switch 4 */
            case 1:                                 /* switch 4 */
                *(s16 *)(temp_19 + 0x3AE) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    if (*(s16 *)(temp_19 + 0x3A6) != 0) {
                        *(s32 *)(arg0 + 0x98) = 0;
                        *(u16 *)(arg0 + 0x34) = (u16) ((*(u16 *)(arg0 + 0x34) | 0x41) & 0xEFFF);
                        func_L01_004AA7E8(arg0, 1);
                    }
                    func_003C3A10(arg0, 0, 0, 8);
                }
                if (*(u8 *)(arg0 + 0x60) & 2) {
                    if (func_00382468(250) != 0) {
                        func_003C3A10(arg0, 0, 0, 0);
                    } else {
                        func_003C3A10(arg0, 1, 0, 0);
                    }
                }
                break;
            case 2:                                 /* switch 4 */
                *(s16 *)(temp_19 + 0x3AE) = 0;
                temp_16_2 = D_L19_001DF71C + (*(s32 *)(temp_19 + 0x37C) << 8);
                temp_4 = func_00382348(temp_16_2);
                if ((temp_16_2 == 0) || (temp_3_4 = *(u8 *)(temp_16_2 + 0x20), (temp_3_4 == 0xFE)) || (temp_3_4 == 0xFD) || ((temp_4 != 0) && (*temp_4 <= 0.0f)) || ((*(s16 *)(temp_16_2 + 0xAA) == 0x1AB8) && (*(u8 *)(temp_16_2 + 0x95) == 5))) {
                    *(u128_t *)(temp_19 + 0x340) = *(u128_t *)((*(s32 *)(temp_19 + 0x37C) << 8) + D_L19_001DF71C + 0x10);
                    temp_3_5 = *(s32 *)(temp_19 + 0x388) - 1;
                    *(s32 *)(temp_19 + 0x388) = temp_3_5;
                    if (temp_3_5 == 0) {
                        *(s32 *)(temp_19 + 0x37C) = -1;
                        func_L01_004450F0(arg0, 1, 0);
                        func_L01_00456230(arg0, 1);
                        func_L01_00409598(arg0, arg0 + 0x10, arg0 + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                    }
                }
                break;
            case 3:                                 /* switch 4 */
                *(s16 *)(temp_19 + 0x3AE) = 0;
                temp_2_3 = *(s32 *)(temp_19 + 0x388) - 1;
                *(s32 *)(temp_19 + 0x388) = temp_2_3;
                if (temp_2_3 == 0) {
                    if (*(s16 *)(temp_19 + 0x234) == 1) {
                        func_L01_004450F0(arg0, 0xC, 2);
                    } else {
                        func_L01_004450F0(arg0, 6, 1);
                    }
                    func_L01_00456230(arg0, 1);
                    func_L01_00409598(arg0, arg0 + 0x10, arg0 + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                    *(s16 *)(temp_19 + 0x3A6) = 0;
                }
                break;
            case 4:                                 /* switch 4 */
                *(s16 *)(temp_19 + 0x3AE) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    func_003C3A10(arg0, 2, 0, 0x19);
                }
                if (*(u8 *)(arg0 + 0x60) & 2) {
                    if (*(s16 *)(temp_19 + 0x37A) != 0 && *(u16 *)(arg0 + 0x96) >= 0x191U && (func_00382468(8) == 0 || *(u16 *)(arg0 + 0x96) >= 0x3E9U)) {
                        func_003C3A10(arg0, 1, 0, 0x11);
                        *(u16 *)(arg0 + 0x96) = 0U;
                    } else {
                        func_003C3A10(arg0, 2, 0, 0x19);
                    }
                }
                break;
            case 5:                                 /* switch 4 */
                *(s16 *)(temp_19 + 0x3AE) = 0;
                *(f32 *)(temp_19 + 0x1B8) = 2.0f;
                *(s32 *)(arg0 + 0x98) = 0;
                *(u16 *)(arg0 + 0x34) = (u16) (*(u16 *)(arg0 + 0x34) & 0xEFFF);
                if (func_L01_004561B8(arg0) != 0) {
                    func_003C3A10(arg0, 3, 0, 0);
                    *(u128_t *)(temp_19 + 0x340) = *(u128_t *)(arg0 + 0x10);
                    *(f32 *)(temp_19 + 0x34C) = 0.0f;
                    *(s32 *)(arg0 + 0x48) = 0;
                    *(f32 *)(arg0 + 0x18) = (f32) (*(f32 *)(arg0 + 0x18) - 4.0f);
                }
                break;
            case 6:                                 /* switch 4 */
                *(s16 *)(temp_19 + 0x3AE) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    *(u16 *)(temp_19 + 0x394) = 0x3E8U;
                    func_003C3A10(arg0, 1, 0, 8);
                }
                temp_2_4 = *(u16 *)(temp_19 + 0x394) - 1;
                *(u16 *)(temp_19 + 0x394) = temp_2_4;
                if ((temp_2_4 << 0x10) == 0) {
                    if (*(s16 *)(temp_19 + 0x3AA) != 0) {
                        func_L01_004450F0(arg0, 4, 0);
                    } else {
                        func_L01_004450F0(arg0, 1, 0);
                    }
                }
                break;
            case 8:                                 /* switch 4 */
                *(s16 *)(temp_19 + 0x3AE) = 0;
                if ((func_L01_004561B8(arg0) != 0) && (*(u8 *)(arg0 + 0x42) == 2)) {
                    func_003C3A10(arg0, 3, 0, 0);
                    *(f32 *)(arg0 + 0x48) = 0.75f;
                }
                if (*(u8 *)(arg0 + 0x60) & 2) {
                    func_L01_004450F0(arg0, 0xC, 2);
                    *(f32 *)(arg0 + 0x48) = 1.0f;
                }
                break;
            case 9:                                 /* switch 4 */
                *(s16 *)(temp_19 + 0x3AE) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    temp_4_2 = *(void* *)(arg0 + 0x24);
                    temp_3_6 = *(u16 *)(arg0 + 0x34) & 0xFFBE;
                    *(u16 *)(arg0 + 0x34) = temp_3_6;
                    *(u16 *)(arg0 + 0x34) = (u16) (temp_3_6 | (*(u16 *)(temp_4_2 + 0x44) & 0x1000));
                    *(f32 *)(arg0 + 0x48) = 1.0f;
                    *(s32 *)(arg0 + 0x98) = (s32) *(s32 *)(temp_4_2 + 0x10);
                    *(f32 *)(temp_19 + 0x34C) = 0.0f;
                }
                temp_f1 = *(f32 *)(temp_19 + 0x34C) + 0.02f;
                *(f32 *)(temp_19 + 0x34C) = temp_f1;
                *(f32 *)(arg0 + 0x18) = (f32) ((*(f32 *)(temp_19 + 0x348) - 4.0f) + (temp_f1 * temp_f1 * 18.3f));
                if ((u16) *(u16 *)(arg0 + 0x96) >= 0x16U) {
                    func_L01_004450F0(arg0, 0xA, -1);
                    *(f32 *)(temp_19 + 0x34C) = 0.0f;
                }
                break;
            case 10:                                /* switch 4 */
                *(s16 *)(temp_19 + 0x3AE) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    temp_8 = (*(s32 *)((u8 *)(*(void* *)(arg0 + 0x24)) + 0x10));
                    *(s32 *)(arg0 + 0x98) = temp_8;
                    *(u16 *)(arg0 + 0x34) = (u16) (*(u16 *)(arg0 + 0x34) | 0x1000);
                    func_003C3A10(arg0, 4, 0, 8);
                }
                temp_f20 = *(f32 *)(temp_19 + 0x34C) + 0.02f;
                *(f32 *)(temp_19 + 0x34C) = temp_f20;
                func_0038CE20(&v10.x, arg0 + 0xC0, temp_f20 * 0.0f);
                vec_add_ba(arg0 + 0x10, &v10, temp_19 + 0x340);
                temp_f0 = *(f32 *)(arg0 + 0x18) + ((15.0f - (temp_f20 * 25.0f)) * temp_f20);
                *(f32 *)(arg0 + 0x18) = temp_f0;
                temp_f1_2 = *(f32 *)(temp_19 + 0x348);
                if (temp_f0 <= temp_f1_2) {
                    *(f32 *)(arg0 + 0x18) = temp_f1_2;
                    func_L01_004450F0(arg0, 0xB, -1);
                }
                break;
            case 11:                                /* switch 4 */
                *(s16 *)(temp_19 + 0x3AE) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    *(f32 *)(temp_19 + 0x1B8) = 1.0f;
                    func_003C3A10(arg0, 5, 0, 0);
                }
                if (*(u8 *)(arg0 + 0x60) & 2) {
                    func_L01_004450F0(arg0, 0xC, 2);
                }
                break;
            case 12:                                /* switch 4 */
                *(s16 *)(temp_19 + 0x3AE) = 0;
                if (*(s32 *)(temp_19 + 0x364) != -1) {
                    func_L01_004450F0(arg0, 0xD, -1);
                } else {
                    func_L19_003B2190(arg0);
                }
                break;
            case 13:                                /* switch 4 */
                if (func_L01_004561B8(arg0) != 0) {
                    *(s32 *)(temp_19 + 0x398) = 0xD;
                    func_003C3A10(arg0, 0, 0, 0xC);
                    if (*(s16 *)(temp_19 + 0x378) != 0) {
                        temp_5_4 = D_L19_0021D500[*(s32 *)(temp_19 + 0x364)];
                        func_L01_0045C150(arg0, temp_5_4, *temp_5_4 - 1, 0);
                        *(s16 *)(temp_19 + 0x378) = 0;
                    }
                }
                *(s16 *)(temp_19 + 0x3AE) = 1;
                if (func_L01_0045BDE8(arg0, *(s32 *)(temp_19 + 0x364)) != 0) {
                    *(s16 *)(temp_19 + 0x378) = 1;
                    *(s32 *)(temp_19 + 0x364) = -1;
                    func_L19_003B2190(arg0);
                }
                break;
            case 16:                                /* switch 4 */
                if (func_L01_004561B8(arg0) != 0) {
                    *(s32 *)(temp_19 + 0x398) = 0x10;
                    func_003C3A10(arg0, 0, 0, 0xC);
                    if (*(s16 *)(temp_19 + 0x378) != 0) {
                        temp_16_3 = arg0 + 0x10;
                        temp_17 = D_L19_0021D500[*(s32 *)(temp_19 + 0x360)];
                        temp_f20_2 = func_0038CF38(temp_16_3, temp_17 + 4);
                        if (func_0038CF38(temp_16_3, temp_17 + (*temp_17 << 2)) < temp_f20_2) {
                            func_L01_0045C150(arg0, temp_17, 0, *temp_17 - 1);
                        } else {
                            func_L01_0045C150(arg0, temp_17, *temp_17 - 1, 0);
                        }
                    }
                    *(s16 *)(temp_19 + 0x378) = 0;
                }
                *(s16 *)(temp_19 + 0x3AE) = 1;
                if (func_L01_0045BDE8(arg0, *(s32 *)(temp_19 + 0x360)) != 0) {
                    func_L01_004450F0(arg0, 0xF, -1);
                    *(s16 *)(temp_19 + 0x378) = 1;
                }
                break;
            case 15:                                /* switch 4 */
                if (func_L19_003AFA68(arg0, temp_19) != 0) {
                    func_L19_003AFA88(arg0);
                    func_L01_004450F0(arg0, 0xE, -1);
                } else {
                    if (func_L01_004561B8(arg0) != 0) {
                        func_003C3A10(arg0, 6, 0, 8);
                    }
                    aim_L19(arg0, temp_19, 0.020106195f, 0.0061435592f);
                }
                break;
            case 14:                                /* switch 4 */
                if (func_L01_004561B8(arg0) != 0) {
                    *(s32 *)(temp_19 + 0x398) = 0xE;
                    func_003C3A10(arg0, 0, 0, 0xC);
                    if (*(s16 *)(temp_19 + 0x378) != 0) {
                        temp_16_4 = arg0 + 0x10;
                        temp_17_2 = D_L19_0021D500[*(s32 *)(temp_19 + 0x360)];
                        temp_f20_3 = func_0038CF38(temp_16_4, temp_17_2 + 4);
                        if (func_0038CF38(temp_16_4, temp_17_2 + (*temp_17_2 << 2)) < temp_f20_3) {
                            func_L01_0045C150(arg0, temp_17_2, 0, *temp_17_2 - 1);
                        } else {
                            func_L01_0045C150(arg0, temp_17_2, *temp_17_2 - 1, 0);
                        }
                    }
                    *(s16 *)(temp_19 + 0x378) = 0;
                }
                *(s16 *)(temp_19 + 0x3AE) = 1;
                if (func_L01_0045BDE8(arg0, *(s32 *)(temp_19 + 0x360)) != 0) {
                    if (*(s16 *)(temp_19 + 0x3AC) != 0) {
                        *(s32 *)(temp_19 + 0x398) = 0x10;
                    }
                    *(s16 *)(temp_19 + 0x378) = 1;
                    func_L01_004450F0(arg0, 0x14, -1);
                }
                break;
            case 17:                                /* switch 4 */
                if (func_L01_004561B8(arg0) != 0) {
                    *(s32 *)(temp_19 + 0x398) = 0x11;
                    func_003C3A10(arg0, 0, 0, 0xC);
                }
                temp_16_5 = temp_19 + 0x340;
                *(s16 *)(temp_19 + 0x3AE) = 0;
                if (func_0038CF38(arg0 + 0x10, temp_16_5) < 1.0f) {
                    func_L01_004450F0(arg0, 0x14, -1);
                } else {
                    func_L01_0045A748(arg0, temp_16_5);
                }
                break;
            case 18:
                temp_22 = temp_19 + 0x340;
                temp_16_7 = arg0 + 0x10;
                if (func_L01_004561B8(arg0) != 0) {
                    *(s32 *)(temp_19 + 0x398) = 0x12;
                    func_003C3A10(arg0, 0, 0, 0xC);
                    if (*(u8 *)(arg0 + 0x94) != 0x1D) {
                        var_17 = 0;
                        *(u128_t *)(temp_19 + 0x340) = *(u128_t *)(temp_19 + 0x220);
                        temp_23 = *(s16 *)(temp_19 + 0x380);
                        if (*(s16 *)(D_L19_001DF34C + *(s32 *)(temp_19 + 0x36C) * 0x30 + 0x32) > 0) {
                            temp_20 = temp_19 + 0x220;
                            do {
                                if (var_17 != temp_23) {
                                    temp_16_6 = D_L19_001DF800 + (*(s32 *)(*(u8 **)(D_L19_001DF34C + *(s32 *)(temp_19 + 0x36C) * 0x30 + 0x40) + var_17 * 4) << 7);
                                    temp_f20_4 = func_0038CF38(temp_16_6 + 0x30, temp_20);
                                    if (func_0038CF38(temp_22, temp_20) < temp_f20_4) {
                                        *(s16 *)(temp_19 + 0x380) = var_17;
                                        *(u128_t *)(temp_19 + 0x340) = *(u128_t *)(temp_16_6 + 0x30);
                                    }
                                }
                                var_17 += 1;
                            } while (var_17 < *(s16 *)(D_L19_001DF34C + *(s32 *)(temp_19 + 0x36C) * 0x30 + 0x32));
                        }
                    }
                }
                *(s16 *)(temp_19 + 0x3AE) = 1;
                if (func_0038CF38(temp_16_7, temp_22) < 1.0f) {
                    func_L01_004450F0(arg0, 0x14, -1);
                } else {
                    func_L01_0045A748(arg0, temp_22);
                }
                break;
            case 20:                                /* switch 4 */
                *(s16 *)(temp_19 + 0x3AE) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    *(s16 *)(temp_19 + 0x396) = 0;
                    func_003C3A10(arg0, 8, 0, 8);
                }
                if ((*(u8 *)(arg0 + 0x43) == 8) && (func_L05_00355C48(arg0) == 0)) {
                    func_003C3A10(arg0, 6, 0, 8);
                }
                aim_L19(arg0, temp_19, 0.020106195f, 0.0061435592f);
                if ((func_L19_003AFA68(arg0, temp_19) != 0) && (*(u8 *)(arg0 + 0x60) & 2)) {
                    func_L19_003AFA88(arg0);
                    if (*(u8 *)(arg0 + 0x43) == 6) {
                        func_L01_004450F0(arg0, 0x16, -1);
                    } else {
                        func_L01_004450F0(arg0, 0x17, -1);
                    }
                }
                break;
            case 22:                                /* switch 4 */
                *(s16 *)(temp_19 + 0x3AE) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    func_003C3A10(arg0, 8, 0, 8);
                    *(f32 *)(arg0 + 0x48) = 10.0f;
                }
                aim_L19(arg0, temp_19, 0.020106195f, 0.0061435592f);
                if (*(u8 *)(arg0 + 0x60) & 2) {
                    func_L01_004450F0(arg0, 0x17, -1);
                    *(f32 *)(arg0 + 0x48) = 1.0f;
                }
                break;
            case 26:                                /* switch 4 */
                *(s16 *)(temp_19 + 0x3AE) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    *(s32 *)(temp_19 + 0x38C) = (s32) *(s32 *)(temp_19 + 0x384);
                    func_003C3A10(arg0, 0xA, 0, 0);
                    *(f32 *)(arg0 + 0x48) = 1.0f;
                }
                if (*(u8 *)(arg0 + 0x60) & 2) {
                    func_L01_004450F0(arg0, 0x18, -1);
                }
                break;
            case 23:                                /* switch 4 */
                *(s16 *)(temp_19 + 0x3AE) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    if (func_L19_003B2880(arg0) == 0) {
                        func_L05_00356018(arg0);
                        *(s32 *)(temp_19 + 0x38C) = (s32) *(s32 *)(temp_19 + 0x384);
                        func_L01_004450F0(arg0, 0x18, -1);
                    }
                    if (*(s16 *)(temp_19 + 0x396) == 0) {
                        func_L19_003AFB40(arg0, 1);
                    }
                    temp_2_5 = (u16) *(s16 *)(temp_19 + 0x396) + 1;
                    *(s16 *)(temp_19 + 0x396) = temp_2_5;
                    if (temp_2_5 >= 4) {
                        var_5_9 = 8;
                        var_7 = 8;
                    } else {
                        var_5_9 = 9;
                        var_7 = 0;
                    }
                    func_003C3A10(arg0, var_5_9, 0, var_7);
                    *(f32 *)(arg0 + 0x48) = 2.0f;
                }
                temp_2_6 = D_001A73E8[0];
                var_5_9 = 5;
                while (temp_2_6 != 0) {
                    temp_4_2 = *(u8 **)(temp_2_6 + 0xB8);
                    if (temp_4_2 == temp_2_6) {
                        break;
                    }
                    var_5_9 -= 1;
                    if (var_5_9 == 0) {
                        break;
                    }
                    if (temp_2_6 == arg0) {
                        func_L01_004450F0(arg0, 0x1B, -1);
                        break;
                    }
                    temp_2_6 = temp_4_2;
                }
                if (*(u8 *)(arg0 + 0x20) != 0x1B) {
                    aim_L19(arg0, temp_19, 0.0061435592f, 0.0030717796f);
                    if (*(s16 *)(temp_19 + 0x396) < 4 && func_L19_003B2538(arg0) == 0) {
                        *(s16 *)(temp_19 + 0x396) = 4;
                        func_L01_004450F0(arg0, 0x17, -1);
                    } else if (*(u8 *)(arg0 + 0x60) & 2) {
                        if (*(s16 *)(temp_19 + 0x396) >= 4) {
                            func_L01_004450F0(arg0, 0x1A, -1);
                        } else {
                            func_L01_004450F0(arg0, 0x17, -1);
                        }
                    }
                }
                break;
            case 27:                                /* switch 4 */
                *(s16 *)(temp_19 + 0x3AE) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    *(s32 *)(temp_19 + 0x38C) = (s32) *(s32 *)(temp_19 + 0x384);
                    *(f32 *)(arg0 + 0x48) = 1.0f;
                    func_003C3A10(arg0, 0xB, 0, 0);
                    func_L19_003AFB40(arg0, 2);
                }
                if (*(u8 *)(arg0 + 0x60) & 2) {
                    func_L01_004450F0(arg0, 0x18, -1);
                }
                break;
            case 24:                                /* switch 4 */
                *(s16 *)(temp_19 + 0x3AE) = 0;
                func_L05_00356018(arg0);
                *(f32 *)(arg0 + 0x48) = 1.0f;
                func_L01_004450F0(arg0, *(s32 *)(temp_19 + 0x398), -1);
                break;
            case 19:                                /* switch 4 */
                temp_16_7 = temp_19 + 0x240;
                if (func_L01_004561B8(arg0) != 0) {
                    func_003C3A10(arg0, 0, 0, 0xC);
                    func_L01_00459188(arg0, *(s32 *)(temp_19 + 0x230), temp_16_7);
                }
                *(s16 *)(temp_19 + 0x3AE) = 1;
                func_L01_00458F78(arg0, temp_16_7, 0, 0);
                func_L01_0045A748(arg0, temp_16_7);
                if ((func_0038CF38(arg0 + 0x10, temp_19 + 0x220) <= 4.0f) && (fabs_asm((*(f32 *)(arg0 + 0x18) + 1.0f) - *(f32 *)(temp_19 + 0x228)) <= 1.5f)) {
                    func_L01_004450F0(arg0, 0x19, -1);
                }
                break;
            case 25:
                *(s16 *)(temp_19 + 0x3AE) = 0;
                if (func_L01_004561B8(arg0) != 0) {
                    func_003C3A10(arg0, 7, 0, 8);
                    func_L19_003AFB40(arg0, 1);
                }
                aim_L19(arg0, temp_19, 0.0061435592f, 0.0030717796f);
                temp_f1_3 = (f32) (s32) func_L01_004395E0(arg0);
                if (temp_f1_3 >= 13.0f && temp_f1_3 <= 15.0f) {
                    func_003C2F58(arg0, 3, &v10);
                    vec_sub_ba(&v10, &v10, arg0 + 0x10);
                    func_0038CE20(&v10.x, &v10, 0.6f);
                    vec_add_ab(&v10, &v10, arg0 + 0x10);
                    v10.z += 0.3f;
                    func_L01_00446780(arg0, &v10, (*(u8 *)(temp_19 + 0x5F) == 0) ? 1 : 0x10001, 0, 1, 0, 1.4f, (f32) *(u8 *)(temp_19 + 0x45), 2.4f);
                }
                if (D_001A73E8[0] == arg0) {
                    func_L19_003AFB40(arg0, 2);
                }
                if (*(u8 *)(arg0 + 0x60) & 2) {
                    func_L01_004450F0(arg0, *(s32 *)(temp_19 + 0x398), -1);
                }
                break;
            case 30:                                /* switch 4 */
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_0045BD78(arg0, 0.0120000001f, 0.0300000012f, 0.00013962634f, 0.100530975f);
                    func_003C3A10(arg0, 0xE, 0, 8);
                }
                if (*(u8 *)(arg0 + 0x60) & 2) {
                    func_003C3A10(arg0, 0xF, 0, 0xA7);
                    *(f32 *)(arg0 + 0x48) = 100.0f;
                    func_L01_004450F0(arg0, 0x1F, -1);
                }
                break;
            case 31:                                /* switch 4 */
                if ((func_L01_004561B8(arg0) != 0) && ((u32) (*(u8 *)(arg0 + 0x42) - 0xE) >= 2U)) {
                    temp_3_7 = *(u8 *)(arg0 + 0x43);
                    if ((temp_3_7 != 0xF) && (temp_3_7 != 0xE)) {
                        func_003C3A10(arg0, 0xF, 0, 8);
                        *(f32 *)(arg0 + 0x48) = 2.0f;
                    }
                }
                if ((*(u8 *)(arg0 + 0x60) & 2) && (*(s16 *)(temp_19 + 0x234) == 1)) {
                    *(f32 *)(arg0 + 0x48) = 1.0f;
                    func_L01_004450F0(arg0, 0x20, -1);
                }
                break;
            case 32:
                if (func_L01_004561B8(arg0) != 0) {
                    func_003C3A10(arg0, 0x10, 0, 8);
                    func_L01_00459188(arg0, *(s32 *)(temp_19 + 0x230), temp_19 + 0x240);
                }
                if (*(s16 *)(temp_19 + 0x234) == 0) {
                    func_003C3A10(arg0, 0xF, 0, 8);
                    func_L01_004450F0(arg0, 0x1F, -1);
                }
                *(u128_t *)&v10 = *(u128_t *)(arg0 + 0x10);
                v10.z += 0.1f;
                func_0038CE20(&v20.x, arg0 + 0xC0, 1.0f);
                vec_add_ab(&v20, &v20, &v10);
                if (func_003D3CB0(&v10, &v20, 16, arg0, 0) != 0) {
                    if (D_L19_001E8E58 != 0 && *(s16 *)(D_L19_001E8E58 + 0xAA) == 0x1D61) {
                        *(f32 *)(arg0 + 0x18) += 0.020000001f;
                    }
                }
                var_16 = temp_19 + 0x220;
                func_L01_0045A748(arg0, var_16);
                if (func_0038CF38(arg0 + 0x10, var_16) <= 2.8f && fabs_asm((*(f32 *)(arg0 + 0x18) + 1.0f) - *(f32 *)(temp_19 + 0x228)) <= 1.5f && func_L19_003B2290(arg0, 0.2f) != 0) {
                    func_L01_004450F0(arg0, 0x21, -1);
                }
                break;
            case 33:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L19_003AFB40(arg0, 1);
                    func_003C3A10(arg0, 0x11, 0, 8);
                }
                aim_L19(arg0, temp_19, 0.0061435592f, 0.0030717796f);
                temp_f1_4 = (f32) (s32) func_L01_004395E0(arg0);
                if (temp_f1_4 >= 9.0f && temp_f1_4 <= 13.0f) {
                    func_003C2F58(arg0, 2, &v10);
                    vec_sub_ba(&v20, &v10, arg0 + 0x10);
                    func_0038CE20(&v20.x, &v20, 0.7f);
                    vec_add_ab(&v10, &v20, arg0 + 0x10);
                    func_L01_00446780(arg0, &v10, 1, 0, 1, 0, 0.8f, (f32) *(u8 *)(temp_19 + 0x45), 2.4f);
                }
                if (D_001A73E8[0] == arg0) {
                    func_L19_003AFB40(arg0, 2);
                }
                if (*(u8 *)(arg0 + 0x60) & 2) {
                    func_L01_004450F0(arg0, 0x1F, -1);
                }
                break;
            }
            func_L19_003B1A80(arg0);
        }
    }
}
