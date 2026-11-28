/* func_L12_003D73C0 (Claude wave 14 r70, 2026-11-28). First draft kept here. */
/* func_L12_003D73C0 (776 B, levels 12/18/29), first draft (wave 14 r70). It cannot compile under its
 * file's line: src/levels/shared/L12_003D72E8.c is "-O2 -G8 -fopt-stack -mno-check-zero-division", but
 * retail is VU0 macro code (lqc2/vsub.xyz/vadd.xyz/sqc2 on vf1/vf2, the include/vu0.h helpers need
 * -mvu0-use-vf0-vf2) whose jal delay slots after the sequences stay nop (@ps2as), and the file's
 * func_L12_003D72E8 block declares `extern void func_L12_003D73C0(void);` while retail reads the
 * object from $a0 (it is the draw callback func_L01_00404808 registers with the object).
 * Measured with tools/check.py --no-context --flags "-mvu0-use-vf0-vf2 @ps2as" (the line of
 * L12_003D4B18.c, which this file was cut from): 14 diff at level 12. Levers found: the colour table as
 * one 2-D sdata array D_001DF010_sda[][3] (gives retail's gp base plus %hi/%lo of +1/+2), loads in b, g, r
 * order, colours stored k[3]..k[0] (as func_L03_003B6DF8), the uv store order below, the clamp as an
 * inline conditional on s32 colours, the 500.0f bump before the first vsub. Left: the first vector group
 * has vf1/vf2 swapped (retail keeps b's vsub result in vf2 across the pos copy to 0xD0, which it stores
 * before b), and the second colour word's two shifted terms take v0/v1 the other way round. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L12_003D73C0 */
typedef struct {
    vu0_v4 q[4];
    s32 k[4];
    f32 e0[4];
    f32 f0[4];
    u8 pad[0x20];
} S_003D73C0;

extern s32 D_L12_001DF840;
extern u8 D_001DF010_sda[][3] __attribute__((section(".sdata")));
__asm__(".extern D_001DF010_sda, 4");
extern vu0_v4 D_L12_001E2700;

void func_L12_003D73C0(u8 *self)
{
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_003D2DA0(void *, s32, s32);
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    S_003D73C0 obj;
    vu0_v4 t;
    s32 idx;
    s32 g;
    s32 bl;
    s32 r;
    u32 col;
    f32 step;
    f32 *p;
    s32 i;
    s32 n;

    idx = *(s32 *)(*(u8 **)(self + 0x68) + 0x44);
    bl = D_001DF010_sda[idx][0];
    g = D_001DF010_sda[idx][1];
    r = D_001DF010_sda[idx][2];
    func_003D93B0(&obj, 0x17, 0, 0x80);
    col = 0x40000000 | (r << 16) | (g << 8) | bl;
    obj.k[3] = col;
    obj.k[2] = col;
    obj.k[1] = col;
    obj.k[0] = col;
    obj.e0[0] = 0.0f;
    obj.e0[1] = 0.0f;
    obj.e0[3] = 1.0f;
    obj.e0[2] = 0.0f;
    obj.f0[2] = 5.0f;
    obj.f0[1] = 0.0f;
    obj.f0[3] = 1.0f;
    obj.f0[0] = 5.0f;
    step = (f32)(D_L12_001DF840 % 10) / 10.0f;
    p = &obj.e0[0];
    for (i = 3; i >= 0; i--) {
        *p = *p - step;
        if (*p <= 7.0f) {
            *p = *p + 7.0f;
        }
        p += 2;
    }
    a = *(vu0_v4 *)(self + 0x10);
    a.z = a.z + 500.0f;
    vec_sub_ba(&b, self + 0x10, &D_L12_001E2700);
    vec_copy(&t, self + 0x10);
    vec_sub_ba(&c, &a, &t);
    func_0038CE90(&d, &b, &c);
    func_0038CF68(&d, &d, 2.0f);
    vec_add_ba(&obj.q[0], self + 0x10, &d);
    vec_sub_ab(&obj.q[1], self + 0x10, &d);
    vec_add_ba(&obj.q[2], &a, &d);
    vec_sub_ab(&obj.q[3], &a, &d);
    func_003D2DA0(&obj, 0, 0);

    func_003D93B0(&obj, 0xE, 1, 0x80);
    col = 0x40000000 | (r << 16) | (g << 8) | (bl + 0x20 < 0x100 ? bl + 0x20 : 0xFF);
    obj.k[3] = col;
    obj.k[2] = col;
    obj.k[1] = col;
    obj.k[0] = col;
    obj.e0[0] = 0.0f;
    obj.e0[1] = 0.0f;
    obj.e0[2] = 0.0f;
    obj.e0[3] = 1.0f;
    obj.f0[0] = 1.0f;
    obj.f0[1] = 0.0f;
    obj.f0[2] = 1.0f;
    obj.f0[3] = 1.0f;
    func_0038CF68(&d, &d, 6.0f);
    vec_add_ba(&obj.q[0], self + 0x10, &d);
    vec_sub_ab(&obj.q[1], self + 0x10, &d);
    vec_add_ba(&obj.q[2], &a, &d);
    vec_sub_ab(&obj.q[3], &a, &d);
    func_003D2DA0(&obj, 0, 0);
}
/* localdecomp:end func_L12_003D73C0 */
