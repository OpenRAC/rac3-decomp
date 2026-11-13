#include "common.h"

/* localdecomp:start func_L40_00434048 */
extern s32 D_001A6A80[];
extern s32 func_L39_005B4398(s32);
extern s32 func_0019D510(void);
extern s32 func_L40_00449B20(s32);
extern s32 func_L40_00449C10(void);
extern s32 func_L40_0044A430(s32 a0);

s32 func_L40_00434048(s32 *a0, u8 *a1) {
    s32 a;
    s32 b;
    s32 c;
    s32 r;
    s32 i;
    s32 res;

    *a0 = -1;
    *a1 = 0;
    a = 0;
    b = 75;
    c = 25;
    if (D_001A6A80[0] & 2) a = b;
    if (!(D_001A6A80[0] & 1)) b = 0;
    if (D_001A6A80[1] == 0) c = 0;
    r = func_L39_005B4398(b + a + c);
    if (r <= b) {
        *a0 = func_0019D510() & ~1;
        res = func_L40_00449B20(*a0);
        for (i = 0; res == 0; i++) {
            *a0 = func_0019D510() & ~1;
            res = func_L40_00449B20(*a0);
            if (i == 20) break;
        }
    } else if (r - b <= c) {
        *a0 = func_0019D510() & ~1;
        res = func_L40_0044A430(*a0);
        *a1 = 1;
        for (i = 0; res == 0; i++) {
            *a0 = func_0019D510() & ~1;
            res = func_L40_0044A430(*a0);
            if (i == 20) break;
        }
    } else {
        *a0 = func_L40_00449C10();
        res = func_L40_0044A430(*a0);
        *a1 = 1;
        for (i = 0; res == 0; i++) {
            *a0 = func_L40_00449C10();
            res = func_L40_00449B20(*a0);
            if (i == 20) break;
        }
    }
    return res;
}
/* localdecomp:end func_L40_00434048 */

/* localdecomp:start func_L40_004341E8 */
extern s32 func_L40_00449788(s32 a0, u8 *a1);
extern s32 func_L40_0044A4C8(s32 a0, u8 *a1);
s32 func_L40_004341E8(u8 *a0) {
    s32 r;
    if (*(s32 *)(a0 + 4) != 0) {
        if (a0[10] == 0) {
            r = func_L40_00449788(*(s16 *)(a0 + 8), a0);
        } else {
            r = func_L40_0044A4C8(*(s16 *)(a0 + 8), a0);
        }
        if (r != 0) {
            *(s32 *)(a0 + 4) = 0;
        }
    }
    return *(s32 *)(a0 + 4) == 0;
}
/* localdecomp:end func_L40_004341E8 */

/* localdecomp:start func_L40_00434248 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L40_00434248(s32 a0) {
    return func_L39_0066DD30(a0, 0, 0) != 0;
}
/* localdecomp:end func_L40_00434248 */

/* localdecomp:start func_L40_00434270 */
extern void func_L39_0066DCC8(int, int, int, int);
extern void func_L39_00662AA0(u8 *a0, void *a1, s32 a2);
extern void *func_0011D534(void *, s32, s32);
extern s32 D_001A5CD0[];
extern void func_L39_006626E8(u8 *a0);
extern s32 func_L40_00434048(s32 *a0, u8 *a1);

typedef struct {
    s32 f0;
    s32 f4;
    s16 f8;
    u8 fA;
} S_00434270;

typedef struct {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x8];
    u8 f20[0xC];
    u8 pad2C[0x4];
    u8 f30[0x20];
    u8 f50[0x8];
    S_00434270 f58[8];
} P_00434270;

void func_L40_00434270(u8 *a0) {
    u8 sel[16];
    u8 b[16];
    s32 w[2];
    P_00434270 *p;
    u8 *h;
    s32 r;
    s32 i;

    p = *(P_00434270 **)(a0 + 0x68);
    h = ((u8 * (*)(u8 *, s32, s32, s32))func_L39_0066DCC8)(a0, 0, 0, 0);
    func_0011D534(p->f30, 0, 0x20);
    func_0011D534(p->f20, 0, 0xC);
    func_0011D534(p->f50, 0, 8);
    p->f14 = 0;
    r = func_L40_00434048(&w[0], sel);
    if (r != 0) {
        w[1] = w[0];
        func_L39_00662AA0(h, &w[1], 4);
        b[0] = sel[0];
        func_L39_00662AA0(h, b, 1);
        i = D_001A5CD0[2];
        func_0011D534(&p->f58[i], 0, 0xC);
        p->f58[i].f8 = r;
        p->f58[i].f4 = 1;
        p->f58[i].f0 = 0;
        p->f58[i].fA = sel[0];
        p->f10 = 1;
        p->f14 = D_001A5CD0[0x128 / 4];
    } else {
        func_L39_006626E8(h);
    }
}
/* localdecomp:end func_L40_00434270 */

/* localdecomp:start func_L40_00434398 */
extern void func_L39_0066DCC8(int, int, int, int);
extern void func_L39_00662AA0(u8 *a0, void *a1, s32 a2);

void func_L40_00434398(s32 a0, s32 a1, s32 a2)
{
    s32 v;
    s32 b = a1 & 0xFF;
    u8 *h = ((u8 * (*)(s32, s32, s32, s32))func_L39_0066DCC8)(a0, 1, 0, 0);

    *(s32 *)(h + 0x50) = b;
    v = a2;
    func_L39_00662AA0(h, &v, 4);
}
/* localdecomp:end func_L40_00434398 */

/* localdecomp:start func_L40_004343F0 */
extern void func_L39_0066DCC8(int, int, int, int);

void func_L40_004343F0(int a0)
{
    func_L39_0066DCC8(a0, 2, 0, 0);
}
/* localdecomp:end func_L40_004343F0 */

INCLUDE_ASM("asm/levels", func_L40_00434418);

/* localdecomp:start func_L40_004349A0 */
extern s32 D_001A5CD0[];
extern s32 func_L39_005B4398(s32);
extern s32 func_L40_00434248(s32 a0);
extern void func_L40_00434270(u8 *a0);

s32 func_L40_004349A0(u8 *a0, s32 a1) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 n;
    s32 lim;
    s32 t;
    s32 r;
    s32 q;
    s32 rem;

    if (a1 == 0) {
        n = a0[0x20];
        if (n != 0) {
            if (n != 1) {
                return 0;
            }
            lim = D_001A5CD0[0x12C / 4];
            if (lim > 8) {
                lim = 8;
            }
            if (lim < 1) {
                lim = 1;
            }
            t = D_001A5CD0[0x128 / 4];
            r = t % (lim * 10000);
            q = r / 10000;
            rem = r - q * 10000;
            if (q > 7) {
                q = 7;
            }
            if (q < 0) {
                q = 0;
            }
            if (q == D_001A5CD0[2]) {
                if (rem >= 5000) {
                    return 0;
                }
                if (*(s32 *)(p + 0x10) != 0) {
                    return 0;
                }
                if (*(s32 *)(p + 4) + 45000 >= t) {
                    return 0;
                }
                if (func_L39_005B4398(250) != 1) {
                    return 0;
                }
                if (func_L40_00434248((s32)a0) != 0) {
                    return 0;
                }
                func_L40_00434270(a0);
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L40_004349A0 */
