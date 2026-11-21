#include "common.h"

/* NTSC-U counterpart of func_L16_00361998 (src/levels/16_kerwan/L16_00361998.c) */
/* localdecomp:start func_L16_00360D30 */
#include "vu0.h"

typedef struct { vu0_v4 a; vu0_v4 b; vu0_v4 c; } Ent_00361998;
typedef struct { s32 st; s32 pad4; void *f8; s32 fC; } Inf_00361998;
typedef struct Ob_00361998 {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 *f20;
    struct Ob_00361998 *f24;
    u8 pad28[0xC];
    u16 f34;
    u8 pad36[0x46 - 0x36];
    u8 f46;
    u8 pad47[0x68 - 0x47];
    u8 *f68;
    u8 pad6C[0xAA - 0x6C];
    s16 fAA;
    u8 padAC[4];
    u8 fB0;
    u8 padB1[7];
    struct Ob_00361998 *fB8;
} Ob_00361998;
typedef struct { u8 pad0[0x18]; Ob_00361998 *f18; s16 f1C; } R_00361998;
typedef struct {
    s32 f0;
    Ob_00361998 *f4;
    Ob_00361998 *f8;
    u8 pad0C[0x10];
    s32 f1C;
    u8 pad20[4];
    s32 f24;
    s32 f28;
    u8 pad2C[4];
    Ob_00361998 *f30;
    s32 f34;
    u8 pad38[0x50 - 0x38];
    Ent_00361998 ent[4];
    Inf_00361998 inf[4];
} S_00361998;
typedef struct {
    vu0_v4 v;
    u8 pad10[8];
    u8 f18;
    u8 pad19;
    u16 f1A;
    u8 pad1C[0x30 - 0x1C];
} Hit_00361998;
typedef struct { u8 pad0[0x18]; Ob_00361998 *tgt; u8 pad1C[4]; vu0_v4 pos; } H_00361998;
typedef struct { u8 pad0[0x1DC]; s16 f1DC; u8 pad1DE[0x25C0 - 0x1DE]; Ob_00361998 *hero; } G_00361998;
typedef struct { s32 a; s32 b; void *f8; s32 c; } T16_00361998;
extern H_00361998 D_L16_001E98C0_00360D30;
extern G_00361998 D_001A4BE0;
extern s32 D_001D545C;
extern s32 D_L16_001DFC40_00360D30;
extern u8 *D_L16_001E0240_00360D30;
extern u8 *D_L16_001E015C_00360D30;
extern void *D_001A71A0[];
extern u8 D_001BBC40[];
extern u8 D_001BBB18[];
extern u8 *D_L16_001E1B48_00360D30[15] __attribute__((section(".sdata")));
__asm__(".extern D_L16_001E1B48_00360D30, 4");
extern s32 D_L16_001DD788;
__asm__(".extern D_L16_001DD788, 4");
extern T16_00361998 D_L16_001DD740[] __attribute__((section(".sdata")));
__asm__(".extern D_L16_001DD740, 4");

extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388730(void *, void *);
extern f32 func_L01_00440918(f32, f32);
extern void func_L01_00443628(void *, void *, s32, f32, void *);
extern s32 func_L04_003596C0(void *, void *, void *);
extern void func_L04_00359700(void *, void *);
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
extern s32 func_003CE740(void *, void *, void *, void *, void *);
extern f32 func_L01_0040C018(void *, void *);
extern f32 func_L13_004A5468(void);
extern s32 func_003BF5E0(void *);
extern u8 *func_0037E0B8(void *);
extern void func_L01_004A72A8(s32, s32, void *, s32);
extern s32 func_L04_0035A890(void *, void *, s32);
extern void func_L01_003666A8(void *, f32);
extern void func_L01_00452F40(void *, s32);
extern void func_L16_00360D30(Ob_00361998 *, S_00361998 *, s32, s32);

static __inline__ void vcopy_00361998(void *d, void *s) {
    *(vu0_q *)d = *(vu0_q *)s;
}

