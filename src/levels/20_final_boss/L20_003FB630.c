#include "common.h"

typedef struct { u8 pad0[0x394]; s32 x394; u8 pad1[0x5C]; s16 x3F4; } T_003FB630;
typedef struct { u8 pad0[0x68]; T_003FB630 *x68; } O_003FB630;

typedef int u128_t __attribute__((mode(TI)));
typedef union Mo_ { u8 b[0x100]; s8 c[0x100]; s16 h[0x80]; u16 uh[0x80]; s32 i[0x40]; u32 u[0x40]; f32 f[0x40]; void *p[0x40]; union Pv_ *pv[0x40]; union Mo_ *mp[0x40]; u128_t q[0x10]; } Mo;
typedef union Pv_ { u8 b[0x400]; s8 c[0x400]; s16 h[0x200]; u16 uh[0x200]; s32 i[0x100]; u32 u[0x100]; f32 f[0x100]; void *p[0x100]; Mo *mp[0x100]; u128_t q[0x40]; } Pv;
typedef struct { s32 n; s32 pad[3]; u128_t pt[1]; } Path;
typedef struct { u8 x0[2]; s16 n; u8 x4[0xC]; s32 *list; u8 x14[0x1C]; } Area;
typedef struct { u8 x0[0x30]; Area a[1]; } Zones;
typedef struct { u8 x0[0x30]; u128_t pos; u8 x40[0x40]; } Spot;
typedef struct { u8 p0[2]; s16 cnt; u8 p4[0xC]; s32 *list; u8 p14[0x1C]; } Z30_FB6A8;
typedef struct { u8 hdr[0x30]; Z30_FB6A8 e[1]; } H30_FB6A8;

/* localdecomp:start func_L20_003FB630 */
extern s32 func_L20_003FB3B0(void *);
extern void func_L05_0035AA68(void *, s32, s32, s32);

void func_L20_003FB630(O_003FB630 *p) {
    T_003FB630 *q;

    q = p->x68;
    if (func_L20_003FB3B0(p) != 0) {
        return;
    }
    if (q->x3F4 != 0) {
        if (q->x394 != 0) {
            func_L05_0035AA68(p, 5, 0, 8);
        } else {
            func_L05_0035AA68(p, 4, 0, 8);
        }
    } else {
        func_L05_0035AA68(p, 6, 0, 8);
    }
}
/* localdecomp:end func_L20_003FB630 */

/* localdecomp:start func_L20_003FB6A8 */
/* func_L20_003FB6A8: a two-moby enemy's per-frame update on the final boss level (the moby and its
   partner moby at pvar 0x3EC), a switch on the moby's mode (m+0x95: 0-5) and one on its state (m+0x20:
   1-18, with switch 3 on pvar 0x3E0 in state 10); 0.64 to func_L05_003560C8, whose helpers
   func_L05_00355AE8..00355DD8 it calls. Written from retail with an m2c draft (Opus, 2026-11-08),
   finished by Opus r0/s3/b1 (2026-11-13/14).
   Needs @ps2as on its file (the inline lui/ori/mtc1 float constants), vu0.h's fabs_asm (state 9's
   abs.s) and the .extern size hints for the $gp scalars.
   What mattered at the end:
   - no pos/tgt locals for m+0x10 and pv+0x350/0x360: every use is the expression, and GCSE's reaching
     register for m+0x10 is retail's $s6 in states 9 and 10 (state 9's addiu $v0 / move $a0 / move $s6
     triple is that copy; a C local gives one instruction less or the wrong register);
   - state 13's two animation calls each in their own arm with the arm's tail (partner call, state
     store): retail cross-jumps the identical tails, which a call falling through to a label (the
     scheduler's USE after it) prevents;
   - the moby array indexed as Mo[] (sizeof 0x100), sp90 an array (its address recomputed per call),
     state 18's two-statement clear, case 6's record tested through the full expression at each use
     and the q[0x350] store through a raw u128 cast (retail reloads D_L20_001DFE4C after it). */


