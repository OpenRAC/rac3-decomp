#include "common.h"

/* NTSC-U counterpart of func_003BC858 (src/frontbin/3BC858.c): 60 Hz timer (25 -> 30) */
/* localdecomp:start func_U_003B7378 */
typedef struct { u8 p0[0x15C]; s32 f15C; s32 f160; s32 f164; } S_142430_003B7378;
extern S_142430_003B7378 D_00142430_003B7378;
extern s32 D_U_001D9A24;
extern s32 D_001D4BC4;
extern s32 D_U_001D9C48;
extern f32 D_U_001D8D20;
extern void func_U_00384B68(s32);
extern void func_U_003A3EF0(s32, unsigned long);
extern long func_U_00384EC0(s32);
extern void func_U_00386D98(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
extern void func_U_00392DD8(f32, f32, f32, f32, f32, s32, s32, long);
extern void func_U_00384C98(void);
extern void func_U_003866E8(s32, s32, s32, s32);
__asm__(".extern D_U_001D8D20, 4");
void func_U_003B7378(void) {
    f32 rotation, y, size;
    if ((D_00142430_003B7378.f15C == 15 || D_00142430_003B7378.f15C == 16) ||
        D_00142430_003B7378.f164 == 15 || D_U_001D9A24 != 0) {
        size = 272.0f;
        func_U_00384B68(1);
        func_U_003A3EF0(0x42, 0x8000000044UL);
        func_U_003A3EF0(0x47, 0x3004B);
        func_U_00386D98(0x2C, D_001D4BC4 - 96, 64, 64, 0, 0, 64, 64, 0x80808080UL, func_U_00384EC0(3));
        rotation = (f32)(D_U_001D9C48 % 55) * -6.2831855f / 55.0f;
        y = (f32)((D_001D4BC4 - 64) << 4);
        func_U_00392DD8(1216.0f, y, size, size, rotation, 64, 64, func_U_00384EC0(4));
        func_U_00384C98();
        if ((D_00142430_003B7378.f15C == 15 || D_00142430_003B7378.f15C == 16) ||
            D_00142430_003B7378.f164 == 15) {
            D_U_001D9A24 = 30;
        } else {
            D_U_001D9A24--;
        }
    }
    func_U_003A3EF0(0x42, 0x8000000044UL);
    func_U_003866E8(0, 0, 0, (s32)(D_U_001D8D20 * 128.0f));
}
/* localdecomp:end func_U_003B7378 */
