/* func_L30_003518F0 (Claude wave 14 r60, 2026-11-28). First draft kept here. */
#include "common.h"

/* func_L30_003518F0 (fresh entry, first draft). Under this file's line (no -mvu0-use-vf0-vf2) the
 * one VU0 sequence cannot be written: vu0.h's helpers fail to compile ("fixed or forbidden register
 * vf17 was spilled for class VU_REGS"), so the add of the spawn offset to the moby position is written
 * as scalar adds here, which costs the 4-instruction lqc2/lqc2/vadd.xyz/sqc2 block (12 scalar
 * instructions instead) and shifts every later position. With the line
 * "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (as L30_00351D10.c) the block
 * is vec_add_ba(&o->pos, &m->pos, &d) (include vu0.h). Aligned against retail, everything else matches
 * except one scheduling choice before the first func_L03_0034B148 call (retail: lh a0, lh a1, then
 * mov.s f12 in the delay slot; here lh a1 lands in the delay slot). Levers that fixed the rest:
 * m->vars read before the null tests, the x/z/y store order of both offset vectors, a ternary for p.z,
 * and the 0x1C color stored through a byte offset (it keeps the D_L30_001DD924 load after it). */

/* localdecomp:start func_L30_003518F0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003518F0;
typedef struct {
    u8 p0[0x10];
    V_003518F0 pos;  /* 0x10 */
    u8 p20[0x48];
    u8 *vars;        /* 0x68 */
} M_003518F0;
typedef struct {
    u8 p0[4];
    s32 color;       /* 0x4 */
    u8 b8;
    u8 p9;
    s16 hA;
    f32 fC;
    V_003518F0 pos;  /* 0x10 */
} O_003518F0;
typedef struct {
    M_003518F0 *moby; /* 0x0 */
    s32 i4;
    s16 h8;
    u16 hA;
    u8 bC;
    u8 pD;
    u16 hE;
    f32 vx;          /* 0x10 */
    f32 vz;          /* 0x14 */
    s32 c18;
    s32 c1C;
} A_003518F0;

__asm__(".extern D_L30_001DD904, 4");
__asm__(".extern D_L30_001DD908, 4");
__asm__(".extern D_L30_001DD90C, 4");
__asm__(".extern D_L30_001DD910, 4");
__asm__(".extern D_L30_001DD914, 4");
__asm__(".extern D_L30_001DD918, 4");
__asm__(".extern D_L30_001DD91C, 4");
__asm__(".extern D_L30_001DD924, 4");
__asm__(".extern D_L30_001DD930, 4");
__asm__(".extern D_L30_001DD934, 4");
__asm__(".extern D_L30_001DD938, 4");
__asm__(".extern D_L30_001DD93C, 4");
__asm__(".extern D_L30_001DD944, 4");
__asm__(".extern D_L30_001DD94C, 4");
__asm__(".extern D_L30_001DD950, 4");
__asm__(".extern D_L30_001DD954, 4");
extern f32 D_L30_001DD904;
extern f32 D_L30_001DD908;
extern f32 D_L30_001DD90C;
extern s32 D_L30_001DD910;
extern s32 D_L30_001DD914;
extern s32 D_L30_001DD918;
extern s32 D_L30_001DD91C;
extern f32 D_L30_001DD924;
extern f32 D_L30_001DD930;
extern f32 D_L30_001DD934;
extern f32 D_L30_001DD938;
extern f32 D_L30_001DD93C;
extern f32 D_L30_001DD944;
extern f32 D_L30_001DD94C;
extern f32 D_L30_001DD950;
extern f32 D_L30_001DD954;
extern C_00351558 D_L30_001E9000;
extern f32 func_003824E0(f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

void func_L30_003518F0(O_003518F0 *o, A_003518F0 *a) {
    extern f32 func_0038DB48(f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    V_003518F0 p;
    V_003518F0 d;
    V_003518F0 v;
    M_003518F0 *m;
    u8 *vars;
    f32 fE;
    f32 dur;
    f32 w;
    f32 ang;
    f32 spin;
    f32 off;
    f32 c;
    s32 i4;

    if (a == 0) return;
    m = a->moby;
    vars = m->vars;
    i4 = a->i4;
    if (m == 0) return;
    if (i4 == 0) return;
    dur = D_L30_001DD930 * (f32)a->h8 * (f32)(a->hE >> 8) * (1.0f / 256.0f);
    fE = (f32)(a->hE & 0xFF);
    w = func_003C4088(D_L30_001DD938, D_L30_001DD934, (f32)a->bC * (1.0f / 256.0f));
    if (a->hA & 1) {
        ang = func_0038DAB8(func_0038DB48(func_003824E0(-D_L30_001DD908, D_L30_001DD908)), *(f32 *)(vars + 0x18));
        spin = func_003824E0(D_L30_001DD950, D_L30_001DD94C);
        off = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        d.x = func_0038D098(off) * D_L30_001DD944;
        d.z = func_0038D0B0(off) * D_L30_001DD944;
        d.y = 0.0f;
        o->pos.x = m->pos.x + d.x;
        o->pos.y = m->pos.y + d.y;
        o->pos.z = m->pos.z + d.z;
        o->pos.w = m->pos.w;
        o->pos.y += D_L30_001DD954;
        v.x = func_0038D098(ang) * spin;
        v.z = func_0038D0B0(ang) * spin;
        v.y = 0.0f;
        a->vx = v.x;
        a->vz = v.z;
        a->c18 = func_0038DBD8(D_L30_001DD91C, D_L30_001DD918, func_003824E0(0.0f, 1.0f));
        *(s32 *)((u8 *)a + 0x1C) = func_0038DBD8(D_L30_001DD914, D_L30_001DD910, func_003824E0(0.0f, 1.0f));
        a->h8 = a->h8 + (s32)(D_L30_001DD924 / spin);
        o->hA = a->h8;
    }
    a->vz += D_L30_001DD90C;
    p = o->pos;
    p.x += a->vx;
    p.z += a->vz;
    if (func_003D3CB0(&o->pos, &p, 1, m, 0) != 0 && D_L30_001E9000.hit != 0) {
        f32 h = a->vx * 0.74f;
        f32 z = p.z;
        p.x = o->pos.x + h;
        p.z = o->pos.y <= *(f32 *)((u8 *)&D_L30_001E9000 + 0x24) ? z - h : z + h;
    }
    o->pos = p;
    c = fE + dur;
    o->fC = func_003C4088(D_L30_001DD93C, w, func_L03_0034B148(o->hA, a->h8, 0.0f));
    o->color = func_0038DBD8(a->c18, a->c1C, func_L03_0034B148(o->hA, a->h8, 0.0f));
    o->color = (o->color & 0xFFFFFF) + ((s32)(func_L03_0034B148(a->h8 - o->hA, a->h8, D_L30_001DD904) * 128.0f) << 24);
    o->b8 = (s32)func_003C4088(fE, c, func_L03_0034B148(o->hA, a->h8, 0.0f));
}
/* localdecomp:end func_L30_003518F0 */
