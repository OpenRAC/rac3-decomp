/* NTSC-U draft (Claude wave K): C of func_L01_0046F008, the NTSC-U twin of func_L01_00472758, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 24 words differ on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L01_0046F008", whose code is not the PAL one).
 * Worker's note: 24 diff words (4 small hunks) with the extras the PAL line lacks (vec_* needs -mvu0-use-vf0-vf2; @ps2as is in the PAL line). Whole function reconstructed. Left: sched order of the four byte->float multiplies and the v.x/v.y/v.z stores in the prologue (retail ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0046F008 */
/* Needs -mvu0-use-vf0-vf2 (vec_* helpers) beyond the PAL file's flags. */
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    s32 w0C;
    u8 b10;
    u8 b11;
    u8 b12;
    u8 b13;
    u8 b14;
    u8 b15;
    u8 b16;
    u8 b17;
    f32 f18;
    f32 f1C;
} P_0046F008;

typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 b8;
    u8 pad9;
    s16 hA;
    f32 fC;
    vu0_v4 pos;
    P_0046F008 p;
} O_0046F008;

extern s32 func_003894A0(s32, s32, f32);
extern f32 func_L01_00442068(f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_004C6EC8(void *, void *);
extern s32 func_003883C8(void *);
extern void func_003C7CE0(void *);

void func_L01_0046F008(O_0046F008 *o) {
    P_0046F008 *p;
    vu0_v4 v;
    vu0_v4 tmp;
    f32 fa;
    f32 fb;
    f32 fc;
    f32 fd;
    f32 t;
    f32 f;

    p = &o->p;
    fa = (f32)p->b15 * 0.0078125f;
    fb = (f32)p->b14 * 0.0078125f;
    fc = (f32)p->b16 * 0.0078125f;
    fd = (f32)p->b17 * 0.0078125f;
    v.x = p->f0;
    v.y = p->f4;
    v.z = p->f8;
    v.w = 0.0f;
    func_L01_004C6EC8(&o->pos, &o->pos);
    t = 1.0f - (f32)o->hA / (f32)p->b11;
    if ((p->b13 & 1) == 0) {
        o->w4 = func_003894A0(0x103080, p->w0C, t) | (p->b12 << 24);
        fc = fa + (fc - fa) * t;
        o->fC = p->f18 + (p->f1C - p->f18) * t;
    } else {
        f = func_L01_00442068(t);
        o->w4 = p->w0C | ((s32)((f32)p->b12 - (f32)p->b12 * f) << 24);
    }
    if ((p->b13 & 2) == 0) {
        fd = fd + fc;
        func_003886E8(&tmp, &v, fc);
        vec_add_ab(&o->pos, &o->pos, &tmp);
        if (fd <= fb) {
            p->b17 = (s32)(fd * 128.0f);
        } else {
            p->b13 = p->b13 | 2;
            func_003886E8(&tmp, &v, fb - fd);
            vec_add_ba(&o->pos, &o->pos, &tmp);
        }
    }
    o->b8 = o->b8 + p->b10;
    if (func_003883C8(&o->hA) != 0) {
        if ((p->b13 & 1) == 0) {
            p->b13 = p->b13 | 1;
            p->b11 = 20;
            o->hA = 20;
        } else {
            func_003C7CE0(o);
        }
    }
}
/* localdecomp:end func_L01_0046F008 */
