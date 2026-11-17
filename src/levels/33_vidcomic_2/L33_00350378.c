#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L33_00350378 */
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L30_0034C8A8(void *, void *);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern s32 D_L33_001DD7C8;
__asm__(".extern D_L33_001DD7C8, 4");
extern f32 D_L33_001DD7CC;
__asm__(".extern D_L33_001DD7CC, 4");
extern u8 D_L33_001E1810[] __attribute__((section(".sdata")));

void func_L33_00350378(void *arg) {
    u8 *a0 = arg;
    u8 *s1 = *(u8 **)(a0 + 0x68);
    s32 v;
    u8 c;

    if (func_L01_004561B8(a0)) {
        if (*(s32 *)(s1 + 0x3C) > 0) {
            func_L01_00446780(a0, a0 + 0x10, 0x30001, 0, 1, 0, D_L33_001DD7CC * *(f32 *)(s1 + 0x20), 20.0f, 1.0f);
        }
        func_003A52A0(2, 0, a0);
        *(s32 *)(s1 + 0x10) = D_L33_001DD7C8;
    }
    func_L30_0034C8A8(D_L33_001E1810, a0);
    v = (s32)((f32)*(s32 *)(s1 + 0x10) * 128.0f / (f32)D_L33_001DD7C8);
    c = a0[0x23];
    if (c < v) {
        v = c;
    }
    a0[0x23] = v;
    if (func_0038CAD0(s1 + 0x10)) {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L33_00350378 */
