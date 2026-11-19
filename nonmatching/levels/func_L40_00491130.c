/* func_L40_00491130: 75 diff with the file's flags; 71 with `--as ps2as --mode S` (the float constants then come out as retail's lui/ori/mtc1 instead of $gp pool loads, but the register choice still differs). The struct is 32 bytes (vec at 0x10, n at 0x14). The helper func_L40_00491768 takes (vec*, vec*, int, float): the int is $6 and the float takes $f12 with $7 unused. Still differs: outer-loop register choice (retail keeps i in v1 and the element pointer in s0), and the order of the l2 copy and its z update. Tried: caching n and vec in locals (80), the ps2as form (71). */
#include "vu0.h"

typedef struct {
    u8 pad0[16];
    u8 *vec;
    s32 n;
    u8 pad1[8];
} Ent00491130;

extern s32 D_L40_00248620[];
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

    for (i = 0; i < D_L40_00248620[0]; i++) {
        e = &D_L40_00290EE0[i];
        if (e->n - 1 > 0) {
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
