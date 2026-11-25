/* Exploratory PAL draft (W32, round 27; W18's m2c-style draft reworked). Level 01 with the owning
 * flags (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2): 215 aligned
 * instruction edits (difflib over check.py's instruction lines), 795 positional word differences
 * (the length is 842 against 861 words, so the positional count is dominated by one early shift;
 * W18: 566 aligned / 890 positional), frame 0x150 like retail. What helped, in order: (1) the ray-
 * probe search is a real do/while loop, not goto loop_23: loop.c then hoists the constants
 * 0.0/0.5/1.0/3.0 into f24..f27 as retail (566 -> 386); (2) the vector temp var_v0 removed by
 * storing sp20/sp30 at the early exits (return) instead of a goto to a shared store: frame 0x150
 * (386 -> 349); (3) the order of the two z updates of each probe pair (349 -> 339); (4) the two
 * copies of each probe pair written second-vector first (sp50 = X; sp60 = X in that order): retail
 * stores 0x40 before 0x30 (339 -> 225); (5) the hit flag initialised to 1 before if (arg2) and
 * updated with var = (call == 0) ? 0 : var (retail's movz forms), the odd final ternary dropped
 * (225 -> 215). Still differs: arguments sit in s1..s4 (retail s3..s6: retail's s1/s2 hold the
 * hoisted hi half of D_L01_001EAA20 and the invariant stack addresses &sp50/&sp60), so nearly
 * every use of arg0/arg1 is a one-register diff; two of the calls take sp90/sp94 spilled to the
 * frame in retail.
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00457F20 */
extern s32 D_L01_001A71A0;
extern u8 D_L01_001EAA00;
extern s32 D_L01_001EAA18;
extern vu0_v4 D_L01_001EAA20;

extern void *func_00382348(s32);                  /* extern */
extern f32 func_0038CED8(void *);                          /* extern */
extern f32 func_0038CF38(void *, void *);                  /* extern */
extern s32 func_0038CF68(vu0_v4 *, vu0_v4 *, f32);         /* extern */
extern f32 func_0038D098(f32);                             /* extern */
extern f32 func_0038D0B0(f32);                             /* extern */
extern f32 func_0038D160(f32, f32);                        /* extern */
extern f32 func_0038DAB8(f32, f32);                        /* extern */
extern s32 func_003D3CB0(vu0_v4 *, vu0_v4 *, s32, void *, s32); /* extern */
extern s32 func_003D5630();                                /* extern */

typedef struct { u8 pad[0x1C]; void *profile; } ProbeVars;
typedef struct { u8 pad[0x68]; ProbeVars *vars; } ProbeObject;

