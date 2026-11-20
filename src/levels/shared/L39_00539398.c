#include "common.h"

/* declared by functions of L39_00537998.c, which this file was cut from */
extern f32 func_L39_005B4410(f32, f32);
extern s32 D_L39_0024112C;
typedef struct {
    u8 pad0[0xAA];
    s16 hAA;
    u8 padAC[0xBE - 0xAC];
    u8 bBE;
} O_00539268;
extern s32 func_L39_0061D7B0(void *);

/* localdecomp:start func_L39_00539398 */
#include "vu0.h"

struct Vars_00539398;

typedef struct Cls_00539398 {
    u8 pad0[0x10];
    s32 i10;
    u8 pad14[0x10];
    f32 f24;
} Cls_00539398;

typedef struct Moby_00539398 {
    u8 pad0[0x10];
    vu0_v4 pos;                         /* 0x10 */
    u8 state;                           /* 0x20 */
    u8 pad21[3];
    Cls_00539398 *cls;                  /* 0x24 */
    u8 pad28[4];
    f32 f2C;                            /* 0x2C */
    u8 b30;                             /* 0x30 */
    u8 pad31[3];
    u16 flags;                          /* 0x34 */
    u8 pad36[0x43 - 0x36];
    u8 b43;                             /* 0x43 */
    u8 pad44[0x68 - 0x44];
    struct Vars_00539398 *vars;         /* 0x68 */
    u8 pad6C[0x98 - 0x6C];
    s32 i98;                            /* 0x98 */
    s32 i9C;                            /* 0x9C */
    u8 padA0[8];
    u8 bA8;                             /* 0xA8 */
    u8 padA9;
    s16 type;                           /* 0xAA */
    u8 padAC[0xB8 - 0xAC];
    struct Moby_00539398 *parent;       /* 0xB8 */
    u8 bBC;                             /* 0xBC */
    u8 padBD[0xF0 - 0xBD];
    f32 rot[3];                         /* 0xF0 */
} Moby_00539398;

typedef struct Vars_00539398 {
    vu0_v4 vel;                         /* 0x00 */
    u8 pad10[0x10];
    vu0_v4 dir;                         /* 0x20 */
    u8 pad30[4];
    s16 t34;                            /* 0x34 */
    s16 s36;                            /* 0x36 */
    u8 pad38[8];
    f32 f40;                            /* 0x40 */
    u8 pad44[4];
    s32 t48;                            /* 0x48 */
    Moby_00539398 *m4C;                 /* 0x4C */
    u8 b50;                             /* 0x50 */
    u8 b51;                             /* 0x51 */
    s16 s52;                            /* 0x52 */
    Moby_00539398 *m54;                 /* 0x54 */
    s32 t58;                            /* 0x58 */
    s32 i5C;                            /* 0x5C */
    f32 f60;                            /* 0x60 */
    f32 f64;                            /* 0x64 */
    s32 slot;                           /* 0x68 */
    f32 f6C;                            /* 0x6C */
    f32 f70;                            /* 0x70 */
    s32 i74;                            /* 0x74 */
    u8 pad78[4];
    u16 idx;                            /* 0x7C */
    s16 s7E;                            /* 0x7E */
} Vars_00539398;

typedef struct Player_00539398 {
    u8 pad0[0xE0];
    vu0_v4 vE0;                         /* 0xE0 */
    u8 padF0[0x450 - 0xF0];
    Moby_00539398 *m450;                /* 0x450 */
    u8 pad454[0x1310 - 0x454];
    s32 i1310;                          /* 0x1310 */
    u8 pad1314[0x1A08 - 0x1314];
    unsigned long l1A08;                          /* 0x1A08 */
    u8 pad1A10[4];
    u8 b1A14;                           /* 0x1A14 */
    u8 pad1A15[0x23A0 - 0x1A15];
    vu0_v4 v23A0;                       /* 0x23A0 */
    u8 pad23B0[0x2488 - 0x23B0];
    s16 s2488;                          /* 0x2488 */
    u8 pad248A[0x24C9 - 0x248A];
    u8 b24C9;                           /* 0x24C9 */
    u8 pad24CA[0x2524 - 0x24CA];
    Moby_00539398 *m2524;               /* 0x2524 */
    u8 pad2528[0x2544 - 0x2528];
    s32 i2544;                          /* 0x2544 */
    s32 i2548;                          /* 0x2548 */
} Player_00539398;

typedef struct Tgt_00539398 {
    u8 pad0[3];
    u8 b3;                              /* 0x03 */
    u8 pad4[0x2D8 - 4];
    struct Tgt_00539398 *p2D8;          /* 0x2D8 */
    u8 pad2DC[0x19E4 - 0x2DC];
    u8 b19E4;                           /* 0x19E4 */
    u8 pad19E5;
    u8 b19E6;                           /* 0x19E6 */
    u8 pad19E7[0x1A06 - 0x19E7];
    u8 b1A06;                           /* 0x1A06 */
    u8 pad1A07[0x1A14 - 0x1A07];
    u8 b1A14;                           /* 0x1A14 */
} Tgt_00539398;

typedef struct Coll_00539398 {
    u8 pad0[0x18];
    Moby_00539398 *hit;                 /* 0x18 */
    s32 count;                          /* 0x1C */
    vu0_v4 pos;                         /* 0x20 */
    vu0_v4 v30;                         /* 0x30 */
    vu0_v4 normal;                      /* 0x40 */
} Coll_00539398;

