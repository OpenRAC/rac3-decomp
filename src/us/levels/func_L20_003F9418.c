#include "common.h"

/* NTSC-U counterpart of func_L20_003FB6A8 (src/levels/20_final_boss/L20_003FB630.c) */
typedef struct { u8 pad0[0x394]; s32 x394; u8 pad1[0x5C]; s16 x3F4; } T_003FB630;
typedef struct { u8 pad0[0x68]; T_003FB630 *x68; } O_003FB630;
typedef int u128_t __attribute__((mode(TI)));
typedef union Mo_ { u8 b[0x100]; s8 c[0x100]; s16 h[0x80]; u16 uh[0x80]; s32 i[0x40]; u32 u[0x40]; f32 f[0x40]; void *p[0x40]; union Pv_ *pv[0x40]; union Mo_ *mp[0x40]; u128_t q[0x10]; } Mo;
typedef union Pv_ { u8 b[0x400]; s8 c[0x400]; s16 h[0x200]; u16 uh[0x200]; s32 i[0x100]; u32 u[0x100]; f32 f[0x100]; void *p[0x100]; Mo *mp[0x100]; u128_t q[0x40]; } Pv;
typedef struct { s32 n; s32 pad[3]; u128_t pt[1]; } Path;
typedef struct { u8 x0[0x30]; u128_t pos; u8 x40[0x40]; } Spot;
typedef struct { u8 p0[2]; s16 cnt; u8 p4[0xC]; s32 *list; u8 p14[0x1C]; } Z30_FB6A8;
typedef struct { u8 hdr[0x30]; Z30_FB6A8 e[1]; } H30_FB6A8;
extern s32 func_L20_003F9120(void *);
extern void func_L05_00359930(void *, s32, s32, s32);

/* localdecomp:start func_L20_003F9418 */
/* func_L20_003F9418: a two-moby enemy's per-frame update on the final boss level (the moby and its
   partner moby at pvar 0x3EC), a switch on the moby's mode (m+0x95: 0-5) and one on its state (m+0x20:
   1-18, with switch 3 on pvar 0x3E0 in state 10); 0.64 to func_L05_003560C8, whose helpers
   func_L05_00354AB0..00355DD8 it calls. Written from retail with an m2c draft (Opus, 2026-11-08),
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
     and the q[0x350] store through a raw u128 cast (retail reloads D_L20_001DFE4C_003F9418 after it). */


