/* func_L40_00491130 (near miss, 65 diff with the file's flags and with `--as ps2as`; 74 before the round-10 rewrite). The float constants are retail's inline
   lui/ori/mtc1, so a match needs `@ps2as` on the file. What fixed 9 diffs: the outer count is a SCALAR with `.extern D_L40_00248620, 16`
   (retail re-reads it with `lui; lw` in the loop test, no hoisted hi), and the `if` reads `D_L40_00290EE0[i].n` from the array while the
   row pointer `e = &D_L40_00290EE0[i]` is assigned inside the `if` (two separate row addresses, as retail has). Still differs: retail keeps the
   `lui 0x29` in $s6 and builds `addiu $s5,$s6,0xee0` and `addiu $s4,$s6,0xee0` itself, the `if` reads `lw 0x14($v1)` from the row address
   (ours folds +0x14 into the hoisted base), and the outer index/stride registers ($s2 = i << 5, $s3 = i + 1). A second row pointer `e2` for the loop
   body gave 71. The helper func_L40_00491768 takes (vec*, vec*, int, float). */
#include "vu0.h"

typedef struct {
    u8 pad0[16];
    u8 *vec;
    s32 n;
    u8 pad1[8];
} Ent00491130;

extern s32 D_L40_00248620;
__asm__(".extern D_L40_00248620, 16");
extern Ent00491130 D_L40_00290EE0[];
extern void func_L40_00491768(void *, void *, s32, f32);

void func_L40_00491130(void)
{
    Ent00491130 *e;
    vu0_v4 l1;
    vu0_v4 l2;
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < D_L40_00248620; i++) {
        if (D_L40_00290EE0[i].n - 1 > 0) {
            e = &D_L40_00290EE0[i];
            j = 0;
            do {
                *(vu0_q *)&l1 = *(vu0_q *)(e->vec + j * 16);
                l1.z = l1.z + 0.05f;
                k = (j + 1) % e->n;
                *(vu0_q *)&l2 = *(vu0_q *)(e->vec + k * 16);
                l2.z = l2.z + 0.05f;
                func_L40_00491768(&l1, &l2, 0x6000FFFF, 0.2f);
                j++;
            } while (j < e->n - 1);
        }
    }
}
