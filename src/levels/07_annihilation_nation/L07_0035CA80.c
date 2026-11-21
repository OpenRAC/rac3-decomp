#include "common.h"

/* localdecomp:start func_L07_0035CA80 */
extern s32 D_001E0F90;

void func_L07_0035CA80(s32 arg0) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if ((&D_001E0F90)[i] == arg0) {
            (&D_001E0F90)[i] = 0;
            return;
        }
    }
}
/* localdecomp:end func_L07_0035CA80 */

/* localdecomp:start func_L07_0035CAB8 */
typedef struct St_0035CAB8 {
    u8 pad0;
    u8 b1;
    u8 pad2[106];
    f32 f6C;
    u8 pad70[128];
} St_0035CAB8;

extern St_0035CAB8 D_L07_002C72C0[];
extern u8 D_001425C0[];
extern s32 D_L07_001DD6A8;
extern void func_L07_0035CA80(s32);
extern void func_L01_004C7D98(u8 *, u8 *);
extern u8 *func_L01_00392908(u8 *, u8 *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                             s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(u8 *);

void func_L07_0035CAB8(u8 *arg0) {
    u8 buf[16];
    u8 x;

    x = D_L07_002C72C0[D_001425C0[87]].b1;
    if (x != 0) {
        func_L01_004C7D98(arg0 + 16, buf);
        func_L01_00392908(arg0 + 16, buf);
    } else {
        func_L01_003303B8(arg0 + 16, 0, 0x14, 0x14, 0x14, 0x14, 0, 2, 0.4f, 0.0f, 5.0f, 2.0f,
                          1, 1, 0, 0, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                          0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    }
    func_L07_0035CA80(arg0);
    D_L07_001DD6A8--;
    func_003C2880(arg0);
}
/* localdecomp:end func_L07_0035CAB8 */

/* localdecomp:start func_L07_0035CC10 */
#include "vu0.h"
/* PROVISIONAL, VU0 j-constraint form: the two hitdelta sequences interleave an addiu with the VU0 ops. */
typedef struct {
    u8 p0[0x38]; f32 height; u8 p3c[0x180-0x3c];
    vu0_v4 chosen, target, spare, best;
    u8 p1c0[4]; f32 distance; u8 p1c8[8]; s32 handle;
} State_0035CC10;
typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 p20[0x48]; State_0035CC10 *state; } Moby_0035CC10;
typedef struct { u8 p0[0x18]; s32 handle; u8 p1c[4]; vu0_v4 pos; } Hit_0035CC10;
extern Hit_0035CC10 D_L07_001E8C00;
typedef struct { u8 p0[0xD0]; vu0_v4 pos; u8 pE0[0x25C0-0xE0]; s32 handle; } Hero_0035CC10;
extern Hero_0035CC10 D_001A4BE0;
extern vu0_v4 D_L07_001E8C20;
void func_L07_0035CC10(Moby_0035CC10 *m, f32 minimum) {
    extern void *func_00382348(s32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038CF38(void *, void *);
    State_0035CC10 *s = m->state;
    vu0_v4 from, to, test, delta, hitdelta;
    u8 *object;
    f32 angle, heading, length, rad, distance, previous;
    *(vu0_q *)&s->chosen = *(vu0_q *)&s->target;
    *(vu0_q *)&from = *(vu0_q *)&m->pos;
    *(vu0_q *)&to = *(vu0_q *)&s->target;
    from.z += s->height;
    to.z += s->height;
    object = func_00382348(s->handle);
    if (s->handle == D_001A4BE0.handle) {
        *(vu0_q *)&to = *(vu0_q *)&D_001A4BE0.pos;
    } else if (object) {
        to.z += *(f32 *)(object + 0x10);
    }
    if (!func_003D3CB0(&from, &to, 0x10, m, 0)) return;
    if (D_L07_001E8C00.handle && D_L07_001E8C00.handle == s->handle) return;
    for (angle = 10.0f; angle <= 100.0f; angle += 10.0f) {
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(delta) : "m"(to), "m"(from) : "vf1", "vf2");
        heading = func_0038D160(delta.x, delta.y);
        length = func_0038CED8(&delta);
        if (length < minimum) length = minimum;
        rad = (angle * 0.017453292f);
        test.x = func_0038D098(func_0038DAB8(rad, heading)) * length;
        test.y = func_0038D0B0(func_0038DAB8(rad, heading)) * length;
        test.z = 0.0f;
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(test) : "m"(from), "m"(test) : "vf1", "vf2");
        if (test.x < 0.0f) test.x = 0.5f;
        if (test.y < 0.0f) test.y = 0.5f;
        if (test.z < 0.0f) test.z = 0.5f;
        if (!func_003D3CB0(&from, &test, 0x10, m, 0)) {
            *(vu0_q *)&s->chosen = *(vu0_q *)&test;
            return;
        }
        if (D_L07_001E8C00.handle && D_L07_001E8C00.handle == s->handle)
            *(vu0_q *)&s->chosen = *(vu0_q *)&test;
        {
            vu0_q hq1, hq2, hqr;
            __asm__("lqc2 %0, %1" : "=j"(hq1) : "m"(m->pos));
            __asm__("lqc2 %0, %1" : "=j"(hq2) : "m"(D_L07_001E8C20));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(hqr) : "j"(hq1), "j"(hq2));
            __asm__("sqc2 %1, %0" : "=m"(hitdelta) : "j"(hqr));
        }
        distance = func_0038CED8(&hitdelta);
        if (s->distance < distance && angle < 60.0f) {
            previous = func_0038CF38(&D_L07_001E8C20, &s->target);
            if (previous < func_0038CF38(&s->best, &s->target)) {
                s->distance = distance;
                *(vu0_q *)&s->best = *(vu0_q *)&D_L07_001E8C20;
            }
        }
        rad = -(angle * 0.017453292f);
        test.x = func_0038D098(func_0038DAB8(rad, heading)) * length;
        test.y = func_0038D0B0(func_0038DAB8(rad, heading)) * length;
        test.z = 0.0f;
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(test) : "m"(from), "m"(test) : "vf1", "vf2");
        if (test.x < 0.0f) test.x = 0.5f;
        if (test.y < 0.0f) test.y = 0.5f;
        if (test.z < 0.0f) test.z = 0.5f;
        if (!func_003D3CB0(&from, &test, 0x10, m, 0)) {
            *(vu0_q *)&s->chosen = *(vu0_q *)&test;
            return;
        }
        if (D_L07_001E8C00.handle && D_L07_001E8C00.handle == s->handle)
            *(vu0_q *)&s->chosen = *(vu0_q *)&test;
        {
            vu0_q hq1, hq2, hqr;
            __asm__("lqc2 %0, %1" : "=j"(hq1) : "m"(m->pos));
            __asm__("lqc2 %0, %1" : "=j"(hq2) : "m"(D_L07_001E8C20));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(hqr) : "j"(hq1), "j"(hq2));
            __asm__("sqc2 %1, %0" : "=m"(hitdelta) : "j"(hqr));
        }
        distance = func_0038CED8(&hitdelta);
        if (s->distance < distance && angle < 60.0f) {
            s->distance = distance;
            *(vu0_q *)&s->best = *(vu0_q *)&D_L07_001E8C20;
        }
    }
}
/* localdecomp:end func_L07_0035CC10 */

/* localdecomp:start func_L07_0035D080 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_L07_001E8C18[4];
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);

void func_L07_0035D080(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 v[4];
    f32 w[4];

    *(u128_t *)v = *(u128_t *)(a0 + 0x10);
    v[2] = v[2] + 0.1f;
    *(u128_t *)w = *(u128_t *)(s + 0x190);
    v[2] = v[2] + *(f32 *)(s + 0x38);
    w[2] = w[2] + *(f32 *)(s + 0x38);
    if (func_003D3CB0(v, w, 0x10, a0, 0) != 0) {
        if (D_L07_001E8C18[0] == 0) {
            return;
        }
        if (D_L07_001E8C18[0] != *(s32 *)(s + 0x1D0)) {
            return;
        }
    }
    *(u128_t *)(s + 0x180) = *(u128_t *)(s + 0x190);
    *(u128_t *)(s + 0x1A0) = *(u128_t *)(s + 0x190);
}
/* localdecomp:end func_L07_0035D080 */
