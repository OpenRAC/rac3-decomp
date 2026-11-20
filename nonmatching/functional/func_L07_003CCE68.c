/* functional: high. Names translated by address via functions.tsv; every float constant checked bit for bit against PAL asm (retail subtracts 0xBDF5C290, one ulp off -0.12f). */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003CCE68 */
typedef int u128_t __attribute__((mode(TI)));

extern void func_L07_003CE940(void *);
extern void func_L07_003CD2E8(void *, s32);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L01_004443E8(void *, s32, s32);
extern void func_L07_003CCDF8(void *);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00446A70(void *, void *, s32, void *, void *, f32);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00404808(void *, void *);
extern void func_L07_003CE3A8();
extern void func_L07_004522E8(void *, s32, void *, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern u8 D_L07_001D66B0[];
extern u8 D_L07_001E1EC0[];

void func_L07_003CCE68(u8 *obj) {
    u8 *p;
    f32 pos[4] __attribute__((aligned(16)));
    s32 r;
    f32 t;

    p = *(u8 **)(obj + 0x68);
    if (obj[0x20] == 1) {
        return;
    }
    if (obj[0x20] >= 0xC) {
        if (*(s16 *)(p + 0x144) != 1) {
            func_L07_003CE940(obj);
            func_L07_003CD2E8(obj, 5);
        }
    }
    if (func_L01_00452FB0(obj, p + 0x70, 0, 0, 0) != 0) {
        p[0x407] = 0;
        func_L07_003CE940(obj);
    }
    if (*(f32 *)(p + 0x30) <= 0.0f) {
        *(u128_t *)pos = *(u128_t *)(obj + 0x10);
        pos[2] = pos[2] + *(f32 *)(p + 0x40);
        func_L01_003303B8(pos, 0, 0xA, 5, 4, 0xA, 0xF, 0, 0.5f, 0.0f, 0.0f, 2.0f, 0, 0, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_L01_00451FE0(obj, 0x3FFF, D_L07_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_004443E8(obj, 0, 3);
        func_L07_003CCDF8(obj);
        func_003A52A0(9, 0, obj);
        return;
    }
    if (*(s32 *)(p + 0x228) == 1 || *(s32 *)(p + 0x228) == 0xB) {
        qzero(pos);
        func_L01_00446A70(obj, obj, 0x10000, pos, pos, (f32)*(s16 *)(p + 0x34));
    } else if (p[0x5E] != 0 || p[0x60] != 0 || p[0x3E] == 2) {
        func_L01_004443E8(obj, 0, 3);
        func_L07_003CCDF8(obj);
        return;
    }
    func_L01_00452860(obj, p + 0x30, 0);
    if (p[0x5F] != 0) {
        func_L01_00456BD0(obj, 5);
        if (obj[0x20] == 5) {
            func_L01_00456C98(obj, *(s32 *)(p + 0x2B0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2B4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(obj, *(s32 *)(p + 0x2B8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2BC), 10.0f, 1.0f);
        }
    } else {
        func_L01_00456BD0(obj, 3);
        if (obj[0x20] == 5) {
            func_L01_00456C98(obj, *(s32 *)(p + 0x2B0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2B4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(obj, *(s32 *)(p + 0x2B8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2BC), 10.0f, 1.0f);
        }
    }
    t = *(f32 *)(p + 0x400) - -0.120000005f;
    *(f32 *)(p + 0x400) = t;
    if (t < 0.0f) {
        *(f32 *)(p + 0x400) = t + 1.0f;
    }
    func_L01_00404808(func_L07_003CE3A8, obj);
    func_L07_004522E8(obj, 0xA, p + 0x240, 2.5f);
    if (obj[0x31] != 0) {
        if (func_L01_0040E548(D_L07_001E1EC0, obj + 0x10) < 576.0f) {
            func_L01_004472C0(obj);
            obj[0x6F] = 0x16;
        }
    }
}
/* localdecomp:end func_L07_003CCE68 */
