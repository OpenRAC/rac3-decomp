/* Level 06 shared (src/levels/shared/L06_*.c) draft, 2026-11-14. 16 differences with the file's flags (-mvu0-use-vf0-vf2 @ps2as): only scheduling, the move of &v10 into $t1 in the prologue and the lui of D_L06_001D66B0 for the last call (retail loads it last); global types and 120 float/int prototype orders of func_L01_0046B458 gave the same 16. */
#include "common.h"
extern void func_L06_00350C50(u8 *, u8 *, s32, void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_L06_00358938(u8 *, void *, void *, s32, f32, f32);
extern void func_L01_0046B458(void *, s32, u32, s32, s32, void *, s32, f32, f32, f32);
extern u8 D_L06_001D66B0[];
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00352410;
void func_L06_00352410(u8 *a0, u8 *a1, s32 a2) {
    V_00352410 pos;
    V_00352410 v10;
    V_00352410 v20;
    V_00352410 v30[4];
    func_L06_00350C50(a0, a1, a2, v30, &pos, &v10);
    func_0038CE20(&v20, &v10, 0.70000005f);
    func_L06_00358938(a0, &pos, &v20, *(s32 *)(a1 + 0x37C),
                      -func_0038D160(func_0038CED8(v30), v30[0].z), (f32)a1[0x44]);
    func_L01_0046B458(&pos, 8, 0x5F007000, 0, 2, D_L06_001D66B0, 0, 4.0f, 5.0f, 0.0f);
}
