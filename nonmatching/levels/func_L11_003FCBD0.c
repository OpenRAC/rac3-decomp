/* near miss (level 11, Obani Moons): the same code as func_L11_003BDED0 with other tables (D_L11_001DEBF0/C20/C30/C38, $gp table D_L11_001D6B20), so the same near miss: with @ps2as on its file (inline lui/ori float constants) the differences are register allocation and loop-invariant hoisting, about 100; without @ps2as 133 (the constants come from .lit4). A match of either ports to the other by renaming the tables */
#include "common.h"

/* localdecomp:start func_L11_003FCBD0 */
typedef int q_3FCBD0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3FCBD0;
extern V4_3FCBD0 D_L11_001DEBF0[];
extern u8 D_L11_001E1720[];
extern q_3FCBD0 D_L11_001DEC20;
extern s32 D_L11_001DEC30;
extern s32 D_L11_001DEC38[10];
extern s32 D_L11_001E5AF4;
extern q_3FCBD0 D_L11_001D6B20[] __attribute__((section(".sdata")));
__asm__(".extern D_L11_001D6B20, 8");
extern void func_0038D570(void *, void *);
extern s32 func_00382468(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D9740(void *, s32, s32, f32, s32, s32);

void func_L11_003FCBD0(void)
{
    s32 i, k, n, r;
    f32 a, b;
    s32 *tab = D_L11_001DEC38;

    func_0038D570(D_L11_001DEBF0, D_L11_001E1720);
    if (D_L11_001E5AF4 == 1) {
        D_L11_001DEC30 = 1;
        for (i = 0; i < 10; i++) {
            tab[i] = func_00382468(20) * 12;
        }
    }
    D_L11_001DEC30++;
    if (D_L11_001DEC30 >= 120) {
        D_L11_001DEC30 = 0;
    }
    n = D_L11_001DEC30;
    for (i = 0; i < 10; i++) {
        r = n % 120;
        a = (f32)r * 0.1f;
        b = (f32)(120 - r) * 0.2f;
        for (k = 0; k < 3; k++) {
            func_0038CF68(&D_L11_001DEBF0[k], &D_L11_001DEBF0[k], a + 76.0f);
        }
        D_L11_001DEC20 = D_L11_001D6B20[0];
        func_003D9740(D_L11_001DEBF0, 0x1E, ((s32)b << 24) | ((240 - tab[i]) << 8) | tab[i], 0.0f, 10, 1);
        n += 12;
        if (n >= 120) {
            tab[i] = func_00382468(20) * 12;
            n -= 120;
        }
    }
}
/* localdecomp:end func_L11_003FCBD0 */
