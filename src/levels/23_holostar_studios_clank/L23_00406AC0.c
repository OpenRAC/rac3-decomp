#include "common.h"
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;
typedef struct {
    Vec4 m[4];
} Mtx4;

extern s32 D_L23_001E5DB4[];
extern u8 D_L23_001EE290[];
extern void func_003C2EC0(void *, s32, Mtx4 *);
extern void func_003C4098(void *, void *, void *, f32);

/* localdecomp:start func_L23_00406AC0 */
void func_L23_00406AC0(void *a0) {
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

    if (D_L23_001E5DB4[0] == 1) {
        for (k = 0; k < 9; k++) {
            func_003C2EC0(a0, k, &m);
            r = (Vec4 *)(D_L23_001EE290 + k * 0x60);
            for (n = 0; n < 6; n++) {
                *r++ = m.m[3];
            }
        }
    } else if (D_L23_001E5DB4[0] < 0xFA) {
        tbl = (Vec4 (*)[6])D_L23_001EE290;
        st = 0x60;
        for (i = 0; i < 9; i++) {
            row = (Vec4 *)((u8 *)tbl + i * st);
            for (j = 5; j > 0; j--) {
                p = (Vec4 *)((u8 *)tbl + i * st) + j;
                a = row[j - 1];
                b = row[j];
                func_003C4098(p, &a, &b, 0.85f);
            }
            func_003C2EC0(a0, i, &m);
            tbl[i][0] = m.m[3];
        }
    }
}
/* localdecomp:end func_L23_00406AC0 */

/* localdecomp:start func_L23_00406C48 */
extern s32 D_L23_001E5DB4[];
extern u8 D_L23_001EE290[];
extern void func_003C2EC0(void *, s32, Mtx4 *);
extern void func_L01_00409E70(u8 *a0, u8 *a1, s32 a2, s32 a3, f32 f12, f32 f13);

void func_L23_00406C48(void *a0) {
    Mtx4 m;
    Vec4 v;
    s32 i;

    if ((u32)(D_L23_001E5DB4[0] - 0x8E) < 0x6C) {
        for (i = 0; i < 9; i++) {
            func_003C2EC0(a0, i, &m);
            v = m.m[3];
            func_L01_00409E70((u8 *)&v, D_L23_001EE290 + i * 0x60, 0x10050525, 6, 0.0f, 0.05f);
        }
    }
}
/* localdecomp:end func_L23_00406C48 */
