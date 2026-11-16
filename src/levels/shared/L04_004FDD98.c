#include "common.h"

/* localdecomp:start func_L04_004FDD98 */
typedef struct { f32 a; f32 b; } F2_004FDD98;
extern void func_L01_004EE850(s32, f32);
extern u8 D_001A4BE0[];
extern s32 D_001D545C;
extern F2_004FDD98 D_L04_001DBC94_004FDD98;
__asm__(".extern D_L04_001DBC94_004FDD98, 16");

void func_L04_004FDD98(void) {
    u8 *h;
    func_L01_004EE850(0, 1.0f);
    h = D_001A4BE0;
    if (*(f32 *)(h + 0x1B0) > 0.0f) {
        *(f32 *)(h + 0x1B0) = D_L04_001DBC94_004FDD98.b * 0.020000001f * *(f32 *)(h + 0x2838);
    }
    if (D_001D545C == 0x15 && h[0x1479] != 0) {
        *(f32 *)(h + 0x1B0) *= 0.85f;
    }
}
/* localdecomp:end func_L04_004FDD98 */
