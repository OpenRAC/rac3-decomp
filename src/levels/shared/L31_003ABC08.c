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

INCLUDE_ASM("asm/levels", func_L31_003ABD70);

INCLUDE_ASM("asm/levels", func_L31_003ABF70);

/* localdecomp:start func_L31_003AC0B0 */

extern u8 *func_003C24B0(s32 a, s32 b);
extern void func_L01_00456160(u8 *m, s32 a);
extern void func_L01_00445F40(u8 *m, s32 a);
extern void func_003C7DD8(u8 *m);
extern f32 func_003824E0(f32 a, f32 b);
extern f32 func_0038DB48(f32 a);
extern void func_L01_004450F0(u8 *m, s32 a, s32 b);

u8 *func_L31_003AC0B0(u128_t *a0, u128_t *a1, s32 a2, s32 a3, s32 a4, s32 a5, f32 scale, f32 f1, f32 f2, f32 f3) {
    u8 *m;
    u8 *v;

    m = func_003C24B0(6948, 80);
    if (m != 0) {
        func_L01_00456160(m, 0);
        if (a2 >= 0) {
            func_L01_00445F40(m, a2);
        }
        *(u128_t *)(m + 16) = *a0;
        func_003C7DD8(m);
        *(u16 *)(m + 52) &= ~5;
        *(f32 *)(m + 244) = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        v = *(u8 **)(m + 104);
        *(f32 *)(m + 44) = scale * *(f32 *)(*(u8 **)(m + 36) + 36);
        *(u128_t *)v = *a1;
        *(s32 *)(v + 16) = a3;
        *(f32 *)(v + 24) = f1;
        *(s32 *)(v + 28) = a4;
        *(s32 *)(v + 32) = a5;
        *(f32 *)(v + 36) = f2;
        *(f32 *)(v + 40) = f3;
        *(s32 *)(v + 60) = -1;
        *(s32 *)(m + 152) = 0;
        func_L01_004450F0(m, 0, -1);
        return m;
    }
    return 0;
}
/* localdecomp:end func_L31_003AC0B0 */

/* localdecomp:start func_L31_003AC210 */
void func_L31_003AC210(u8 *obj, s32 a, s32 b, s32 c, s32 d, f32 e, f32 f, f32 g, f32 h) {
    u8 *p = *(u8 **)(obj + 104);
    *(f32 *)(p + 44) = e;
    *(s32 *)(p + 48) = a;
    *(s32 *)(p + 52) = c;
    *(s32 *)(p + 56) = b;
    *(s32 *)(p + 60) = d;
    *(f32 *)(p + 64) = f;
    *(f32 *)(p + 68) = g;
    *(f32 *)(p + 72) = h;
}
/* localdecomp:end func_L31_003AC210 */

INCLUDE_ASM("asm/levels", func_L31_003AC238);

/* localdecomp:start func_L31_003AC410 */
/* Ps2EeAs only uses $gp for these if it knows their size before the use; D_L31_001DF340 gets
   no hint: retail reaches it through $gp only in a delay slot. */
__asm__(".extern D_L31_001DEB00, 4");
__asm__(".extern D_L31_001DEB04, 4");
__asm__(".extern D_L31_001DEB14, 4");
__asm__(".extern D_L31_001DEB18, 4");
__asm__(".extern D_L31_001DEB24, 4");
__asm__(".extern D_L31_001DEB28, 1");
extern s32 D_L31_001DEB00;
extern s32 D_L31_001DEB04;
extern f32 D_L31_001DEB14;
extern s32 D_L31_001DEB18;
extern s32 D_L31_001DEB24;
extern u8 D_L31_001DEB28;
extern s32 D_L31_001DF340;
extern u8 D_L31_001E1D10[] __attribute__((section(".sdata")));
extern u8 D_001A4C60[];
extern void func_L31_003AC578(u8 *, u8 *);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004561B8(u8 *);
extern s32 func_003A52A0(s32, s32, u8 *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern s32 func_0038CAD0(u8 *);
extern void func_L30_0034C8A8(u8 *, u8 *);

void func_L31_003AC410(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    switch (a0[0x20]) {
    case 0:
        *(f32 *)(a0 + 0x14) = *(f32 *)(D_001A4C60 + 4);
        *(f32 *)(a0 + 0x48) = 0.5f;
        if (D_L31_001DEB28 == 0) {
            D_L31_001DEB28 = 1;
            func_L03_0034B218(D_L31_001E1D10, D_L31_001DEB00, D_L31_001DEB04, D_L31_001DEB14, D_L31_001DEB18, (void *)func_L31_003AC578);
        }
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_L01_00456250(a0) != 0) {
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(a0) != 0) {
            if (D_L31_001DF340 >= 11) {
                func_003A52A0(0, 0, a0);
            }
            *(s32 *)(s + 4) = D_L31_001DEB24;
            *(s32 *)(a0 + 0x98) = 0;
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(a0, 1);
        }
        if (func_0038CAD0(s + 4) == 0 && D_L31_001DF340 > D_L31_001DEB24) {
            func_L30_0034C8A8(D_L31_001E1D10, a0);
        }
        break;
    }
}
/* localdecomp:end func_L31_003AC410 */

INCLUDE_ASM("asm/levels", func_L31_003AC578);
