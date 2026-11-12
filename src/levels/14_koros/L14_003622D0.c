#include "common.h"

INCLUDE_ASM("asm/levels", func_L14_003622D0);

/* localdecomp:start func_L14_003624B0 */
extern s32 func_L01_004561B8(u8 *a0);
extern s32 func_00382498(s32, s32);
extern s32 func_0038CAD0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 D_L14_001DD828;
extern s32 D_L14_001DD82C;

s32 func_L14_003624B0(u8 *a0, u8 *a1) {
    if (func_L01_004561B8(a0)) {
        *(s32 *)(a1 + 0x14) = func_00382498(D_L14_001DD828, D_L14_001DD82C);
    }
    if (func_0038CAD0(a1 + 0x14)) {
        func_L01_004450F0(a0, 2, -1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L14_003624B0 */

/* localdecomp:start func_L14_00362520 */
extern s32 D_001DD830;
extern s32 func_L01_004561B8(u8 *);
extern s32 func_L14_00361B30(u8 *, u8 *);
extern s32 func_0038CAD0(void *);
extern void func_L01_004450F0(void *, s32, s32);

s32 func_L14_00362520(u8 *a0, u8 *a1) {
    if (func_L01_004561B8(a0) != 0) {
        *(s32 *)(a1 + 0x14) = D_001DD830;
    }
    func_L14_00361B30(a0, a1);
    if (func_0038CAD0(a1 + 0x14) != 0) {
        func_L01_004450F0(a0, 4, -1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L14_00362520 */

/* localdecomp:start func_L14_00362590 */
extern s32 func_L01_004561B8(u8 *);
extern s32 func_L14_00361B30(u8 *, u8 *);
extern s32 func_0038CAD0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 D_001DD834;

s32 func_L14_00362590(u8 *a0, u8 *a1) {
    if (func_L01_004561B8(a0)) {
        *(s32 *)(a1 + 0x14) = D_001DD834;
    }
    if (func_L14_00361B30(a0, a1)) {
        if (func_0038CAD0(a1 + 0x14)) {
            func_L01_004450F0(a0, 5, -1);
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L14_00362590 */

INCLUDE_ASM("asm/levels", func_L14_00362608);

INCLUDE_ASM("asm/levels", func_L14_00362868);

/* localdecomp:start func_L14_00362A50 */
extern f32 D_L14_00286520[];
extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
extern void func_0038CE20(f32 *, void *, f32);
void func_L14_00362A50(f32 a, f32 b, s32 u0, s32 u1, f32 *p6, f32 *p7, f32 *p8, f32 *p9) {
    f32 v0[4];
    f32 v1[4];
    s32 i;
    f32 *o = D_L14_00286520;
    for (i = 3; i >= 0; i--) {
        func_0038CDF8(v0, p7, p8, p9[0]);
        func_0038CE20(v1, p6, (a + (b - a) * p9[0]) * ((p9[1] - 0.5f) * 2.0f));
        p9 += 2;
        o[0] = v0[0] + v1[0];
        o[1] = v0[1] + v1[1];
        o[2] = v0[2] + v1[2];
        o += 3;
    }
}
/* localdecomp:end func_L14_00362A50 */

INCLUDE_ASM("asm/levels", func_L14_00362B68);

/* localdecomp:start func_L14_00362BF8 */
extern int D_L14_001E1200[] __attribute__((section(".sdata")));
void func_L14_00362BF8(int a, int b, int v)
{
    int i;
    for (i = 3; i >= 0; i--)
        D_L14_001E1200[i] = v;
}
/* localdecomp:end func_L14_00362BF8 */

INCLUDE_ASM("asm/levels", func_L14_00362C28);

INCLUDE_ASM("asm/levels", func_L14_00362D30);