void func_L01_00457F20(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, f32 fparg0) {
    vu0_v4 sp;
    vu0_v4 sp10;
    vu0_v4 sp20;                                      /* compiler-managed */
    vu0_v4 sp30;
    vu0_v4 sp40;                                      /* compiler-managed */
    vu0_v4 sp50;
    vu0_v4 sp60;                                      /* compiler-managed */
    vu0_v4 sp70;
    vu0_v4 sp80;
    vu0_v4 *sp90;
    vu0_v4 *sp94;
    vu0_v4 *sp98;
    vu0_v4 *sp9C;
    f32 temp_f0;
    f32 temp_f0_10;
    f32 temp_f0_11;
    f32 temp_f0_12;
    f32 temp_f0_13;
    f32 temp_f0_14;
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
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f20_6;
    f32 temp_f20_7;
    f32 temp_f20_8;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f22;
    f32 var_f23;
    f32 var_f29;
    s16 temp_a0;
    s32 temp_a0_2;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_v1;
    s32 temp_v1_3;
    s32 temp_v1_5;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s0_5;
    s32 var_s7;
    s32 var_s7_2;
    void *temp_a1;
    void *temp_fp;
    void *var_a1;

    temp_a1 = ((ProbeObject *)arg0)->vars->profile;
    if (temp_a1 != 0) {
        sp10 = *(vu0_v4 *)(arg1 + 0x10);
        *(vu0_v4 *)arg1 = sp10;
        sp = *(vu0_v4 *)(arg0 + 0x10);
        temp_a0 = (*(s16 *)((u8 *)(arg0) + (0xAA)));
        if (temp_a0 == 0x16E4 || temp_a0 == 0x16BD) {
            sp.z += 0.25f;
            sp10.z += 0.25f;
        } else {
            sp.z += (*(f32 *)((u8 *)(temp_a1) + (8)));
            sp10.z += (*(f32 *)((u8 *)(temp_a1) + (8)));
        }
        temp_a0_2 = (*(s32 *)((u8 *)(arg1) + (0x50)));
        var_a1 = 0;
        if (temp_a0_2 != 0) {
            var_a1 = func_00382348(temp_a0_2);
        }
        if (((*(s32 *)((u8 *)(arg1) + (0x50))) != D_L01_001A71A0) && (var_a1 != 0)) {
            sp10.z += (*(f32 *)((u8 *)(var_a1) + (0x10)));
        }
        if ((func_003D3CB0(&sp, &sp10, 0x10, arg0, 0) == 0) || ((temp_v1 = D_L01_001EAA18, (temp_v1 != 0)) && (temp_v1 == (*(s32 *)((u8 *)(arg1) + (0x50)))))) {
            var_s0 = 1;
            if (arg2 != 0) {
                sp20 = (*(vu0_v4 *)((u8 *)(arg0) + (0xC0)));
                func_0038CF68(&sp20, &sp20, 3.0f);

                vec_add_ab(&sp20, &sp20, arg0 + 0x10);
                sp30 = sp20;
                sp40 = sp20;
                sp30.z += 1.0f;
                sp40.z -= 3.0f;
                var_s0 = (func_003D3CB0(&sp30, &sp40, 0x20, arg0, 0) == 0) ? 0 : 1;
            }
            if (arg3 != 0) {
                sp20 = (*(vu0_v4 *)((u8 *)(arg0) + (0xC0)));
                func_0038CF68(&sp20, &sp20, 3.0f);

                vec_add_ab(&sp20, &sp20, arg0 + 0x10);
                sp30 = sp20;
                sp40 = sp20;
                sp30.z += 1.0f;
                sp40.z -= 3.0f;
                if (func_003D3CB0(&sp30, &sp40, 0, arg0, 0) != 0) {
                    var_s0 = (func_003D5630() == 0) ? 0 : var_s0;
                }
            }
            if (var_s0 == 0) {
                goto block_22;
            }
        } else {
block_22:
            sp98 = &sp20;
            temp_fp = arg1 + 0x10;
            sp9C = &sp30;
            var_f29 = 10.0f;
            sp90 = &sp50;
            sp94 = &sp60;
            do {

                vec_sub_ab(&sp30, &sp10, &sp);
            temp_f22 = func_0038D160(sp30.x, sp30.y);
            var_f23 = func_0038CED8(sp9C);
            if (var_f23 < fparg0) {
                var_f23 = fparg0;
            }
            temp_f21 = var_f29 * 0.017453292f;
            temp_f0 = func_0038D098(func_0038DAB8(temp_f21, temp_f22)) * var_f23;
            sp20.x = temp_f0;
            temp_f0_2 = func_0038D0B0(func_0038DAB8(temp_f21, temp_f22)) * var_f23;
            sp20.z = 0.0f;
            sp20.y = temp_f0_2;

                vec_add_ab(&sp20, &sp, &sp20);
            if (temp_f0 < 0.0f) {
                sp20.x = 0.5f;
            }
            if (sp20.y < 0.0f) {
                sp20.y = 0.5f;
            }
            if (sp20.z < 0.0f) {
                sp20.z = 0.5f;
            }
            var_s7 = 1;
            if (func_003D3CB0(&sp, sp98, 0x10, arg0, 0) == 0) {
                var_s7 = 0;
                var_s0_2 = 1;
                if (arg2 != 0) {
                    temp_f20 = var_f23 * 0.5f;
                    sp40.x = func_0038D098(func_0038DAB8(temp_f21, temp_f22)) * temp_f20;
                    temp_f0_3 = func_0038D0B0(func_0038DAB8(temp_f21, temp_f22)) * temp_f20;
                    sp40.z = 0.0f;
                    sp40.y = temp_f0_3;

                vec_add_ab(&sp40, &sp, &sp40);
                    sp50 = sp20;
                    sp60 = sp20;
                    sp50.z += 1.0f;
                    sp60.z -= 3.0f;
                    var_s0_2 = (func_003D3CB0(sp90, sp94, 0x20, arg0, 0) == 0) ? 0 : var_s0_2;
                    sp50 = sp40;
                    sp60 = sp40;
                    sp50.z += 1.0f;
                    sp60.z -= 3.0f;
                    var_s0_2 = (func_003D3CB0(sp90, sp94, 0x20, arg0, 0) == 0) ? 0 : var_s0_2;
                }
                if (arg3 != 0) {
                    sp40.x = 2.0f * func_0038D098(func_0038DAB8(temp_f21, temp_f22));
                    temp_f0_4 = 2.0f * func_0038D0B0(func_0038DAB8(temp_f21, temp_f22));
                    sp40.z = 0.0f;
                    sp40.y = temp_f0_4;

                vec_add_ab(&sp40, &sp, &sp40);
                    sp50 = sp20;
                    sp60 = sp20;
                    sp50.z += 1.0f;
                    sp60.z -= 3.0f;
                    if (func_003D3CB0(&sp50, &sp60, 0, arg0, 0) != 0) {
                        var_s0_2 = (func_003D5630() != 0) ? 1 : var_s0_2;
                    }
                    sp50 = sp40;
                    sp60 = sp40;
                    sp50.z += 1.0f;
                    sp60.z -= 3.0f;
                    if (func_003D3CB0(&sp50, &sp60, 0, arg0, 0) != 0) {
                        var_s0_2 = (func_003D5630() == 0) ? 0 : var_s0_2;
                    }
                }
                if (var_s0_2 != 0) {
                    *(vu0_v4 *)arg1 = sp20;
                    return;
                }
                goto block_45;
            }
            temp_v1_3 = (*(s32 *)((u8 *)((void *)&D_L01_001EAA00) + (0x18)));
            if ((temp_v1_3 != 0) && (temp_v1_3 == (*(s32 *)((u8 *)(arg1) + (0x50))))) {
                (*(vu0_v4 *)((u8 *)(arg1) + (0))) = sp20;
            }
block_45:
            if (var_s7 != 0) {
                var_s0_3 = 1;
                vec_sub_ab(&sp40, arg0 + 0x10, (void *)&D_L01_001EAA20);
                sp50 = D_L01_001EAA20;
                if (arg2 != 0) {
                    temp_f20_2 = var_f23 * 0.5f;
                    sp60.x = func_0038D098(func_0038DAB8(temp_f21, temp_f22)) * temp_f20_2;
                    temp_f0_5 = func_0038D0B0(func_0038DAB8(temp_f21, temp_f22)) * temp_f20_2;
                    sp60.z = 0;
                    sp60.y = temp_f0_5;

                vec_add_ab(&sp60, &sp, &sp60);
                    sp70 = sp60;
                    sp80 = sp60;
                    sp70.z += 1.0f;
                    sp80.z -= 3.0f;
                    var_s0_3 = (func_003D3CB0(&sp70, &sp80, 0x20, arg0, 0) == 0) ? 0 : 1;
                }
                if (arg3 != 0) {
                    temp_f20_3 = var_f23 * 0.5f;
                    sp60.x = func_0038D098(func_0038DAB8(temp_f21, temp_f22)) * temp_f20_3;
                    temp_f0_6 = func_0038D0B0(func_0038DAB8(temp_f21, temp_f22)) * temp_f20_3;
                    sp60.z = 0.0f;
                    sp60.y = temp_f0_6;

                vec_add_ab(&sp60, &sp, &sp60);
                    sp70 = sp60;
                    sp80 = sp60;
                    sp70.z += 1.0f;
                    sp80.z -= 3.0f;
                    if (func_003D3CB0(&sp70, &sp80, 0, arg0, 0) != 0) {
                        var_s0_3 = (func_003D5630() == 0) ? 0 : var_s0_3;
                    }
                }
                if (var_s0_3 != 0) {
                    temp_f0_7 = func_0038CED8((vu0_v4 *) &sp40);
                    if (((*(f32 *)((u8 *)(arg1) + (0x44))) < temp_f0_7) && (var_f29 < 60.0f)) {
                        temp_f20_4 = func_0038CF38((void *)&D_L01_001EAA20, temp_fp);
                        if (temp_f20_4 < func_0038CF38(arg1 + 0x30, temp_fp)) {
                            (*(f32 *)((u8 *)(arg1) + (0x44))) = temp_f0_7;
                            (*(vu0_v4 *)((u8 *)(arg1) + (0x30))) = sp50;
                        }
                    }
                }
            }
            temp_f21_2 = -(var_f29 * 0.017453292f);
            temp_f0_8 = func_0038D098(func_0038DAB8(temp_f21_2, temp_f22)) * var_f23;
            sp20.x = temp_f0_8;
            temp_f0_9 = func_0038D0B0(func_0038DAB8(temp_f21_2, temp_f22)) * var_f23;
            sp20.z = 0.0f;
            sp20.y = temp_f0_9;

                vec_add_ab(&sp20, &sp, &sp20);
            if (temp_f0_8 < 0.0f) {
                sp20.x = 0.5f;
            }
            if (sp20.y < 0.0f) {
                sp20.y = 0.5f;
            }
            if (sp20.z < 0.0f) {
                sp20.z = 0.5f;
            }
            var_s7_2 = 1;
            if (func_003D3CB0(&sp, sp98, 0x10, arg0, 0) == 0) {
                var_s7_2 = 0;
                var_s0_4 = 1;
                if (arg2 != 0) {
                    temp_f20_5 = var_f23 * 0.5f;
                    sp40.x = func_0038D098(func_0038DAB8(temp_f21_2, temp_f22)) * temp_f20_5;
                    temp_f0_10 = func_0038D0B0(func_0038DAB8(temp_f21_2, temp_f22)) * temp_f20_5;
                    sp40.z = 0.0f;
                    sp40.y = temp_f0_10;

                vec_add_ab(&sp40, &sp, &sp40);
                    sp50 = sp20;
                    sp60 = sp20;
                    sp50.z += 1.0f;
                    sp60.z -= 3.0f;
                    var_s0_4 = (func_003D3CB0(sp90, sp94, 0x20, arg0, 0) == 0) ? 0 : var_s0_4;
                    sp50 = sp40;
                    sp60 = sp40;
                    sp50.z += 1.0f;
                    sp60.z -= 3.0f;
                    var_s0_4 = (func_003D3CB0(sp90, sp94, 0x20, arg0, 0) == 0) ? 0 : var_s0_4;
                }
                if (arg3 != 0) {
                    sp40.x = 2.0f * func_0038D098(func_0038DAB8(temp_f21_2, temp_f22));
                    temp_f0_11 = 2.0f * func_0038D0B0(func_0038DAB8(temp_f21_2, temp_f22));
                    sp40.z = 0.0f;
                    sp40.y = temp_f0_11;

                vec_add_ab(&sp40, &sp, &sp40);
                    sp50 = sp20;
                    sp60 = sp20;
                    sp50.z += 1.0f;
                    sp60.z -= 3.0f;
                    if (func_003D3CB0(&sp50, &sp60, 0, arg0, 0) != 0) {
                        var_s0_4 = (func_003D5630() != 0) ? 1 : var_s0_4;
                    }
                    sp50 = sp40;
                    sp60 = sp40;
                    sp50.z += 1.0f;
                    sp60.z -= 3.0f;
                    if (func_003D3CB0(&sp50, &sp60, 0, arg0, 0) != 0) {
                        var_s0_4 = (func_003D5630() == 0) ? 0 : var_s0_4;
                    }
                }
                if (var_s0_4 != 0) {
                    *(vu0_v4 *)arg1 = sp20;
                    return;
                }
                goto block_76;
            }
            temp_v1_5 = (*(s32 *)((u8 *)((void *)&D_L01_001EAA00) + (0x18)));
            if ((temp_v1_5 != 0) && (temp_v1_5 == (*(s32 *)((u8 *)(arg1) + (0x50))))) {
                (*(vu0_v4 *)((u8 *)(arg1) + (0))) = sp20;
            }
block_76:
            if (var_s7_2 != 0) {
                var_s0_5 = 1;
                vec_sub_ab(&sp40, arg0 + 0x10, (void *)&D_L01_001EAA20);
                sp50 = D_L01_001EAA20;
                if (arg2 != 0) {
                    temp_f20_6 = var_f23 * 0.5f;
                    sp60.x = func_0038D098(func_0038DAB8(temp_f21_2, temp_f22)) * temp_f20_6;
                    temp_f0_12 = func_0038D0B0(func_0038DAB8(temp_f21_2, temp_f22)) * temp_f20_6;
                    sp60.z = 0;
                    sp60.y = temp_f0_12;

                vec_add_ab(&sp60, &sp, &sp60);
                    sp70 = sp60;
                    sp80 = sp60;
                    sp70.z += 1.0f;
                    sp80.z -= 3.0f;
                    var_s0_5 = (func_003D3CB0(&sp70, &sp80, 0x20, arg0, 0) == 0) ? 0 : 1;
                }
                if (arg3 != 0) {
                    temp_f20_7 = var_f23 * 0.5f;
                    sp60.x = func_0038D098(func_0038DAB8(temp_f21_2, temp_f22)) * temp_f20_7;
                    temp_f0_13 = func_0038D0B0(func_0038DAB8(temp_f21_2, temp_f22)) * temp_f20_7;
                    sp60.z = 0;
                    sp60.y = temp_f0_13;

                vec_add_ab(&sp60, &sp, &sp60);
                    sp70 = sp60;
                    sp80 = sp60;
                    sp70.z += 1.0f;
                    sp80.z -= 3.0f;
                    if (func_003D3CB0(&sp70, &sp80, 0, arg0, 0) != 0) {
                        var_s0_5 = (func_003D5630() == 0) ? 0 : var_s0_5;
                    }
                }
                if (var_s0_5 != 0) {
                    temp_f0_14 = func_0038CED8((vu0_v4 *) &sp40);
                    if (((*(f32 *)((u8 *)(arg1) + (0x44))) < temp_f0_14) && (var_f29 < 60.0f)) {
                        temp_f20_8 = func_0038CF38((void *)&D_L01_001EAA20, temp_fp);
                        if (temp_f20_8 < func_0038CF38(arg1 + 0x30, temp_fp)) {
                            (*(f32 *)((u8 *)(arg1) + (0x44))) = temp_f0_14;
                            (*(vu0_v4 *)((u8 *)(arg1) + (0x30))) = sp50;
                        }
                    }
                }
            }
            var_f29 += 10.0f;
            } while (var_f29 <= 90.0f);
                if ((arg2 != 0) || (arg3 != 0)) {
                    (*(vu0_v4 *)((u8 *)(arg1) + (0))) = (*(vu0_v4 *)((u8 *)(arg1) + (0x30)));
                    if (func_0038CF38(arg0 + 0x10, arg1 + 0x30) < 1.0f) {
                        sp30 = *(vu0_v4 *)(arg0 + 0xC0);
                        func_0038CF68(sp9C, sp9C, fparg0 / 1.25f);

                vec_add_ba(&sp30, &sp30, arg0 + 0x10);
                        *(vu0_v4 *)arg1 = sp30;
                    }
                }
        }
    }
}
/* localdecomp:end func_L01_00457F20 */
