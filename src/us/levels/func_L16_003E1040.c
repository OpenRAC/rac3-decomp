#include "common.h"

/* NTSC-U counterpart of func_L16_003E2E30 (src/levels/16_kerwan/L16_003E2518.c) */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
#include "vu0.h"
extern void func_L01_00440A88(f32 *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);

/* localdecomp:start func_L16_003E1040 */
extern u8 D_L16_002206D8_003E1040[];
extern s32 D_001DF400_sda_003E1040;
__asm__(".extern D_001DF400_sda_003E1040, 4");
extern void func_L01_00440A88(f32 *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L16_003E1040(u8 *a0, u128_t *a1) {
    f32 v[4];
    vu0_v4 pos;
    u8 *r;
    s32 i;

    *(u128_t *)&pos = *a1;
    pos.z = *(f32 *)(a0 + 0x18) + 1.179f;
    func_L01_00440A88(v, 0.02500000223517418f, 0.0416666679084301f);
    v[2] = fabs_asm(v[2]) + func_0037E250(0.7f, 1.5f) * 0.01666666753590107f;
    r = func_L01_00472438(&pos, v, func_0037E208(0x5A, 0x96), -1, D_001DF400_sda_003E1040,
                          D_001DF400_sda_003E1040 & 0xFFFFFF, 16800.0f, 16800.0f, 5.6f, 0);
    if (r != 0) {
        r[2] = (*(u8 **)(D_L16_002206D8_003E1040 + 0x184))[func_0037E1D8(3) + 0xA];
        r[3] = 0x44;
    }
    for (i = 0; i < 20; i++) {
        u8 *e;

        func_L01_00440A88(v, 0.0033333336468786f, 0.005833333358168602f);
        v[2] = fabs_asm(v[2]) + func_0037E250(0.3f, 1.1f) * 0.01666666753590107f;
        e = func_L01_00472438(&pos, v, 0x3C, -1, D_001DF400_sda_003E1040, D_001DF400_sda_003E1040 & 0xFFFFFF, 25200.0f, 48300.0f,
                              0.0f, 0);
        if (e != 0) {
            u8 *g = D_L16_002206D8_003E1040;

            e[2] = **(u8 **)(g + 0x10);
            e[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L16_003E1040 */
