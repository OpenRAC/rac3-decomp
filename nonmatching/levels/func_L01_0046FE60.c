/* NTSC-U draft (Claude wave K): C of func_L01_0046C788, the NTSC-U twin of func_L01_0046FE60, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 12 words differ on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L01_0046C788", whose code is not the PAL one).
 * Worker's note: 12 diff words (2 small hunks) with the extras the PAL line lacks (vec_add_ab needs -mvu0-use-vf0-vf2; @ps2as is in the PAL line): only the placement of the k[0] s16 loads around the addu/subu of the key-array address differs (retail hoists lh v0,(a0) before ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0046C788 */
/* Needs -mvu0-use-vf0-vf2 (vec_* helpers) beyond the PAL file's flags. */
typedef struct {
    u32 *p0;
    s16 *p4;
    s16 *p8;
    s16 hC;
    u8 padE[2];
    u16 h10;
    u8 pad12[2];
    f32 f14;
} Path_0046C788;

typedef struct {
    vu0_v4 vel;
    Path_0046C788 *path;
    s16 h14;
    u8 pad16[2];
    u8 b18;
} P_0046C788;

typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 b8;
    u8 pad9;
    u16 hA;
    f32 fC;
    vu0_v4 pos;
    P_0046C788 st;
} O_0046C788;

extern void func_003886E8(void *, void *, f32);
extern s32 func_L01_00444338(s32, s32, f32);
extern s32 func_003883C8(void *);
extern void func_003C7CE0(void *);

void func_L01_0046C788(O_0046C788 *o) {
    P_0046C788 *p;
    Path_0046C788 *path;
    s16 *k;
    s32 t;
    f32 f;

    p = &o->st;
    path = p->path;
    func_003886E8(p, p, path->f14);
    vec_add_ab(&o->pos, &o->pos, &o->st);
    o->b8 = o->b8 + p->b18;
    t = (s16)(path->h10 - o->hA);
    if (path->p8[p->h14 + 1] < t && p->h14 < path->hC) {
        p->h14 = (u16)p->h14 + 1;
    }
    k = path->p8 + p->h14;
    f = (f32)(t - k[0]) / (f32)(k[1] - k[0]);
    o->w4 = func_L01_00444338(path->p0[p->h14], path->p0[p->h14 + 1], f);
    k = path->p4 + p->h14;
    o->fC = ((f32)k[0] + f * (f32)(k[1] - k[0])) * 1000.0f;
    if (func_003883C8(&o->hA) != 0) {
        func_003C7CE0(o);
    }
}
/* localdecomp:end func_L01_0046C788 */
