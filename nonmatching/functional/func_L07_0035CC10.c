/* functional: high. Differences are scheduling and register allocation only. */
#include "common.h"
/* localdecomp:start func_L07_0035CC10 */
#include "vu0.h"
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
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(hitdelta) : "m"(m->pos), "m"(D_L07_001E8C20) : "vf1", "vf2");
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
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(hitdelta) : "m"(m->pos), "m"(D_L07_001E8C20) : "vf1", "vf2");
        distance = func_0038CED8(&hitdelta);
        if (s->distance < distance && angle < 60.0f) {
            s->distance = distance;
            *(vu0_q *)&s->best = *(vu0_q *)&D_L07_001E8C20;
        }
    }
}
/* localdecomp:end func_L07_0035CC10 */
