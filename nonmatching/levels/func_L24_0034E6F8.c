/* func_L24_0034E6F8: 52 differences (level 24, file L24_0034DAB8.c). Needs -mvu0-use-vf0-vf2 on that file's line (checked:
   func_L24_0034E250, func_L24_0034E370, func_L24_0034E6B0 and func_L24_0034EBF8 still match with it; not committed).
   Turret camera: locked-target view, free-aim view (VU0 offset and smoothing of +0x190 toward +0x170, aim line drawn by
   func_L19_0045E1A8) and the orbit camera setup. Logic, calls, constants and frame size match. Two store patterns:
   retail's "r = a op b; slot = r; dest = r" (sqc2 r, lq r, sq slot, sq dest: a by-value inline helper around vu0.h's
   vec_add) and "dest = dest op b" with the result stored from its VU0 register to dest and to the same slot (the
   vaddto/vsubto helpers below: d->q = r; return d->v). Still differ: the slot numbering after the first "dest op="
   (retail reuses 0x50/0x60 for the second pair, this C moves to 0x60/0x70), the order of the dest/slot stores, the
   VU0 register roles of the first vsub (retail loads b into vf1 and writes vf2), and the tail's copies to b/c. */
#include "common.h"
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

/* r = a op b into a local, returned by value */
static __inline__ vu0_v4 vadd_ab_34E6F8(void *a, void *b) {
    vu0_v4 r;
    vec_add_ab(&r, a, b);
    return r;
}

static __inline__ vu0_v4 vadd_ba_34E6F8(void *a, void *b) {
    vu0_v4 r;
    vec_add_ba(&r, a, b);
    return r;
}

/* d = a op b, the result stored by the compiler from its VU0 register and returned */
static __inline__ vu0_v4 vaddto_ba_34E6F8(UQ_34E6F8 *d, void *a, void *b) {
    vu0_q qa, qb, r;
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(qa), "j"(qb));
    d->q = r;
    return d->v;
}

static __inline__ vu0_v4 vsubto_ab_34E6F8(UQ_34E6F8 *d, void *a, void *b) {
    vu0_q qa, qb, r;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(qa), "j"(qb));
    d->q = r;
    return d->v;
}

void func_L24_0034E6F8(u8 *obj, s32 force) {
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *t = *(u8 **)(s + 0x1A0);
    UQ_34E6F8 a;
    UQ_34E6F8 b;
    UQ_34E6F8 c;
    vu0_v4 d;
    vu0_v4 e;
    f32 f;
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
        vec_sub_ba(&a, s + 0x170, s + 0x190);
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
        {
            a.v = vadd_ab_34E6F8(obj + 0x10, &e);
        }
        {
            vaddto_ba_34E6F8(&a, &a, &d);
        }
        func_0038CF68(&e, &e, D_L24_001DD444);
        {
            c.v = vadd_ba_34E6F8(s + 0x190, &e);
        }
        {
            vsubto_ab_34E6F8(&c, &c, &a);
        }
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
    cam = *(u8 **)(s + 0x158);
    *(f32 *)cam = D_L24_001DD428;
    *(s32 *)(*(u8 **)(s + 0x158) + 0x34) = D_L24_001DD4A8;
    (*(u8 **)(s + 0x158))[0x1E] = 1;
    (*(u8 **)(s + 0x158))[0x18] = 1;
    *(s16 *)(*(u8 **)(s + 0x158) + 0x1A) = 1;
    *(f32 *)(*(u8 **)(s + 0x158) + 8) = D_L24_001DD440;
    *(f32 *)(*(u8 **)(s + 0x158) + 0xC) = D_L24_001DD42C;
    f = func_0038DAB8(func_0038DAB8(*(f32 *)(obj + 0xF8), *(f32 *)(s + 0x140)),
                      *(f32 *)(s + 0x144) * (D_L24_001DD448 * 1.2f));
    a.v.x = func_0038D098(f) * D_L24_001DD420;
    a.v.y = func_0038D0B0(f) * D_L24_001DD420;
    a.v.z = 0.0f;
    {
        vu0_v4 k;

        vec_copy(&k, &D_L24_001E2180);
        b.v = vaddto_ba_34E6F8(&a, &a, obj + 0x10);
        vec_sub_ab(&c, &a, &k);
        b = c;
        *(UQ_34E6F8 *)(*(u8 **)(s + 0x158) + 0x20) = c;
    }
}
