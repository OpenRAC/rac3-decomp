#include "common.h"
#include "vu0.h"

typedef struct { u8 pad[0x3EC]; void *x3EC; u8 pad2[4]; s16 x3F4; } V_35EE8;
typedef struct { u8 pad[0x68]; V_35EE8 *x68; } O_35EE8;

/* localdecomp:start func_L05_00355DD8 */
extern f32 func_0038D160(f32, f32);
extern void func_L01_0045AA10(void *, f32);
extern void func_L01_0045D218(void *, void *);

void func_L05_00355DD8(u8 *a0, vu0_v4 *pt) {
    vu0_v4 p = *pt;
    vu0_v4 d;
    if (*(s16 *)(*(u8 **)(a0 + 0x68) + 0x3DA) == 0) {
        f32 x = p.x;
        f32 y = p.y;
        func_L01_0045AA10(a0, func_0038D160(x - *(f32 *)(a0 + 0x10), y - *(f32 *)(a0 + 0x14)));
    } else {
        vec_sub_ab(&d, &p, a0 + 0x10);
        func_L01_0045D218(a0, a0 + 0x10);
    }
}
/* localdecomp:end func_L05_00355DD8 */

/* localdecomp:start func_L05_00355E58 */
typedef int u128_t __attribute__((mode(TI)));
typedef union { u128_t q; f32 f[4]; } Vec4;
extern f32 func_L05_00355D00(u8 *, Vec4 *);
extern s32 func_L02_003E6F38(f32, f32, f32);
s32 func_L05_00355E58(u8 *a0, Vec4 *a1) {
    s32 r = 0;
    Vec4 v;
    v = *a1;
    if (func_L05_00355D00(a0, &v) < 3.0f) {
        r = func_L02_003E6F38(*(f32 *)(a0 + 24) + 1.0f, a1->f[2], 1.5f) != 0;
    }
    return r;
}
/* localdecomp:end func_L05_00355E58 */

/* localdecomp:start func_L05_00355EE8 */
extern s32 func_L05_00355B30(u8 *a0);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L05_0035AA68();

void func_L05_00355EE8(O_35EE8 *o) {
    V_35EE8 *v = o->x68;
    if (func_L05_00355B30((u8 *)o) == 0) {
        if (v->x3F4 != 0) {
            func_L05_0035AA68(o, 5, 0, 8);
        } else {
            func_L05_0035AA68(o, 6, 0, 8);
        }
    } else {
        func_003C3A10(v->x3EC, 5, 0, 8);
    }
}
/* localdecomp:end func_L05_00355EE8 */

/* localdecomp:start func_L05_00355F60 */
extern s32 func_L05_0035AC08(u8 *);
extern s32 func_L05_0035ACD8(u8 *);

s32 func_L05_00355F60(u8 *obj) {
    s32 ret;
    if ((*(u8 **)(obj + 104))[95] != 0) {
        return func_L05_0035AC08(obj);
    }
    ret = 0;
    if (obj[188] == 0) {
        ret = func_L05_0035ACD8(obj) != 0;
    }
    return ret;
}
/* localdecomp:end func_L05_00355F60 */

/* localdecomp:start func_L05_00355FB0 */
extern s32 D_L05_001DFBD8;
extern void *D_L05_0021DAE0[];
extern void func_L01_00445BE0(s32, s32);
void func_L05_00355FB0(u8 *a0) {
    if (a0[188] == 0) {
        s32 i = a0[33];
        if (i < D_L05_001DFBD8 && D_L05_0021DAE0[i] != 0) {
            func_L01_00445BE0(i, 1);
            a0[188] = 0;
        }
    }
}
/* localdecomp:end func_L05_00355FB0 */

/* localdecomp:start func_L05_00356018 */
extern void *D_L05_0021DAE0[];
extern s32 D_L05_001DFBD8;
extern void func_L01_00445BE0(s32, s32);
void func_L05_00356018(u8 *a0) {
    if (a0[188] == 0) {
        u8 i = a0[33];
        if (i < D_L05_001DFBD8 && ((s32 *)&D_L05_0021DAE0)[i] != 0) {
            func_L01_00445BE0(i, 0);
        }
    }
}
/* localdecomp:end func_L05_00356018 */

/* localdecomp:start func_L05_00356070 */
extern f32 D_L05_001DF6CC;
extern f32 D_L05_001DF6D0;

s32 func_L05_00356070(f32 fparg0) {
    s32 var_v0;

    var_v0 = 0;
    if ((D_L05_001DF6D0 < fparg0) && (D_L05_001DF6CC < fparg0)) {
        var_v0 = 1;
    }
    return var_v0;
}
/* localdecomp:end func_L05_00356070 */

/* localdecomp:start func_L05_003560A8 */
__asm__(".extern D_L05_001DD600, 8");
extern u8 D_L05_001DD600[8];
u8 *func_L05_003560A8(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 2) {
        *a2 = 12;
        return D_L05_001DD600;
    }
    return 0;
}
/* localdecomp:end func_L05_003560A8 */

/* localdecomp:start func_L05_003560C8 */
typedef union Mo_60C8_ { u8 b[0x100]; s8 c[0x100]; s16 h[0x80]; u16 uh[0x80]; s32 i[0x40]; u32 u[0x40]; f32 f[0x40]; void *p[0x40]; union Pv_60C8_ *pv[0x40]; union Mo_60C8_ *mp[0x40]; u128_t q[0x10]; } Mo_60C8;
typedef union Pv_60C8_ { u8 b[0x420]; s8 c[0x420]; s16 h[0x210]; u16 uh[0x210]; s32 i[0x108]; u32 u[0x108]; f32 f[0x108]; void *p[0x108]; Mo_60C8 *mp[0x108]; u128_t q[0x42]; } Pv_60C8;
typedef struct { s32 n; s32 pad[3]; u128_t pt[1]; } Path_60C8;
typedef struct { u8 x0[2]; s16 n; u8 x4[0xC]; s32 *list; u8 x14[0x1C]; } Area_60C8;
typedef struct { u8 x0[0x30]; Area_60C8 a[1]; } Zones_60C8;
typedef struct { u8 x0[0x30]; u128_t pos; u8 x40[0x40]; } Spot_60C8;

