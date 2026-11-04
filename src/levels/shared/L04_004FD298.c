#include "common.h"

/* localdecomp:start func_L04_004FD298 */
extern u8 D_001A4BE0[];
extern f32 func_0038CF38(void *a0, void *a1);
extern void func_003C4138(f32 *a0, f32 a1, f32 a2);
extern void func_L01_004482A0(f32 *a0, f32 *a1, f32 a2, f32 a3, f32 a4, f32 a5);

void func_L04_004FD298(s32 a0) {
    switch (D_001A4BE0[0x25E4]) {
    case 0:
        *(f32 *)(D_001A4BE0 + 0x278) = 0.8f;
        *(f32 *)(D_001A4BE0 + 0x27C) = 0.7f;
        *(f32 *)(D_001A4BE0 + 0x280) = 0.45f;
        break;
    case 1:
        *(f32 *)(D_001A4BE0 + 0x278) = 0.55f;
        *(f32 *)(D_001A4BE0 + 0x27C) = 0.45f;
        *(f32 *)(D_001A4BE0 + 0x280) = 0.25f;
        break;
    case 3:
        *(f32 *)(D_001A4BE0 + 0x278) = 0.8f;
        *(f32 *)(D_001A4BE0 + 0x27C) = 0.6f;
        *(f32 *)(D_001A4BE0 + 0x280) = 0.45f;
        break;
    }
    {
        u8 *g = D_001A4BE0;
        if (*(s32 *)(g + 0x25CC) == 4) {
            if (*(s16 *)(g + 0x47C) < *(s32 *)(g + 0x1B8) && !g[0x46E]) {
                *(f32 *)(g + 0x27C) = *(f32 *)(g + 0x488);
            }
        } else if (*(s32 *)(g + 0x25C4) == 6) {
            *(f32 *)(g + 0x27C) = 0.5f;
        } else if (*(s32 *)(g + 0x25C4) == 4) {
            *(f32 *)(g + 0x278) = 0.350000023841858f;
        } else if (*(s32 *)(g + 0x25CC) == 0x11 || *(s32 *)(g + 0x25CC) == 0x12) {
            *(f32 *)(g + 0x278) = 0.0f;
            *(f32 *)(g + 0x27C) = 0.0f;
        } else if (*(s32 *)(g + 0x25C4) == 0x81) {
            *(f32 *)(g + 0x280) = 0.8f;
        } else if (*(s32 *)(g + 0x25C4) == 0x50) {
            *(f32 *)(g + 0x280) = 0.5f;
        }
    }
    if (a0 != 0) {
        u8 *g = D_001A4BE0;
        *(f32 *)(g + 0x270) = *(f32 *)(g + 0x278);
        *(f32 *)(g + 0x274) = *(f32 *)(g + 0x27C);
        *(f32 *)(g + 0x284) = *(f32 *)(g + 0x280);
    }
    if (!D_001A4BE0[0x2A7] || *(s32 *)(D_001A4BE0 + 0x25D4) == 0x12 ||
        *(s32 *)(D_001A4BE0 + 0x25E0) == 0x12 ||
        (!D_001A4BE0[0x25E4] && *(f32 *)(D_001A4BE0 + 0x274) < 0.53f) ||
        *(s32 *)(D_001A4BE0 + 0x25CC) == 0x11 || D_001A4BE0[0x1476] ||
        func_0038CF38(D_001A4BE0 + 0x260, D_001A4BE0 + 0x80) > *(f32 *)(D_001A4BE0 + 0x284) * 0.5f) {
        f32 *p = (f32 *)(D_001A4BE0 + 0x270);
        u8 *g = D_001A4BE0;
        func_003C4138(p, *(f32 *)(g + 0x278), 0.024f);
        func_003C4138(p + 1, *(f32 *)(g + 0x27C), 0.024f);
        func_L01_004482A0(p + 5, p + 6, *(f32 *)(g + 0x280), 0.0288000014f, 0.43200004f, 0.0800000056f);
    }
}
/* localdecomp:end func_L04_004FD298 */
