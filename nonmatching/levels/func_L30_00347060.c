/* PAL near miss (k6 a6, 2026-11-26): func_L30_00347060 (648 B, levels 30-36), a particle update
 * callback (sibling of func_L30_0034E548 / func_L30_00350050), written from retail. 11 diff with
 * --flags "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as": the file's line
 * (L30_00346FB8.c) has no @ps2as, and without it 6.2831855f becomes a .lit4 load (137 diff).
 * Typed structs for the moby, the particle and the owner took 55 -> 20, f4 read before the flag
 * test 20 -> 11. What differs: the func_L03_0034B440 call loads p->h8 before m->hA (retail hA
 * first) and the argument conversions follow in that order; arg temps, casts and statement
 * orders do not change it. */
#include "common.h"
/* localdecomp:start func_L30_00347060 */
#include "vu0.h"
__asm__(".extern D_L30_001DCF80, 4");
__asm__(".extern D_L30_001DCF84, 4");
__asm__(".extern D_L30_001DCF90, 4");
__asm__(".extern D_L30_001DCF94, 4");
__asm__(".extern D_L30_001DCF98, 4");
__asm__(".extern D_L30_001DCF9C, 4");
__asm__(".extern D_L30_001DCFA0, 4");
__asm__(".extern D_L30_001DCFAC, 4");
__asm__(".extern D_L30_001DCFB0, 4");
__asm__(".extern D_L30_001DCFF4, 4");
__asm__(".extern D_L30_001DCFF8, 4");
extern s32 D_L30_001DCF80;
extern s32 D_L30_001DCF84;
extern f32 D_L30_001DCF90;
extern f32 D_L30_001DCF94;
extern f32 D_L30_001DCF98;
extern f32 D_L30_001DCF9C;
extern f32 D_L30_001DCFA0;
extern f32 D_L30_001DCFAC;
extern f32 D_L30_001DCFB0;
extern f32 D_L30_001DCFF4;
extern f32 D_L30_001DCFF8;
typedef struct {
    u8 p0[4];
    s32 color;
    u8 b8;
    u8 p9;
    s16 hA;
    f32 fC;
    vu0_v4 pos;
} M_00347060;
typedef struct {
    u8 p0[0xA0];
    f32 fA0;
} S_00347060;
typedef struct {
    u8 p0[0x10];
    vu0_v4 pos;
    u8 p20[0x68 - 0x20];
    S_00347060 *f68;
} O_00347060;
typedef struct {
    O_00347060 *owner;
    s32 f4;
    s16 h8;
    u16 hA;
    u16 pC;
    u16 hE;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
} P_00347060;
extern void func_L30_0034C958(void *, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L02_003BA9F8(void *, void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
void func_L30_00347060(M_00347060 *m, P_00347060 *p) {
    O_00347060 *t;
    S_00347060 *s;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    f32 ang;
    f32 r;
    f32 k;

    if (p == 0) return;
    {
    s32 f4;
    t = p->owner;
    s = t->f68;
    f4 = p->f4;
    if (p->hA & 1) {
        if (t == 0 || s == 0 || f4 == 0) return;
        *(vu0_q *)&m->pos = *(vu0_q *)&t->pos;
        func_L30_0034C958(&m->pos, D_L30_001DCF90);
        ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        r = func_003824E0(D_L30_001DCFB0, D_L30_001DCFAC);
        a.x = func_0038D098(s->fA0);
        a.z = func_0038D0B0(s->fA0);
        a.y = 0.0f;
        b.x = func_0038D098(ang) * r;
        b.z = func_0038D0B0(ang) * r;
        b.y = 0.0f;
        func_L02_003BA9F8(&b, &a, &c, &d);
        func_0038CE20(&c, &c, 1.0f - D_L30_001DCFF4);
        func_0038CE20(&d, &d, D_L30_001DCFF4 + 1.0f);
        vec_add_ab(&b, &c, &d);
        p->f10 = b.x;
        p->f14 = b.z;
        p->f18 = func_003824E0(D_L30_001DCFA0, D_L30_001DCF9C);
        p->f1C = func_003824E0(D_L30_001DCF98, D_L30_001DCF94);
    }
    }
    k = func_L03_0034B440(1, 0, 0, (f32)m->hA, (f32)p->h8, 1.0f);
    m->pos.x += p->f10;
    m->pos.z += p->f14;
    m->color = func_0038DBD8(D_L30_001DCF84, D_L30_001DCF80, k);
    m->fC = func_003C4088(p->f18, p->f1C, k);
    m->b8 = func_003C4088((f32)(p->hE & 0xFF), (f32)(p->hE & 0xFF) + D_L30_001DCFF8 * (f32)p->h8 * (f32)(p->hE >> 8) * 0.00390625f, k);
}
/* localdecomp:end func_L30_00347060 */
