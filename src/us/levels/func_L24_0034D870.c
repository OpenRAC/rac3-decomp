#include "common.h"

/* NTSC-U counterpart of func_L24_0034E6F8 (src/levels/24_insomniac_museum/L24_0034E6F8.c) */
/* localdecomp:start func_L24_0034D870 */
#include "vu0.h"
__asm__(".extern D_L24_001DD460_0034D870, 4");
__asm__(".extern D_L24_001DD464_0034D870, 4");
__asm__(".extern D_L24_001DD468_0034D870, 4");
__asm__(".extern D_L24_001DD46C_0034D870, 4");
__asm__(".extern D_L24_001DD478_0034D870, 4");
__asm__(".extern D_L24_001DD47C_0034D870, 4");
__asm__(".extern D_L24_001DD480_0034D870, 4");
__asm__(".extern D_L24_001DD484_0034D870, 4");
__asm__(".extern D_L24_001DD488_0034D870, 4");
__asm__(".extern D_L24_001DD490, 4");
__asm__(".extern D_L24_001DD494, 4");
__asm__(".extern D_L24_001DD498_0034D870, 4");
__asm__(".extern D_L24_001DD49C_0034D870, 4");
__asm__(".extern D_L24_001DD4A0_0034D870, 4");
__asm__(".extern D_L24_001DD4A4_0034D870, 4");
__asm__(".extern D_L24_001DD4A8_0034D870, 4");
__asm__(".extern D_L24_001DD4AC, 4");
__asm__(".extern D_L24_001DD4B0_0034D870, 4");
__asm__(".extern D_L24_001DD4E8_0034D870, 4");
__asm__(".extern D_001D52FC, 4");
extern f32 D_L24_001DD460_0034D870;
extern f32 D_L24_001DD464_0034D870;
extern f32 D_L24_001DD468_0034D870;
extern f32 D_L24_001DD46C_0034D870;
extern f32 D_L24_001DD478_0034D870;
extern f32 D_L24_001DD47C_0034D870;
extern f32 D_L24_001DD480_0034D870;
extern f32 D_L24_001DD484_0034D870;
extern f32 D_L24_001DD488_0034D870;
extern f32 D_L24_001DD490;
extern f32 D_L24_001DD494;
extern f32 D_L24_001DD498_0034D870;
extern f32 D_L24_001DD49C_0034D870;
extern f32 D_L24_001DD4A0_0034D870;
extern f32 D_L24_001DD4A4_0034D870;
extern f32 D_L24_001DD4A8_0034D870;
extern f32 D_L24_001DD4AC;
extern f32 D_L24_001DD4B0_0034D870;
extern s32 D_L24_001DD4E8_0034D870;
extern u8 *D_001D52FC;
extern u8 D_L24_001E2200_0034D870[];
extern vu0_v4 D_L24_001E2180_0034D870;
extern void func_L01_003F0980(s32, s32);
extern f32 func_00389380(f32, f32);
extern void func_L01_003E9588(s32, void *, void *, s32, s32, s32);
extern void func_L22_003F00E0(s32, f32, f32, f32, f32, f32, f32);
extern void func_L01_003E94A0(s32, void *);
extern void func_L01_003E9510(s32, void *);
extern void func_003886E8(f32 *, void *, f32);
extern void func_L01_0040C188(void *, void *, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L19_0045A428(void *, void *, s32, s32, s32, s32, s32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_003887A0(void *);
extern void func_L01_003E9730(s32, s32);
extern s32 func_L01_003F08D8(s32, s32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);

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

void func_L24_0034D870(u8 *obj, s32 force) {
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
            func_L01_003F0980(0, *(s32 *)(s + 0x158));
            force = 1;
            *(s32 *)(s + 0x158) = 0;
            *(vu0_v4 *)(s + 0x190) = *(vu0_v4 *)(s + 0x170);
        }
        qzero(&a);
        qzero(&b);
        a.v = *(vu0_v4 *)(*(u8 **)(s + 0x1A0) + 0x10);
        a.v.z += D_L24_001DD4B0_0034D870;
        b.v.z = func_00389380(*(f32 *)(obj + 0xF8), *(f32 *)(s + 0x140));
        b.v.y = 1.5707964f;
        if (force != 0) {
            func_L01_003E9588(0, D_L24_001E2200_0034D870, D_L24_001E2200_0034D870 + 0x10, 3, 120, 0);
        }
        func_L22_003F00E0(0, D_L24_001DD490, D_L24_001DD494 * 0.00027777778f, D_L24_001DD498_0034D870 * 0.016666668f,
                          D_L24_001DD49C_0034D870, D_L24_001DD4A0_0034D870 * 0.017453292f * 0.00027777778f,
                          D_L24_001DD4A4_0034D870 * 0.017453292f * 0.016666668f);
        func_L01_003E94A0(0, &a);
        func_L01_003E9510(0, &b);
        return;
    }
    if (s[0x1A4] != 0 && !(*(s32 *)(D_001D52FC + 0x1A4) & 0x81)) {
        if (*(s32 *)(s + 0x158) != 0) {
            func_L01_003F0980(0, *(s32 *)(s + 0x158));
            force = 1;
            *(s32 *)(s + 0x158) = 0;
            *(vu0_v4 *)(s + 0x190) = *(vu0_v4 *)(s + 0x170);
        }
        vec_sub_ab(&a, s + 0x170, s + 0x190);
        func_003886E8((f32 *)&a, &a, D_L24_001DD4AC);
        func_L01_0040C188(&a, &a, D_L24_001DD4A8_0034D870 * 0.016666668f);
        vec_add_ba(s + 0x190, s + 0x190, &a);
        qzero(&b);
        qzero(&a);
        qzero(&d);
        qzero(&e);
        func_0037E4B8(&d, -D_L24_001DD464_0034D870, func_00389380(*(f32 *)(obj + 0xF8), *(f32 *)(s + 0x140)),
                      -*(f32 *)(s + 0x148) * D_L24_001DD478_0034D870);
        if (d.z < -D_L24_001DD47C_0034D870) {
            d.z = -D_L24_001DD47C_0034D870;
        }
        e.z = D_L24_001DD47C_0034D870;
        vec_add_ab(&y, obj + 0x10, &e);
        r.v = a.v = y;
        r.q = vaddto_q_34E6F8(&a, &a, &d);
        func_00388830(&e, &e, D_L24_001DD484_0034D870);
        vec_add_ba(&y, s + 0x190, &e);
        r.v = c.v = y;
        r.q = vsubto_q_34E6F8(&c, &c, &a);
        func_L19_0045A428(&a, obj, 1, 0x80208020, 0x7F, 5, 0xFF, 1.0f);
        b.v.z = func_00388A28(c.v.x, c.v.y);
        b.v.y = -func_00388A28(func_003887A0(&c), c.v.z);
        if (force != 0) {
            func_L01_003E9588(0, D_L24_001E2200_0034D870, D_L24_001E2200_0034D870 + 0x10, 3, 120, 0);
        }
        func_L22_003F00E0(0, D_L24_001DD490, D_L24_001DD494 * 0.00027777778f, D_L24_001DD498_0034D870 * 0.016666668f,
                          D_L24_001DD49C_0034D870, D_L24_001DD4A0_0034D870 * 0.017453292f * 0.00027777778f,
                          D_L24_001DD4A4_0034D870 * 0.017453292f * 0.016666668f);
        func_L01_003E94A0(0, &a);
        func_L01_003E9510(0, &b);
        return;
    }
    if (*(s32 *)(s + 0x158) == 0) {
        func_L01_003E9730(0, 2);
        *(s32 *)(s + 0x158) = func_L01_003F08D8(0, 5);
        if (*(s32 *)(s + 0x158) == 0) {
            return;
        }
    }
    (*(Cam_34E6F8 **)(s + 0x158))->x0 = D_L24_001DD468_0034D870;
    (*(Cam_34E6F8 **)(s + 0x158))->x34 = D_L24_001DD4E8_0034D870;
    (*(Cam_34E6F8 **)(s + 0x158))->x1E = 1;
    (*(Cam_34E6F8 **)(s + 0x158))->x18 = 1;
    (*(Cam_34E6F8 **)(s + 0x158))->x1A = 1;
    (*(Cam_34E6F8 **)(s + 0x158))->x8 = D_L24_001DD480_0034D870;
    (*(Cam_34E6F8 **)(s + 0x158))->xC = D_L24_001DD46C_0034D870;
    f = func_00389380(func_00389380(*(f32 *)(obj + 0xF8), *(f32 *)(s + 0x140)),
                      *(f32 *)(s + 0x144) * (D_L24_001DD488_0034D870));
    a.v.x = func_00388960(f) * D_L24_001DD460_0034D870;
    g = func_00388978(f);
    vec_copy(&k, &D_L24_001E2180_0034D870);
    a.v.y = g * D_L24_001DD460_0034D870;
    a.v.z = 0.0f;
    b.q = vaddto_q_34E6F8(&a, &a, obj + 0x10);
    cam = *(u8 **)(s + 0x158);
    vec_sub_ab(&c, &a, &k);
    *(UQ_34E6F8 *)(cam + 0x20) = b = c;
}
/* localdecomp:end func_L24_0034D870 */
