#include "common.h"

/* localdecomp:start func_L24_0034E6F8 */
#include "vu0.h"
__asm__(".extern D_L24_001DD420, 4");
__asm__(".extern D_L24_001DD424, 4");
__asm__(".extern D_L24_001DD428, 4");
__asm__(".extern D_L24_001DD42C, 4");
__asm__(".extern D_L24_001DD438, 4");
__asm__(".extern D_L24_001DD43C, 4");
__asm__(".extern D_L24_001DD440, 4");
__asm__(".extern D_L24_001DD444, 4");
__asm__(".extern D_L24_001DD448, 4");
__asm__(".extern D_L24_001DD450, 4");
__asm__(".extern D_L24_001DD454, 4");
__asm__(".extern D_L24_001DD458, 4");
__asm__(".extern D_L24_001DD45C, 4");
__asm__(".extern D_L24_001DD460, 4");
__asm__(".extern D_L24_001DD464, 4");
__asm__(".extern D_L24_001DD468, 4");
__asm__(".extern D_L24_001DD46C, 4");
__asm__(".extern D_L24_001DD470, 4");
__asm__(".extern D_L24_001DD4A8, 4");
__asm__(".extern D_001D52FC, 4");
extern f32 D_L24_001DD420;
extern f32 D_L24_001DD424;
extern f32 D_L24_001DD428;
extern f32 D_L24_001DD42C;
extern f32 D_L24_001DD438;
extern f32 D_L24_001DD43C;
extern f32 D_L24_001DD440;
extern f32 D_L24_001DD444;
extern f32 D_L24_001DD448;
extern f32 D_L24_001DD450;
extern f32 D_L24_001DD454;
extern f32 D_L24_001DD458;
extern f32 D_L24_001DD45C;
extern f32 D_L24_001DD460;
extern f32 D_L24_001DD464;
extern f32 D_L24_001DD468;
extern f32 D_L24_001DD46C;
extern f32 D_L24_001DD470;
extern s32 D_L24_001DD4A8;
extern u8 *D_001D52FC;
extern u8 D_L24_001E2200[];
extern vu0_v4 D_L24_001E2180;
extern void func_L01_003F2AF8(s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L22_003F21E8(s32, f32, f32, f32, f32, f32, f32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_L01_0040E6B8(void *, void *, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L19_0045E1A8(void *, void *, s32, s32, s32, s32, s32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_L01_003EB5E0(s32, s32);
extern s32 func_L01_003F2A50(s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

typedef union { vu0_q q; vu0_v4 v; } UQ_34E6F8;
typedef struct { f32 x0; u8 p4[4]; f32 x8; f32 xC; u8 p10[8]; u8 x18; u8 p19; s16 x1A; u8 p1C[2]; u8 x1E; u8 p1F; vu0_q x20; u8 p30[4]; s32 x34; } Cam_34E6F8;

/* d = a + b (b loaded first) and the value: the result is stored to d from its VU0 register and returned */
static __inline__ vu0_q vaddto_q_34E6F8(void *d, void *a, void *b) {
    vu0_q qa, qb, r;
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(r));
    return r;
}

/* d = a - b (a loaded first) and the value */
static __inline__ vu0_q vsubto_q_34E6F8(void *d, void *a, void *b) {
    vu0_q qa, qb, r;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(r));
    return r;
}

void func_L24_0034E6F8(u8 *obj, s32 force) {
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *t = *(u8 **)(s + 0x1A0);
    UQ_34E6F8 a;
    UQ_34E6F8 b;
    UQ_34E6F8 c;
    vu0_v4 d;
    vu0_v4 e;
    UQ_34E6F8 r;
    vu0_v4 y;
    vu0_v4 k;
    f32 f;
    f32 g;
    u8 *cam;

    if (t != 0 && t[0x20] != 0xFE && t[0x20] != 0xFD) {
        if (*(s32 *)(s + 0x158) != 0) {
            func_L01_003F2AF8(0, *(s32 *)(s + 0x158));
            force = 1;
            *(s32 *)(s + 0x158) = 0;
            *(vu0_v4 *)(s + 0x190) = *(vu0_v4 *)(s + 0x170);
        }
        qzero(&a);
        qzero(&b);
        a.v = *(vu0_v4 *)(*(u8 **)(s + 0x1A0) + 0x10);
        a.v.z += D_L24_001DD470;
        b.v.z = func_0038DAB8(*(f32 *)(obj + 0xF8), *(f32 *)(s + 0x140));
        b.v.y = 1.5707964f;
        if (force != 0) {
            func_L01_003EB438(0, D_L24_001E2200, D_L24_001E2200 + 0x10, 3, 100, 0);
        }
        func_L22_003F21E8(0, D_L24_001DD450 * 1.2f, D_L24_001DD454 * 0.00040000002f, D_L24_001DD458 * 0.020000001f,
                          D_L24_001DD45C * 1.2f, D_L24_001DD460 * 0.017453292f * 0.00040000002f,
                          D_L24_001DD464 * 0.017453292f * 0.020000001f);
        func_L01_003EB350(0, &a);
        func_L01_003EB3C0(0, &b);
        return;
    }
    if (s[0x1A4] != 0 && !(*(s32 *)(D_001D52FC + 0x1A4) & 0x81)) {
        if (*(s32 *)(s + 0x158) != 0) {
            func_L01_003F2AF8(0, *(s32 *)(s + 0x158));
            force = 1;
            *(s32 *)(s + 0x158) = 0;
            *(vu0_v4 *)(s + 0x190) = *(vu0_v4 *)(s + 0x170);
        }
        vec_sub_ab(&a, s + 0x170, s + 0x190);
        func_0038CE20((f32 *)&a, &a, D_L24_001DD46C * 1.2f);
        func_L01_0040E6B8(&a, &a, D_L24_001DD468 * 0.020000001f);
        vec_add_ba(s + 0x190, s + 0x190, &a);
        qzero(&b);
        qzero(&a);
        qzero(&d);
        qzero(&e);
        func_00382760(&d, -D_L24_001DD424, func_0038DAB8(*(f32 *)(obj + 0xF8), *(f32 *)(s + 0x140)),
                      -*(f32 *)(s + 0x148) * D_L24_001DD438);
        if (d.z < -D_L24_001DD43C) {
            d.z = -D_L24_001DD43C;
        }
        e.z = D_L24_001DD43C;
        vec_add_ab(&y, obj + 0x10, &e);
        r.v = a.v = y;
        r.q = vaddto_q_34E6F8(&a, &a, &d);
        func_0038CF68(&e, &e, D_L24_001DD444);
        vec_add_ba(&y, s + 0x190, &e);
        r.v = c.v = y;
        r.q = vsubto_q_34E6F8(&c, &c, &a);
        func_L19_0045E1A8(&a, obj, 1, 0x80208020, 0x7F, 5, 0xFF, 1.0f);
        b.v.z = func_0038D160(c.v.x, c.v.y);
        b.v.y = -func_0038D160(func_0038CED8(&c), c.v.z);
        if (force != 0) {
            func_L01_003EB438(0, D_L24_001E2200, D_L24_001E2200 + 0x10, 3, 100, 0);
        }
        func_L22_003F21E8(0, D_L24_001DD450 * 1.2f, D_L24_001DD454 * 0.00040000002f, D_L24_001DD458 * 0.020000001f,
                          D_L24_001DD45C * 1.2f, D_L24_001DD460 * 0.017453292f * 0.00040000002f,
                          D_L24_001DD464 * 0.017453292f * 0.020000001f);
        func_L01_003EB350(0, &a);
        func_L01_003EB3C0(0, &b);
        return;
    }
    if (*(s32 *)(s + 0x158) == 0) {
        func_L01_003EB5E0(0, 2);
        *(s32 *)(s + 0x158) = func_L01_003F2A50(0, 5);
        if (*(s32 *)(s + 0x158) == 0) {
            return;
        }
    }
    (*(Cam_34E6F8 **)(s + 0x158))->x0 = D_L24_001DD428;
    (*(Cam_34E6F8 **)(s + 0x158))->x34 = D_L24_001DD4A8;
    (*(Cam_34E6F8 **)(s + 0x158))->x1E = 1;
    (*(Cam_34E6F8 **)(s + 0x158))->x18 = 1;
    (*(Cam_34E6F8 **)(s + 0x158))->x1A = 1;
    (*(Cam_34E6F8 **)(s + 0x158))->x8 = D_L24_001DD440;
    (*(Cam_34E6F8 **)(s + 0x158))->xC = D_L24_001DD42C;
    f = func_0038DAB8(func_0038DAB8(*(f32 *)(obj + 0xF8), *(f32 *)(s + 0x140)),
                      *(f32 *)(s + 0x144) * (D_L24_001DD448 * 1.2f));
    a.v.x = func_0038D098(f) * D_L24_001DD420;
    g = func_0038D0B0(f);
    vec_copy(&k, &D_L24_001E2180);
    a.v.y = g * D_L24_001DD420;
    a.v.z = 0.0f;
    b.q = vaddto_q_34E6F8(&a, &a, obj + 0x10);
    cam = *(u8 **)(s + 0x158);
    vec_sub_ab(&c, &a, &k);
    *(UQ_34E6F8 *)(cam + 0x20) = b = c;
}
/* localdecomp:end func_L24_0034E6F8 */
