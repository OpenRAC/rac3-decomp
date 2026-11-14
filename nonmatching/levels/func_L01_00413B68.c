/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_00411538, the NTSC-U twin of func_L01_00413B68, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L01_00412E30.c's current line.
 * Worker's note: 218 diff improved from 234; 2 checks; documented inline-literal assembler mismatch under permitted GNU-as flags (.01, smoothing constants, .51 use .lit4; retail inline lui/ori/mtc1); no flags_alt or unlisted flags tried; VU0 scheduling and pointer allocation remain; best log func_L01_00411538.check-
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00411538 */
typedef int Q_00411538 __attribute__((mode(TI)));
typedef union { Q_00411538 q; f32 f[4]; } V_00411538;
typedef struct {
    u8 pad0[0x30]; V_00411538 eye; u8 pad40[0x7C]; void *owner;
    V_00411538 forward, rotation; u16 flags; u8 padE2[0x42]; f32 distance, velocity;
} Camera_00411538;
typedef struct { u8 pad0[0xAA]; s16 oclass; } Moby_00411538;
typedef struct { u8 pad0[0x18]; Moby_00411538 *object; u8 pad1C[4]; V_00411538 normal, point; } Hit_00411538;
extern Hit_00411538 D_L01_001EAA80;
__asm__(".extern D_L01_001EAA80, 16");
extern V_00411538 D_L01_001EAAB0[];
extern f32 D_001D6530_sda, D_001D6534_sda;
extern f32 func_00388730(void *, void *);
extern f32 func_00388770(void *);
extern f32 func_L01_00443D00(void *, void *, s32, void *, f32);
extern void func_003BEC60(f32 *, f32, f32 *, f32, f32, f32);
extern void func_003888C8(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_003CF790(void *, s32, void *, s32, f32);
extern f32 func_003887C8(void *, void *);
extern void func_00388BD0(void *, void *);
extern void func_00388EB8(void *, void *, void *);

static __inline__ void sub_00411538(V_00411538 *d, V_00411538 *a, V_00411538 *b) {
    __asm__("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvsub.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void add_00411538(V_00411538 *d, V_00411538 *a, V_00411538 *b) {
    __asm__("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvadd.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}

void func_L01_00411538(Camera_00411538 *camera, V_00411538 *a, V_00411538 *b) {
    V_00411538 target, source, delta, original, offset, direction, hit;
    V_00411538 matrix[3], reference;
    f32 dot, length, fraction;
    V_00411538 *src = &source;
    V_00411538 *dst = &target;
    V_00411538 *ray;
    *dst = *a;
    *src = *b;
    original = target;
    sub_00411538(&delta, &target, &source);
    dot = func_00388730(&delta, &delta);
    length = func_00388770(&camera->forward);
    if (fabs_asm(dot) > 0.01f) {
        fraction = func_L01_00443D00(src, dst, 0x84, camera->owner, D_001D6530_sda);
        if (fraction < 1.0f) {
            if (D_L01_001EAA80.object == 0 || fraction > 0.0f) target = D_L01_001EAA80.point;
        }
    }
    if (length == 0.0f) {
        camera->eye = target;
        return;
    }
    if (camera->flags & 4) {
        camera->flags &= ~4;
        func_003BEC60(&camera->distance, 0.0f, &camera->velocity, 0.0222222228f, 0.0444444455f, 1.33333337f);
    } else {
        func_003888C8(&direction, &camera->forward, camera);
        ray = &direction;
        func_00388830(&direction, &direction, length + 0.5f);
        add_00411538(&direction, &direction, &original);
        if (func_003CE740(dst, &direction, 4, camera->owner, 0)) {
            hit = D_L01_001EAA80.normal;
            if (D_L01_001EAA80.object && D_L01_001EAA80.object->oclass != 0xD54 && func_003CF790(&camera->eye, 0, camera->owner, 0, 0.51f)) {
                length = func_003887C8(&original, &hit) - 0.5f;
            } else {
                if (func_003CE740(dst, ray, 2, camera->owner, 0)) {
                    length = func_003887C8(&original, &D_L01_001EAA80.normal) - 0.5f;
                }
            }
            if (length < 0.0f) {
                camera->eye = target;
                return;
            }
        }
        if (length < camera->distance) {
            camera->distance = length;
            camera->velocity = 0.0f;
        } else if (length > camera->distance) {
            if (camera->velocity < 0.0f) camera->velocity = 0.0f;
            func_003BEC60(&camera->distance, length, &camera->velocity, 0.00555555569f, 0.00555555569f, 0.333333343f);
        }
    }
    func_003888C8(&camera->eye, &camera->forward, camera);
    func_00388830(&offset, &camera->eye, camera->distance - 1.0f);
    func_00388830(&camera->eye, &camera->eye, camera->distance);
    __asm__("lqc2 vf2, %3\n\tlqc2 vf1, %0\n\tvadd.xyz vf1, vf1, vf2\n\tlqc2 vf2, %4\n\tsqc2 vf2, %1\n\tsqc2 vf1, %0\n\tlqc2 vf2, %2\n\tlqc2 vf1, %1\n\tvadd.xyz vf2, vf2, vf1\n\tsqc2 vf2, %2"
        : "+m"(camera->eye), "=m"(reference), "+m"(offset) : "m"(original), "m"(target) : "vf1", "vf2");
    fraction = func_L01_00443D00(&offset, &camera->eye, 0x104, camera->owner, D_001D6534_sda);
    if (fraction < 1.0f) camera->eye = D_L01_001EAAB0[0];
    func_00388BD0(matrix, &camera->rotation);
    func_00388EB8(camera, camera, matrix);
}
/* localdecomp:end func_L01_00411538 */
