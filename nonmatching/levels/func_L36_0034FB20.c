/* func_L36_0034FB20: near miss, level 36 (Vidcomic 1 Special Edition). 15 differences. Needs the config/levels/divs_nops.txt row 'func_L36_0034FB20 0 0 0 0 0 0 2 0 0' (not committed); L36_0034E8C0.c has -mvu0-use-vf0-vf2. Everything else is retail's (sqrt.s through sqrt_asm, the clamp written out with both arms re-evaluated, the half length taken inside the expression, a float-placement search for func_L31_003478E8); left: retail keeps size in $f22 and the clamp result m in $f23, ours the other way round (regalloc.py: m, 5 refs over 19 insns, outranks size, 10 refs over 93); a separate fraction, a separate root, declaration order and the ternary form tried */
#include "vu0.h"
__asm__(".extern D_L36_001DD35C, 4");
__asm__(".extern D_L36_001DD350, 4");
__asm__(".extern D_L36_001DD354, 4");
__asm__(".extern D_L36_001DD378, 4");
__asm__(".extern D_L36_001DD420, 4");
__asm__(".extern D_L36_001DD374, 4");
__asm__(".extern D_L36_001DD3D0, 4");
__asm__(".extern D_L36_001DD3DC, 4");
__asm__(".extern D_L36_001DD3B8, 4");
__asm__(".extern D_L36_001DD41C, 4");
extern s32 D_L36_001DD35C;
extern s32 D_L36_001DF6C0;
extern f32 D_L36_001DD350;
extern f32 D_L36_001DD354;
extern s32 D_L36_001DD378;
extern f32 D_L36_001DD420;
extern f32 D_L36_001DD374;
extern f32 D_L36_001DD3D0;
extern f32 D_L36_001DD3DC;
extern f32 D_L36_001DD3B8;
extern f32 D_L36_001DD41C;
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L31_003478E8(f32, f32, f32, u8 *, u8 *, f32, f32, f32, f32, u8 *, s32);
void func_L36_0034FB20(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 p;
    f32 size;
    f32 k;
    f32 r;
    f32 lim;
    f32 h;
    f32 t;
    f32 m;
    f32 dist;

    size = (f32)(D_L36_001DF6C0 % D_L36_001DD35C) / (f32)D_L36_001DD35C;
    size = func_003C4088(D_L36_001DD354, D_L36_001DD350, func_0038D098(func_0038DB48(size * 6.2831855f)) * 0.5f + 0.5f);
    p = *(vu0_v4 *)(s + 0xB0);
    k = D_L36_001DD420;
    p.z = p.z + D_L36_001DD374 * func_0038D0B0(func_0038DB48((f32)(D_L36_001DF6C0 % D_L36_001DD378) * 6.2831855f / (f32)D_L36_001DD378));
    vec_sub_ba(&e, &p, a0 + 0x10);
    dist = func_0038CE68(&e, s + 0xC0);
    func_0038CE20(&a, &e, dist / func_0038CE68(&e, &e));
    vec_sub_ab(&b, s + 0xC0, &a);
    if (0.0f < func_0038CEA8(&a)) {
        r = func_0038CEA8(&e) / func_0038CEA8(&a);
    } else {
        r = 10000.0f;
    }
    lim = D_L36_001DD3D0 * size;
    if (lim < func_0038CEA8(&b) * 2.0f / r) {
        m = D_L36_001DD3D0 * size;
    } else {
        m = func_0038CEA8(&b) * 2.0f / r;
    }
    size = sqrt_asm(size * size - m * m);
    t = func_0038CEA8(&a);
    h = func_0038CEA8(&a) / size * (t * 0.5f) + t * 0.5f;
    func_0038CF68(&d, &b, m);
    func_0038CE20(&d, &d, -1.0f);
    func_0038CF68(&c, &e, size);
    if (func_0038CEA8(&e) < h) {
        if (0.0f < func_0038CE68(&a, &e)) {
            func_0038CE20(&c, &c, -1.0f);
        }
    }
    vec_add_ba(s + 0xC0, s + 0xC0, &d);
    vec_add_ab(s + 0xC0, s + 0xC0, &c);
    func_L31_003478E8(D_L36_001DD3B8, D_L36_001DD3DC * *(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24), k,
                      a0, a0 + 0x10, k, k, D_L36_001DD41C, 0.0f, s + 0xC0, 0);
}
