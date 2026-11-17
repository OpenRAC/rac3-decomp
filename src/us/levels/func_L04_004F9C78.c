#include "common.h"

/* NTSC-U counterpart of func_L04_004FDD98 (src/levels/shared/L04_004FDD98.c) */
/* localdecomp:start func_L04_004F9C78 */
typedef struct { f32 a; f32 b; } F2_004FDD98;
extern void func_L01_004EAA78(s32, f32);
extern u8 D_001A4BE0[];
extern s32 D_001D545C;
extern F2_004FDD98 D_L04_001DBCD4_004F9C78;
__asm__(".extern D_L04_001DBCD4_004F9C78, 16");

void func_L04_004F9C78(void) {
    u8 *h;
    func_L01_004EAA78(0, 1.0f);
    h = D_001A4BE0;
    if (*(f32 *)(h + 0x1B0) > 0.0f) {
        *(f32 *)(h + 0x1B0) = D_L04_001DBCD4_004F9C78.b * 0.01666666754f * *(f32 *)(h + 0x2838);
    }
    if (D_001D545C == 0x15 && h[0x1479] != 0) {
        *(f32 *)(h + 0x1B0) *= 0.85f;
    }
}
/* localdecomp:end func_L04_004F9C78 */
