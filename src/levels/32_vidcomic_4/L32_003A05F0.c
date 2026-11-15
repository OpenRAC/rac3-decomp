#include "common.h"

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
