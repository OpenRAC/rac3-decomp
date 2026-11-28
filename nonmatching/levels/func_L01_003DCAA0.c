/* func_L01_003DCAA0 (Claude wave 14 r69, 2026-11-28). First draft kept here. */
/* func_L01_003DCAA0 (1616 B, 34 places): first PAL draft, wave 14 worker r69 (2026-11-28), written from
 * the retail assembly with the functional draft (nonmatching/functional/) for the fields. 316 diff at level 01
 * under the file's line; the instruction stream is the same apart from a few spots, most rows are a permuted
 * callee-saved allocation (retail: m s2, vars s3, vel s4 then m+0xD0, m+0xC0 s5, hero s6, source s7,
 * owner fp, origin/dir/&t/m+0xE0 spilled at 0x60/0x64/0x6C/0x68; here m and vars take s3/s4).
 * What was found: D_001A4BE0 through a hero struct alias (base + offset loads as retail; the file types
 * D_001A4BE0 in a later block, so an alias as the file's other blocks use), a single return of m (retail's
 * early exit returns the 0 in $s2), qzero for the zeroed base, the VU0 operand orders (vec_add_ba for the
 * first two adds, vec_add_ab for the third), c0/d0/e0 pointers in the 0x1D path (retail keeps m+0xC0/0xD0
 * and spills m+0xE0), a pointer to the second table row (retail keeps it in $s0 across the first call),
 * the chained 0.0f store (retail stores one $f0 three times) and the shared normalize/cross tail of the
 * two 0x1D sub-paths (retail cross-jumps it).
 * Still different: retail keeps 1.0f (-1.0f in the 0x2874 path) in $f20 across the normalize calls (here
 * it is rematerialized; a per-path variable passed through an inline helper gave $f20 but lost the shared
 * tail), the order of the three 0.0f stores (retail CC, EC, DC), and the hero base is reloaded in two
 * places in retail ([!0x1D, source] path and the final probe) where this uses $s6. */
#include "common.h"

/* localdecomp:start func_L01_003DCAA0 */
typedef struct {
    f32 pos[3];
    u8 *owner;
    u128_t trail[4];
    u128_t velocity;
    u8 *source;
    f32 zoff;
    f32 f68, f6C, f70;
    u16 s74;
    u8 b76, b77;
    f32 f78;
    u8 p7C[4];
    u128_t basis;
    u128_t dir;
    s32 mark;
    s32 handle;
    s32 life1, life2;
    u8 pB0[0x0C];
    s32 extra;
} Fx_003DCAA0;

typedef struct {
    u8 p0[0x6E0];
    vu0_v4 v6E0;
    vu0_v4 v6F0;
    u8 p700[0x16B0 - 0x700];
    s32 w16B0;
    u8 p16B4[0x25C0 - 0x16B4];
    u8 *cam;
    s32 state;
    u8 p25C8[0x2874 - 0x25C8];
    s16 h2874;
} Hero_003DCAA0;

extern Hero_003DCAA0 D_001A4BE0_003DCAA0;
extern vu0_v4 D_L01_001E29E0;
extern vu0_v4 D_L01_001E29C0;
extern u128_t D_L01_001EAA20;
extern s16 D_L01_001E0140[] __attribute__((section(".sdata")));
extern Row_003DD9C8 D_L01_002C5600[];
extern u8 D_001425C0[];
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CE90(void *, void *, void *);

static __inline__ void basis_003DCAA0(u8 *x, u8 *y, u8 *z, void *fwd, void *up, f32 k) {
    func_0038CF68(x, fwd, k);
    func_0038CE90(y, x, up);
    func_0038CF68(y, y, k);
    func_0038CE90(z, y, x);
}

