#include "common.h"

/* localdecomp:start func_L01_003E1748 */
extern f32 D_001DF660_sda;
__asm__(".extern D_001DF660_sda, 4");
extern f32 D_001DF668_sda;
__asm__(".extern D_001DF668_sda, 4");
extern f32 D_001DF66C_sda;
__asm__(".extern D_001DF66C_sda, 4");
extern s32 D_001DF670_sda;
__asm__(".extern D_001DF670_sda, 4");
extern f32 D_001DF674_sda;
__asm__(".extern D_001DF674_sda, 4");
extern s32 D_001DF678_sda;
__asm__(".extern D_001DF678_sda, 4");
extern s32 D_001DF67C_sda;
__asm__(".extern D_001DF67C_sda, 4");
extern u8 *D_L01_00221118[];

extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L01_003E1748(f32 scale, u8 *obj, s32 count) {
    u8 loc[0x10];
    u8 *r;
    s32 k;
    s32 i;
    s32 c1;
    s32 c2;
    f32 s1;
    f32 s2;

    func_0037E2F0(loc, D_001DF660_sda * 0.5f * 0.016666668f, D_001DF660_sda * 0.016666668f);
    for (i = 0; i < count; i++) {
        func_0037E2F0(loc, D_001DF668_sda * 0.5f * 0.016666668f, D_001DF668_sda * 0.016666668f);
        k = func_0037E208(-1, 1);
        if (func_0037E1D8(2) != 0) {
            c1 = D_001DF678_sda;
        } else {
            c1 = D_001DF67C_sda;
        }
        c2 = D_001DF67C_sda;
        s1 = D_001DF66C_sda * scale;
        s2 = s1 * 0.35f;
        r = func_L01_00472438(obj, loc, D_001DF670_sda, k, c1, c2 & 0xFFFFFF, s1 * 210000.0f, s2 * 210000.0f,
                              func_0037E250(D_001DF674_sda * 0.6f, D_001DF674_sda), 0);
        if (r != 0) {
            r[9] = 0xF2;
            r[3] = 0x44;
            r[2] = func_0037E1D8(6) != 0 ? *D_L01_00221118[0x10 / 4] : D_L01_00221118[0x184 / 4][3];
        }
    }
}
/* localdecomp:end func_L01_003E1748 */
