/* Level 03 (Starship Phoenix), PAL. 12 diff with check.py --target level_03 --as ps2as --flags=-mvu0-use-vf0-vf2 (L03_00399D30.c has no C yet; it would need -mvu0-use-vf0-vf2 ... @ps2as). Structure, VU0 helpers, constants and the func_L01_0046FB40 prototype (as in func_L02_0039EF28) match; left: retail sets `addiu $a2,$zero,0x64` before `movz` and `move $a0,$sp` after it (this C the reverse), and keeps the returned pointer in $a2 with the 0x44 byte in $a1 and the table byte in $a0, this C leaves it in $a0 / $v0. About 12 wordings tried (vec_add_ab/ba, D_001D66B0 as array/scalar address, the pointer global as scalar/array). */
#include "common.h"
#include "vu0.h"
extern u8 D_L03_001E24C0[];
extern u8 D_001D66B0;
extern u8 *D_L03_0021F2F4;
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);
void func_L03_0039A118(void *arg) {
    vu0_v4 v;
    vu0_v4 d;
    u8 *r;
    vec_sub_ab(&d, D_L03_001E24C0, (u8 *)arg + 0x10);
    func_0038CF68(&d, &d, 0.8f);
    vec_add_ba(&v, (u8 *)arg + 0x10, &d);
    v.z += 0.625f;
    r = func_L01_0046FB40(&v, &D_001D66B0, 100, 0x7FFFFFFF, func_00382468(2) != 0 ? -1 : 1, 0, 0x7F, 525000.0f, 525000.0f, 0, 0.0f);
    if (r != 0) {
        r[3] = 0x44;
        r[2] = D_L03_0021F2F4[0];
    }
}
