/* NTSC-U draft (Claude wave K): C of func_L14_00361C00, the NTSC-U twin of func_L14_00362D30, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 439 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L14_00361C00", whose code is not the PAL one).
 * Worker's note: 439 raw diff lines, 112 aligned insns differ of 502 (register-blind: only 37 structural; yours 500 insns vs retail 502), draft near/func_L14_00361C00.medium.c compiles and has retail's whole structure; PAL line already has vu0 + @ps2as. NEEDS divs row ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L14_00362D30 (src/levels/14_koros/L14_003622D0.c) */
/* localdecomp:start func_L14_00361C00 */
#include "vu0.h"

extern s32 D_001DD878_sda;
__asm__(".extern D_001DD878_sda, 4");
extern f32 D_001DD9E8_sda;
__asm__(".extern D_001DD9E8_sda, 4");
extern f32 D_001DD9F0_sda;
__asm__(".extern D_001DD9F0_sda, 4");
extern f32 D_001DD9EC_sda;
__asm__(".extern D_001DD9EC_sda, 4");
extern f32 D_001DD9BC_sda;
__asm__(".extern D_001DD9BC_sda, 4");
extern f32 D_001DD9B8_sda;
__asm__(".extern D_001DD9B8_sda, 4");
extern f32 D_001DD9F4_sda;
__asm__(".extern D_001DD9F4_sda, 4");
extern f32 D_001DD9F8_sda;
__asm__(".extern D_001DD9F8_sda, 4");
extern f32 D_001DD9FC_sda;
__asm__(".extern D_001DD9FC_sda, 4");
extern f32 D_001DDA04_sda;
__asm__(".extern D_001DDA04_sda, 4");
extern s32 D_001DDA00_sda;
__asm__(".extern D_001DDA00_sda, 4");
extern f32 D_001DDA08_sda;
__asm__(".extern D_001DDA08_sda, 4");
extern f32 D_001DDA0C_sda;
__asm__(".extern D_001DDA0C_sda, 4");
extern f32 D_001DDA10_sda;
__asm__(".extern D_001DDA10_sda, 4");
extern s32 D_001DDA14_sda;
__asm__(".extern D_001DDA14_sda, 4");
extern s32 D_001DDA18_sda;
__asm__(".extern D_001DDA18_sda, 4");
extern s32 D_001DDA1C_sda;
__asm__(".extern D_001DDA1C_sda, 4");
extern s32 D_001DDA20_sda;
__asm__(".extern D_001DDA20_sda, 4");
extern f32 D_001DDA24_sda;
__asm__(".extern D_001DDA24_sda, 4");
extern s32 D_001DD9E0_sda;
__asm__(".extern D_001DD9E0_sda, 4");
extern s32 D_001DD9E4_sda;
__asm__(".extern D_001DD9E4_sda, 4");
extern f32 D_001DD9D0_sda;
__asm__(".extern D_001DD9D0_sda, 4");
extern f32 D_001DD9D4_sda;
__asm__(".extern D_001DD9D4_sda, 4");
extern f32 D_001DD9D8_sda;
__asm__(".extern D_001DD9D8_sda, 4");
extern f32 D_001DD9C4_sda;
__asm__(".extern D_001DD9C4_sda, 4");
extern f32 D_001DD9C8_sda;
__asm__(".extern D_001DD9C8_sda, 4");
extern f32 D_001DD9CC_sda;
__asm__(".extern D_001DD9CC_sda, 4");
extern s32 D_001DD978_sda;
__asm__(".extern D_001DD978_sda, 4");
extern s32 D_001DD998_sda;
__asm__(".extern D_001DD998_sda, 4");
extern s32 D_001DD958_sda;
__asm__(".extern D_001DD958_sda, 4");
extern vu0_v4 D_L14_001E20C0;

