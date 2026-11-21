#include "common.h"

/* NTSC-U counterpart of func_L22_00351D20 (src/levels/22_mylon/L22_00351D20.c) */
/* localdecomp:start func_L22_00351208 */
#include "vu0.h"

typedef struct { vu0_v4 a; vu0_v4 b; vu0_v4 c; } Ent_00351D20;
typedef struct { s32 st; s32 pad4; void *f8; s32 fC; } Inf_00351D20;
typedef struct Ob_00351D20 {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 *f20;
    u8 *f24;
    u8 pad28[0xC];
    u16 f34;
    u8 pad36[0x68 - 0x36];
    u8 *f68;
    u8 pad6C[0xAA - 0x6C];
    s16 fAA;
    u8 padAC[4];
    u8 fB0;
    u8 padB1[7];
    struct Ob_00351D20 *fB8;
} Ob_00351D20;
typedef struct { u8 pad0[0x18]; Ob_00351D20 *f18; s16 f1C; } R_00351D20;
typedef struct {
    s32 f0;
    Ob_00351D20 *f4;
    Ob_00351D20 *f8;
    u8 pad0C[0x10];
    s32 f1C;
    u8 pad20[4];
    s32 f24;
    s32 f28;
    u8 pad2C[4];
    Ob_00351D20 *f30;
    s32 f34;
    u8 pad38[0x50 - 0x38];
    Ent_00351D20 ent[4];
    Inf_00351D20 inf[4];
} S_00351D20;
typedef struct {
    vu0_v4 v;
    u8 pad10[8];
    u8 f18;
    u8 pad19;
    u16 f1A;
    u8 pad1C[0x30 - 0x1C];
} Hit_00351D20;
typedef struct { u8 pad0[0x18]; Ob_00351D20 *tgt; u8 pad1C[4]; vu0_v4 pos; } H_00351D20;
typedef struct { u8 pad0[0x1DC]; s16 f1DC; u8 pad1DE[0x25C0 - 0x1DE]; Ob_00351D20 *hero; } G_00351D20;

extern H_00351D20 D_L22_001E9840_00351208;
extern G_00351D20 D_001A4BE0;
extern s32 D_001D545C;
extern s32 D_L22_001DF8C0_00351208;
extern u8 *D_L22_001DFE80_00351208;
extern u8 *D_L22_001DFD9C_00351208;
extern Ob_00351D20 *D_001A71A0[];
extern u8 D_001BBC40[];
extern u8 D_001BBB18[];
__asm__(".extern D_L22_001E1810_00351208, 4");
extern u8 *D_L22_001E1810_00351208[] __attribute__((section(".sdata")));
__asm__(".extern D_L22_001DD448, 4");
extern s32 D_L22_001DD448;
__asm__(".extern D_L22_001DD400, 4");
extern void *D_L22_001DD400[] __attribute__((section(".sdata")));

extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388730(void *, void *);
extern f32 func_L01_00440918(f32, f32);
extern void func_L01_00443628(void *, void *, s32, f32, void *);
extern s32 func_L04_003596C0(u8 **, s32 *, void *);
extern void func_L04_00359700(u8 **, s32 *);
extern void func_L04_00359588(void *, void *);
extern s32 func_L04_00359618(void *, void *, void *);
extern s32 func_L01_00366240(void);
extern void func_L01_003F15C8(s32);
extern void func_L01_003F15F0(s32);
extern s32 func_L01_003662F8(void *, void *, void *, void *);
extern void func_L01_003664D8(void *, s32, void *, void *, void *, s32);
extern void func_L04_003791A0(void *, void *, s32);
extern void func_L04_003788A8(void *, void *);
extern void func_L04_003782C8(void *);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern f32 func_L01_0040C018(void *, void *);
extern f32 func_L13_004A5468(void);
extern s32 func_003BF5E0(void *);
extern R_00351D20 *func_0037E0B8(void *);
extern s32 func_L01_004A72A8(s32, s32, void *, s32);
extern s32 func_L04_0035A890(void *, void *, s32);
extern void func_L01_003666A8(void *, f32);
extern void func_L01_00452F40(void *, s32);

static __inline__ void qcopy_00351D20(void *d, void *src) { *(vu0_q *)d = *(vu0_q *)src; }

