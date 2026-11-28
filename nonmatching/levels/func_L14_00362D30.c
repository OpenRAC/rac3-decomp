/* Wave 13 (r26, 2026-11-28) replaces the earlier draft of this function (NTSC-U draft of `func_L14_00361C00` (Claude wave K)). */
/* PAL near miss (wave 13 r26), the first PAL C of func_L14_00362D30 (the old draft was the NTSC-U twin
 * func_L14_00361C00's C). PAL: func_L14_00361D00 / 00362A50 / 00362BF8 / 00362C28 with the types of the
 * file's own definitions, func_0038CF00 / 0038CE90 / 0038CF68 / 0038CE20 / 003824E0 / 00382498 /
 * L01_00466588 / 003A9440 / 00389598 / 0038C750, the file's D_L14_001DD838 and D_L14_001DD988, the
 * level-14 gp slots 0x1DD978..0x1DD9E4 as D_L14_ scalars with .extern hints (the tables 0x1DD918/938/958
 * as scalars so cc1 keeps their addresses gp-relative), the first t scaled by 1.0f / D_L14_001DD9A8, and
 * the n loop as a for over i (retail's copy of n counted down). Needs a divs row
 * 'func_L14_00362D30 2 2 2 2 2 0' (checked with --divs 2,2,2,2,2,0). 182 diff; aligned, 90 rows differ
 * and nearly all are one allocation: retail gives c (zeroed in f20 before func_L14_00361D00) the first
 * saved FP register, so t, a, the 1.0 constant and b sit one register higher (f21..f24) than here
 * (f20..f23), where c lands in f24 (its long life gives it the lowest priority); the moves that feed
 * f12/f13 then schedule differently, and the n loop's t = 1.0 is a copy of the 1.0 constant in retail.
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L14_00362D30 */
__asm__(".extern D_L14_001DD838, 4");
__asm__(".extern D_L14_001DD988, 4");
__asm__(".extern D_L14_001DD918, 4");
__asm__(".extern D_L14_001DD938, 4");
__asm__(".extern D_L14_001DD958, 4");
__asm__(".extern D_L14_001DD9A8, 4");
__asm__(".extern D_L14_001DD9AC, 4");
__asm__(".extern D_L14_001DD9B0, 4");
__asm__(".extern D_L14_001DD9B4, 4");
__asm__(".extern D_L14_001DD9B8, 4");
__asm__(".extern D_L14_001DD9BC, 4");
__asm__(".extern D_L14_001DD978, 4");
__asm__(".extern D_L14_001DD97C, 4");
__asm__(".extern D_L14_001DD9C0, 4");
__asm__(".extern D_L14_001DD9C4, 4");
__asm__(".extern D_L14_001DD9C8, 4");
__asm__(".extern D_L14_001DD9CC, 4");
__asm__(".extern D_L14_001DD9D0, 4");
__asm__(".extern D_L14_001DD9D4, 4");
__asm__(".extern D_L14_001DD9D8, 4");
__asm__(".extern D_L14_001DD9DC, 4");
__asm__(".extern D_L14_001DD9E0, 4");
__asm__(".extern D_L14_001DD9E4, 4");
__asm__(".extern D_L14_001DD9A0, 4");
__asm__(".extern D_L14_001DD9A4, 4");
__asm__(".extern D_L14_001DD990, 4");
__asm__(".extern D_L14_001DD994, 4");
__asm__(".extern D_L14_001DD998, 4");
__asm__(".extern D_L14_001DD984, 4");
__asm__(".extern D_L14_001DD98C, 4");
extern f32 D_L14_001DD9A8;
extern f32 D_L14_001DD9AC;
extern f32 D_L14_001DD9B0;
extern f32 D_L14_001DD9B4;
extern f32 D_L14_001DD9B8;
extern f32 D_L14_001DD9BC;
extern f32 D_L14_001DD978;
extern f32 D_L14_001DD97C;
extern s32 D_L14_001DD9C0;
extern f32 D_L14_001DD9C4;
extern f32 D_L14_001DD9C8;
extern f32 D_L14_001DD9CC;
extern f32 D_L14_001DD9D0;
extern s32 D_L14_001DD9D4;
extern s32 D_L14_001DD9D8;
extern s32 D_L14_001DD9DC;
extern s32 D_L14_001DD9E0;
extern f32 D_L14_001DD9E4;
extern s32 D_L14_001DD9A0;
extern s32 D_L14_001DD9A4;
extern f32 D_L14_001DD990;
extern f32 D_L14_001DD994;
extern f32 D_L14_001DD998;
extern f32 D_L14_001DD984;
extern f32 D_L14_001DD98C;
extern f32 D_L14_001DD918;
extern f32 D_L14_001DD938;
extern f32 D_L14_001DD958;
extern vu0_v4 D_L14_001E20C0;

