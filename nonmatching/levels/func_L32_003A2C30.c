/* NTSC-U draft (2026-11-14, Claude worker): C of func_L32_003A13D8, the NTSC-U twin of func_L32_003A2C30, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "@ps2as" (src/levels/32_vidcomic_4/L32_003A0BB8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L32_003A0BB8-class spark spawner */
/* localdecomp:start func_L32_003A13D8 */
extern f32 D_001DE85C_sda;
__asm__(".extern D_001DE85C_sda, 4");
extern s32 D_001DE860_sda;
__asm__(".extern D_001DE860_sda, 4");
extern s32 D_001DE864_sda;
__asm__(".extern D_001DE864_sda, 4");
extern f32 D_001DE868_sda;
__asm__(".extern D_001DE868_sda, 4");
extern f32 D_001DE86C_sda;
__asm__(".extern D_001DE86C_sda, 4");
extern f32 D_001DE874_sda;
__asm__(".extern D_001DE874_sda, 4");
extern s32 D_001DE878_sda;
__asm__(".extern D_001DE878_sda, 4");
extern f32 D_001DE880_sda;
__asm__(".extern D_001DE880_sda, 4");
extern s32 D_001DE888_sda;
__asm__(".extern D_001DE888_sda, 4");
extern u8 *D_L32_0021F918[];
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_003D72E0(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L32_003A13D8(f32 scale, u8 *obj, void *vec, s32 count, s32 arg) {
    u8 loc[0x10];
    u8 *r;
    s32 k;
    s32 i;
    f32 s1;

    func_003886E8(loc, vec, func_0037E250(D_001DE85C_sda * 0.5f, D_001DE85C_sda) * 0.0166666675f);
    func_L01_003D72E0(obj, loc, D_001DE864_sda, 7, 5, D_001DE860_sda, arg, 0, -100000.0f, scale * D_001DE868_sda, D_001DE880_sda);
    for (i = 0; i < count; i++) {
        func_0037E2F0(loc, D_001DE86C_sda * 0.5f * 0.0166666675f, D_001DE86C_sda * 0.0166666675f);
        k = func_0037E208(-2, 2);
        s1 = D_001DE874_sda * scale * 210000.0f;
        r = func_L01_00472438(obj, loc, D_001DE878_sda, k, 0x7F407FFF, 0x00407FFF, s1, s1, func_0037E250(D_001DE880_sda * 0.6f, D_001DE880_sda), 0);
        if (r != 0) {
            r[9] = 0xF2;
            r[3] = func_0037E1D8(D_001DE888_sda) != 0 ? 0x44 : 0x48;
            r[2] = D_L32_0021F918[0x184 / 4][3];
        }
    }
}
/* localdecomp:end func_L32_003A13D8 */
