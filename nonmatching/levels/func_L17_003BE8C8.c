/* Level 17 (Crash Site), PAL. 61 diff with check.py (L17_003BE8C8.c flags). The machine gun enemy's hit/explosion effect (called by func_L17_003BEB98 and func_L17_003BEE50 with their colours).
   What differs: mostly the frame. Retail saves $s0..$s7, $fp and $ra in 16-byte `sq` slots, ascending
   with $ra highest, in a 0x170 frame (the sq_ra class, like func_L02_004BE7A8); the file's -fopt-stack
   gives 8-byte `sd` slots in 0x120, and without it gcc writes descending `sq` slots with `sd $ra`
   lowest (0x180 frame). Levels have no sq_ra_funcs table, so the frame cannot be reached; every
   stack offset after it differs. In the body: the argument moves of the first func_L01_00451FE0 call
   are scheduled in another order, two calls' float moves sit after the int moves, and the last
   two stack parameters land in $s6/$s7 swapped. Calls, constants, the VU0 add and the 30-argument
   func_L01_003303B8 call are right. */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BE8C8;
extern s32 D_L17_001D66B0[2];
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L05_003DC520(void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L02_00429840(void *, void *, s32, s32, void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L17_003BE8C8(u8 *self, s32 id, s32 snd, s32 fx1, s32 fx2, s32 fx3, s32 col1, s32 col2,
                       f32 speed, f32 scale, s32 col3, s32 col4, s32 col5, u8 flag) {
    V4_3BE8C8 pos, vel;

    func_003A52A0(0, 0, self);
    func_L01_00451FE0(self, id, D_L17_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                      3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
    if (snd != 0) func_L05_003DC520(self, snd);
    pos = *(V4_3BE8C8 *)(self + 0x10);
    vel = *(V4_3BE8C8 *)(self + 0xE0);
    func_0038CF68(&vel, &vel, *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24) * speed);
    vec_add_ab(&pos, &pos, &vel);
    if (fx1 != 0) {
        func_L02_00429840(self, &pos, 0x14, 0, D_L17_001D66B0, col1, 0, 0x4B,
                          *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24) * 4.0f, 0.20000002f, 1.0f, 1.5f);
    }
    if (fx2 != 0) {
        func_L02_003E2E38(self, &pos, 1.0f, D_L17_001D66B0, 0xF, 0, 1, 0.050000004f, 2.5f, 5.0f, 1.0f);
    }
    if (fx3 != 0) {
        func_L01_003303B8((u8 *)&pos, 0, 0, 0, 0, 4, 5, 0,
                          *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24) * scale, 0.0f, 0.0f, 0.0f,
                          flag, 1, 0, 0, 0, 0, 0x1000000, 0, col2, col3, 0, 0, 0, 0, col4, col5, 0, 0);
    }
    func_L01_00451E78(self, 1, 0.0f);
    func_003C2880(self);
}
