/* func_L05_003560C8 (src/levels/shared/L05_00355DD8.c; levels 05, 10, 14, 17): a two-moby enemy's
   per-frame update (the moby and its partner moby at pvar 0x3EC), a switch on the moby's mode
   (m+0x95: 0-5) and one on its state (m+0x20: 1-18, with switch 3 on pvar 0x3E0 in state 10).
   A near miss, written by hand from retail's assembly, with func_L20_003FB6A8 (0.64 similar,
   L20_003FB630.c) as the model for its shape. Compiled with check.py in the context of
   L05_00355DD8.c (its u128_t, Vec4 and earlier declarations). See nonmatching/README.md. */

typedef union Mo_60C8_ { u8 b[0x100]; s8 c[0x100]; s16 h[0x80]; u16 uh[0x80]; s32 i[0x40]; u32 u[0x40]; f32 f[0x40]; void *p[0x40]; union Pv_60C8_ *pv[0x40]; union Mo_60C8_ *mp[0x40]; u128_t q[0x10]; } Mo_60C8;
typedef union Pv_60C8_ { u8 b[0x420]; s8 c[0x420]; s16 h[0x210]; u16 uh[0x210]; s32 i[0x108]; u32 u[0x108]; f32 f[0x108]; void *p[0x108]; Mo_60C8 *mp[0x108]; u128_t q[0x42]; } Pv_60C8;
typedef struct { s32 n; s32 pad[3]; u128_t pt[1]; } Path_60C8;
typedef struct { u8 x0[2]; s16 n; u8 x4[0xC]; s32 *list; u8 x14[0x1C]; } Area_60C8;
typedef struct { u8 x0[0x30]; Area_60C8 a[1]; } Zones_60C8;
typedef struct { u8 x0[0x30]; u128_t pos; u8 x40[0x40]; } Spot_60C8;

