/* PAL near miss (Codex wave 11): near miss: 194 words differ with the file's flags.
 * Worker's note: 194 diff at level 40 (W/out/func_L40_00490080.near.checks/level_40.log), ~11 checks: logic, calls, constants and VU0 sequences (vu0.h vec_copy/vec_sub/vec_add + a j-class vmr32/sqc2 as in L39_005BEAE0.c) follow retail, frame 0x110 matches; left is register allocation: retail keeps stride 0x60 in s7 and the array base in fp (mult+addu, no madd), &D[i] before the inner entry test, tmp as a spilled pseudo at 0x90, and in loop 2 n in s0 with &D[n] recomputed after the call and i+1 spilled to 0x60(sp). Pointer locals give the register stride but mtlo/madd (206); n as s16, re-read index: no gain
 */
#include "common.h"

/* localdecomp:start func_L40_00490080 */
/* Near miss (194 positional diffs with the file's flags). Logic and VU0 sequences follow
   retail; what differs is register allocation: retail keeps the 0x60 stride in a register
   (s7, the inner giv steps by it) and D_L40_002926E0 in fp with mult+addu, computes &D[i]
   before the inner loop's entry test, rematerializes the stack addresses, keeps tmp as a
   reload-spilled pseudo at 0x90, and in the second loop keeps n in s0, recomputes &D[n]
   after the call and spills i + 1 to 0x60(sp). Pointer locals (a = &D[i], b = &D[j]) give
   the register stride but turn &D[i] into mtlo/madd (206 diffs, W/exp/L40_v2.c). */
#include "vu0.h"
typedef struct {
    vu0_v4 pos;
    f32 f10;
    f32 f14;
    f32 f18;
    u8 pad1C[4];
    s16 h20[8];
    f32 f30[8];
    u8 pad50[0x10];
} S_00490080;
extern s32 D_L40_00248628;
extern S_00490080 D_L40_002926E0[];

void func_L40_00490080(void) {
    extern f32 func_0038CF38(void *, void *);
    extern s32 func_L39_005BEAF8(void *, void *, void *);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_0038CF00(void *, void *);
    extern void func_L40_004903C8(s32, s32, f32);
    vu0_v4 up;
    vu0_v4 side;
    vu0_v4 diff;
    vu0_v4 start;
    vu0_v4 end;
    vu0_v4 axis;
    vu0_v4 tmp;
    vu0_q q;
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    f32 z;
    f32 zmin;
    f32 zmax;
    f32 d;

    for (i = 0; i < D_L40_00248628; i++) {
        for (j = i + 1; j < D_L40_00248628; j++) {
            if (func_0038CF38(&D_L40_002926E0[i], &D_L40_002926E0[j]) > 40.0f) {
                continue;
            }
            if (!func_L39_005BEAF8(&D_L40_002926E0[i], &D_L40_002926E0[j], 0)) {
                continue;
            }
            vec_copy(&tmp, &D_L40_002926E0[j]);
            __asm__("vmr32.xyzw %0, vf0" : "=j"(q));
            __asm__("sqc2 %1, %0" : "=m"(axis) : "j"(q));
            vec_sub_ab(&diff, &D_L40_002926E0[i], &tmp);
            vec_copy(&up, &axis);
            func_0038CE90(&side, &diff, &up);
            func_0038CF68(&side, &side, 0.5f);
            vec_add_ba(&start, &D_L40_002926E0[i], &side);
            vec_add_ab(&end, &D_L40_002926E0[j], &side);
            if (!func_L39_005BEAF8(&start, &end, 0)) {
                continue;
            }
            vec_sub_ba(&start, &D_L40_002926E0[i], &side);
            vec_sub_ab(&end, &D_L40_002926E0[j], &side);
            if (func_L39_005BEAF8(&start, &end, 0)) {
                func_L40_004903C8(i, j, func_0038CF00(&D_L40_002926E0[i], &D_L40_002926E0[j]));
            }
        }
    }
    for (i = 0; i < D_L40_00248628; i++) {
        zmax = D_L40_002926E0[i].pos.z;
        zmin = zmax;
        for (k = 0; k < 8; k++) {
            n = D_L40_002926E0[i].h20[k];
            if (n == -1) {
                break;
            }
            d = func_0038CF00(&D_L40_002926E0[i], &D_L40_002926E0[n]);
            if (D_L40_002926E0[i].f10 < d) {
                D_L40_002926E0[i].f10 = d;
            }
            z = D_L40_002926E0[n].pos.z;
            if (z < zmin) {
                zmin = z;
            } else if (zmax < z) {
                zmax = z;
            }
        }
        D_L40_002926E0[i].f14 = zmin - 5.0f;
        D_L40_002926E0[i].f18 = zmax + 5.0f;
        D_L40_002926E0[i].f10 += 2.0f;
    }
}
/* localdecomp:end func_L40_00490080 */
