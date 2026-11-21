#include "common.h"

/* NTSC-U counterpart of func_L07_003BC6C0 (src/levels/07_annihilation_nation/L07_003BC4D8.c) */
extern void func_L07_003BB470(void *);

/* localdecomp:start func_L07_003BADB0 */
extern u8 D_L07_001E1EC0_003BADB0[];
extern u8 D_L07_001D66B0_003BADB0[] __attribute__((section(".sdata")));
extern s32 D_L07_001DEF40_003BADB0;
__asm__(".extern D_L07_001DEF40_003BADB0, 16");
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern u8 *func_L01_00444358(void *, s32, s32);
extern s32 func_L01_0044FCD0(void *, void *, s32, s32, s32);
extern f32 func_00388730(void *, void *);
extern f32 func_003887A0(void *);
extern f32 func_00388A28(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_L07_003BB200(void *, s32);
extern s32 func_L01_0032FE90_003BADB0(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L01_004412D0(void *, s32, s32);
extern void func_L07_003BB470(void *);
extern s32 func_L01_0044F5E8(void *, void *, s32);
extern void func_L01_004538E0(void *, s32);
extern void func_L01_004539A8(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L07_003BADB0(u8 *o) {
    u8 *s = *(u8 **)(o + 0x68);
    u8 *u;
    u8 *v;
    f32 pitch;
    f32 yaw;
    s32 ia;
    f32 fa;

    if (o[0x31] != 0) {
        if (func_L01_0040C018(D_L07_001E1EC0_003BADB0, o + 0x10) < 576.0f) {
            func_L01_00444188(o);
            o[0x6F] = 0x16;
        }
    }
    u = func_L01_00444358(o, 0x10000, 0);
    if (func_L01_0044FCD0(o, s + 0x160, 0, 0, 0) != 0) {
        if (u != 0) {
            v = u + 0x10;
            if (0.0f < func_00388730(v, v)) {
                pitch = -func_00388A28(func_003887A0(v), *(f32 *)(u + 0x18));
                if (pitch > 0.34906584f) {
                    pitch = 0.34906584f;
                } else if (pitch < 0.0f) {
                    pitch = 0.0f;
                }
                yaw = func_00388A28(*(f32 *)(u + 0x10), *(f32 *)(u + 0x14));
                func_0037E4B8(s + 0xD0, 1.0f, yaw, pitch);
                func_L07_003BB200(o, 0xE);
                return;
            }
        }
        func_L01_0032FE90_003BADB0(o + 0x10, 0, 5, 10, 10, 3, 20, 0, 0.3f, 0.0f, 0.0f, 2.0f,
                          0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_L01_0044ED60(o, 0x1F, D_L07_001D66B0_003BADB0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_004412D0(o, 0, 3);
        func_L07_003BB470(o);
        return;
    }
    if (s[0x14E] != 0 || s[0x150] != 0 || s[0x12E] == 2) {
        func_L01_004412D0(o, 0, 3);
        func_L07_003BB470(o);
        return;
    }
    func_L01_0044F5E8(o, s + 0x120, 0);
    if (s[0x14F] != 0) {
        func_L01_004538E0(o, 5);
        if ((D_L07_001DEF40_003BADB0 & 0xF) == (((s32)o >> 8) & 0xF)) {
            ia = o[0x20] >= 7 ? *(s32 *)(s + 0x288) : *(s32 *)(s + 0x280);
            fa = o[0x20] >= 7 ? *(f32 *)(s + 0x28C) : *(f32 *)(s + 0x284);
            func_L01_004539A8(o, ia, 0, 0, 0, 0, 3, 0, 0, 0, fa, 10.0f, 1.0f);
        }
    } else {
        func_L01_004538E0(o, 3);
        if ((D_L07_001DEF40_003BADB0 & 0xF) == (((s32)o >> 8) & 0xF)) {
            ia = o[0x20] >= 7 ? *(s32 *)(s + 0x288) : *(s32 *)(s + 0x280);
            fa = o[0x20] >= 7 ? *(f32 *)(s + 0x28C) : *(f32 *)(s + 0x284);
            func_L01_004539A8(o, ia, 0, 0, 0, 0, 1, 0, 0, 0, fa, 10.0f, 1.0f);
        }
    }
    if (o[0x31] != 0) {
        if (func_L01_0040C018(D_L07_001E1EC0_003BADB0, o + 0x10) < 576.0f) {
            func_L01_00444188(o);
            o[0x6F] = 0x16;
        }
    }
}
/* localdecomp:end func_L07_003BADB0 */
