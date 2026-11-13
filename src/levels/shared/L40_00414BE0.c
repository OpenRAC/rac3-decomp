#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_00414BE0);

/* localdecomp:start func_L40_00414C40 */
typedef int u128_00414C40 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x10];
    s16 n0;
    s16 n1;
    s16 n2;
    s16 n3;
    u8 pad18[4];
    s32 *l0;
    s32 *l1;
    s32 *l2;
    s32 *l3;
    u8 pad2C[4];
} S_00414C40;

typedef struct {
    u8 pad0[0x20];
    S_00414C40 e[1];
} H_00414C40;

extern H_00414C40 *D_L40_0024814C;
extern s32 *D_L40_0028FD80[];
extern u8 *D_L40_00248500;
extern u8 *D_L40_0024852C;
extern u8 D_L40_00242930[1];
__asm__(".extern D_L40_00247510, 4");
extern f32 D_L40_00247510;

extern void func_L40_0048FDE8(s32 **paths, s32 *counts, s32 n);
extern s32 func_L40_0048FF90(void *p, s32 a1, f32 a, f32 b);
extern void func_L40_00490080(u8 *p);
extern f32 func_0038CEA8(void *v);
extern s32 func_L40_00490E98(u128_00414C40 *a0, f32 f12, f32 f13, f32 f14);
extern void func_L40_00490F48(S_00414C40 *e, s32 n0, s32 *l0, s32 n1, s32 *l1, s32 n2, s32 *l2, s32 n3, s32 *l3);
extern void func_L40_004910D0(void);
extern s32 func_L01_004450F0(u8 *, s32, s32);

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 pad;
    s32 ids[8];
} V_00414C40;

void func_L40_00414C40(u8 *self) {
    V_00414C40 *vars = *(V_00414C40 **)(self + 0x68);
    s32 *paths[64];
    s32 counts[64];

    switch (self[0x20]) {
    case 0: {
        s32 i;
        s32 n;
        self[0x30] = 0xFF;
        n = D_L40_0024814C->e[vars->a].n0;
        for (i = 0; i < n; i++) {
            paths[i] = D_L40_0028FD80[(D_L40_0024814C->e + vars->a)->l0[i]] + 4;
            counts[i] = *D_L40_0028FD80[(D_L40_0024814C->e + vars->a)->l0[i]];
        }
        func_L40_0048FDE8(paths, counts, n);
    }
    {
        s32 i;
        s32 n = D_L40_0024814C->e[vars->b].n1;
        for (i = 0; i < n; i++) {
            u8 *p = D_L40_00248500 + D_L40_0024814C->e[vars->b].l1[i] * 128;
            func_L40_0048FF90(p + 0x30, 0, *(f32 *)(p + 0x28), *(f32 *)(p + 0x28));
        }
    }
        func_L40_00490080(D_L40_00242930);
        if (vars->c >= 0) {
            s32 i;
            s32 n = D_L40_0024814C->e[vars->c].n3;
            for (i = 0; i < n; i++) {
                f32 f;
                s32 k = D_L40_0024814C->e[vars->c].l3[i] * 128;
                f = func_0038CEA8(D_L40_0024852C + k);
                func_L40_00490E98((u128_00414C40 *)(D_L40_0024852C + k + 0x30), f * 0.2f, f, D_L40_00247510);
            }
        }
    {
        s32 i;
        for (i = 0; i < 8; i++) {
            if (vars->ids[i] != -1) {
                S_00414C40 *e = &D_L40_0024814C->e[vars->ids[i]];
                func_L40_00490F48(e, e->n0, e->l0, e->n1, e->l1, e->n2, e->l2, e->n3, e->l3);
            }
        }
    }
        func_L01_004450F0(self, 1, -1);
        break;
    case 1:
        func_L40_004910D0();
        break;
    }
}
/* localdecomp:end func_L40_00414C40 */
