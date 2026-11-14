#include "common.h"

/* NTSC-U counterpart of func_L30_00342A08 (src/levels/30_vidcomic_unnamed/L30_003417B8.c) */
/* localdecomp:start func_L30_00341D40 */
typedef struct V4_342A08 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_342A08;
extern f32 D_001DCE84_sda;
__asm__(".extern D_001DCE84_sda, 4");
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern u8 *func_L01_004633E8(void *, s32, void *, f32, f32, f32, f32, u32, s32);
extern void func_L01_0046CF70(void *, void *, s32, f32);

void func_L30_00341D40(u8 *obj) {
    V4_342A08 dir = {0.0f, 0.0f, 0.0f, 1.0f};
    V4_342A08 vel = {0.0f, 0.0f, 0.0f, 1.0f};
    V4_342A08 pos;
    s32 i;
    s32 spin;
    u8 *p;
    u8 *q;
    f32 ang;

    for (i = 0; i < 0x30; i++) {
        ang = (f32)i / 48.0f * 6.2831855f;
        dir.x = D_001DCE84_sda * 0.016666668f * func_00388978(ang);
        dir.y = D_001DCE84_sda * 0.016666668f * func_00388960(ang);
        spin = func_0037E208(0, 2) - 1;
        p = func_L01_004633E8(obj + 0x10, spin, &dir, 0.1f, 1.0f, 1.0f, func_0037E250(0.25f, 1.0f) * 210000.0f, 0x207F7F7F, 0);
        if (p != 0) {
            *(s16 *)(p + 0xA) = 0x3C;
            q = p + 0x20;
            *(s32 *)(q + 4) = 2;
            q[0xA] = 0x20;
            q[0xB] = p[0xA];
        }
        if (func_0037E1D8(9) == 0) {
            pos = *(V4_342A08 *)(obj + 0x10);
            vel.x = dir.x * func_0037E250(1.0f, 3.0f);
            vel.y = dir.y * func_0037E250(1.0f, 3.0f);
            vel.z = func_0037E250(1.0f, 4.0f) * 0.016666668f;
            pos.x = pos.x + func_L01_00440918(0.0f, 0.4f);
            pos.y = pos.y + func_L01_00440918(0.0f, 0.4f);
            func_L01_0046CF70(&pos, &vel, func_0037E208(0x14, 0x1E), 0.0f);
        }
    }
}
/* localdecomp:end func_L30_00341D40 */
