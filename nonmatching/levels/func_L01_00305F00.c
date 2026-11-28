/* func_L01_00305F00 (Claude wave 14 r58, 2026-11-28). First draft kept here. */
/* PAL near miss (wave 14 r58, 2026-11-28): first draft, 395 words differ with the file's flags (-O2 -G8
 * -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2). Written from the retail assembly
 * with nonmatching/functional/func_L01_00305F00.c for the layout: three 0x90-byte quad packets, the
 * segment basis mat[4], then v1F0, v200, cur and other in that stack order (retail 0x0-0x22F), the
 * v1F0/v200 quads cleared as 128-bit zeros, mat[3] = other before the last two transforms, the
 * texture pick as one func_00389598 call per arm (cross-jumped in retail, a conditional move
 * otherwise), the s2 colour as an if (level >= 4) / else pair of stores (retail's bnel), the v200
 * scale as `level >= 4 ? 3.0f : 6.0f` (6.0 loaded first, bnel), the ring index wrap as
 * `next = prev; if (prev < 0) next = 34;` (retail's movz) and `idx = prev < 0 ? 34 : prev` after the
 * draws (retail's movn). func_003824E0 is declared f32 (f32, f32) as the file declares it after this
 * function (an earlier 377-word version called it undeclared, which conflicts with that line).
 * Left: the %hi of D_L01_002C5600 is kept in $s1 across the first three weapon-level lookups where
 * retail rebuilds it each time (one extra move at 0x64 shifts the words after it), the scheduling of
 * the s0/s1 packet constants, the s1.m/s2.m copies before the loop, and in the loop the idx/next
 * registers ($s5/$s6) and retail's second prev >= 0 test after the draws. Tried: array, &array and
 * pointer spellings of the lookup (no change), the texture pick as one call with ?: (442), the
 * packet store orders (395-397).
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00305F00 */
#include "structs/weapon.h"
typedef struct {
    vu0_v4 m[4];
    s32 c[4];
    f32 uv[8];
    long x70, x78, x80, x88;
} Ribbon_00305F00;
typedef struct {
    vu0_v4 origin;
    u8 pad10[0x44 - 0x10];
    s32 count;
    s32 head;
    u8 pad4C[0x58 - 0x4C];
    f32 u;
    f32 v;
} Trail_00305F00;
extern u8 D_001425C0[];
extern struct WeaponRow D_L01_002C5600[];
extern vu0_v4 D_L01_001E29C0;
extern vu0_v4 *D_001DC5C4_sda;
__asm__(".extern D_001DC5C4_sda, 4");
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D028(void *, void *, void *);
extern f32 func_003824E0(f32, f32);

