#include "common.h"

/* localdecomp:start func_L39_00634F80 */
extern s32 *D_L39_00241120;
extern s32 D_L39_00240300;
extern s32 D_L39_00240304;
extern s32 D_L39_00241470;
extern char *func_00381FF0(s32);
extern void func_0038E150(s32);
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern void func_L01_00436020(s32, s32, f32, f32, f32, f32);
extern void func_003910C0(void *, s32, s32, s32, s32, s32, s32, s32, s32);
/* func_L39_00593468 with its floats after the integers (rac2's text call is (layout, style, text,
 * length)): the order of this function's argument moves shows it */
extern void func_L39_00593468_00634F80(void *, long, char *, s32, unsigned long, f32, f32);

void func_L39_00634F80(void) {
    s32 box[8];
    s32 d, k;
    f32 scale, kx, ky;
    s32 cx, cy, hx, hy, top, bottom, left, right;
    char *text;
    s32 old;

    if (*D_L39_00241120 >= 2) {
        d = 14;
        cx = (s32)(D_L39_00240300 * 0.47f);
        cy = (s32)(D_L39_00240304 * 0.81f);
        scale = 0.85f;
        kx = 0.255f;
        ky = 0.14f;
        k = 1;
    } else {
        d = 16;
        cx = (s32)(D_L39_00240300 * 0.465f);
        cy = (s32)(D_L39_00240304 * 0.825f);
        scale = 1.0f;
        kx = 0.25f;
        ky = 0.09f;
        k = 2;
    }
    hy = (s32)(ky * D_L39_00240304);
    hx = (s32)(kx * D_L39_00240300);
    top = cy - hy;
    left = cx - hx;
    bottom = cy + hy;
    right = cx + hx;
    text = func_00381FF0(0x1280);
    old = D_L39_00241470;
    func_0038E150(1);
    func_0038C3B0(top, bottom, left, right, 0x50, 0x500E5092);
    func_L01_00436020(0x33, 0x332299DE, top, bottom, left, right);
    func_003910C0(box, top + k, bottom + k, left + k, right + k, cx + k, cy + k, d, 3);
    func_L39_00593468_00634F80(box, (s32)0x80000000, text, -1, 0x80000000UL, scale, scale);
    func_003910C0(box, top, bottom, left, right, cx, cy, d, 3);
    func_L39_00593468_00634F80(box, (s32)0x8066CCFF, text, -1, 0x80000000UL, scale, scale);
    func_0038E150(old);
}
/* localdecomp:end func_L39_00634F80 */
