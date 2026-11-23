#include "common.h"

/* localdecomp:start func_L03_004109D8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t q0;
    u8 pad10[0x10];
    u128_t *list;
    f32 x24;
    f32 x28;
    u8 pad2C[0x14];
    s32 x40[4];
} S_L03_002E5CA0;
typedef struct {
    u8 pad0[0x34];
    s32 frame;
    u8 pad38[0x18];
    S_L03_002E5CA0 *cur;
    u8 pad54[0x1A0 - 0x54];
    s32 tab[1];
} G_004109D8;
typedef struct {
    u128_t v[4];
    u128_t x40;
    s32 start;
    s32 end;
    s32 idx[4];
} A_004109D8;
extern G_004109D8 D_L03_001E6800;
extern S_L03_002E5CA0 D_L03_002E5CA0;
extern u8 D_L03_001D6AD0;
extern u8 D_L03_001D6AC5;
extern f32 func_0038CF38(void *, void *);
extern void func_L01_004234E8(u128_t *, s32 *);
extern void func_L01_00423530(u128_t *, void *);
extern void func_L01_00423580(void);
extern void func_L01_00423690(void);
extern void func_L01_00404808(void *, s32);

void func_L03_004109D8(A_004109D8 *a, s32 *b, void *c, void *d) {
    s32 ok = 1;
    f32 w;
    f32 h;
    s32 i;
    s32 j;

    if (D_L03_001E6800.frame >= (a->start * 5 + 2) / 6 &&
        (a->end * 5 + 2) / 6 >= D_L03_001E6800.frame) {
        w = (func_0038CF38(a, &a->v[2]) + func_0038CF38(&a->v[1], &a->v[3])) * 0.5f;
        h = (func_0038CF38(a, &a->v[1]) + func_0038CF38(&a->v[1], &a->v[2])) * 0.5f;
        if (D_L03_002E5CA0.list == 0) {
            D_L03_002E5CA0.list = (u128_t *)&D_L03_001D6AD0;
        }
        if (h < w) {
            D_L03_002E5CA0.x24 = 1.0f;
            D_L03_002E5CA0.x28 = h / w;
        } else {
            D_L03_002E5CA0.x28 = 1.0f;
            D_L03_002E5CA0.x24 = w / h;
        }
        D_L03_002E5CA0.q0 = a->x40;
        for (i = 0; i < 4; i++) {
            D_L03_002E5CA0.list[i] = a->v[i];
        }
        if (b != 0 && D_L03_001E6800.frame >= (b[0] * 5 + 2) / 6 &&
            (b[1] * 5 + 2) / 6 >= D_L03_001E6800.frame) {
            func_L01_004234E8(D_L03_002E5CA0.list, b);
            func_L01_00404808(func_L01_00423580, 0);
            if (b[5] == 0) {
                ok = 0;
            }
        }
        if (c != 0 && d != 0) {
            func_L01_00423530(D_L03_002E5CA0.list, c);
            func_L01_00404808(func_L01_00423690, 0);
            if (D_L03_001D6AC5 != 0) {
                ok = 0;
            }
        }
    } else {
        ok = 0;
    }
    if (ok && a->idx[0] >= 0) {
        D_L03_001E6800.cur = &D_L03_002E5CA0;
        for (j = 0; j < 4; j++) {
            if (a->idx[j] >= 0) {
                D_L03_001E6800.cur->x40[j] = D_L03_001E6800.tab[a->idx[j]];
            } else {
                D_L03_001E6800.cur->x40[j] = 0;
            }
        }
    } else {
        D_L03_001E6800.cur = 0;
    }
}
/* localdecomp:end func_L03_004109D8 */
