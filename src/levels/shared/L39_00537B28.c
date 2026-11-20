#include "common.h"

/* declared by functions of L39_00537998.c, which this file was cut from */
extern f32 func_L39_005B4410(f32, f32);
extern s32 D_L39_0024112C;

/* localdecomp:start func_L39_00537B28 */
#include "vu0.h"

typedef struct V_00537B28 V_00537B28;

typedef struct M_00537B28 {
    u8 pad0[0x10];
    vu0_v4 pos;              /* 0x10 */
    u8 b20;                  /* 0x20 */
    u8 pad21[3];
    u8 *cls;                 /* 0x24 */
    u8 pad28[4];
    u8 v2C[8];               /* 0x2C */
    u16 h34;                 /* 0x34 */
    u8 pad36[0xD];
    u8 b43;                  /* 0x43 */
    u8 pad44[0x24];
    V_00537B28 *vars;        /* 0x68 */
    u8 pad6C[0x2C];
    s32 i98;                 /* 0x98 */
    s32 i9C;                 /* 0x9C */
    u8 padA0[0xA];
    s16 hAA;                 /* 0xAA */
    u8 padAC[0xC];
    s32 iB8;                 /* 0xB8 */
    u8 bBC;                  /* 0xBC */
    u8 padBD[0x33];
    f32 fF0;                 /* 0xF0 */
    f32 fF4;                 /* 0xF4 */
    f32 fF8;                 /* 0xF8 */
} M_00537B28;

struct V_00537B28 {
    vu0_v4 vel;              /* 0x00 */
    u8 pad10[0x24];
    s16 h34;                 /* 0x34 */
    u8 pad36[0xA];
    f32 f40;                 /* 0x40 */
    u8 pad44[4];
    s32 i48;                 /* 0x48 */
    M_00537B28 *p4C;         /* 0x4C */
    u8 b50;                  /* 0x50 */
    u8 b51;                  /* 0x51 */
    s16 h52;                 /* 0x52 */
    M_00537B28 *p54;         /* 0x54 */
    s32 i58;                 /* 0x58 */
    u8 pad5C[4];
    u8 v60[4];               /* 0x60 */
    u8 v64[4];               /* 0x64 */
    s32 i68;                 /* 0x68 */
    f32 f6C;                 /* 0x6C */
    f32 f70;                 /* 0x70 */
    s32 i74;                 /* 0x74 */
    u8 pad78[4];
    u16 h7C;                 /* 0x7C */
};

typedef struct {
    vu0_v4 v0;
    M_00537B28 *p10;
    s32 i14;
    u8 b18;
    u8 b19;
    u16 h1A;
    f32 f1C;
    s32 i20;
    s32 i24;
    s32 i28;
    s32 i2C;
} __attribute__((aligned(16))) A_00537B28;

typedef struct {
    u8 pad0[0x18];
    M_00537B28 *p18;         /* 0x18 */
    s32 i1C;                 /* 0x1C */
    vu0_v4 v20;              /* 0x20 */
    vu0_v4 v30;              /* 0x30 */
    vu0_v4 v40;              /* 0x40 */
} G_00537B28;

typedef struct {
    u8 pad0[0x21];
    s8 b21;
    u8 pad22[0xE];
    f32 f30;
    u8 pad34[0x4C];
} R_00537B28;

typedef struct {
    u8 pad0[0x20];
    f32 f20;
    u8 pad24[4];
    s32 i28;
    s32 i2C;
    u8 pad30[0x430];
} E_00537B28;

typedef union {
    u8 b[8];
    u32 w[2];
} B_00537B28;

extern u8 *D_L39_0024CE20[8] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024CE20, 32");
extern f32 D_L39_0024AECC;
extern f32 D_L39_0024AD94;
__asm__(".extern D_L39_0024AD94, 4");
extern f32 D_L39_0024AD98;
__asm__(".extern D_L39_0024AD98, 4");
extern f32 D_L39_0024AD9C;
__asm__(".extern D_L39_0024AD9C, 4");
extern s16 D_L39_0024ADA0;
__asm__(".extern D_L39_0024ADA0, 2");
extern s16 D_L39_0024ADA4;
__asm__(".extern D_L39_0024ADA4, 2");
extern s32 D_L39_0024CAF0;
__asm__(".extern D_L39_0024CAF0, 4");
extern s32 D_L39_0024CAF8;
extern R_00537B28 D_L39_0049C890[];
extern G_00537B28 D_L39_0025F740;
extern u8 D_001FE020[];
extern u8 D_L39_004997E0[];
extern void *D_L39_002637C0[];
extern E_00537B28 D_L39_0024DE80[];
extern s16 D_L39_00293F38[][64];
extern u8 *D_L39_00296818[];

