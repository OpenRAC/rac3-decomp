#include "common.h"
#include "vu0.h"

typedef int Quad_3543C8 __attribute__((mode(TI)));
typedef struct Obj_3543C8 {
    u8 pad0[0x10];
    Quad_3543C8 pos;
    u8 pad20[4];
    u8 *def;
    u8 pad28[0xC];
    u16 flags;
    u8 pad36[0x32];
    u8 *vars;
    u8 pad6C[0x2A];
    u16 timer;
    s32 w98;
    u8 pad9C[0xC];
    u8 alpha;
    u8 padA9[0x13];
    u8 state;
    u8 padBD[0x33];
    Quad_3543C8 pos2;
} Obj_3543C8;
typedef struct Vars_3543C8 {
    u8 pad0[0x30];
    f32 hp;
    s16 maxhp;
    s16 hurt;
    u8 pad38[0x48];
    s32 w80;
    u8 pad84[0x2FE];
    u8 b382;
    u8 pad383[0x7D];
    Quad_3543C8 q400;
    Quad_3543C8 q410;
} Vars_3543C8;

/* declared by functions of L18_003514B8.c, which this file was cut from */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L18_00352AF8 */
typedef int u128_00352AF8 __attribute__((mode(TI)));
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) V_00352AF8;

extern f32 func_0038DB00(f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038CEA8(void *);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_L01_0046E078(void *, void *, void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);
__asm__(".extern D_L18_001DD358, 8");
extern V_00352AF8 D_L18_001DD358[][3] __attribute__((section(".sdata")));
__asm__(".extern D_L18_001DD388, 4");
extern f32 D_L18_001DD388;
__asm__(".extern D_L18_001DD38C, 4");
extern f32 D_L18_001DD38C;
__asm__(".extern D_L18_001DD390, 4");
extern f32 D_L18_001DD390;
__asm__(".extern D_L18_001DD394, 4");
extern f32 D_L18_001DD394;
__asm__(".extern D_L18_001DD398, 4");
extern f32 D_L18_001DD398;

void func_L18_00352AF8(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    f32 a;
    f32 b;
    f32 s;
    s32 i;
    s32 k;
    V_00352AF8 vec;
    V_00352AF8 v1;
    V_00352AF8 v2;
    V_00352AF8 v3;
    V_00352AF8 v4;

    a = func_0038DB00(*(f32 *)(a0 + 0xF4), *(f32 *)(st + 0x2C4));
    b = *(f32 *)(st + 0x2C8);
    *(u128_00352AF8 *)&vec = 0;
    s = func_0038CEA8(st + 0x290) / 0.48000002f;
    if (s > 1.0f) {
        s = 1.0f;
    } else if (s < 0.5f) {
        s = 0.5f;
    }
    k = 0;
    for (i = 0; i < 2; i++) {
        func_003C2F58(a0, i == 0 ? 6 : 7, &v1);
        v1.v[3] = 0.0f;
        *(u128_00352AF8 *)&v2 = *(u128_00352AF8 *)&v1;
        *(u128_00352AF8 *)&v3 = *(u128_00352AF8 *)&v1;
        *(u128_00352AF8 *)&v4 = *(u128_00352AF8 *)&v1;
        func_003C4C18(&v2, D_L18_001DD388);
        func_003C4C18(&v3, D_L18_001DD388);
        func_003C4C18(&v4, D_L18_001DD388);
        func_00382760(&vec, -(func_003824E0(D_L18_001DD38C, D_L18_001DD390) * 0.020000001f) * s, b, a);
        func_L01_0046E078(a0, &v2, &vec, &D_L18_001DD358[k][0], 1);
        func_0038CE20(&vec, &vec, func_003824E0(D_L18_001DD394, D_L18_001DD398));
        func_L01_0046E078(a0, &v3, &vec, &D_L18_001DD358[k][1], 1);
        func_0038CE20(&vec, &vec, func_003824E0(D_L18_001DD394, D_L18_001DD398));
        func_L01_0046E078(a0, &v4, &vec, &D_L18_001DD358[k][2], 1);
    }
}
/* localdecomp:end func_L18_00352AF8 */

/* localdecomp:start func_L18_00352D30 */
typedef struct {
    u32 flag;
    u8 pad[0x1C];
} E_00352D30;
typedef struct {
    u8 p0[0x2260];
    f32 x2260;
    f32 x2264;
    u8 p2268[0x25C4 - 0x2268];
    s32 x25C4;
} G_00352D30;
extern G_00352D30 D_001A4BE0_00352D30;
extern u8 *D_001D52FC;
extern u8 D_001439F4[];
extern E_00352D30 D_00143A70[];
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_L18_00352AF8(u8 *);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D750(void *, s32, f32);
extern f32 func_L01_00448728(void *, f32, void *, f32, f32, f32, s32);
extern void func_003C3FC0(void *, void *);

void func_L18_00352D30(u8 *o) {
    u8 *p;
    u8 *cam;
    f32 a;
    f32 b;
    f32 c;
    f32 x;
    f32 ax;
    f32 z;
    f32 s;
    f32 t;
    s32 sel;

    p = *(u8 **)(o + 0x68);
    a = 0.0f;
    b = 0.0f;
    c = 0.0f;
    cam = D_001D52FC;
    if (D_001A4BE0_00352D30.x25C4 != 0x31) {
        func_003C4138((f32 *)(p + 0x390), 0.05235988f, 0.0034906587f);
    } else {
        x = D_001A4BE0_00352D30.x2260;
        ax = fabs_asm(x);
        if (x > 0.0f) {
            b = ax * -0.6f;
        } else if (x < 0.0f) {
            a = ax * -0.6f;
        }
        c = x * 0.3f;
        x = D_001A4BE0_00352D30.x2264;
        ax = fabs_asm(x);
        if (x > 0.0f) {
            z = ax * 0.5f;
            b += z;
            a += z;
        } else if (x < 0.0f) {
            z = ax * -0.6f;
            b += z;
            a += z;
        }
        sel = D_001439F4[0];
        s = 1.0f;
        if (D_00143A70[sel].flag != 0) {
            s = -1.0f;
        }
        if (sel == 0) {
            s = 1.0f;
        }
        x = *(f32 *)(cam + 0x100) * s;
        ax = fabs_asm(x);
        if (x > 0.0f) {
            b += ax * -0.6f;
            a += ax * 0.5f;
        } else if (x < 0.0f) {
            b += ax * 0.5f;
            a += ax * -0.6f;
        }
        if (b > 0.5f) {
            b = 0.5f;
        }
        if (b < -0.6f) {
            b = -0.6f;
        }
        if (a > 0.5f) {
            a = 0.5f;
        }
        if (a < -0.6f) {
            a = -0.6f;
        }
        c += x * 0.3f;
        if (c > 0.3f) {
            c = 0.3f;
        }
        if (c < -0.3f) {
            c = -0.3f;
        }
        if (*(s32 *)(p + 0x3BC) == 0) {
            t = b;
            b = a;
            a = t;
        }
    }
    func_L18_00352AF8(o);
    *(f32 *)(p + 0x388) = func_0038DB00(*(f32 *)(p + 0x388), *(f32 *)(p + 0x390));
    *(f32 *)(p + 0x38C) = func_0038DAB8(*(f32 *)(p + 0x38C), *(f32 *)(p + 0x390));
    func_0038D750(p + 0xA0, 2, *(f32 *)(p + 0x388));
    func_0038D750(p + 0xE0, 2, *(f32 *)(p + 0x38C));
    func_003C4138((f32 *)(p + 0x394), b, 0.034906588f);
    func_003C4138((f32 *)(p + 0x39C), a, 0.034906588f);
    func_0038D750(p + 0x120, 1, *(f32 *)(p + 0x394));
    func_0038D750(p + 0x160, 1, *(f32 *)(p + 0x39C));
    t = func_0038DAB8(*(f32 *)(p + 0x350), *(f32 *)(p + 0x2B4));
    func_L01_00448728(p + 0x2C4, -t, p + 0x3A4, 0.028800001f, 0.21600002f, 0.034906588f, 0);
    func_L01_00448728(p + 0x2C8, *(s32 *)(p + 0x3BC) != 0 ? -c : c, p + 0x3A8, 0.011520001f, 0.28800002f, 0.034906588f, 0);
    func_003C3FC0(p + 0x1A0, p + 0x2C0);
    *(u128_t *)(p + 0x1E0) = *(u128_t *)(p + 0x1A0);
}
/* localdecomp:end func_L18_00352D30 */

/* localdecomp:start func_L18_00353110 */
void func_L18_00353110(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);

    if (*(s32 *)(s + 0x3BC) != 0) {
        *(f32 *)(a0 + 0x18) = *(f32 *)(s + 0x368);
    } else {
        *(u128_t *)(a0 + 0x10) = *(u128_t *)(s + 0x420);
    }
}
/* localdecomp:end func_L18_00353110 */
