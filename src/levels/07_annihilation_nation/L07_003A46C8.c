#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003A46C8);

/* localdecomp:start func_L07_003A5078 */
/* after func_L07_00352510 (L07_00351C58.c), the same init shape */
extern s32 func_L07_003C1AF8(void);
extern f32 func_L07_003C1B40(s32);
extern void func_L01_00446058(void *, s32, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L07_003A55D8(void *);
extern void func_L07_003A5670(void *);

void func_L07_003A5078(u8 *self) {
    u8 *v = *(u8 **)(self + 0x68);
    s32 mode = func_L07_003C1AF8();
    u8 *p = v + 0x30;
    f32 factor = func_L07_003C1B40(mode);
    *(s16 *)(p + 4) = *(s16 *)(v + 0x34) * factor;
    *(f32 *)(v + 0x30) = *(s16 *)(p + 4);
    p[0x14] = v[0x44] * factor;
    p[0x15] = v[0x45] * factor;
    p[0x16] = v[0x46] * factor;
    if (mode == 1 || mode == 3) func_L01_00446058(self, 0x1D8C, 0x195E);
    p[0x28] = 20;
    p[0x2A] = 14;
    *(f32 *)(p + 0x10) = 1.25f;
    p[0xF] = 0;
    p[9] = 1;
    v[0x80] = 5;
    v[0x240] = 0xB0;
    v[0x241] = 0x50;
    v[0x242] = 0x80;
    v[0x244] = v[0x243] = 0xE0;
    v[0xB8] = 255;
    *(f32 *)(v + 0x120) = 1.0f;
    *(s32 *)(v + 0x124) |= 1;
    *(f32 *)(v + 0x150) = 0.65f;
    *(f32 *)(v + 0xA4) = *(f32 *)(v + 0xA0) = 0.5f;
    *(f32 *)(v + 0x154) = *(f32 *)(v + 0xAC) = 0.15f;
    *(f32 *)(v + 0x15C) = *(f32 *)(v + 0x158) = 0.5f;
    *(f32 *)(v + 0x160) = 3.1415927f;
    *(f32 *)(v + 0x180) = 0.7853982f;
    *(f32 *)(v + 0x17C) = 0.003920000046491623f;
    *(f32 *)(v + 0x184) = 0.2f;
    func_L01_0045BD78(self, 0.002f, 0.04400000348687172f, 0.005026548635214567f, 0.12566371262073517f);
    v[0x28D] = 5;
    *(s32 *)(v + 0x498) = 0;
    *(s32 *)(v + 0x264) = 0;
    *(s32 *)(v + 0x494) = 0;
    *(void **)(v + 0x274) = func_L07_003A5670;
    *(void **)(v + 0x278) = func_L07_003A55D8;
    *(s16 *)(v + 0x27C) = -1;
    v[0x28F] = 7;
    *(s32 *)(v + 0x260) = 0;
    func_L07_003A55D8(self);
}
/* localdecomp:end func_L07_003A5078 */

/* localdecomp:start func_L07_003A52F0 */
#include "vu0.h"
extern u8 D_L07_001E1EC0[];
void func_L07_003A52F0(u8 *self) {
    extern s32 func_L01_00452FB0(u8 *, u8 *, s32, s32, s32);
    extern void func_L07_003333F8(s32, f32, f32);
    extern void func_L07_00334588(u8 *);
    extern void func_L07_003DC020(s32, s32);
    extern void func_L01_00446A70(u8 *, u8 *, s32, void *, void *, f32);
    extern void func_L07_003315B0(u8 *);
    extern void func_L07_00331158(u8 *);
    extern void func_L01_0044FD88(u8 *, s32, s32, s32);
    extern void func_003C2F58(u8 *, s32, void *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern f32 func_0038CF38(void *, void *);
    extern void func_L01_0044E850(u8 *, u8 *, s32, f32, f32);
    extern void func_L07_004522E8(u8 *, s32, u8 *, f32);
    extern f32 func_L01_0040E548(void *, void *);
    extern void func_L01_004472C0(u8 *);
    extern void func_L01_00446780(u8 *, u8 *, s32, f32, f32, f32, s32, s32, s32);
    vu0_v4 pos;
    u8 *p = *(u8 **)(self + 0x68);
    f32 health;
    f32 angle;
    if (self[0x20] == 1) return;
    health = *(f32 *)(p + 0x30);
    if (func_L01_00452FB0(self, p + 0x70, 0, 0, 0)) {
        func_L07_003333F8(*(s32 *)(p + 0x270), health, *(f32 *)(p + 0x30));
        func_L07_00334588(self);
        *(s32 *)(p + 0x188) &= ~0x10;
        if (*(s32 *)(p + 0x498)) func_L07_003DC020(*(s32 *)(p + 0x498), 0);
    }
    if (*(s32 *)(p + 0x228) == 1) {
        qzero(&pos);
        func_L01_00446A70(self, self, 0x10000, &pos, &pos, *(s16 *)(p + 0x34));
    } else if (p[0x5E] || p[0x60] || p[0x3E] == 2) {
        func_L07_003315B0(self);
        return;
    }
    func_L07_00331158(self);
    if (*(s32 *)(p + 0x494)) func_L01_0044FD88(self, *(s32 *)(p + 0x494), 0, 0);
    if (*(s16 *)(p + 0x144) == 1) {
        func_003C2F58(self, 2, &pos);
        angle = func_0038D160(*(f32 *)(*(u8 **)(p + 0x140) + 0x10) - pos.x,
                             *(f32 *)(*(u8 **)(p + 0x140) + 0x14) - pos.y);
        *(f32 *)(p + 0x2F8) = func_0038DB00(angle, *(f32 *)(self + 0xF8));
        if (*(f32 *)(p + 0x2F8) > 0.5235987901687622f) *(f32 *)(p + 0x2F8) = 0.5235987901687622f;
        else if (*(f32 *)(p + 0x2F8) < -0.5235987901687622f) *(f32 *)(p + 0x2F8) = -0.5235987901687622f;
        angle = func_0038CF38(&pos, *(u8 **)(p + 0x140) + 0x10);
        *(f32 *)(p + 0x2F4) = -func_0038D160(angle, *(f32 *)(*(u8 **)(p + 0x140) + 0x18) - pos.z);
        if (*(f32 *)(p + 0x2F4) > 0.4363323152065277f) *(f32 *)(p + 0x2F4) = 0.4363323152065277f;
        else if (*(f32 *)(p + 0x2F4) < -0.4363323152065277f) *(f32 *)(p + 0x2F4) = -0.4363323152065277f;
    }
    func_L01_0044E850(self, p + 0x290, 2, 0.0432f, 0.4320000410079956f);
    func_L07_004522E8(self, 3, p + 0x310, 2.5f);
    if (self[0x31] && func_L01_0040E548(D_L07_001E1EC0, self + 0x10) < 576.0f) {
        func_L01_004472C0(self);
        self[0x6F] = 22;
    }
    func_L01_00446780(self, self + 0x10, 0x8000000, 0.75f, 1.0f, 1.0f, 0, 1, 0);
}
/* localdecomp:end func_L07_003A52F0 */

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

/* localdecomp:start func_L07_003A5670 */
typedef int Quad_003A5670 __attribute__((mode(TI)));
extern s32 func_L07_003DBF10(void *, s32, void *, f32, f32);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0044A7D0(void *);
extern void func_003C7C38(void *);
extern void func_L07_00334800(void *);
extern void func_L07_003A5780(void *, s32);
void func_L07_003A5670(void *arg0) {
    Quad_003A5670 offset;
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    u8 *child;
    if (p[0x28D] != 3) {
        offset = 0;
        ((f32 *)&offset)[2] = 1.6f;
        *(s32 *)(p + 0x498) = func_L07_003DBF10(arg0, 1, &offset,
            *(f32 *)(*(u8 **)(p + 0x270) + 0x18), (f32)p[0x45]);
    }
    if (p[0x28D] != 4) {
        child = func_003C24B0(0x1B3F, 0x80);
        *(u8 **)(p + 0x494) = child;
        if (child != 0) {
            *(u16 *)(child + 0x34) |= 0x100;
            *(u16 *)(*(u8 **)(p + 0x494) + 0x32) = *(u16 *)((u8 *)arg0 + 0x32);
            (*(u8 **)(p + 0x494))[0x31] = ((u8 *)arg0)[0x31];
            (*(u8 **)(p + 0x494))[0x30] = 0;
            func_L01_0044A7D0(*(u8 **)(p + 0x494));
            func_003C7C38(*(u8 **)(p + 0x494));
        }
    }
    *(s32 *)(p + 0x260) = *(s32 *)(p + 0x494);
    *(s32 *)(p + 0x264) = *(s32 *)(p + 0x498);
    p[0x28D] = 5;
    *(f32 *)((u8 *)arg0 + 0x2C) = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x24) + 0x24);
    func_L07_00334800(arg0);
    func_L07_003A5780(arg0, 2);
}
/* localdecomp:end func_L07_003A5670 */

