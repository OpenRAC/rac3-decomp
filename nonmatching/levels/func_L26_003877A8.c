/* NTSC-U draft (Codex wave 3): C of func_L26_003863A8, the NTSC-U twin of func_L26_003877A8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 378 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L26_003863A8", whose code is not the PAL one).
 * Worker's note: 378 diff; best log func_L26_003863A8.c01.log; full draft reconstructed; flags blocker documented Matching-Patterns.md:139: default assembler pools 1.5707964/1.0471976/0.017453292/0.17453292 literals while retail emits inline lui/ori/mtc1; @ps2as unlisted and ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L26_003863A8 */
typedef int Q_3863A8 __attribute__((mode(TI)));
typedef union { f32 f[4]; Q_3863A8 q; } V_3863A8;
typedef union O_3863A8 O_3863A8;
union O_3863A8 { u8 b[0x2600]; s16 h[0x1300]; s32 i[0x980]; f32 f[0x980]; O_3863A8 *p[0x980]; Q_3863A8 q[0x260]; };
extern O_3863A8 D_001A4BE0;
extern O_3863A8 *D_L26_0021E6E0[];
extern O_3863A8 *D_L26_001EA898[];
extern Q_3863A8 D_L26_001EA8A0[];
extern u8 D_L26_00220046[];
extern s32 D_L26_001D678C[];
extern s32 D_001D6790_sda;
extern f32 D_001DDC44_sda, D_001DDC40_sda;
extern void func_003886E8(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern O_3863A8 *func_0037E0B8(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388800(void *, void *);
extern f32 func_00389468(f32, f32);
extern f32 func_003887C8(void *, void *);
extern f32 func_00388730(void *, void *);
extern f32 func_00388770(void *);
extern f32 func_00388990(f32);
extern void func_0037E4B8(void *, f32, f32, f32);

O_3863A8 *func_L26_003863A8(O_3863A8 *owner, V_3863A8 *pos, f32 *yaw_out, f32 *pitch_out) {
    V_3863A8 origin, offset, start;
    O_3863A8 *disabled[128];
    V_3863A8 point, predicted, ray, scaled;
    O_3863A8 *vars = owner->p[0x68/4];
    O_3863A8 *best = 0;
    O_3863A8 *m, *cls, *block;
    s32 index, disabled_count = 0, valid, steps, j;
    f32 best_dist = D_001DDC44_sda;
    f32 yaw, pitch, yawdiff, distance, a, side, length, angle, radius;
    origin.q = pos->q;
    func_003886E8(&offset, &D_001A4BE0.p[0x25C0/4]->q[0xE0/16], 0.5f);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(start) : "m"(D_001A4BE0.p[0x25C0/4]->q[1]), "m"(offset) : "vf1", "vf2");
    if (func_003CE740(&start, &origin, 6, D_001A4BE0.p[0x25C0/4], 0)) {
        origin.q = D_L26_001EA8A0[0];
        return 0;
    }
    for (index = 0; (m = D_L26_0021E6E0[index]) != 0; index++) {
        if (m->b[0x20] == 0xFE || m->b[0x20] == 0xFD || m->h[0xAA/2] == 0x1BC3 || m->h[0xAA/2] == 0x189B || m->h[0xAA/2] == 0x1D3E || m->h[0xAA/2] == 0x1A90) continue;
        point.q = m->q[1];
        cls = func_0037E0B8(m);
        if (!cls || cls->b[0xE] == 3) continue;
        func_003886E8(&predicted, &m->q[0xE0/16], cls->f[0x10/4]);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(point) : "m"(point), "m"(predicted) : "vf1", "vf2");
        if (!m || !m->p[0x24/4] || D_L26_00220046[0] != 5) continue;
        valid = 0;
        yaw = func_00388A28(point.f[0] - origin.f[0], point.f[1] - origin.f[1]);
        pitch = func_00388A28(func_00388800(&origin, &point), point.f[2] - origin.f[2]);
        yawdiff = func_00389468(*yaw_out, yaw);
        distance = func_003887C8(&origin, &point);
        if (D_L26_001D678C[0] || D_001A4BE0.h[0x368/2] || D_001D6790_sda) {
            if (distance < 2.5f) {
                __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                        : "=m"(ray) : "m"(m->q[1]), "m"(D_001A4BE0.p[0x25C0/4]->q[1]) : "vf1", "vf2");
                a = func_00388730(&ray, &D_001A4BE0.p[0x25C0/4]->q[0xE0/16]);
                if (fabs_asm(a) < 2.0f) {
                    func_003886E8(&scaled, &D_001A4BE0.p[0x25C0/4]->q[0xE0/16], a);
                    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                            : "=m"(ray) : "m"(ray), "m"(scaled) : "vf1", "vf2");
                    side = func_00388730(&ray, &D_001A4BE0.p[0x25C0/4]->q[0xC0/16]);
                    length = func_00388770(&ray);
                    if (length != 0.0f) {
                        angle = func_00388990(side / length);
                        if (1.5707964f - angle < 1.0471976f) valid = 1;
                    }
                }
            }
        } else {
            if (distance < 2.5f && func_00389468(D_001A4BE0.p[0x25C0/4]->f[0xF8/4], func_00388A28(m->f[0x10/4] - D_001A4BE0.f[0x80/4], m->f[0x14/4] - D_001A4BE0.f[0x84/4])) < 1.0471976f && fabs_asm(origin.f[2] - point.f[2]) < 2.0f) valid = 1;
        }
        if (valid && !func_003CE740(&origin, &point, 6, D_001A4BE0.p[0x25C0/4], 0)) {
            best = m;
            *pitch_out = -pitch;
            *yaw_out = yaw;
            break;
        }
        if (distance > best_dist && m != vars->p[0x10/4]) continue;
        if (distance > D_001DDC44_sda) continue;
        func_0037E4B8(&predicted, distance, *yaw_out, *pitch_out + D_001A4BE0.f[0x344/4] * 0.5f);
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                : "=m"(predicted) : "m"(predicted), "m"(origin) : "vf1", "vf2");
        angle = func_00388990(func_003887C8(&predicted, &point) / (distance * 2.0f)) * 2.0f;
        if (angle > D_001DDC40_sda * 0.017453292f) {
            cls = func_0037E0B8(m);
            if (cls) {
                radius = cls->b[0xA] * 0.125f;
                a = func_00388990(radius / distance);
                if (radius < distance) {
                    angle -= a;
                    if (angle < 0.0f) angle = 0.0f;
                }
            }
        }
        if (!(angle < D_001DDC40_sda * 0.017453292f)) continue;
        valid = 1;
        ray.q = origin.q;
        steps = 0;
        while (func_003CE740(&ray, &point, 6, owner, 0)) {
            if (++steps >= 7) break;
            block = D_L26_001EA898[0];
            if (block) {
                if (block->h[0xAA/2] == 0x1BC3 || block->h[0xAA/2] == 0x189B || block->h[0xAA/2] == 0x1D3E) {
                    disabled[disabled_count++] = block;
                    block->i[0x98/4] = 0;
                    if (disabled_count >= 128) break;
                    ray.q = D_L26_001EA8A0[0];
                    continue;
                }
                if (block == m) break;
            }
            valid = 0;
            break;
        }
        if (valid) {
            *pitch_out = -pitch;
            best_dist = distance;
            if (yawdiff < 0.17453292f) *yaw_out = yaw;
            best = m;
            if (m == vars->p[0x10/4]) goto return_now;
        }
    }
    for (j = 0; j < disabled_count; j++) disabled[j]->i[0x98/4] = disabled[j]->p[0x24/4]->i[0x10/4];
return_now:
    return best;
}
/* localdecomp:end func_L26_003863A8 */
