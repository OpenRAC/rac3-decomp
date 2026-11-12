#include "common.h"

/* localdecomp:start func_L20_00442428 */
extern s32 D_001D545C;
extern s32 D_001D6B00;
extern u8 D_001D6AF5;
extern f32 D_001D6B94;
extern u8 D_L20_002F05E0[];
extern u8 D_L20_001E71F0[];
extern u8 D_L20_002F0630[];
extern void func_L01_00423068(void *, s32, s32, s32, s32, s32, s32);
__asm__(".extern D_001D6B00, 4");
__asm__(".extern D_001D6AF5, 4");
__asm__(".extern D_001D6B94, 4");

void func_L20_00442428(void) {
    u8 *p = D_L20_002F05E0;
    u8 *q = 0;
    D_001D6B94 = 1.0f;
    *(s32 *)(p + 0x20) = (s32)&D_001D6B00;
    *(s32 *)(p + 0x30) = 1;
    D_001D6AF5 = 0;
    if (D_001D545C == 20) {
        if (*(s32 *)D_L20_001E71F0 == 0) {
            q = D_L20_002F0630;
        }
    }
    if (q != 0) {
        func_L01_00423068(q, 0, 0, 0, 0, 1, 0);
    }
}
/* localdecomp:end func_L20_00442428 */