void func_L22_00351208(Ob_00351D20 *obj, S_00351D20 *s, s32 k, s32 flag)
{
    vu0_v4 v00, v10, v20, v30, v40, v50, v60, v70, v80;
    Hit_00351D20 g90;
    Ent_00351D20 *e = &s->ent[k];
    Inf_00351D20 *inf = &s->inf[k];
    H_00351D20 *h;
    s32 cnt, want, res, dflag, d4;
    s32 col;
    Ob_00351D20 *hp, *o2;
    R_00351D20 *r2;
    u8 *b68;
    u8 *u2;
    s32 i2, f2;

    qcopy_00351D20(&v00, &e->b);
    vec_sub_ba(&v10, &e->b, &e->a);
    func_00388830(&v10, &v10, 1.0f);
    col = 0x110001;
    if (k == 2 || k == 3) col += 0x100000;
    qzero(&v20);
    v20.z = 1.0f;
    func_00388758(&v30, &v10, &v20);
    func_003886E8(&v30, &v30, func_L01_00440918(0.5f, 1.0f));
    if (D_001D545C == 0x10) {
        func_L01_00443628(&g90, obj, col, 50.0f, &v30);
    } else {
        func_L01_00443628(&g90, obj, col, 1.0f, &v30);
    }
    g90.f18 = 9;
    g90.f1A = obj->fAA;
    if (s->f4 != 0) {
        if (k == 2 || k == 3) {
            func_L04_003596C0(D_L22_001E1810_00351208, &D_L22_001DD448, s->f4);
        } else {
            s->f4->f34 &= 0xBFFF;
        }
    }
    if (func_L01_00366240()) {
        func_L04_003596C0(D_L22_001E1810_00351208, &D_L22_001DD448, D_001A71A0[0]);
    }
    want = 0;
    func_L01_003F15C8(0);
    res = 0;
    inf->st = 0;
    func_L04_00359588(e, inf);
    if (flag == 0) {
        switch (k) {
        case 1:
        case 3:
            res = func_L01_003662F8(e, &e->b, &v60, &v70);
            if (res != 0) {
                if (res == 2) {
                    s->f0 = 1;
                    {
                        s32 off = k * 16 + 8;
                        func_L01_003664D8(obj, k, *(void **)((u8 *)D_L22_001DD400 + off), e, &v60, -1);
                    }
                } else {
                    want = 1;
                }
            }
            break;
        case 0:
        case 2:
            res = func_L01_003662F8(e, &e->b, &v60, &v70);
            if (res != 0) {
                if (res == 2) {
                    s->f0 = 1;
                    {
                        s32 off = k * 16 + 8;
                        func_L01_003664D8(obj, k, *(void **)((u8 *)D_L22_001DD400 + off), e, &v60, -1);
                    }
                    if (k != 0) k = 3; else k = 1;
                    qcopy_00351D20(&s->ent[k].a, &e->a);
                    qcopy_00351D20(&e->a, &v70);
                    qcopy_00351D20(&e->b, &v70);
                    qcopy_00351D20(&s->ent[k].b, &v00);
                    func_L22_00351208(obj, s, k, 1);
                    func_L04_00359700(D_L22_001E1810_00351208, &D_L22_001DD448);
                    if (s->f4 != 0 && k != 2 && k != 3) {
                        s->f4->f34 |= 0x4000;
                    }
                    func_L01_003F15F0(0);
                    return;
                }
                want = 1;
                func_003886E8(&e->b, &v10, 0.01f);
                vec_add_ab(&e->b, &e->b, &v60);
                if (k == 0) inf->st = 5; else inf->st = 6;
                if (res & 2) flag = 1;
            }
            break;
        }
    }
    dflag = 0;
    d4 = 0;
    if (k == 2 || k == 3) d4 = 1;
    qcopy_00351D20(&v40, &e->a);
    qcopy_00351D20(&v50, &e->b);
    for (cnt = 0; cnt < 5 && func_003CE740(&v40, &v50, 0, 0, &g90); cnt++) {
        h = &D_L22_001E9840_00351208;
        hp = h->tgt;
        if (hp == 0 || hp->fAA == 0x1B92) {
            qcopy_00351D20(&e->b, &h->pos);
            inf->st = 1;
            if (s->f4 != 0 && d4) {
                if (s->f1C != 0) {
                    if (obj->fB0 != 0xFF) {
                        if (D_001BBC40[obj->fB0 + (D_001D545C << 4)] & 0x80) break;
                    }
                    if (s->f34 != -1) {
                        if (D_001BBB18[s->f34 + (D_001D545C << 3)] != 0) break;
                    }
                }
                func_L04_003782C8(s->f4);
            }
            break;
        }
        if (hp->fAA == 0x192F || hp->fAA == 0x1930) {
            qcopy_00351D20(&v40, &h->pos);
            if (func_L04_003596C0(D_L22_001E1810_00351208, &D_L22_001DD448, hp) == 0) break;
            continue;
        }
        if (hp->fAA == 0x1BA8) {
            Ob_00351D20 *t1;
            t1 = 0;
            func_L01_00452F40(hp, 1);
            i2 = *(s32 *)h->tgt->f68;
            if (i2 != -1) h->tgt = (Ob_00351D20 *)(D_L22_001DFD9C_00351208 + (i2 << 8));
            if ((s->f24 != -1 && (u8 *)h->tgt == D_L22_001DFD9C_00351208 + (s->f24 << 8)) ||
                (s->f28 != -1 && (u8 *)h->tgt == D_L22_001DFD9C_00351208 + (s->f28 << 8))) {
                t1 = D_L22_001E9840_00351208.tgt;
            }
            if (t1 == 0) {
                qcopy_00351D20(&v40, &D_L22_001E9840_00351208.pos);
                if (func_L04_003596C0(D_L22_001E1810_00351208, &D_L22_001DD448, D_L22_001E9840_00351208.tgt) == 0) break;
                continue;
            }
            func_L04_003788A8(t1, &v80);
            if (func_L04_00359618(e, &v80, &v80)) {
                qcopy_00351D20(&e->b, &v80);
                s->f8 = t1;
                func_L04_003791A0(t1, obj, 1);
                inf->st = 3;
                break;
            }
            if (func_L04_003596C0(D_L22_001E1810_00351208, &D_L22_001DD448, t1) == 0) break;
            continue;
        }
        if (hp->fAA == 0x1860 || hp->fAA == 0x1751) {
            Ob_00351D20 *t2;
            s32 n2;
            t2 = 0;
            if (hp->fAA == 0x1860) {
                o2 = obj->fB8;
                if (o2 != 0 && (n2 = *(s32 *)(o2->f68 + 0x13C)) != -1 &&
                    func_L01_0040C018(&o2->pos, D_L22_001DFE80_00351208 + (n2 << 7) + 0x30) > 1.6899998f) {
                    qcopy_00351D20(&v40, &h->pos);
                    if (func_L04_003596C0(D_L22_001E1810_00351208, &D_L22_001DD448, h->tgt) == 0) break;
                    continue;
                }
                if (s->f30 != 0) {
                    t2 = s->f30;
                } else if ((s->f24 != -1 && (u8 *)D_L22_001E9840_00351208.tgt == D_L22_001DFD9C_00351208 + (s->f24 << 8)) ||
                           (s->f28 != -1 && (u8 *)D_L22_001E9840_00351208.tgt == D_L22_001DFD9C_00351208 + (s->f28 << 8))) {
                    t2 = D_L22_001E9840_00351208.tgt;
                }
            } else {
                b68 = hp->f68;
                n2 = *(s32 *)(b68 + 0x13C);
                if (n2 != -1 && func_L01_0040C018(&hp->pos, D_L22_001DFE80_00351208 + (n2 << 7) + 0x30) > 1.6899998f) {
                    qcopy_00351D20(&v40, &h->pos);
                    if (func_L04_003596C0(D_L22_001E1810_00351208, &D_L22_001DD448, h->tgt) == 0) break;
                    continue;
                }
                t2 = 0;
                if ((s->f24 != -1 && *(u8 **)(b68 + 0x12C) == D_L22_001DFD9C_00351208 + (s->f24 << 8)) ||
                    (s->f28 != -1 && *(u8 **)(b68 + 0x12C) == D_L22_001DFD9C_00351208 + (s->f28 << 8))) {
                    t2 = *(Ob_00351D20 **)(b68 + 0x12C);
                }
            }
            if (t2 == 0) {
                qcopy_00351D20(&v40, &D_L22_001E9840_00351208.pos);
                if (func_L04_003596C0(D_L22_001E1810_00351208, &D_L22_001DD448, D_L22_001E9840_00351208.tgt) == 0) break;
                continue;
            }
            func_L04_003788A8(t2, &v80);
            if (func_L04_00359618(e, &v80, &v80)) {
                qcopy_00351D20(&e->b, &v80);
                s->f8 = t2;
                func_L04_003791A0(t2, obj, 1);
                inf->st = 3;
                break;
            }
            if (func_L04_003596C0(D_L22_001E1810_00351208, &D_L22_001DD448, t2) == 0) break;
            continue;
        }
        if (hp->fAA == 0x185F) {
            if (hp != s->f4) {
                if (func_L04_003596C0(D_L22_001E1810_00351208, &D_L22_001DD448, hp) == 0) break;
                if (k == 0 || k == 2) {
                    dflag = 1;
                    qcopy_00351D20(&e->b, &h->pos);
                    break;
                }
            }
            if (s->f4 != 0 && (k == 0 || k == 1)) {
                inf->st = 4;
                qcopy_00351D20(&e->b, &s->f4->pos);
                break;
            }
            qcopy_00351D20(&v40, &D_L22_001E9840_00351208.pos);
            if (func_L04_003596C0(D_L22_001E1810_00351208, &D_L22_001DD448, D_L22_001E9840_00351208.tgt) == 0) break;
            continue;
        }
        if (!(hp->f34 & 0x4000)) {
            qcopy_00351D20(&e->b, &h->pos);
            inf->st = 1;
            if (s->f4 != 0 && d4) {
                if (s->f1C != 0) {
                    if (obj->fB0 != 0xFF) {
                        if (D_001BBC40[obj->fB0 + (D_001D545C << 4)] & 0x80) break;
                    }
                    if (s->f34 != -1) {
                        if (D_001BBB18[s->f34 + (D_001D545C << 3)] != 0) break;
                    }
                }
                func_L04_003782C8(s->f4);
            }
            break;
        }
        if (hp == D_001A4BE0.hero) {
            if (func_L01_00366240()) {
                qcopy_00351D20(&v40, &h->pos);
                if (func_L04_003596C0(D_L22_001E1810_00351208, &D_L22_001DD448, h->tgt) == 0) break;
                continue;
            }
            if (h->tgt == D_001A4BE0.hero) {
                if (func_L13_004A5468() != 0.0f) {
                    if (k == 0 || k == 2) {
                        dflag = 1;
                        qcopy_00351D20(&e->b, &h->pos);
                        break;
                    }
                    qcopy_00351D20(&v40, &h->pos);
                    if (func_L04_003596C0(D_L22_001E1810_00351208, &D_L22_001DD448, h->tgt) == 0) break;
                    continue;
                }
            }
        }
        if (k == 0 || k == 2) {
            dflag = 1;
            qcopy_00351D20(&e->b, &D_L22_001E9840_00351208.pos);
            break;
        }
        qcopy_00351D20(&v40, &D_L22_001E9840_00351208.pos);
        if (func_L04_003596C0(D_L22_001E1810_00351208, &D_L22_001DD448, D_L22_001E9840_00351208.tgt) == 0) break;
        if (D_L22_001E9840_00351208.tgt == D_001A4BE0.hero) {
            if (D_001A4BE0.f1DC >= 2) continue;
        } else if (func_003BF5E0(D_L22_001E9840_00351208.tgt) != 0 || ((u2 = D_L22_001E9840_00351208.tgt->f24) != 0 && u2[0x46] == 0x16)) {
            if (D_L22_001E9840_00351208.tgt == inf->f8 && D_L22_001DF8C0_00351208 - inf->fC < 60) continue;
        } else {
            r2 = func_0037E0B8(D_L22_001E9840_00351208.tgt);
            if (r2 == 0) {
                if (D_L22_001E9840_00351208.tgt == inf->f8 && D_L22_001DF8C0_00351208 - inf->fC < 60) continue;
            } else {
                if (r2->f18 == obj && r2->f1C < 0x3B) continue;
            }
        }
        inf->f8 = D_L22_001E9840_00351208.tgt;
        inf->fC = D_L22_001DF8C0_00351208;
        func_L01_004A72A8(2, 0, D_L22_001E9840_00351208.tgt, 0x1937);
    }
    if (want) {
        switch (k) {
        case 1:
        case 3: {
            f32 a = func_00388730(&v10, &e->b);
            if (a < func_00388730(&v10, &v60) + 0.01f) want = 0;
            break;
        }
        case 0:
        case 2:
            if (inf->st != 5 && inf->st != 6) want = 0;
            break;
        }
        if (want != 0 && k == 0) {
            if (func_L04_0035A890(obj, s, 1)) {
                if (D_001D545C == 0x10) {
                    func_L01_003666A8(obj, 50.0f);
                } else {
                    func_L01_003666A8(obj, 2.0f);
                }
            }
        }
    }
    if (inf->st == 5 || inf->st == 6 || dflag) {
        if ((res & 2) || dflag) {
            f2 = 1;
            if (k == 0) k = 1; else k = 3;
            func_003886E8(&s->ent[k], &v10, -0.01f);
            if (dflag != 0 || func_003CE740(&e->b, &v70, 0, D_001A71A0[0], 0) != 0) {
                Ob_00351D20 *m = D_L22_001E9840_00351208.tgt;
                if (m == 0 || !((m->f34 & 0x4000) || m->fAA == 0x1BA8 || m->fAA == 0x1860 || m->fAA == 0x185F)) {
                    f2 = 0;
                } else {
                    vec_add_ba(&s->ent[k].a, &s->ent[k].a, &e->b);
                }
            } else {
                vec_add_ba(&s->ent[k].a, &s->ent[k].a, &v70);
            }
            if (f2) {
                qcopy_00351D20(&s->ent[k].b, &v00);
                func_L22_00351208(obj, s, k, flag);
            } else {
                qcopy_00351D20(&s->ent[k].b, &s->ent[k].a);
            }
        }
    }
    func_L04_00359700(D_L22_001E1810_00351208, &D_L22_001DD448);
    if (s->f4 != 0 && k != 2 && k != 3) {
        s->f4->f34 |= 0x4000;
    }
    func_L01_003F15F0(0);
}
/* localdecomp:end func_L22_00351208 */
