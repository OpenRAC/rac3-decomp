/* functional: high. Store/call sequence verified against asm; diffs are float-constant register allocation only. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_0036BC98 */
typedef struct {
    vu0_q q0;
    vu0_q q10;
    f32 x20, y24, z28, w2C;
    vu0_q q30;
    vu0_q q40;
    f32 f50, f54, f58, f5C, f60, f64, f68, f6C, f70, f74, f78, f7C, f80, f84, f88, f8C, f90, f94;
    s32 w98;
    s32 w9C;
    s32 wA0;
    s32 wA4;
    s32 wA8;
    s32 pAC;
} P_0036BC98;
extern P_0036BC98 D_L05_0028DE00[];
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);

void func_L05_0036BC98(u8 *owner, u8 *pos, s32 arg) {
    s32 i;
    P_0036BC98 *p;

    for (i = 0; i < 16; i++) {
        p = &D_L05_0028DE00[i];
        if (p->w9C == 0) {
            p->w9C = (s32)owner;
            *(vu0_q *)&p->x20 = *(vu0_q *)(owner + 0x10);
            p->q40 = *(vu0_q *)pos;
            p->x20 += func_003824E0(-0.1f, 0.1f);
            p->y24 += func_003824E0(-0.1f, 0.1f);
            p->z28 += func_003824E0(-0.1f, 0.1f);
            p->f50 = func_003824E0(-3.1415927f, 3.1415927f);
            p->f54 = func_003824E0(-3.1415927f, 3.1415927f);
            p->f58 = func_003824E0(-3.1415927f, 3.1415927f);
            p->f74 = func_003824E0(-3.1415927f, 3.1415927f);
            p->f78 = func_003824E0(-3.1415927f, 3.1415927f);
            p->f7C = func_003824E0(-3.1415927f, 3.1415927f);
            p->f5C = func_L01_00443A18(0.001f, 0.005f);
            p->f60 = func_L01_00443A18(0.001f, 0.005f);
            p->f64 = func_L01_00443A18(0.001f, 0.005f);
            p->f80 = func_L01_00443A18(0.001f, 0.005f);
            p->f84 = func_L01_00443A18(0.001f, 0.005f);
            p->f88 = func_L01_00443A18(0.001f, 0.005f);
            p->f68 = func_003824E0(3.25f, 4.75f);
            p->f6C = func_003824E0(3.25f, 4.75f);
            p->f70 = func_003824E0(3.25f, 4.75f);
            p->f8C = func_003824E0(3.25f, 4.75f);
            p->f90 = func_003824E0(3.25f, 4.75f);
            p->f94 = func_003824E0(3.25f, 4.75f);
            p->w98 = 17;
            qzero(&p->q0);
            p->wA4 = arg;
            qzero(&p->q10);
            p->wA8 = 0;
            p->wA0 = arg;
            return;
        }
    }
}
/* localdecomp:end func_L05_0036BC98 */
