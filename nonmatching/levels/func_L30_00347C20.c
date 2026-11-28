/* func_L30_00347C20 (Claude wave 14 r58, 2026-11-28). Replaces the earlier draft of this function (k8-a6 typed draft (2026-11-27)). */
/* PAL near miss (wave 14 r58, 2026-11-28): 13 words differ with the file's flags (-mvu0-use-vf0-vf2 -O2
 * -G8 -fopt-stack -mno-check-zero-division @ps2as), was 43 for the k8-a6 draft.
 * Changed against that draft: (1) the u8 * parameters of the file's declaration with typed locals
 * (the draft's typed parameters conflict with the file's extern); (2) D_L30_001DD048 as a one-element
 * array read as [0]: a scalar global at a fixed address does not conflict with the varying-address
 * struct copy (fixed_scalar_and_varying_struct_p), so its lwc1 was scheduled above the sq; as an
 * array element it stays after it as in retail; (3) the init block inside do { } while (0): the loop
 * notes weight the vars pointer's references inside it (loop depth 2), which gives vars the higher
 * allocation priority, so vars is $s0 and the params $s1 as in retail (a probe that removed three
 * params references gave the same swap, so it is the global allocator's priority).
 * Left (13 words): the argument set-up of the func_L03_0034B440 call. Retail loads age into $v0
 * first, then life into $v1, converts age, loads 1.0, converts life, mov.s $f14, li $a0 1, and
 * $a1 = 0 in the delay slot; this C always issues the load it evaluates second first, into $v1,
 * with li $a0 1 early and mov.s $f14 in the delay slot. Same 13 with the conversions precomputed in
 * any statement order, the literal 1.0f, or one set before or after them; a do { } while (0) around
 * the call gives 30-32.
 */
#include "common.h"

/* localdecomp:start func_L30_00347C20 */
#include "vu0.h"
extern f32 D_L30_001DD048[1]; __asm__(".extern D_L30_001DD048, 4");
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

void func_L30_00347C20(u8 *arg0, u8 *arg1) {
    Particle_00347C20 *a0 = (Particle_00347C20 *)arg0;
    Params_00347C20 *a1 = (Params_00347C20 *)arg1;
    Owner_00347C20 *o;
    u8 *v;
    void *t;
    V_00347C20 d, w;
    f32 s, k, r, one, lo, x, fa, fl;

    if (a1 != 0) {
        o = a1->owner;
        t = a1->system;
        v = o->vars;
        if (o != 0) {
            if (v != 0 && t != 0) {
                if (a1->flags & 1) {
                    do {
                        a0->pos = o->pos;
                        func_L30_0034C958(&a0->pos, D_L30_001DD048[0]);
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
                    } while (0);
                }
                fa = a0->age;
                one = 1.0f;
                fl = a1->life;
                r = func_L03_0034B440(1, 0, 0, fa, fl, one);
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
