#include "common.h"

/* NTSC-U counterpart of func_L02_00310838 (src/levels/shared/L02_0030FA80.c): 0.02 -> 0.0166667 */
#include "vu0.h"
typedef unsigned long UL_0030FF48;
typedef struct Obj_00310838 {
    s32 w0;
    s32 w4;
    u8 pad8[0x1C];
    f32 f24;
    f32 f28;
    f32 f2C;
    u8 b30;
    u8 b31;
    u8 b32;
    u8 pad33;
    u8 b34;
    u8 b35;
    u8 b36;
    u8 pad37[0x15];
    f32 f4C;
    u8 pad50[0x14];
    s8 c64[6];
} Obj_00310838;
typedef struct Stk_00310838 {
    vu0_v4 m[3];
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    vu0_v4 v70;
    vu0_v4 v80;
    vu0_v4 v90;
    vu0_v4 vA0;
    vu0_v4 vB0;
    vu0_v4 vC0;
    vu0_v4 vD0;
    vu0_v4 vE0;
    vu0_v4 vF0;
    vu0_v4 v100;
    vu0_v4 v110;
} Stk_00310838;
extern void func_L02_00310500(void *);
extern u8 D_L02_001E1300_00310500[];
extern UL_0030FF48 D_L02_0026ECE0[];
extern s32 D_L02_001E0144;
extern s32 D_L02_001E0148;
extern s32 D_L02_001E014C;
extern s32 D_L02_001E0150;
extern f32 D_L02_001E5EC0[];
extern long func_00384EC0(s32);
extern f32 D_L02_001E0154;
extern f32 D_L02_001E0138;
extern f32 *D_L02_001E0140;
extern f32 func_L02_0030F820(f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);

/* localdecomp:start func_L02_00310500 */
__asm__(".extern D_L02_001DC5A8, 4");

extern f32 D_L02_001DC5A8;
extern s32 D_L02_001DE540;
extern s32 D_L02_001DE55C;
extern f32 D_L02_001E015C;
extern f32 D_L02_001E0160;
extern f32 D_L02_001E0164;
extern f32 D_L02_001E0168;
extern f32 D_L02_001E016C;
extern f32 D_L02_001E5F70[];
extern f32 D_L02_001E5F74[];
extern u32 *D_L02_001DFA68;
extern u8 D_L02_001E11C0[];
extern u8 D_L02_001E12E0[];
extern u8 D_L02_001E1330[];
extern u8 D_00116070[];
extern u16 D_00116060[];
extern u8 D_001D5477_00310500;

extern void func_00388718(void *, void *, f32);
extern void func_003888C8(void *, void *, void *);
extern void func_003888F0(void *, void *, void *);
extern f32 func_003887C8(void *, void *);
extern f32 func_00388A28(f32, f32);
extern void func_003A3DE8(void *, s32);
extern void func_003A3EF0(s32, long);
extern void func_L01_0040C920(void *, void *);
extern void func_L02_003103F8(void *, void *, void *, void *, void *);
extern f32 func_L02_0030F8D0(f32);
extern void func_L02_003104A0(void *, f32 *, f32 *, f32);
extern void func_L02_00310170(f32 *, f32 *, f32 *, f32);

#define C0(T, o) (*(T *)((u8 *)D_L02_001E0140 + (o)))
#define CC(o) (*(f32 *)(c + (o)))

