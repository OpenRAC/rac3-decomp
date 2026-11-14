#include "common.h"

/* declared by functions of L32_003A0228.c, which this file was cut from */
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern void func_L30_0034C8A8(void *, void *);
extern void func_L32_003A25B0(void *, f32, f32);
extern void func_L32_003A2508(void *, f32, s32);
extern void func_L32_003A14C8(void *, s32);
extern s32 func_0038CAD0(void *);
extern f32 D_L32_001DE6C8;

/* localdecomp:start func_L32_003A06B8 */
#include "vu0.h"

extern f32 func_003C4088(f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern void func_L01_00404A10(void *, void *);
extern void func_L32_003A2830(void *);
extern void func_L32_003A3420(void *, f32);
extern void func_L32_003A3CA8(void *);
extern void func_L32_003A3E70(void *);
extern u8 D_001A30B0[];
extern u8 D_L32_001E2240_003A06B8[] __attribute__((section(".sdata")));
__asm__(".extern D_L32_001E2240_003A06B8, 16");
extern s32 D_L32_001DE6E4;
extern s32 D_L32_001DE6E0;
extern f32 D_L32_001DE6D0;
extern f32 D_L32_001DE6D4;
extern f32 D_L32_001DE6C4;
extern f32 D_L32_001DE674;
extern f32 D_L32_001DE688[] __attribute__((section(".sdata")));
extern f32 D_L32_001DE698[] __attribute__((section(".sdata")));
extern s32 D_L32_001DF9C0;
extern f32 D_L32_001DE810;
extern f32 D_L32_001DE7E4;
extern f32 D_L32_001E222C;
extern f32 D_L32_001E2224[] __attribute__((section(".sdata")));
extern vu0_q D_L32_001E99A0;

__asm__(".extern D_L32_001DE6E4, 4");
__asm__(".extern D_L32_001DE6E0, 4");
__asm__(".extern D_L32_001DE6D0, 4");
__asm__(".extern D_L32_001DE6D4, 4");
__asm__(".extern D_L32_001DE6C4, 4");
__asm__(".extern D_L32_001DE6C8, 4");
__asm__(".extern D_L32_001DE674, 4");
__asm__(".extern D_L32_001DF9C0, 4");
__asm__(".extern D_L32_001DE810, 4");
__asm__(".extern D_L32_001DE7E4, 4");
__asm__(".extern D_L32_001E222C, 4");
__asm__(".extern D_L32_001E2224, 16");
__asm__(".extern D_L32_001DE688, 8");
__asm__(".extern D_L32_001DE698, 8");

typedef struct {
    u8 pad0[0x1C0];
    vu0_q f1C0;
    f32 f1D0[3];
    u8 pad1DC[0x1EC - 0x1DC];
    s32 f1EC;
    f32 f1F0;
    s32 f1F4;
    u8 pad1F8[0x220 - 0x1F8];
    s32 f220;
} Vars_003A06B8;

void func_L32_003A06B8(void *arg0) {
    Vars_003A06B8 *p;
    f32 one;
    f32 f;
    f32 a;
    s32 i;
    u8 *q;
    vu0_v4 tmp;

    p = *(Vars_003A06B8 **)((u8 *)arg0 + 0x68);
    one = 1.0f;
    f = func_L03_0034B440(1, 0, 0, (f32)p->f220, (f32)D_L32_001DE6E4, one);
    a = func_003C4088(D_L32_001DE6D0, D_L32_001DE6D4, f);
    func_L32_003A25B0(arg0, a, func_003C4088(D_L32_001DE6C4, D_L32_001DE6C8, f));
    func_L32_003A2508(arg0, one, 2);
    for (i = 0; i < 3; i++) {
        p->f1D0[i] += D_L32_001DE698[i];
        if (D_L32_001DE688[i] < p->f1D0[i]) {
            p->f1D0[i] -= D_L32_001DE688[i];
        }
    }
    func_L30_0034C8A8(D_L32_001E2240_003A06B8, arg0);
    func_L30_0034C8A8(D_L32_001E2240_003A06B8, arg0);
    p->f1F0 += D_L32_001DE674;
    if (35.0f < p->f1F0) {
        p->f1F0 = 35.0f;
    }
    vec_sub_ba(&tmp, &p->f1C0, (u8 *)arg0 + 0x10);
    func_0038CF68(&tmp, &tmp, p->f1F0);
    vec_add_ab(&tmp, &tmp, (u8 *)arg0 + 0x10);
    if (func_003D3CB0((u8 *)arg0 + 0x10, &tmp, 2, arg0, 0) != 0) {
        if (p->f1EC == 0) {
            p->f1EC = D_L32_001DF9C0;
            p->f1C0 = D_L32_001E99A0;
        }
        if (func_0038CAD0(D_L32_001E2224) == 0 && D_L32_001E222C < D_L32_001DE810) {
            D_L32_001E2224[2] = D_L32_001E222C + D_L32_001DE7E4;
        }
        func_L32_003A2830(arg0);
        if (func_0038CAD0(&p->f220) != 0) {
            func_L32_003A14C8(arg0, 4);
        }
    }
    if (D_L32_001DE6E4 - D_L32_001DE6E0 < p->f220) {
        s32 idx = p->f1F4;
        if (idx == -1 || (q = D_001A30B0 + (idx << 7), *(void **)(q + 0xDC) != arg0) || *(u8 *)(q + 0xD0) == 0) {
            p->f1F4 = func_003A52A0(3, 4, arg0);
        }
        func_L32_003A3420(arg0, func_L03_0034B440(1, 0, 0, (f32)(p->f220 - (D_L32_001DE6E4 - D_L32_001DE6E0)),
                                                  (f32)D_L32_001DE6E0, 1.0f));
        if (p->f1EC != 0) {
            func_L32_003A3CA8(arg0);
        }
    } else {
        s32 idx = p->f1F4;
        if (idx != -1) {
            q = D_001A30B0 + (idx << 7);
            if (*(void **)(q + 0xDC) == arg0 && *(u8 *)(q + 0xD0) != 0) {
                func_003A4F28(idx);
            }
        }
        p->f1F4 = -1;
    }
    func_L01_00404A10(func_L32_003A3E70, arg0);
}
/* localdecomp:end func_L32_003A06B8 */
