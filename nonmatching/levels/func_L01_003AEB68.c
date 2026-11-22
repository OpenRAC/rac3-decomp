/* PAL near miss (Sonnet round 20, b33 h4b): 41 raw / 23 aligned / 17 registers-masked differences in the file's flags (S + @ps2as + vu flag).
 * Laser-beam style drawer (family of func_L01_003AE1A0 / func_L07_003CB1F8): fade alpha from the distance to the camera, scroll counter
 * s->f1C, two GS quads whose corners are d -/+ e and a -/+ g (e, g = (point - camera) x f normalised to 0.4, f = a - d), uv tables
 * D_L01_001DE4F8 / 4FC with +/- scroll, colours through func_0038DBD8, then two func_003D9508 sparks at the object position.
 * The corner temporaries u (sp+0xf0) / t (sp+0xe0) are function-level locals (`vec_sub_ba(&u, ..); t = u; q.p[k] = t;`, see func_L01_0035A6B0);
 * `q.c[1] = q.c[0] = func_0038DBD8(..)` chains give retail's store order; `D_L01_001DBCA0` as a plain scalar gives the `lui` / `lui $at` pair.
 * Per-site vu0.h helper forms were swept greedily (site 0 = vec_add_ab(&d, &a, &d)); all permutations of the first-half and second-half vector statements
 * were tried (current order is the best). Left: the scheduler puts the argument moves of the first func_0038CE90 call (move a2,s1 / a0,s0 / a1,s0 and the
 * s3 / s7 pointer copies) among the lqc2 / sqc2 of the camera copies in retail, after them in ours, and ours keeps the obj+0x10 pointer in $s7 (retail $fp, with
 * s7 = copy of &f); the two scroll loops load `lwc1 $f0,0x1c($s2)` first in retail. Tried: pointer variables for &e / &f / &g (worse), an inline cross+normalise helper (worse),
 * u/v statement order and a local copy of the scroll in the loops (no better). */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_003AEB68 */
