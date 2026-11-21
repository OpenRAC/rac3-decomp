/* functional: high. Port of the NTSC-U draft re-read line by line against the PAL asm: PAL names/addresses (gp offsets are NTSC -0x40), the 0.02f (0x3CA3D70B) particle scale instead of NTSC 1/60, and t*(1.0f/X) in the first ramp as retail does. Compiles with the file flags; not byte-exact (register allocation). */
#include "vu0.h"

__asm__(".extern D_L14_001DD9A8, 4");
extern f32 D_L14_001DD9A8;
__asm__(".extern D_L14_001DD9B0, 4");
extern f32 D_L14_001DD9B0;
__asm__(".extern D_L14_001DD9AC, 4");
extern f32 D_L14_001DD9AC;
__asm__(".extern D_L14_001DD97C, 4");
extern f32 D_L14_001DD97C;
__asm__(".extern D_L14_001DD978, 4");
extern f32 D_L14_001DD978;
__asm__(".extern D_L14_001DD9B4, 4");
extern f32 D_L14_001DD9B4;
__asm__(".extern D_L14_001DD9B8, 4");
extern f32 D_L14_001DD9B8;
__asm__(".extern D_L14_001DD9BC, 4");
extern f32 D_L14_001DD9BC;
__asm__(".extern D_L14_001DD9C4, 4");
extern f32 D_L14_001DD9C4;
__asm__(".extern D_L14_001DD9C8, 4");
extern f32 D_L14_001DD9C8;
__asm__(".extern D_L14_001DD9CC, 4");
extern f32 D_L14_001DD9CC;
__asm__(".extern D_L14_001DD9D0, 4");
extern f32 D_L14_001DD9D0;
__asm__(".extern D_L14_001DD9E4, 4");
extern f32 D_L14_001DD9E4;
__asm__(".extern D_L14_001DD990, 4");
extern f32 D_L14_001DD990;
__asm__(".extern D_L14_001DD994, 4");
extern f32 D_L14_001DD994;
__asm__(".extern D_L14_001DD998, 4");
extern f32 D_L14_001DD998;
__asm__(".extern D_L14_001DD984, 4");
extern f32 D_L14_001DD984;
__asm__(".extern D_L14_001DD988, 4");
extern f32 D_L14_001DD988;
__asm__(".extern D_L14_001DD98C, 4");
extern f32 D_L14_001DD98C;
__asm__(".extern D_L14_001DD838, 4");
extern s32 D_L14_001DD838;
__asm__(".extern D_L14_001DD9C0, 4");
extern s32 D_L14_001DD9C0;
__asm__(".extern D_L14_001DD9D4, 4");
extern s32 D_L14_001DD9D4;
__asm__(".extern D_L14_001DD9D8, 4");
extern s32 D_L14_001DD9D8;
__asm__(".extern D_L14_001DD9DC, 4");
extern s32 D_L14_001DD9DC;
__asm__(".extern D_L14_001DD9E0, 4");
extern s32 D_L14_001DD9E0;
__asm__(".extern D_L14_001DD9A0, 4");
extern s32 D_L14_001DD9A0;
__asm__(".extern D_L14_001DD9A4, 4");
extern s32 D_L14_001DD9A4;
__asm__(".extern D_L14_001DD918, 16");
extern s32 D_L14_001DD918;
__asm__(".extern D_L14_001DD938, 16");
extern s32 D_L14_001DD938;
__asm__(".extern D_L14_001DD958, 16");
extern s32 D_L14_001DD958;
extern vu0_v4 D_L14_001E20C0;

