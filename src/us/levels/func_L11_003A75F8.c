#include "common.h"

/* NTSC-U counterpart of func_L11_003A9260 (src/levels/11_obani_moons/L11_003A8FE0.c) */
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);

/* localdecomp:start func_L11_003A75F8 */
extern u8 *D_L11_0021CB80_003A75F8[];

extern s32 func_L11_003A7BC8(u8 *);
extern void func_L11_003A8018(u8 *);
extern void func_L11_003A80B8(void *);
extern void func_L01_0032FE90_003A75F8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32);
extern void func_003BD360(u8 *);
extern s32 func_L01_00452EF0(u8 *);
extern s32 func_0037E208(s32, s32);
extern void func_00389158(void *, void *, void *, f32);
extern s32 func_003883C8(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern s32 func_L01_00451078(u8 *, u8 *);
extern void func_L01_003154D8(u8 *, s32, s32);
extern s32 func_L01_00452EC8(u8 *);
extern f32 func_003887C8(void *, void *);
extern void func_00388830(void *, void *, f32);

void func_L11_003A75F8(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 d;
    u8 *e;
    u8 *p;
    f32 best;
    s32 i;
    s32 r;

    if (func_L11_003A7BC8(a0) != 0) {
        func_003BD360(a0);
        return;
    }
    if (*(f32 *)(v + 0x30) <= 0.0f) {
        func_L11_003A8018(a0);
        func_L01_0032FE90_003A75F8(a0 + 0x10, 1, 0x28, 0x28, 0x28, 0x28, 0x41, 0, 3.0f, 0.0f, 0.0f, 2.0f,
                          0, 1, 1, 1, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003BD360(a0);
        return;
    }
    switch (a0[0x95]) {
    case 0:
        if (func_L01_00452EF0(a0) != 0) {
            *(u16 *)(v + 0x2D6) = func_0037E208(0, 0x1E);
        }
        func_00389158(a0 + 0xD0, a0 + 0xD0, a0 + 0xE0, 0.03490658849477768f);
        func_00389158(a0 + 0xC0, a0 + 0xC0, a0 + 0xE0, 0.03490658849477768f);
        if (*(s16 *)(v + 0x234) == 1) {
            if (func_003883C8(v + 0x2D6) != 0) {
                break;
            }
        }
        if (*(s32 *)(v + 0x2D8) == 0) {
            break;
        }
        if (func_003883C8(v + 0x2D6) == 0) {
            break;
        }
        *(s32 *)(v + 0x2D8) = 0;
        if (*(s32 *)(v + 0x2D0) < 300) {
            *(s32 *)(v + 0x2D0) = func_0037E208(0x1E0, 0x258);
        }
        break;
    case 1:
        if (*(s16 *)(v + 0x234) == 1) {
            func_L01_00441FB8(a0, 3, 2);
        } else if (*(s32 *)(v + 0x2D0) == 0) {
            func_L01_00441FB8(a0, 1, 0);
        }
        break;
    case 2:
        if (a0[0x42] == 2) {
            if (a0[0x20] != 4 && a0[0x43] != 3) {
                func_003BE4F0(a0, 3, 0, 3);
            }
        }
        if (a0[0x42] == 3 && (a0[0x60] & 2) != 0 && a0[0x43] != 0) {
            func_003BE4F0(a0, 0, 0, 2);
        }
        if (*(s16 *)(v + 0x234) != 1) {
            func_L01_00452EF0(a0);
        }
        break;
    case 3:
        r = func_L01_00451078(a0, v + 0x160);
        if (r & 1) {
            func_L11_003A8018(a0);
            func_L01_003154D8(a0, 0, 0);
            return;
        }
        if (r & 2) {
            if (*(s16 *)(v + 0x234) == 1) {
                func_L01_00441FB8(a0, 3, 2);
            } else {
                func_L01_00441FB8(a0, 2, 1);
                *(s32 *)(v + 0x2D0) = func_0037E208(0x244, 0x258);
            }
        }
        break;
    }
    switch (a0[0x20]) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        if (func_L01_00452EC8(a0) != 0 && a0[0x94] != 4) {
            e = D_L11_0021CB80_003A75F8[*(s32 *)(v + 0x2E4)];
            best = 1.0e9f;
            for (i = 0; i < *(s32 *)e - 1; i++) {
                if (func_003887C8(a0 + 0x10, e + 0x10 + i * 0x10) < best) {
                    best = func_003887C8(a0 + 0x10, e + 0x10 + i * 0x10);
                    *(s32 *)(v + 0x2E8) = i;
                }
            }
        }
        if (*(s32 *)(v + 0x2E4) != -1) {
            p = D_L11_0021CB80_003A75F8[*(s32 *)(v + 0x2E4)];
            vec_sub_ba(&d, p + 0x10 + *(s32 *)(v + 0x2E8) * 0x10, a0 + 0x10);
            func_00388830(&d, &d, *(s32 *)(v + 0x2E4) * 0.0166666675f);
            if (func_003887C8(a0 + 0x10, p + 0x10 + *(s32 *)(v + 0x2E8) * 0x10) < 1.0f) {
                *(s32 *)(v + 0x2E8) += 1;
                if (*(s32 *)(v + 0x2E8) >= *(s32 *)p) {
                    *(s32 *)(v + 0x2E8) = 0;
                }
            }
        }
        if (*(u16 *)(a0 + 0x96) >= 0xF1) {
            func_L01_00441FB8(a0, 4, -1);
            if (a0[0x43] != 1) {
                func_003BE4F0(a0, 1, 0, 10);
            }
        }
        break;
    case 4:
        if (a0[0x42] == 1 && (a0[0x60] & 2) != 0 && a0[0x43] != 2) {
            func_003BE4F0(a0, 2, 0, 3);
        }
        func_00389158(a0 + 0xD0, a0 + 0xD0, a0 + 0xE0, 0.03490658849477768f);
        func_00389158(a0 + 0xC0, a0 + 0xC0, a0 + 0xE0, 0.03490658849477768f);
        if (*(u16 *)(a0 + 0x96) >= 0x3D) {
            func_L01_00441FB8(a0, 3, -1);
        }
        break;
    case 5:
        break;
    }
    func_L11_003A80B8(a0);
}
/* localdecomp:end func_L11_003A75F8 */
