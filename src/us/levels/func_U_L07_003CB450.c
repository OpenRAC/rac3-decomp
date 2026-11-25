#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L07_003CCE68. */
/* localdecomp:start func_U_L07_003CB450 */

typedef int u128_t __attribute__((mode(TI)));

extern void func_U_003CCF28(void *);
extern void func_U_003CB8D0(void *, s32);
extern s32 func_U_00450290(void *, void *, s32, s32, s32);
extern s32 func_U_0032CC58(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_U_0044F2C8(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_U_00441840(void *, s32, s32);
extern void func_U_003CB3E0(void *);
extern void func_U_004A60E0(s32, s32, void *);
extern void func_U_004442A8(void *, void *, s32, void *, void *, f32);
extern s32 func_U_0044FBD8(void *, void *, s32);
extern void func_U_00453E80(void *, s32);
extern void func_U_00453F48(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_U_004039F8(void *, void *);
extern void func_U_003CC990();
extern void func_U_0044F0E8(void *, s32, void *, f32);
extern f32 func_U_0040C928(void *, void *);
extern void func_U_00444AF8(void *);
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
extern u8 D_L07_001E1EC0[];

void func_U_L07_003CB450(u8 *obj) {
    u8 *p;
    f32 pos[4] __attribute__((aligned(16)));
    f32 t;

    p = *(u8 **)(obj + 0x68);
    if (obj[0x20] == 1) {
        return;
    }
    if (obj[0x20] >= 0xC) {
        if (*(s16 *)(p + 0x144) != 1) {
            func_U_003CCF28(obj);
            func_U_003CB8D0(obj, 5);
        }
    }
    if (func_U_00450290(obj, p + 0x70, 0, 0, 0) != 0) {
        p[0x407] = 0;
        func_U_003CCF28(obj);
    }
    if (*(f32 *)(p + 0x30) <= 0.0f) {
        *(u128_t *)pos = *(u128_t *)(obj + 0x10);
        pos[2] = pos[2] + *(f32 *)(p + 0x40);
        func_U_0032CC58(pos, 0, 0xA, 5, 4, 0xA, 0xF, 0, 0.5f, 0.0f, 0.0f, 2.0f, 0, 0, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_U_0044F2C8(obj, 0x3FFF, D_L07_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_U_00441840(obj, 0, 3);
        func_U_003CB3E0(obj);
        func_U_004A60E0(9, 0, obj);
        return;
    }
    if (*(s32 *)(p + 0x228) == 1 || *(s32 *)(p + 0x228) == 0xB) {
        qzero(pos);
        func_U_004442A8(obj, obj, 0x10000, pos, pos, (f32)*(s16 *)(p + 0x34));
    } else if (p[0x5E] != 0 || p[0x60] != 0 || p[0x3E] == 2) {
        func_U_00441840(obj, 0, 3);
        func_U_003CB3E0(obj);
        return;
    }
    func_U_0044FBD8(obj, p + 0x30, 0);
    if (p[0x5F] != 0) {
        func_U_00453E80(obj, 5);
        if (obj[0x20] == 5) {
            func_U_00453F48(obj, *(s32 *)(p + 0x2B0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2B4), 10.0f, 1.0f);
        } else {
            func_U_00453F48(obj, *(s32 *)(p + 0x2B8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2BC), 10.0f, 1.0f);
        }
    } else {
        func_U_00453E80(obj, 3);
        if (obj[0x20] == 5) {
            func_U_00453F48(obj, *(s32 *)(p + 0x2B0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2B4), 10.0f, 1.0f);
        } else {
            func_U_00453F48(obj, *(s32 *)(p + 0x2B8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2BC), 10.0f, 1.0f);
        }
    }
    t = *(f32 *)(p + 0x400) - -0.1f;
    *(f32 *)(p + 0x400) = t;
    if (t < 0.0f) {
        *(f32 *)(p + 0x400) = t + 1.0f;
    }
    func_U_004039F8(func_U_003CC990, obj);
    func_U_0044F0E8(obj, 0xA, p + 0x240, 2.5f);
    if (obj[0x31] != 0) {
        if (func_U_0040C928(D_L07_001E1EC0, obj + 0x10) < 576.0f) {
            func_U_00444AF8(obj);
            obj[0x6F] = 0x16;
        }
    }
}
/* localdecomp:end func_U_L07_003CB450 */