typedef struct Ent_00539398 {
    u8 pad0[0x21];
    s8 b21;                             /* 0x21 */
    u8 pad22[0x30 - 0x22];
    f32 f30;                            /* 0x30 */
    u8 pad34[0x80 - 0x34];
} Ent_00539398;

typedef struct Probe_00539398 {
    Moby_00539398 *owner;               /* 0x00 */
    s32 mask;                           /* 0x04 */
    u8 a;                               /* 0x08 */
    u8 b;                               /* 0x09 */
    u16 type;                           /* 0x0A */
    f32 f0C;                            /* 0x0C */
    s32 i10;                            /* 0x10 */
    s32 i14;                            /* 0x14 */
    s32 i18;                            /* 0x18 */
} Probe_00539398;

typedef struct Ev_00539398 {
    vu0_v4 pos;                         /* 0x00 */
    s32 a;                              /* 0x10 */
    u32 b;                              /* 0x14 */
    s32 c;                              /* 0x18 */
    u8 d;                               /* 0x1C */
} Ev_00539398;

typedef struct Out_00539398 {
    vu0_v4 v;                           /* 0x00 */
    u8 pad10[9];
    u8 b19;                             /* 0x19 */
    u8 pad1A[0x16];
} Out_00539398;

typedef struct Res_00539398 {
    u8 pad0[0x20];
    Moby_00539398 *m20;                 /* 0x20 */
} Res_00539398;

typedef union Buf_00539398 {
    u8 b[8];
    u32 w[2];
} Buf_00539398;

typedef struct Snd_00539398 {
    u8 pad0[4];
    s32 i4;                             /* 0x004 */
    u8 pad8[0x128 - 8];
    s32 i128;                           /* 0x128 */
    u8 pad12C[0x170 - 0x12C];
    s32 i170;                           /* 0x170 */
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;                            /* 0x7D4 */
} Snd_00539398;

extern Snd_00539398 D_001A5CD0;
extern u8 D_001FE020[];
extern u8 D_L39_004997E0[];
extern Ent_00539398 D_L39_0049C890[];
extern Coll_00539398 D_L39_0025F740;
extern Moby_00539398 *D_L39_00292C20[];
extern Moby_00539398 *D_L39_002637C0[];
typedef struct Hud_00539398 {
    u8 pad0[0x20];
    f32 f20;                            /* 0x20 */
    u8 pad24[4];
    s32 i28;                            /* 0x28 */
    s32 i2C;                            /* 0x2C */
    u8 pad30[0x460 - 0x30];
} Hud_00539398;

extern Hud_00539398 D_L39_0024DE80[];
extern s32 D_L39_002412DC;
__asm__(".extern D_L39_002412DC, 16");
extern s32 D_L39_002405AC;
__asm__(".extern D_L39_002405AC, 16");
extern s32 D_L39_0024CAF8;
__asm__(".extern D_L39_0024CAF8, 16");
extern s16 D_L39_00293F38[][64];
extern s32 D_L39_0024ADA8;
__asm__(".extern D_L39_0024ADA8, 4");
extern void *D_L39_0024CAF0;
__asm__(".extern D_L39_0024CAF0, 4");
extern s16 D_L39_0024ADA0;
__asm__(".extern D_L39_0024ADA0, 2");
extern s16 D_L39_0024ADA4;
__asm__(".extern D_L39_0024ADA4, 2");
extern u8 *D_L39_0024CE20[8] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024CE20, 32");

