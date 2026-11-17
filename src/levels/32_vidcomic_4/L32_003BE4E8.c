#include "common.h"

typedef struct S_003BED60 {
    u8 pad00[4];
    u8 f04[8];
    f32 f0C;
    f32 f10;
    u8 pad14[0x28];
    s32 f3C;
} S_003BED60;
typedef struct S_003BED60_arg {
    u8 pad00[0x68];
    S_003BED60 *f68;
} S_003BED60_arg;

/* declared by functions of L32_003BE008.c, which this file was cut from */
void func_L32_003BE830();
void func_L32_003BE4E8();

/* localdecomp:start func_L32_003BE4E8 */
extern s32 D_L32_001DF1DC;
__asm__(".extern D_L32_001DF1DC, 4");
void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L32_003BE4E8(u8 *a0) {
    u8 *p;
    f32 f20;

    p = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 1) {
        f20 = 1.0f - (f32)*(s32 *)(p + 0x4) / (f32)*(s32 *)(p + 0x8);
    } else {
        f20 = 1.0f;
    }
    func_003D9508(a0 + 0x10, 0x43, D_L32_001DF1DC, 1, f20 * 2.25f, -0.1f, *(f32 *)(p + 0x10));
    func_003D9508(a0 + 0x10, 0x31, 0x7FFFFFFF, 1, f20, 0.0f, -*(f32 *)(p + 0xC));
    func_003D9508(a0 + 0x10, 0x4B, 0x7FFFFFFF, 3, f20 + f20, 0.025f, -*(f32 *)(p + 0x10));
}
/* localdecomp:end func_L32_003BE4E8 */

INCLUDE_ASM("asm/levels", func_L32_003BE5E0);

/* localdecomp:start func_L32_003BE830 */
extern s32 D_L32_001DF1BC; __asm__(".extern D_L32_001DF1BC, 4");
extern s32 D_L32_001DF180; __asm__(".extern D_L32_001DF180, 4");
extern s32 D_L32_001DF184; __asm__(".extern D_L32_001DF184, 4");
extern f32 D_L32_001DF190; __asm__(".extern D_L32_001DF190, 4");
extern s32 D_L32_001DF194; __asm__(".extern D_L32_001DF194, 4");
typedef struct { s16 a, b; f32 c; s32 d, e, f; void *g; } S_003BE830;
extern S_003BE830 D_L32_001E2590 __attribute__((section(".sdata")));
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern void func_L03_0034B218(void *, s32, s32, f32, s32, void *);
extern void func_L32_003BE5E0(void *);

void func_L32_003BE830(void *a)
{
    S_003BED60 *p = ((S_003BED60_arg *)a)->f68;

    p->f0C = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
    p->f10 = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
    p->f3C = -1;
    if (D_L32_001DF1BC == 0) {
        D_L32_001DF1BC = 1;
        func_L03_0034B218(&D_L32_001E2590, D_L32_001DF180, D_L32_001DF184, D_L32_001DF190,
                          D_L32_001DF194, func_L32_003BE5E0);
    }
}
/* localdecomp:end func_L32_003BE830 */
