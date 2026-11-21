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
extern void func_L18_00351908(void *);

/* localdecomp:start func_L18_00352350 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00352350;
typedef struct {
    u32 flag;
    u8 pad[0x1C];
} E_00352350;
typedef struct {
    u8 p0[0x360];
    s32 x360;
    u8 p364[0x2260 - 0x364];
    f32 x2260;
    f32 x2264;
} G_00352350;

extern G_00352350 D_001A4BE0_00352350;
extern u8 *D_001D52FC;
extern u8 D_001439F4[];
extern E_00352350 D_00143A10_00352350[];
extern E_00352350 D_00143A70_00352350[];
extern void func_0038D5B0(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern void func_0038D328(void *, void *);
extern f32 func_0038CED8(void *);
extern f32 func_L01_00448728(void *, f32, void *, f32, f32, f32, s32);

static __inline__ f32 scale_00352350(f32 v, f32 pos, f32 neg) {
    if (v > 0.0f) {
        return v * pos;
    }
    return v * neg;
}

s32 func_L18_00352350(void *arg0) {
    u8 *o = arg0;
    u8 *v;
    u8 *cam;
    u8 *vel;
    G_00352350 *g;
    f32 maxA;
    f32 maxB;
    f32 z;
    f32 side;
    f32 sy;
    f32 sgn;
    f32 s;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 r;
    s32 bits;
    s32 sel;
    s32 ret;
    V_00352350 m0[4];
    V_00352350 v40;
    V_00352350 v50;
    V_00352350 v60;
    V_00352350 m70[4];
    V_00352350 rot;
    V_00352350 newvel;
    vu0_q qa;
    vu0_q qb;

    v = *(u8 **)(o + 0x68);
    cam = D_001D52FC;
    maxA = 30.0f;
    maxB = 25.0f;
    if (*(s32 *)(v + 0x3BC) != 0) {
        func_0038D5B0(m0, o + 0xC0);
        func_0038D028(&v40, v + 0x290, m0);
    } else {
        *(u128_t *)&v40 = *(u128_t *)(v + 0x290);
    }
    vel = v + 0x290;
    *(f32 *)(v + 0x2A8) *= 0.9f;
    z = *(f32 *)(v + 0x298) * 0.95f;
    func_0038CE20(vel, vel, 0.98f);
    *(f32 *)(v + 0x298) = z;

    g = &D_001A4BE0_00352350;
    sel = D_001439F4[0];
    side = g->x2260;
    if (*(s32 *)(v + 0x3BC) != 0) {
        side = -side;
    }
    sgn = -1.0f;
    if (D_00143A10_00352350[sel].flag != 0) {
        sgn = 1.0f;
    }
    s = 1.0f;
    if (D_00143A70_00352350[sel].flag != 0) {
        s = -1.0f;
    }
    g->x360 = 0;
    if (sel == 0) {
        s = 1.0f;
    }
    a = -*(f32 *)(cam + 0x100) * s;
    c = g->x2264;
    bits = *(s32 *)(cam + 0x1A0);
    b = 0.0f;
    if (bits & 4) {
        b = 1.0f;
    }
    if (bits & 1) {
        b -= 1.0f;
    }
    if (bits & 0x40) {
        b += 1.0f;
    }
    if (bits & 0x80) {
        b -= 1.0f;
    }
    if (b > 1.0f) {
        b = 1.0f;
    }
    if (b < -1.0f) {
        b = -1.0f;
    }
    d = (b + 1.0f) * 0.5f * 0.087266475f + 0.05235988f - *(f32 *)(v + 0x390);
    if (d > 0.0034906587f) {
        d = 0.0034906587f;
    } else if (d < -0.0034906587f) {
        d = -0.0034906587f;
    }
    *(f32 *)(v + 0x390) += d;
    sy = side * 0.024f;
    a *= 0.0034906587f;
    c *= 0.014f;
    b = scale_00352350(b, 0.024f, 0.024f);
    r = func_0038DAB8(*(f32 *)(v + 0x2A8), a);
    *(f32 *)(v + 0x2A8) = r;
    if (r > 0.2792527f) {
        *(f32 *)(v + 0x2A8) = 0.2792527f;
    } else if (r < -0.2792527f) {
        *(f32 *)(v + 0x2A8) = -0.2792527f;
    }
    if (*(s32 *)(v + 0x3BC) != 0) {
        *(f32 *)(o + 0xF8) = func_0038DAB8(*(f32 *)(o + 0xF8), *(f32 *)(v + 0x2A8));
    } else {
        func_003C4840(&v60, v + 0x2F0, *(f32 *)(v + 0x2A8));
        maxA = 35.0f;
        maxB = -7.0f;
        func_0038D850(v + 0x2D0, v + 0x2D0, &v60);
        func_0038D850(v + 0x2E0, v + 0x2E0, &v60);
    }
    qzero(&rot);
    v60.x = c;
    v60.z = b;
    v60.y = sy;
    rot.z = *(f32 *)(o + 0xF8);
    func_0038D328(m70, &rot);
    b = 0.48000002f;
    func_0038D028(&v60, &v60, m70);
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(V_00352350 *)(v + 0x290)));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(v60));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
    *(vu0_q *)&newvel = *(vu0_q *)(v + 0x290) = qa;
    c = func_0038CED8(vel);
    if (c > b) {
        b /= c;
        *(f32 *)(v + 0x290) *= b;
        *(f32 *)(v + 0x294) *= b;
    }
    if (*(f32 *)(v + 0x298) > 0.28000003f) {
        *(f32 *)(v + 0x298) = 0.28000003f;
    } else if (*(f32 *)(v + 0x298) < -0.28000003f) {
        *(f32 *)(v + 0x298) = -0.28000003f;
    }
    ret = ((s32 (*)(void *))func_L18_00351908)(o);
    if (*(s32 *)(v + 0x3BC) != 0) {
        a = (*(f32 *)(v + 0x394) - *(f32 *)(v + 0x39C)) * -0.8f;
    } else {
        a = (*(f32 *)(v + 0x39C) - *(f32 *)(v + 0x394)) * -0.8f;
    }
    func_L01_00448728(v + 0x2B0, a, v + 0x2A0, 0.01008f, 0.28800002f, 0.024434611f, 0);
    if (*(f32 *)(v + 0x2B0) > 0.3f) {
        *(f32 *)(v + 0x2B0) = 0.3f;
    }
    if (*(f32 *)(v + 0x2B0) < -0.3f) {
        *(f32 *)(v + 0x2B0) = -0.3f;
    }
    if (*(s32 *)(v + 0x3BC) != 0) {
        *(f32 *)(o + 0xF0) = *(f32 *)(v + 0x2B0);
    } else {
        func_003C4840(m70, o + 0xC0, *(f32 *)(v + 0x2B0));
        func_0038D850(o + 0xD0, o + 0xD0, m70);
        func_0038D850(o + 0xE0, o + 0xE0, m70);
    }
    *(f32 *)(v + 0x350) += *(f32 *)(cam + 0x104) * -0.012f * sgn;
    if (*(f32 *)(v + 0x350) > maxA * 0.017453292f) {
        *(f32 *)(v + 0x350) = maxA * 0.017453292f;
    }
    if (*(f32 *)(v + 0x350) < -maxB * 0.017453292f) {
        *(f32 *)(v + 0x350) = -maxB * 0.017453292f;
    }
    if (*(s32 *)(v + 0x3BC) != 0) {
        *(f32 *)(o + 0xF4) = *(f32 *)(v + 0x350);
    }
    if (*(s32 *)(v + 0x3BC) != 0) {
        func_0038D028(&v50, vel, m0);
    } else {
        *(u128_t *)&v50 = *(u128_t *)(v + 0x290);
    }
    a = (v50.x - v40.x) * 45.0f;
    c = 0.008f;
    if (fabs_asm(a) <= 0.001f) {
        c = 0.00080000004f;
    }
    func_L01_00448728(v + 0x2B4, a, v + 0x2A4, c * 1.44f, 0.28800002f, 0.034906588f, 0);
    if (*(f32 *)(v + 0x2B4) > 0.55f) {
        *(f32 *)(v + 0x2B4) = 0.55f;
    }
    if (*(f32 *)(v + 0x2B4) < -0.5f) {
        *(f32 *)(v + 0x2B4) = -0.5f;
    }
    if (*(s32 *)(v + 0x3BC) != 0) {
        *(f32 *)(o + 0xF4) = func_0038DAB8(*(f32 *)(o + 0xF4), *(f32 *)(v + 0x2B4));
    } else {
        func_003C4840(m70, o + 0xD0, -*(f32 *)(v + 0x350));
        func_0038D850(o + 0xC0, o + 0xC0, m70);
        func_0038D850(o + 0xE0, o + 0xE0, m70);
        func_003C4840(m70, o + 0xD0, *(f32 *)(v + 0x2B4));
        func_0038D850(o + 0xC0, o + 0xC0, m70);
        func_0038D850(o + 0xE0, o + 0xE0, m70);
    }
    return ret;
}
/* localdecomp:end func_L18_00352350 */
