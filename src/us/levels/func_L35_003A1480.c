#include "common.h"

/* NTSC-U counterpart of func_L35_003A2D30 (src/levels/35_vidcomic_5/L35_003A2D30.c) */
extern u8 D_001A4BE0[];

/* localdecomp:start func_L35_003A1480 */
#include "vu0.h"

extern u8 D_001A4BE0[];
extern u8 D_L35_001D66B0_003A1480[8];
extern s32 D_L35_001E1DE0;
__asm__(".extern D_L35_001E1DE0, 16");
extern f32 D_L35_001E1DE4;
__asm__(".extern D_L35_001E1DE4, 16");
extern u8 D_L35_0021F2D8[];
extern s32 D_L35_001DE9E8_003A1480;
extern const f32 D_L35_001DE9D0_003A1480;
extern s32 D_L35_001DE9F8_003A1480;
extern s32 D_L35_001DEA04_003A1480;
extern s32 D_L35_001DEA00_003A1480;
extern f32 D_L35_001DE9EC_003A1480;
extern s32 D_L35_001DE9E0_003A1480;
__asm__(".extern D_L35_001DE9E8_003A1480, 4");
__asm__(".extern D_L35_001DE9D0_003A1480, 4");
__asm__(".extern D_L35_001DE9F8_003A1480, 4");
__asm__(".extern D_L35_001DEA04_003A1480, 4");
__asm__(".extern D_L35_001DEA00_003A1480, 4");
__asm__(".extern D_L35_001DE9EC_003A1480, 4");
__asm__(".extern D_L35_001DE9E0_003A1480, 4");
extern void func_L35_003A1EA8(u8 *);
extern void func_L35_003A1C50(u8 *);
extern void func_L35_003A1F78(u8 *);
extern void func_L35_003A1BE8(u8 *);
extern void func_L01_00441FB8(u8 *moby, s32 a, s32 b);
extern s32 func_L01_00452EC8(u8 *);
extern void func_003BF838(void *, void *, void *, void *);
extern s32 func_L01_004A72A8(s32, s32, u8 *, s32);
extern void func_L01_00452F40(void *, s32);
extern void func_L01_004A6DF8(void *, s32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern f32 func_L03_0034A880(s32, s32, s32, f32, f32, f32);
extern s32 func_L30_0034C9F8_003A1480(void *, f32);
extern void func_L30_0034B9C8(void *, void *);
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern s32 func_00388398(void *);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_0044B598(void *, s32);

void func_L35_003A1480(u8 *a0) {
    u8 *s2 = *(u8 **)(a0 + 0x68);
    vu0_v4 pos = *(vu0_v4 *)(a0 + 0x10);
    vu0_v4 rot = *(vu0_v4 *)(a0 + 0xF0);
    vu0_v4 d;
    vu0_v4 v;
    vu0_v4 a;
    u8 *p;
    s32 i;
    f32 f;
    u8 *g;
    u8 *tbl;

    switch (a0[0x20]) {
    case 0:
        func_L35_003A1EA8(a0);
        func_L01_00441FB8(a0, 1, -1);
        break;
    case 1:
        if (func_L01_00452EC8(a0) != 0) {
            a0[0x23] = 0x80;
        }
        if (*(s32 *)(s2 + 0x98) != 0) {
            g = D_001A4BE0;
            if (*(f32 *)(g + 0x88) < *(f32 *)(a0 + 0x18) && *(u8 **)(g + 0x35C) != a0) {
                *(s32 *)(a0 + 0x98) = 0;
            } else {
                *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
            }
        } else {
            *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
        }
        func_L35_003A1C50(a0);
        vec_sub_ba(&d, a0 + 0x10, &pos);
        func_003BF838(s2 + 0x30, &d, &rot, a0 + 0xF0);
        break;
    case 2:
        if (func_L01_00452EC8(a0) != 0) {
            func_L01_004A72A8(1, 0, a0, 0x1D64);
            if (*(void **)(s2 + 0xA4) != 0) {
                func_L01_00452F40(*(void **)(s2 + 0xA4), 1);
            }
            *(s32 *)(s2 + 0xB0) = D_L35_001DE9E8_003A1480;
            D_L35_001E1DE4 = D_L35_001DE9D0_003A1480;
            *(s32 *)(a0 + 0x98) = 0;
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
            func_L01_004A6DF8(a0, 1);
            func_L01_0044ED60(a0, 7, D_L35_001D66B0_003A1480, 3.0f, 5.0f, 3.0f, 5.0f, 0xFF, 25.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        }
        *(f32 *)(s2 + 0xB4) = func_L03_0034A880(1, 0, 0, (f32)*(s32 *)(s2 + 0xB0), (f32)D_L35_001DE9E8_003A1480, 1.0f);
        if (func_L30_0034C9F8_003A1480(a0 + 0x10, 1.2f) != 0) {
            func_L30_0034B9C8(&D_L35_001E1DE0, a0);
        }
        tbl = D_L35_0021F2D8;
        for (i = 0; i < 10; i++) {
            func_0037E2F0(&a, 0.02500000223517418f, 0.05000000447034836f);
            func_0037E2F0(&v, 0.0f, 1.5f);
            vec_add_ab(&v, &v, a0 + 0x10);
            p = func_L01_00472438(&v, &a, 0x1E, func_0037E208(-3, 3), 0x7FFFF38F, 0x10FFF38F, 63000.004f, 42000.0f, 20.0f, 0);
            if (p != 0) {
                p[2] = func_0037E1D8(3) != 0 ? (*(u8 **)(tbl + 0x1FC))[func_0037E208(1, 3)] : **(u8 **)(tbl + 0xD4);
                p[3] = func_0037E1D8(2) != 0 ? 0x44 : 0x48;
            }
        }
        if (*(s32 *)(s2 + 0x98) == 0 && *(s32 *)(s2 + 0xB0) < D_L35_001DE9E8_003A1480 - D_L35_001DE9F8_003A1480) {
            func_L35_003A1F78(a0);
        }
        if (func_00388398(s2 + 0xB0) != 0) {
            func_L35_003A1BE8(a0);
        }
        break;
    case 3:
        if (func_L01_00452EC8(a0) != 0) {
            *(s32 *)(a0 + 0x98) = 0;
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
            func_L01_004A6DF8(a0, 1);
            *(s32 *)(s2 + 0xB0) = D_L35_001DEA04_003A1480;
        }
        if (func_00388398(s2 + 0xB0) != 0) {
            func_L01_00441FB8(a0, 4, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(a0) != 0) {
            u8 *m = *(u8 **)(a0 + 0x24);
            s32 n = D_L35_001DEA00_003A1480 - 1;
            *(u16 *)(a0 + 0x34) &= 0xFFBE;
            *(u16 *)(a0 + 0x34) |= *(u16 *)(m + 0x44) & 0x1000;
            *(s32 *)(a0 + 0x98) = *(s32 *)(m + 0x10);
            *(s32 *)(s2 + 0xB0) = n;
        }
        f = func_L03_0034A880(1, 0, 0, (f32)*(s32 *)(s2 + 0xB0), (f32)D_L35_001DEA00_003A1480, 1.0f);
        *(f32 *)(s2 + 0xB4) = f;
        a0[0x23] = (s32)(f * 128.0f);
        func_L01_0044B598(a0, func_003894A0(0x8000C4C4, 0x80808080, *(f32 *)(s2 + 0xB4)));
        if (*(f32 *)(s2 + 0xB4) > D_L35_001DE9EC_003A1480) {
            *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
        } else {
            *(s32 *)(a0 + 0x98) = 0;
        }
        if (func_00388398(s2 + 0xB0) != 0) {
            *(s32 *)(s2 + 0x90) = D_L35_001DE9E0_003A1480;
            func_L01_00441FB8(a0, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L35_003A1480 */
