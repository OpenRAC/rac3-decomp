#include "common.h"
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;
typedef struct {
    Vec4 m[4];
} Mtx4;

extern s32 D_L23_001E5E34[];
extern u8 D_L23_001EE310[];
extern void func_U_0041A640(void *, s32, Mtx4 *);
extern void func_U_00427B98(void *, void *, void *, f32);

/* localdecomp:start func_U_L23_00403E30 */
void func_U_L23_00403E30(void *a0) {
    Mtx4 m;
    Vec4 a;
    Vec4 b;
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    s32 st;
    Vec4 *p;
    Vec4 *r;
    Vec4 *row;
    Vec4 (*tbl)[6];

    if (D_L23_001E5E34[0] == 1) {
        for (k = 0; k < 9; k++) {
            func_U_0041A640(a0, k, &m);
            r = (Vec4 *)(D_L23_001EE310 + k * 0x60);
            for (n = 0; n < 6; n++) {
                *r++ = m.m[3];
            }
        }
    } else if (D_L23_001E5E34[0] < 300) {
        tbl = (Vec4 (*)[6])D_L23_001EE310;
        st = 0x60;
        for (i = 0; i < 9; i++) {
            row = (Vec4 *)((u8 *)tbl + i * st);
            for (j = 5; j > 0; j--) {
                p = (Vec4 *)((u8 *)tbl + i * st) + j;
                a = row[j - 1];
                b = row[j];
                func_U_00427B98(p, &a, &b, 0.85f);
            }
            func_U_0041A640(a0, i, &m);
            tbl[i][0] = m.m[3];
        }
    }
}
/* localdecomp:end func_U_L23_00403E30 */
