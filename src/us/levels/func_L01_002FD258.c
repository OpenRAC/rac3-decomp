#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_002FD288 (src/levels/shared/L01_002F7800.c): timer 15 frames at 60 Hz, not 12 */
/* localdecomp:start func_L01_002FD258 */
typedef struct {
    f32 pos[4], second[4], origin[4], attached[4];
    f32 angle[3], velocity[3], scale[3];
    f32 angle2[3], velocity2[3], scale2[3];
    s32 timer, kind;
    u8 *owner;
    s32 remaining, duration, finished;
} Effect_002FD258;
extern Effect_002FD258 D_L01_0026EB30_002FD258[];
extern vu0_q D_L01_001E1740_002FD258[1] __attribute__((section(".sdata")));
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern u8 *func_0037E0B8(u8 *);
extern void func_L01_0044E010(u8 *, f32 *, s32);
extern void func_003886E8(f32 *, f32 *, f32);

void func_L01_002FD258(s32 kind, u8 *owner, s32 duration) {
    f32 offset[4] __attribute__((aligned(16)));
    Effect_002FD258 *base = D_L01_0026EB30_002FD258;
    s32 i = 0;
    vu0_q *origin = D_L01_001E1740_002FD258;
    Effect_002FD258 *p;
    u8 *attachment;
    for (; i < 3; i++) {
        p = &base[i];
        if (p->kind != 0) continue;
        p->kind = kind;
        *(vu0_q *)p->origin = *origin;
        p->angle[0] = func_0037E250(-3.1415927f, 3.1415927f);
        p->angle[1] = func_0037E250(-3.1415927f, 3.1415927f);
        p->angle[2] = func_0037E250(-3.1415927f, 3.1415927f);
        p->angle2[0] = func_0037E250(-3.1415927f, 3.1415927f);
        p->angle2[1] = func_0037E250(-3.1415927f, 3.1415927f);
        p->angle2[2] = func_0037E250(-3.1415927f, 3.1415927f);
        p->velocity[0] = func_L01_00440918(0.001f, 0.005f);
        p->velocity[1] = func_L01_00440918(0.001f, 0.005f);
        p->velocity[2] = func_L01_00440918(0.001f, 0.005f);
        p->velocity2[0] = func_L01_00440918(0.001f, 0.005f);
        p->velocity2[1] = func_L01_00440918(0.001f, 0.005f);
        p->velocity2[2] = func_L01_00440918(0.001f, 0.005f);
        p->scale[0] = func_0037E250(3.25f, 4.75f) * 0.5f;
        p->scale[1] = func_0037E250(3.25f, 4.75f) * 0.5f;
        p->scale[2] = func_0037E250(3.25f, 4.75f) * 0.5f;
        p->scale2[0] = func_0037E250(3.25f, 4.75f) * 0.5f;
        p->scale2[1] = func_0037E250(3.25f, 4.75f) * 0.5f;
        p->scale2[2] = func_0037E250(3.25f, 4.75f) * 0.5f;
        qzero(p->pos);
        qzero(p->second);
        p->remaining = duration;
        p->duration = duration;
        p->timer = 15;
        p->owner = owner;
        p->finished = 0;
        attachment = func_0037E0B8(owner);
        if (attachment != 0) {
            func_L01_0044E010(owner, offset, 1);
            func_003886E8(offset, offset, *(f32 *)(attachment + 0x10));
            vec_add_ba(p->attached, offset, owner + 0x10);
        } else {
            *(vu0_q *)p->attached = *(vu0_q *)(owner + 0x10);
        }
        break;
    }
}
/* localdecomp:end func_L01_002FD258 */
