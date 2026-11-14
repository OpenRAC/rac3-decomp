#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union Mo_ { u8 b[0x100]; s8 c[0x100]; s16 h[0x80]; u16 uh[0x80]; s32 i[0x40]; u32 u[0x40]; f32 f[0x40]; void *p[0x40]; union Mo_ *mp[0x40]; u128_t q[0x10]; } Mo;
typedef union Pv_ { u8 b[0x400]; s8 c[0x400]; s16 h[0x200]; u16 uh[0x200]; s32 i[0x100]; u32 u[0x100]; f32 f[0x100]; void *p[0x100]; Mo *mp[0x100]; u128_t q[0x40]; } Pv;
typedef union { f32 f[4]; s32 i[4]; u128_t q; } __attribute__((aligned(16))) V4;
typedef struct { V4 pos; V4 dir; f32 f20[16]; } Beam;
typedef union { u8 b[0x3000]; s16 h[0x1800]; s32 i[0xC00]; f32 f[0xC00]; } GBig;
typedef union { u8 *p[0x100]; } PtrTab;
typedef struct { u8 pad[0xD0]; u8 on; u8 pad1[0xB]; union Mo_ *owner; } Chan;

/* localdecomp:start func_L20_003AF880 */
/* func_L20_003AF880: the final boss's per-frame update (Nefarious's ship / its two arm mobys at pvar
   0x2E0/0x2E4): a switch on the boss mode (m+0x95, 0-5) and one on its state (m+0x20, 1-14) with
   particle bursts (func_L01_0046A610 / func_L01_004713C8), the 30-argument explosion call
   func_L01_003303B8 and sound slots in D_001A30B0 (0x80-byte records, owner at +0xDC, live flag at
   +0xD0). Written from retail by hand (Opus, 2026-11-14); m2c had failed on it.
   Near miss: 2421 of 2423 instructions; 2396 (98.9 percent) equal when aligned with registers
   ignored. Needs "-mvu0-use-vf0-vf2 ... @ps2as" on src/levels/20_final_boss/L20_003AF880.c and
   include/vu0.h; the later C functions of the file declare func_0038CAD0/func_0038CB00 as s32 too.
   What mattered:
   - all vectors are function-scope locals (gcc 2.95 never shares stack slots between blocks): 0x90,
     0xA0, a 0x60-byte union at 0xB0 (the beam record copied from D_L20_002C5280 in mode 3, and the
     vectors 0xB0..0x100 of the other states), a 4-row matrix at 0x110 and 0x150; case 1's and
     case 14's vC0/vD0 read uninitialised slots, as retail does;
   - case order 1, 3, 6, 7, 8, 11, 10, 9, 12, 13, 14 (retail's layout; 8 and 11 cross-jump into
     9 and 10);
   - D_001A4BE0, D_001CCFD0, D_001A30B0, D_L20_001E2E80 and D_L20_00220258 as aggregates with
     .extern size hints (lui/addiu base + offset loads);
   - the particle pointer is one u8 * variable: the vector address, then the call's result
     (retail's $s0); the random int argument in a variable before the call; func_L01_0046A610 takes
     (void *, f32, f32, f32, void *, s32, s32, s32, s32, f32, f32);
   - constants retail builds at run time (1680000 * 2.4f is inexact, so not folded) and the
     one-ulp-off ones (0.0200000014f, 1.60000014f, 0.100000009f, 0.140000015f, 1.00000012f).
   Left (about 28 small hunks):
   - mode 3: retail reloads m+0x96 for every test (and again for the subtraction); this C keeps
     it in a register (one instruction short);
   - case 1's loop: retail's vadd has D0 in vf1 and the sum in vf2 (vf1/vf2 swapped here), and a
     nop before the loop head;
   - argument set-up order around func_L01_0046A610 (the D_L20_001D66B0 lui) and
     func_L01_004713C8 (a0 before t0) in cases 13/14. */
#include "vu0.h"
static __inline__ void vec_add_bt(void *d, void *a, void *b) {
    vu0_q qa, qb;
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(qa) : "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qa));
}

extern GBig D_001A4BE0;
extern GBig D_001CCFD0;
__asm__(".extern D_001A4BE0, 16");
__asm__(".extern D_001CCFD0, 16");
extern Mo *D_L20_001E029C;
extern f32 D_L20_001DFB50;
extern GBig D_L20_001E2E80;
__asm__(".extern D_L20_001E2E80, 16");
extern char D_L20_001E9980[];
extern Beam D_L20_002C5280;
extern char D_L20_001D66B0[] __attribute__((section(".sdata")));
extern u8 *D_L20_002203C8[];

