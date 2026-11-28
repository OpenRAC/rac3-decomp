/* func_L33_0034FC00 (Claude wave 14 r56, 2026-11-28). First draft kept here. */
/* func_L33_0034FC00 (fresh entry, first draft). Written from the PAL assembly with struct views of the
 * particle (a) and its emitter record (b), plain struct-field access (which lets the D_L33_001DD830/820/844
 * scalar loads move above the emitter stores as retail has them), the b+4 and owner->0x68 loads hoisted
 * before their tests (retail's delay slots), and one VU0 asm block per vadd.xyz sequence so it compiles
 * under the file's own line (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as): 29 diffs there with
 * the divs metadata 0 0 2 (NEEDS divs row 'func_L33_0034FC00 0 0 2'), 49 without.
 * Retail's second sequence interleaves `lwc1 $f0, 0x10($sp)` between the lqc2s and the vadd, which only
 * the j-form vu0.h helpers (vec_add_ab / vec_add_ba) give, and those need -mvu0-use-vf0-vf2: the j-form
 * twin of this draft (build/codex/wr56/func_L33_0034FC00.jform.c) gives 16 diffs under the existing
 * line "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (L33_0034F530.c's), and
 * the file's only other C function func_L33_0034FEE8 MATCHes under that line too (whole-file change).
 * Still differs (j-form, VU0 line): at the join after the init block, retail stores em->vy right after
 * the add.s and only then materialises 128.0f, 1/256 and the 0.0f argument; ours fills the add.s latency
 * with those three constant loads (sched2 has them ready from the start of the block). */
#include "common.h"

/* localdecomp:start func_L33_0034FC00 */
extern f32 D_L33_001DD814;
__asm__(".extern D_L33_001DD814, 4");
extern s32 D_L33_001DD818;
__asm__(".extern D_L33_001DD818, 4");
extern s32 D_L33_001DD81C;
__asm__(".extern D_L33_001DD81C, 4");
extern f32 D_L33_001DD820;
__asm__(".extern D_L33_001DD820, 4");
extern f32 D_L33_001DD830;
__asm__(".extern D_L33_001DD830, 4");
extern f32 D_L33_001DD834;
__asm__(".extern D_L33_001DD834, 4");
extern f32 D_L33_001DD838;
__asm__(".extern D_L33_001DD838, 4");
extern f32 D_L33_001DD844;
__asm__(".extern D_L33_001DD844, 4");
extern f32 D_L33_001DD848;
__asm__(".extern D_L33_001DD848, 4");

typedef struct {
    u8 pad0[4];
    s32 color;
    s8 shade;
    u8 pad9;
    s16 age;
    f32 scale;
    vu0_v4 pos;
} Pt_0034FC00;

typedef struct {
    u8 *owner;
    s32 active;
    s16 life;
    u16 flags;
    u8 padC[2];
    u16 shade;
    f32 vx;
    f32 vy;
    u8 pad18[4];
    f32 ay;
} Em_0034FC00;

void func_L33_0034FC00(u8 *a, u8 *b) {
    extern void func_00382580(void *, f32, f32);
    extern f32 func_0038CE68(void *, void *);
    extern void func_L02_003BA9F8(void *, void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_003C4088(f32, f32, f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern f32 func_L03_0034B148(s32, s32, f32);
    extern f32 func_003824E0(f32, f32);
    Pt_0034FC00 *p = (Pt_0034FC00 *)a;
    Em_0034FC00 *em = (Em_0034FC00 *)b;
    u8 *c;
    u8 *st;
    s32 w;
    f32 x;
    f32 k;
    f32 e;
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 v2;
    vu0_v4 v3;

    if (em == 0) {
        return;
    }
    c = em->owner;
    w = em->active;
    if (c == 0) {
        return;
    }
    if (w == 0) {
        return;
    }
    st = *(u8 **)(c + 0x68);
    if (em->flags & 1) {
        if (st == 0) {
            p->age = 0;
            return;
        }
        x = D_L33_001DD814 * *(f32 *)(c + 0xC) * 0.0009765625f;
        func_00382580(&v0, x, x);
        *(vu0_q *)&v1 = *(vu0_q *)&v0;
        if (func_0038CE68(&v1, st) < 0.0f) {
            func_L02_003BA9F8(&v1, st, &v3, &v2);
            func_0038CE20(&v3, &v3, -1.0f);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(v1) : "m"(v3), "m"(v2) : "vf1", "vf2");
        }
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(p->pos) : "m"(v0), "m"(*(vu0_v4 *)(c + 0x10)) : "vf1", "vf2");
        v1.x = v1.x * D_L33_001DD848;
        func_0038CF68(&v1, &v1, D_L33_001DD844);
        em->vy = v1.z;
        em->vx = v1.x;
        em->ay = func_003C4088(D_L33_001DD820, -D_L33_001DD820, v1.z / D_L33_001DD844 * 0.5f + 0.5f);
        p->color = func_0038DBD8(D_L33_001DD818, D_L33_001DD81C, func_003824E0(0.0f, 1.0f));
        p->scale = func_003824E0(D_L33_001DD838, D_L33_001DD834);
    }
    em->vy += em->ay;
    p->pos.x += em->vx;
    p->pos.z += em->vy;
    p->color = (p->color & 0xFFFFFF) | ((s32)((f32)p->age / (f32)em->life * 128.0f) << 24);
    k = D_L33_001DD830 * (f32)em->life * (f32)(em->shade >> 8) * 0.00390625f;
    e = (f32)(em->shade & 0xFF);
    p->shade = (s32)func_003C4088(e, e + (e + k), func_L03_0034B148(p->age, em->life, 0.0f));
    p->scale = p->scale * ((f32)p->age / (f32)(p->age + 1));
}
/* localdecomp:end func_L33_0034FC00 */

