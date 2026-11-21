#include "common.h"

/* localdecomp:start func_L13_003B2D80 */
#include "vu0.h"

typedef int u128_003B2D80 __attribute__((mode(TI)));
typedef union { f32 f[0xA80]; u8 b[0x2A00]; } Hero_003B2D80;
extern Hero_003B2D80 D_001A4BE0;
extern u8 D_001A4C60[];
extern u8 D_001A30B0[];
extern f32 D_L13_001DE860;
__asm__(".extern D_L13_001DE860, 4");
extern f32 D_L13_001DE85C;
__asm__(".extern D_L13_001DE85C, 4");
extern f32 D_L13_001DE864;
__asm__(".extern D_L13_001DE864, 4");
extern f32 D_L13_001DE868;
__asm__(".extern D_L13_001DE868, 4");
extern s32 func_L01_0044C108(void *);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004561B8(void *);
extern f32 func_003C3D30(void *, s32, void *, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_0038CAD0(void *);
extern f32 func_003C41A0(f32 *, f32, void *, f32, f32, f32);
extern void func_003C4DA8(void *, void *, void *, void *);

void func_L13_003B2D80(u8 *o) {
    u8 *s;
    vu0_v4 pos0;
    vu0_v4 delta;
    s32 idx;
    s32 idy;
    u8 *e;
    f32 d;
    f32 t;
    f32 lim;
    f32 zt;
    f32 f20;
    f32 ma;
    f32 mb;
    u8 *hp;

    s = *(u8 **)(o + 0x68);
    if (func_L01_0044C108(o + 0x10) == 0) {
        return;
    }
    if (o[0x20] != 0 && *(s32 *)(s + 0xA0) != 0) {
        if (func_L01_00456250(o) == 0) {
            return;
        }
    }
    *(u128_003B2D80 *)&pos0 = *(u128_003B2D80 *)(o + 0x10);
    switch (o[0x20]) {
    case 0:
        *(s32 *)(s + 0x7C) = -1;
        *(s32 *)(s + 0x70) = 1;
        *(s32 *)(s + 0x78) = 0;
        *(f32 *)(s + 0x74) = *(f32 *)(s + 0x74) * *(f32 *)(s + 0x74);
        *(u128_003B2D80 *)(s + 0x80) = *(u128_003B2D80 *)(o + 0x10);
        *(u128_003B2D80 *)(s + 0x90) = *(u128_003B2D80 *)(o + 0x10);
        *(f32 *)(s + 0x98) = func_003C3D30(s + 0x90, 2, o, -0.5f);
        func_L01_004450F0(o, 2, -1);
        break;
    case 2:
        if (func_L01_004561B8(o)) {
            *(u128_003B2D80 *)(o + 0x10) = *(u128_003B2D80 *)(s + 0x80);
            idx = *(s32 *)(s + 0x7C);
            if (idx != -1) {
                e = D_001A30B0 + (idx << 7);
                if (*(u8 **)(e + 0xDC) == o && e[0xD0] != 0) {
                    func_003A4F28(idx);
                }
            }
            *(s32 *)(s + 0x7C) = -1;
        }
        if (fabs_asm(*(f32 *)(s + 0x98) - D_001A4BE0.f[0x88 / 4]) < fabs_asm(*(f32 *)(s + 0x88) - D_001A4BE0.f[0x88 / 4])) {
            func_L01_004450F0(o, 3, -1);
        } else {
            d = func_L01_0040E570(o + 0x10, (u8 *)&D_001A4BE0 + 0x80);
            if (d < *(f32 *)(s + 0x74)) {
                func_0038CAD0(s + 0xA8);
                if (*(s32 *)(s + 0x70) != 0 && *(s32 *)(s + 0xA8) == 0) {
                    func_L01_004450F0(o, 3, -1);
                }
            } else {
                *(s32 *)(s + 0x70) = 1;
                *(s32 *)(s + 0xA8) = (*(s32 *)(s + 0xA4) * 5 + 2) / 6;
            }
        }
        break;
    case 4:
        if (func_L01_004561B8(o)) {
            *(u128_003B2D80 *)(o + 0x10) = *(u128_003B2D80 *)(s + 0x90);
            idx = *(s32 *)(s + 0x7C);
            if (idx != -1) {
                e = D_001A30B0 + (idx << 7);
                if (*(u8 **)(e + 0xDC) == o && e[0xD0] != 0) {
                    func_003A4F28(idx);
                }
            }
            *(s32 *)(s + 0x7C) = -1;
        }
        if (fabs_asm(*(f32 *)(s + 0x88) - D_001A4BE0.f[0x88 / 4]) < fabs_asm(*(f32 *)(s + 0x98) - D_001A4BE0.f[0x88 / 4])) {
            func_L01_004450F0(o, 1, -1);
        } else {
            d = func_L01_0040E570(o + 0x10, (u8 *)&D_001A4BE0 + 0x80);
            if (d < *(f32 *)(s + 0x74)) {
                func_0038CAD0(s + 0xA8);
                if (*(s32 *)(s + 0x70) != 0 && *(s32 *)(s + 0xA8) == 0) {
                    func_L01_004450F0(o, 1, -1);
                }
            } else {
                *(s32 *)(s + 0x70) = 1;
                *(s32 *)(s + 0xA8) = (*(s32 *)(s + 0xA4) * 5 + 2) / 6;
            }
        }
        break;
    case 3:
        if (func_L01_004561B8(o)) {
            idy = *(s32 *)(s + 0x7C);
            if (idy == -1 || (e = D_001A30B0 + (idy << 7), *(u8 **)(e + 0xDC) != o) || e[0xD0] == 0) {
                *(s32 *)(s + 0x7C) = func_003A52A0(0, 4, o);
            }
            *(s32 *)(s + 0x70) = 0;
        }
        f20 = *(f32 *)(s + 0x98);
        hp = D_001A4C60;
        d = func_L01_0040E570(hp, o + 0x10);
        mb = *(f32 *)(o + 0x2C);
        ma = D_L13_001DE860;
        lim = ma * mb / *(f32 *)(*(u8 **)(o + 0x24) + 0x24) + 1.0f;
        if (d < lim * lim) {
            if (*(f32 *)(hp + 8) < *(f32 *)(o + 0x18) - 0.1f) {
                zt = *(f32 *)(hp + 8) + D_L13_001DE85C;
                if (*(f32 *)(s + 0x88) < zt) {
                    f20 = *(f32 *)(s + 0x88);
                } else {
                    f20 = zt;
                }
            }
        }
        func_003C41A0((f32 *)(o + 0x18), f20, s + 0x78, D_L13_001DE864, D_L13_001DE864, D_L13_001DE868);
        if (fabs_asm(*(f32 *)(o + 0x18) - *(f32 *)(s + 0x98)) < 0.001f) {
            func_L01_004450F0(o, 4, -1);
        }
        break;
    case 1:
        if (func_L01_004561B8(o)) {
            idy = *(s32 *)(s + 0x7C);
            if (idy == -1 || (e = D_001A30B0 + (idy << 7), *(u8 **)(e + 0xDC) != o) || e[0xD0] == 0) {
                *(s32 *)(s + 0x7C) = func_003A52A0(0, 4, o);
            }
            *(s32 *)(s + 0x70) = 0;
        }
        func_003C41A0((f32 *)(o + 0x18), *(f32 *)(s + 0x88), s + 0x78, D_L13_001DE864, D_L13_001DE864, D_L13_001DE868);
        if (fabs_asm(*(f32 *)(o + 0x18) - *(f32 *)(s + 0x88)) < 0.001f) {
            func_L01_004450F0(o, 2, -1);
        }
        break;
    }
    if (*(u16 *)(o + 0x96) < 0xFFFF) {
        *(u16 *)(o + 0x96) = *(u16 *)(o + 0x96) + 1;
    }
    vec_sub_ba(&delta, o + 0x10, &pos0);
    func_003C4DA8(s + 0x30, &delta, o + 0xF0, o + 0xF0);
}
/* localdecomp:end func_L13_003B2D80 */
