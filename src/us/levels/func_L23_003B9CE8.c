#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L23_003BB7C8, with a 360-frame lifetime. */
/* localdecomp:start func_L23_003B9CE8 */
typedef struct {
    u8 pad0[0x10];
    vu0_q pos;
    u8 x20;
    u8 pad21[0xB];
    f32 x2C;
    u8 x30;
    u8 pad31[0x37];
    u8 *vars;
    u8 pad6C[0x2A];
    u16 x96;
    u8 pad98[0x12];
    s16 xAA;
} Moby_3B9CE8;

extern u8 *func_003BCFB0(s32, s32);
extern void func_L01_00443610(void *, void *, s32, f32);
extern s32 D_L23_001DECC0;

Moby_3B9CE8 *func_L23_003B9CE8(s32 arg0, vu0_q *pos, vu0_q *arg2, f32 scale, s32 arg3, f32 arg5) {
    Moby_3B9CE8 *o;
    u8 *v;

    o = (Moby_3B9CE8 *)func_003BCFB0(0x1C43, 0x80);
    if (o != 0) {
        o->x20 = 0;
        o->x30 = 0xFF;
        o->x2C = scale;
        v = o->vars;
        o->pos = *pos;
        *(vu0_q *)(v + 0x40) = *arg2;
        *(s32 *)(v + 0x0) = arg0;
        *(s32 *)(v + 0x4) = D_L23_001DECC0 + 360;
        func_L01_00443610(v + 0x10, o, arg3, arg5);
        *(u16 *)(v + 0x2A) = o->xAA;
        *(u8 *)(v + 0x28) = 3;
        *(u8 *)(v + 0x29) = 3;
    }
    return o;
}
/* localdecomp:end func_L23_003B9CE8 */
