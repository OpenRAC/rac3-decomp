#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003D8B18);

/* localdecomp:start func_L07_003D8E28 */
extern void func_L07_003D90A8(s32);
extern s32 func_L07_003D9630(u8 *);
extern void func_L01_004450F0(s32, s32, s32);
extern void func_L07_003D9298(s32);
extern void func_L07_003D9330(s32);

void func_L07_003D8E28(s32 arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *s;
    func_L07_003D90A8(arg0);
    s = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 1:
        break;
    case 2:
        if (*(f32 *)(s + 0x2C) != 0.0f) {
            *(f32 *)(s + 0x2C) -= 0.018000001f;
            if (*(f32 *)(s + 0x2C) <= 0.0f) *(f32 *)(s + 0x2C) = 0.0f;
        }
        if (func_L07_003D9630(obj)) func_L01_004450F0(arg0, 7, -1);
        func_L07_003D9298(arg0);
        break;
    case 3:
        if (func_L07_003D9630(obj)) func_L01_004450F0(arg0, 6, -1);
        break;
    case 4:
        *(f32 *)(s + 0x2C) += 0.018000001f;
        if (1.0f < *(f32 *)(s + 0x2C)) {
            *(f32 *)(s + 0x2C) = 1.0f;
            if (s[0x3C] != 0) func_L01_004450F0(arg0, 5, -1);
            else func_L01_004450F0(arg0, 3, -1);
        }
        func_L07_003D9298(arg0);
        break;
    case 5:
        *(f32 *)(s + 0x28) += 0.012f;
        if (1.0f < *(f32 *)(s + 0x28)) {
            *(f32 *)(s + 0x28) = 1.0f;
            func_L01_004450F0(arg0, 2, -1);
        }
        func_L07_003D9330(arg0);
        break;
    case 6:
        *(f32 *)(s + 0x2C) -= 0.018000001f;
        if (*(f32 *)(s + 0x2C) <= 0.0f) {
            *(f32 *)(s + 0x2C) = 0.0f;
            func_L01_004450F0(arg0, 1, -1);
        }
        func_L07_003D9298(arg0);
        break;
    case 7:
        if (*(f32 *)(s + 0x2C) != 0.0f) {
            *(f32 *)(s + 0x2C) -= 0.018000001f;
            if (*(f32 *)(s + 0x2C) <= 0.0f) *(f32 *)(s + 0x2C) = 0.0f;
            func_L07_003D9298(arg0);
        }
        *(f32 *)(s + 0x28) += 0.012f;
        if (2.0f <= *(f32 *)(s + 0x28) && *(f32 *)(s + 0x2C) <= 0.0f) {
            *(f32 *)(s + 0x28) = 0.0f;
            func_L01_004450F0(arg0, 1, -1);
        }
        func_L07_003D9330(arg0);
        break;
    }
}
/* localdecomp:end func_L07_003D8E28 */

INCLUDE_ASM("asm/levels", func_L07_003D90A8);

/* localdecomp:start func_L07_003D9218 */
extern void func_L01_004450F0(s32 a0, s32 a1, s32 a2);
extern void func_L07_003D9298(s32 a0);
extern void func_L07_003D9330(s32 a0);

void func_L07_003D9218(s32 a0) {
    s32 *p = *(s32 **)(a0 + 0x68);
    p[11] = 0;
    p[10] = 0;
    func_L07_003D9298(a0);
    func_L07_003D9330(a0);
    func_L01_004450F0(a0, 1, -1);
}
/* localdecomp:end func_L07_003D9218 */

/* localdecomp:start func_L07_003D9260 */
void func_L01_004450F0(s32, s32, s32);
void func_L07_003D93F0();

void func_L07_003D9260(s32 arg0) {
    func_L07_003D93F0();
    func_L01_004450F0(arg0, 4, -1);
}
/* localdecomp:end func_L07_003D9260 */

/* localdecomp:start func_L07_003D9298 */
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_003C7C38(void *);

void func_L07_003D9298(s32 a0) {
    s32 *e = *(s32 **)(a0 + 0x68);
    s32 *p = (s32 *)((u8 *)e + 0x34);
    f32 d = func_003C3BE8(0.0f, 8.0f, *(f32 *)((u8 *)e + 0x2C));
    s32 i = 0;

    do {
        f32 f = *(f32 *)((u8 *)a0 + 0x10);
        s32 *v = (s32 *)*p;
        if (i == 0) {
            f = f - d;
        } else {
            f = f + d;
        }
        *(f32 *)((u8 *)v + 0x10) = f;
        i++;
        func_003C7C38((void *)*p);
        p++;
    } while (i < 2);
}
/* localdecomp:end func_L07_003D9298 */

/* localdecomp:start func_L07_003D9330 */
extern f32 func_003C3BE8(f32, f32, f32);

