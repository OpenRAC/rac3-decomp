/* functional: high. Read block by block against the PAL asm (clamping, wrap modulo, both tangent branches, angle outputs); differs only in scheduling of VU0 blocks and remainder ordering. */
#include "common.h"
#include "vu0.h"
void func_L01_00477998(s32 *table, s32 wrap, Vec4 *out, Vec4 *angles, s32 flags, f32 frame) {
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    Vec4 a, b, c, tangent, d, e, extra, tmp;
    s32 clamped = 0;
    s32 index = (s32)frame;
    s32 i;
    s32 j, k;
    f32 t;
    if (!wrap && index >= table[0] - 2) {
        index = table[0] - 2;
        clamped = 1;
    }
    t = frame - (f32)index;
    if (clamped && t > 1.0f) t = 1.0f;
    i = index;
    j = i + 1;
    k = i + 2;
    if (k >= table[0]) {
        i %= table[0];
        j %= table[0];
        k %= table[0];
    }
    a.q = ((Vec4 *)(table + 4))[i].q;
    b.q = ((Vec4 *)(table + 4))[j].q;
    func_0038CDF8(out, &a, &b, t);
    if (flags & 1) return;
    if (clamped) {
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(tangent) : "m"(b), "m"(a) : "vf1", "vf2");
    } else {
        if ((flags & 2) && k < j) {
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(tmp) : "m"(b), "m"(a) : "vf1", "vf2");
            c.q = tmp.q;
            extra.q = c.q;
            __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0\n\tsqc2 $vf1, %1" : "+m"(c), "=m"(extra) : "m"(b) : "vf1", "vf2");
        } else c.q = ((Vec4 *)(table + 4))[k].q;
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(d) : "m"(b), "m"(a) : "vf1", "vf2");
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(e) : "m"(c), "m"(b) : "vf1", "vf2");
        func_0038CDF8(&tangent, &d, &e, t);
    }
    angles->f[1] = -func_0038D160(func_0038CED8(&tangent), tangent.f[2]);
    angles->f[2] = func_0038D160(tangent.f[0], tangent.f[1]);
    angles->f[3] = a.f[3] * (1.0f - t) + b.f[3] * t;
}
