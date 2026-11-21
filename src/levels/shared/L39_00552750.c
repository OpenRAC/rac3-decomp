#include "common.h"

/* localdecomp:start func_L39_00552750 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern f32 func_L39_005B44C8(void);
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_005FF198(u8 *, u8 *, u8 *);

u8 *func_L39_00552750(s32 a0, u8 *a1, u8 *a2, u8 *a3, s32 a4, f32 a5) {
    u8 *object = func_003C24B0(0x10A9, 0x80);
    u8 *state;
    u8 stamp;
    u8 *pos;
    u8 *vec;
    if (object != 0) {
        state = *(u8 **)(object + 0x68);
        stamp = 0xFF;
        *(u16 *)(object + 0x32) = stamp;
        object[0x30] = stamp;
        if (a4 != 0) {
            object[0x20] = 1;
        } else {
            object[0x20] = 0;
        }
        vec = object + 0xE0;
        pos = object + 0x10;
        *(u128_t *)pos = *(u128_t *)a2;
        *(u128_t *)state = *(u128_t *)a3;
        *(f32 *)(state + 0x10) = func_L39_005B44C8();
        *(f32 *)(state + 0x18) = 0.005f;
        *(f32 *)(state + 0x1C) = 0.01f;
        *(s32 *)(state + 0x24) = -1;
        *(f32 *)(state + 0x28) = a5;
        *(s32 *)(state + 0x30) = 0x19;
        *(s32 *)(state + 0x14) = 0;
        *(u8 **)(state + 0x2C) = a1;
        *(f32 *)(object + 0x2C) = *(f32 *)(*(u8 **)(object + 0x24) + 0x24) * 3.25f;
        object[0x23] = 0x14;
        *(u16 *)(object + 0x34) |= 0x100;
        *(s32 *)(object + 0xB8) = a0;
        *(u128_t *)(object + 0xC0) = *(u128_t *)(*(u8 **)(a1 + 0x2524) + 0xC0);
        *(u128_t *)(object + 0xD0) = *(u128_t *)(*(u8 **)(a1 + 0x2524) + 0xD0);
        *(u128_t *)(object + 0xE0) = *(u128_t *)(*(u8 **)(a1 + 0x2524) + 0xE0);
        func_0038CF68(object + 0xD0, object + 0xD0, *(f32 *)(state + 0x18));
        func_0038CF68(vec, vec, *(f32 *)(state + 0x1C));
        *(u16 *)(object + 0x34) |= 4;
        *(s32 *)(object + 0x98) = 0;
        state[0x70] = a1 != 0 && *(s16 *)(a1 + 0x2D8) != 0;
        func_L39_005FF198(a1, pos, state + 0x60);
        func_0038CF68(state + 0x60, state + 0x60, 0.0048f);
    }
    return object;
}
/* localdecomp:end func_L39_00552750 */

INCLUDE_ASM("asm/levels", func_L39_00552920);

/* localdecomp:start func_L39_00553148 */
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern void func_L01_0037BCF8(void *, void *, s32, u32, f32, f32, f32, s32);
extern void func_L01_0037BE80(void *, void *, s32, s32, u32, f32, f32, f32, f32, f32, f32, s32);
extern u8 D_L39_0024DE00[];
extern u32 D_L39_0024B188[] __attribute__((section(".sdata")));
extern u32 D_L39_0024B1A8[] __attribute__((section(".sdata")));
extern u32 D_L39_0024B1E8[] __attribute__((section(".sdata")));
extern u32 D_L39_0024B208[] __attribute__((section(".sdata")));
extern u32 D_L39_0024B228[] __attribute__((section(".sdata")));
extern u32 D_L39_0024B248[] __attribute__((section(".sdata")));
extern u32 D_L39_0024B1C8[] __attribute__((section(".sdata")));
extern s32 D_L39_0024B158;
__asm__(".extern D_L39_0024B158, 4");
extern s32 D_L39_0024B15C;
__asm__(".extern D_L39_0024B15C, 4");
extern s32 D_L39_0024B160;
__asm__(".extern D_L39_0024B160, 4");
extern s32 D_L39_0024B164;
__asm__(".extern D_L39_0024B164, 4");
extern s32 D_L39_0024B168;
__asm__(".extern D_L39_0024B168, 4");
extern s32 D_L39_0024B16C;
__asm__(".extern D_L39_0024B16C, 4");
extern s32 D_L39_0024B170;
__asm__(".extern D_L39_0024B170, 4");
extern f32 D_L39_0024B174;
__asm__(".extern D_L39_0024B174, 4");
extern f32 D_L39_0024B178;
__asm__(".extern D_L39_0024B178, 4");
extern f32 D_L39_0024B17C;
__asm__(".extern D_L39_0024B17C, 4");
extern f32 D_L39_0024B180;
__asm__(".extern D_L39_0024B180, 4");