typedef struct {
    u8 pad[0x14];
    f32 f14;
    f32 f18;
    u8 tail[0x100 - 0x1C];
} S_3D9330;

extern S_3D9330 *D_L07_001DF41C;

void func_L07_003D9330(s32 a0) {
    u8 *e = *(u8 **)(a0 + 0x68);
    f32 t = *(f32 *)(e + 0x28);
    f32 one;
    f32 rest;
    S_3D9330 *g;
    s32 idx;

    if (1.0f < t) {
        one = 1.0f;
        rest = t - 1.0f;
    } else {
        one = t;
        rest = 0.0f;
    }
    idx = *(s32 *)(e + 0x30);
    g = &D_L07_001DF41C[idx];
    g->f14 = *(f32 *)(a0 + 0x14) - func_003C3BE8(0.0f, 15.01f, one);
    g->f18 = *(f32 *)(a0 + 0x18) - func_003C3BE8(0.0f, 3.0f, rest);
}
/* localdecomp:end func_L07_003D9330 */

/* localdecomp:start func_L07_003D93F0 */
extern u8 D_00142764[];
extern u8 D_00142763[];
extern void func_L07_003A2380(s32, s32, s32, s32);
extern u8 *func_L07_00333CF8(void *, s32);
extern void func_L07_003D9548(void *, void *, s32, s32, f32);

void func_L07_003D93F0(u8 *obj) {
    u8 *sub = *(u8 **)(obj + 0x68);
    s32 i;
    s32 j;
    u8 *p;

    for (i = 1; i >= 0; i--) {
        *(s32 *)(sub + 0x20 + i * 4) = 0;
    }
    if (sub[0x13] != 0) {
        if (D_00142764[0] == 0) {
            func_L07_003A2380(0x1C, *(s32 *)sub, 0, 0x64);
        }
        sub[0x3C] = 1;
        func_L07_003D9548(obj, func_L07_00333CF8(*(void **)sub, 0), sub[0x3C], 0, 0.0f);
    } else if (*(u16 *)(sub + 0x14) != 0) {
        if (D_00142763[0] == 0) {
            func_L07_003A2380(0x1B, *(s32 *)sub, 0, 0x64);
        }
        sub[0x3C] = 1;
        func_L07_003D9548(obj, func_L07_00333CF8(*(void **)sub, 1), sub[0x3C], 0, 1.0f);
        func_L07_003D9548(obj, func_L07_00333CF8(*(void **)sub, 2), sub[0x3C], 1, -1.0f);
    }
    p = sub + 0x15;
    for (j = 2; j >= 0; j--) {
        *p = 0;
        p--;
    }
}
/* localdecomp:end func_L07_003D93F0 */

/* localdecomp:start func_L07_003D9548 */
/* Adapted from the repository's NTSC-U counterpart func_L07_003D78E8. */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_L07_00333918(void *);
extern void func_L07_00333D40(void *, void *);
extern void func_L07_00333C70(void *, void *);

void func_L07_003D9548(void *objArg, void *outArg, s32 a2, s32 idx, f32 f)
{
    u8 *obj = objArg;
    u8 *out = outArg;
    u8 *p = *(u8 **)(obj + 0x68);
    u8 *q;
    idx = (u8)idx;
    q = func_L07_00333918(out);

    *(s16 *)(q + 0xE) = 0x3E;
    if (p[0x3C] != 0) {
        *(s16 *)(q + 0xE) = 0x91;
    }
    q[0x1E] = 0;
    *(u128_t *)(out + 0x10) = *(u128_t *)(obj + 0x10);
    *(f32 *)(out + 0x18) = *(f32 *)(out + 0x18) + 1.5f;
    if (f != 0.0f) {
        *(f32 *)(out + 0x10) = *(f32 *)(out + 0x10) + f * 3.0f;
    }
    func_L07_00333D40(*(void **)(q + 4), out);
    *(f32 *)(out + 0xF8) = *(f32 *)(obj + 0xF8);
    func_L07_00333C70(*(void **)p, out);
    *(u8 **)(p + (idx << 2) + 0x20) = out;
}
/* localdecomp:end func_L07_003D9548 */

/* localdecomp:start func_L07_003D9630 */
extern s32 func_L07_00333AB8(void *);
extern f32 func_L01_0040E570(void *, void *);

s32 func_L07_003D9630(u8 *arg0) {
    s32 *p;
    u8 *a;
    s32 i = 0;

    a = *(u8 **)(arg0 + 0x68);
    p = (s32 *)(a + 0x20);
    do {
        if (*p != 0) {
            if (func_L07_00333AB8((void *)*p) == 0) {
                if (484.0f < func_L01_0040E570((u8 *)*p + 0x10, *(u8 **)a + 0x10)) {
                    return 0;
                }
            }
            *p = 0;
        }
        i++;
        p++;
    } while (i < 2);
    return 1;
}
/* localdecomp:end func_L07_003D9630 */
