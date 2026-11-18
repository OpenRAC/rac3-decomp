/* PAL port of the NTSC-U draft (round 8): PAL port of the NTSC-U draft (round 8): 12 differences with the file's line (the line already has -mvu0-use-vf0-vf2 and @ps2as), two small hunks, callees func_0038CE20, func_L01_00447470, func_0038CB00, func_003CD250 and the first argument (f14 - 1.0f) * 1.2f + 1.0f all match. Left: retail loads k[0] before k[1] in both key-array reads (lh $v0,0($a0); lh $a2,2($a0); the second array likewise) and uses $a0 for the first array address and $v0 for the loaded p8 pointer, gcc loads k[1] first and swaps those two registers; k0/k1 locals (s32, s16), numerator/denominator locals in both orders, &p8[i] indexing, swapped comparison and an h14 temp did not change the 12 (reading both locals in the second block: 23, difference first: 28) */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0046FE60 */
typedef struct {
    u32 *p0;
    s16 *p4;
    s16 *p8;
    s16 hC;
    u8 padE[2];
    u16 h10;
    u8 pad12[2];
    f32 f14;
} Path_46FE60;

typedef struct {
    vu0_v4 vel;
    Path_46FE60 *path;
    s16 h14;
    u8 pad16[2];
    u8 b18;
} P_46FE60;

typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 b8;
    u8 pad9;
    u16 hA;
    f32 fC;
    vu0_v4 pos;
    P_46FE60 st;
} O_46FE60;

extern s32 func_L01_00447470(s32, s32, f32);

void func_L01_0046FE60(O_46FE60 *o)
{
    P_46FE60 *p;
    Path_46FE60 *path;
    s16 *k;
    s32 t;
    f32 f;

    p = &o->st;
    path = p->path;
    func_0038CE20(p, p, (path->f14 - 1.0f) * 1.2f + 1.0f);
    vec_add_ab(&o->pos, &o->pos, &o->st);
    o->b8 = o->b8 + p->b18;
    t = (s16)(path->h10 - o->hA);
    if (path->p8[p->h14 + 1] < t && p->h14 < path->hC) {
        p->h14 = (u16)p->h14 + 1;
    }
    k = path->p8 + p->h14;
    f = (f32)(t - k[0]) / (f32)(k[1] - k[0]);
    o->w4 = func_L01_00447470(path->p0[p->h14], path->p0[p->h14 + 1], f);
    k = path->p4 + p->h14;
    o->fC = ((f32)k[0] + f * (f32)(k[1] - k[0])) * 1000.0f;
    if (func_0038CB00((s16 *)&o->hA) != 0) {
        func_003CD250((Obj *)o);
    }
}
/* localdecomp:end func_L01_0046FE60 */