void func_L39_00553148(u8 *obj) {
    u8 t;
    u8 *st;
    f32 *q;
    f32 *p;
    s32 idx;
    f32 d;
    f32 r;
    f32 f23;
    f32 f21;

    if (obj != 0) {
        t = obj[0x20];
        if (t != 0xFE) {
            if (t == 0xFD) {
                return;
            }
            st = *(u8 **)(obj + 0x68);
            if (st != 0) {
                
                idx = *(s32 *)(*(u8 **)(st + 0x2C) + 0x2548);
                *(f32 *)(st + 0x44) = func_0038DAB8(*(f32 *)(st + 0x44), func_L39_005B4410(-0.5f, -1.0f) * 0.017453292f);
                *(f32 *)(st + 0x34) = func_0038DAB8(*(f32 *)(st + 0x34), func_L39_005B4410(-1.0f, -2.0f) * 0.017453292f);
                *(f32 *)(st + 0x48) = func_0038DAB8(*(f32 *)(st + 0x48), func_L39_005B4410(-1.0f, -1.5f) * 0.017453292f);
                *(f32 *)(st + 0x38) = func_0038DAB8(*(f32 *)(st + 0x38), func_L39_005B4410(-1.5f, -2.5f) * 0.017453292f);
                *(f32 *)(st + 0x4C) = func_0038DAB8(*(f32 *)(st + 0x4C), func_L39_005B4410(-0.5f, -1.5f) * 0.017453292f);
                *(f32 *)(st + 0x3C) = func_0038DAB8(*(f32 *)(st + 0x3C), func_L39_005B4410(-0.5f, -1.5f) * 0.017453292f);
                d = func_L01_0040E570(obj + 0x10, D_L39_0024DE00);
                r = d < D_L39_0024B178 ? (d - D_L39_0024B174) / (D_L39_0024B178 - D_L39_0024B174) : 1.0f;
                f23 = r < 0.0f ? 0.0f : r;
                r = d < D_L39_0024B180 ? (d - D_L39_0024B17C) / (D_L39_0024B180 - D_L39_0024B17C) : 1.0f;
                f21 = r < 0.0f ? 0.0f : r;
                if (D_L39_0024B158) {
                    func_003D9508(obj + 0x10, 0x39, D_L39_0024B188[idx], 1, 0.1875f, 0.0f, *(f32 *)(st + 0x34));
                    func_003D9508(obj + 0x10, 0x39, D_L39_0024B188[idx], 1, 0.1875f, 0.0f, -*(f32 *)(st + 0x3C));
                }
                if (D_L39_0024B15C) {
                    func_L01_0037BCF8(obj, obj + 0x10, 0xB, D_L39_0024B1A8[idx], 0.22500001f, 0.01f, *(f32 *)(st + 0x38), 1);
                }
                if (f21 > 0.25f && D_L39_0024B160) {
                    u32 color = D_L39_0024B1E8[idx];
                    if (f21 != 1.0f) {
                        u8 alpha = (s32)((f32)(s32)(color >> 24) * f21);
                        alpha = alpha > 0x7F ? 0x7F : alpha;
                        color = (alpha << 24) | (color & 0xFFFFFF);
                    }
                    func_L01_0037BCF8(obj, obj + 0x10, 0xB, color, 1.0f, 0.01f, *(f32 *)(st + 0x38), 1);
                }
                if (f21 > 0.0f && D_L39_0024B164) {
                    u32 color = D_L39_0024B208[idx];
                    if (f21 != 1.0f) {
                        u8 alpha = (s32)((f32)(s32)(color >> 24) * f21);
                        alpha = alpha > 0x7F ? 0x7F : alpha;
                        color = (alpha << 24) | (color & 0xFFFFFF);
                    }
                    func_L01_0037BCF8(obj, obj + 0x10, 8, color, 1.1f, 0.01f, *(f32 *)(st + 0x38), 1);
                }
                if (D_L39_0024B168) {
                    f32 s = 1.0f - f23;
                    u32 color = D_L39_0024B228[idx];
                    if (s * 3.0f + 1.0f != 1.0f) {
                        u8 alpha = (s32)((f32)(s32)(color >> 24) * s * 3.0f + 1.0f);
                        alpha = alpha > 0x7F ? 0x7F : alpha;
                        color = (alpha << 24) | (color & 0xFFFFFF);
                    }
                    func_L01_0037BE80(obj, obj + 0x10, 0x43, 0x43, color, 1.0f, 1.0f, 1.0f, *(f32 *)(st + 0x44), *(f32 *)(st + 0x34), 0.0f, 0);
                }
                if (f23 > 0.2f && D_L39_0024B16C) {
                    u32 color = D_L39_0024B248[idx];
                    if (f23 != 1.0f) {
                        u8 alpha = (s32)((f32)(s32)(color >> 24) * f23);
                        alpha = alpha > 0x7F ? 0x7F : alpha;
                        color = (alpha << 24) | (color & 0xFFFFFF);
                    }
                    func_L01_0037BE80(obj, obj + 0x10, 0x43, 0x43, color, 1.0f, 1.0f, 1.0f, *(f32 *)(st + 0x48), *(f32 *)(st + 0x38), 0.02f, 0);
                    func_L01_0037BE80(obj, obj + 0x10, 0x43, 0x43, color, 1.0f, 1.0f, 1.0f, *(f32 *)(st + 0x48), *(f32 *)(st + 0x38), -0.02f, 0);
                }
                if (D_L39_0024B170) {
                    func_L01_0037BE80(obj, obj + 0x10, 0x43, 0x43, D_L39_0024B1C8[idx], 1.0f, 1.0f, 1.0f, *(f32 *)(st + 0x4C), *(f32 *)(st + 0x3C), 0.04f, 0);
                    func_L01_0037BE80(obj, obj + 0x10, 0x43, 0x43, D_L39_0024B1C8[idx], 1.0f, 1.0f, 1.0f, *(f32 *)(st + 0x4C), *(f32 *)(st + 0x3C), -0.04f, 0);
                }
            }
        }
    }
}
/* localdecomp:end func_L39_00553148 */

