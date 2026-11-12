/* near miss (level 11, Obani Moons): 100 positional diffs with @ps2as on its file.
   The logic and instruction supply are retail's: the top `if` is a BNEL whose delay slot is
   the post-if `n = D_L11_001DEC30` load (needed only on the taken path), so `n` must be a
   local read from D_L11_001E5AF4 before the if; the store in the if body is the flag (1).
   Float constants are inline (lui/ori), so the file needs @ps2as (it is missing in
   config/levels/text_parts.txt). What still differs: register allocation (retail keeps n in
   $s0 and i in $a0; this C the other way), the prologue's scheduling, and retail's $gp
   source pointer held in $s7 across the loop (this C recomputes it, so 0xF0 is hoisted into
   $fp instead of 12 and the loop gets one alignment nop). */
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
extern q_3FCBD0 D_001D6B20_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001D6B20_sda, 4");
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
    n = D_L11_001E5AF4;
    if (n == 1) {
        D_L11_001DEC30 = 1;
        for (i = 0; i < 10; i++) {
            tab[i] = func_00382468(20) * 12;
        }
    }
    n = D_L11_001DEC30;
    n++;
    D_L11_001DEC30 = n;
    if (n >= 120) {
        D_L11_001DEC30 = 0;
    }
    n = D_L11_001DEC30;
    for (i = 0; i < 10; i++) {
        r = n % 120;
        b = (f32)(120 - r) * 0.2f;
        a = (f32)r * 0.1f;
        for (k = 0; k < 3; k++) {
            func_0038CF68(&D_L11_001DEBF0[k], &D_L11_001DEBF0[k], a + 76.0f);
        }
        D_L11_001DEC20 = D_001D6B20_sda[0];
        func_003D9740(D_L11_001DEBF0, 0x1E, ((s32)b << 24) | ((240 - tab[i]) << 8) | tab[i], 0.0f, 10, 1);
        n += 12;
        if (n >= 120) {
            tab[i] = func_00382468(20) * 12;
            n -= 120;
        }
    }
}
/* localdecomp:end func_L11_003FCBD0 */
