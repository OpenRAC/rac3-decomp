/* func_L24_003A4E60: level 24 near miss, 1 difference (see nonmatching/README.md). Its place is L24_003A4E60.c, which needs -mvu0-use-vf0-vf2 and @ps2as for this C (checked with --flags=-mvu0-use-vf0-vf2 --as ps2as; the file's three matched blocks still match with them). The #include "vu0.h" belongs in the file's prelude. */
#include "vu0.h"
extern u8 D_L24_001E8F40[];
extern f32 D_L24_001E8F60[];
extern f32 D_L24_001DE268;
__asm__(".extern D_L24_001DE268, 4");
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003C41A0(f32 *, f32, void *, f32, f32, f32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern s32 func_L24_003A5408(void *, void *, u8);
extern f32 func_0038D160(f32, f32);
extern s32 func_L24_0042C1C8(void *, s32, s32, f32, f32);
extern f32 func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern f32 func_0038DB48(f32);

s32 func_L24_003A4E60(u8 *p, u8 *m, f32 *tgt, f32 f) {
    f32 d[4] __attribute__((aligned(16)));
    f32 pos[4] __attribute__((aligned(16)));
    f32 t1[4] __attribute__((aligned(16)));
    f32 t2[4] __attribute__((aligned(16)));
    f32 u[4] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    f32 out[2];
    s32 r = 0;
    f32 z;
    f32 len;
    f32 l2;
    f32 s;
    f32 a;
    f32 zero;

    z = *(f32 *)(p + 0x8);
    *(f32 *)(p + 0x8) = 0.0f;
    vec_sub_ab(d, tgt, m + 0x10);
    d[2] = 0.0f;
    if (fabs_asm(d[0]) < *(f32 *)(p + 0x54) && fabs_asm(d[1]) < *(f32 *)(p + 0x54)) {
        *(f32 *)(p + 0x4C) = 0.0f;
        return 4;
    }
    len = func_0038CEA8(d);
    l2 = func_0038CEA8(p);
    func_0038CF68(d, d, 1.0f);
    out[1] = l2 * *(f32 *)(p + 0x58) + func_0038CE68(p, d) * (1.0f - *(f32 *)(p + 0x58));
    out[0] = 0.0f;
    func_003C41A0(&out[0], len, &out[1], *(f32 *)(p + 0x14), *(f32 *)(p + 0x18), *(f32 *)(p + 0x10));
    if ((len < *(f32 *)(p + 0x10) ? len : *(f32 *)(p + 0x10)) < out[0]) {
        out[0] = len < *(f32 *)(p + 0x10) ? len : *(f32 *)(p + 0x10);
    }
    qzero(u);
    *(f32 *)(p + 0x4C) = out[0];
    func_0038CF68(p, d, out[1]);
    vec_add_ab(pos, m + 0x10, p);
    zero = 0.0f;
    if (zero < *(f32 *)(p + 0x30)) {
        *(vu0_q *)t1 = *(vu0_q *)pos;
        t1[2] += *(f32 *)(p + 0x34);
        if (func_L01_003FB640(t1, 0x10, m, *(f32 *)(p + 0x30)) != 0) {
            u8 *g = D_L24_001E8F40;
            if (func_L24_003A5408(*(void **)(g + 0x18), *(void **)(p + 0x50), p[0x5C]) != 0) {
                vec_sub_ba(u, g + 0x30, pos);
                u[2] = zero;
                vec_add_ab(pos, pos, u);
            }
        }
    }
    if (0.0f < *(f32 *)(p + 0x38)) {
        *(vu0_q *)t2 = *(vu0_q *)pos;
        t2[2] += *(f32 *)(p + 0x3C);
        if (func_L01_003FB640(t2, 0x10, m, *(f32 *)(p + 0x38)) != 0) {
            u8 *g = D_L24_001E8F40;
            if (func_L24_003A5408(*(void **)(g + 0x18), *(void **)(p + 0x50), p[0x5C]) != 0) {
                vec_sub_ba(w, g + 0x30, pos);
                w[2] = zero;
                vec_add_ba(u, u, w);
                vec_add_ab(pos, pos, w);
            }
        }
    }
    if (fabs_asm(u[0]) >= *(f32 *)(p + 0x54) || fabs_asm(u[1]) >= *(f32 *)(p + 0x54)) {
        r = 2;
        *(f32 *)(p + 0x48) = func_0038D160(u[0], u[1]);
    }
    if (func_L24_0042C1C8(pos, 0, 0, *(f32 *)(p + 0x40), *(f32 *)(p + 0x44)) != 0 || p[0x5D] != 0) {
        pos[2] = *(f32 *)(m + 0x18) + (D_L24_001E8F60[2] - *(f32 *)(m + 0x18)) * D_L24_001DE268;
        vec_sub_ba(w, pos, m + 0x10);
        w[2] = 0.0f;
        func_0038CF68(w, w, 1.0f);
        s = func_0038CE68(w, p);
        if (fabs_asm(out[1]) < s) {
            s = fabs_asm(out[1]);
        } else if (s < -fabs_asm(out[1])) {
            s = -fabs_asm(out[1]);
        }
        func_0038CF68(p, p, s);
        if (fabs_asm(s) < *(f32 *)(p + 0x54)) {
            r |= 0x10;
        } else {
            r |= 1;
        }
        if (f <= -1.0e12f) {
            if (fabs_asm(*(f32 *)(p + 0x0)) >= *(f32 *)(p + 0x54) || fabs_asm(*(f32 *)(p + 0x4)) >= *(f32 *)(p + 0x54)) {
                a = func_0038D160(*(f32 *)(p + 0x0), *(f32 *)(p + 0x4));
            } else {
                a = func_0038D160(d[0], d[1]);
            }
        } else {
            a = func_0038DB48(f);
        }
        if (fabs_asm(*(f32 *)(p + 0x24)) >= *(f32 *)(p + 0x54)) {
            func_L01_00448890(m + 0xF8, p + 0x20, 0, a, *(f32 *)(p + 0x28), *(f32 *)(p + 0x2C), *(f32 *)(p + 0x24));
        } else {
            *(f32 *)(p + 0x20) = 0.0f;
        }
        *(vu0_q *)(m + 0x10) = *(vu0_q *)pos;
    } else {
        if (func_L24_0042C1C8(m + 0x10, 0, 0, *(f32 *)(p + 0x40), *(f32 *)(p + 0x44)) == 0) {
            *(f32 *)(p + 0x8) = z - *(f32 *)(p + 0x1C);
            vec_add_ba(m + 0x10, m + 0x10, p);
        }
        r |= 8;
    }
    return r;
}
