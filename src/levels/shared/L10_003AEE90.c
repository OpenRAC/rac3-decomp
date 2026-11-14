#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003AEE90;
typedef struct M_003AEE90 {
    u8 pad0[0x10];
    V4_003AEE90 pos;
    u8 state;
    u8 pad21[0xB];
    f32 f2C;
    u8 pad30[0x12];
    u8 anim;
    u8 anim2;
    u8 pad44[0x1C];
    u8 b60;
    u8 pad61[7];
    struct P_003AEE90 *pv;
    u8 pad6C[0x2A];
    u16 h96;
    s32 w98;
    u8 pad9C[0x5C];
    f32 fF8;
} __attribute__((aligned(16))) M_003AEE90;
typedef struct Q_003AEE90 {
    s32 w0;
    s32 w4;
    u8 pad8[4];
    s32 wC;
    s32 w10;
} Q_003AEE90;
typedef struct P_003AEE90 {
    u8 pad0[0x61];
    u8 b61;
    u8 pad62[0xE];
    f32 f70;
    u8 pad74[0x34];
    s32 wA8;
    u8 padAC[0x44];
    s32 wF0;
    u8 padF4[0x1C];
    V4_003AEE90 v110;
    u8 pad120[0x50];
    u8 b170;
    u8 pad171[0x37];
    u8 b1A8;
    u8 pad1A9[0x97];
    V4_003AEE90 v240;
    u8 pad250[0x160];
    s32 w3B0;
    s32 w3B4;
    s16 h3B8;
    s16 h3BA;
    M_003AEE90 *m3BC;
    s32 w3C0[4];
    u8 pad3D0[8];
    s32 w3D8;
    f32 f3DC;
    u8 pad3E0[0x100];
    f32 f4E0;
    s32 w4E4;
    M_003AEE90 *m4E8;
    s32 w4EC;
    s32 w4F0;
    s32 w4F4;
    f32 f4F8;
    M_003AEE90 *m4FC;
    s32 w500;
    s32 w504;
    s32 w508;
    s32 w50C;
    u8 pad510[4];
    f32 f514;
    f32 f518;
    u8 pad51C[0x24];
    V4_003AEE90 v540;
    V4_003AEE90 v550;
} P_003AEE90;
typedef struct { s32 n; u8 pad4[0xC]; V4_003AEE90 pt[1]; } Path_003AEE90;

/* localdecomp:start func_L10_003AEE90 */
#include "vu0.h"


extern u8 D_001A4BE0[];
extern s32 D_L10_001DEE40;
__asm__(".extern D_L10_001DEE40, 16");
extern s32 D_L10_001DBDD4;
__asm__(".extern D_L10_001DBDD4, 16");
extern s32 D_L10_001DE584;
__asm__(".extern D_L10_001DE584, 4");
extern s32 D_L10_001DF2D8;
__asm__(".extern D_L10_001DF2D8, 4");
extern s32 D_L10_001DF2D8_003AEE90;
__asm__(".extern D_L10_001DF2D8_003AEE90, 16");
extern u8 *D_L10_001DF29C;
__asm__(".extern D_L10_001DF29C, 16");
extern s32 D_L10_001E8918[];
extern s32 D_001A71A0[];
extern M_003AEE90 *D_001A6630_003AEE90;
__asm__(".extern D_001A6630_003AEE90, 16");
extern s16 *D_L10_0021BF20[];
extern Path_003AEE90 *D_L10_0021D1C0[];

