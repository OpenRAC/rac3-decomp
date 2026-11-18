/* PAL port (round 8) of the NTSC-U draft of func_L07_003BADB0: PAL port with the file's own flags (it already has @ps2as): 11 words off, all in the order of the a0/a1/a2 argument setup of the two big calls (func_L01_003303B8 and func_L01_00451FE0): retail sets a0, a1, a2 in order, ours puts a2 (and for the second call a2/a0 pair) first. A local for o + 0x10 is much worse (270). */
#include "common.h"
/* localdecomp:start func_L07_003BC6C0 */
extern u8 D_L07_001E1EC0[];
extern u8 D_L07_001D66B0[];
extern s32 D_L07_001DEF40;
__asm__(".extern D_L07_001DEF40, 16");
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern u8 *func_L01_00447490(void *, s32, s32);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_L07_003BCB10(void *, s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L01_004443E8(void *, s32, s32);
extern void func_L07_003BCD80(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L07_003BC6C0(u8 *o) {
    u8 *s = *(u8 **)(o + 0x68);
    u8 *u;
    u8 *v;
    f32 pitch;
    f32 yaw;
    s32 ia;
    f32 fa;

    if (o[0x31] != 0) {
        if (func_L01_0040E548(D_L07_001E1EC0, o + 0x10) < 576.0f) {
            func_L01_004472C0(o);
            o[0x6F] = 0x16;
        }
    }
    u = func_L01_00447490(o, 0x10000, 0);
    if (func_L01_00452FB0(o, s + 0x160, 0, 0, 0) != 0) {
        if (u != 0) {
            v = u + 0x10;
            if (0.0f < func_0038CE68(v, v)) {
                pitch = -func_0038D160(func_0038CED8(v), *(f32 *)(u + 0x18));
                if (pitch > 0.34906584f) {
                    pitch = 0.34906584f;
                } else if (pitch < 0.0f) {
                    pitch = 0.0f;
                }
                yaw = func_0038D160(*(f32 *)(u + 0x10), *(f32 *)(u + 0x14));
                func_00382760(s + 0xD0, 1.2f, yaw, pitch);
                func_L07_003BCB10(o, 0xE);
                return;
            }
        }
        func_L01_003303B8(o + 0x10, 0, 5, 10, 10, 3, 20, 0, 0.3f, 0.0f, 0.0f, 2.0f,
                          0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_L01_00451FE0(o, 0x1F, D_L07_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        func_L01_004443E8(o, 0, 3);
        func_L07_003BCD80(o);
        return;
    }
    if (s[0x14E] != 0 || s[0x150] != 0 || s[0x12E] == 2) {
        func_L01_004443E8(o, 0, 3);
        func_L07_003BCD80(o);
        return;
    }
    func_L01_00452860(o, s + 0x120, 0);
    if (s[0x14F] != 0) {
        func_L01_00456BD0(o, 5);
        if ((D_L07_001DEF40 & 0xF) == (((s32)o >> 8) & 0xF)) {
            ia = o[0x20] >= 7 ? *(s32 *)(s + 0x288) : *(s32 *)(s + 0x280);
            fa = o[0x20] >= 7 ? *(f32 *)(s + 0x28C) : *(f32 *)(s + 0x284);
            func_L01_00456C98(o, ia, 0, 0, 0, 0, 3, 0, 0, 0, fa, 10.0f, 1.0f);
        }
    } else {
        func_L01_00456BD0(o, 3);
        if ((D_L07_001DEF40 & 0xF) == (((s32)o >> 8) & 0xF)) {
            ia = o[0x20] >= 7 ? *(s32 *)(s + 0x288) : *(s32 *)(s + 0x280);
            fa = o[0x20] >= 7 ? *(f32 *)(s + 0x28C) : *(f32 *)(s + 0x284);
            func_L01_00456C98(o, ia, 0, 0, 0, 0, 1, 0, 0, 0, fa, 10.0f, 1.0f);
        }
    }
    if (o[0x31] != 0) {
        if (func_L01_0040E548(D_L07_001E1EC0, o + 0x10) < 576.0f) {
            func_L01_004472C0(o);
            o[0x6F] = 0x16;
        }
    }
}
/* localdecomp:end func_L07_003BC6C0 */