/* localdecomp:start func_L39_005537B8 */
extern u32 D_L39_0024B1A8_005537B8[] __attribute__((section(".sdata")));
typedef struct S_005537B8 {
    u8 pad00[0x2C];
    u8 *p2C;
    u8 pad30[4];
    f32 f34;
    f32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
    f32 f48;
    f32 f4C;
} S_005537B8;

__asm__(".extern D_L39_0024B158, 4");
__asm__(".extern D_L39_0024B15C, 4");
__asm__(".extern D_L39_0024B160, 4");
__asm__(".extern D_L39_0024B164, 4");
__asm__(".extern D_L39_0024B168, 4");
__asm__(".extern D_L39_0024B16C, 4");
__asm__(".extern D_L39_0024B170, 4");
void func_L39_005537B8(u8 *a0) {
    u8 t;
    S_005537B8 *st;
    s32 idx;
    f32 f;
    if (a0 != 0) {
        t = a0[0x20];
        if (t != 0xFE) {
            if (t == 0xFD) {
                return;
            }
            st = *(S_005537B8 **)(a0 + 0x68);
            if (st != 0) {
                idx = *(s32 *)(st->p2C + 0x2548);
                st->f44 = func_0038DAB8(st->f44, func_L39_005B4410(-0.5f, -1.0f) * 0.017453292f);
                st->f34 = func_0038DAB8(st->f34, func_L39_005B4410(-1.0f, -2.0f) * 0.017453292f);
                st->f48 = func_0038DAB8(st->f48, func_L39_005B4410(-1.0f, -1.5f) * 0.017453292f);
                st->f38 = func_0038DAB8(st->f38, func_L39_005B4410(-1.5f, -2.5f) * 0.017453292f);
                st->f4C = func_0038DAB8(st->f4C, func_L39_005B4410(-0.5f, -1.5f) * 0.017453292f);
                st->f3C = func_0038DAB8(st->f3C, func_L39_005B4410(-0.5f, -1.5f) * 0.017453292f);
                if (D_L39_0024B158 != 0) {
                    func_003D9508(a0 + 0x10, 0x39, D_L39_0024B188[idx], 1, 0.2f, 0.0f, st->f34);
                    func_003D9508(a0 + 0x10, 0x39, D_L39_0024B188[idx], 1, 0.2f, 0.0f, -st->f3C);
                }
                if (D_L39_0024B15C != 0) {
                    func_L01_0037BCF8(a0, a0 + 0x10, 0xB, D_L39_0024B1A8_005537B8[idx], 0.22500001f, 0.01f, st->f38, 1);
                }
                if (D_L39_0024B160 != 0) {
                    func_L01_0037BCF8(a0, a0 + 0x10, 0xB, 0x1510107F, 1.0f, 0.01f, st->f38, 1);
                }
                f = st->f40;
                if (f < 1.1f) {
                    u8 *p = a0 + 0x10;
                    f = f + 0.05f;
                    st->f40 = f;
                    if (D_L39_0024B164 != 0) {
                        func_L01_0037BCF8(a0, p, 8, 0x25204080, f, 0.01f, st->f38, 1);
                    }
                    func_L01_0037BCF8(a0, p, 8, 0xF204080, 1.1f, 0.01f, st->f38, 1);
                }
                if (D_L39_0024B168 != 0) {
                    func_L01_0037BE80(a0, a0 + 0x10, 0x43, 0x43, D_L39_0024B228[idx], 1.0f, 1.0f, 1.0f, st->f44, st->f34, 0.0f, 0);
                }
                if (D_L39_0024B16C != 0) {
                    func_L01_0037BE80(a0, a0 + 0x10, 0x43, 0x43, 0x2F204080, 1.0f, 1.0f, 1.0f, st->f48, st->f38, 0.02f, 0);
                    func_L01_0037BE80(a0, a0 + 0x10, 0x43, 0x43, 0x2F204080, 1.0f, 1.0f, 1.0f, st->f48, st->f38, -0.02f, 0);
                }
                if (D_L39_0024B170 != 0) {
                    func_L01_0037BE80(a0, a0 + 0x10, 0x43, 0x43, D_L39_0024B1C8[idx], 1.0f, 1.0f, 1.0f, st->f4C, st->f3C, 0.04f, 0);
                    func_L01_0037BE80(a0, a0 + 0x10, 0x43, 0x43, D_L39_0024B1C8[idx], 1.0f, 1.0f, 1.0f, st->f4C, st->f3C, -0.04f, 0);
                }
            }
        }
    }
}
/* localdecomp:end func_L39_005537B8 */

