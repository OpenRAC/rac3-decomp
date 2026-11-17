/* NTSC-U draft (Claude wave K): C of func_L39_0061CC50, the NTSC-U twin of func_L39_0061F3F0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 26 words differ on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L39_0061CC50", whose code is not the PAL one).
 * Worker's note: PAL line lacks -mvu0-use-vf0-vf2: the vu0.h "j" helpers do not compile without it (spilled vf17), so even an exact match is `flags`. Draft 26 diff words of 108 (frame, s-regs, f20-f22 all match). NEEDS divs row 'func_L39_0061CC50 2 2 2'. Found: D_L39_0024130C ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L39_0061CC50 */
typedef struct {
    u8 p0[0x30];
    vu0_v4 v30;
    vu0_v4 v40;
    u8 p50[0x20];
    vu0_v4 v70;
    u8 p80[0x10];
    vu0_v4 v90;
    vu0_v4 vA0;
    vu0_v4 vB0;
    u8 pC0[0x34];
    s32 wF4;
    u8 pF8[4];
    s32 wFC;
    u8 p100[0x5C];
    s32 w15C;
    vu0_v4 v160;
    vu0_v4 v170;
    vu0_v4 v180;
} O_0061CC50;

extern s32 D_001A5F78[];
extern f32 D_L39_0024130C;
__asm__(".extern D_L39_0024130C, 16");
extern void func_003886E8(void *, void *, f32);

void func_L39_0061CC50(O_0061CC50 *o) {
    s32 now;
    vu0_v4 a, b, c, d, e, f, g;
    f32 t, inv;
    vu0_v4 *pv;

    now = D_001A5F78[0];
    if (now == o->wFC) {
        return;
    }
    if (o->w15C >= 0 && now >= o->w15C) {
        *(vu0_q *)&o->v180 = *(vu0_q *)&o->v170;
        *(vu0_q *)&o->v170 = *(vu0_q *)&o->v160;
        o->w15C = -1;
    }
    t = (f32)(now - o->wF4) / (D_L39_0024130C * 1000.0f);
    a = o->v90;
    pv = &o->vA0;
    b = *pv;
    func_003886E8(&c, &o->v30, t);
    func_003886E8(&d, &o->v40, t * 0.5f * t);
    vec_add_ba(&e, &c, &d);
    vec_copy(&g, &o->v70);
    vec_copy(&f, &a);
    vec_add_ba(&o->v90, &g, &e);
    vec_sub_ba(&o->vA0, &f, &o->v90);
    t = (f32)(now - o->wFC) / (D_L39_0024130C * 1000.0f);
    inv = 1.0f / t;
    func_003886E8(pv, pv, inv);
    vec_sub_ba(&o->vB0, &b, &o->vA0);
    func_003886E8(&o->vB0, &o->vB0, inv);
    o->wFC = now;
}
/* localdecomp:end func_L39_0061CC50 */
