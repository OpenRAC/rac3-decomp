#include "common.h"

/* declared by functions of L20_003368E0.c, which this file was cut from */
extern s32 D_L20_001DCAB8;
extern void func_L20_00337140(void *);

/* localdecomp:start func_L20_00337140 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x12];
    s16 timer;                  /* 0x12 */
    s32 color;                  /* 0x14 */
    u8 idx[4];                  /* 0x18 */
    u8 pad1C[4];
    vu0_v4 src[4];              /* 0x20 */
    vu0_v4 pos[32];             /* 0x60 */
    vu0_v4 vel[28];             /* 0x260 */
    vu0_v4 grid[4][4];          /* 0x420 */
    vu0_v4 gvel[4][4];          /* 0x520 */
    s32 total;                  /* 0x620 */
} V_00337140;

extern s32 D_L20_001DCAB4;
__asm__(".extern D_L20_001DCAB4, 4");
__asm__(".extern D_L20_001DCAB8, 4");
extern s32 D_L20_001DCAE4;
__asm__(".extern D_L20_001DCAE4, 4");
extern s32 D_L20_001DCAE8;
__asm__(".extern D_L20_001DCAE8, 4");
extern s32 D_L20_001DCAEC;
__asm__(".extern D_L20_001DCAEC, 4");
extern s32 func_0038DBD8(s32, s32, f32);

void func_L20_00337140(void *self) {
    V_00337140 *v = *(V_00337140 **)((u8 *)self + 0x68);
    s32 i;
    s32 k;
    s32 j;

    if (v->timer != 0) {
        v->timer--;
        for (i = 0; i < 23; i++) {
            vec_add_ab(&v->pos[i], &v->pos[i], &v->vel[i]);
        }
        for (i = 0; (f32)i < 4.0f; i++) {
            for (k = 1; k < 4; k++) {
                vec_add_ab(&v->grid[k][i], &v->grid[k][i], &v->gvel[k][i]);
            }
        }
        for (j = 0; j < 4; j++) {
            *(vu0_q *)&v->grid[0][j] = *(vu0_q *)&v->src[v->idx[j]];
        }
    }
    if (D_L20_001DCAB4 < v->timer) {
        v->color = func_0038DBD8(D_L20_001DCAE8, D_L20_001DCAE4,
            (f32)(v->timer - D_L20_001DCAB4) / (f32)(v->total - D_L20_001DCAB4));
    } else if (D_L20_001DCAB8 < v->timer) {
        v->color = func_0038DBD8(D_L20_001DCAEC, D_L20_001DCAE8,
            (f32)(v->timer - D_L20_001DCAB8) / (f32)(D_L20_001DCAB4 - D_L20_001DCAB8));
    } else {
        v->color = 0;
    }
}
/* localdecomp:end func_L20_00337140 */

INCLUDE_ASM("asm/levels", func_L20_003372C8);
