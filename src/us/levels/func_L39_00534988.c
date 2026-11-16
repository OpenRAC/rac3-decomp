#include "common.h"

/* NTSC-U counterpart of func_L39_00535028 (src/levels/shared/L39_00535028.c) */
/* localdecomp:start func_L39_00534988 */
#include "vu0.h"

typedef struct {
    vu0_v4 pos;
    u8 pad10[0x450];
} C_00535028;
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 pad8[2];
    u8 bA;
    u8 bB;
    u8 padC[0x1C - 0xC];
    f32 f1C;
} P_00535028;
typedef struct {
    u8 pad0[9];
    u8 b9;
    s16 hA;
    u8 padC[0x20 - 0xC];
    P_00535028 sub;
} Q_00535028;

extern s32 D_L39_00241298_00534988;
extern C_00535028 D_L39_0024DF80[];
extern u8 D_L39_0025F860[];
extern f32 D_L39_004704D0[];
extern u8 D_L39_00296918[];
extern s32 D_L39_0024AE68;
__asm__(".extern D_L39_0024AE68, 4");

extern s32 func_L01_004493C0(u8 *, s32, u8 *, u8 *, u8 *, u8 *);
extern s32 func_003883C8(void *);
extern f32 func_00388A28(f32, f32);
extern void func_L01_004495F8(u8 *, s32, u8 *, void *);
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_L39_005B24C8(s32, s32);
extern void *func_L01_0046CF70(void *, void *, s32, f32);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B2568(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern Q_00535028 *func_L01_004633E8(void *, f32, f32, f32, f32, s32, void *, s32, s32);
extern f32 func_L39_005B25C8_00534988(void);
extern void *func_L01_002FB638(void *, void *, s32, s32, s32, s32);
extern void func_00388758(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_00389158(void *, void *, void *, f32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);
extern s32 func_L01_003F9498(void *, f32, s32, u8 *);
extern void func_L01_004026A0(void *, void *);
extern void func_L01_003317C8(void);
extern void func_003BD360(void *);

void func_L39_00534988(u8 *a0) {
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 v2;
    vu0_v4 v3;
    vu0_v4 v4;
    vu0_v4 v5;
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 ang;
    f32 a;
    f32 b;

    if (*(s32 *)(s + 0x38) != 0) {
        func_L01_004493C0(a0, *(s32 *)(s + 0x38), a0 + 0x10, a0 + 0xF0, a0 + 0x10, a0 + 0xF0);
    }
    if (func_003883C8(s + 0x10) == 0) {
        ang = func_00388A28(D_L39_0024DF80[D_L39_00241298_00534988].pos.x - ((vu0_v4 *)(a0 + 0x10))->x,
                            D_L39_0024DF80[D_L39_00241298_00534988].pos.y - ((vu0_v4 *)(a0 + 0x10))->y);
        qzero(&v0);
        if (*(s32 *)(s + 0x38) != 0) {
            func_L01_004495F8(a0, *(s32 *)(s + 0x38), a0 + 0x10, &v0);
        }
        if (*(s16 *)(s + 0x10) == 0x3A) {
            s32 i;
            for (i = 0; i < *(s16 *)(s + 0x32); i++) {
                func_0037E2F0(&v1, *(f32 *)(s + 0xC) * 0.25f, *(f32 *)(s + 0xC) * 0.3333333433f);
                vec_add_ab(&v1, &v1, &v0);
                func_L01_0046CF70(a0 + 0x10, &v1, func_L39_005B24C8(0x19, 0x28), 0.00405555591f);
            }
        }
        if (*(s16 *)(s + 0x10) == 0x39) {
            s32 i;
            s32 k;
            s32 sign = 1;
            for (i = 0; i < *(s32 *)(s + 0x2C); i++) {
                Q_00535028 *q;
                sign = -sign;
                k = (D_L39_0024AE68 + 1) % 44;
                v1.x = ((vu0_v4 *)(a0 + 0x10))->x + D_L39_004704D0[k] * *(f32 *)(s + 0xC);
                D_L39_0024AE68 = k;
                k = (D_L39_0024AE68 + 1) % 44;
                v1.y = ((vu0_v4 *)(a0 + 0x10))->y + D_L39_004704D0[k] * *(f32 *)(s + 0xC);
                D_L39_0024AE68 = k;
                k = (D_L39_0024AE68 + 1) % 44;
                v1.z = ((vu0_v4 *)(a0 + 0x10))->z + D_L39_004704D0[k] * *(f32 *)(s + 0xC);
                D_L39_0024AE68 = k;
                a = func_L39_005B2510(0.0166666675f, 0.0333333351f) * *(f32 *)(s + 0xC);
                b = func_L39_005B2568(0.0f, 1.3962634f);
                func_0037E4B8(&v2, a, func_00389380(ang, func_L39_005B2568(0.0f, 1.5707964f)), b);
                vec_add_ab(&v2, &v2, &v0);
                q = func_L01_004633E8(&v1, 0.0f, 1.0f, 1.01f, *(f32 *)(s + 0xC) * 1.5f * 210000.0f, sign, &v2,
                                      *(s32 *)(s + 0x58), 0);
                if (q != 0) {
                    P_00535028 *p;
                    q->hA = func_L39_005B24C8(0x28, 0x46);
                    q->b9 = 0x44;
                    p = &q->sub;
                    p->w4 = 3;
                    p->f1C = func_L39_005B24C8(1, 10);
                    p->bA = 0x40;
                    p->bB = q->hA;
                }
            }
        }
        if (*(s16 *)(s + 0x10) == 0x38) {
            s32 i;
            for (i = 0; i < *(s16 *)(s + 0x30); i++) {
                a = func_L39_005B2510(0.43633232f, 0.7853982f);
                b = func_L39_005B25C8_00534988();
                func_0037E4B8(&v1, func_L39_005B2510(10.0f, 20.0f) * 0.0166666675f * *(f32 *)(s + 0xC), b, a);
                vec_add_ab(&v1, &v1, &v0);
                func_L01_002FB638(a0 + 0x10, &v1, func_L39_005B24C8(120, 150), 2, 0, 1);
            }
        }
        if (*(s16 *)(s + 0x10) == 0x37 && *(s16 *)(s + 0x3C) != 0) {
            u8 *g;
            s32 i;
            a = func_L39_005B25C8_00534988();
            func_0037E2F0(&v1, 1.0f, 1.0f);
            vec_sub_ba(&v2, &D_L39_0024DF80[D_L39_00241298_00534988].pos, a0 + 0x10);
            func_00388758(&v3, &v2, &v1);
            func_00388830(&v3, &v3, 1.0f);
            g = D_L39_00296918;
            for (i = 0; i < 100; i++) {
                s32 n;
                u8 *e;
                n = func_L39_005B2568(2.0f, 5.0f);
                func_00389158(&v4, &v3, &v1, a);
                func_00388830(&v4, &v4, *(f32 *)(s + 0xC) * 0.25f);
                e = func_L01_0046DCB8(a0 + 0x10, &v4, func_L39_005B24C8(0x14, 0x1B),
                                      *(f32 *)(s + 0xC) * 231000.0f, *(s32 *)(s + 0x60), n, 0x4F, 0,
                                              *(f32 *)(s + 0xC) * 252000.02f, 0.0f, 1);
                if (e != 0) {
                    e[2] = **(u8 **)(g + 0x170);
                }
                a = func_00389380(a, 0.06346652f);
            }
        }
        if (*(s16 *)(s + 0x10) == 0x36 && *(s16 *)(s + 0x16) != 0) {
            a = func_L39_005B25C8_00534988();
            if (func_L01_003F9498(a0 + 0x10, 1.0f, 0x14, 0) != 0) {
                v1 = *(vu0_v4 *)(D_L39_0025F860 + 0x20);
                v2 = *(vu0_v4 *)D_L39_0025F860;
            } else {
                func_0037E2F0(&v1, 1.0f, 1.0f);
                v2 = *(vu0_v4 *)(a0 + 0x10);
            }
            func_00388830(&v1, &v1, 0.05f);
            vec_add_ba(&v2, &v2, &v1);
            func_00388830(&v1, &v1, 1.0f);
            vec_sub_ba(&v3, &D_L39_0024DF80[D_L39_00241298_00534988].pos, a0 + 0x10);
            func_00388758(&v4, &v3, &v1);
            func_00388830(&v4, &v4, 1.0f);
            if (*(s16 *)(s + 0x36) != 0) {
                u8 *g = D_L39_00296918;
                s32 i;
                for (i = 0; i < 100; i++) {
                    s32 n;
                    u8 *e;
                    n = func_L39_005B2568(2.0f, 5.0f);
                    func_00389158(&v5, &v4, &v1, a);
                    func_00388830(&v5, &v5, func_L39_005B2510(5.0f, 9.0f) * 0.0166666675f * *(f32 *)(s + 0xC));
                    if (i % 3 == 0) {
                        e = func_L01_0046DCB8(&v2, &v5, func_L39_005B24C8(0x14, 0x1B),
                                              *(f32 *)(s + 0xC) * 231000.0f, *(s32 *)(s + 0x60), n, 0x4F, 0,
                                              *(f32 *)(s + 0xC) * 252000.02f, 0.0f, 1);
                        if (e != 0) {
                            e[2] = **(u8 **)(g + 0x170);
                        }
                    }
                    a = func_00389380(a, 0.06346652f);
                }
            } else {
                u8 *g = D_L39_00296918;
                s32 i;
                for (i = 0; i < 100; i++) {
                    s32 n;
                    u8 *e;
                    n = func_L39_005B2568(2.0f, 5.0f);
                    func_00389158(&v5, &v4, &v1, a);
                    func_00388830(&v5, &v5, *(f32 *)(s + 0xC) * 0.25f);
                    e = func_L01_0046DCB8(&v2, &v5, func_L39_005B24C8(0x14, 0x1B),
                                          *(f32 *)(s + 0xC) * 231000.0f, *(s32 *)(s + 0x60), n, 0x4F, 0,
                                              *(f32 *)(s + 0xC) * 252000.02f, 0.0f, 1);
                    if (e != 0) {
                        e[2] = **(u8 **)(g + 0x170);
                    }
                    a = func_00389380(a, 0.06346652f);
                }
            }
        }
        func_003883C8(s + 0x14);
        func_L01_004026A0(func_L01_003317C8, a0);
    } else {
        func_003BD360(a0);
    }
}
/* localdecomp:end func_L39_00534988 */
