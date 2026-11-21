#include "common.h"

/* NTSC-U counterpart of func_L08_003C7660 (src/levels/08_aquatos/L08_003C7660.c) */
/* localdecomp:start func_L08_003C5360 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C7660;
extern u8 D_001A30B0[];
extern void func_003886E8(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L08_003C50F0(void *, void *, void *);
extern s32 func_00388398(void *);
extern void func_0039FB08(s32);

void func_L08_003C5360(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    V4_3C7660 a;
    s32 idx;
    u8 *e;

    switch (m[0x20]) {
    case 0:
        *(f32 *)(v + 0x14) = *(f32 *)(m + 0x2C) / *(f32 *)(*(u8 **)(m + 0x24) + 0x24);
        func_003886E8(v, m + 0xD0, -1.0f);
        *(s32 *)(v + 0x10) = func_0037E208(0x5A, 0xAA);
        func_L01_00441FB8(m, 1, -1);
        break;
    case 1: {
        s32 i = *(s32 *)(v + 0x18);
        if (i == -1 || (e = D_001A30B0 + (i << 7), *(void **)(e + 0xDC) != m) || e[0xD0] == 0) {
            *(s32 *)(v + 0x18) = func_0039FE80(0, 4, m);
        }
        func_003886E8(&a, m + 0xD0, *(f32 *)(v + 0x14) * -0.75199997f);
        vec_add_ba(&a, m + 0x10, &a);
        func_L08_003C50F0(m, &a, v);
        if (func_00388398(v + 0x10) != 0) {
            func_L01_00441FB8(m, 2, -1);
        }
    }
    case 2:
        idx = *(s32 *)(v + 0x18);
        if (idx != -1) {
            e = D_001A30B0 + (idx << 7);
            if (*(void **)(e + 0xDC) == m && e[0xD0] != 0) {
                func_0039FB08(idx);
            }
        }
        *(s32 *)(v + 0x18) = -1;
        break;
    }
    m[0xA8] = 0xFF;
}
/* localdecomp:end func_L08_003C5360 */
