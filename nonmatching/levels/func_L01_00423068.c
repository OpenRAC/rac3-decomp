/* c53 cut pass (wave 14c, 2026-11-28): r59's VU0 form unchanged, still the closest draft: 85 diff / 68 aligned
 * under '-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2' (tools/check.py --mode S
 * --flags=-mvu0-use-vf0-vf2, divs 2 2 2 injected), same instruction count as retail (285). Finding: retail's
 * loop 2 giv starts from sll a6,6, which loop.c only produces when loop 2's own invariant a6*4 is moved by
 * that loop (simplify_giv_expr looks through movables); here gcse PRE first hoists it above loop 1 into s7
 * and the giv starts from (a6*4)<<4. Retail's early a6*4 (sll at 0xE8, spilled to 0x60) feeds only the
 * func_L01_004234E8 call. Tried: a variable n = a6 * 4 after func_0038D308 for the call (246), the folded
 * loop-2 form buf + a6 * 4 + i (268), i + a6 * 4, buf + (a6 << 2) for the call (85). */
/* PAL first draft (wave 14 r59, 2026-11-28), written from retail. Under its file's line
 * (L01_00422FE0.c: -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses @ps2as) it cannot
 * match: retail has VU0 macro code (lqc2/vadd.xyz/sqc2, the vu0.h vec_add_ba helper, which needs
 * -mvu0-use-vf0-vf2) and gcc's split addresses (lui/addiu of D_L01_001E6D80 and D_L01_002E68E0 scheduled
 * apart). This file is the VU0 form (vec_add_ba at both sites); it gives 85 diff under the existing line
 * '-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2' (tools/check.py --mode S
 * --flags=-mvu0-use-vf0-vf2 with divs '2 2 2' injected). Needs divs row 'func_L01_00423068 2 2 2'.
 * Left there: callee-saved register permutation (l in s4 instead of s3, loop 1 counter/pointer and &tmp
 * swapped) and the a6*4 index: retail spills a6*4 (0x60) for the func_L01_004234E8 block and starts loop
 * 2's giv from a6 (sll 6) with a6 in s7; here gcse hoists loop 2's a6*4 into s7 and a6 is spilled. */
#include "common.h"

