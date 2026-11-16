/* NTSC-U draft (Claude wave C4): C of func_L07_003ACDC0, the NTSC-U twin of func_L07_003AE618, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L07_003ACDC0", whose code is not the PAL one).
 * Worker's note: flags: MATCH (native_fix OK, aliases kept: D_L07_001E1EC0_003ACDC0) with '-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as': the 0.34906584f/0.0027222224f/0.3f... constants are lui/ori/mtc1, the PAL file has no @ps2as (the PAL twin func_L07_003AE618 needs ...
 */
#include "common.h"

/* localdecomp:start func_L07_003ACDC0 */
extern u8 D_L07_001D66B0[8];
__asm__(".extern D_L07_001D66B0, 16");
extern u8 D_L07_001E1EC0_003ACDC0[];
extern u8 *func_L01_00444358(void *, s32, s32);
extern s32 func_L01_0044FCD0(void *, void *, s32, s32, s32);
extern void func_L07_00332CB8(s32, f32, f32);
extern void func_L01_0044ED60(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L07_00330E70(void *);
extern f32 func_00388730(void *, void *);
extern f32 func_003887A0(void *);
extern f32 func_00388A28(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_L07_003AD248(void *, s32);
extern void func_L01_004A72A8(s32, s32, void *, s32);
extern void func_L07_00330A18(void *);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);

void func_L07_003ACDC0(u8 *obj) {
    u8 *p;
    u8 *t;
    f32 f;
    f32 g;
    f32 yaw;
    f32 lim;

    p = *(u8 **)(obj + 0x68);
    if (obj[0x20] == 1 || obj[0x20] == 0xE) {
        return;
    }
    f = *(f32 *)(p + 0x120);
    t = func_L01_00444358(obj, 0x10000, 0);
    if (func_L01_0044FCD0(obj, p + 0x160, 0, 0, 0) != 0) {
        func_L07_00332CB8(*(s32 *)(p + 0x240), f, *(f32 *)(p + 0x120));
    }
    if (*(s32 *)(p + 0x108) == 1) {
        func_L01_0044ED60(obj, 0x1F, D_L07_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        func_L01_0032FE90(obj + 0x10, 0, 5, 10, 10, 3, 20, 0, 0.3f, 0.0f, 0.0f, 2.0f, 0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_L07_00330E70(obj);
    } else {
        if (*(f32 *)(p + 0x120) <= 0.0f) {
            if (t != 0 && 0.0f < func_00388730(t + 0x10, t + 0x10)) {
                g = -func_00388A28(func_003887A0(t + 0x10), *(f32 *)(t + 0x18));
                lim = 0.34906584f;
                if (lim < g) {
                    g = lim;
                } else if (g < 0.0f) {
                    g = 0.0f;
                }
                yaw = func_00388A28(*(f32 *)(t + 0x10), *(f32 *)(t + 0x14));
                func_0037E4B8(p + 0xD0, 1.0f, yaw, g);
                func_L07_003AD248(obj, 0xE);
                return;
            }
            func_L01_0032FE90(obj + 0x10, 0, 5, 10, 10, 3, 20, 0, 0.3f, 0.0f, 0.0f, 2.0f, 0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_004A72A8(2, 0, obj, 0x19D2);
            func_L07_00330E70(obj);
            return;
        }
        if (p[0x14E] != 0 || p[0x150] != 0 || p[0x12E] == 2) {
            func_L07_00330E70(obj);
            return;
        }
    }
    func_L07_00330A18(obj);
    if ((u8)(obj[0x20] - 8) < 3) {
        if (*(f32 *)(*(u8 **)(p + 0x240) + 0x18) + 0.5f < *(f32 *)(obj + 0x18)) {
            *(f32 *)(p + 0x280) = *(f32 *)(p + 0x280) + 0.0027222224f;
            *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) - *(f32 *)(p + 0x280);
            if (*(f32 *)(obj + 0x18) < *(f32 *)(*(u8 **)(p + 0x240) + 0x18) + 0.5f) {
                *(f32 *)(obj + 0x18) = *(f32 *)(*(u8 **)(p + 0x240) + 0x18) + 0.5f;
            }
        } else {
            *(s32 *)(p + 0x280) = 0;
        }
    } else {
        *(s32 *)(p + 0x280) = 0;
    }
    if (obj[0x31] != 0) {
        if (func_L01_0040C018(D_L07_001E1EC0_003ACDC0, obj + 0x10) < 576.0f) {
            func_L01_00444188(obj);
            obj[0x6F] = 0x16;
        }
    }
}
/* localdecomp:end func_L07_003ACDC0 */
