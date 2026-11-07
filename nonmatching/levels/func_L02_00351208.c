/* Level 02 (Florana), PAL. 2 diff with check.py --target level_02. 2 differences: in the second `if (new30 < f20)` block retail has `addiu $v0,$zero,0xff` before `move $a1,$s2`, this C the other way round; about 8 variants (store/call order, `q` versus `p + 0x160`, a `u8` temp, compare forms) did not change it. Needs `@ps2as` (already set for its file). */
#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_351208;
extern s32 D_001DE4C0_sda;
__asm__(".extern D_001DE4C0_sda, 4");
extern s32 D_L02_001DE4C0;
__asm__(".extern D_L02_001DE4C0, 16");
extern s32 func_L02_003514D0(void *);
extern void func_L02_003516A8(void *);
extern void func_L02_00351780(void *);
extern f32 func_003C3D30(void *, s32, void *, f32);
extern void func_L01_0046A938(void *, s32, s32, f32, f32);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_003C4A40(void *, void *);
extern void func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L02_00351208(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *q;
    f32 f20;
    s32 v;
    s32 h;
    if (a0[0x20] == 0) {
        if (func_L02_003514D0(a0) != 0) return 1;
    }
    if (p[0x3E] == 2) {
        func_L02_003516A8(a0);
        return 1;
    }
    if ((D_001DE4C0_sda & 3) == (((s32)a0 >> 8) & 3)) {
        V4_351208 vec;
        f32 r = func_003C3D30(a0 + 0x10, 0, a0, 2.0f);
        vec = *(V4_351208 *)(a0 + 0x10);
        vec.z = r + 0.2f;
        func_L01_0046A938(&vec, 0, -1, 4.0f, 21000.0f);
    }
    q = p + 0x160;
    f20 = *(f32 *)(p + 0x30);
    if (func_L01_00452FB0(a0, q, 0, 0, 0) != 0) {
        p[0x167] = 0xFF;
        func_003C4A40(a0, q);
        func_L02_00351780(a0);
    }
    if (*(f32 *)(p + 0x30) < f20) {
        p[0x167] = 0xFF;
        func_003C4A40(a0, q);
    }
    func_L01_00452860(a0, p + 0x30, 0);
    if ((*(s16 *)(a0 + 0xB2) + 8) % 8 != D_L02_001DE4C0 % 8) return 0;
    if (p[0x5F] != 0) {
        func_L01_00456BD0(a0, 5);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2C0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2C8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2CC), 10.0f, 1.0f);
        }
    } else {
        func_L01_00456BD0(a0, 3);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2C8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2CC), 10.0f, 1.0f);
        }
    }
    return 0;
}
