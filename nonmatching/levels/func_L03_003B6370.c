/* PAL draft (2026-11-21, Promises): written from level 3's assembly. Its file is
 * src/levels/shared/L03_003B6180.c (the cut at 0x3B6180, 2026-11-22), with the flags
 * -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses @ps2as, which
 * func_L03_003B6180 needs (8 differences in split-address mode).
 * 19 differences (tools/check.py, levels 03 and 05, the file's flags) with a
 * config/levels/divs_nops.txt row "func_L03_003B6370 2 0 0" (retail has two nops before the first
 * div.s; add the row when it lands, after the last func_L03_ row); 134 without it.
 * Left: in the kind 0/3/6 block retail reaches D_L03_0021F2D4 through gcc's split form (lui $a0,
 * lw $v0, %lo($a0)), which needs split addresses; this file's -mno-split-addresses gives the
 * assembler's macro (lui $v0; lw $v0). And the 1/256 constant is loaded at the top of the alpha
 * block where retail loads it just before the first mul.s (both scheduling passes place it).
 * With --mode S (split addresses), this C gives 14, all in the 1/256 placement; func_L03_003B6740
 * matches in both modes, so a second cut at 0x3B6370 would give it split addresses, but not a
 * match. Done here: D_L03_0021F2D4 as an unsized array read at [0] (23 -> 21 in S mode), and the
 * stores in the order colour, sound, size, age (19; S mode 14; colour, size, sound, age: 21 in
 * S mode; the sound read into a local before the size store: 14 in S mode).
 * Tried for the constant: / 256.0f, the fade without (f32) casts (14 in S mode); earlier: four
 * store orders, / 256.0f, a pointer local for D_L03_0021F2D4 (23), read before the kind test (42);
 * the alpha fade as a static inline helper at both sites (23); the tint terms before the first fade
 * (137); a switch on the kind (230). */
#include "common.h"

/* localdecomp:start func_L03_003B6370 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003B6370;

typedef struct {
    u8 pad0[0x24];
    s32 kind;
    u8 pad28[0x18];
    f32 size;
} Vars_003B6370;

typedef struct {
    u8 pad0[0x10];
    V4_003B6370 pos;
    u8 state;
    u8 pad21[0x47];
    Vars_003B6370 *vars;
} Moby_003B6370;

typedef struct {
    Moby_003B6370 *m;
    s32 on;
    s16 life;
    u16 flags;
    u16 padC;
    u16 tint;
    f32 x, y, z;
} Src_003B6370;

typedef struct {
    u8 pad0[2];
    u8 sound;
    u8 pad3;
    u32 color;
    u8 shade;
    u8 pad9;
    s16 age;
    f32 size;
    V4_003B6370 pos;
} Dst_003B6370;

extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern u8 *D_L03_0021F2D4[];
extern u32 D_L03_001DEA34_003B6370;
__asm__(".extern D_L03_001DEA34_003B6370, 4");
extern f32 D_L03_001DEA30_003B6370;
__asm__(".extern D_L03_001DEA30_003B6370, 4");

void func_L03_003B6370(Dst_003B6370 *d, Src_003B6370 *s) {
    Moby_003B6370 *m;
    Vars_003B6370 *vars;
    s32 on;
    f32 a;
    f32 r;
    f32 lo;
    f32 hi;
    s32 life;
    s32 k;

    if (s == 0) {
        return;
    }
    m = s->m;
    on = s->on;
    vars = m->vars;
    if (m == 0 || on == 0) {
        return;
    }
    if ((u8)(m->state + 3) < 3 || vars == 0) {
        d->age = 0;
        return;
    }
    if (s->flags & 1) {
        a = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        r = func_003824E0(0.25f, 0.6f);
        d->pos = m->pos;
        d->pos.x += r * func_0038D098(a);
        d->pos.y += r * func_0038D098(a);
        d->pos.z += r * func_0038D0B0(a);
        s->x = m->pos.x;
        s->y = m->pos.y;
        s->z = m->pos.z;
        k = vars->kind;
        if (k == 0 || k == 3 || k == 6) {
            d->color = D_L03_001DEA34_003B6370;
            d->sound = *D_L03_0021F2D4[0];
            d->size = 63000.004f;
            d->age = 30;
        } else {
            d->color = 0x88028820;
            d->sound = func_00382498(1, 2);
            d->size = D_L03_001DEA30_003B6370 * 210000.0f;
            d->age = (func_00382498(20, 120) * 5 + 2) / 6;
        }
        vars->size = d->size;
        d->color = (d->color & 0xFFFFFF) | ((s32)((f32)d->age * 128.0f / (f32)s->life) << 24);
        life = s->life;
        lo = s->tint & 0xFF;
        hi = lo + (f32)life * (f32)(s->tint >> 8) * 0.00390625f;
        d->shade = func_003C4088(lo, hi, func_L03_0034B148(d->age, life, 0.0f));
    }
    d->color = (d->color & 0xFFFFFF) | ((s32)((f32)d->age * 128.0f / (f32)s->life) << 24);
    if (vars != 0) {
        k = vars->kind;
        if (k == 0 || k == 3 || k == 6) {
            d->size += (210000.0f - vars->size) / (f32)s->life;
        }
    }
    d->pos.x += m->pos.x - s->x;
    s->x = m->pos.x;
    d->pos.y += m->pos.y - s->y;
    s->y = m->pos.y;
    d->pos.z += m->pos.z - s->z;
    s->z = m->pos.z;
}
/* localdecomp:end func_L03_003B6370 */