extern void func_L14_00361D00(u8 *, u8 *, void *, void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_L01_00436710(s32, s32);
extern s32 func_L01_00466588(void *, void *, u32, u32, s32, s32, f32);
extern void func_L14_00362BF8(u8 *, u8 *, s32);
extern void func_L01_0036B670(u8 *, u8 *, void *, void *, void *, void *, f32, f32);
extern void func_L14_00362C28(u8 *, u8 *, void *, void *, void *, void *, f32);
extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038C750(void);

void func_L14_00362D30(u8 *self) {
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    vu0_v4 v70;
    vu0_v4 v80;
    vu0_v4 v90;
    f32 u0, u1, u2, u3, u4, u5;
    u8 *o;
    f32 t;
    f32 a;
    f32 b;
    f32 dist;
    f32 c;
    f32 lim;
    f32 step;
    f32 fa;
    f32 fb;
    f32 fc;
    f32 fd;
    s32 n;

    if (self[0x20] != 5) {
        return;
    }
    o = *(u8 **)(self + 0x68);
    t = (1.0f - (f32)*(s32 *)(o + 0x14) / (f32)D_L14_001DD838) * 0.75f;
    if (1.0f < t) {
        return;
    }
    func_L14_00361D00(self, o, &v0, &v10);
    dist = func_0038CF00(&v0, o + 0x230);
    vec_sub_ba(&v20, &D_L14_001E20C0, &v0);
    func_0038CE90(&v30, &v20, &v10);
    func_0038CF68(&v30, &v30, 1.0f);
    if (t < D_L14_001DD9A8) {
        t = t * (1.0f / D_L14_001DD9A8);
        a = D_L14_001DD9AC + (D_L14_001DD9B0 - D_L14_001DD9AC) * t;
        b = a * D_L14_001DD97C;
        a = a * D_L14_001DD978;
    } else {
        t = (t - D_L14_001DD9A8) / (1.0f - D_L14_001DD9A8);
        a = D_L14_001DD9B4 + (D_L14_001DD9B8 - D_L14_001DD9B4) * t;
        b = a * D_L14_001DD97C;
        a = a * D_L14_001DD978;
        if (D_L14_001DD9BC < t) {
            t = (t - D_L14_001DD9BC) / (1.0f - D_L14_001DD9BC);
            vec_sub_ab(&v70, o + 0x230, &v0);
            if (D_L14_001DD9C4 < dist) {
                func_0038CF68(&v70, &v70, D_L14_001DD9C4);
                n = D_L14_001DD9C0;
            } else {
                n = (s32)((f32)D_L14_001DD9C0 * (dist / D_L14_001DD9C4));
            }
            func_0038CE20(&v70, &v70, 1.0f / (f32)(D_L14_001DD9C0 + 1));
            func_0038CE20(&v60, &v70, t);
            vec_add_ab(&v60, &v60, &v0);
            if (n > 0) {
                t = 1.0f;
                do {
                    n--;
                    func_0038CE20(&v80, &v10, func_003824E0(t - D_L14_001DD9C8, D_L14_001DD9C8 + t));
                    vec_add_ab(&v80, &v60, &v80);
                    func_0038CE20(&v90, &v10, func_003824E0(D_L14_001DD9CC, D_L14_001DD9D0) * 0.020000001f);
                    func_L01_00466588(&v80, &v90, D_L14_001DD9D4, D_L14_001DD9D8,
                                      func_L01_00436710(D_L14_001DD9DC, D_L14_001DD9E0), 1, D_L14_001DD9E4 * 210000.0f);
                    vec_add_ab(&v60, &v60, &v70);
                } while (n != 0);
            }
        }
    }
    func_L14_00362BF8(self, o, D_L14_001DD9A0);
    fa = *(f32 *)(o + 0x38) + D_L14_001DD990;
    fb = *(f32 *)(o + 0x3C) + D_L14_001DD994;
    fc = *(f32 *)(o + 0x40) + D_L14_001DD990 * D_L14_001DD998;
    fd = *(f32 *)(o + 0x44) + D_L14_001DD994 * D_L14_001DD998;
    fa = fa - (f32)(s32)fa;
    fb = fb - (f32)(s32)fb;
    fc = fc - (f32)(s32)fc;
    fd = fd - (f32)(s32)fd;
    *(f32 *)(o + 0x38) = fa;
    u1 = fa;
    *(f32 *)(o + 0x3C) = fb;
    u0 = fb;
    *(f32 *)(o + 0x40) = fc;
    u5 = fc;
    u3 = fc;
    *(f32 *)(o + 0x44) = fd;
    u4 = fd;
    u2 = fd;
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260L);
    func_003A9440(0x47, 0x513F1);
    func_003A9440(6, func_00389598(*(s32 *)(o + 0x34) + 0x64));
    func_0038C750();
    *(vu0_q *)&v40 = *(vu0_q *)&v0;
    func_0038CE20(&v50, &v10, D_L14_001DD984);
    vec_add_ab(&v50, &v50, &v0);
    t = D_L14_001DD984;
    func_L14_00362BF8(self, o, D_L14_001DD9A0);
    func_L01_0036B670(self, o, &v30, &v40, &v50, &D_L14_001DD938, b, a);
    func_L14_00362C28(self, o, &u0, &u1, &D_L14_001DD918, &D_L14_001DD938, t);
    func_L14_00362BF8(self, o, D_L14_001DD9A4);
    func_L01_0036B670(self, o, &v30, &v40, &v50, &D_L14_001DD958, b, a);
    func_L14_00362C28(self, o, &u2, &u3, &D_L14_001DD918, &D_L14_001DD958, t);
    func_L01_0036B670(self, o, &v30, &v40, &v50, &D_L14_001DD958, -b, -a);
    func_L14_00362C28(self, o, &u4, &u5, &D_L14_001DD918, &D_L14_001DD958, t);
    c = 0.0f;
    c = c + D_L14_001DD984;
    lim = dist - 0.1f;
    if (c < lim) {
        do {
            step = dist - c;
            if (D_L14_001DD988 * D_L14_001DD98C < step) {
                step = D_L14_001DD988 * D_L14_001DD98C;
            }
            func_0038CE20(&v40, &v10, c);
            c = c + step;
            vec_add_ab(&v40, &v0, &v40);
            func_0038CE20(&v50, &v10, c);
            vec_add_ab(&v50, &v50, &v0);
            func_L14_00362BF8(self, o, D_L14_001DD9A0);
            func_L01_0036B670(self, o, &v30, &v40, &v50, &D_L14_001DD938, a, a);
            func_L14_00362C28(self, o, &u0, &u1, &D_L14_001DD918, &D_L14_001DD938, step);
            func_L14_00362BF8(self, o, D_L14_001DD9A4);
            func_L01_0036B670(self, o, &v30, &v40, &v50, &D_L14_001DD958, a, a);
            func_L14_00362C28(self, o, &u2, &u3, &D_L14_001DD918, &D_L14_001DD958, step);
            func_L01_0036B670(self, o, &v30, &v40, &v50, &D_L14_001DD958, -a, -a);
            func_L14_00362C28(self, o, &u4, &u5, &D_L14_001DD918, &D_L14_001DD958, step);
        } while (c < lim);
    }
    func_003A9440(0x47, 0x5360B);
}
