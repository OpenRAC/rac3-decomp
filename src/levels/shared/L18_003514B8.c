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

/* localdecomp:start func_L18_003514B8 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
void func_L18_003514B8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 104);
    *(u128_t *)(s + 752) = *(u128_t *)(s + 960);
    func_0038CE90(s + 736, s + 752, s + 720);
    func_0038CF68(s + 736, s + 736, 1.0f);
    func_0038CE90(s + 720, s + 736, s + 752);
    *(s32 *)(s + 732) = 0;
    *(s32 *)(s + 748) = 0;
    *(s32 *)(s + 764) = 0;
}
/* localdecomp:end func_L18_003514B8 */

INCLUDE_ASM("asm/levels", func_L18_00351548);

INCLUDE_ASM("asm/levels", func_L18_00351908);

/* localdecomp:start func_L18_00352288 */
typedef struct G_352288 {
    u8 pad0[0x19E0];
    void *x19E0;
    u8 pad19E4[0xBE0];
    s32 x25C4;
} G_352288;

extern void func_L18_00351908(void *);
extern G_352288 D_001A4BE0;

void func_L18_00352288(void *arg0) {
    u8 *v = *(u8 **)((u8 *)arg0 + 0x68);

    *(f32 *)(v + 0x290) = *(f32 *)(v + 0x290) - *(f32 *)(v + 0x290) * 0.060000002f;
    if (fabs_asm(*(f32 *)(v + 0x290)) < 0.001f) {
        *(f32 *)(v + 0x290) = 0.0f;
    }
    *(f32 *)(v + 0x294) = *(f32 *)(v + 0x294) - *(f32 *)(v + 0x294) * 0.060000002f;
    if (fabs_asm(*(f32 *)(v + 0x294)) < 0.001f) {
        *(f32 *)(v + 0x294) = 0.0f;
    }
    *(f32 *)(v + 0x298) -= 0.00392f;
    if (D_001A4BE0.x25C4 != 0x31 || D_001A4BE0.x19E0 != arg0) {
        *(f32 *)(v + 0x298) -= 0.00392f;
    }
    func_L18_00351908(arg0);
}
/* localdecomp:end func_L18_00352288 */

INCLUDE_ASM("asm/levels", func_L18_00352350);

INCLUDE_ASM("asm/levels", func_L18_00352AF8);

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
extern void func_L18_00352AF8(void *);
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
