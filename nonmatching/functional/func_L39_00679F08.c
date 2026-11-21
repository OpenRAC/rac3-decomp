/* functional: high. from asm; gp float slots named by level-39 gp 0x247FC0 (D_L39_002466xx); the last 7 rows share one loop in my C (retail unrolled); the colour constant 0x8066CCFF is an unsigned long (retail builds it with dsll); not byte exact; callee func_00594D70 is func_L01_00412BC0, func_00594C00 is func_L39_00594C00 */
#include "common.h"

extern s32 D_L39_00240300;
extern s32 D_L39_00240304;
extern f32 D_L39_002466BC;
__asm__(".extern D_L39_002466BC, 4");
extern f32 D_L39_002466B0;
__asm__(".extern D_L39_002466B0, 4");
extern f32 D_L39_002466AC;
__asm__(".extern D_L39_002466AC, 4");
extern f32 D_L39_002466B8;
__asm__(".extern D_L39_002466B8, 4");
extern f32 D_L39_002466E0;
__asm__(".extern D_L39_002466E0, 4");
extern u8 D_L39_00352CE0[];
extern void func_L01_00412BC0(f32 x, f32 y, f32 e, unsigned long col, char *s, s32 a2);
extern void func_L39_00594C00(s32 x, s32 y, unsigned long col, char *s, s32 a4);

void func_L39_00679F08(void) {
    u8 *t = D_L39_00352CE0;
    f32 W = (f32)D_L39_00240300;
    s32 x = (s32)(D_L39_002466BC * W);
    s32 w = (s32)((D_L39_002466BC + D_L39_002466B0) * W);
    f32 H = (f32)D_L39_00240304;
    s32 y;
    s32 k;

    if (t[0] == 0) {
        y = (s32)((D_L39_002466AC + D_L39_002466B8 * 0.0f) * H);
        func_L01_00412BC0((f32)x, (f32)y, D_L39_002466E0, 0x8066CCFF, (char *)(t + 0x2E1), -1);
        func_L39_00594C00(w, y, 0x8066CCFF, (char *)(t + 0x40 + (*(s32 *)(t + 0xC) << 5)), -1);
    }
    if (t[1] == 0) {
        y = (s32)((D_L39_002466AC + D_L39_002466B8) * H);
        func_L01_00412BC0((f32)x, (f32)y, D_L39_002466E0, 0x8066CCFF, (char *)(t + 0x301), -1);
        func_L39_00594C00(w, y, 0x8066CCFF, (char *)(t + 0x180), -1);
    }
    if (t[2] == 0) {
        y = (s32)((D_L39_002466AC + (D_L39_002466B8 + D_L39_002466B8)) * H);
        func_L01_00412BC0((f32)x, (f32)y, D_L39_002466E0, 0x8066CCFF, (char *)(t + 0x321), -1);
        func_L39_00594C00(w, y, 0x8066CCFF, (char *)(t + 0x1C0), -1);
    }
    if (t[3] == 0) {
        y = (s32)((D_L39_002466AC + D_L39_002466B8 * 3.0f) * H);
        func_L01_00412BC0((f32)x, (f32)y, D_L39_002466E0, 0x8066CCFF, (char *)(t + 0x341), -1);
        func_L39_00594C00(w, y, 0x8066CCFF, (char *)(t + 0x1A0), -1);
    }
    for (k = 4; k <= 10; k++) {
        static const u16 off[7] = { 0x1E0, 0x200, 0x220, 0x240, 0x261, 0x281, 0x2A1 };
        if (t[k] == 0) {
            y = (s32)((D_L39_002466AC + D_L39_002466B8 * (f32)k) * H);
            func_L01_00412BC0((f32)x, (f32)y, D_L39_002466E0, 0x8066CCFF, (char *)(t + off[k - 4]), -1);
        }
    }
}
