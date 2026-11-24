/* NTSC-U native near miss: 2 instruction words differ. Stores to the target
 * pointer at +0x30 and packed colour at +0x0C occur in the opposite order.
 * The lifetime global is a real u16, without PAL frame scaling.
 * Not linked and not counted as a match.
 */
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

/* localdecomp:start func_U_L23_00446600 */
#include "vu0.h"
extern u8 *func_U_L23_0043FBA0(s32);
extern void func_U_L23_003EED68(void *, void *, f32);
extern u16 D_L23_001D7EDC;

void func_U_L23_00446600(s32 arg0, V4 *pos, Tgt_449BD8 *target) {
    Fx_449BD8 *o;
    V4 p;
    V4 v[2], temp;

    p = *pos;
    o = (Fx_449BD8 *)func_U_L23_0043FBA0(0x1F);
    if (o != 0) {
        vec_sub_ba(&temp, &p, &target->pos);
        v[0] = v[1] = temp;
        func_U_L23_003EED68(v, v, 0.25f);
        vec_add_ba(&temp, &target->pos, v);
        o->pos = v[1] = temp;
        o->x20 = p;
        o->x30 = target;
        o->x4 = arg0;
        o->x9 = 0x74;
        o->x3 = 0x44;
        o->x1 = 2;
        o->xA = D_L23_001D7EDC;
        o->xC = arg0 & 0xFFFFFF;
    }
}
/* localdecomp:end func_U_L23_00446600 */
