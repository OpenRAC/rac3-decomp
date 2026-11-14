#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003A46C8);

INCLUDE_ASM("asm/levels", func_L07_003A5078);

INCLUDE_ASM("asm/levels", func_L07_003A52F0);

/* localdecomp:start func_L07_003A55D8 */
void func_003C2880(s32);
void func_L07_00334740(void *);
void func_L07_003A5780(void *, s32);

void func_L07_003A55D8(void *arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    temp_a0 = *(s32 *)((u8 *)temp_s0 + 0x498);
    if (temp_a0 != 0) {
        func_003C2880(temp_a0);
        *(s32 *)((u8 *)temp_s0 + 0x498) = 0;
        *(s32 *)((u8 *)temp_s0 + 0x264) = 0;
    }
    temp_a0_2 = *(s32 *)((u8 *)temp_s0 + 0x494);
    if (temp_a0_2 != 0) {
        func_003C2880(temp_a0_2);
        *(s32 *)((u8 *)temp_s0 + 0x494) = 0;
        *(s32 *)((u8 *)temp_s0 + 0x260) = 0;
    }
    *(s16 *)((u8 *)arg0 + 0x7C) = 0x1F;
    *(f32 *)((u8 *)temp_s0 + 0x250) = (f32) (*(s16 *)((u8 *)temp_s0 + 0x34));
    func_L07_00334740(arg0);
    func_L07_003A5780(arg0, 1);
}
/* localdecomp:end func_L07_003A55D8 */

INCLUDE_ASM("asm/levels", func_L07_003A5670);

INCLUDE_ASM("asm/levels", func_L07_003A5780);

INCLUDE_ASM("asm/levels", func_L07_003A5CA8);

INCLUDE_ASM("asm/levels", func_L07_003A5D80);

/* localdecomp:start func_L07_003A5ED0 */
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern s32 func_L07_00334408(void *);
extern s32 func_L07_003346D8(u8 *);
void func_L07_003A5780(void *, s32);