/* localdecomp:start func_L07_003A5780 */
void func_L07_003A5780(void *arg0, s32 state) {
    extern void func_003C3A10(void *, s32, s32, s32);
    extern void func_L07_003A60A8(void *, f32, f32);
    extern void func_L07_003DC020(s32, s32);
    extern void func_L07_003A63D8(void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_L01_004450F0(u8 *, s32, s32);
    u8 *obj = arg0;
    u8 *p = *(u8 **)(obj + 0x68);
    switch (state) {
    case 1: case 3: case 5: break;
    case 2:
        if (obj[0x43] != 0) func_003C3A10(obj, 0, 0, 0);
        break;
    case 4:
        *(u16 *)(obj + 0x34) |= 0x5000;
        func_L07_003A60A8(obj, 0.12000000476837158f, 0.0036000001709908247f);
        if (obj[0x43] != 5) func_003C3A10(obj, 5, 0, 3);
        break;
    case 6:
        *(s32 *)(p + 0x188) &= ~0x10;
        if (obj[0x43] != 0) func_003C3A10(obj, 0, 0, 7);
        func_L07_003DC020(*(s32 *)(p + 0x498), 0);
        break;
    case 7:
        func_L07_003A60A8(obj, 0.12000000476837158f, 0.0036000001709908247f);
        *(f32 *)(p + 0x170) = 0.0036000001709908247f;
        *(f32 *)(p + 0x174) = 0.0036000001709908247f;
        *(f32 *)(p + 0x178) = 0.12000000476837158f;
        if (obj[0x43] != 5) func_003C3A10(obj, 5, 0, 7);
        break;
    case 8:
        *(s32 *)(p + 0x188) &= ~0x10;
        func_L07_003A60A8(obj, 0.04400000348687172f, 0.0020000000949949026f);
        if (obj[0x43] != 4) func_003C3A10(obj, 4, 0, 7);
        break;
    case 9:
        *(s16 *)(p + 0x492) = 17;
        if (obj[0x43] != 3) func_003C3A10(obj, 3, 0, 10);
        break;
    case 10:
        *(s32 *)(p + 0x188) |= 0x10;
        *(f32 *)(p + 0x170) = 0.00800000037997961f;
        *(f32 *)(p + 0x174) = 0.00800000037997961f;
        *(f32 *)(p + 0x178) = 0.04000000283122063f;
        if (obj[0x43] != 7) func_003C3A10(obj, 7, 0, 5);
        break;
    case 11:
        *(s32 *)(p + 0x188) |= 0x10;
        *(f32 *)(p + 0x170) = 0.00800000037997961f;
        *(f32 *)(p + 0x174) = 0.00800000037997961f;
        *(f32 *)(p + 0x178) = 0.04000000283122063f;
        if (obj[0x43] != 6) func_003C3A10(obj, 6, 0, 5);
        break;
    case 12:
        if (obj[0x43] != 12) func_003C3A10(obj, 12, 0, 4);
        break;
    case 13:
        *(s16 *)(p + 0x492) = 4;
        if (obj[0x43] != 13) func_003C3A10(obj, 13, 0, 2);
        break;
    case 14:
        func_L07_003A60A8(obj, 0.015000000596046448f, 0.0004000000189989805f);
        *(f32 *)(p + 0x200) = *(f32 *)(p + 0x178);
        func_L07_003DC020(*(s32 *)(p + 0x498), 1);
        if (obj[0x43] != 15) func_003C3A10(obj, 15, 0, 2);
        *(f32 *)(obj + 0x48) = 0.75f;
        break;
    case 15:
        if (obj[0x43] != 8) func_003C3A10(obj, 8, 0, 4);
        break;
    case 16:
        *(s16 *)(p + 0x492) = 4;
        if (obj[0x43] != 9) func_003C3A10(obj, 9, 0, 2);
        break;
    case 17:
        func_L07_003A60A8(obj, 0.015000000596046448f, 0.0004000000189989805f);
        *(f32 *)(p + 0x200) = *(f32 *)(p + 0x178);
        func_L07_003A63D8(obj);
        if (obj[0x43] != 10) func_003C3A10(obj, 10, 0, 2);
        break;
    case 18:
        *(f32 *)(p + 0x49C) = func_003824E0(6.0f, 7.5f);
        *(s32 *)(p + 0x188) &= ~0x10;
        func_L07_003A60A8(obj, 0.04400000348687172f, 0.0020000000949949026f);
        if (obj[0x43] != 4) func_003C3A10(obj, 4, 0, 5);
        break;
    case 19:
        *(f32 *)(p + 0x49C) = func_003824E0(6.0f, 7.5f);
        *(s32 *)(p + 0x188) &= ~0x10;
        func_L07_003A60A8(obj, 0.12000000476837158f, 0.0036000001709908247f);
        if (obj[0x43] != 5) func_003C3A10(obj, 5, 0, 7);
        break;
    case 20:
        *(s32 *)(p + 0x188) |= 0x10;
        func_L07_003A60A8(obj, 0.04000000283122063f, 0.00800000037997961f);
        if (obj[0x43] != 7) func_003C3A10(obj, 7, 0, 5);
        break;
    case 21:
        *(s32 *)(p + 0x188) |= 0x10;
        func_L07_003A60A8(obj, 0.04000000283122063f, 0.00800000037997961f);
        if (obj[0x43] != 6) func_003C3A10(obj, 6, 0, 5);
        break;
    }
    func_L01_004450F0(obj, state, -1);
}
/* localdecomp:end func_L07_003A5780 */

/* localdecomp:start func_L07_003A5CA8 */
typedef int Q_003A5CA8 __attribute__((mode(TI)));
void func_L07_003A5CA8(void *arg0, f32 *arg1, f32 arg2) {
    extern void func_L03_0032FAF0(f32 *, f32 *, f32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern f32 func_L07_00332CF0(s32, void *, void *, f32);
    extern s32 func_L01_0045A7A8(void *, void *, f32);
    extern void func_L07_00333DB8(s32, void *, s32, s32, f32);
    f32 v[4] __attribute__((aligned(16)));
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    f32 f;
    if (arg2 != 0.0f) {
        func_L03_0032FAF0(v, arg1, *(f32 *)(p + 0x280), arg2);
    } else {
        *(Q_003A5CA8 *)v = *(Q_003A5CA8 *)arg1;
    }
    f = func_0038DB00(*(f32 *)(p + 0x280), *(f32 *)(p + 0x284));
    f = func_L07_00332CF0(*(s32 *)(p + 0x270), arg0, v, f * 0.15f);
    func_L01_0045A7A8(arg0, v, f);
    if ((*(u16 *)((u8 *)arg0 + 0x96) & 7) == 0) {
        func_L07_00333DB8(*(s32 *)(p + 0x270), arg0, 0, 0, arg2);
    }
    (*(u16 *)((u8 *)arg0 + 0x96))++;
}
/* localdecomp:end func_L07_003A5CA8 */

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

/* localdecomp:start func_L07_003A63E8 */
typedef int Q_003A63E8 __attribute__((mode(TI)));

static __inline__ void copy_003A63E8(Q_003A63E8 *d, Q_003A63E8 *s) {
    *d = *s;
}

typedef struct {
    u8 pad0[0x350];
    Q_003A63E8 a[10];
    Q_003A63E8 b[10];

    u8 head;
    u8 count;
} S_003A63E8;

void func_L07_003A63E8(u8 *arg0, Q_003A63E8 *arg1, Q_003A63E8 *arg2) {
    S_003A63E8 *s = *(S_003A63E8 **)(arg0 + 0x68);
    int i;

    s->count++;
    if (s->count > 10) {
        s->head = (s->head + 1) % 10;
        s->count = 10;
    }
    i = (s->head + s->count - 1) % 10;
    copy_003A63E8(&s->a[i], arg1);
    copy_003A63E8(&s->b[i], arg2);
}
/* localdecomp:end func_L07_003A63E8 */

/* localdecomp:start func_L07_003A6460 */
extern void func_L07_003A6498(u8 *, u8 *, s32, s32, s32);
void func_L07_003A6460(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    func_L07_003A6498(p + 0x350, p + 0x3F0, p[0x491], p[0x490], p[0x4A4] + 100);
}
/* localdecomp:end func_L07_003A6460 */

/* localdecomp:start func_L07_003A6498 */
/* from func_L07_003CE618 (L07_003CE2B8.c), the same strip drawer */
typedef struct { f32 x, y, z, w; } UV_003A6498;
extern f32 D_L07_002A2100[][6];
extern u32 D_L07_002A21F0[][2];
extern UV_003A6498 D_L07_002A2240[];
extern f32 D_L07_001E1650[] __attribute__((section(".sdata")));
extern void func_0038C750(void);
extern long func_00389598(s32);
extern void func_003A9440(s32, unsigned long);
extern f32 func_0038CF00(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003D3A24(s32, void *, void *, void *, s32);

static __inline__ void copy_003A6498(f32 *d, f32 *s) {
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
}

void func_L07_003A6498(u8 *a0, u8 *a1, s32 count, s32 start, s32 texture) {
    s32 i;
    s32 j;
    s32 index;
    s32 next;
    f32 total;
    f32 t;
    s32 color;
    if (count < 2) return;
    func_0038C750();
    total = 0.0f;
    func_003A9440(6, func_00389598(texture));
    func_003A9440(20, 0x0000FF9000000260UL);
    func_003A9440(8, 0);
    func_003A9440(0x42, 0x4000000044UL);
    for (i = 0; i < count; i++) {
        index = (i + start) % count;
        next = (index + 1) % count;
        if (i != count - 1) {
            f32 distance = func_0038CF00(a0 + index * 16, a0 + next * 16);
            total += distance;
            D_L07_001E1650[i] = distance;
        }
        copy_003A6498(D_L07_002A2100[i], (f32 *)(a0 + index * 16));
        copy_003A6498(D_L07_002A2100[i] + 3, (f32 *)(a1 + index * 16));
    }
    total = 1.0f / total;
    t = 0.0f;
    for (j = 0; j < count; j++) {
        color = func_0038DBD8(0x408020, 0x30802020, t);
        D_L07_002A21F0[j][1] = color;
        D_L07_002A21F0[j][0] = color;
        D_L07_002A2240[j].x = t;
        D_L07_002A2240[j].y = 0.0f;
        D_L07_002A2240[j].z = t;
        D_L07_002A2240[j].w = 1.0f;
        t += D_L07_001E1650[j] * total;
    }
    func_003D3A24(count * 2, D_L07_002A2100, D_L07_002A21F0, D_L07_002A2240, 1);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L07_003A6498 */

INCLUDE_ASM("asm/levels", func_L07_003A66E8);

INCLUDE_ASM("asm/levels", func_L07_003A6C90);

/* localdecomp:start func_L07_003A6EA8 */
typedef int Q_003A6EA8 __attribute__((mode(TI)));
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
extern void func_L01_004450F0(u8 *, s32, s32);
void func_L07_003A6EA8(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    if (*(s32 *)(p + 0x70) != -1) {
        *(Q_003A6EA8 *)(arg0 + 0x10) = *(Q_003A6EA8 *)(p + 0x90);
        *(Q_003A6EA8 *)(p + 0x90) = *(Q_003A6EA8 *)D_L07_001D66B0;
        *(s32 *)(p + 0x70) = -1;
        func_L01_004450F0(arg0, 0, -1);
    }
}
/* localdecomp:end func_L07_003A6EA8 */

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
