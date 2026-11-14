#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L16_003E2C88 (src/levels/16_kerwan/L16_003E2518.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L16_003E0EB0 */
extern void func_L01_00440A88(f32 *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, f32, f32, s32, f32);
extern u8 *D_L16_002206D8[];

void func_L16_003E0EB0(u8 *obj, u128_t *vec)
{
    f32 buf[4];
    f32 pos[4];
    s32 i;
    f32 f20;
    s32 a2;
    u8 *r;

    *(u128_t *)pos = *vec;
    pos[2] = *(f32 *)(obj + 0x18) + 1.179f;
    for (i = 1; i >= 0; i--) {
        func_L01_00440A88(buf, 0.033333335f, 0.058333337f);
        f20 = fabs_asm(buf[2]);
        buf[2] = f20 + func_0037E250(1.0f, 2.5f) * 0.016666668f;
        f20 = func_0037E250(0.08f, 0.14f);
        a2 = func_0037E208(0x5A, 0x96);
        r = func_L01_0046DCB8(pos, buf, a2, 0x827770, -1, 0x7F, 0x7F, f20 * 210000.0f, f20 * 210000.0f, 0, 0.0026666669f);
        if (r != 0) {
            r[2] = D_L16_002206D8[0x61][func_0037E1D8(3) + 0xA];
            r[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L16_003E0EB0 */