/* localdecomp:start func_L01_00423068 */
#include "vu0.h"
typedef struct {
    vu0_v4 pos;
    u8 p10[0x10];
    s128 *buf;
    f32 f24;
    f32 f28;
    s32 f2C;
    u8 p30[0x10];
    void *f40[4];
} S_00423068;
typedef struct {
    u8 p0[0x34];
    s32 f34;
    u8 p38[0x18];
    S_00423068 *f50;
    u8 p54[0x1A0 - 0x54];
    void *list[1];
} G_00423068;
typedef struct {
    vu0_v4 dir;
    vu0_v4 pos;
    vu0_v4 rot;
    f32 f30;
    f32 size;
    s32 lo;
    s32 hi;
    s32 idx;
    s32 f44[4];
} L_00423068;
typedef struct {
    u8 p0[0x10];
    vu0_v4 pos;
    u8 p20[4];
    u8 *f24;
    u8 p28[4];
    f32 f2C;
    u8 p30[0xC0 - 0x30];
    u8 mtx[0x40];
} O_00423068;
extern G_00423068 D_L01_001E6D80;
extern u8 D_L01_001D6B00;
extern u8 D_L01_001D6B40;
extern u8 D_L01_001D6B80;
extern f32 D_L01_001D6B94;
extern u8 D_L01_001D6AF5;
__asm__(".extern D_L01_001D6B00, 1");
__asm__(".extern D_L01_001D6B40, 1");
__asm__(".extern D_L01_001D6B80, 1");
__asm__(".extern D_L01_001D6B94, 4");
__asm__(".extern D_L01_001D6AF5, 1");
extern void func_0038D308(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00404808(void *, s32);
extern void func_L01_00423690(void);
extern u8 D_L01_002E68E0[];
void func_L01_004234E8(s128 *a0, s32 a1);
void func_L01_00423530(s128 *a0, s32 a1);
void func_L01_00423580(void);

void func_L01_00423068(L_00423068 *l, s32 *a1, s32 a2, s32 a3, O_00423068 *a4, s32 a5, s32 a6) {
    s128 mtx[3];
    vu0_v4 tmp;
    vu0_v4 q;
    s32 flag;
    s32 i;
    f32 k;
    f32 r;

    flag = 1;
    if ((l->lo * 5 + 2) / 6 <= D_L01_001E6D80.f34 && D_L01_001E6D80.f34 <= (l->hi * 5 + 2) / 6) {
        k = -1.0f;
        if (((S_00423068 *)D_L01_002E68E0)->buf == 0) {
            ((S_00423068 *)D_L01_002E68E0)->buf = (s128 *)&D_L01_001D6B00;
        }
        func_0038D308(mtx, &l->rot);
        for (i = 0; i < 4; i++) {
            *(s128 *)&q = 0;
            q.y = l->size;
            if (i < 2) {
                q.y = -l->size;
            }
            if (i & 1) {
                q.z = 1.0f;
            } else {
                q.z = -1.0f;
            }
            *(s128 *)&tmp = *(s128 *)&q;
            func_0038D000((s128 *)&D_L01_001D6B40 + i, &tmp, mtx);
            if (k < 0.0f) {
                *(s128 *)&q = ((s128 *)&D_L01_001D6B40)[i];
                func_0038CF68(&q, &q, 1.0f);
                k = 1.0f / fabs_asm(q.z);
            }
        }
        ((S_00423068 *)D_L01_002E68E0)->f28 = 1.0f / l->size;
        ((S_00423068 *)D_L01_002E68E0)->f24 = D_L01_001D6B94;
        *(s128 *)&((S_00423068 *)D_L01_002E68E0)->pos = *(s128 *)&l->pos;
        func_0038D000(&D_L01_001D6B80, l, mtx);
        if (a4 == 0) {
            a4 = D_L01_001E6D80.list[l->idx];
        }
        r = a4->f2C / *(f32 *)(a4->f24 + 0x24);
        for (i = 0; i < 4; i++) {
            func_0038CF68(&tmp, (s128 *)&D_L01_001D6B40 + i, l->f30 * k);
            func_0038D000(((S_00423068 *)D_L01_002E68E0)->buf + (a6 * 4 + i), &tmp, a4->mtx);
            func_0038CE20(((S_00423068 *)D_L01_002E68E0)->buf + (a6 * 4 + i), ((S_00423068 *)D_L01_002E68E0)->buf + (a6 * 4 + i), r);
            vec_add_ba(&((S_00423068 *)D_L01_002E68E0)->buf[a6 * 4 + i], &((S_00423068 *)D_L01_002E68E0)->buf[a6 * 4 + i], &a4->pos);
            vec_add_ba(&((S_00423068 *)D_L01_002E68E0)->buf[a6 * 4 + i], &((S_00423068 *)D_L01_002E68E0)->buf[a6 * 4 + i], &D_L01_001D6B80);
        }
        if (a1 != 0 && (a1[0] * 5 + 2) / 6 <= D_L01_001E6D80.f34 && D_L01_001E6D80.f34 <= (a1[1] * 5 + 2) / 6) {
            func_L01_004234E8(((S_00423068 *)D_L01_002E68E0)->buf + a6 * 4, (s32)a1);
            func_L01_00404808(func_L01_00423580, 0);
            if (a1[5] == 0) {
                flag = 0;
            }
        }
        if (a2 != 0 && a3 != 0) {
            func_L01_00423530(((S_00423068 *)D_L01_002E68E0)->buf, a2);
            func_L01_00404808(func_L01_00423690, 0);
            if (D_L01_001D6AF5 != 0) {
                flag = 0;
            }
        }
    } else {
        flag = 0;
    }
    if (flag != 0 && l->f44[0] >= 0) {
        D_L01_001E6D80.f50 = (S_00423068 *)D_L01_002E68E0;
        for (i = 0; i < 4; i++) {
            if (l->f44[i] >= 0) {
                D_L01_001E6D80.f50->f40[i] = D_L01_001E6D80.list[l->f44[i]];
            } else {
                D_L01_001E6D80.f50->f40[i] = 0;
            }
        }
        D_L01_001E6D80.f50->f2C = a5;
    } else {
        D_L01_001E6D80.f50 = 0;
    }
}
/* localdecomp:end func_L01_00423068 */
