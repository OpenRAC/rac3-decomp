#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L20_003E5C28 */
typedef int u128_t __attribute__((mode(TI)));
extern f32 D_001DF1B8_sda_003E5C28;
__asm__(".extern D_001DF1B8_sda_003E5C28, 4");
extern s32 D_001DF1B0_sda;
__asm__(".extern D_001DF1B0_sda, 4");
extern s32 D_001DF1B4_sda;
__asm__(".extern D_001DF1B4_sda, 4");
extern f32 D_001DF1BC_sda_003E5C28;
__asm__(".extern D_001DF1BC_sda_003E5C28, 4");
extern f32 D_001DF1C0_sda_003E5C28;
__asm__(".extern D_001DF1C0_sda_003E5C28, 4");
extern f32 D_001DF1C4_sda_003E5C28;
__asm__(".extern D_001DF1C4_sda_003E5C28, 4");
extern u32 D_001DF1C8_sda_003E5C28;
__asm__(".extern D_001DF1C8_sda_003E5C28, 4");
extern u32 D_001DF1CC_sda_003E5C28;
__asm__(".extern D_001DF1CC_sda_003E5C28, 4");
extern u8 D_L20_001E2E00[];
extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_003D3FA0(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);
extern void func_00389158(void *, void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_004084B0(u128_t *a, u128_t *b, s32 c, s32 d, u32 c0, u32 c1, u32 c2, u32 c3, f32 e, f32 f, f32 g);

void func_L20_003E5C28(u8 *a0) {
    f32 d[4] __attribute__((aligned(16)));
    f32 e[4] __attribute__((aligned(16)));
    f32 g[4] __attribute__((aligned(16)));
    u8 *p;
    s32 col;
    s32 i;
    f32 nb;
    f32 pf;

    p = *(u8 **)(a0 + 0x68);
    col = func_003894A0(D_001DF1B0_sda, D_001DF1B4_sda, func_00388978(D_001DF1B8_sda_003E5C28) * 0.5f + 0.5f);
    nb = func_00389380(D_001DF1B8_sda_003E5C28, func_0037E250(D_001DF1BC_sda_003E5C28, D_001DF1C0_sda_003E5C28) * 0.017453292f * 0.016666668f);
    pf = *(f32 *)p;
    D_001DF1B8_sda_003E5C28 = nb;
    func_003D3FA0(a0 + 0x10, 0x43, col, 1, 2.25f, -0.1f, pf);
    func_003D3FA0(a0 + 0x10, 0x31, 0x7FFFFFFF, 1, 1.0f, 0.0f, -*(f32 *)(p + 4));
    func_003D3FA0(a0 + 0x10, 0x4B, 0x7FFFFFFF, 3, 2.0f, 0.025f, -*(f32 *)p);
    for (i = 0; i < 12; i++) {
        vec_sub_ab(d, D_L20_001E2E00, a0 + 0x10);
        func_00389158(p + 0xC50 + i * 0x10, p + 0xC50 + i * 0x10, d, *(f32 *)(p + 0xD10 + i * 4));
        *(f32 *)(p + 0x2C) = *(f32 *)(p + 0x2C) + 0.03f;
        if (*(f32 *)(p + 0x2C) > 2.5f) {
            *(f32 *)(p + 0x2C) = 2.5f;
        }
        func_00388830(p + 0xC50 + i * 0x10, p + 0xC50 + i * 0x10, *(f32 *)(p + 0x2C));
        vec_add_ab(e, p + 0xC50 + i * 0x10, a0 + 0x10);
        *(u128_t *)g = *(u128_t *)(a0 + 0x10);
        func_L01_004084B0((u128_t *)e, (u128_t *)g, 0x12, 1, D_001DF1C8_sda_003E5C28, D_001DF1C8_sda_003E5C28, D_001DF1CC_sda_003E5C28, D_001DF1CC_sda_003E5C28, D_001DF1C4_sda_003E5C28, 3.0f, *(f32 *)(p + 0xD40));
    }
    *(f32 *)(p + 0xD40) = *(f32 *)(p + 0xD40) - func_0037E250(0.025f, 0.035f);
    if (*(f32 *)(p + 0xD40) <= -8.0f) {
        *(f32 *)(p + 0xD40) = *(f32 *)(p + 0xD40) + 8.0f;
    }
}
/* localdecomp:end func_L20_003E5C28 */
