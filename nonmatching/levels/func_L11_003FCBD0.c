/* near miss (level 11, Obani Moons): 63 diff with --as ps2as (122 without). The hoisted
   $gp source is solved: the TImode copy routed through a temp inside a dead
   `do { t = D_001D6B20_sda[0]; } while (0); D_L11_001DEC20 = t;` gives the source-address
   pseudo 6 references instead of 5, enough to outrank the hoisted literal 12 and win $s7
   (retail's `addiu $s7,$gp,-0x5D90` and `lq $v0,0($s7)`). The `0xF0` is kept out of a
   callee-saved register with the dead-second-set recipe (block-local `s32 m; m = 240; ...;
   m = 0;`), so $fp goes to the literal 12 as retail. Also needed: the twin's loop shape
   (p carried, n = p + 12, p = n, p = n - 120) and an explicit pp walk in the first loop.
   Left: prologue scheduling, the flag-test registers, p/i preference ($s1/$s0 vs $s0/$a0),
   and the sq/cvt.w.s order around the lq. The owning file needs @ps2as. No
   div.s/sqrt.s. Twin: func_L11_003BDED0 takes the same two edits. */
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
    s32 i, k, p, n, rem, v;
    s32 *tab = D_L11_001DEC38;
    f32 a, b;
    q_3FCBD0 t;

    func_0038D570(D_L11_001DEBF0, D_L11_001E1720);
    v = D_L11_001E5AF4;
    if (v == 1) {
        s32 *pp;

        D_L11_001DEC30 = 1;
        pp = tab;
        for (i = 0; i < 10; i++)
            *pp++ = func_00382468(0x14) * 12;
    }
    v = D_L11_001DEC30;
    v++;
    D_L11_001DEC30 = v;
    if (v >= 120)
        D_L11_001DEC30 = 0;

    p = D_L11_001DEC30;
    for (i = 0; i < 10; i++) {
        s32 m;

        n = p + 12;
        rem = p % 120;
        b = (f32)(120 - rem) * 0.2f;
        a = (f32)rem * 0.1f;
        for (k = 0; k < 3; k++)
            func_0038CF68(&D_L11_001DEBF0[k], &D_L11_001DEBF0[k], a + 76.0f);
        do { t = D_001D6B20_sda[0]; } while (0);
        D_L11_001DEC20 = t;
        m = 240;
        v = tab[i];
        func_003D9740(D_L11_001DEBF0, 0x1E, ((s32)b << 24) | ((m - v) << 8) | v, 0.0f, 10, 1);
        m = 0;
        p = n;
        if (n >= 120) {
            p = n - 120;
            tab[i] = func_00382468(0x14) * 12;
        }
    }
}
/* localdecomp:end func_L11_003FCBD0 */
