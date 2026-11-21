#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L31_003ABC08 */
/* Ps2EeAs only uses $gp for these if it knows their size before the use. */
__asm__(".extern D_L31_001DEAB8, 4");
__asm__(".extern D_L31_001DEACC, 4");
__asm__(".extern D_L31_001DEAD0, 4");
__asm__(".extern D_L31_001DEAE0, 4");
__asm__(".extern D_L31_001DEAE4, 4");
__asm__(".extern D_L31_001DEAE8, 4");
extern s32 D_L31_001DEAB8;
extern s32 D_L31_001DEACC;
extern s32 D_L31_001DEAD0;
extern f32 D_L31_001DEAE0;
extern s32 D_L31_001DEAE4;
extern s32 D_L31_001DEAE8;
extern u8 D_L31_001E1CF0[] __attribute__((section(".sdata")));
extern void func_L31_003ABF70(u8 *);
extern void func_L31_003ABD70(u8 *, u8 *);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_003A52A0(s32, s32, u8 *);
/* L36_003A7F38.c declares it (f32, u8 *, s32, s32, s32, void *): the same registers; this order gives retail's argument loads */
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern f32 func_L03_0034B148(s32 a0, s32 a1, f32 f);
extern s32 func_0038CAD0(u8 *);
extern void func_003C2880(void *);
extern void func_L30_0034C8A8(u8 *, u8 *);

void func_L31_003ABC08(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 st = a0[0x20];

    switch (st) {
    case 0:
        func_L31_003ABF70(a0);
        break;
    case 1:
        if (func_L01_004561B8(a0) != 0) {
            if (*(s32 *)(s + 0x10) > 0) {
                func_L01_00446780(a0, a0 + 0x10, 1, 0, 1, 0, *(f32 *)(s + 0x24), (f32)*(s32 *)(s + 0x10), 1.0f);
            }
            if (*(s16 *)(a0 + 0xAA) == 0x1B1D) {
                func_003A52A0(0, 0, a0);
            }
            if (D_L31_001DEAE8 == 0) {
                func_L03_0034B218(D_L31_001E1CF0, D_L31_001DEACC, D_L31_001DEAD0, D_L31_001DEAE0, D_L31_001DEAE4, (void *)func_L31_003ABD70);
                D_L31_001DEAE8 = st;
            }
            *(s32 *)(s + 0x14) = D_L31_001DEAB8;
        }
        a0[0x23] = (s32)(func_L03_0034B148(D_L31_001DEAB8 - *(s32 *)(s + 0x14), D_L31_001DEAB8, 0.0f) * 128.0f);
        if (func_0038CAD0(s + 0x14) != 0) {
            func_003C2880(a0);
        } else {
            func_L30_0034C8A8(D_L31_001E1CF0, a0);
        }
        break;
    }
}
/* localdecomp:end func_L31_003ABC08 */

/* localdecomp:start func_L31_003ABD70 */
__asm__(".extern D_L31_001DEABC, 4");
__asm__(".extern D_L31_001DEAC0, 4");
__asm__(".extern D_L31_001DEAC4, 4");
__asm__(".extern D_L31_001DEAC8, 4");
__asm__(".extern D_L31_001DEAD4, 4");
__asm__(".extern D_L31_001DEAD8, 4");
__asm__(".extern D_L31_001DEADC, 4");
extern f32 D_L31_001DEABC;
extern s32 D_L31_001DEAC0;
extern s32 D_L31_001DEAC4;
extern f32 D_L31_001DEAC8;
extern f32 D_L31_001DEAD4;
extern f32 D_L31_001DEAD8;
extern f32 D_L31_001DEADC;
typedef struct { u8 pad0[3]; u8 b3; s32 c4; u8 b8; u8 pad9; s16 tA; f32 xC; f32 v10[4]; } P_003ABD70;
typedef struct { u8 *m; s32 x4; s16 x8; u16 xA; u16 xC; u16 xE; f32 x10; } E_003ABD70;
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);

void func_L31_003ABD70(u8 *arg0, u8 *arg1) {
    P_003ABD70 *p = (P_003ABD70 *)arg0;
    E_003ABD70 *e = (E_003ABD70 *)arg1;
    u8 *m;
    s32 x4;
    f32 a;
    f32 r;
    f32 lo;
    f32 hi;

    if (e == 0) {
        return;
    }
    do {
        m = e->m;
    } while (0);
    x4 = e->x4;
    if (m == 0 || x4 == 0) {
        return;
    }
    if (e->xA & 1) {
        a = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        r = func_003824E0(0.0f, 1.0f) * D_L31_001DEABC * *(f32 *)(m + 0xC) * 0.0009765625f;
        *(u128_t *)p->v10 = *(u128_t *)(m + 0x10);
        p->v10[0] += r * func_0038D098(a);
        p->v10[2] += r * func_0038D0B0(a);
        p->v10[1] += r * func_003824E0(-0.5f, 0.5f);
    }
    e->x10 += D_L31_001DEAC8;
    p->v10[2] += e->x10;
    p->c4 = func_0038DBD8(D_L31_001DEAC0, D_L31_001DEAC4, func_L03_0034B148(p->tA, e->x8, 0.0f));
    lo = (f32)(e->xE & 0xFF);
    hi = lo + D_L31_001DEAD4 * (f32)e->x8 * (f32)(e->xE >> 8) * 0.00390625f;
    p->b8 = func_003C4088(lo, hi, func_L03_0034B148(p->tA, e->x8, 0.0f));
    p->xC = func_003C4088(D_L31_001DEAD8, D_L31_001DEADC, func_L03_0034B148(p->tA, e->x8, 0.0f));
}
/* localdecomp:end func_L31_003ABD70 */
