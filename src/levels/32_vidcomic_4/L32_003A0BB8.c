#include "common.h"
#include "vu0.h"


/* localdecomp:start func_L32_003A0BB8 */
__asm__(".extern D_L32_001DE6D4, 4");
__asm__(".extern D_L32_001DE6C8, 4");
extern f32 D_L32_001DE6D4;
extern f32 D_L32_001DE6C8;
void func_L32_003A25B0(void *, f32, f32);
void func_L32_003A2508(void *, s32, f32);
void func_L32_003A14C8(void *, s32);

void func_L32_003A0BB8(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    func_L32_003A25B0(arg0, D_L32_001DE6D4, D_L32_001DE6C8);
    func_L32_003A2508(arg0, 0, 0.0f);
    if (p[0x228] != 0) {
        func_L32_003A14C8(arg0, 1);
    }
}
/* localdecomp:end func_L32_003A0BB8 */

/* localdecomp:start func_L32_003A0C18 */
/* func_L32_003A0C18: the file is @ps2as; the gp-relative scalars carry `.extern X, 4` hints (Ps2EeAs
   only uses $gp for a symbol whose size it already knows), D_L32_001E2280/D_L32_001E22A0 are declared
   8 bytes (retail's adjacent lui/addiu `la`), and *(s32 *)(c + 0x68) is read before the null tests. */
typedef int u128_t __attribute__((mode(TI)));
__asm__(".extern D_L32_001DE75C, 4");
__asm__(".extern D_L32_001DE734, 4");
__asm__(".extern D_L32_001DE73C_003A0C18, 4");
__asm__(".extern D_L32_001DE738, 4");
__asm__(".extern D_L32_001DE744, 4");
__asm__(".extern D_L32_001DE740_003A0C18, 4");
__asm__(".extern D_L32_001DE74C, 4");
__asm__(".extern D_L32_001DE770, 4");
__asm__(".extern D_L32_001DE754, 4");
__asm__(".extern D_L32_001DE750, 4");
__asm__(".extern D_L32_001DE758, 4");
__asm__(".extern D_L32_001DE774, 4");
__asm__(".extern D_L32_001DE778, 4");
__asm__(".extern D_L32_001DE748, 4");

extern u8 D_L32_001E2280[8];
extern u8 D_L32_001E22A0[8];
extern u8 *D_L32_0021FAF8[];
extern f32 D_L32_001DE75C; extern s32 D_L32_001DE734; extern s32 D_L32_001DE73C_003A0C18; extern s32 D_L32_001DE738;
extern s32 D_L32_001DE744; extern s32 D_L32_001DE740_003A0C18; extern u8 D_L32_001DE74C; extern s32 D_L32_001DE770;
extern f32 D_L32_001DE754; extern f32 D_L32_001DE750; extern f32 D_L32_001DE758; extern f32 D_L32_001DE774;
extern f32 D_L32_001DE778; extern f32 D_L32_001DE748;
void func_L30_0034C958(void *, f32);
s32 func_0038DBD8(f32, s32, s32);
f32 func_003824E0(f32, f32);
f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
f32 func_003C4088(f32, f32, f32);

void func_L32_003A0C18(u8 *a, u8 *b) {
    if (b != 0) {
        u8 *c = *(u8 **)b;
        u8 *arr = D_L32_001E2280;
        s32 v68 = *(s32 *)(c + 0x68);
        if (c != 0 && v68 != 0 && arr != 0) {
            f32 f22, f20;
            if (b[9] & 1) {
                *(u128_t *)(a + 0x20) = *(u128_t *)D_L32_001E22A0;
                do {
                    func_L30_0034C958(a + 0x20, D_L32_001DE75C);
                    *(s32 *)(a + 0xC) = D_L32_001DE734;
                    {
                        u16 h = *(u16 *)(b + 0xA);
                        f32 t = (f32)((h & 0xFF0) >> 4) * 0.00390625f;
                        s32 x, y;
                        if (h & 1) { x = D_L32_001DE73C_003A0C18; y = D_L32_001DE738; }
                        else { x = D_L32_001DE744; y = D_L32_001DE740_003A0C18; }
                        *(s32 *)(a + 4) = func_0038DBD8(t, x, y);
                    }
                    a[3] = D_L32_001DE74C;
                } while (0);
                if (func_003824E0(0.0f, 1.0f) < 0.5f) {
                    a[2] = D_L32_0021FAF8[0][D_L32_001DE770];
                }
            }
            f22 = func_L03_0034B440(1, 0, 0, (f32)*(s16 *)(a + 0xA), (f32)(b[8] << 2), 1.0f);
            *(u128_t *)(a + 0x10) = *(u128_t *)(a + 0x20);
            f20 = func_003C4088(D_L32_001DE754, D_L32_001DE750, (f32)(*(u16 *)(b + 0xA) >> 8) * 0.00390625f);
            f20 *= func_003C4088(1.0f, D_L32_001DE758, f22);
            {
                f32 g = D_L32_001DE774;
                f32 g2 = D_L32_001DE778;
                f32 r;
                *(f32 *)(a + 0x18) += f20;
                r = func_003C4088(g, g2, (f32)b[0xA] * 0.00390625f);
                *(f32 *)(a + 0x2C) = D_L32_001DE748;
                *(f32 *)(a + 0x1C) = r * (1.0f - f22);
            }
        }
    }
}
/* localdecomp:end func_L32_003A0C18 */