extern s32 D_L05_001DFBD8;
extern void *D_L05_0021DAE0[];
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0045D218(void *, void *);
extern s32 func_L05_00355B30(u8 *);
extern f32 func_L05_00355D00(u8 *, Vec4 *);
extern s32 func_L05_00355E58(u8 *, Vec4 *);
extern s32 func_L05_00355F60(u8 *);
extern void func_L05_00355FB0(u8 *);
extern void func_L05_00356018(u8 *);
extern void func_L05_0035AA68();
extern s32 func_L05_0035ACD8(u8 *);
extern void func_L05_00355EE8(O_35EE8 *);
extern s32 func_L05_00359878(u8 *);
extern void func_L01_004AA7E8(Mo_60C8 *, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L05_0035A568(u8 *, s32);
extern void func_003C2880(u8 *);
extern s32 func_L01_004561E0(Mo_60C8 *);
extern s32 func_00382498(s32, s32);
extern s32 func_0038CB00_003560C8(void *);
extern s32 func_0038CAD0_003560C8(void *);
extern s32 func_L01_0045D218_003560C8(void *, void *);
extern s32 func_L05_00355DD8_003560C8(u8 *, vu0_v4 *);
extern void func_L01_004450F0(void *, s32, s32);
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
extern s32 func_L05_0035AAC8();
extern s32 func_L05_00355C70(Mo_60C8 *);
extern s32 func_L05_00355C48(Mo_60C8 *);
extern s32 func_L05_00355AE8(void *);
extern void func_L01_004591B8(Mo_60C8 *, Vec4 *, u8 *);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L05_0035AEC8(Mo_60C8 *);
extern f32 func_L05_00355C98(Mo_60C8 *, Vec4 *, Vec4 *);
extern void func_L05_0035AD60(u8 *);
extern s32 func_L05_00355BD8();
extern s32 func_L05_00355B80(void *);
extern s32 func_L01_003EBED0(Mo_60C8 *);
extern f32 func_L05_00355D60(Mo_60C8 *, Mo_60C8 *);
extern void func_003C2F58(s32, s32, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00446780(Mo_60C8 *, f32, Vec4 *, s32, f32, f32, s32, s32, s32);
extern void func_L05_00358FF8();
extern void func_L05_0035A880(u8 *);

extern s32 D_L05_001D6694;
extern s32 D_001D545C;
extern s32 D_L05_001DBBE0;
extern s32 D_L05_001DF6C0;
extern u8 *D_L05_001DFB9C;
extern Path_60C8 *D_L05_0021ED80[];
extern u8 *D_L05_001DF7CC;
extern Spot_60C8 *D_L05_001DFC80;

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
    if (func_L05_00359878(m->b) != 0) {
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
        func_003C2880(m->b);
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
        if ((pv->h[0x234/2] == 1) && (func_0038CB00_003560C8(pv->b + 0x3D6) != 0)) {
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
            if (func_0038CAD0_003560C8(pv->b + 0x3C4) != 0) {
                func_L01_00409598(m, m->b + 0x10, m->b + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                func_L01_00409598(pv->mp[0x3EC/4], pv->mp[0x3EC/4]->b + 0x10, pv->mp[0x3EC/4]->b + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                pv->i[0x3A0/4] = 0;
                func_L01_004450F0(m, 0xA, 2);
            }
        } else if (pv->h[0x234/2] == 1) {
            func_L01_004450F0(m, 0xA, 2);
        } else if (func_0038CAD0_003560C8(pv->b + 0x3D0) != 0) {
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
                func_003C2880(m->b);
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
                {
                    s32 t = func_L05_00355D00(m->b, &sp20) < d;
                    c = t;
                }
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
                if (func_0038CAD0_003560C8(pv->b + 0x3C4) != 0) {
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
            if (func_0038CAD0_003560C8(pv->b + 0x3C4) != 0) {
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
                            if ((e->h[0xAA/2] == 0x1625) && (e->pv[0x68/4] != 0)) {
                                e->pv[0x68/4]->i[0x39C/4]--;
                            }
                            q++;
                        }
                    }
                }
                if (pv->i[0x3E4/4] == 0) {
                    break;
                }
            }
            if (func_0038CAD0_003560C8(pv->b + 0x3C4) != 0) {
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
                    r = func_L01_0045D218_003560C8(m, pv->b + 0x350);
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
                        {
                            s32 t = func_L05_00355D00(m->b, &sp20) < d;
                            c = t;
                        }
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
                        if (*(s16 *)(pf + 0xC8) > *(s16 *)(pf + 0xCA)) {
                            vec_sub_ab(&sp10, &D_L05_0021ED80[pv->i[0x380/4]]->pt[*(s16 *)(pf + 0xC8) - 1], &D_L05_0021ED80[pv->i[0x380/4]]->pt[*(s16 *)(pf + 0xC8)]);
                        } else if (*(s16 *)(pf + 0xCA) > *(s16 *)(pf + 0xC8)) {
                            vec_sub_ab(&sp10, &D_L05_0021ED80[pv->i[0x380/4]]->pt[*(s16 *)(pf + 0xC8) + 1], &D_L05_0021ED80[pv->i[0x380/4]]->pt[*(s16 *)(pf + 0xC8)]);
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
                        {
                            s32 t = func_L05_00355D00(m->b, &sp20) < d;
                            c = t;
                        }
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
                        if (*(s16 *)(pf + 0xC8) > *(s16 *)(pf + 0xCA)) {
                            vec_sub_ab(&sp10, &D_L05_0021ED80[pv->i[0x384/4]]->pt[*(s16 *)(pf + 0xC8) - 1], &D_L05_0021ED80[pv->i[0x384/4]]->pt[*(s16 *)(pf + 0xC8)]);
                        } else if (*(s16 *)(pf + 0xCA) > *(s16 *)(pf + 0xC8)) {
                            vec_sub_ab(&sp10, &D_L05_0021ED80[pv->i[0x384/4]]->pt[*(s16 *)(pf + 0xC8) + 1], &D_L05_0021ED80[pv->i[0x384/4]]->pt[*(s16 *)(pf + 0xC8)]);
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
                    func_L05_0035AD60(m->b);
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
                        func_L05_0035AD60(m->b);
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
            func_L05_00355DD8_003560C8(m->b, (vu0_v4 *)&sp10);
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
            pv->mp[0x3EC/4]->b[0x20] = 3;
            pv->i[0x3DC/4] = 0;
            if (func_L05_00355B30(m->b) != 0) {
                func_L05_00454940(m, pv->b + 0x220);
            }
            if (func_L05_00355BD8(m, pv->b + 0x220) == 0) {
                sp10.q = pv->q[0x220/16];
                func_L05_00355DD8_003560C8(m->b, (vu0_v4 *)&sp10);
            } else {
                func_L01_003EBED0(m);
            }
            if ((func_L05_00355B30(m->b) == 0) && (func_L05_00355E58(m->b, (Vec4 *)(pv->b + 0x220)) != 0)) {
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
            func_L05_00355DD8_003560C8(m->b, (vu0_v4 *)&sp10);
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
            func_L05_0035AD60(m->b);
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
            func_L05_00355DD8_003560C8(m->b, (vu0_v4 *)&sp10);
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
            func_L05_00355DD8_003560C8(m->b, (vu0_v4 *)&sp10);
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
            func_L05_00355DD8_003560C8(m->b, (vu0_v4 *)&sp10);
            if ((a > 15.0f) && (a < 20.0f)) {
                func_003C2F58((s32)pv->mp[0x3EC/4], 0, &sp20);
                func_003C2F58((s32)pv->mp[0x3EC/4], 1, &sp10);
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
    func_L05_0035A880(m->b);
}
/* localdecomp:end func_L05_003560C8 */

/* localdecomp:start func_L05_00358FF8 */
typedef struct {
    vu0_v4 v00, v10, v20, v30, v40, v50, v60, v70;
} C_00358FF8;

typedef struct {
    u8 p0[0x10];
    vu0_v4 pos;
    u8 flags;
    u8 p21[0x9F];
    vu0_v4 vC0;
    vu0_v4 vD0;
    vu0_v4 vE0;
    vu0_v4 vF0;
} Q_00358FF8;

typedef struct {
    u8 p0;
    u8 b1;
    u8 p2[0xE];
    vu0_v4 v10;
    u8 p20[0xC];
    f32 f2C;
    u8 p30[0xC];
    f32 f3C;
} R_00358FF8;

typedef struct {
    u8 p0[0x220];
    vu0_v4 v220;
    u8 p230[0x1BC];
    Q_00358FF8 *q;
    u8 p3F0[0x18];
    s16 h408;
    s16 h40A;
    u8 p40C[4];
    R_00358FF8 r;
} P_00358FF8;

typedef struct {
    u8 p0[0x10];
    vu0_v4 pos;
    u8 p20[0xC];
    f32 f2C;
    u8 p30[4];
    u16 h34;
    u8 p36[0x32];
    P_00358FF8 *p;
    u8 p6C[0x54];
    vu0_v4 vC0;
    vu0_v4 vD0;
    vu0_v4 vE0;
    vu0_v4 vF0;
} M_00358FF8;

extern f32 D_L05_001DD60C;
extern f32 D_L05_001DD610;
extern f32 D_L05_001DD614;
extern f32 D_L05_001DD618;
extern f32 D_L05_001DD61C;
extern f32 D_L05_001DD620;
extern f32 D_L05_001DD624;
__asm__(".extern D_L05_001DD60C, 4");
__asm__(".extern D_L05_001DD610, 4");
__asm__(".extern D_L05_001DD614, 4");
__asm__(".extern D_L05_001DD618, 4");
__asm__(".extern D_L05_001DD61C, 4");
__asm__(".extern D_L05_001DD620, 4");
__asm__(".extern D_L05_001DD624, 4");

extern void func_0038D308(void *, void *);
extern void func_003CA4A0(void *, s32, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D570(void *, void *);
extern void func_0038D640(void *, void *, void *);
extern f32 func_L01_0040E4C0(void *);
extern s32 func_L02_003E6F38(f32, f32, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern s32 func_L05_00355B80(void *);
extern s32 func_L05_00355AE8(void *);
extern void func_L01_0040EE50(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0043A430(void *, s32, void *);
extern f32 func_L01_00448728(f32 *, f32, f32 *, f32, f32, f32, s32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);

void func_L05_00358FF8(M_00358FF8 *m) {
    P_00358FF8 *p;
    Q_00358FF8 *q;
    R_00358FF8 *r;
    s16 *st;
    C_00358FF8 c;
    vu0_v4 v80, v90, vA0, vB0, vC0, vD0, vE0;
    s32 loc;
    f32 fa, fb;
    f32 f20, f21, f22, f23, len, dot, lenA, lenB;
    vu0_v4 *pc;

    p = m->p;
    q = p->q;
    st = &p->h40A;
    if (!(m->h34 & 0x100)) {
        func_0038D308(&m->vC0, &m->vF0);
    }
    if (q->flags & 8) {
        qzero(&q->vF0);
        q->flags &= 0xFC;
        p->h40A = 0;
        p->h408 = 0;
    }
    loc = 0;
    func_003CA4A0(m, 1, &loc, &c);
    func_0038CE20(&c.v30, &c.v30, m->f2C * 0.0009765625f);
    func_0038D570(&c.v40, &m->vC0);
    c.v70 = m->pos;
    func_0038D640(&c, &c.v40, &c);
    q->pos = c.v30;
    if (q->flags & 0x10) {
        return;
    }
    if (q->flags & 4) {
        v80 = c.v20;
        if (p->h408 != 1) {
            vA0 = q->vE0;
            vec_sub_ab(&vB0, &v80, &vA0);
            lenA = func_L01_0040E4C0(&vB0);
            f20 = (((D_L05_001DD624 * 5.0f + 2.0f) / 6.0f) * ((D_L05_001DD624 * 5.0f + 2.0f) / 6.0f));
            if (func_L02_003E6F38(0.0f, lenA, f20)) {
                p->h408 = 1;
            } else {
                p->h408 = 0;
                func_0038CE20(&vB0, &vB0, sqrt_asm(f20 / lenA));
                vec_add_ab(&v80, &vB0, &vA0);
                func_0038CF68(&v80, &v80, 1.0f);
            }
        }
    } else {
        v80 = c.v60;
        if (p->h408 != 2) {
            vA0 = q->vE0;
            vec_sub_ab(&vB0, &v80, &vA0);
            lenB = func_L01_0040E4C0(&vB0);
            f20 = (((D_L05_001DD624 * 5.0f + 2.0f) / 6.0f) * ((D_L05_001DD624 * 5.0f + 2.0f) / 6.0f));
            if (func_L02_003E6F38(0.0f, lenB, f20)) {
                p->h408 = 2;
            } else {
                p->h408 = 0;
                func_0038CE20(&vB0, &vB0, sqrt_asm(f20 / lenB));
                vec_add_ab(&v80, &vB0, &vA0);
                func_0038CF68(&v80, &v80, 1.0f);
            }
        }
    }
    *(vu0_q *)&q->vE0 = *(vu0_q *)&v80;
    f21 = (((D_L05_001DD61C * 5.0f + 2.0f) / 6.0f) * ((D_L05_001DD61C * 5.0f + 2.0f) / 6.0f));
    if (func_L05_00355B80(q)) {
        f21 = f21 * 4.0f;
    }
    if (q->flags & 1) {
        vec_sub_ba(&v90, &p->v220, &q->pos);
        f23 = 0.0f;
        dot = func_0038CE68(&v80, &v90);
        func_0038CE20(&vA0, &v80, dot);
        vec_sub_ba(&v90, &v90, &vA0);
        vB0 = c.v40;
        dot = func_0038CE68(&v80, &vB0);
        func_0038CE20(&vA0, &v80, dot);
        vec_sub_ab(&vB0, &vB0, &vA0);
        f20 = func_0038CE68(&vB0, &v90);
        if (f20 < f23) {
            dot = func_L01_0040E4C0(&vB0);
            func_0038CE20(&vA0, &vB0, f20 / dot);
            vec_sub_ab(&v90, &v90, &vA0);
        }
        f22 = 1.0f;
        func_0038CF68(&v90, &v90, f22);
        vC0 = q->vC0;
        dot = func_0038CE68(&v90, &vC0);
        if (dot < 0.96f) {
            *st = 0;
        }
        if (*st != 2) {
            dot = func_0038CE68(&v80, &vC0);
            func_0038CE20(&vA0, &v80, dot);
            vec_sub_ba(&vC0, &vC0, &vA0);
            func_0038CF68(&vC0, &vC0, f22);
            vec_sub_ab(&vD0, &v90, &vC0);
            f20 = func_L01_0040E4C0(&vD0);
            if (func_L02_003E6F38(f23, f20, f21)) {
                *st = 2;
            } else {
                *st = 0;
                func_0038CE20(&vD0, &vD0, sqrt_asm(f21 / f20));
                vec_add_ab(&v90, &vD0, &vC0);
                func_0038CF68(&v90, &v90, f22);
            }
        }
    } else {
        if (q->flags & 4) {
            v90 = c.v00;
        } else {
            v90 = c.v40;
        }
        f22 = 1.0f;
        dot = func_0038CE68(&v80, &v90);
        func_0038CE20(&vA0, &v80, dot);
        vec_sub_ab(&v90, &v90, &vA0);
        func_0038CF68(&v90, &v90, f22);
        if (*st != 1) {
            vB0 = q->vC0;
            dot = func_0038CE68(&v80, &vB0);
            func_0038CE20(&vA0, &v80, dot);
            vec_sub_ba(&vB0, &vB0, &vA0);
            func_0038CF68(&vB0, &vB0, f22);
            vec_sub_ab(&vC0, &v90, &vB0);
            len = func_L01_0040E4C0(&vC0);
            f20 = (((D_L05_001DD620 * 5.0f + 2.0f) / 6.0f) * ((D_L05_001DD620 * 5.0f + 2.0f) / 6.0f));
            if (func_L02_003E6F38(0.0f, len, f20)) {
                *st = 1;
            } else {
                *st = 0;
                func_0038CE20(&vC0, &vC0, sqrt_asm(f20 / len));
                vec_add_ab(&v90, &vC0, &vB0);
                func_0038CF68(&v90, &v90, f22);
            }
        }
    }
    q->vC0 = v90;
    pc = &q->vC0;
    func_0038CE90(&q->vD0, &v90, &v80);
    r = &p->r;
    f21 = 0.0f;
    if (q->flags & 2) {
        func_L01_0040EE50(&vA0, pc);
        f20 = D_L05_001DD60C;
        if (func_L05_00355AE8(m)) {
            f20 = D_L05_001DD610;
        }
        func_0038CE20(&vD0, &m->vE0, f20);
        vec_add_ba(&vE0, &vD0, &m->pos);
        vec_sub_ba(&vD0, &p->v220, &vE0);
        func_0038CF68(&vD0, &vD0, 1.0f);
        func_0038D000(&vD0, &vD0, &vA0);
        if (vD0.x < D_L05_001DD618) {
            if (vD0.z < 0.0f) {
                f21 = -D_L05_001DD614;
            } else {
                f21 = D_L05_001DD614;
            }
        } else {
            f21 = func_0038D160(vD0.x, vD0.z);
        }
        f21 = f21 * 0.5f;
    }
    if (r->b1 == 0) {
        func_L01_0043A430(q, 5, r);
    }
    fa = r->f2C;
    fb = r->f3C;
    func_L01_00448728(&fa, f21, &fb, 0.369333357f, 0.693333387f, 0.0f, 0);
    r->f2C = fa;
    r->f3C = fb;
    loc = 5;
    func_003CA4A0(q, 1, &loc, &c);
    func_L01_0040EE50(&vA0, &c);
    r->v10 = vB0;
    func_0038CE20(&r->v10, &r->v10, func_0038D0B0(fa));
    r->v10.w = func_0038D098(fa);
}
/* localdecomp:end func_L05_00358FF8 */

/* localdecomp:start func_L05_00359878 */
typedef struct {
    u8 p0[0x20];
    u8 b20;
    u8 p21[0x30 - 0x21];
    unsigned long q30;
    u8 p38[0x43 - 0x38];
    u8 b43;
    u8 p44[0x62 - 0x44];
    u8 b62;
    u8 p63[0x68 - 0x63];
    void *p68;
    u8 p6C[0x94 - 0x6C];
    u8 b94;
    u8 b95;
    u8 p96[2];
    s32 w98;
    u8 p9C[0xA8 - 0x9C];
    u8 bA8;
} M_359878;

typedef struct {
    u8 p0[0x30];
    f32 f30;
    u8 p34[0x3E - 0x34];
    u8 b3E;
    u8 p3F[0x5E - 0x3F];
    u8 b5E;
    u8 b5F;
    u8 b60;
    u8 p61[0x160 - 0x61];
    u8 x160[0x370 - 0x160];
    s32 w370;
    f32 f374;
    s32 w378;
    f32 f37C;
    u8 p380[0x3D8 - 0x380];
    s16 h3D8;
    s16 h3DA;
    u8 p3DC[0x3EC - 0x3DC];
    M_359878 *x3EC;
    u8 p3F0[0x3FC - 0x3F0];
    s32 w3FC;
} C_359878;

extern s32 D_001D545C;
extern s32 func_L05_00359C78(u8 *);
extern void func_L05_0035A568(u8 *, s32);
extern void func_L05_0035A980(u8 *);
extern void func_L05_00356018(u8 *);
extern void func_003C2880(u8 *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C6FB0(void *, s32 *, s32 *, s32 *);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, f32, void *, s32, s32, s32, s32, s32, f32, f32, s32, s32);

s32 func_L05_00359878(u8 *a0) {
    M_359878 *m = (M_359878 *)a0;
    C_359878 *c = (C_359878 *)m->p68;
    s32 v[3];
    s32 r;
    s32 s5;
    u8 save;
    f32 f;

    if (m->b20 == 0 && func_L05_00359C78(a0) != 0) {
        return 1;
    }
    if (D_001D545C == 0xE) {
        m->b62 = 0;
        if (c->x3EC != 0) {
            c->x3EC->b62 = 0;
        }
    }
    if (c->b60 != 0 || c->b5E != 0 || c->b3E == 2) {
        func_L05_0035A568(a0, 0);
        func_003C2880(a0);
        return 1;
    }
    s5 = func_L05_00355B30(a0);
    f = c->f30;
    save = m->b94;
    r = func_L01_00452FB0(m, c->x160, 0, 0, c->h3DA);
    if (f != c->f30) {
        func_L05_0035A980(a0);
    }
    if (r != 0) {
        if (r != 1) {
            if (m->b94 == 2 || m->b94 == 0x10 || m->b94 == 0x11 || m->b94 == 0x12) {
                m->b94 = save;
            }
            if (m->b94 == 0xE) {
                m->b94 = 0xF;
            } else if (m->b94 == 0xC) {
                m->b94 = 0xB;
            }
            if (m->b43 < 0x12) {
                func_003C3A10(c->x3EC, m->b43, 0, 2);
            }
            if (s5 != 0 || c->w3FC != 0) {
                func_003C3A10(m, 0x13, 0, 0);
            }
        }
    }
    m->bA8 = 0xFF;
    if (c->x3EC != 0) {
        func_003C6FB0(m, &v[0], &v[1], &v[2]);
        func_L01_0043B9E8(c->x3EC, v[0], v[1], v[2]);
    }
    func_L01_00452860(m, &c->f30, 0);
    if (c->b5F != 0) {
        func_L05_00356018(a0);
        if ((m->q30 & 0x104100000000UL) != 0x4100000000UL || m->w98 != 0) {
            if (c->f30 > 0.0f) {
                func_L01_00456BD0(m, 5);
            }
        }
        if (m->b95 == 0) {
            func_L01_00456C98(m, c->w370, c->f374, 0, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
            return 0;
        } else {
            func_L01_00456C98(m, c->w378, c->f37C, 0, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
        }
        return 0;
    }
    if ((m->q30 & 0x104100000000UL) != 0x4100000000UL || m->w98 != 0) {
        if (c->f30 > 0.0f) {
            func_L01_00456BD0(m, 3);
        }
    }
    if (c->h3D8 != 0) {
        func_L01_00456C98(m, -1, 255.0f, 0, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 0);
    } else if (m->b95 == 0) {
        func_L01_00456C98(m, c->w370, c->f374, 0, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 0);
    } else {
        func_L01_00456C98(m, c->w378, c->f37C, 0, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L05_00359878 */

INCLUDE_ASM("asm/levels", func_L05_00359C78);

/* localdecomp:start func_L05_0035A2B0 */
extern s32 D_L05_001DFBD8_0035A2B0;
__asm__(".extern D_L05_001DFBD8_0035A2B0, 16");
extern u8 *D_L05_001DFB9C_0035A2B0;
__asm__(".extern D_L05_001DFB9C_0035A2B0, 16");
extern u16 *D_L05_0021DAE0_0035A2B0[];

u8 *func_L05_0035A2B0(s32 n) {
    u16 *p;
    u8 *e;
    p = D_L05_0021DAE0_0035A2B0[n];
    for (;;) {
        if ((n & 0xFF) == 0xFF) break;
        if (D_L05_001DFBD8_0035A2B0 < n) break;
        if (p == 0) break;
        if ((s16)p[-1] < 0 && p != D_L05_0021DAE0_0035A2B0[n]) break;
        e = D_L05_001DFB9C_0035A2B0 + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (*(s16 *)(e + 0xAA) == 0x1625 && e[0x20] == 7)
            return e;
        p++;
    }
    return 0;
}
/* localdecomp:end func_L05_0035A2B0 */

/* localdecomp:start func_L05_0035A380 */
extern void func_0038D308(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3938(void *, s32, s32);

void func_L05_0035A380(u8 *arg0, u8 *pos, s32 a2, f32 angle)
{
    vu0_v4 rot;
    u8 *v;

    qzero(&rot);
    rot.z = angle;
    v = *(u8 **)(arg0 + 0x68);
    *(vu0_q *)(arg0 + 0x10) = *(vu0_q *)pos;
    *(vu0_v4 *)(arg0 + 0xF0) = rot;
    func_0038D308(arg0 + 0xC0, &rot);
    *(vu0_q *)(*(u8 **)(v + 0x3EC) + 0x10) = *(vu0_q *)pos;
    *(vu0_v4 *)(*(u8 **)(v + 0x3EC) + 0xF0) = rot;
    func_0038D308(*(u8 **)(v + 0x3EC) + 0xC0, &rot);
    *(u16 *)(arg0 + 0x34) &= ~0x41;
    *(u16 *)(arg0 + 0x34) |= *(u16 *)(*(u8 **)(arg0 + 0x24) + 0x44) & 0x1000;
    *(s32 *)(arg0 + 0x98) = *(s32 *)(*(u8 **)(arg0 + 0x24) + 0x10);
    *(u16 *)(*(u8 **)(v + 0x3EC) + 0x34) &= ~0x41;
    *(u16 *)(*(u8 **)(v + 0x3EC) + 0x34) |= *(u16 *)(*(u8 **)(*(u8 **)(v + 0x3EC) + 0x24) + 0x44) & 0x1000;
    *(s32 *)(*(u8 **)(v + 0x3EC) + 0x98) = *(s32 *)(*(u8 **)(*(u8 **)(v + 0x3EC) + 0x24) + 0x10);
    (*(u8 **)(v + 0x3EC))[0x20] = 0xC;
    *(u16 *)(*(u8 **)(v + 0x3EC) + 0x34) &= ~2;
    *(u16 *)(*(u8 **)(v + 0x3EC) + 0x34) &= ~4;
    *(f32 *)(v + 0x3B0) = 0.5f;
    *(f32 *)(arg0 + 0x2C) = *(f32 *)(*(u8 **)(arg0 + 0x24) + 0x24) * *(f32 *)(v + 0x3B0);
    *(f32 *)(*(u8 **)(v + 0x3EC) + 0x2C) = *(f32 *)(*(u8 **)(*(u8 **)(v + 0x3EC) + 0x24) + 0x24) * *(f32 *)(v + 0x3B0);
    *(s32 *)(v + 0x3F0) = a2;
    func_0038CE20(v + 0x110, arg0 + 0xC0, 0.080000006f);
    *(s32 *)(v + 0x100) = 0;
    *(s32 *)(v + 0xF8) = 0;
    *(s32 *)(v + 0xFC) = 0;
    *(f32 *)(v + 0x118) = 0.040000003f;
    qzero(v + 0xC0);
    *(s32 *)(v + 0x148) = -1;
    func_L01_004450F0(arg0, 8, 5);
    func_003C3938(arg0, 0x11, 1);
    func_003C3938(*(u8 **)(v + 0x3EC), 0x11, 1);
}
/* localdecomp:end func_L05_0035A380 */

/* localdecomp:start func_L05_0035A558 */
void func_L05_0035A558(void *arg0) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x3F0) = 0;
}
/* localdecomp:end func_L05_0035A558 */

/* localdecomp:start func_L05_0035A568 */
#include "vu0.h"

typedef struct {
    u8 pad[0x3E];
    u8 x3E;
    u8 pad3F[0x47 - 0x3F];
    u8 x47;
    u8 pad48[0x5E - 0x48];
    u8 x5E;
    u8 pad5F;
    u8 x60;
    u8 pad61[0x3EC - 0x61];
    u8 *x3EC;
    u8 pad2[4];
    s16 x3F4;
} V_35A568_0035A568;

extern s32 D_001D545C;
extern s32 D_L05_001D67BC_0035A568;
extern s32 D_L05_001DFBD8_0035A568;
extern u8 *D_L05_001DFB9C_0035A568;
extern void *D_L05_0021DAE0_0035A568[];
extern u8 D_L05_001D66B0_0035A568[8];
extern void func_L01_00459C50_0035A568(s32);
extern s32 func_L05_00356070_0035A568(f32);
extern void func_L03_0043FC00_0035A568(void *, s32, u8 *, s32, s32, f32, f32, f32, f32, s32, f32, f32, s32, s32, f32);
extern s32 func_L01_003303B8_0035A568(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004443E8_0035A568(void *, s32, s32);
extern void func_003C2880(u8 *);
extern void func_L05_00356018_0035A568(u8 *);

void func_L05_0035A568(u8 *s, s32 a1) {
    V_35A568_0035A568 *v = *(V_35A568_0035A568 **)(s + 0x68);
    u16 *p;
    u8 *e;

    if (D_001D545C == 0x11 && (v->x60 != 0 || v->x47 == 0x87)) {
        D_L05_001D67BC_0035A568 = D_L05_001D67BC_0035A568 + 1;
        if (D_L05_001D67BC_0035A568 >= 0x28) {
            func_L01_00459C50_0035A568(0x13);
        }
    }
    if (a1 == 0) {
        if (v->x60 == 0 && v->x5E == 0) {
            if (v->x3E != 2) {
                vu0_v4 pos;
                s32 n = 1;
                s32 c = 7;
                s32 k;

                if (v->x3EC != 0) {
                    pos = *(vu0_v4 *)(v->x3EC + 0x10);
                    c = 0x7F;
                    n = 2;
                } else {
                    pos = *(vu0_v4 *)(s + 0x10);
                }
                if (func_L05_00356070_0035A568(1.0f) != 0 || v->x3F4 != 0) {
                    n = 0;
                }
                if (func_L05_00356070_0035A568(1.4f) != 0) {
                    func_L03_0043FC00_0035A568(s, c, D_L05_001D66B0_0035A568, 3, n, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 1.0f);
                }
                k = v->x3F4 != 0 ? 3 : 7;
                func_L01_003303B8_0035A568((u8 *)&pos, 0, k, k, k, k, k + 5, 0, 0.9f, 0.0f, 0.0f, 0.0f,
                                  0, 0, 0, 0, 0, 0, 0x10000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                                  0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            }
        }
        func_L01_004443E8_0035A568(s, 0, 3);
        if (s[0x21] != 0xFF) {
            p = D_L05_0021DAE0_0035A568[s[0x21]];
            while (s[0x21] != 0xFF && s[0x21] <= D_L05_001DFBD8_0035A568 && p != 0 &&
                   ((s16)p[-1] >= 0 || p == D_L05_0021DAE0_0035A568[s[0x21]])) {
                e = D_L05_001DFB9C_0035A568 + ((*p & 0x7FFF) << 8);
                if (e == 0)
                    break;
                if (*(s16 *)(e + 0xAA) == 0x1625 && *(u8 **)(e + 0x68) != 0)
                    (*(s32 *)(*(u8 **)(e + 0x68) + 0x39C))++;
                p++;
            }
        }
    }
    if (v->x3EC != 0) {
        func_003C2880(v->x3EC);
        v->x3EC = 0;
    }
    func_L05_00356018_0035A568(s);
}
/* localdecomp:end func_L05_0035A568 */

/* localdecomp:start func_L05_0035A880 */
extern void func_0038CAD0(void *);
extern void func_0038CB00(void *);
extern void func_L01_00451DF8(void *a, void *b, s32 c, s32 d, f32 e);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(u8 *);
extern void func_L05_0035AFB8(u8 *);
extern void func_L05_0035B1A0(u8 *);
extern void func_L05_0035B308(u8 *);
extern void func_L01_00404808(void *, u8 *);
extern u8 D_L05_001E2700[];

void func_L05_0035A880(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    func_0038CAD0(v + 0x3D0);
    func_0038CB00(v + 0x3D4);
    if (*(u16 *)(a0 + 0x96) < 0xFFFF) {
        (*(u16 *)(a0 + 0x96))++;
    }
    func_L01_00451DF8(*(void **)(v + 0x3EC), v + 0x2D0, 3, 1, 2.5f);
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L05_001E2700, a0 + 0x10) < 576.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x16;
        }
        if (a0[0x31] != 0) {
            if (func_L05_00355B30(a0)) {
                func_L05_0035AFB8(a0);
                func_L01_00404808(func_L05_0035B308, a0);
            }
            func_L01_00404808(func_L05_0035B1A0, a0);
        }
    }
}
/* localdecomp:end func_L05_0035A880 */

/* localdecomp:start func_L05_0035A980 */
extern u8 *D_L05_001DFB9C;

void func_L05_0035A980(u8 *object) {
    u16 *p;
    u8 *e;
    if (object[0x21] == 0xFF) {
        *(s16 *)(*(u8 **)(object + 0x68) + 0x3D8) = 1;
        return;
    }
    p = D_L05_0021DAE0[object[0x21]];
    while (object[0x21] != 0xFF && object[0x21] <= D_L05_001DFBD8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L05_0021DAE0[object[0x21]])) {
        e = D_L05_001DFB9C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (*(s16 *)(e + 0xAA) == *(s16 *)(object + 0xAA))
            *(s16 *)(*(u8 **)(e + 0x68) + 0x3D8) = 1;
        if (*(s16 *)(e + 0xAA) == 0x1619)
            *(s32 *)(*(u8 **)(e + 0x68) + 0x8D8) = 1;
        p++;
    }
}
/* localdecomp:end func_L05_0035A980 */

/* localdecomp:start func_L05_0035AA68 */
typedef struct { u8 pad[0x3EC]; void *x3EC; } V_359930;
typedef struct { u8 pad[0x68]; V_359930 *x68; } O_359930;
extern void func_003C3A10(void *, s32, s32, s32);
void func_L05_0035AA68(O_359930 *o, s32 a, s32 b, s32 c) {
    V_359930 *v = o->x68;
    func_003C3A10(o, a, b, c);
    func_003C3A10(v->x3EC, a, b, c);
}
/* localdecomp:end func_L05_0035AA68 */

/* localdecomp:start func_L05_0035AAC8 */
extern s32 func_L05_00355E58(u8 *a0, Vec4 *a1);
typedef struct { u8 pad[0x68]; u8 *x68; } O_359990;
extern s32 func_L05_00355BD8(O_359990 *, u8 *);
s32 func_L05_0035AAC8(O_359990 *o) {
    s32 r = 0;
    u8 *p = o->x68 + 0x220;
    if (((s32 (*)(O_359990 *, u8 *))func_L05_00355E58)(o, p) == 0) {
        r = func_L05_00355BD8(o, p) != 0;
    }
    return r;
}
/* localdecomp:end func_L05_0035AAC8 */

/* localdecomp:start func_L05_0035AB28 */
extern void func_0038CF68(void *, void *, f32);
extern u8 *D_L05_001EA6D8[];
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

s32 func_L05_0035AB28(u8 *arg0, f32 h)
{
    vu0_v4 p;
    vu0_v4 d;
    u8 *v;
    u8 *o;
    s32 r;

    *(vu0_q *)&p = *(vu0_q *)(arg0 + 0x10);
    v = *(u8 **)(arg0 + 0x68);
    p.z += h;
    vec_sub_ba(&d, v + 0x220, &p);
    d.z = 0.0f;
    func_0038CF68(&d, &d, 3.0f);
    vec_add_ab(&d, &d, &p);
    if (func_003D3CB0(&p, &d, 0x10, arg0, 0) == 0) {
        return 1;
    }
    o = D_L05_001EA6D8[0];
    r = 0;
    if (o != 0 && (*(s16 *)(o + 0xAA) == 0x1625 || o == *(u8 **)(v + 0x230))) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L05_0035AB28 */

/* localdecomp:start func_L05_0035AC08 */
extern void func_003C2F58(s32, s32, void *);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);

s32 func_L05_0035AC08(u8 *arg0)
{
    u8 *v;
    vu0_v4 p;
    vu0_v4 d;
    u8 *o;
    s32 hit;
    s32 r;

    v = *(u8 **)(arg0 + 0x68);
    func_003C2F58(*(s32 *)(v + 0x3EC), 0, &p);
    *(vu0_q *)&d = *(vu0_q *)(v + 0x220);
    func_L01_004CB320();
    hit = func_003D3CB0(&p, &d, 0x10, arg0, 0);
    if (hit != 0) {
        o = D_L05_001EA6D8[0];
        if (o != 0 && *(s16 *)(o + 0xAA) == 0x186D && o[0x20] != 2 && o[0x20] != 5) {
            o[0x20] = 4;
        }
    }
    func_L01_004CB358();
    if (hit == 0) {
        return 1;
    }
    {
        u8 *h = D_L05_001EA6D8[0];
        r = 0;
        if (h != 0) {
            r = h == *(u8 **)(v + 0x230);
        }
    }
    return r;
}
/* localdecomp:end func_L05_0035AC08 */

/* localdecomp:start func_L05_0035ACD8 */
extern u8 *D_L05_001EA6D8[];
extern void func_003C2F58(s32, s32, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

s32 func_L05_0035ACD8(u8 *arg0)
{
    u8 *v;
    u8 *o;
    s32 buf[4];

    v = *(u8 **)(arg0 + 104);
    func_003C2F58(*(s32 *)(v + 1004), 0, buf);
    if (func_003D3CB0(buf, v + 544, 0, arg0, 0)) {
        o = D_L05_001EA6D8[0];
        if (o != 0 && *(s16 *)(o + 170) == 5669) {
            return o == *(u8 **)(v + 560);
        }
    }
    return 1;
}
/* localdecomp:end func_L05_0035ACD8 */

/* localdecomp:start func_L05_0035AD60 */
extern s32 func_00382468(s32);
extern s32 func_L05_0035AC08(u8 *);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_003C2F58(s32, s32, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L05_003C8890(void *, void *, void *, void *, f32);
extern s32 func_003A52A0(s32, s32, void *);

void func_L05_0035AD60(u8 *arg0)
{
    u8 *v;
    vu0_v4 p;
    vu0_v4 d;
    vu0_v4 a;
    vu0_v4 t;
    vu0_v4 r;
    vu0_v4 m[4];

    v = *(u8 **)(arg0 + 0x68);
    t = *(vu0_v4 *)(v + 0x220);
    if (func_00382468(4) == 0 && func_L05_0035AC08(arg0) == 0) {
        func_L01_00443B88(&r, 0.8f, 1.2f);
        if (func_00382468(2)) {
            r.x = -r.x;
        }
        if (func_00382468(2)) {
            r.y = -r.y;
        }
        vec_add_ab(&t, &t, &r);
    }
    func_003C2F58(*(s32 *)(v + 0x3EC), 0, &p);
    func_003C2EC0(*(void **)(v + 0x3EC), 0, m);
    func_0038CF68(&a, m, 0.1f);
    vec_add_ba(&p, &p, &a);
    vec_sub_ab(&d, &t, &p);
    func_0038CF68(&d, &d, 0.200000018f);
    func_L05_003C8890(arg0, *(void **)(v + 0x230), &p, &d, v[0x44]);
    func_003A52A0(3, 0, arg0);
}
/* localdecomp:end func_L05_0035AD60 */

INCLUDE_ASM("asm/levels", func_L05_0035AEC8);

INCLUDE_ASM("asm/levels", func_L05_0035AFB8);

INCLUDE_ASM("asm/levels", func_L05_0035B1A0);

/* localdecomp:start func_L05_0035B308 */
extern void func_003C2F58(s32, s32, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_003C5458(void *, s32, f32, f32);
__asm__(".extern D_L05_001DD6F0, 8");
extern u8 D_L05_001DD6F0[8];
__asm__(".extern D_L05_001DD710, 8");
extern s32 D_L05_001DD710[2];
__asm__(".extern D_L05_001DD6E0, 8");
extern f32 D_L05_001DD6E0[2];
__asm__(".extern D_L05_001DD6D8, 8");
extern f32 D_L05_001DD6D8[2];

void func_L05_0035B308(u8 *arg0)
{
    u8 *v;
    s32 i;
    vu0_v4 p;
    u8 m[0x40];
    vu0_v4 d;

    v = *(u8 **)(arg0 + 0x68);
    for (i = 0; i < 2; i++) {
        func_003C2F58(*(s32 *)(v + 0x3EC), 2, &p);
        func_003C2EC0(*(void **)(v + 0x3EC), 2, m);
        func_0038D028(&d, D_L05_001DD6F0 + i * 0x10, m);
        vec_add_ab(&p, &p, &d);
        func_003C5458(&p, D_L05_001DD710[i], D_L05_001DD6E0[i], D_L05_001DD6D8[i]);
    }
}
/* localdecomp:end func_L05_0035B308 */

INCLUDE_ASM("asm/levels", func_L05_0035B3F0);

/* localdecomp:start func_L05_0035CE98 */
extern s32 func_L05_0035D078(u8 *);
extern void func_L05_0035D300(u8 *);
extern void func_003C2880(u8 *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L01_003A6BB0(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, f32, void *, s32, s32, s32, s32, s32, f32, f32, s32, s32);

s32 func_L05_0035CE98(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 0) {
        if (func_L05_0035D078(a0) != 0) return 1;
    }
    if (p[0x5E] != 0) {
        func_L05_0035D300(a0);
        func_003C2880(a0);
        return 1;
    }
    if (p[0x3E] == 2) {
        func_L05_0035D300(a0);
        return 1;
    }
    if (func_L01_00452FB0(a0, p + 0x160, 0, 0, 0) != 0) func_L01_003A6BB0(a0);
    func_L01_00452860(a0, p + 0x30, 0);
    if (p[0x5F] != 0) {
        func_L01_00456BD0(a0, 5);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2C0), *(f32 *)(p + 0x2C4), 0, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
        } else {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2C8), *(f32 *)(p + 0x2CC), 0, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
        }
    } else {
        func_L01_00456BD0(a0, 3);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2C0), *(f32 *)(p + 0x2C4), 0, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 0);
        } else {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2C8), *(f32 *)(p + 0x2CC), 0, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 0);
        }
    }
    return 0;
}
/* localdecomp:end func_L05_0035CE98 */

INCLUDE_ASM("asm/levels", func_L05_0035D078);

/* localdecomp:start func_L05_0035D300 */
extern u8 D_001A30B0[];
extern void func_003A4F28(s32);
extern void func_L01_004443E8(u8 *, s32, s32);
extern void func_003C2880(u8 *);

void func_L05_0035D300(u8 *arg0)
{
    u8 *v;
    s32 i;
    u8 *e;

    v = *(u8 **)(arg0 + 104);
    i = *(s32 *)(v + 748);
    if (i != -1) {
        e = D_001A30B0 + (i << 7);
        if (*(u8 **)(e + 220) == arg0 && e[208] != 0) {
            func_003A4F28(i);
        }
    }
    *(s32 *)(v + 748) = -1;
    func_L01_004443E8(arg0, 0, 3);
    func_003C2880(arg0);
}
/* localdecomp:end func_L05_0035D300 */

/* localdecomp:start func_L05_0035D388 */
extern u8 D_001A30B0[];
extern void func_L05_0035D560(s32);
extern void func_L05_0035D590(u8 *);

void func_L05_0035D388(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 h;
    u8 *e;

    func_0038CAD0(v + 0x2D0);
    func_0038CB00(v + 0x2D4);
    if (*(u16 *)(a0 + 0x96) < 0xFFFF) {
        (*(u16 *)(a0 + 0x96))++;
    }
    func_L01_00451DF8(a0, v + 0x240, 6, 1, 2.5f);
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L05_001E2700, a0 + 0x10) < 576.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x16;
        }
    }
    h = *(s32 *)(v + 0x2EC);
    if (h == -1 || (e = D_001A30B0 + (h << 7), *(u8 **)(e + 0xDC) != a0) || e[0xD0] == 0) {
        *(s32 *)(v + 0x2EC) = func_003A52A0(1, 4, a0);
    }
    func_L01_00404808(func_L05_0035D560, a0);
    func_L01_00404808(func_L05_0035D590, a0);
}
/* localdecomp:end func_L05_0035D388 */
