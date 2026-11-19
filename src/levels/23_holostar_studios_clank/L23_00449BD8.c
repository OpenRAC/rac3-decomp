#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct {
    u8 x0;
    u8 x1;
    u8 x2;
    u8 x3;
    s32 x4;
    u8 x8;
    u8 x9;
    s16 xA;
    s32 xC;
    V4 pos;
    V4 x20;
    void *x30;
} Fx_449BD8;
typedef struct { u8 pad0[0x10]; V4 pos; } Tgt_449BD8;

/* localdecomp:start func_L23_00449BD8 */
#include "vu0.h"
extern u8 *func_L01_004618E0(s32);
extern void func_0038CE20(void *, void *, f32);
extern s32 D_L23_001D7EDC;

void func_L23_00449BD8(s32 arg0, V4 *pos, Tgt_449BD8 *target) {
    Fx_449BD8 *o;
    V4 p;
    V4 v[2], temp;

    p = *pos;
    o = (Fx_449BD8 *)func_L01_004618E0(0x1F);
    if (o != 0) {
        vec_sub_ba(&temp, &p, &target->pos);
        v[0] = v[1] = temp;
        func_0038CE20(v, v, 0.25f);
        vec_add_ba(&temp, &target->pos, v);
        o->pos = v[1] = temp;
        o->x20 = p;
        o->x30 = target;
        o->xC = arg0 & 0xFFFFFF;
        o->x4 = arg0;
        o->x9 = 0x74;
        o->x3 = 0x44;
        o->x1 = 2;
        o->xA = (D_L23_001D7EDC * 5 + 2) / 6;
    }
}
/* localdecomp:end func_L23_00449BD8 */
