#include "common.h"

/* localdecomp:start func_L01_00353158 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_00353158;
extern s32 func_0037E208(s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00407180(void *, void *, void *, s32, s32, s32, s32, s32, u32, u32);

void func_L01_00353158(u8 *m, Vec_00353158 *position) {
    Vec_00353158 copy;
    Vec_00353158 *dest = (Vec_00353158 *)(m + 0x10);
    copy = *position;
    *dest = copy;
    *(u16 *)(m + 0x34) &= 0xFFBC;
    *(u16 *)(m + 0x34) |= *(u16 *)(*(u8 **)(m + 0x24) + 0x44) & 0x1000;
    *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
    if (m[0x43]) func_003BE4F0(m, 0, func_0037E208(0, 10), 0);
    *(f32 *)(m + 0x18) = func_003BE7F0(dest, 0, 0, 0.5f);
    if (m[0x95] == 9) func_L01_00441FB8(m, 24, -1);
    else func_L01_00441FB8(m, 2, 1);
    m[0x31] = 0;
    *(u16 *)(m + 0x34) |= 1;
    func_L01_00407180(m, m + 0x10, m + 0xF0, 0, 2, 3, 45, 45, 0x80FF40, 0x108F10);
}
/* localdecomp:end func_L01_00353158 */