u8 *func_L01_003DCAA0(u8 *owner, u8 *origin, u8 *source, u8 *dir, u8 *vel, s32 extra, f32 zoff) {
    extern u8 *func_003C24B0(s32, s32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_00382538(void);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_L01_004CB128(void *, void *, s32);
    extern void func_003C7C38(u8 *);
    extern void func_L01_0044BE50(u8 *, void *, s32);
    extern s32 func_L01_004C85C8(u8 *, s32, f32, f32, f32);
    extern void func_L01_004AA7E8(u8 *, s32);
    vu0_v4 base;
    vu0_v4 t;
    vu0_v4 s20;
    vu0_v4 s30;
    vu0_v4 s40;
    vu0_v4 s50;
    vu0_v4 *tbl;
    vu0_v4 *t1;
    u8 *m;
    Fx_003DCAA0 *v;
    s32 r;
    s32 i;
    f32 *src;
    f32 one;
    u8 *c0;
    u8 *d0;
    u8 *e0;

    m = func_003C24B0(0x1DCE, 0xC0);
    if (m != 0) {
    v = *(Fx_003DCAA0 **)(m + 0x68);
    *(u128_t *)(m + 0x10) = *(u128_t *)origin;
    m[0x30] = 0xFF;
    *(u16 *)(m + 0x32) = 0xFF;
    m[0x31] = 1;
    *(u16 *)(m + 0x34) |= 0x100;
    m[0x20] = 0;
    v->mark = -1;
    r = func_00382498(0, 30);
    v->life1 = (r * 5 + 2) / 6;
    r = func_00382498(10, 60);
    v->extra = extra;
    v->life2 = (r * 5 + 2) / 6;
    if (source != 0) {
        func_L01_004CB128(&base, source, 0);
        v->source = source;
    } else {
        qzero(&base);
    }
    v->velocity = *(u128_t *)vel;
    if (D_001A4BE0_003DCAA0.state == 0x1D) {
        tbl = &D_L01_001E29E0;
        t1 = &tbl[1];
        c0 = m + 0xC0;
        d0 = m + 0xD0;
        e0 = m + 0xE0;
        *(vu0_v4 *)(m + 0xC0) = tbl[0];
        *(vu0_v4 *)(m + 0xD0) = tbl[1];
        *(vu0_v4 *)(m + 0xE0) = tbl[2];
        *(vu0_v4 *)(m + 0x10) = tbl[-2];
        func_0038CE20(&t, &tbl[2], -0.2f);
        vec_add_ba(m + 0x10, m + 0x10, &t);
        func_0038CE20(&s20, t1, -0.25f);
        vec_add_ba(m + 0x10, m + 0x10, &s20);
        func_0038CE20(&s30, tbl, 0.0f);
        vec_add_ab(m + 0x10, m + 0x10, &s30);
        if (source != 0) {
            one = 1.0f;
            vec_sub_ab(c0, &base, m + 0x10);
            func_0038CF68(c0, c0, one);
        } else {
            func_0038CE20(&s40, tbl, 30.0f);
            vec_add_ab(&s40, &tbl[-2], &s40);
            if (func_003D3CB0(&D_L01_001E29C0, &s40, 0, D_001A4BE0_003DCAA0.cam, 0) != 0) {
                *(u128_t *)&s40 = D_L01_001EAA20;
            }
            one = 1.0f;
            vec_sub_ab(&s50, &s40, m + 0x10);
            func_0038CF68(c0, &s50, one);
        }
        func_0038CE90(d0, c0, D_001A4BE0_003DCAA0.cam + 0xE0);
        func_0038CF68(d0, d0, one);
        func_0038CE90(e0, d0, c0);
    } else if (D_001A4BE0_003DCAA0.h2874 == 1) {
        one = -1.0f;
        func_0038CF68(m + 0xC0, owner + 0xD0, one);
        func_0038CE20(m + 0xD0, owner + 0xC0, one);
        *(u128_t *)(m + 0xE0) = *(u128_t *)(owner + 0xE0);
    } else if (D_001A4BE0_003DCAA0.w16B0 == 1 && source == 0) {
        tbl = &D_L01_001E29E0;
        *(vu0_v4 *)(m + 0xC0) = tbl[0];
        *(vu0_v4 *)(m + 0xD0) = tbl[1];
        *(vu0_v4 *)(m + 0xE0) = tbl[2];
    } else if (source != 0) {
        one = 1.0f;
        vec_sub_ab(m + 0xC0, &base, m + 0x10);
        basis_003DCAA0(m + 0xC0, m + 0xD0, m + 0xE0, m + 0xC0, D_001A4BE0_003DCAA0.cam + 0xE0, one);
    } else {
        *(vu0_v4 *)(m + 0xC0) = D_001A4BE0_003DCAA0.v6F0;
        func_0038CE90(m + 0xD0, m + 0xC0, &D_001A4BE0_003DCAA0.v6E0);
        func_0038CF68(m + 0xD0, m + 0xD0, 1.0f);
        func_0038CE90(m + 0xE0, m + 0xD0, m + 0xC0);
    }
    *(f32 *)(m + 0xDC) = *(f32 *)(m + 0xEC) = *(f32 *)(m + 0xCC) = 0.0f;
    v->owner = owner;
    v->f6C = func_003824E0(4.0f, 10.0f);
    v->s74 = 0xFA;
    if (((u8 *)&D_L01_002C5600[D_001425C0[0x97]])[1] >= 4) {
        v->s74 = 100;
        v->f6C = func_003824E0(50.0f, 70.0f);
    }
    v->f70 = func_L01_00443A18(6.0f, 10.0f);
    v->f68 = *(f32 *)((u8 *)&D_L01_002C5600[D_001425C0[0x97]] + 0x4C) * 0.020000001f * 0.8f;
    v->f78 = func_00382538();
    v->b76 = 1;
    v->b77 = 1;
    v->basis = *(u128_t *)(m + 0xC0);
    v->dir = *(u128_t *)dir;
    for (i = 0; i < 4; i++) {
        v->trail[i] = *(u128_t *)(m + 0x10);
    }
    if (source != 0) {
        src = (f32 *)(source + 0x10);
        v->pos[0] = src[0];
        v->pos[1] = src[1];
        v->zoff = zoff;
        v->pos[2] = src[2] + zoff;
    }
    *(u128_t *)&t = *(u128_t *)(owner + 0x10);
    t.z = *(f32 *)(origin + 8);
    if (func_003D3CB0(&t, origin, 0, D_001A4BE0_003DCAA0.cam, 0) != 0) {
        m[0xBC] = 1;
        *(u128_t *)(m + 0x10) = D_L01_001EAA20;
    }
    func_003C7C38(m);
    func_L01_0044BE50(m, D_L01_001E0140, 0x1F);
    v->handle = func_L01_004C85C8(m, 0, 1.0f, 1.0f, 1.0f);
    *(f32 *)(m + 0x2C) = *(f32 *)(m + 0x2C) * 2.5f;
    *(s32 *)(m + 0x98) = 0;
    *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
    func_L01_004AA7E8(m, 1);
    }
    return m;
}
/* localdecomp:end func_L01_003DCAA0 */
