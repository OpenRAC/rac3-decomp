#include "common.h"

/* localdecomp:start func_L07_003B0C10 */
extern u8 D_001A4C60[];
extern u8 *D_001DF41C_sda;
__asm__(".extern D_001DF41C_sda, 4");
extern void func_00388BD0(void *, void *);
extern void func_L07_003B0FB8(void *);
extern s32 func_0037E0F0(void *, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_004A72A8(s32, s32, void *, s32);
extern void func_L01_004A6D70(s32, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L07_003B0E80(void *);

void func_L07_003B0C10(u8 *a0) {
    u8 *p;

    p = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 0) {
        func_00388BD0(a0 + 0xC0, a0 + 0xF0);
        func_L07_003B0FB8(a0);
    }
    switch (a0[0x20]) {
    case 1:
        if (*(s32 *)(p + 0xC) != -1) {
            if (func_0037E0F0(D_001A4C60, *(s32 *)(p + 0xC), 0) != 0) {
                a0[0xBE] |= 4;
            }
        }
        if (a0[0xBE] & 4) {
            func_L01_00441FB8(a0, 2, -1);
        }
        break;
    case 2:
        if (func_L01_00452EC8(a0) != 0) {
            func_L01_004A72A8(0, 4, a0, 0x1D79);
            if (*(s32 *)(p + 0x10) != -1) {
                (D_001DF41C_sda + (*(s32 *)(p + 0x10) << 8))[0xBE] |= 4;
            }
        }
        if (!(a0[0xBE] & 4)) {
            func_L01_004A6D70(0, a0);
            func_L01_00441FB8(a0, 4, -1);
        } else {
            *(f32 *)(p + 0x14) = *(f32 *)(p + 0x14) + 0.01f;
            if (*(f32 *)(p + 0x14) >= 1.0f) {
                *(f32 *)(p + 0x14) = 1.0f;
                func_L01_004A6D70(0, a0);
                func_L01_00441FB8(a0, 3, -1);
            }
            func_L07_003B0E80(a0);
        }
        break;
    case 3:
        if (!(a0[0xBE] & 4)) {
            func_L01_00441FB8(a0, 4, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(a0) != 0) {
            func_L01_004A72A8(0, 4, a0, 0x1D79);
            if (*(s32 *)(p + 0x10) != -1) {
                (D_001DF41C_sda + (*(s32 *)(p + 0x10) << 8))[0xBE] &= 0xFB;
            }
        }
        if (a0[0xBE] & 4) {
            func_L01_004A6D70(0, a0);
            func_L01_00441FB8(a0, 2, -1);
        } else {
            *(f32 *)(p + 0x14) = *(f32 *)(p + 0x14) - 0.01f;
            if (*(f32 *)(p + 0x14) <= 0.0f) {
                *(f32 *)(p + 0x14) = 0.0f;
                func_L01_004A6D70(0, a0);
                func_L01_00441FB8(a0, 1, -1);
            }
            func_L07_003B0E80(a0);
        }
        break;
    }
}
/* localdecomp:end func_L07_003B0C10 */