typedef struct { f32 u, v; } UV_003AEB68;
typedef struct { vu0_v4 p[4]; s32 c[4]; UV_003AEB68 uv[4]; long l70, l78, l80, l88; } Q_003AEB68;
typedef struct { u8 p0[0x1C]; f32 f1C; } S_003AEB68;
extern s32 D_L01_001DBCA0;
extern f32 D_L01_001DE4F8_003AEB68[2];
extern f32 D_L01_001DE4FC_003AEB68[2];
extern u8 D_L01_001E29C0_003AEB68[];
extern s32 D_L01_001DE4E0;
extern s32 D_L01_001DE4D8;
extern s32 D_L01_001DE4DC;
extern s32 D_L01_001DE4E8;
extern s32 D_L01_001DE4EC;
extern f32 D_L01_001DE4F0;
extern s32 D_L01_001DE4E4;
__asm__(".extern D_L01_001DE4E0, 4");
__asm__(".extern D_L01_001DE4D8, 4");
__asm__(".extern D_L01_001DE4DC, 4");
__asm__(".extern D_L01_001DE4E8, 4");
__asm__(".extern D_L01_001DE4EC, 4");
__asm__(".extern D_L01_001DE4F0, 4");
__asm__(".extern D_L01_001DE4E4, 4");
extern f32 func_0038CF00(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern f32 func_00382538(void);

void func_L01_003AEB68(u8 *o) {
    vu0_v4 a;
    Q_003AEB68 q;
    vu0_v4 e;
    vu0_v4 g;
    vu0_v4 f;
    vu0_v4 d;
    vu0_v4 t;
    vu0_v4 u;
    vu0_v4 cam1;
    vu0_v4 cam2;
    vu0_v4 cam3;
    S_003AEB68 *s;
    f32 alpha;
    f32 dist;
    f32 sc;
    s32 i;
    s32 c1;
    s32 c2;
    s32 x;

    s = *(S_003AEB68 **)(o + 0x68);
    dist = func_0038CF00(o + 0x10, D_L01_001E29C0_003AEB68);
    if ((f32)*(s16 *)(o + 0x32) < dist) {
        alpha = 1.0f - (dist - (f32)*(s16 *)(o + 0x32)) * 10.0f;
        if (alpha < 0.01f) {
            return;
        }
    } else {
        alpha = 1.0f;
    }
    sc = s->f1C + 0.15f;
    D_L01_001DBCA0 |= 1;
    s->f1C = sc;
    if (4.0f <= sc) {
        s->f1C = sc - 4.0f;
    }
    a = *(vu0_v4 *)(o + 0x10);
    func_0038CF68(&d, s, -4.0f);
    vec_add_ab(&d, &a, &d);
    vec_copy(&cam1, D_L01_001E29C0_003AEB68);
    vec_copy(&cam2, D_L01_001E29C0_003AEB68);
    vec_sub_ba(&f, &a, &d);
    vec_sub_ba(&e, &a, &cam1);
    vec_sub_ab(&g, &d, &cam2);
    func_0038CE90(&e, &e, &f);
    func_0038CF68(&e, &e, 0.4f);
    func_0038CE90(&g, &g, &f);
    func_0038CF68(&g, &g, 0.4f);
    q.l78 = func_00389598(D_L01_001DE4DC);
    q.l80 = 0xFF9000000260L;
    q.l88 = 0x8000000048L;
    q.l70 = 0;
    q.c[1] = q.c[0] = func_0038DBD8(0, 0x806040, alpha);
    x = D_L01_001DE4EC;
    q.c[3] = q.c[2] = func_0038DBD8(x & 0xFF000000, x, alpha);
    for (i = 0; i < 4; i++) {
        q.uv[i].u = D_L01_001DE4F8_003AEB68[2 * i] + s->f1C;
        q.uv[i].v = D_L01_001DE4FC_003AEB68[2 * i];
    }
    vec_sub_ba(&u, &d, &e);
    t = u;
    q.p[0] = t;
    vec_add_ba(&u, &d, &e);
    t = u;
    q.p[1] = t;
    vec_sub_ba(&u, &a, &g);
    t = u;
    q.p[2] = t;
    vec_add_ba(&u, &a, &g);
    t = u;
    q.p[3] = t;
    func_003D2DA0(&q, 0, 0);

    vec_sub_ba(&f, &a, &d);
    vec_copy(&cam3, D_L01_001E29C0_003AEB68);
    vec_sub_ba(&e, &a, D_L01_001E29C0_003AEB68);
    vec_sub_ab(&g, &d, &cam3);
    func_0038CE90(&e, &e, &f);
    func_0038CF68(&e, &e, 0.4f);
    func_0038CE90(&g, &g, &f);
    func_0038CF68(&g, &g, 0.4f);
    q.l78 = func_00389598(D_L01_001DE4D8);
    q.l80 = 0xFF9000000260L;
    q.l88 = 0x8000000048L;
    q.l70 = 0;
    q.c[1] = q.c[0] = func_0038DBD8(0, 0x704020, alpha);
    x = D_L01_001DE4E8;
    q.c[3] = q.c[2] = func_0038DBD8(x & 0xFF000000, x, alpha);
    for (i = 0; i < 4; i++) {
        q.uv[i].u = D_L01_001DE4F8_003AEB68[2 * i] - s->f1C;
        q.uv[i].v = D_L01_001DE4FC_003AEB68[2 * i];
    }
    vec_sub_ba(&u, &d, &e);
    t = u;
    q.p[0] = t;
    vec_add_ba(&u, &d, &e);
    t = u;
    q.p[1] = t;
    vec_sub_ba(&u, &a, &g);
    t = u;
    q.p[2] = t;
    vec_add_ab(&u, &a, &g);
    t = u;
    q.p[3] = t;
    func_003D2DA0(&q, 0, 0);

    c1 = func_0038DBD8(D_L01_001DE4E4 & 0xFF000000, D_L01_001DE4E4, alpha);
    func_003D9508(o + 0x10, D_L01_001DE4E0, c1, 1, D_L01_001DE4F0, 0.08f, func_00382538());
    c2 = func_0038DBD8(0x81000000, 0x80808080, alpha);
    func_003D9508(o + 0x10, D_L01_001DE4E0, c2, 1, D_L01_001DE4F0 * 0.5f, 0.08f, func_00382538());
}
/* localdecomp:end func_L01_003AEB68 */
