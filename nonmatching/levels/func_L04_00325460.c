/* PAL draft (2026-11-20, Promises fleet rac3-w3): PAL names and PAL's constants (50 for the two
 * 60s, 8 and 0.125 for 10 and 0.1, 33 for 40). check.py at level 04: 44 diff with its file's line set to
 * `-mvu0-use-vf0-vf2 -O2 -G8 -mno-check-zero-division @ps2as` and `func_L04_00325460` in
 * config/levels/sq_ra_funcs.txt (both not committed: it does not match yet). Why: retail saves the
 * $s registers and $ra with sq in ascending 16-byte slots (frame 0x130), builds float constants
 * inline (lui/ori), reads D_001D52F0 through lui and once through $gp in a delay slot (Ps2EeAs), and
 * interleaves its VU0 lqc2 with ordinary code (j-form, vec_sub_ba / vec_sub_ab from include/vu0.h).
 * Steps: 188 (file flags) -> 174 (sq saves, -fno-opt-stack) -> 55 (the three .w = 0.0f as one chained
 * store from an FPR) -> 53 (chain order C, D, E) -> 44 (j-form helpers).
 * What still differs: retail keeps the source order of the stores at the start (0x30, 0x32, 0x20) and of
 * the p-> stores (h2 right after w30, h0 near the end), and reads D_001D52F0 only after the m->pos
 * copy; this C lets the scheduler move the stores and hoist that load to the top. A player-pointer
 * local, u8-offset stores, the `.extern D_001D52F0, 16` hint, -fno-strict-aliasing/-fno-sched-interblock/
 * -fno-force-mem/-fno-sched-spec (diagnostic only) leave it at 44.
 * 2026-11-21 (task 2784): still 44 diff; all six source orders of the first three stores (0x30, 0x32,
 * 0x20) compile to the same code, so their order is the scheduler's, not the source's.
 * Earlier header (NTSC-U draft):
 */
/* NTSC-U draft (2026-11-14, Codex worker): C of func_L04_00324BA8, the NTSC-U twin of func_L04_00325460, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L04_00325460.c's current line.
 * Worker's note: 191 diff best log func_L04_00324BA8.check01.log; documented inline-literal assembler mismatch lit4 lwc1 vs retail inline literals; unlisted flags not tried; frame/saved-register width/VU0 scheduling also differ
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_00325460 */
typedef struct { s16 h0,h2,h4,pad6; f32 f8,fC,f10,f14; s32 w18,w1C,w20,w24,w28,w2C,w30,w34,w38; void *p3C; } P_325460;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 b20; u8 pad21[0x30-0x21]; u8 b30,pad31; s16 h32; u8 pad34[0x68-0x34]; P_325460 *vars; u8 pad6C[0xC0-0x6C]; vu0_v4 vC0,vD0,vE0; } M_325460;
typedef struct { vu0_v4 pos; u8 pad10[0x10]; f32 f20; u8 pad24[4]; s32 w28,w2C; u8 pad30[0x380-0x30]; vu0_v4 v380; u8 pad390[0x460-0x390]; } Player_325460;
extern M_325460 *func_003C24B0(s32,s32);
extern Player_325460 D_L04_001E2840[];
extern s32 D_001D52F0;
extern void func_0038CF68(void *,void *,f32);
extern void func_003C5180(void *,void *,s32);
extern void func_0038CE90(void *,void *,void *);
extern void func_L01_0044C870(void *,void *,void *,void *);
extern s32 func_0038DC20(void *,f32);
extern f32 func_L01_0040E548(void *,void *);
extern f32 func_0038CE68(void *,void *);
extern f32 func_0038D0C8(f32);
extern void func_L04_00325C08(void *,void *,void *,f32);
M_325460 *func_L04_00325460(vu0_v4 *pos,s32 flag,s32 w20,s32 w24,s32 w28,s32 w2C,s32 w30,s32 w18,s32 w34,s32 w1C,s32 w38,void *parent,f32 scale,f32 extra) {
    vu0_v4 dir,basis,shift,box,aim;
    M_325460 *m = func_003C24B0(0x13A0,0x80);
    if (m) {
        P_325460 *p;
        m->b30 = 0xFF;
        m->h32 = 0x1FF;
        m->b20 = 0;
        p = m->vars;
        m->pos = *pos;
        m->pos.w = 1.0f;
        vec_sub_ba(&dir,&D_L04_001E2840[D_001D52F0].pos,&m->pos);
        func_0038CF68(&dir,&dir,1.0f);
        func_003C5180(&m->pos,&basis,1);
        m->vC0 = dir;
        func_0038CE90(&m->vD0,&m->vC0,&basis);
        func_0038CF68(&m->vD0,&m->vD0,1.0f);
        func_0038CE90(&m->vE0,&m->vD0,&m->vC0);
        m->vC0.w = m->vD0.w = m->vE0.w = 0.0f;
        p->w20=w20;
        p->w24=w24;
        p->w28=w28;
        p->w2C=w2C;
        p->w30=w30;
        p->h2=50;
        p->f8=scale+scale;
        p->fC=scale*4.0f;
        p->w34=w34;
        p->w1C=w1C;
        p->w38=w38;
        p->f14=scale;
        p->w18=w18;
        p->h0=50;
        p->p3C=parent;
        qzero(&shift);
        if (parent) func_L01_0044C870(m,parent,&m->pos,&shift);
        box=m->pos;
        box.w=scale*3.0f;
        if (func_0038DC20(&box,511.0f)==1) {
            p->h4=8;
            p->f10=0.125f;
            if (flag && func_L01_0040E548(pos,&D_L04_001E2840[D_001D52F0].pos)<2304.0f) {
                D_L04_001E2840[0].w28=33;
                D_L04_001E2840[0].f20=0.075f;
                D_L04_001E2840[0].w2C=0;
            }
            if (p->w18) {
                f32 a;
                vec_sub_ab(&aim,&m->pos,&D_L04_001E2840[D_001D52F0].pos);
                func_0038CF68(&aim,&aim,1.0f);
                a=func_0038D0C8(func_0038CE68(&aim,&D_L04_001E2840[D_001D52F0].v380));
                if (1.5707963705062866f-a<0.45378559827804565f) p->w18=1;
                else p->w18=0;
            }
        } else {p->h4=0;p->w18=0;}
        func_L04_00325C08(m,&basis,&shift,extra);
    }
    return m;
}
/* localdecomp:end func_L04_00325460 */
