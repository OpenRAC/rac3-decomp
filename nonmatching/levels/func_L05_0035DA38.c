/* func_L05_0035DA38 (PAL, level 5 shared code, file L05_0035D560.c): 172 differences
 * (tools/check.py, level 05) with its file's flags. Started from Flavius's functional draft
 * (nonmatching/functional/func_L05_0035DA38.c, 268 differences): s * t computed at the hb setup, the loop
 * test written as retail's `i < n + 1`, the first colour words as one chain, the a.v[2..3] -> a.v[0..1]
 * copy right after a's draw call (b's stays at the loop end), the colour words of the loop in ascending
 * stores, and the colour global read at $gp+0xEA4 (D_L05_001DD754; the functional draft names 001DD794).
 * Still differs: (1) retail hoists both first-segment colours (0x303064FF and 0x0C3064FF) out of the loop
 * and spills them to 0x188/0x18C($sp); this C hoists only the first, so the loop's code shifts; (2) the
 * vec_sub_ba operand roles in the loop: retail loads p[i] into $vf1 and puts the result in $vf2
 * (vsub.xyz $vf2, $vf2, $vf1), this C the reverse, the same VU0 register-role difference as
 * func_L05_0035AFB8. Promises, 2026-11-21. */
#include "common.h"
#include "vu0.h"
typedef struct { vu0_v4 v[4]; s32 c[4]; f32 uv[8]; long t70, t78, t80, t88; } Q_35DA38;
extern void func_003D93B0(void *, s32, s32, long);
extern void func_003D2DA0(void *, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern vu0_v4 D_L05_001E2680;
extern u8 D_001A4EC0[];
__asm__(".extern D_L05_001DD754, 4");
extern u32 D_L05_001DD754;

void func_L05_0035DA38(vu0_v4 *p, s32 n, u32 col_a, u32 col_b, f32 s, f32 t) {
    Q_35DA38 a;
    Q_35DA38 b;
    vu0_v4 m[4];
    vu0_v4 ha;
    vu0_v4 hb;
    s32 i;

    func_003D93B0(&a, 0x1E, 1, 0x80);
    a.c[0] = a.c[1] = a.c[2] = a.c[3] = col_a;
    a.uv[0] = 0.0f;
    a.uv[1] = 0.0f;
    a.uv[2] = 0.0f;
    a.uv[3] = 1.0f;
    a.uv[4] = 1.0f;
    a.uv[5] = 0.0f;
    a.uv[6] = 1.0f;
    a.uv[7] = 1.0f;
    func_003D93B0(&b, 0x2B, 1, 0x80);
    b.c[0] = b.c[1] = b.c[2] = b.c[3] = col_b;
    b.uv[0] = 0.0f;
    b.uv[1] = 0.0f;
    b.uv[2] = 0.0f;
    b.uv[3] = 1.0f;
    b.uv[4] = 1.0f;
    b.uv[5] = 0.0f;
    b.uv[6] = 1.0f;
    b.uv[7] = 1.0f;
    m[3] = p[0];
    vec_sub_ab(&m[0], &D_L05_001E2680, &m[3]);
    func_0038CF68(&m[0], &m[0], 1.0f);
    func_0038CE90(&m[1], &m[0], D_001A4EC0);
    func_0038CF68(&m[1], &m[1], 1.0f);
    func_0038CE90(&m[2], &m[1], &m[0]);
    *(vu0_q *)&ha = 0;
    *(vu0_q *)&hb = 0;
    ha.w = 1.0f;
    ha.z = s;
    hb.z = s * t;
    hb.w = 1.0f;
    vec_sub_ba(&m[0], &p[1], &p[0]);
    func_0038CF68(&m[0], &m[0], 1.0f);
    vec_sub_ba(&m[1], &D_L05_001E2680, &p[0]);
    func_0038CE90(&m[2], &m[1], &m[0]);
    func_0038CF68(&m[2], &m[2], 1.0f);
    func_0038CE90(&m[1], &m[0], &m[2]);
    m[3] = p[0];
    a.v[0] = ha;
    func_0038CE20(&a.v[1], &a.v[0], -1.0f);
    func_0038D028(&a.v[0], &a.v[0], m);
    func_0038D028(&a.v[1], &a.v[1], m);
    b.v[0] = hb;
    func_0038CE20(&b.v[1], &b.v[0], -1.0f);
    func_0038D028(&b.v[0], &b.v[0], m);
    func_0038D028(&b.v[1], &b.v[1], m);
    for (i = 1; i < n + 1; i++) {
        a.v[2] = ha;
        func_0038CE20(&a.v[3], &a.v[2], -1.0f);
        vec_sub_ba(&m[0], &p[i + 1], &p[i]);
        func_0038CF68(&m[0], &m[0], 1.0f);
        vec_sub_ba(&m[1], &D_L05_001E2680, &p[i]);
        func_0038CE90(&m[2], &m[1], &m[0]);
        func_0038CF68(&m[2], &m[2], 1.0f);
        func_0038CE90(&m[1], &m[0], &m[2]);
        m[3] = p[i];
        func_0038D028(&a.v[2], &a.v[2], m);
        func_0038D028(&a.v[3], &a.v[3], m);
        if (i == 1) {
            a.c[0] = 0x303064FF;
            a.c[1] = 0x303064FF;
        } else if (i == 2) {
            a.c[0] = D_L05_001DD754;
            a.c[1] = D_L05_001DD754;
            a.c[2] = 0x200000FF;
            a.c[3] = 0x200000FF;
        } else if (i == 3) {
            a.c[0] = 0x200000FF;
            a.c[1] = 0x200000FF;
            a.c[2] = 0x200000FF;
            a.c[3] = 0x200000FF;
        } else if (i == 4) {
            a.c[0] = 0x200000FF;
            a.c[1] = 0x200000FF;
            a.c[2] = D_L05_001DD754;
            a.c[3] = D_L05_001DD754;
        }
        func_003D2DA0(&a, 0, 0);
        a.v[0] = a.v[2];
        a.v[1] = a.v[3];
        b.v[2] = hb;
        func_0038CE20(&b.v[3], &b.v[2], -1.0f);
        func_0038D028(&b.v[2], &b.v[2], m);
        func_0038D028(&b.v[3], &b.v[3], m);
        if (i == 1) {
            b.c[0] = 0x0C3064FF;
            b.c[1] = 0x0C3064FF;
        } else if (i == 2) {
            b.c[0] = 0x0C0000FF;
            b.c[1] = 0x0C0000FF;
            b.c[2] = 0x040000FF;
            b.c[3] = 0x040000FF;
        } else if (i == 3) {
            b.c[0] = 0x040000FF;
            b.c[1] = 0x040000FF;
            b.c[2] = 0x040000FF;
            b.c[3] = 0x040000FF;
        } else if (i == 4) {
            b.c[0] = 0x040000FF;
            b.c[1] = 0x040000FF;
            b.c[2] = 0x0C0000FF;
            b.c[3] = 0x0C0000FF;
        }
        func_003D2DA0(&b, 0, 0);
        b.v[0] = b.v[2];
        b.v[1] = b.v[3];
    }
}
