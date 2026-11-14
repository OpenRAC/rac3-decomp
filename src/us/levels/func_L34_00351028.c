#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L34_00351D48 (src/levels/34_vidcomic_3/L34_003515A0.c) */
/* localdecomp:start func_L34_00351028 */
extern f32 func_003BEC60(void *, void *, f32, f32, f32, f32);
extern f32 func_L01_00445758(void *, void *, s32, f32, f32, f32, f32);
extern void func_L01_0044B860(void *, void *, void *, f32, f32, f32);
extern void func_L34_00350F48(void *);

void func_L34_00351028(u8 *a0) {
    u8 *d;
    f32 c;

    d = *(u8 **)(a0 + 0x68);
    func_003BEC60(d + 0x148, d + 0x164, (f32)*(s32 *)(d + 0x144) * *(f32 *)(d + 0x178), 0.013888889f, 0.013888889f, 0.0019444445f);
    c = 0.0f;
    if ((f32)*(s32 *)(d + 0x144) < 0.0f) {
        c = 3.1415927f;
    }
    func_L01_00445758(a0 + 0xF8, d + 0x168, 0, c, 0.004848137f, 0.0024240685f, 0.14544411f);
    *(f32 *)(a0 + 0x10) = *(f32 *)(a0 + 0x10) + *(f32 *)(d + 0x148);
    func_L01_0044B860(a0, d + 0x14C, d + 0x150, 0.25f, 0.058177646f, *(f32 *)(d + 0x154));
    *(f32 *)(d + 0x64) = fabs_asm(*(f32 *)(d + 0x148)) * 0.47123888f / *(f32 *)(d + 0x178);
    *(f32 *)(d + 0x60) = -(*(f32 *)(d + 0x168) * 0.5235988f) / 0.14544411f;
    func_L34_00350F48(a0);
}
/* localdecomp:end func_L34_00351028 */
