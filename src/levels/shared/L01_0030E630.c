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

/* localdecomp:start func_L01_0030E630 */
extern vu0_v4 D_L01_001E29C0;
extern u8 D_001A4BE0_0030E630[];
extern s32 D_L01_001D673C_0030E630;
extern f32 D_L01_001DC664;
__asm__(".extern D_L01_001DC664, 4");
extern f32 D_L01_001DC668;
__asm__(".extern D_L01_001DC668, 4");
extern f32 D_L01_001DC66C;
__asm__(".extern D_L01_001DC66C, 4");
extern f32 D_L01_001DC670;
__asm__(".extern D_L01_001DC670, 4");
extern f32 D_L01_001DC674;
__asm__(".extern D_L01_001DC674, 4");
extern f32 D_L01_001DC678;
__asm__(".extern D_L01_001DC678, 4");
extern f32 D_L01_001DC67C;
__asm__(".extern D_L01_001DC67C, 4");
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_0013D3E0(void);
extern u8 *func_L01_0046B458(void *, s32, f32, f32, u32, s32, s32, void *, f32, s32);

void func_L01_0030E630(u8 *pos, s32 count, s32 small) {
    vu0_v4 velocity, at, delta, axis, t50;
    f32 size, speed, yaw;
    s32 spin, i;
    u8 *p;

    vec_sub_ab(&delta, &D_L01_001E29C0, pos);
    if (D_L01_001D673C_0030E630 == 0) {
        delta.z = 0.0f;
        axis.x = 0.0f;
        axis.y = 0.0f;
        axis.z = 1.0f;
        axis.w = 1.0f;
    } else {
        vec_sub_ab(&t50, pos, D_001A4BE0_0030E630 + 0xB0);
        func_0038CF68(&axis, &t50, 1.0f);
        func_0038CE20(&t50, &axis, func_0038CE68(&axis, &delta));
        vec_sub_ab(&delta, &delta, &t50);
    }
    for (i = 0; i < count; i++) {
        size = func_003824E0(D_L01_001DC678, D_L01_001DC67C);
        spin = func_00382468(2);
        if (spin == 0) spin--;
        yaw = func_003824E0(-1.0471976f, 1.0471976f);
        func_0038D890(&velocity, &delta, &axis, yaw);
        speed = func_003824E0(D_L01_001DC664, D_L01_001DC668) * 0.020000001f;
        func_0038CF68(&velocity, &velocity, speed);
        velocity.z = func_003824E0(D_L01_001DC66C, D_L01_001DC670) * 0.020000001f;
        *(vu0_q *)&at = *(vu0_q *)pos;
        at.x += func_L01_00443A18(0.0f, 0.15f);
        at.y += func_L01_00443A18(0.0f, 0.15f);
        at.z += func_L01_00443A18(0.0f, 0.15f);
        if (small == 0) {
            if ((func_0013D3E0() & 1) == 0) {
                func_0038CE20(&velocity, &velocity, 1.5f);
                p = func_L01_0046B458(&at, 0x32, size * 0.1f * 3.5f, size, 0x7F800000, 0, spin, &velocity, D_L01_001DC674 * 1.44f, 1);
                if (p) p[9] = 0x74;
                p = func_L01_0046B458(&at, 0x32, size * 0.07f * 3.5f, size * 0.7f, 0x7F7F7F7F, 1, -spin, &velocity, D_L01_001DC674 * 1.44f, 1);
                if (p) p[9] = 0x74;
            } else {
                vec_sub_ba(&t50, &D_L01_001E29C0, &at);
                func_0038CF68(&t50, &t50, speed);
                vec_add_ab(&velocity, &velocity, &t50);
                p = func_L01_0046B458(&at, 0x21, size * 0.1f * 20.5f, size, 0x7F800000, 0, spin, &velocity, D_L01_001DC674 * 1.44f, 1);
                if (p) p[9] = 0x74;
                p = func_L01_0046B458(&at, 0x21, size * 0.07f * 20.5f, size * 0.7f, 0x7F7F7F7F, 1, -spin, &velocity, D_L01_001DC674 * 1.44f, 1);
                if (p) p[9] = 0x74;
            }
        } else {
            if ((func_0013D3E0() & 1) == 0) {
                func_0038CE20(&velocity, &velocity, 1.5f);
                p = func_L01_0046B458(&at, 0x32, size * 0.1f * 3.0f, size, 0x7F800000, 0, spin, &velocity, D_L01_001DC674 * 1.44f, 1);
                if (p) p[9] = 0x74;
                p = func_L01_0046B458(&at, 0x32, size * 0.07f * 3.0f, size * 0.7f, 0x7F7F7F7F, 1, -spin, &velocity, D_L01_001DC674 * 1.44f, 1);
                if (p) p[9] = 0x74;
            } else {
                vec_sub_ba(&t50, &D_L01_001E29C0, &at);
                func_0038CF68(&t50, &t50, speed);
                vec_add_ab(&velocity, &velocity, &t50);
                p = func_L01_0046B458(&at, 0x21, size * 0.1f * 2.5f, size, 0x7F800000, 0, spin, &velocity, D_L01_001DC674 * 1.44f, 1);
                if (p) p[9] = 0x74;
                p = func_L01_0046B458(&at, 0x21, size * 0.07f * 2.5f, size * 0.7f, 0x7F7F7F7F, 1, -spin, &velocity, D_L01_001DC674 * 1.44f, 1);
                if (p) p[9] = 0x74;
            }
        }
    }
}
/* localdecomp:end func_L01_0030E630 */

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

