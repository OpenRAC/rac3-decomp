/* near miss (level 11, Obani Moons): 78 diffs with --as ps2as (127 without; the file needs
   @ps2as for its inline float constants, and then the already matched neighbour
   func_L11_003BE100 needs __asm__(".extern D_L11_001DE3D0, 4"); added to keep its $gp load --
   with that line it matches under both assemblers). The epilogue, the prologue word count,
   both float loops and the inner 3-call loop are retail's. One value is missing from the
   entry block: retail hoists addiu $s7, $gp, 0x1B10 (the address of the 16-byte
   D_001DE3C0_sda source) into a callee-saved register and keeps it across the outer loop;
   every C form tried (pointer at top, address-of, direct 16-byte global with a ,4 hint,
   u128_t) rematerialises it at the lq instead, which cascades into the register allocation
   (n/i swapped, 12 and 0xF0 places) and the loop-alignment nop. Older attempts: a local table
   pointer, a local source pointer, storing the loaded flag instead of 1. */
#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BDED0;

__asm__(".extern D_001DE3C0_sda, 4");
__asm__(".extern D_001E1160_sda, 4");
__asm__(".extern D_L11_001E1160, 16");
__asm__(".extern D_L11_001E5AF4, 16");

extern V4_3BDED0 D_L11_001E1120[];
extern u8 D_L11_001E1720[];
extern s32 D_L11_001E1168[];
extern V4_3BDED0 D_L11_001E1150;
extern s32 D_L11_001E1160;
extern s32 D_001E1160_sda;
extern s32 D_L11_001E5AF4;
extern s32 D_001DE3C0_sda;

extern void func_0038D570(void *, void *);
extern s32 func_00382468(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D9740(void *, s32, s32, s32, s32, f32);

void func_L11_003BDED0(void *unused)
{
    s32 i, k, p, n, rem, v;
    s32 *tab = D_L11_001E1168;
    V4_3BDED0 *q = (V4_3BDED0 *)&D_001DE3C0_sda;
    f32 f20, f21;

    func_0038D570(D_L11_001E1120, D_L11_001E1720);
    v = D_L11_001E5AF4;
    if (v == 1) {
        D_L11_001E1160 = v;
        {
            s32 *pp = tab;
            for (i = 0; i < 10; i++)
                *pp++ = func_00382468(0x14) * 12;
        }
        v = D_L11_001E1160;
    } else {
        v = D_001E1160_sda;
    }
    v++;
    D_001E1160_sda = v;
    if (v >= 120)
        D_L11_001E1160 = 0;

    p = D_L11_001E1160;
    for (i = 0; i < 10; i++) {
        n = p + 12;
        rem = p % 120;
        f21 = (f32)(120 - rem) * 0.2f;
        f20 = (f32)rem * 0.1f;
        for (k = 0; k < 3; k++)
            func_0038CF68(&D_L11_001E1120[k], &D_L11_001E1120[k], f20 + 76.0f);
        D_L11_001E1150 = *q;
        v = tab[i];
        func_003D9740(D_L11_001E1120, 0x1E, ((s32)f21 << 24) | ((240 - v) << 8) | v, 0xA, 1, 0.0f);
        p = n;
        if (n >= 120) {
            p = n - 120;
            tab[i] = func_00382468(0x14) * 12;
        }
    }
}
