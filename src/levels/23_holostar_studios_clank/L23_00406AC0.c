#include "common.h"
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;
typedef struct {
    Vec4 m[4];
} Mtx4;

INCLUDE_ASM("asm/levels", func_L23_00406AC0);

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
