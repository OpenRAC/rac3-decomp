#include "common.h"

/* localdecomp:start func_L01_00373438 */
/* Level 1's copy of func_L39_00565860's routine: colour from a global, no size factor. */
#include "vu0.h"

typedef struct {
    f32 u, v;
} UV_00373438;

typedef struct {
    vu0_v4 v[4];
    s32 col[4];
    UV_00373438 uv[4];
    unsigned long l70, tag, l80, l88;
} S_00373438;

extern f32 func_L01_00443A18(f32, f32);
extern unsigned long func_00389598(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);
extern vu0_v4 D_L01_001E29C0;
extern f32 D_L01_001DD9E8[] __attribute__((section(".sdata")));
extern f32 D_L01_001DD9EC[] __attribute__((section(".sdata")));
extern s32 D_L01_001DD9D8;
__asm__(".extern D_L01_001DD9D8, 4");
extern s32 D_L01_001DD9E0;
__asm__(".extern D_L01_001DD9E0, 4");

void func_L01_00373438(u8 *self, vu0_v4 unused)
{
    u8 *obj = *(u8 **)(self + 0x68);
    S_00373438 s;
    vu0_v4 a, b, c, t, r;
    f32 k = 0.65f;
    f32 x;
    s32 i, col;
    s32 j;

    x = *(f32 *)(obj + 0x38);
    if (x > 32.0f) {
        k = (1.0f - (x - 32.0f) / 6.0f) * k;
        if (k < 0.001f)
            k = 0.001f;
    }

    vec_sub_ba(&c, obj, obj + 0x10);
    vec_sub_ba(&a, obj, &D_L01_001E29C0);
    vec_sub_ba(&b, obj + 0x10, &D_L01_001E29C0);
    func_0038CE90(&a, &a, &c);
    func_0038CF68(&a, &a, (func_L01_00443A18(0.1f, 0.3f) + 0.65f) * k);
    func_0038CE90(&b, &b, &c);
    func_0038CF68(&b, &b, (func_L01_00443A18(0.1f, 0.3f) + 0.65f) * k);
    s.tag = func_00389598(0x3E);
    s.l80 = 0xFF9000000260UL;
    s.l70 = 0;
    s.l88 = ((unsigned long)D_L01_001DD9D8 << 32) | 0x48;
    col = D_L01_001DD9E0;
    s.col[3] = col;
    s.col[2] = col;
    s.col[1] = col;
    s.col[0] = col;
    for (i = 0; i < 4; i++) {
        s.uv[i].u = D_L01_001DD9E8[2 * i];
        s.uv[i].v = D_L01_001DD9EC[2 * i];
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
    vec_sub_ba(&a, obj, &D_L01_001E29C0);
    vec_sub_ba(&b, obj + 0x10, &D_L01_001E29C0);
    func_0038CE90(&a, &a, &c);
    func_0038CF68(&a, &a, (func_L01_00443A18(0.05f, 0.15f) + 0.325f) * k);
    func_0038CE90(&b, &b, &c);
    func_0038CF68(&b, &b, (func_L01_00443A18(0.05f, 0.15f) + 0.325f) * k);
    s.tag = func_00389598(0x3F);
    s.l80 = 0xFF9000000260UL;
    s.l70 = 0;
    s.l88 = ((unsigned long)D_L01_001DD9D8 << 32) | 0x48;
    s.col[3] = 0x60DDDDDD;
    s.col[2] = 0x60DDDDDD;
    s.col[1] = 0x60DDDDDD;
    s.col[0] = 0x60DDDDDD;
    for (j = 0; j < 4; j++) {
        s.uv[j].u = D_L01_001DD9E8[2 * j];
        s.uv[j].v = D_L01_001DD9EC[2 * j];
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
/* localdecomp:end func_L01_00373438 */

/* localdecomp:start func_L01_003738E0 */
void func_L01_003738E0(void *position)
{
    extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32,
        f32, f32, f32, f32,
        s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    func_L01_003303B8(position, 0, 5, 0, 5, 5, 0, 0,
        0.4f, 0.0f, 0.0f, 0.0f,
        0, 0, 0, 0, 0, 0, 0x10000, 0,
        0x00F78E38, 0x00F76300, 0x00FF7F40, 0x00FF2000,
        0x00FF8F00, 0x00FF6430, 0x7FFFA060, 0x28FF0000, 0x00FF6430, 0);
}
/* localdecomp:end func_L01_003738E0 */

/* localdecomp:start func_L01_003739B8 */
void func_L01_003739B8(void) {

}
/* localdecomp:end func_L01_003739B8 */

INCLUDE_ASM("asm/levels", func_L01_003739C0);

INCLUDE_ASM("asm/levels", func_L01_00373F78);
