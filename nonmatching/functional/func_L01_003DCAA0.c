/* functional: medium. Written from the disassembly (no draft), compiled in context, not byte-compared. Spawns a 0x1DCE projectile/effect moby: random lifetimes, builds its orientation basis from one of four camera/hero cases, collision-probes from the owner, sets flags. VU0 vadd/vsub.xyz and lq/sq written as scalar and u128 C. */
#include "common.h"
/* localdecomp:start func_L01_003DCAA0 */
typedef struct { f32 x, y, z, w; } V4_003DCAA0 __attribute__((aligned(16)));
typedef struct {
    f32 pos[3];
    u8 *owner;         /* 0x0C */
    u128_t trail[4];   /* 0x10 */
    u128_t velocity;   /* 0x50 */
    u8 *source;        /* 0x60 */
    f32 zoff;          /* 0x64 */
    f32 f68, f6C, f70;
    u16 s74;
    u8 b76, b77;
    f32 f78;
    u8 p7C[4];
    u128_t basis;      /* 0x80 */
    u128_t dir;        /* 0x90 */
    s32 mark;          /* 0xA0 */
    s32 handle;        /* 0xA4 */
    s32 life1, life2;  /* 0xA8, 0xAC */
    u8 pB0[0x0C];
    s32 extra;         /* 0xBC */
} Fx_003DCAA0;
extern u8 D_001A4BE0[];
extern u8 D_L01_001E29E0[];
extern u8 D_L01_001EAA20[];
extern u8 D_L01_001E0140[];
extern u8 D_L01_002C5600[];
extern u8 D_001425C0[];
u8 *func_L01_003DCAA0(u8 *owner, u8 *origin, u8 *source, u8 *dir, u8 *vel, s32 extra, f32 zoff) {
    extern u8 *func_003C24B0(s32, s32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_L01_004CB128(void *, void *, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern void func_003C7C38(u8 *);
    extern void func_L01_0044BE50(u8 *, void *, s32);
    extern s32 func_L01_004C85C8(u8 *, s32, f32, f32, f32);
    extern void func_L01_004AA7E8(u8 *, s32);
    V4_003DCAA0 base, probe, s20, s30, s40, s50;
    u8 *m;
    Fx_003DCAA0 *v;
    u8 *cam;
    s32 st, sub, r;
    f32 f;
    u8 *row;
    m = func_003C24B0(0x1DCE, 0xC0);
    if (m == 0) return m;
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
        base.x = 0; base.y = 0; base.z = 0; base.w = 0;
    }
    v->velocity = *(u128_t *)vel;
    st = *(s32 *)(D_001A4BE0 + 0x25C4);
    if (st == 0x1D) {
        u8 *tbl = D_L01_001E29E0;
        *(u128_t *)(m + 0xC0) = *(u128_t *)tbl;
        *(u128_t *)(m + 0xD0) = *(u128_t *)(tbl + 0x10);
        *(u128_t *)(m + 0xE0) = *(u128_t *)(tbl + 0x20);
        *(u128_t *)(m + 0x10) = *(u128_t *)(tbl - 0x20);
        func_0038CE20(&probe, tbl + 0x20, -0.20000000298023224f);
        *(f32 *)(m + 0x10) = *(f32 *)(m + 0x10) + probe.x;
        *(f32 *)(m + 0x14) = *(f32 *)(m + 0x14) + probe.y;
        *(f32 *)(m + 0x18) = *(f32 *)(m + 0x18) + probe.z;
        func_0038CE20(&s20, tbl + 0x10, -0.25f);
        *(f32 *)(m + 0x10) = *(f32 *)(m + 0x10) + s20.x;
        *(f32 *)(m + 0x14) = *(f32 *)(m + 0x14) + s20.y;
        *(f32 *)(m + 0x18) = *(f32 *)(m + 0x18) + s20.z;
        func_0038CE20(&s30, tbl, 0.0f);
        *(f32 *)(m + 0x10) = *(f32 *)(m + 0x10) + s30.x;
        *(f32 *)(m + 0x14) = *(f32 *)(m + 0x14) + s30.y;
        *(f32 *)(m + 0x18) = *(f32 *)(m + 0x18) + s30.z;
        if (source != 0) {
            *(f32 *)(m + 0xC0) = base.x - *(f32 *)(m + 0x10);
            *(f32 *)(m + 0xC4) = base.y - *(f32 *)(m + 0x14);
            *(f32 *)(m + 0xC8) = base.z - *(f32 *)(m + 0x18);
            *(f32 *)(m + 0xCC) = base.w;
            func_0038CF68(m + 0xC0, m + 0xC0, 1.0f);
        } else {
            func_0038CE20(&s40, tbl, 30.0f);
            s40.x = *(f32 *)(tbl - 0x20) + s40.x;
            s40.y = *(f32 *)(tbl - 0x1C) + s40.y;
            s40.z = *(f32 *)(tbl - 0x18) + s40.z;
            s40.w = *(f32 *)(tbl - 0x14);
            cam = *(u8 **)(D_001A4BE0 + 0x25C0);
            if (func_003D3CB0(tbl - 0x20, &s40, 0, cam, 0) != 0) *(u128_t *)&s40 = *(u128_t *)D_L01_001EAA20;
            s50.x = s40.x - *(f32 *)(m + 0x10);
            s50.y = s40.y - *(f32 *)(m + 0x14);
            s50.z = s40.z - *(f32 *)(m + 0x18);
            s50.w = s40.w;
            func_0038CF68(m + 0xC0, &s50, 1.0f);
        }
        func_0038CE90(m + 0xD0, m + 0xC0, *(u8 **)(D_001A4BE0 + 0x25C0) + 0xE0);
        func_0038CF68(m + 0xD0, m + 0xD0, 1.0f);
        func_0038CE90(m + 0xE0, m + 0xD0, m + 0xC0);
    } else {
        sub = *(s16 *)(D_001A4BE0 + 0x2874);
        if (sub == 1) {
            func_0038CF68(m + 0xC0, owner + 0xD0, -1.0f);
            func_0038CE20(m + 0xD0, owner + 0xC0, -1.0f);
            *(u128_t *)(m + 0xE0) = *(u128_t *)(owner + 0xE0);
        } else if (*(s32 *)(D_001A4BE0 + 0x16B0) == 1 && source == 0) {
            *(u128_t *)(m + 0xC0) = *(u128_t *)D_L01_001E29E0;
            *(u128_t *)(m + 0xD0) = *(u128_t *)(D_L01_001E29E0 + 0x10);
            *(u128_t *)(m + 0xE0) = *(u128_t *)(D_L01_001E29E0 + 0x20);
        } else if (source != 0) {
            *(f32 *)(m + 0xC0) = base.x - *(f32 *)(m + 0x10);
            *(f32 *)(m + 0xC4) = base.y - *(f32 *)(m + 0x14);
            *(f32 *)(m + 0xC8) = base.z - *(f32 *)(m + 0x18);
            *(f32 *)(m + 0xCC) = base.w;
            func_0038CF68(m + 0xC0, m + 0xC0, 1.0f);
            func_0038CE90(m + 0xD0, m + 0xC0, *(u8 **)(D_001A4BE0 + 0x25C0) + 0xE0);
            func_0038CF68(m + 0xD0, m + 0xD0, 1.0f);
            func_0038CE90(m + 0xE0, m + 0xD0, m + 0xC0);
        } else {
            *(u128_t *)(m + 0xC0) = *(u128_t *)(D_001A4BE0 + 0x6F0);
            func_0038CE90(m + 0xD0, m + 0xC0, D_001A4BE0 + 0x6E0);
            func_0038CF68(m + 0xD0, m + 0xD0, 1.0f);
            func_0038CE90(m + 0xE0, m + 0xD0, m + 0xC0);
        }
    }
    *(f32 *)(m + 0xCC) = 0.0f;
    *(f32 *)(m + 0xEC) = 0.0f;
    *(f32 *)(m + 0xDC) = 0.0f;
    v->owner = owner;
    f = func_003824E0(4.0f, 10.0f);
    v->f6C = f;
    v->s74 = 0xFA;
    row = D_L01_002C5600 + D_001425C0[0x97] * 0xF0;
    if (!(row[1] < 4)) {
        v->s74 = 100;
        v->f6C = func_003824E0(50.0f, 70.0f);
    }
    v->f70 = func_L01_00443A18(6.0f, 10.0f);
    v->f68 = *(f32 *)(D_L01_002C5600 + D_001425C0[0x97] * 0xF0 + 0x4C) * 0.020000001415610313f * 0.800000011920929f;
    v->f78 = func_00382538();
    v->b76 = 1;
    v->b77 = 1;
    v->basis = *(u128_t *)(m + 0xC0);
    v->dir = *(u128_t *)dir;
    for (r = 3; r >= 0; r--) v->trail[3 - r] = *(u128_t *)(m + 0x10);
    if (source != 0) {
        v->pos[0] = *(f32 *)(source + 0x10);
        v->pos[1] = *(f32 *)(source + 0x14);
        v->zoff = zoff;
        v->pos[2] = *(f32 *)(source + 0x18) + zoff;
    }
    *(u128_t *)&probe = *(u128_t *)(owner + 0x10);
    probe.z = *(f32 *)(origin + 8);
    cam = *(u8 **)(D_001A4BE0 + 0x25C0);
    if (func_003D3CB0(&probe, origin, 0, cam, 0) != 0) {
        m[0xBC] = 1;
        *(u128_t *)(m + 0x10) = *(u128_t *)D_L01_001EAA20;
    }
    func_003C7C38(m);
    func_L01_0044BE50(m, D_L01_001E0140, 0x1F);
    v->handle = func_L01_004C85C8(m, 0, 1.0f, 1.0f, 1.0f);
    *(f32 *)(m + 0x2C) = *(f32 *)(m + 0x2C) * 2.5f;
    *(s32 *)(m + 0x98) = 0;
    *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
    func_L01_004AA7E8(m, 1);
    return m;
}
/* localdecomp:end func_L01_003DCAA0 */