extern void func_L01_0032FE90_003F9418(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00407180(Mo *, u8 *, u8 *, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L20_003FBCF8(Mo *);
extern void func_003BD360(Mo *);
extern s32 func_L01_004A72A8(s32, s32, Mo *, s32);
extern void func_L20_003FC6B0(Mo *, s32);
extern s32 func_L01_00452EF0(Mo *);
extern s32 func_L01_00452EC8(Mo *);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_004A6DF8(Mo *, s32);
extern s32 func_003883C8(u8 *);
extern void func_L01_00441FB8(Mo *, s32, s32);
extern void func_L05_00359930(void *, s32, s32, s32);
extern void func_L01_00442AA8(s32, s32);
extern s32 func_0039FE80(s32, s32, Mo *);
extern s32 func_L01_00451078(Mo *, u8 *);
extern s32 func_L20_003F9120(void *);
extern f32 func_L05_00354D28(Mo *, Mo *);
extern void func_L01_00458A70(Mo *, f32, f32, f32, f32);
extern f32 func_L05_00354CC8(Mo *, u128_t *);
extern f32 func_L05_00354C60(Mo *, u128_t *, u128_t *);
extern s32 func_L05_00354DA0(Mo *, u128_t *);
extern void func_L01_00458E48(Mo *, Path *, s32, s32);
extern void func_003BE4F0(Mo *, s32, s32, s32);
extern s32 func_L03_00446540(Mo *, s32);
extern s32 func_L01_00458AE0(Mo *, s32);
extern u8 *func_0037E0B8(Mo *);
extern s32 func_00388398(u8 *);
extern s32 func_L01_00442998(s32, s32, s32);
extern s32 func_L01_00458F98(Mo *, f32, f32, f32);
extern void func_L01_004576E8(Mo *);
extern f32 func_00388800(void *, void *);
extern f32 func_003887C8(void *, void *);
extern void func_L01_00457440(Mo *, u8 *);
extern void func_L01_00457590(Mo *, u8 *, f32);
extern f32 func_00389468(f32, f32);
extern f32 func_00388A28(f32, f32);
extern void func_L01_00458A08(Mo *, f32);
extern void func_L20_003FCAE0(Mo *);
extern void func_L20_003F93A0(O_003FB630 *);
extern void func_L01_00455E98(Mo *, Mo *, u8 *);
extern void func_L01_00455C88(Mo *, u8 *, s32, s32);
extern void func_L01_004574A0(Mo *, u8 *, f32);
extern s32 func_L20_003FCBF8(Mo *);
extern s32 func_L05_00354C38(Mo *);
extern s32 func_L05_00354C10(Mo *);
extern s32 func_L05_00354AB0(Mo *);
extern s32 func_L20_003FCE60(Mo *);
extern void func_L01_00459F10(Mo *, u8 *);
extern void func_L01_00455EC8(Mo *, u128_t *, u8 *);
extern void func_L20_003FD048(Mo *);
extern void func_L20_003FCEE8(Mo *);
extern s32 func_L20_003F92E0(Mo *);
extern f32 func_L01_00436500(Mo *);
extern void func_003BDA38(Mo *, s32, u128_t *);
extern void func_L01_004434F8(u128_t *, u128_t *, u128_t *, u8 *);
extern s32 func_L01_00443648(Mo *, f32, u128_t *, s32, f32, f32, s32, s32, s32);
extern void func_L20_003FC898(Mo *);

extern s32 D_L20_001DEC2C;
extern s32 D_L20_001DEC30;
extern f32 D_L20_001DF600;
extern f32 D_L20_001DF604;
extern f32 D_L20_001DF608;
extern f32 D_L20_001DF60C;
extern f32 D_L20_001DF610_003F9418;
extern f32 D_L20_001DF614;
extern f32 D_L20_001DF618_003F9418;
extern f32 D_L20_001DF61C_003F9418;
extern f32 D_L20_001DF620_003F9418;
extern f32 D_L20_001DF624;
extern f32 D_L20_001DF628_003F9418;
extern f32 D_L20_001DF62C;
extern f32 D_L20_001DF650;
extern f32 D_L20_001DF658_003F9418;
extern f32 D_L20_001DF65C_003F9418;
extern f32 D_L20_001DF660_003F9418;
extern f32 D_L20_001DF668_003F9418;
extern f32 D_L20_001DF674;
extern f32 D_L20_001DF678;
extern f32 D_L20_001DF67C;
extern f32 D_L20_001DF680;
extern f32 D_L20_001DF684;
extern f32 D_L20_001DF688;
extern f32 D_L20_001DF68C;
extern f32 D_L20_001DF694;
extern f32 D_L20_001DF698;
extern f32 D_L20_001DF69C;
extern f32 D_L20_001DF6A0;
extern f32 D_L20_001DF6A4;
extern f32 D_L20_001DF6B0;
extern s32 D_L20_001DF6A8;
extern s32 D_L20_001DF6AC;
extern s32 D_L20_001DFD40_003F9418;
extern u8 *D_L20_001DFE4C_003F9418;
extern Spot *D_L20_001E0380_003F9418;
extern Mo *D_L20_001E029C_003F9418;
extern Mo *D_L20_001E029C_d;
extern s32 D_L20_001E02D8_003F9418;
extern s32 D_L20_001E02D8_d;
extern s16 *D_L20_0021CFE0_003F9418[];
extern Path *D_L20_0021E880_003F9418[];

__asm__(".extern D_L20_001DEC2C, 4");
__asm__(".extern D_L20_001DEC30, 4");
__asm__(".extern D_L20_001DF600, 4");
__asm__(".extern D_L20_001DF604, 4");
__asm__(".extern D_L20_001DF608, 4");
__asm__(".extern D_L20_001DF60C, 4");
__asm__(".extern D_L20_001DF610_003F9418, 4");
__asm__(".extern D_L20_001DF614, 4");
__asm__(".extern D_L20_001DF618_003F9418, 4");
__asm__(".extern D_L20_001DF61C_003F9418, 4");
__asm__(".extern D_L20_001DF620_003F9418, 4");
__asm__(".extern D_L20_001DF624, 4");
__asm__(".extern D_L20_001DF628_003F9418, 4");
__asm__(".extern D_L20_001DF62C, 4");
__asm__(".extern D_L20_001DF650, 4");
__asm__(".extern D_L20_001DF658_003F9418, 4");
__asm__(".extern D_L20_001DF65C_003F9418, 4");
__asm__(".extern D_L20_001DF660_003F9418, 4");
__asm__(".extern D_L20_001DF668_003F9418, 4");
__asm__(".extern D_L20_001DF674, 4");
__asm__(".extern D_L20_001DF678, 4");
__asm__(".extern D_L20_001DF67C, 4");
__asm__(".extern D_L20_001DF680, 4");
__asm__(".extern D_L20_001DF684, 4");
__asm__(".extern D_L20_001DF688, 4");
__asm__(".extern D_L20_001DF68C, 4");
__asm__(".extern D_L20_001DF694, 4");
__asm__(".extern D_L20_001DF698, 4");
__asm__(".extern D_L20_001DF69C, 4");
__asm__(".extern D_L20_001DF6A0, 4");
__asm__(".extern D_L20_001DF6A4, 4");
__asm__(".extern D_L20_001DF6B0, 4");
__asm__(".extern D_L20_001DF6A8, 4");
__asm__(".extern D_L20_001DF6AC, 4");
__asm__(".extern D_L20_001E02D8_003F9418, 4");
__asm__(".extern D_L20_001E029C_003F9418, 4");

#include "vu0.h"

static __inline__ s32 f_lt(f32 a, f32 b) { return a < b; }
static __inline__ s32 f_le(f32 a, f32 b) { return a <= b; }

void func_L20_003F9418(Mo *m) {
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
    if (func_L20_003FBCF8(m) != 0) {
        func_003BD360(m);
        return;
    }
    if (D_L20_001DEC2C == 0) {
        return;
    }
    if (D_L20_001DEC30 != 0) {
        func_003BD360(pv->mp[0x3EC/4]);
        func_003BD360(m);
        return;
    }
    if (pv->h[0x3DA/2] != 0) {
        m->uh[0x34/2] |= 0x100;
    }
    if (pv->f[0x30/4] <= 0.0f) {
        func_L01_004A72A8(9, 0, pv->mp[0x3EC/4], 0x1610);
        func_L20_003FC6B0(m, 0);
        func_L01_0032FE90_003F9418(m->b + 0x10, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 1.0f, 0.0f, 0.0f, 0.0f,
                          0, 0, 0, 0, 0, 0, 0x10000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003BD360(m);
        return;
    }
    switch (m->b[0x95]) {
    case 0:
        if ((func_L01_00452EF0(m) != 0) && (pv->h[0x3D6/2] == 0)) {
            pv->h[0x3D6/2] = func_0037E208(0, 0x1E);
        }
        if ((pv->i[0x3A0/4] != 0) && ((m->b[0x34] ^ 1) & 1)) {
            m->i[0x98/4] = 0;
            m->uh[0x34/2] = (m->uh[0x34/2] | 0x41) & 0xEFFF;
            func_L01_004A6DF8(m, 1);
            pv->mp[0x3EC/4]->uh[0x34/2] |= 0x41;
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xEFFF;
            pv->mp[0x3EC/4]->i[0x98/4] = 0;
            func_L01_004A6DF8(pv->mp[0x3EC/4], 1);
            pv->mp[0x3EC/4]->uh[0x34/2] |= 2;
            pv->mp[0x3EC/4]->uh[0x34/2] |= 4;
        }
        if (((pv->h[0x234/2] == 1) && (func_003883C8(pv->b + 0x3D6) != 0)) || (pv->h[0x3D8/2] != 0)) {
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xFFFD;
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xFFFB;
            func_L01_00441FB8(m, 0xA, 2);
            if (pv->i[0x3A0/4] != 0) {
                func_L01_00407180(m, m->b + 0x10, m->b + 0xF0, 0, 2, 3, 0x2D, 0x2D, 0xFF8040, 0x8F1010);
                func_L01_00407180(pv->mp[0x3EC/4], pv->mp[0x3EC/4]->b + 0x10, pv->mp[0x3EC/4]->b + 0xF0, 0, 2, 3, 0x2D, 0x2D, 0xFF8040, 0x8F1010);
                pv->i[0x3A0/4] = 0;
            }
        }
        break;
    case 1:
        if ((pv->h[0x234/2] == 1) || (pv->h[0x3D8/2] != 0)) {
            func_L01_00441FB8(m, 0xA, 2);
        }
        break;
    case 2:
        if (func_L01_00452EF0(m) != 0) {
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xFFFD;
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xFFFB;
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xFFFE;
            pv->mp[0x3EC/4]->uh[0x34/2] &= 0xFFBF;
            m->uh[0x34/2] &= 0xFFBA;
        } else if (pv->h[0x234/2] != 1) {
            func_L01_00441FB8(m, 1, 1);
            func_L05_00359930(m, 8, 0, 10);
            pv->i[0x3D0/4] = func_0037E208(0x244, 0x258);
            if (m->b[0xBC] == 0) {
                if ((m->b[0x21] < D_L20_001E02D8_d) && (D_L20_0021CFE0_003F9418[m->b[0x21]] != 0)) {
                    func_L01_00442AA8(m->b[0x21], 0);
                }
            }
        }
        break;
    case 3:
        if (func_L01_00452EF0(m) != 0) {
            if (m->b[0xBC] == 0) {
                if ((m->b[0x21] < D_L20_001E02D8_d) && (D_L20_0021CFE0_003F9418[m->b[0x21]] != 0)) {
                    func_L01_00442AA8(m->b[0x21], 0);
                }
            }
            if ((m->b[0x42] == 0x10) || (m->b[0x43] == 0x10)) {
                m->f[0x48/4] = D_L20_001DF6A4;
                pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF6A4;
            }
            func_0039FE80(4, 0, m);
        }
        {
        s32 r = func_L01_00451078(m, pv->b + 0x160);
        if (pv->f[0x30/4] <= 0.0f) {
            func_L20_003FC6B0(m, 0);
            func_0039FE80(5, 0, m);
            func_L01_0032FE90_003F9418(m->b + 0x10, 0, 0xA, 0xA, 0xA, 0xA, 0x1E, 0, 0.5f, 0.0f, 0.0f, 0.0f,
                              0, 0, 0, 0, 0, 0, 0x10000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_003BD360(m);
            return;
        }
        if (r & 2) {
            func_L01_00441FB8(m, 0xA, 2);
            if ((func_L20_003F9120(m) == 0) && (func_L05_00354D28(m, pv->mp[0x230/4]) < D_L20_001DF68C)) {
                func_L01_00441FB8(m, 0x10, -1);
                func_L05_00359930(m, 0xF, 3, 3);
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
        if (func_L01_00452EC8(m) != 0) {
            func_L01_00458A70(m, D_L20_001DF614 * 0.00027777778450399637f, D_L20_001DF610_003F9418 * 0.01666666753590107f,
                              D_L20_001DF61C_003F9418 * 0.017453292f * 0.00027777778450399637f, D_L20_001DF618_003F9418 * 0.017453292f * 0.01666666753590107f);
            if (pv->i[0x390/4] != -1) {
                Path *p;
                f32 d;
                u8 c;
                func_L05_00359930(m, 4, 0, 10);
                p = D_L20_0021E880_003F9418[pv->i[0x390/4]];
                sp90[0] = p->pt[0];
                d = func_L05_00354CC8(m, sp90);
                spA0 = *(u128_t *)((u8 *)p + p->n * 16);
                c = f_lt(func_L05_00354CC8(m, &spA0), d);
                if (c) {
                    func_L01_00458E48(m, p, 0, p->n - 1);
                } else {
                    func_L01_00458E48(m, p, p->n - 1, 0);
                }
            } else if (pv->i[0x3FC/4] != 0) {
                func_003BE4F0(m, 0x13, 0, 0);
                func_003BE4F0(pv->mp[0x3EC/4], 2, 0, 0);
                pv->i[0xA8/4] |= 0x404;
            } else if (m->b[0x95] == 1) {
                func_L05_00359930(m, 0, 0, 10);
            } else {
                func_L05_00359930(m, 2, 0, 10);
            }
        }
        if (pv->i[0x390/4] != -1) {
            s32 r;
            if (pv->h[0x3DA/2] != 0) {
                r = func_L03_00446540(m, pv->i[0x390/4]);
            } else {
                r = func_L01_00458AE0(m, pv->i[0x390/4]);
            }
            if (r != 0) {
                func_L01_00441FB8(m, 1, -1);
            }
        } else if (func_0037E1D8(0x12C) == 0) {
            func_L01_00441FB8(m, 2, -1);
        }
        break;
    case 2:
        if (func_L01_00452EC8(m) != 0) {
            if (func_L20_003F9120(m) != 0) {
                if (m->b[0x95] == 1) {
                    func_003BE4F0(pv->mp[0x3EC/4], 1, 0, 10);
                } else {
                    func_003BE4F0(pv->mp[0x3EC/4], 3, 0, 10);
                }
            } else if (m->b[0x95] == 1) {
                func_L05_00359930(m, 1, 0, 10);
            } else {
                func_L05_00359930(m, 3, 0, 10);
            }
        }
        if (pv->mp[0x3EC/4]->b[0x60] & 2) {
            func_L01_00441FB8(m, m->b[0x94], -1);
        }
        break;
    case 3:
        if (D_L20_001DFD40_003F9418 >= 3) {
            Mo *t = &D_L20_001E029C_003F9418[pv->i[0x3A4/4]];
            f32 *hp = (f32 *)func_0037E0B8(t);
            if ((t == 0) || (t->b[0x20] == 0xFE) || (t->b[0x20] == 0xFD) || ((hp != 0) && (*hp <= 0.0f))) {
                pv->q[0x350/16] = D_L20_001E029C_d[pv->i[0x3A4/4]].q[1];
                if (func_00388398(pv->b + 0x3C4) != 0) {
                    pv->i[0x3A0/4] = 0;
                    pv->i[0x3A4/4] = -1;
                    func_L01_00441FB8(m, 1, 0);
                    func_L01_00407180(m, m->b + 0x10, m->b + 0xF0, 0, 2, 3, 0x2D, 0x2D, 0xFF8040, 0x8F1010);
                    func_L01_00407180(pv->mp[0x3EC/4], pv->mp[0x3EC/4]->b + 0x10, pv->mp[0x3EC/4]->b + 0xF0, 0, 2, 3, 0x2D, 0x2D, 0xFF8040, 0x8F1010);
                    pv->mp[0x3EC/4]->uh[0x34/2] |= 2;
                    pv->mp[0x3EC/4]->uh[0x34/2] |= 4;
                }
            }
        }
        break;
    case 4:
        if ((D_L20_001DFD40_003F9418 >= 3) && (func_L01_00442998(pv->i[0x3A8/4], -1, 1) == 0)) {
            if (func_00388398(pv->b + 0x3C4) != 0) {
                pv->i[0x3A0/4] = 0;
                func_L01_00441FB8(m, 1, 0);
                func_L01_00407180(m, m->b + 0x10, m->b + 0xF0, 0, 2, 3, 0x2D, 0x2D, 0xFF8040, 0x8F1010);
                func_L01_00407180(pv->mp[0x3EC/4], pv->mp[0x3EC/4]->b + 0x10, pv->mp[0x3EC/4]->b + 0xF0, 0, 2, 3, 0x2D, 0x2D, 0xFF8040, 0x8F1010);
                pv->mp[0x3EC/4]->uh[0x34/2] |= 2;
                pv->mp[0x3EC/4]->uh[0x34/2] |= 4;
            }
        }
        break;
    case 5:
        if (func_L01_00452EC8(m) != 0) {
            pv->i[0x3E4/4] = 0;
        }
        if (D_L20_001DFD40_003F9418 >= 3) {
            if (pv->i[0x3E4/4] == 0) {
                if (pv->i[0x39C/4] > 0) {
                    s16 *l;
                    pv->i[0x3E4/4] = 1;
                    l = D_L20_0021CFE0_003F9418[m->b[0x21]];
                    if ((l != 0) && (m->b[0x21] < D_L20_001E02D8_003F9418)) {
                        s16 *q = l;
                        do {
                            D_L20_001E029C_003F9418[*q & 0x7FFF].pv[0x68/4]->i[0x39C/4]--;
                        } while (*q++ >= 0);
                    }
                }
                if (pv->i[0x3E4/4] == 0) {
                    break;
                }
            }
            if (func_00388398(pv->b + 0x3C4) != 0) {
                pv->i[0x3A0/4] = 0;
                func_L01_00441FB8(m, 1, 0);
                func_L01_00407180(m, m->b + 0x10, m->b + 0xF0, 0, 2, 3, 0x2D, 0x2D, 0xFF8040, 0x8F1010);
                func_L01_00407180(pv->mp[0x3EC/4], pv->mp[0x3EC/4]->b + 0x10, pv->mp[0x3EC/4]->b + 0xF0, 0, 2, 3, 0x2D, 0x2D, 0xFF8040, 0x8F1010);
                pv->mp[0x3EC/4]->uh[0x34/2] |= 2;
                pv->mp[0x3EC/4]->uh[0x34/2] |= 4;
            }
        }
        break;
    case 8:
        if (func_L01_00452EC8(m) != 0) {
            pv->f[0x1B8/4] = 2.0f;
            pv->f[0x1BC/4] = 2.0f;
        }
        if (pv->f[0x3B0/4] < 1.0f) {
            pv->f[0x3B0/4] += D_L20_001DF650;
            if (pv->f[0x3B0/4] > 1.0f) {
                pv->f[0x3B0/4] = 1.0f;
            }
            m->f[0x2C/4] = ((Mo *)m->p[0x24/4])->f[0x24/4] * pv->f[0x3B0/4];
            pv->mp[0x3EC/4]->f[0x2C/4] = ((Mo *)pv->mp[0x3EC/4]->p[0x24/4])->f[0x24/4] * pv->f[0x3B0/4];
        }
        if (pv->mp[0x3F0/4] != 0) {
            pv->mp[0x3F0/4]->i[0x98/4] = 0;
        }
        if (func_L01_00458F98(m, D_L20_001DF658_003F9418, D_L20_001DF65C_003F9418, D_L20_001DF660_003F9418) != 0) {
            m->f[0x48/4] = 1.0f;
            pv->mp[0x3EC/4]->f[0x48/4] = 1.0f;
            func_L01_004576E8(m);
            pv->f[0x1BC/4] = 0.3f;
            pv->i[0x1B8/4] = 0;
            if (pv->h[0x3BA/2] != 0) {
                func_L01_00441FB8(m, 9, 5);
                func_L05_00359930(m, 4, 0, 10);
            } else {
                func_L01_00441FB8(m, 1, 0);
                func_L05_00359930(m, 0, 0, 10);
            }
        } else if (pv->mp[0x3EC/4] != 0) {
            pv->mp[0x3EC/4]->f[0x48/4] = m->f[0x48/4];
        }
        if (pv->mp[0x3F0/4] != 0) {
            pv->mp[0x3F0/4]->i[0x98/4] = ((Mo *)pv->mp[0x3F0/4]->p[0x24/4])->i[0x10/4];
        }
        break;
    case 9:
        if (func_L01_00452EC8(m) != 0) {
            func_L01_00458A70(m, D_L20_001DF614 * 0.00027777778450399637f, D_L20_001DF610_003F9418 * 0.01666666753590107f,
                              D_L20_001DF61C_003F9418 * 0.017453292f * 0.00027777778450399637f, D_L20_001DF618_003F9418 * 0.017453292f * 0.01666666753590107f);
        }
        {
        if (func_00388800(m->b + 0x10, pv->b + 0x360) > 0.5f) {
            func_L01_00457440(m, pv->b + 0x360);
        } else {
            func_L01_00457590(m, pv->b + 0x360, pv->f[0x3B4/4]);
        }
        if (pv->h[0x234/2] == 1) {
            func_L01_00441FB8(m, 0xA, 2);
        } else if (func_00388800(m->b + 0x10, pv->b + 0x360) <= pv->f[0xA4/4]) {
            if (pv->f[0xA0/4] < fabs_asm(func_00389468(m->f[0xF8/4], pv->f[0x3B4/4]))) {
                func_L01_00458A08(m, pv->f[0x3B4/4]);
            } else {
                func_L01_00458A70(m, D_L20_001DF604 * 0.00027777778450399637f, D_L20_001DF600 * 0.01666666753590107f,
                                  D_L20_001DF60C * 0.017453292f * 0.00027777778450399637f, D_L20_001DF608 * 0.017453292f * 0.01666666753590107f);
                func_L01_00441FB8(m, 1, 0);
                func_L05_00359930(m, 0, 0, 10);
            }
        }
        }
        break;
    case 10:
        if (func_L01_00452EC8(m) != 0) {
            f32 a;
            m->b[0xBE] &= 0xFE;
            func_L20_003FCAE0(m);
            if (pv->h[0x3F4/2] != 0) {
                func_L01_00458A70(m, D_L20_001DF614 * 0.00027777778450399637f, D_L20_001DF610_003F9418 * 0.01666666753590107f,
                                  D_L20_001DF61C_003F9418 * 0.017453292f * 0.00027777778450399637f, D_L20_001DF618_003F9418 * 0.017453292f * 0.01666666753590107f);
            } else if (func_L20_003F9120(m) != 0) {
                func_L01_00458A70(m, D_L20_001DF624 * 0.00027777778450399637f, D_L20_001DF620_003F9418 * 0.01666666753590107f,
                                  D_L20_001DF62C * 0.017453292f * 0.00027777778450399637f, D_L20_001DF628_003F9418 * 0.017453292f * 0.01666666753590107f);
            } else {
                func_L01_00458A70(m, D_L20_001DF604 * 0.00027777778450399637f, D_L20_001DF600 * 0.01666666753590107f,
                                  D_L20_001DF60C * 0.017453292f * 0.00027777778450399637f, D_L20_001DF608 * 0.017453292f * 0.01666666753590107f);
            }
            pv->i[0x3E4/4] = 0;
            a = func_0037E250(5.0f, 10.0f) * 0.017453292f;
            if (func_0037E1D8(2) != 0) {
                a = -a;
            }
            pv->f[0x3E8/4] = a;
        }
        switch (pv->u[0x3E0/4]) {
        case 0:
            {
            if (func_L01_00452EC8(m) != 0) {
                func_L20_003F93A0(m);
                func_L01_00455E98(m, pv->mp[0x230/4], pv->b + 0x250);
            }
            if (pv->mp[0x230/4] != pv->mp[0x2A0/4]) {
                func_L01_00455E98(m, pv->mp[0x230/4], pv->b + 0x250);
            }
            func_L01_00455C88(m, pv->b + 0x250, 0, 0);
            func_L01_004574A0(m, pv->b + 0x250, pv->f[0x3E8/4]);
            if (func_L20_003FCBF8(m) != 0) {
                if ((m->uh[0x96/2] >= 0x3D) && ((m->uh[0x96/2] >= 0x79) || (func_0037E1D8(0x3C) == 0)) && (func_L05_00354C38(m) != 0)) {
                    if (func_L20_003FCE60(m) != 0) {
                        func_L01_00441FB8(m, 0xB, -1);
                    }
                }
            }
            }
            break;
        case 1:
            if (func_L01_00452EC8(m) != 0) {
                func_L20_003F93A0(m);
                if (pv->h[0x3DA/2] == 0) {
                    func_L01_00455E98(m, pv->mp[0x230/4], pv->b + 0x250);
                }
            }
            if (pv->h[0x3DA/2] != 0) {
                func_L01_00459F10(m, pv->mp[0x230/4]->b + 0x10);
            } else {
                u8 *r = pv->b + 0x250;
                if (pv->mp[0x230/4] != pv->mp[0x2A0/4]) {
                    func_L01_00455E98(m, pv->mp[0x230/4], r);
                }
                func_L01_00455C88(m, r, 0, 0);
                func_L01_004574A0(m, r, pv->f[0x3E8/4]);
            }
            break;
        case 4:
            sp90[0] = pv->q[0x350/16];
            if (func_L05_00354CC8(m, sp90) < 0.75f) {
                if ((func_L20_003F9120(m) == 0) && (func_L05_00354C10(m) == 0)) {
                    func_L01_00441FB8(m, 0xD, -1);
                } else {
                    func_L01_00441FB8(m, 0xB, -1);
                }
                m->i[0x48/4] = 0;
                pv->mp[0x3EC/4]->i[0x48/4] = 0;
                pv->i[0x3DC/4] = 0;
            } else {
                if (func_L01_00452EC8(m) != 0) {
                    func_L20_003F93A0(m);
                    if (pv->h[0x3DA/2] == 0) {
                        spA0 = pv->q[0x350/16];
                        func_L01_00455EC8(m, &spA0, pv->b + 0x250);
                    }
                }
                if (pv->h[0x3DA/2] != 0) {
                    func_L01_00459F10(m, pv->b + 0x350);
                } else {
                    u8 *r = pv->b + 0x250;
                    func_L01_00455C88(m, r, 0, 0);
                    func_L01_00457440(m, r);
                }
            }
            break;
        case 5:
            sp90[0] = pv->q[0x350/16];
            if (func_L05_00354CC8(m, sp90) < 0.75f) {
                pv->i[0x388/4] = -1;
                func_L20_003FD048(m);
                func_L01_00441FB8(m, 0xA, 2);
            } else {
                if (func_L01_00452EC8(m) != 0) {
                    func_L20_003F93A0(m);
                    if (pv->h[0x3DA/2] == 0) {
                        spA0 = pv->q[0x350/16];
                        func_L01_00455EC8(m, &spA0, pv->b + 0x250);
                    }
                }
                if (pv->h[0x3DA/2] != 0) {
                    func_L01_00459F10(m, pv->b + 0x350);
                } else {
                    u8 *r = pv->b + 0x250;
                    func_L01_00455C88(m, r, 0, 0);
                    func_L01_00457440(m, r);
                }
            }
            break;
        case 3:
            if (func_L01_00452EC8(m) != 0) {
                Path *p;
                func_L20_003F93A0(m);
                p = D_L20_0021E880_003F9418[pv->i[0x380/4]];
                if (pv->h[0x3F6/2] != 0) {
                    f32 d;
                    u8 c;
                    sp90[0] = p->pt[0];
                    d = func_L05_00354CC8(m, sp90);
                    spA0 = *(u128_t *)((u8 *)p + p->n * 16);
                    c = f_lt(func_L05_00354CC8(m, &spA0), d);
                    if (c) {
                        func_L01_00458E48(m, D_L20_0021E880_003F9418[pv->i[0x380/4]], 0, p->n - 1);
                    } else {
                        func_L01_00458E48(m, D_L20_0021E880_003F9418[pv->i[0x380/4]], p->n - 1, 0);
                    }
                    pv->h[0x3F6/2] = 0;
                }
            }
            {
            s32 r;
            if (pv->h[0x3DA/2] != 0) {
                r = func_L03_00446540(m, pv->i[0x380/4]);
            } else {
                r = func_L01_00458AE0(m, pv->i[0x380/4]);
            }
            if (r != 0) {
                pv->i[0x3DC/4] = 0;
                pv->h[0x3F6/2] = 1;
                if (func_L05_00354C38(m) != 0) {
                    if ((func_L20_003F9120(m) == 0) && (func_L05_00354C10(m) == 0)) {
                        func_L01_00441FB8(m, 0xD, -1);
                    } else {
                        func_L01_00441FB8(m, 0xB, -1);
                    }
                } else {
                    func_L01_00441FB8(m, 0xA, -1);
                }
            }
            }
            break;
        case 2:
            if (func_L01_00452EC8(m) != 0) {
                Path *p;
                if (pv->i[0x3F8/4] != 0) {
                    if ((func_L20_003F9120(m) == 0) && (pv->i[0x3FC/4] == 0)) {
                        func_L01_00441FB8(m, 0x11, -1);
                    }
                } else {
                    func_L20_003F93A0(m);
                }
                p = D_L20_0021E880_003F9418[pv->i[0x384/4]];
                if (func_L20_003F9120(m) != 0) {
                    func_L01_00458A70(m, D_L20_001DF624 * 0.00027777778450399637f, pv->f[0x3BC/4] * 0.01666666753590107f,
                                      D_L20_001DF62C * 0.017453292f * 0.00027777778450399637f, D_L20_001DF628_003F9418 * 0.017453292f * 0.01666666753590107f);
                }
                if (pv->h[0x3F6/2] != 0) {
                    f32 d;
                    u8 c;
                    sp90[0] = p->pt[0];
                    d = func_L05_00354CC8(m, sp90);
                    spA0 = *(u128_t *)((u8 *)p + p->n * 16);
                    c = f_lt(func_L05_00354CC8(m, &spA0), d);
                    if (c) {
                        func_L01_00458E48(m, D_L20_0021E880_003F9418[pv->i[0x384/4]], 0, p->n - 1);
                    } else {
                        func_L01_00458E48(m, D_L20_0021E880_003F9418[pv->i[0x384/4]], p->n - 1, 0);
                    }
                    pv->h[0x3F6/2] = 0;
                }
            }
            {
            s32 r;
            if (pv->h[0x3DA/2] != 0) {
                r = func_L03_00446540(m, pv->i[0x384/4]);
            } else {
                r = func_L01_00458AE0(m, pv->i[0x384/4]);
            }
            if (r != 0) {
                pv->h[0x3F6/2] = 1;
                pv->i[0x384/4] = -1;
                func_L20_003FD048(m);
                func_L01_00441FB8(m, 0xA, 2);
                if ((pv->i[0x3F8/4] != 0) && (pv->i[0x3FC/4] == 0)) {
                    func_L01_00441FB8(m, 0x12, -1);
                }
            }
            }
            break;
        case 6:
            {
            s32 ok = func_L01_00452EC8(m);
            if (ok != 0) {
                func_L20_003F93A0(m);
                if (pv->i[0x38C/4] != -1) {
                    if ((((H30_FB6A8 *)D_L20_001DFE4C_003F9418)->e[pv->i[0x38C/4]].cnt != 0) && (pv->h[0x3F6/2] != 0)) {
                        s32 k;
                        pv->h[0x3F6/2] = 0;
                        *(u128_t *)(pv->b + 0x350) = *(u128_t *)((u8 *)D_L20_001E0380_003F9418 + (**(s32 **)(D_L20_001DFE4C_003F9418 + pv->i[0x38C/4] * 0x30 + 0x40) << 7) + 0x30);
                        for (k = 0; k < ((H30_FB6A8 *)D_L20_001DFE4C_003F9418)->e[pv->i[0x38C/4]].cnt; k++) {
                            Spot *s = &D_L20_001E0380_003F9418[(*(s32 **)(D_L20_001DFE4C_003F9418 + pv->i[0x38C/4] * 0x30 + 0x40))[k]];
                            f32 d;
                            u8 c;
                            sp90[0] = s->pos;
                            spA0 = pv->q[0x220/16];
                            d = func_L05_00354C60(m, sp90, &spA0);
                            spB0 = pv->q[0x350/16];
                            spC0 = *(u128_t *)(pv->b + 0x220);
                            {
                            s32 r = (func_L05_00354C60(m, &spB0, &spC0) < d) || (spD0 = pv->q[0x350/16], func_L05_00354CC8(m, &spD0) < 2.0f);
                            c = r;
                            }
                            if (c) {
                                spE0 = s->pos;
                                if (func_L05_00354CC8(m, &spE0) > 2.0f) {
                                    pv->q[0x350/16] = s->pos;
                                }
                            }
                        }
                    }
                }
            }
            if (func_L20_003F9120(m) != 0) {
                if (func_003887C8(m->b + 0x10, pv->b + 0x350) < 1.0f) {
                    pv->h[0x3F6/2] = 1;
                    if (func_L05_00354C38(m) != 0) {
                        func_L01_00441FB8(m, 0xB, -1);
                    } else {
                        func_L01_00441FB8(m, 0xA, -1);
                    }
                } else {
                    func_L01_00457440(m, pv->b + 0x350);
                }
            } else if (func_00388800(m->b + 0x10, pv->b + 0x350) < 1.0f) {
                pv->i[0x3DC/4] = 0;
                pv->h[0x3F6/2] = 1;
                if (func_L05_00354C38(m) != 0) {
                    if (func_L05_00354C10(m) == 0) {
                        func_L01_00441FB8(m, 0xD, -1);
                    } else {
                        func_L01_00441FB8(m, 0xB, -1);
                    }
                } else {
                    func_L01_00441FB8(m, 0xA, -1);
                }
            } else if (pv->h[0x3DA/2] != 0) {
                func_L01_00459F10(m, pv->b + 0x350);
            } else {
                func_L01_00457440(m, pv->b + 0x350);
            }
            }
            break;
        }
        if (pv->i[0x394/4] != 0) {
            if (pv->i[0x3FC/4] != 0) {
                sp90[0] = pv->q[0x220/16];
                func_L05_00354DA0(m, sp90);
            }
            if (pv->i[0x394/4] != 0) {
                if ((pv->mp[0x3EC/4]->b[0x60] & 2) && (pv->i[0x3E4/4] == 0) && (func_L20_003FCBF8(m) != 0)) {
                    if ((((m->b[0xBC] == 0) && (func_L20_003FCE60(m) != 0)) || (pv->b[0x5F] != 0)) && (func_L05_00354C38(m) != 0)) {
                        if ((m->b[0x21] < D_L20_001E02D8_003F9418) && (D_L20_0021CFE0_003F9418[m->b[0x21]] != 0)) {
                            func_L01_00442AA8(m->b[0x21], 1);
                            m->b[0xBC] = 0;
                        }
                        func_003BE4F0(pv->mp[0x3EC/4], 7, 0, 10);
                        pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF684;
                        pv->i[0x3E4/4] = 1;
                        pv->i[0x3DC/4] = 0;
                    }
                } else if ((pv->i[0x3E4/4] == 1) && (pv->mp[0x3EC/4]->b[0x60] & 2)) {
                    func_003BE4F0(pv->mp[0x3EC/4], 8, 0, 0);
                    pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF684;
                    pv->i[0x3E4/4] = 2;
                    func_L20_003FCEE8(m);
                } else if ((pv->i[0x3E4/4] == 2) && (pv->mp[0x3EC/4]->b[0x60] & 2)) {
                    if (++pv->i[0x3DC/4] >= 3) {
                        func_003BE4F0(pv->mp[0x3EC/4], 0xA, 0, 0);
                        pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF684;
                        pv->i[0x3E4/4] = 3;
                    } else {
                        func_L20_003FCEE8(m);
                    }
                } else if ((pv->i[0x3E4/4] == 3) && (pv->mp[0x3EC/4]->b[0x60] & 2)) {
                    if (func_L20_003F9120(m) != 0) {
                        func_003BE4F0(pv->mp[0x3EC/4], 2, 0, 0);
                    } else if (pv->h[0x3F4/2] != 0) {
                        func_003BE4F0(pv->mp[0x3EC/4], 5, 0, 0);
                    } else {
                        func_003BE4F0(pv->mp[0x3EC/4], 6, 0, 0);
                    }
                    pv->i[0x3E4/4] = 0;
                    pv->mp[0x3EC/4]->f[0x48/4] = 1.0f;
                    if ((m->b[0x21] < D_L20_001E02D8_d) && (D_L20_0021CFE0_003F9418[m->b[0x21]] != 0)) {
                        func_L01_00442AA8(m->b[0x21], 0);
                    }
                }
            }
        }
        if ((func_L20_003F9120(m) == 0) && (func_00388800(m->b + 0x10, pv->mp[0x230/4]->b + 0x10) < D_L20_001DF68C)) {
            func_L01_00441FB8(m, 0x10, -1);
        }
        break;
    case 11:
        if (func_L01_00452EC8(m) != 0) {
            if (func_L20_003F9120(m) != 0) {
                func_003BE4F0(pv->mp[0x3EC/4], 7, 0, 10);
                pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF688;
            } else if (((func_00388800(m->b + 0x10, pv->mp[0x230/4]->b + 0x10) < D_L20_001DF694) || (func_0037E1D8(2) != 0)) && (func_L05_00354C10(m) != 0)) {
                if (func_L05_00354AB0(m) == 0) {
                    func_L05_00359930(m, 0xB, 0, 10);
                } else {
                    func_003BE4F0(pv->mp[0x3EC/4], 7, 0, 10);
                    func_003BE4F0(m, 0xC, 0, 10);
                    m->f[0x48/4] = D_L20_001DF688;
                    pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF688;
                }
            } else {
                func_L05_00359930(m, 7, 0, 10);
                m->f[0x48/4] = D_L20_001DF688;
                pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF688;
            }
        }
        {
        f32 lim = 0.0f;
        if (func_L20_003F9120(m) == 0) {
            lim = D_L20_001DF6A0 * 0.017453292f;
        }
        if (lim < func_00389468(m->f[0xF8/4], func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]))) {
            sp90[0] = pv->q[0x220/16];
            func_L05_00354DA0(m, sp90);
        } else {
            func_L20_003F92E0(m);
        }
        }
        if (pv->mp[0x3EC/4]->b[0x60] & 2) {
            func_L01_00441FB8(m, 0xC, -1);
            if (func_L20_003F9120(m) == 0) {
                m->i[0x48/4] = 0;
            }
            pv->mp[0x3EC/4]->i[0x48/4] = 0;
        }
        break;
    case 12:
        if (func_L01_00452EC8(m) != 0) {
            if (func_L20_003F9120(m) != 0) {
                func_003BE4F0(pv->mp[0x3EC/4], 8, 0, 0);
            } else if (func_L05_00354AB0(m) != 0) {
                func_L05_00359930(m, 0xC, 0, 0);
            } else {
                func_L05_00359930(m, 8, 0, 0);
            }
            m->f[0x48/4] = 1.0f;
            pv->mp[0x3EC/4]->f[0x48/4] = 1.0f;
        }
        {
        f32 lim = 0.0f;
        if (func_L20_003F9120(m) == 0) {
            lim = D_L20_001DF6A0 * 0.017453292f;
        }
        if (lim < func_00389468(m->f[0xF8/4], func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]))) {
            sp90[0] = pv->q[0x220/16];
            func_L05_00354DA0(m, sp90);
        } else {
            func_L20_003F92E0(m);
        }
        }
        if ((D_L20_001DF6AC < m->uh[0x96/2]) && ((pv->b[0x5F] != 0) || ((m->b[0xBC] == 0) && (func_L20_003FCE60(m) != 0)))) {
            func_L01_00441FB8(m, 0xE, -1);
            if ((m->b[0x21] < D_L20_001E02D8_d) && (D_L20_0021CFE0_003F9418[m->b[0x21]] != 0)) {
                func_L01_00442AA8(m->b[0x21], 1);
                m->b[0xBC] = 0;
            }
        } else if ((D_L20_001DF6A8 < m->uh[0x96/2]) || (func_L20_003FCBF8(m) == 0)) {
            func_L01_00441FB8(m, 0xA, 2);
            if (m->b[0xBC] == 0) {
                if ((m->b[0x21] < D_L20_001E02D8_003F9418) && (D_L20_0021CFE0_003F9418[m->b[0x21]] != 0)) {
                    func_L01_00442AA8(m->b[0x21], 0);
                }
            }
        } else if ((func_L20_003F9120(m) == 0) && (func_00388800(m->b + 0x10, pv->mp[0x230/4]->b + 0x10) < D_L20_001DF68C)) {
            func_L01_00441FB8(m, 0xA, -1);
            func_L01_00441FB8(m, 0x10, -1);
        }
        break;
    case 13:
        if (func_L01_00452EC8(m) != 0) {
            if (func_L05_00354AB0(m) == 0) {
                pv->i[0x3E4/4] = 0;
                func_003BE4F0(m, 0xB, 0, 10);
                func_003BE4F0(pv->mp[0x3EC/4], 2, 0, 10);
            } else {
                pv->i[0x3E4/4] = 1;
                func_003BE4F0(m, 0xC, 0, 10);
                func_003BE4F0(pv->mp[0x3EC/4], 2, 0, 10);
            }
        }
        if (func_00389468(m->f[0xF8/4], func_00388A28(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) > D_L20_001DF6A0 * 0.017453292f) {
            sp90[0] = pv->q[0x220/16];
            func_L05_00354DA0(m, sp90);
        } else {
            func_L20_003F92E0(m);
        }
        if ((pv->i[0x3E4/4] == 0) && (m->b[0x60] & 2)) {
            pv->i[0x3E4/4] = 1;
            func_003BE4F0(m, 0xC, 0, 10);
            func_003BE4F0(pv->mp[0x3EC/4], 2, 0, 10);
        } else if ((pv->i[0x3E4/4] == 1) && (m->uh[0x96/2] >= 0x79)) {
            if ((pv->b[0x5F] != 0) || ((m->b[0xBC] == 0) && (func_L20_003FCE60(m) != 0))) {
                if ((m->b[0x21] < D_L20_001E02D8_d) && (D_L20_0021CFE0_003F9418[m->b[0x21]] != 0)) {
                    func_L01_00442AA8(m->b[0x21], 1);
                    m->b[0xBC] = 0;
                }
                if ((func_L05_00354C10(m) != 0) && ((func_00388800(m->b + 0x10, pv->mp[0x230/4]->b + 0x10) < D_L20_001DF694) || (func_0037E1D8(3) == 0))) {
                    func_003BE4F0(m, 0xC, 0, 10);
                    func_003BE4F0(pv->mp[0x3EC/4], 7, 0, 10);
                    pv->i[0x3E4/4] = 3;
                } else {
                    func_003BE4F0(m, 0xE, 0, 10);
                    func_003BE4F0(pv->mp[0x3EC/4], 7, 0, 10);
                    pv->i[0x3E4/4] = 3;
                }
            }
        } else if ((pv->i[0x3E4/4] == 2) && (m->b[0x60] & 2)) {
            func_L05_00359930(m, 8, 0, 10);
            pv->i[0x3E4/4] = 3;
            m->f[0x48/4] = D_L20_001DF688;
            pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF688;
        } else if ((pv->i[0x3E4/4] == 3) && ((m->b[0x60] & 2) || (pv->mp[0x3EC/4]->b[0x60] & 2))) {
            func_L01_00441FB8(m, 0xC, -1);
            m->i[0x48/4] = 0;
            pv->mp[0x3EC/4]->i[0x48/4] = 0;
        }
        break;
    case 14:
        if (func_L01_00452EC8(m) != 0) {
            pv->h[0x3D8/2] = 0;
            pv->i[0x3DC/4]++;
            func_L20_003FCEE8(m);
            if (func_L20_003F9120(m) == 0) {
                func_003BE4F0(pv->mp[0x3EC/4], 0xC, 0, 3);
                if (func_L05_00354AB0(m) != 0) {
                    if (m->b[0x43] != 0xD) {
                        func_003BE4F0(m, 0xD, 0, 3);
                    }
                } else if ((m->b[0x42] == 7) && (m->b[0x43] != 9)) {
                    func_003BE4F0(m, 9, 0, 3);
                }
            }
            pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF668_003F9418;
            m->f[0x48/4] = D_L20_001DF668_003F9418;
        }
        func_L20_003F92E0(m);
        if (pv->mp[0x3EC/4]->b[0x60] & 2) {
            s32 go = 0;
            if ((func_L20_003FCE60(m) != 0) && (((func_L05_00354AB0(m) != 0) && (func_L05_00354C10(m) != 0)) || (func_L05_00354C38(m) != 0))) {
                go = 1;
            }
            if ((pv->i[0x3DC/4] < 0xA) && (go != 0)) {
                func_L01_00441FB8(m, 0xE, -1);
            } else {
                pv->i[0x3DC/4] = 0;
                pv->h[0x3D8/2] = 0;
                func_L01_00441FB8(m, 0xF, -1);
            }
        }
        break;
    case 15:
        if (func_L01_00452EC8(m) != 0) {
            if (m->b[0xBC] == 0) {
                if ((m->b[0x21] < D_L20_001E02D8_d) && (D_L20_0021CFE0_003F9418[m->b[0x21]] != 0)) {
                    func_L01_00442AA8(m->b[0x21], 0);
                }
            }
            if ((u32)(pv->i[0x3E0/4] - 4) < 2) {
                if (func_L20_003F9120(m) != 0) {
                    func_L01_00441FB8(m, 0xC, -1);
                } else {
                    if (func_L05_00354AB0(m) != 0) {
                        func_L01_00441FB8(m, 0xC, -1);
                    } else if (func_L05_00354C10(m) == 0) {
                        func_L01_00441FB8(m, 0xD, -1);
                    } else {
                        func_L01_00441FB8(m, 0xC, -1);
                    }
                    break;
                }
            } else if (func_L20_003F9120(m) != 0) {
                func_003BE4F0(pv->mp[0x3EC/4], 0xE, 0, 10);
            } else if (func_L05_00354AB0(m) != 0) {
                func_L05_00359930(m, 0xE, 0, 10);
            } else {
                func_L05_00359930(m, 0xA, 0, 10);
            }
        }
        func_L20_003F92E0(m);
        if (pv->mp[0x3EC/4]->b[0x60] & 2) {
            func_L01_00441FB8(m, 0xA, 2);
            m->i[0x48/4] = 0;
            pv->mp[0x3EC/4]->i[0x48/4] = 0;
        }
        break;
    case 16:
        if (func_L01_00452EC8(m) != 0) {
            func_L01_00455E98(m, pv->mp[0x230/4], pv->b + 0x250);
            if (func_L05_00354AB0(m) == 0) {
                if (func_00388800(m->b + 0x10, pv->b + 0x220) <= D_L20_001DF674) {
                    pv->i[0x3E4/4] = 2;
                    if ((m->b[0x42] != 0xF) && (m->b[0x43] != 0xF)) {
                        func_L05_00359930(m, 0xF, 0, 10);
                    }
                    m->f[0x48/4] = D_L20_001DF678;
                    pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF678;
                } else {
                    pv->i[0x3E4/4] = 1;
                    func_003BE4F0(m, 6, 0, 10);
                }
            } else {
                pv->i[0x3E4/4] = 0;
                func_003BE4F0(m, 0xE, 0, 10);
            }
        }
        if (pv->i[0x3E4/4] == 0) {
            u8 c;
            sp90[0] = pv->q[0x220/16];
            func_L05_00354DA0(m, sp90);
            if (m->b[0x60] & 2) {
                sp90[0] = pv->q[0x220/16];
                c = f_le(func_L05_00354CC8(m, sp90), D_L20_001DF674);
                if (!c) {
                    pv->i[0x3E4/4] = 1;
                    func_003BE4F0(m, 6, 0, 0);
                } else {
                    pv->i[0x3E4/4] = 2;
                    func_L05_00359930(m, 0xF, 0, 0);
                    m->f[0x48/4] = D_L20_001DF678;
                    pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF678;
                }
            }
        } else if (pv->i[0x3E4/4] == 1) {
            u8 c;
            if (pv->h[0x3DA/2] != 0) {
                func_L01_00459F10(m, pv->mp[0x230/4]->b + 0x10);
            } else {
                u8 *r = pv->b + 0x250;
                if (pv->mp[0x230/4] != pv->mp[0x2A0/4]) {
                    func_L01_00455E98(m, pv->mp[0x230/4], r);
                }
                func_L01_00455C88(m, r, 0, 0);
                func_L01_00457440(m, r);
            }
            sp90[0] = pv->q[0x220/16];
            c = f_le(func_L05_00354CC8(m, sp90), D_L20_001DF674);
            if (c) {
                pv->i[0x3E4/4] = 2;
                func_L05_00359930(m, 0xF, 0, 0);
                m->f[0x48/4] = D_L20_001DF678;
                pv->mp[0x3EC/4]->f[0x48/4] = D_L20_001DF678;
            }
        } else if (pv->i[0x3E4/4] == 2) {
            f32 h = func_L01_00436500(m);
            sp90[0] = pv->q[0x220/16];
            func_L05_00354DA0(m, sp90);
            if ((D_L20_001DF698 < h) && (h < D_L20_001DF69C)) {
                func_003BDA38(pv->mp[0x3EC/4], 0, sp90);
                func_003BDA38(pv->mp[0x3EC/4], 1, &spA0);
                func_L01_004434F8(&spB0, sp90, &spA0, pv->b + 0x220);
                func_L01_00443648(m, D_L20_001DF680, &spB0, 0x10001, (f32)pv->b[0x45], D_L20_001DF67C, 0, 1, 0);
            }
            if (pv->mp[0x3EC/4]->b[0x60] & 2) {
                func_L01_00441FB8(m, m->b[0x94], -1);
            }
        }
        break;
    case 17:
        if (func_L01_00452EC8(m) != 0) {
            func_003BE4F0(m, 0x12, 0, 10);
            func_003BE4F0(pv->mp[0x3EC/4], 2, 0, 10);
            pv->i[0xA8/4] |= 0x404;
        }
        func_L20_003F92E0(m);
        if (m->b[0x60] & 2) {
            func_003BE4F0(m, 0x13, 0, 10);
            func_L01_00441FB8(m, m->b[0x94], -1);
        }
        break;
    case 18:
        if (func_L01_00452EC8(m) != 0) {
            func_003BE4F0(pv->mp[0x3EC/4], 2, 0, 10);
            pv->i[0xA8/4] &= ~4;
            pv->i[0xA8/4] &= ~0x400;
        }
        func_L20_003F92E0(m);
        if ((m->b[0x42] != 0x14) && (m->b[0x43] != 0x14)) {
            if (m->f[0x18/4] - pv->f[0x100/4] < D_L20_001DF6B0) {
                func_003BE4F0(m, 0x14, 0, 10);
            }
        } else if (m->b[0x60] & 2) {
            func_L01_00441FB8(m, m->b[0x94], -1);
            m->i[0x48/4] = 0;
            pv->mp[0x3EC/4]->i[0x48/4] = 0;
        }
        break;
    }
    func_L20_003FC898(m);
}
/* localdecomp:end func_L20_003F9418 */
