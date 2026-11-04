#include "common.h"


/* localdecomp:start func_L32_003A0AF8 */
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern void func_L03_0034B248(void *, void *);
extern void func_L32_003A25B0(void *, f32, f32);
extern void func_L32_003A2508(void *, f32, s32);
extern void func_L32_003A14C8(void *, s32);
extern s32 func_0038CAD0(void *);
extern s32 D_L32_001DE6EC;
extern f32 D_L32_001DE6D4;
extern f32 D_L32_001DE6C8;
extern f32 D_L32_001DE788;
extern f32 D_L32_001E2284[];
extern u8 D_L32_001E2280[];

void func_L32_003A0AF8(void *arg0) {
    void *p;
    f32 f20;
    f32 f;

    p = *(void **)((u8 *)arg0 + 0x68);
    f20 = 1.0f;
    f = func_L03_0034B440(1, 0, 0, (f32)*(s32 *)((u8 *)p + 0x220), (f32)D_L32_001DE6EC, f20);
    f20 = f20 - f;
    func_L32_003A25B0(arg0, f20 * D_L32_001DE6D4, D_L32_001DE6C8);
    func_L32_003A2508(arg0, 0.0f, 1);
    D_L32_001E2284[0] = D_L32_001DE788;
    func_L03_0034B248(D_L32_001E2280, arg0);
    if (func_0038CAD0((u8 *)p + 0x220) != 0) {
        func_L32_003A14C8(arg0, 0);
    }
}
/* localdecomp:end func_L32_003A0AF8 */
