#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[104];
    u8 *inner;
} Obj3899C0;
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_38C110v;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t q[5];
} S_2BEE10;
typedef struct {
    u8 pad_0[0x80];
    vu0_v4 pos;                /* 0x80 */
    u8 pad_90[0x1D8 - 0x90];
    s32 i1D8;                  /* 0x1D8 */
    u8 pad_1DC[0x6F0 - 0x1DC];
    vu0_v4 aim;                /* 0x6F0 */
    u8 pad_700[0x1210 - 0x700];
    s32 fire_button;           /* 0x1210 */
    u8 pad_1214[0x1220 - 0x1214];
    s32 i1220;                 /* 0x1220 */
    u8 pad_1224[0x1430 - 0x1224];
    u8 *lockon_target;         /* 0x1430 */
    u8 pad_1434[0x16B0 - 0x1434];
    s32 mode;                  /* 0x16B0 */
    u8 pad_16B4[0x25C0 - 0x16B4];
    u8 *camera;                /* 0x25C0 */
    s32 state;                 /* 0x25C4 */
    u8 pad_25C8[0x25E9 - 0x25C8];
    u8 b25E9;                  /* 0x25E9 */
    u8 pad_25EA[0x25ED - 0x25EA];
    u8 no_firing;              /* 0x25ED */
    u8 pad_25EE[0x2874 - 0x25EE];
    s16 h2874;                 /* 0x2874 */
    u8 pad_2876[0x28BC - 0x2876];
    s32 aiming_fire_wait;      /* 0x28BC */
} Hero_38B280_0038B280;

/* localdecomp:start func_L01_00386B38 */
#include "vu0.h"

typedef struct {
    f32 timer;          /* 0x00 */
    s16 h4;             /* 0x04 */
    s16 h6;             /* 0x06 */
    s16 h8;             /* 0x08 */
    s16 hA;             /* 0x0A */
    s32 charge;         /* 0x0C */
    vu0_v4 muzzle;      /* 0x10 */
    f32 f20;            /* 0x20 */
    f32 f24;            /* 0x24 */
    f32 f28;            /* 0x28 */
    f32 f2C;            /* 0x2C */
    vu0_v4 aim_dir;     /* 0x30 */
    s32 w40;            /* 0x40 */
    f32 f44;            /* 0x44 */
    s32 w48;            /* 0x48 */
    s32 rumble;         /* 0x4C */
    u8 pad50[0x10];     /* 0x50 */
    s32 charged;        /* 0x60 */
    s32 sfx;            /* 0x64 */
    f32 f68;            /* 0x68 */
} Vars_00386B38;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;         /* 0x10 */
    u8 phase;           /* 0x20 */
    u8 pad21[0x68 - 0x21];
    Vars_00386B38 *vars;/* 0x68 */
    u8 pad6C[0x98 - 0x6C];
    s32 w98;            /* 0x98 */
    u8 pad9C[0xAA - 0x9C];
    u16 hAA;            /* 0xAA */
    u8 padAC[0xC0 - 0xAC];
    vu0_v4 mat;         /* 0xC0 */
    vu0_v4 fwd;         /* 0xD0 */
} Moby_00386B38;

typedef struct {
    u8 pad0[0x6C0];
    vu0_v4 v6C0;        /* 0x6C0 */
    vu0_v4 v6D0;        /* 0x6D0 */
    u8 pad6E0[0x10];
    vu0_v4 aim;         /* 0x6F0 */
    u8 pad700[0xBD8 - 0x700];
    u8 *pBD8;           /* 0xBD8 */
    u8 padBDC[0x1210 - 0xBDC];
    s32 fire_button;    /* 0x1210 */
    u8 pad1214[0x1220 - 0x1214];
    s32 i1220;          /* 0x1220 */
    u8 pad1224[0x1430 - 0x1224];
    u8 *lockon_target;  /* 0x1430 */
    u8 pad1434[0x16B0 - 0x1434];
    s32 mode;           /* 0x16B0 */
    u8 pad16B4[0x16D4 - 0x16B4];
    s32 w16D4;          /* 0x16D4 */
    s32 w16D8;          /* 0x16D8 */
    u8 pad16DC[0x25C0 - 0x16DC];
    u8 *camera;         /* 0x25C0 */
    s32 state;          /* 0x25C4 */
    u8 pad25C8[4];
    s32 w25CC;          /* 0x25CC */
    u8 pad25D0[0x25E9 - 0x25D0];
    u8 b25E9;           /* 0x25E9 */
    u8 pad25EA[3];
    u8 no_firing;       /* 0x25ED */
    u8 pad25EE[0x2874 - 0x25EE];
    s16 h2874;          /* 0x2874 */
    u8 pad2876[0x28BC - 0x2876];
    s32 aiming_fire_wait; /* 0x28BC */
} Hero_00386B38;

typedef struct {
    u8 pad0[0x24];
    s32 w24;
    u8 pad28[0x6C - 0x28];
    f32 damage;
    u8 pad70[0xF0 - 0x70];
} WRow_00386B38;

typedef struct {
    u8 pad0[0x80];
} Sfx_00386B38;

typedef struct {
    vu0_v4 vec;
    Moby_00386B38 *owner;
    s32 flags;
    u8 b18;
    u8 b19;
    u16 h1A;
    f32 dmg;
    s32 w20;
} Shot_00386B38;

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    u32 cC;
    u32 c10;
    f32 f14;
} Eff_00386B38;

typedef struct {
    u8 pad0[0x184];
    u8 *p184;
    u8 pad188[0x1A0 - 0x188];
    u8 *p1A0;
} Tex_00386B38;

typedef struct {
    u8 pad0[0x20];
    f32 f20;
    u8 pad24[4];
    s32 w28;
    s32 w2C;
    f32 f30;
    u8 pad34[4];
    s32 w38;
} Cam_00386B38;

typedef struct {
    vu0_v4 v0;
    vu0_v4 v1;
} Pair_00386B38;

extern u8 D_001425E7[];
extern s32 D_0014288C[];
extern u8 D_00142A60[];
extern Sfx_00386B38 D_001A30B0[];
extern Hero_00386B38 D_001A4BE0_00386B38;
extern u8 *D_001D52FC;
extern s32 D_001D545C;
extern u8 D_L01_001D66B0[8];
extern s32 D_L01_001D7BE0;
__asm__(".extern D_L01_001D7BE0, 4");
extern s32 D_L01_001DDDB0;
__asm__(".extern D_L01_001DDDB0, 4");
extern s32 D_L01_001DDDB4;
__asm__(".extern D_L01_001DDDB4, 4");
extern s32 D_L01_001DDDB8;
__asm__(".extern D_L01_001DDDB8, 4");
extern s32 D_L01_001DDDBC;
__asm__(".extern D_L01_001DDDBC, 4");
extern s32 D_L01_001DDDC0;
__asm__(".extern D_L01_001DDDC0, 4");
extern s32 D_L01_001DDDE4;
__asm__(".extern D_L01_001DDDE4, 4");
extern s32 D_L01_001DDDEC;
__asm__(".extern D_L01_001DDDEC, 4");
extern f32 D_L01_001DDE04;
__asm__(".extern D_L01_001DDE04, 4");
extern f32 D_L01_001DDE08;
__asm__(".extern D_L01_001DDE08, 4");
extern f32 D_L01_001DDE10;
__asm__(".extern D_L01_001DDE10, 4");
extern f32 D_L01_001DDE14;
__asm__(".extern D_L01_001DDE14, 4");
extern f32 D_L01_001DDE20[2];
__asm__(".extern D_L01_001DDE20, 8");
extern s32 D_L01_001DFB40;
extern s32 D_L01_001E1EA0;
extern s32 D_L01_001E1EA4;
extern s32 D_L01_001E1EBC;
extern u8 D_L01_001E1ED0[8];
extern u8 D_L01_001E1EE0[8];
extern s32 D_L01_001E1EF0[1];
extern s32 D_L01_001E1EF4[1];
extern s32 D_L01_001E1F00;
extern Pair_00386B38 D_L01_001E29E0_00386B38;
extern Cam_00386B38 D_L01_001E2A40_00386B38;
extern Moby_00386B38 *D_L01_001EEA80[];
extern Tex_00386B38 D_L01_00221098_00386B38;
extern u8 *D_L01_00221208[];
extern vu0_v4 D_L01_002906E0[];
extern u8 D_L01_002B3B90[];
extern Eff_00386B38 D_L01_002B3C10_00386B38;
extern WRow_00386B38 D_L01_002C5600_00386B38[];

