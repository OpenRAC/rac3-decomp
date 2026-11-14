#include "common.h"

/* NTSC-U counterpart of func_L24_003A8118 (src/levels/24_insomniac_museum/L24_003A7AA8.c) */
#include "vu0.h"
extern void func_003BD9A0(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern void func_003D3FA0(void *, s32, s32, s32, f32, f32, f32);
extern void func_003BD9A0(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_0037E250(f32, f32);

/* localdecomp:start func_L24_003A6530 */
extern vu0_q D_L24_001E8F60_003A6530;
extern void func_003BD9A0(void *, s32, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L01_004084B0(void *, void *, u32, s32, u32, u32, u32, u32, f32, f32, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern void func_003D3FA0(void *, s32, s32, s32, f32, f32, f32);
extern void *func_L01_0046CF70(void *, void *, s32, f32);

void func_L24_003A6530(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 v[4] __attribute__((aligned(16)));
    f32 r[4] __attribute__((aligned(16)));
    f32 m[16] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    u8 *q;
    f32 x;
    s32 i;

    func_003BD9A0(a0, 0, m);
    *(vu0_q *)v = *(vu0_q *)m;
    func_00388830(v, v, 0.1f);
    q = p + 0x970;
    vec_add_ab(v, v, &m[12]);
    func_00388830(q, m, 10.0f);
    vec_add_ab(q, v, q);
    if (func_003CE740(v, q, 2, a0, 0) != 0) {
        *(vu0_q *)q = D_L24_001E8F60_003A6530;
    }
    *(vu0_q *)w = *(vu0_q *)q;
    func_L01_004084B0(v, w, 0xE, 0, 0x8010104F, 0x8010104F, 0x8010104F, 0x8010104F, (f32)*(s32 *)(p + 0x95C) * 0.1f, 1.0f, 0.0f);
    x = (f32)*(s32 *)(p + 0x95C) * 0.1f + (func_0037E250(0.0f, 0.1f) + 0.5f);
    func_003D3FA0(v, 0x31, 0x8010104F, 0, x, 0.08f, func_0037E2A8());
    x = (f32)*(s32 *)(p + 0x95C) * 0.1f + (func_0037E250(0.0f, 0.2f) + 0.5f);
    func_003D3FA0(q, 0x31, 0x8010104F, 0, x, 0.08f, func_0037E2A8());
    x = (f32)*(s32 *)(p + 0x95C) * 0.1f;
    for (i = 0; i < *(s32 *)(p + 0x95C) + 1; i++) {
        qzero(r);
        r[0] = func_0037E250(-3.0f - x, x + 3.0f) * 0.016666668f;
        r[1] = func_0037E250(-3.0f - x, x + 3.0f) * 0.016666668f;
        r[2] = (func_0037E250(0.0f, 1.0f) + 2.0f) * 0.016666668f;
        func_L01_0046CF70(p + 0x970, r, *(s32 *)(p + 0x95C) * 2 + 15, 4.848137e-06f);
    }
}
/* localdecomp:end func_L24_003A6530 */
