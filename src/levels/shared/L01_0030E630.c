#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x28];
    s32 w28;
} S_311A18m;
typedef struct {
    u8 pad0[0x10];
    s128 q10;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    S_311A18m *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} S_311A18;

INCLUDE_ASM("asm/levels", func_L01_0030E630);

INCLUDE_ASM("asm/levels", func_L01_0030EAE8);

/* localdecomp:start func_L01_0030F0B0 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x80];
    f32 pos[4];
    u8 pad90[0x25F3 - 0x90];
    u8 pickup_instant;
    u8 pad25F4[0x2824 - 0x25F4];
    f32 pickup_radius;
    f32 pickup_height;
    u8 pad282C[0x2850 - 0x282C];
    s32 health;
} Hero_0030F0B0;
typedef struct {
    u8 pad0[0x5C];
    u8 b5C;
    u8 pad5D[0x68 - 0x5D];
    s32 w68;
    u8 pad6C[0x74 - 0x6C];
    f32 f74;
    u8 b78;
} Vars_0030F0B0;
typedef struct {
    u8 pad0[0x10];
    f32 pos[4];
    u8 pad20[0x68 - 0x20];
    Vars_0030F0B0 *vars;
} Moby_0030F0B0;
typedef struct {
    u8 pad0[0x8A];
    u16 h8A;
    u8 pad8C[0xF0 - 0x8C];
} Lvl_0030F0B0;

extern Hero_0030F0B0 D_001A4BE0;
extern s32 D_L01_001D673C;

extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern Lvl_0030F0B0 D_L01_002C5600[];
extern f32 func_L01_00451580(void *);
extern s32 func_L01_0040E020(void *);
extern f32 func_L01_0040E570(void *, void *);

s32 func_L01_0030F0B0(Moby_0030F0B0 *m, s32 a1) {
    Vars_0030F0B0 *vars = m->vars;
    Hero_0030F0B0 *hero = &D_001A4BE0;
    s32 idx;
    s32 n;
    Lvl_0030F0B0 *e;
    f32 d;

    if (hero->health == 0) {
        return 0;
    }
    if (D_L01_001D673C ? func_L01_00451580(m->pos) < vars->f74 - 2.0f : m->pos[2] < vars->f74 - 2.0f) {
        return 1;
    }
    if (hero->pickup_instant) {
        return 1;
    }
    idx = vars->w68;
    n = D_001427F0[idx];
    e = &D_L01_002C5600[D_001425C0[idx]];
    if (n >= e->h8A) {
        return 0;
    }
    if (vars->b5C != 0 || a1 != 0) {
        if (func_L01_0040E020(&vars->b78) != 0) {
            Hero_0030F0B0 *h = &D_001A4BE0;

            if (h->pickup_height < fabs_asm(m->pos[2] - h->pos[2])) {
                return 0;
            }
            d = func_L01_0040E570(m->pos, h->pos);
            if (h->pickup_radius * h->pickup_radius < d) {
                return 0;
            }
        }
    } else {
        Hero_0030F0B0 *h = &D_001A4BE0;

        if (fabs_asm(m->pos[2] - h->pos[2]) < h->pickup_height
            && func_L01_0040E570(m->pos, h->pos) < h->pickup_radius * h->pickup_radius) {
            vars->b78 = 3;
        }
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L01_0030F0B0 */

INCLUDE_ASM("asm/levels", func_L01_0030F288);

LINKER_REMNANT("asm/levels", func_L01_0030F4E0);

INCLUDE_ASM("asm/levels", func_L01_0030F4E8);

INCLUDE_ASM("asm/levels", func_L01_0030F6C0);

LINKER_REMNANT("asm/levels", func_L01_003104A0);