extern void func_L01_0034C9F0(void *, s32, void *);
extern Moby_00386B38 *func_L01_003882A0_00386B38(void *, void *, void *, void *, f32);
extern void func_L01_003884D8(u8 *);
extern void func_L01_003886E8(u8 *);
extern void func_L01_00388AC8_00386B38(void *, void *);
extern void func_L01_00388EE0_00386B38(void *);
extern void func_L01_00389798_00386B38(void *);
extern void func_L01_003897E8(void);
extern s32 func_L01_003F2058(void *, void *);
extern void func_L01_003F2278(s32, void *);
extern void func_L01_003F6F20(s32, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern void func_L01_00404AD8(void *, void *);
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_0040E050_00386B38(void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_00382538(void);
extern void func_00382580(void *, f32, f32);
extern void func_L01_00446978(void *, void *);
extern void func_L01_00457588(void *, void *, void *, f32);
extern void func_L01_004735F0(void *, void *, s32, f32);
extern s32 func_L01_004AA710(void *, s32);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_004CB1F0(f32, f32);
extern void func_L01_004EA7D8(s32);
extern void func_L01_005003D0(s32, s32);
extern s32 func_L01_005118D0(s32, s32);
extern s32 func_L01_005119E0(s32);

void func_L01_00386B38(Moby_00386B38 *m) {
    extern void func_L01_00404A10(void *, void *);
    extern void func_0038D890(void *, void *, void *, f32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, u32, s32, f32, f32, f32, f32, f32);
    extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
    Vars_00386B38 *v = m->vars;
    union {
        struct {
            vu0_v4 v0;
            vu0_v4 v10;
            Shot_00386B38 shot1;
        } a;
        struct {
            Shot_00386B38 shot0;
            vu0_v4 v30;
            vu0_v4 v40;
        } b;
    } u;
    vu0_v4 v50;
    vu0_v4 v60;
    vu0_v4 v70;
    Moby_00386B38 *hit_mobys[24];
    s32 saved_w98[24];
    vu0_v4 v140;
    vu0_v4 v150;
    s32 can_fire;
    s32 fire_trig;

    if (m->phase == 0) {
        m->phase = 1;
        v->h8 = 0;
        v->hA = 0;
        v->rumble = -1;
        v->sfx = -1;
        D_L01_001E1EA4 = 0;
        D_00142A60[0x27] |= 0x22;
    }
    if (m->phase == 6) {
        if (func_0038CB00(&v->h4) != 0) {
            func_003A52A0(2, 0, m);
            m->phase = 1;
        }
    }
    func_0038D000(&v->muzzle, D_L01_001DDE20, &m->mat);
    vec_add_ab(&v->muzzle, &v->muzzle, &m->pos);
    if (D_001A4BE0_00386B38.state == 1) {
        func_L01_005003D0(0x1D, 1);
    }
    func_L01_0040E050_00386B38(v);
    if (D_001A4BE0_00386B38.state == 0x1D || D_001A4BE0_00386B38.mode != 0) {
        s32 id = func_L01_004CB1F0(0.95f, 150.0f);
        func_L01_003F6F20(0, m, id, 0, 0x5B, -1, 4, 1.0f, 1.5707963705062866f, 90.0f, 0.5f, 0.5f, 30.0f, 55.0f);
    } else {
        D_001A4BE0_00386B38.w16D4 = 0;
        D_001A4BE0_00386B38.w16D8 = 0;
    }
    if (D_001A4BE0_00386B38.lockon_target != 0) {
        D_001A4BE0_00386B38.pBD8 = D_001A4BE0_00386B38.lockon_target;
    }
    can_fire = 1;
    if (D_001A4BE0_00386B38.state == 0x1D) {
        if (func_0038CAD0(&D_001A4BE0_00386B38.aiming_fire_wait) == 0) {
            can_fire = 0;
        }
    } else {
        D_001A4BE0_00386B38.aiming_fire_wait = 0x21;
    }

    if ((*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0_00386B38.fire_button) && func_L01_005119E0(-1) != 0 && D_001A4BE0_00386B38.no_firing == 0) {
        if (v->charge == 0) {
            fire_trig = 1;
        } else {
            fire_trig = 0;
        }
        v->charge++;
        if (func_L01_004AA710(m, v->sfx) == 0) {
            v->sfx = func_003A52A0(3, 4, m);
        }
        if (v->charge >= 0x42) {
            s32 i;
            v->charged = 1;
            for (i = 0; i < 2; i++) {
                s32 life = (func_00382498(10, 20) * 5 + 2) / 6;
                u8 *p = func_L01_004713C8(&v->muzzle, D_L01_001D66B0, life, 0x965050, func_00382498(-1, -3), 0x40, 0, 0,
                                          84000.0f, 220499.984375f, -0.0004000000189989805f);
                if (p != 0) {
                    p[2] = D_L01_00221098_00386B38.p1A0[func_00382498(0, 3)];
                }
            }
            u.b.shot0.vec = v->muzzle;
            for (i = 0; i < 2; i++) {
                s32 life;
                u8 *p;
                u.b.shot0.vec.x += func_003824E0(-0.2f, 0.2f);
                u.b.shot0.vec.y += func_003824E0(-0.2f, 0.2f);
                u.b.shot0.vec.z += func_003824E0(-0.2f, 0.2f);
                life = (func_00382498(10, 20) * 5 + 2) / 6;
                p = func_L01_004713C8(&u.b.shot0.vec, D_L01_001D66B0, life, 0x505096, func_00382498(-1, -3), 0x40, 0, 0,
                                      84000.0f, 220499.984375f, -0.0004000000189989805f);
                if (p != 0) {
                    p[2] = D_L01_00221098_00386B38.p184[func_00382498(5, 7)];
                }
            }
            func_00382580(&u.b.shot0.vec, 0.025f, 0.15f);
            vec_add_ab(&u.b.shot0.vec, &u.b.shot0.vec, &v->muzzle);
            vec_sub_ab(&u.a.v10, &v->muzzle, &u.b.shot0.vec);
            func_0038CF68(&u.a.v10, &u.a.v10, 0.015000000596046448f);
            func_L01_004735F0(&u.b.shot0.vec, &u.a.v10, 12, 1.0f);
            if (func_00382468(2) != 0) {
                s32 r = (s32)func_L01_00443A18(1.0f, -1.0f);
                u8 *p = func_L01_0046A610(&v->muzzle, D_L01_001D66B0, 12, 6, 0x904020, r, 10.0f, 500.0f, 1.0f, 0.0f, 0.0f);
                if (p != 0) {
                    p[2] = D_L01_00221208[0][1];
                }
            }
        } else {
            s32 i;
            for (i = 0; i < 2; i++) {
                s32 life = (func_00382498(10, 20) * 5 + 2) / 6;
                u32 col = ((0xFF - v->charge) << 16) | ((v->charge + 0x80) << 8) | 0x20;
                u8 *p = func_L01_004713C8(&v->muzzle, D_L01_001D66B0, life, col, func_00382498(-1, -3), v->charge / 3, 0, 0,
                                          21000.0f, 115500.0f, -0.0004000000189989805f);
                if (p != 0) {
                    p[2] = D_L01_00221098_00386B38.p1A0[func_00382498(0, 3)];
                }
            }
        }
    } else {
        if ((*(s32 *)(D_001D52FC + 0x1A4) & D_001A4BE0_00386B38.fire_button) && func_L01_005119E0(-1) == 0) {
            func_003A52A0(1, 0, m);
        }
        fire_trig = (v->charge >= 0x42);
        v->charge = 0;
        if (v->sfx != -1) {
            u8 *sx = (u8 *)&D_001A30B0[v->sfx];
            if (*(void **)(sx + 0xDC) == m && sx[0xD0] != 0) {
                func_003A4F28(v->sfx);
            }
        }
        v->sfx = -1;
    }

    if (fire_trig != 0 && m->phase == 1 && v->timer == 0.0f && D_001A4BE0_00386B38.i1220 >= 0x13 && can_fire != 0) {
        if (func_L01_005119E0(-1) != 0) {
            if (D_001A4BE0_00386B38.camera[0x43] == (D_L01_002C5600_00386B38 + D_001425E7[0])->w24 || D_001A4BE0_00386B38.w25CC != 0 || D_001A4BE0_00386B38.h2874 != 0) {
                v->w48 = 1;
                v->h6 = (D_L01_001DDDB0 * 5 + 2) / 6;
                v->h8 = (D_L01_001DDDB8 * 5 + 2) / 6;
                v->hA = (D_L01_001DDDC0 * 5 + 2) / 6;
            } else {
                v->h6 = 2;
                v->w48 = 0;
                v->h8 = (D_L01_001DDDB4 * 5 + 2) / 6;
                v->hA = (D_L01_001DDDBC * 5 + 2) / 6;
            }
            if (v->charged != 0) {
                s32 i;
                for (i = 0; i < 10; i++) {
                    func_L01_005118D0(-1, 1);
                }
            } else {
                func_L01_005118D0(-1, 1);
            }
            D_L01_001E1F00 = 1;
            if (v->charged != 0) {
                D_L01_001E1EF0[0] = 1;
                D_L01_001E1EF4[0] = D_L01_001DFB40;
                D_L01_002B3C10_00386B38.cC = 0x7F804020;
                D_L01_002B3C10_00386B38.c10 = 0x7FFF4020;
                D_L01_002B3C10_00386B38.w0 = 10;
                D_L01_002B3C10_00386B38.w4 = 10;
                D_L01_002B3C10_00386B38.f14 = 1.0f;
            }
            func_L01_004EA7D8(-1);
            v->rumble = func_L01_003F2058(D_L01_002B3B90, 0);
            m->phase = 2;
            v->f68 = func_00382538();
            if (v->charged != 0) {
                D_L01_001E1EA4 = 0x19;
                D_L01_001E1EBC = 0;
                D_L01_001DDE04 = 1.0f;
                D_L01_001DDE08 = 1.0f;
                D_L01_001E1EA0 = (D_L01_001DDDEC * 5 + 2) / 6;
            } else {
                D_L01_001DDE10 = 1.0f;
                D_L01_001E1EBC = 0x11;
                D_L01_001DDE14 = 1.0f;
                D_L01_001E1EA0 = 5;
                D_L01_001E1EA4 = 0;
            }
            v->f20 = 1.0f / (f32)v->h8;
            v->f24 = 1.0f / (f32)v->hA;
            v->f28 = func_00382538();
            v->f2C = func_00382538();
            v->w40 = (D_L01_001DDDE4 * 5 + 2) / 6;
            v->f44 = 1.0f / (f32)v->w40;
        } else {
            if (v->charged != 0 && D_0014288C[0] < 10) {
                v->charged = 0;
            }
            if ((*(s32 *)(D_001D52FC + 0x1A4) & D_001A4BE0_00386B38.fire_button) || D_L01_001E1F00 == 1) {
                func_003A52A0(3, 0, m);
                D_L01_001E1F00 = 0;
            }
        }
        if (!(((*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0_00386B38.fire_button) || ((*(s32 *)(D_001D52FC + 0x1A0) & 8) && D_001A4BE0_00386B38.state == 0x1D)) &&
              func_L01_005119E0(-1) != 0 && D_001A4BE0_00386B38.b25E9 != 0) &&
            v->rumble >= 0) {
            func_L01_003F2278(v->rumble, 0);
            v->rumble = -1;
        }
    }

    if (D_L01_001E1EA4 > 0) {
        s32 i;
        func_00382580(&u.a.shot1.vec, 0.3f, 0.40000003576278687f);
        u.b.shot0.vec.w = 5627.925f;
        u.a.shot1.flags = 0x210000;
        u.a.shot1.w20 = 1;
        u.a.shot1.b18 = 3;
        u.a.shot1.b19 = 2;
        u.a.shot1.h1A = m->hAA;
        u.a.shot1.dmg = (D_L01_002C5600_00386B38 + D_001425E7[0])->damage * 10.0f;
        u.a.shot1.owner = m;
        func_0038CE20(&u.a.v10, &m->fwd, -1.35f);
        vec_add_ab(&u.a.v10, &u.a.v10, &m->pos);
        func_0038CE20(&v50, &m->mat, 0.275f);
        vec_add_ab(&u.a.v10, &u.a.v10, &v50);
        for (i = 0; i < 20; i++) {
            v60 = v->muzzle;
            func_0038CE20(&v70, &D_001A4BE0_00386B38.aim, (f32)(i + 1) * 2.0f);
            vec_add_ab(&D_L01_002906E0[i], &v70, &v60);
            func_003D4D00(&D_L01_002906E0[i], 1, D_001A4BE0_00386B38.camera, &u.a.shot1, 1.5f);
        }
    }
    if (D_L01_001E1EA4 > 0 && D_L01_001E1EA4 < 0x19) {
        func_L01_00404A10(func_L01_003897E8, m);
    }
    if (D_L01_001E1EA4 == 8) {
        D_L01_001E1EF0[0] = 2;
        D_L01_001E1EF4[0] = D_L01_001DFB40;
    }
    if (D_L01_001E1EA4 != 0) {
        s32 i, j;
        func_003C2F58(m, 0, &u.a.v10);
        *(vu0_q *)D_L01_001E1ED0 = *(vu0_q *)&u.a.v10;
        if (D_001A4BE0_00386B38.h2874 != 0) {
            func_0038CE20(&u.b.shot0.vec, &m->fwd, -10.0f);
        } else if (D_001A4BE0_00386B38.mode == 1) {
            func_0038CE20(&u.b.shot0.vec, &D_L01_001E29E0_00386B38.v0, 40.0f);
        } else {
            func_0038CE20(&u.b.shot0.vec, &D_001A4BE0_00386B38.aim, 40.0f);
        }
        vec_add_ab((vu0_v4 *)D_L01_001E1EE0, &u.a.v10, &u.b.shot0.vec);
        for (j = 0; j < 5; j++) {
            s32 life;
            u8 *p;
            func_0038CDF8(&u.a.shot1.vec, D_L01_001E1ED0, (vu0_v4 *)D_L01_001E1EE0, func_003824E0(0.0f, 1.0f));
            life = (func_00382498(10, 18) * 5 + 2) / 6;
            p = func_L01_004713C8(&u.a.shot1.vec, D_L01_001D66B0, life, 0x804020, func_00382498(-1, -3), 0x50, 0, 0,
                                  168000.0f, 315000.0f, -0.0004000000189989805f);
            if (p != 0) {
                p[2] = D_L01_00221098_00386B38.p1A0[func_00382498(0, 3)];
            }
        }
        for (i = 0; i < 1; i++) {
            s32 life = (func_00382498(10, 18) * 5 + 2) / 6;
            u8 *p = func_L01_004713C8(D_L01_001E1ED0, D_L01_001D66B0, life, 0x804020, func_00382498(-1, -3), 0x50, 0, 0,
                                      63000.00390625f, 210000.0f, -0.0004000000189989805f);
            if (p != 0) {
                p[2] = D_L01_00221098_00386B38.p1A0[func_00382498(0, 3)];
            }
        }
    }
    if (v->h6 == 0) {
        func_0038CB00(&v->hA);
        func_0038CB00(&v->h8);
        func_0038CAD0(&v->w40);
        if (v->h8 != 0 || v->hA != 0) {
            func_L01_00404A10(func_L01_00388EE0_00386B38, m);
        }
    }
    if (func_0038CAD0(&D_L01_001E1EA0) == 0) {
        func_L01_00404AD8(func_L01_00389798_00386B38, m);
    }
    if (func_0038CAD0(&D_L01_001E1EA4) == 0) {
        if (D_L01_001E1EA4 >= 0xD) {
            D_L01_001DDE04 += 0.1f;
            D_L01_001DDE08 += 0.1f;
        } else {
            D_L01_001DDE04 -= 0.125f;
            D_L01_001DDE08 -= 0.075f;
        }
        if (D_L01_001E1EA4 < 0x1A) {
            func_L01_00404A10(func_L01_003897E8, m);
        }
        func_L01_00404A10(func_L01_003886E8, m);
    }
    if (func_0038CAD0(&D_L01_001E1EBC) == 0) {
        if (D_L01_001E1EBC >= 0xD) {
            D_L01_001DDE10 += 0.5f;
            D_L01_001DDE14 += 0.3f;
        } else {
            D_L01_001DDE10 -= 0.3f;
            D_L01_001DDE14 -= 0.2f;
        }
        func_L01_00404A10(func_L01_003884D8, m);
    }

    if (m->phase == 2 || m->phase == 3) {
        if (func_0038CB00(&v->h6) != 0) {
            if (D_001A4BE0_00386B38.pBD8 != 0) {
                func_L01_00457588(D_001A4BE0_00386B38.pBD8, &v->muzzle, &D_001A4BE0_00386B38.aim, 1.0f);
                D_001A4BE0_00386B38.v6C0 = D_001A4BE0_00386B38.aim;
            }
            if (m->phase == 2) {
                m->phase = 3;
                func_L01_00388AC8_00386B38(m, &v->muzzle);
                v->aim_dir = D_001A4BE0_00386B38.aim;
                func_L01_00404A10(func_L01_00388EE0_00386B38, m);
                if (v->charged != 0) {
                    func_003A52A0(0, 0, m);
                } else {
                    func_003A52A0(4, 0, m);
                }
                if (v->w48 != 0) {
                    D_L01_001E2A40_00386B38.w2C = 0;
                    D_L01_001E2A40_00386B38.f20 = 0.12f;
                    D_L01_001E2A40_00386B38.w28 = 0x19;
                    D_L01_001E2A40_00386B38.w38 = 0x19;
                    D_L01_001E2A40_00386B38.f30 = 0.12f;
                } else {
                    D_L01_001E2A40_00386B38.w2C = 0;
                    D_L01_001E2A40_00386B38.f20 = 0.06f;
                    D_L01_001E2A40_00386B38.w28 = 0x19;
                    D_L01_001E2A40_00386B38.w38 = 0x19;
                    D_L01_001E2A40_00386B38.f30 = 0.06f;
                }
            } else {
                m->phase = 6;
                v->h4 = 0x11;
                if (v->charged == 0) {
                    s32 i, count;
                    u.b.shot0.flags = 0x410000;
                    u.b.shot0.w20 = 1;
                    u.b.shot0.b18 = 3;
                    u.b.shot0.b19 = 2;
                    u.b.shot0.h1A = m->hAA;
                    u.b.shot0.dmg = (D_L01_002C5600_00386B38 + D_001425E7[0])->damage;
                    u.b.shot0.owner = m;
                    for (i = 0; i < 4 && (!((D_L01_001D7BE0 >= 0 && D_L01_001D7BE0 < 9) || D_001D545C == 0x1C || D_001D545C == 0x16) || i < 1); i++) {
                        s32 n, j;
                        func_0038CE20(&u.b.v30, &m->fwd, (f32)(i + 1) * -1.35f);
                        vec_add_ab(&u.b.v30, &u.b.v30, &m->pos);
                        func_0038CE20(&u.b.v40, &m->mat, (f32)(i + 1) * -0.175f);
                        vec_add_ab(&u.b.v30, &u.b.v30, &u.b.v40);
                        n = func_003D4D00(&u.b.v30, 1, D_001A4BE0_00386B38.camera, 0, (f32)i * 0.25f + 1.5f);
                        for (j = 0; j < n; j++) {
                            if (D_L01_001EEA80[j] != (Moby_00386B38 *)D_001A4BE0_00386B38.camera) {
                                func_0038CE20(&u.b.shot0.vec, &m->fwd, -1.75f);
                                u.b.shot0.vec.w = 5627.925f;
                                func_L01_00446978(D_L01_001EEA80[j], &u.b.shot0);
                                func_L01_0034C9F0(D_L01_001EEA80[j], 39, m);
                            }
                        }
                    }
                    if (v->charged == 0) {
                        s32 k, r, q, p_i;
                        v50 = v->muzzle;
                        if (D_001A4BE0_00386B38.h2874 == 1) {
                            func_0038CE20(&u.b.v30, &m->fwd, -1.0f);
                            func_0038CE20(&u.b.v40, &m->mat, -1.0f);
                        } else if (D_001A4BE0_00386B38.mode == 1) {
                            u.b.v30 = D_L01_001E29E0_00386B38.v0;
                            u.b.v40 = D_L01_001E29E0_00386B38.v1;
                        } else {
                            u.b.v30 = D_001A4BE0_00386B38.v6C0;
                            u.b.v40 = D_001A4BE0_00386B38.v6D0;
                        }
                        v->aim_dir = u.b.v30;
                        count = 0;
                        for (k = 0; k < 23; k++) {
                            hit_mobys[k] = 0;
                            saved_w98[k] = 0;
                        }
                        for (r = 0; r < 23; r++) {
                            f32 ang;
                            Moby_00386B38 *hit;
                            func_0038CF68(&v70, &u.b.v40, 1.0f);
                            func_0038CF68(&v60, &v->aim_dir, 1.0f);
                            ang = func_003824E0(0.0f, -17.0f) * 0.01745329238474369f;
                            func_0038D890(&v140, &v60, &v70, ang);
                            func_0038D890(&v140, &v140, &v60, func_003824E0(-170.0f, 170.0f) * 0.01745329238474369f);
                            func_0038CE20(&v140, &v140, 32.0f);
                            vec_add_ab(&v150, &v50, &v140);
                            hit = func_L01_003882A0_00386B38(m, &v50, &v150, &u.b.shot0, ang);
                            if (hit != 0) {
                                saved_w98[count] = hit->w98;
                                hit_mobys[count] = hit;
                                hit->w98 = 0;
                                count++;
                            }
                        }
                        for (q = 0; q < 3; q++) {
                            Moby_00386B38 *hit;
                            func_0038CF68(&v150, &u.b.v40, 1.0f);
                            func_0038CF68(&v140, &v->aim_dir, 1.0f);
                            func_0038D890(&v60, &v140, &v150, -0.2617993950843811f);
                            func_0038D890(&v60, &v60, &v140, (f32)q * 0.3490658402442932f + -0.3490658402442932f);
                            func_0038CE20(&v60, &v60, 32.0f);
                            vec_add_ab(&v70, &v50, &v60);
                            hit = func_L01_003882A0_00386B38(m, &v50, &v70, &u.b.shot0, -0.2617993950843811f);
                            if (hit != 0) {
                                saved_w98[count] = hit->w98;
                                hit_mobys[count] = hit;
                                hit->w98 = 0;
                                count++;
                            }
                        }
                        for (p_i = 0; p_i < count; p_i++) {
                            hit_mobys[p_i]->w98 = saved_w98[p_i];
                        }
                    }
                }
                v->timer = 0.0f;
                v->charged = 0;
                if (v->sfx != -1) {
                    u8 *sx = (u8 *)&D_001A30B0[v->sfx];
                    if (*(void **)(sx + 0xDC) == m && sx[0xD0] != 0) {
                        func_003A4F28(v->sfx);
                    }
                }
                v->sfx = -1;
            }
        }
    }
}
/* localdecomp:end func_L01_00386B38 */

/* localdecomp:start func_L01_003882A0 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_003882A0;
typedef struct { u8 pad[0x46]; u8 kind; } Class_003882A0;
typedef struct { u8 pad[0x24]; Class_003882A0 *cls; } Moby_003882A0;
typedef struct { u8 pad[0x18]; Moby_003882A0 *moby; } Hit_003882A0;
typedef struct { u8 pad[0x6C]; f32 damage; u8 tail[0x80]; } WeaponRow_003882A0;

extern Hit_003882A0 D_L01_001EAA00;
extern Vec_003882A0 D_L01_001EAA20;
extern WeaponRow_003882A0 D_L01_002C5600_003882A0[];
extern u8 D_001425E7[];
extern s32 D_001A71A0[];

/* shock_cannon_ray_test: tests one of the Shock Cannon's rays from start to end. On a hit, the
 * distance sets the damage (all of it under 10 u, 3/4 under 14, 1/2 under 20, else 1/8), queued on
 * the moby hit; returns that moby if its class is of kind 5, else 0. */
Moby_003882A0 *func_L01_003882A0(void *gun, Vec_003882A0 *start, Vec_003882A0 *end, Vec_003882A0 *shot, f32 radius) {
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern void *func_L01_00389B00_003882A0(void *, void *, void *, s32, f32);
    extern f32 func_0038CF00(void *, void *);
    extern void func_L01_00446978(void *, void *);
    extern void func_L01_0034C9F0(void *, s32, void *);
    Vec_003882A0 delta;
    f32 damage, dist;
    Moby_003882A0 *moby, *ret;
    Vec_003882A0 *hit_pos;

    vec_sub_ab(shot, end, start);
    func_0038CF68(shot, shot, 1.5f);
    shot->w = 5627.925f;
    if (func_003D3CB0(start, end, 16, D_001A71A0[0], 0)) {
        vec_sub_ab(&delta, end, start);
        func_0038CF68(&delta, &delta, 1.0f);
        hit_pos = &D_L01_001EAA20;
        vec_sub_ab(&delta, hit_pos, start);
        func_L01_00389B00_003882A0(start, &delta, hit_pos, 1, radius);
        if (((s32 *)hit_pos)[-2]) {
            damage = ((WeaponRow_003882A0 *)D_L01_002C5600_003882A0)[D_001425E7[0]].damage;
            dist = func_0038CF00(hit_pos, start);
            if (dist < 10.0f) ((f32 *)shot)[7] = damage;
            else if (dist < 14.0f) ((f32 *)shot)[7] = damage * 0.75f;
            else if (dist < 20.0f) ((f32 *)shot)[7] = damage * 0.5f;
            else ((f32 *)shot)[7] = damage * 0.125f;
            func_L01_00446978(D_L01_001EAA00.moby, shot);
            func_L01_0034C9F0(D_L01_001EAA00.moby, 39, gun);
            moby = D_L01_001EAA00.moby;
            ret = 0;
            if (moby != 0) {
                Class_003882A0 *cls = moby->cls;
                ret = moby;
                if (cls == 0 || cls->kind != 5) ret = 0;
            }
        } else {
            ret = 0;
        }
    } else {
        vec_sub_ab(&delta, end, start);
        func_L01_00389B00_003882A0(start, &delta, end, 0, -1.0f);
        ret = 0;
    }
    return ret;
}
/* localdecomp:end func_L01_003882A0 */

/* localdecomp:start func_L01_003884D8 */
#include "vu0.h"

extern void func_0038CE20(void *, void *, f32);
extern f32 D_L01_001DDE14;
extern f32 D_L01_001DDE10;
extern f32 D_L01_001DDE0C;
extern s32 D_L01_001DDE30;
extern s32 D_L01_001DDE34;
__asm__(".extern D_L01_001DDE14,4");
__asm__(".extern D_L01_001DDE10,4");
__asm__(".extern D_L01_001DDE0C,4");
__asm__(".extern D_L01_001DDE30,4");
__asm__(".extern D_L01_001DDE34,4");
extern f32 D_L01_001E1EC0;
extern s32 D_L01_001E1EBC;

void func_L01_003884D8(u8 *obj) {
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32,f32);
    extern void func_0038D328(s128 *,S_38C110v *);
    extern void func_003D9740(s128 *,s32,u32,s32,s32,f32);
    s128 mat[4];
    S_38C110v pos;
    S_38C110v dir;
    S_38C110v rot;
    S_38C110v offset;
    u8 *basis=obj+0xD0;
    pos=*(S_38C110v *)(*(u8 **)(obj+0x68)+0x10);
    func_0038CE20(&dir,basis,-1.0f);
    rot.x=0;
    rot.y=-func_0038D160(func_0038CED8(&dir),dir.z) + -1.5707964f;
    rot.z=func_0038D160(dir.x,dir.y);
    rot.w=1.0f;
    func_0038D328(mat,&rot);
    func_0038CE20(&offset,basis,-1.0f);
    func_0038CE20(&offset,&offset,5.0f);
    vec_add_ab(&pos,&pos,&offset);
    mat[3]=*(s128 *)&pos;
    func_0038CE20(&mat[0],&mat[0],D_L01_001DDE14);
    func_0038CE20(&mat[1],&mat[1],D_L01_001DDE10);
    func_0038CE20(&mat[2],&mat[2],D_L01_001DDE0C);
    D_L01_001E1EC0+=0.2f;
    if (D_L01_001E1EC0>=7.0f) D_L01_001E1EC0-=7.0f;
    func_003D9740(mat,D_L01_001DDE30,((D_L01_001E1EBC*5)<<24)|0xFF8080,4,1,D_L01_001E1EC0);
    func_0038CE20(&mat[0],&mat[0],D_L01_001DDE14*1.25f);
    func_0038CE20(&mat[1],&mat[1],D_L01_001DDE10*1.25f);
    func_003D9740(mat,D_L01_001DDE34,((D_L01_001E1EBC*3)<<24)|0xBF0530,2,1,D_L01_001E1EC0);
}
/* localdecomp:end func_L01_003884D8 */

/* localdecomp:start func_L01_003886E8 */
typedef struct {
    u8 pad0[0x16B0]; s32 mode;
    u8 pad16B4[0x25C0 - 0x16B4]; u8 *camera;
    u8 pad25C4[0x2874 - 0x25C4]; s16 aiming;
} Hero_003886E8;
extern Hero_003886E8 D_001A4BE0_003886E8;
extern s128 D_L01_001E29E0;
extern f32 D_L01_001DDE00, D_L01_001DDE04, D_L01_001DDE08;
extern s32 D_L01_001DDDF4, D_L01_001DDDF8, D_L01_001DDDFC;
extern s32 D_L01_001E1EA4;
extern f32 D_L01_001E1EA8, D_L01_001E1EAC, D_L01_001E1EB0;
__asm__(".extern D_L01_001DDE00, 4");
__asm__(".extern D_L01_001DDE04, 4");
__asm__(".extern D_L01_001DDE08, 4");
__asm__(".extern D_L01_001DDDF4, 4");
__asm__(".extern D_L01_001DDDF8, 4");
__asm__(".extern D_L01_001DDDFC, 4");

/* shock_cannon_domes_draw: the Shock Cannon lance's three spinning domes (fx_dome), from the gun
 * along the aim, the camera's facing, or the scripted direction, opening out along the lance. */
void func_L01_003886E8(u8 *moby) {
    extern void func_003C2F58(void *, s32, void *);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    extern void func_0038D328(s128 *, S_38C110v *);
    extern void func_0038D890(f32 *, f32 *, f32 *, f32);
    extern void func_003D9740(s128 *, s32, u32, s32, s32, f32);
    struct { s128 matrix[4], position, direction; S_38C110v rotation; s128 offset; } v;
    func_003C2F58(moby, 0, &v.position);
    if (D_001A4BE0_003886E8.aiming) {
        func_0038CE20(&v.direction, moby + 0xD0, -1.0f);
    } else if (D_001A4BE0_003886E8.mode == 1) {
        v.direction = D_L01_001E29E0;
    } else {
        v.direction = *(s128 *)(D_001A4BE0_003886E8.camera + 0xC0);
    }
    v.rotation.x = 0.0f;
    v.rotation.y = -func_0038D160(func_0038CED8(&v.direction), ((f32 *)&v.direction)[2]) + -1.57079637f;
    v.rotation.z = func_0038D160(((f32 *)&v.direction)[0], ((f32 *)&v.direction)[1]);
    v.rotation.w = 1.0f;
    func_0038D328(v.matrix, &v.rotation);
    if (D_001A4BE0_003886E8.aiming) {
        func_0038CE20(&v.offset, moby + 0xD0, -1.0f);
    } else if (D_001A4BE0_003886E8.mode == 1) {
        v.offset = D_L01_001E29E0;
    } else {
        v.offset = *(s128 *)(D_001A4BE0_003886E8.camera + 0xC0);
    }
    func_0038CE20(&v.offset, &v.offset, D_L01_001DDE00 - 0.5f);
    vec_add_ab(&v.position, &v.position, &v.offset);
    v.matrix[3] = v.position;
    func_0038CE20(&v.matrix[0], &v.matrix[0], D_L01_001DDE08);
    func_0038CE20(&v.matrix[1], &v.matrix[1], D_L01_001DDE04);
    func_0038CE20(&v.matrix[2], &v.matrix[2], D_L01_001DDE00);
    /* each dome's spin, wrapped at 7 */
    D_L01_001E1EA8 += 0.15f;
    if (D_L01_001E1EA8 >= 7.0f) D_L01_001E1EA8 -= 7.0f;
    D_L01_001E1EAC += 0.1f;
    if (D_L01_001E1EAC >= 7.0f) D_L01_001E1EAC -= 7.0f;
    D_L01_001E1EB0 += 0.05f;
    if (D_L01_001E1EB0 >= 7.0f) D_L01_001E1EB0 -= 7.0f;
    func_0038D890((f32 *)&v.matrix[0], (f32 *)&v.matrix[0], (f32 *)&v.matrix[2], 0.785398185f);
    func_0038D890((f32 *)&v.matrix[1], (f32 *)&v.matrix[1], (f32 *)&v.matrix[2], 0.785398185f);
    func_003D9740(v.matrix, D_L01_001DDDF4, (D_L01_001E1EA4 << 25) | 0x804020, 8, 1, D_L01_001E1EA8);
    func_0038D890((f32 *)&v.matrix[0], (f32 *)&v.matrix[0], (f32 *)&v.matrix[2], -1.57079637f);
    func_0038D890((f32 *)&v.matrix[1], (f32 *)&v.matrix[1], (f32 *)&v.matrix[2], -1.57079637f);
    func_003D9740(v.matrix, D_L01_001DDDF8, (D_L01_001E1EA4 << 25) | 0x801040, 8, 1, D_L01_001E1EAC);
    func_003D9740(v.matrix, D_L01_001DDDFC, (D_L01_001E1EA4 << 25) | 0x804010, 8, 1, D_L01_001E1EB0);
    func_0038CE20(&v.matrix[0], &v.matrix[0], 1.1f);
    func_0038CE20(&v.matrix[1], &v.matrix[1], 1.1f);
    func_003D9740(v.matrix, 10, (D_L01_001E1EA4 << 24) | 0xD20A40, 6, 1, D_L01_001E1EA8);
}
/* localdecomp:end func_L01_003886E8 */

/* localdecomp:start func_L01_00388AC8 */
#include "vu0.h"
typedef struct {
    u8 pad_0[0x110];
    s128 velocity;              /* 0x110 */
    u8 pad_120[0x360 - 0x120];
    s32 moving;                 /* 0x360 */
    u8 pad_364[0x6C0 - 0x364];
    S_38C110v axes[2];          /* 0x6C0 */
} Hero_00388AC8;
extern Hero_00388AC8 D_001A4BE0_00388AC8;
extern u8 *D_L01_00221098[];

/* A burst of 20 smoke puffs (particle_spawn_smoke) and embers (particle_spawn_ember) from position,
 * thrown out along a direction tilted 20 deg about the hero's axes and spun by a random angle each
 * time, carrying 1.7 x the hero's velocity when he moves. */
void func_L01_00388AC8(void *unused, s128 *position) {
    extern void func_0038D890(f32 *, f32 *, f32 *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D850(void *, void *, void *);
    S_38C110v spin, direction, base, origin, velocity, point, inherited, offset;
    s32 i, kind;
    f32 angle = 0.0f;
    u8 *particle;

    *(s128 *)&base = 0;
    base.x = 0.3f;
    base.y = -1.0f;
    base.w = 1.0f;
    *(s128 *)&origin = *position;
    func_0038D890((f32 *)&base, (f32 *)&D_001A4BE0_00388AC8.axes[0], (f32 *)&D_001A4BE0_00388AC8.axes[1], 0.34906584f);
    direction = base;
    qzero(&inherited);
    if (D_001A4BE0_00388AC8.moving)
        func_0038CE20(&inherited, &D_001A4BE0_00388AC8.velocity, 1.7f);
    func_0038CE20(&offset, &D_001A4BE0_00388AC8.axes[0], 0.4f);
    vec_add_ab(&origin, &origin, &offset);
    for (i = 0; i < 20; i++) {
        angle = func_0038DAB8(angle, func_003824E0(0.0f, 0.62831855f));
        func_0038CE20(&velocity, &direction, func_003824E0(0.24000001f, 0.32000002f));
        vec_add_ab(&velocity, &velocity, &inherited);
        point.x = origin.x + func_L01_00443A18(0.0f, 0.3f);
        point.y = origin.y + func_L01_00443A18(0.0f, 0.3f);
        point.z = origin.z + func_L01_00443A18(0.0f, 0.3f);
        kind = (s32)func_L01_00443A18(1.0f, 2.0f);
        particle = func_L01_004669B0(&point, 0.0f, 1.0f, 1.01f, func_003824E0(0.2f, 0.75f) * 210000.0f, kind,
                                     &D_001A4BE0_00388AC8.velocity, 0x7FFFFFFF, 0);
        if (particle) {
            u8 *p;
            particle[3] = 72;
            *(s16 *)(particle + 10) = 50;
            p = particle + 0x20;
            particle[9] = 68;
            *(f32 *)(p + 0x1C) = 4.0f;
            *(s32 *)(p + 4) = 3;
            p[10] = 48;
            p[11] = particle[10];
        }
        point.x = origin.x + func_L01_00443A18(0.0f, 0.6f);
        point.y = origin.y + func_L01_00443A18(0.0f, 0.6f);
        point.z = origin.z + func_L01_00443A18(0.0f, 0.6f);
        {
            f32 size = func_003824E0(0.2f, 1.75f);
            vec_sub_ab(&point, &point, &velocity);
            particle = func_L01_0046A610(&point, &velocity, 5, 127, 0x404040, kind, size * 210000.0f, 500.0f, 0.95f, 0.0f, 0.0f);
        }
        if (particle) particle[2] = D_L01_00221098[0x5B][1];
        if (fabs_asm(angle) > 0.00001f) {
            func_003C4840(&spin, &D_001A4BE0_00388AC8.axes[0], angle);
            func_0038D850(&direction, &base, &spin);
        }
    }
    {
        f32 scale = func_003824E0(8.0f, 12.0f) * 0.020000001f;
        func_0038CE20(&base, &D_001A4BE0_00388AC8.axes[0], scale);
    }
}
/* localdecomp:end func_L01_00388AC8 */

/* localdecomp:start func_L01_00388EE0 */
typedef struct {
    vu0_v4 pos[4];
    u32 colour[4];
    f32 uv[4][2];
    u8 pad70[0x20];
} Quad_00388EE0;
typedef struct { u8 pad[0x150]; s16 h150; s16 h152; } Screen_00388EE0;
typedef struct {
    u8 pad_0[0x8];
    s16 h8;
    s16 hA;
    u8 pad_C[4];
    vu0_v4 pos;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    vu0_v4 v30;
    s32 w40;
    f32 f44;
    u8 pad_48[0x68 - 0x48];
    f32 f68;
} Vars_00388EE0;
typedef struct {
    u8 pad_0[0x10];
    f32 x, y, z;
    u8 pad_1C[0x68 - 0x1C];
    Vars_00388EE0 *vars;
} Moby_00388EE0;
typedef struct {
    u8 pad_0[0x80];
    f32 x, y;
    u8 pad_88[0x25C4 - 0x88];
    s32 state;
} Hero_00388EE0;
typedef struct { u8 pad[0x140]; f32 x, y; } Cam_00388EE0;
extern Screen_00388EE0 D_001CFEC0_00388EE0;
extern Hero_00388EE0 D_001A4BE0_00388EE0;
extern Cam_00388EE0 D_L01_001E2880;
extern vu0_v4 D_L01_001E2A40;
extern f32 D_L01_001DDDC4, D_L01_001DDDC8, D_L01_001DDDCC, D_L01_001DDDD0, D_L01_001DDDD4;
extern f32 D_L01_001DDDD8, D_L01_001DDDDC, D_L01_001DDDE0, D_L01_001DDDE8;
__asm__(".extern D_L01_001DDDC4, 4");
__asm__(".extern D_L01_001DDDC8, 4");
__asm__(".extern D_L01_001DDDCC, 4");
__asm__(".extern D_L01_001DDDD0, 4");
__asm__(".extern D_L01_001DDDD4, 4");
__asm__(".extern D_L01_001DDDD8, 4");
__asm__(".extern D_L01_001DDDDC, 4");
__asm__(".extern D_L01_001DDDE0, 4");
__asm__(".extern D_L01_001DDDE8, 4");

/* the four corners of a ribbon quad: centre +/- a (along) +/- b (across), through t */
static __inline__ void ribbon_00388EE0(Quad_00388EE0 *q, vu0_v4 *c, vu0_v4 *a, vu0_v4 *b, vu0_v4 *t) {
    vec_add_ab(t, c, a);
    vec_add_ab(&q->pos[0], t, b);
    vec_sub_ab(&q->pos[1], t, b);
    vec_sub_ab(t, c, a);
    vec_add_ab(&q->pos[2], t, b);
    vec_sub_ab(&q->pos[3], t, b);
}

/* the beam moby's draw: an 8-way starburst core of quads, 40 sparks around the hero (unless in state 7),
   two rotating cross ribbons and, when vars->w40 is set, a glow ribbon and the screen flash */
void func_L01_00388EE0(Moby_00388EE0 *moby) {
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D850(void *, void *, void *);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
    extern void func_0038AF30(s32, s32, s32, s32, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003A9440(s32, s32);
    extern u8 *D_L01_00221098[];
    Quad_00388EE0 quad;
    vu0_v4 pos, hit, dir, c, d, e, f, h100, h110, h120, h130, h140, h150;
    Vars_00388EE0 *vars = moby->vars;
    s32 i, j, life, spin, colour;
    f32 k, k1, angle, lerp;
    u8 *p;

    *(vu0_q *)&pos = *(vu0_q *)&vars->pos;
    func_003C5180(&pos, &hit, 1);
    vec_sub_ba(&dir, &D_L01_001E2A40, &pos);
    func_0038CF68(&dir, &dir, 1.0f);
    if (vars->h8 != 0) {
        k1 = (f32)vars->h8 * vars->f20;
        func_003D93B0(&quad, 0x1A, 1, 0x80);
        colour = ((s32)(k1 * 255.0f) << 24) | 0xFF4020;
        quad.colour[0] = quad.colour[1] = quad.colour[2] = quad.colour[3] = colour;
        quad.uv[0][0] = 0.5f; quad.uv[0][1] = 0.0f;
        quad.uv[1][0] = 0.5f; quad.uv[1][1] = 1.0f;
        quad.uv[2][0] = 1.0f; quad.uv[2][1] = 0.0f;
        quad.uv[3][0] = 1.0f; quad.uv[3][1] = 1.0f;

        func_0038CE20(&c, &hit, D_L01_001DDDC4);
        vec_add_ab(&d, &pos, &c);
        func_003C4840(&e, &dir, vars->f68);
        func_0038D850(&c, &c, &e);
        for (i = 0; i < 8; i++) {
            func_0038CE90(&f, &dir, &c);
            func_0038CF68(&f, &f, D_L01_001DDDC8);
            vec_add_ab(&quad.pos[0], &pos, &f);
            vec_sub_ab(&quad.pos[1], &pos, &f);
            func_0038CE20(&f, &f, D_L01_001DDDCC / D_L01_001DDDC8);
            vec_add_ab(&h100, &pos, &c);
            vec_add_ab(&quad.pos[2], &h100, &f);
            vec_sub_ab(&quad.pos[3], &h100, &f);
            func_003D2DA0(&quad, 0, 0);
            if (i < 7) {
                func_003C4840(&e, &dir, 0.7853982f);
                func_0038D850(&c, &c, &e);
            }
        }
        if (D_001A4BE0_00388EE0.state != 7) {
            for (j = 39; j >= 0; j--) {
                angle = func_0038D160(D_001A4BE0_00388EE0.x - D_L01_001E2880.x, D_001A4BE0_00388EE0.y - D_L01_001E2880.y);
                func_L01_00443A18(1.0f, 2.0f);
                f.x = moby->x + func_L01_00443A18(0.0f, 0.15f);
                f.y = moby->y + func_L01_00443A18(0.0f, 0.15f);
                f.z = moby->z - 0.3f;
                angle = func_0038DAB8(angle, func_L01_00443A18(0.0f, -6.2831855f));
                h100.x = func_0038D098(angle) * 0.20000002f;
                h100.y = func_0038D0B0(angle) * 0.20000002f;
                h100.z = 0.0f;
                life = (func_00382498(10, 30) * 5 + 2) / 6;
                spin = func_00382498(-2, -4);
                p = func_L01_004713C8(&f, &h100, life, 0x707070, spin, 0x40, 0, 63000.004f, 168000.0f, 0.0f, 0);
                if (p != 0) {
                    p[2] = D_L01_00221098[23][0];
                }
            }
        }
    }
    k = (f32)vars->hA * vars->f24;
    vars->f28 = func_0038DAB8(vars->f28, D_L01_001DDDD8 * 0.017453292f);
    vars->f2C = func_0038DAB8(vars->f2C, D_L01_001DDDDC * 0.017453292f);
    func_003D93B0(&quad, 0x3D, 1, 0x80);
    colour = ((s32)(k * 20.0f) << 24) | 0xFF8080;
    quad.uv[0][0] = 0.0f; quad.uv[0][1] = 0.0f;
    quad.uv[1][0] = 0.0f; quad.uv[1][1] = 1.0f;
    quad.uv[2][0] = 1.0f; quad.uv[2][1] = 0.0f;
    quad.uv[3][0] = 1.0f; quad.uv[3][1] = 1.0f;
    quad.colour[0] = quad.colour[1] = quad.colour[2] = quad.colour[3] = colour;
    func_0038CE20(&c, &vars->v30, k * -16.0f + 16.0f);
    vec_add_ba(&d, &pos, &c);
    vec_sub_ab(&e, &D_L01_001E2A40, &d);
    func_0038CF68(&e, &e, 1.0f);
    func_003C4840(&f, &e, vars->f28);
    func_0038CE90(&h100, &e, &hit);
    func_0038CE90(&h110, &h100, &e);
    func_0038D850(&h120, &h110, &f);
    lerp = D_L01_001DDDD4 + (D_L01_001DDDD0 - D_L01_001DDDD4) * k;
    func_0038CF68(&h120, &h120, lerp);
    func_0038CE90(&h130, &e, &h120);
    func_0038CF68(&h130, &h130, lerp);
    ribbon_00388EE0(&quad, &d, &h120, &h130, &h140);
    func_003D2DA0(&quad, 0, 0);
    func_003C4840(&f, &e, vars->f2C);
    func_0038D850(&h120, &h110, &f);
    func_0038CE20(&h120, &h120, lerp);
    func_0038CE90(&h130, &e, &h120);
    func_0038CF68(&h130, &h130, lerp);
    ribbon_00388EE0(&quad, &d, &h120, &h130, &h140);
    func_003D2DA0(&quad, 0, 0);
    if (vars->w40 != 0) {
        k = (f32)vars->w40 * vars->f44;
        func_003D93B0(&quad, 0xB, 4, 0x80);
        colour = ((s32)(k * 255.0f) << 24) | 0x808080;
        quad.colour[0] = quad.colour[1] = quad.colour[2] = quad.colour[3] = colour;
        func_0038CE20(&h150, &dir, -0.1f);
        vec_add_ba(&d, &D_L01_001E2A40, &h150);
        func_0038CE90(&h130, &dir, &hit);
        func_0038CF68(&h130, &h130, D_L01_001DDDE0);
        func_0038CE90(&h120, &h130, &dir);
        func_0038CF68(&h120, &h120, D_L01_001DDDE0);
        ribbon_00388EE0(&quad, &d, &h120, &h130, &h140);
        func_003D2DA0(&quad, 0, 0);
        colour = ((s32)(D_L01_001DDDE8 * k) << 24) | 0x808080;
        quad.colour[0] = quad.colour[1] = quad.colour[2] = quad.colour[3] = colour;
        func_003A9440(0x42, 0x48);
        func_0038AF30(0, D_001CFEC0_00388EE0.h152, 0, D_001CFEC0_00388EE0.h150, quad.colour[0]);
    }
}
/* localdecomp:end func_L01_00388EE0 */

/* localdecomp:start func_L01_00389798 */
typedef struct {
    u8 pad_0[0x10];
    u8 position[0x10];
} ShotVars_389798;
typedef struct {
    u8 pad_0[0x68];
    ShotVars_389798 *vars;
} Moby_389798;

/* The screen warp's timer: 6 frames for an uncharged shot, 27 charged (0x1E1F20 on NTSC-U) */
extern s32 D_L01_001E1EA0;
extern void func_L01_00389810(void *position, s32 texture, s32 alpha, f32 a, f32 b, f32 c, f32 d);

/* shock_cannon_warp: the Shock Cannon's screen warp each frame its timer runs: texture 66 at
   5 x the timer; the four floats (1, 0, 0, 0.9) aren't read */
void func_L01_00389798(Moby_389798 *shot) {
    func_L01_00389810(shot->vars->position, 0x42, D_L01_001E1EA0 * 5, 1.0f, 0.0f, 0.0f, 0.9f);
}
/* localdecomp:end func_L01_00389798 */

/* localdecomp:start func_L01_003897E8 */
/* The charged lance's beam state (0x1E1F50 on NTSC-U); declared small so its address is one la,
   as retail builds it. */
extern u8 D_L01_001E1ED0[8];
/* The beam's numbers: fade times, half width, texture spacing (0x2B3C90 on NTSC-U) */
extern u8 D_L01_002B3C10[];
extern void func_L01_0040B858(void *beam, void *numbers);

/* shock_cannon_beam_draw: draws the Shock Cannon's charged lance beam with fx_beam_rings:
   texture 69 from the gun 40 u along the aim */
void func_L01_003897E8(void) {
    func_L01_0040B858(D_L01_001E1ED0, D_L01_002B3C10);
}
/* localdecomp:end func_L01_003897E8 */

/* localdecomp:start func_L01_00389810 */
extern s32 D_001D5520;
extern s16 D_001CFEC0[];
extern s32 D_L01_001DDE38;
__asm__(".extern D_L01_001DDE38, 4");
extern s32 D_L01_001DDE40;
__asm__(".extern D_L01_001DDE40, 4");
extern s32 D_L01_001DDE44;
__asm__(".extern D_L01_001DDE44, 4");
extern s32 D_L01_001DDE48;
__asm__(".extern D_L01_001DDE48, 4");
extern s32 D_L01_001DDE4C;
__asm__(".extern D_L01_001DDE4C, 4");
extern s32 D_L01_001DDE50;
__asm__(".extern D_L01_001DDE50, 4");
extern s32 D_L01_001DDE54;
__asm__(".extern D_L01_001DDE54, 4");
extern s32 D_L01_001DDE58;
__asm__(".extern D_L01_001DDE58, 4");
extern s32 D_L01_001DDE5C;
__asm__(".extern D_L01_001DDE5C, 4");
extern s32 D_L01_001DDE60;
__asm__(".extern D_L01_001DDE60, 4");
extern s32 D_L01_001DDE64;
__asm__(".extern D_L01_001DDE64, 4");
extern s32 D_L01_001DDE68;
__asm__(".extern D_L01_001DDE68, 4");
extern s32 D_L01_001DDE6C;
__asm__(".extern D_L01_001DDE6C, 4");
extern s32 D_L01_001DDE70;
__asm__(".extern D_L01_001DDE70, 4");
extern s32 D_L01_001DDE94;
__asm__(".extern D_L01_001DDE94, 4");
extern void func_L01_004C5E28(void);
/* the file's earlier blocks declare it with a 32-bit value; these calls pass the full 64-bit GS register */
extern void func_003A9440(s32, unsigned long);
extern unsigned long func_00389598(s32 a);
extern void func_0038B4D0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, long i, long j);

/* shock_cannon_warp_draw: the screen warp, texture 66 into the frame's alpha in four mirrored quarters, then the frame's copy mixed in */
void func_L01_00389810(void *position, s32 texture, s32 alpha, f32 a, f32 b, f32 c, f32 d) {
    long tex, col;

    func_L01_004C5E28();
    if (D_001D5520 != 0) {
        D_L01_001DDE94 = -1;
        D_L01_001DDE6C = 0xEC;
        D_L01_001DDE70 = 0xF0;
    }
    ((void (*)(s32, long))func_003A9440)(0x47, 0x513F1);
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDE44 | ((long)D_L01_001DDE48 << 2) | ((long)D_L01_001DDE4C << 4) | ((long)D_L01_001DDE50 << 6)) | (0x8000L << 24));
    tex = func_00389598(D_L01_001DDE38);
    col = (s32)((alpha << 24) | 0x7F7F7F);
    func_0038B4D0(0, 0, (s32)((f32)D_001CFEC0[0xA8] * 0.5f), (s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(D_001CFEC0[0xA8], 0, -(s32)((f32)D_001CFEC0[0xA8] * 0.5f), (s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(0, D_001CFEC0[0xA9], (s32)((f32)D_001CFEC0[0xA8] * 0.5f), -(s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(D_001CFEC0[0xA8], D_001CFEC0[0xA9], -(s32)((f32)D_001CFEC0[0xA8] * 0.5f), -(s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDE44 | ((long)D_L01_001DDE48 << 2) | ((long)D_L01_001DDE4C << 4) | ((long)D_L01_001DDE50 << 6)) | (0x8000L << 24));
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDE54 | ((long)D_L01_001DDE58 << 2) | ((long)D_L01_001DDE5C << 4) | ((long)D_L01_001DDE60 << 6)) | (0x8000L << 24));
    func_0038B4D0(0, 0, D_001CFEC0[0xA8], D_001CFEC0[0xA9], D_L01_001DDE64, D_L01_001DDE68, D_L01_001DDE6C, D_L01_001DDE70, D_L01_001DDE40, func_00389598(D_L01_001DDE94));
}
/* localdecomp:end func_L01_00389810 */

/* localdecomp:start func_L01_00389B00 */
#include "vu0.h"
typedef struct {
    s128 position;             /* 0x00 */
    u8 pad_10[0x10];
    vu0_v4 velocity;           /* 0x20 */
    u8 pad_30[4];
    s32 owner;                 /* 0x34 */
    s32 life;                  /* 0x38 */
    f32 fade;                  /* 0x3C */
    u8 pad_40[0x10];
    vu0_v4 back;               /* 0x50 */
    f32 value;                 /* 0x60 */
} Vars_00389B00;
typedef struct Moby_00389B00 {
    u8 pad_0[0x10];
    s128 pos;                  /* 0x10 */
    u8 b20;                    /* 0x20 */
    u8 pad_21[0xF];
    u8 b30;                    /* 0x30 */
    u8 b31;                    /* 0x31 */
    u16 h32;                   /* 0x32 */
    u16 h34;                   /* 0x34 */
    u8 pad_36[0x68 - 0x36];
    Vars_00389B00 *vars;       /* 0x68 */
} Moby_00389B00;
extern u8 *func_003C24B0(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0038A4B8(void *);

Moby_00389B00 *func_L01_00389B00(s128 *position, void *direction, s128 *rotation, s32 owner, f32 value)
{
    Moby_00389B00 *moby = (Moby_00389B00 *)func_003C24B0(0x1883, 0x80);
    if (moby != 0) {
        Vars_00389B00 *vars = moby->vars;
        s128 *pos = &moby->pos;
        vu0_v4 back;
        moby->b30 = 0xFF;
        moby->b20 = 0;
        moby->h32 = 0xFF;
        moby->b31 = 1;
        moby->h34 |= 0x41;
        func_0038CF68(&vars->velocity, direction, 0.16000001f);
        vars->position = *position;
        moby->pos = *rotation;
        func_0038CF68(&back, &vars->velocity, -1.5f);
        vec_add_ab(&vars->back, position, &back);
        vars->value = value;
        vars->owner = owner;
        vars->fade = 0.05882353f;
        vars->life = 17;
        func_L01_0038A4B8(pos);
    }
    return moby;
}
/* localdecomp:end func_L01_00389B00 */

/* localdecomp:start func_L01_00389C28 */
#include "vu0.h"
typedef struct { vu0_v4 old, normal, copy, center, spawn; } Work_00389C28;
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
extern u8 *D_L01_0022116C[];
extern u8 *D_L01_00221098[];
void func_L01_00389C28(u8 *obj) {
    extern void func_003C5180(void *, void *, s32);
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern s32 func_0038CAD0(void *);
    extern void func_003C2880(u8 *);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
    extern void func_L01_0038A0F8(void *);
    extern void func_L01_00404A10(void (*)(void *), void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    Work_00389C28 w;
    u8 *vars=*(u8 **)(obj+0x68);
    u8 *p;
    s32 spin, life, i;
    f32 t, angle, size;
    *(vu0_q *)&w.old=*(vu0_q *)(obj+0x10);
    func_003C5180(obj+0x10,&w.normal,1);
    *(vu0_q *)&w.copy=*(vu0_q *)(obj+0x10);
    if (func_L01_004CB2D8()) {
        func_L01_004CAB30(obj+0x10,obj+0x10);
        func_L01_004CAB30(vars+0x50,vars+0x50);
        func_L01_004CAB30(vars,vars);
    }
    if (obj[0x20]==0) {
        vec_add_ab(vars+0x50, vars+0x50, vars+0x20);
        if (func_0038CAD0(vars+0x38)) {
            func_003C2880(obj);
            return;
        }
        func_0038CF68(&w.center,vars+0x20,-0.5f);
        vec_add_ab(&w.center, obj+0x10, &w.center);
        spin=func_00382468(255);
        func_L01_004CB2D8();
        p=func_L01_0046FB40(&w.center,D_L01_001D66B0,2,0x802020,spin,32,16,420000.0f,420000.0f,0.0f,2);
        if (p) p[2]=*D_L01_0022116C[0];
        spin=(spin+128)%255;
        p=func_L01_0046FB40(&w.center,D_L01_001D66B0,2,0x802020,spin,32,16,420000.0f,420000.0f,0.0f,2);
        if (p) p[2]=*D_L01_0022116C[0];
        func_L01_00404A10(func_L01_0038A0F8,obj);
        for (i=1;i>=0;i--) {
            u8 *first;
            u8 *second;
            t=func_003824E0(0.0f,1.0f);
            func_0038CDF8(&w.spawn,vars,&w.center,t);
            spin=func_00382468(255);
            angle=-(*(f32 *)(vars+0x60)*180.0f/3.1415927f);
            t*=20.0f;
            t-=angle;
            angle*=0.01f;
            life=t;
            size=1.8f-angle*5.0f;
            if (life>=10) life=9;
            else if (life<2) life=2;
            w.spawn.x+=func_L01_00443A18(0.0f,0.04f);
            w.spawn.y+=func_L01_00443A18(0.0f,0.04f);
            w.spawn.z+=func_L01_00443A18(0.0f,0.04f);
            life=(life*5+2)/6;
            first=func_L01_0046FB40(&w.spawn,vars+0x20,life,0x808080,spin,48,0,size*210000.0f,size*0.2f*210000.0f,0.0f,2);
            if (first) first[2]=D_L01_00221098[91][1];
            size*=0.5f;
            second=func_L01_0046FB40(&w.spawn,vars+0x20,life,0x808080,spin,48,0,size*210000.0f,size*0.2f*210000.0f,0.0f,2);
            if (second) second[2]=D_L01_00221098[91][1];
        }
    }
    if (*(f32 *)(obj+0x10)<2.0f || *(f32 *)(obj+0x10)>1021.0f ||
        *(f32 *)(obj+0x14)<2.0f || *(f32 *)(obj+0x14)>1021.0f ||
        *(f32 *)(obj+0x18)<2.0f || *(f32 *)(obj+0x18)>1021.0f) func_003C2880(obj);
}
/* localdecomp:end func_L01_00389C28 */

/* localdecomp:start func_L01_0038A0F8 */
#include "vu0.h"
typedef struct {
    vu0_v4 position[4];
    u32 colour[4];
    f32 uv[4][2];
    u8 pad70[0x20];
} Quad_0038A0F8;
extern s32 D_L01_001DDEA0;
extern s32 D_L01_001DDEA4;
extern vu0_v4 D_L01_001E29C0;
__asm__(".extern D_L01_001DDEA0, 4");
__asm__(".extern D_L01_001DDEA4, 4");

/* shock_cannon_ray_draw: draws the Shock Cannon's ray (class 0x1883) from the moby to the end point
 * in its vars (+0x50) as camera-facing quads, their u scrolled by vars+0x30 each frame: the first
 * texture in (0x20, 0x40, 0x80) blended over two halves, then the second in (0, 0x40, 0xFF), its
 * alpha 96 x life x fade. */
void func_L01_0038A0F8(u8 *moby) {
    extern void func_003D93B0(Quad_0038A0F8 *, s32, s32, s32);
    extern void func_003D2DA0(Quad_0038A0F8 *, s32, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    Quad_0038A0F8 quad;
    vu0_v4 eye, step, end, side;
    u8 *vars;
    f32 intensity, *uv;
    s32 i;
    u32 colour;

    vars = *(u8 **)(moby + 0x68);
    if (moby == 0) return;
    if (moby[0x20] == 0xFE) return;
    if (moby[0x20] == 0xFD) return;
    if (vars == 0) return;
    intensity = (f32)*(s32 *)(vars + 0x38) * *(f32 *)(vars + 0x3C);
    func_003D93B0(&quad, D_L01_001DDEA0, 0, 0x80);
    colour = ((s32)(intensity * 96.0f) << 24) | 0x804020;
    quad.colour[1] = colour;
    quad.colour[0] = colour;
    quad.colour[3] = colour;
    quad.colour[2] = colour;
    quad.uv[0][0] = 0.0f;
    quad.uv[0][1] = 0.0f;
    quad.uv[1][0] = 0.0f;
    quad.uv[1][1] = 1.0f;
    quad.uv[2][0] = 1.0f;
    quad.uv[2][1] = 0.0f;
    quad.uv[3][0] = 1.0f;
    quad.uv[3][1] = 1.0f;
    uv = &quad.uv[0][0];
    for (i = 3; i >= 0; i--, uv += 2) {
        *uv += *(f32 *)(vars + 0x30);
        if (*uv >= 7.0f) *uv -= 7.0f;
    }
    *(f32 *)(vars + 0x30) += 0.1f;
    if (*(f32 *)(vars + 0x30) >= 4.0f) *(f32 *)(vars + 0x30) -= 4.0f;
    vec_sub_ab(&eye, moby + 0x10, &D_L01_001E29C0);
    vec_sub_ab(&step, vars + 0x50, moby + 0x10);
    func_0038CE20(&step, &step, 0.5f);
    vec_add_ba(&end, moby + 0x10, &step);
    func_0038CE90(&side, &eye, &step);
    func_0038CF68(&side, &side, 1.4f);
    vec_add_ba(&quad.position[0], moby + 0x10, &side);
    vec_sub_ab(&quad.position[1], moby + 0x10, &side);
    func_0038CF68(&side, &side, 0.6f);
    vec_add_ba(&quad.position[2], &end, &side);
    vec_sub_ba(&quad.position[3], &end, &side);
    func_003D2DA0(&quad, 0, 0);
    quad.colour[0] = quad.colour[2];
    quad.colour[1] = quad.colour[3];
    quad.colour[3] = 0x204080;
    quad.colour[2] = 0x204080;
    *(vu0_q *)&quad.position[0] = *(vu0_q *)&quad.position[2];
    *(vu0_q *)&quad.position[1] = *(vu0_q *)&quad.position[3];
    vec_add_ba(&quad.position[2], &quad.position[2], &step);
    vec_add_ab(&quad.position[3], &quad.position[3], &step);
    func_003D2DA0(&quad, 0, 0);
    func_003D93B0(&quad, D_L01_001DDEA4, 1, 0x80);
    colour = ((s32)(intensity * 96.0f) << 24) | 0xFF4000;
    quad.uv[0][0] = 0.0f;
    quad.uv[0][1] = 0.0f;
    quad.uv[1][0] = 0.0f;
    quad.uv[1][1] = 1.0f;
    quad.colour[1] = colour;
    quad.uv[2][0] = 1.0f;
    quad.uv[2][1] = 0.0f;
    quad.uv[3][0] = 1.0f;
    quad.colour[0] = colour;
    quad.colour[3] = 0xFF4000;
    quad.uv[3][1] = 1.0f;
    quad.colour[2] = 0xFF4000;
    func_0038CF68(&side, &side, 0.6f);
    vec_add_ba(&quad.position[0], moby + 0x10, &side);
    vec_sub_ab(&quad.position[1], moby + 0x10, &side);
    vec_add_ab(&end, moby + 0x10, &step);
    vec_add_ba(&end, &end, &step);
    vec_add_ab(&quad.position[2], &end, &side);
    vec_sub_ab(&quad.position[3], &end, &side);
    func_003D2DA0(&quad, 0, 0);
}
/* localdecomp:end func_L01_0038A0F8 */

/* localdecomp:start func_L01_0038A4B8 */
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
extern u8 *D_L01_00221098[];

void func_L01_0038A4B8(void *p) {
    extern f32 func_0038D160(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    vu0_v4 *origin = p;
    vu0_v4 delta, velocity, position;
    f32 angle, speed, tilt, yaw;
    f32 life;
    s32 type, i;
    u8 *particle;

    vec_sub_ab(&delta, &D_L01_001E29C0, origin);
    angle = func_0038D160(delta.x, delta.y);
    for (i = 14; i >= 0; i--) {
        speed = func_003824E0(0.5f, 1.0f);
        type = func_L01_00443A18(1.0f, 2.0f);
        func_003824E0(0.05f, 0.2f);
        life = 210000.0f;
        tilt = func_003824E0(0.0f, 1.3962634f);
        yaw = func_0038DAB8(angle, func_L01_00443A18(0.0f, 1.3962634f));
        func_00382760(&velocity, speed * 0.020000001415610313f, yaw, tilt);
        position.x = origin->x + func_L01_00443A18(0.0f, 0.1f);
        position.y = origin->y + func_L01_00443A18(0.0f, 0.1f);
        position.z = origin->z + func_L01_00443A18(0.0f, 0.1f);
        particle = func_L01_0046A610(&position, &velocity, 25, 127, 0x7F7F7F, type,
            func_003824E0(0.05f, 0.2f) * life, 500.0f, 1.0f, 0.0f, 2.0f);
        if (particle) particle[2] = D_L01_00221098[0x5B][1];
    }
}
/* localdecomp:end func_L01_0038A4B8 */

/* localdecomp:start func_L01_0038A708 */
typedef struct {
    u8 pad_0[0x1D8];
    s32 i1D8;                  /* 0x1D8 */
    u8 pad_1DC[0x6F0 - 0x1DC];
    S_38C110v aim;             /* 0x6F0 */
    u8 pad_700[0x1210 - 0x700];
    s32 fire_button;           /* 0x1210 */
    u8 pad_1214[0x1220 - 0x1214];
    s32 i1220;                 /* 0x1220 */
    u8 pad_1224[0x1430 - 0x1224];
    u8 *lockon_target;         /* 0x1430 */
    u8 pad_1434[0x25C0 - 0x1434];
    u8 *moby;                  /* 0x25C0 */
    s32 state;                 /* 0x25C4 */
    u8 pad_25C8[0x25E9 - 0x25C8];
    u8 b25E9;                  /* 0x25E9 */
    u8 pad_25EA[0x25ED - 0x25EA];
    u8 no_firing;              /* 0x25ED */
    u8 pad_25EE[0x28BC - 0x25EE];
    s32 aiming_fire_wait;      /* 0x28BC */
} Hero_0038A708;
typedef struct {
    u8 pad_0[0x10];
    u8 landing[0x10];          /* 0x10 */
    f32 timer;                 /* 0x20 */
    s32 w24;                   /* 0x24 */
    s32 w28;                   /* 0x28 */
    s32 rumble;                /* 0x2C */
} Vars_0038A708;
typedef struct {
    u8 pad_0[0x20];
    u8 phase;                  /* 0x20 */
    u8 pad_21[0x42 - 0x21];
    u8 b42;                    /* 0x42 */
    u8 b43;                    /* 0x43 */
    u8 pad_44[0x60 - 0x44];
    u8 b60;                    /* 0x60 */
    u8 pad_61[0x68 - 0x61];
    Vars_0038A708 *vars;       /* 0x68 */
} Moby_0038A708;
typedef struct { u8 pad_0[0x50]; f32 rate; u8 pad_54[0xF0 - 0x54]; } Row_0038A708;
typedef struct { s32 w[5]; } Skip_0038A708;
typedef struct { s32 w[6]; } Skip2_0038A708;
extern Hero_0038A708 D_001A4BE0_0038A708;
extern u8 *D_001D52FC;
extern s32 D_001D545C;
extern u8 D_00142637[];
extern u8 D_L01_001DAFF0_0038A708;
extern s32 D_L01_001D673C_0038A708;
extern s32 D_L01_001E1F10_0038A708;
extern f32 D_L01_001DDEA8_0038A708;
__asm__(".extern D_L01_001DDEA8_0038A708, 4");
extern f32 D_L01_001DDEAC_0038A708;
__asm__(".extern D_L01_001DDEAC_0038A708, 4");
extern f32 D_L01_001DDEB0_0038A708;
__asm__(".extern D_L01_001DDEB0_0038A708, 4");
extern f32 D_L01_001DDEB4_0038A708;
__asm__(".extern D_L01_001DDEB4_0038A708, 4");
extern Skip_0038A708 D_L01_001DDEB8_0038A708;
extern Skip2_0038A708 D_L01_001DDED0_0038A708;
extern u8 D_L01_002B3C60_0038A708[];
extern Row_0038A708 D_L01_002C5600_0038A708[];
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_00444F38_0038A708(u8 *, s32, s32, s32, s32);
extern u8 *func_00382348(void *);
extern s32 func_0038CAD0(void *);
extern u8 *func_L01_004501E8_0038A708(void *, void *, f32, f32, f32, f32, void *, s32, s32, s32, f32, s32, void *, s32, s32, s32);
extern void func_L01_0038AD40_0038A708(void *, void *, void *, s32, f32, f32, f32, f32);
extern s32 func_L01_004C7A18_0038A708(f32, void *, void *, void *, void *, void *, s32, s32);
extern void func_L01_004EAA80_0038A708(void);
extern s32 func_L01_005118D0_0038A708(s32, s32);
extern void func_L01_004EA7D8_0038A708(s32);
extern s32 func_L01_003F2058_0038A708(void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00362610_0038A708(void *, void *, void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_005119E0_0038A708(s32);
extern void func_L01_003F2278_0038A708(s32, void *);
extern s32 func_L01_0040E050_0038A708(void *);
extern void func_L01_00404A10_0038A708(void *, void *);
extern void func_L01_0038ACE8_0038A708(void *);

void func_L01_0038A708(Moby_0038A708 *m)
{
    Vars_0038A708 *vars = m->vars;
    u8 *target;
    S_38C110v pos;
    union { Skip_0038A708 skip; S_38C110v dir; } u;
    Skip2_0038A708 skip2;
    s32 at;
    s32 at2;
    s32 can_fire;

    func_003C2F58(m, 0, &pos);
    if (m->b42 == m->b43 && (m->b60 & 2))
        func_L01_00444F38_0038A708((u8 *)m, 1, 0, 2, 0);
    target = 0;
    if (D_001A4BE0_0038A708.lockon_target != 0 && D_001A4BE0_0038A708.lockon_target[0x20] != 0xFE &&
        D_001A4BE0_0038A708.lockon_target[0x20] != 0xFD) {
        f32 *health = (f32 *)func_00382348(D_001A4BE0_0038A708.lockon_target);
        if (health != 0 && 0.0f < *health)
            target = D_001A4BE0_0038A708.lockon_target;
    }
    can_fire = 1;
    if (D_001A4BE0_0038A708.state == 0x1D || D_001A4BE0_0038A708.state == 1) {
        if (func_0038CAD0(&D_001A4BE0_0038A708.aiming_fire_wait) == 0)
            can_fire = 0;
    } else {
        D_001A4BE0_0038A708.aiming_fire_wait = 0x21;
        if (target == 0) {
            u.skip = D_L01_001DDEB8_0038A708;
            target = func_L01_004501E8_0038A708(&pos, &D_001A4BE0_0038A708.aim, 0.39269909262657166f, 1.5707963705062866f,
                                       11.100000381469727f, 0.0f, &at, 0, 0, 0, 0.0f, 0, &u.skip, 1, -1, 0);
        }
    }
    if (D_L01_001DAFF0_0038A708 != 0 && D_001D545C == 5) {
        skip2 = D_L01_001DDED0_0038A708;
        target = func_L01_004501E8_0038A708(&pos, &D_001A4BE0_0038A708.aim, 0.8726646304130554f, 1.0471975803375244f,
                                   30.0f, 0.0f, &at2, 0, 0, 0, 0.0f, 0, &skip2, 1, -1, 0);
        if (target != 0 && *(s16 *)(target + 0xAA) == 0x1A13) {
            D_L01_001DDEA8_0038A708 = 10.0f;
            D_L01_001DDEB4_0038A708 = 50.0f;
        } else {
            D_L01_001DDEA8_0038A708 = 12.0f;
            D_L01_001DDEB4_0038A708 = 12.5f;
        }
    } else if (D_L01_001D673C_0038A708 != 0) {
        D_L01_001DDEA8_0038A708 = 6.0f;
        D_L01_001DDEB4_0038A708 = 12.5f;
    } else {
        D_L01_001DDEA8_0038A708 = 12.0f;
        D_L01_001DDEB4_0038A708 = 12.5f;
    }
    func_L01_0038AD40_0038A708(&u.dir, &pos, target, 0, D_L01_001DDEAC_0038A708, D_L01_001DDEA8_0038A708,
                      D_L01_001DDEB4_0038A708 * 0.020000001415610313f, D_L01_001DDEB0_0038A708 * 0.0004000000189989805f);
    vars->w24 = func_L01_004C7A18_0038A708(D_L01_001DDEB0_0038A708 * 0.0004000000189989805f, &pos, &u.dir, vars, vars->landing,
                                  m, 0, 0);
    switch (m->phase) {
    case 0:
        m->phase = 1;
        vars->rumble = -1;
        vars->timer = 0.0f;
        vars->w28 = 0;
    case 1:
        if (D_001A4BE0_0038A708.i1D8 >= 0x12)
            func_L01_004EAA80_0038A708();
        if (can_fire && vars->timer == 0.0f && D_001A4BE0_0038A708.no_firing == 0 &&
            (*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0_0038A708.fire_button) &&
            D_001A4BE0_0038A708.i1220 >= 0x13) {
            if (func_L01_005118D0_0038A708(-1, 1)) {
                D_L01_001E1F10_0038A708 = 1;
                func_L01_004EA7D8_0038A708(-1);
                vars->rumble = func_L01_003F2058_0038A708(D_L01_002B3C60_0038A708, 0);
                func_L01_00444F38_0038A708((u8 *)m, 2, 0, 2, 0);
                if (target != 0)
                    func_0038D890(&u.dir, &u.dir, D_001A4BE0_0038A708.moby + 0xD0, -0.17453292012214661f);
                else
                    func_0038D890(&u.dir, &u.dir, D_001A4BE0_0038A708.moby + 0xD0, 0.08726646006107330f);
                if (func_0038CEA8(&u.dir) > 0.6000000238418579f)
                    func_0038CF68(&u.dir, &u.dir, 0.4400000274181366f);
                func_L01_00362610_0038A708(&pos, &u.dir, m, 1, 0);
                func_003A52A0(0, 0, m);
                vars->timer = 1.0f / (D_L01_002C5600_0038A708 + D_00142637[0])->rate;
            } else if ((*(s32 *)(D_001D52FC + 0x1A4) & D_001A4BE0_0038A708.fire_button) || D_L01_001E1F10_0038A708 == 1) {
                func_003A52A0(1, 0, m);
                D_L01_001E1F10_0038A708 = 0;
            }
            if (!((*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0_0038A708.fire_button) && func_L01_005119E0_0038A708(-1) &&
                  D_001A4BE0_0038A708.b25E9 != 0) && vars->rumble >= 0) {
                func_L01_003F2278_0038A708(vars->rumble, 0);
                vars->rumble = -1;
            }
        }
        break;
    }
    func_L01_0040E050_0038A708(&vars->timer);
    func_L01_00404A10_0038A708(func_L01_0038ACE8_0038A708, m);
}
/* localdecomp:end func_L01_0038A708 */

/* localdecomp:start func_L01_0038ACE8 */

extern s32 func_L01_005119E0(s32);
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, f32);

void func_L01_0038ACE8(Obj3899C0 *obj) {
    u8 *p = obj->inner;
    if (*(s32 *)(p + 36) == 0) {
        return;
    }
    if (func_L01_005119E0(-1)) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_0038ACE8 */

/* localdecomp:start func_L01_0038AD40 */
#include "vu0.h"
typedef int u128_4C4A18 __attribute__((mode(TI)));
typedef struct {
    u128_4C4A18 pos;
    f32 x10;
    f32 x14;
    f32 x18;
    u8 *x1C;
} E_4C4A18;
typedef struct {
    u8 pad0[872];
    s16 x368;
    u8 pad36A[8790];
    u8 *x25C0;
} S_4C4A18;
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_004C4AD8;
typedef struct {
    u8 p0[0x10];
    Vec4_004C4AD8 x10;
} O_004C4AD8;
typedef struct {
    u8 p0[0xE0];
    Vec4_004C4AD8 xE0;
} P_004C4AD8;
typedef struct {
    Vec4_004C4AD8 x0;
    f32 x10;
    f32 x14;
    f32 x18;
    O_004C4AD8 *x1C;
} T_004C4AD8;
typedef struct { u8 pad[0x368]; s16 state; u8 gap[0x25C0-0x36A]; u8 *camera; s32 mode; u8 gap2[0x25ED-0x25C8]; u8 disabled; } Hero_004C7438;
extern S_4C4A18 D_001A4BE0_0038AD40;
extern s32 D_L01_001D6740;
extern s32 D_L01_001D673C;
extern u8 *D_001D52FC;
extern Vec4_004C4AD8 D_L01_001E29E0_0038AD40;
void func_L01_0038AD40(Vec4_004C4AD8 *out, Vec4_004C4AD8 *pos, u8 *moby, u8 *camera,
                     f32 minimum, f32 maximum, f32 speed, f32 acceleration) {
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003C5180(u128_4C4A18 *, E_4C4A18 *, s32);
    extern void func_L01_005003D0(s32, s32);
    extern s32 func_003A3BB8(s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_0038CE68(Vec4_004C4AD8 *, T_004C4AD8 *);
    extern void func_0038CE90(Vec4_004C4AD8 *, Vec4_004C4AD8 *, T_004C4AD8 *);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D098(f32);
    extern void func_0038D810(Vec4_004C4AD8 *, Vec4_004C4AD8 *);
    extern void func_0038D5F0(Vec4_004C4AD8 *, Vec4_004C4AD8 *, Vec4_004C4AD8 *);
    extern f32 func_0038CEA8(void *);
    extern f32 func_L01_004451A8(f32);
    extern void func_0038D000(void *, void *, void *);
    extern u8 *func_00382348(void *);
    Vec4_004C4AD8 v, temp, direction, target, delta, correction;
    Vec4_004C4AD8 from, to, accel, result;
    Vec4_004C4AD8 basis[4];
    Vec4_004C4AD8 quat, axis, unit, rotated[3], matrix[3], point;
    f32 distance, denominator, plane, angle, t, inv;
    f32 *data;
    if (camera) {
        *(u128_4C4A18 *)&basis[0] = *(u128_4C4A18 *)(camera+0x10);
        *(u128_4C4A18 *)&basis[1] = *(u128_4C4A18 *)(camera+0xC0);
        *(u128_4C4A18 *)&basis[2] = *(u128_4C4A18 *)(camera+0xD0);
        *(u128_4C4A18 *)&basis[3] = *(u128_4C4A18 *)(camera+0xE0);
    } else {
        *(u128_4C4A18 *)&basis[0] = *(u128_4C4A18 *)(D_001A4BE0_0038AD40.x25C0+0x10);
        *(u128_4C4A18 *)&basis[1] = *(u128_4C4A18 *)((u8 *)&D_001A4BE0_0038AD40+0x6C0);
        *(u128_4C4A18 *)&basis[2] = *(u128_4C4A18 *)((u8 *)&D_001A4BE0_0038AD40+0x6D0);
        *(u128_4C4A18 *)&basis[3] = *(u128_4C4A18 *)((u8 *)&D_001A4BE0_0038AD40+0x6E0);
    }
    out->x=1; out->y=0; out->z=0; out->w=0;
    if (D_001A4BE0_0038AD40.x368 && !D_L01_001D6740)
        func_0038CE20(&direction,(Vec4_004C4AD8 *)(D_001A4BE0_0038AD40.x25C0+0xE0),-1.0f);
    else func_003C5180((u128_4C4A18 *)&basis[0],(E_4C4A18 *)&direction,0);
    distance=maximum;
    if (!moby) {
        if (((Hero_004C7438 *)&D_001A4BE0_0038AD40)->mode==1) func_L01_005003D0(29,1);
        if ((*(s32 *)(D_001D52FC+0x1A0)&func_003A3BB8(4,0)) && !((Hero_004C7438 *)&D_001A4BE0_0038AD40)->disabled) {
            func_0038CF68(&unit,&D_L01_001E29E0_0038AD40,1.0f);
            angle=func_0038CE68(&unit,(T_004C4AD8 *)&direction);
            func_0038CE20(&temp,&direction,angle);
            vec_sub_ab(&v, &unit, &temp);
            func_0038CF68(&v,&v,1.0f);
            func_0038CE90(&axis,&unit,(T_004C4AD8 *)&v);
            angle=func_0038CE68(&unit,(T_004C4AD8 *)&v)*0.5f;
            func_0038CE20(&quat,&axis,func_0038D0B0(angle));
            quat.w=func_0038D098(angle);
            func_0038D810(&quat,matrix);
            func_0038D5F0(rotated,matrix,&D_L01_001E29E0_0038AD40);
            plane=-func_0038CE68(&basis[0],(T_004C4AD8 *)&direction);
            func_0038CF68(&point,&D_L01_001E29E0_0038AD40,1.0f);
            denominator=func_0038CE68(&direction,(T_004C4AD8 *)&point);
            if (denominator>0.0f) {
                func_0038CE20(&point,&point,(func_0038CE68(&direction,(T_004C4AD8 *)((u8 *)&D_L01_001E29E0_0038AD40-0x20))+plane)/denominator);
                vec_sub_ba(&point, (u8 *)&D_L01_001E29E0_0038AD40 - 0x20, &point);
                vec_sub_ba(&point, &point, (u8 *)&D_L01_001E29E0_0038AD40 - 0x20);
                angle=func_0038CE68(&point,(T_004C4AD8 *)&direction);
                func_0038CE20(&temp,&direction,angle);
                vec_sub_ab(&v, &point, &temp);
                distance=func_0038CEA8(&v);
                if (maximum<distance) distance=maximum;
                else if (distance<minimum) distance=minimum;
            }
            distance=maximum*func_L01_004451A8(distance/maximum);
            func_0038D000(out,out,rotated);
        } else func_0038D000(out,out,&basis[1]);
        func_0038CF68(out,out,distance);
        vec_add_ba(&target, out, &basis[0]);
    } else {
        *(u128_4C4A18 *)&target=*(u128_4C4A18 *)(moby+0x10);
    }
    vec_sub_ab(&delta, &target, pos);
    angle=func_0038CE68(&delta,(T_004C4AD8 *)&direction);
    func_0038CE20(&temp,&direction,angle);
    vec_sub_ba(&v, &delta, &temp);
    func_0038CF68(out,&v,speed);
    t=func_0038CEA8(&v)/speed;
    inv=1.0f/t;
    angle=func_0038CE68(pos,(T_004C4AD8 *)&direction);
    func_0038CE20(&from,&direction,angle);
    angle=func_0038CE68(&target,(T_004C4AD8 *)&direction);
    func_0038CE20(&to,&direction,angle);
    func_0038CE20(&accel,&direction,acceleration*(t*t)*0.5f);
    vec_sub_ba(&result, &from, &to);
    vec_add_ba(&result, &result, &accel);
    func_0038CE20(&result,&result,-1.0f);
    func_0038CE20(&correction,&result,inv);
    vec_add_ab(out, out, &correction);
}
/* localdecomp:end func_L01_0038AD40 */

/* localdecomp:start func_L01_0038B280 */
#include "vu0.h"

typedef struct {
    u8 pad_0[0x10];
    u8 landing[0x10];          /* 0x10 */
    f32 timer;                 /* 0x20 */
    s32 w24;                   /* 0x24 */
    u8 pad_28[4];
    s32 rumble;                /* 0x2C */
} InfVars_38B280_0038B280;
typedef struct {
    u8 pad_0[0x10];
    vu0_v4 pos;                /* 0x10 */
    u8 phase;                  /* 0x20 */
    u8 pad_21[0x42 - 0x21];
    u8 b42;                    /* 0x42 */
    u8 b43;                    /* 0x43 */
    u8 pad_44[0x60 - 0x44];
    u8 b60;                    /* 0x60 */
    u8 pad_61[0x68 - 0x61];
    InfVars_38B280_0038B280 *vars;      /* 0x68 */
    u8 pad_6C[0xC0 - 0x6C];
    u8 matrix[0x10];           /* 0xC0 */
    u8 forward[0x10];          /* 0xD0 */
} Inf_38B280_0038B280;
typedef struct { u8 pad_0[0x50]; f32 rate; u8 pad_54[0xF0 - 0x54]; } Row_38B280_0038B280;
typedef struct { s32 w[5]; } Skip_38B280_0038B280;

extern Hero_38B280_0038B280 D_001A4BE0;
extern u8 *D_001D52FC;
extern u8 D_001425F7[];
extern s32 D_L01_001D673C_0038B280;
extern s32 D_L01_001E1F14_0038B280;
extern f32 D_L01_001DDEF0_0038B280;
__asm__(".extern D_L01_001DDEF0_0038B280, 4");
extern f32 D_L01_001DDEF4_0038B280;
__asm__(".extern D_L01_001DDEF4_0038B280, 4");
extern f32 D_L01_001DDEF8_0038B280;
__asm__(".extern D_L01_001DDEF8_0038B280, 4");
extern f32 D_L01_001DDEFC_0038B280;
__asm__(".extern D_L01_001DDEFC_0038B280, 4");
extern f32 D_L01_001DDF00_0038B280[2];
__asm__(".extern D_L01_001DDF00_0038B280, 8");
extern Skip_38B280_0038B280 D_L01_001DDF10_0038B280;
extern u8 D_L01_002B3CE0_0038B280[];
extern Row_38B280_0038B280 D_L01_002C5600_0038B280[];
extern u8 D_L01_001D66B0_0038B280[8];
extern u8 *D_L01_0022123C_0038B280[];

extern void func_003C2F58(void *, s32, void *);
extern u8 *func_00382348(void *);
extern s32 func_0038CAD0(void *);
extern u8 *func_L01_004501E8_0038B280(void *, void *, f32, f32, f32, f32, void *, s32, s32, s32, f32, s32, void *, s32, s32, s32);
extern void func_L01_004C7438_0038B280(void *out, void *in, void *target, s32 b, f32 c, f32 d, f32 e, f32 f);
extern s32 func_L01_004C7A18_0038B280(f32 h, void *a, void *b, void *c, void *d, void *e, s32 f, s32 g);
extern void func_L01_00444F38_0038B280(u8 *, s32, s32, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004EAA80_0038B280(void);
extern s32 func_L01_005118D0_0038B280(s32, s32);
extern void func_L01_004EA7D8_0038B280(s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_003F2058_0038B280(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00390240_0038B280(void *, void *, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_005119E0_0038B280(s32);
extern void func_L01_003F2278_0038B280(s32, void *);
extern void func_0038D000(void *, void *, void *);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8_0038B280(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_00382468(s32);
extern void func_L01_004C7D98_0038B280(void *, void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_0013D3E0(void);
extern void func_L01_00466F50_0038B280(void *, void *, s32, f32, f32);
extern s32 func_L01_0040E050_0038B280(void *);
extern void func_L01_00404A10_0038B280(void *, void *);
extern void func_L01_0038B950_0038B280(u8 *);

/* infector_v5_update: the Infector's V5 update: entry 0 to fire, 1 for no ammo */
void func_L01_0038B280(Inf_38B280_0038B280 *inf)
{
    InfVars_38B280_0038B280 *vars = inf->vars;
    u8 *target = 0;
    vu0_v4 from;
    union { Skip_38B280_0038B280 skip; vu0_v4 pos; } u;
    vu0_v4 spot;
    vu0_v4 up;
    vu0_v4 at;
    s32 can_fire;
    s32 life;
    u8 *p;

    func_003C2F58(inf, 0, &from);
    if (D_001A4BE0.lockon_target != 0 && D_001A4BE0.lockon_target[0x20] != 0xFE &&
        D_001A4BE0.lockon_target[0x20] != 0xFD) {
        f32 *health = (f32 *)func_00382348(D_001A4BE0.lockon_target);
        if (health != 0 && 0.0f < *health)
            target = D_001A4BE0.lockon_target;
    }
    can_fire = 1;
    if (D_001A4BE0.state == 0x1D || D_001A4BE0.state == 1) {
        if (func_0038CAD0(&D_001A4BE0.aiming_fire_wait) == 0)
            can_fire = 0;
    } else {
        D_001A4BE0.aiming_fire_wait = 0x21;
        if (target == 0) {
            u.skip = D_L01_001DDF10_0038B280;
            target = func_L01_004501E8_0038B280(&from, &D_001A4BE0.aim, 0.39269909262657166f, 0.7853981852531433f,
                                       11.100000381469727f, 0.0f, &at, 0, 0, 0, 0.0f, 0, &u.skip, 1, -1, 0);
        }
    }
    if (D_L01_001D673C_0038B280 != 0) {
        D_L01_001DDEF0_0038B280 = 7.800000190734863f;
        D_L01_001DDEF4_0038B280 = 9.999999747378752e-06f;
        D_L01_001DDEF8_0038B280 = 12.0f;
        D_L01_001DDEFC_0038B280 = 10.0f;
    } else {
        D_L01_001DDEF0_0038B280 = 12.0f;
        D_L01_001DDEF4_0038B280 = 9.999999747378752e-06f;
        D_L01_001DDEF8_0038B280 = 12.0f;
        D_L01_001DDEFC_0038B280 = 15.0f;
    }
    func_L01_004C7438_0038B280(&u.pos, &from, target, 0, D_L01_001DDEF4_0038B280, D_L01_001DDEF0_0038B280,
                      D_L01_001DDEFC_0038B280 * 0.020000001415610313f, D_L01_001DDEF8_0038B280 * 0.0004000000189989805f);
    vars->w24 = func_L01_004C7A18_0038B280(D_L01_001DDEF8_0038B280 * 0.0004000000189989805f, &from, &u.pos, vars, vars->landing,
                                  inf, 0, 0);
    if (inf->b42 == inf->b43 && (inf->b60 & 2))
        func_L01_00444F38_0038B280((u8 *)inf, 1, 0, 2, 0);
    if (D_001A4BE0.h2874 != 0)
        func_0038CE20(&u.pos, inf->forward, -0.2900000214576721f);
    switch (inf->phase) {
    case 0:
        inf->phase = 1;
        vars->rumble = -1;
        vars->timer = 0.0f;
    case 1:
        if (D_001A4BE0.i1D8 >= 0x12)
            func_L01_004EAA80_0038B280();
        if (vars->timer == 0.0f && D_001A4BE0.no_firing == 0 &&
            (*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0.fire_button) && can_fire &&
            D_001A4BE0.i1220 >= 0x13) {
            if (func_L01_005118D0_0038B280(-1, 1)) {
                D_L01_001E1F14_0038B280 = 1;
                func_L01_004EA7D8_0038B280(-1);
                func_003C3A10(inf, 2, 0, 0);
                vars->rumble = func_L01_003F2058_0038B280(D_L01_002B3CE0_0038B280, 0);
                if (func_0038CEA8(&u.pos) > 0.6000000238418579f)
                    func_0038CF68(&u.pos, &u.pos, 0.4400000274181366f);
                func_L01_00390240_0038B280(inf, &from, &u.pos);
                func_003A52A0(0, 0, inf);
                vars->timer = 1.0f / (D_L01_002C5600_0038B280 + D_001425F7[0])->rate;
            } else if ((*(s32 *)(D_001D52FC + 0x1A4) & D_001A4BE0.fire_button) || D_L01_001E1F14_0038B280 == 1) {
                func_003A52A0(1, 0, inf);
                D_L01_001E1F14_0038B280 = 0;
            }
            if (!((*(s32 *)(D_001D52FC + 0x1A0) & D_001A4BE0.fire_button) && func_L01_005119E0_0038B280(-1) &&
                  D_001A4BE0.b25E9 != 0) && vars->rumble >= 0) {
                func_L01_003F2278_0038B280(vars->rumble, 0);
                vars->rumble = -1;
            }
            inf->phase = 1;
        }
        break;
    }
    if (D_001A4BE0.no_firing == 0) {
        func_0038D000(&spot, D_L01_001DDF00_0038B280, inf->matrix);
        vec_add_ab(&spot, &spot, &inf->pos);
        life = (func_00382498(10, 20) * 5 + 2) / 6;
        p = func_L01_004713C8_0038B280(&spot, D_L01_001D66B0_0038B280, life, 0x5A182, func_00382498(1, 4), 0x30, 0, 0,
                              52500.0f, 157500.0f, 0.00020000000949949026f);
        if (p != 0) {
            p[3] = func_00382468(2) ? 0x48 : 0x44;
            p[2] = D_L01_0022123C_0038B280[0][0];
        }
        func_L01_004C7D98_0038B280(&D_001A4BE0.pos, &up);
        func_0038CF68(&up, &up, func_003824E0(0.004999999888241291f, 0.014999999664723873f));
        spot.x += func_003824E0(-0.07500000298023224f, 0.07500000298023224f);
        spot.y += func_003824E0(-0.07500000298023224f, 0.07500000298023224f);
        spot.z += func_003824E0(-0.07500000298023224f, 0.07500000298023224f);
        if (func_0013D3E0() % 12 == 0)
            func_L01_00466F50_0038B280(&spot, &up, 0x4005A182, -1.0f, 0.0f);
    }
    func_L01_0040E050_0038B280(&vars->timer);
    func_L01_00404A10_0038B280(func_L01_0038B950_0038B280, inf);
}
/* localdecomp:end func_L01_0038B280 */

/* localdecomp:start func_L01_0038B950 */
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, float);
void func_L01_0038B950(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (*(s32 *)(p + 36) != 0) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_0038B950 */

/* localdecomp:start func_L01_0038B988 */
extern void func_L01_0036E578_0038B988();
 
void func_L01_0038B988(void) {
    func_L01_0036E578_0038B988();
}
/* localdecomp:end func_L01_0038B988 */