void func_L02_00310500(void *arg) {
    Stk_00310838 s;
    Obj_00310838 *p;
    f32 cur;
    f32 lim;
    f32 f26;
    f32 ang;
    f32 n0;
    f32 n1;
    f32 inv;
    f32 d;
    f32 ox;
    f32 nx;
    f32 q;
    f32 u1;
    f32 t;
    f32 r1;
    f32 r2;
    u32 k;
    long a;
    long b;
    long lo;
    long hi;
    u8 *cam;

    p = *(Obj_00310838 **)((u8 *)arg + 0x68);
    if (D_001D5477_00310500) {
        func_003886E8(D_L02_001E1330, D_L02_001E1330, -1.0f);
    }
    cur = p->f4C;
    f26 = (f32)D_L02_001DE540 * 0.0166666675f;
    cam = D_L02_001E11C0;
    lim = *(f32 *)(cam + 0x148);
    if (lim <= cur) {
        return;
    }
    if (lim <= cur + 0.5f) {
        cur = lim - 0.5f;
    }
    cur += D_L02_001E015C;
    ang = func_00388A28(*(f32 *)(cam + 0x188), *(f32 *)(cam + 0x178));
    n1 = *(f32 *)(cam + 0x160);
    n0 = -*(f32 *)(cam + 0x164);
    inv = 1.0f / sqrt_asm(n1 * n1 + n0 * n0);
    n1 = n1 * inv;
    n0 = n0 * inv;
    func_L01_0040C920(&s, cam + 0x160);
    ang = ang * 1.2732395f;
    ang = ang + 8.0f;
    s.v40.x = 1.0f;
    k = (s32)ang & 7;
    s.v40.w = 0.0f;
    switch (k) {
    case 0:
    case 1:
        s.v40.y = -D_L02_001E5EC0[0x2C];
        s.v40.z = -D_L02_001E5EC0[0x2D];
        break;
    case 2:
    case 3:
        s.v40.y = -D_L02_001E5EC0[0x2C];
        s.v40.z = D_L02_001E5EC0[0x2D];
        break;
    case 4:
    case 5:
        s.v40.y = D_L02_001E5EC0[0x2C];
        s.v40.z = D_L02_001E5EC0[0x2D];
        break;
    case 6:
    case 7:
        s.v40.y = D_L02_001E5EC0[0x2C];
        s.v40.z = -D_L02_001E5EC0[0x2D];
        break;
    }
    func_003888C8(&s.v30, &s.v40, D_L02_001E1300_00310500 + 0x20);
    if (0.0f <= s.v30.z) {
        return;
    }
    func_L02_003104A0(&s.v50, (f32 *)(D_L02_001E1300_00310500), (f32 *)&s.v30, cur);
    s.v80.w = 0.0f;
    switch (k) {
    case 0:
    case 3:
        s.v80.y = -1.0f;
        s.v80.x = D_L02_001E5F70[0];
        s.v80.z = 0.0f;
        break;
    case 1:
    case 6:
        s.v80.z = -1.0f;
        s.v80.x = D_L02_001E5F74[0];
        s.v80.y = 0.0f;
        break;
    case 2:
    case 5:
        s.v80.z = 1.0f;
        s.v80.x = D_L02_001E5F74[0];
        s.v80.y = 0.0f;
        break;
    case 4:
    case 7:
        s.v80.y = 1.0f;
        s.v80.x = D_L02_001E5F70[0];
        s.v80.z = 0.0f;
        break;
    }
    func_003888C8(&s.v70, &s.v80, D_L02_001E1300_00310500 + 0x20);
        s.v110.x = n0;
    s.v110.y = n1;
    s.v110.z = 0.0f;
    s.v110.w = 0.0f;
    func_L02_003103F8(&s.v60, &s.v50, &s.v110, D_L02_001E1300_00310500, &s.v70);
    d = func_003887C8(&s.v50, &s.v60);
    vec_add_ab(&s.vD0, &s.v50, &s.v60);
    func_003886E8(&s.vD0, &s.vD0, 0.5f);
    vec_sub_ab(&s.v100, &s.vD0, D_L02_001E1300_00310500);
    func_003888C8(&s.v100, &s.v100, &s.m);
    ox = s.v100.x;
    vec_sub_ba(&s.v100, &s.vD0, D_L02_001E1300_00310500);
    s.v100.x = s.v100.x + n1 * 650.0f;
    s.v100.y = s.v100.y + -n0 * 650.0f;
    func_003888C8(&s.v100, &s.v100, &s.m);
    nx = s.v100.x;
    q = d * nx / ox;
    if (d < 32.0f) {
        d = 32.0f;
    }
    D_L02_001E0138 = (q - d) * D_L02_001DC5A8 / ((nx - ox) * d);
    s.vD0.z = s.vD0.z - D_L02_001E015C;
    func_003886E8(&s.v90, &s.v110, d * 0.015625f);
    switch (k) {
    case 0:
    case 7:
        {
            u8 *c = D_L02_001E11C0;
            s.vB0.z = 0.0f;
            s.vB0.x = CC(0x174);
            s.vB0.y = -CC(0x170);
            s.vB0.w = 0.0f;
        }
        break;
    case 1:
    case 2:
        {
            u8 *c = D_L02_001E11C0;
            s.vB0.z = 0.0f;
            s.vB0.x = -CC(0x184);
            s.vB0.y = CC(0x180);
            s.vB0.w = 0.0f;
        }
        break;
    case 3:
    case 4:
        {
            u8 *c = D_L02_001E11C0;
            s.vB0.z = 0.0f;
            s.vB0.x = -CC(0x174);
            s.vB0.y = CC(0x170);
            s.vB0.w = 0.0f;
        }
        break;
    case 5:
    case 6:
        {
            u8 *c = D_L02_001E11C0;
            s.vB0.z = 0.0f;
            s.vB0.x = CC(0x184);
            s.vB0.y = -CC(0x180);
            s.vB0.w = 0.0f;
        }
        break;
    }
    inv = 1.0f / sqrt_asm(s.vB0.x * s.vB0.x + s.vB0.y * s.vB0.y);
    func_003886E8(&s.vB0, &s.vB0, inv * D_L02_001DC5A8);
    vec_sub_ab(&s.vE0, &s.vD0, D_L02_001E1300_00310500);
    s.vE0.w = 1.0f;
    func_003886E8(&s.v100, &s.vE0, 1024.0f);
    func_003888F0(&s.vF0, &s.v100, D_L02_001E1300_00310500 - 0x40);
    func_003886E8(&s.v100, &s.v90, 1024.0f);
    func_003888F0(&s.vA0, &s.v100, D_L02_001E1300_00310500 - 0x40);
    func_003886E8(&s.v100, &s.vB0, 1024.0f);
    func_003888F0(&s.vC0, &s.v100, D_L02_001E1300_00310500 - 0x40);
    if (D_L02_001DE55C != 10) {
        func_003A3DE8(D_00116070, D_00116060[0]);
        D_L02_001DE55C = 10;
    }
    D_L02_001DFA68[0] = D_L02_001E0144 | 0x30000000;
    D_L02_001DFA68[1] = (u32)D_L02_0026ECE0;
    D_L02_001DFA68[2] = 0x13000000;
    a = 0;
    b = 0;
    D_L02_001DFA68[3] = D_L02_001E0144 | 0x50000000;
    D_L02_001DFA68 = D_L02_001DFA68 + 4;
    if (p->w0 >= 0) {
        a = func_00384EC0(p->w0 + 0x64);
        if (D_L02_001E0148 > 0) {
            lo = D_L02_001E014C;
            hi = D_L02_001E0150;
            lo |= func_00384EC0(p->c64[0] + 0x64) & 0x3FFF;
            if (D_L02_001E0148 > 1) {
                lo |= (func_00384EC0(p->c64[1] + 0x64) & 0x3FFF) << 20;
                if (D_L02_001E0148 > 2) {
                    lo |= (func_00384EC0(p->c64[2] + 0x64) & 0x3FFF) << 40;
                    if (D_L02_001E0148 > 3) {
                        hi |= func_00384EC0(p->c64[3] + 0x64) & 0x3FFF;
                        if (D_L02_001E0148 > 4) {
                            hi |= (func_00384EC0(p->c64[4] + 0x64) & 0x3FFF) << 20;
                            if (D_L02_001E0148 > 5) {
                                hi |= (func_00384EC0(p->c64[5] + 0x64) & 0x3FFF) << 40;
                            }
                        }
                        func_003A3EF0(0x36, hi);
                    }
                }
            }
            func_003A3EF0(0x34, lo);
        }
    }
    if (p->w4 >= 0) {
        b = func_00384EC0(p->w4 + 0x64);
    }
    D_L02_001DFA68[0] = 0x1000002B;
    D_L02_001DFA68[1] = 0;
    D_L02_001DFA68[2] = 0x1000404;
    D_L02_001DFA68[3] = 0x6C2B0000;
    {
        u32 *w = D_L02_001DFA68;
        D_L02_001E0140 = (f32 *)(w + 4);
        D_L02_001DFA68 = w + 0xB0;
        w[0xB0] = 0x10000000;
    }
    D_L02_001DFA68[1] = 0;
    D_L02_001DFA68[2] = 0x14000000;
    D_L02_001DFA68[3] = 0x11000000;
    D_L02_001DFA68 = D_L02_001DFA68 + 4;
    func_L02_00310170((f32 *)&s.vD0, (f32 *)&s.v90, (f32 *)&s.vB0, f26);
    C0(f32, 0x160) = (f32)p->b30;
    C0(f32, 0x164) = (f32)p->b31;
    C0(f32, 0x168) = (f32)p->b32;
    C0(f32, 0x16C) = 0.0f;
    C0(vu0_q, 0x100) = *(vu0_q *)&s.vF0;
    C0(vu0_q, 0x110) = *(vu0_q *)&s.vA0;
    C0(vu0_q, 0x120) = *(vu0_q *)&s.vC0;
    u1 = 1.0f / p->f24;
    r1 = func_00388960(func_L02_0030F820(p->f28 * 0.017453292f));
    t = p->f2C * r1;
    r2 = func_00388978(func_L02_0030F820(p->f28 * 0.017453292f));
    C0(f32, 0x130) = func_L02_0030F8D0((-s.vD0.y + f26 * (p->f2C * r2)) * u1);
    C0(f32, 0x134) = func_L02_0030F8D0((s.vD0.x - f26 * t) * u1);
    C0(f32, 0x138) = 1.0f;
    C0(f32, 0x140) = -s.v90.y * u1;
    C0(f32, 0x144) = s.v90.x * u1;
    C0(f32, 0x150) = -s.vB0.y * u1;
    C0(f32, 0x154) = s.vB0.x * u1;
    C0(f32, 0x118) = D_L02_001E0138;
    C0(f32, 0x13C) = 0.0f;
    C0(f32, 0x15C) = 1.0f;
    func_00388718((u8 *)D_L02_001E0140 + 0x180, D_L02_001E12E0, 1024.0f);
    C0(vu0_q, 0x190) = *(vu0_q *)((u8 *)D_L02_001E5EC0 + 0x190);
    C0(f32, 0x190) = C0(f32, 0x190) * D_L02_001E5EC0[0x74];
    C0(f32, 0x194) = C0(f32, 0x194) * D_L02_001E5EC0[0x75];
    C0(vu0_q, 0x1A0) = *(vu0_q *)((u8 *)D_L02_001E5EC0 + 0x1A0);
    C0(s32, 0x1B0) = 0x21;
    C0(s32, 0x1B4) = 0x32;
    C0(s32, 0x1B8) = 0x32;
    C0(s32, 0x1BC) = 5;
    C0(f32, 0x268) = D_L02_001E0160;
    C0(f32, 0x26C) = D_L02_001E0164;
    C0(f32, 0x19C) = D_L02_001E0168;
    C0(f32, 0x1AC) = D_L02_001E016C;
    C0(s32, 0x1C0) = 0x8000;
    C0(s32, 0x1C4) = p->w0 >= 0 ? 0x303E4000 : 0x30364000;
    C0(s32, 0x1C8) = 0x412;
    C0(s32, 0x1CC) = 0;
    func_003886E8((u8 *)D_L02_001E0140 + 0x210, &s.vE0, -1.0f);
    func_003886E8((u8 *)D_L02_001E0140 + 0x220, &s.v90, -1.0f);
    func_003886E8((u8 *)D_L02_001E0140 + 0x230, &s.vB0, -1.0f);
    C0(f32, 0x22C) = n1 * D_L02_001E0154;
    C0(f32, 0x21C) = -n0 * D_L02_001E0154;
    C0(f32, 0x228) = 1.0f;
    C0(s32, 0x240) = p->b34;
    C0(s32, 0x244) = p->b35;
    C0(s32, 0x248) = p->b36;
    C0(s32, 0x250) = 0x8000;
    C0(s32, 0x254) = p->w4 >= 0 ? 0x313E4000 : 0x31364000;
    C0(s32, 0x258) = 0x412;
    C0(s32, 0x25C) = 0;
    switch (k) {
    case 0:
    case 7:
        C0(s32, 0x270) = 0x32;
        C0(s32, 0x274) = 0x31;
        C0(s32, 0x278) = 8;
        break;
    case 1:
    case 2:
        C0(s32, 0x270) = 0x34;
        C0(s32, 0x274) = 0x38;
        C0(s32, 0x278) = 2;
        break;
    case 3:
    case 4:
        C0(s32, 0x270) = 0x31;
        C0(s32, 0x274) = 0x32;
        C0(s32, 0x278) = 4;
        break;
    case 5:
    case 6:
        C0(s32, 0x270) = 0x38;
        C0(s32, 0x274) = 0x34;
        C0(s32, 0x278) = 1;
        break;
    }
    if (D_001D5477_00310500) {
        s32 x = C0(s32, 0x274);
        s32 y = C0(s32, 0x270);
        C0(s32, 0x270) = x;
        C0(s32, 0x274) = y;
    }
    C0(s32, 0x280) = 1;
    C0(s32, 0x284) = 0x10000000;
    C0(s32, 0x288) = 0xE;
    C0(s32, 0x28C) = 0;
    C0(long, 0x290) = a;
    C0(s32, 0x298) = 6;
    C0(long, 0x2A0) = b;
    C0(s32, 0x2A8) = 7;
    func_003A3EF0(0x47, 0x5360B);
    if (D_001D5477_00310500) {
        func_003886E8(D_L02_001E1330, D_L02_001E1330, -1.0f);
    }
}
/* localdecomp:end func_L02_00310500 */
