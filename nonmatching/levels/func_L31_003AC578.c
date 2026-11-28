/* func_L31_003AC578 (Claude wave 14 r66, 2026-11-28). Replaces the earlier draft of this function (k6 agent 2, from its functional C). */
/* PAL near miss (wave 14 r66, 2026-11-28): 8 instruction diffs at level 31 under the file's own line
 * (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as; no -mvu0-use-vf0-vf2 needed any more). Against the k6 draft
 * (vec_sub_ba from vu0.h, which needs the vu0 flag line and does not compile under the file's line): the vsub is one
 * VU0 asm block with "m" operands (lqc2 vf2 / lqc2 vf1 / vsub.xyz / sqc2, as in L01_0033D2B8.c), and the particle and
 * emitter are structs (P_/E_003AC578): struct-field stores let the scheduler hoist the $gp scalars D_L31_001DEB1C/20
 * above the p+4 / e+0x18 stores as retail does (fixed scalar vs varying struct), which fixed the whole first block;
 * the alpha byte written (c << 24) | (colour & 0xFFFFFF) gives retail's e+8 halfword in v1 and colour word in a1.
 * Left: retail loads D_L31_001DEB08 (f20) and p->pos.x / p->pos.z after the div.s, here before the mul.s/div.s
 * (6 rows); retail ORs (colour | shifted) into a1 (or a1, a1, v0) where this gives or v0, v0, a1 (2 rows). The order
 * (colour & 0xFFFFFF) | (c << 24) gives retail's or but swaps v1/a1 (11 diffs). Tried without effect: float temp,
 * inline expression, mask in a local before/after, fade in a local, += forms, union colour field; do {} while (0)
 * after the div moves the loads but adds a loop pad nop (30 diffs). */
#include "common.h"

/* localdecomp:start func_L31_003AC578 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003AC578;
typedef struct {
    u8 pad0[3];
    u8 kind;
    s32 color;
    u8 alpha;
    u8 pad9;
    s16 age;
    f32 size;
    V4_003AC578 pos;
} P_003AC578;
typedef struct {
    u8 *anchor;
    s32 count;
    s16 life;
    u16 flags;
    u16 padC;
    u16 fade;
    f32 vx;
    f32 vz;
    f32 alpha;
} E_003AC578;
extern f32 D_L31_001DEAF0;
extern s32 D_L31_001DEAF4;
extern s32 D_L31_001DEAF8;
extern f32 D_L31_001DEAFC;
extern f32 D_L31_001DEB08;
extern f32 D_L31_001DEB0C;
extern f32 D_L31_001DEB10;
extern f32 D_L31_001DEB1C;
extern f32 D_L31_001DEB20;
__asm__(".extern D_L31_001DEAF0, 4");
__asm__(".extern D_L31_001DEAF4, 4");
__asm__(".extern D_L31_001DEAF8, 4");
__asm__(".extern D_L31_001DEAFC, 4");
__asm__(".extern D_L31_001DEB08, 4");
__asm__(".extern D_L31_001DEB0C, 4");
__asm__(".extern D_L31_001DEB10, 4");
__asm__(".extern D_L31_001DEB1C, 4");
__asm__(".extern D_L31_001DEB20, 4");

/* Per-particle update callback of the vid-comic 1 emitter (particle, emitter state): on a particle's first frame
 * places it at the anchor with a random outward velocity and colour; every frame fades its alpha with age/life,
 * moves it and sets its size. */
void func_L31_003AC578(u8 *particle, u8 *emitter) {
    extern void func_L30_0034C958(void *, f32);
    extern s32 func_L30_0034DBA0(s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_0038CEA8(void *);
    extern f32 func_003C4088(f32, f32, f32);
    extern f32 func_L03_0034B148(s32, s32, f32);
    P_003AC578 *p = (P_003AC578 *)particle;
    E_003AC578 *e = (E_003AC578 *)emitter;
    u8 *a;
    s32 c;
    s32 n;
    V4_003AC578 d;
    f32 f20, f21;

    if (e == 0) return;
    a = e->anchor;
    n = e->count;
    if (a == 0) return;
    if (n == 0) return;
    if (e->flags & 1) {
        *(u128_t *)&p->pos = *(u128_t *)(a + 0x10);
        func_L30_0034C958(&p->pos, D_L31_001DEAFC);
        p->color = func_L30_0034DBA0(D_L31_001DEAF4, D_L31_001DEAF8);
        e->alpha = (f32)(p->color >> 24);
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(d) : "m"(p->pos), "m"(*(V4_003AC578 *)(a + 0x10)) : "vf1", "vf2");
        func_0038CF68(&d, &d, func_003824E0(D_L31_001DEB20, D_L31_001DEB1C));
        e->vx = d.x;
        e->vz = d.z;
        if (func_0038CEA8(&d) < D_L31_001DEAF0 * (D_L31_001DEB20 + D_L31_001DEB1C)) {
            p->kind = 0x44;
        } else {
            p->kind = 0x48;
        }
        p->size = func_003C4088(D_L31_001DEB10, D_L31_001DEB0C,
                                (func_0038CEA8(&d) - D_L31_001DEB20) / (D_L31_001DEB1C - D_L31_001DEB20));
    }
    c = (s32)(e->alpha * (f32)p->age / (f32)e->life);
    p->color = (c << 24) | (p->color & 0xFFFFFF);
    p->pos.x = p->pos.x + e->vx;
    p->pos.z = p->pos.z + e->vz;
    f21 = (f32)(e->fade & 0xFF);
    f20 = f21 + D_L31_001DEB08 * (f32)e->life * (f32)(e->fade >> 8) * 0.00390625f;
    p->alpha = (s32)func_003C4088(f21, f20, func_L03_0034B148(p->age, e->life, 0.0f));
}
/* localdecomp:end func_L31_003AC578 */