extern s32 func_00382380(void *, s32, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038CAD0(s32 *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_003C2880(void *);
extern void func_003C3A10(M_003AEE90 *, s32, s32, s32);
extern f32 func_003C3D30(f32, void *, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, M_003AEE90 *, s32);
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_L01_004395E0(M_003AEE90 *);
extern void func_L01_004450F0(M_003AEE90 *, s32, s32);
extern s32 func_L01_0044C108(void *);
extern void func_L01_0044FD88(M_003AEE90 *, M_003AEE90 *, s32, s32);
extern s32 func_L01_00454370(M_003AEE90 *, void *);
extern s32 func_L01_004561B8(M_003AEE90 *);
extern s32 func_L01_0045A748(M_003AEE90 *, void *);
extern s32 func_L01_0045A9F0(M_003AEE90 *);
extern s32 func_L01_0045AA10(f32, M_003AEE90 *);
extern void func_L01_0045AA30(M_003AEE90 *, void *);
extern s32 func_L01_0045BD10(f32, M_003AEE90 *);
extern void func_L01_0045BD78(f32, f32, f32, f32, M_003AEE90 *);
extern void func_L10_003A7160(void *);
extern void func_L10_003B0788(M_003AEE90 *);
extern void func_L10_003B0B50(M_003AEE90 *);
extern void func_L10_003B0F78();
extern s32 func_L10_003B10C8(M_003AEE90 *, s32, void *, void *, void *, s32);

#define HERO_003AEE90 (D_001A4BE0 + 0x80)
#define P1A50_003AEE90 (*(M_003AEE90 **)(g + 0x1A50))

void func_L10_003AEE90(M_003AEE90 *m) {
    P_003AEE90 *p;
    V4_003AEE90 a;
    V4_003AEE90 b;
    V4_003AEE90 c;
    V4_003AEE90 d;


    if (func_L01_0044C108(&m->pos) == 0) {
        return;
    }
    p = m->pv;
    func_L10_003B0788(m);
    switch (m->state) {
    case 1:
        if (func_L01_004561B8(m) != 0) {
            func_003C3A10(m, p->w4EC ? 7 : 8, 0, 8);
            p->w3B0 = func_003824E0(5.0f, 15.0f) * 50.0f;
        }
        if (func_0038CAD0(&p->w3B0) != 0) {
            s32 x;
            if (func_00382498(0, 8) == 0) {
                x = p->w4EC ? 10 : 6;
            } else {
                x = p->w4EC ? 9 : 4;
            }
            if (m->anim2 != x) {
                func_003C3A10(m, x, 0, 8);
            }
            p->w3B0 = func_003824E0(5.0f, 15.0f) * 50.0f;
        }
        if (m->b60 & 2) {
            func_003C3A10(m, p->w4EC ? 7 : 8, 0, 8);
        }
        func_L01_0045A9F0(m);
        if (D_L10_001DEE40 % 30 == 0) {
            if (func_L01_0040E570(HERO_003AEE90, &m->pos) < p->f4E0 * p->f4E0) {
                u8 *h = HERO_003AEE90 - 0x80;
                p->m3BC = *(M_003AEE90 **)(h + 0x25C0);
                p->f4F8 = func_0038D160(*(f32 *)(h + 0x80) - m->pos.x, *(f32 *)(h + 0x84) - m->pos.y);
                D_L10_001DBDD4 = 1;
                D_L10_001DE584++;
                func_L01_004450F0(m, 2, -1);
            }
        }
        if (p->b61 != 0) {
            func_L01_004450F0(m, 9, 3);
        }
        break;
    case 2:
        if (func_L01_004561B8(m) != 0) {
            func_003C3A10(m, p->w4EC ? 7 : 8, 0, 8);
            p->w3B0 = func_003824E0(5.0f, 15.0f) * 50.0f;
        }
        if (func_0038CAD0(&p->w3B0) != 0) {
            s32 x;
            if (func_00382498(0, 8) == 0) {
                x = p->w4EC ? 10 : 6;
            } else {
                x = p->w4EC ? 9 : 4;
            }
            if (m->anim2 != x) {
                func_003C3A10(m, x, 0, 8);
            }
            p->w3B0 = func_003824E0(5.0f, 15.0f) * 50.0f;
        }
        if (m->b60 & 2) {
            func_003C3A10(m, p->w4EC ? 7 : 8, 0, 8);
        }
        if (func_0038DBA0(m->fF8, p->f4F8) > 0.34906584f) {
            a.x = func_0038D098(p->f4F8) * 4.0f;
            a.y = func_0038D0B0(p->f4F8) * 4.0f;
            a.z = 0.0f;
            vec_add_ba(&a, &a, &m->pos);
            p->v240 = a;
            if (m->anim2 != 0x10) {
                func_003C3A10(m, 0x10, 0, 8);
            }
        } else if (m->anim2 != 8) {
            func_003C3A10(m, 8, 0, 8);
        }
        func_L01_0045AA10(p->f4F8, m);
        func_L10_003B0B50(m);
        if ((p->h3B8 != 0 && func_L01_0040E570(&m->pos, &p->v550) > 0.040000003f) || p->h3BA != 0) {
            func_L01_004450F0(m, 4, 2);
        }
        if (p->b61 != 0) {
            func_L01_004450F0(m, 9, 3);
        }
        break;
    case 3:
        if (func_L01_004561B8(m) != 0) {
            if (p->w4EC != 0) {
                func_L01_004450F0(m, 2, 1);
                return;
            }
            {
            u8 *g = D_001A4BE0;
            if (P1A50_003AEE90 != 0) {
                func_L10_003A7160(P1A50_003AEE90);
                P1A50_003AEE90 = 0;
                p->w3D8 = 0;
                p->h3BA = 0;
            }
            }
            p->w3B0 = 0;
        }
        if (func_0038CAD0(&p->w3B0) != 0) {
            if (m->anim2 != 0xB) {
                func_003C3A10(m, 0xB, 0, 8);
            }
            p->w3B0 = func_003824E0(5.0f, 15.0f) * 50.0f;
        }
        if ((m->b60 & 2) && m->anim2 != 8) {
            func_003C3A10(m, 8, 0, 8);
        }
        func_L01_0045AA10(p->f4F8, m);
        func_L10_003B0B50(m);
        if (p->h3BA != 0) {
            func_L01_004450F0(m, 4, 2);
        } else if (m->anim2 == 8 && D_L10_001DEE40 % 30 == 0) {
            p->f4F8 = func_0038D160(p->v550.x - m->pos.x, p->v550.y - m->pos.y);
            if (func_L01_0040E570(&m->pos, &p->v550) < 64.0f) {
                a = m->pos;
                a.z += 0.5f;
                b = p->v550;
                b.z += 0.5f;
                if (func_003D3CB0(&a, &b, 0, m, 0) == 0 || D_L10_001E8918[0] == D_001A71A0[0]) {
                    func_L01_004450F0(m, 4, 2);
                }
            }
        }
        break;
    case 5:
        if (func_L01_004561B8(m) != 0) {
            if (m->anim2 != 5) {
                func_003C3A10(m, 5, 0, 8);
            }
            {
            u8 *g = D_001A4BE0;
            p->f4F8 = func_0038D160(P1A50_003AEE90->pos.x - m->pos.x, P1A50_003AEE90->pos.y - m->pos.y);
            p->m4FC = P1A50_003AEE90;
            P1A50_003AEE90 = 0;
            p->w3D8 = 0;
            }
            p->m4FC->w98 = 0;
        }
        if (p->m4FC != 0 && func_L01_0040E570(&m->pos, &p->m4FC->pos) > 3.0f) {
            func_L10_003A7160(p->m4FC);
            p->m4FC = 0;
            p->h3BA = 0;
            func_L01_004450F0(m, 3, 1);
        }
        if (p->b61 != 0) {
            if (p->m4FC != 0) {
                func_L10_003A7160(p->m4FC);
                p->m4FC = 0;
                p->h3BA = 0;
            }
            func_L01_004450F0(m, 9, 3);
        } else {
            f32 t;
            func_L01_0045AA10(p->f4F8, m);
            t = func_L01_004395E0(m);
            if (p->m4FC != 0) {
                if (t > 25.0f) {
                    func_L01_0044FD88(m, p->m4FC, 0, 0);
                }
                if (p->m4FC != 0) {
                    if (t >= 53.0f && t <= 60.0f) {
                        p->m4FC->f2C *= 0.9f;
                    }
                    if (p->m4FC != 0 && t > 60.0f) {
                        func_003C2880(p->m4FC);
                        p->m4FC = 0;
                        p->h3BA = 0;
                    }
                }
            }
            if (m->b60 & 2) {
                p->v550 = p->m3BC->pos;
                func_L01_004450F0(m, 2, -1);
            }
        }
        break;
    case 4:
        func_L10_003B0B50(m);
        if (p->w4EC != 0) {
            Path_003AEE90 *pth;
            f32 rem;
            if (func_L01_004561B8(m) != 0 && m->anim2 != 0xC) {
                func_003C3A10(m, 0xC, 0, 5);
            }
            pth = D_L10_0021D1C0[((Q_003AEE90 *)p->m4E8->pv)->wC];
            func_L10_003B0F78(m, p->m4E8->pv);
            rem = p->f514;
            qzero(&d);
            do {
                s32 n = p->w4E4;
                s32 nx;
                f32 len;
                {
                    s32 pv = n - 1;
                    s32 nv = n + 1;
                    nx = p->w4F0 == 0 ? pv : nv;
                }
                a = (&pth->pt[0])[n];
                b = (&pth->pt[0])[nx];
                vec_sub_ab(&c, &b, &m->pos);
                c.z = 0.0f;
                len = func_0038CEA8(&c);
                if (len < rem) {
                    vec_add_ab(&d, &d, &c);
                    rem -= len;
                    p->w4E4 = nx;
                    if ((p->w4F0 == 0 && nx <= 0) || (p->w4F0 == 1 && nx >= pth->n - 1)) {
                        rem = 0.0f;
                        func_L01_004450F0(m, 7, -1);
                    }
                } else {
                    func_0038CF68(&c, &c, rem);
                    rem = 0.0f;
                    vec_add_ab(&d, &d, &c);
                }
            } while (rem > 0.0f);
            func_L01_0045AA30(m, &d);
            if (p->f514 > 0.0f) {
                func_L01_0045BD10(func_0038D160(d.x, d.y), m);
            }
            {
                f32 f = func_0038CF38(&m->pos, &a);
                m->pos.z = func_003C4088(a.z, b.z, f / func_0038CF38(&b, &a)) - p->f518;
            }
        } else {
            f32 dist;
            s32 ok;
            a = p->v550;
            if (func_L10_003B10C8(m, p->w50C, &a, (u8 *)p + 0x530, (u8 *)p + 0x510, 0) == 0) {
                if (fabs_asm(p->v550.z - m->pos.z) > 2.5f) {
                    func_L01_004450F0(m, 3, 1);
                }
            }
            p->f4F8 = func_0038D160(a.x - m->pos.x, a.y - m->pos.y);
            if (func_0038DBA0(m->fF8, p->f4F8) > 0.17453292f) {
                b.x = func_0038D098(p->f4F8) * 4.0f;
                b.y = func_0038D0B0(p->f4F8) * 4.0f;
                b.z = 0.0f;
                vec_add_ba(&b, &b, &m->pos);
                p->v240 = b;
            }
            dist = func_L01_0040E570(&m->pos, &p->v550);
            if (dist > 0.040000003f) {
                f32 s;
                V4_003AEE90 *bp;
                vec_sub_ab(&b, &a, &m->pos);
                b.z = 0.0f;
                bp = &b;
                s = func_0038CEA8(bp) < 1.5f ? func_0038CEA8(bp) : 1.5f;
                func_0038CF68(bp, bp, s);
                vec_add_ba(&c, &m->pos, &b);
                c.z += 0.5f;
                d = c;
                d.z -= 1.5f;
                ok = func_003D3CB0(&c, &d, 0, m, 0);
                {
                    s32 i;
                    for (i = 0; i < 4 && ok; i++) {
                        s16 *q;
                        if (p->w3C0[i] == 0xFF) {
                            continue;
                        }
                        q = D_L10_0021BF20[p->w3C0[i]];
                        while ((p->w3C0[i] & 0xFF) != 0xFF && p->w3C0[i] <= D_L10_001DF2D8_003AEE90 && q != 0
                               && (q[-1] >= 0 || q == D_L10_0021BF20[p->w3C0[i]])) {
                            M_003AEE90 *o = (M_003AEE90 *)(D_L10_001DF29C + ((*q & 0x7FFF) << 8));
                            if (o == 0) {
                                break;
                            }
                            if (o->state != 0xFE) {
                                if (o->state != 0xFD && func_L01_0040E570(&c, &o->pos) < 9.0f) {
                                    qzero(&p->v110);
                                    ok = 0;
                                }
                            }
                            q++;
                        }
                    }
                }
                if (ok) {
                    if (p->h3BA != 0) {
                        func_L01_0045BD78(0.0064000003f, 0.120000005f, 0.0075398227f, 0.16755162f, m);
                        if (m->anim2 != 0) {
                            func_003C3A10(m, 0, 0, 7);
                        }
                        p->f70 = 0.6f;
                    } else if (dist > 12.25f) {
                        func_L01_0045BD78(0.0064000003f, 0.10000001f, 0.0075398227f, 0.16755162f, m);
                        if (m->anim2 != 0x11) {
                            func_003C3A10(m, 0x11, 0, 8);
                        }
                    } else if (m->anim2 != 0x11) {
                        func_L01_0045BD78(0.0064000003f, 0.020000001f, 0.0075398227f, 0.16755162f, m);
                        if (m->anim2 != 0x10) {
                            func_003C3A10(m, 0x10, 0, 8);
                        }
                    }
                    func_L01_0045A748(m, &a);
                    if (p->wF0 >= 0x33) {
                        func_L01_004450F0(m, 3, 1);
                    }
                    if (p->h3BA != 0) {
                        f32 f = func_0038CF38(&(*(M_003AEE90 **)(D_001A4BE0 + 0x1A50))->pos, &m->pos);
                        if (f < p->f3DC) {
                            p->f3DC = f;
                        } else if (++p->w3B4 >= 0xFB) {
                            func_L01_004450F0(m, 3, 1);
                        }
                    }
                } else {
                    s16 *q;
                    if (m->anim2 != 8) {
                        func_003C3A10(m, 8, 0, 5);
                    }
                    q = D_L10_0021BF20[p->w4F4];
                    while ((p->w4F4 & 0xFF) != 0xFF && p->w4F4 <= D_L10_001DF2D8 && q != 0
                           && (q[-1] >= 0 || q == D_L10_0021BF20[p->w4F4])) {
                        M_003AEE90 *o = (M_003AEE90 *)(D_L10_001DF29C + ((*q & 0x7FFF) << 8));
                        Q_003AEE90 *r;
                        if (o == 0) {
                            break;
                        }
                        r = (Q_003AEE90 *)o->pv;
                        if (func_00382380(&m->pos, r->w0, 0) != 0 && func_00382380(&p->v550, r->w4, 0) != 0) {
                            p->m4E8 = o;
                            p->w4F0 = 1;
                            func_L01_004450F0(m, 6, -1);
                            break;
                        }
                        if (r->w10 == 0 && func_00382380(&m->pos, r->w4, 0) != 0 && func_00382380(&p->v550, r->w0, 0) != 0) {
                            p->m4E8 = o;
                            p->w4F0 = 0;
                            func_L01_004450F0(m, 6, -1);
                            break;
                        }
                        q++;
                    }
                    func_L01_0045AA10(p->f4F8, m);
                    if (p->m4E8 == 0) {
                        func_L01_004450F0(m, 3, 1);
                    }
                }
            } else {
                func_L01_0045AA10(p->f4F8, m);
                if (p->h3BA != 0) {
                    func_L01_004450F0(m, 5, 1);
                } else {
                    func_L01_004450F0(m, 2, 1);
                }
            }
        }
        break;
    case 6:
        {
            Path_003AEE90 *pth;
            M_003AEE90 *o;
            if (func_L01_004561B8(m) != 0) {
                func_L01_0045BD78(0.0064000003f, 0.10000001f, 0.0075398227f, 0.16755162f, m);
                if (m->anim2 != 0x11) {
                    func_003C3A10(m, 0x11, 0, 8);
                }
            }
            pth = D_L10_0021D1C0[((Q_003AEE90 *)p->m4E8->pv)->wC];
            {
                V4_003AEE90 *pt = pth->pt;
                s32 k;
                s32 k2;
                a = *(p->w4F0 != 0 ? pt : &pt[k = pth->n - 1]);
                a.z -= 1.35f;
                b = *(p->w4F0 == 0 ? &pt[k2 = pth->n - 2] : &pth->pt[1]);
                b.z -= 1.35f;
            }
            func_L10_003B0F78(m);
            p->v240 = a;
            if (m->anim == 3) {
                f32 t = func_L01_004395E0(m);
                f32 dz = a.z - p->v540.z;
                c = m->pos;
                if (t > 6.0f && t < 20.0f) {
                    f32 k = (t - 6.0f) / 13.0f;
                    k = 1.0f - k;
                    k = 1.0f - k * k;
                    c.x = p->v540.x + (a.x - p->v540.x) * k;
                    c.y = p->v540.y + (a.y - p->v540.y) * k;
                    c.z = p->v540.z + dz * k;
                    vec_sub_ab(&d, &c, &m->pos);
                    func_L01_0045AA30(m, &d);
                }
                func_L01_0045BD10(func_0038D160(b.x - a.x, b.y - a.y), m);
                if (t > 20.0f) {
                    m->pos = a;
                    p->w4EC = 1;
                    p->w4E4 = p->w4F0 != 0 ? 0 : pth->n - 1;
                    if (m->anim2 != 0xC) {
                        func_003C3A10(m, 0xC, 0, 5);
                    }
                    func_L01_004450F0(m, 4, -1);
                }
            } else {
                func_L01_0045A748(m, &a);
                if (func_L01_0040E570(&m->pos, &a) <= 0.040000003f) {
                    p->v540 = m->pos;
                    if (m->anim2 != 3) {
                        func_003C3A10(m, 3, 0, 5);
                    }
                }
            }
        }
        break;
    case 7:
        if (func_L01_004561B8(m) != 0) {
            if (m->anim2 != 1) {
                func_003C3A10(m, 1, 0, 5);
            }
            p->v540 = m->pos;
        } else if (m->anim == 1) {
            f32 t = func_L01_004395E0(m);
            V4_003AEE90 *pos = &m->pos;
            a = m->pos;
            if (t >= 0.0f && t <= 5.0f) {
                f32 z = func_003C3D30(0.5f, pos, 0, 0);
                f32 k = (t - 0.0f) / 5.0f;
                a.z = p->v540.z - (p->v540.z - z) * (k * k);
                vec_sub_ab(&b, &a, &m->pos);
                func_L01_0045AA30(m, &b);
            }
            if (t > 10.0f) {
                p->w4EC = 0;
                p->m4E8 = 0;
                func_L01_004450F0(m, 4, -1);
            }
        }
        break;
    case 8:
        if (func_L01_004561B8(m) != 0) {
            p->w508 = 800;
            p->b170 = 0xFF;
            p->b1A8 = 0xFF;
            if (m->anim2 != 0xB) {
                func_003C3A10(m, 0xB, 0, 5);
            }
        } else if (m->b60 & 2) {
            func_L01_004450F0(m, 9, -1);
        }
        func_L01_0045AA10(p->f4F8, m);
        func_0038CAD0(&p->w508);
        break;
    case 9:
        {
            if (func_L01_004561B8(m) != 0) {
                M_003AEE90 *o = 0;
                s16 *q = D_L10_0021BF20[p->w500];
                while ((p->w500 & 0xFF) != 0xFF && p->w500 <= D_L10_001DF2D8 && q != 0
                       && (q[-1] >= 0 || q == D_L10_0021BF20[p->w500])) {
                    o = (M_003AEE90 *)(D_L10_001DF29C + ((*q & 0x7FFF) << 8));
                    if (o == 0) {
                        break;
                    }
                    if (func_00382380(&m->pos, ((Q_003AEE90 *)o->pv)->w0, 0) != 0) {
                        break;
                    }
                    q++;
                }
                if (o != 0) {
                    p->w504 = ((Q_003AEE90 *)o->pv)->wC;
                    p->w4E4 = 0;
                } else {
                    func_L01_004450F0(m, 4, 2);
                }
                if (m->anim2 != 0) {
                    func_003C3A10(m, 0, 0, 0);
                }
                {
                u8 *g = D_001A4BE0;
                if (P1A50_003AEE90 != 0) {
                    func_L10_003A7160(P1A50_003AEE90);
                    P1A50_003AEE90 = 0;
                    p->w3D8 = 0;
                    p->h3BA = 0;
                }
                }
            }
            func_L10_003B0B50(m);
            func_L01_0045BD78(0.0064000003f, 0.120000005f, 0.010053097f, 0.25132743f, m);
            if (p->wF0 < 3) {
                p->wA8 |= 0x10;
            }
            func_L01_0045A748(m, &p->v550);
            func_L01_0045BD10(func_0038D160(p->v110.x, p->v110.y), m);
            p->wA8 &= ~0x10;
            if (m->h96 >= 0x191 || p->b61 == 0) {
                if (p->m3BC != 0) {
                    func_L01_004450F0(m, 4, 2);
                } else if (p->b61 != 0) {
                    func_L01_004450F0(m, 1, 1);
                } else if (func_L01_0040E570(HERO_003AEE90, &m->pos) < p->f4E0 * p->f4E0 * 9.0f) {
                    u8 *h = HERO_003AEE90 - 0x80;
                    p->m3BC = *(M_003AEE90 **)(h + 0x25C0);
                    p->f4F8 = func_0038D160(*(f32 *)(h + 0x80) - m->pos.x, *(f32 *)(h + 0x84) - m->pos.y);
                    D_L10_001DBDD4 = 1;
                    func_L01_004450F0(m, 4, 2);
                } else {
                    func_L01_004450F0(m, 1, 1);
                }
            }
        }
        break;
    case 10:
        if (func_L01_004561B8(m) != 0) {
            if (p->w4EC != 0) {
                if (m->anim2 != 0xD) {
                    func_003C3A10(m, 0xD, 0, 5);
                }
            } else if (m->anim2 != 0x12) {
                func_003C3A10(m, 0x12, 0, 5);
            }
            if (p->m4FC != 0) {
                func_L10_003A7160(p->m4FC);
                p->m4FC = 0;
                p->h3BA = 0;
            }
        }
        func_L01_0045A9F0(m);
        if (func_L01_00454370(m, (u8 *)p + 0x160) & 2) {
            if (p->m3BC == 0) {
                func_L01_004450F0(m, 1, 1);
            } else {
                func_L01_004450F0(m, 2, 1);
            }
        }
        break;
    }
    p->b61 = 0;
}
/* localdecomp:end func_L10_003AEE90 */

INCLUDE_ASM("asm/levels", func_L10_003B0788);

INCLUDE_ASM("asm/levels", func_L10_003B0940);