extern PtrTab D_L20_00220258;
__asm__(".extern D_L20_00220258, 16");
extern u8 *func_00382348(void *);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_00382580(void *, f32, f32);
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_00392B20();
extern s32 func_00392C78(void *);
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
extern void func_003A1798(void);
extern void func_003A2B68(s32, s32);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2880(void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_003C4098(void *, void *, void *, f32);
extern void func_003C7958(void *, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00356C90(void *);
extern void func_L01_003B1350(void *);
extern void func_L01_003B1DB8(void *);
extern void func_L01_00404808(void *, void *);
extern f32 func_L01_004395E0(void *);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_00443B88(f32 *, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_L01_00447878(f32 *, f32 *, f32 *, f32, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_004561E0(void *);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_0045BD10(void *, f32);
extern u8 *func_L01_0046A610(void *, f32, void *, s32, s32, s32, s32, f32, f32, f32, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L01_004BA800(void);
extern s32 func_L03_00433C70(void *, void *, void *, s32, s32, s32, s32, f32, f32);
extern void func_L07_003E3C90(void *, void *, void *, s32, s32, s32, f32, f32, f32);
extern s32 func_L20_003B1E58();
extern void func_L20_003B24B0(s32);
extern void func_L20_003B24F0(u8 *);
extern void func_L20_003B2618(void *, s32, s32, s32);
extern void func_L20_004026A0(void *);

extern Chan D_001A30B0;
__asm__(".extern D_001A30B0, 16");
extern s32 D_L20_001DFD40;
extern s32 D_L20_001E9BD8[];
extern f32 D_L20_001DE2F8;
extern f32 D_L20_001DE2FC;
extern f32 D_L20_001DE300;
__asm__(".extern D_L20_001DE2F8, 4");
__asm__(".extern D_L20_001DE2FC, 4");
__asm__(".extern D_L20_001DE300, 4");
extern void func_L20_003B2698(void);
extern void func_L20_003B2960(void);
extern void func_L20_003F21A8(void *, void *, void *, void *);
extern void func_L20_003F27E8(void *, void *, void *, s32, f32, f32);
extern void func_L20_003F4320(void *, f32, f32);



#define SND(h) ((Chan *)((u8 *)&D_001A30B0 + (h) * 0x80))


void func_L20_003AF880(Mo *m) {
    Pv *pv = m->p[0x68 / 4];
    s32 flag;
    V4 v90, vA0;
    union {
        Beam b;
        struct { V4 b0, c0, d0, e0, f0, x100; } s;
    } u;
    V4 v110[4];
    V4 v150;
    s32 n;
    u8 *pp;

    if (func_L20_003B1E58() != 0) {
        func_003C2880(m);
        return;
    }
    flag = 0;
    if (D_001A4BE0.i[0x19E0 / 4] != 0) {
        f32 *p = (f32 *)func_00382348((void *)D_001A4BE0.i[0x19E0 / 4]);
        if (p != 0) {
            f32 f = *p;
            if (pv->f[0x394 / 4] != f) {
                if (f < pv->f[0x394 / 4]) {
                    flag = 1;
                }
                pv->f[0x394 / 4] = f;
            }
        }
    } else {
        pv->f[0x394 / 4] = 0.0f;
    }
    if ((flag != 0) || ((D_001A4BE0.i[0x2808 / 4] != 0) && (D_001A4BE0.i[0x19E0 / 4] == 0))) {
        if ((func_00382468(10) == 0) && (m->b[0x95] == 2)) {
            func_L01_003B1DB8(m);
        }
    }
    switch (m->b[0x95]) {
    case 5:
        if (func_L01_004BA800() == 0) {
            func_003A0EC0(9, 1, 0, 0, 0);
        }
        break;
    case 4:
        if (func_L01_00456250(m) != 0) {
            Mo *c;
            func_L20_003B2618(m, 2, 0, 0);
            c = m->mp[0x24 / 4];
            m->uh[0x34 / 2] &= 0xFFBE;
            m->uh[0x34 / 2] |= c->uh[0x44 / 2] & 0x1000;
            m->i[0x98 / 4] = c->i[0x10 / 4];
            pv->mp[0x2E4 / 4]->uh[0x34 / 2] &= 0xFFBE;
            pv->mp[0x2E4 / 4]->uh[0x34 / 2] |= pv->mp[0x2E4 / 4]->mp[0x24 / 4]->uh[0x44 / 2] & 0x1000;
            pv->mp[0x2E4 / 4]->i[0x98 / 4] = pv->mp[0x2E4 / 4]->mp[0x24 / 4]->i[0x10 / 4];
            pv->mp[0x2E0 / 4]->uh[0x34 / 2] &= 0xFFBE;
            pv->mp[0x2E0 / 4]->uh[0x34 / 2] |= pv->mp[0x2E0 / 4]->mp[0x24 / 4]->uh[0x44 / 2] & 0x1000;
            pv->mp[0x2E0 / 4]->i[0x98 / 4] = pv->mp[0x2E0 / 4]->mp[0x24 / 4]->i[0x10 / 4];
            func_L01_004450F0(m, 3, 2);
        }
        break;
    case 0:
        func_L01_0045BD10(m, func_0038D160(D_001A4BE0.f[0x80 / 4] - m->f[0x10 / 4], D_001A4BE0.f[0x84 / 4] - m->f[0x14 / 4]));
        if (func_L01_004561E0(m) != 0) {
            pv->h[0x2D6 / 2] = (func_00382498(0, 30) * 5 + 2) / 6;
        }
        if ((pv->h[0x234 / 2] == 1) && (func_0038CB00(pv->b + 0x2D6) != 0)) {
            func_L01_004450F0(m, 4, 2);
        } else if ((pv->i[0x2D8 / 4] != 0) && (func_0038CB00(pv->b + 0x2D6) != 0)) {
            func_L01_004450F0(m, 2, 1);
            pv->i[0x2D8 / 4] = 0;
            if (pv->i[0x2D0 / 4] < 0xFA) {
                pv->i[0x2D0 / 4] = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    case 1:
        if (pv->h[0x234 / 2] == 1) {
            func_L01_004450F0(m, 4, 2);
        } else if (pv->i[0x2D0 / 4] == 0) {
            func_L01_004450F0(m, 1, 0);
        }
        break;
    case 2:
        if (func_L01_004561E0(m) != 0) {
            func_003A2B68((pv->i[0x364 / 4] & 0x3FFF) + 0x7D0, 0);
            pv->i[0x398 / 4] = func_00382498(0xB4, 0x168);
        }
        if (D_001CCFD0.i[0x6C / 4] == 0) {
            if ((D_001CCFD0.i[0x24 / 4] == -1) && (D_001CCFD0.i[0x94 / 4] == 0) && (pv->i[0x390 / 4] == 0) &&
                (D_001A4BE0.i[0x2850 / 4] > 0) && (func_0038CAD0(pv->b + 0x398) != 0)) {
                func_L01_00356C90(m);
            }
            if ((D_001CCFD0.i[0x6C / 4] == 0) && (D_001CCFD0.i[0x24 / 4] == -1) && (D_001CCFD0.i[0x94 / 4] == 0) &&
                (pv->i[0x390 / 4] == 0) && (D_001A4BE0.i[0x2850 / 4] < 0)) {
                func_L01_003B1350(m);
            }
        }
        if ((D_001CCFD0.h[0x76 / 2] == 0) && (D_001CCFD0.h[0x9E / 2] == 3) && (D_001CCFD0.h[0x98 / 2] < 7000)) {
            func_003A1798();
            pv->i[0x390 / 4] = 0;
        }
        if (D_001A4BE0.i[0x19E0 / 4] != 0) {
            func_L01_0045BD10(m, func_0038D160(D_001A4BE0.f[0x80 / 4] - m->f[0x10 / 4], D_001A4BE0.f[0x84 / 4] - m->f[0x14 / 4]));
        } else {
            Mo *t = &D_L20_001E029C[pv->i[0x2DC / 4]];
            func_L01_0045BD10(m, func_0038D160(t->f[0x10 / 4] - m->f[0x10 / 4], t->f[0x14 / 4] - m->f[0x14 / 4]));
        }
        if (pv->h[0x234 / 2] != 1) {
            func_L01_004561E0(m);
        }
        break;
    case 3: {
        s32 r = func_L01_00454370(m, pv->b + 0x160);
        if ((func_L01_004561E0(m) != 0) && (pv->f[0x30 / 4] <= 0.0f)) {
            func_L20_003B2618(m, 0x11, 0, 0x11);
            m->f[0x48 / 4] = 0.65f;
            func_003C2F58(m, 0, &v90);
            func_003C2F58(pv->mp[0x2E0 / 4], 1, &vA0);
            func_L01_003303B8(&vA0, 1, 10, 10, 10, 10, 0x14, 0, 9.0f, 0.0f, 0.0f, 2.0f,
                              1, 1, 1, 1, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_003A52A0(func_00382498(5, 9), 0, m);
            D_L20_001E2E80.f[0x40 / 4] = 0.1f;
            D_L20_001E2E80.i[0x48 / 4] = 0x4B;
            D_L20_001E2E80.f[0x20 / 4] = 0.2f;
            D_L20_001E2E80.i[0x28 / 4] = 0x9E;
            D_L20_001E2E80.i[0x2C / 4] = 0;
        }
        if (pv->f[0x30 / 4] <= 0.0f) {
            if (*(u16 *)((u8 *)m + 0x96) == 0x96) {
                m->f[0x48 / 4] = 0.65f;
            }
            if (*(u16 *)((u8 *)m + 0x96) >= 0x96) {
                D_L20_001DFB50 = (f32)(*(u16 *)((u8 *)m + 0x96) - 0x96) / 60.0f;
            }
            if (*(u16 *)((u8 *)m + 0x96) == 0x7D) {
                func_003C2F58(m, 0, &v90);
                func_003C2F58(pv->mp[0x2E0 / 4], 1, &vA0);
                func_003A52A0(10, 0, m);
                func_L01_003303B8(&vA0, 1, 0, 0, 0, 0, 0, 0, 9.0f, 0.0f, 0.0f, 2.0f,
                                  1, 1, 1, 1, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                                  0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            }
            if (*(u16 *)((u8 *)m + 0x96) >= 0xB8) {
                func_L20_003B24B0((s32)m);
                m->i[0x98 / 4] = 0;
                m->uh[0x34 / 2] = (m->uh[0x34 / 2] | 0x41) & 0xEFFF;
                func_L01_004AA7E8(m, 1);
                pv->mp[0x2E4 / 4]->uh[0x34 / 2] |= 0x41;
                pv->mp[0x2E4 / 4]->uh[0x34 / 2] &= 0xEFFF;
                pv->mp[0x2E4 / 4]->i[0x98 / 4] = 0;
                func_L01_004AA7E8(pv->mp[0x2E4 / 4], 1);
                pv->mp[0x2E0 / 4]->uh[0x34 / 2] |= 0x41;
                pv->mp[0x2E0 / 4]->uh[0x34 / 2] &= 0xEFFF;
                pv->mp[0x2E0 / 4]->i[0x98 / 4] = 0;
                func_L01_004AA7E8(pv->mp[0x2E0 / 4], 1);
                func_L01_004450F0(m, 0x12, 5);
                func_00392B20(D_L20_001E9980, 0x16);
                func_00392C78(D_L20_001E9980);
            } else {
                s32 hit;
                f32 s;
                D_001A4BE0.h[0x1DC / 2] = 3;
                u.b = D_L20_002C5280;
                hit = 0;
                u.b.f20[1] = func_003824E0(2.0f, 5.0f);
                u.b.f20[13] = 1.4f;
                u.b.f20[0] = 1.0f;
                if (func_00382468(25) == 0) {
                    func_003C2EC0(pv->mp[0x2E0 / 4], 1, v110);
                    hit = 1;
                }
                if (func_00382468(25) == 0) {
                    func_003C2EC0(pv->mp[0x2E0 / 4], 2, v110);
                    hit = 1;
                }
                if (func_00382468(25) == 0) {
                    func_003C2EC0(pv->mp[0x2E4 / 4], 2, v110);
                    hit = 1;
                }
                if (func_00382468(25) == 0) {
                    func_003C2EC0(pv->mp[0x2E4 / 4], 3, v110);
                    hit = 1;
                }
                if (func_00382468(25) == 0) {
                    func_003C2EC0(m, 1, v110);
                    hit = 1;
                }
                if (func_00382468(25) == 0) {
                    func_003C2EC0(m, 2, v110);
                    hit = 1;
                }
                if (hit != 0) {
                    u.b.pos = v110[3];
                    func_003C2F58(m, 0, &v90);
                    s = -1.0f;
                    if (func_00382468(2) == 0) {
                        s = 1.0f;
                    }
                    func_0038CF68(&u.b.dir, &v110[func_00382468(3)], s);
                    vec_sub_ab(&vA0, &u.b.pos, &v90);
                    func_0038CF68(&vA0, &vA0, 1.0f);
                    v150 = u.b.dir;
                    func_003C4098(&u.b.dir, &vA0, &v150, func_003824E0(0.1f, 0.5f));
                    func_L20_004026A0(&u.b);
                    if (func_00382468(3) == 0) {
                        func_003A52A0(func_00382498(5, 9), 0, m);
                    }
                }
            }
        } else if ((r & 2) && (pv->f[0x30 / 4] > 0.0f)) {
            if (pv->h[0x234 / 2] == 1) {
                func_L01_004450F0(m, 4, 2);
            } else {
                func_L01_004450F0(m, 2, 1);
                pv->i[0x2D0 / 4] = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    }
    }
    switch (m->b[0x20]) {
    case 1: {
        u8 *e;
        s32 i;
        f32 k = 1680000.0f;
        func_003C2EC0(pv->mp[0x2E0 / 4], 1, &v90);
        func_0038CF68(&u.s.e0, &v90, 3.0f);
        vec_add_ab(&u.s.d0, &u.s.e0, &u.s.c0);
        if (func_00382468(2) != 0) {
            e = (u8 *)&u.s.d0;
            n = (s32)func_L01_00443A18(1.0f, -1.0f);
            e = func_L01_0046A610(e, k * 6.0f, D_L20_001D66B0, 0xC, 6, 0x7C0030, n, 500.0f, 1.0f, 0.0f, 0.0f);
            if (e != 0) {
                e[2] = D_L20_002203C8[0][1];
            }
        }
        u.s.f0.f[0] = u.s.d0.f[0] + func_L01_00443A18(0.0f, 0.04f);
        u.s.f0.f[1] = u.s.d0.f[1] + func_L01_00443A18(0.0f, 0.04f);
        u.s.f0.f[2] = u.s.d0.f[2] + func_L01_00443A18(0.0f, 0.04f);
        if (func_00382468(2) != 0) {
            e = (u8 *)&u.s.f0;
            n = (s32)func_L01_00443A18(1.0f, -1.0f);
            e = func_L01_0046A610(e, k * 2.4f, D_L20_001D66B0, 0xC, 0x7F, 0x7C0030, n, 500.0f, 1.0f, 0.0f, 0.0f);
            if (e != 0) {
                e[3] = func_00382468(2) ? 0x48 : 0x44;
                e[2] = D_L20_002203C8[0][0];
            }
        }
        for (i = 0; i < 20; i++) {
            func_00382580(&u.s.x100, 5.0f, 8.0f);
            vec_add_ab(&v110[0], &u.s.x100, &u.s.d0);
            vec_sub_ab(&u.s.x100, &u.s.d0, &v110[0]);
            func_0038CF68(&u.s.x100, &u.s.x100, 0.240000010f);
            pp = func_L01_004713C8(&v110[0], &u.s.x100, 0x19, 0, (s32)func_L01_00443A18(2.0f, 5.0f), 0x7F, 0x7F,
                                  func_003824E0(0.8f, 1.25f) * 210000.0f, 2100.0f, 0.00584f, 6);
            if (pp != 0) {
                pp[3] = 0x44;
                pp[2] = D_L20_00220258.p[0xD4 / 4][0];
            }
            pp = func_L01_004713C8(&v110[0], &u.s.x100, 0x19, 0, (s32)func_L01_00443A18(2.0f, 5.0f), 0x30, 0x30,
                                  func_003824E0(0.8f, 1.25f) * 210000.0f * 3.0f, 4200.0f, 0.00584f, 0);
            if (pp != 0) {
                pp[3] = 0x44;
                pp[2] = D_L20_00220258.p[0xD4 / 4][0];
            }
        }
        break;
    }
    case 3:
        if (m->b[0x60] & 2) {
            func_L01_004450F0(m, 6, -1);
            func_L20_003B2618(m, 0xC, 0, 7);
        }
        break;
    case 6: {
        f32 d = func_L01_004395E0(m);
        if ((13.0f < d) && (d < 28.0f)) {
            f32 a;
            Mo *t;
            func_003A52A0(2, 0, m);
            func_003C2F58(pv->mp[0x2E0 / 4], 1, &v90);
            a = m->f[0xF8 / 4];
            a = func_0038DAB8(a, func_L01_00443A18(15.0f, 65.0f) * 0.0174532924f);
            vA0.f[0] = func_0038D098(a);
            vA0.f[1] = func_0038D0B0(a);
            vA0.i[2] = 0;
            vA0.f[2] = func_L01_00443A18(vA0.f[2], 45.0f) * 0.0174532924f;
            func_0038CF68(&vA0, &vA0, 1.00000012f);
            if (D_001A4BE0.i[0x19E0 / 4] != 0) {
                t = *(Mo **)&D_001A4BE0.i[0x25C0 / 4];
            } else if (func_00382468(2) != 0) {
                t = *(Mo **)&D_001A4BE0.i[0x25C0 / 4];
            } else {
                t = &D_L20_001E029C[pv->i[0x2DC / 4]];
            }
            func_L20_003F21A8(pv->mp[0x2E0 / 4], &v90, &vA0, t);
        }
        if (m->b[0x60] & 2) {
            func_L20_003B2618(m, 7, 0, 0xF);
            func_L01_004450F0(m, 7, -1);
        }
        break;
    }
    case 7:
        if (m->b[0x60] & 2) {
            func_L20_003B2618(m, 8, 0, 2);
            func_L01_004450F0(m, 8, -1);
        }
        break;
    case 8:
        if (m->b[0x60] & 2) {
            func_L20_003B2618(m, 9, 0, 4);
            func_L01_004450F0(m, 9, -1);
        }
        if ((func_L01_0044E1B8(m, 0.5f) != 0) || (func_L01_0044E1B8(m, 15.0f) != 0)) {
            f32 sp, r;
            func_003A52A0(0, 0, m);
            func_L01_00443B88(v90.f, 0.0f, 1.0f);
            func_003C2F58(pv->mp[0x2E4 / 4], 0, &vA0);
            func_0038CE20(&u.s.b0, &v90, 3.0f);
            u.s.b0.f[2] = 0.0f;
            u.s.c0.q = *(u128_t *)&D_001A4BE0.f[0xD0 / 4];
            if (D_001A4BE0.i[0x19E0 / 4] == 0) {
                u.s.c0.q = *(u128_t *)((u8 *)D_L20_001E029C + (pv->i[0x2DC / 4] << 8) + 0x10);
            }
            vec_add_ba(&u.s.b0, &u.s.b0, &u.s.c0);
            sp = D_L20_001DE2F8 * 0.0200000014f;
            r = func_003824E0(D_L20_001DE2FC, D_L20_001DE300) * 0.000400000019f;
            vec_sub_ab(&u.s.d0, &u.s.b0, &vA0);
            u.s.d0.f[2] = 0.0f;
            func_0038CF68(&u.s.d0, &u.s.d0, sp);
            u.s.d0.f[2] = func_L01_00447878(vA0.f, u.s.b0.f, 0, D_L20_001DE2F8 * 0.0200000014f, -r);
            func_L01_003303B8(&vA0, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 1, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L20_003F27E8(pv->mp[0x2E4 / 4], &vA0, &u.s.d0, 0, r, 150.0f);
        }
        break;
    case 11:
        if (m->b[0x60] & 2) {
            func_L20_003B2618(m, 0xC, 0, 8);
            func_L01_004450F0(m, 6, -1);
        }
        if ((D_L20_001DFD40 & 5) == (((s32)m >> 8) & 5)) {
            Mo *h;
            func_003A52A0(0, 0, m);
            func_L01_00443B88(v90.f, 0.0f, 1.0f);
            func_003C2F58(pv->mp[0x2E4 / 4], 1, &vA0);
            u.s.c0.q = *(u128_t *)&D_001A4BE0.f[0xD0 / 4];
            if (D_001A4BE0.i[0x19E0 / 4] == 0) {
                u.s.c0.q = *(u128_t *)((u8 *)D_L20_001E029C + (pv->i[0x2DC / 4] << 8) + 0x10);
            }
            func_0038CE20(&u.s.b0, &v90, 3.0f);
            u.s.b0.f[2] = 0.0f;
            u.s.b0 = u.s.c0;
            h = *(Mo **)&D_001A4BE0.i[0x19E0 / 4];
            if ((h != 0) && (h->h[0xAA / 2] == 0x107E)) {
                func_0038CF68(&u.s.d0, (u8 *)h->p[0x68 / 4] + 0x290, func_003824E0(4.0f, 10.0f));
                vec_add_ab(&u.s.b0, &u.s.d0, &u.s.b0);
            }
            vec_sub_ab(&u.s.d0, &u.s.b0, &vA0);
            func_0038CF68(&u.s.d0, &u.s.d0, 1.60000014f);
            func_L01_003303B8(&vA0, 0, 0, 0, 0, 5, 0, 0, 2.0f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L07_003E3C90(m, &vA0, &u.s.d0, 1, 0xC8, 0, 45.0f, 3.0f, 0.0f);
        }
        break;
    case 10:
        if (m->b[0x60] & 2) {
            func_L20_003B2618(m, 9, 0, 4);
            func_L01_004450F0(m, 0xB, -1);
        }
        if ((D_L20_001DFD40 & 5) == (((s32)m >> 8) & 5)) {
            Mo *h;
            func_003A52A0(0, 0, m);
            func_L01_00443B88(v90.f, 0.0f, 1.0f);
            func_003C2F58(pv->mp[0x2E4 / 4], 0, &vA0);
            func_0038CE20(&u.s.b0, &v90, 3.0f);
            u.s.b0.f[2] = 0.0f;
            u.s.c0.q = *(u128_t *)&D_001A4BE0.f[0xD0 / 4];
            h = *(Mo **)&D_001A4BE0.i[0x19E0 / 4];
            if (h == 0) {
                u.s.c0.q = *(u128_t *)((u8 *)D_L20_001E029C + (pv->i[0x2DC / 4] << 8) + 0x10);
            }
            u.s.b0 = u.s.c0;
            if ((h != 0) && (h->h[0xAA / 2] == 0x107E)) {
                func_0038CF68(&u.s.d0, (u8 *)h->p[0x68 / 4] + 0x290, func_003824E0(14.0f, 24.0f));
                vec_add_ab(&u.s.b0, &u.s.d0, &u.s.b0);
            }
            vec_sub_ab(&u.s.d0, &u.s.b0, &vA0);
            func_0038CF68(&u.s.d0, &u.s.d0, 1.60000014f);
            func_L01_003303B8(&vA0, 0, 0, 0, 0, 5, 0, 0, 2.0f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L07_003E3C90(pv->mp[0x2E4 / 4], &vA0, &u.s.d0, 1, 0x96, 0, 45.0f, 3.0f, 0.0f);
        }
        break;
    case 9:
        if (m->b[0x60] & 2) {
            func_L20_003B2618(m, 0xA, 0, 7);
            func_L01_004450F0(m, 0xC, -1);
        }
        if ((func_L01_0044E1B8(m, 4.0f) != 0) || (func_L01_0044E1B8(m, 18.0f) != 0)) {
            f32 sp, r;
            func_003A52A0(0, 0, m);
            func_L01_00443B88(v90.f, 0.0f, 1.0f);
            func_003C2F58(pv->mp[0x2E4 / 4], 1, &vA0);
            u.s.c0.q = *(u128_t *)&D_001A4BE0.f[0xD0 / 4];
            if (D_001A4BE0.i[0x19E0 / 4] == 0) {
                u.s.c0.q = *(u128_t *)((u8 *)D_L20_001E029C + (pv->i[0x2DC / 4] << 8) + 0x10);
            }
            func_0038CE20(&u.s.b0, &v90, 3.0f);
            u.s.b0.f[2] = 0.0f;
            vec_add_ba(&u.s.b0, &u.s.b0, &u.s.c0);
            sp = D_L20_001DE2F8 * 0.0200000014f;
            r = func_003824E0(D_L20_001DE2FC, D_L20_001DE300) * 0.000400000019f;
            vec_sub_ab(&u.s.d0, &u.s.b0, &vA0);
            u.s.d0.f[2] = 0.0f;
            func_0038CF68(&u.s.d0, &u.s.d0, sp);
            u.s.d0.f[2] = func_L01_00447878(vA0.f, u.s.b0.f, 0, D_L20_001DE2F8 * 0.0200000014f, -r);
            func_L01_003303B8(&vA0, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 1, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L20_003F27E8(pv->mp[0x2E4 / 4], &vA0, &u.s.d0, 0, r, 150.0f);
        }
        break;
    case 12:
        if (m->b[0x60] & 2) {
            if (m->b[0x42] == 10) {
                func_L20_003B2618(m, 0xB, 0, 7);
            }
            if ((m->b[0x60] & 2) && (m->b[0x42] == 11)) {
                func_L20_003B2618(m, 8, 0, 0xC);
                func_L01_004450F0(m, 0xA, -1);
            }
        }
        break;
    case 13:
        if (func_L01_004561B8(m) != 0) {
            pv->i[0x2F4 / 4] = 0;
            pv->i[0x2FC / 4] = 0;
            pv->i[0x2F8 / 4] = 0;
        }
        pv->f[0x2F4 / 4] += 0.0299999993f;
        if (m->b[0x60] & 2) {
            func_L20_003B2618(m, 0xD, 0, 0x11);
            func_L01_004450F0(m, 0xE, -1);
            func_003C2F58(pv->mp[0x2E0 / 4], 2, &v90);
            pv->q[0x310 / 16] = v90.q;
            vA0.q = *(u128_t *)&D_001A4BE0.f[0xD0 / 4];
            if (D_001A4BE0.i[0x19E0 / 4] == 0) {
                vA0.q = *(u128_t *)((u8 *)D_L20_001E029C + (pv->i[0x2DC / 4] << 8) + 0x10);
            }
            pv->q[0x300 / 16] = vA0.q;
        } else {
            f32 k = pv->f[0x2F4 / 4] * 262500.0f;
            u8 *e;
            s32 i;
            func_003C2EC0(pv->mp[0x2E0 / 4], 1, &u.s.b0);
            func_0038CF68(&u.s.f0, &u.s.b0, 3.0f);
            vec_add_ab(&v90, &u.s.e0, &u.s.f0);
            if (func_00382468(2) != 0) {
            e = (u8 *)&v90;
                n = (s32)func_L01_00443A18(1.0f, -1.0f);
                e = func_L01_0046A610(e, k * 6.0f, D_L20_001D66B0, 0xC, 6, 0x7C0030, n, 500.0f, 1.0f, 0.0f, 0.0f);
                if (e != 0) {
                    e[2] = D_L20_002203C8[0][1];
                }
            }
            vA0.f[0] = v90.f[0] + func_L01_00443A18(0.0f, 0.04f);
            vA0.f[1] = v90.f[1] + func_L01_00443A18(0.0f, 0.04f);
            vA0.f[2] = v90.f[2] + func_L01_00443A18(0.0f, 0.04f);
            if (func_00382468(2) != 0) {
            e = (u8 *)&vA0;
                n = (s32)func_L01_00443A18(1.0f, -1.0f);
                e = func_L01_0046A610(e, k * 2.4f, D_L20_001D66B0, 0xC, 0x7F, 0x7C0030, n, 500.0f, 1.0f, 0.0f, 0.0f);
                if (e != 0) {
                    e[3] = func_00382468(2) ? 0x48 : 0x44;
                    e[2] = D_L20_002203C8[0][0];
                }
            }
            for (i = 0; i < 6; i++) {
                func_00382580(&u.s.x100, pv->f[0x2F4 / 4] * 0.100000009f, pv->f[0x2F4 / 4] * 0.140000015f);
                pp = func_L01_004713C8(&v90, &u.s.x100, 0xC, 0, (s32)func_L01_00443A18(2.0f, 5.0f), 0x7F, 0x7F,
                                      func_003824E0(0.8f, 1.25f) * 210000.0f * pv->f[0x2F4 / 4],
                                      pv->f[0x2F4 / 4] * 2100.0f, 0.00584f, 6);
                if (pp != 0) {
                    pp[3] = 0x44;
                    pp[2] = D_L20_00220258.p[0xD4 / 4][0];
                }
                pp = func_L01_004713C8(&v90, &u.s.x100, 0xC, 0, (s32)func_L01_00443A18(2.0f, 5.0f), 0x30, 0x30,
                                      func_003824E0(0.8f, 1.25f) * 210000.0f * 3.0f * pv->f[0x2F4 / 4],
                                      pv->f[0x2F4 / 4] * 4200.0f, 0.00584f, 0);
                if (pp != 0) {
                    pp[3] = 0x44;
                    pp[2] = D_L20_00220258.p[0xD4 / 4][0];
                }
            }
        }
        break;
    case 14: {
        u8 *e;
        s32 i, h, h2, h3;
        f32 k;
        func_L01_00404808(func_L20_003B2698, m);
        pv->f[0x2FC / 4] += 0.0600000024f;
        if (2.5f < pv->f[0x2FC / 4]) {
            pv->f[0x2FC / 4] = 2.5f;
        }
        pv->f[0x2F8 / 4] += 0.0200000014f;
        if (2.5f < pv->f[0x2F8 / 4]) {
            pv->f[0x2F8 / 4] = 2.5f;
        }
        func_003C2EC0(pv->mp[0x2E0 / 4], 1, &vA0);
        func_0038CF68(&u.s.e0, &vA0, 3.0f);
        vec_add_ba(&v90, &u.s.d0, &u.s.e0);
        pv->mp[0x2E4 / 4]->i[0x98 / 4] = 0;
        pv->mp[0x2E0 / 4]->i[0x98 / 4] = 0;
        func_003C7958(pv->mp[0x2E4 / 4], 0x80807F7F);
        func_003C7958(pv->mp[0x2E0 / 4], 0x80807F7F);
        func_L03_00433C70(m, &v90, pv->b + 0x310, 1, 0, 1, 0, 45.0f, 1.0f);
        pv->mp[0x2E4 / 4]->i[0x98 / 4] = pv->mp[0x2E4 / 4]->mp[0x24 / 4]->i[0x10 / 4];
        pv->mp[0x2E0 / 4]->i[0x98 / 4] = pv->mp[0x2E0 / 4]->mp[0x24 / 4]->i[0x10 / 4];
        func_003C7958(pv->mp[0x2E4 / 4], 0x80807F7F);
        func_003C7958(pv->mp[0x2E0 / 4], 0x80807F7F);
        vec_sub_ba(&u.s.f0, pv->b + 0x300, &v90);
        func_0038CF68(&u.s.f0, &u.s.f0, pv->f[0x2F8 / 4] * 120.0f);
        vec_add_ab(&u.s.f0, &u.s.f0, &v90);
        if (func_003D3CB0(&v90, &u.s.f0, 2, m, 0) != 0) {
            if (D_L20_001E9BD8[0] == 0) {
                h2 = pv->i[0x2EC / 4];
                if ((h2 == -1) || ((Mo *)SND(h2)->owner != m) || (SND(h2)->on == 0)) {
                    pv->i[0x2EC / 4] = func_003A52A0(4, 4, m);
                }
                func_L20_003F4320(pv->b + 0x310, 2.0f, 3.0f);
            }
        } else {
            h = pv->i[0x2EC / 4];
            if ((h != -1) && ((Mo *)SND(h)->owner == m) && (SND(h)->on != 0)) {
                func_003A4F28(h);
            }
            pv->i[0x2EC / 4] = -1;
        }
        k = pv->f[0x2F4 / 4] * 262500.0f;
        if (func_00382468(2) != 0) {
            n = (s32)func_L01_00443A18(1.0f, -1.0f);
            e = func_L01_0046A610(&v90, k * 6.0f, D_L20_001D66B0, 0xC, 6, 0x7C0030, n, 500.0f, 1.0f, 0.0f, 0.0f);
            if (e != 0) {
                e[2] = D_L20_002203C8[0][1];
            }
        }
        u.s.x100.f[0] = v90.f[0] + func_L01_00443A18(0.0f, 0.04f);
        u.s.x100.f[1] = v90.f[1] + func_L01_00443A18(0.0f, 0.04f);
        u.s.x100.f[2] = v90.f[2] + func_L01_00443A18(0.0f, 0.04f);
        if (func_00382468(2) != 0) {
            e = (u8 *)&u.s.x100;
            n = (s32)func_L01_00443A18(1.0f, -1.0f);
            e = func_L01_0046A610(e, k * 2.4f, D_L20_001D66B0, 0xC, 0x7F, 0x7C0030, n, 500.0f, 1.0f, 0.0f, 0.0f);
            if (e != 0) {
                e[3] = func_00382468(2) ? 0x48 : 0x44;
                e[2] = D_L20_002203C8[0][0];
            }
        }
        for (i = 0; i < 6; i++) {
            func_00382580(&v110[0], pv->f[0x2F4 / 4] * 0.100000009f, pv->f[0x2F4 / 4] * 0.140000015f);
            pp = func_L01_004713C8(&v90, &v110[0], 0xC, 0, (s32)func_L01_00443A18(2.0f, 5.0f), 0x7F, 0x7F,
                                  func_003824E0(0.8f, 1.25f) * 210000.0f * pv->f[0x2F4 / 4],
                                  pv->f[0x2F4 / 4] * 2100.0f, 0.00584f, 6);
            if (pp != 0) {
                pp[3] = 0x44;
                pp[2] = D_L20_00220258.p[0xD4 / 4][0];
            }
            pp = func_L01_004713C8(&v90, &v110[0], 0xC, 0, (s32)func_L01_00443A18(2.0f, 5.0f), 0x30, 0x30,
                                  func_003824E0(0.8f, 1.25f) * 210000.0f * 3.0f * pv->f[0x2F4 / 4],
                                  pv->f[0x2F4 / 4] * 4200.0f, 0.00584f, 0);
            if (pp != 0) {
                pp[3] = 0x44;
                pp[2] = D_L20_00220258.p[0xD4 / 4][0];
            }
        }
        h3 = pv->i[0x2E8 / 4];
        if ((h3 == -1) || ((Mo *)SND(h3)->owner != m) || (SND(h3)->on == 0)) {
            pv->i[0x2E8 / 4] = func_003A52A0(1, 4, m);
        }
        if (m->uh[0x96 / 2] > 0x96) {
            h = pv->i[0x2EC / 4];
            if ((h != -1) && ((Mo *)SND(h)->owner == m) && (SND(h)->on != 0)) {
                func_003A4F28(h);
            }
            pv->i[0x2EC / 4] = -1;
            h = pv->i[0x2E8 / 4];
            if ((h != -1) && ((Mo *)SND(h)->owner == m) && (SND(h)->on != 0)) {
                func_003A4F28(h);
            }
            pv->i[0x2F8 / 4] = 0;
            pv->i[0x2F4 / 4] = 0;
            pv->i[0x2FC / 4] = 0;
            pv->i[0x2E8 / 4] = -1;
            func_L20_003B2618(m, 0xC, 0, 8);
            func_L01_004450F0(m, 6, -1);
        }
        break;
    }
    }
    func_L20_003B24F0((u8 *)m);
    if ((u8)(m->b[0x95] - 4) >= 2) {
        func_L01_00404808(func_L20_003B2960, m);
    }
}
/* localdecomp:end func_L20_003AF880 */

INCLUDE_ASM("asm/levels", func_L20_003B1E58);

INCLUDE_ASM("asm/levels", func_L20_003B2200);

/* localdecomp:start func_L20_003B24B0 */
void func_L01_004443E8(s32, s32, s32);
void func_L01_00451F60(s32, s32, s32);

void func_L20_003B24B0(s32 arg0) {
    func_L01_00451F60(-1, -1, 0);
    func_L01_004443E8(arg0, 0, 3);
}
/* localdecomp:end func_L20_003B24B0 */

/* localdecomp:start func_L20_003B24F0 */
/* donor: rac2 func_L06_00443E18 (matched there), renamed and adapted to rac3 */
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_00451DF8(u8 *, void *, s32, s32, f32);

void func_L20_003B24F0(u8 *a0)
{
    u8 *s1 = *(u8 **)(a0 + 0x68);
    u32 v;

    func_0038CAD0(s1 + 0x2D0);
    func_0038CB00(s1 + 0x2D4);
    v = *(u16 *)(a0 + 0x96);
    if (v <= 0xFFFE)
        *(u16 *)(a0 + 0x96) = v + 1;
    func_L01_00451DF8(a0, s1 + 0x240, 0, 1, 2.5f);
}
/* localdecomp:end func_L20_003B24F0 */
