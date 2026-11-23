#include "common.h"

/* localdecomp:start func_L07_003A6EA8 */
typedef int Q_003A6EA8 __attribute__((mode(TI)));
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
extern void func_L01_004450F0(u8 *, s32, s32);
void func_L07_003A6EA8(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    if (*(s32 *)(p + 0x70) != -1) {
        *(Q_003A6EA8 *)(arg0 + 0x10) = *(Q_003A6EA8 *)(p + 0x90);
        *(Q_003A6EA8 *)(p + 0x90) = *(Q_003A6EA8 *)D_L07_001D66B0;
        *(s32 *)(p + 0x70) = -1;
        func_L01_004450F0(arg0, 0, -1);
    }
}
/* localdecomp:end func_L07_003A6EA8 */

/* localdecomp:start func_L07_003A6EF8 */
extern f32 D_L07_001DEF50;
extern void func_L01_00443B18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00472F58(void *, void *, s32, f32);

void func_L07_003A6EF8(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68) + 0xA0;
    f32 v[4];
    f32 t = 0.95f;
    s32 i;

    for (i = 8; i >= 0; i--) {
        if (D_L07_001DEF50 < t) {
            func_L01_00443B18(v, 0.0030000003f);
            v[2] = func_003824E0(0.0050000004f, 0.020000001f);
            func_L01_00472F58(p, v, 0x44, func_003824E0(0.05f, 0.1f));
        }
        p += 0x10;
    }
}
/* localdecomp:end func_L07_003A6EF8 */

/* localdecomp:start func_L07_003A6FC8 */
extern s32 func_0038CAD0(void *);
extern f32 func_L01_004451A8(f32);

void func_L07_003A6FC8(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    u8 **q;
    s32 i;
    f32 t;
    u8 *o;

    if (arg1 != 0) {
        *(s32 *)(p + 0x158) = 0x43;
        return;
    }
    func_0038CAD0(p + 0x158);
    t = (f32) * (s32 *)(p + 0x158) / 33.0f;
    if (1.0f < t) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    func_L01_004451A8(t);
    q = (u8 **)(p + 0x130);
    for (i = 8; i >= 0; i--) {
        o = *q;
        if (o != 0) {
            *(f32 *)(o + 0xC) = t * 210000.0f * 0.75f;
        }
        q++;
    }
}
/* localdecomp:end func_L07_003A6FC8 */
