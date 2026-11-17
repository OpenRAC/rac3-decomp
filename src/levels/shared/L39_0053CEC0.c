#include "common.h"

/* declared by functions of L39_00537998.c, which this file was cut from */
extern void func_L39_005FE358(u8 *, u8 *, void *, s32, f32);
extern u8 *D_L39_0024BF5C;
extern void func_0038CF68(void *, void *, f32);

/* declared by functions of L39_0053C2A0.c, which this file was cut from */
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);

/* localdecomp:start func_L39_0053CEC0 */
typedef struct { u8 b[8]; } S8_0053CEC0;
extern S8_0053CEC0 D_L39_0024ADF0 __attribute__((section(".data")));
extern void func_L39_005FF198(u8 *, u8 *, f32 *);
extern f32 func_0038CE68(void *, void *);
extern void func_L39_005FE358(u8 *, u8 *, void *, s32, f32);
extern s32 func_L39_00620CF8(u8 *, s32);
extern void func_003C2F58(u8 *, s32, u8 *);
extern f32 func_0038DAB8(f32, f32);
extern void func_003D9508(u8 *, s32, s32, s32, f32, f32, f32);
extern f32 func_L39_005B44C8(void);

void func_L39_0053CEC0(u8 *a0) {
    f32 v[4];
    S8_0053CEC0 loc;
    u8 buf[16];
    u8 *p;
    u8 *q;
    u8 *r;

    if (a0 == 0) {
        return;
    }
    if (*(s16 *)(a0 + 170) != 4261) {
        return;
    }
    if (a0[32] == 254) {
        return;
    }
    if (a0[32] == 253) {
        return;
    }
    p = *(u8 **)(a0 + 104);
    if (p == 0) {
        return;
    }
    q = *(u8 **)(p + 80);
    func_L39_005FF198(q, p, v);
    if (func_0038CE68(p + 16, v) <= 0.9f) {
        *(s32 *)(p + 72) = 0;
    } else {
        *(s32 *)(p + 72) = 1;
    }
    loc = D_L39_0024ADF0;
    if (*(s32 *)(p + 68) != 0 && q[6676] != 0) {
        if (*(s32 *)(p + 72) != 0) {
            func_L39_005FE358(p, p + 16, 0, 1, 1.0f);
        } else {
            func_L39_005FE358(p, p + 16, &loc, 1, 1.0f);
        }
    }
    if (func_L39_00620CF8(q, -1) == 0) {
        return;
    }
    r = *(u8 **)(q + 9508);
    if (r == 0) {
        return;
    }
    if (((r[52] ^ 1) & 1) == 0) {
        return;
    }
    if (*(s16 *)(q + 9352) != 0) {
        return;
    }
    func_003C2F58(a0, 1, buf);
    *(f32 *)(p + 84) = func_0038DAB8(*(f32 *)(p + 84), 0.01745329238f);
    func_003D9508(buf, 57, 0x50505050, 1, 0.25f, 0.0f, func_0038DAB8(*(f32 *)(p + 84) * 2.5f, 0.0f));
    func_003D9508(buf, 42, 0x307F2040, 1, 0.25f, 0.0f, func_0038DAB8(-*(f32 *)(p + 84) * 1.5f, 0.0f));
    func_003D9508(buf, 44, 0x307F2040, 1, 0.25f, 0.0f, func_0038DAB8(*(f32 *)(p + 84), 0.0f));
    func_003D9508(buf, 49, 0x30FF7F00, 1, 0.18f, 0.0f, *(f32 *)(p + 84) * 0.5f);
    func_003D9508(buf, 49, 0x30FF7F, 1, 0.18f, 0.0f, *(f32 *)(p + 84) * -0.5f);
    func_003D9508(buf, 47, 0x607F7F7F, 1, 0.06f, 0.0f, func_L39_005B44C8());
}
/* localdecomp:end func_L39_0053CEC0 */

/* localdecomp:start func_L39_0053D1C0 */
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);

