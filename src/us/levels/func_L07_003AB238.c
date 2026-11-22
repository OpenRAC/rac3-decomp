#include "common.h"

/* NTSC-U counterpart of func_L07_003ACA90 (src/levels/07_annihilation_nation/L07_003ACA00.c) */
#include "vu0.h"
void func_L07_003AB238(void *, s32);
void func_L07_003AB238(void *, s32);

/* localdecomp:start func_L07_003AB238 */
void func_L07_003AB238(void *obj, s32 state) {
    extern void func_003BE4F0(void *, s32, s32, s32);
    extern void func_L07_003AB800(void *);
    extern f32 func_0037E250(f32, f32);
    extern void func_L01_00441FB8(void *, s32, s32);
    u8 *p = obj;
    u8 *s = *(u8 **)(p + 0x68);
    f32 r;
    switch (state) {
    case 1: break;
    case 2:
        if (p[0x43] != 0) func_003BE4F0(obj, 0, 0, 0);
        break;
    case 4:
        if (p[0x43] != 4) func_003BE4F0(obj, 4, 0, 5);
        *(f32 *)(s + 0x170) = 0.0018055555410683155f;
        *(f32 *)(s + 0x174) = 0.0018055555410683155f;
        *(f32 *)(s + 0x178) = 0.10833334177732468f;
        *(u16 *)(p + 0x34) |= 0x5000;
        break;
    case 6:
        if (p[0x43] != 3) func_003BE4F0(obj, 3, 0, 5);
        break;
    case 7:
        *(f32 *)(s + 0x170) = 0.0018055555410683155f;
        *(f32 *)(s + 0x174) = 0.0018055555410683155f;
        *(f32 *)(s + 0x178) = 0.10833334177732468f;
        if (p[0x43] != 4) func_003BE4F0(obj, 4, 0, 5);
        break;
    case 8:
        *(u32 *)(s + 0x188) |= 0x10;
        *(f32 *)(s + 0x170) = 0.0009722222457639873f;
        *(f32 *)(s + 0x174) = 0.0009722222457639873f;
        *(f32 *)(s + 0x178) = 0.05833333730697632f;
        if (p[0x43] != 3) func_003BE4F0(obj, 3, 0, 5);
        break;
    case 10:
        *(s16 *)(s + 0x564) = 0;
        func_L07_003AB800(obj);
        s[0x566] = 0;
        r = func_0037E250(0.0f, 1.0f);
        if (r < 0.5f) {
            s[0x567] = 1;
            if (p[0x43] != 5) func_003BE4F0(obj, 5, 0, 3);
        } else if (r < 1.0f) {
            s[0x567] = 2;
            if (p[0x43] != 6) func_003BE4F0(obj, 6, 0, 3);
        } else {
            s[0x567] = 3;
            if (p[0x43] != 7) func_003BE4F0(obj, 7, 0, 3);
            state = 11;
        }
        break;
    case 12:
        if (p[0x43] != 8) func_003BE4F0(obj, 8, 0, 3);
        break;
    case 13:
        *(u32 *)(s + 0x188) |= 0x10;
        *(f32 *)(s + 0x170) = 0.0009722222457639873f;
        *(f32 *)(s + 0x174) = 0.0009722222457639873f;
        *(f32 *)(s + 0x178) = 0.05833333730697632f;
        if (p[0x43] != 3) func_003BE4F0(obj, 3, 0, 5);
        break;
    }
    func_L01_00441FB8(obj, state, -1);
}
/* localdecomp:end func_L07_003AB238 */