extern void func_L14_00360BF8(u8 *, u8 *, void *, void *);
extern f32 func_003887C8(void *, void *);
extern void func_00388758(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00462FD0(void *, void *, s32, s32, s32, s32, f32);
extern void func_L14_00361AC8(u8 *, u8 *, s32);
extern void func_L14_00361920(u8 *, u8 *, void *, void *, void *, void *, f32, f32);
extern void func_L14_00361AF8(u8 *, u8 *, void *, void *, void *, void *, f32);
extern void func_003A3EF0(s32, long);
extern s32 func_00384EC0(s32);
extern void func_00388018(void);

void func_L14_00361C00(u8 *self) {
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
    t = (1.0f - (f32)*(s32 *)(o + 0x14) / (f32)D_001DD878_sda) * 0.75f;
    if (1.0f < t) {
        return;
    }
    func_L14_00360BF8(self, o, &v0, &v10);
    dist = func_003887C8(&v0, o + 0x230);
    vec_sub_ba(&v20, &D_L14_001E20C0, &v0);
    func_00388758(&v30, &v20, &v10);
    func_00388830(&v30, &v30, 1.0f);
    if (t < D_001DD9E8_sda) {
        t = t / D_001DD9E8_sda;
        a = D_001DD9EC_sda + (D_001DD9F0_sda - D_001DD9EC_sda) * t;
        b = a * D_001DD9BC_sda;
        a = a * D_001DD9B8_sda;
    } else {
        t = (t - D_001DD9E8_sda) / (1.0f - D_001DD9E8_sda);
        a = D_001DD9F4_sda + (D_001DD9F8_sda - D_001DD9F4_sda) * t;
        b = a * D_001DD9BC_sda;
        a = a * D_001DD9B8_sda;
        if (D_001DD9FC_sda < t) {
            t = (t - D_001DD9FC_sda) / (1.0f - D_001DD9FC_sda);
            vec_sub_ab(&v70, o + 0x230, &v0);
            if (D_001DDA04_sda < dist) {
                func_00388830(&v70, &v70, D_001DDA04_sda);
                n = D_001DDA00_sda;
            } else {
                n = (s32)((f32)D_001DDA00_sda * (dist / D_001DDA04_sda));
            }
            func_003886E8(&v70, &v70, 1.0f / (f32)(D_001DDA00_sda + 1));
            func_003886E8(&v60, &v70, t);
            vec_add_ab(&v60, &v60, &v0);
            if (n > 0) {
                t = 1.0f;
                do {
                    n--;
                    func_003886E8(&v80, &v10, func_0037E250(t - D_001DDA08_sda, D_001DDA08_sda + t));
                    vec_add_ab(&v80, &v60, &v80);
                    func_003886E8(&v90, &v10, func_0037E250(D_001DDA0C_sda, D_001DDA10_sda) * 0.016666668f);
                    func_L01_00462FD0(&v80, &v90, D_001DDA14_sda, D_001DDA18_sda,
                                      func_0037E208(D_001DDA1C_sda, D_001DDA20_sda), 1, D_001DDA24_sda * 210000.0f);
                    vec_add_ab(&v60, &v60, &v70);
                } while (n != 0);
            }
        }
    }
    func_L14_00361AC8(self, o, D_001DD9E0_sda);
    fa = *(f32 *)(o + 0x38) + D_001DD9D0_sda;
    fb = *(f32 *)(o + 0x3C) + D_001DD9D4_sda;
    fc = *(f32 *)(o + 0x40) + D_001DD9D0_sda * D_001DD9D8_sda;
    fd = *(f32 *)(o + 0x44) + D_001DD9D4_sda * D_001DD9D8_sda;
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
    func_003A3EF0(8, 0);
    func_003A3EF0(0x14, 0xFF9000000260L);
    func_003A3EF0(0x47, 0x513F1);
    func_003A3EF0(6, func_00384EC0(*(s32 *)(o + 0x34) + 0x64));
    func_00388018();
    *(vu0_q *)&v40 = *(vu0_q *)&v0;
    func_003886E8(&v50, &v10, D_001DD9C4_sda);
    vec_add_ab(&v50, &v50, &v0);
    t = D_001DD9C4_sda;
    func_L14_00361AC8(self, o, D_001DD9E0_sda);
    func_L14_00361920(self, o, &v30, &v40, &v50, &D_001DD978_sda, b, a);
    func_L14_00361AF8(self, o, &u0, &u1, &D_001DD958_sda, &D_001DD978_sda, t);
    func_L14_00361AC8(self, o, D_001DD9E4_sda);
    func_L14_00361920(self, o, &v30, &v40, &v50, &D_001DD998_sda, b, a);
    func_L14_00361AF8(self, o, &u2, &u3, &D_001DD958_sda, &D_001DD998_sda, t);
    func_L14_00361920(self, o, &v30, &v40, &v50, &D_001DD998_sda, -b, -a);
    func_L14_00361AF8(self, o, &u4, &u5, &D_001DD958_sda, &D_001DD998_sda, t);
    c = 0.0f;
    c = c + D_001DD9C4_sda;
    lim = dist - 0.1f;
    if (c < lim) {
        do {
            step = dist - c;
            if (D_001DD9C8_sda * D_001DD9CC_sda < step) {
                step = D_001DD9C8_sda * D_001DD9CC_sda;
            }
            func_003886E8(&v40, &v10, c);
            c = c + step;
            vec_add_ab(&v40, &v0, &v40);
            func_003886E8(&v50, &v10, c);
            vec_add_ab(&v50, &v50, &v0);
            func_L14_00361AC8(self, o, D_001DD9E0_sda);
            func_L14_00361920(self, o, &v30, &v40, &v50, &D_001DD978_sda, a, a);
            func_L14_00361AF8(self, o, &u0, &u1, &D_001DD958_sda, &D_001DD978_sda, step);
            func_L14_00361AC8(self, o, D_001DD9E4_sda);
            func_L14_00361920(self, o, &v30, &v40, &v50, &D_001DD998_sda, a, a);
            func_L14_00361AF8(self, o, &u2, &u3, &D_001DD958_sda, &D_001DD998_sda, step);
            func_L14_00361920(self, o, &v30, &v40, &v50, &D_001DD998_sda, -a, -a);
            func_L14_00361AF8(self, o, &u4, &u5, &D_001DD958_sda, &D_001DD998_sda, step);
        } while (c < lim);
    }
    func_003A3EF0(0x47, 0x5360B);
}
/* localdecomp:end func_L14_00361C00 */
