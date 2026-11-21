#include "common.h"

/* NTSC-U counterpart of func_003811E8 (src/boot_elf/text/381080.c): no func_003AB218 call at the end */
/* localdecomp:start func_U_00381228 */
typedef struct { u8 pad[0x84]; s32 f84; } S_00381228;
extern S_00381228 D_U_00227600;
extern s32 D_U_001D5C78_00381228;
__asm__(".extern D_U_001D5C78_00381228, 16");
extern s32 func_0011A264(s32, s32, s32);
extern s32 func_U_003F2580(s32, s32);
extern void *func_U_003AF2D0();

void func_U_00381228(void) {
    func_0011A264(D_U_00227600.f84, 0xCD, 0x40000);
    D_U_001D5C78_00381228 = (s32)func_U_003AF2D0(func_U_003F2580(0x24F10, D_U_00227600.f84), 0x40000);
}
/* localdecomp:end func_U_00381228 */
