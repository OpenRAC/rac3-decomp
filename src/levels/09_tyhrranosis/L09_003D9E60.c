#include "common.h"

INCLUDE_ASM("asm/levels", func_L09_003D9E60);

/* localdecomp:start func_L09_003DA2A8 */
extern f32 D_001A4C60[];
extern void func_L01_0044ABD0(void *, void *);
extern s32 func_0038CB00(void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003C4A40(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
void func_L09_003DA2A8(u8 *a0) {
    u8 *q;
    u8 *hit;
    u8 *o;
    if (a0[0x20] == 0) {
        return;
    }
    q = *(u8 **)(a0 + 0x68);
    func_L01_0044ABD0(a0, q + 0x70);
    if (func_0038CB00(q + 0x8C) != 0 && *(f32 *)(a0 + 0x18) - D_001A4C60[2] < 10.0f) {
        hit = (u8 *)func_L01_00447490(a0, 0x30000, 0);
        if (hit != 0 && (o = *(u8 **)(hit + 0x20)) != 0 && *(s16 *)(o + 0xAA) != 0xABC && *(s16 *)(o + 0xAA) != 0x1A17) {
            f32 dmg = *(f32 *)(hit + 0x2C);
            *(s16 *)(q + 0x8C) = 10;
            q[0x77] = 0xFF;
            *(s16 *)(q + 0x8A) -= (s32)dmg;
            func_003C4A40(a0, q + 0x70);
            *(f32 *)(q + 0x98) = 0.31415927f;
            if (*(s16 *)(q + 0x8A) <= 0) {
                func_L01_004450F0(a0, 2, -1);
            } else {
                func_003A52A0(1, 0, a0);
            }
        }
    }
    a0[0xA8] = 0xFF;
    *(f32 *)(q + 0x30) = (f32)*(s16 *)(q + 0x8A);
}
/* localdecomp:end func_L09_003DA2A8 */
