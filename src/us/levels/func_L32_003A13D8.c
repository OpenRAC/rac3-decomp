#include "common.h"

/* NTSC-U counterpart of func_L32_003A2C30 (src/levels/32_vidcomic_4/L32_003A2508.c) */
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);

/* localdecomp:start func_L32_003A13D8 */
typedef struct V_003A2C30 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003A2C30;

extern f32 D_L32_001DE85C_003A13D8;
__asm__(".extern D_L32_001DE85C_003A13D8, 4");
extern s32 D_L32_001DE860_003A13D8;
__asm__(".extern D_L32_001DE860_003A13D8, 4");
extern s32 D_L32_001DE864_003A13D8;
__asm__(".extern D_L32_001DE864_003A13D8, 4");
extern f32 D_L32_001DE868_003A13D8;
__asm__(".extern D_L32_001DE868_003A13D8, 4");
extern f32 D_L32_001DE86C_003A13D8;
__asm__(".extern D_L32_001DE86C_003A13D8, 4");
extern f32 D_L32_001DE874;
__asm__(".extern D_L32_001DE874, 4");
extern s32 D_L32_001DE878_003A13D8;
__asm__(".extern D_L32_001DE878_003A13D8, 4");
extern f32 D_L32_001DE880_003A13D8;
__asm__(".extern D_L32_001DE880_003A13D8, 4");
extern s32 D_L32_001DE888_003A13D8;
__asm__(".extern D_L32_001DE888_003A13D8, 4");
extern u8 *D_L32_0021F918_003A13D8[];
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_003D72E0(void *, void *, f32, s32, f32, s32, f32, s32, s32, s32, s32);
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern s32 func_0037E1D8(s32);

void func_L32_003A13D8(void *arg0, void *arg1, s32 count, s32 arg3, f32 scale) {
    V_003A2C30 v;
    u8 *p;
    s32 i;
    s32 r;
    f32 size;

    func_003886E8(&v, arg1, func_0037E250(D_L32_001DE85C_003A13D8 * 0.5f, D_L32_001DE85C_003A13D8) * 0.016666668f);
    func_L01_003D72E0(arg0, &v, -100000.0f, D_L32_001DE864_003A13D8, scale * D_L32_001DE868_003A13D8, 7,
                      D_L32_001DE880_003A13D8, 5, D_L32_001DE860_003A13D8, arg3, 0);
    for (i = 0; i < count; i++) {
        func_0037E2F0(&v, D_L32_001DE86C_003A13D8 * 0.5f * 0.016666668f, D_L32_001DE86C_003A13D8 * 0.016666668f);
        r = func_0037E208(-2, 2);
        size = D_L32_001DE874 * scale * 210000.0f;
        p = func_L01_00472438(arg0, &v, D_L32_001DE878_003A13D8, r, 0x7F407FFF, 0x407FFF, size, size,
                              func_0037E250(D_L32_001DE880_003A13D8 * 0.6f, D_L32_001DE880_003A13D8), 0);
        if (p != 0) {
            p[9] = 0xF2;
            p[3] = func_0037E1D8(D_L32_001DE888_003A13D8) ? 0x44 : 0x48;
            p[2] = D_L32_0021F918_003A13D8[97][3];
        }
    }
}
/* localdecomp:end func_L32_003A13D8 */