void func_L39_0053D1C0(u8 *a0, u8 *b) {
    u8 *p = *(u8 **)(a0 + 104);
    u8 *q = *(u8 **)(p + 80);
    s32 d;
    s32 e;
    f32 *v;
    f32 *dst;

    if (q != 0 && q[0x1A14] != 0) {
        e = q[0x44EE];
        d = q[0x44ED];
        if (e == 3) {
            d += 2;
        } else {
            d += 1;
        }
        d = d % 256;
        e = (e + 1) % 4;
        *(s32 *)(b + 8) = (d << 8) | e;
        if (b[3] == 8) {
            v = (f32 *)(p + 32);
            if (0.40000004f < func_0038CEA8(v)) {
                func_0038CF68(v, v, 0.40000004f);
            }
            dst = (f32 *)(b + 24);
            dst[0] = *(f32 *)(p + 32);
            dst[1] = v[1];
            dst[2] = v[2];
        }
    }
}
/* localdecomp:end func_L39_0053D1C0 */

/* localdecomp:start func_L39_0053D2C0 */
typedef int U128_0053D2C0 __attribute__((mode(TI)));
typedef union { U128_0053D2C0 q; f32 f[4]; } Vec4_0053D2C0;

extern s32 D_L39_00241128;
__asm__(".extern D_L39_00241128, 16");
extern u8 *D_L39_0024BF5C;
extern s32 D_001D72AC_sda;

extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern void func_L03_003DA010(s32);
extern void func_L01_00451290(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, s32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L03_003F6A80(void *, void *, void *, s32, s32);
extern s32 func_L39_005BE900(void *, s32, f32);
extern void func_L01_00404A10(void (*)(void *), void *);
extern void func_L03_00300DA0(void *);
extern void func_L03_00300F50(void *);

void func_L39_0053D2C0(u8 *a0) {
    u8 *p;
    u8 *e;
    s32 i;
    s32 t;
    u16 f;
    Vec4_0053D2C0 v;
    s32 u;
    u8 *g;
    p = *(u8 **)(a0 + 0x68);
    if (D_L39_00241128 == 2) {
        return;
    }
    switch (a0[0x20]) {
    case 0:
        f = *(u16 *)(a0 + 0x34) | 0x1000;
        *(u16 *)(a0 + 0x34) = f;
        if (*(s32 *)(p + 0x30) != -1 ||
            !((t = *(s32 *)(p + 0x3C)) == -1 || (e = D_L39_0024BF5C + t * 256) == 0 || e[0x20] == 0xFE || e[0x20] == 0xFD)) {
            a0[0x30] = 0xFF;
            *(u16 *)(a0 + 0x34) = f | 0x41;
            a0[0x20] = 2;
        } else {
            func_L01_0043B9E8(a0, 0xC0, 0xC0, 0xC0);
            for (i = 0; i < 4; i++) {
                func_L03_003DA010(i);
            }
            if (D_001D72AC_sda != 0) {
                *(u16 *)(a0 + 0x34) |= 0x100;
                func_L01_00451290(a0, &v, 1);
                func_L01_004515D8(a0 + 0xC0, &v, 0);
            }
            a0[0x20] = 1;
        }
        break;
    case 1:
        if (*(s16 *)(a0 + 0xAA) == 0x323 || *(s16 *)(a0 + 0xAA) == 0x19C4 || *(s16 *)(a0 + 0xAA) == 0x2F6) {
            *(f32 *)(a0 + 0xF8) = func_0038DAB8(*(f32 *)(a0 + 0xF8), 0.062831856f);
        }
        break;
    case 2:
        u = *(s32 *)(p + 0x3C);
        if (u != -1) {
            g = D_L39_0024BF5C + u * 256;
            if (g == 0 || g[0x20] == 0xFE || g[0x20] == 0xFD) {
                *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x1000) & 0xFFBE;
                func_L03_003F6A80(a0, a0 + 0x10, a0 + 0xF0, 0, 0);
                *(s32 *)(p + 0x30) = -1;
                a0[0x20] = 0;
            }
        }
        break;
    }
    v.q = *(U128_0053D2C0 *)(a0 + 0x10);
    v.f[3] = 2.0f;
    if (func_L39_005BE900(&v, 0, 64.0f) > 0) {
        if (*(s16 *)(a0 + 0xAA) != 0x2F6) {
            func_L01_00404A10(func_L03_00300DA0, a0);
        } else {
            func_L01_00404A10(func_L03_00300F50, a0);
        }
    }
}
/* localdecomp:end func_L39_0053D2C0 */