/* localdecomp:start func_L01_0030F288 */
typedef int s128_0030F288 __attribute__((mode(TI)));
typedef union { u8 b[0x2A00]; s32 i[0xA80]; u8 *ptr[0xA80]; s128_0030F288 q[0x2A0]; } Hero_0030F288;
typedef struct { u8 pad0[0x88]; u16 w88; u8 pad8A[0xF0 - 0x8A]; } RecF0_0030F288;
extern Hero_0030F288 D_001A4BE0_0030F288;
extern RecF0_0030F288 D_L01_002C5600_0030F288[];
extern u8 D_001425C0[];
extern s32 D_L01_001D673C;
extern s32 func_L01_00511950(s32);
extern f32 func_00382538(void);
extern void func_003C5180(void *, void *, s32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_00443B88(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_004510A8(void *, void *, void *, s32, f32);
extern u8 *func_L01_003F79D8(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern f32 func_L01_00451580(void *);
extern void func_003C7C38(void *);
extern void func_L01_0044A7D0(void *);
extern void func_L01_0030EAE8_0030F288(void);

u8 *func_L01_0030F288(void *a0, s32 a1, s32 a2, s32 a3) {
    RecF0_0030F288 *row;
    f32 v20[4];
    f32 v30[4];
    f32 f20;
    u8 *r;
    u8 *s1;
    s32 t;

    row = &D_L01_002C5600_0030F288[D_001425C0[func_L01_00511950(a1)]];
    *(s128_0030F288 *)v30 = 0;
    v30[2] = func_00382538();
    *(s128_0030F288 *)v20 = *(s128_0030F288 *)v30;
    if (D_L01_001D673C != 0) {
        func_003C5180(a0, v30, 1);
        v20[1] = func_0038D160(v30[2], func_0038CED8(v30));
        v20[2] = func_0038D160(v30[0], v30[1]);
    }
    func_L01_00443B88(v30, 0.040000003f, 0.080000006f);
    func_L01_004510A8(D_001A4BE0_0030F288.ptr[0x25C0 / 4], v30, v30, 0, func_003824E0(4.0f, 8.0f) * 0.020000001f);
    f20 = func_003824E0(180.0f, 360.0f);
    r = func_L01_003F79D8(D_001A4BE0_0030F288.ptr[0x25C0 / 4], 2, 0xCDB, 0, a0, v20, v30, 0xFF, f20,
                          func_003824E0(10.0f, 15.0f), 0xB4, 0, 0x80);
    if (r != 0) {
        r[0x20] = 1;
        *(void (**)(void))(r + 0x64) = func_L01_0030EAE8_0030F288;
        s1 = *(u8 **)(r + 0x68);
        if (a2 == -1) {
            *(s32 *)(s1 + 0x60) = D_L01_002C5600_0030F288[D_001425C0[func_L01_00511950(a1)]].w88;
        } else {
            *(s32 *)(s1 + 0x60) = a2;
        }
        t = D_L01_001D673C;
        *(s32 *)(s1 + 0x68) = a1;
        *(f32 *)(s1 + 0x6C) = (f32)a3;
        if (t != 0) {
            *(f32 *)(s1 + 0x74) = func_L01_00451580(r + 0x10);
        } else {
            *(f32 *)(s1 + 0x74) = *(f32 *)(r + 0x18);
        }
        func_003C7C38(r);
        func_L01_0044A7D0(r);
    }
    return r;
}
/* localdecomp:end func_L01_0030F288 */

LINKER_REMNANT("asm/levels", func_L01_0030F4E0);

/* localdecomp:start func_L01_0030F4E8 */
#include "vu0.h"
extern s32 D_001427F0[];
extern u8 D_001425C0[];
extern u8 D_L01_002C5600_0030F4E8[];
extern s32 D_L01_001DFB40;
extern s32 D_L01_001E1728;
extern s32 func_L01_00511950(s32);
extern s32 func_L01_00511958_0030F4E8(s32, s32);
extern void func_L01_00451FB8(s32, s32, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);

typedef struct { u8 pad0[0x70]; f32 f70; } Vars_0030F4E8;

s32 func_L01_0030F4E8(u8 *m) {
    u8 *v;
    s32 *tbl;
    s32 a;
    s32 diff;
    f32 lim;
    s32 d;
    s32 arg;
    u8 *row;
    s32 r;

    v = *(u8 **)(m + 0x68);
    if (m[0x20] == 2) {
        return 0;
    }
    tbl = D_001427F0;
    a = tbl[func_L01_00511950(*(s32 *)(v + 0x68))];
    lim = (f32)func_L01_00511958_0030F4E8(*(s32 *)(v + 0x68), *(s32 *)(v + 0x60));
    if (a < tbl[func_L01_00511950(*(s32 *)(v + 0x68))]) {
        diff = tbl[func_L01_00511950(*(s32 *)(v + 0x68))] - a;
        if (diff == 1) {
            row = D_L01_002C5600_0030F4E8 + D_001425C0[func_L01_00511950(*(s32 *)(v + 0x68))] * 0xF0;
            arg = *(s16 *)(row + 0x36);
        } else {
            row = D_L01_002C5600_0030F4E8 + D_001425C0[func_L01_00511950(*(s32 *)(v + 0x68))] * 0xF0;
            arg = *(s16 *)(row + 0x34);
        }
        func_L01_00451FB8(arg, diff, -1, 0);
        if (lim < (f32)*(s32 *)(v + 0x60)) {
            m[0x20] = 2;
            *(f32 *)(m + 0x2C) = *(f32 *)(m + 0x2C) * 1.24f;
            qzero(v);
            ((Vars_0030F4E8 *)v)->f70 = 0.16000001f;
            d = D_L01_001DFB40 - D_L01_001E1728;
            if (abs_asm(d) >= 9) {
                func_003A52A0(0, 0, m);
                D_L01_001E1728 = D_L01_001DFB40;
            }
        }
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L01_0030F4E8 */

INCLUDE_ASM("asm/levels", func_L01_0030F6C0);

LINKER_REMNANT("asm/levels", func_L01_003104A0);