void func_L14_00362D30(u8 *self) {
    extern void func_L14_00361D00(u8 *, u8 *, void *, void *);
    extern f32 func_0038CF00(void *, void *);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_L01_00466588(void *, void *, s32, s32, s32, s32, f32);
    extern unsigned long func_00389598(s32);
    extern void func_0038C750(void);
    extern void func_L14_00362A50(f32 a, f32 b, s32 u0, s32 u1, f32 *p6, f32 *p7, f32 *p8, f32 *p9);
    extern void func_L14_00362BF8(int a, int b, int v);
    extern void func_L14_00362C28(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, f32 t);
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
    u8 *o = *(u8 **)(self + 0x68);
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
    s32 i;

    if (self[0x20] != 5) {
        return;
    }
    t = 1.0f - (f32)*(s32 *)(o + 0x14) / (f32)D_L14_001DD838;
    t = t * 0.75f;
    if (1.0f < t) {
        return;
    }
    c = 0.0f;
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
            func_0038CE20((f32 *)&v70, &v70, 1.0f / (f32)(D_L14_001DD9C0 + 1));
            func_0038CE20((f32 *)&v60, &v70, t);
            vec_add_ab(&v60, &v60, &v0);
            t = 1.0f;
            for (i = 0; i < n; i++) {
                {
                    func_0038CE20((f32 *)&v80, &v10, func_003824E0(t - D_L14_001DD9C8, D_L14_001DD9C8 + t));
                    vec_add_ab(&v80, &v80, &v60);
                    func_0038CE20((f32 *)&v90, &v10, func_003824E0(D_L14_001DD9CC, D_L14_001DD9D0) * 0.020000001f);
                    func_L01_00466588(&v80, &v90, D_L14_001DD9D4, D_L14_001DD9D8,
                                      func_00382498(D_L14_001DD9DC, D_L14_001DD9E0), 1, D_L14_001DD9E4 * 210000.0f);
                    vec_add_ab(&v60, &v60, &v70);
                }
            }
        }
    }
    func_L14_00362BF8((s32)self, (s32)o, D_L14_001DD9A0);
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
    u3 = fc;
    u5 = fc;
    *(f32 *)(o + 0x44) = fd;
    u2 = fd;
    u4 = fd;
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260UL);
    func_003A9440(0x47, 0x513F1);
    func_003A9440(6, func_00389598(*(s32 *)(o + 0x34) + 0x64));
    func_0038C750();
    *(vu0_q *)&v40 = *(vu0_q *)&v0;
    func_0038CE20((f32 *)&v50, &v10, D_L14_001DD984);
    vec_add_ab(&v50, &v50, &v0);
    t = D_L14_001DD984;
    func_L14_00362BF8((s32)self, (s32)o, D_L14_001DD9A0);
    func_L14_00362A50(b, a, (s32)self, (s32)o, (f32 *)&v30, (f32 *)&v40, (f32 *)&v50, &D_L14_001DD938);
    func_L14_00362C28((s32)self, (s32)o, (s32)&u0, (s32)&u1, (s32)&D_L14_001DD918, (s32)&D_L14_001DD938, t);
    func_L14_00362BF8((s32)self, (s32)o, D_L14_001DD9A4);
    func_L14_00362A50(b, a, (s32)self, (s32)o, (f32 *)&v30, (f32 *)&v40, (f32 *)&v50, &D_L14_001DD958);
    func_L14_00362C28((s32)self, (s32)o, (s32)&u2, (s32)&u3, (s32)&D_L14_001DD918, (s32)&D_L14_001DD958, t);
    func_L14_00362A50(-b, -a, (s32)self, (s32)o, (f32 *)&v30, (f32 *)&v40, (f32 *)&v50, &D_L14_001DD958);
    func_L14_00362C28((s32)self, (s32)o, (s32)&u4, (s32)&u5, (s32)&D_L14_001DD918, (s32)&D_L14_001DD958, t);
    c = c + D_L14_001DD984;
    lim = dist - 0.1f;
    if (c < lim) {
        do {
            step = dist - c;
            if (D_L14_001DD988 * D_L14_001DD98C < step) {
                step = D_L14_001DD988 * D_L14_001DD98C;
            }
            func_0038CE20((f32 *)&v40, &v10, c);
            c = c + step;
            vec_add_ab(&v40, &v40, &v0);
            func_0038CE20((f32 *)&v50, &v10, c);
            vec_add_ab(&v50, &v50, &v0);
            func_L14_00362BF8((s32)self, (s32)o, D_L14_001DD9A0);
            func_L14_00362A50(a, a, (s32)self, (s32)o, (f32 *)&v30, (f32 *)&v40, (f32 *)&v50, &D_L14_001DD938);
            func_L14_00362C28((s32)self, (s32)o, (s32)&u0, (s32)&u1, (s32)&D_L14_001DD918, (s32)&D_L14_001DD938, step);
            func_L14_00362BF8((s32)self, (s32)o, D_L14_001DD9A4);
            func_L14_00362A50(a, a, (s32)self, (s32)o, (f32 *)&v30, (f32 *)&v40, (f32 *)&v50, &D_L14_001DD958);
            func_L14_00362C28((s32)self, (s32)o, (s32)&u2, (s32)&u3, (s32)&D_L14_001DD918, (s32)&D_L14_001DD958, step);
            func_L14_00362A50(-a, -a, (s32)self, (s32)o, (f32 *)&v30, (f32 *)&v40, (f32 *)&v50, &D_L14_001DD958);
            func_L14_00362C28((s32)self, (s32)o, (s32)&u4, (s32)&u5, (s32)&D_L14_001DD918, (s32)&D_L14_001DD958, step);
        } while (c < lim);
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L14_00362D30 */