extern void func_003C2880(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern s32 func_003D3CB0(f32 *, u8 *, s32, u8 *, s32);
extern s32 func_003D4D00(void *, s32, f32, void *, void *);
extern s32 func_003D5630(void);
extern u8 *func_00382348(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_003C3EC8(void *, void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern u8 *func_003C4D58(u8 *);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);
extern s32 func_L39_0053B6B0(u8 *, u8 *, u8 *);
extern s32 func_L39_0053C110(void *, void *, void *);
extern void func_L39_0053C1E8(void *, void *, f32);
extern f32 func_L39_0053C248(void *, void *);
extern void func_L39_0053C2A0(void *);
extern void func_L39_0053C300(void *);
extern f32 func_L39_00537908(f32, f32, f32);
extern s32 func_L39_005FF0B8(void *, void *, void *, s32, f32);
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_005B43C8(s32, s32);
extern f32 func_L39_005B44C8(void);
extern void *func_L39_005CA8B0(void *, void *, u32, f32, f32);
extern s32 func_L39_00648AE0(u8 *, s32);
extern u8 *func_L39_0061BF38(s32);
extern s32 func_L39_005F2FA0(void *, s32);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_L39_005F3088(s32);
extern void func_L39_005B8978(void *, void *, void *, f32, f32, s32, s32, s32, f32, f32, f32, f32, s32, f32, s32, s32, s32, s32, s32);
extern u8 *func_L01_003016B0(void *, s32, f32, f32);
extern void func_L01_004C67A0(void *, s32, u32, f32, f32, f32, f32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern f32 func_L01_004463D0(void *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446978(void *, void *);
extern void func_L01_004471A8(void *, f32);
extern void *func_L01_00447490(void *, s32, s32);
extern void func_L01_0044BB30(void *, void *, s32, f32, f32);
extern void func_L01_0044BEC8(void *, void *);
extern s32 func_L01_0044C638(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *);
extern void func_L01_0044EBA0(void *, void *, void *, f32, f32, f32);
extern void *func_L01_00468A68(void *, void *, s32, s32);
extern void func_L01_00511158(void *, void *, void *, f32);
extern void func_L01_0040E790(void *, void *, void *);
extern void func_L32_003B8498(void *, f32, f32, f32, s32, u8, f32, s32, s32, s32, s32);

/* the weapon table row of id, or its upgraded row */
static __inline__ Ent_00539398 *ent_00539398(u8 *p, s32 id) {
    if (func_L39_00648AE0(p, id)) {
        return &D_L39_0049C890[D_L39_0049C890[id].b21];
    }
    return &D_L39_0049C890[id];
}


static __inline__ Tgt_00539398 *live_00539398(void *m) {
    Tgt_00539398 *t = (Tgt_00539398 *)func_L39_0061D7B0(m);
    Tgt_00539398 *r = 0;

    if (t != 0) {
        r = (t->b3 & 0xF) ? 0 : t;
    }
    return r;
}

static __inline__ Tgt_00539398 *tgt_00539398(void *m) {
    Tgt_00539398 *t = (Tgt_00539398 *)func_L39_0061D7B0(m);
    Tgt_00539398 *r = 0;

    if (t != 0 && !(t->b3 & 0xF)) {
        r = t;
    }
    return r;
}

static __inline__ u32 decode_00539398(u8 *p) {
    Buf_00539398 buf;
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
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)p;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

static __inline__ void release_00539398(Moby_00539398 *a0, Vars_00539398 *v) {
    s32 slot;

    a0->state = 1;
    slot = v->slot;
    if (slot != -1) {
        u8 *e = D_001FE020 + slot * 128;
        if (*(Moby_00539398 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
            func_L39_005F3088(slot);
        }
    }
    v->slot = -1;
    func_L39_0053C2A0(a0);
}


static __inline__ void up_00539398(vu0_v4 *d) {
    vu0_q q;
    __asm__("vmr32.xyzw %0, $vf0" : "=j"(q));
    __asm__("sqc2 %1, %0" : "=m"(*d) : "j"(q));
}


void func_L39_00539398(Moby_00539398 *a0) {
    vu0_v4 grav = { 0.0f, 0.0f, 0.040000003f, 0.0f };
    vu0_v4 from;
    vu0_v4 dir;
    vu0_v4 up;
    vu0_v4 fwd;
    Probe_00539398 probe;
    vu0_v4 side;
    vu0_v4 push;
    Vars_00539398 *v;
    Player_00539398 *pl;
    u8 *found;
    s32 hit;
    f32 f;
    f32 k;

    found = 0;
    v = a0->vars;
    if (v->idx >= 8) {
        func_003C2880(a0);
        return;
    }
    pl = (Player_00539398 *)D_L39_0024CE20[(s16)v->idx];
    func_0038CF68(&dir, &v->dir, 1.0f);
    if (pl != 0 && ((pl->l1A08 & 0xFFFF0000) != 0 || pl->i1310 == 2 || pl->s2488 != 0) && a0->state == 0) {
        a0->flags |= 0x41;
    } else {
        a0->flags &= ~0x41;
    }
    if (pl == 0 || !((pl->m450 != 0 && pl->m450->type == 0x1098) || a0->state != 0)) {
        func_003C2880(a0);
        return;
    }
    if (a0->parent != 0 && a0->parent->state != 0xFE && a0->parent->state != 0xFD &&
        a0->parent->type == 0x1098 && v->s36 == 0 && 0.0f < func_0038CEA8(v)) {
        func_L39_0053B6B0((u8 *)v, (u8 *)a0, (u8 *)a0->parent->vars);
    }
    if (a0->state == 0) {
        Moby_00539398 *p;

        if (pl->m450 == 0 || pl->m450->type != 0x1098) {
            func_003C2880(a0);
        return;
        }
        p = a0->parent;
        if (p == 0 || p->state == 0xFE || p->state == 0xFD) {
            return;
        }
        if (p->type == 0x1098) {
            a0->i98 = 0;
        }
        return;
    }

    a0->flags &= ~0x100;
    from = a0->pos;
    if (!(a0->state & 4)) {
        if (v->b50 == 0) {
            if (func_L39_005FF0B8(&v->dir, &a0->pos, v, v->s36 == -1, 0.00472f)) {
                v->s36 = -1;
            } else {
                v->s36 = 1;
            }
            vec_add_ab(&a0->pos, &v->vel, &a0->pos);
        } else {
            v->vel.z -= 0.00039200002f;
            if (func_L39_005B4398(4) == 0) {
                f = func_003C3EC8(&a0->pos, &up);
                func_0038CE20((f32 *)&up, v, 0.25f);
                func_L39_005CA8B0(&a0->pos, &up, 0x88A0A0A0, func_L39_005B4410(0.05f, 0.1f) * 210000.0f, f);
            }
        }
    }
    probe.owner = a0;
    probe.mask = 0x01030001;
    probe.f0C = ent_00539398((u8 *)pl, 6)->f30;
    probe.i10 = 1;
    fwd = v->vel;
    if (v->s36 == -1) {
        up = v->dir;
        func_0038CF68(&up, &up, 1.0f);
    } else {
        up_00539398(&up);
    }
    func_0038CF68(&fwd, &fwd, 1.0f);
    func_0038CE90(&side, &fwd, &up);
    func_0038CE90(&fwd, &side, &up);
    func_0038CF68(&fwd, &fwd, 1.0f);
    vec_add_ab(&fwd, &fwd, &up);
    fwd.w = 5627.925f;
    probe.a = 2;
    probe.b = 3;
    probe.type = a0->type;
    if ((a0->state & 4) || v->t34 < 0x5C) {
        if (v->s36 == -1) {
            push = v->dir;
        } else {
            up_00539398(&push);
        }
        func_0038CF68(&push, &push, 0.4f);
        f = (f32)(D_L39_0024112C - v->i74) / 5.3333335f;
        if (f > 1.0f) {
            f = 1.0f;
        } else if (f < 0.0f) {
            f = 0.0f;
        }
        {
            vu0_v4 t;

            {
                func_0038CF68(&t, &push, v->f6C * func_0038D0B0(v->f70) * f);
                vec_add_ba(&push, &push, &t);
            }
        }
        vec_sub_ab(&a0->pos, &a0->pos, &push);
    } else {
        qzero(&push);
    }

    if (!(a0->state & 4)) {
        hit = func_003D3CB0((f32 *)&from, (u8 *)&a0->pos, D_L39_0024ADA8 | 0x10, (u8 *)a0, 0);
        vec_add_ab(&a0->pos, &a0->pos, &push);
    }
    if (!(a0->state & 4)) {
        if (hit != 0) {
            vu0_v4 vel;
            s32 near;
            f32 vz;
            Moby_00539398 *h;

            near = func_L39_00539268(pl->i2548, (O_00539268 *)D_L39_0025F740.hit, 0) != 0;
            if (near) {
                func_L01_00446978(D_L39_0025F740.hit, &fwd);
            }
            vel = v->vel;
            if (func_003D5630() == 2) {
                vu0_v4 n;
{

                func_0038CF68(&n, &D_L39_0025F740.normal, 1.0f);
                vz = func_0038CE68(v, &n);
            }
} else {
                vz = vel.z;
            }
            if (v->b50 == 0 && (func_003D5630() == 0 || func_003D5630() == 0xD || func_003D5630() == 0xB) && vz < 0.0f) {
                vu0_v4 sp;
                vu0_v4 off;
                u8 *fx;
                s32 i;
                f32 ang;
                f32 r;
                s32 n;
{

                func_L01_004C67A0(D_L39_0024CAF0, D_L39_0024CAF8, 1, a0->pos.x, a0->pos.y, 0.5f, -0.35f);
                qzero(&v->vel);
                v->b50 = 1;
                v->vel.z = -0.030000001f;
                sp.x = a0->pos.x;
                sp.y = a0->pos.y;
                sp.z = D_L39_0025F740.pos.z;
                fx = func_L01_003016B0(&sp, 3, 2.0f, 1.025f);
                if (fx != 0) {
                    fx[0x23] = 0x70;
                }
                for (i = 0; i < 16; i++) {
                    ang = func_L39_005B44C8();
                    r = func_L39_005B4410(0.0f, 0.060000002f);
                    off.x = func_0038D098(ang) * r;
                    off.y = func_0038D0B0(ang) * r;
                    off.z = func_L39_005B4410(0.060000002f, 0.13000001f);
                    n = func_L39_005B43C8(0x5A, 0x78);
                    func_L01_00468A68(&sp, &off, func_L39_005B4398(2), n);
                }
            }
} else if (v->b50 != 0 || func_003D5630() != 0) {
                if (D_L39_0025F740.hit != 0 && near && D_L39_0025F740.hit->type != a0->type && pl != 0 && D_L39_0025F740.hit != pl->m2524 && D_L39_0025F740.hit != a0->parent) {
                    Tgt_00539398 *t;

                    a0->bBC = 1;
                    if (a0->state != 1) {
                        a0->pos = D_L39_0025F740.pos;
                        t = live_00539398(a0);
                        if (t == 0 || t->b1A06 == 0) {
                            a0->pos.z = func_003C3D30(&a0->pos, 0, 0, 0.5f);
                        }
                        vec_add_ab(&a0->pos, &a0->pos, &push);
                    }
                } else if (D_L39_0025F740.hit != 0 && D_L39_0025F740.hit->type == a0->type) {
                    vu0_v4 c;
                    vu0_v4 d;
                    vu0_v4 o;
                    vu0_v4 w;
{

                    vec_sub_ba(&D_L39_0025F740.normal, &a0->pos, &D_L39_0025F740.hit->pos);
                    if (vz < -0.19600002f) {
                        a0->bBC = 1;
                        a0->pos = D_L39_0025F740.pos;
                        vec_add_ba(&a0->pos, &a0->pos, &push);
                        func_L01_0040E790(&grav, v, &D_L39_0025F740.normal);
                        func_0038CF68(&grav, &grav, 0.040000003f);
                        func_0038CF68(&dir, &D_L39_0025F740.normal, 1.0f);
                    } else {
                        a0->pos = D_L39_0025F740.pos;
                        vec_add_ba(&a0->pos, &a0->pos, &push);
                        func_0038CF68(&w, &D_L39_0025F740.normal, 0.0038800002f);
                        vec_add_ab(&a0->pos, &a0->pos, &w);
                        func_0038CF68(&w, &D_L39_0025F740.normal, 0.01f);
                        vec_add_ab(&c, &w, &D_L39_0025F740.pos);
                        if (func_003D3CB0((f32 *)&c, (u8 *)&a0->pos, D_L39_0024ADA8 | 2, 0, 0)) {
                            a0->pos = D_L39_0025F740.pos;
                        }
                        func_L01_0040E790(v, v, &w);
                        func_0038CE20((f32 *)v, v, 0.4f);
                        func_0038CF68(&c, &w, 1.0f);
                        func_0038CE68(&c, &dir);
                        d = D_L39_0025F740.normal;
                        k = 0.05235988f;
                        {
                            f32 cs;
                            f32 sn;

                            cs = func_0038D098(a0->rot[2]);
                            sn = func_0038D0B0(a0->rot[2]);
                            o.x = d.x * cs + d.y * sn;
                            cs = func_0038D098(a0->rot[2]);
                            sn = func_0038D0B0(a0->rot[2]);
                            o.y = d.y * cs - d.x * sn;
                            o.z = d.z;
                            a0->rot[0] = func_L39_00537908(a0->rot[0], -func_0038D160(sqrt_asm(o.x * o.x + o.z * o.z), o.y), k);
                            a0->rot[1] = func_L39_00537908(a0->rot[1], func_0038D160(o.z, o.x), k);
                        }
                    }
                }
} else if ((D_L39_0025F740.hit != 0 && pl != 0 && D_L39_0025F740.hit != pl->m2524 && D_L39_0025F740.hit != a0->parent) || D_L39_0025F740.count > 0) {
                    if (v->b50 != 0 || func_003D5630() == 0 || func_003D5630() == 0xD || func_003D5630() == 0xB || vz < -0.19600002f) {
                        a0->bBC = 1;
                        *(vu0_q *)&a0->pos = *(vu0_q *)&D_L39_0025F740.pos;
                        vec_add_ba(&a0->pos, &a0->pos, &push);
                        func_L01_0040E790(&grav, v, &D_L39_0025F740.normal);
                        func_0038CF68(&grav, &grav, 0.040000003f);
                        func_0038CF68(&dir, &D_L39_0025F740.normal, 1.0f);
                    } else {
                        vu0_v4 c;
                        vu0_v4 d;
                        vu0_v4 o;
                        vu0_v4 w;
                        vu0_v4 land;
                        f32 dot;
                        s32 flip;
{

                        *(vu0_q *)&land = *(vu0_q *)&D_L39_0025F740.pos;
                        if (D_L39_0025F740.hit != 0) {
                            found = func_003C4D58((u8 *)D_L39_0025F740.hit);
                        }
                        *(vu0_q *)&a0->pos = *(vu0_q *)&D_L39_0025F740.pos;
                        func_0038CF68(&w, &D_L39_0025F740.normal, 0.0038800002f);
                        vec_add_ba(&a0->pos, &a0->pos, &w);
                        func_L01_0040E790(v, v, &D_L39_0025F740.normal);
                        func_0038CE20((f32 *)v, v, 0.6f);
                        func_0038CF68(&c, &D_L39_0025F740.normal, 1.0f);
                        dot = func_0038CE68(&c, &dir);
                        if (func_003D5630() == 2) {
                            vu0_v4 b;
{

                            func_0038CF68(&v->dir, &D_L39_0025F740.normal, 0.00472f);
                            f = func_0038CE68(v, &c) * 0.5f;
                            func_0038CF68(&b, &D_L39_0025F740.normal, -f);
                            vec_add_ab(&v->vel, &v->vel, &b);
                            if (v->f6C == 0.0f) {
                                v->f6C = f * 4.0f;
                                v->f70 = 0.0f < vz ? 0.7853982f : -2.3561945f;
                                v->i74 = D_L39_0024112C;
                            }
                        }
} else {
                            v->vel.z *= 0.5f;
                            if (v->f6C == 0.0f) {
                                f32 a;

                                v->f6C = fabs_asm(vel.z) + fabs_asm(vel.z);
                                a = -2.3561945f;
                                if (0.0f < vel.z) {
                                    a = 0.7853982f;
                                }
                                v->f70 = a;
                                v->i74 = D_L39_0024112C;
                            }
                        }
                        flip = 0;
                        if (dot > 0.707f && vz < 0.0f) {
                            if (func_003D5630() == 2) {
                                vu0_v4 g;
                                vu0_v4 r;
                                vu0_v4 b;
{

                                func_L39_0053C110(a0, &g, &a0->pos);
                                vec_sub_ab(&r, &g, &a0->pos);
                                if (func_0038CE68(&r, &c) > 0.0f) {
                                    a0->pos = g;
                                }
                                flip = 1;
                                f = func_0038CE68(v, &c) * -2.0f;
                                func_0038CF68(&b, &D_L39_0025F740.normal, f);
                                vec_add_ab(&v->vel, &v->vel, &b);
                            }
} else {
                                f32 z = func_003C3D30(&a0->pos, 0, 0, 0.5f);
                                if (D_L39_002412DC == 0x30) {
                                    z = func_L01_004463D0(&a0->pos);
                                }
                                if (a0->pos.z < z) {
                                    a0->pos.z = z;
                                }
                                v->vel.z = -v->vel.z;
                            }
                            if (func_0038CEA8(v) < 0.010000001f || found != 0) {
                                qzero(&v->vel);
                                a0->state |= 4;
                                if (pl->b1A14 != 0) {
                                    {
                                        Ev_00539398 ev;

                                        {
                                            ev.d = 0xD;
                                            ev.c = (pl->i2544 << 16) | v->s7E;
                                            ev.a = 0x40;
                                            ev.b = -1;
                                            ((s32 *)&ev.pos)[3] = D_001A5CD0.i128;
                                            ev.pos = a0->pos;
                                            if (D_001A5CD0.i170 == 0) {
                                                func_0014AD08(D_001A5CD0.b7D4 | 0x40, D_001A5CD0.i4, -1, D_L39_002405AC, 0x20, &ev);
                                            }
                                        }
                                    }
                                }
                                a0->b30 = 0x40;
                                if (a0->b43 != 2) {
                                    func_003C3A10(a0, 2, 0, 10);
                                }
                                a0->i98 = a0->cls->i10;
                                a0->i9C = 0;
                                if (D_L39_0025F740.hit != 0 && found != 0) {
                                    v->m4C = D_L39_0025F740.hit;
                                }
                                if (flip) {
                                    v->s36 = -1;
                                }
                            } else {
                                vec_add_ab(&a0->pos, &a0->pos, &push);
                            }
                        } else {
                            vec_add_ab(&a0->pos, &a0->pos, &push);
                        }
                        func_0038CF68(&w, &w, 0.01f);
                        vec_add_ab(&c, &w, &land);
                        if (func_003D3CB0((f32 *)&c, (u8 *)&a0->pos, D_L39_0024ADA8 | 2, 0, 0)) {
                            *(vu0_q *)&a0->pos = *(vu0_q *)&D_L39_0025F740.pos;
                        }
                        *(vu0_q *)&d = *(vu0_q *)&D_L39_0025F740.normal;
                        k = 0.05235988f;
                        {
                            f32 cs;
                            f32 sn;

                            cs = func_0038D098(a0->rot[2]);
                            sn = func_0038D0B0(a0->rot[2]);
                            o.x = d.x * cs + d.y * sn;
                            cs = func_0038D098(a0->rot[2]);
                            sn = func_0038D0B0(a0->rot[2]);
                            o.y = d.y * cs - d.x * sn;
                            o.z = d.z;
                            a0->rot[0] = func_L39_00537908(a0->rot[0], -func_0038D160(sqrt_asm(o.x * o.x + o.z * o.z), o.y), k);
                            a0->rot[1] = func_L39_00537908(a0->rot[1], func_0038D160(o.z, o.x), k);
                        }
                    }
}
                }
            }
        }
    } else {
        vu0_v4 tgt;
{

        func_003C4138(&a0->f2C, a0->cls->f24 * 1.25f, a0->cls->f24 * 0.05f);
        func_L39_0053C110(a0, &tgt, &a0->pos);
        if (v->m4C != 0) {
            if (v->m4C->state == 0xFE) {
                a0->bBC = 1;
                v->m4C = 0;
            } else if (v->m4C->state == 0xFD) {
                a0->bBC = 1;
                v->m4C = 0;
            } else if (D_L39_0025F740.hit != 0) {
                found = func_003C4D58((u8 *)D_L39_0025F740.hit);
                if (found != 0) {
                    func_L01_0044C638((u8 *)a0, (u8 *)v->m4C, (u8 *)&a0->pos, (u8 *)a0->rot, (u8 *)&a0->pos, (u8 *)a0->rot);
                }
            }
            if (found == 0) {
                release_00539398(a0, v);
                v->m4C = 0;
                v->t34 = 100;
            }
        } else if (!(a0->state & 0x10)) {
            vu0_v4 d;
{

            vec_sub_ba(&d, &a0->pos, &tgt);
            if (func_0038CEA8(&d) < 0.016f) {
                a0->pos = tgt;
                v->t34 = 0;
                if (D_L39_0025F740.hit != 0 && func_003C4D58((u8 *)D_L39_0025F740.hit) != 0) {
                    v->m4C = D_L39_0025F740.hit;
                }
            } else {
                release_00539398(a0, v);
                v->t34 = 100;
            }
        }
}
        {
            s32 flag = 0;
            Tgt_00539398 *t;

            if (v->m54 != 0) {
                t = tgt_00539398(v->m54);
                if (t != 0) {
                    if ((decode_00539398(&t->b19E6) ^ 0x14) == 0 || (decode_00539398(&t->b19E4) ^ 0x7A) == 0) {
                        flag = 1;
                    }
                }
            }
            if (!(v->m54 != 0 && v->m54->state != 0xFE && v->m54->state != 0xFD && flag == 0 && (v->m54->flags & 0x1000))) {
                if (a0->state & 0x10) {
                    release_00539398(a0, v);
                    v->m54 = 0;
                    v->t34 = 100;
                }
            }
        }
        if (v->m54 != 0 && (a0->state & 0x10)) {
            vu0_v4 d;
            vu0_v4 saved;
            Out_00539398 out;
            vu0_v4 p;
            vu0_v4 q;
{

            saved = a0->pos;
            if (func_L39_005F2FA0(a0, v->slot) == 0) {
                v->slot = func_L39_005F33E0(1, 4, a0);
            }
            v->f40 += 0.0032000002f;
            if (v->f40 > 0.16000001f) {
                v->f40 = 0.16000001f;
            }
            if (v->s52 == 1) {
                func_L39_0053C1E8(a0, &a0->pos, 0.060000002f);
                if (func_0038CAD0(&v->t48)) {
                    v->t48 = 6;
                    v->s52 = 2;
                }
            } else if (v->s52 == 2) {
                func_L39_0053C1E8(a0, &a0->pos, -0.060000002f);
                if (func_0038CAD0(&v->t48)) {
                    v->s52 = 0;
                }
            }
            vec_sub_ba(&d, &v->m54->pos, &a0->pos);
            func_0038CF68(&d, &d, v->f40);
            vec_add_ab(&a0->pos, &a0->pos, &d);
            out.b19 = 3;
            {
                f32 w = pl != 0 ? ent_00539398((u8 *)pl, 6)->f30 : ent_00539398(func_L39_0061BF38(0), 6)->f30;

                func_L01_00446760(&out, a0, 0x10001, &d, w);
            }
            p = a0->pos;
            func_L39_0053C1E8(a0, &p, 0.35f);
            if (func_003D4D00(&p, 0x10, 0.35f, a0, &out)) {
                Moby_00539398 *h = D_L39_0025F740.hit;
                if (h != 0 && (h->flags & 0x1000) && h->type != 0x363 && h->type != 0x1099 &&
                    h->type != 0x458 && h->type != 0x365 && h->type != 0x367) {
                    a0->bBC = 1;
                }
            }
            p = a0->pos;
            func_L39_0053C1E8(a0, &p, 0.25f);
            if (func_L01_003FB640(&p, D_L39_0024ADA8, (u8 *)a0, 0.25f)) {
                vec_sub_ba(&q, &D_L39_0025F740.v30, &p);
                vec_add_ab(&a0->pos, &a0->pos, &q);
            }
            if (func_0038CAD0(&v->t58)) {
                a0->bBC = 1;
            }
        }
}
        func_L01_0044EBA0(a0, &v->f60, &v->f64, 0.5235988f, 0.010471976f, 0.0059341197f);
        if (a0->state & 4) {
            vu0_v4 c;
            vu0_v4 dd;
{

            vec_sub_ba(&dd, &a0->pos, &from);
            c = dd;
            v->vel = c;
        }
}
    }
}

    if (!(a0->state & 2) && func_0038CB00(&v->t34)) {
        a0->state |= 2;
        v->m54 = 0;
    }
    {
        Res_00539398 *r = (Res_00539398 *)func_L01_00447490(a0, 0x01030000, 0);
        if (r != 0 && r->m20 != 0 && r->m20->type != a0->type) {
            a0->bBC = 1;
        }
    }
    a0->bA8 = 0xFF;
    if (a0->state & 4) {
        if (v->f6C > 0.05f) {
            v->f6C *= 0.9856f;
            if (v->f6C < 0.05f) {
                v->f6C = 0.05f;
            }
        }
        f = (f32)(D_L39_0024112C - v->i74) / 5.3333335f;
        if (f > 1.0f) {
            f = 1.0f;
        } else if (f < 0.0f) {
            f = 0.0f;
        }
        v->f70 = func_0038DAB8(v->f70, 0.12566371f);
        if (v->s36 == -1) {
            vu0_v4 b;
{

            b = v->dir;
            func_0038CF68(&b, &b, 0.4f);
            vec_add_ba(&a0->pos, &a0->pos, &b);
            func_0038CF68(&b, &b, v->f6C * func_0038D0B0(v->f70) * f);
            vec_add_ab(&a0->pos, &a0->pos, &b);
        }
} else {
            a0->pos.z = a0->pos.z + v->f6C * func_0038D0B0(v->f70) * f + 0.4f;
        }
    }
    if (a0->state & 2) {
        if (!(a0->state & 4)) {
            a0->bBC = 1;
            goto skip;
        }
        if (pl != 0 && func_0038CF38(&pl->vE0, &a0->pos) < 1.4f &&
            fabs_asm(func_L39_0053C248(a0, &pl->vE0)) < 0.9f && (a0->state & 0x10)) {
            a0->bBC = 1;
            goto skip;
        }
        if ((D_L39_0024112C & 3) == (((s32)a0 >> 8) & 3)) {
            vu0_v4 b;
            s32 j;
            Moby_00539398 *m;
            Moby_00539398 *best = 0;
            f32 bestd = 0.0f;
            f32 range = 10.0f;
{

            for (j = 0; (m = D_L39_00292C20[j]) != 0; j++) {
                {
                    if (m->i98 != 0) {
                        u8 *r = func_00382348(m);
                        f32 d;

                        if (r != 0) {
                            Tgt_00539398 *t2;
                            vu0_v4 *mp = &m->pos;

                            b = *mp;
                            t2 = tgt_00539398(m);
                            if (t2 != 0) {
                                func_L01_00511158(t2, &b, mp, *(f32 *)(r + 0x10));
                            } else {
                                b.z += *(f32 *)(r + 0x10);
                            }
                        } else {
                            b = m->pos;
                        }
                        if (!(func_0038CF00(&a0->pos, &b) > range + 4.0f) &&
                            func_L39_00539268(pl->i2548, (O_00539268 *)m, 0) != 0) {
                            if (func_0038CF00(&a0->pos, &b) < 2.0f) {
                                a0->bBC = 1;
                                break;
                            }
                            d = func_0038CF38(&a0->pos, &b);
                            if (d < range && fabs_asm(func_L39_0053C248(a0, &b)) < 2.65f &&
                                (v->m54 == 0 || v->m54->state == 0xFE || v->m54->state == 0xFD) &&
                                (best == 0 || d < bestd)) {
                                best = m;
                                bestd = d;
                            }
                        }
                    }
                }
            }
            if (best != 0) {
                vu0_v4 c;
{

                b = a0->pos;
                func_L39_0053C1E8(a0, &b, 1.0f);
                c = best->pos;
                func_L39_0053C1E8(a0, &c, 2.0f);
                if (func_003D3CB0((f32 *)&b, (u8 *)&c, D_L39_0024ADA8, (u8 *)a0, 0) == 0 || D_L39_0025F740.hit == best) {
                    Tgt_00539398 *t2;

                    a0->state |= 0x10;
                    func_L39_005F33E0(0, 0, a0);
                    v->m54 = best;
                    v->f40 = 0.0f;
                    v->t58 = 500;
                    v->s52 = 1;
                    v->t48 = 6;
                    t2 = (Tgt_00539398 *)func_L39_0061D7B0(best);
                    if (t2 != 0 && ((t2->b3 & 0xF) == 0 || (t2->b3 & 0xF) == 3)) {
                        s32 ok = 0;

                        if ((t2->b3 & 0xF) == 0) {
                            ok = t2->b1A14 != 0;
                        } else if ((t2->b3 & 0xF) == 3 && t2->p2D8 != 0) {
                            ok = t2->p2D8->b1A14 != 0;
                        }
                        if (ok) {
                            Ev_00539398 ev;
{

                            ev.d = 0xD;
                            ev.c = (pl->i2544 << 16) | v->s7E;
                            ev.a = 0x20;
                            ev.b = *(s32 *)t2;
                            ((s32 *)&ev.pos)[3] = D_001A5CD0.i128;
                            ev.pos = best->pos;
                            if (D_001A5CD0.i170 == 0) {
                                func_0014AD08(D_001A5CD0.b7D4 | 0x40, D_001A5CD0.i4, -1, D_L39_002405AC, 0x20, &ev);
                            }
                        }
}
                    }
                }
            }
}
        }
}
    }
skip:
    if (v->i5C < 0) {
        func_L01_0044BB30(a0, &a0->pos, -1, 0.33f, 0.0f);
        if (v->i5C == -2) {
            {
                Ev_00539398 ev;

                {
                    ev.d = 0xD;
                    ev.c = (pl->i2544 << 16) | v->s7E;
                    ev.a = 0x10;
                    ev.b = 1;
                    ((s32 *)&ev.pos)[3] = D_001A5CD0.i128;
                    ev.pos = a0->pos;
                    if (D_001A5CD0.i170 == 0) {
                        func_0014AD08(D_001A5CD0.b7D4 | 0x40, D_001A5CD0.i4, -1, D_L39_002405AC, 0x20, &ev);
                    }
                }
            }
        }
        func_L01_0044BEC8(a0, D_L39_00293F38[pl->i2544]);
        func_003C2880(a0);
        return;
    }
    if (func_003D3CB0((f32 *)&from, (u8 *)&a0->pos, D_L39_0024ADA8 | 2, 0, 0)) {
        a0->bBC = 1;
        a0->pos = from;
    }
    if (a0->bBC != 0 && pl != 0) {
        vu0_v4 b;
        f32 dist = func_0038CF38(&a0->pos, &pl->v23A0);
{

        if (v->b50 == 0) {
            Probe_00539398 pr;
            vu0_v4 u;
            vu0_v4 s;
            vu0_v4 x;
            s32 n;
            s32 i;
{

            n = func_003D4D00(&a0->pos, 0x10, 2.0f, a0, 0);
            pr.f0C = ent_00539398((u8 *)pl, 6)->f30;
            pr.owner = a0;
            pr.mask = 0x01010001;
            pr.i10 = 0x01010001;
            pr.a = 4;
            pr.b = 3;
            pr.type = a0->type;
            pr.i18 = -1;
            if (v->s36 == -1) {
                u = v->dir;
                func_0038CF68(&u, &u, 1.0f);
            } else {
                up_00539398(&u);
            }
            for (i = 0; i < n; i++) {
                vec_sub_ba(&s, &D_L39_002637C0[i]->pos, &a0->pos);
                func_0038CF68(&s, &s, 1.0f);
                func_0038CE90(&x, &s, &u);
                func_0038CE90(&s, &x, &u);
                func_0038CF68(&b, &s, 0.25f);
                func_0038CF68(&u, &u, 1.5f);
                vec_add_ab(&b, &b, &u);
                b.w = 5627.925f;
                func_L01_00446978(D_L39_002637C0[i], &b);
            }
        }
}
        func_L39_0053C110(a0, &b, &a0->pos);
        if (v->b50 != 0) {
            func_L39_0053C300(a0);
        } else if (v->b51 == 0 && func_0038CF00(&a0->pos, &b) > 2.0f) {
            vu0_v4 z;
{

            qzero(&z);
            func_L39_005B8978(a0, &z, 0, 0.0f, 0.0f, 3, 3, 5, 2.0f, 1.0f, 4.0f, 1.0f, 2, 7.0f, 0, 1, -1, 0, 0x01010001);
        }
} else {
            vu0_v4 dd;
            vu0_v4 *dp = 0;
{

            if (v->s36 == -1) {
                dd = v->dir;
                func_0038CF68(&dd, &dd, 1.0f);
                dp = &dd;
            }
            func_L32_003B8498(&a0->pos, 1.0f, 2.0f, 1.0f, 0, 0x7F, 1.4f, 0x30, D_L39_0024ADA0, D_L39_0024ADA4, (s32)dp);
        }
}
        a0->bBC = 0;
        func_L39_005F33E0(2, 0, a0);
        if (pl != 0 && pl->b1A14 != 0) {
            {
                Hud_00539398 *h = D_L39_0024DE80 + pl->b24C9;

                h->f20 = dist < 8.0f ? 0.55f - dist * 0.0225f : 0.100000024f;
            }
            (D_L39_0024DE80 + pl->b24C9)->i28 = 0x36;
            (D_L39_0024DE80 + pl->b24C9)->i2C = 0;
        }
        {
            Ev_00539398 ev;

            {
                ev.d = 0xD;
                ev.c = (pl->i2544 << 16) | v->s7E;
                ev.a = 0x10;
                ev.b = 0;
                ((s32 *)&ev.pos)[3] = D_001A5CD0.i128;
                ev.pos = a0->pos;
                if (D_001A5CD0.i170 == 0) {
                    func_0014AD08(D_001A5CD0.b7D4 | 0x40, D_001A5CD0.i4, -1, D_L39_002405AC, 0x20, &ev);
                }
            }
        }
        func_L01_0044BEC8(a0, D_L39_00293F38[pl->i2544]);
        func_003C2880(a0);
        return;
    }
}
    func_L01_004471A8(a0, 0.25f);
}
/* localdecomp:end func_L39_00539398 */
