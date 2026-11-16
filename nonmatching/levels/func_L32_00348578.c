/* func_L32_00348578: 74 diff with --flags "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division" (the file's flags fail to compile vu0.h helpers: NEEDS-FLAGS). VU0 asm via vec_sub_ba/vec_add_ba/vec_add_ab matches; differs in register allocation (retail copies arg0 to $7 early, n in $4, idx in $6) and the final (f32)(s32)f is cvt.w.s $f12 + cvt.s.w with no mfc1/mtc1 round trip in retail. */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_445208;
void func_L01_00445208(f32 t, Vec_445208 *out, Vec_445208 *start, Vec_445208 *end, Vec_445208 *bow, Vec_445208 *far);

void func_L32_00348578(s32 *arg0, u128_t *out, f32 t) {
    s32 *curve = arg0;
    Vec_445208 tmp0, tmp1;
    s32 idx, off;
    f32 f;
    qzero(out);
    if (curve != 0) {
        s32 n = curve[0];
        if (n > 0) {
            if (n == 1) {
                *out = *(u128_t *)(curve + 4);
                return;
            }
            if (1.0f < t) t = 1.0f;
            else if (t < 0.0f) t = 0.0f;
            f = t * (f32)(n - 1);
            idx = (s32)f;
            if (n - 2 < idx) {
                *out = *(u128_t *)((u8 *)curve + n * 16);
                return;
            }
            if (idx == 0) {
                vec_sub_ba(&tmp0, (u8 *)curve + 0x10, (u8 *)curve + 0x20);
                vec_add_ba(&tmp0, &tmp0, (u8 *)curve + 0x10);
                off = 0;
            } else {
                off = idx * 16;
                *(u128_t *)&tmp0 = *(u128_t *)((u8 *)curve + off);
            }
            if (idx == curve[0] - 2) {
                u8 *e = (u8 *)curve + curve[0] * 16;
                vec_sub_ba(&tmp1, e, e - 0x10);
                vec_add_ab(&tmp1, &tmp1, e);
            } else {
                *(u128_t *)&tmp1 = *(u128_t *)((u8 *)curve + off + 0x30);
            }
            f = t * (f32)(curve[0] - 1);
            func_L01_00445208(f - (f32)(s32)f, out, (Vec_445208 *)((u8 *)curve + off + 0x10), (Vec_445208 *)((u8 *)curve + off + 0x20), &tmp0, &tmp1);
        }
    }
}
