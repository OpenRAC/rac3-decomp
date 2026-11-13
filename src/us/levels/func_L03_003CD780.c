#include "common.h"

/* NTSC-U counterpart of func_L03_003CF7B0 (src/levels/03_starship_phoenix/L03_003CF7B0.c): 83 -> 100; 125 -> 150; 250 -> 300 */
#include "vu0.h"

/* localdecomp:start func_L03_003CD780 */
extern u8 D_00142CBE[];
extern s32 D_L03_001D6694_003CD780;
extern s32 D_001A71A4[];
extern u8 D_001A4C60[];
extern void func_003BD360(void *);
extern void func_L03_003CDB60(u8 *);
extern void func_L03_003CDAB8(u8 *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern void func_L03_004460F8(void *, s32, s32, s32);
extern s32 func_00388398(void *);
extern s32 func_L02_003E4788(f32, void *, void *);
extern f32 func_00388730(void *, void *);
extern void func_L03_00445EB8(void *, s32);
extern f32 func_00388A28(f32, f32);
extern void func_L01_00458A08(void *, f32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_L01_00456960(s32);
extern void func_003BF4F8(void *, void *);
extern void func_L01_004576E8(void *);
void func_L03_003CD780(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x68);
    s32 st;
    f32 d[4];
    s32 t;
    if (D_00142CBE[0] == 0) {
        func_003BD360(a0);
        return;
    }
    if (D_L03_001D6694_003CD780 == 2 || D_001A71A4[0] == 0x65) {
        a0[0x31] = 0;
        *(u16 *)(a0 + 0x34) |= 1;
    } else {
        a0[0x31] = 1;
        *(u16 *)(a0 + 0x34) &= ~1;
    }
    st = a0[0x20];
    switch (st) {
    case 0:
        func_L03_003CDB60(a0);
        func_L01_00441FB8(a0, 1, -1);
        if (a0[0x43] != 2) {
            func_003BE4F0(a0, 2, 0, 10);
        }
        break;
    case 1:
        if (func_L01_00452EC8(a0) != 0) {
            func_L03_004460F8(a0, *(s32 *)(q + 0x2A0), 1, -1);
        }
        if (func_00388398(q + 0x2C8) != 0) {
            if (func_L02_003E4788(5.0f, a0 + 0x10, D_001A4C60) != 0) {
                vec_sub_ba(d, D_001A4C60, a0 + 0x10);
                if (func_00388730(d, q + 0xD0) > 0.0f) {
                    t = -*(s32 *)(q + 0x2CC);
                    *(s32 *)(q + 0x2CC) = t;
                    func_L03_004460F8(a0, *(s32 *)(q + 0x2A0), (t == 1) ? 1 : -1, -1);
                }
                *(s32 *)(q + 0x2C8) = 0x64;
            }
        }
        if (*(s32 *)(q + 0x2C8) != 0) {
            if (a0[0x43] != 0) {
                func_003BE4F0(a0, 0, 0, 10);
            }
        } else {
            if (a0[0x43] != 2) {
                func_003BE4F0(a0, 2, 0, 10);
            }
        }
        func_L03_00445EB8(a0, *(s32 *)(q + 0x2A0));
        func_L01_00458A08(a0, func_00388A28(*(f32 *)(q + 0xD0), *(f32 *)(q + 0xD4)));
        break;
    case 2:
        if (func_L01_00452EC8(a0) != 0) {
            a0[0xBC] = 0;
            *(s32 *)(q + 0x2D0) = (*(s32 *)(q + 0x2D4) != 0) ? 0x12C : 0x96;
            if (a0[0x43] != 3) {
                func_003BE4F0(a0, 3, 0, 10);
            }
            *(s32 *)(q + 0x2D8) = *(s32 *)(q + 0x2D8) + 1;
            if (*(s32 *)(q + 0x2D8) < 6) {
                func_L01_0044EBF8(a0, 1, 0.0f);
            }
            if (*(s32 *)(q + 0x2D4) != 0) {
                func_L01_00456960(5);
            }
            q[0x297] = 0xFF;
            func_003BF4F8(a0, q + 0x290);
        }
        if (a0[0x60] & 2) {
            if (a0[0xBC] == 0 && *(s32 *)(q + 0x2D4) != 0) {
                a0[0xBC] = 1;
                if (a0[0x43] != 1) {
                    func_003BE4F0(a0, 1, 0, 10);
                }
            } else {
                func_L01_00441FB8(a0, 1, -1);
            }
        }
        func_L01_004576E8(a0);
        break;
    }
    func_L03_003CDAB8(a0);
}
/* localdecomp:end func_L03_003CD780 */
