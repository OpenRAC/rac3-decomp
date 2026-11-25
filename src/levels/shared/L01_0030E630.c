#include "common.h"
#include "vu0.h"

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

/* localdecomp:start func_L01_0030EAE8 */
extern s32 D_L01_001D6694;
extern s32 D_L01_001DFB40;
extern s32 D_L01_001E1728;
extern u8 D_001425C0[];
typedef struct {
    u8 pad0[0x34];
    s16 h34;
    s16 h36;
    s16 h38;
    s16 h3A;
    u8 pad3C[0xF0 - 0x3C];
} Rec_0030EAE8;
extern Rec_0030EAE8 D_L01_002C5600_0030EAE8[];
extern s32 D_001427F0[];
extern s32 D_001A71A0[];
extern u8 D_001A4C60[];
extern s32 func_L01_004BA800(void);
extern void func_L01_003F7EE8(void *);
extern f32 func_L01_0040E548(void *, void *);
extern f32 func_L01_0040E4C0(void *);
extern s32 func_L01_0030F0B0_0030EAE8(void *, s32);
extern void func_L01_00511958(s32, s32);
extern void func_L01_00451FB8_0030EAE8(s32, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_0040E5D8(void *, s32);
extern void func_003C2880(void *);
extern void func_003C4138(void *, f32, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038D810(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_003C4CE8(f32, void *, void *);

void func_L01_0030EAE8(u8 *self)
{
    u8 *p;
    vu0_v4 a;
    vu0_v4 b10;
    vu0_v4 c20;
    vu0_v4 d30;
    vu0_v4 e40;
    vu0_v4 f50;
    vu0_v4 g60;
    vu0_v4 h70;
    vu0_v4 i80;
    f32 s;
    f32 dist;
    s32 i;
    s32 idx;
    s32 old;
    s32 diff;
    s32 hit;
    s32 nb;
    u8 *hero;
    u8 *hv;
    s32 *up;
    s32 ia;
    s32 dd;
    u32 bb;
    Rec_0030EAE8 *re;
    f32 sq;
    f32 tgt;
    f32 len;
    s32 spare[8];

    p = *(u8 **)(self + 0x68);
    if (D_L01_001D6694 == 2) {
        self[0x31] = 0;
        *(u16 *)(self + 0x34) |= 1;
    } else if (func_L01_004BA800() == 0) {
        self[0x31] = 1;
        *(u16 *)(self + 0x34) &= 0xFFFE;
    }
    switch (self[0x20]) {
    case 0:
        self[0x20] = 1;
        for (i = 0; i < 0x9C; i++) {
            re = D_L01_002C5600_0030EAE8 + D_001425C0[i];
            if (re->h3A == *(s16 *)(self + 0xAA)) {
                *(s32 *)(p + 0x68) = i;
            }
        }
        break;
    case 1:
        hit = 0;
        if (p[0x79] >= 8 && (D_L01_001DFB40 & 0xF) != (((s32)self >> 8) & 0xF)) {
            hit = 0;
        } else {
            if (p[0x5C] == 3 && (D_L01_001DFB40 & 0xF) == (((s32)self >> 8) & 0xF)) {
                qzero(p);
                __asm__("sqc2 vf0, %0" : "=m"(*(vu0_v4 *)(p + 0x10)));
                p[0x5C] = 0;
            }
            a = *(vu0_v4 *)p;
            func_L01_003F7EE8(self);
            sq = *(f32 *)(p + 0x48);
            sq = sq + sq;
            dist = func_L01_0040E548(&a, p);
            sq = sq * sq;
            if (sq < dist) {
                hit = 1;
            }
            if (func_L01_0040E4C0(p) < 4.00000044e-06f) {
                if (func_L01_0040E4C0(p + 0x10) < 9.00000032e-06f) {
                    p[0x79] = p[0x79] + 1;
                } else {
                    p[0x79] = 0;
                }
            } else {
                p[0x79] = 0;
            }
        }
        if (func_L01_0030F0B0_0030EAE8(self, hit) != 0) {
            idx = *(s32 *)(p + 0x68);
            up = &D_001427F0[idx];
            old = *up;
            func_L01_00511958(idx, *(s32 *)(p + 0x60));
            if (old < *up) {
                diff = *up - old;
                if (diff == 1) {
                    re = D_L01_002C5600_0030EAE8 + D_001425C0[idx];
                    ia = re->h36;
                } else {
                    re = D_L01_002C5600_0030EAE8 + D_001425C0[idx];
                    ia = re->h34;
                }
                func_L01_00451FB8_0030EAE8(ia, diff, -1, 0);
            }
            func_L01_004450F0(self, 2, -1);
            qzero(p);
            dd = D_L01_001DFB40 - D_L01_001E1728;
            *(f32 *)(p + 0x70) = 0.16000001f;
            if (abs_asm(dd) >= 9) {
                func_003A52A0(0, 0, self);
                D_L01_001E1728 = D_L01_001DFB40;
            }
        }
        break;
    case 2:
        hero = D_001A4C60;
        vec_sub_ab(&a, self + 0x10, hero);
        func_0038D000(&a, &a, hero - 0x40);
        tgt = 8.0f;
        if (0.0f < a.z) {
            tgt = 0.0f;
        }
        func_003C4138(p + 0x70, tgt, 0.00960000046f);
        func_0038CF68(&b10, hero - 0x60, *(f32 *)(p + 0x70));
        {
            vu0_q qs;
            __asm__("lqc2 $vf1, %1\n"
                    "lqc2 %0, %2\n"
                    "vadd.xyz %0, %0, $vf1\n"
                    : "=j"(qs)
                    : "m"(b10), "m"(*(vu0_v4 *)(self + 0x10))
                    : "vf1");
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(self + 0x10)) : "j"(qs));
        }
        vec_add_ba(self + 0x10, self + 0x10, hero + 0xD0);
        len = func_0038CEA8(p);
        func_003C4138(&len, 1.28000009f, 0.00960000046f);
        vec_sub_ab(&c20, hero + 0x60, self + 0x10);
        dist = func_0038CEA8(&c20) / len;
        if (dist < 25.0f) {
            func_003C4138(self + 0x2C, 0.0f, *(f32 *)(*(u8 **)(self + 0x24) + 0x24) / 25.0f);
        }
        if (*(f32 *)(self + 0x2C) == 0.0f || dist <= 1.0f) {
            func_003C2880(self);
            return;
        }
        func_0038CF68(p, &c20, len);
        vec_add_ab(self + 0x10, self + 0x10, p);
        func_0038CE90(&d30, hero - 0x60, p);
        func_003C4CE8(0.104719758f, &d30, &d30);
        h70 = (vu0_v4){0.0f, 0.0f, 0.0f, 0.0f};
        h70.z = 0.3f;
        func_0038D000(&e40, &h70, self + 0xC0);
        func_0038D810(&d30, &i80);
        func_0038D5F0(self + 0xC0, &i80, self + 0xC0);
        func_0038D000(&f50, &h70, self + 0xC0);
        vec_sub_ba(&g60, &f50, &e40);
        vec_sub_ba(self + 0x10, self + 0x10, &g60);
        break;
    default:
        break;
    }
    if (self[0x20] == 1 && func_L01_0040E5D8(self, D_001A71A0[0]) != 0) {
        bb = self[0x23];
        self[0x23] = bb < 0x25 ? 0x24 : bb - 4;
    } else {
        bb = self[0x23];
        self[0x23] = bb < 0x7C ? bb + 4 : 0x80;
    }
    if ((s8)self[0x23] >= 0) {
        *(u16 *)(self + 0x34) |= 0x2000;
    } else {
        *(u16 *)(self + 0x34) &= 0xDFFF;
    }
}
/* localdecomp:end func_L01_0030EAE8 */

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
