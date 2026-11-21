#include "common.h"

/* NTSC-U counterpart of func_L36_0037CA40 (src/levels/36_vidcomic_1_special_edition/L36_0037BDF0.c) */
#include "vu0.h"
extern f32 func_00388770(void *);
extern f32 func_00389380(f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L36_0037B780(u8 *, vu0_v4 *, vu0_v4 *);
extern f32 func_0037E250(f32, f32);
#include "vu0.h"
extern f32 func_00389380(f32, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00389380(f32, f32);

/* localdecomp:start func_L36_0037B780 */
#include "vu0.h"
__asm__(".extern D_L36_001DE210, 4");
__asm__(".extern D_L36_001DE214, 4");
__asm__(".extern D_L36_001DE220, 4");
extern vu0_v4 D_001A4EC0;
__asm__(".extern D_L36_001DE1E0_0037B780, 4");
extern vu0_v4 D_L36_001DE1E0_0037B780[] __attribute__((section(".sdata")));
extern f32 D_L36_001DE210;
extern f32 D_L36_001DE214;
extern f32 D_L36_001DE220;
extern f32 D_L36_001DE224;
extern f32 D_L36_001DE228;
extern f32 D_L36_001E1BE0_0037B780[] __attribute__((section(".sdata")));
extern u8 *D_L36_0021F4D8_0037B780[];
extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_003888C8(void *, void *, void *);
extern void func_00388BD0(void *, void *);
extern f32 func_00389380(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0013D3E0(void);
extern void func_003BF6A8(void *, f32);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern u8 *func_L01_00462190(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, f32, f32, f32, s32, s32, s32);
void func_L36_0037B780(u8 *a0, vu0_v4 *a1, vu0_v4 *a2) {
    vu0_v4 from;
    vu0_v4 to;
    vu0_v4 vel;
    vu0_v4 pos;
    vu0_v4 step;
    vu0_v4 d;
    vu0_v4 m[3];
    vu0_v4 q;
    u8 *s;
    f32 len;
    s32 n;
    s32 i;
    s32 k = 0;

    from = *a1;
    s = *(u8 **)(a0 + 0x68);
    to = *a2;
    len = func_00388770(s);
    pos = to;
    vec_sub_ab(&step, &from, &to);
    n = len / 0.1f;
    func_00388830(&step, &step, len / (f32)n);
    for (i = 0; i < n; i++) {
        s32 spin = (s32)func_L01_00440918(1.0f, 3.0f);
        s32 life;
        s32 alpha;
        s32 rgb;
        u8 *p;
        f32 r = func_0037E250(0.1f, 0.2f);
        func_003886E8(&vel, &D_001A4EC0, -(r * 0.016666668f));
        life = func_0037E208(3, 6);
        if (func_0013D3E0() & 2) {
            alpha = 0x40;
            rgb = 0x407FFF;
        } else {
            alpha = 0x60;
            rgb = 0x4040FF;
        }
        p = func_L01_00466F98(&pos, &vel, life, alpha, rgb, spin, 63000.004f, 10000.0f, 1.0f, 0.0f, 0.0f);
        vec_add_ab(&pos, &pos, &step);
        if (p != 0) {
            p[2] = *D_L36_0021F4D8_0037B780[0x5C / 4];
            p[3] = (alpha == 0x40) ? 0x48 : 0x44;
        }
    }
    if (*(s32 *)(s + 0x34) < 0x3c && func_0037E1D8(2)) {
        s32 c;
        u8 *p;
        func_003886E8(&d, s, -0.033333335f);
        c = 0x7F80DFFF;
        func_003BF6A8(&d, 0.10000001f);
        d.z += 0.050000004f;
        if (func_0037E1D8(2)) {
            c = 0x7F407FFF;
        }
        p = func_L01_00462190(a0 + 0x10, &d, c, 0xFF, func_0037E208(10, 0x14), 0, -1, -1, 0, 94500.0f);
        if (p != 0) {
            *(f32 *)(p + 0x2C) = 0.0016666667f;
            p[2] = *D_L36_0021F4D8_0037B780[0xD4 / 4];
        }
    }
    D_L36_001E1BE0_0037B780[0] = func_00389380(D_L36_001E1BE0_0037B780[0], D_L36_001DE220 * 0.017453292f * 0.016666668f);
    D_L36_001E1BE0_0037B780[1] = func_00389380(D_L36_001E1BE0_0037B780[1], D_L36_001DE224 * 0.017453292f * 0.016666668f);
    D_L36_001E1BE0_0037B780[2] = func_00389380(D_L36_001E1BE0_0037B780[2], D_L36_001DE228 * 0.017453292f * 0.016666668f);
    func_00388BD0(m, D_L36_001E1BE0_0037B780);
    for (k = 0; k < 3; k++) {
        u8 *p;
        func_003888C8(&q, &D_L36_001DE1E0_0037B780[k], m);
        if (*(s32 *)(s + 0x34) >= 6) {
            func_00388830(&q, &q, D_L36_001DE210);
        } else {
            func_00388830(&q, &q, 0.0f);
        }
        vec_add_ab(&q, &q, a0 + 0x10);
        vec_sub_ab(&d, &q, a0 + 0x10);
        func_00388830(&d, &d, D_L36_001DE214 * 0.016666668f);
        p = func_L01_0046DCB8(&q, &d, 0xF, 0x204080, (s32)func_L01_00440918(2.0f, 5.0f), 63000.004f,
                              func_0037E250(0.119999997f, 0.180000007f) * 210000.0f, 0.0f, 0x6F, 0, 6);
        if (p != 0) {
            p[3] = func_0037E1D8(4) ? 0x48 : 0x44;
        }
    }
}
/* localdecomp:end func_L36_0037B780 */
