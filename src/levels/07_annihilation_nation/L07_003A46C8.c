#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003A46C8);

INCLUDE_ASM("asm/levels", func_L07_003A5078);

INCLUDE_ASM("asm/levels", func_L07_003A52F0);

/* localdecomp:start func_L07_003A55D8 */
void func_003C2880(s32);
void func_L07_00334740(void *);
void func_L07_003A5780(void *, s32);

void func_L07_003A55D8(void *arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    temp_a0 = *(s32 *)((u8 *)temp_s0 + 0x498);
    if (temp_a0 != 0) {
        func_003C2880(temp_a0);
        *(s32 *)((u8 *)temp_s0 + 0x498) = 0;
        *(s32 *)((u8 *)temp_s0 + 0x264) = 0;
    }
    temp_a0_2 = *(s32 *)((u8 *)temp_s0 + 0x494);
    if (temp_a0_2 != 0) {
        func_003C2880(temp_a0_2);
        *(s32 *)((u8 *)temp_s0 + 0x494) = 0;
        *(s32 *)((u8 *)temp_s0 + 0x260) = 0;
    }
    *(s16 *)((u8 *)arg0 + 0x7C) = 0x1F;
    *(f32 *)((u8 *)temp_s0 + 0x250) = (f32) (*(s16 *)((u8 *)temp_s0 + 0x34));
    func_L07_00334740(arg0);
    func_L07_003A5780(arg0, 1);
}
/* localdecomp:end func_L07_003A55D8 */

INCLUDE_ASM("asm/levels", func_L07_003A5670);

INCLUDE_ASM("asm/levels", func_L07_003A5780);

INCLUDE_ASM("asm/levels", func_L07_003A5CA8);

INCLUDE_ASM("asm/levels", func_L07_003A5D80);

INCLUDE_ASM("asm/levels", func_L07_003A5ED0);

/* localdecomp:start func_L07_003A5FA0 */
extern s32 func_00382468(s32);
u8 func_L07_003A5FA0(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    if (*(s32 *)(p + 0x498) == 0) {
        return 0;
    }
    if (*(s32 *)(p + 0x494) == 0) {
        return 1;
    }
    return func_00382468(2);
}
/* localdecomp:end func_L07_003A5FA0 */

/* localdecomp:start func_L07_003A5FE0 */
void func_L07_003A5780(void *, s32);
s32 func_L07_003A6110(void *, s32);
extern f32 func_0038DB00(f32, f32);
extern s32 func_00382468(s32);

void func_L07_003A5FE0(void *arg0, u8 arg1) {
    u8 s0;
    void *p;
    f32 f;

    p = *(void **)((u8 *)arg0 + 0x68);
    f = func_0038DB00(*(f32 *)((u8 *)p + 0x284), *(f32 *)((u8 *)p + 0x280));
    if (0.0f < f) {
        s0 = 1;
    } else if (f < 0.0f) {
        s0 = 0;
    } else {
        s0 = func_00382468(2);
    }
    if (func_L07_003A6110(arg0, s0) != 0) {
        func_L07_003A5780(arg0, arg1 + s0);
        return;
    }
    if (s0 != 0) {
        s0 = 0;
    } else {
        s0 = 1;
    }
    if (func_L07_003A6110(arg0, s0) != 0) {
        func_L07_003A5780(arg0, arg1 + s0);
    }
}
/* localdecomp:end func_L07_003A5FE0 */

/* localdecomp:start func_L07_003A60A8 */
extern f32 func_L01_0040E4C0(void *);
extern void func_0038CF68(void *, void *, f32);

void func_L07_003A60A8(void *arg0, f32 x, f32 y) {
    u8 *o;
    void *p;
    f32 v;

    o = *(u8 **)((u8 *)arg0 + 0x68);
    p = o + 0x1F0;
    *(f32 *)(o + 0x178) = x;
    *(f32 *)(o + 0x170) = y;
    *(f32 *)(o + 0x174) = y;
    v = func_L01_0040E4C0(p);
    if (*(f32 *)(o + 0x178) * *(f32 *)(o + 0x178) < v) {
        func_0038CF68(p, p, *(f32 *)(o + 0x178));
        *(f32 *)(o + 0x200) = *(f32 *)(o + 0x178);
    }
}
/* localdecomp:end func_L07_003A60A8 */

INCLUDE_ASM("asm/levels", func_L07_003A6110);

INCLUDE_ASM("asm/levels", func_L07_003A61E8);

/* localdecomp:start func_L07_003A63D8 */
void func_L07_003A63D8(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    p[0x490] = 0;
    p[0x491] = 0;
}
/* localdecomp:end func_L07_003A63D8 */

INCLUDE_ASM("asm/levels", func_L07_003A63E8);

/* localdecomp:start func_L07_003A6460 */
extern void func_L07_003A6498(u8 *, u8 *, s32, s32, s32);
void func_L07_003A6460(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    func_L07_003A6498(p + 0x350, p + 0x3F0, p[0x491], p[0x490], p[0x4A4] + 100);
}
/* localdecomp:end func_L07_003A6460 */

INCLUDE_ASM("asm/levels", func_L07_003A6498);

INCLUDE_ASM("asm/levels", func_L07_003A66E8);

INCLUDE_ASM("asm/levels", func_L07_003A6C90);

INCLUDE_ASM("asm/levels", func_L07_003A6EA8);

INCLUDE_ASM("asm/levels", func_L07_003A6EF8);

INCLUDE_ASM("asm/levels", func_L07_003A6FC8);
