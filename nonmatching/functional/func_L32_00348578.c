/* functional: high. VU0 helpers (vec_*_ba) per draft; near-miss only in register allocation and cvt round trip; behaviour identical. Needs -mvu0-use-vf0-vf2 flag to compile vu0.h helpers. Spline point on a Vec4 curve (count, then points) at parameter t. */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_445208;
void func_L32_00423E78(f32 t, Vec_445208 *out, Vec_445208 *start, Vec_445208 *end, Vec_445208 *bow, Vec_445208 *far);

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
            func_L32_00423E78(f - (f32)(s32)f, out, (Vec_445208 *)((u8 *)curve + off + 0x10), (Vec_445208 *)((u8 *)curve + off + 0x20), &tmp0, &tmp1);
        }
    }
}