extern void func_L39_00539398(M_00537B28 *);
/* func_L39_00539268 is defined later in this file with struct types of its own: a per-function alias */
extern s32 func_L39_00539268_00537B28(s32, M_00537B28 *, void *);
extern s32 func_L39_00648AE0(u8 *, s32);
extern void func_0038CFB8(void *, void *, f32);
extern s32 func_003D3CB0(f32 *, u8 *, s32, u8 *, s32);
extern void func_L01_00446978(void *, void *);
extern void func_L01_0040E790(f32 *, f32 *, f32 *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D5630(void);
extern void func_L01_004C67A0(s32, s32, s32, f32, f32, f32, f32);
extern u8 *func_L01_003016B0(void *, s32, f32, f32);
extern f32 func_L39_005B44C8(void);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L39_005B43C8(s32, s32);
extern s32 func_L39_005B4398(s32);
extern void func_L01_00468A68(void *, void *, s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern u8 *func_003C4D58(M_00537B28 *);
extern void func_0038CE20(f32 *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L39_00537908(f32, f32, f32);
extern void func_003C4138(void *, f32, f32);
extern void func_L01_0044C638(void *, void *, void *, void *, void *, void *);
extern void func_L39_005F3088(s32);
extern s32 func_L39_0061D7B0(void *);
extern s32 func_L39_005F2FA0(void *, s32);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern s32 func_0038CAD0(void *);
extern u8 *func_L39_0061BF38(s32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L01_0044EBA0(void *, void *, void *, f32, f32, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_00447718(void *, void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L39_005CA8B0(void *, void *, f32, f32, s32);
extern void func_L39_005CE670(void *, void *, s32, f32, f32, f32, s32, s32, s32);
extern s32 func_L01_00480A78(s32, s32, f32);
extern s32 func_L01_00448D88(s32, s32);
extern void func_L39_005C7B40(void *, void *, s32, s32, f32, s32, s32, s32, s32, s32);
extern void func_L32_003B8498(void *, f32, f32, f32, s32, f32, u8, u8, s16, s16, s32);
extern void func_L01_0044BEC8(void *, s16 *);
extern void func_003C2880(void *);
extern void func_L01_004471A8(void *, f32);

static __inline__ u32 decode_00537B28(u8 *p, B_00537B28 *buf) {
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*p == 0) {
        return 0;
    }
    n = *p;
    k = ((u32)p - n) & 7;
    m = n + 1;
    d = buf->b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf->w[0] ^= (u32)p;
    buf->w[1] ^= buf->w[0];
    return buf->w[1];
}

static __inline__ void face_00537B28(M_00537B28 *moby, vu0_v4 *d, vu0_v4 *e, vu0_v4 *dir, f32 rate) {
    f32 s;
    f32 c;

    *(vu0_q *)d = *(vu0_q *)dir;
    s = func_0038D098(moby->fF8);
    c = func_0038D0B0(moby->fF8);
    e->x = d->x * s + d->y * c;
    s = func_0038D098(moby->fF8);
    c = func_0038D0B0(moby->fF8);
    e->y = d->y * s - d->x * c;
    e->z = d->z;
    moby->fF0 = func_L39_00537908(moby->fF0, -func_0038D160(sqrt_asm(e->x * e->x + e->z * e->z), e->y), rate);
    moby->fF4 = func_L39_00537908(moby->fF4, func_0038D160(e->z, e->x), rate);
}

static __inline__ void detach_00537B28(M_00537B28 *moby, V_00537B28 *vars) {
    moby->b20 = 1;
    if (vars->i68 != -1) {
        u8 *e = D_001FE020 + vars->i68 * 128;
        if (*(M_00537B28 **)(e + 0xDC) == moby && e[0xD0] != 0) {
            func_L39_005F3088(vars->i68);
        }
    }
    vars->i68 = -1;
    vars->h34 = 100;
    vars->vel.z = 0.0f;
}

static __inline__ R_00537B28 *row_00537B28(u8 *player, s32 mode) {
    R_00537B28 *e;

    if (func_L39_00648AE0(player, mode)) {
        e = &D_L39_0049C890[((R_00537B28 *)((u8 *)D_L39_0049C890 + (mode << 7)))->b21];
    } else {
        e = (R_00537B28 *)((u8 *)D_L39_0049C890 + (mode << 7));
    }
    return e;
}

void func_L39_00537B28(M_00537B28 *moby) {
    V_00537B28 *vars;

    vars = moby->vars;
    if (vars->b51 == 0) {
        func_L39_00539398(moby);
        return;
    }
    {
    u8 *player;
    u8 *grab;
    vu0_v4 v10 = { 0.0f, 0.0f, 0.040000003f, 0.0f };
    vu0_v4 saved;
    vu0_v4 v30 = { 0.0f, 0.0f, 1.0f, 0.0f };
    A_00537B28 args;
    vu0_v4 t70;
    vu0_v4 t80;
    vu0_v4 t90;
    vu0_v4 tA0;
    A_00537B28 hb;
    f32 dist;
    f32 rate;

    grab = 0;
    if (vars->h7C >= 8) {
        func_003C2880(moby);
        return;
    }
    player = D_L39_0024CE20[(s16)vars->h7C];
    moby->h34 &= ~0x100;
    saved = moby->pos;
    if (!(moby->b20 & 4) && vars->b51 != 0) {
        vec_add_ab(&moby->pos, &moby->pos, &vars->vel);
        vars->vel.z -= D_L39_0024AECC;
    }
    args.p10 = moby;
    args.i14 = 0x1030001;
    if (vars->b51 != 0) {
        args.f1C = D_L39_0024AD94;
    } else {
        args.f1C = row_00537B28(player, 6)->f30;
    }
    args.i20 = 1;
    *(vu0_q *)&args.v0 = *(vu0_q *)&vars->vel;
    func_0038CFB8(&args, &args, 1.0f);
    args.v0.w = 5627.9248f;
    args.b18 = 2;
    args.b19 = 3;
    args.h1A = *(u16 *)&moby->hAA;
    args.v0.z = 1.0f;
    if (vars->b51 != 0) {
        args.i28 = vars->i74;
    }

    if (!(moby->b20 & 4) && func_003D3CB0((f32 *)&saved, (u8 *)&moby->pos, 0x10, (u8 *)moby, 0)) {
        if (moby->iB8 == (s32)D_L39_0025F740.p18 && vars->b51 != 0) {
            return;
        }
        if (func_L39_00539268_00537B28(*(s32 *)(player + 0x2548), D_L39_0025F740.p18, 0)) {
            func_L01_00446978(D_L39_0025F740.p18, &args);
        }
        if (vars->b51 != 0) {
            moby->bBC = 1;
            *(vu0_q *)&moby->pos = *(vu0_q *)&D_L39_0025F740.v20;
            func_L01_0040E790((f32 *)&v10, (f32 *)vars, (f32 *)&D_L39_0025F740.v40);
            func_0038CF68(&v10, &v10, 0.040000003f);
            func_0038CF68(&v30, &D_L39_0025F740.v40, 1.0f);
        }
        if (vars->b50 == 0 && func_003D5630() == 0 && vars->vel.z < 0.0f) {
            u8 *fx;
            s32 i;
            s32 n;

            func_L01_004C67A0(D_L39_0024CAF0, D_L39_0024CAF8, 1, moby->pos.x, moby->pos.y, 0.5f, -0.35f);
            qzero(&vars->vel);
            vars->b50 = 1;
            vars->vel.z = -0.030000001f;
            t70.x = moby->pos.x;
            t70.y = moby->pos.y;
            t70.z = D_L39_0025F740.v20.z;
            fx = func_L01_003016B0(&t70, 3, 2.0f, 1.025f);
            if (fx != 0) {
                fx[0x23] = 0x70;
            }
            for (i = 0; i < 16; i++) {
                f32 ang = func_L39_005B44C8();
                f32 r = func_L39_005B4410(0.0f, 0.060000002f);
                t80.x = func_0038D098(ang) * r;
                t80.y = func_0038D0B0(ang) * r;
                t80.z = func_L39_005B4410(0.060000002f, 0.13000001f);
                n = func_L39_005B43C8(0x5A, 0x78);
                func_L01_00468A68(&t70, &t80, func_L39_005B4398(2), n);
            }
        } else if (vars->b50 != 0 || func_003D5630() != 0) {
            if (D_L39_0025F740.p18 != 0
                && func_L39_00539268_00537B28(*(s32 *)(player + 0x2548), D_L39_0025F740.p18, 0)
                && D_L39_0025F740.p18->hAA != moby->hAA
                && player != 0
                && D_L39_0025F740.p18 != *(M_00537B28 **)(player + 0x2524)
                && D_L39_0025F740.p18 != (M_00537B28 *)moby->iB8) {
                moby->bBC = 1;
                if (moby->b20 != 1) {
                    *(vu0_q *)&moby->pos = *(vu0_q *)&D_L39_0025F740.v20;
                    moby->pos.z = func_003C3D30(&moby->pos, 0, 0, 0.5f);
                }
            } else if (D_L39_0025F740.p18 != 0 && D_L39_0025F740.p18->hAA == moby->hAA) {
                vec_sub_ba(&D_L39_0025F740.v40, &moby->pos, &D_L39_0025F740.p18->pos);
                if (vars->vel.z < -0.19600002f) {
                    moby->bBC = 1;
                    *(vu0_q *)&moby->pos = *(vu0_q *)&D_L39_0025F740.v20;
                    func_L01_0040E790((f32 *)&v10, (f32 *)vars, (f32 *)&D_L39_0025F740.v40);
                    func_0038CF68(&v10, &v10, 0.040000003f);
                    func_0038CF68(&v30, &D_L39_0025F740.v40, 1.0f);
                } else {
                    *(vu0_q *)&moby->pos = *(vu0_q *)&D_L39_0025F740.v20;
                    func_0038CF68(&t70, &D_L39_0025F740.v40, 0.0038800002f);
                    rate = 0.05235988f;
                    vec_add_ba(&moby->pos, &moby->pos, &t70);
                    func_L01_0040E790((f32 *)vars, (f32 *)vars, (f32 *)&D_L39_0025F740.v40);
                    func_0038CE20((f32 *)vars, vars, 0.4f);
                    func_0038CF68(&t70, &D_L39_0025F740.v40, 1.0f);
                    func_0038CE68(&t70, &v30);
                    face_00537B28(moby, &t80, &t90, &D_L39_0025F740.v40, rate);
                }
            } else if ((D_L39_0025F740.p18 != 0 && player != 0
                        && D_L39_0025F740.p18 != *(M_00537B28 **)(player + 0x2524)
                        && D_L39_0025F740.p18 != (M_00537B28 *)moby->iB8)
                       || D_L39_0025F740.i1C > 0) {
                if (vars->b50 != 0 || func_003D5630() == 0 || vars->vel.z < -0.19600002f) {
                    moby->bBC = 1;
                    *(vu0_q *)&moby->pos = *(vu0_q *)&D_L39_0025F740.v20;
                    func_L01_0040E790((f32 *)&v10, (f32 *)vars, (f32 *)&D_L39_0025F740.v40);
                    func_0038CF68(&v10, &v10, 0.040000003f);
                    func_0038CF68(&v30, &D_L39_0025F740.v40, 1.0f);
                } else {
                    if (D_L39_0025F740.p18 != 0) {
                        grab = func_003C4D58(D_L39_0025F740.p18);
                    }
                    *(vu0_q *)&moby->pos = *(vu0_q *)&D_L39_0025F740.v20;
                    func_0038CF68(&t70, &D_L39_0025F740.v40, 0.0038800002f);
                    vec_add_ba(&moby->pos, &moby->pos, &t70);
                    *(vu0_q *)&tA0 = *(vu0_q *)&vars->vel;
                    func_L01_0040E790((f32 *)vars, (f32 *)vars, (f32 *)&D_L39_0025F740.v40);
                    func_0038CE20((f32 *)vars, vars, 0.6f);
                    vars->vel.z *= 0.5f;
                    if (vars->f6C == 0.0f) {
                        f32 a;
                        vars->f6C = fabs_asm(tA0.z) * 2.0f;
                        a = -2.3561945f;
                        if (0.0f < tA0.z) {
                            a = 0.7853982f;
                        }
                        vars->f70 = a;
                        vars->i74 = D_L39_0024112C;
                    }
                    func_0038CF68(&t70, &D_L39_0025F740.v40, 1.0f);
                    if (func_0038CE68(&t70, &v30) > 0.707f && tA0.z < 0.0f) {
                        f32 h = func_003C3D30(&moby->pos, 0, 0, 0.5f);
                        if (moby->pos.z < h) {
                            moby->pos.z = h;
                        }
                        vars->vel.z = -vars->vel.z;
                        if (func_0038CEA8(vars) < 0.010000001f || grab != 0) {
                            qzero(&vars->vel);
                            moby->b20 |= 4;
                            if (moby->b43 != 2) {
                                func_003C3A10(moby, 2, 0, 10);
                            }
                            moby->i98 = *(s32 *)(moby->cls + 0x10);
                            moby->i9C = 0;
                            if (D_L39_0025F740.p18 != 0 && grab != 0) {
                                vars->p4C = D_L39_0025F740.p18;
                            }
                        }
                    }
                    rate = 0.05235988f;
                    face_00537B28(moby, &t80, &t90, &D_L39_0025F740.v40, rate);
                }
            }
        }
    } else if (moby->b20 & 4) {
        f32 h;
        s32 flag;

        func_003C4138(moby->v2C, *(f32 *)(moby->cls + 0x24) * 1.25f, *(f32 *)(moby->cls + 0x24) * 0.05f);
        h = func_003C3D30(&moby->pos, 0, 0, 0.5f);
        if (vars->p4C != 0) {
            M_00537B28 *o = vars->p4C;
            if (o->b20 == 0xFE || vars->p4C->b20 == 0xFD) {
                moby->bBC = 1;
                vars->p4C = 0;
            } else if (D_L39_0025F740.p18 != 0) {
                grab = func_003C4D58(D_L39_0025F740.p18);
                if (grab != 0) {
                    func_L01_0044C638(moby, vars->p4C, &moby->pos, &moby->fF0, &moby->pos, &moby->fF0);
                }
            }
            if (grab == 0) {
                detach_00537B28(moby, vars);
                vars->p4C = 0;
            }
        } else if (!(moby->b20 & 0x10)) {
            if (moby->pos.z - h < 0.016f) {
                moby->pos.z = h;
                vars->h34 = 0;
                if (D_L39_0025F740.p18 != 0 && func_003C4D58(D_L39_0025F740.p18) != 0) {
                    vars->p4C = D_L39_0025F740.p18;
                }
            } else {
                detach_00537B28(moby, vars);
            }
        }

        flag = 0;
        if (vars->p54 != 0) {
            u8 *r = (u8 *)func_L39_0061D7B0(vars->p54);
            u8 *q = 0;
            if (r != 0 && (r[3] & 0xF) == 0) {
                q = r;
            }
            if (q != 0) {
                if ((decode_00537B28(q + 0x19E6, (B_00537B28 *)&t70) ^ 0x14) == 0
                    || (decode_00537B28(q + 0x19E4, (B_00537B28 *)&t70) ^ 0x7A) == 0) {
                    flag = 1;
                }
            }
        }
        if (vars->p54 == 0 || vars->p54->b20 == 0xFE || vars->p54->b20 == 0xFD || flag != 0
            || !(vars->p54->h34 & 0x1000)) {
            if (moby->b20 & 0x10) {
                detach_00537B28(moby, vars);
                vars->p54 = 0;
            }
        }
        if (vars->p54 != 0 && (moby->b20 & 0x10)) {
            R_00537B28 *row;

            *(vu0_q *)&t80 = *(vu0_q *)&moby->pos;
            if (func_L39_005F2FA0(moby, vars->i68) == 0) {
                vars->i68 = func_L39_005F33E0(1, 4, moby);
            }
            vars->f40 += 0.0032000002f;
            if (vars->f40 > 0.16000001f) {
                vars->f40 = 0.16000001f;
            }
            if (vars->h52 == 1) {
                moby->pos.z += 0.060000002f;
                if (func_0038CAD0(&vars->i48)) {
                    vars->i48 = 6;
                    vars->h52 = 2;
                }
            } else if (vars->h52 == 2) {
                moby->pos.z -= 0.060000002f;
                if (func_0038CAD0(&vars->i48)) {
                    vars->h52 = 0;
                }
            }
            vec_sub_ba(&t70, &vars->p54->pos, &moby->pos);
            func_0038CF68(&t70, &t70, vars->f40);
            vec_add_ab(&moby->pos, &moby->pos, &t70);
            if (player != 0 ? func_L39_00648AE0(player, 6) : func_L39_00648AE0(func_L39_0061BF38(0), 6)) {
                row = D_L39_0049C890 + D_L39_0049C890[6].b21;
            } else {
                row = D_L39_0049C890;
                row += 6;
            }
            func_L01_00446760(&hb, moby, 0x30001, &t70, row->f30);
            if (vars->b51 != 0) {
                hb.b19 = 3;
            }
            *(vu0_q *)&t90 = *(vu0_q *)&moby->pos;
            t90.z += 0.35f;
            if (func_003D4D00(&t90, 0x10, moby, &hb, 0.35f) && D_L39_0025F740.p18 != 0
                && (D_L39_0025F740.p18->h34 & 0x1000)
                && D_L39_0025F740.p18->hAA != 0x363 && D_L39_0025F740.p18->hAA != 0x1099
                && D_L39_0025F740.p18->hAA != 0x458 && D_L39_0025F740.p18->hAA != 0x365
                && D_L39_0025F740.p18->hAA != 0x367) {
                moby->bBC = 1;
            }
            *(vu0_q *)&t90 = *(vu0_q *)&moby->pos;
            t90.z += 0.25f;
            if (func_L01_003FB640(&t90, 0, moby, 0.25f)) {
                vec_sub_ba(&tA0, &D_L39_0025F740.v30, &t90);
                vec_add_ba(&moby->pos, &moby->pos, &tA0);
            }
            if (func_0038CAD0(&vars->i58)) {
                moby->bBC = 1;
            }
        }
        func_L01_0044EBA0(moby, vars->v60, vars->v64, 0.5235988f, 0.010471976f, 0.0059341197f);
        if (moby->b20 & 4) {
            vec_sub_ba(&t80, &moby->pos, &saved);
            *(vu0_q *)&t70 = *(vu0_q *)&t80;
            *(vu0_q *)&vars->vel = *(vu0_q *)&t70;
        }
    }
    if (moby->bBC != 0 && player != 0) {
        dist = func_0038CF38(&moby->pos, player + 0x23A0);
        if (vars->b50 == 0) {
            s32 r;
            R_00537B28 *row;
            f32 f;

            r = func_003D4D00(&moby->pos, 0x10, moby, 0, vars->b51 != 0 ? D_L39_0024AD98 : 2.0f);
            row = row_00537B28(player, 6);
            f = row->f30;
            *(vu0_q *)&t70 = *(vu0_q *)&moby->pos;
            func_L01_00447718(moby, &t70, D_L39_002637C0, r, vars->b51 != 0 ? moby->iB8 : 0, 0x1010001, 4, 3, -1,
                              vars->b51 != 0 ? D_L39_0024AD94 : f, 0.25f, 1.5f);
        }
        if (vars->b50 != 0) {
            f32 gz;
            s32 i;
            s32 j;
            s32 k;
            s32 r;
            s32 g;
            s32 b;

            *(vu0_q *)&t70 = *(vu0_q *)&moby->pos;
            t70.z += 3.5f;
            gz = func_003C3D30(&t70, 0, 0, 0.5f);
            for (i = 0; i < 150; i++) {
                *(vu0_q *)&t90 = 0;
                t90.x = func_L39_005B4410(-1.0f, 1.0f);
                t90.y = func_L39_005B4410(-1.0f, 1.0f);
                t90.z = func_L39_005B4410(-0.5f, -2.0f);
                *(vu0_q *)&t80 = *(vu0_q *)&t90;
                func_0038CF68(&t80, &t80, func_L39_005B4410(0.080000006f, 0.16000001f));
                func_L39_005CA8B0(&moby->pos, &t80, func_L39_005B4410(0.05f, 0.1f) * 210000.0f, gz, 0x88A0A0A0);
            }
            r = 0x60;
            g = 0x60;
            b = 0x7F;
            for (j = 0; j < 150; j++) {
                f32 rr;
                f32 ang;
                *(vu0_q *)&t90 = 0;
                t90.x = func_L39_005B4410(-0.015000001f, 0.015000001f);
                t90.y = func_L39_005B4410(-0.015000001f, 0.015000001f);
                t90.z = func_L39_005B4410(0.080000006f, 0.32000002f);
                *(vu0_q *)&t80 = *(vu0_q *)&t90;
                rr = func_L39_005B4410(0.0f, 0.35f);
                ang = func_L39_005B44C8();
                t90.x = func_0038D098(ang) * rr;
                t90.y = func_0038D0B0(ang) * rr;
                t90.z = 0.0f;
                vec_add_ba(&t90, &t90, &moby->pos);
                t90.z = gz + 0.5f;
                t80.z -= rr * 0.020000001f * 8.0f;
                func_L39_005CE670(&t90, &t80, 0, func_L39_005B4410(0.35f, 1.25f), gz, 0.008f, ((0x16 << 24) | (b << 16) | (g << 8) | r), ((b << 16) | (g << 8) | r), 1);
            }
            for (k = 0; k < 20; k++) {
                s32 ca;
                s32 cb;
                f32 life;
                s32 n;
                ca = func_L01_00480A78(0x7F000000, ((0x7F << 24) | (b << 16) | (g << 8) | r), func_L39_005B4410(0.25f, 1.0f));
                cb = func_L01_00480A78(0, (((b / 2) << 16) | ((g / 2) << 8) | (r / 2)), func_L39_005B4410(0.5f, 1.0f));
                t90.x = func_L39_005B4410(-3.0f, 3.0f);
                t90.y = func_L39_005B4410(-3.0f, 3.0f);
                t90.z = func_L39_005B4410(0.080000006f, 0.28000003f);
                func_0038CF68(&t90, &t90, func_L39_005B4410(1.5f, 3.0f) * 0.020000001f);
                t90.z = func_L39_005B4410(3.0f, 6.0f) * 0.020000001f;
                *(vu0_q *)&t80 = *(vu0_q *)&moby->pos;
                t80.z = gz;
                ca = func_L01_00448D88(ca, 0);
                cb = func_L01_00448D88(cb, 0);
                life = func_L39_005B4410(31500.002f, 52500.0f);
                n = func_L39_005B43C8(0x4B, 0x7D);
                func_L39_005C7B40(&t80, &t90, ca, cb, life, n, 1, *D_L39_00296818[11], -1, 0);
            }
        } else {
            func_L32_003B8498(&moby->pos, vars->b51 != 0 ? D_L39_0024AD9C : 1.0f, 2.0f, 1.0f, 0, 1.4f, 0x7F, 0x30,
                              D_L39_0024ADA0, D_L39_0024ADA4, 0);
        }
        moby->bBC = 0;
        func_L39_005F33E0(2, 0, moby);
        if (player != 0 && player[0x1A14] != 0) {
            E_00537B28 *e = &D_L39_0024DE80[player[0x24C9]];
            if (dist < 8.0f) {
                e->f20 = 0.55f - dist * 0.0225f;
            } else {
                e->f20 = 0.100000024f;
            }
            (D_L39_0024DE80 + player[0x24C9])->i28 = 0x36;
            (D_L39_0024DE80 + player[0x24C9])->i2C = 0;
        }
        func_L01_0044BEC8(moby, D_L39_00293F38[*(s32 *)(player + 0x2544)]);
        func_003C2880(moby);
    } else {
        func_L01_004471A8(moby, 0.25f);
    }
    }
}
/* localdecomp:end func_L39_00537B28 */
