#include "common.h"

/* NTSC-U counterpart of func_L21_003B1280 (src/levels/21_obani_draco/L21_003B0F18.c) */
#include "vu0.h"
#include "vu0.h"
extern void func_L21_003AF6C8(u8 *arg0);

/* localdecomp:start func_L21_003AF6C8 */
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern u8 D_L21_001D66B0_003AF6C8;
extern u8 *D_L21_0021E6C4[];

void func_L21_003AF6C8(u8 *arg0) {
    u8 *pos;
    s32 life;
    u8 *r;

    pos = arg0 + 0x10;
    life = func_0037E208(0x14, 0x1E);
    r = func_L01_0046DCB8(pos, &D_L21_001D66B0_003AF6C8, life, 0x7FFFFFFF, func_0037E208(-5, 5), 0x4F, 0, 0, 210000.0f, 0.0f, -0.00027777778450399637f);
    if (r != 0) {
        r[2] = D_L21_0021E6C4[0][3];
    }
}
/* localdecomp:end func_L21_003AF6C8 */
