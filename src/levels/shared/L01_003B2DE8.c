#include "common.h"

/* localdecomp:start func_L01_003B2DE8 */
extern s32 D_001D545C;
extern u8 D_00142738[];
extern u8 D_001439F4[];
extern s32 D_001D4C38;
extern u32 D_001A7DD0[];
extern u32 D_001A8414[];
extern u32 D_001A842C[];
extern s32 D_001C5290[][16];
__asm__(".extern D_001D545C, 16");
__asm__(".extern D_001D4C38, 16");
extern s32 func_L01_00513EF0(void);
extern s32 func_L01_003273E8(void);
extern void func_L01_0041A5B0(s32, s32);

void func_L01_003B2DE8(void *unused, s32 *event) {
    if (D_001D545C == 4) {
        if (*event == 100 && !D_00142738[0] && !D_001439F4[0] && (D_001D4C38 * 5 + 2) / 6 - D_001A7DD0[0] > 180000u &&
            !func_L01_00513EF0() && !(D_001A8414[0] & (1 << D_001D545C))) {
            func_L01_0041A5B0(0xCD6, 0x7F);
        }
    } else if (D_001D545C == 12) {
        s32 n = func_L01_003273E8();
        if (D_001C5290[D_001D545C][n] == 3 && !D_001439F4[0] && (D_001D4C38 * 5 + 2) / 6 - D_001A7DD0[0] > 60000u &&
            !func_L01_00513EF0() && !(D_001A842C[0] & (1 << D_001D545C))) {
            func_L01_0041A5B0(0xCD8, 0x81);
        }
    }
}
/* localdecomp:end func_L01_003B2DE8 */
