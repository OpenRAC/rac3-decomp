#include "common.h"

/* NTSC-U counterpart of func_L39_0053D2C0 (src/levels/shared/L39_0053C2A0.c): 0.0628319 -> 0.0523599 */
extern u8 *D_L39_0024C05C;
extern f32 func_00389380(f32, f32);

/* localdecomp:start func_L39_0053CB28 */
typedef int U128_0053D2C0 __attribute__((mode(TI)));
typedef union { U128_0053D2C0 q; f32 f[4]; } Vec4_0053D2C0;

extern s32 D_L39_002412A8;
__asm__(".extern D_L39_002412A8, 16");
extern u8 *D_L39_0024C05C;
extern s32 D_001D72AC_sda_0053CB28;

extern void func_L01_00438908(u8 *, s32, s32, s32);
extern void func_L03_003D7F00(s32);
extern void func_L01_0044E010(void *, void *, s32);
extern void func_L01_0044E358(void *, void *, s32);
extern f32 func_00389380(f32, f32);
extern s32 func_L03_003F4470(void *, void *, void *, s32, s32);
extern s32 func_L39_005BC958(void *, s32, f32);
extern void func_L01_004026A0(void (*)(void *), void *);
extern void func_L03_00300BF8(void *);
extern void func_L03_00300DA8(void *);

void func_L39_0053CB28(u8 *a0) {
    u8 *p;
    u8 *e;
    s32 i;
    s32 t;
    u16 f;
    Vec4_0053D2C0 v;
    s32 u;
    u8 *g;
    p = *(u8 **)(a0 + 0x68);
    if (D_L39_002412A8 == 2) {
        return;
    }
    switch (a0[0x20]) {
    case 0:
        f = *(u16 *)(a0 + 0x34) | 0x1000;
        *(u16 *)(a0 + 0x34) = f;
        if (*(s32 *)(p + 0x30) != -1 ||
            !((t = *(s32 *)(p + 0x3C)) == -1 || (e = D_L39_0024C05C + t * 256) == 0 || e[0x20] == 0xFE || e[0x20] == 0xFD)) {
            a0[0x30] = 0xFF;
            *(u16 *)(a0 + 0x34) = f | 0x41;
            a0[0x20] = 2;
        } else {
            func_L01_00438908(a0, 0xC0, 0xC0, 0xC0);
            for (i = 0; i < 4; i++) {
                func_L03_003D7F00(i);
            }
            if (D_001D72AC_sda_0053CB28 != 0) {
                *(u16 *)(a0 + 0x34) |= 0x100;
                func_L01_0044E010(a0, &v, 1);
                func_L01_0044E358(a0 + 0xC0, &v, 0);
            }
            a0[0x20] = 1;
        }
        break;
    case 1:
        if (*(s16 *)(a0 + 0xAA) == 0x323 || *(s16 *)(a0 + 0xAA) == 0x19C4 || *(s16 *)(a0 + 0xAA) == 0x2F6) {
            *(f32 *)(a0 + 0xF8) = func_00389380(*(f32 *)(a0 + 0xF8), 0.0523598827f);
        }
        break;
    case 2:
        u = *(s32 *)(p + 0x3C);
        if (u != -1) {
            g = D_L39_0024C05C + u * 256;
            if (g == 0 || g[0x20] == 0xFE || g[0x20] == 0xFD) {
                *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x1000) & 0xFFBE;
                func_L03_003F4470(a0, a0 + 0x10, a0 + 0xF0, 0, 0);
                *(s32 *)(p + 0x30) = -1;
                a0[0x20] = 0;
            }
        }
        break;
    }
    v.q = *(U128_0053D2C0 *)(a0 + 0x10);
    v.f[3] = 2.0f;
    if (func_L39_005BC958(&v, 0, 64.0f) > 0) {
        if (*(s16 *)(a0 + 0xAA) != 0x2F6) {
            func_L01_004026A0(func_L03_00300BF8, a0);
        } else {
            func_L01_004026A0(func_L03_00300DA8, a0);
        }
    }
}
/* localdecomp:end func_L39_0053CB28 */
