/* functional: high. Draft verified block by block against retail asm (draw-struct layout, constants, callees, loop bounds, vec helper operand order); check.py compiles, remaining diffs are scheduling/register only. */
#include "common.h"
#include "vu0.h"

typedef struct {
    vu0_v4 v[4];
    u32 color[4];
    f32 uv[4][2];
    unsigned long u70, texture, u80, mode;
} Draw_3372C8;
typedef struct {
    u8 pad0[0x14];
    s32 color;
    u8 idx[4];
    u8 pad1C[4];
    vu0_v4 pos[32];
    vu0_v4 vel[32];
    vu0_v4 grid[4][4];
    vu0_v4 gvel[4][4];
    u8 pad620[0x30];
    vu0_v4 rotation;
} Vars_3372C8;
extern s32 D_L20_001DBCA0;
extern vu0_v4 D_L20_001E2E00;
extern s32 D_L20_001DCAD0;
extern s32 D_L20_001DCAD4;
extern s32 D_L20_001DCAD8;
extern s32 D_L20_001DCADC;
extern s32 D_L20_001DCAE0;
__asm__(".extern D_L20_001DCAD0, 4");
__asm__(".extern D_L20_001DCAD4, 4");
__asm__(".extern D_L20_001DCAD8, 4");
__asm__(".extern D_L20_001DCADC, 4");
__asm__(".extern D_L20_001DCAE0, 4");
extern f32 D_L20_001DCAF0[4][2] __attribute__((section(".sdata")));
extern void func_0038D328(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, void *, s32);

static __inline__ void copy_3372C8(void *d, void *s) {
    *(vu0_q *)d = *(vu0_q *)s;
}

static __inline__ s32 valid_3372C8(s32 index) {
    if (index < 31) {
        if (index >= 0) return 1;
    }
    return 0;
}

void func_L20_003372C8(void *self) {
    Draw_3372C8 q[3];
    vu0_v4 matrix[3];
    vu0_v4 position;
    vu0_v4 inverse[4];
    vu0_v4 eye;
    vu0_v4 previous;
    vu0_v4 current;
    vu0_v4 a;
    vu0_v4 b;
    Vars_3372C8 *v;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 k2;
    s32 n;
    long tex;
    unsigned long mode;
    u8 *indices;

    v = *(Vars_3372C8 **)((u8 *)self + 0x68);
    D_L20_001DBCA0 |= 1;
    func_0038D328(matrix, &v->rotation);
    func_0038D5B0(inverse, matrix);
    position = *(vu0_v4 *)((u8 *)self + 0x10);
    vec_sub_ba(&eye, &D_L20_001E2E00, (u8 *)self + 0x10);
    func_0038D000(&eye, &eye, inverse);
    tex = func_00389598(D_L20_001DCAD0);
    mode = (unsigned long)D_L20_001DCAD4
        | ((unsigned long)D_L20_001DCAD8 << 2)
        | ((unsigned long)D_L20_001DCADC << 4)
        | ((unsigned long)D_L20_001DCAE0 << 6)
        | (0x8000L << 24);
    q[0].u80 = q[1].u80 = q[2].u80 = 0xFF9000000260UL;
    q[0].texture = q[1].texture = q[2].texture = tex;
    q[0].u70 = q[1].u70 = q[2].u70 = 0;
    q[0].mode = q[1].mode = q[2].mode = mode;
    for (n = 0; n < 4; n++) {
        q[0].uv[n][1] = q[1].uv[n][1] = q[2].uv[n][1] = D_L20_001DCAF0[n][1];
        q[0].color[n] = q[1].color[n] = q[2].color[n] = v->color;
    }
    indices = v->idx;
    qzero(&current);
    for (j = 0; j < 31; j++) {
        previous = current;
        if (j < 30) {
            vec_sub_ab(&b, &v->pos[j], &v->pos[j+2]);
            vec_sub_ab(&a, &v->pos[j+1], &eye);
            func_0038CE90(&current, &a, &b);
            func_0038CF68(&current, &current, 0.1f);
        } else {
            qzero(&current);
        }
        for (k = 0; k < 4; k++) {
            if (k < 2) {
                s32 odd = k & 1;
                copy_3372C8(&q[0].v[k], &v->pos[j]);
                if (odd) vec_add_ab(&q[0].v[k], &q[0].v[k], &previous);
                else vec_sub_ab(&q[0].v[k], &q[0].v[k], &previous);
            } else {
                s32 odd = k & 1;
                copy_3372C8(&q[0].v[k], &v->pos[j+1]);
                if (odd) vec_add_ab(&q[0].v[k], &q[0].v[k], &current);
                else vec_sub_ab(&q[0].v[k], &q[0].v[k], &current);
            }
            q[0].uv[k][0] = D_L20_001DCAF0[k][0] + (f32)(j % 4) * 0.25f;
        }
        func_003D2DA0(&q[0], matrix, 0);
    }
    for (i = 0; i < 4; i++) {
        qzero(&current);
        if (valid_3372C8(indices[i])) {
            for (m = 0; m < 3; m++) {
                previous = current;
                if (m < 2) {
                    vec_sub_ab(&b, &v->grid[m][i], &v->grid[m+2][i]);
                    vec_sub_ba(&a, &v->grid[m+1][i], &eye);
                    func_0038CE90(&current, &a, &b);
                    func_0038CF68(&current, &current, 0.1f);
                } else {
                    qzero(&current);
                }
                if (m == 0) previous = current;
                for (k2 = 0; k2 < 4; k2++) {
                    if (k2 < 2) {
                        s32 odd = k2 & 1;
                        copy_3372C8(&q[0].v[k2], &v->grid[m][i]);
                        if (odd) vec_add_ab(&q[0].v[k2], &q[0].v[k2], &previous);
                        else vec_sub_ab(&q[0].v[k2], &q[0].v[k2], &previous);
                    } else {
                        s32 odd = k2 & 1;
                        copy_3372C8(&q[0].v[k2], &v->grid[m+1][i]);
                        if (odd) vec_add_ab(&q[0].v[k2], &q[0].v[k2], &current);
                        else vec_sub_ab(&q[0].v[k2], &q[0].v[k2], &current);
                    }
                    q[0].uv[k2][0] = D_L20_001DCAF0[k2][0] + (f32)(m % 4) * 0.25f;
                }
                func_003D2DA0(&q[0], matrix, 0);
            }
        }
    }
}
