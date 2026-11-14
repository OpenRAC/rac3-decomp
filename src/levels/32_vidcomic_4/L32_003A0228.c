#include "common.h"

INCLUDE_ASM("asm/levels", func_L32_003A0228);

INCLUDE_ASM("asm/levels", func_L32_003A0370);

/* localdecomp:start func_L32_003A05F0 */
/* follows func_L32_003A0AF8 (same file family) */
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern void func_L03_0034B248(void *, void *);
extern void func_L30_0034C8A8(void *, void *);
extern void func_L32_003A25B0(void *, f32, f32);
extern void func_L32_003A2508(void *, f32, s32);
extern void func_L32_003A14C8(void *, s32);
extern s32 func_0038CAD0(void *);
extern s32 D_L32_001DE6DC;
extern f32 D_L32_001DE6CC;
extern f32 D_L32_001DE6C8;
extern f32 D_L32_001DE780;
extern u8 D_L32_001E2240[];
extern u8 D_L32_001E2280[] __attribute__((section(".sdata")));

void func_L32_003A05F0(void *arg0) {
    void *p;
    f32 f20;

    p = *(void **)((u8 *)arg0 + 0x68);
    f20 = func_L03_0034B440(1, 0, 0, (f32)*(s32 *)((u8 *)p + 0x220), (f32)D_L32_001DE6DC, 1.0f);
    func_L32_003A25B0(arg0, f20 * D_L32_001DE6CC, D_L32_001DE6C8);
    func_L32_003A2508(arg0, f20, 2);
    *(f32 *)(D_L32_001E2280 + 4) = D_L32_001DE780;
    func_L30_0034C8A8(D_L32_001E2240, arg0);
    func_L03_0034B248(D_L32_001E2280, arg0);
    if (func_0038CAD0((u8 *)p + 0x220) != 0) {
        func_L32_003A14C8(arg0, 3);
    }
}
/* localdecomp:end func_L32_003A05F0 */

INCLUDE_ASM("asm/levels", func_L32_003A06B8);

/* localdecomp:start func_L32_003A09F0 */
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L03_0034B248(void *, void *);
extern void func_L30_0034C8A8(void *, void *);
extern void func_L32_003A25B0(void *, f32, f32);
extern void func_L32_003A2508(void *, f32, s32);
extern void func_L32_003A14C8(void *, s32);
extern s32 func_0038CAD0(void *);
extern s32 D_L32_001DE6E8;
extern f32 D_L32_001DE6CC;
extern f32 D_L32_001DE6D0;
extern f32 D_L32_001DE6C8;
extern f32 D_L32_001DE6C4;
extern f32 D_L32_001DE784;
extern f32 D_L32_001E2284[];
extern u8 D_L32_001E2280[];
extern u8 D_L32_001E2240[];

static __inline__ void emitter_003A09F0(void *a) {
    func_L30_0034C8A8(D_L32_001E2240, a);
}

void func_L32_003A09F0(void *arg0) {
    void *p;
    f32 one;
    f32 f;
    f32 a;

    p = *(void **)((u8 *)arg0 + 0x68);
    one = 1.0f;
    f = func_L03_0034B440(1, 0, 0, (f32)*(s32 *)((u8 *)p + 0x220), (f32)D_L32_001DE6E8, one);
    a = func_003C4088(D_L32_001DE6CC, D_L32_001DE6D0, f);
    func_L32_003A25B0(arg0, a, func_003C4088(D_L32_001DE6C8, D_L32_001DE6C4, f));
    func_L32_003A2508(arg0, one, 2);
    D_L32_001E2284[0] = D_L32_001DE784;
    func_L03_0034B248(D_L32_001E2280, arg0);
    emitter_003A09F0(arg0);
    emitter_003A09F0(arg0);
    if (func_0038CAD0((u8 *)p + 0x220) != 0) {
        func_L32_003A14C8(arg0, 2);
    }
}
/* localdecomp:end func_L32_003A09F0 */
