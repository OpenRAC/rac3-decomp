#include "common.h"

/* NTSC-U counterpart of func_L39_00539398 (src/levels/shared/L39_00539398.c) */
extern f32 func_L39_005B2510(f32, f32);
extern s32 D_L39_002412AC;
typedef struct {
    u8 pad0[0xAA];
    s16 hAA;
    u8 padAC[0xBE - 0xAC];
    u8 bBE;
} O_00539268;
extern s32 func_L39_0061B038(void *);

/* localdecomp:start func_L39_00538C08 */
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

extern Snd_00539398 D_001A5E50;
extern u8 D_L39_001FE1A0[];
extern u8 D_L39_004998A0[];
extern Ent_00539398 D_L39_0049C950[];
extern Coll_00539398 D_L39_0025F840;
extern Moby_00539398 *D_L39_00292D20[];
extern Moby_00539398 *D_L39_002638C0[];
typedef struct Hud_00539398 {
    u8 pad0[0x20];
    f32 f20;                            /* 0x20 */
    u8 pad24[4];
    s32 i28;                            /* 0x28 */
    s32 i2C;                            /* 0x2C */
    u8 pad30[0x460 - 0x30];
} Hud_00539398;

extern Hud_00539398 D_L39_0024DF80[];
extern s32 D_L39_0024145C;
__asm__(".extern D_L39_0024145C, 16");
extern s32 D_L39_0024072C;
__asm__(".extern D_L39_0024072C, 16");
extern s32 D_L39_0024CBF8_00538C08;
__asm__(".extern D_L39_0024CBF8_00538C08, 16");
extern s16 D_L39_00294038[][64];
extern s32 D_L39_0024AEB8_00538C08;
__asm__(".extern D_L39_0024AEB8_00538C08, 4");
extern void *D_L39_0024CBF0_00538C08;
__asm__(".extern D_L39_0024CBF0_00538C08, 4");
extern s16 D_L39_0024AEB0;
__asm__(".extern D_L39_0024AEB0, 2");
extern s16 D_L39_0024AEB4;
__asm__(".extern D_L39_0024AEB4, 2");
extern u8 *D_L39_0024CF20[8] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024CF20, 32");