s32 func_L07_003A5ED0(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    f32 dx;
    f32 dz;
    f32 ang;
    f32 diff;

    dx = *(f32 *)(p + 0x130) - *(f32 *)(arg0 + 0x10);
    dz = *(f32 *)(p + 0x134) - *(f32 *)(arg0 + 0x14);
    ang = func_0038D160(dx, dz);
    diff = func_0038DBA0(*(f32 *)(arg0 + 0xF8), ang);
    if (diff < 0.78539816f) {
        *(s16 *)(p + 0x27C) = func_L07_00334408(arg0);
        if (func_L07_003346D8(arg0) != 0) {
            *(s32 *)(p + 0x188) &= ~0x10;
            if (*(u8 *)(p + 0x4A5) == 0) {
                func_L07_003A5780(arg0, 0xF);
            } else {
                func_L07_003A5780(arg0, 0xC);
            }
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L07_003A5ED0 */

/* localdecomp:start func_L07_003A5FA0 */
extern s32 func_00382468(s32);
u8 func_L07_003A5FA0(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    if (*(s32 *)(p + 0x498) == 0) {
        return 0;
    }
    if (*(s32 *)(p + 0x494) == 0) {
        return 1;
    }
    return func_00382468(2);
}
/* localdecomp:end func_L07_003A5FA0 */

/* localdecomp:start func_L07_003A5FE0 */
void func_L07_003A5780(void *, s32);
s32 func_L07_003A6110(void *, s32);
extern f32 func_0038DB00(f32, f32);
extern s32 func_00382468(s32);

void func_L07_003A5FE0(void *arg0, u8 arg1) {
    u8 s0;
    void *p;
    f32 f;

    p = *(void **)((u8 *)arg0 + 0x68);
    f = func_0038DB00(*(f32 *)((u8 *)p + 0x284), *(f32 *)((u8 *)p + 0x280));
    if (0.0f < f) {
        s0 = 1;
    } else if (f < 0.0f) {
        s0 = 0;
    } else {
        s0 = func_00382468(2);
    }
    if (func_L07_003A6110(arg0, s0) != 0) {
        func_L07_003A5780(arg0, arg1 + s0);
        return;
    }
    if (s0 != 0) {
        s0 = 0;
    } else {
        s0 = 1;
    }
    if (func_L07_003A6110(arg0, s0) != 0) {
        func_L07_003A5780(arg0, arg1 + s0);
    }
}
/* localdecomp:end func_L07_003A5FE0 */

/* localdecomp:start func_L07_003A60A8 */
extern f32 func_L01_0040E4C0(void *);
extern void func_0038CF68(void *, void *, f32);

void func_L07_003A60A8(void *arg0, f32 x, f32 y) {
    u8 *o;
    void *p;
    f32 v;

    o = *(u8 **)((u8 *)arg0 + 0x68);
    p = o + 0x1F0;
    *(f32 *)(o + 0x178) = x;
    *(f32 *)(o + 0x170) = y;
    *(f32 *)(o + 0x174) = y;
    v = func_L01_0040E4C0(p);
    if (*(f32 *)(o + 0x178) * *(f32 *)(o + 0x178) < v) {
        func_0038CF68(p, p, *(f32 *)(o + 0x178));
        *(f32 *)(o + 0x200) = *(f32 *)(o + 0x178);
    }
}
/* localdecomp:end func_L07_003A60A8 */

/* localdecomp:start func_L07_003A6110 */
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L03_0032FAF0(f32 *, f32 *, f32, f32);
extern s32 func_L07_00333200(s32, void *, void *);

s32 func_L07_003A6110(void *arg0, s32 arg1) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    f32 v[4];
    f32 d;
    f32 num = 1.8133334f;
    f32 a;
    f32 r;

    d = func_0038CF38((u8 *)arg0 + 0x10, p + 0x130);
    a = num / d;
    if (a > 3.14159274f) {
        a = 3.14159274f;
    }
    if (arg1 == 0) {
        r = func_0038DB00(*(f32 *)(p + 0x280), a);
    } else {
        r = func_0038DAB8(*(f32 *)(p + 0x280), a);
    }
    func_L03_0032FAF0(v, (f32 *)(p + 0x130), r, d);
    return func_L07_00333200(*(s32 *)(p + 0x270), arg0, v);
}
/* localdecomp:end func_L07_003A6110 */

INCLUDE_ASM("asm/levels", func_L07_003A61E8);

/* localdecomp:start func_L07_003A63D8 */
void func_L07_003A63D8(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    p[0x490] = 0;
    p[0x491] = 0;
}
/* localdecomp:end func_L07_003A63D8 */

INCLUDE_ASM("asm/levels", func_L07_003A63E8);

/* localdecomp:start func_L07_003A6460 */
extern void func_L07_003A6498(u8 *, u8 *, s32, s32, s32);
void func_L07_003A6460(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    func_L07_003A6498(p + 0x350, p + 0x3F0, p[0x491], p[0x490], p[0x4A4] + 100);
}
/* localdecomp:end func_L07_003A6460 */

INCLUDE_ASM("asm/levels", func_L07_003A6498);

INCLUDE_ASM("asm/levels", func_L07_003A66E8);

INCLUDE_ASM("asm/levels", func_L07_003A6C90);

INCLUDE_ASM("asm/levels", func_L07_003A6EA8);

/* localdecomp:start func_L07_003A6EF8 */
extern f32 D_L07_001DEF50;
extern void func_L01_00443B18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00472F58(void *, void *, s32, f32);

void func_L07_003A6EF8(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68) + 0xA0;
    f32 v[4];
    f32 t = 0.95f;
    s32 i;

    for (i = 8; i >= 0; i--) {
        if (D_L07_001DEF50 < t) {
            func_L01_00443B18(v, 0.0030000003f);
            v[2] = func_003824E0(0.0050000004f, 0.020000001f);
            func_L01_00472F58(p, v, 0x44, func_003824E0(0.05f, 0.1f));
        }
        p += 0x10;
    }
}
/* localdecomp:end func_L07_003A6EF8 */

/* localdecomp:start func_L07_003A6FC8 */
extern s32 func_0038CAD0(void *);
extern f32 func_L01_004451A8(f32);

void func_L07_003A6FC8(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    u8 **q;
    s32 i;
    f32 t;
    u8 *o;

    if (arg1 != 0) {
        *(s32 *)(p + 0x158) = 0x43;
        return;
    }
    func_0038CAD0(p + 0x158);
    t = (f32) * (s32 *)(p + 0x158) / 33.0f;
    if (1.0f < t) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    func_L01_004451A8(t);
    q = (u8 **)(p + 0x130);
    for (i = 8; i >= 0; i--) {
        o = *q;
        if (o != 0) {
            *(f32 *)(o + 0xC) = t * 210000.0f * 0.75f;
        }
        q++;
    }
}
/* localdecomp:end func_L07_003A6FC8 */
