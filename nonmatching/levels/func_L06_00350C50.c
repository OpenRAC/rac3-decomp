/* Level 06 shared (src/levels/shared/L06_003506E0.c) draft, 2026-11-15. 32 differences with the file's flags (-mvu0-use-vf0-vf2 @ps2as): retail indexes the $gp table D_L06_001DD2D0 with `la` ($gp + 0xA20) + addu, scheduled first; under check.py this C gets `lw $a1, D($v0)` (lui/addu/lw), and with it a different prologue order and the 0.3f select. The file's -mno-split-addresses is the cause (check.py's flags line does not print it): without it (--mode S) the table read is retail's `la` + addu and 17 VU0 register-order differences remain, but func_L06_003506E0 needs the flag (D_L06_001DD340 is larger than 8 bytes, so it cannot be declared small to get the same `la`). func_L06_00350E28 has the same $gp table read. The VU0 parts use include/vu0.h's vec_neg/vec_add_ba. */
#include "vu0.h"
#include "common.h"
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

typedef struct {
    Vec4 m[4];
} Mtx4;
extern void func_003C2EC0(void *, s32, Mtx4 *);
extern void func_0038CE20(void *, void *, f32);
__asm__(".extern D_L06_001DD2D0, 8");
extern s32 D_L06_001DD2D0[2];
void func_L06_00350C50(u8 *a0, u8 *a1, s32 a2, u8 *a3, u8 *t0, u8 *t1) {
    vu0_v4 tmp;
    f32 f;

    func_003C2EC0(*(void **)(a1 + 0x260), D_L06_001DD2D0[a2], (Mtx4 *)a3);
    if (a2 == 0) {
        vec_neg(a3 + 0x10, a3 + 0x10);
        vec_neg(a3, a3);
    }
    func_0038CE20(&tmp, a3 + 0x10, 0.5f);
    vec_add_ba(t0, &tmp, a3 + 0x30);
    func_0038CE20(&tmp, a3 + 0x20, 0.775f);
    vec_add_ba(t0, &tmp, t0);
    f = 0.3f;
    if (a2 == 0) {
        f = -0.3f;
    }
    func_0038CE20(&tmp, a3, f);
    vec_add_ba(t0, &tmp, t0);
    *(vu0_q *)t1 = *(vu0_q *)(a3 + 0x10);
}
