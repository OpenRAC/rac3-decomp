/* functional: high. VU0 helpers (vec_*_ba) per draft; near-miss only in register allocation and cvt round trip; behaviour identical. VU0 helpers written as plain C xyz math (w lane kept as retail leaves it). Spline point on a Vec4 curve (count, then points) at parameter t. */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_445208;
static void pv_add(void *d, void *a, void *b) {
    f32 *o = (f32 *)d, *p = (f32 *)a, *q = (f32 *)b;
    f32 x = p[0] + q[0], y = p[1] + q[1], z = p[2] + q[2];
    o[0] = x; o[1] = y; o[2] = z;
}
static void pv_sub(void *d, void *a, void *b) {
    f32 *o = (f32 *)d, *p = (f32 *)a, *q = (f32 *)b;
    f32 x = p[0] - q[0], y = p[1] - q[1], z = p[2] - q[2];
    o[0] = x; o[1] = y; o[2] = z;
}
void func_L32_00423E78(f32 t, Vec_445208 *out, Vec_445208 *start, Vec_445208 *end, Vec_445208 *bow, Vec_445208 *far);

void func_L32_00348578(s32 *arg0, u128_t *out, f32 t) {
    s32 *curve = arg0;
    Vec_445208 tmp0, tmp1;
    s32 idx, off;
    f32 f;
    *out = 0;
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
                pv_sub(&tmp0, (u8 *)curve + 0x10, (u8 *)curve + 0x20);
                pv_add(&tmp0, &tmp0, (u8 *)curve + 0x10);
                off = 0;
            } else {
                off = idx * 16;
                *(u128_t *)&tmp0 = *(u128_t *)((u8 *)curve + off);
            }
            if (idx == curve[0] - 2) {
                u8 *e = (u8 *)curve + curve[0] * 16;
                pv_sub(&tmp1, e, e - 0x10);
                pv_add(&tmp1, &tmp1, e);
            } else {
                *(u128_t *)&tmp1 = *(u128_t *)((u8 *)curve + off + 0x30);
            }
            f = t * (f32)(curve[0] - 1);
            func_L32_00423E78(f - (f32)(s32)f, (Vec_445208 *)out, (Vec_445208 *)((u8 *)curve + off + 0x10), (Vec_445208 *)((u8 *)curve + off + 0x20), &tmp0, &tmp1);
        }
    }
}