/* The other form the notes name (Claude wave 14 r56, func_L33_0034FC00.jform.c): the draft for the line or declaration it needs, not compiled here. */
#if 0
/* func_L33_0034FC00, j-form draft for the VU0 line "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
 * -mno-check-zero-division @ps2as" (does not compile under the file's own line): 16 diffs there with divs
 * 0 0 2; see out/func_L33_0034FC00.near.c for what still differs. */
#include "common.h"

/* localdecomp:start func_L33_0034FC00 */
extern f32 D_L33_001DD814;
__asm__(".extern D_L33_001DD814, 4");
extern s32 D_L33_001DD818;
__asm__(".extern D_L33_001DD818, 4");
extern s32 D_L33_001DD81C;
__asm__(".extern D_L33_001DD81C, 4");
extern f32 D_L33_001DD820;
__asm__(".extern D_L33_001DD820, 4");
extern f32 D_L33_001DD830;
__asm__(".extern D_L33_001DD830, 4");
extern f32 D_L33_001DD834;
__asm__(".extern D_L33_001DD834, 4");
extern f32 D_L33_001DD838;
__asm__(".extern D_L33_001DD838, 4");
extern f32 D_L33_001DD844;
__asm__(".extern D_L33_001DD844, 4");
extern f32 D_L33_001DD848;
__asm__(".extern D_L33_001DD848, 4");

typedef struct {
    u8 pad0[4];
    s32 color;
    s8 shade;
    u8 pad9;
    s16 age;
    f32 scale;
    vu0_v4 pos;
} Pt_0034FC00;

typedef struct {
    u8 *owner;
    s32 active;
    s16 life;
    u16 flags;
    u8 padC[2];
    u16 shade;
    f32 vx;
    f32 vy;
    u8 pad18[4];
    f32 ay;
} Em_0034FC00;

void func_L33_0034FC00(u8 *a, u8 *b) {
    extern void func_00382580(void *, f32, f32);
    extern f32 func_0038CE68(void *, void *);
    extern void func_L02_003BA9F8(void *, void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_003C4088(f32, f32, f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern f32 func_L03_0034B148(s32, s32, f32);
    extern f32 func_003824E0(f32, f32);
    Pt_0034FC00 *p = (Pt_0034FC00 *)a;
    Em_0034FC00 *em = (Em_0034FC00 *)b;
    u8 *c;
    u8 *st;
    s32 w;
    f32 x;
    f32 k;
    f32 e;
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 v2;
    vu0_v4 v3;

    if (em == 0) {
        return;
    }
    c = em->owner;
    w = em->active;
    if (c == 0) {
        return;
    }
    if (w == 0) {
        return;
    }
    st = *(u8 **)(c + 0x68);
    if (em->flags & 1) {
        if (st == 0) {
            p->age = 0;
            return;
        }
        x = D_L33_001DD814 * *(f32 *)(c + 0xC) * 0.0009765625f;
        func_00382580(&v0, x, x);
        *(vu0_q *)&v1 = *(vu0_q *)&v0;
        if (func_0038CE68(&v1, st) < 0.0f) {
            func_L02_003BA9F8(&v1, st, &v3, &v2);
            func_0038CE20(&v3, &v3, -1.0f);
            vec_add_ab(&v1, &v3, &v2);
        }
        vec_add_ba(&p->pos, &v0, c + 0x10);
        v1.x = v1.x * D_L33_001DD848;
        func_0038CF68(&v1, &v1, D_L33_001DD844);
        em->vy = v1.z;
        em->vx = v1.x;
        em->ay = func_003C4088(D_L33_001DD820, -D_L33_001DD820, v1.z / D_L33_001DD844 * 0.5f + 0.5f);
        p->color = func_0038DBD8(D_L33_001DD818, D_L33_001DD81C, func_003824E0(0.0f, 1.0f));
        p->scale = func_003824E0(D_L33_001DD838, D_L33_001DD834);
    }
    em->vy += em->ay;
    p->pos.x += em->vx;
    p->pos.z += em->vy;
    p->color = (p->color & 0xFFFFFF) | ((s32)((f32)p->age / (f32)em->life * 128.0f) << 24);
    k = D_L33_001DD830 * (f32)em->life * (f32)(em->shade >> 8) * 0.00390625f;
    e = (f32)(em->shade & 0xFF);
    p->shade = (s32)func_003C4088(e, e + (e + k), func_L03_0034B148(p->age, em->life, 0.0f));
    p->scale = p->scale * ((f32)p->age / (f32)(p->age + 1));
}
/* localdecomp:end func_L33_0034FC00 */
#endif
