/* NTSC-U draft (2026-11-14, Claude worker): C of func_L04_004F9C78, the NTSC-U twin of func_L04_004FDD98, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L04_004FDD98.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L04_004FDD98 (src/levels/shared/L04_004FDD98.c) */
/* localdecomp:start func_L04_004F9C78 */
extern s32 D_001D545C;
extern f32 D_L04_001DBCD8[];
typedef struct {
    u8 pad0[0x1B0];
    f32 f1B0;
    u8 pad1B4[0x1479 - 0x1B4];
    u8 b1479;
    u8 pad147A[0x2838 - 0x147A];
    f32 f2838;
} H_004F9C78;
extern H_004F9C78 D_001A4BE0;
extern void func_L01_004EAA78(s32, f32);

void func_L04_004F9C78(void) {
    func_L01_004EAA78(0, 1.0f);
    if (D_001A4BE0.f1B0 > 0.0f) {
        D_001A4BE0.f1B0 = D_L04_001DBCD8[0] * 0.016666668f * D_001A4BE0.f2838;
    }
    if (D_001D545C == 0x15 && D_001A4BE0.b1479 != 0) {
        D_001A4BE0.f1B0 = D_001A4BE0.f1B0 * 0.85f;
    }
}
/* localdecomp:end func_L04_004F9C78 */
