#include "common.h"

/* localdecomp:start func_L39_00535028 */
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

extern s32 D_L39_00241118;
extern C_00535028 D_L39_0024DE80[];
extern u8 D_L39_0025F760[];
extern f32 D_L39_004703D0[];
extern u8 D_L39_00296818[];
extern s32 D_L39_0024AD58;
__asm__(".extern D_L39_0024AD58, 4");

extern s32 func_L01_0044C638(u8 *, s32, u8 *, u8 *, u8 *, u8 *);
extern s32 func_0038CB00(void *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0044C870(u8 *, s32, u8 *, void *);
extern void func_00382580(void *, f32, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern void *func_L01_00470668(void *, void *, s32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern Q_00535028 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, s32, s32);
extern f32 func_L39_005B44C8(void);
extern void *func_L01_002FB660(void *, void *, s32, s32, s32, s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);
extern s32 func_L01_003FB640(void *, f32, s32, u8 *);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_00331DD0(void);
extern void func_003C2880(void *);

void func_L39_00535028(u8 *a0) {
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
        func_L01_0044C638(a0, *(s32 *)(s + 0x38), a0 + 0x10, a0 + 0xF0, a0 + 0x10, a0 + 0xF0);
    }
    if (func_0038CB00(s + 0x10) == 0) {
        ang = func_0038D160(D_L39_0024DE80[D_L39_00241118].pos.x - ((vu0_v4 *)(a0 + 0x10))->x,
                            D_L39_0024DE80[D_L39_00241118].pos.y - ((vu0_v4 *)(a0 + 0x10))->y);
        qzero(&v0);
        if (*(s32 *)(s + 0x38) != 0) {
            func_L01_0044C870(a0, *(s32 *)(s + 0x38), a0 + 0x10, &v0);
        }
        if (*(s16 *)(s + 0x10) == 0x3A) {
            s32 i;
            for (i = 0; i < *(s16 *)(s + 0x32); i++) {
                func_00382580(&v1, *(f32 *)(s + 0xC) * 0.3f, *(f32 *)(s + 0xC) * 0.40000004f);
                vec_add_ab(&v1, &v1, &v0);
                func_L01_00470668(a0 + 0x10, &v1, (func_L39_005B43C8(0x19, 0x28) * 5 + 2) / 6, 0.00584f);
            }
        }
        if (*(s16 *)(s + 0x10) == 0x39) {
            s32 i;
            s32 k;
            s32 sign = 1;
            for (i = 0; i < *(s32 *)(s + 0x2C); i++) {
                Q_00535028 *q;
                sign = -sign;
                k = (D_L39_0024AD58 + 1) % 44;
                v1.x = ((vu0_v4 *)(a0 + 0x10))->x + D_L39_004703D0[k] * *(f32 *)(s + 0xC);
                D_L39_0024AD58 = k;
                k = (D_L39_0024AD58 + 1) % 44;
                v1.y = ((vu0_v4 *)(a0 + 0x10))->y + D_L39_004703D0[k] * *(f32 *)(s + 0xC);
                D_L39_0024AD58 = k;
                k = (D_L39_0024AD58 + 1) % 44;
                v1.z = ((vu0_v4 *)(a0 + 0x10))->z + D_L39_004703D0[k] * *(f32 *)(s + 0xC);
                D_L39_0024AD58 = k;
                a = func_L39_005B4410(0.020000001f, 0.040000003f) * *(f32 *)(s + 0xC);
                b = func_L39_005B4468(0.0f, 1.3962634f);
                func_00382760(&v2, a, func_0038DAB8(ang, func_L39_005B4468(0.0f, 1.5707964f)), b);
                vec_add_ab(&v2, &v2, &v0);
                q = func_L01_004669B0(&v1, 0.0f, 1.0f, 1.01f, *(f32 *)(s + 0xC) * 1.5f * 210000.0f, sign, &v2,
                                      *(s32 *)(s + 0x58), 0);
                if (q != 0) {
                    P_00535028 *p;
                    q->hA = (func_L39_005B43C8(0x28, 0x46) * 5 + 2) / 6;
                    q->b9 = 0x44;
                    p = &q->sub;
                    p->w4 = 3;
                    p->f1C = (func_L39_005B43C8(1, 10) * 5 + 2) / 6;
                    p->bA = 0x40;
                    p->bB = q->hA;
                }
            }
        }
        if (*(s16 *)(s + 0x10) == 0x38) {
            s32 i;
            for (i = 0; i < *(s16 *)(s + 0x30); i++) {
                a = func_L39_005B4410(0.43633232f, 0.7853982f);
                b = func_L39_005B44C8();
                func_00382760(&v1, func_L39_005B4410(10.0f, 20.0f) * 0.020000001f * *(f32 *)(s + 0xC), b, a);
                vec_add_ab(&v1, &v1, &v0);
                func_L01_002FB660(a0 + 0x10, &v1, func_L39_005B43C8(100, 125), 2, 0, 1);
            }
        }
        if (*(s16 *)(s + 0x10) == 0x37 && *(s16 *)(s + 0x3C) != 0) {
            u8 *g;
            s32 i;
            a = func_L39_005B44C8();
            func_00382580(&v1, 1.0f, 1.0f);
            vec_sub_ba(&v2, &D_L39_0024DE80[D_L39_00241118].pos, a0 + 0x10);
            func_0038CE90(&v3, &v2, &v1);
            func_0038CF68(&v3, &v3, 1.0f);
            g = D_L39_00296818;
            for (i = 0; i < 100; i++) {
                s32 n;
                u8 *e;
                n = func_L39_005B4468(2.0f, 5.0f);
                func_0038D890(&v4, &v3, &v1, a);
                func_0038CF68(&v4, &v4, *(f32 *)(s + 0xC) * 0.3f);
                e = func_L01_004713C8(a0 + 0x10, &v4, (func_L39_005B43C8(0x14, 0x1B) * 5 + 2) / 6,
                                      *(f32 *)(s + 0xC) * 231000.0f, *(s32 *)(s + 0x60), n, 0x4F, 0,
                                              *(f32 *)(s + 0xC) * 252000.02f, 0.0f, 1);
                if (e != 0) {
                    e[2] = **(u8 **)(g + 0x170);
                }
                a = func_0038DAB8(a, 0.06346652f);
            }
        }
        if (*(s16 *)(s + 0x10) == 0x36 && *(s16 *)(s + 0x16) != 0) {
            a = func_L39_005B44C8();
            if (func_L01_003FB640(a0 + 0x10, 1.0f, 0x14, 0) != 0) {
                v1 = *(vu0_v4 *)(D_L39_0025F760 + 0x20);
                v2 = *(vu0_v4 *)D_L39_0025F760;
            } else {
                func_00382580(&v1, 1.0f, 1.0f);
                v2 = *(vu0_v4 *)(a0 + 0x10);
            }
            func_0038CF68(&v1, &v1, 0.05f);
            vec_add_ba(&v2, &v2, &v1);
            func_0038CF68(&v1, &v1, 1.0f);
            vec_sub_ba(&v3, &D_L39_0024DE80[D_L39_00241118].pos, a0 + 0x10);
            func_0038CE90(&v4, &v3, &v1);
            func_0038CF68(&v4, &v4, 1.0f);
            if (*(s16 *)(s + 0x36) != 0) {
                u8 *g = D_L39_00296818;
                s32 i;
                for (i = 0; i < 100; i++) {
                    s32 n;
                    u8 *e;
                    n = func_L39_005B4468(2.0f, 5.0f);
                    func_0038D890(&v5, &v4, &v1, a);
                    func_0038CF68(&v5, &v5, func_L39_005B4410(5.0f, 9.0f) * 0.020000001f * *(f32 *)(s + 0xC));
                    if (i % 3 == 0) {
                        e = func_L01_004713C8(&v2, &v5, (func_L39_005B43C8(0x14, 0x1B) * 5 + 2) / 6,
                                              *(f32 *)(s + 0xC) * 231000.0f, *(s32 *)(s + 0x60), n, 0x4F, 0,
                                              *(f32 *)(s + 0xC) * 252000.02f, 0.0f, 1);
                        if (e != 0) {
                            e[2] = **(u8 **)(g + 0x170);
                        }
                    }
                    a = func_0038DAB8(a, 0.06346652f);
                }
            } else {
                u8 *g = D_L39_00296818;
                s32 i;
                for (i = 0; i < 100; i++) {
                    s32 n;
                    u8 *e;
                    n = func_L39_005B4468(2.0f, 5.0f);
                    func_0038D890(&v5, &v4, &v1, a);
                    func_0038CF68(&v5, &v5, *(f32 *)(s + 0xC) * 0.3f);
                    e = func_L01_004713C8(&v2, &v5, (func_L39_005B43C8(0x14, 0x1B) * 5 + 2) / 6,
                                          *(f32 *)(s + 0xC) * 231000.0f, *(s32 *)(s + 0x60), n, 0x4F, 0,
                                              *(f32 *)(s + 0xC) * 252000.02f, 0.0f, 1);
                    if (e != 0) {
                        e[2] = **(u8 **)(g + 0x170);
                    }
                    a = func_0038DAB8(a, 0.06346652f);
                }
            }
        }
        func_0038CB00(s + 0x14);
        func_L01_00404A10(func_L01_00331DD0, a0);
    } else {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L39_00535028 */
