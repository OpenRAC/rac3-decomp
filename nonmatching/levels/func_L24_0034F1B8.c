/* func_L24_0034F1B8: 195 differences (level 24, file L24_0034F040.c, -mvu0-use-vf0-vf2 @ps2as), a first draft. The
   steering/physics step (damping of +0x118/+0x144/+0x100, the hero-relative push when the target at +0x1A0 is gone,
   turn rates through func_0038DAB8/func_0038DB00, func_L01_00448890 and func_L01_004455E8, the push added through two
   VU0 adds, then func_L24_0034ED28 and func_L24_0034E6F8) has retail's calls and blocks; the float constant scheduling
   and saved FP registers differ throughout (retail keeps the four push terms in $f20..$f23 initialised from one zero,
   the yaw in $f24). One compile. */
#include "common.h"
#include "vu0.h"
extern void func_0038CE20(f32 *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern void func_L01_004455E8(void *, void *, f32, f32, f32, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_0040E728(void *, void *, f32);
extern s32 func_L24_0034ED28(u8 *);
extern void func_L24_0034E6F8(u8 *, s32);
extern u8 *D_001D52FC;
extern vu0_q D_L24_001E21A0;
__asm__(".extern D_L24_001DD3F0, 4");
__asm__(".extern D_L24_001DD3F4, 4");
__asm__(".extern D_L24_001DD3F8, 4");
__asm__(".extern D_L24_001DD3FC, 4");
__asm__(".extern D_L24_001DD400, 4");
__asm__(".extern D_L24_001DD404, 4");
__asm__(".extern D_L24_001DD408, 4");
__asm__(".extern D_L24_001DD40C, 4");
__asm__(".extern D_L24_001DD410, 4");
__asm__(".extern D_L24_001DD414, 4");
__asm__(".extern D_L24_001DD418, 4");
__asm__(".extern D_L24_001DD41C, 4");
__asm__(".extern D_L24_001DD4BC, 4");
__asm__(".extern D_L24_001DD4C0, 4");
extern f32 D_L24_001DD3F0;
extern f32 D_L24_001DD3F4;
extern f32 D_L24_001DD3F8;
extern f32 D_L24_001DD3FC;
extern f32 D_L24_001DD400;
extern f32 D_L24_001DD404;
extern f32 D_L24_001DD408;
extern f32 D_L24_001DD40C;
extern f32 D_L24_001DD410;
extern f32 D_L24_001DD414;
extern f32 D_L24_001DD418;
extern f32 D_L24_001DD41C;
extern f32 D_L24_001DD4BC;
extern f32 D_L24_001DD4C0;

static __inline__ void vadd2_34F1B8(void *d1, void *d2, void *a, void *b) {
    vu0_q qa, qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d1) : "j"(qr));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d2) : "j"(qr));
}

s32 func_L24_0034F1B8(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 v[4];
    f32 t[4];
    f32 z;
    f32 yaw;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 r12;
    u8 *m;
    u8 *h;
    s32 r;

    *(f32 *)(s + 0x118) = *(f32 *)(s + 0x118) * D_L24_001DD410;
    *(f32 *)(s + 0x144) = *(f32 *)(s + 0x144) * D_L24_001DD414;
    z = *(f32 *)(s + 0x108) * D_L24_001DD41C;
    func_0038CE20((f32 *)(s + 0x100), s + 0x100, D_L24_001DD418);
    *(f32 *)(s + 0x108) = z;
    a = 0.0f;
    b = 0.0f;
    c = 0.0f;
    d = 0.0f;
    m = *(u8 **)(s + 0x1A0);
    if (m == 0 || m[0x20] == 0xFE || m[0x20] == 0xFD) {
        *(u8 **)(s + 0x1A0) = 0;
        h = D_001D52FC;
        d = -*(f32 *)(h + 0x10C) * (D_L24_001DD3F8 * 0.00040000002f);
        c = -*(f32 *)(h + 0x108) * (D_L24_001DD3F4 * 0.00040000002f);
        b = -(*(f32 *)(h + 0x104) - 0.25f);
        a = *(f32 *)(h + 0x100) * (D_L24_001DD408 * 0.017453292f * 0.00040000002f);
    }
    yaw = func_0038D160(*(f32 *)(s + 0x100), *(f32 *)(s + 0x104));
    *(f32 *)(s + 0x144) = func_0038DAB8(*(f32 *)(s + 0x144), a);
    r12 = 0.0f;
    if (b < 0.0f) {
        r12 = D_L24_001DD4BC * 0.017453292f * b;
    } else if (0.0f < b) {
        r12 = D_L24_001DD4C0 * 0.017453292f * b;
    }
    func_L01_00448890(s + 0x148, s + 0x14C, 0, r12, D_L24_001DD3FC * 0.017453292f * 0.00040000002f, D_L24_001DD3FC * 0.017453292f * 0.00040000002f, D_L24_001DD404 * 0.017453292f * 0.020000001f);
    {
        f32 lim = D_L24_001DD40C * 0.017453292f * 0.020000001f;
        if (lim < *(f32 *)(s + 0x144)) {
            *(f32 *)(s + 0x144) = lim;
        } else if (*(f32 *)(s + 0x144) < -lim) {
            *(f32 *)(s + 0x144) = -lim;
        }
    }
    func_L01_004455E8(obj, s + 0x118, yaw, D_L24_001DD3FC * 0.017453292f * 0.00040000002f, D_L24_001DD400 * 1.44f, D_L24_001DD404 * 0.017453292f * 0.020000001f);
    *(f32 *)(s + 0x140) = func_0038DAB8(*(f32 *)(s + 0x140), *(f32 *)(s + 0x144));
    *(f32 *)(s + 0x140) = func_0038DB00(*(f32 *)(s + 0x140), *(f32 *)(s + 0x118));
    v[0] = d;
    v[1] = c;
    v[2] = 0.0f;
    func_0038D000(v, v, &D_L24_001E21A0);
    v[2] = 0.0f;
    vadd2_34F1B8(s + 0x100, t, s + 0x100, v);
    func_L01_0040E728(s + 0x100, s + 0x100, D_L24_001DD3F0 * 0.020000001f);
    vadd2_34F1B8(t, obj + 0x10, obj + 0x10, s + 0x100);
    r = func_L24_0034ED28(obj);
    func_L24_0034E6F8(obj, 0);
    return r;
}
