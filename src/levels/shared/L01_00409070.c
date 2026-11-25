#include "common.h"

/* localdecomp:start func_L01_00409070 */
#include "vu0.h"
typedef int Quad_00409070 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_00409070;
typedef struct { Vec_00409070 a, b; } Scratch_00409070;
extern u8 D_L01_001D66B0[8];
typedef struct { u8 pad[0xD4]; u8 *texture; } Textures_00409070;
extern Textures_00409070 D_L01_00221098[];
extern s32 func_003C2B88(void *, void *);
extern void func_00382580(void *, f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_0038CDF8(void *, void *, void *, f32);
s32 func_L01_00409070(void *arg0, s32 arg1, s32 arg2) {
    Vec_00409070 a, b, c;
    s32 count = func_003C2B88(arg0, 0);
    Scratch_00409070 *p;
    s32 i;
    s32 t;
    s32 n;
    u8 *out;
    if (count == 0) return 0;
    p = (Scratch_00409070 *)0x70000000;
    for (i = 0; i < count; i++, p++) {
        if (p->b.w == 0.0f) {
            f32 f, g;
            *(Quad_00409070 *)&a = *(Quad_00409070 *)&p->a;
            a.w = 1.0f;
            func_00382580(&b, 0.0f, p->a.w);
            vec_add_ab(&a, &a, &b);
            t = func_L01_00443A18(2.0f, 5.0f);
            f = func_003824E0(0.7f, 1.0f) * p->a.w;
            func_L01_004713C8(&a, D_L01_001D66B0, (func_00382498(10, 15) * 5 + 2) / 6, arg1, t, 0x7F, 0x7F, f * 210000.0f, 2100.0f, -0.0012f, 1);
            t = -(t * 2);
            n = func_00382498(10, 15);
            g = f * 6.0f;
            out = func_L01_004713C8(&a, D_L01_001D66B0, (n * 5 + 2) / 6, arg2, t, 0x30, 0x30, g * 210000.0f, 4200.0f, -0.0012f, 0);
            if (out) out[2] = *D_L01_00221098[0].texture;
        } else {
            f32 f, g;
            *(Quad_00409070 *)&a = *(Quad_00409070 *)&p->a;
            *(Quad_00409070 *)&b = *(Quad_00409070 *)&p->b;
            a.w = 1.0f;
            b.w = 1.0f;
            func_0038CDF8(&c, &a, &b, func_003824E0(0.0f, 1.0f));
            c.x += func_003824E0(-p->a.w * 0.4f, p->a.w * 0.4f);
            c.y += func_003824E0(-p->a.w * 0.4f, p->a.w * 0.4f);
            c.z += func_003824E0(-p->a.w * 0.4f, p->a.w * 0.4f);
            t = func_L01_00443A18(2.0f, 5.0f);
            f = func_003824E0(0.7f, 1.0f) * p->a.w;
            func_L01_004713C8(&c, D_L01_001D66B0, (func_00382498(10, 15) * 5 + 2) / 6, arg1, t, 0x7F, 0x7F, f * 210000.0f, 2100.0f, -0.0012f, 1);
            t = -(t * 2);
            n = func_00382498(10, 15);
            g = f * 6.0f;
            out = func_L01_004713C8(&c, D_L01_001D66B0, (n * 5 + 2) / 6, arg2, t, 0x30, 0x30, g * 210000.0f, 4200.0f, -0.0012f, 0);
            if (out) out[2] = *D_L01_00221098[0].texture;
        }
    }
    return 1;
}
/* localdecomp:end func_L01_00409070 */