extern void func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00409598(Mo *, u8 *, u8 *, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L20_003FDFE8(Mo *);
extern void fe_func_003C2880(Mo *);
extern s32 func_L01_004AAC98(s32, s32, Mo *, s32);
extern void func_L20_003FE9C0(Mo *, s32);
extern s32 func_L01_004561E0(Mo *);
extern s32 func_L01_004561B8(Mo *);
extern s32 fe_func_00382498(s32, s32);
extern s32 fe_func_00382468(s32);
extern f32 fe_func_003824E0(f32, f32);
extern void func_L01_004AA7E8(Mo *, s32);
extern s32 fe_func_0038CB00(u8 *);
extern void func_L01_004450F0(Mo *, s32, s32);
extern void func_L05_0035AA68(void *, s32, s32, s32);
extern void func_L01_00445BE0(s32, s32);
extern s32 fe_func_003A52A0(s32, s32, Mo *);
extern s32 func_L01_00454370(Mo *, u8 *);
extern s32 func_L20_003FB3B0(void *);
extern f32 func_L05_00355D60(Mo *, Mo *);
extern void func_L01_0045BD78(Mo *, f32, f32, f32, f32);
extern f32 func_L05_00355D00(Mo *, u128_t *);
extern f32 func_L05_00355C98(Mo *, u128_t *, u128_t *);
extern s32 func_L05_00355DD8(Mo *, u128_t *);
extern void func_L01_0045C150(Mo *, Path *, s32, s32);
extern void fe_func_003C3A10(Mo *, s32, s32, s32);
extern s32 func_L03_00449C30(Mo *, s32);
extern s32 func_L01_0045BDE8(Mo *, s32);
extern u8 *fe_func_00382348(Mo *);
extern s32 fe_func_0038CAD0(u8 *);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern s32 func_L01_0045C2A0(Mo *, f32, f32, f32);
extern void func_L01_0045A9F0(Mo *);
extern f32 fe_func_0038CF38(void *, void *);
extern f32 fe_func_0038CF00(void *, void *);
extern void func_L01_0045A748(Mo *, u8 *);
extern void func_L01_0045A898(Mo *, u8 *, f32);
extern f32 fe_func_0038DBA0(f32, f32);
extern f32 fe_func_0038D160(f32, f32);
extern void func_L01_0045BD10(Mo *, f32);
extern void func_L20_003FEDF0(Mo *);
extern void func_L20_003FB630(O_003FB630 *);
extern void func_L01_00459188(Mo *, Mo *, u8 *);
extern void func_L01_00458F78(Mo *, u8 *, s32, s32);
extern void func_L01_0045A7A8(Mo *, u8 *, f32);
extern s32 func_L20_003FEF08(Mo *);
extern s32 func_L05_00355C70(Mo *);
extern s32 func_L05_00355C48(Mo *);
extern s32 func_L05_00355AE8(Mo *);
extern s32 func_L20_003FF170(Mo *);
extern void func_L01_0045D218(Mo *, u8 *);
extern void func_L01_004591B8(Mo *, u128_t *, u8 *);
extern void func_L20_003FF358(Mo *);
extern void func_L20_003FF1F8(Mo *);
extern s32 func_L20_003FB570(Mo *);
extern f32 func_L01_004395E0(Mo *);
extern void fe_func_003C2F58(Mo *, s32, u128_t *);
extern void func_L01_00446630(u128_t *, u128_t *, u128_t *, u8 *);
extern s32 func_L01_00446780(Mo *, f32, u128_t *, s32, f32, f32, s32, s32, s32);
extern void func_L20_003FEBA8(Mo *);

extern s32 D_L20_001DEBEC;
extern s32 D_L20_001DEBF0;
extern f32 D_L20_001DF5C0;
extern f32 D_L20_001DF5C4;
extern f32 D_L20_001DF5C8;
extern f32 D_L20_001DF5CC;
extern f32 D_L20_001DF5D0;
extern f32 D_L20_001DF5D4;
extern f32 D_L20_001DF5D8;
extern f32 D_L20_001DF5DC;
extern f32 D_L20_001DF5E0;
extern f32 D_L20_001DF5E4;
extern f32 D_L20_001DF5E8;
extern f32 D_L20_001DF5EC;
extern f32 D_L20_001DF610;
extern f32 D_L20_001DF618;
extern f32 D_L20_001DF61C;
extern f32 D_L20_001DF620;
extern f32 D_L20_001DF628;
extern f32 D_L20_001DF634;
extern f32 D_L20_001DF638;
extern f32 D_L20_001DF63C;
extern f32 D_L20_001DF640;
extern f32 D_L20_001DF644;
extern f32 D_L20_001DF648;
extern f32 D_L20_001DF64C;
extern f32 D_L20_001DF654;
extern f32 D_L20_001DF658;
extern f32 D_L20_001DF65C;
extern f32 D_L20_001DF660;
extern f32 D_L20_001DF664;
extern f32 D_L20_001DF670;
extern s32 D_L20_001DF668;
extern s32 D_L20_001DF66C;
extern s32 D_L20_001DFD40;
extern u8 *D_L20_001DFE4C;
extern Spot *D_L20_001E0380;
extern Mo *D_L20_001E029C;
extern Mo *D_L20_001E029C_d;
extern s32 D_L20_001E02D8;
extern s32 D_L20_001E02D8_d;
extern s16 *D_L20_0021CFE0[];
extern Path *D_L20_0021E880[];

__asm__(".extern D_L20_001DEBEC, 4");
__asm__(".extern D_L20_001DEBF0, 4");
__asm__(".extern D_L20_001DF5C0, 4");
__asm__(".extern D_L20_001DF5C4, 4");
__asm__(".extern D_L20_001DF5C8, 4");
__asm__(".extern D_L20_001DF5CC, 4");
__asm__(".extern D_L20_001DF5D0, 4");
__asm__(".extern D_L20_001DF5D4, 4");
__asm__(".extern D_L20_001DF5D8, 4");
__asm__(".extern D_L20_001DF5DC, 4");
__asm__(".extern D_L20_001DF5E0, 4");
__asm__(".extern D_L20_001DF5E4, 4");
__asm__(".extern D_L20_001DF5E8, 4");
__asm__(".extern D_L20_001DF5EC, 4");
__asm__(".extern D_L20_001DF610, 4");
__asm__(".extern D_L20_001DF618, 4");
__asm__(".extern D_L20_001DF61C, 4");
__asm__(".extern D_L20_001DF620, 4");
__asm__(".extern D_L20_001DF628, 4");
__asm__(".extern D_L20_001DF634, 4");
__asm__(".extern D_L20_001DF638, 4");
__asm__(".extern D_L20_001DF63C, 4");
__asm__(".extern D_L20_001DF640, 4");
__asm__(".extern D_L20_001DF644, 4");
__asm__(".extern D_L20_001DF648, 4");
__asm__(".extern D_L20_001DF64C, 4");
__asm__(".extern D_L20_001DF654, 4");
__asm__(".extern D_L20_001DF658, 4");
__asm__(".extern D_L20_001DF65C, 4");
__asm__(".extern D_L20_001DF660, 4");
__asm__(".extern D_L20_001DF664, 4");
__asm__(".extern D_L20_001DF670, 4");
__asm__(".extern D_L20_001DF668, 4");
__asm__(".extern D_L20_001DF66C, 4");
__asm__(".extern D_L20_001E02D8, 4");
__asm__(".extern D_L20_001E029C, 4");

#include "vu0.h"

static __inline__ s32 f_lt(f32 a, f32 b) { return a < b; }
static __inline__ s32 f_le(f32 a, f32 b) { return a <= b; }

void func_L20_003FB6A8(Mo *m) {
    Pv *pv;
    u128_t sp90[1];
    u128_t spA0;
    u128_t spB0;
    u128_t spC0;
    u128_t spD0;
    u128_t spE0;

    pv = m->pv[0x68/4];
    if ((pv->i[0x3C8/4] != 0) && (m->b[0x20] == 7)) {
        return;
    }
    if (func_L20_003FDFE8(m) != 0) {
        fe_func_003C2880(m);
        return;
    }
    if (D_L20_001DEBEC == 0) {
        return;
    }
    if (D_L20_001DEBF0 != 0) {
        fe_func_003C2880(pv->mp[0x3EC/4]);
        fe_func_003C2880(m);
        return;
    }
    if (pv->h[0x3DA/2] != 0) {
        m->uh[0x34/2] |= 0x100;
    }
    if (pv->f[0x30/4] <= 0.0f) {
        func_L01_004AAC98(9, 0, pv->mp[0x3EC/4], 0x1610);
        func_L20_003FE9C0(m, 0);
        func_L01_003303B8(m->b + 0x10, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 1.0f, 0.0f, 0.0f, 0.0f,
                          0, 0, 0, 0, 0, 0, 0x10000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        fe_func_003C2880(m);
        return;
    }
    switch (m->b[0x95]) {
    case 0:
        if ((func_L01_004561E0(m) != 0) && (pv->h[0x3D6/2] == 0)) {
            pv->h[0x3D6/2] = (fe_func_00382498(0, 0x1E) * 5 + 2) / 6;
        }
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
        if (((pv->h[0x234/2] == 1) && (fe_func_0038CB00(pv->b + 0x3D6) != 0)) || (pv->h[0x3D8/2] != 0)) {
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xFFFD;
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xFFFB;
            func_L01_004450F0(m, 0xA, 2);
            if (pv->i[0x3A0/4] != 0) {
                func_L01_00409598(m, m->b + 0x10, m->b + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                func_L01_00409598(pv->mp[0x3EC/4], pv->mp[0x3EC/4]->b + 0x10, pv->mp[0x3EC/4]->b + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                pv->i[0x3A0/4] = 0;
            }
        }
        break;
    case 1:
        if ((pv->h[0x234/2] == 1) || (pv->h[0x3D8/2] != 0)) {
            func_L01_004450F0(m, 0xA, 2);
        }
        break;
    case 2:
        if (func_L01_004561E0(m) != 0) {
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xFFFD;
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xFFFB;
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xFFFE;
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xFFBF;
            m->uh[0x34/2] &= 0xFFBA;
        } else if (pv->h[0x234/2] != 1) {
            func_L01_004450F0(m, 1, 1);
            func_L05_0035AA68(m, 8, 0, 8);
            pv->i[0x3D0/4] = (fe_func_00382498(0x244, 0x258) * 5 + 2) / 6;
            if (m->b[0xBC] == 0) {
                if ((m->b[0x21] < D_L20_001E02D8_d) && (D_L20_0021CFE0[m->b[0x21]] != 0)) {
                    func_L01_00445BE0(m->b[0x21], 0);
                }
            }
        }
        break;
    case 3:
        if (func_L01_004561E0(m) != 0) {
            if (m->b[0xBC] == 0) {
                if ((m->b[0x21] < D_L20_001E02D8_d) && (D_L20_0021CFE0[m->b[0x21]] != 0)) {
                    func_L01_00445BE0(m->b[0x21], 0);
                }
            }
            if ((m->b[0x42] == 0x10) || (m->b[0x43] == 0x10)) {
                m->f[0x48/4] = D_L20_001DF664;
                pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF664;
            }
            fe_func_003A52A0(4, 0, m);
        }
        {
        s32 r = func_L01_00454370(m, pv->b + 0x160);
        if (pv->f[0x30/4] <= 0.0f) {
            func_L20_003FE9C0(m, 0);
            fe_func_003A52A0(5, 0, m);
            func_L01_003303B8(m->b + 0x10, 0, 0xA, 0xA, 0xA, 0xA, 0x1E, 0, 0.5f, 0.0f, 0.0f, 0.0f,
                              0, 0, 0, 0, 0, 0, 0x10000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            fe_func_003C2880(m);
            return;
        }
        if (r & 2) {
            func_L01_004450F0(m, 0xA, 2);
            if ((func_L20_003FB3B0(m) == 0) && (func_L05_00355D60(m, pv->mp[0x230/4]) < D_L20_001DF64C)) {
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
            func_L01_0045BD78(m, D_L20_001DF5D4 * 0.00040000002f, D_L20_001DF5D0 * 0.020000001f,
                              D_L20_001DF5DC * 0.017453292f * 0.00040000002f, D_L20_001DF5D8 * 0.017453292f * 0.020000001f);
            if (pv->i[0x390/4] != -1) {
                Path *p;
                f32 d;
                u8 c;
                func_L05_0035AA68(m, 4, 0, 8);
                p = D_L20_0021E880[pv->i[0x390/4]];
                sp90[0] = p->pt[0];
                d = func_L05_00355D00(m, sp90);
                spA0 = *(u128_t *)((u8 *)p + p->n * 16);
                c = f_lt(func_L05_00355D00(m, &spA0), d);
                if (c) {
                    func_L01_0045C150(m, p, 0, p->n - 1);
                } else {
                    func_L01_0045C150(m, p, p->n - 1, 0);
                }
            } else if (pv->i[0x3FC/4] != 0) {
                fe_func_003C3A10(m, 0x13, 0, 0);
                fe_func_003C3A10(pv->mp[0x3EC/4], 2, 0, 0);
                pv->i[0xA8/4] |= 0x404;
            } else if (m->b[0x95] == 1) {
                func_L05_0035AA68(m, 0, 0, 8);
            } else {
                func_L05_0035AA68(m, 2, 0, 8);
            }
        }
        if (pv->i[0x390/4] != -1) {
            s32 r;
            if (pv->h[0x3DA/2] != 0) {
                r = func_L03_00449C30(m, pv->i[0x390/4]);
            } else {
                r = func_L01_0045BDE8(m, pv->i[0x390/4]);
            }
            if (r != 0) {
                func_L01_004450F0(m, 1, -1);
            }
        } else if (fe_func_00382468(0xFA) == 0) {
            func_L01_004450F0(m, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(m) != 0) {
            if (func_L20_003FB3B0(m) != 0) {
                if (m->b[0x95] == 1) {
                    fe_func_003C3A10(pv->mp[0x3EC/4], 1, 0, 8);
                } else {
                    fe_func_003C3A10(pv->mp[0x3EC/4], 3, 0, 8);
                }
            } else if (m->b[0x95] == 1) {
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
        if (D_L20_001DFD40 >= 3) {
            Mo *t = &D_L20_001E029C[pv->i[0x3A4/4]];
            f32 *hp = (f32 *)fe_func_00382348(t);
            if ((t == 0) || (t->b[0x20] == 0xFE) || (t->b[0x20] == 0xFD) || ((hp != 0) && (*hp <= 0.0f))) {
                pv->q[0x350/16] = D_L20_001E029C_d[pv->i[0x3A4/4]].q[1];
                if (fe_func_0038CAD0(pv->b + 0x3C4) != 0) {
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
        if ((D_L20_001DFD40 >= 3) && (func_L01_00445AD0(pv->i[0x3A8/4], -1, 1) == 0)) {
            if (fe_func_0038CAD0(pv->b + 0x3C4) != 0) {
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
        if (func_L01_004561B8(m) != 0) {
            pv->i[0x3E4/4] = 0;
        }
        if (D_L20_001DFD40 >= 3) {
            if (pv->i[0x3E4/4] == 0) {
                if (pv->i[0x39C/4] > 0) {
                    s16 *l;
                    pv->i[0x3E4/4] = 1;
                    l = D_L20_0021CFE0[m->b[0x21]];
                    if ((l != 0) && (m->b[0x21] < D_L20_001E02D8)) {
                        s16 *q = l;
                        do {
                            D_L20_001E029C[*q & 0x7FFF].pv[0x68/4]->i[0x39C/4]--;
                        } while (*q++ >= 0);
                    }
                }
                if (pv->i[0x3E4/4] == 0) {
                    break;
                }
            }
            if (fe_func_0038CAD0(pv->b + 0x3C4) != 0) {
                pv->i[0x3A0/4] = 0;
                func_L01_004450F0(m, 1, 0);
                func_L01_00409598(m, m->b + 0x10, m->b + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                func_L01_00409598(pv->mp[0x3EC/4], pv->mp[0x3EC/4]->b + 0x10, pv->mp[0x3EC/4]->b + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                pv->mp[0x3EC/4]->uh[0x34/2] |= 2;
                pv->mp[0x3EC/4]->uh[0x34/2] |= 4;
            }
        }
        break;
    case 8:
        if (func_L01_004561B8(m) != 0) {
            pv->f[0x1B8/4] = 2.0f;
            pv->f[0x1BC/4] = 2.0f;
        }
        if (pv->f[0x3B0/4] < 1.0f) {
            pv->f[0x3B0/4] += D_L20_001DF610;
            if (pv->f[0x3B0/4] > 1.0f) {
                pv->f[0x3B0/4] = 1.0f;
            }
            m->f[0x2C/4] = ((Mo *)m->p[0x24/4])->f[0x24/4] * pv->f[0x3B0/4];
            pv->mp[0x3EC/4]->f[0x2C/4] = ((Mo *)pv->mp[0x3EC/4]->p[0x24/4])->f[0x24/4] * pv->f[0x3B0/4];
        }
        if (pv->mp[0x3F0/4] != 0) {
            pv->mp[0x3F0/4]->i[0x98/4] = 0;
        }
        if (func_L01_0045C2A0(m, D_L20_001DF618, D_L20_001DF61C, D_L20_001DF620) != 0) {
            m->f[0x48/4] = 1.0f;
            pv->mp[0x3EC/4]->f[0x48/4] = 1.0f;
            func_L01_0045A9F0(m);
            pv->f[0x1BC/4] = 0.3f;
            pv->i[0x1B8/4] = 0;
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
            pv->mp[0x3F0/4]->i[0x98/4] = ((Mo *)pv->mp[0x3F0/4]->p[0x24/4])->i[0x10/4];
        }
        break;
    case 9:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, D_L20_001DF5D4 * 0.00040000002f, D_L20_001DF5D0 * 0.020000001f,
                              D_L20_001DF5DC * 0.017453292f * 0.00040000002f, D_L20_001DF5D8 * 0.017453292f * 0.020000001f);
        }
        {
        if (fe_func_0038CF38(m->b + 0x10, pv->b + 0x360) > 0.5f) {
            func_L01_0045A748(m, pv->b + 0x360);
        } else {
            func_L01_0045A898(m, pv->b + 0x360, pv->f[0x3B4/4]);
        }
        if (pv->h[0x234/2] == 1) {
            func_L01_004450F0(m, 0xA, 2);
        } else if (fe_func_0038CF38(m->b + 0x10, pv->b + 0x360) <= pv->f[0xA4/4]) {
            if (pv->f[0xA0/4] < fabs_asm(fe_func_0038DBA0(m->f[0xF8/4], pv->f[0x3B4/4]))) {
                func_L01_0045BD10(m, pv->f[0x3B4/4]);
            } else {
                func_L01_0045BD78(m, D_L20_001DF5C4 * 0.00040000002f, D_L20_001DF5C0 * 0.020000001f,
                                  D_L20_001DF5CC * 0.017453292f * 0.00040000002f, D_L20_001DF5C8 * 0.017453292f * 0.020000001f);
                func_L01_004450F0(m, 1, 0);
                func_L05_0035AA68(m, 0, 0, 8);
            }
        }
        }
        break;
    case 10:
        if (func_L01_004561B8(m) != 0) {
            f32 a;
            m->b[0xBE] &= 0xFE;
            func_L20_003FEDF0(m);
            if (pv->h[0x3F4/2] != 0) {
                func_L01_0045BD78(m, D_L20_001DF5D4 * 0.00040000002f, D_L20_001DF5D0 * 0.020000001f,
                                  D_L20_001DF5DC * 0.017453292f * 0.00040000002f, D_L20_001DF5D8 * 0.017453292f * 0.020000001f);
            } else if (func_L20_003FB3B0(m) != 0) {
                func_L01_0045BD78(m, D_L20_001DF5E4 * 0.00040000002f, D_L20_001DF5E0 * 0.020000001f,
                                  D_L20_001DF5EC * 0.017453292f * 0.00040000002f, D_L20_001DF5E8 * 0.017453292f * 0.020000001f);
            } else {
                func_L01_0045BD78(m, D_L20_001DF5C4 * 0.00040000002f, D_L20_001DF5C0 * 0.020000001f,
                                  D_L20_001DF5CC * 0.017453292f * 0.00040000002f, D_L20_001DF5C8 * 0.017453292f * 0.020000001f);
            }
            pv->i[0x3E4/4] = 0;
            a = fe_func_003824E0(5.0f, 10.0f) * 0.017453292f;
            if (fe_func_00382468(2) != 0) {
                a = -a;
            }
            pv->f[0x3E8/4] = a;
        }
        switch (pv->u[0x3E0/4]) {
        case 0:
            {
            if (func_L01_004561B8(m) != 0) {
                func_L20_003FB630(m);
                func_L01_00459188(m, pv->mp[0x230/4], pv->b + 0x250);
            }
            if (pv->mp[0x230/4] != pv->mp[0x2A0/4]) {
                func_L01_00459188(m, pv->mp[0x230/4], pv->b + 0x250);
            }
            func_L01_00458F78(m, pv->b + 0x250, 0, 0);
            func_L01_0045A7A8(m, pv->b + 0x250, pv->f[0x3E8/4]);
            if (func_L20_003FEF08(m) != 0) {
                if ((m->uh[0x96/2] >= 0x33) && ((m->uh[0x96/2] >= 0x65) || (fe_func_00382468(0x32) == 0)) && (func_L05_00355C70(m) != 0)) {
                    if (func_L20_003FF170(m) != 0) {
                        func_L01_004450F0(m, 0xB, -1);
                    }
                }
            }
            }
            break;
        case 1:
            if (func_L01_004561B8(m) != 0) {
                func_L20_003FB630(m);
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
            sp90[0] = pv->q[0x350/16];
            if (func_L05_00355D00(m, sp90) < 0.75f) {
                if ((func_L20_003FB3B0(m) == 0) && (func_L05_00355C48(m) == 0)) {
                    func_L01_004450F0(m, 0xD, -1);
                } else {
                    func_L01_004450F0(m, 0xB, -1);
                }
                m->i[0x48/4] = 0;
                pv->mp[0x3EC/4]->i[0x48/4] = 0;
                pv->i[0x3DC/4] = 0;
            } else {
                if (func_L01_004561B8(m) != 0) {
                    func_L20_003FB630(m);
                    if (pv->h[0x3DA/2] == 0) {
                        spA0 = pv->q[0x350/16];
                        func_L01_004591B8(m, &spA0, pv->b + 0x250);
                    }
                }
                if (pv->h[0x3DA/2] != 0) {
                    func_L01_0045D218(m, pv->b + 0x350);
                } else {
                    u8 *r = pv->b + 0x250;
                    func_L01_00458F78(m, r, 0, 0);
                    func_L01_0045A748(m, r);
                }
            }
            break;
        case 5:
            sp90[0] = pv->q[0x350/16];
            if (func_L05_00355D00(m, sp90) < 0.75f) {
                pv->i[0x388/4] = -1;
                func_L20_003FF358(m);
                func_L01_004450F0(m, 0xA, 2);
            } else {
                if (func_L01_004561B8(m) != 0) {
                    func_L20_003FB630(m);
                    if (pv->h[0x3DA/2] == 0) {
                        spA0 = pv->q[0x350/16];
                        func_L01_004591B8(m, &spA0, pv->b + 0x250);
                    }
                }
                if (pv->h[0x3DA/2] != 0) {
                    func_L01_0045D218(m, pv->b + 0x350);
                } else {
                    u8 *r = pv->b + 0x250;
                    func_L01_00458F78(m, r, 0, 0);
                    func_L01_0045A748(m, r);
                }
            }
            break;
        case 3:
            if (func_L01_004561B8(m) != 0) {
                Path *p;
                func_L20_003FB630(m);
                p = D_L20_0021E880[pv->i[0x380/4]];
                if (pv->h[0x3F6/2] != 0) {
                    f32 d;
                    u8 c;
                    sp90[0] = p->pt[0];
                    d = func_L05_00355D00(m, sp90);
                    spA0 = *(u128_t *)((u8 *)p + p->n * 16);
                    c = f_lt(func_L05_00355D00(m, &spA0), d);
                    if (c) {
                        func_L01_0045C150(m, D_L20_0021E880[pv->i[0x380/4]], 0, p->n - 1);
                    } else {
                        func_L01_0045C150(m, D_L20_0021E880[pv->i[0x380/4]], p->n - 1, 0);
                    }
                    pv->h[0x3F6/2] = 0;
                }
            }
            {
            s32 r;
            if (pv->h[0x3DA/2] != 0) {
                r = func_L03_00449C30(m, pv->i[0x380/4]);
            } else {
                r = func_L01_0045BDE8(m, pv->i[0x380/4]);
            }
            if (r != 0) {
                pv->i[0x3DC/4] = 0;
                pv->h[0x3F6/2] = 1;
                if (func_L05_00355C70(m) != 0) {
                    if ((func_L20_003FB3B0(m) == 0) && (func_L05_00355C48(m) == 0)) {
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
            if (func_L01_004561B8(m) != 0) {
                Path *p;
                if (pv->i[0x3F8/4] != 0) {
                    if ((func_L20_003FB3B0(m) == 0) && (pv->i[0x3FC/4] == 0)) {
                        func_L01_004450F0(m, 0x11, -1);
                    }
                } else {
                    func_L20_003FB630(m);
                }
                p = D_L20_0021E880[pv->i[0x384/4]];
                if (func_L20_003FB3B0(m) != 0) {
                    func_L01_0045BD78(m, D_L20_001DF5E4 * 0.00040000002f, pv->f[0x3BC/4] * 0.020000001f,
                                      D_L20_001DF5EC * 0.017453292f * 0.00040000002f, D_L20_001DF5E8 * 0.017453292f * 0.020000001f);
                }
                if (pv->h[0x3F6/2] != 0) {
                    f32 d;
                    u8 c;
                    sp90[0] = p->pt[0];
                    d = func_L05_00355D00(m, sp90);
                    spA0 = *(u128_t *)((u8 *)p + p->n * 16);
                    c = f_lt(func_L05_00355D00(m, &spA0), d);
                    if (c) {
                        func_L01_0045C150(m, D_L20_0021E880[pv->i[0x384/4]], 0, p->n - 1);
                    } else {
                        func_L01_0045C150(m, D_L20_0021E880[pv->i[0x384/4]], p->n - 1, 0);
                    }
                    pv->h[0x3F6/2] = 0;
                }
            }
            {
            s32 r;
            if (pv->h[0x3DA/2] != 0) {
                r = func_L03_00449C30(m, pv->i[0x384/4]);
            } else {
                r = func_L01_0045BDE8(m, pv->i[0x384/4]);
            }
            if (r != 0) {
                pv->h[0x3F6/2] = 1;
                pv->i[0x384/4] = -1;
                func_L20_003FF358(m);
                func_L01_004450F0(m, 0xA, 2);
                if ((pv->i[0x3F8/4] != 0) && (pv->i[0x3FC/4] == 0)) {
                    func_L01_004450F0(m, 0x12, -1);
                }
            }
            }
            break;
        case 6:
            {
            s32 ok = func_L01_004561B8(m);
            if (ok != 0) {
                func_L20_003FB630(m);
                if (pv->i[0x38C/4] != -1) {
                    if ((((H30_FB6A8 *)D_L20_001DFE4C)->e[pv->i[0x38C/4]].cnt != 0) && (pv->h[0x3F6/2] != 0)) {
                        s32 k;
                        pv->h[0x3F6/2] = 0;
                        *(u128_t *)(pv->b + 0x350) = *(u128_t *)((u8 *)D_L20_001E0380 + (**(s32 **)(D_L20_001DFE4C + pv->i[0x38C/4] * 0x30 + 0x40) << 7) + 0x30);
                        for (k = 0; k < ((H30_FB6A8 *)D_L20_001DFE4C)->e[pv->i[0x38C/4]].cnt; k++) {
                            Spot *s = &D_L20_001E0380[(*(s32 **)(D_L20_001DFE4C + pv->i[0x38C/4] * 0x30 + 0x40))[k]];
                            f32 d;
                            u8 c;
                            sp90[0] = s->pos;
                            spA0 = pv->q[0x220/16];
                            d = func_L05_00355C98(m, sp90, &spA0);
                            spB0 = pv->q[0x350/16];
                            spC0 = *(u128_t *)(pv->b + 0x220);
                            {
                            s32 r = (func_L05_00355C98(m, &spB0, &spC0) < d) || (spD0 = pv->q[0x350/16], func_L05_00355D00(m, &spD0) < 2.0f);
                            c = r;
                            }
                            if (c) {
                                spE0 = s->pos;
                                if (func_L05_00355D00(m, &spE0) > 2.0f) {
                                    pv->q[0x350/16] = s->pos;
                                }
                            }
                        }
                    }
                }
            }
            if (func_L20_003FB3B0(m) != 0) {
                if (fe_func_0038CF00(m->b + 0x10, pv->b + 0x350) < 1.0f) {
                    pv->h[0x3F6/2] = 1;
                    if (func_L05_00355C70(m) != 0) {
                        func_L01_004450F0(m, 0xB, -1);
                    } else {
                        func_L01_004450F0(m, 0xA, -1);
                    }
                } else {
                    func_L01_0045A748(m, pv->b + 0x350);
                }
            } else if (fe_func_0038CF38(m->b + 0x10, pv->b + 0x350) < 1.0f) {
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
            }
            break;
        }
        if (pv->i[0x394/4] != 0) {
            if (pv->i[0x3FC/4] != 0) {
                sp90[0] = pv->q[0x220/16];
                func_L05_00355DD8(m, sp90);
            }
            if (pv->i[0x394/4] != 0) {
                if ((pv->mp[0x3EC/4]->b[0x60] & 2) && (pv->i[0x3E4/4] == 0) && (func_L20_003FEF08(m) != 0)) {
                    if ((((m->b[0xBC] == 0) && (func_L20_003FF170(m) != 0)) || (pv->b[0x5F] != 0)) && (func_L05_00355C70(m) != 0)) {
                        if ((m->b[0x21] < D_L20_001E02D8) && (D_L20_0021CFE0[m->b[0x21]] != 0)) {
                            func_L01_00445BE0(m->b[0x21], 1);
                            m->b[0xBC] = 0;
                        }
                        fe_func_003C3A10(pv->mp[0x3EC/4], 7, 0, 8);
                        pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF644;
                        pv->i[0x3E4/4] = 1;
                        pv->i[0x3DC/4] = 0;
                    }
                } else if ((pv->i[0x3E4/4] == 1) && (pv->mp[0x3EC/4]->b[0x60] & 2)) {
                    fe_func_003C3A10(pv->mp[0x3EC/4], 8, 0, 0);
                    pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF644;
                    pv->i[0x3E4/4] = 2;
                    func_L20_003FF1F8(m);
                } else if ((pv->i[0x3E4/4] == 2) && (pv->mp[0x3EC/4]->b[0x60] & 2)) {
                    if (++pv->i[0x3DC/4] >= 3) {
                        fe_func_003C3A10(pv->mp[0x3EC/4], 0xA, 0, 0);
                        pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF644;
                        pv->i[0x3E4/4] = 3;
                    } else {
                        func_L20_003FF1F8(m);
                    }
                } else if ((pv->i[0x3E4/4] == 3) && (pv->mp[0x3EC/4]->b[0x60] & 2)) {
                    if (func_L20_003FB3B0(m) != 0) {
                        fe_func_003C3A10(pv->mp[0x3EC/4], 2, 0, 0);
                    } else if (pv->h[0x3F4/2] != 0) {
                        fe_func_003C3A10(pv->mp[0x3EC/4], 5, 0, 0);
                    } else {
                        fe_func_003C3A10(pv->mp[0x3EC/4], 6, 0, 0);
                    }
                    pv->i[0x3E4/4] = 0;
                    pv->mp[0x3EC/4]->f[0x48/4] = 1.0f;
                    if ((m->b[0x21] < D_L20_001E02D8_d) && (D_L20_0021CFE0[m->b[0x21]] != 0)) {
                        func_L01_00445BE0(m->b[0x21], 0);
                    }
                }
            }
        }
        if ((func_L20_003FB3B0(m) == 0) && (fe_func_0038CF38(m->b + 0x10, pv->mp[0x230/4]->b + 0x10) < D_L20_001DF64C)) {
            func_L01_004450F0(m, 0x10, -1);
        }
        break;
    case 11:
        if (func_L01_004561B8(m) != 0) {
            if (func_L20_003FB3B0(m) != 0) {
                fe_func_003C3A10(pv->mp[0x3EC/4], 7, 0, 8);
                pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF648;
            } else if (((fe_func_0038CF38(m->b + 0x10, pv->mp[0x230/4]->b + 0x10) < D_L20_001DF654) || (fe_func_00382468(2) != 0)) && (func_L05_00355C48(m) != 0)) {
                if (func_L05_00355AE8(m) == 0) {
                    func_L05_0035AA68(m, 0xB, 0, 8);
                } else {
                    fe_func_003C3A10(pv->mp[0x3EC/4], 7, 0, 8);
                    fe_func_003C3A10(m, 0xC, 0, 8);
                    m->f[0x48/4] = D_L20_001DF648;
                    pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF648;
                }
            } else {
                func_L05_0035AA68(m, 7, 0, 8);
                m->f[0x48/4] = D_L20_001DF648;
                pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF648;
            }
        }
        {
        f32 lim = 0.0f;
        if (func_L20_003FB3B0(m) == 0) {
            lim = D_L20_001DF660 * 0.017453292f;
        }
        if (lim < fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]))) {
            sp90[0] = pv->q[0x220/16];
            func_L05_00355DD8(m, sp90);
        } else {
            func_L20_003FB570(m);
        }
        }
        if (pv->mp[0x3EC/4]->b[0x60] & 2) {
            func_L01_004450F0(m, 0xC, -1);
            if (func_L20_003FB3B0(m) == 0) {
                m->i[0x48/4] = 0;
            }
            pv->mp[0x3EC/4]->i[0x48/4] = 0;
        }
        break;
    case 12:
        if (func_L01_004561B8(m) != 0) {
            if (func_L20_003FB3B0(m) != 0) {
                fe_func_003C3A10(pv->mp[0x3EC/4], 8, 0, 0);
            } else if (func_L05_00355AE8(m) != 0) {
                func_L05_0035AA68(m, 0xC, 0, 0);
            } else {
                func_L05_0035AA68(m, 8, 0, 0);
            }
            m->f[0x48/4] = 1.0f;
            pv->mp[0x3EC/4]->f[0x48/4] = 1.0f;
        }
        {
        f32 lim = 0.0f;
        if (func_L20_003FB3B0(m) == 0) {
            lim = D_L20_001DF660 * 0.017453292f;
        }
        if (lim < fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]))) {
            sp90[0] = pv->q[0x220/16];
            func_L05_00355DD8(m, sp90);
        } else {
            func_L20_003FB570(m);
        }
        }
        if (((D_L20_001DF66C * 5 + 2) / 6 < m->uh[0x96/2]) && ((pv->b[0x5F] != 0) || ((m->b[0xBC] == 0) && (func_L20_003FF170(m) != 0)))) {
            func_L01_004450F0(m, 0xE, -1);
            if ((m->b[0x21] < D_L20_001E02D8_d) && (D_L20_0021CFE0[m->b[0x21]] != 0)) {
                func_L01_00445BE0(m->b[0x21], 1);
                m->b[0xBC] = 0;
            }
        } else if (((D_L20_001DF668 * 5 + 2) / 6 < m->uh[0x96/2]) || (func_L20_003FEF08(m) == 0)) {
            func_L01_004450F0(m, 0xA, 2);
            if (m->b[0xBC] == 0) {
                if ((m->b[0x21] < D_L20_001E02D8) && (D_L20_0021CFE0[m->b[0x21]] != 0)) {
                    func_L01_00445BE0(m->b[0x21], 0);
                }
            }
        } else if ((func_L20_003FB3B0(m) == 0) && (fe_func_0038CF38(m->b + 0x10, pv->mp[0x230/4]->b + 0x10) < D_L20_001DF64C)) {
            func_L01_004450F0(m, 0xA, -1);
            func_L01_004450F0(m, 0x10, -1);
        }
        break;
    case 13:
        if (func_L01_004561B8(m) != 0) {
            if (func_L05_00355AE8(m) == 0) {
                pv->i[0x3E4/4] = 0;
                fe_func_003C3A10(m, 0xB, 0, 8);
                fe_func_003C3A10(pv->mp[0x3EC/4], 2, 0, 8);
            } else {
                pv->i[0x3E4/4] = 1;
                fe_func_003C3A10(m, 0xC, 0, 8);
                fe_func_003C3A10(pv->mp[0x3EC/4], 2, 0, 8);
            }
        }
        if (fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) > D_L20_001DF660 * 0.017453292f) {
            sp90[0] = pv->q[0x220/16];
            func_L05_00355DD8(m, sp90);
        } else {
            func_L20_003FB570(m);
        }
        if ((pv->i[0x3E4/4] == 0) && (m->b[0x60] & 2)) {
            pv->i[0x3E4/4] = 1;
            fe_func_003C3A10(m, 0xC, 0, 8);
            fe_func_003C3A10(pv->mp[0x3EC/4], 2, 0, 8);
        } else if ((pv->i[0x3E4/4] == 1) && (m->uh[0x96/2] >= 0x65)) {
            if ((pv->b[0x5F] != 0) || ((m->b[0xBC] == 0) && (func_L20_003FF170(m) != 0))) {
                if ((m->b[0x21] < D_L20_001E02D8_d) && (D_L20_0021CFE0[m->b[0x21]] != 0)) {
                    func_L01_00445BE0(m->b[0x21], 1);
                    m->b[0xBC] = 0;
                }
                if ((func_L05_00355C48(m) != 0) && ((fe_func_0038CF38(m->b + 0x10, pv->mp[0x230/4]->b + 0x10) < D_L20_001DF654) || (fe_func_00382468(3) == 0))) {
                    fe_func_003C3A10(m, 0xC, 0, 8);
                    fe_func_003C3A10(pv->mp[0x3EC/4], 7, 0, 8);
                    pv->i[0x3E4/4] = 3;
                } else {
                    fe_func_003C3A10(m, 0xE, 0, 8);
                    fe_func_003C3A10(pv->mp[0x3EC/4], 7, 0, 8);
                    pv->i[0x3E4/4] = 3;
                }
            }
        } else if ((pv->i[0x3E4/4] == 2) && (m->b[0x60] & 2)) {
            func_L05_0035AA68(m, 8, 0, 8);
            pv->i[0x3E4/4] = 3;
            m->f[0x48/4] = D_L20_001DF648;
            pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF648;
        } else if ((pv->i[0x3E4/4] == 3) && ((m->b[0x60] & 2) || (pv->mp[0x3EC/4]->b[0x60] & 2))) {
            func_L01_004450F0(m, 0xC, -1);
            m->i[0x48/4] = 0;
            pv->mp[0x3EC/4]->i[0x48/4] = 0;
        }
        break;
    case 14:
        if (func_L01_004561B8(m) != 0) {
            pv->h[0x3D8/2] = 0;
            pv->i[0x3DC/4]++;
            func_L20_003FF1F8(m);
            if (func_L20_003FB3B0(m) == 0) {
                fe_func_003C3A10(pv->mp[0x3EC/4], 0xC, 0, 2);
                if (func_L05_00355AE8(m) != 0) {
                    if (m->b[0x43] != 0xD) {
                        fe_func_003C3A10(m, 0xD, 0, 2);
                    }
                } else if ((m->b[0x42] == 7) && (m->b[0x43] != 9)) {
                    fe_func_003C3A10(m, 9, 0, 2);
                }
            }
            pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF628;
            m->f[0x48/4] = D_L20_001DF628;
        }
        func_L20_003FB570(m);
        if (pv->mp[0x3EC/4]->b[0x60] & 2) {
            s32 go = 0;
            if ((func_L20_003FF170(m) != 0) && (((func_L05_00355AE8(m) != 0) && (func_L05_00355C48(m) != 0)) || (func_L05_00355C70(m) != 0))) {
                go = 1;
            }
            if ((pv->i[0x3DC/4] < 0xA) && (go != 0)) {
                func_L01_004450F0(m, 0xE, -1);
            } else {
                pv->i[0x3DC/4] = 0;
                pv->h[0x3D8/2] = 0;
                func_L01_004450F0(m, 0xF, -1);
            }
        }
        break;
    case 15:
        if (func_L01_004561B8(m) != 0) {
            if (m->b[0xBC] == 0) {
                if ((m->b[0x21] < D_L20_001E02D8_d) && (D_L20_0021CFE0[m->b[0x21]] != 0)) {
                    func_L01_00445BE0(m->b[0x21], 0);
                }
            }
            if ((u32)(pv->i[0x3E0/4] - 4) < 2) {
                if (func_L20_003FB3B0(m) != 0) {
                    func_L01_004450F0(m, 0xC, -1);
                } else {
                    if (func_L05_00355AE8(m) != 0) {
                        func_L01_004450F0(m, 0xC, -1);
                    } else if (func_L05_00355C48(m) == 0) {
                        func_L01_004450F0(m, 0xD, -1);
                    } else {
                        func_L01_004450F0(m, 0xC, -1);
                    }
                    break;
                }
            } else if (func_L20_003FB3B0(m) != 0) {
                fe_func_003C3A10(pv->mp[0x3EC/4], 0xE, 0, 8);
            } else if (func_L05_00355AE8(m) != 0) {
                func_L05_0035AA68(m, 0xE, 0, 8);
            } else {
                func_L05_0035AA68(m, 0xA, 0, 8);
            }
        }
        func_L20_003FB570(m);
        if (pv->mp[0x3EC/4]->b[0x60] & 2) {
            func_L01_004450F0(m, 0xA, 2);
            m->i[0x48/4] = 0;
            pv->mp[0x3EC/4]->i[0x48/4] = 0;
        }
        break;
    case 16:
        if (func_L01_004561B8(m) != 0) {
            func_L01_00459188(m, pv->mp[0x230/4], pv->b + 0x250);
            if (func_L05_00355AE8(m) == 0) {
                if (fe_func_0038CF38(m->b + 0x10, pv->b + 0x220) <= D_L20_001DF634) {
                    pv->i[0x3E4/4] = 2;
                    if ((m->b[0x42] != 0xF) && (m->b[0x43] != 0xF)) {
                        func_L05_0035AA68(m, 0xF, 0, 8);
                    }
                    m->f[0x48/4] = D_L20_001DF638;
                    pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF638;
                } else {
                    pv->i[0x3E4/4] = 1;
                    fe_func_003C3A10(m, 6, 0, 8);
                }
            } else {
                pv->i[0x3E4/4] = 0;
                fe_func_003C3A10(m, 0xE, 0, 8);
            }
        }
        if (pv->i[0x3E4/4] == 0) {
            u8 c;
            sp90[0] = pv->q[0x220/16];
            func_L05_00355DD8(m, sp90);
            if (m->b[0x60] & 2) {
                sp90[0] = pv->q[0x220/16];
                c = f_le(func_L05_00355D00(m, sp90), D_L20_001DF634);
                if (!c) {
                    pv->i[0x3E4/4] = 1;
                    fe_func_003C3A10(m, 6, 0, 0);
                } else {
                    pv->i[0x3E4/4] = 2;
                    func_L05_0035AA68(m, 0xF, 0, 0);
                    m->f[0x48/4] = D_L20_001DF638;
                    pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF638;
                }
            }
        } else if (pv->i[0x3E4/4] == 1) {
            u8 c;
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
            sp90[0] = pv->q[0x220/16];
            c = f_le(func_L05_00355D00(m, sp90), D_L20_001DF634);
            if (c) {
                pv->i[0x3E4/4] = 2;
                func_L05_0035AA68(m, 0xF, 0, 0);
                m->f[0x48/4] = D_L20_001DF638;
                pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF638;
            }
        } else if (pv->i[0x3E4/4] == 2) {
            f32 h = func_L01_004395E0(m);
            sp90[0] = pv->q[0x220/16];
            func_L05_00355DD8(m, sp90);
            if ((D_L20_001DF658 < h) && (h < D_L20_001DF65C)) {
                fe_func_003C2F58(pv->mp[0x3EC/4], 0, sp90);
                fe_func_003C2F58(pv->mp[0x3EC/4], 1, &spA0);
                func_L01_00446630(&spB0, sp90, &spA0, pv->b + 0x220);
                func_L01_00446780(m, D_L20_001DF640, &spB0, 0x10001, (f32)pv->b[0x45], D_L20_001DF63C, 0, 1, 0);
            }
            if (pv->mp[0x3EC/4]->b[0x60] & 2) {
                func_L01_004450F0(m, m->b[0x94], -1);
            }
        }
        break;
    case 17:
        if (func_L01_004561B8(m) != 0) {
            fe_func_003C3A10(m, 0x12, 0, 8);
            fe_func_003C3A10(pv->mp[0x3EC/4], 2, 0, 8);
            pv->i[0xA8/4] |= 0x404;
        }
        func_L20_003FB570(m);
        if (m->b[0x60] & 2) {
            fe_func_003C3A10(m, 0x13, 0, 8);
            func_L01_004450F0(m, m->b[0x94], -1);
        }
        break;
    case 18:
        if (func_L01_004561B8(m) != 0) {
            fe_func_003C3A10(pv->mp[0x3EC/4], 2, 0, 8);
            pv->i[0xA8/4] &= ~4;
            pv->i[0xA8/4] &= ~0x400;
        }
        func_L20_003FB570(m);
        if ((m->b[0x42] != 0x14) && (m->b[0x43] != 0x14)) {
            if (m->f[0x18/4] - pv->f[0x100/4] < D_L20_001DF670) {
                fe_func_003C3A10(m, 0x14, 0, 8);
            }
        } else if (m->b[0x60] & 2) {
            func_L01_004450F0(m, m->b[0x94], -1);
            m->i[0x48/4] = 0;
            pv->mp[0x3EC/4]->i[0x48/4] = 0;
        }
        break;
    }
    func_L20_003FEBA8(m);
}
/* localdecomp:end func_L20_003FB6A8 */

/* localdecomp:start func_L20_003FDFE8 */
/* PAL port of the NTSC-U match src/us/levels/func_L20_003FBCF8.c */
extern s32 func_L20_003FE3D0(void *);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern s32 func_L20_003FB3B0(void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_003C6FB0(void *, s32 *, s32 *, s32 *);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern void func_L01_00455E18(void *, void *, void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, f32, s32, s32, s32, s32, s32, s32, f32, f32, s32, s32);

s32 func_L20_003FDFE8(Mo * obj_) {
    u8 * obj = obj_;

    u8 *p = *(u8 **)(obj + 0x68);
    u8 saved;
    s32 t;
    s32 x;
    s32 y;
    s32 z;

    if (obj[0x20] == 0) {
        if (func_L20_003FE3D0(obj) != 0) {
            return 1;
        }
    }
    if (p[0x5E] != 0) {
        func_L20_003FE9C0(obj, 0);
        func_003C2880(obj);
        return 1;
    }
    if (*(u8 **)(p + 0x3EC) != 0) {
        func_003C2F58(obj, 0, *(u8 **)(p + 0x3EC) + 0x10);
        if ((*(unsigned long *)(obj + 0x30) & 0x104100000000L) != 0x4100000000L || *(s32 *)(obj + 0x98) != 0) {
            *(s32 *)(*(u8 **)(p + 0x3EC) + 0xF0) = 0;
            *(s32 *)(*(u8 **)(p + 0x3EC) + 0xF4) = 0;
            func_0038D308(*(u8 **)(p + 0x3EC) + 0xC0, *(u8 **)(p + 0x3EC) + 0xF0);
            func_0038D5F0(*(u8 **)(p + 0x3EC) + 0xC0, obj + 0xC0, *(u8 **)(p + 0x3EC) + 0xC0);
        }
    }
    if (p[0x3E] == 2) {
        func_L20_003FE9C0(obj, 0);
        return 1;
    }
    t = func_L20_003FB3B0(obj);
    saved = obj[0x94];
    if (func_L01_00452FB0(obj, p + 0x160, 0, 0, *(s16 *)(p + 0x3DA)) != 0) {
        if (obj[0x94] == 2 || obj[0x94] == 0x10 || obj[0x94] == 0x11 || obj[0x94] == 0x12) {
            obj[0x94] = saved;
        }
        func_003C3A10(obj, obj[0x43], 0, 2);
        func_003C3A10(*(u8 **)(p + 0x3EC), (*(u8 **)(p + 0x3EC))[0x43], 0, 2);
        if (t != 0) {
            func_003C3A10(obj, obj[0x43], 0, 0);
        }
        func_L20_003FEDF0(obj);
    }
    obj[0xA8] = 0xFF;
    if (*(u8 **)(p + 0x3EC) != 0) {
        func_003C6FB0(obj, &x, &y, &z);
        func_L01_0043B9E8(*(u8 **)(p + 0x3EC), x, y, z);
        func_L01_00455E18(*(u8 **)(p + 0x3EC), *(u8 **)(*(u8 **)(p + 0x3EC) + 0x68) + 0x30, p + 0x30);
    }
    func_L01_00452860(obj, p + 0x30, 0);
    if (p[0x5F] != 0) {
        *(s16 *)(p + 0x3F4) = 0;
        *(s32 *)(p + 0x3E0) = 1;
        *(s32 *)(p + 0x394) = 1;
        *(s32 *)(p + 0x398) = 0;
        if ((*(unsigned long *)(obj + 0x30) & 0x104100000000L) != 0x4100000000L || *(s32 *)(obj + 0x98) != 0) {
            if (0.0f < *(f32 *)(p + 0x30)) {
                func_L01_00456BD0(obj, 5);
            }
        }
        if (obj[0x95] == 0) {
            func_L01_00456C98(obj, *(s32 *)(p + 0x370), *(f32 *)(p + 0x374), 0, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
        } else {
            func_L01_00456C98(obj, *(s32 *)(p + 0x378), *(f32 *)(p + 0x37C), 0, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
        }
    } else {
        if ((*(unsigned long *)(obj + 0x30) & 0x104100000000L) != 0x4100000000L || *(s32 *)(obj + 0x98) != 0) {
            if (0.0f < *(f32 *)(p + 0x30)) {
                func_L01_00456BD0(obj, 3);
            }
        }
        if (obj[0x95] == 0) {
            func_L01_00456C98(obj, *(s32 *)(p + 0x370), *(f32 *)(p + 0x374), 0, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 1);
        } else {
            func_L01_00456C98(obj, *(s32 *)(p + 0x378), *(f32 *)(p + 0x37C), 0, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 1);
        }
    }
    return 0;
}
/* localdecomp:end func_L20_003FDFE8 */

INCLUDE_ASM("asm/levels", func_L20_003FE3D0);

LINKER_REMNANT("asm/levels", func_L20_003FE9B0);

INCLUDE_ASM("asm/levels", func_L20_003FE9C0);

INCLUDE_ASM("asm/levels", func_L20_003FEBA8);

/* localdecomp:start func_L20_003FEDF0 */
void func_L20_003FEDF0(Mo *m) {
    u16 *q;

    if (m->b[0x21] == 0xFF) {
        return;
    }
    q = (u16 *)D_L20_0021CFE0[m->b[0x21]];
    while (m->b[0x21] != 0xFF && m->b[0x21] <= D_L20_001E02D8 && q != 0 &&
           ((s16)q[-1] >= 0 || q == (u16 *)D_L20_0021CFE0[m->b[0x21]])) {
        Mo *e = &D_L20_001E029C[*q & 0x7FFF];
        if (e == 0) {
            break;
        }
        q++;
        if (e->h[0xAA / 2] == m->h[0xAA / 2]) {
            e->pv[0x68 / 4]->uh[0x3D8 / 2] = 1;
        }
    }
}
/* localdecomp:end func_L20_003FEDF0 */
