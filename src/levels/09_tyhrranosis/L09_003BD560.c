#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L09_003BD360.c, which this file was cut from */
extern u8 *D_L09_0021E640[];
typedef struct {
    s8 b[8];
} S_003BD3E8;
extern S_003BD3E8 D_L09_002A29E0[];

/* localdecomp:start func_L09_003BD560 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003BD560;
typedef struct { s32 count; s32 pad[3]; V4_003BD560 v[1]; } VList_003BD560;
extern V4_003BD560 D_001A4C60;
extern void func_L09_003BC450(u8 *, s32, s32, s32, s32);
extern s32 func_L06_004591F8(void *, void *, u8);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L03_00449C30(void *, s32, s32, s32);

static __inline__ s32 nearest_003BD560(VList_003BD560 *l) {
    V4_003BD560 v = D_001A4C60;
    return func_L06_004591F8(&v, l, 0);
}

s32 func_L09_003BD560(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 *list = (s32 *)a1;

    if (a4 == 0) {
        VList_003BD560 *l;
        s32 i;
        s32 best;
        f32 bd;
        f32 d;
        bd = 1e11f;
        best = -1;
        for (i = 0; i < a2; i++) {
            l = (VList_003BD560 *)D_L09_0021E640[list[i]];
            d = func_0038CF38(&D_001A4C60, &l->v[nearest_003BD560(l)]);
            if (d < bd) {
                bd = d;
                best = i;
            }
        }
        if (D_L09_002A29E0[0].b[1] != best) {
            func_L09_003BC450(a0, a1, a2, a3, a4);
            return 0;
        }
    } else if (a4 == 1) {
        VList_003BD560 *l;
        s32 i;
        s32 j;
        s32 best;
        f32 bd;
        f32 d;
        f32 m;
        bd = 0.0f;
        best = -1;
        for (i = 0; i < a2; i++) {
            l = (VList_003BD560 *)D_L09_0021E640[list[i]];
            m = 0.0f;
            for (j = 0; j < l->count; j++) {
                d = func_0038CF38(&D_001A4C60, &l->v[j]);
                if (m < d) {
                    m = d;
                }
            }
            if (bd < m) {
                best = i;
                bd = m;
            }
        }
        if (D_L09_002A29E0[0].b[1] != best) {
            func_L09_003BC450(a0, a1, a2, a3, a4);
            return 0;
        }
    }
    {
        S_003BD3E8 tmp;
        s32 k;

        for (k = 0; k < 10; k++) {
            if (D_L09_002A29E0[k].b[1] == -1) {
                if (k != 0) {
                    S_003BD3E8 *prev = &D_L09_002A29E0[k - 1];
                    tmp = *prev;
                    D_L09_002A29E0[k - 1].b[1] = -1;
                    break;
                }
                if (a4 == 2) {
                    return 1;
                }
                func_L09_003BC450(a0, a1, a2, a3, a4);
                return 0;
            }
        }
        func_L03_00449C30(a0, list[tmp.b[1]], tmp.b[3], tmp.b[2]);
        return 0;
    }
}
/* localdecomp:end func_L09_003BD560 */
