/* Level 01. 7 diff, all in the argument setup of func_L01_00451FE0: retail schedules "move $a0,$s0" after "sw $v0,8($sp)" and puts "addiu $a1,$zero,0x7f" in the jal delay slot; gcc hoists both above the mov.s copies. Needs @ps2as. About 25 variants tried. */
#include "common.h"
extern u8 D_001D66B0[8];
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void *func_L01_00452460(void *, s32, s32);
extern void func_003C2880(void *);

void func_L01_003D9428(u8 *o) {
    u8 *p;
    if (func_L01_00447490(o, -1, 0) != 0) {
        func_003A52A0(0, 0, o);
        func_L01_00451FE0(o, 0x7F, D_001D66B0, 255, 180, 0, 0, 35, 0, 3, 2.0f, 3.0f, 2.0f, 4.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        p = func_L01_00452460(o, 0x1E80, 0);
        if (p != 0) *(s32 *)(p + 0x98) = *(s32 *)(*(u8 **)(p + 0x24) + 0x10);
        func_L01_00451E78(o, 1, 0.0f);
        func_003C2880(o);
    }
}
