#include "common.h"

/* NTSC-U counterpart of func_L09_003DA2A8 (src/levels/09_tyhrranosis/L09_003D9E60.c) */
extern void func_L09_003D87A0(u8 *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);

/* localdecomp:start func_L09_003D87A0 */
extern f32 D_001A4C60[];
extern void func_L01_004479A8(void *, void *);
extern s32 func_003883C8(void *);
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_003BF4F8(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
void func_L09_003D87A0(u8 *a0) {
    u8 *q;
    u8 *hit;
    u8 *o;
    if (a0[0x20] == 0) {
        return;
    }
    q = *(u8 **)(a0 + 0x68);
    func_L01_004479A8(a0, q + 0x70);
    if (func_003883C8(q + 0x8C) != 0 && *(f32 *)(a0 + 0x18) - D_001A4C60[2] < 10.0f) {
        hit = (u8 *)func_L01_00444358(a0, 0x30000, 0);
        if (hit != 0 && (o = *(u8 **)(hit + 0x20)) != 0 && *(s16 *)(o + 0xAA) != 0xABC && *(s16 *)(o + 0xAA) != 0x1A17) {
            f32 dmg = *(f32 *)(hit + 0x2C);
            *(s16 *)(q + 0x8C) = 10;
            q[0x77] = 0xFF;
            *(s16 *)(q + 0x8A) -= (s32)dmg;
            func_003BF4F8(a0, q + 0x70);
            *(f32 *)(q + 0x98) = 0.2617994f;
            if (*(s16 *)(q + 0x8A) <= 0) {
                func_L01_00441FB8(a0, 2, -1);
            } else {
                func_0039FE80(1, 0, a0);
            }
        }
    }
    a0[0xA8] = 0xFF;
    *(f32 *)(q + 0x30) = (f32)*(s16 *)(q + 0x8A);
}
/* localdecomp:end func_L09_003D87A0 */
