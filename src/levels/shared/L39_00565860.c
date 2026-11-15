#include "common.h"

/* localdecomp:start func_L39_00565860 */
/* func_L39_00565860 log (needs -mvu0-use-vf0-vf2: vu0.h vec_sub/vec_add helpers)
 * - first draft (block 2 with a vec_copy of the camera vector): 285 diff; that 0xF0 slot is
 *   the compiler's spill of the shared D_L39_0024DE00 load, so both blocks are written alike
 * - $gp slot needs the .extern size hint; block 2's constants 0.05/0.15/0.325
 * - s.v[k] = t = r reproduces retail's lq/sq through the 0xD0 temporary
 * - uv table as two symbols (as rac2-decomp's func_0030DB88: D_001AF0A0 / D_001AF0A4), both
 *   addressed unsplit (section .sdata, like rac2's MACRO_ADDR), colours stored 3, 2, 1, 0
 * - left: the 2 nops retail has before the div.s (DIVS)
 */
#include "vu0.h"

typedef struct {
    f32 u, v;
} UV_00565860;

typedef struct {
    vu0_v4 v[4];
    s32 col[4];
    UV_00565860 uv[4];
    unsigned long l70, tag, l80, l88;
} S_00565860;

extern f32 func_L39_005B4468(f32, f32);
extern unsigned long func_L39_00589890(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);
extern vu0_v4 D_L39_0024DE00;
extern f32 D_L39_0024B568[] __attribute__((section(".sdata")));
extern f32 D_L39_0024B56C[] __attribute__((section(".sdata")));
extern s32 D_L39_0024B558;
__asm__(".extern D_L39_0024B558, 4");

void func_L39_00565860(u8 *self, vu0_v4 unused)
{
    u8 *obj = *(u8 **)(self + 0x68);
    S_00565860 s;
    vu0_v4 a, b, c, t, r;
    f32 k = 0.65f;
    f32 x;
    s32 i, col;

    x = *(f32 *)(obj + 0x38);
    if (x > 32.0f) {
        k = (1.0f - (x - 32.0f) / 6.0f) * k;
        if (k < 0.001f)
            k = 0.001f;
    }

    vec_sub_ba(&c, obj, obj + 0x10);
    vec_sub_ba(&a, obj, &D_L39_0024DE00);
    vec_sub_ba(&b, obj + 0x10, &D_L39_0024DE00);
    func_0038CE90(&a, &a, &c);
    func_0038CF68(&a, &a, *(f32 *)(self + 0x2C) * (func_L39_005B4468(0.1f, 0.3f) + 0.65f) * k);
    func_0038CE90(&b, &b, &c);
    func_0038CF68(&b, &b, *(f32 *)(self + 0x2C) * (func_L39_005B4468(0.1f, 0.3f) + 0.65f) * k);
    s.tag = func_L39_00589890(0x3E);
    s.l80 = 0xFF9000000260UL;
    s.l70 = 0;
    s.l88 = ((unsigned long)D_L39_0024B558 << 32) | 0x48;
    col = *(s32 *)(obj + 0x44);
    s.col[3] = col;
    s.col[2] = col;
    s.col[1] = col;
    s.col[0] = col;
    for (i = 0; i < 4; i++) {
        s.uv[i].u = D_L39_0024B568[2 * i];
        s.uv[i].v = D_L39_0024B56C[2 * i];
    }
    vec_sub_ba(&r, obj, &a);
    s.v[0] = t = r;
    vec_add_ba(&r, obj, &a);
    s.v[1] = t = r;
    vec_sub_ba(&r, obj + 0x10, &b);
    s.v[2] = t = r;
    vec_add_ba(&r, obj + 0x10, &b);
    s.v[3] = t = r;
    func_003D2DA0(&s, 0, 0);

    vec_sub_ba(&c, obj, obj + 0x10);
    vec_sub_ba(&a, obj, &D_L39_0024DE00);
    vec_sub_ba(&b, obj + 0x10, &D_L39_0024DE00);
    func_0038CE90(&a, &a, &c);
    func_0038CF68(&a, &a, *(f32 *)(self + 0x2C) * (func_L39_005B4468(0.05f, 0.15f) + 0.325f) * k);
    func_0038CE90(&b, &b, &c);
    func_0038CF68(&b, &b, *(f32 *)(self + 0x2C) * (func_L39_005B4468(0.05f, 0.15f) + 0.325f) * k);
    s.tag = func_L39_00589890(0x3F);
    s.l80 = 0xFF9000000260UL;
    s.l70 = 0;
    s.l88 = ((unsigned long)D_L39_0024B558 << 32) | 0x48;
    s.col[3] = 0x60DDDDDD;
    s.col[2] = 0x60DDDDDD;
    s.col[1] = 0x60DDDDDD;
    s.col[0] = 0x60DDDDDD;
    for (i = 0; i < 4; i++) {
        s.uv[i].u = D_L39_0024B568[2 * i];
        s.uv[i].v = D_L39_0024B56C[2 * i];
    }
    vec_sub_ba(&r, obj, &a);
    s.v[0] = t = r;
    vec_add_ba(&r, obj, &a);
    s.v[1] = t = r;
    vec_sub_ba(&r, obj + 0x10, &b);
    s.v[2] = t = r;
    vec_add_ab(&r, obj + 0x10, &b);
    s.v[3] = t = r;
    func_003D2DA0(&s, 0, 0);
}
/* localdecomp:end func_L39_00565860 */
