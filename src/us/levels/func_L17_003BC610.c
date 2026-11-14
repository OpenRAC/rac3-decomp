#include "common.h"

/* NTSC-U counterpart of func_L17_003BE338 (src/levels/17_crash_site/L17_003BE210.c) */
extern void func_L17_003BC610();

/* localdecomp:start func_L17_003BC610 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BE338;
extern f32 D_L17_001DE668_003BC610;
extern f32 D_L17_001DE66C_003BC610;
extern s32 D_L17_001DE670_003BC610;
extern s32 D_L17_001DE674_003BC610;
extern f32 D_L17_001DE678;
extern f32 D_L17_001DE67C;
extern f32 D_L17_001DE680;
extern f32 D_L17_001DE684;
extern f32 D_L17_001DE688;
extern f32 D_L17_001DE68C;
extern s32 D_L17_001DE690;
extern s32 D_L17_001DE694;
extern s32 D_L17_001DE698;
extern f32 D_L17_001DE69C;
extern f32 D_L17_001DE6A0;
extern f32 D_L17_001DE6A4;
extern f32 D_L17_001DE6A8;
__asm__(".extern D_L17_001DE668_003BC610, 4");
__asm__(".extern D_L17_001DE66C_003BC610, 4");
__asm__(".extern D_L17_001DE670_003BC610, 4");
__asm__(".extern D_L17_001DE674_003BC610, 4");
__asm__(".extern D_L17_001DE678, 4");
__asm__(".extern D_L17_001DE67C, 4");
__asm__(".extern D_L17_001DE680, 4");
__asm__(".extern D_L17_001DE684, 4");
__asm__(".extern D_L17_001DE688, 4");
__asm__(".extern D_L17_001DE68C, 4");
__asm__(".extern D_L17_001DE690, 4");
__asm__(".extern D_L17_001DE694, 4");
__asm__(".extern D_L17_001DE698, 4");
__asm__(".extern D_L17_001DE69C, 4");
__asm__(".extern D_L17_001DE6A0, 4");
__asm__(".extern D_L17_001DE6A4, 4");
__asm__(".extern D_L17_001DE6A8, 4");
extern void func_003886E8(void *, void *, f32);
extern void func_L01_0044ED60(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L17_003BC610(u8 *self) {
    V4_3BE338 v, pos, dir;
    f32 sx, sy, s;
    s32 i, j;

    func_003886E8(&v, self + 0xE0, 0.08f);
    func_L01_0044ED60(self, 0xFFFF, &v, 0xFF, 0x3C, 0, 0, 0x23, 0, 3,
                      2.0f, 4.0f, D_L17_001DE6A4, D_L17_001DE6A8, -1.0f, 0.0f, 1.0f, 1.0f);
    sy = 1.0f / (f32)D_L17_001DE674_003BC610;
    sx = 1.0f / (f32)D_L17_001DE670_003BC610;
    for (i = 0; i < D_L17_001DE670_003BC610; i++) {
        for (j = 0; j < D_L17_001DE674_003BC610; j++) {
            f32 r;
            pos.x = *(f32 *)(self + 0x10) + (((f32)i + (f32)i) * sx - 1.0f) * D_L17_001DE668_003BC610;
            r = func_0037E250(-D_L17_001DE678, D_L17_001DE678);
            pos.y = *(f32 *)(self + 0x14) + (((f32)j + (f32)j) * sy - 1.0f) * D_L17_001DE66C_003BC610 + r;
            pos.z = *(f32 *)(self + 0x18);
            s = func_0037E250(D_L17_001DE67C, D_L17_001DE680) * 0.0166666675f;
            dir.x = func_0037E250(-1.0f, 1.0f);
            dir.y = func_0037E250(-1.0f, 1.0f);
            dir.z = 0.0f;
            func_00388830(&dir, &dir, s);
            dir.z = func_0037E250(D_L17_001DE684, D_L17_001DE688) * 0.0166666675f;
            func_L01_00472438(&pos, &dir, D_L17_001DE690, 1, D_L17_001DE694, D_L17_001DE698, 0,
                              D_L17_001DE69C * 210000.0f, D_L17_001DE6A0 * 210000.0f, D_L17_001DE68C);
        }
    }
    self[0x31] = 0;
    *(s32 *)(self + 0x98) = 0;
    self[0x20] = 2;
    *(u16 *)(self + 0x34) |= 1;
}
/* localdecomp:end func_L17_003BC610 */
