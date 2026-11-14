#include "common.h"

INCLUDE_ASM("asm/levels", func_L16_003E8D20);

INCLUDE_ASM("asm/levels", func_L16_003E8DC0);

INCLUDE_ASM("asm/levels", func_L16_003E9068);

/* localdecomp:start func_L16_003E91B0 */
extern void func_L16_003E9068(void *a0, void *a1, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4, s32 a2, s32 a3, u8 a4, u8 a5, s32 a6);
__asm__(".extern D_L16_001DF644, 4");
extern f32 D_L16_001DF644;
__asm__(".extern D_L16_001DF648, 1");
extern u8 D_L16_001DF648;
__asm__(".extern D_L16_001DF649, 1");
extern u8 D_L16_001DF649;
__asm__(".extern D_L16_001DF64A, 1");
extern u8 D_L16_001DF64A;
__asm__(".extern D_L16_001DF64B, 1");
extern u8 D_L16_001DF64B;
__asm__(".extern D_L16_001DF64C, 4");
extern s32 D_L16_001DF64C;

void func_L16_003E91B0(void *arg0, u8 *p, f32 *t) {
    u8 *m = *(u8 **)((u8 *)arg0 + 0x68);

    *t -= D_L16_001DF644;
    if (*t <= -10.0f) {
        *t = 10.0f;
    }
    func_L16_003E9068(p, m + 0x40, 0.0f, *(f32 *)(p + 0xC), 1.0f, *(f32 *)(m + 0x64), *t, 0x3ED8FF, 0x446876,
                      D_L16_001DF648, D_L16_001DF649, D_L16_001DF64C);
    func_L16_003E9068(p, m + 0x40, 1.0f, *(f32 *)(p + 0xC), 1.0f, *(f32 *)(m + 0x64), *t * 3.0f, 0x54AB, 0x9099,
                      D_L16_001DF64A, D_L16_001DF64B, m[0x6F]);
}
/* localdecomp:end func_L16_003E91B0 */

INCLUDE_ASM("asm/levels", func_L16_003E92B8);

INCLUDE_ASM("asm/levels", func_L16_003E93F8);

/* localdecomp:start func_L16_003E95A8 */
extern void func_L01_004048D0(void *, u8 *);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_004450F0(s32, s32, s32);
extern void func_003C2880(void *);
extern void func_L16_003E93F8();
extern u8 D_1A4C60[];

void func_L16_003E95A8(u8 *o) {
    s32 k = o[0x20];
    f32 d;

    switch (k) {
    case 0:
        func_L01_004450F0((s32)o, 1, -1);
        break;
    case 1:
        func_L01_004048D0(func_L16_003E93F8, o);
        d = func_0038CF38(D_1A4C60, o + 0x10);
        if (40.0f < d) {
            func_L01_004450F0((s32)o, 2, -1);
        }
        break;
    case 2:
        func_003C2880(o);
        break;
    }
}
/* localdecomp:end func_L16_003E95A8 */

INCLUDE_ASM("asm/levels", func_L16_003E9660);

INCLUDE_ASM("asm/levels", func_L16_003E9ED8);
