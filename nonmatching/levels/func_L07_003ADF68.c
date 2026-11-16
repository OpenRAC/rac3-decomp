/* NTSC-U draft (Claude wave C4): C of func_L07_003AC710, the NTSC-U twin of func_L07_003ADF68, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L07_003AC710", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (MATCH) only with the extra -mvu0-use-vf0-vf2 and @ps2as; its PAL counterpart file src/levels/07_annihilation_nation/L07_003ADF68.c has '-O2 -G8 -fopt-stack -mno-check-zero-division' only: COMPILE ERROR with its flags (the vec_add_ba ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003AC710 */
extern u8 D_L07_001D66B0[8];

extern void func_L07_003ACBB8(u8 *);
extern void func_L07_003ACDC0(u8 *);
extern s32 func_003883C8(u8 *);
extern void func_L07_003AD248(u8 *, s32);
extern void func_L07_003AD7B8(u8 *, void *, void *);
extern void func_L01_003B15F8();
extern void func_L07_003AD720(u8 *, void *);
extern void func_L07_003AD858(u8 *, void *, f32);
extern void func_L07_003ADA40(u8 *, s32, f32);
extern s32 func_L07_003AD4C8(u8 *);
extern void func_L07_003AD528(u8 *);
extern s32 func_L07_003308C8(u8 *, u8 *);
extern f32 func_L01_0040C040(void *, void *);
extern void func_L03_0032F420(void *, void *, f32, f32);
extern f32 func_00389380(f32, f32);
extern s32 func_L01_003F9498(void *, s32, u8 *, f32);
extern void func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044ED60(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                              f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                              s32 h, s32 k);
extern void func_L07_00330E70(u8 *);
extern s32 func_0039FE80(s32, s32, void *);

void func_L07_003AC710(u8 *obj) {
    u8 *s;
    vu0_v4 tmp;
    vu0_v4 *q;

    if (obj[0x20] == 0) {
        func_L07_003ACBB8(obj);
    }
    func_L07_003ACDC0(obj);
    s = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 1:
        break;
    case 2:
        if (func_003883C8(s + 0x24E) != 0) {
            func_L07_003AD248(obj, 3);
        }
        break;
    case 3:
        func_L07_003AD248(obj, 4);
        /* fall through */
    case 4:
        func_L07_003AD7B8(obj, s + 0x260, func_L01_003B15F8);
        if (func_L01_0040C040(obj + 0x10, *(u8 **)(s + 0x240) + 0x10) < 484.0f) {
            s[0x25E] = 1;
            func_L07_003AD248(obj, 6);
        }
        break;
    case 6:
        func_L07_003AD528(obj);
        if (func_L07_003308C8(*(u8 **)(s + 0x240), obj) != 0) {
            func_L07_003AD248(obj, 7);
        }
        break;
    case 7:
        if (func_L07_003AD4C8(obj) != 0) {
            func_L03_0032F420(&tmp, s + 0x220, *(f32 *)(s + 0x254), 2.5f);
            func_L07_003AD7B8(obj, &tmp, func_L07_003AD720);
            if (func_L01_0040C040(obj + 0x10, s + 0x220) < 9.0f) {
                func_L07_003AD248(obj, 8);
            }
        }
        break;
    case 8:
        func_L07_003AD7B8(obj, obj + 0x10, func_L01_003B15F8);
        if (func_L07_003AD4C8(obj) != 0) {
            if (obj[0x60] & 2) {
                func_L07_003AD248(obj, 9);
            }
        }
        break;
    case 9:
        func_L07_003AD7B8(obj, obj + 0x10, func_L01_003B15F8);
        *(f32 *)(obj + 0x48) = 1.0f - (f32) * (s16 *)(s + 0x284) / 50.0f;
        if (func_L07_003AD4C8(obj) != 0) {
            if (func_003883C8(s + 0x284) != 0) {
                func_L07_003AD248(obj, 10);
            }
        }
        break;
    case 10:
        if (func_L07_003AD4C8(obj) != 0) {
            func_L07_003AD720(obj, s + 0x220);
            func_L07_003AD858(obj, D_L07_001D66B0, 0.0f);
            func_L07_003ADA40(obj, 0, 0.0f);
            if (func_L01_0040C040(obj + 0x10, s + 0x220) > 225.0f) {
                func_L07_003AD248(obj, 7);
            }
        }
        break;
    case 14:
        *(f32 *)(obj + 0xF8) = func_00389380(*(f32 *)(obj + 0xF8), 1440.0f * 0.017453292f * 0.016666668f);
        q = &tmp;
        vec_add_ba(obj + 0x10, obj + 0x10, s + 0xD0);
        tmp = *(vu0_v4 *)(obj + 0x10);
        tmp.z = tmp.z + 0.8f;
        if (func_003883C8(s + 0x284) != 0 || func_L01_003F9498(q, 0, obj, 0.9f) != 0) {
            func_L01_0032FE90(obj + 0x10, 0, 5, 0xA, 0xA, 3, 0x14, 0, 0.3f, 0.0f, (f32)s[0x135], 1.0f,
                              0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                              0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_0044ED60(obj, 0x1F, D_L07_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23,
                              1.0f, 1.0f, 0, 3);
            func_L07_00330E70(obj);
            func_0039FE80(2, 0, obj);
        }
        break;
    }
}
/* localdecomp:end func_L07_003AC710 */
