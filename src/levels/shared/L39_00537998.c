#include "common.h"

/* localdecomp:start func_L39_00537998 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(u8 *);
extern f32 func_L39_005B4410(f32, f32);
extern f32 D_L39_0024AD90;
__asm__(".extern D_L39_0024AD90, 4");
extern s32 D_L39_0024112C;

u8 *func_L39_00537998(s32 a0, u8 *a1, u128_t *a2, u128_t *a3, s32 a4, s32 a5) {
    u8 *p;
    u8 *q;

    p = func_003C24B0(0x1099, 0x80);
    if (p != 0) {
        q = *(u8 **)(p + 0x68);
        p[0x30] = 0xFF;
        *(s16 *)(p + 0x32) = 0x7F;
        *(s32 *)(p + 0xB8) = a0;
        *(f32 *)(p + 0x2C) *= 0.5f;
        p[0x31] = 1;
        p[0x20] = 0;
        *(s16 *)(q + 0x36) = 0;
        if (a4 != 0) {
            *(f32 *)(p + 0x2C) = *(f32 *)(*(u8 **)(p + 0x24) + 0x24) * D_L39_0024AD90;
            *(u128_t *)q = *a3;
            q[0x51] = 1;
            *(s32 *)(q + 0x74) = a5;
        }
        *(u16 *)(q + 0x7C) = *(u16 *)(a1 + 0x2544);
        *(s32 *)(p + 0x90) = *(s32 *)a1;
        *(s32 *)(p + 0x78) = 0;
        *(u16 *)(p + 0x34) |= 0x10;
        *(u128_t *)(p + 0x10) = *a2;
        *(f32 *)(q + 0x38) = func_L39_005B4410(0.020943953f, 0.06283186f);
        {
            s32 d;
            f32 t = func_L39_005B4410(0.020943953f, 0.06283186f);
            f32 z = 0.0f;
            d = D_L39_0024112C;
            *(f32 *)(q + 0x64) = z;
            *(f32 *)(q + 0x3C) = t;
            *(f32 *)(q + 0x60) = z;
            *(f32 *)(q + 0x70) = z;
            *(f32 *)(q + 0x6C) = z;
            *(s32 *)(q + 0x5C) = d;
            *(s32 *)(q + 0x68) = -1;
        }
        *(s32 *)(p + 0x98) = 0;
        func_003C7C38(p);
    }
    return p;
}
/* localdecomp:end func_L39_00537998 */

INCLUDE_ASM("asm/levels", func_L39_00537B28);

INCLUDE_ASM("asm/levels", func_L39_00539268);

INCLUDE_ASM("asm/levels", func_L39_00539398);

INCLUDE_ASM("asm/levels", func_L39_0053B6B0);

INCLUDE_ASM("asm/levels", func_L39_0053B810);

INCLUDE_ASM("asm/levels", func_L39_0053BA68);

INCLUDE_ASM("asm/levels", func_L39_0053BB08);

/* localdecomp:start func_L39_0053BE50 */
extern s16 D_L39_00293F38[][64];
extern u8 *D_L39_0024BF5C;

u8 *func_L39_0053BE50(s32 idx, s32 id) {
    s32 i;
    u8 *m;
    u8 *p;

    for (i = 1; i <= D_L39_00293F38[idx][0]; i++) {
        m = D_L39_0024BF5C + D_L39_00293F38[idx][i] * 256;
        p = *(u8 **)(m + 104);
        if (p != 0 && *(s16 *)(p + 126) == id) {
            return m;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_0053BE50 */

INCLUDE_ASM("asm/levels", func_L39_0053BED0);

INCLUDE_ASM("asm/levels", func_L39_0053C110);

INCLUDE_ASM("asm/levels", func_L39_0053C1E8);

INCLUDE_ASM("asm/levels", func_L39_0053C248);

/* localdecomp:start func_L39_0053C2A0 */
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_L39_0053C1E8(void *, void *, f32);

void func_L39_0053C2A0(u8 *a0) {
    f32 v[4];
    u8 *p = *(u8 **)(a0 + 104);
    func_0038CF68(v, p + 32, 1.0f);
    func_L39_0053C1E8(a0, p, -func_0038CE68(p, v));
}
/* localdecomp:end func_L39_0053C2A0 */

INCLUDE_ASM("asm/levels", func_L39_0053C300);

INCLUDE_ASM("asm/levels", func_L39_0053C758);

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

INCLUDE_ASM("asm/levels", func_L39_0053D2C0);
