/* near miss (level 11, Obani Moons): func_L11_0034C8A0, 0xD50 bytes (852 words), 667 diff
 * positional, this C 822 words; checked with --as ps2as --flags=-mvu0-use-vf0-vf2 (the owning
 * file L11_0034C8A0.c would need both). The control flow is retail's (switch on k: 1,3 / 0,2,
 * the 5-pass loop with per-type branches 0x1BA8/0x1860/0x1751/0x185F/0x4000, the doubled
 * tail with the early return) and the $gp/lui scalar forms match. Left: register allocation and
 * loop.c hoisting: retail keeps &g90 in $s0, &v80 in $fp and &D_L11_001E84C0 in $s1, has six
 * spill slots and a 0x140 frame; gcc hoists loop-invariant entry addresses and spills more.
 * -fno-sched-interblock changes nothing here (the loop is 448 insns). VU0 through
 * include/vu0.h only. */
#include "common.h"
#include "vu0.h"

typedef struct { vu0_v4 a; vu0_v4 b; vu0_v4 c; } Ent_34C8A0;
typedef struct { s32 st; s32 pad4; void *f8; s32 fC; } Inf_34C8A0;
typedef struct Ob_34C8A0 {
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
    struct Ob_34C8A0 *fB8;
} Ob_34C8A0;
typedef struct { u8 pad0[0x18]; struct Ob_34C8A0 *f18; s16 f1C; } R_34C8A0;
typedef struct {
    s32 f0;
    Ob_34C8A0 *f4;
    Ob_34C8A0 *f8;
    u8 pad0C[0x10];
    s32 f1C;
    u8 pad20[4];
    s32 f24;
    s32 f28;
    u8 pad2C[4];
    Ob_34C8A0 *f30;
    s32 f34;
    u8 pad38[0x50 - 0x38];
    Ent_34C8A0 ent[4];
    Inf_34C8A0 inf[4];
} S_34C8A0;
typedef struct {
    vu0_v4 v;
    u8 pad10[8];
    u8 f18;
    u8 pad19;
    u16 f1A;
    u8 pad1C[0x30 - 0x1C];
} Hit_34C8A0;
typedef struct { u8 pad0[0x18]; Ob_34C8A0 *tgt; u8 pad1C[4]; vu0_v4 pos; } H_34C8A0;
typedef struct { u8 pad0[0x1DC]; s16 f1DC; u8 pad1DE[0x25C0 - 0x1DE]; Ob_34C8A0 *hero; } G_34C8A0;
typedef struct { s32 a; s32 b; void *f8; s32 c; } T16_34C8A0;
extern H_34C8A0 D_L11_001E84C0;
extern G_34C8A0 D_001A4BE0;
extern s32 D_001D545C;
extern s32 D_L11_001DE940;
extern u8 *D_L11_001DEF00;
extern u8 *D_L11_001DEE1C;
extern void *D_001A71A0[];
extern u8 D_001BBC40[];
extern u8 D_001BBB18[];
__asm__(".extern D_L11_001E0808, 4");
extern u8 D_L11_001E0808[8];
__asm__(".extern D_L11_001DD320, 4");
extern u8 D_L11_001DD320[8];
extern T16_34C8A0 D_L11_001DD2D8_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_L11_001DD2D8_sda, 4");

extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_L04_0035A660(void *, void *, void *);
extern void func_L04_0035A6A0(void *, void *);
extern void func_L04_0035A528(void *, void *);
extern s32 func_L04_0035A5B8(void *, void *, void *);
extern s32 func_L01_00366FC8(void);
extern void func_L01_003F3740(s32);
extern void func_L01_003F3768(s32);
extern s32 func_L01_00367080(void *, void *, void *, void *);
extern void func_L01_00367260(void *, s32, void *, void *, void *, s32);
extern void func_L04_0037A5B8(void *, void *, s32);
extern void func_L04_00379CC0(void *, void *);
extern void func_L04_003796C8(void *);
extern s32 func_003D3CB0(void *, void *, void *, void *, void *);
extern f32 func_L01_0040E548(void *, void *);
extern f32 func_L01_004C93D8(void);
extern s32 func_003C4B50(void);
extern u8 *func_00382348(void *);
extern void func_L01_004AAC98(s32, s32, void *, s32);
extern s32 func_L04_0035B838(void *, void *, s32);
extern void func_L01_00367430(void *, f32);
extern void func_L01_00456230(void *, s32);
extern void func_L11_0034C8A0(Ob_34C8A0 *, S_34C8A0 *, s32, s32);



