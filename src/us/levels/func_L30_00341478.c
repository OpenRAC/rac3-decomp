#include "common.h"

/* NTSC-U counterpart of func_L30_003420E0 (src/levels/30_vidcomic_unnamed/L30_00341D88.c) */
typedef int u128_t __attribute__((mode(TI)));
extern void func_L01_00441FB8(u8 *, s32, s32);
extern f32 D_001A4C60[];

/* localdecomp:start func_L30_00341478 */
#include "vu0.h"
extern f32 D_001A4C60[];
__asm__(".extern D_L30_001DCE64, 4");
extern s32 D_L30_001DCE64;
__asm__(".extern D_L30_001DCE70, 2");
extern s16 D_L30_001DCE70;
__asm__(".extern D_L30_001DCE78, 4");
extern f32 D_L30_001DCE78;
extern u8 D_L30_001D66B0_00341478[8];
extern u8 D_001A4BE0[];
extern s32 func_L01_00452EC8(u8 *);
extern void func_0039FE80(s32, s32, void *);
extern void func_003BD360(void *);
extern void func_L01_004A6DF8(void *, s32);
extern s32 func_L30_0034C9F8_00341478(void *, f32);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L30_00341B30(u8 *);
extern s32 func_L30_00341CB8(u8 *);
extern void func_L30_00341D40(u8 *);
extern f32 func_003887C8(void *, void *);
extern void func_L30_0034BC88(u8 *, s32, s32, s32, u128_t *, s32, f32, f32);
extern s32 func_L01_0032FE90_00341478(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L30_00341938(u8 *);


void func_L30_00341478(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    s32 flags;

    switch (o[0x20]) {
    case 0x42:
        if (func_L01_00452EC8(o)) {
            *(u128_t *)(o + 0x10) = *(u128_t *)(v + 0x50);
            func_0039FE80(2, 0, o);
            flags = *(s32 *)(v + 0x84);
            *(s32 *)(v + 0x84) = flags & ~4;
            if ((flags & 2) || ((v[0x84] ^ 1) & 1)) {
                func_003BD360(o);
                return;
            }
            *(s32 *)(o + 0x98) = 0;
            *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
            func_L01_004A6DF8(o, 1);
        }
        if (func_L30_0034C9F8_00341478(o + 0x10, 1.5f) != 0) {
            flags = *(s32 *)(v + 0x84);
            if (flags & 1) {
                if (flags & 4) {
                u8 *c;
                *(u16 *)(o + 0x34) &= 0xFFBE;
                c = *(u8 **)(o + 0x24);
                *(u16 *)(o + 0x34) |= *(u16 *)(c + 0x44) & 0x1000;
                *(s32 *)(o + 0x98) = *(s32 *)(c + 0x10);
                func_L01_00441FB8(o, 0, -1);
                }
            }
        } else {
            *(s32 *)(v + 0x84) |= 4;
        }
        break;
    case 1:
        if (func_L01_00452EC8(o) && o[0x43] != 1) {
            func_003BE4F0(o, 1, 0, D_L30_001DCE64);
        }
        func_L30_00341B30(o);
        if (func_L30_00341CB8(o)) {
            func_L30_00341D40(o);
            func_L01_00441FB8(o, 3, -1);
        }
        break;
    case 2:
        if (func_L01_00452EC8(o) && o[0x43] != 5) {
            func_003BE4F0(o, 5, 0, D_L30_001DCE64);
        }
        if (fabs_asm(D_001A4C60[0] - *(f32 *)(o + 0x10)) <= *(f32 *)(v + 0x78)) {
            func_L01_00441FB8(o, 1, -1);
        }
        break;
    case 0:
        if (*(s16 *)(v + 4) <= 0) {
            *(s16 *)(v + 4) = D_L30_001DCE70;
        }
        *(s16 *)(v + 0x4C) = 4;
        *(s16 *)(v + 0x4E) = 0xF;
        *(f32 *)v = (f32)*(s16 *)(v + 4);
        *(u128_t *)(v + 0x50) = *(u128_t *)(o + 0x10);
        *(f32 *)(v + 0x70) = *(f32 *)(o + 0x2C) * 1.6f / *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
        *(f32 *)(v + 0x74) = *(f32 *)(o + 0x2C) * 1.6f / *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
        *(s32 *)(v + 0x80) = 0;
        if (*(s32 *)(v + 0x84) & 2) {
            func_L01_00441FB8(o, 5, -1);
        } else {
            qzero(v + 0x60);
            func_L01_00441FB8(o, 2, -1);
        }
        break;
    case 3:
        if (func_L01_00452EC8(o) && o[0x43] != 2) {
            func_003BE4F0(o, 2, 0, D_L30_001DCE64);
        }
        if (o[0x60] & 2) {
            func_L01_00441FB8(o, 4, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(o) && o[0x43] != 4) {
            func_003BE4F0(o, 4, 0, D_L30_001DCE64);
        }
        {
            f32 t = *(f32 *)(v + 0x60);
            *(f32 *)(v + 0x60) = D_001A4C60[0] < *(f32 *)(o + 0x10) ? t - D_L30_001DCE78 : t + D_L30_001DCE78;
        }
        func_L30_00341B30(o);
        if (func_003887C8(D_001A4BE0 + 0x80, o + 0x10) < *(f32 *)(v + 0x7C)) {
            func_L30_0034BC88(o, (s32)D_L30_001D66B0_00341478, 1, -1, 0, 0, (f32)v[0x14], *(f32 *)(v + 0x7C) * 1.5f);
            func_L01_0032FE90_00341478(o + 0x10, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, *(f32 *)(v + 0x7C) / 3.0f, 1.0f, 0.0f, 0.0f,
                              1, 1, 0, 0, 1, 1, 0, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                              0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_00441FB8(o, 0x42, -1);
        }
        break;
    case 5:
        func_L01_00452EC8(o);
        func_L01_00441FB8(o, 1, -1);
        break;
    }
    func_L30_00341938(o);
}
/* localdecomp:end func_L30_00341478 */
