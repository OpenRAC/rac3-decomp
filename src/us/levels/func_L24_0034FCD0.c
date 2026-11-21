#include "common.h"

/* NTSC-U counterpart of func_L24_00350C30 (src/levels/24_insomniac_museum/L24_0034F040.c) */
#include "vu0.h"
typedef struct {
    u8 p0[0x80];
    vu0_q x80;
    vu0_q x90;
    u8 pA0[0x30];
    vu0_q xD0;
    u8 pE0[0x108 - 0xE0];
    f32 x108;
    u8 p10C[0x19E0 - 0x10C];
    s32 x19E0;
    s16 x19E4;
    u8 p19E6[0x25C0 - 0x19E6];
    u8 *x25C0;
    u8 p25C4[0x25E5 - 0x25C4];
    u8 x25E5;
} S_34F040;
extern S_34F040 D_001A4BE0;
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
#include "vu0.h"
extern void func_003886E8(f32 *, void *, f32);
extern f32 func_00388A28(f32, f32);
#include "vu0.h"
#include "vu0.h"
extern u8 *func_0037E0B8(void *);
extern f32 func_00388800(void *, void *);
extern f32 func_00388A28(f32, f32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
#include "vu0.h"
extern u8 *func_0037E0B8(void *);
#include "vu0.h"
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_003886E8(f32 *, void *, f32);
#include "vu0.h"
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_003886E8(f32 *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
extern f32 func_00388800(void *, void *);
extern void func_003886E8(f32 *, void *, f32);
extern f32 func_0037E250(f32, f32);
#include "vu0.h"
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_L01_00447D00(void *, void *, s32, f32, f32, s32, s32, s32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);
#include "vu0.h"
extern u8 *func_0037E0B8(void *);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_L01_0040C260(f32 *, f32 *, f32 *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00447D00(void *, void *, s32, f32, f32, s32, s32, s32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);

/* localdecomp:start func_L24_0034FCD0 */
#include "vu0.h"
extern u8 *func_0037E0B8(void *);
extern f32 func_00388800(void *, void *);
extern f32 func_L18_00454598(f32, f32, f32 *, f32, f32, f32);
extern f32 func_L01_0040BF90(void *);
extern void func_003886E8(f32 *, void *, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_003887A0(void *);
extern void func_0037E4B8(void *, f32, f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00460318(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_00388880(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern void func_L01_0040C260(f32 *, f32 *, f32 *);
extern void func_L01_00447D00(void *, void *, s32, f32, f32, s32, s32, s32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);
extern s32 func_00388398(void *);
extern u8 D_L24_001E8F40_0034FCD0[];

typedef struct {
    f32 dir[4];
    void *obj;
    s32 x14;
    u8 x18;
    u8 x19;
    u16 x1A;
    f32 x1C;
    s32 x20;
    u8 p24[0x30 - 0x24];
} S_350C30;

void func_L24_0034FCD0(u8 *obj) {
    u8 *s;
    u8 *t;
    u8 *r;
    u8 *g;
    u8 *h;
    f32 *from;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 r1;
    f32 r2;
    f32 k;
    s32 n;
    f32 v20[4];
    f32 v30[4];
    f32 v40[4];
    f32 v50[4];

    if (obj == 0) return;
    s = *(u8 **)(obj + 0x68);
    if (s == 0) return;
    *(vu0_q *)v30 = 0;
    v30[2] = 0.13333334f;
    *(f32 *)(obj + 0x2C) += (*(f32 *)(*(u8 **)(obj + 0x24) + 0x24) - *(f32 *)(obj + 0x2C)) * 0.05f;
    *(f32 *)(s + 0x20) += (1.0f - *(f32 *)(s + 0x20)) * 0.1f;
    if (*(u8 **)(s + 0x18) != 0) {
        r = func_0037E0B8(*(u8 **)(s + 0x18));
        if (r != 0) {
            if (*(f32 *)r <= 0.0f) {
                *(u8 **)(s + 0x18) = 0;
            }
        } else if (4.0f < func_00388800(*(u8 **)(s + 0x18) + 0x10, s)) {
            *(u8 **)(s + 0x18) = 0;
        }
    }
    if (*(s32 *)(s + 0x14) < 0xF5) {
        t = *(u8 **)(s + 0x18);
        if (t == 0 || *(s16 *)(t + 0xAA) != *(s32 *)(s + 0x34) || t[0x20] == 0xFE || t[0x20] == 0xFD) {
            *(u8 **)(s + 0x18) = 0;
            *(f32 *)(obj + 0xF8) = func_L18_00454598(*(f32 *)(obj + 0xF8), *(f32 *)(s + 0x2C), (f32 *)(s + 0x24), 0.02617994f, 0.0f, 0.0f);
            *(f32 *)(obj + 0xF4) = func_L18_00454598(*(f32 *)(obj + 0xF4), *(f32 *)(s + 0x30), (f32 *)(s + 0x28), 0.02617994f, 0.0f, 0.0f);
        } else {
            f32 v60[4];
            f32 v70[4];
            f32 v80[4];
            f32 v90[4];
            vu0_q p;
            vu0_q a2;

            __asm__("lqc2 %0, %1" : "=j"(p) : "m"(*(vu0_v4 *)(obj + 0x10)));
            *(vu0_q *)v80 = *(vu0_q *)(t + 0x10);
            v80[2] += *(f32 *)(s + 0x1C);
            vec_sub_ab(v70, v80, s);
            __asm__("lqc2 %0, %1" : "=j"(a2) : "m"(*(vu0_v4 *)v80));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(a2) : "j"(a2), "j"(p));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)v60) : "j"(a2));
            *(vu0_q *)s = *(vu0_q *)v80;
            c = func_L01_0040BF90(v70);
            b = (v70[0] * v60[0] + v70[1] * v60[1] + v70[2] * v60[2]) * -2.0f;
            a = *(f32 *)(s + 0x20) * *(f32 *)(s + 0x20) - c;
            c = func_L01_0040BF90(v60);
            d = sqrt_asm(b * b - a * 4.0f * -c);
            r1 = (-b + d) / (a + a);
            r2 = (-b - d) / (a + a);
            if (0.0f < r1 && 0.0f < r2) {
                k = (r2 < r1) ? r1 : r2;
            } else if (0.0f < r1) {
                k = r1;
            } else if (0.0f < r2) {
                k = r2;
            } else {
                k = -1.0f;
            }
            if (0.0f < k) {
                func_003886E8(v90, v70, k);
                vec_add_ab(v90, v90, v60);
                *(f32 *)(obj + 0xF8) = func_L18_00454598(*(f32 *)(obj + 0xF8), func_00388A28(v90[0], v90[1]), (f32 *)(s + 0x24), 0.02617994f, 0.0f, 0.0f);
                *(f32 *)(obj + 0xF4) = func_L18_00454598(*(f32 *)(obj + 0xF4), -func_00388A28(func_003887A0(v90), v90[2]), (f32 *)(s + 0x28), 0.02617994f, 0.0f, 0.0f);
            }
        }
    } else {
        if (*(u8 **)(s + 0x18) != 0) {
            *(vu0_q *)s = *(vu0_q *)(*(u8 **)(s + 0x18) + 0x10);
        }
    }
    func_0037E4B8(v50, *(f32 *)(s + 0x20), *(f32 *)(obj + 0xF8), -*(f32 *)(obj + 0xF4));
    {
    {
        f32 v60[4];
        f32 v70[4];

        *(vu0_q *)v70 = 0;
        v70[0] = func_0037E250(-1.0f, 1.0f);
        v70[1] = func_0037E250(-1.0f, 1.0f);
        v70[2] = func_0037E250(-1.0f, 1.0f);
        *(vu0_q *)v60 = *(vu0_q *)v70;
        func_00388830(v60, v60, func_0037E250(0.1f, 0.2f) * 0.016666668f);
        func_00388830(v40, v50, -func_0037E250(0.0016666668f, 0.016666668f));
        vec_add_ba(v60, v60, v40);
        func_00388830(v40, v50, func_0037E250(0.0f, 1.0f) * *(f32 *)(s + 0x20));
        vec_add_ba(v40, v40, obj + 0x10);
        n = func_0037E208(0x1C, 0x28);
        func_L01_00460318(v40, v60, 0x6F00AFFF, 0x100000FF, n, 0x28, func_0037E208(0x28, 0x46), 1);
    }
    }
    from = v20;
    *(vu0_q *)from = *(vu0_q *)(obj + 0x10);
    vec_add_ab(obj + 0x10, obj + 0x10, v50);
    if (*(f32 *)(obj + 0x10) < 0.0f || *(f32 *)(obj + 0x14) < 0.0f || *(f32 *)(obj + 0x18) < 0.0f) {
        func_003BD360(obj);
        return;
    }
    {
        S_350C30 q;

        q.obj = obj;
        q.x14 = 0x01030000;
        q.x1C = *(f32 *)(s + 0x38);
        q.x20 = 1;
        *(vu0_q *)q.dir = *(vu0_q *)v50;
        func_00388880(q.dir, q.dir, 1.0f);
        q.dir[2] = 1.0f;
        q.dir[3] = 5627.925f;
        q.x18 = 3;
        q.x19 = 3;
        q.x1A = *(u16 *)(obj + 0xAA);
        if (func_003CE740(from, obj + 0x10, 0, *(void **)(s + 0x10), &q) != 0) {
            g = D_L24_001E8F40_0034FCD0;
            h = *(u8 **)(g + 0x18);
            if (h != 0) {
                if (h == D_001A4BE0.x25C0) return;
                if (h == *(u8 **)(s + 0x10)) return;
                if (*(s16 *)(h + 0xAA) == 0x15DB) return;
                if (*(s16 *)(h + 0xAA) == 0) return;
                obj[0xBC] = 2;
                *(vu0_q *)(obj + 0x10) = *(vu0_q *)(g + 0x20);
                func_L01_0040C260(v30, v50, (f32 *)(g + 0x40));
                func_00388830(v30, v30, 0.033333335f);
                func_L01_00447D00(obj, v30, 0, 0.0f, 0.0f, 10, 3, 9, 4.0f, 2.0f, 9.0f, 1.0f, 15.0f, 0, 1, 1, -1, 0, 0x1010001);
                func_003BD360(obj);
            } else {
                if (*(s32 *)(g + 0x1C) <= 0) return;
                obj[0xBC] = 1;
                *(vu0_q *)(obj + 0x10) = *(vu0_q *)(g + 0x20);
                func_L01_0040C260(v30, v50, (f32 *)(g + 0x40));
                func_00388830(v30, v30, 0.033333335f);
                func_L01_00447D00(obj, v30, 0, 0.0f, *(f32 *)(s + 0x38), 10, 3, 9, 4.0f, 2.0f, 9.0f, 1.0f, 15.0f, 0, 1, 1, -1, 0, 0x1010001);
                func_003BD360(obj);
            }
        } else if (func_00388398(s + 0x14) != 0 || 300.0f < func_00388800(obj + 0x10, D_001A4BE0.x25C0 + 0x10)) {
            func_003BD360(obj);
        }
    }
}
/* localdecomp:end func_L24_0034FCD0 */