void func_L11_0034C8A0(Ob_34C8A0 *obj, S_34C8A0 *s, s32 k, s32 flag)
{
    vu0_v4 v00, v10, v20, v30, v40, v50, v60, v70, v80;
    Hit_34C8A0 g90;
    Ent_34C8A0 *e = &s->ent[k];
    Inf_34C8A0 *inf = &s->inf[k];
    s32 cnt, want, res, dflag, d4;
    s32 col;
    Ob_34C8A0 *hp, *tgt, *o2;
    R_34C8A0 *r2;
    u8 *b68;
    s32 i2, tm, f2;

    *(vu0_q *)&v00 = *(vu0_q *)&e->b;
    vec_sub_ba(&v10, &e->b, &e->a);
    func_0038CF68(&v10, &v10, 1.0f);
    col = 0x110001;
    if (k == 2 || k == 3) col += 0x100000;
    qzero(&v20);
    v20.z = 1.0f;
    func_0038CE90(&v30, &v10, &v20);
    func_0038CE20(&v30, &v30, func_L01_00443A18(0.5f, 1.0f));
    if (D_001D545C == 0x10) {
        func_L01_00446760(&g90, obj, col, &v30, 50.0f);
    } else {
        func_L01_00446760(&g90, obj, col, &v30, 1.0f);
    }
    g90.f18 = 9;
    g90.f1A = obj->fAA;
    if (s->f4 != 0) {
        if (k == 2 || k == 3) {
            func_L04_0035A660(D_L11_001E0808, D_L11_001DD320, s->f4);
        } else {
            s->f4->f34 &= 0xBFFF;
        }
    }
    if (func_L01_00366FC8()) {
        func_L04_0035A660(D_L11_001E0808, D_L11_001DD320, D_001A71A0[0]);
    }
    want = 0;
    func_L01_003F3740(0);
    res = 0;
    inf->st = 0;
    func_L04_0035A528(e, inf);
    if (flag == 0) {
        switch (k) {
        case 1:
        case 3:
            res = func_L01_00367080(e, &e->b, &v60, &v70);
            if (res != 0) {
                if (res == 2) {
                    s->f0 = 1;
                    {
                        s32 off = k * 16 + 8;
                        func_L01_00367260(obj, k, *(void **)((u8 *)D_L11_001DD2D8_sda + off), e, &v60, -1);
                    }
                } else {
                    want = 1;
                }
            }
            break;
        case 0:
        case 2:
            res = func_L01_00367080(e, &e->b, &v60, &v70);
            if (res != 0) {
                if (res == 2) {
                    s->f0 = 1;
                    {
                        s32 off = k * 16 + 8;
                        func_L01_00367260(obj, k, *(void **)((u8 *)D_L11_001DD2D8_sda + off), e, &v60, -1);
                    }
                    if (k != 0) k = 3; else k = 1;
                    *(vu0_q *)&s->ent[k].a = *(vu0_q *)&e->a;
                    *(vu0_q *)&e->b = *(vu0_q *)&v70;
                    *(vu0_q *)&e->a = *(vu0_q *)&v70;
                    *(vu0_q *)&s->ent[k].b = *(vu0_q *)&v00;
                    func_L11_0034C8A0(obj, s, k, 1);
                    func_L04_0035A6A0(D_L11_001E0808, D_L11_001DD320);
                    if (s->f4 != 0 && k != 2 && k != 3) {
                        s->f4->f34 |= 0x4000;
                    }
                    func_L01_003F3768(0);
                    return;
                }
                want = 1;
                func_0038CE20(&e->b, &v10, 0.01f);
                vec_add_ab(&e->b, &e->b, &v60);
                if (k != 0) inf->st = 6; else inf->st = 5;
                if (res & 2) flag = 1;
            }
            break;
        }
    }
    dflag = 0;
    d4 = (k == 2 || k == 3);
    *(vu0_q *)&v40 = *(vu0_q *)&e->a;
    *(vu0_q *)&v50 = *(vu0_q *)&e->b;
    for (cnt = 0; cnt < 5 && func_003D3CB0(&v40, &v50, 0, 0, &g90); cnt++) {
        hp = D_L11_001E84C0.tgt;
        if (hp == 0 || hp->fAA == 0x1B92) {
            *(vu0_q *)&e->b = *(vu0_q *)&D_L11_001E84C0.pos;
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
                func_L04_003796C8(s->f4);
            }
            break;
        }
        if (hp->fAA == 0x192F || hp->fAA == 0x1930 || hp->fAA == 0x1A77) {
            *(vu0_q *)&v40 = *(vu0_q *)&D_L11_001E84C0.pos;
            if (func_L04_0035A660(D_L11_001E0808, D_L11_001DD320, hp) == 0) break;
            continue;
        }
        if (hp->fAA == 0x1BA8) {
            tgt = 0;
            func_L01_00456230(hp, 1);
            i2 = *(s32 *)D_L11_001E84C0.tgt->f68;
            if (i2 != -1) D_L11_001E84C0.tgt = (Ob_34C8A0 *)(D_L11_001DEE1C + (i2 << 8));
            if ((s->f24 != -1 && (u8 *)D_L11_001E84C0.tgt == D_L11_001DEE1C + (s->f24 << 8)) ||
                (s->f28 != -1 && (u8 *)D_L11_001E84C0.tgt == D_L11_001DEE1C + (s->f28 << 8))) {
                tgt = D_L11_001E84C0.tgt;
            }
            if (tgt == 0) {
                *(vu0_q *)&v40 = *(vu0_q *)&D_L11_001E84C0.pos;
                if (func_L04_0035A660(D_L11_001E0808, D_L11_001DD320, D_L11_001E84C0.tgt) == 0) break;
                continue;
            }
            func_L04_00379CC0(tgt, &v80);
            if (func_L04_0035A5B8(e, &v80, &v80)) {
                *(vu0_q *)&e->b = *(vu0_q *)&v80;
                s->f8 = tgt;
                func_L04_0037A5B8(tgt, obj, 1);
                inf->st = 3;
                break;
            }
            if (func_L04_0035A660(D_L11_001E0808, D_L11_001DD320, tgt) == 0) break;
            continue;
        }
        if (hp->fAA == 0x1860 || hp->fAA == 0x1751) {
            tgt = 0;
            if (hp->fAA == 0x1860) {
                o2 = obj->fB8;
                if (o2 != 0) {
                    i2 = *(s32 *)(o2->f68 + 0x13C);
                    if (i2 != -1) {
                        if (func_L01_0040E548(&o2->pos, D_L11_001DEF00 + (i2 << 7) + 0x30) > 1.6899998f) goto go154;
                    }
                }
                if (s->f30 != 0) {
                    tgt = s->f30;
                } else if ((s->f24 != -1 && (u8 *)D_L11_001E84C0.tgt == D_L11_001DEE1C + (s->f24 << 8)) ||
                           (s->f28 != -1 && (u8 *)D_L11_001E84C0.tgt == D_L11_001DEE1C + (s->f28 << 8))) {
                    tgt = D_L11_001E84C0.tgt;
                }
            } else {
                b68 = hp->f68;
                i2 = *(s32 *)(b68 + 0x13C);
                if (i2 != -1) {
                    if (func_L01_0040E548(&hp->pos, D_L11_001DEF00 + (i2 << 7) + 0x30) > 1.6899998f) goto go154;
                }
                tgt = 0;
                if (s->f24 != -1 && *(u8 **)(b68 + 0x12C) == D_L11_001DEE1C + (s->f24 << 8)) {
                    tgt = *(Ob_34C8A0 **)(b68 + 0x12C);
                } else if (s->f28 != -1 && *(u8 **)(b68 + 0x12C) == D_L11_001DEE1C + (s->f28 << 8)) {
                    tgt = *(Ob_34C8A0 **)(b68 + 0x12C);
                }
            }
            if (tgt == 0) {
                *(vu0_q *)&v40 = *(vu0_q *)&D_L11_001E84C0.pos;
                if (func_L04_0035A660(D_L11_001E0808, D_L11_001DD320, D_L11_001E84C0.tgt) == 0) break;
                continue;
            }
            func_L04_00379CC0(tgt, &v80);
            if (func_L04_0035A5B8(e, &v80, &v80)) {
                *(vu0_q *)&e->b = *(vu0_q *)&v80;
                s->f8 = tgt;
                func_L04_0037A5B8(tgt, obj, 1);
                inf->st = 3;
                break;
            }
            if (func_L04_0035A660(D_L11_001E0808, D_L11_001DD320, tgt) == 0) break;
            continue;
        }
        if (hp->fAA == 0x185F) {
            if (hp != s->f4) {
                if (func_L04_0035A660(D_L11_001E0808, D_L11_001DD320, hp) == 0) break;
                if (k == 0 || k == 2) {
                    dflag = 1;
                    *(vu0_q *)&e->b = *(vu0_q *)&D_L11_001E84C0.pos;
                    break;
                }
            }
            if (s->f4 != 0 && (k == 0 || k == 1)) {
                inf->st = 4;
                *(vu0_q *)&e->b = *(vu0_q *)&s->f4->pos;
                break;
            }
            *(vu0_q *)&v40 = *(vu0_q *)&D_L11_001E84C0.pos;
            if (func_L04_0035A660(D_L11_001E0808, D_L11_001DD320, D_L11_001E84C0.tgt) == 0) break;
            continue;
        }
        if (!(hp->f34 & 0x4000)) {
            *(vu0_q *)&e->b = *(vu0_q *)&D_L11_001E84C0.pos;
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
                func_L04_003796C8(s->f4);
            }
            break;
        }
        if (hp == D_001A4BE0.hero) {
            if (func_L01_00366FC8()) goto go154;
            if (D_L11_001E84C0.tgt == D_001A4BE0.hero) {
                if (func_L01_004C93D8() != 0.0f) {
                    if (k == 0 || k == 2) {
                        dflag = 1;
                        *(vu0_q *)&e->b = *(vu0_q *)&D_L11_001E84C0.pos;
                        break;
                    }
                go154:
                    *(vu0_q *)&v40 = *(vu0_q *)&D_L11_001E84C0.pos;
                    if (func_L04_0035A660(D_L11_001E0808, D_L11_001DD320, D_L11_001E84C0.tgt) == 0) break;
                    continue;
                }
            }
        }
        if (k == 0 || k == 2) {
            dflag = 1;
            *(vu0_q *)&e->b = *(vu0_q *)&D_L11_001E84C0.pos;
            break;
        }
        *(vu0_q *)&v40 = *(vu0_q *)&D_L11_001E84C0.pos;
        if (func_L04_0035A660(D_L11_001E0808, D_L11_001DD320, D_L11_001E84C0.tgt) == 0) break;
        if (D_L11_001E84C0.tgt == D_001A4BE0.hero) {
            if (D_001A4BE0.f1DC < 2) {
                tm = D_L11_001DE940;
                goto stamp;
            }
            continue;
        }
        if (func_003C4B50() == 0) {
            o2 = (Ob_34C8A0 *)D_L11_001E84C0.tgt->f24;
            if (o2 == 0 || *(u8 *)((u8 *)o2 + 0x46) != 0x16) {
                r2 = (R_34C8A0 *)func_00382348(D_L11_001E84C0.tgt);
                if (r2 != 0) {
                    if (r2->f18 == obj && r2->f1C < 0x31) continue;
                } else {
                    if (D_L11_001E84C0.tgt == inf->f8 && D_L11_001DE940 - inf->fC < 50) continue;
                }
                goto stamp_now;
            }
        }
        if (D_L11_001E84C0.tgt == inf->f8 && D_L11_001DE940 - inf->fC < 50) continue;
    stamp_now:
        tm = D_L11_001DE940;
    stamp:
        inf->f8 = D_L11_001E84C0.tgt;
        inf->fC = tm;
        func_L01_004AAC98(2, 0, D_L11_001E84C0.tgt, 0x1937);
    }
    if (want) {
        switch (k) {
        case 1:
        case 3: {
            f32 a = func_0038CE68(&v10, &e->b);
            if (a < func_0038CE68(&v10, &v60) + 0.01f) want = 0;
            break;
        }
        case 0:
        case 2:
            if (inf->st != 5 && inf->st != 6) want = 0;
            break;
        }
        if (want != 0 && k == 0) {
            if (func_L04_0035B838(obj, s, 1)) {
                if (D_001D545C == 0x10) {
                    func_L01_00367430(obj, 50.0f);
                } else {
                    func_L01_00367430(obj, 2.0f);
                }
            }
        }
    }
    if ((inf->st == 5 || inf->st == 6 || dflag) && ((res & 2) || dflag)) {
        f2 = 1;
        if (k != 0) k = 3; else k = 1;
        func_0038CE20(&s->ent[k], &v10, -0.01f);
        if (dflag == 0 && func_003D3CB0(&e->b, &v70, 0, D_001A71A0[0], 0) == 0) {
            vec_add_ba(&s->ent[k].a, &s->ent[k].a, &v70);
        } else {
            hp = D_L11_001E84C0.tgt;
            if (hp == 0) {
                f2 = 0;
            } else if ((hp->f34 & 0x4000) || hp->fAA == 0x1BA8 || hp->fAA == 0x1860 || hp->fAA == 0x185F) {
                vec_add_ba(&s->ent[k].a, &s->ent[k].a, &e->b);
            } else {
                f2 = 0;
            }
        }
        if (f2) {
            *(vu0_q *)&s->ent[k].b = *(vu0_q *)&v00;
            func_L11_0034C8A0(obj, s, k, flag);
        } else {
            *(vu0_q *)&s->ent[k].b = *(vu0_q *)&s->ent[k].a;
        }
    }
    func_L04_0035A6A0(D_L11_001E0808, D_L11_001DD320);
    if (s->f4 != 0 && k != 2 && k != 3) {
        s->f4->f34 |= 0x4000;
    }
    func_L01_003F3768(0);
}