extern void func_003BD360(void *);
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(f32 *, void *, f32);
extern f32 func_00388730(void *, void *);
extern void func_00388758(void *, void *, void *);
extern f32 func_00388770(void *);
extern f32 func_003887C8(void *, void *);
extern f32 func_00388800(void *, void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern s32 func_00388398(void *);
extern s32 func_003883C8(void *);
extern s32 func_003CE740(f32 *, u8 *, s32, u8 *, s32);
extern s32 func_003CF790(void *, s32, f32, void *, void *);
extern s32 func_003D00C0(void);
extern u8 *func_0037E0B8(void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern f32 func_003BE988(void *, void *);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern u8 *func_003BF7E8(u8 *);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);
extern s32 func_L39_0053AF18(u8 *, u8 *, u8 *);
extern s32 func_L39_0053B978(void *, void *, void *);
extern void func_L39_0053BA50(void *, void *, f32);
extern f32 func_L39_0053BAB0(void *, void *);
extern void func_L39_0053BB08_00538C08(void *);
extern void func_L39_0053BB68(void *);
extern f32 func_L39_00537180(f32, f32, f32);
extern s32 func_L39_005FC918(void *, void *, void *, s32, f32);
extern s32 func_L39_005B2498(s32);
extern s32 func_L39_005B24C8(s32, s32);
extern f32 func_L39_005B25C8_00538C08(void);
extern void *func_L39_005C84F8(void *, void *, u32, f32, f32);
extern s32 func_L39_00646268(u8 *, s32);
extern u8 *func_L39_006197C0(s32);
extern s32 func_L39_005F08A0(void *, s32);
extern s32 func_L39_005F0CE0(s32, s32, void *);
extern void func_L39_005F0988(s32);
extern void func_L39_005B69C0(void *, void *, void *, f32, f32, s32, s32, s32, f32, f32, f32, f32, s32, f32, s32, s32, s32, s32, s32);
extern u8 *func_L01_00301508(void *, s32, f32, f32);
extern void func_L01_004C2BF8(void *, s32, u32, f32, f32, f32, f32);
extern s32 func_L01_003F9498(void *, s32, u8 *, f32);
extern f32 func_L01_00443298(void *);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_00443840(void *, void *);
extern void func_L01_00444070(void *, f32);
extern void *func_L01_00444358(void *, s32, s32);
extern void func_L01_004488B8(void *, void *, s32, f32, f32);
extern void func_L01_00448C50(void *, void *);
extern s32 func_L01_004493C0(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *);
extern void func_L01_0044B920(void *, void *, void *, f32, f32, f32);
extern void *func_L01_00465410(void *, void *, s32, s32);
extern void func_L01_0050D180(void *, void *, void *, f32);
extern void func_L01_0040C260(void *, void *, void *);
extern void func_L32_003B6A10(void *, f32, f32, f32, s32, u8, f32, s32, s32, s32, s32);

/* the weapon table row of id, or its upgraded row */
static __inline__ Ent_00539398 *ent_00539398(u8 *p, s32 id) {
    if (func_L39_00646268(p, id)) {
        return &D_L39_0049C950[D_L39_0049C950[id].b21];
    }
    return &D_L39_0049C950[id];
}


static __inline__ Tgt_00539398 *live_00539398(void *m) {
    Tgt_00539398 *t = (Tgt_00539398 *)func_L39_0061B038(m);
    Tgt_00539398 *r = 0;

    if (t != 0) {
        r = (t->b3 & 0xF) ? 0 : t;
    }
    return r;
}

static __inline__ Tgt_00539398 *tgt_00539398(void *m) {
    Tgt_00539398 *t = (Tgt_00539398 *)func_L39_0061B038(m);
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
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
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
        u8 *e = D_L39_001FE1A0 + slot * 128;
        if (*(Moby_00539398 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
            func_L39_005F0988(slot);
        }
    }
    v->slot = -1;
    func_L39_0053BB08_00538C08(a0);
}


static __inline__ void up_00539398(vu0_v4 *d) {
    vu0_q q;
    __asm__("vmr32.xyzw %0, $vf0" : "=j"(q));
    __asm__("sqc2 %1, %0" : "=m"(*d) : "j"(q));
}


void func_L39_00538C08(Moby_00539398 *a0) {
    vu0_v4 grav = { 0.0f, 0.0f, 0.033333335f, 0.0f };
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
        func_003BD360(a0);
        return;
    }
    pl = (Player_00539398 *)D_L39_0024CF20[(s16)v->idx];
    func_00388830(&dir, &v->dir, 1.0f);
    if (pl != 0 && ((pl->l1A08 & 0xFFFF0000) != 0 || pl->i1310 == 2 || pl->s2488 != 0) && a0->state == 0) {
        a0->flags |= 0x41;
    } else {
        a0->flags &= ~0x41;
    }
    if (pl == 0 || !((pl->m450 != 0 && pl->m450->type == 0x1098) || a0->state != 0)) {
        func_003BD360(a0);
        return;
    }
    if (a0->parent != 0 && a0->parent->state != 0xFE && a0->parent->state != 0xFD &&
        a0->parent->type == 0x1098 && v->s36 == 0 && 0.0f < func_00388770(v)) {
        func_L39_0053AF18((u8 *)v, (u8 *)a0, (u8 *)a0->parent->vars);
    }
    if (a0->state == 0) {
        Moby_00539398 *p;

        if (pl->m450 == 0 || pl->m450->type != 0x1098) {
            func_003BD360(a0);
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
            if (func_L39_005FC918(&v->dir, &a0->pos, v, v->s36 == -1, 0.0032777779f)) {
                v->s36 = -1;
            } else {
                v->s36 = 1;
            }
            vec_add_ab(&a0->pos, &v->vel, &a0->pos);
        } else {
            v->vel.z -= 0.00027222223f;
            if (func_L39_005B2498(5) == 0) {
                f = func_003BE988(&a0->pos, &up);
                func_003886E8((f32 *)&up, v, 0.25f);
                func_L39_005C84F8(&a0->pos, &up, 0x88A0A0A0, func_L39_005B2510(0.05f, 0.1f) * 210000.0f, f);
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
        func_00388830(&up, &up, 1.0f);
    } else {
        up_00539398(&up);
    }
    func_00388830(&fwd, &fwd, 1.0f);
    func_00388758(&side, &fwd, &up);
    func_00388758(&fwd, &side, &up);
    func_00388830(&fwd, &fwd, 1.0f);
    vec_add_ab(&fwd, &fwd, &up);
    fwd.w = 5627.925f;
    probe.a = 2;
    probe.b = 3;
    probe.type = a0->type;
    if ((a0->state & 4) || v->t34 < 0x6E) {
        if (v->s36 == -1) {
            push = v->dir;
        } else {
            up_00539398(&push);
        }
        func_00388830(&push, &push, 0.4f);
        f = (f32)(D_L39_002412AC - v->i74) / 6.0f;
        if (f > 1.0f) {
            f = 1.0f;
        } else if (f < 0.0f) {
            f = 0.0f;
        }
        {
            vu0_v4 t;

            {
                func_00388830(&t, &push, v->f6C * func_00388978(v->f70) * f);
                vec_add_ba(&push, &push, &t);
            }
        }
        vec_sub_ab(&a0->pos, &a0->pos, &push);
    } else {
        qzero(&push);
    }

    if (!(a0->state & 4)) {
        hit = func_003CE740((f32 *)&from, (u8 *)&a0->pos, D_L39_0024AEB8_00538C08 | 0x10, (u8 *)a0, 0);
        vec_add_ab(&a0->pos, &a0->pos, &push);
    }
    if (!(a0->state & 4)) {
        if (hit != 0) {
            vu0_v4 vel;
            s32 near;
            f32 vz;
            Moby_00539398 *h;

            near = func_L39_00538AD8(pl->i2548, (O_00539268 *)D_L39_0025F840.hit, 0) != 0;
            if (near) {
                func_L01_00443840(D_L39_0025F840.hit, &fwd);
            }
            vel = v->vel;
            if (func_003D00C0() == 2) {
                vu0_v4 n;
{

                func_00388830(&n, &D_L39_0025F840.normal, 1.0f);
                vz = func_00388730(v, &n);
            }
} else {
                vz = vel.z;
            }
            if (v->b50 == 0 && (func_003D00C0() == 0 || func_003D00C0() == 0xD || func_003D00C0() == 0xB) && vz < 0.0f) {
                vu0_v4 sp;
                vu0_v4 off;
                u8 *fx;
                s32 i;
                f32 ang;
                f32 r;
                s32 n;
{

                func_L01_004C2BF8(D_L39_0024CBF0_00538C08, D_L39_0024CBF8_00538C08, 1, a0->pos.x, a0->pos.y, 0.5f, -0.35f);
                qzero(&v->vel);
                v->b50 = 1;
                v->vel.z = -0.025000002f;
                sp.x = a0->pos.x;
                sp.y = a0->pos.y;
                sp.z = D_L39_0025F840.pos.z;
                fx = func_L01_00301508(&sp, 3, 2.0f, 1.025f);
                if (fx != 0) {
                    fx[0x23] = 0x70;
                }
                for (i = 0; i < 16; i++) {
                    ang = func_L39_005B25C8_00538C08();
                    r = func_L39_005B2510(0.0f, 0.050000004f);
                    off.x = func_00388960(ang) * r;
                    off.y = func_00388978(ang) * r;
                    off.z = func_L39_005B2510(0.050000004f, 0.10833334f);
                    n = func_L39_005B24C8(0x5A, 0x78);
                    func_L01_00465410(&sp, &off, func_L39_005B2498(2), n);
                }
            }
} else if (v->b50 != 0 || func_003D00C0() != 0) {
                if (D_L39_0025F840.hit != 0 && near && D_L39_0025F840.hit->type != a0->type && pl != 0 && D_L39_0025F840.hit != pl->m2524 && D_L39_0025F840.hit != a0->parent) {
                    Tgt_00539398 *t;

                    a0->bBC = 1;
                    if (a0->state != 1) {
                        a0->pos = D_L39_0025F840.pos;
                        t = live_00539398(a0);
                        if (t == 0 || t->b1A06 == 0) {
                            a0->pos.z = func_003BE7F0(&a0->pos, 0, 0, 0.5f);
                        }
                        vec_add_ab(&a0->pos, &a0->pos, &push);
                    }
                } else if (D_L39_0025F840.hit != 0 && D_L39_0025F840.hit->type == a0->type) {
                    vu0_v4 c;
                    vu0_v4 d;
                    vu0_v4 o;
                    vu0_v4 w;
{

                    vec_sub_ba(&D_L39_0025F840.normal, &a0->pos, &D_L39_0025F840.hit->pos);
                    if (vz < -0.16333334f) {
                        a0->bBC = 1;
                        a0->pos = D_L39_0025F840.pos;
                        vec_add_ba(&a0->pos, &a0->pos, &push);
                        func_L01_0040C260(&grav, v, &D_L39_0025F840.normal);
                        func_00388830(&grav, &grav, 0.033333335f);
                        func_00388830(&dir, &D_L39_0025F840.normal, 1.0f);
                    } else {
                        a0->pos = D_L39_0025F840.pos;
                        vec_add_ba(&a0->pos, &a0->pos, &push);
                        func_00388830(&w, &D_L39_0025F840.normal, 0.0026944445f);
                        vec_add_ab(&a0->pos, &a0->pos, &w);
                        func_00388830(&w, &D_L39_0025F840.normal, 0.01f);
                        vec_add_ab(&c, &w, &D_L39_0025F840.pos);
                        if (func_003CE740((f32 *)&c, (u8 *)&a0->pos, D_L39_0024AEB8_00538C08 | 2, 0, 0)) {
                            a0->pos = D_L39_0025F840.pos;
                        }
                        func_L01_0040C260(v, v, &w);
                        func_003886E8((f32 *)v, v, 0.4f);
                        func_00388830(&c, &w, 1.0f);
                        func_00388730(&c, &dir);
                        d = D_L39_0025F840.normal;
                        k = 0.05235988f;
                        {
                            f32 cs;
                            f32 sn;

                            cs = func_00388960(a0->rot[2]);
                            sn = func_00388978(a0->rot[2]);
                            o.x = d.x * cs + d.y * sn;
                            cs = func_00388960(a0->rot[2]);
                            sn = func_00388978(a0->rot[2]);
                            o.y = d.y * cs - d.x * sn;
                            o.z = d.z;
                            a0->rot[0] = func_L39_00537180(a0->rot[0], -func_00388A28(sqrt_asm(o.x * o.x + o.z * o.z), o.y), k);
                            a0->rot[1] = func_L39_00537180(a0->rot[1], func_00388A28(o.z, o.x), k);
                        }
                    }
                }
} else if ((D_L39_0025F840.hit != 0 && pl != 0 && D_L39_0025F840.hit != pl->m2524 && D_L39_0025F840.hit != a0->parent) || D_L39_0025F840.count > 0) {
                    if (v->b50 != 0 || func_003D00C0() == 0 || func_003D00C0() == 0xD || func_003D00C0() == 0xB || vz < -0.16333334f) {
                        a0->bBC = 1;
                        *(vu0_q *)&a0->pos = *(vu0_q *)&D_L39_0025F840.pos;
                        vec_add_ba(&a0->pos, &a0->pos, &push);
                        func_L01_0040C260(&grav, v, &D_L39_0025F840.normal);
                        func_00388830(&grav, &grav, 0.033333335f);
                        func_00388830(&dir, &D_L39_0025F840.normal, 1.0f);
                    } else {
                        vu0_v4 c;
                        vu0_v4 d;
                        vu0_v4 o;
                        vu0_v4 w;
                        vu0_v4 land;
                        f32 dot;
                        s32 flip;
{

                        *(vu0_q *)&land = *(vu0_q *)&D_L39_0025F840.pos;
                        if (D_L39_0025F840.hit != 0) {
                            found = func_003BF7E8((u8 *)D_L39_0025F840.hit);
                        }
                        *(vu0_q *)&a0->pos = *(vu0_q *)&D_L39_0025F840.pos;
                        func_00388830(&w, &D_L39_0025F840.normal, 0.0026944445f);
                        vec_add_ba(&a0->pos, &a0->pos, &w);
                        func_L01_0040C260(v, v, &D_L39_0025F840.normal);
                        func_003886E8((f32 *)v, v, 0.6f);
                        func_00388830(&c, &D_L39_0025F840.normal, 1.0f);
                        dot = func_00388730(&c, &dir);
                        if (func_003D00C0() == 2) {
                            vu0_v4 b;
{

                            func_00388830(&v->dir, &D_L39_0025F840.normal, 0.0032777779f);
                            f = func_00388730(v, &c) * 0.5f;
                            func_00388830(&b, &D_L39_0025F840.normal, -f);
                            vec_add_ab(&v->vel, &v->vel, &b);
                            if (v->f6C == 0.0f) {
                                v->f6C = f * 4.0f;
                                v->f70 = 0.0f < vz ? 0.7853982f : -2.3561945f;
                                v->i74 = D_L39_002412AC;
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
                                v->i74 = D_L39_002412AC;
                            }
                        }
                        flip = 0;
                        if (dot > 0.707f && vz < 0.0f) {
                            if (func_003D00C0() == 2) {
                                vu0_v4 g;
                                vu0_v4 r;
                                vu0_v4 b;
{

                                func_L39_0053B978(a0, &g, &a0->pos);
                                vec_sub_ab(&r, &g, &a0->pos);
                                if (func_00388730(&r, &c) > 0.0f) {
                                    a0->pos = g;
                                }
                                flip = 1;
                                f = func_00388730(v, &c) * -2.0f;
                                func_00388830(&b, &D_L39_0025F840.normal, f);
                                vec_add_ab(&v->vel, &v->vel, &b);
                            }
} else {
                                f32 z = func_003BE7F0(&a0->pos, 0, 0, 0.5f);
                                if (D_L39_0024145C == 0x30) {
                                    z = func_L01_00443298(&a0->pos);
                                }
                                if (a0->pos.z < z) {
                                    a0->pos.z = z;
                                }
                                v->vel.z = -v->vel.z;
                            }
                            if (func_00388770(v) < 0.0083333338f || found != 0) {
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
                                            ((s32 *)&ev.pos)[3] = D_001A5E50.i128;
                                            ev.pos = a0->pos;
                                            if (D_001A5E50.i170 == 0) {
                                                func_0014AD08(D_001A5E50.b7D4 | 0x40, D_001A5E50.i4, -1, D_L39_0024072C, 0x20, &ev);
                                            }
                                        }
                                    }
                                }
                                a0->b30 = 0x40;
                                if (a0->b43 != 2) {
                                    func_003BE4F0(a0, 2, 0, 10);
                                }
                                a0->i98 = a0->cls->i10;
                                a0->i9C = 0;
                                if (D_L39_0025F840.hit != 0 && found != 0) {
                                    v->m4C = D_L39_0025F840.hit;
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
                        func_00388830(&w, &w, 0.01f);
                        vec_add_ab(&c, &w, &land);
                        if (func_003CE740((f32 *)&c, (u8 *)&a0->pos, D_L39_0024AEB8_00538C08 | 2, 0, 0)) {
                            *(vu0_q *)&a0->pos = *(vu0_q *)&D_L39_0025F840.pos;
                        }
                        *(vu0_q *)&d = *(vu0_q *)&D_L39_0025F840.normal;
                        k = 0.05235988f;
                        {
                            f32 cs;
                            f32 sn;

                            cs = func_00388960(a0->rot[2]);
                            sn = func_00388978(a0->rot[2]);
                            o.x = d.x * cs + d.y * sn;
                            cs = func_00388960(a0->rot[2]);
                            sn = func_00388978(a0->rot[2]);
                            o.y = d.y * cs - d.x * sn;
                            o.z = d.z;
                            a0->rot[0] = func_L39_00537180(a0->rot[0], -func_00388A28(sqrt_asm(o.x * o.x + o.z * o.z), o.y), k);
                            a0->rot[1] = func_L39_00537180(a0->rot[1], func_00388A28(o.z, o.x), k);
                        }
                    }
}
                }
            }
        }
    } else {
        vu0_v4 tgt;
{

        func_003BEBF8(&a0->f2C, a0->cls->f24 * 1.25f, a0->cls->f24 * 0.05f);
        func_L39_0053B978(a0, &tgt, &a0->pos);
        if (v->m4C != 0) {
            if (v->m4C->state == 0xFE) {
                a0->bBC = 1;
                v->m4C = 0;
            } else if (v->m4C->state == 0xFD) {
                a0->bBC = 1;
                v->m4C = 0;
            } else if (D_L39_0025F840.hit != 0) {
                found = func_003BF7E8((u8 *)D_L39_0025F840.hit);
                if (found != 0) {
                    func_L01_004493C0((u8 *)a0, (u8 *)v->m4C, (u8 *)&a0->pos, (u8 *)a0->rot, (u8 *)&a0->pos, (u8 *)a0->rot);
                }
            }
            if (found == 0) {
                release_00539398(a0, v);
                v->m4C = 0;
                v->t34 = 120;
            }
        } else if (!(a0->state & 0x10)) {
            vu0_v4 d;
{

            vec_sub_ba(&d, &a0->pos, &tgt);
            if (func_00388770(&d) < 0.011111111f) {
                a0->pos = tgt;
                v->t34 = 0;
                if (D_L39_0025F840.hit != 0 && func_003BF7E8((u8 *)D_L39_0025F840.hit) != 0) {
                    v->m4C = D_L39_0025F840.hit;
                }
            } else {
                release_00539398(a0, v);
                v->t34 = 120;
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
                    v->t34 = 120;
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
            if (func_L39_005F08A0(a0, v->slot) == 0) {
                v->slot = func_L39_005F0CE0(1, 4, a0);
            }
            v->f40 += 0.0022222223f;
            if (v->f40 > 0.13333334f) {
                v->f40 = 0.13333334f;
            }
            if (v->s52 == 1) {
                func_L39_0053BA50(a0, &a0->pos, 0.05f);
                if (func_00388398(&v->t48)) {
                    v->t48 = 7;
                    v->s52 = 2;
                }
            } else if (v->s52 == 2) {
                func_L39_0053BA50(a0, &a0->pos, -0.05f);
                if (func_00388398(&v->t48)) {
                    v->s52 = 0;
                }
            }
            vec_sub_ba(&d, &v->m54->pos, &a0->pos);
            func_00388830(&d, &d, v->f40);
            vec_add_ab(&a0->pos, &a0->pos, &d);
            out.b19 = 3;
            {
                f32 w = pl != 0 ? ent_00539398((u8 *)pl, 6)->f30 : ent_00539398(func_L39_006197C0(0), 6)->f30;

                func_L01_00443628(&out, a0, 0x10001, &d, w);
            }
            p = a0->pos;
            func_L39_0053BA50(a0, &p, 0.35f);
            if (func_003CF790(&p, 0x10, 0.35f, a0, &out)) {
                Moby_00539398 *h = D_L39_0025F840.hit;
                if (h != 0 && (h->flags & 0x1000) && h->type != 0x363 && h->type != 0x1099 &&
                    h->type != 0x458 && h->type != 0x365 && h->type != 0x367) {
                    a0->bBC = 1;
                }
            }
            p = a0->pos;
            func_L39_0053BA50(a0, &p, 0.25f);
            if (func_L01_003F9498(&p, D_L39_0024AEB8_00538C08, (u8 *)a0, 0.25f)) {
                vec_sub_ba(&q, &D_L39_0025F840.v30, &p);
                vec_add_ab(&a0->pos, &a0->pos, &q);
            }
            if (func_00388398(&v->t58)) {
                a0->bBC = 1;
            }
        }
}
        func_L01_0044B920(a0, &v->f60, &v->f64, 0.5235988f, 0.0087266471f, 0.0049450998f);
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

    if (!(a0->state & 2) && func_003883C8(&v->t34)) {
        a0->state |= 2;
        v->m54 = 0;
    }
    {
        Res_00539398 *r = (Res_00539398 *)func_L01_00444358(a0, 0x01030000, 0);
        if (r != 0 && r->m20 != 0 && r->m20->type != a0->type) {
            a0->bBC = 1;
        }
    }
    a0->bA8 = 0xFF;
    if (a0->state & 4) {
        if (v->f6C > 0.05f) {
            v->f6C *= 0.988f;
            if (v->f6C < 0.05f) {
                v->f6C = 0.05f;
            }
        }
        f = (f32)(D_L39_002412AC - v->i74) / 6.0f;
        if (f > 1.0f) {
            f = 1.0f;
        } else if (f < 0.0f) {
            f = 0.0f;
        }
        v->f70 = func_00389380(v->f70, 0.104719765f);
        if (v->s36 == -1) {
            vu0_v4 b;
{

            b = v->dir;
            func_00388830(&b, &b, 0.4f);
            vec_add_ba(&a0->pos, &a0->pos, &b);
            func_00388830(&b, &b, v->f6C * func_00388978(v->f70) * f);
            vec_add_ab(&a0->pos, &a0->pos, &b);
        }
} else {
            a0->pos.z = a0->pos.z + v->f6C * func_00388978(v->f70) * f + 0.4f;
        }
    }
    if (a0->state & 2) {
        if (!(a0->state & 4)) {
            a0->bBC = 1;
            goto skip;
        }
        if (pl != 0 && func_00388800(&pl->vE0, &a0->pos) < 1.4f &&
            fabs_asm(func_L39_0053BAB0(a0, &pl->vE0)) < 0.9f && (a0->state & 0x10)) {
            a0->bBC = 1;
            goto skip;
        }
        if ((D_L39_002412AC & 3) == (((s32)a0 >> 8) & 3)) {
            vu0_v4 b;
            s32 j;
            Moby_00539398 *m;
            Moby_00539398 *best = 0;
            f32 bestd = 0.0f;
            f32 range = 10.0f;
{

            for (j = 0; (m = D_L39_00292D20[j]) != 0; j++) {
                {
                    if (m->i98 != 0) {
                        u8 *r = func_0037E0B8(m);
                        f32 d;

                        if (r != 0) {
                            Tgt_00539398 *t2;
                            vu0_v4 *mp = &m->pos;

                            b = *mp;
                            t2 = tgt_00539398(m);
                            if (t2 != 0) {
                                func_L01_0050D180(t2, &b, mp, *(f32 *)(r + 0x10));
                            } else {
                                b.z += *(f32 *)(r + 0x10);
                            }
                        } else {
                            b = m->pos;
                        }
                        if (!(func_003887C8(&a0->pos, &b) > range + 4.0f) &&
                            func_L39_00538AD8(pl->i2548, (O_00539268 *)m, 0) != 0) {
                            if (func_003887C8(&a0->pos, &b) < 2.0f) {
                                a0->bBC = 1;
                                break;
                            }
                            d = func_00388800(&a0->pos, &b);
                            if (d < range && fabs_asm(func_L39_0053BAB0(a0, &b)) < 2.65f &&
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
                func_L39_0053BA50(a0, &b, 1.0f);
                c = best->pos;
                func_L39_0053BA50(a0, &c, 2.0f);
                if (func_003CE740((f32 *)&b, (u8 *)&c, D_L39_0024AEB8_00538C08, (u8 *)a0, 0) == 0 || D_L39_0025F840.hit == best) {
                    Tgt_00539398 *t2;

                    a0->state |= 0x10;
                    func_L39_005F0CE0(0, 0, a0);
                    v->m54 = best;
                    v->f40 = 0.0f;
                    v->t58 = 600;
                    v->s52 = 1;
                    v->t48 = 7;
                    t2 = (Tgt_00539398 *)func_L39_0061B038(best);
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
                            ((s32 *)&ev.pos)[3] = D_001A5E50.i128;
                            ev.pos = best->pos;
                            if (D_001A5E50.i170 == 0) {
                                func_0014AD08(D_001A5E50.b7D4 | 0x40, D_001A5E50.i4, -1, D_L39_0024072C, 0x20, &ev);
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
        func_L01_004488B8(a0, &a0->pos, -1, 0.33f, 0.0f);
        if (v->i5C == -2) {
            {
                Ev_00539398 ev;

                {
                    ev.d = 0xD;
                    ev.c = (pl->i2544 << 16) | v->s7E;
                    ev.a = 0x10;
                    ev.b = 1;
                    ((s32 *)&ev.pos)[3] = D_001A5E50.i128;
                    ev.pos = a0->pos;
                    if (D_001A5E50.i170 == 0) {
                        func_0014AD08(D_001A5E50.b7D4 | 0x40, D_001A5E50.i4, -1, D_L39_0024072C, 0x20, &ev);
                    }
                }
            }
        }
        func_L01_00448C50(a0, D_L39_00294038[pl->i2544]);
        func_003BD360(a0);
        return;
    }
    if (func_003CE740((f32 *)&from, (u8 *)&a0->pos, D_L39_0024AEB8_00538C08 | 2, 0, 0)) {
        a0->bBC = 1;
        a0->pos = from;
    }
    if (a0->bBC != 0 && pl != 0) {
        vu0_v4 b;
        f32 dist = func_00388800(&a0->pos, &pl->v23A0);
{

        if (v->b50 == 0) {
            Probe_00539398 pr;
            vu0_v4 u;
            vu0_v4 s;
            vu0_v4 x;
            s32 n;
            s32 i;
{

            n = func_003CF790(&a0->pos, 0x10, 2.0f, a0, 0);
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
                func_00388830(&u, &u, 1.0f);
            } else {
                up_00539398(&u);
            }
            for (i = 0; i < n; i++) {
                vec_sub_ba(&s, &D_L39_002638C0[i]->pos, &a0->pos);
                func_00388830(&s, &s, 1.0f);
                func_00388758(&x, &s, &u);
                func_00388758(&s, &x, &u);
                func_00388830(&b, &s, 0.25f);
                func_00388830(&u, &u, 1.5f);
                vec_add_ab(&b, &b, &u);
                b.w = 5627.925f;
                func_L01_00443840(D_L39_002638C0[i], &b);
            }
        }
}
        func_L39_0053B978(a0, &b, &a0->pos);
        if (v->b50 != 0) {
            func_L39_0053BB68(a0);
        } else if (v->b51 == 0 && func_003887C8(&a0->pos, &b) > 2.0f) {
            vu0_v4 z;
{

            qzero(&z);
            func_L39_005B69C0(a0, &z, 0, 0.0f, 0.0f, 3, 3, 5, 2.0f, 1.0f, 4.0f, 1.0f, 2, 7.0f, 0, 1, -1, 0, 0x01010001);
        }
} else {
            vu0_v4 dd;
            vu0_v4 *dp = 0;
{

            if (v->s36 == -1) {
                dd = v->dir;
                func_00388830(&dd, &dd, 1.0f);
                dp = &dd;
            }
            func_L32_003B6A10(&a0->pos, 1.0f, 2.0f, 1.0f, 0, 0x7F, 1.4f, 0x30, D_L39_0024AEB0, D_L39_0024AEB4, (s32)dp);
        }
}
        a0->bBC = 0;
        func_L39_005F0CE0(2, 0, a0);
        if (pl != 0 && pl->b1A14 != 0) {
            {
                Hud_00539398 *h = D_L39_0024DF80 + pl->b24C9;

                h->f20 = dist < 8.0f ? 0.55f - dist * 0.0225f : 0.100000024f;
            }
            (D_L39_0024DF80 + pl->b24C9)->i28 = 0x41;
            (D_L39_0024DF80 + pl->b24C9)->i2C = 0;
        }
        {
            Ev_00539398 ev;

            {
                ev.d = 0xD;
                ev.c = (pl->i2544 << 16) | v->s7E;
                ev.a = 0x10;
                ev.b = 0;
                ((s32 *)&ev.pos)[3] = D_001A5E50.i128;
                ev.pos = a0->pos;
                if (D_001A5E50.i170 == 0) {
                    func_0014AD08(D_001A5E50.b7D4 | 0x40, D_001A5E50.i4, -1, D_L39_0024072C, 0x20, &ev);
                }
            }
        }
        func_L01_00448C50(a0, D_L39_00294038[pl->i2544]);
        func_003BD360(a0);
        return;
    }
}
    func_L01_00444070(a0, 0.25f);
}
/* localdecomp:end func_L39_00538C08 */
