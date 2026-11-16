/* NTSC-U draft (Codex wave 3): C of func_L01_0046D330, the NTSC-U twin of func_L01_00470A28, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 11 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_0046D330", whose code is not the PAL one).
 * Worker's note: 11 diff; best log w91/func_L01_0046D330.01.log; allowed flags reverified; real VU0 blocks match arithmetic but cannot interleave scalar mtc1 at 088 and inline constants at 188-198; prior j-class helper failed with vf17 spill under permitted flags; best ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0046D330 */
typedef struct Motion_46D330 {
    f32 x, y, z, w;
    s32 col0, col1;
    s16 duration, spark;
} Motion_46D330;
typedef struct Particle_46D330 {
    u8 a, b, c, d;
    s32 color;
    s16 x, life;
    f32 size;
    vu0_v4 pos;
    Motion_46D330 motion;
} Particle_46D330;
extern s32 D_001DFBC0_sda;
extern s32 func_003883C8(s16 *);
extern void func_003C7CE0(void *);
extern s32 func_L01_00444338(s32, s32, f32);
extern void func_L01_004C6EC8(void *, void *);
extern f32 func_0037E250(f32, f32), func_00388770(void *);
extern void func_00388830(void *, void *, f32), func_003886E8(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00462190(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);

void func_L01_0046D330(Particle_46D330 *p) {
    vu0_v4 old;
    vu0_v4 vec;
    Motion_46D330 *vel = &p->motion;
    vu0_v4 *pos;
    f32 length;
    if (func_003883C8(&p->life)) {
        func_003C7CE0(p);
        return;
    }
    pos = &p->pos;
    p->color = func_L01_00444338(vel->col1, vel->col0, (f32)p->life / (f32)vel->duration);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(p->pos) : "m"(p->pos), "m"(*(vu0_v4 *)vel) : "vf1", "vf2");
    vel->z -= vel->w;
    old = p->pos;
    if (p->pos.w != 0.0f) {
        if (p->pos.w == 2.0f) func_L01_004C6EC8(pos, pos);
        p->pos.w = 2.0f;
    }
    if (vel->spark && (D_001DFBC0_sda & 1)) {
        vu0_v4 r = {0.0f, 0.0f, 0.0f, 0.0f};
        r.x = func_0037E250(-1.0f, 1.0f);
        r.y = func_0037E250(-1.0f, 1.0f);
        r.z = func_0037E250(-1.0f, 1.0f);
        vec = r;
        length = func_00388770(vel);
        func_00388830(&vec, &vec, length * func_0037E250(0.15f, 0.25f));
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(vec) : "m"(vec), "m"(*(vu0_v4 *)vel) : "vf1", "vf2");
        func_003886E8(&vec, &vec, func_0037E250(0.75f, 0.95f));
        func_L01_00462190(pos, &vec, p->color, vel->col1, func_0037E208(15, 30), 0,
            p->c, p->d, (s32)p->pos.w, p->size);
    } else {
        func_003886E8(vel, vel, 0.96f);
    }
}
/* localdecomp:end func_L01_0046D330 */
