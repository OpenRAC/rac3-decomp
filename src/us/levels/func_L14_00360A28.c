#include "common.h"

/* NTSC-U counterpart of func_L14_00361B30 (src/levels/14_koros/L14_00361598.c): 0.0004 -> 0.000277778; 0.02 -> 0.0166667 */
#include "vu0.h"
extern void func_00388BD0(void *, void *);

/* localdecomp:start func_L14_00360A28 */
__asm__(".extern D_L14_001DD880_00360A28, 4");
__asm__(".extern D_L14_001DD884_00360A28, 4");
__asm__(".extern D_L14_001DD888_00360A28, 4");
__asm__(".extern D_L14_001DD88C_00360A28, 4");
__asm__(".extern D_L14_001DD89C_00360A28, 4");
extern f32 D_L14_001DD880_00360A28;
extern f32 D_L14_001DD884_00360A28;
extern f32 D_L14_001DD888_00360A28;
extern f32 D_L14_001DD88C_00360A28;
extern f32 D_L14_001DD89C_00360A28;
extern u8 D_001A30B0[];
extern f32 func_L01_00445758(void *, void *, s32, f32, f32, f32, f32);
extern void func_00388BD0(void *, void *);
extern f32 func_00389468(f32, f32);
extern void func_0039FB08(s32);
extern s32 func_L01_004A6D20(void *, s32);
extern s32 func_L01_004A73F8(s32, s32, void *, s32);
s32 func_L14_00360A28(u8 *a0, u8 *a1) {
    s32 r1 = 0;
    s32 r2 = 0;
    s32 idx;
    u8 *e;
    f32 t;
    func_L01_00445758(a0 + 0xF8, a1 + 0x20, 0, *(f32 *)(a1 + 0x1C), D_L14_001DD884_00360A28 * 0.017453292f * 0.000277777785f, D_L14_001DD884_00360A28 * 0.017453292f * 0.000277777785f, D_L14_001DD880_00360A28 * 0.017453292f * 0.0166666675f);
    func_00388BD0(a0 + 0xC0, a0 + 0xF0);
    func_L01_00445758(a1 + 0x1F4, a1 + 0x24, 0, *(f32 *)(a1 + 0x18), D_L14_001DD88C_00360A28 * 0.017453292f * 0.000277777785f, D_L14_001DD88C_00360A28 * 0.017453292f * 0.000277777785f, D_L14_001DD888_00360A28 * 0.017453292f * 0.0166666675f);
    *(f32 *)(a1 + 0x214) = *(f32 *)(a1 + 0x1F4);
    if (fabs_asm(func_00389468(*(f32 *)(a1 + 0x1C), *(f32 *)(a0 + 0xF8))) < D_L14_001DD89C_00360A28) {
        *(s32 *)(a1 + 0x20) = 0;
        r1 = 1;
    }
    if (fabs_asm(func_00389468(*(f32 *)(a1 + 0x18), *(f32 *)(a1 + 0x1F4))) < D_L14_001DD89C_00360A28) {
        *(s32 *)(a1 + 0x24) = 0;
        r2 = 1;
    }
    if (r1 != 0 && r2 != 0) {
        idx = *(s32 *)(a1 + 0x48);
        if (idx != -1) {
            e = D_001A30B0 + (idx << 7);
            if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
                func_0039FB08(idx);
            }
        }
        *(s32 *)(a1 + 0x48) = -1;
    } else if (func_L01_004A6D20(a0, *(s32 *)(a1 + 0x48)) == 0) {
        *(s32 *)(a1 + 0x48) = func_L01_004A73F8(0x10, 4, a0, 0);
    }
    return r1 && r2;
}
/* localdecomp:end func_L14_00360A28 */