void func_L16_00360D30(Ob_00361998 *obj, S_00361998 *s, s32 k, s32 flag)
{
    vu0_v4 v00, v10, v20, v30, v40, v50, v60, v70, v80;
    Hit_00361998 g90;
    Ent_00361998 *e = &s->ent[k];
    Inf_00361998 *inf = &s->inf[k];
    s32 cnt, want, res, dflag, d4;
    s32 col;
    H_00361998 *h;
    Ob_00361998 *hp, *tgt, *o2;
    R_00361998 *r2;
    u8 *b68;
    s32 i2, f2;

    vcopy_00361998(&v00, &e->b);
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
            func_L04_003596C0(D_L16_001E1B48_00360D30, &D_L16_001DD788, s->f4);
        } else {
            s->f4->f34 &= 0xBFFF;
        }
    }
    if (func_L01_00366240()) {
        func_L04_003596C0(D_L16_001E1B48_00360D30, &D_L16_001DD788, D_001A71A0[0]);
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
                        func_L01_003664D8(obj, k, *(void **)((u8 *)D_L16_001DD740 + off), e, &v60, -1);
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
                        func_L01_003664D8(obj, k, *(void **)((u8 *)D_L16_001DD740 + off), e, &v60, -1);
                    }
                    if (k != 0) k = 3; else k = 1;
                    vcopy_00361998(&s->ent[k].a, &e->a);
                    vcopy_00361998(&e->a, &v70);
                    vcopy_00361998(&e->b, &v70);
                    vcopy_00361998(&s->ent[k].b, &v00);
                    func_L16_00360D30(obj, s, k, 1);
                    func_L04_00359700(D_L16_001E1B48_00360D30, &D_L16_001DD788);
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
    d4 = 0;
    if (k == 2 || k == 3) d4 = 1;
    dflag = 0;
    vcopy_00361998(&v40, &e->a);
    vcopy_00361998(&v50, &e->b);
    for (cnt = 0; cnt < 5 && func_003CE740(&v40, &v50, 0, 0, &g90); cnt++) {
        h = &D_L16_001E98C0_00360D30;
        hp = h->tgt;
        if (hp == 0 || hp->fAA == 0x1B92) {
            vcopy_00361998(&e->b, &h->pos);
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
            vcopy_00361998(&v40, &h->pos);
            if (func_L04_003596C0(D_L16_001E1B48_00360D30, &D_L16_001DD788, hp) == 0) break;
            continue;
        }
        if (hp->fAA == 0x1BA8) {
            tgt = 0;
            func_L01_00452F40(hp, 1);
            i2 = *(s32 *)h->tgt->f68;
            if (i2 != -1) h->tgt = (Ob_00361998 *)(D_L16_001E015C_00360D30 + (i2 << 8));
            if ((s->f24 != -1 && (u8 *)h->tgt == D_L16_001E015C_00360D30 + (s->f24 << 8)) ||
                (s->f28 != -1 && (u8 *)h->tgt == D_L16_001E015C_00360D30 + (s->f28 << 8))) {
                tgt = D_L16_001E98C0_00360D30.tgt;
            }
            if (tgt == 0) {
                vcopy_00361998(&v40, &D_L16_001E98C0_00360D30.pos);
                if (func_L04_003596C0(D_L16_001E1B48_00360D30, &D_L16_001DD788, D_L16_001E98C0_00360D30.tgt) == 0) break;
                continue;
            }
            func_L04_003788A8(tgt, &v80);
            if (func_L04_00359618(e, &v80, &v80)) {
                vcopy_00361998(&e->b, &v80);
                s->f8 = tgt;
                func_L04_003791A0(tgt, obj, 1);
                inf->st = 3;
                break;
            }
            if (func_L04_003596C0(D_L16_001E1B48_00360D30, &D_L16_001DD788, tgt) == 0) break;
            continue;
        }
        if (hp->fAA == 0x1860 || hp->fAA == 0x1751) {
            tgt = 0;
            if (hp->fAA == 0x1860) {
                Ob_00361998 *o = obj->fB8;
                if (o != 0) {
                    s32 j = *(s32 *)(o->f68 + 0x13C);
                    if (j != -1) {
                        if (func_L01_0040C018(&o->pos, D_L16_001E0240_00360D30 + (j << 7) + 0x30) > 1.6899998f) {
                            vcopy_00361998(&v40, &h->pos);
                            if (func_L04_003596C0(D_L16_001E1B48_00360D30, &D_L16_001DD788, h->tgt) == 0) break;
                            continue;
                        }
                    }
                }
                if (s->f30 != 0) {
                    tgt = s->f30;
                } else if ((s->f24 != -1 && (u8 *)D_L16_001E98C0_00360D30.tgt == D_L16_001E015C_00360D30 + (s->f24 << 8)) ||
                           (s->f28 != -1 && (u8 *)D_L16_001E98C0_00360D30.tgt == D_L16_001E015C_00360D30 + (s->f28 << 8))) {
                    tgt = D_L16_001E98C0_00360D30.tgt;
                }
            } else {
                s32 j;
                b68 = hp->f68;
                j = *(s32 *)(b68 + 0x13C);
                if (j != -1) {
                    if (func_L01_0040C018(&hp->pos, D_L16_001E0240_00360D30 + (j << 7) + 0x30) > 1.6899998f) {
                            vcopy_00361998(&v40, &h->pos);
                            if (func_L04_003596C0(D_L16_001E1B48_00360D30, &D_L16_001DD788, h->tgt) == 0) break;
                            continue;
                        }
                }
                tgt = 0;
                if ((s->f24 != -1 && *(u8 **)(b68 + 0x12C) == D_L16_001E015C_00360D30 + (s->f24 << 8)) ||
                    (s->f28 != -1 && *(u8 **)(b68 + 0x12C) == D_L16_001E015C_00360D30 + (s->f28 << 8))) {
                    tgt = *(Ob_00361998 **)(b68 + 0x12C);
                }
            }
            if (tgt == 0) {
                vcopy_00361998(&v40, &D_L16_001E98C0_00360D30.pos);
                if (func_L04_003596C0(D_L16_001E1B48_00360D30, &D_L16_001DD788, D_L16_001E98C0_00360D30.tgt) == 0) break;
                continue;
            }
            func_L04_003788A8(tgt, &v80);
            if (func_L04_00359618(e, &v80, &v80)) {
                vcopy_00361998(&e->b, &v80);
                s->f8 = tgt;
                func_L04_003791A0(tgt, obj, 1);
                inf->st = 3;
                break;
            }
            if (func_L04_003596C0(D_L16_001E1B48_00360D30, &D_L16_001DD788, tgt) == 0) break;
            continue;
        }
        if (hp->fAA == 0x185F) {
            if (hp != s->f4) {
                if (func_L04_003596C0(D_L16_001E1B48_00360D30, &D_L16_001DD788, hp) == 0) break;
                if (k == 0 || k == 2) {
                    dflag = 1;
                    vcopy_00361998(&e->b, &h->pos);
                    break;
                }
            }
            if (s->f4 != 0 && (k == 0 || k == 1)) {
                inf->st = 4;
                vcopy_00361998(&e->b, &s->f4->pos);
                break;
            }
            vcopy_00361998(&v40, &D_L16_001E98C0_00360D30.pos);
            if (func_L04_003596C0(D_L16_001E1B48_00360D30, &D_L16_001DD788, D_L16_001E98C0_00360D30.tgt) == 0) break;
            continue;
        }
        if (!(hp->f34 & 0x4000)) {
            vcopy_00361998(&e->b, &h->pos);
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
                vcopy_00361998(&v40, &h->pos);
                if (func_L04_003596C0(D_L16_001E1B48_00360D30, &D_L16_001DD788, h->tgt) == 0) break;
                continue;
            }
            if (h->tgt == D_001A4BE0.hero && func_L13_004A5468() != 0.0f) {
                if (k == 0 || k == 2) {
                    dflag = 1;
                    vcopy_00361998(&e->b, &h->pos);
                    break;
                }
                vcopy_00361998(&v40, &h->pos);
                if (func_L04_003596C0(D_L16_001E1B48_00360D30, &D_L16_001DD788, h->tgt) == 0) break;
                continue;
            }
        }
        if (k == 0 || k == 2) {
            dflag = 1;
            vcopy_00361998(&e->b, &D_L16_001E98C0_00360D30.pos);
            break;
        }
        vcopy_00361998(&v40, &D_L16_001E98C0_00360D30.pos);
        if (func_L04_003596C0(D_L16_001E1B48_00360D30, &D_L16_001DD788, D_L16_001E98C0_00360D30.tgt) == 0) break;
        if (D_L16_001E98C0_00360D30.tgt == D_001A4BE0.hero) {
            if (D_001A4BE0.f1DC >= 2) continue;
        } else if (func_003BF5E0(D_L16_001E98C0_00360D30.tgt) != 0 ||
                   ((o2 = D_L16_001E98C0_00360D30.tgt->f24) != 0 && o2->f46 == 0x16)) {
            if (D_L16_001E98C0_00360D30.tgt == inf->f8 && D_L16_001DFC40_00360D30 - inf->fC < 60) continue;
        } else {
            r2 = (R_00361998 *)func_0037E0B8(D_L16_001E98C0_00360D30.tgt);
            if (r2 == 0) {
                if (D_L16_001E98C0_00360D30.tgt == inf->f8 && D_L16_001DFC40_00360D30 - inf->fC < 60) continue;
            } else {
                if (r2->f18 == obj && r2->f1C < 0x3B) continue;
            }
        }
        inf->f8 = D_L16_001E98C0_00360D30.tgt;
        inf->fC = D_L16_001DFC40_00360D30;
        func_L01_004A72A8(2, 0, D_L16_001E98C0_00360D30.tgt, 0x1937);
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
                Ob_00361998 *t = D_L16_001E98C0_00360D30.tgt;
                if (t == 0 || !((t->f34 & 0x4000) || t->fAA == 0x1BA8 || t->fAA == 0x1860 || t->fAA == 0x185F)) {
                    f2 = 0;
                } else {
                    vec_add_ba(&s->ent[k].a, &s->ent[k].a, &e->b);
                }
            } else {
                vec_add_ba(&s->ent[k].a, &s->ent[k].a, &v70);
            }
            if (f2) {
                vcopy_00361998(&s->ent[k].b, &v00);
                func_L16_00360D30(obj, s, k, flag);
            } else {
                vcopy_00361998(&s->ent[k].b, &s->ent[k].a);
            }
        }
    }
    func_L04_00359700(D_L16_001E1B48_00360D30, &D_L16_001DD788);
    if (s->f4 != 0 && k != 2 && k != 3) {
        s->f4->f34 |= 0x4000;
    }
    func_L01_003F15F0(0);
}
/* localdecomp:end func_L16_00360D30 */