void func_L01_00305F00(u8 *obj, f32 scale) {
    Trail_00305F00 *t = *(Trail_00305F00 **)(obj + 0x68);
    Ribbon_00305F00 s0, s1, s2;
    vu0_v4 mat[4];
    vu0_v4 v1F0, v200, cur, other;
    vu0_v4 *g;
    f32 w;
    f32 h;
    s32 idx;
    s32 prev;
    s32 i;
    s32 next;

    if (t->count == 0) {
        return;
    }
    if ((D_L01_002C5600 + D_001425C0[0x11])->level >= 4) {
        s0.x78 = func_00389598(0x45);
    } else {
        s0.x78 = func_00389598(10);
    }
    s0.c[0] = s0.c[1] = s0.c[2] = s0.c[3] = 0x609F9F9F;
    s0.x80 = 0xFF9000000260L;
    s0.x88 = 0x4000000064L;
    s0.x70 = 0;
    s1.x78 = func_00389598(0xE);
    s1.c[0] = s1.c[1] = s1.c[2] = s1.c[3] = 0x507F7F7F;
    s1.x80 = 0xFF9000000260L;
    s1.x88 = 0x4000000068L;
    s1.x70 = 0;
    s2.x78 = func_00389598(0x2B);
    s2.x70 = 0;
    s2.x80 = 0xFF9000000260L;
    s2.x88 = 0x5000000068L;
    if ((D_L01_002C5600 + D_001425C0[0x11])->level >= 4) {
        s2.c[0] = s2.c[1] = s2.c[2] = s2.c[3] = 0x55803010;
    } else {
        s2.c[0] = s2.c[1] = s2.c[2] = s2.c[3] = 0x55103080;
    }
    w = scale * 0.5f;
    *(vu0_q *)&v1F0 = 0;
    v1F0.w = 1.0f;
    h = func_003824E0(w, scale);
    v1F0.z = h;
    *(vu0_q *)&v200 = 0;
    v200.w = 1.0f;
    v200.z = h * ((D_L01_002C5600 + D_001425C0[0x11])->level >= 4 ? 3.0f : 6.0f);
    func_L01_00305C50((S_35A8A0 *)&s0);
    s0.uv[0] = t->u + 0.0f;
    s0.uv[1] = t->v + 0.0f;
    s0.uv[2] = t->u + 0.0f;
    s0.uv[3] = t->v + 1.0f;
    s0.uv[4] = t->u + 1.0f;
    s0.uv[5] = t->v + 0.0f;
    s0.uv[6] = t->u + 1.0f;
    s0.uv[7] = t->v + 1.0f;
    s1.uv[0] = t->u + 0.0f;
    s1.uv[1] = 0.0f;
    s1.uv[2] = t->u + 0.0f;
    s1.uv[3] = 1.0f;
    s1.uv[4] = t->u + 1.0f;
    s1.uv[5] = 0.0f;
    s1.uv[6] = t->u + 1.0f;
    s1.uv[7] = 1.0f;
    s2.uv[0] = t->u + 0.0f;
    s2.uv[1] = 0.0f;
    s2.uv[2] = t->u + 0.0f;
    s2.uv[3] = 1.0f;
    s2.uv[4] = t->u + 1.0f;
    s2.uv[5] = 0.0f;
    s2.uv[6] = t->u + 1.0f;
    s2.uv[7] = 1.0f;
    g = D_001DC5C4_sda;
    cur = t->origin;
    idx = t->head;
    other = g[idx * 4];
    vec_sub_ba(&mat[0], &other, &cur);
    func_0038CF68(&mat[0], &mat[0], 1.0f);
    vec_sub_ba(&mat[1], &D_L01_001E29C0, &cur);
    func_0038CE90(&mat[2], &mat[1], &mat[0]);
    func_0038CF68(&mat[2], &mat[2], 1.0f);
    func_0038CE90(&mat[1], &mat[0], &mat[2]);
    mat[3] = cur;
    s0.m[0] = v1F0;
    func_0038CE20((f32 *)&s0.m[1], (f32 *)&s0.m[0], -1.0f);
    func_0038D028(&s0.m[0], &s0.m[0], mat);
    func_0038D028(&s0.m[1], &s0.m[1], mat);
    s2.m[0] = v200;
    s1.m[0] = s0.m[0];
    s1.m[1] = s0.m[1];
    func_0038CE20((f32 *)&s2.m[1], (f32 *)&s2.m[0], -1.0f);
    func_0038D028(&s2.m[0], &s2.m[0], mat);
    func_0038D028(&s2.m[1], &s2.m[1], mat);
    for (i = 1; i < t->count; i++) {
        s0.m[2] = v1F0;
        scale *= 0.94f;
        func_0038CE20((f32 *)&s0.m[3], (f32 *)&s0.m[2], -1.0f);
        w *= 0.94f;
        s2.m[2] = v200;
        func_0038CE20((f32 *)&s2.m[3], (f32 *)&s2.m[2], -1.0f);
        g = D_001DC5C4_sda;
        cur = g[idx * 4];
        prev = idx - 1;
        next = prev;
        if (prev < 0) {
            next = 34;
        }
        other = g[next * 4];
        vec_sub_ba(&mat[0], &other, &cur);
        func_0038CF68(&mat[0], &mat[0], 1.0f);
        vec_sub_ba(&mat[1], &D_L01_001E29C0, &cur);
        func_0038CE90(&mat[2], &mat[1], &mat[0]);
        func_0038CF68(&mat[2], &mat[2], 1.0f);
        func_0038CE90(&mat[1], &mat[0], &mat[2]);
        mat[3] = cur;
        func_0038D028(&s0.m[2], &s0.m[2], mat);
        func_0038D028(&s0.m[3], &s0.m[3], mat);
        func_0038D028(&s2.m[2], &s2.m[2], mat);
        func_0038D028(&s2.m[3], &s2.m[3], mat);
        s1.m[2] = s0.m[2];
        s1.m[3] = s0.m[3];
        func_003D2DA0((S_35A8A0 *)&s0, 0, 0);
        func_003D2DA0((S_35A8A0 *)&s1, 0, 0);
        func_003D2DA0((S_35A8A0 *)&s2, 0, 0);
        idx = prev < 0 ? 34 : prev;
        s0.m[1] = s0.m[3];
        s1.m[0] = s1.m[2];
        s1.m[1] = s1.m[3];
        s2.m[0] = s2.m[2];
        s0.m[0] = s0.m[2];
        s2.m[1] = s2.m[3];
        s0.c[0] = s0.c[1] = s0.c[2];
        s1.c[0] = s1.c[1] = s1.c[2];
        s2.c[0] = s2.c[1] = s2.c[2];
        h = func_003824E0(w, scale);
        v1F0.z = h;
        v200.z = h * ((D_L01_002C5600 + D_001425C0[0x11])->level >= 4 ? 3.0f : 6.0f);
    }
    mat[3] = other;
    func_0038D028(&s0.m[2], &s0.m[2], mat);
    func_0038D028(&s0.m[3], &s0.m[3], mat);
}
/* localdecomp:end func_L01_00305F00 */
