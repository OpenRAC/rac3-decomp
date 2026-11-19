/* func_L05_003B21A8: 85 diff with the file's flags (@ps2as). Retail keeps o in $s5, p=o->0x68 in $s7 and hoists only the 0xFF0000 mask; ours hoists 0x800000FF, the D_L05_001E1D70 address and spills p (frame 0xc0 vs 0xb0). Matrix scratch is 0x40 bytes (position at +0x30) as retail. Tried loop-invariant variants (constant order, p before/after the first call, array size/pointer forms). */
#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
typedef int u128_t __attribute__((mode(TI)));
extern void func_003A9440(s32, unsigned long);
extern s32 func_L05_003B1E80(s32, s32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_003C4C18(void *, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_0040A8C0(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern u128_t D_L05_001E1D70[];

void func_L05_003B21A8(u8 *o) {
    u128_t a, b;
    u128_t m[4];
    s32 i;
    s32 c0, c1;
    u8 *p;
    p = *(u8 **)(o + 0x68);
    func_003A9440(0x47, 0x53001);
    for (i = 0; i < 2; i++) {
        if ((p[0x2BB] >> i) & 1) {
            func_003C2EC0(o, func_L05_003B1E80(i, 1), m);
            a = m[3];
            b = D_L05_001E1D70[i];
            func_003C4C18(&a, 0.035f);
            func_003C4C18(&b, 0.045f);
            c0 = 0x800000FF | (func_00382498(0x2000, 0xFF00) & 0xFF00);
            c0 |= func_00382498(0x200000, 0x600000) & 0xFF0000;
            c1 = 0x80000080 | (func_00382498(0, 0x4000) & 0xFF00);
            c1 |= func_00382498(0, 0x200000) & 0xFF0000;
            func_L01_0040A8C0(&a, &b, 0xE, 1, c0, c0, c1, c1, 0.1f, 1.0f, 0.0f);
        }
    }
}
