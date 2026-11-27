/* PAL near miss (k8-a6, 2026-11-27): 43 words differ with the file's flags (-mvu0-use-vf0-vf2 -O2 -G8
 * -fopt-stack -mno-check-zero-division @ps2as), was 166 for the functional C. The particle callback
 * of the func_L32_003A7F48 family, written with typed particle/params structs.
 * Found: the owner position is a plain 128-bit struct copy (lq/sq, not vec_copy); owner->vars read
 * before the owner null test; the two direction vectors are stack vectors summed with
 * vec_add_ab(&d, &d, &w), their y = 0 stores after the z components; the tail order
 * speedY += speedZ, pos.x, pos.z, then the alpha (the in->speedY reload after the out stores).
 * Left: $s0/$s1 swapped (retail gives vars $s0 and the params $s1, about 30 words), the sq of the
 * position copy after the delay-slot lwc1 of the first call's argument, and the argument set-up
 * order of the func_L03_0034B440 call (retail converts age, loads 1.0, converts life, then a0/a1);
 * the f32-first prototype (as func_L32_003A7F48's) gives the same bytes.
 */
#include "common.h"

/* localdecomp:start func_L30_00347C20 */
#include "vu0.h"
extern f32 D_L30_001DD048; __asm__(".extern D_L30_001DD048, 4");
extern f32 D_L30_001DD078; __asm__(".extern D_L30_001DD078, 4");
extern f32 D_L30_001DD074; __asm__(".extern D_L30_001DD074, 4");
extern f32 D_L30_001DD054; __asm__(".extern D_L30_001DD054, 4");
extern f32 D_L30_001DD058; __asm__(".extern D_L30_001DD058, 4");
extern f32 D_L30_001DD044; __asm__(".extern D_L30_001DD044, 4");
extern f32 D_L30_001DD040; __asm__(".extern D_L30_001DD040, 4");
extern f32 D_L30_001DD064; __asm__(".extern D_L30_001DD064, 4");
extern f32 D_L30_001DD060; __asm__(".extern D_L30_001DD060, 4");
extern f32 D_L30_001DD03C; __asm__(".extern D_L30_001DD03C, 4");
extern f32 D_L30_001DD05C; __asm__(".extern D_L30_001DD05C, 4");
extern f32 D_L30_001DD068; __asm__(".extern D_L30_001DD068, 4");
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00347C20;
typedef struct { u8 pad00[0x10]; V_00347C20 pos; u8 pad20[0x48]; u8 *vars; } Owner_00347C20;
typedef struct {
    Owner_00347C20 *owner;
    void *system;
    s16 life;
    u16 flags;
    s16 threshold;
    u16 color;
    f32 speedX, speedY, speedZ, scale;
} Params_00347C20;
typedef struct {
    u8 pad00[3];
    u8 kind;
    u32 color;
    u8 alpha;
    u8 pad09;
    s16 age;
    f32 size;
    V_00347C20 pos;
} Particle_00347C20;

void func_L30_00347C20(Particle_00347C20 *a0, Params_00347C20 *a1) {
    Owner_00347C20 *o;
    u8 *v;
    void *t;
    V_00347C20 d, w;
    f32 s, k, r, one, lo, x;

    if (a1 != 0) {
        o = a1->owner;
        v = o->vars;
        t = a1->system;
        if (o != 0) {
            if (v != 0 && t != 0) {
                if (a1->flags & 1) {
                    a0->pos = o->pos;
                    func_L30_0034C958(&a0->pos, D_L30_001DD048);
                    s = func_003824E0(D_L30_001DD078, D_L30_001DD074) * *(f32 *)(v + 0x50);
                    d.x = func_0038D098(func_0038DB48(*(f32 *)(v + 0x48) + (*(s32 *)(v + 0x4C) ? 1.5707964f : -1.5707964f))) * s;
                    d.z = func_0038D0B0(func_0038DB48(*(f32 *)(v + 0x48) + (*(s32 *)(v + 0x4C) ? 1.5707964f : -1.5707964f))) * s;
                    d.y = 0;
                    k = func_003824E0(D_L30_001DD058, D_L30_001DD054);
                    w.x = func_0038D098(*(f32 *)(v + 0x48)) * k;
                    w.z = func_0038D0B0(*(f32 *)(v + 0x48)) * k;
                    w.y = 0;
                    vec_add_ab(&d, &d, &w);
                    a1->speedX = d.x;
                    a1->speedY = d.z;
                    a1->speedZ = func_003824E0(D_L30_001DD044, D_L30_001DD040);
                    a0->kind = 0x49;
                    a0->color = 0x80000000;
                    a1->scale = func_003824E0(D_L30_001DD064, D_L30_001DD060);
                }
                one = 1.0f;
                r = func_L03_0034B440(1, 0, 0, (f32)a0->age, (f32)a1->life, one);
                a1->speedY = a1->speedY + a1->speedZ;
                a0->pos.x = a0->pos.x + a1->speedX;
                a0->pos.z = a0->pos.z + a1->speedY;
                a0->color = (s32)(D_L30_001DD03C * (one - r)) << 24;
                {
                    u16 c = a1->color;
                    lo = (f32)(c & 0xFF);
                    x = lo + (lo + D_L30_001DD05C * (f32)a1->life * (f32)(c >> 8) * 0.00390625f);
                }
                a0->alpha = func_003C4088(lo, x, func_L03_0034B148(a0->age, a1->life, 0.0f));
                a0->size = a1->scale * func_003C4088(one, D_L30_001DD068, r);
            }
        }
    }
}
/* localdecomp:end func_L30_00347C20 */
