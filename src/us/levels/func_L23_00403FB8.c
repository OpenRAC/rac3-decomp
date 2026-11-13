#include "common.h"

/* NTSC-U counterpart of func_L23_00406C48 (src/levels/23_holostar_studios_clank/L23_00406AC0.c) */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;
typedef struct {
    Vec4 m[4];
} Mtx4;

/* localdecomp:start func_L23_00403FB8 */
extern s32 D_L23_001E5E34[];
extern u8 D_L23_001EE310[];
extern void func_003BD9A0(void *, s32, Mtx4 *);
extern void func_L01_00407A60(u8 *a0, u8 *a1, s32 a2, s32 a3, f32 f12, f32 f13);

void func_L23_00403FB8(void *a0) {
    Mtx4 m;
    Vec4 v;
    s32 i;

    if ((u32)(D_L23_001E5E34[0] - 170) < 130) {
        for (i = 0; i < 9; i++) {
            func_003BD9A0(a0, i, &m);
            v = m.m[3];
            func_L01_00407A60((u8 *)&v, D_L23_001EE310 + i * 0x60, 0x10050525, 6, 0.0f, 0.05f);
        }
    }
}
/* localdecomp:end func_L23_00403FB8 */
