#include "common.h"

/* NTSC-U counterpart of func_L40_00421148 (src/levels/shared/L40_00420BC8.c) */
extern u8 *func_L40_004208A8(s32, s32, u8 *);
extern void func_00388440(void *, s32, s32);

/* localdecomp:start func_L40_004208A8 */
typedef struct { u8 pad[0x30]; u8 x30; u8 x31; u16 x32; u16 x34; } S_00421148;
extern s32 func_L40_0053CA28(u8 *msg);
extern u8 *func_L40_0053CCC0(s32 cls, s32 uid, s32 sender, s32 a3, s32 index);
extern void func_00388440(void *, s32, s32);
extern void func_003C26C8(u8 *m);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern s32 *D_L40_002412A0;

u8 *func_L40_004208A8(s32 a0, s32 a1, u8 *msg) {
    s32 index = *(s32 *)(msg + 0x18);
    u8 *m;
    u8 *v;
    s32 *h = (s32 *)(msg + 8);
    s32 n;
    f32 f2b4;
    s32 w2c0;
    f32 f2b8;
    s32 w464;
    s32 w468;
    s32 w454;

    m = func_L40_0053CCC0(0x1A91, h[1], *(s32 *)(msg + 4), func_L40_0053CA28(msg), index);
    if (m != 0) {
        ((S_00421148 *)m)->x30 = 0x7F;
        ((S_00421148 *)m)->x34 |= 0x20;
        ((S_00421148 *)m)->x32 = 0x7F;
        v = *(u8 **)(m + 0x68);
        if (*D_L40_002412A0 >= 2) {
            *(u8 *)(m + 0x62) = 1;
        }
        *(s32 *)(v + 0x2B0) = 0;
        *(u8 *)(m + 0x20) = 0;
        *(s32 *)(v + 0x2A4) = 0;
        n = *(s32 *)(v + 0x44C);
        if (n < 100) {
            n = 100;
        }
        f2b4 = *(f32 *)(v + 0x2B4);
        w2c0 = *(s32 *)(v + 0x2C0);
        f2b8 = *(f32 *)(v + 0x2B8);
        w464 = *(s32 *)(v + 0x464);
        w468 = *(s32 *)(v + 0x468);
        w454 = *(s32 *)(v + 0x454);
        func_00388440(v + 0x294, 0, 0x1D8);
        *(f32 *)(v + 0x2B4) = f2b4;
        *(s32 *)(v + 0x2C0) = w2c0;
        *(f32 *)(v + 0x2B8) = f2b8;
        *(s32 *)(v + 0x468) = w468;
        *(s32 *)(v + 0x464) = w464;
        *(s32 *)(v + 0x454) = w454;
        *(s32 *)(v + 0x2A0) = 2;
        func_003C26C8(m);
        func_L01_00458A70(m, 0.0008333333535119891f, 0.05000000447034836f, 0.0017453293548896909f, 0.10471976548433304f);
        *(f32 *)(v + 0x1B0) = 1.3f;
        *(f32 *)(v + 0x1AC) = 2.5f;
        *(f32 *)(v + 0x1A8) = 1.0f;
        *(s32 *)(v + 0x44C) = n;
        *(f32 *)(v + 0x30) = *(f32 *)(v + 0x2B4);
        *(s16 *)(v + 0x34) = *(f32 *)(v + 0x2B4);
    }
    return m;
}
/* localdecomp:end func_L40_004208A8 */
