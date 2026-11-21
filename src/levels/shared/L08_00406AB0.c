#include "common.h"

/* localdecomp:start func_L08_00406AB0 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00406AB0;
typedef struct { V_00406AB0 a, b; } P_00406AB0;
typedef struct { u8 pad[0xD4]; u8 *bytes; } G_00406AB0;
extern G_00406AB0 D_L08_0021EB18;
extern u8 D_L08_001D66B0;
extern s32 func_003C2B88(void *, s32);
extern void func_00382580(void *, f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);

s32 func_L08_00406AB0(void *source, s32 color1, s32 color2, s32 count, f32 low, f32 high, f32 scale) {
    V_00406AB0 a, b, c;
    s32 total = func_003C2B88(source, 0);
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
                    func_00382580(&b, 0.0f, p->a.w);
                    vec_add_ab(&a, &a, &b);
                    n = (s32)func_L01_00443A18(2.0f, 5.0f);
                    size = func_003824E0(low, high) * p->a.w;
                    k = (func_00382498(lo, hi) * 5 + 2) / 6;
                    func_L01_004713C8(&a, &D_L08_001D66B0, k, color1, n, 127, 127, size * 210000.0f, 2100.0f, inv * -3.0f * 0.00040000002f, 1);
                    n = -(n * 2);
                    k = (func_00382498(lo, hi) * 5 + 2) / 6;
                    out = func_L01_004713C8(&a, &D_L08_001D66B0, k, color2, n, 48, 48, size * 6.0f * 210000.0f, 4200.0f, inv * -3.0f * 0.00040000002f, 0);
                    if (out) {
                        out[2] = D_L08_0021EB18.bytes[0];
                    }
                } else {
                    s32 n, k;
                    f32 size;
                    a = p->a;
                    b = p->b;
                    a.w = 1.0f;
                    b.w = 1.0f;
                    func_0038CDF8(&c, &a, &b, func_003824E0(0.0f, 1.0f));
                    c.x += func_003824E0(-p->a.w * 0.4f, p->a.w * 0.4f);
                    c.y += func_003824E0(-p->a.w * 0.4f, p->a.w * 0.4f);
                    c.z += func_003824E0(-p->a.w * 0.4f, p->a.w * 0.4f);
                    n = (s32)func_L01_00443A18(2.0f, 5.0f);
                    size = inv * (func_003824E0(low, high) * p->a.w);
                    k = (func_00382498(lo, hi) * 5 + 2) / 6;
                    func_L01_004713C8(&c, &D_L08_001D66B0, k, color1, n, 127, 127, size * 210000.0f, 2100.0f, inv * -3.0f * 0.00040000002f, 1);
                    n = -(n * 2);
                    k = (func_00382498(lo, hi) * 5 + 2) / 6;
                    out = func_L01_004713C8(&c, &D_L08_001D66B0, k, color2, n, 48, 48, size * 6.0f * 210000.0f, 4200.0f, inv * -3.0f * 0.00040000002f, 0);
                    if (out) {
                        out[2] = D_L08_0021EB18.bytes[0];
                    }
                }
            }
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L08_00406AB0 */