/* localdecomp:start func_L39_00553C30 */
__asm__(".extern D_L39_0024B158, 4");
__asm__(".extern D_L39_0024B15C, 4");
__asm__(".extern D_L39_0024B160, 4");
__asm__(".extern D_L39_0024B164, 4");
__asm__(".extern D_L39_0024B168, 4");
__asm__(".extern D_L39_0024B16C, 4");
__asm__(".extern D_L39_0024B170, 4");
__asm__(".extern D_L39_0024B174, 4");
__asm__(".extern D_L39_0024B178, 4");
__asm__(".extern D_L39_0024B17C, 4");
__asm__(".extern D_L39_0024B180, 4");
void func_L39_00553C30(u8 *obj) {
    u8 t;
    u8 *st;
    s32 idx;
    f32 d;
    f32 r;
    f32 f23;
    f32 f21;

    if (obj != 0) {
        t = obj[0x20];
        if (t != 0xFE) {
            if (t == 0xFD) {
                return;
            }
            st = *(u8 **)(obj + 0x68);
            if (st != 0) {
                idx = *(s32 *)(*(u8 **)(st + 0x2C) + 0x2548);
                *(f32 *)(st + 0x44) = func_0038DAB8(*(f32 *)(st + 0x44), func_L39_005B4410(-0.5f, -1.0f) * 0.017453292f);
                *(f32 *)(st + 0x34) = func_0038DAB8(*(f32 *)(st + 0x34), func_L39_005B4410(-1.0f, -2.0f) * 0.017453292f);
                *(f32 *)(st + 0x48) = func_0038DAB8(*(f32 *)(st + 0x48), func_L39_005B4410(-1.0f, -1.5f) * 0.017453292f);
                *(f32 *)(st + 0x38) = func_0038DAB8(*(f32 *)(st + 0x38), func_L39_005B4410(-1.5f, -2.5f) * 0.017453292f);
                *(f32 *)(st + 0x4C) = func_0038DAB8(*(f32 *)(st + 0x4C), func_L39_005B4410(-0.5f, -1.5f) * 0.017453292f);
                *(f32 *)(st + 0x3C) = func_0038DAB8(*(f32 *)(st + 0x3C), func_L39_005B4410(-0.5f, -1.5f) * 0.017453292f);
                d = func_L01_0040E570(obj + 0x10, D_L39_0024DE00);
                r = d < D_L39_0024B178 ? (d - D_L39_0024B174) / (D_L39_0024B178 - D_L39_0024B174) : 1.0f;
                f23 = r < 0.0f ? 0.0f : r;
                r = d < D_L39_0024B180 ? (d - D_L39_0024B17C) / (D_L39_0024B180 - D_L39_0024B17C) : 1.0f;
                f21 = r < 0.0f ? 0.0f : r;
                if (D_L39_0024B158) {
                    u32 color = D_L39_0024B188[idx];
                    func_003D9508(obj + 0x10, 0x39, ((0x4F - *(s32 *)(st + 0x14) * 2) << 24) | (color & 0xFFFFFF), 1, 0.1875f, 0.0f, *(f32 *)(st + 0x34));
                    func_003D9508(obj + 0x10, 0x39, ((0x4F - *(s32 *)(st + 0x14) * 2) << 24) | (color & 0xFFFFFF), 1, 0.1875f, 0.0f, -*(f32 *)(st + 0x3C));
                }
                if (D_L39_0024B15C) {
                    func_L01_0037BCF8(obj, obj + 0x10, 0xB, ((0x3F - *(s32 *)(st + 0x14) * 2) << 24) | (D_L39_0024B1A8[idx] & 0xFFFFFF), 0.22500001f, 0.01f, *(f32 *)(st + 0x38), 1);
                }
                if (f21 > 0.25f && D_L39_0024B160) {
                    u32 color = D_L39_0024B1E8[idx];
                    if (f21 != 1.0f) {
                        u8 alpha = (s32)((f32)(s32)(color >> 24) * f21);
                        alpha = alpha < 0x80 ? alpha : 0x7F;
                        color = (alpha << 24) | (color & 0xFFFFFF);
                    }
                    func_L01_0037BCF8(obj, obj + 0x10, 0xB, ((0x3F - *(s32 *)(st + 0x14) * 2) << 24) | (color & 0xFFFFFF), 1.0f, 0.01f, *(f32 *)(st + 0x38), 1);
                }
                if (f21 > 0.0f && D_L39_0024B164) {
                    u32 color = D_L39_0024B208[idx];
                    if (f21 != 1.0f) {
                        u8 alpha = (s32)((f32)(s32)(color >> 24) * f21);
                        alpha = alpha < 0x80 ? alpha : 0x7F;
                        color = (alpha << 24) | (color & 0xFFFFFF);
                    }
                    func_L01_0037BCF8(obj, obj + 0x10, 8, ((0x3F - *(s32 *)(st + 0x14) * 2) << 24) | (color & 0xFFFFFF), 1.1f, 0.01f, *(f32 *)(st + 0x38), 1);
                }
                if (D_L39_0024B168) {
                    func_L01_0037BE80(obj, obj + 0x10, 0x43, 0x43, ((0x3F - *(s32 *)(st + 0x14) * 2) << 24) | (D_L39_0024B228[idx] & 0xFFFFFF), 1.0f, 1.0f, 1.0f, *(f32 *)(st + 0x44), *(f32 *)(st + 0x34), 0.0f, 0);
                }
                if (f23 > 0.2f && D_L39_0024B16C) {
                    u32 color = D_L39_0024B248[idx];
                    if (f23 != 1.0f) {
                        u8 alpha = (s32)((f32)(s32)(color >> 24) * f23);
                        alpha = alpha < 0x80 ? alpha : 0x7F;
                        color = (alpha << 24) | (color & 0xFFFFFF);
                    }
                    func_L01_0037BE80(obj, obj + 0x10, 0x43, 0x43, ((0x3F - *(s32 *)(st + 0x14) * 2) << 24) | (color & 0xFFFFFF), 1.0f, 1.0f, 1.0f, *(f32 *)(st + 0x48), *(f32 *)(st + 0x38), 0.02f, 0);
                    func_L01_0037BE80(obj, obj + 0x10, 0x43, 0x43, ((0x3F - *(s32 *)(st + 0x14) * 2) << 24) | (color & 0xFFFFFF), 1.0f, 1.0f, 1.0f, *(f32 *)(st + 0x48), *(f32 *)(st + 0x38), -0.02f, 0);
                }
                if (D_L39_0024B170) {
                    u32 color = D_L39_0024B1C8[idx];
                    func_L01_0037BE80(obj, obj + 0x10, 0x43, 0x43, ((0x3F - *(s32 *)(st + 0x14) * 2) << 24) | (color & 0xFFFFFF), 1.0f, 1.0f, 1.0f, *(f32 *)(st + 0x4C), *(f32 *)(st + 0x3C), 0.04f, 0);
                    func_L01_0037BE80(obj, obj + 0x10, 0x43, 0x43, ((0x3F - *(s32 *)(st + 0x14) * 2) << 24) | (color & 0xFFFFFF), 1.0f, 1.0f, 1.0f, *(f32 *)(st + 0x4C), *(f32 *)(st + 0x3C), -0.04f, 0);
                }
                obj[0x23] = 0x15 - *(s32 *)(st + 0x14);
            }
        }
    }
}
/* localdecomp:end func_L39_00553C30 */