extern s32 func_L05_00359878(Mo_60C8 *);
extern void func_L01_004AA7E8(Mo_60C8 *, s32);
extern s32 func_003A52A0(s32, s32, Mo_60C8 *);
extern void func_L05_0035A568(u8 *, s32);
extern void func_003C2880(Mo_60C8 *);
extern s32 func_L01_004561E0(Mo_60C8 *);
extern s32 func_00382498(s32, s32);
extern s32 func_0038CB00(void *);
extern s32 func_0038CAD0(void *);
extern void func_L01_004450F0(Mo_60C8 *, s32, s32);
extern void func_L01_00409598(Mo_60C8 *, u8 *, u8 *, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_00454370(Mo_60C8 *, u8 *);
extern s32 func_L01_004561B8(Mo_60C8 *);
extern void func_L01_0045BD78(Mo_60C8 *, f32, f32, f32, f32);
extern void func_L01_0045C150(Mo_60C8 *, Path_60C8 *, s32, s32);
extern s32 func_L03_00449C30(Mo_60C8 *, s32);
extern s32 func_L01_0045BDE8(Mo_60C8 *, s32);
extern s32 func_L05_00454940(Mo_60C8 *, void *);
extern void func_L05_00454970(Mo_60C8 *, void *);
extern s32 func_00382468(s32);
extern f32 *func_00382348(Mo_60C8 *);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern s32 func_L01_0045C2A0(Mo_60C8 *, f32, f32, f32);
extern f32 func_L01_004395E0(Mo_60C8 *);
extern void func_L01_0045A9F0(Mo_60C8 *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CF00(void *, void *);
extern s32 func_L01_0045A748(Mo_60C8 *, void *);
extern void func_L01_0045A898(Mo_60C8 *, void *, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_L01_0045BD10(Mo_60C8 *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00459188(Mo_60C8 *, Mo_60C8 *, u8 *);
extern void func_L01_00458F78(Mo_60C8 *, u8 *, s32, s32);
extern void func_L01_0045A7A8(Mo_60C8 *, u8 *, f32);
extern s32 func_L05_0035AAC8(Mo_60C8 *);
extern s32 func_L05_00355C70(Mo_60C8 *);
extern s32 func_L05_00355C48(Mo_60C8 *);
extern s32 func_L05_00355AE8(Mo_60C8 *);
extern void func_L01_004591B8(Mo_60C8 *, Vec4 *, u8 *);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L05_0035AEC8(Mo_60C8 *);
extern f32 func_L05_00355C98(Mo_60C8 *, Vec4 *, Vec4 *);
extern void func_L05_0035AD60(Mo_60C8 *);
extern s32 func_L05_00355BD8(Mo_60C8 *, u8 *);
extern s32 func_L05_00355B80(Mo_60C8 *);
extern s32 func_L01_003EBED0(Mo_60C8 *);
extern f32 func_L05_00355D60(Mo_60C8 *, Mo_60C8 *);
extern void func_003C2F58(Mo_60C8 *, s32, Vec4 *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00446780(Mo_60C8 *, f32, Vec4 *, s32, f32, f32, s32, s32, s32);
extern void func_L05_00358FF8(Mo_60C8 *);
extern void func_L05_0035A880(Mo_60C8 *);

extern s32 D_L05_001D6694;
extern s32 D_001D545C;
extern s32 D_L05_001DBBE0;
extern s32 D_L05_001DF6C0;
extern u8 *D_L05_001DFB9C;
extern Path_60C8 *D_L05_0021ED80[];
extern u8 *D_L05_001DF7CC;
extern Spot_60C8 *D_L05_001DFC80;

static __inline__ s32 f_lt_60C8(f32 a, f32 b) { return a < b; }

void func_L05_003560C8(Mo_60C8 *m) {
    Pv_60C8 *pv;
    s32 f;
    Vec4 sp10;
    Vec4 sp20;
    Vec4 sp30;
    Vec4 sp40;
    Vec4 sp50;
    Vec4 sp60;

    pv = m->pv[0x68/4];
    if ((pv->i[0x3A0/4] != 0) && ((m->b[0x34] ^ 1) & 1)) {
        m->i[0x98/4] = 0;
        m->uh[0x34/2] = (m->uh[0x34/2] | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
        if ((pv != 0) && (pv->mp[0x3EC/4] != 0)) {
            pv->mp[0x3EC/4]->uh[0x34/2] |= 0x41;
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xEFFF;
            pv->mp[0x3EC/4]->i[0x98/4] = 0;
            func_L01_004AA7E8(pv->mp[0x3EC/4], 1);
            pv->mp[0x3EC/4]->uh[0x34/2] |= 4;
            pv->mp[0x3EC/4]->uh[0x34/2] |= 2;
        }
    }
    if (func_L05_00359878(m) != 0) {
        return;
    }
    if (D_L05_001D6694 == 2) {
        if ((m->b[0x34] ^ 1) & 1) {
            m->i[0x98/4] = 0;
            m->uh[0x34/2] = (m->uh[0x34/2] | 0x41) & 0xEFFF;
            func_L01_004AA7E8(m, 1);
            pv->mp[0x3EC/4]->uh[0x34/2] |= 0x41;
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xEFFF;
            pv->mp[0x3EC/4]->i[0x98/4] = 0;
            func_L01_004AA7E8(pv->mp[0x3EC/4], 1);
            pv->i[0x400/4] = 1;
        }
        return;
    }
    if (pv->i[0x400/4] != 0) {
        m->uh[0x34/2] &= 0xFFBE;
        m->uh[0x34/2] |= m->mp[0x24/4]->uh[0x44/2] & 0x1000;
        m->i[0x98/4] = m->mp[0x24/4]->i[0x10/4];
        pv->mp[0x3EC/4]->uh[0x34/2] &= 0xFFBE;
        pv->mp[0x3EC/4]->uh[0x34/2] |= pv->mp[0x3EC/4]->mp[0x24/4]->uh[0x44/2] & 0x1000;
        pv->mp[0x3EC/4]->i[0x98/4] = pv->mp[0x3EC/4]->mp[0x24/4]->i[0x10/4];
        pv->i[0x400/4] = 0;
    }
    if (pv->h[0x3DA/2] != 0) {
        m->uh[0x34/2] |= 0x100;
    }
    if (pv->f[0x30/4] <= 0.0f) {
        func_003A52A0(5, 0, m);
        func_L05_0035A568(m->b, 0);
        func_003C2880(m);
        return;
    }
    if ((m->b[0x34] ^ 1) & 1) {
        D_L05_001DBBE0 |= 1;
        if (m->i[0x98/4] == 0) {
            m->i[0x98/4] = m->mp[0x24/4]->i[0x10/4];
            m->uh[0x34/2] |= 0x1000;
        }
    }
    switch (m->b[0x95]) {
    case 0:
        if ((func_L01_004561E0(m) != 0) && (pv->h[0x3D6/2] == 0)) {
            if (!((pv->i[0x3A0/4] != 0) && (pv->i[0x3C4/4] < 0))) {
                pv->h[0x3D6/2] = (func_00382498(0, 0x1E) * 5 + 2) / 6;
            }
            if (D_001D545C != 0x11) {
                pv->i[0x3C4/4] = 0;
            }
        }
        if ((pv->h[0x234/2] == 1) && (func_0038CB00(pv->b + 0x3D6) != 0)) {
            if (pv->i[0x3A0/4] != 0) {
                if (pv->i[0x3C4/4] >= 0) {
                    m->b[0x95] = 1;
                    break;
                }
                m->uh[0x34/2] &= 0xFFBE;
                m->uh[0x34/2] |= m->mp[0x24/4]->uh[0x44/2] & 0x1000;
                m->i[0x98/4] = m->mp[0x24/4]->i[0x10/4];
                pv->mp[0x3EC/4]->uh[0x34/2] &= 0xFFBE;
                pv->mp[0x3EC/4]->uh[0x34/2] |= pv->mp[0x3EC/4]->mp[0x24/4]->uh[0x44/2] & 0x1000;
                pv->mp[0x3EC/4]->i[0x98/4] = pv->mp[0x3EC/4]->mp[0x24/4]->i[0x10/4];
                pv->i[0x3A0/4] = 0;
            }
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xFFFD;
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xFFFB;
            func_L01_004450F0(m, 0xA, 2);
        }
        break;
    case 1:
        if (pv->i[0x3A0/4] != 0) {
            if (func_0038CAD0(pv->b + 0x3C4) != 0) {
                func_L01_00409598(m, m->b + 0x10, m->b + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                func_L01_00409598(pv->mp[0x3EC/4], pv->mp[0x3EC/4]->b + 0x10, pv->mp[0x3EC/4]->b + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                pv->i[0x3A0/4] = 0;
                func_L01_004450F0(m, 0xA, 2);
            }
        } else if (pv->h[0x234/2] == 1) {
            func_L01_004450F0(m, 0xA, 2);
        } else if (func_0038CAD0(pv->b + 0x3D0) != 0) {
            func_L01_004450F0(m, 1, 0);
        }
        break;
    case 2:
        if (func_L01_004561E0(m) != 0) {
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xFFFD;
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xFFFB;
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xFFFE;
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xFFBF;
            m->uh[0x34/2] &= 0xFFBA;
        } else if ((pv->h[0x234/2] != 1) && (pv->i[0x3E0/4] != 2)) {
            func_L01_004450F0(m, 1, 1);
            func_L05_0035AA68(m, 8, 0, 8);
            pv->i[0x3D0/4] = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
            func_L05_00356018(m->b);
        }
        break;
    case 3:
        if (func_L01_004561E0(m) != 0) {
            func_L05_00356018(m->b);
            if ((m->b[0x42] == 0x10) || (m->b[0x43] == 0x10)) {
                m->f[0x48/4] = 2.0f;
                pv->mp[0x3EC/4]->f[0x48/4] = 2.0f;
            }
            func_003A52A0(7, 0, m);
        }
        {
            s32 r = func_L01_00454370(m, pv->b + 0x160);
            if (pv->f[0x30/4] <= 0.0f) {
                func_L05_0035A568(m->b, 0);
                func_003A52A0(5, 0, m);
                func_003C2880(m);
                return;
            }
            if (r & 2) {
                m->f[0x48/4] = 1.0f;
                pv->mp[0x3EC/4]->f[0x48/4] = 1.0f;
                func_L01_004450F0(m, 0xA, 2);
                if ((func_L05_00355B30(m->b) == 0) && (func_L05_00355E58(m->b, (Vec4 *)(pv->b + 0x220)) != 0)) {
                    func_L01_004450F0(m, 0x10, -1);
                    func_L05_0035AA68(m, 0xF, 3, 2);
                }
            }
        }
        break;
    case 4:
    case 5:
        break;
    }
    switch (m->b[0x20]) {
    case 1:
        if (func_L01_004561B8(m) != 0) {
            u8 a;
            u8 b;
            pv->mp[0x3EC/4]->b[0x20] = 4;
            func_L01_0045BD78(m, 0.012f, 0.052f, 0.020943953f, 0.17453294f);
            a = 0;
            b = 0;
            if ((pv->i[0x390/4] != -1) && (m->b[0x95] == 0)) {
                Path_60C8 *p;
                f32 d;
                u8 c;
                if (pv->i[0x3FC/4] != 0) {
                    a = 0x13;
                    b = 2;
                    pv->i[0xA8/4] |= 0x414;
                } else {
                    a = 4;
                    b = 4;
                }
                p = D_L05_0021ED80[pv->i[0x390/4]];
                sp10.q = p->pt[0];
                d = func_L05_00355D00(m->b, &sp10);
                sp20.q = *(u128_t *)((u8 *)p + p->n * 16);
                c = f_lt_60C8(func_L05_00355D00(m->b, &sp20), d);
                if (c) {
                    func_L01_0045C150(m, p, 0, p->n - 1);
                } else {
                    func_L01_0045C150(m, p, p->n - 1, 0);
                }
            } else {
                if (m->b[0x95] != 0) {
                    a = 2;
                    b = 2;
                }
                if (pv->i[0x3FC/4] != 0) {
                    b = 2;
                }
                if (m->b[0x42] == 9) {
                    b = 8;
                    a = 8;
                } else if (m->b[0x42] == 0xD) {
                    b = 0xC;
                    a = 0xC;
                } else if (pv->mp[0x3EC/4]->b[0x42] == 9) {
                    a = 8;
                    b = 8;
                } else if (((pv->mp[0x3EC/4]->b[0x42] == 8) || (pv->mp[0x3EC/4]->b[0x42] == 0xC)) && (m->b[0x42] != 0xFF)) {
                    b = pv->mp[0x3EC/4]->b[0x42];
                    a = m->b[0x42];
                }
                if (pv->i[0x3FC/4] != 0) {
                    pv->i[0xA8/4] |= 0x414;
                    a = 0x13;
                }
            }
            if ((b == 8) || (b == 0xC)) {
                pv->mp[0x3EC/4]->b[0x20] = 0;
            }
            if (m->b[0x43] != a) {
                func_003C3A10(m, a, 0, 8);
            }
            if (pv->mp[0x3EC/4]->b[0x43] != b) {
                func_003C3A10(pv->mp[0x3EC/4], b, 0, 8);
            }
        }
        if ((pv->i[0x390/4] != -1) && (m->b[0x95] == 0)) {
            s32 r;
            if (pv->h[0x3DA/2] != 0) {
                r = func_L03_00449C30(m, pv->i[0x390/4]);
            } else {
                r = func_L01_0045BDE8(m, pv->i[0x390/4]);
            }
            if (r != 0) {
                func_L01_004450F0(m, 1, -1);
            } else if (func_L05_00355B30(m->b) != 0) {
                func_L05_00454940(m, &D_L05_0021ED80[pv->i[0x390/4]]->pt[pv->h[0x138/2]]);
            }
        } else if (func_00382468(0xFA) == 0) {
            func_L01_004450F0(m, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(m) != 0) {
            pv->mp[0x3EC/4]->b[0x20] = 4;
            if (func_L05_00355B30(m->b) != 0) {
                func_003C3A10(pv->mp[0x3EC/4], 3, 0, 0xC);
            } else if (m->b[0x95] == 0) {
                func_L05_0035AA68(m, 1, 0, 8);
            } else {
                func_L05_0035AA68(m, 3, 0, 8);
            }
        }
        if (pv->mp[0x3EC/4]->b[0x60] & 2) {
            func_L01_004450F0(m, m->b[0x94], -1);
        }
        break;
    case 3:
        if ((pv->i[0x3A0/4] != 0) && ((m->b[0x34] ^ 1) & 1)) {
            m->i[0x98/4] = 0;
            m->uh[0x34/2] = (m->uh[0x34/2] | 0x41) & 0xEFFF;
            func_L01_004AA7E8(m, 1);
            pv->mp[0x3EC/4]->uh[0x34/2] |= 0x41;
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xEFFF;
            pv->mp[0x3EC/4]->i[0x98/4] = 0;
            func_L01_004AA7E8(pv->mp[0x3EC/4], 1);
            pv->mp[0x3EC/4]->uh[0x34/2] |= 2;
            pv->mp[0x3EC/4]->uh[0x34/2] |= 4;
        }
        pv->mp[0x3EC/4]->b[0x20] = 0x10;
        if (D_L05_001DF6C0 >= 3) {
            Mo_60C8 *t = (Mo_60C8 *)(D_L05_001DFB9C + pv->i[0x3A4/4] * 0x100);
            f32 *hp = func_00382348(t);
            if ((t == 0) || (t->b[0x20] == 0xFE) || (t->b[0x20] == 0xFD) || ((hp != 0) && (*hp <= 0.0f))) {
                pv->q[0x350/16] = ((Mo_60C8 *)(D_L05_001DFB9C + pv->i[0x3A4/4] * 0x100))->q[1];
                if (func_0038CAD0(pv->b + 0x3C4) != 0) {
                    pv->i[0x3A0/4] = 0;
                    pv->i[0x3A4/4] = -1;
                    func_L01_004450F0(m, 1, 0);
                    func_L01_00409598(m, m->b + 0x10, m->b + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                    func_L01_00409598(pv->mp[0x3EC/4], pv->mp[0x3EC/4]->b + 0x10, pv->mp[0x3EC/4]->b + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                    pv->mp[0x3EC/4]->uh[0x34/2] |= 2;
                    pv->mp[0x3EC/4]->uh[0x34/2] |= 4;
                }
            }
        }
        break;
    case 4:
        pv->mp[0x3EC/4]->b[0x20] = 0x10;
        if ((D_L05_001DF6C0 >= 3) && (func_L01_00445AD0(pv->i[0x3A8/4], -1, 1) == 0)) {
            if (func_0038CAD0(pv->b + 0x3C4) != 0) {
                pv->i[0x3A0/4] = 0;
                func_L01_004450F0(m, 1, 0);
                func_L01_00409598(m, m->b + 0x10, m->b + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                func_L01_00409598(pv->mp[0x3EC/4], pv->mp[0x3EC/4]->b + 0x10, pv->mp[0x3EC/4]->b + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                pv->mp[0x3EC/4]->uh[0x34/2] |= 2;
                pv->mp[0x3EC/4]->uh[0x34/2] |= 4;
            }
        }
        break;
    case 5:
        pv->mp[0x3EC/4]->b[0x20] = 0x10;
        if (func_L01_004561B8(m) != 0) {
            pv->i[0x3E4/4] = 0;
        }
        if (D_L05_001DF6C0 >= 3) {
            if (pv->i[0x3E4/4] == 0) {
                if (pv->i[0x39C/4] > 0) {
                    pv->i[0x3E4/4] = 1;
                    if (m->b[0x21] != 0xFF) {
                        s16 *q = ((s16 **)D_L05_0021DAE0)[m->b[0x21]];
                        while ((m->b[0x21] != 0xFF) && (m->b[0x21] <= D_L05_001DFBD8) && (q != 0)
                               && ((q[-1] >= 0) || (q == ((s16 **)D_L05_0021DAE0)[m->b[0x21]]))) {
                            Mo_60C8 *e = (Mo_60C8 *)(D_L05_001DFB9C + ((*q & 0x7FFF) << 8));
                            if (e == 0) {
                                break;
                            }
                            q++;
                            if ((e->h[0xAA/2] == 0x1625) && (e->pv[0x68/4] != 0)) {
                                e->pv[0x68/4]->i[0x39C/4]--;
                            }
                        }
                    }
                }
                if (pv->i[0x3E4/4] == 0) {
                    break;
                }
            }
            if (func_0038CAD0(pv->b + 0x3C4) != 0) {
                pv->i[0x3A0/4] = 0;
                func_L01_004450F0(m, 1, 0);
                func_L01_00409598(m, m->b + 0x10, m->b + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                func_L01_00409598(pv->mp[0x3EC/4], pv->mp[0x3EC/4]->b + 0x10, pv->mp[0x3EC/4]->b + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                pv->mp[0x3EC/4]->uh[0x34/2] |= 2;
                pv->mp[0x3EC/4]->uh[0x34/2] |= 4;
            }
        }
        break;
    case 7:
        pv->mp[0x3EC/4]->b[0x20] = 0x10;
        break;
    case 8:
        if (func_L01_004561B8(m) != 0) {
            pv->f[0x1B8/4] = 2.0f;
            pv->f[0x1BC/4] = 2.0f;
        }
        if (pv->f[0x3B0/4] < 1.0f) {
            pv->f[0x3B0/4] += 0.018000001f;
            if (pv->f[0x3B0/4] > 1.0f) {
                pv->f[0x3B0/4] = 1.0f;
            }
            m->f[0x2C/4] = m->mp[0x24/4]->f[0x24/4] * pv->f[0x3B0/4];
            pv->mp[0x3EC/4]->f[0x2C/4] = pv->mp[0x3EC/4]->mp[0x24/4]->f[0x24/4] * pv->f[0x3B0/4];
        }
        if (pv->mp[0x3F0/4] != 0) {
            pv->mp[0x3F0/4]->i[0x98/4] = 0;
        }
        if ((func_L01_0045C2A0(m, 1.0f, 5.0f, 11.0f) != 0) || (func_L01_004395E0(m) > 20.0f)) {
            m->f[0x48/4] = 1.0f;
            pv->mp[0x3EC/4]->f[0x48/4] = 1.0f;
            func_L01_0045A9F0(m);
            pv->f[0x1BC/4] = 0.5f;
            pv->f[0x1B8/4] = 0.2f;
            if (pv->h[0x3BA/2] != 0) {
                func_L01_004450F0(m, 9, 5);
                func_L05_0035AA68(m, 4, 0, 8);
            } else {
                func_L01_004450F0(m, 1, 0);
                func_L05_0035AA68(m, 0, 0, 8);
            }
        } else if (pv->mp[0x3EC/4] != 0) {
            pv->mp[0x3EC/4]->f[0x48/4] = m->f[0x48/4];
        }
        if (pv->mp[0x3F0/4] != 0) {
            pv->mp[0x3F0/4]->i[0x98/4] = pv->mp[0x3F0/4]->mp[0x24/4]->i[0x10/4];
        }
        break;
    case 9:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, 0.012f, 0.052f, 0.020943953f, 0.17453294f);
        }
        if (func_0038CF38(m->b + 0x10, pv->b + 0x360) > 0.5f) {
            func_L01_0045A748(m, pv->b + 0x360);
        } else {
            func_L01_0045A898(m, pv->b + 0x360, pv->f[0x3B4/4]);
        }
        if (pv->h[0x234/2] == 1) {
            func_L01_004450F0(m, 0xA, 2);
        } else if (func_0038CF38(m->b + 0x10, pv->b + 0x360) <= pv->f[0xA4/4]) {
            if (pv->f[0xA0/4] < fabs_asm(func_0038DBA0(m->f[0xF8/4], pv->f[0x3B4/4]))) {
                func_L01_0045BD10(m, pv->f[0x3B4/4]);
            } else {
                func_L01_0045BD78(m, 0.012f, 0.15f, 0.020943953f, 0.17453294f);
                func_L01_004450F0(m, 1, 0);
                func_L05_0035AA68(m, 0, 0, 8);
            }
        }
        break;
    case 10:
        if (func_L01_004561B8(m) != 0) {
            f32 a;
            m->b[0xBE] &= 0xFE;
            if (pv->h[0x3F4/2] != 0) {
                func_L01_0045BD78(m, 0.012f, 0.052f, 0.020943953f, 0.17453294f);
            } else if (func_L05_00355B30(m->b) != 0) {
                func_L01_0045BD78(m, 0.012f, 0.15f, 0.0069813174f, 0.17453294f);
            } else {
                func_L01_0045BD78(m, 0.012f, 0.15f, 0.020943953f, 0.17453294f);
            }
            pv->i[0x3E4/4] = 0;
            a = func_003824E0(5.0f, 10.0f) * 0.017453292f;
            if (func_00382468(2) != 0) {
                a = -a;
            }
            pv->f[0x3E8/4] = a;
        }
        switch (pv->u[0x3E0/4]) {
        case 0:
            {
                if (func_L01_004561B8(m) != 0) {
                    pv->mp[0x3EC/4]->b[0x20] = 4;
                    func_L05_00355EE8((O_35EE8 *)m);
                    func_L01_00459188(m, pv->mp[0x230/4], pv->b + 0x250);
                }
                if (pv->mp[0x230/4] != pv->mp[0x2A0/4]) {
                    func_L01_00459188(m, pv->mp[0x230/4], pv->b + 0x250);
                }
                func_L01_00458F78(m, pv->b + 0x250, 0, 0);
                func_L01_0045A7A8(m, pv->b + 0x250, pv->f[0x3E8/4]);
                if ((func_L05_0035AAC8(m) != 0) && (m->uh[0x96/2] >= 0x33)
                    && ((m->uh[0x96/2] >= 0x65) || (func_00382468(0x32) == 0)) && (func_L05_00355C70(m) != 0)) {
                    if (func_L05_0035ACD8(m->b) != 0) {
                        func_L01_004450F0(m, 0xB, -1);
                    }
                }
            }
            break;
        case 1:
            if (func_L01_004561B8(m) != 0) {
                s16 s;
                pv->mp[0x3EC/4]->b[0x20] = 4;
                s = pv->h[0x3F4/2];
                pv->h[0x3F4/2] = 0;
                func_L01_0045BD78(m, 0.012f, 0.15f, 0.020943953f, 0.17453294f);
                func_L05_00355EE8((O_35EE8 *)m);
                pv->h[0x3F4/2] = s;
                if (pv->h[0x3DA/2] == 0) {
                    func_L01_00459188(m, pv->mp[0x230/4], pv->b + 0x250);
                }
            }
            if (pv->h[0x3DA/2] != 0) {
                func_L01_0045D218(m, pv->mp[0x230/4]->b + 0x10);
            } else {
                u8 *r = pv->b + 0x250;
                if (pv->mp[0x230/4] != pv->mp[0x2A0/4]) {
                    func_L01_00459188(m, pv->mp[0x230/4], r);
                }
                func_L01_00458F78(m, r, 0, 0);
                func_L01_0045A7A8(m, r, pv->f[0x3E8/4]);
            }
            break;
        case 4:
            sp10.q = pv->q[0x350/16];
            if (func_L05_00355D00(m->b, &sp10) < 0.75f) {
                pv->mp[0x3EC/4]->b[0x20] = 1;
                if ((func_L05_00355B30(m->b) == 0) && (func_L05_00355C48(m) == 0)) {
                    func_L01_004450F0(m, 0xD, -1);
                } else {
                    func_L01_004450F0(m, 0xB, -1);
                }
                if (func_L05_00355B30(m->b) == 0) {
                    m->i[0x48/4] = 0;
                }
                pv->mp[0x3EC/4]->i[0x48/4] = 0;
                pv->i[0x3DC/4] = 0;
            } else {
                s32 r;
                if (func_L01_004561B8(m) != 0) {
                    pv->mp[0x3EC/4]->b[0x20] = 4;
                    func_L05_00355EE8((O_35EE8 *)m);
                    if (pv->h[0x3DA/2] == 0) {
                        sp20.q = pv->q[0x350/16];
                        func_L01_004591B8(m, &sp20, pv->b + 0x250);
                    }
                }
                if (pv->h[0x3DA/2] != 0) {
                    r = ((s32 (*)(void *, void *))func_L01_0045D218)(m, pv->b + 0x350);
                } else {
                    func_L01_00458F78(m, pv->b + 0x250, 0, 0);
                    r = func_L01_0045A748(m, pv->b + 0x250);
                    if (func_L05_00355B30(m->b) != 0) {
                        if (pv->i[0x3E4/4] != 0) {
                            func_L05_00454940(m, pv->b + 0x220);
                        } else if (func_L01_0040E570(m->b + 0x10, pv->b + 0x350) < 25.0f) {
                            vec_sub_ab(&sp20, pv->b + 0x220, pv->b + 0x350);
                            func_L05_00454970(m, &sp20);
                        } else {
                            func_L05_00454940(m, pv->b + 0x350);
                        }
                    }
                }
                if (r & 3) {
                    pv->i[0xF0/4]++;
                }
                if (pv->i[0xF0/4] > 0x32) {
                    pv->q[0x350/16] = m->q[1];
                }
            }
            break;
        case 3:
            {
                s32 r;
                if (func_L01_004561B8(m) != 0) {
                    Path_60C8 *p;
                    pv->mp[0x3EC/4]->b[0x20] = 4;
                    func_L05_00355EE8((O_35EE8 *)m);
                    p = D_L05_0021ED80[pv->i[0x380/4]];
                    if (pv->h[0x3F6/2] != 0) {
                        f32 d;
                        u8 c;
                        sp10.q = p->pt[0];
                        d = func_L05_00355D00(m->b, &sp10);
                        sp20.q = *(u128_t *)((u8 *)p + p->n * 16);
                        c = f_lt_60C8(func_L05_00355D00(m->b, &sp20), d);
                        if (c) {
                            func_L01_0045C150(m, D_L05_0021ED80[pv->i[0x380/4]], 0, p->n - 1);
                        } else {
                            func_L01_0045C150(m, D_L05_0021ED80[pv->i[0x380/4]], p->n - 1, 0);
                        }
                        pv->h[0x3F6/2] = 0;
                    }
                }
                if (pv->h[0x3DA/2] != 0) {
                    r = func_L03_00449C30(m, pv->i[0x380/4]);
                } else {
                    r = func_L01_0045BDE8(m, pv->i[0x380/4]);
                }
                if (func_L05_00355B30(m->b) != 0) {
                    u8 *pf = pv->b + 0x70;
                    if (pv->i[0x3E4/4] != 0) {
                        func_L05_00454940(m, pv->b + 0x220);
                    } else if (func_L01_0040E570(m->b + 0x10, &D_L05_0021ED80[pv->i[0x380/4]]->pt[*(s16 *)(pf + 0xC8)]) < 25.0f) {
                        if (*(s16 *)(pf + 0xCA) < *(s16 *)(pf + 0xC8)) {
                            vec_sub_ba(&sp10, &D_L05_0021ED80[pv->i[0x380/4]]->pt[*(s16 *)(pf + 0xC8) - 1], &D_L05_0021ED80[pv->i[0x380/4]]->pt[*(s16 *)(pf + 0xC8)]);
                        } else if (*(s16 *)(pf + 0xC8) < *(s16 *)(pf + 0xCA)) {
                            vec_sub_ba(&sp10, &D_L05_0021ED80[pv->i[0x380/4]]->pt[*(s16 *)(pf + 0xC8) + 1], &D_L05_0021ED80[pv->i[0x380/4]]->pt[*(s16 *)(pf + 0xC8)]);
                        } else {
                            vec_sub_ab(&sp10, pv->b + 0x220, &D_L05_0021ED80[pv->i[0x380/4]]->pt[*(s16 *)(pf + 0xC8)]);
                        }
                        func_L05_00454970(m, &sp10);
                    } else {
                        func_L05_00454940(m, &D_L05_0021ED80[pv->i[0x380/4]]->pt[*(s16 *)(pf + 0xC8)]);
                    }
                }
                if (r != 0) {
                    pv->i[0x3DC/4] = 0;
                    pv->h[0x3F6/2] = 1;
                    if (func_L05_00355C70(m) != 0) {
                        if ((func_L05_00355B30(m->b) == 0) && (func_L05_00355C48(m) == 0)) {
                            func_L01_004450F0(m, 0xD, -1);
                        } else {
                            func_L01_004450F0(m, 0xB, -1);
                        }
                    } else {
                        func_L01_004450F0(m, 0xA, -1);
                    }
                }
            }
            break;
        case 2:
            {
                s32 r;
                if (func_L01_004561B8(m) != 0) {
                    Path_60C8 *p;
                    pv->mp[0x3EC/4]->b[0x20] = 4;
                    if ((pv->i[0x3F8/4] != 0) && (func_L05_00355B30(m->b) == 0) && (pv->i[0x3FC/4] == 0)) {
                        func_L01_004450F0(m, 0x11, -1);
                    } else {
                        func_L05_00355EE8((O_35EE8 *)m);
                    }
                    p = D_L05_0021ED80[pv->i[0x384/4]];
                    if (func_L05_00355B30(m->b) != 0) {
                        func_L01_0045BD78(m, 0.012f, pv->f[0x3BC/4] * 0.020000001f, 0.0069813174f, 0.17453294f);
                    }
                    if (pv->h[0x3F6/2] != 0) {
                        f32 d;
                        u8 c;
                        sp10.q = p->pt[0];
                        d = func_L05_00355D00(m->b, &sp10);
                        sp20.q = *(u128_t *)((u8 *)p + p->n * 16);
                        c = f_lt_60C8(func_L05_00355D00(m->b, &sp20), d);
                        if (c) {
                            func_L01_0045C150(m, D_L05_0021ED80[pv->i[0x384/4]], 0, p->n - 1);
                        } else {
                            func_L01_0045C150(m, D_L05_0021ED80[pv->i[0x384/4]], p->n - 1, 0);
                        }
                        pv->h[0x3F6/2] = 0;
                    }
                }
                if (pv->h[0x3DA/2] != 0) {
                    r = func_L03_00449C30(m, pv->i[0x384/4]);
                } else {
                    r = func_L01_0045BDE8(m, pv->i[0x384/4]);
                }
                if (func_L05_00355B30(m->b) != 0) {
                    u8 *pf = pv->b + 0x70;
                    if (pv->i[0x3E4/4] != 0) {
                        func_L05_00454940(m, pv->b + 0x220);
                    } else if (func_L01_0040E570(m->b + 0x10, &D_L05_0021ED80[pv->i[0x384/4]]->pt[*(s16 *)(pf + 0xC8)]) < 25.0f) {
                        if (*(s16 *)(pf + 0xCA) < *(s16 *)(pf + 0xC8)) {
                            vec_sub_ba(&sp10, &D_L05_0021ED80[pv->i[0x384/4]]->pt[*(s16 *)(pf + 0xC8) - 1], &D_L05_0021ED80[pv->i[0x384/4]]->pt[*(s16 *)(pf + 0xC8)]);
                        } else if (*(s16 *)(pf + 0xC8) < *(s16 *)(pf + 0xCA)) {
                            vec_sub_ba(&sp10, &D_L05_0021ED80[pv->i[0x384/4]]->pt[*(s16 *)(pf + 0xC8) + 1], &D_L05_0021ED80[pv->i[0x384/4]]->pt[*(s16 *)(pf + 0xC8)]);
                        } else {
                            vec_sub_ab(&sp10, pv->b + 0x220, &D_L05_0021ED80[pv->i[0x384/4]]->pt[*(s16 *)(pf + 0xC8)]);
                        }
                        func_L05_00454970(m, &sp10);
                    } else {
                        func_L05_00454940(m, &D_L05_0021ED80[pv->i[0x384/4]]->pt[*(s16 *)(pf + 0xC8)]);
                    }
                }
                if (r != 0) {
                    pv->h[0x3F6/2] = 1;
                    pv->i[0x384/4] = -1;
                    if (pv->h[0x40C/2] != 0) {
                        pv->h[0x3F4/2] = 0;
                    }
                    func_L05_0035AEC8(m);
                    func_L01_004450F0(m, 0xA, 2);
                    if ((pv->i[0x3F8/4] != 0) && (pv->i[0x3FC/4] == 0)) {
                        func_L01_004450F0(m, 0x12, -1);
                    }
                }
            }
            break;
        case 5:
            if (func_L01_004561B8(m) != 0) {
                pv->mp[0x3EC/4]->b[0x20] = 4;
                func_L05_00355EE8((O_35EE8 *)m);
                if (pv->i[0x38C/4] != -1) {
                    if ((((Zones_60C8 *)D_L05_001DF7CC)->a[pv->i[0x38C/4]].n != 0) && (pv->h[0x3F6/2] != 0)) {
                        s32 k;
                        pv->h[0x3F6/2] = 0;
                        *(u128_t *)(pv->b + 0x350) = *(u128_t *)((u8 *)D_L05_001DFC80 + (**(s32 **)(D_L05_001DF7CC + pv->i[0x38C/4] * 0x30 + 0x40) << 7) + 0x30);
                        for (k = 0; k < ((Zones_60C8 *)D_L05_001DF7CC)->a[pv->i[0x38C/4]].n; k++) {
                            Spot_60C8 *s = &D_L05_001DFC80[(*(s32 **)(D_L05_001DF7CC + pv->i[0x38C/4] * 0x30 + 0x40))[k]];
                            f32 d;
                            u8 c;
                            sp10.q = s->pos;
                            sp20.q = pv->q[0x220/16];
                            d = func_L05_00355C98(m, &sp10, &sp20);
                            sp30.q = pv->q[0x350/16];
                            sp40.q = *(u128_t *)(pv->b + 0x220);
                            {
                                s32 r = (func_L05_00355C98(m, &sp30, &sp40) < d)
                                    || (sp50.q = pv->q[0x350/16], func_L05_00355D00(m->b, &sp50) < 2.0f);
                                c = r;
                            }
                            if (c) {
                                sp60.q = s->pos;
                                if (func_L05_00355D00(m->b, &sp60) > 2.0f) {
                                    pv->q[0x350/16] = s->pos;
                                }
                            }
                        }
                    }
                }
            }
            if (func_L05_00355B30(m->b) != 0) {
                if (func_0038CF00(m->b + 0x10, pv->b + 0x350) < 1.0f) {
                    pv->i[0x3DC/4] = 0;
                    pv->h[0x3F6/2] = 1;
                    if (func_L05_00355C70(m) != 0) {
                        func_L01_004450F0(m, 0xB, -1);
                    } else {
                        func_L01_004450F0(m, 0xA, -1);
                    }
                } else {
                    func_L01_0045A748(m, pv->b + 0x350);
                    if (func_L05_00355B30(m->b) != 0) {
                        if (pv->i[0x3E4/4] != 0) {
                            func_L05_00454940(m, pv->b + 0x220);
                        } else if (func_L01_0040E570(m->b + 0x10, pv->b + 0x350) < 25.0f) {
                            vec_sub_ab(&sp10, pv->b + 0x220, pv->b + 0x350);
                            func_L05_00454970(m, &sp10);
                        } else {
                            func_L05_00454940(m, pv->b + 0x350);
                        }
                    }
                }
            } else if (func_0038CF38(m->b + 0x10, pv->b + 0x350) < 1.0f) {
                pv->i[0x3DC/4] = 0;
                pv->h[0x3F6/2] = 1;
                if (func_L05_00355C70(m) != 0) {
                    if (func_L05_00355C48(m) == 0) {
                        func_L01_004450F0(m, 0xD, -1);
                    } else {
                        func_L01_004450F0(m, 0xB, -1);
                    }
                } else {
                    func_L01_004450F0(m, 0xA, -1);
                }
            } else if (pv->h[0x3DA/2] != 0) {
                func_L01_0045D218(m, pv->b + 0x350);
            } else {
                func_L01_0045A748(m, pv->b + 0x350);
            }
            break;
        }
        if (pv->i[0x394/4] != 0) {
            if ((pv->mp[0x3EC/4]->b[0x60] & 2) && (pv->i[0x3E4/4] == 0) && (func_L05_0035AAC8(m) != 0)) {
                if ((func_L05_00355F60(m->b) != 0) && (func_L05_00355C70(m) != 0)) {
                    pv->mp[0x3EC/4]->b[0x20] = 3;
                    func_L05_00355FB0(m->b);
                    func_003C3A10(pv->mp[0x3EC/4], 7, 0, 4);
                    pv->mp[0x3EC/4]->f[0x48/4] = 2.0f;
                    pv->i[0x3E4/4] = 1;
                    pv->i[0x3DC/4] = 0;
                }
            } else if ((pv->i[0x3E4/4] == 1) && (pv->mp[0x3EC/4]->b[0x60] & 2)) {
                {
                    pv->mp[0x3EC/4]->b[0x20] = 3;
                    func_003C3A10(pv->mp[0x3EC/4], 8, 0, 0);
                    pv->mp[0x3EC/4]->f[0x48/4] = 2.0f;
                    pv->i[0x3E4/4] = 2;
                    func_L05_0035AD60(m);
                }
            } else if ((pv->i[0x3E4/4] == 2) && (pv->mp[0x3EC/4]->b[0x60] & 2)) {
                {
                    pv->mp[0x3EC/4]->b[0x20] = 3;
                    pv->i[0x3DC/4]++;
                    if (pv->i[0x3DC/4] >= 3) {
                        pv->mp[0x3EC/4]->b[0x20] = 4;
                        pv->i[0x3DC/4] = 0;
                        if (func_L05_00355B30(m->b) != 0) {
                            func_003C3A10(pv->mp[0x3EC/4], 2, 0, 0xC);
                        } else if (pv->h[0x3F4/2] != 0) {
                            func_003C3A10(pv->mp[0x3EC/4], 5, 0, 0xC);
                        } else {
                            func_003C3A10(pv->mp[0x3EC/4], 6, 0, 0xC);
                        }
                        pv->mp[0x3EC/4]->f[0x48/4] = 1.0f;
                        pv->i[0x3E4/4] = 3;
                    } else {
                        func_L05_0035AD60(m);
                    }
                }
            } else if ((pv->i[0x3E4/4] == 3) && (pv->mp[0x3EC/4]->b[0x60] & 2)) {
                {
                    pv->i[0x3E4/4] = 0;
                    func_L05_00356018(m->b);
                }
            }
        }
        if ((func_L05_00355B30(m->b) == 0) && (func_L05_00355E58(m->b, (Vec4 *)(pv->b + 0x220)) != 0)) {
            func_L01_004450F0(m, 0x10, -1);
        }
        break;
    case 11:
        if (func_L01_004561B8(m) != 0) {
            if (func_L05_00355B30(m->b) != 0) {
                func_003C3A10(pv->mp[0x3EC/4], 8, 0, 0x11);
            } else if ((pv->mp[0x3EC/4]->b[0x42] != 8) && (pv->mp[0x3EC/4]->b[0x42] != 0xC)
                       && (func_L05_00355BD8(m, pv->b + 0x220) == 0)) {
                if (func_L05_00355AE8(m) != 0) {
                    func_L05_0035AA68(m, 0xE, 0, 8);
                } else if (func_L05_00355C48(m) != 0) {
                    func_L05_0035AA68(m, 0xB, 0, 8);
                } else {
                    func_L01_004450F0(m, 0xD, -1);
                    break;
                }
            } else {
                if (((func_L05_00355D60(m, pv->mp[0x230/4]) < 8.0f) || (func_00382468(2) != 0)) && (func_L05_00355C48(m) != 0)) {
                    if (func_L05_00355AE8(m) == 0) {
                        func_L05_0035AA68(m, 0xB, 0, 8);
                    } else {
                        if ((pv->mp[0x3EC/4]->b[0x42] != 8) && (pv->mp[0x3EC/4]->b[0x42] != 0xC)) {
                            func_003C3A10(pv->mp[0x3EC/4], 7, 0, 8);
                        } else {
                            func_003C3A10(pv->mp[0x3EC/4], 0xC, 0, 8);
                        }
                        func_003C3A10(m, 0xC, 0, 8);
                    }
                } else if (func_L05_00355AE8(m) != 0) {
                    func_L05_0035AA68(m, 0xE, 0, 8);
                } else {
                    u8 c = pv->mp[0x3EC/4]->b[0x42];
                    if (c != 8) {
                        func_L05_0035AA68(m, 7, 0, 8);
                    } else {
                        func_003C3A10(pv->mp[0x3EC/4], 8, 0, 8);
                        if (m->b[0x42] != c) {
                            func_003C3A10(m, 7, 0, 8);
                        } else {
                            func_003C3A10(m, 8, 0, 8);
                        }
                    }
                }
            }
        }
        if (func_L05_00355B30(m->b) != 0) {
            func_L05_00454940(m, pv->b + 0x220);
            pv->mp[0x3EC/4]->b[0x20] = 2;
        }
        if (func_L05_00355B80(m) != 0) {
            sp10.q = pv->q[0x220/16];
            func_L05_00355DD8(m->b, (vu0_v4 *)&sp10);
            pv->mp[0x3EC/4]->b[0x20] = 0;
        } else {
            func_L01_003EBED0(m);
            pv->mp[0x3EC/4]->b[0x20] = 1;
        }
        if (func_L05_00355B30(m->b) != 0) {
            f = pv->mp[0x3EC/4]->b[0x60] & 2;
        } else {
            f = m->b[0x60] & 2;
        }
        if (f != 0) {
            if (func_L05_00355AE8(m) != 0) {
                func_L05_0035AA68(m, 0xC, 0, 0);
            } else {
                func_003C3A10(pv->mp[0x3EC/4], 8, 0, 0);
                if (func_L05_00355B30(m->b) == 0) {
                    func_003C3A10(m, 8, 0, 0);
                }
            }
            func_L01_004450F0(m, 0xC, -1);
        }
        break;
    case 12:
        {
            u8 *r;
            pv->mp[0x3EC/4]->b[0x20] = 3;
            pv->i[0x3DC/4] = 0;
            r = pv->b + 0x220;
            if (func_L05_00355B30(m->b) != 0) {
                func_L05_00454940(m, r);
            }
            if (func_L05_00355BD8(m, r) == 0) {
                sp10.q = pv->q[0x220/16];
                func_L05_00355DD8(m->b, (vu0_v4 *)&sp10);
            } else {
                func_L01_003EBED0(m);
            }
            if ((func_L05_00355B30(m->b) == 0) && (func_L05_00355E58(m->b, (Vec4 *)r) != 0)) {
                func_L01_004450F0(m, 0x10, -1);
                break;
            }
            if ((m->uh[0x96/2] >= 0x3F) && (func_L05_00355F60(m->b) != 0)) {
                func_L01_004450F0(m, 0xE, -1);
                func_L05_00355FB0(m->b);
                break;
            }
            if ((m->uh[0x96/2] < 0xFB) && (func_L05_0035AAC8(m) != 0)) {
                break;
            }
            if (pv->i[0x3E0/4] == 4) {
                sp10.q = pv->q[0x350/16];
                if (0.75f < func_L05_00355D00(m->b, &sp10)) {
                    func_L01_004450F0(m, 0xA, -1);
                } else {
                    func_L01_004450F0(m, 0xB, -1);
                }
            } else {
                func_L01_004450F0(m, 0xA, -1);
            }
            pv->h[0x3D8/2] = 0;
            func_L05_00356018(m->b);
        }
        break;
    case 13:
        if (func_L01_004561B8(m) != 0) {
            pv->mp[0x3EC/4]->b[0x20] = 4;
            if (func_L05_00355AE8(m) == 0) {
                pv->i[0x3E4/4] = 0;
                func_003C3A10(m, 0xB, 0, 8);
                func_003C3A10(pv->mp[0x3EC/4], 2, 0, 8);
            } else {
                pv->i[0x3E4/4] = 1;
                func_003C3A10(m, 0xC, 0, 8);
                func_003C3A10(pv->mp[0x3EC/4], 2, 0, 8);
            }
        }
        if ((func_L05_00355B80(m) != 0) || (func_L05_00355BD8(m, pv->b + 0x220) == 0)) {
            sp10.q = pv->q[0x220/16];
            func_L05_00355DD8(m->b, (vu0_v4 *)&sp10);
        } else {
            func_L01_003EBED0(m);
        }
        if ((pv->i[0x3E4/4] == 0) && (m->b[0x60] & 2)) {
            pv->i[0x3E4/4] = 1;
            func_003C3A10(m, 0xC, 0, 8);
            func_003C3A10(pv->mp[0x3EC/4], 2, 0, 8);
        } else if ((pv->i[0x3E4/4] == 1) && (m->uh[0x96/2] >= 0x65)) {
            if ((pv->b[0x5F] != 0) || ((m->b[0xBC] == 0) && (func_L05_0035ACD8(m->b) != 0))) {
                func_L05_00355FB0(m->b);
                if ((func_L05_00355C48(m) != 0)
                    && ((func_0038CF38(m->b + 0x10, pv->mp[0x230/4]->b + 0x10) < 8.0f) || (func_00382468(3) == 0))) {
                    func_003C3A10(m, 0xC, 0, 8);
                    func_003C3A10(pv->mp[0x3EC/4], 7, 0, 8);
                    pv->i[0x3E4/4] = 3;
                } else {
                    func_003C3A10(m, 0xE, 0, 8);
                    func_003C3A10(pv->mp[0x3EC/4], 7, 0, 8);
                    pv->i[0x3E4/4] = 3;
                }
            }
        } else if ((pv->i[0x3E4/4] == 2) && (m->b[0x60] & 2)) {
            {
                func_L05_0035AA68(m, 8, 0, 8);
                pv->i[0x3E4/4] = 3;
                m->f[0x48/4] = 1.0f;
                pv->mp[0x3EC/4]->f[0x48/4] = 1.0f;
            }
        } else if (pv->i[0x3E4/4] == 3) {
            if ((m->b[0x60] & 2) || (pv->mp[0x3EC/4]->b[0x60] & 2)) {
                if (func_L05_00355AE8(m) != 0) {
                    func_L05_0035AA68(m, 0xC, 0, 0);
                } else {
                    func_L05_0035AA68(m, 8, 0, 8);
                }
                func_L01_004450F0(m, 0xC, -1);
            }
        }
        break;
    case 14:
        if (func_L01_004561B8(m) != 0) {
            pv->i[0x3DC/4]++;
            func_L05_0035AD60(m);
            if (func_L05_00355B30(m->b) == 0) {
                if (func_L05_00355AE8(m) != 0) {
                    if (m->b[0x43] != 0xD) {
                        func_003C3A10(m, 0xD, 0, 0);
                    }
                } else if (m->b[0x43] != 9) {
                    func_003C3A10(m, 9, 0, 0);
                }
            }
            pv->mp[0x3EC/4]->f[0x48/4] = 12.0f;
            m->f[0x48/4] = 12.0f;
            if (pv->i[0x3DC/4] == 5) {
                func_003C3A10(pv->mp[0x3EC/4], 9, 0, 0);
                pv->mp[0x3EC/4]->f[0x48/4] = m->f[0x48/4] = 1.0f;
            }
        }
        if (func_L05_00355B30(m->b) != 0) {
            func_L05_00454940(m, pv->b + 0x220);
            pv->mp[0x3EC/4]->b[0x20] = 0;
        } else {
            func_L01_003EBED0(m);
        }
        if (func_L05_00355B30(m->b) != 0) {
            f = pv->mp[0x3EC/4]->b[0x60] & 2;
        } else {
            f = m->b[0x60] & 2;
        }
        if (f != 0) {
            if (pv->i[0x3DC/4] < 5) {
                func_L01_004450F0(m, 0xE, -1);
                break;
            }
            func_L05_00356018(m->b);
            pv->i[0x3DC/4] = 0;
            pv->h[0x3D8/2] = 0;
            if (pv->i[0x3E0/4] == 4) {
                if (func_L05_00355B30(m->b) != 0) {
                    func_L01_004450F0(m, 0xC, -1);
                    func_003C3A10(pv->mp[0x3EC/4], 8, 0, 2);
                } else if (func_L05_00355AE8(m) != 0) {
                    func_L01_004450F0(m, 0xC, -1);
                    func_L05_0035AA68(m, 0xC, 0, 2);
                    break;
                } else {
                    func_L05_0035AA68(m, 8, 0, 2);
                    if (func_L05_00355C48(m) == 0) {
                        func_L01_004450F0(m, 0xD, -1);
                    } else {
                        func_L01_004450F0(m, 0xC, -1);
                    }
                    break;
                }
            } else if (func_L05_00355B30(m->b) != 0) {
                func_003C3A10(pv->mp[0x3EC/4], 2, 0, 0x11);
            } else if (func_L05_00355AE8(m) != 0) {
                func_L05_0035AA68(m, 0xE, 0, 0);
            } else {
                func_L05_0035AA68(m, 0xA, 0, 0);
            }
            func_L01_004450F0(m, 0xF, -1);
        }
        break;
    case 15:
        if (func_L05_00355B30(m->b) != 0) {
            func_L05_00454940(m, pv->b + 0x220);
            pv->mp[0x3EC/4]->b[0x20] = 0;
        } else if (func_L05_00355B80(m) != 0) {
            sp10.q = pv->q[0x220/16];
            func_L05_00355DD8(m->b, (vu0_v4 *)&sp10);
        } else {
            func_L01_003EBED0(m);
        }
        if (pv->mp[0x3EC/4]->b[0x60] & 2) {
            func_L01_004450F0(m, 0xA, 2);
            if (func_L05_00355B30(m->b) == 0) {
                m->i[0x48/4] = 0;
            }
            pv->mp[0x3EC/4]->i[0x48/4] = 0;
        }
        break;
    case 16:
        if (func_L01_004561B8(m) != 0) {
            pv->mp[0x3EC/4]->b[0x20] = 0;
            func_L01_0045BD78(m, 0.012f, 0.15f, 0.020943953f, 0.17453294f);
            func_L01_00459188(m, pv->mp[0x230/4], pv->b + 0x250);
            pv->i[0x3E4/4] = 2;
            if ((m->b[0x42] != 0xF) && (m->b[0x43] != 0xF)) {
                func_L05_0035AA68(m, 0xF, 0, 2);
            }
            m->f[0x48/4] = 2.0f;
            pv->mp[0x3EC/4]->f[0x48/4] = 2.0f;
        }
        if (pv->i[0x3E4/4] == 0) {
            sp10.q = pv->q[0x220/16];
            func_L05_00355DD8(m->b, (vu0_v4 *)&sp10);
            if (m->b[0x60] & 2) {
                sp10.q = pv->q[0x220/16];
                if (func_L05_00355D00(m->b, &sp10) <= 2.5f) {
                    pv->i[0x3E4/4] = 2;
                    func_L05_0035AA68(m, 0xF, 0, 0);
                    m->f[0x48/4] = 2.0f;
                    pv->mp[0x3EC/4]->f[0x48/4] = 2.0f;
                } else {
                    pv->i[0x3E4/4] = 1;
                    func_L05_0035AA68(m, 6, 0, 0);
                }
            }
        } else if (pv->i[0x3E4/4] == 1) {
            if (pv->h[0x3DA/2] != 0) {
                func_L01_0045D218(m, pv->mp[0x230/4]->b + 0x10);
            } else {
                u8 *r = pv->b + 0x250;
                if (pv->mp[0x230/4] != pv->mp[0x2A0/4]) {
                    func_L01_00459188(m, pv->mp[0x230/4], r);
                }
                func_L01_00458F78(m, r, 0, 0);
                func_L01_0045A748(m, r);
            }
            sp10.q = pv->q[0x220/16];
            if (func_L05_00355D00(m->b, &sp10) <= 2.5f) {
                pv->i[0x3E4/4] = 2;
                func_L05_0035AA68(m, 0xF, 0, 0);
                m->f[0x48/4] = 2.0f;
                pv->mp[0x3EC/4]->f[0x48/4] = 2.0f;
            }
        } else if (pv->i[0x3E4/4] == 2) {
            f32 a = func_L01_004395E0(m);
            sp10.q = pv->q[0x220/16];
            func_L05_00355DD8(m->b, (vu0_v4 *)&sp10);
            if ((a > 15.0f) && (a < 20.0f)) {
                func_003C2F58(pv->mp[0x3EC/4], 0, &sp20);
                func_003C2F58(pv->mp[0x3EC/4], 1, &sp10);
                vec_add_ab(&sp30, &sp10, &sp20);
                func_0038CE20(&sp30, &sp30, 0.5f);
                func_L01_00446780(m, 1.3f, &sp30, (pv->b[0x5F] != 0) ? 0x10001 : 1, (f32)pv->b[0x45], 1.5f, 0, 1, 0);
            }
            if (pv->mp[0x3EC/4]->b[0x60] & 2) {
                if (m->b[0x94] == 0xE) {
                    m->b[0x94] = 0xF;
                } else if (m->b[0x94] == 0xC) {
                    m->b[0x94] = 0xB;
                }
                func_L01_004450F0(m, m->b[0x94], -1);
            }
        }
        break;
    case 17:
        if (func_L01_004561B8(m) != 0) {
            pv->mp[0x3EC/4]->b[0x20] = 4;
            func_003C3A10(m, 0x12, 0, 8);
            func_003C3A10(pv->mp[0x3EC/4], 2, 0, 8);
            pv->i[0xA8/4] |= 0x414;
        }
        func_L01_003EBED0(m);
        if (m->b[0x60] & 2) {
            func_003C3A10(m, 0x13, 0, 8);
            func_L01_004450F0(m, m->b[0x94], -1);
        }
        break;
    case 18:
        if (func_L01_004561B8(m) != 0) {
            pv->mp[0x3EC/4]->b[0x20] = 4;
            func_003C3A10(pv->mp[0x3EC/4], 2, 0, 8);
            pv->i[0xA8/4] &= ~0x414;
        }
        func_L01_0045A9F0(m);
        if ((m->b[0x42] != 0x14) && (m->b[0x43] != 0x14)) {
            if ((m->f[0x18/4] - pv->f[0x100/4]) < 0.05f) {
                func_003C3A10(m, 0x14, 0, 8);
            }
        } else if (m->b[0x60] & 2) {
            func_L01_004450F0(m, m->b[0x94], -1);
            m->i[0x48/4] = 0;
            pv->mp[0x3EC/4]->i[0x48/4] = 0;
        }
        break;
    }
    if ((func_L05_00355B30(m->b) != 0) && (pv != 0) && (pv->mp[0x3EC/4] != 0)) {
        pv->mp[0x3EC/4]->b[0x20] &= 0xFE;
    }
    func_L05_00358FF8(m);
    func_L05_0035A880(m);
}
