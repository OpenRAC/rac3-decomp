/* functional: high. Read line by line against asm; no behavioural difference known. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_0036B870 */
extern u8 D_L05_0028DE00[];
extern s32 D_L05_001E16E0;
extern f32 D_L05_001E16E4;
__asm__(".extern D_L05_001E16E0, 4");
__asm__(".extern D_L05_001E16E4, 4");
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern void func_L05_0036BAD0();

void func_L05_0036B870(u8 *obj) {
    u8 *s = D_L05_0028DE00;
    u8 *p = D_L05_0028DE00 + 0x30;
    s32 i;
    s32 col;
    f32 size;

    for (i = 0; i < 16; i++, s += 0xB0, p += 0xB0) {
        if (*(u8 **)(p + 0x6C) != obj) {
            continue;
        }
        func_L05_0036BAD0(obj, s);
        if (*(s32 *)(p + 0x70) != 0) {
            continue;
        }
        size = func_003824E0(0.125f, 0.25f) * 5.0f;
        func_003D9508(p, 0x39, 0x3F7F0000, 1, size, 1.25f, func_00382538());
        size = func_003824E0(0.0625f, 0.125f) * 5.0f;
        func_003D9508(p, 0x39, 0x5F7F7F7F, 1, size, 1.24f, func_00382538());
        size = func_003824E0(0.15f, 0.35f) * 5.0f;
        func_003D9508(p, 0xB, 0x103F0000, 1, size, 1.23f, 0.0f);
    }
    obj += 0x10;
    col = ((D_L05_001E16E0 + 0x14) << 24) | 0xFF0032;
    func_003D9508(obj, 0x1A, col, 1, D_L05_001E16E4, 0.5f, 0.0f);
    func_003D9508(obj, 0x3D, ((D_L05_001E16E0) << 24) | 0xFF0032, 1, D_L05_001E16E4, 0.5f, 0.0f);
    func_003D9508(obj, 0x3D, ((D_L05_001E16E0) << 24) | 0xFF0032, 1, D_L05_001E16E4 + D_L05_001E16E4, 0.5f, 0.0f);
    D_L05_001E16E4 += 0.3f;
    D_L05_001E16E0 -= 6;
    if (D_L05_001E16E0 < 0) {
        D_L05_001E16E0 = 0;
    }
}
/* localdecomp:end func_L05_0036B870 */
