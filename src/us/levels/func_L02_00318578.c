#include "common.h"

/* NTSC-U counterpart of func_L02_00318A28 (src/levels/shared/L02_00318910.c) */
/* localdecomp:start func_L02_00318578 */
typedef int u128_t_00318A28 __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
extern u8 D_L02_0021E158[];
extern u8 D_L02_0026F820[];
extern void func_L02_003B8D00(void *, void *, void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);

void func_L02_00318578(u8 *self, s32 *col) {
    u128_t_00318A28 v[2];
    u8 *st;
    s32 i;
    s32 a;
    f32 f;
    u8 *p;
    u8 *h;
    u8 *g;

    st = *(u8 **)(self + 0x68);
    for (i = 0; i < 24; i++) {
        h = D_001A4BE0;
        func_L02_003B8D00(*(void **)(h + 0x25C0), D_L02_0026F820, &v[0], 0, 0.0f);
        v[1] = *(u128_t_00318A28 *)(self + 0xE0);
        func_00388830(&v[1], &v[1], *(f32 *)(st + 0x14) * 0.033333335f);
        a = (s32)func_L01_00440918(2.0f, 5.0f);
        f = func_0037E250(0.05f, 0.1f);
        func_L01_0046DCB8(&v[0], &v[1], (s32)((f32)func_0037E208(20, 25) * *(f32 *)(st + 0x14)), f * 210000.0f, col[0], a, 0x7F, 0x7F, 2100.0f, -0.00083333335f, 1);
        a = -(a * 2);
        p = func_L01_0046DCB8(&v[0], &v[1], (s32)((f32)func_0037E208(20, 25) * *(f32 *)(st + 0x14)), f * 4.0f * 210000.0f, col[1], a, 0x30, 0x30, 4200.0f, -0.00083333335f, 0);
        if (p != 0) {
            g = D_L02_0021E158;
            p[2] = **(u8 **)(g + 0xD4);
        }
    }
    *(f32 *)(st + 0x14) = *(f32 *)(st + 0x14) + 0.029166669f;
    if (*(f32 *)(st + 0x14) > 1.0f) {
        *(f32 *)(st + 0x14) = 1.0f;
    }
}
/* localdecomp:end func_L02_00318578 */
