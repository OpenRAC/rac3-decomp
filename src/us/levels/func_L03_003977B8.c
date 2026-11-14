#include "common.h"

/* localdecomp:start func_L03_003977B8 */
typedef struct { f32 angle; u8 pad[0x1C]; } Row_3977B8;
typedef struct { u8 pad[0x3C0]; f32 angle; } Angle_3977B8;
typedef struct { u8 pad[0xD0]; u8 active; u8 gap[0xB]; void *owner; } Slot_3977B8;
typedef struct {
    u8 pad0[0x3C0];
    Row_3977B8 row[2][4];
    u8 pad4C0[0x10];
    f32 target;
    f32 velocity;
    u8 pad4D8[0x10];
    s32 handle;
    s16 phase;
} State_3977B8;
typedef struct { u8 pad[0x68]; State_3977B8 *state; } Obj_3977B8;
extern f32 func_L03_00397B98(s32, s32);
extern f32 func_L01_00445758(void *, f32, f32, f32, f32, void *, s32);
extern f32 func_00389380(f32, f32);
extern f32 func_003893C8(f32, f32);
extern void func_0039FB08(s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern u8 D_001A30B0[];

void func_L03_003977B8(Obj_3977B8 *self, s32 axis, s32 next) {
    State_3977B8 *p = self->state;
    f32 angle;
    s32 i;
    if (p->phase == -1) {
        p->velocity = 0.0f;
        p->phase = 3;
        p->target = func_L03_00397B98(3, 1);
    }
    angle = func_L01_00445758(&p->row[axis][p->phase],
        func_L03_00397B98(0, 1), 0.0004848137032240629f, 0.0004848137032240629f, 45.0f, &p->velocity, 0);
    for (i = 3; i > p->phase; i--) {
        ((Angle_3977B8 *)((u8 *)p + axis * 0x80 + i * 0x20))->angle = func_00389380(((Angle_3977B8 *)((u8 *)p + axis * 0x80 + i * 0x20))->angle, angle);
    }
    if (func_003893C8(((Angle_3977B8 *)((u8 *)p + (axis * 0x80 + p->phase * 0x20)))->angle, p->target) >= 0.0f) {
        if (p->phase > 0) {
            p->target = func_L03_00397B98(--p->phase, 1);
        } else {
            p->velocity = 0.0f;
            p->phase = -1;
            if (p->handle != -1 && ((Slot_3977B8 *)(D_001A30B0 + p->handle * 0x80))->owner == self && ((Slot_3977B8 *)(D_001A30B0 + p->handle * 0x80))->active) {
                func_0039FB08(p->handle);
            }
            p->handle = -1;
            func_L01_00441FB8(self, next, -1);
        }
    }
}
/* localdecomp:end func_L03_003977B8 */
