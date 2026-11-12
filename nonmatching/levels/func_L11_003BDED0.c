/* near miss (level 11, Obani Moons): about 80-100 differences, measured with @ps2as on the file (its float constants are built inline with lui/ori, which only Ps2EeAs does; func_L11_003BE100 then needs __asm__(".extern D_L11_001DE3D0, 4") to keep its $gp load). The logic and calls are retail's, the differences are register allocation and loop-invariant hoisting: retail keeps &D_L11_001E1168 in $s6, the $gp address of D_L11_001DE3C0 in $s7 and 12 in $fp across the loop, n in $s0 and i in $a0, and reloads 0xF0 each pass; the C hoists 0xF0 and recomputes the $gp address. Tried a local table pointer, a local source pointer, storing the loaded flag instead of 1 */
#include "common.h"

/* localdecomp:start func_L11_003BDED0 */
typedef int q_3BDED0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BDED0;
extern V4_3BDED0 D_L11_001E1120[];
extern u8 D_L11_001E1720[];
extern q_3BDED0 D_L11_001E1150;
extern s32 D_L11_001E1160;
extern s32 D_L11_001E1168[10];
extern s32 D_L11_001E5AF4;
extern q_3BDED0 D_L11_001DE3C0[] __attribute__((section(".sdata")));
__asm__(".extern D_L11_001DE3C0, 8");
extern void func_0038D570(void *, void *);
extern s32 func_00382468(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D9740(void *, s32, s32, f32, s32, s32);

void func_L11_003BDED0(void)
{
    s32 i, k, n, r;
    f32 a, b;
    s32 *tab = D_L11_001E1168;

    func_0038D570(D_L11_001E1120, D_L11_001E1720);
    if (D_L11_001E5AF4 == 1) {
        D_L11_001E1160 = 1;
        for (i = 0; i < 10; i++) {
            tab[i] = func_00382468(20) * 12;
        }
    }
    D_L11_001E1160++;
    if (D_L11_001E1160 >= 120) {
        D_L11_001E1160 = 0;
    }
    n = D_L11_001E1160;
    for (i = 0; i < 10; i++) {
        r = n % 120;
        a = (f32)r * 0.1f;
        b = (f32)(120 - r) * 0.2f;
        for (k = 0; k < 3; k++) {
            func_0038CF68(&D_L11_001E1120[k], &D_L11_001E1120[k], a + 76.0f);
        }
        D_L11_001E1150 = D_L11_001DE3C0[0];
        func_003D9740(D_L11_001E1120, 0x1E, ((s32)b << 24) | ((240 - tab[i]) << 8) | tab[i], 0.0f, 10, 1);
        n += 12;
        if (n >= 120) {
            tab[i] = func_00382468(20) * 12;
            n -= 120;
        }
    }
}
/* localdecomp:end func_L11_003BDED0 */
