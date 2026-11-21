#include "common.h"

/* NTSC-U counterpart of func_L08_00406AB0 (src/levels/shared/L08_00406AB0.c) */
/* localdecomp:start func_L08_004038A8 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00406AB0;
typedef struct { V_00406AB0 a, b; } P_00406AB0;
typedef struct { u8 pad[0xD4]; u8 *bytes; } G_00406AB0;
extern G_00406AB0 D_L08_0021EB18_004038A8;
extern u8 D_L08_001D66B0_004038A8;
extern s32 func_003BD668(void *, s32);
extern void func_0037E2F0(void *, f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_003886C0(void *, void *, void *, f32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);

s32 func_L08_004038A8(void *source, s32 color1, s32 color2, s32 count, f32 low, f32 high, f32 scale) {
    V_00406AB0 a, b, c;
    s32 total = func_003BD668(source, 0);
    s32 lo, hi, i, j;
    f32 inv;
    u8 *out;
    P_00406AB0 *p;

    if (total != 0) {
        lo = (s32)(scale * 10.0f);
        hi = (s32)(scale * 15.0f);
        inv = 1.0f / scale;
        p = (P_00406AB0 *)0x70000000;
        for (i = 0; i < total; i++, p++) {
            for (j = 0; j < count; j++) {
                if (p->b.w == 0.0f) {
                    s32 n, k;
                    f32 size;
                    a = p->a;
                    a.w = 1.0f;
                    func_0037E2F0(&b, 0.0f, p->a.w);
                    vec_add_ab(&a, &a, &b);
                    n = (s32)func_L01_00440918(2.0f, 5.0f);
                    size = func_0037E250(low, high) * p->a.w;
                    k = func_0037E208(lo, hi);
                    func_L01_0046DCB8(&a, &D_L08_001D66B0_004038A8, k, color1, n, 127, 127, size * 210000.0f, 2100.0f, inv * -3.0f * 0.00027777778f, 1);
                    n = -(n * 2);
                    k = func_0037E208(lo, hi);
                    out = func_L01_0046DCB8(&a, &D_L08_001D66B0_004038A8, k, color2, n, 48, 48, size * 6.0f * 210000.0f, 4200.0f, inv * -3.0f * 0.00027777778f, 0);
                    if (out) {
                        out[2] = D_L08_0021EB18_004038A8.bytes[0];
                    }
                } else {
                    s32 n, k;
                    f32 size;
                    a = p->a;
                    b = p->b;
                    a.w = 1.0f;
                    b.w = 1.0f;
                    func_003886C0(&c, &a, &b, func_0037E250(0.0f, 1.0f));
                    c.x += func_0037E250(-p->a.w * 0.4f, p->a.w * 0.4f);
                    c.y += func_0037E250(-p->a.w * 0.4f, p->a.w * 0.4f);
                    c.z += func_0037E250(-p->a.w * 0.4f, p->a.w * 0.4f);
                    n = (s32)func_L01_00440918(2.0f, 5.0f);
                    size = inv * (func_0037E250(low, high) * p->a.w);
                    k = func_0037E208(lo, hi);
                    func_L01_0046DCB8(&c, &D_L08_001D66B0_004038A8, k, color1, n, 127, 127, size * 210000.0f, 2100.0f, inv * -3.0f * 0.00027777778f, 1);
                    n = -(n * 2);
                    k = func_0037E208(lo, hi);
                    out = func_L01_0046DCB8(&c, &D_L08_001D66B0_004038A8, k, color2, n, 48, 48, size * 6.0f * 210000.0f, 4200.0f, inv * -3.0f * 0.00027777778f, 0);
                    if (out) {
                        out[2] = D_L08_0021EB18_004038A8.bytes[0];
                    }
                }
            }
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L08_004038A8 */
