#include "common.h"

/* localdecomp:start func_L11_003FCBD0 */
typedef int q_3FCBD0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3FCBD0;
/* No size hint for the three level tables: gcc treats them as small data (one-insn `la`),
   Ps2EeAs does not know their size and expands each `la` to lui/addiu. */
extern V4_3FCBD0 D_L11_001DEBF0[] __attribute__((section(".sdata")));
extern q_3FCBD0 D_L11_001DEC20[] __attribute__((section(".sdata")));
extern s32 D_L11_001DEC38[] __attribute__((section(".sdata")));
extern u8 D_L11_001E1720[];
extern s32 D_L11_001DEC30;
extern s32 D_L11_001E5AF4[];
extern q_3FCBD0 D_001D6B20_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001D6B20_sda, 4");
extern void func_0038D570(void *, void *);
extern s32 func_00382468(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D9740(void *, s32, s32, f32, s32, s32);

void func_L11_003FCBD0(void)
{
    s32 i, j, k, p, n, rem, v, w, u;
    f32 a, b;

    func_0038D570(D_L11_001DEBF0, D_L11_001E1720);
    v = D_L11_001E5AF4[0];
    if (v == 1) {
        D_L11_001DEC30 = 1;
        for (j = 0; j < 10; j++)
            D_L11_001DEC38[j] = func_00382468(0x14) * 12;
    }
    w = D_L11_001DEC30;
    w++;
    D_L11_001DEC30 = w;
    if (w >= 120)
        D_L11_001DEC30 = 0;

    p = D_L11_001DEC30;
    for (i = 0; i < 10; i++) {
        n = p + 12;
        rem = p % 120;
        b = (f32)(120 - rem) * 0.2f;
        a = (f32)rem * 0.1f;
        for (k = 0; k < 3; k++)
            func_0038CF68(&D_L11_001DEBF0[k], &D_L11_001DEBF0[k], a + 76.0f);
        D_L11_001DEC20[0] = D_001D6B20_sda[0];
        u = D_L11_001DEC38[i];
        func_003D9740(D_L11_001DEBF0, 0x1E, ((s32)b << 24) | ((240 - u) << 8) | u, 0.0f, 10, 1);
        p = n;
        if (n >= 120) {
            p = n - 120;
            D_L11_001DEC38[i] = func_00382468(0x14) * 12;
        }
    }
}
/* localdecomp:end func_L11_003FCBD0 */
