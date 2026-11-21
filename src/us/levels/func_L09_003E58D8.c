#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L09_003E75B0 (src/levels/09_tyhrranosis/L09_003E75B0.c): turn clamp pi/360 (60 Hz) in place of pi/300 */
/* localdecomp:start func_L09_003E58D8 */
extern f32 func_00388730(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_L01_00449148(void *, void *, void *, void *, f32, f32, void *, f32, f32, s32);
extern void func_003BF360(void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_00443610(void *, void *, s32, f32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern s32 func_003CF790(void *, s32, f32, void *, void *);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_00443840(void *, void *);
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_L01_003F9498(void *, s32, f32, void *);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);
extern void func_L09_003E60D0(u8 *);
extern u8 D_L09_001D9BA0[] __attribute__((section(".sdata")));
extern s32 D_L09_001ED9C0[];
typedef struct { u8 pad[0x1DC]; s16 f1DC; } H_003E58D8;
extern H_003E58D8 D_001A4BE0;
extern vu0_v4 D_001A4C60;

void func_L09_003E58D8(u8 *a0) {
    u8 *v;
    u8 *pos;
    s32 n;
    s32 i;
    f32 d;
    vu0_v4 old;
    vu0_v4 diff;
    u8 buf[32];
    vu0_v4 tgt;

    pos = a0 + 0x10;
    v = *(u8 **)(a0 + 0x68);
    old = *(vu0_v4 *)(a0 + 0x10);
    if (v[0x2F] == 0) {
        vec_sub_ba(&diff, a0 + 0x10, v + 0x10);
        if (v[0x2E] == 0 && func_00388730(a0 + 0xC0, &diff) < 0.0f) {
            d = func_003893C8(func_00388A28(*(f32 *)(v + 0x10) - *(f32 *)(a0 + 0x10),
                                            *(f32 *)(v + 0x14) - *(f32 *)(a0 + 0x14)),
                              *(f32 *)(a0 + 0xF8));
            if (d > 0.00872664712f) {
                d = 0.00872664712f;
            } else if (d < -0.00872664712f) {
                d = -0.00872664712f;
            }
            *(f32 *)(a0 + 0xF8) = func_00389380(*(f32 *)(a0 + 0xF8), d);
        }
    } else {
        if (v[0x2F] == 1) {
            func_L01_00449148(pos, a0 + 0xC0, v + 0x10, v + 0x28, 0.003f, 0.003f, D_L09_001D9BA0, 0.0f, 0.0f, 0);
            func_003BF360(a0 + 0xC0, a0 + 0xF0);
        } else {
            func_L01_00449148(pos, a0 + 0xC0, v + 0x10, v + 0x28, 0.003f, 0.003f, D_L09_001D9BA0, 0.0f, 7.0f, 0);
            func_003BF360(a0 + 0xC0, a0 + 0xF0);
        }
    }
    func_00388830(a0 + 0xC0, a0 + 0xC0, 1.0f);
    func_003886E8(v, a0 + 0xC0, *(f32 *)(v + 0x24));
    vec_add_ab(a0 + 0x10, v, a0 + 0x10);
    if (v[0x2F] == 0) {
        func_L01_00443610(buf, a0, v[0x2E] ? 0x1090001 : 0x1010001, (f32)*(s16 *)(v + 0x2C));
        if (func_003CE740(&old, a0 + 0x10, 0, *(void **)(a0 + 0xB8), buf) != 0
            || func_003CF790(a0 + 0x10, 0, 0.1f, *(void **)(a0 + 0xB8), buf) != 0) {
            func_0039FE80(0, 0, a0);
            func_L01_0032FE90(a0 + 0x10, 0, 5, 5, 5, 5, 10, 1, 0.8f, 0.0f, 0.0f, 2.0f,
                0, 1, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_003BD360(a0);
        } else {
            goto miss;
        }
    } else {
        n = func_003CF790(a0 + 0x10, 1, 1.0f, a0, 0);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                if (D_L09_001ED9C0[i] == *(s32 *)(v + 0x20)) {
                    if (v[0x2F] == 2) {
                        func_003886E8(&tgt, *(u8 **)(a0 + 0xB8) + 0xC0, 10.0f);
                        tgt.w = 5627.9248f;
                    } else {
                        func_003886E8(&tgt, *(u8 **)(a0 + 0xB8) + 0xC0, 4.0f);
                        tgt.w = 5627.9248f;
                    }
                    func_L01_00443628(&diff, a0, 1, &tgt, (f32)*(s16 *)(v + 0x2C));
                    if (v[0x2F] == 2) {
                        D_001A4BE0.f1DC = 0;
                    }
                    func_L01_00443840((void *)D_L09_001ED9C0[i], &diff);
                    func_0039FE80(0, 0, a0);
                    func_L01_0032FE90(a0 + 0x10, 0, 5, 5, 5, 5, 10, 1, 0.8f, 0.0f, 0.0f, 2.0f,
                        0, 1, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                        0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                    func_003BD360(a0);
                    return;
                }
            }
        }
        if (func_003CE740(&old, a0 + 0x10, 0, *(void **)(a0 + 0xB8), 0) != 0
            || func_L01_003F9498(a0 + 0x10, 0, 0.1f, *(void **)(a0 + 0xB8)) != 0) {
            func_L01_00443610(&diff, a0, 0x10000, (f32)*(s16 *)(v + 0x2C));
            func_003CF790(a0 + 0x10, 0, 1.7f, a0, &diff);
            func_0039FE80(0, 0, a0);
            func_L01_0032FE90(a0 + 0x10, 0, 5, 5, 5, 5, 10, 1, 0.8f, 0.0f, 0.0f, 2.0f,
                0, 1, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_003BD360(a0);
        } else {
            goto miss;
        }
    }
    return;
miss:
    if (*(u8 **)(v + 0x20) != 0 && *(s16 *)(*(u8 **)(v + 0x20) + 0xAA) == 0 && v[0x2F] == 2) {
        *(vu0_v4 *)(v + 0x10) = D_001A4C60;
    }
    func_L09_003E60D0(a0);
}
/* localdecomp:end func_L09_003E58D8 */
