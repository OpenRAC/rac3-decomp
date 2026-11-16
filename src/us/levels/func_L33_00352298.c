#include "common.h"

/* NTSC-U counterpart of func_L33_00352ED0 (src/levels/33_vidcomic_2/L33_00352ED0.c) */
#include "vu0.h"

/* localdecomp:start func_L33_00352298 */
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_0037E208(s32, s32);
extern s32 D_L33_001DDB88_00352298;
__asm__(".extern D_L33_001DDB88_00352298, 4");
extern s32 D_L33_001DDB84;
__asm__(".extern D_L33_001DDB84, 4");
extern s32 D_L33_001DDAB0_00352298;
__asm__(".extern D_L33_001DDAB0_00352298, 4");
extern f32 D_L33_001DD928;
__asm__(".extern D_L33_001DD928, 4");
extern f32 D_L33_001DDAC4;
__asm__(".extern D_L33_001DDAC4, 4");
extern f32 D_L33_001DDAAC_00352298;
__asm__(".extern D_L33_001DDAAC_00352298, 4");
extern f32 D_L33_001DD8B8_00352298[2];
__asm__(".extern D_L33_001DD8B8_00352298, 8");
extern f32 D_L33_001DD8A8_00352298[2];
__asm__(".extern D_L33_001DD8A8_00352298, 8");
extern f32 D_L33_001DD998_00352298[2];
__asm__(".extern D_L33_001DD998_00352298, 8");
extern f32 D_L33_001DD9C8[2];
__asm__(".extern D_L33_001DD9C8, 8");
extern f32 D_L33_001DDA70_00352298[2];
__asm__(".extern D_L33_001DDA70_00352298, 8");
extern f32 D_L33_001DD9F0_00352298[2];
__asm__(".extern D_L33_001DD9F0_00352298, 8");
extern f32 D_L33_001DDA80_00352298[2];
__asm__(".extern D_L33_001DDA80_00352298, 8");
extern f32 D_L33_001DDAA0_00352298[2];
__asm__(".extern D_L33_001DDAA0_00352298, 8");

void func_L33_00352298(u8 *a0, s32 a1) {
    s32 i = 0x1761 - *(s16 *)(a0 + 0xAA);

    func_L01_00441FB8(a0, a1, -1);
    switch (a0[0x20]) {
    case 1:
        func_003BE4F0(a0, 4, (s32)D_L33_001DD8B8_00352298[i], D_L33_001DDB88_00352298);
        *(f32 *)(a0 + 0x48) = D_L33_001DD8A8_00352298[i];
        break;
    case 2:
        if (a0[0x43] != 0xB) {
            func_003BE4F0(a0, 0xB, (s32)D_L33_001DD998_00352298[i], D_L33_001DDB84);
        }
        *(f32 *)(a0 + 0x44) += *(f32 *)(a0 + 0x4C);
        *(f32 *)(a0 + 0x48) = 1.0f;
        break;
    case 3:
        if (a0[0x43] != 7) {
            func_003BE4F0(a0, 7, 0, D_L33_001DDB88_00352298);
        }
        *(f32 *)(a0 + 0x48) = D_L33_001DD9C8[i];
        break;
    case 4:
        func_003BE4F0(a0, 0xA, (s32)D_L33_001DDA70_00352298[i], D_L33_001DDB84);
        *(f32 *)(a0 + 0x48) = D_L33_001DD9F0_00352298[i];
        *(f32 *)(a0 + 0x44) += *(f32 *)(a0 + 0x4C);
        break;
    case 5:
        if (func_0037E208(0, 1) == 0) {
            if (a0[0x43] != 1) {
                func_003BE4F0(a0, 1, 0, D_L33_001DDB88_00352298);
            }
        } else {
            if (a0[0x43] != 2) {
                func_003BE4F0(a0, 2, 0, D_L33_001DDB88_00352298);
            }
        }
        *(f32 *)(a0 + 0x48) = 1.0f;
        break;
    case 7:
        if (a0[0x43] != 5) {
            func_003BE4F0(a0, 5, 0, D_L33_001DDB88_00352298);
        }
        *(f32 *)(a0 + 0x48) = D_L33_001DD928;
        break;
    case 8:
        if (a0[0x43] != 6) {
            func_003BE4F0(a0, 6, (s32)D_L33_001DDAC4, D_L33_001DDB88_00352298);
        }
        *(f32 *)(a0 + 0x48) = 1.0f;
        break;
    case 9:
        if (a0[0x43] != 6) {
            func_003BE4F0(a0, 6, 0, D_L33_001DDB88_00352298);
        }
        break;
    case 10:
        if (a0[0x43] != 0xC) {
            func_003BE4F0(a0, 0xC, (s32)D_L33_001DDAAC_00352298, D_L33_001DDAB0_00352298);
        }
        *(f32 *)(a0 + 0x48) = D_L33_001DDA80_00352298[i];
        break;
    case 11:
        if (a0[0x43] != 8) {
            func_003BE4F0(a0, 8, (s32)D_L33_001DDAA0_00352298[i], D_L33_001DDAB0_00352298);
        }
        *(f32 *)(a0 + 0x48) = D_L33_001DDA80_00352298[i];
        break;
    case 13:
        if (a0[0x43] != 9) {
            func_003BE4F0(a0, 9, 0, D_L33_001DDB88_00352298);
        }
        *(f32 *)(a0 + 0x48) = 1.0f;
        break;
    case 6:
    case 12:
    case 14:
        if (a0[0x43] != 3) {
            func_003BE4F0(a0, 3, 0, D_L33_001DDB88_00352298);
        }
        break;
    case 15:
        if (a0[0x43] != 3) {
            func_003BE4F0(a0, 3, 0, D_L33_001DDB88_00352298);
        }
        *(f32 *)(a0 + 0x48) = 1.0f;
        break;
    case 0:
    case 0x42:
        break;
    }
}
/* localdecomp:end func_L33_00352298 */
