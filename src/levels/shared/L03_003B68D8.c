#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L03_003B68D8);

INCLUDE_ASM("asm/levels", func_L03_003B6CB8);

/* localdecomp:start func_L03_003B6DF8 */
typedef struct S_003B6DF8 {
    vu0_v4 v[4];
    s32 c[4];
    f32 z0;
    f32 z1;
    f32 z2;
    f32 g0;
    f32 g1;
    f32 z3;
    f32 g2;
    f32 g3;
    u8 pad70[0x20];
} S_003B6DF8;
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);
extern vu0_v4 D_L03_001D7C90[];
__asm__(".extern D_L03_001DEA70, 4");
extern f32 D_L03_001DEA70;

void func_L03_003B6DF8(u8 *a0, s32 a1, s32 c, s32 a3, f32 size, f32 off, f32 rot) {
    S_003B6DF8 s;
    vu0_v4 m[4];
    vu0_v4 t;
    vu0_v4 d;
    vu0_v4 r[3];
    s32 i;

    func_003D93B0(&s, a1, a3, 0x80);
    s.c[3] = c;
    s.c[2] = c;
    s.c[1] = c;
    s.c[0] = c;
    s.z0 = 0.0f;
    s.z1 = 0.0f;
    s.z2 = 0.0f;
    s.g0 = 1.0f;
    s.g1 = 1.0f;
    s.z3 = 0.0f;
    s.g2 = 1.0f;
    s.g3 = 1.0f;
    *(vu0_q *)&m[3] = *(vu0_q *)(a0 + 0x10);
    *(vu0_q *)&m[0] = *(vu0_q *)(a0 + 0xD0);
    *(vu0_q *)&m[1] = *(vu0_q *)(a0 + 0xC0);
    *(vu0_q *)&m[2] = *(vu0_q *)(a0 + 0xE0);
    *(vu0_q *)&t = *(vu0_q *)(a0 + 0xE0);
    func_0038CF68(&t, &t, D_L03_001DEA70);
    vec_add_ab(&m[3], &t, &m[3]);
    if (rot != 0.0f) {
        *(vu0_q *)&d = 0;
        d.x = rot;
        func_0038D308(r, &d);
        func_0038D5F0(m, m, r);
    }
    func_0038CE20(&d, m, off);
    vec_add_ab(&m[3], &m[3], &d);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&s.v[i], &D_L03_001D7C90[i], size);
        func_0038D028(&s.v[i], &s.v[i], m);
    }
    func_003D2DA0(&s, 0, 1);
}
/* localdecomp:end func_L03_003B6DF8 */

INCLUDE_ASM("asm/levels", func_L03_003B6F98);

INCLUDE_ASM("asm/levels", func_L03_003B7190);

/* localdecomp:start func_L03_003B7458 */
extern void func_003C2F58(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_003C48A8(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D308(void *, void *);
__asm__(".extern D_L03_001DEA3C, 4");
extern s32 D_L03_001DEA3C;
__asm__(".extern D_L03_001DEA40, 4");
extern s32 D_L03_001DEA40;
__asm__(".extern D_L03_001DEA44, 4");
extern s32 D_L03_001DEA44;
__asm__(".extern D_L03_001DEA48, 4");
extern f32 D_L03_001DEA48;
__asm__(".extern D_L03_001DEA4C, 4");
extern f32 D_L03_001DEA4C;
__asm__(".extern D_L03_001DEA50, 4");
extern f32 D_L03_001DEA50;

void func_L03_003B7458(u8 *a0) {
    u8 *v;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 t;
    vu0_v4 m[3];

    v = *(u8 **)(a0 + 0x68);
    func_003C2F58(*(s32 *)(v + 0x28), *(s32 *)(v + 0x30), v + 0x10);
    func_003C2F58(*(s32 *)(v + 0x28), *(s32 *)(v + 0x30) + 0x20, v);
    *(f32 *)(v + 0x24) += *(f32 *)(v + 0x20);
    func_003C2F58(*(s32 *)(v + 0x28), 0x40, &t);
    vec_sub_ab(&b, &t, v + 0x10);
    func_0038CF68(&b, &b, D_L03_001DEA4C);
    vec_sub_ab(&a, v, v + 0x10);
    func_0038CF68(&c, &a, D_L03_001DEA48);
    func_0038CF68(&a, &a, *(f32 *)(v + 0x24));
    vec_add_ba(a0 + 0x10, v + 0x10, &a);
    func_0038CE90(&d, &b, &c);
    func_0038CF68(&d, &d, D_L03_001DEA50);
    func_0038CE68(&b, &c);
    func_0038CE68(&c, &d);
    func_0038CE68(&d, &b);
    *(vu0_q *)&m[D_L03_001DEA3C] = *(vu0_q *)&c;
    *(vu0_q *)&m[D_L03_001DEA40] = *(vu0_q *)&b;
    *(vu0_q *)&m[D_L03_001DEA44] = *(vu0_q *)&d;
    func_003C48A8(m, a0 + 0xF0);
    *(f32 *)(a0 + 0xF0) = func_0038DAB8(*(f32 *)(a0 + 0xF0), 1.5707964f);
    func_0038D308(a0 + 0xC0, a0 + 0xF0);
}
/* localdecomp:end func_L03_003B7458 */
