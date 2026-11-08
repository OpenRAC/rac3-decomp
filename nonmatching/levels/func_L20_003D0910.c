/* func_L20_003D0910: the final boss's per-frame update on level 20 (Dr. Nefarious' arena; the moby
   with pvars at m+0x68), a switch on its mode (m+0x95: 0-7, jtbl_002C8C90) then one on its state
   (m+0x20: 2-34, jtbl_002C8CB0), then the 0x618/0x67C child updates. Written from retail with an m2c
   draft (Opus, 2026-11-08). No twin: states 16, 23 and 29 are three copies of the same charge/burst
   routine (light, 20-particle ring, sparks, 300-particle blast) with their own bones and constants.
   Near miss: mine 5549 retail 5560: exact-equal 5271 (94.8%), opcode-equal 5415 (97.4%), diffrows 397
   Needs on src/levels/20_final_boss/L20_003CE2D0.c (no other C function in the file):
   "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the VU0 helpers' "j"
   operands, the inline float constants), include/vu0.h (vec_add/sub_ab/ba, qzero, fabs_asm at the
   one abs.s), and the .extern size hints for the $gp scalars. What mattered:
   - vectors are f32[4] aligned(16) locals (sp0..spA0, retail's slots), copied as u128_t; a u128_t
     local written per component turns into ld/and/or/sd bit insertion;
   - D_L20_001DFD40, D_L20_001E2698, D_L20_001D67A8 and D_L20_001E0380 are read both through $gp
     (.extern hint) and through %hi/%lo: the %hi/%lo uses are the _d aliases (as func_L20_003FB6A8);
     D_L20_002203C8 is D_L20_00220258[0x5C] (an array element, so never in a delay slot as a $gp word);
   - the bursts' particle colour as `c = 0xFFFFFF; if (x == 0) ... else if (x == 1) ... else if
     (x == 2)` (retail's chain and movz), the spawn's model choice as an if chain;
   - fresh locals where retail has them: a pointer q = sp10 before the second spark's n (retail keeps
     &sp10 in $s0 across the call), the loop's own particle pointer, p shared by the two sparks;
   - stores in the order sched2 emits them (the light record, D_L20_001DEBEC/F0/F4, the Boss record).
   Left: register allocation and scheduling, mostly in the three burst states (the 20-step loop counter vs the &sp30 pointer: retail spills the pointer to 0xB0, mine the counter), the 3.5/20 divisions that retail does at run time (mine fold), constant materialisation (two li of 0x44/0xFF where mine shares one).
*/
typedef int u128_t __attribute__((mode(TI)));
typedef union Mo_ { long d[0x20]; u8 b[0x100]; s8 c[0x100]; s16 h[0x80]; u16 uh[0x80]; s32 i[0x40]; u32 u[0x40]; f32 f[0x40]; void *p[0x40]; union Pv_ *pv[0x40]; union Mo_ *mp[0x40]; u128_t q[0x10]; } Mo;
typedef union Pv_ { u8 b[0x800]; s8 c[0x800]; s16 h[0x400]; u16 uh[0x400]; s32 i[0x200]; u32 u[0x200]; f32 f[0x200]; void *p[0x200]; Mo *mp[0x200]; f32 *fp[0x200]; u128_t q[0x80]; } Pv;
typedef union { u8 b[0x2600]; s32 i[0x980]; f32 f[0x980]; u128_t q[0x260]; } Hero;
typedef struct { u8 x0[0x30]; u128_t pos; u8 x40[0x30]; u128_t x70; } Spot;

typedef struct { f32 r, g, b; s32 on; union { u128_t pos; struct { f32 x, y, z, w; } v; } u; } Light;
typedef struct { u8 x0[0x20]; f32 x20; u8 x24[4]; s32 x28; s32 x2C; u8 x30[0x10]; f32 x40; u8 x44[4]; s32 x48; u8 x4C[0xF8]; Mo *x144; s32 x148; } Boss;
typedef struct { u8 x0[0x20]; u8 *x20[0x80]; } Pal;

extern s32 func_L20_003D61B8(Mo *);
extern s32 func_L20_003D6AE0(Mo *);
extern s32 func_L20_003D6B78(Mo *);
extern void func_L20_003D6BF8(Mo *);
extern void func_L20_003D6D18(Mo *);
extern void func_L20_003E56D8(Mo *, u128_t *, u128_t *, s32, s32);
extern void func_L20_003EAA70(Mo *, u8 *, u128_t *);
extern void func_L20_003F9C10(Mo *, u128_t *, u128_t *, f32);
extern void func_L20_003D6F30(void);
extern void func_L20_003D7558(void);
extern void func_L20_003D7950(void);
extern void func_L20_003D8248(void);
extern f32 *func_L01_003F2A50(s32, s32);
extern void func_L01_00404808(void *, Mo *);
extern void func_L01_00404A10(void *, Mo *);
extern s32 fe_func_0038CAD0(u8 *);
extern s32 fe_func_0038CB00(u8 *);
extern void fe_func_0038CE20(void *, void *, f32);
extern f32 fe_func_0038CED8(u128_t *);
extern f32 fe_func_0038CF38(void *, void *);
extern void fe_func_0038CF68(u128_t *, void *, f32);
extern f32 fe_func_0038D098(f32);
extern f32 fe_func_0038D0B0(f32);
extern f32 fe_func_0038D160(f32, f32);
extern void fe_func_0038D850(void *, void *, void *);
extern void fe_func_0038D890(void *, void *, void *, f32);
extern f32 fe_func_0038DAB8(f32, f32);
extern f32 fe_func_0038DB00(f32, f32);
extern f32 fe_func_0038DBA0(f32, f32);
extern s32 fe_func_00392B20(u8 *, s32);
extern void fe_func_00392C78(u8 *);
extern s32 func_L01_00424CB0(void *, f32, f32, f32, f32, f32);
extern void func_L01_00424D88(s32);
extern Mo *fe_func_003C24B0(s32, s32);
extern void fe_func_003C2880(Mo *);
extern f32 func_L01_004395E0(Mo *);
extern void fe_func_003C2EC0(Mo *, s32, u128_t *);
extern void fe_func_003C2F58(Mo *, s32, u128_t *);
extern void fe_func_003C7C38(Mo *);
extern s32 fe_func_00382380(void *, s32, s32);
extern s32 fe_func_00382468(s32);
extern s32 fe_func_00382498(s32, s32);
extern f32 fe_func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 fe_func_00382538(void);
extern void fe_func_00382580(void *, f32, f32);
extern void fe_func_003C3938(Mo *, s32, s32);
extern void fe_func_003C3A10(Mo *, s32, s32, s32);
extern void func_L01_004450F0(Mo *, s32, s32);
extern f32 fe_func_003C3D30(u8 *, s32, s32, f32);
extern void func_L01_004468C8(f32, f32, f32, Mo *, s32, s32, s32, s32, s32);
extern f32 func_L01_00447878(void *, void *, void *, f32, f32);
extern void fe_func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern void fe_func_003C4840(void *, void *, f32);
extern s32 func_L01_0044E1B8(Mo *, f32);
extern s32 func_L01_00454370(Mo *, u8 *);
extern void func_L01_00456160(Mo *, Mo *);
extern s32 func_L01_004561B8(Mo *);
extern s32 func_L01_004561E0(Mo *);
extern void func_L01_00456230(Mo *, s32);
extern void func_L01_0045A748(Mo *, void *);
extern void func_L02_00431568(Mo *, void *, f32, f32, f32, f32, s32);
extern void func_L01_0045AA30(Mo *, u128_t *);
extern void func_L01_0045BD10(Mo *, f32);
extern void func_L01_0045BD78(Mo *, f32, f32, f32, f32);
extern s32 func_L01_0045BDE8(Mo *, s32);
extern u8 *func_L01_004669B0(f32, f32, f32, f32, void *, s32, void *, u32, s32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);
extern void func_L01_004AA7E8(Mo *, s32);
extern void fe_func_003A4F28(s32);
extern s32 fe_func_003A52A0(s32, s32, Mo *);
extern s32 func_L01_004AAC98(s32, s32, Mo *, s32);
extern s32 func_L01_004BA800(void);
extern void func_L01_004F50C8(void *, void *, s32, s32);

extern u8 D_L20_001D66B0[];
extern s32 D_L20_001D6694;
extern s32 D_L20_001D67A8;
extern s32 D_L20_001D67A8_d;
extern s32 D_L20_001DEBEC;
extern s32 D_L20_001DEBF0;
extern s32 D_L20_001DEBF4;
extern f32 D_L20_001DEBBC;
extern f32 D_L20_001DEBC0;
extern f32 D_L20_001DEBC4;
extern f32 D_L20_001DEBC8;
extern f32 D_L20_001DEBCC;
extern f32 D_L20_001DEBD0;
extern f32 D_L20_001DEBD4;
extern f32 D_L20_001DEBD8;
extern f32 D_L20_001DEBDC;
extern f32 D_L20_001DEBE0;
extern f32 D_L20_001DEBE4;
extern f32 D_L20_001DEBE8;
extern s32 D_L20_001DFD40;
extern s32 D_L20_001DFD40_d;
extern Mo *D_L20_001E029C_d;
extern Spot *D_L20_001E0380;
extern Spot *D_L20_001E0380_d;
extern s32 D_L20_001E2698;
extern s32 D_L20_001E2698_d;
extern Boss D_L20_001E2E80;
extern u8 D_L20_001E9980[];
extern Light D_L20_001F0D00[];
extern void *D_L20_0021E880[];
extern u8 *D_L20_00220258[];
extern u8 D_001A30B0[];
extern char D_001A4BE0[];
extern s32 D_00142C58;
extern s32 D_001A7430;

#include "vu0.h"

__asm__(".extern D_L20_001D6694, 4");
__asm__(".extern D_L20_001D67A8, 4");
__asm__(".extern D_L20_001DEBEC, 4");
__asm__(".extern D_L20_001DEBF0, 4");
__asm__(".extern D_L20_001DEBF4, 4");
__asm__(".extern D_L20_001DEBBC, 4");
__asm__(".extern D_L20_001DEBC0, 4");
__asm__(".extern D_L20_001DEBC4, 4");
__asm__(".extern D_L20_001DEBC8, 4");
__asm__(".extern D_L20_001DEBCC, 4");
__asm__(".extern D_L20_001DEBD0, 4");
__asm__(".extern D_L20_001DEBD4, 4");
__asm__(".extern D_L20_001DEBD8, 4");
__asm__(".extern D_L20_001DEBDC, 4");
__asm__(".extern D_L20_001DEBE0, 4");
__asm__(".extern D_L20_001DEBE4, 4");
__asm__(".extern D_L20_001DEBE8, 4");
__asm__(".extern D_L20_001E2698, 4");
__asm__(".extern D_L20_001DFD40, 4");
__asm__(".extern D_L20_001E0380, 4");

static __inline__ f32 fe_speed(f32 x) { return x / 20.0f; }

void func_L20_003D0910(Mo *m) {
    Pv *pv;
    f32 sp0[4] __attribute__((aligned(16)));
    f32 sp10[4] __attribute__((aligned(16)));
    f32 sp20[4] __attribute__((aligned(16)));
    f32 sp30[4] __attribute__((aligned(16)));
    f32 sp40[4] __attribute__((aligned(16)));
    f32 sp50[4] __attribute__((aligned(16)));
    f32 sp60[4] __attribute__((aligned(16)));
    f32 sp70[4] __attribute__((aligned(16)));
    f32 sp80[4] __attribute__((aligned(16)));
    f32 sp90[4] __attribute__((aligned(16)));
    f32 spA0[4] __attribute__((aligned(16)));

    pv = m->pv[0x68/4];
    if ((pv->mp[0x618/4] != 0) && (m->b[0x20] != 0x1B)) {
        pv->mp[0x618/4]->i[0x98/4] = pv->mp[0x618/4]->mp[0x24/4]->i[0x10/4];
        fe_func_003C7C38(pv->mp[0x618/4]);
    }
    if ((pv->mp[0x67C/4] != 0) && (m->b[0x20] != 0x1B)) {
        pv->mp[0x67C/4]->i[0x98/4] = pv->mp[0x67C/4]->mp[0x24/4]->i[0x10/4];
        fe_func_003C7C38(pv->mp[0x67C/4]);
    }
    if (func_L20_003D61B8(m) != 0) {
        fe_func_003C2880(m);
        return;
    }
    if (D_L20_001D6694 == 2) {
        m->i[0x98/4] = 0;
        m->uh[0x34/2] = (m->uh[0x34/2] | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
        if (pv->mp[0x2F8/4] != 0) {
            pv->mp[0x2F8/4]->uh[0x34/2] |= 0x41;
            pv->mp[0x2F8/4]->uh[0x34/2] &= 0xEFFF;
            pv->mp[0x2F8/4]->i[0x98/4] = 0;
            func_L01_004AA7E8(pv->mp[0x2F8/4], 1);
        }
        if (pv->mp[0x2FC/4] != 0) {
            pv->mp[0x2FC/4]->uh[0x34/2] |= 0x41;
            pv->mp[0x2FC/4]->uh[0x34/2] &= 0xEFFF;
            pv->mp[0x2FC/4]->i[0x98/4] = 0;
            func_L01_004AA7E8(pv->mp[0x2FC/4], 1);
        }
    } else {
        Mo *c = m->mp[0x24/4];
        m->uh[0x34/2] &= 0xFFBE;
        m->uh[0x34/2] |= c->uh[0x44/2] & 0x1000;
        m->i[0x98/4] = c->i[0x10/4];
    }
    switch (m->b[0x95]) {
    case 5:
        if (func_L01_004BA800() == 0) {
            f32 *v = (f32 *)&sp0;
            v[2] = 203.97f;
            v[1] = 152.22f;
            v[0] = 267.92f;
            func_L01_004F50C8(&sp0, D_001A4BE0 + 0x90, 0, 1);
            {
            Mo *c = m->mp[0x24/4];
            m->uh[0x34/2] &= 0xFFBE;
            m->uh[0x34/2] |= c->uh[0x44/2] & 0x1000;
            m->i[0x98/4] = c->i[0x10/4];
            }
            if (m->b[0x43] != 9) {
                fe_func_003C3A10(m, 9, 0, 8);
            }
            func_L01_004450F0(m, 7, 2);
        }
        break;
    case 7:
        if ((pv->i[0x638/4] != 0) && (func_L01_004BA800() == 0)) {
            Spot *s;
            void **t;
            {
            Mo *c = m->mp[0x24/4];
            m->uh[0x34/2] &= 0xFFBE;
            m->uh[0x34/2] |= c->uh[0x44/2] & 0x1000;
            m->i[0x98/4] = c->i[0x10/4];
            }
            s = &D_L20_001E0380_d[pv->i[0x65C/4]];
            func_L01_004F50C8(&s->pos, &s->x70, 0, 1);
            D_L20_001DEBF4 = 1;
            func_L01_004450F0(m, 0x1B, 2);
            if (m->b[0x43] != 0xB) {
                fe_func_003C3A10(m, 0xB, 0, 2);
            }
            t = &D_L20_0021E880[pv->i[0x63C/4]];
            m->q[0x10/16] = ((Mo *)*t)->q[0x10/16];
            fe_func_003C3938(m, 0xB, 0);
        }
        break;
    case 6:
        if (func_L01_004BA800() == 0) {
            func_L20_003D6BF8(m);
            fe_func_003C2880(m);
            return;
        }
        break;
    case 0:
        if (func_L01_004561E0(m) != 0) {
            pv->h[0x2D6/2] = 0;
        }
        if ((pv->h[0x234/2] == 1) && (fe_func_0038CB00(pv->b + 0x2D6) != 0)) {
            if (D_L20_001E2E80.x144 == 0) {
                D_L20_001E2E80.x144 = m;
                D_L20_001E2E80.x148 = 0;
            }
            func_L01_004450F0(m, 7, 2);
            if (m->b[0x43] != 9) {
                fe_func_003C3A10(m, 9, 0, 8);
            }
            if (!(D_00142C58 & 0x2000000)) {
                func_L01_004450F0(m, 4, 2);
                if (m->b[0x43] != 8) {
                    fe_func_003C3A10(m, 8, 0, 8);
                }
            }
        }
        if (fe_func_00382380(D_001A4BE0 + 0x80, pv->i[0x654/4], 0) != 0) {
            D_L20_001DEBEC = 1;
            D_L20_001DEBF0 = 1;
            D_L20_001DEBF4 = 1;
            func_L20_003D6BF8(m);
            fe_func_003C2880(m);
            return;
        }
        break;
    case 1:
        if (pv->h[0x234/2] == 1) {
            func_L01_004450F0(m, 7, 2);
        } else if (pv->i[0x2D0/4] == 0) {
            func_L01_004450F0(m, 2, 0);
        }
        break;
    case 2:
        {
        s32 n;
        if (func_L01_004561E0(m) != 0) {
            D_L20_001E2698_d = D_L20_001D67A8;
        }
        n = D_L20_001E2698;
        if (pv->i[0x648/4] == 0) {
            f32 *p = func_L01_003F2A50(0, 5);
            pv->fp[0x644/4] = p;
            pv->i[0x648/4] = 1;
            p[0] = 7.0f;
            pv->fp[0x644/4][1] = 3.0f;
            n = D_L20_001E2698_d;
        }
        if ((n == D_L20_001D67A8_d) && (D_001A7430 <= 0)) {
            D_L20_001D67A8_d = n + 1;
        }
        if ((pv->h[0x234/2] != 1) && (func_L01_004561E0(m) == 0)) {
            pv->i[0x2D0/4] = (fe_func_00382498(0x244, 0x258) * 5 + 2) / 6;
        }
        }
        break;
    case 3:
        {
        s32 r = func_L01_00454370(m, pv->b + 0x160);
        if (r & 1) {
            if (D_L20_001E2E80.x144 == m) {
                D_L20_001E2E80.x144 = 0;
            }
            m->i[0x98/4] = 0;
            m->uh[0x34/2] = (m->uh[0x34/2] | 0x41) & 0xEFFF;
            func_L01_004AA7E8(m, 1);
            func_L01_004450F0(m, 2, 6);
            if (fe_func_00392B20(D_L20_001E9980, 0xBB) != 0) {
                m->i[0x98/4] = 0;
                m->uh[0x34/2] = (m->uh[0x34/2] | 0x41) & 0xEFFF;
                func_L01_004AA7E8(m, 1);
                func_L01_004450F0(m, 2, 6);
                fe_func_00392C78(D_L20_001E9980);
            }
            return;
        }
        if (r & 2) {
            if (pv->h[0x234/2] == 1) {
                if (m->b[0x43] != 9) {
                    fe_func_003C3A10(m, 9, 0, 8);
                }
                func_L01_004450F0(m, 7, 2);
                if (fe_func_0038CF38(m->b + 0x10, D_001A4BE0 + 0x80) <= 18.0f) {
                    if (m->b[0x43] != 0xE) {
                        fe_func_003C3A10(m, 0xE, 0, 5);
                    }
                    func_L01_004450F0(m, 8, -1);
                }
            } else {
                func_L01_004450F0(m, 3, 1);
                pv->i[0x2D0/4] = (fe_func_00382498(0x244, 0x258) * 5 + 2) / 6;
            }
        }
        }
        break;
    case 4:
        break;
    }
    switch (m->b[0x20]) {
    case 2:
    case 3:
        break;
    case 4:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, D_L20_001DEBC8 * 0.00040000002f, D_L20_001DEBC4 * 0.020000001f, 0.010053097f, 0.25132743f);
        }
        func_L01_0045A748(m, D_001A4BE0 + 0x80);
        if ((m->uh[0x96/2] >= 0x1A) && (fe_func_00392B20(D_L20_001E9980, 0xB9) != 0)) {
            func_L01_004450F0(m, 2, 5);
            fe_func_00392C78(D_L20_001E9980);
        }
        break;
    case 5:
        {
        f32 f;
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if (func_L01_004561B8(m) != 0) {
            pv->q[0x5D0/16] = m->q[0x10/16];
        }
        if (m->b[0x42] != 5) {
            break;
        }
        if (pv->i[0x5C8/4] != 0) {
            if (func_L20_003D6AE0(m) != 0) {
                fe_func_003C2F58(pv->mp[0x2F8/4], 0, sp0);
                vec_sub_ba(sp10, D_001A4BE0 + 0xD0, sp0);
                func_L20_003E56D8(m, sp0, sp10, pv->b[0x45], 1);
            }
            if (func_L20_003D6B78(m) != 0) {
                fe_func_003C2F58(pv->mp[0x2FC/4], 0, sp0);
                vec_sub_ab(sp10, D_001A4BE0 + 0xD0, sp0);
                func_L20_003E56D8(m, sp0, sp10, pv->b[0x45], 1);
            }
        }
        f = func_L01_004395E0(m);
        *(u128_t *)sp0 = m->q[0x10/16];
        if ((f > 115.0f) && (f < 124.0f)) {
            fe_func_003C41A0(sp0 + 2, pv->b + 0x5C0, pv->f[0x5D8/4] + 10.0f, 0.032f, 0.036000002f, 0.20000002f);
        } else if ((f > 124.0f) && (f < 135.0f)) {
            fe_func_003C41A0(sp0 + 2, pv->b + 0x5C0, fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f), 0.060000002f, 0.060000002f, 0.40000004f);
        } else {
            pv->i[0x5C0/4] = 0;
        }
        if ((f > 115.0f) && (f < 135.0f)) {
            fe_func_0038CF68(sp10, m->b + 0xD0, -fe_speed(3.5f));
            vec_add_ba(sp0, sp0, sp10);
            vec_sub_ba(sp10, sp0, m->b + 0x10);
            func_L01_0045AA30(m, sp10);
        } else {
            f32 g = fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f);
            if (g < m->f[0x18/4]) {
                m->f[0x18/4] = m->f[0x18/4] - 0.080000006f;
                if (m->f[0x18/4] < g) {
                    m->f[0x18/4] = g;
                }
            }
        }
        if (m->b[0x60] & 2) {
            func_L01_004450F0(m, 0x15, -1);
            if (m->b[0x43] != 0x23) {
                fe_func_003C3A10(m, 0x23, 0, 0xC);
            }
        }
        }
        break;
    case 32:
        {
        f32 f;
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if (func_L01_004561B8(m) != 0) {
            pv->q[0x5D0/16] = m->q[0x10/16];
        }
        if (m->b[0x42] != 5) {
            break;
        }
        if (pv->i[0x5C8/4] != 0) {
            if (func_L20_003D6AE0(m) != 0) {
                fe_func_003C2F58(pv->mp[0x2F8/4], 0, sp0);
                vec_sub_ba(sp10, D_001A4BE0 + 0xD0, sp0);
                func_L20_003E56D8(m, sp0, sp10, pv->b[0x45], 1);
            }
            if (func_L20_003D6B78(m) != 0) {
                fe_func_003C2F58(pv->mp[0x2FC/4], 0, sp0);
                vec_sub_ab(sp10, D_001A4BE0 + 0xD0, sp0);
                func_L20_003E56D8(m, sp0, sp10, pv->b[0x45], 1);
            }
        }
        f = func_L01_004395E0(m);
        *(u128_t *)sp0 = m->q[0x10/16];
        if ((f > 115.0f) && (f < 124.0f)) {
            fe_func_003C41A0(sp0 + 2, pv->b + 0x5C0, pv->f[0x5D8/4] + 10.0f, 0.032f, 0.036000002f, 0.20000002f);
        } else if ((f > 124.0f) && (f < 135.0f)) {
            fe_func_003C41A0(sp0 + 2, pv->b + 0x5C0, fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f), 0.040000003f, 0.060000002f, 0.3f);
        } else {
            pv->i[0x5C0/4] = 0;
        }
        if ((f > 115.0f) && (f < 135.0f)) {
            fe_func_0038CF68(sp10, m->b + 0xD0, -fe_speed(7.0f));
            vec_add_ba(sp0, sp0, sp10);
            vec_sub_ba(sp10, sp0, m->b + 0x10);
            func_L01_0045AA30(m, sp10);
        } else {
            f32 g = fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f);
            if (g < m->f[0x18/4]) {
                m->f[0x18/4] = m->f[0x18/4] - 0.080000006f;
                if (m->f[0x18/4] < g) {
                    m->f[0x18/4] = g;
                }
            }
        }
        if (m->b[0x60] & 2) {
            if (pv->i[0x670/4] == 0xA) {
                if (m->b[0x43] != 0xE) {
                    fe_func_003C3A10(m, 0xE, 0, 7);
                }
                func_L01_004450F0(m, 8, -1);
            } else {
                func_L01_004450F0(m, 0x15, -1);
                if (m->b[0x43] != 0x23) {
                    fe_func_003C3A10(m, 0x23, 0, 0xF);
                }
            }
        }
        }
        break;
    case 6:
        {
        f32 f;
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if (func_L01_004561B8(m) != 0) {
            pv->q[0x5D0/16] = m->q[0x10/16];
        }
        if (m->b[0x42] != 7) {
            break;
        }
        if (pv->i[0x5C8/4] != 0) {
            if (func_L20_003D6AE0(m) != 0) {
                fe_func_003C2F58(pv->mp[0x2F8/4], 0, sp0);
                vec_sub_ba(sp10, D_001A4BE0 + 0xD0, sp0);
                func_L20_003E56D8(m, sp0, sp10, pv->b[0x45], 1);
            }
            if (func_L20_003D6B78(m) != 0) {
                fe_func_003C2F58(pv->mp[0x2FC/4], 0, sp0);
                vec_sub_ab(sp10, D_001A4BE0 + 0xD0, sp0);
                func_L20_003E56D8(m, sp0, sp10, pv->b[0x45], 1);
            }
        }
        f = func_L01_004395E0(m);
        *(u128_t *)sp0 = m->q[0x10/16];
        if ((f > 115.0f) && (f < 124.0f)) {
            fe_func_003C41A0(sp0 + 2, pv->b + 0x5C0, pv->f[0x5D8/4] + 10.0f, 0.032f, 0.036000002f, 0.20000002f);
        } else if ((f > 124.0f) && (f < 135.0f)) {
            fe_func_003C41A0(sp0 + 2, pv->b + 0x5C0, fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f), 0.040000003f, 0.060000002f, 0.3f);
        } else {
            pv->i[0x5C0/4] = 0;
        }
        if ((f > 115.0f) && (f < 135.0f)) {
            fe_func_0038CF68(sp10, m->b + 0xD0, fe_speed(3.5f));
            vec_add_ba(sp0, sp0, sp10);
            vec_sub_ba(sp10, sp0, m->b + 0x10);
            func_L01_0045AA30(m, sp10);
        } else {
            f32 g = fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f);
            if (g < m->f[0x18/4]) {
                m->f[0x18/4] = m->f[0x18/4] - 0.080000006f;
                if (m->f[0x18/4] < g) {
                    m->f[0x18/4] = g;
                }
            }
        }
        if (m->b[0x60] & 2) {
            func_L01_004450F0(m, 0x15, -1);
            if (m->b[0x43] != 0x23) {
                fe_func_003C3A10(m, 0x23, 0, 0xC);
            }
        }
        }
        break;
    case 7:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, D_L20_001DEBC0 * 0.00040000002f, D_L20_001DEBBC * 0.020000001f, 0.010053097f, 0.25132743f);
        }
        func_L01_0045A748(m, D_001A4BE0 + 0x80);
        if (fe_func_0038CF38(m->b + 0x10, D_001A4BE0 + 0x80) <= 16.0f) {
            if (fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4])) < 0.2617994f) {
                if (m->b[0x43] != 0xE) {
                    fe_func_003C3A10(m, 0xE, 0, 8);
                }
                func_L01_004450F0(m, 8, -1);
            }
        }
        break;
    case 8:
        if (func_L01_004561B8(m) != 0) {
            pv->p[0x300/4] = 0;
            pv->p[0x304/4] = 0;
            pv->p[0x308/4] = 0;
        }
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 0xF) {
                fe_func_003C3A10(m, 0xF, 0, 1);
            }
            func_L01_004450F0(m, 9, -1);
        }
        if ((func_L01_0044E1B8(m, 120.0f) != 0) && (m->b[0x42] == 0xE) && (pv->i[0x5CC/4] >= 2)) {
            fe_func_003A52A0(0xE, 0, m);
            fe_func_0038CF68(sp0, m->b + 0xD0, 2.0f);
            vec_add_ab(sp0, sp0, m->b + 0x10);
            pv->mp[0x300/4] = fe_func_003C24B0(0x1CAF, 0x130);
            func_L01_00456160(pv->mp[0x300/4], m);
            pv->mp[0x300/4]->q[0x10/16] = *(u128_t *)sp0;
            fe_func_003C3938(pv->mp[0x300/4], 0, m->b[0x40]);
        }
        if ((func_L01_0044E1B8(m, 125.0f) != 0) && (m->b[0x42] == 0xE) && (pv->i[0x5CC/4] >= 2)) {
            fe_func_003A52A0(0xE, 0, m);
            fe_func_0038CF68(sp0, m->b + 0xD0, -2.0f);
            vec_add_ab(sp0, sp0, m->b + 0x10);
            pv->mp[0x304/4] = fe_func_003C24B0(0x1CAF, 0x130);
            func_L01_00456160(pv->mp[0x304/4], m);
            pv->mp[0x304/4]->q[0x10/16] = *(u128_t *)sp0;
            fe_func_003C3938(pv->mp[0x304/4], 0, m->b[0x40]);
        }
        if ((func_L01_0044E1B8(m, 115.0f) != 0) && (m->b[0x42] == 0xE) && (pv->i[0x5CC/4] != 2)) {
            fe_func_003A52A0(0xE, 0, m);
            fe_func_0038CF68(sp0, m->b + 0xC0, 2.0f);
            vec_add_ab(sp0, sp0, m->b + 0x10);
            pv->mp[0x308/4] = fe_func_003C24B0(0x1CAF, 0x130);
            func_L01_00456160(pv->mp[0x308/4], m);
            pv->mp[0x308/4]->q[0x10/16] = *(u128_t *)sp0;
            fe_func_003C3938(pv->mp[0x308/4], 0, m->b[0x40]);
        }
        break;
    case 9:
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if (m->uh[0x96/2] >= 5) {
            if (pv->mp[0x300/4] != 0) {
                pv->mp[0x300/4]->b[0xBC] = 1;
            }
            if (pv->mp[0x304/4] != 0) {
                pv->mp[0x304/4]->b[0xBC] = 1;
            }
            if (pv->mp[0x308/4] != 0) {
                pv->mp[0x308/4]->b[0xBC] = 1;
            }
            if ((pv->i[0x61C/4] == 1) || (pv->i[0x61C/4] == 3)) {
                if (m->b[0x43] != 0x11) {
                    fe_func_003C3A10(m, 0x11, 1, 4);
                }
            } else {
                if (m->b[0x43] != 0x10) {
                    fe_func_003C3A10(m, 0x10, 1, 4);
                }
            }
            func_L01_004450F0(m, 0xA, -1);
        }
        break;
    case 10:
        {
        f32 f;
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, 0.36f, 2.0000002f, 0.010053097f, 0.25132743f);
        }
        if ((func_L01_0044E1B8(m, 127.0f) != 0) && ((u32)(m->b[0x42] - 0x10) < 2)) {
            if (pv->i[0x5CC/4] == 1) {
                pv->i[0x61C/4]++;
                if (pv->i[0x61C/4] >= 4) {
                    pv->i[0x61C/4] = 0;
                    if (m->b[0x43] != 0x1C) {
                        fe_func_003C3A10(m, 0x1C, 2, 0xC);
                    }
                    func_L01_004450F0(m, 0xB, -1);
                } else {
                    if (m->b[0x43] != 0xE) {
                        fe_func_003C3A10(m, 0xE, 0, 7);
                    }
                    func_L01_004450F0(m, 8, -1);
                }
            } else if (pv->i[0x5CC/4] == 2) {
                pv->i[0x61C/4]++;
                if (pv->i[0x61C/4] >= 2) {
                    pv->i[0x61C/4] = 0;
                    if (m->b[0x43] != 0x1C) {
                        fe_func_003C3A10(m, 0x1C, 2, 0xC);
                    }
                    func_L01_004450F0(m, 0xB, -1);
                } else {
                    if (m->b[0x43] != 0xE) {
                        fe_func_003C3A10(m, 0xE, 0, 7);
                    }
                    func_L01_004450F0(m, 8, -1);
                }
            } else {
                pv->i[0x61C/4] = 0;
                if (m->b[0x43] != 0x1C) {
                    fe_func_003C3A10(m, 0x1C, 2, 0xC);
                }
                func_L01_004450F0(m, 0xB, -1);
            }
            if (fe_func_0038CF38(m->b + 0x10, D_001A4BE0 + 0x80) < 5.0f) {
                pv->i[0x670/4] = 0xA;
                if (m->b[0x43] != 5) {
                    fe_func_003C3A10(m, 5, 0, 8);
                }
                func_L01_004450F0(m, 0x20, -1);
            }
            if ((pv->i[0x638/4] != 0) && (fe_func_00392B20(D_L20_001E9980, 0xBA) != 0)) {
                func_L01_004450F0(m, 2, 7);
                fe_func_00392C78(D_L20_001E9980);
            }
        }
        f = func_L01_004395E0(m);
        if ((f > 112.0f) && (f < 118.0f) && ((u32)(m->b[0x42] - 0x10) < 2)) {
            if (m->b[0x42] == 0x10) {
                func_L01_004468C8(0.5f, pv->b[0x44], 3.0f, m, 0, 1, 0, 1, 0);
            } else {
                func_L01_004468C8(0.5f, pv->b[0x44], 3.0f, m, 1, 1, 0, 1, 0);
            }
        }
        }
        break;
    case 11:
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 0x12) {
                fe_func_003C3A10(m, 0x12, 0, 7);
            }
            func_L01_004450F0(m, 0x13, -1);
        }
        break;
    case 13:
        {
        f32 f;
        if (m->b[0x60] & 2) {
            m->f[0x48/4] = 1.0f;
            if (m->b[0x43] != 0xC) {
                fe_func_003C3A10(m, 0xC, 0, 2);
            }
            func_L01_004450F0(m, 0x10, -1);
            if (pv->i[0x638/4] != 0) {
                D_L20_001DEBF4 = 1;
                func_L01_004450F0(m, 0x1B, -1);
                if (m->b[0x43] != 0xB) {
                    fe_func_003C3A10(m, 0xB, 0, 2);
                }
            }
        }
        f = func_L01_004395E0(m);
        if ((f > 112.0f) && (f < 117.0f) && (m->b[0x42] == 0xA)) {
            m->f[0x48/4] = 0.77f;
            func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
            m->f[0x18/4] = m->f[0x18/4] + 0.50000006f;
        } else {
            m->f[0x48/4] = 1.0f;
        }
        }
        break;
    case 14:
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if (m->uh[0x96/2] >= 0x33) {
            if (m->b[0x43] != 0xC) {
                fe_func_003C3A10(m, 0xC, 0, 5);
            }
            func_L01_004450F0(m, 0x10, -1);
        }
        break;
    case 18:
        {
        f32 f;
        if (m->b[0x60] & 2) {
            pv->i[0x5EC/4] = 0;
            m->f[0x18/4] = fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f);
            if ((u32)(m->b[0x94] - 0x10) < 2) {
                func_L01_004450F0(m, 0x22, -1);
                if (m->b[0x43] != 0x1C) {
                    fe_func_003C3A10(m, 0x1C, 0, 0xC);
                }
            } else {
                if (m->b[0x43] != 0x11) {
                    fe_func_003C3A10(m, 0x11, 0, 8);
                }
                func_L01_004450F0(m, 0x17, -1);
            }
            if ((pv->f[0x30/4] < 400.0f) && (pv->i[0x610/4] == 0)) {
                if (m->b[0x43] != 9) {
                    fe_func_003C3A10(m, 9, 0, 7);
                }
                func_L01_004450F0(m, 0x19, -1);
            }
        }
        f = func_L01_004395E0(m);
        if ((f > 119.0f) && (f < 123.0f) && (m->b[0x42] == 0xD)) {
            f32 g;
            f32 t;
            func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
            g = fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f);
            t = m->f[0x18/4] - 0.64000005f;
            m->f[0x18/4] = t;
            if (t < g) {
                m->f[0x18/4] = g;
            }
        }
        }
        break;
    case 34:
        if (func_L01_004561B8(m) != 0) {
            m->f[0x48/4] = 0.8f;
        }
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 0x11) {
                fe_func_003C3A10(m, 0x11, 0, 8);
            }
            func_L01_004450F0(m, 0x17, -1);
        }
        break;
    case 16:
        {
        f32 f;
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if (func_L01_004561B8(m) != 0) {
            pv->f[0x2E8/4] = 0.0f;
            pv->i[0x2EC/4] = 0;
            pv->i[0x5E0/4] = fe_func_00382468(2);
            if (pv->i[0x5CC/4] == 2) {
                pv->i[0x5E0/4] = 1;
            }
            pv->i[0x62C/4] = -1;
        }
        if (pv->i[0x62C/4] == -1) {
            if (func_L01_004395E0(m) < 163.0f) {
                pv->i[0x62C/4] = func_L01_00424CB0(m->b + 0x10, pv->f[0x2E8/4] * 15.0f, 0.0f, 0.45f, 0.2f, 1.0f);
            }
        } else {
            Light *l;
            fe_func_003C2F58(m, 3, sp0);
            l = &D_L20_001F0D00[pv->i[0x62C/4]];
            l->u.pos = *(u128_t *)sp0;
            l->u.v.w = pv->f[0x2E8/4] * 15.0f;
            l->r = 0.45f;
            l->g = 0.2f;
            l->b = 1.0f;
            l->on = 0;
            if (pv->i[0x5E0/4] == 1) {
                l->r = 0.8f;
                l->g = 0.0f;
                l->b = 0.0f;
                l->on = 0;
            }
        }
        if ((pv->f[0x30/4] < 400.0f) && (pv->i[0x610/4] == 0)) {
            if (m->b[0x43] != 0xD) {
                fe_func_003C3A10(m, 0xD, 0, 8);
            }
            func_L01_004450F0(m, 0x12, -1);
        }
        if (fe_func_0038CAD0(pv->b + 0x2EC) == 0) {
            f32 ang;
            s32 k;
            f32 *p30;
            fe_func_0038CAD0(pv->b + 0x2F0);
            func_L01_00404A10(func_L20_003D6F30, m);
            fe_func_003C2F58(m, 3, sp0);
            p30 = sp30;
            *(u128_t *)sp30 = 0;
            *(u128_t *)sp40 = *(u128_t *)sp0;
            sp30[0] = 0.3f;
            sp30[1] = -1.0f;
            sp30[3] = 1.0f;
            *(u128_t *)sp70 = m->q[0xC0/16];
            *(u128_t *)sp80 = m->q[0xD0/16];
            fe_func_0038D890(sp30, sp70, sp80, 0.34906584f);
            qzero(sp90);
            *(u128_t *)sp20 = *(u128_t *)sp30;
            fe_func_0038CE20(spA0, sp70, 0.4f);
            vec_add_ab(sp40, sp40, spA0);
            ang = 0.0f;
            k = 0x13;
            do {
                s32 n;
                s32 c;
                u8 *p;
                f32 r;
                ang = fe_func_0038DAB8(ang, fe_func_003824E0(0.0f, 0.62831855f));
                fe_func_0038CE20(sp50, sp20, fe_func_003824E0(0.24000001f, 0.32000002f));
                vec_add_ab(sp50, sp50, sp90);
                sp60[0] = sp40[0] + func_L01_00443A18(0.0f, 0.3f);
                sp60[1] = sp40[1] + func_L01_00443A18(0.0f, 0.3f);
                sp60[2] = sp40[2] + func_L01_00443A18(0.0f, 0.3f);
                n = func_L01_00443A18(1.0f, 2.0f);
                p = func_L01_004669B0(0.0f, 1.0f, 1.01f, fe_func_003824E0(0.2f, 0.75f) * 210000.0f, sp60, n, D_L20_001D66B0, 0x7F000000, 0);
                if (p != 0) {
                    u8 *q;
                    p[3] = 0x44;
                    *(s16 *)(p + 0xA) = 0x32;
                    p[9] = 0x44;
                    q = p + 0x20;
                    *(f32 *)(q + 0x1C) = 4.0f;
                    *(s32 *)(q + 4) = 3;
                    q[0xA] = 0x30;
                    q[0xB] = p[0xA];
                }
                sp60[0] = sp40[0] + func_L01_00443A18(0.0f, 0.6f);
                sp60[1] = sp40[1] + func_L01_00443A18(0.0f, 0.6f);
                sp60[2] = sp40[2] + func_L01_00443A18(0.0f, 0.6f);
            c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                } else if (pv->i[0x5E0/4] == 1) {
                    c = 0x6065C;
                } else if (pv->i[0x5E0/4] == 2) {
                    c = 0x7C30;
                }
                r = fe_func_003824E0(0.2f, 1.75f);
                vec_sub_ab(sp60, sp60, sp50);
                p = func_L01_0046A610(sp60, sp50, 5, 0x7F, c, n, r * 210000.0f, 500.0f, 0.95f, 0.0f, 0.0f);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0x16C/4][1];
                }
                if (fabs_asm(ang) > 1e-05f) {
                    fe_func_003C4840(sp10, sp70, ang);
                    fe_func_0038D850(sp20, p30, sp10);
                }
            } while (--k >= 0);
        }
        if (m->b[0x60] & 2) {
            if (pv->i[0x5EC/4] < 3) {
                if (m->b[0x43] != 0xB) {
                    fe_func_003C3A10(m, 0xB, 0, 2);
                }
                func_L01_004450F0(m, 0x11, -1);
                pv->i[0x5EC/4]++;
            } else {
                if (m->b[0x43] != 0xD) {
                    fe_func_003C3A10(m, 0xD, 0, 7);
                }
                func_L01_004450F0(m, 0x12, -1);
            }
            if ((pv->i[0x5CC/4] == 2) && (pv->i[0x5EC/4] >= 2)) {
                if (m->b[0x43] != 0xD) {
                    fe_func_003C3A10(m, 0xD, 0, 7);
                }
                func_L01_004450F0(m, 0x12, -1);
            }
        }
        f = func_L01_004395E0(m);
        if ((m->b[0x42] != 0xC) || (f < 156.0f)) {
            {
            f32 e;
            f32 t;
            s32 i;
            u8 *p;
            t = pv->f[0x2E8/4] + 0.016f;
            e = t * 262500.0f;
            pv->f[0x2E8/4] = t;
            fe_func_003C2F58(m, 3, sp0);
            if (fe_func_00382468(2) != 0) {
                s32 n;
                s32 c;
                c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                } else if (pv->i[0x5E0/4] == 1) {
                    c = 0x6065C;
                } else if (pv->i[0x5E0/4] == 2) {
                    c = 0x7C30;
                }
                n = func_L01_00443A18(1.0f, -1.0f);
                p = func_L01_0046A610(sp0, D_L20_001D66B0, 0xC, 6, c, n, e * 6.0f, 500.0f, 1.0f, 0.0f, 0.0f);
                if (p != 0) {
                    p[2] = D_L20_00220258[0x170/4][1];
                }
            }
            sp10[0] = sp0[0] + func_L01_00443A18(0.0f, 0.04f);
            sp10[1] = sp0[1] + func_L01_00443A18(0.0f, 0.04f);
            sp10[2] = sp0[2] + func_L01_00443A18(0.0f, 0.04f);
            if (fe_func_00382468(2) != 0) {
                s32 n;
                s32 c;
                f32 *q;
                c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                } else if (pv->i[0x5E0/4] == 1) {
                    c = 0x6065C;
                } else if (pv->i[0x5E0/4] == 2) {
                    c = 0x7C30;
                }
                q = sp10;
                n = func_L01_00443A18(1.0f, -1.0f);
                p = func_L01_0046A610(q, D_L20_001D66B0, 0xC, 0x7F, c, n, e * 2.4f, 500.0f, 1.0f, 0.0f, 0.0f);
                if (p != 0) {
                    p[3] = (fe_func_00382468(2) != 0) ? 0x48 : 0x44;
                    p[2] = D_L20_00220258[0x170/4][0];
                }
            }
            for (i = 0; i < 6; i++) {
                s32 n;
                u8 *p;
                fe_func_00382580(sp20, pv->f[0x2E8/4] * 0.10000001f, pv->f[0x2E8/4] * 0.14000002f);
                n = func_L01_00443A18(2.0f, 5.0f);
                p = func_L01_004713C8(sp0, sp20, 0xC, fe_func_003824E0(0.8f, 1.25f) * 210000.0f * pv->f[0x2E8/4], 0, n, 0x7F, 0x7F, pv->f[0x2E8/4] * 2100.0f, 0.00584f, 6);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0xD4/4][0];
                }
                n = func_L01_00443A18(2.0f, 5.0f);
                p = func_L01_004713C8(sp0, sp20, 0xC, fe_func_003824E0(0.8f, 1.25f) * 210000.0f * 3.0f * pv->f[0x2E8/4], 0, n, 0x30, 0x30, pv->f[0x2E8/4] * 4200.0f, 0.00584f, 0);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0xD4/4][0];
                }
            }
            }
        }
        if ((f < 153.0f) || (m->b[0x42] != 0xC)) {
            m->f[0x48/4] = 0.2f;
        }
        if ((f > 153.0f) && (f < 156.0f) && (m->b[0x42] == 0xC)) {
            m->f[0x48/4] = 0.06f;
        }
        if ((f > 156.0f) && (f < 165.0f) && (m->b[0x42] == 0xC)) {
            m->f[0x48/4] = 3.0f;
        }
        if ((f > 165.0f) && (m->b[0x42] == 0xC)) {
            m->f[0x48/4] = 0.8f;
        }
        if (func_L01_0044E1B8(m, 165.0f) != 0) {
            Mo *o;
            s32 i;
            f32 *p30;
            s32 a;
            s32 b;
            if (pv->i[0x62C/4] != -1) {
                func_L01_00424D88(pv->i[0x62C/4]);
            }
            pv->i[0x62C/4] = -1;
            if (pv->i[0x5E0/4] == 0) {
                a = 0x1AF1;
                b = 0xD90;
            } else if (pv->i[0x5E0/4] == 1) {
                a = 0x1CDA;
                b = 0xD50;
            } else if (pv->i[0x5E0/4] == 2) {
                a = 0x1CDB;
                b = 0xD50;
            } else {
                a = 0x1AF1;
                b = 0xD90;
            }
            o = fe_func_003C24B0(a, b);
            *(u128_t *)sp0 = m->q[0x10/16];
            sp0[2] += 1.0f;
            func_L20_003EAA70(m, D_L20_001D66B0, sp0);
            o->b[0x30] = 0xFF;
            o->uh[0x32/2] = 0xFF;
            o->b[0x31] = 1;
            o->mp[0xB8/4] = m;
            o->q[0x10/16] = m->q[0x10/16];
            o->q[0xF0/16] = m->q[0xF0/16];
            o->f[0x18/4] += 1.5f;
            o->d[0x38/8] = m->d[0x38/8];
            fe_func_0038CF68(sp10, m->b + 0xC0, 2.0f);
            vec_add_ba(o->b + 0x10, sp10, o->b + 0x10);
            pv->i[0x2EC/4] = 0x15;
            pv->i[0x2F0/4] = 5;
            D_L20_001E2E80.x40 = 0.1f;
            D_L20_001E2E80.x48 = 0x4B;
            D_L20_001E2E80.x20 = 0.2f;
            D_L20_001E2E80.x28 = 0x32;
            D_L20_001E2E80.x2C = 0;
            p30 = sp30;
            for (i = 0; i < 300; i++) {
                s32 n;
                s32 c;
                u8 *p;
                fe_func_003C2F58(m, 3, sp20);
                fe_func_00382580(p30, 0.6f, 0.70000005f);
                n = func_L01_00443A18(2.0f, 3.0f);
                p = func_L01_004713C8(sp20, p30, 0x32, fe_func_003824E0(0.8f, 1.25f) * 210000.0f * pv->f[0x2E8/4], 0, n, 0x7F, 0x7F, pv->f[0x2E8/4] * 2100.0f, 0.0f, 6);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0xD4/4][0];
                }
            c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                } else if (pv->i[0x5E0/4] == 1) {
                    c = 0x6065C;
                } else if (pv->i[0x5E0/4] == 2) {
                    c = 0x7C30;
                }
                n = func_L01_00443A18(2.0f, 3.0f);
                p = func_L01_004713C8(sp20, p30, 0x32, fe_func_003824E0(0.8f, 1.25f) * 210000.0f * 1.25f * pv->f[0x2E8/4], c, n, 0x30, 0x30, pv->f[0x2E8/4] * 4200.0f, 0.0f, 0);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0xD4/4][0];
                }
            }
        }
        }
        break;
    case 19:
        if (func_L01_0044E1B8(m, 125.0f) != 0) {
            pv->i[0x5E4/4] = 0;
            func_L01_004450F0(m, 0x15, -1);
            if (m->b[0x43] != 0x23) {
                fe_func_003C3A10(m, 0x23, 0, 0xF);
            }
            if (fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4])) > 0.7853982f) {
                func_L01_004450F0(m, 5, -1);
                if (m->b[0x43] != 5) {
                    fe_func_003C3A10(m, 5, 0, 7);
                }
            }
            if (fe_func_0038CF38(m->b + 0x10, D_001A4BE0 + 0x80) < 5.0f) {
                pv->i[0x670/4] = 0x13;
                if (m->b[0x43] != 5) {
                    fe_func_003C3A10(m, 5, 0, 8);
                }
                func_L01_004450F0(m, 0x20, -1);
            }
        }
        if ((func_L01_0044E1B8(m, 120.0f) != 0) && (m->b[0x42] == 0x12)) {
            pv->mp[0x2F8/4]->uh[0x34/2] &= 0xFFBE;
            pv->mp[0x2F8/4]->uh[0x34/2] |= pv->mp[0x2F8/4]->mp[0x24/4]->uh[0x44/2] & 0x1000;
            pv->mp[0x2F8/4]->i[0x98/4] = pv->mp[0x2F8/4]->mp[0x24/4]->i[0x10/4];
            pv->mp[0x2FC/4]->uh[0x34/2] &= 0xFFBE;
            pv->mp[0x2FC/4]->uh[0x34/2] |= pv->mp[0x2FC/4]->mp[0x24/4]->uh[0x44/2] & 0x1000;
            pv->mp[0x2FC/4]->i[0x98/4] = pv->mp[0x2FC/4]->mp[0x24/4]->i[0x10/4];
        }
        break;
    case 20:
        if (m->uh[0x96/2] >= 2) {
            func_L01_004450F0(m, 0x15, -1);
            if (m->b[0x43] != 0x23) {
                fe_func_003C3A10(m, 0x23, 0, 0xC);
            }
        }
        pv->f[0x418/4] = D_L20_001DEBD4 * 0.017453292f;
        pv->f[0x498/4] = D_L20_001DEBD8 * 0.017453292f;
        pv->f[0x514/4] = D_L20_001DEBDC * 0.017453292f;
        pv->f[0x510/4] = D_L20_001DEBE0 * 0.017453292f;
        pv->f[0x518/4] = D_L20_001DEBE8 * 0.017453292f;
        pv->f[0x590/4] = D_L20_001DEBE4 * 0.017453292f;
        break;
    case 21:
        {
        u8 *pos;
        f32 g;
        if (func_L01_004561B8(m) != 0) {
            m->f[0x48/4] = 1.5f;
            pv->f[0x630/4] = 0.0f;
        }
        pos = m->b + 0x10;
        g = fe_func_003C3D30(pos, 0, 0, 0.5f);
        if (g < m->f[0x18/4]) {
            m->f[0x18/4] = m->f[0x18/4] - 0.080000006f;
            if (m->f[0x18/4] < g) {
                m->f[0x18/4] = g;
            }
        }
        if (m->b[0x42] == 0x23) {
            s32 h;
            u8 *s;
            s32 fr;
            s32 bit;
            fe_func_0038DB00(fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]), m->f[0xF8/4]);
            fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
            h = pv->i[0x658/4];
            if ((h == -1) || (s = D_001A30B0 + (h << 7), *(Mo **)(s + 0xDC) != m) || (s[0xD0] == 0)) {
                pv->i[0x658/4] = func_L01_004AAC98(0, 4, m, 0x1CB4);
            }
            if (m->uh[0x96/2] >= 0x97) {
                h = pv->i[0x658/4];
                if (h != -1) {
                    s = D_001A30B0 + (h << 7);
                    if ((*(Mo **)(s + 0xDC) == m) && (s[0xD0] != 0)) {
                        fe_func_003A4F28(h);
                    }
                }
                pv->i[0x658/4] = -1;
                pv->i[0x5C8/4] = 0;
                if (pv->i[0x5C4/4] == 0) {
                    func_L01_004450F0(m, 5, -1);
                    if (m->b[0x43] != 5) {
                        fe_func_003C3A10(m, 5, 0, 7);
                    }
                    if (fe_func_0038CF38(pos, D_001A4BE0 + 0x80) < 5.0f) {
                        pv->i[0x670/4] = 0x15;
                        if (m->b[0x43] != 5) {
                            fe_func_003C3A10(m, 5, 0, 8);
                        }
                        func_L01_004450F0(m, 0x20, -1);
                    }
                    pv->i[0x5C4/4]++;
                } else if (pv->i[0x5C4/4] == 1) {
                    if (m->b[0x43] != 7) {
                        fe_func_003C3A10(m, 7, 0, 7);
                    }
                    func_L01_004450F0(m, 6, -1);
                    if (fe_func_0038CF38(pos, D_001A4BE0 + 0x80) < 5.0f) {
                        pv->i[0x670/4] = 0x13;
                        if (m->b[0x43] != 5) {
                            fe_func_003C3A10(m, 5, 0, 8);
                        }
                        func_L01_004450F0(m, 0x20, -1);
                    }
                    pv->i[0x5C4/4]++;
                } else {
                    func_L01_004450F0(m, 0x16, -1);
                    if (m->b[0x43] != 0x16) {
                        fe_func_003C3A10(m, 0x16, 0, 5);
                    }
                }
                if ((pv->i[0x638/4] != 0) && (fe_func_00392B20(D_L20_001E9980, 0xBA) != 0)) {
                    m->i[0x98/4] = 0;
                    m->uh[0x34/2] = (m->uh[0x34/2] | 0x41) & 0xEFFF;
                    func_L01_004AA7E8(m, 1);
                    func_L01_004450F0(m, 2, 7);
                    fe_func_00392C78(D_L20_001E9980);
                }
            }
            fr = D_L20_001DFD40;
            if ((pv->f[0x30/4] < 400.0f) && (pv->i[0x610/4] == 0)) {
                func_L01_004450F0(m, 0x16, -1);
                if (m->b[0x43] != 0x16) {
                    fe_func_003C3A10(m, 0x16, 0, 5);
                }
                fr = D_L20_001DFD40_d;
            }
            bit = fr & 1;
            if ((((s32)m >> 8) & 1) == bit) {
                f32 d;
                f32 z;
                f32 f;
                f32 a;
                fe_func_003C2EC0(pv->mp[0x2F8/4], 0, sp0);
                *(u128_t *)sp40 = *(u128_t *)sp30;
                vec_sub_ab(sp60, D_001A4BE0 + 0xD0, sp40);
                z = sp60[2];
                d = fe_func_0038CED8(sp60);
                a = m->f[0xF8/4];
                a = fe_func_0038DAB8(a, fe_func_0038D098(pv->f[0x630/4]));
                sp60[0] = fe_func_0038D098(a) * d;
                sp60[1] = fe_func_0038D0B0(a) * d;
                sp60[2] = z;
                *(u128_t *)sp50 = *(u128_t *)sp60;
                func_L20_003E56D8(m, sp40, sp50, pv->b[0x45], 1);
                if ((D_L20_001DFD40_d & 1) == bit) {
                    f32 d;
                    f32 z;
                    f32 a;
                    fe_func_003C2EC0(pv->mp[0x2FC/4], 0, sp0);
                    *(u128_t *)sp40 = *(u128_t *)sp30;
                    vec_sub_ab(sp60, D_001A4BE0 + 0xD0, sp40);
                    z = sp60[2];
                    d = fe_func_0038CED8(sp60);
                    a = m->f[0xF8/4];
                    a = fe_func_0038DB00(a, fe_func_0038D098(pv->f[0x630/4]));
                    sp60[0] = fe_func_0038D098(a) * d;
                    sp60[1] = fe_func_0038D0B0(a) * d;
                    sp60[2] = z;
                    *(u128_t *)sp50 = *(u128_t *)sp60;
                    func_L20_003E56D8(m, sp40, sp50, pv->b[0x45], 1);
                }
            }
            pv->f[0x630/4] = pv->f[0x630/4] + 0.035f;
            if (pv->f[0x630/4] >= 6.0f) {
                pv->f[0x630/4] = 0.0f;
            }
        }
        }
        break;
    case 22:
        if (func_L01_004561B8(m) != 0) {
            pv->i[0x5C4/4] = 0;
        }
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 0x11) {
                fe_func_003C3A10(m, 0x11, 0, 8);
            }
            func_L01_004450F0(m, 0x17, -1);
            if (pv->i[0x5CC/4] != 1) {
                if (m->b[0x43] != 0xA) {
                    fe_func_003C3A10(m, 0xA, 0, 6);
                }
                func_L01_004450F0(m, 0xD, -1);
            }
            if ((pv->f[0x30/4] < 400.0f) && (pv->i[0x610/4] == 0)) {
                if (m->b[0x43] != 9) {
                    fe_func_003C3A10(m, 9, 0, 7);
                }
                func_L01_004450F0(m, 0x19, -1);
            }
        }
        if ((func_L01_0044E1B8(m, 125.0f) != 0) && (m->b[0x42] == 0x16)) {
            pv->mp[0x2F8/4]->uh[0x34/2] |= 0x41;
            pv->mp[0x2F8/4]->uh[0x34/2] &= 0xEFFF;
            pv->mp[0x2F8/4]->i[0x98/4] = 0;
            func_L01_004AA7E8(pv->mp[0x2F8/4], 1);
            pv->mp[0x2FC/4]->uh[0x34/2] |= 0x41;
            pv->mp[0x2FC/4]->uh[0x34/2] &= 0xEFFF;
            pv->mp[0x2FC/4]->i[0x98/4] = 0;
            func_L01_004AA7E8(pv->mp[0x2FC/4], 1);
        }
        break;
    case 23:
        {
        f32 f;
        if (func_L01_004561B8(m) != 0) {
            pv->f[0x2E8/4] = 0.0f;
            pv->i[0x62C/4] = -1;
            pv->i[0x2EC/4] = 0;
            pv->i[0x5E0/4] = 0;
        }
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if (pv->i[0x62C/4] == -1) {
            pv->i[0x62C/4] = func_L01_00424CB0(m->b + 0x10, pv->f[0x2E8/4] * 15.0f, 0.0f, 0.45f, 0.2f, 1.0f);
        } else {
            Light *l;
            fe_func_003C2F58(m, 9, sp0);
            l = &D_L20_001F0D00[pv->i[0x62C/4]];
            l->u.pos = *(u128_t *)sp0;
            l->u.v.w = pv->f[0x2E8/4] * 15.0f;
            l->r = 0.45f;
            l->g = 0.2f;
            l->b = 1.0f;
            l->on = 0;
        }
        if (fe_func_0038CAD0(pv->b + 0x2EC) == 0) {
            f32 ang;
            s32 k;
            f32 *p30;
            fe_func_0038CAD0(pv->b + 0x2F0);
            func_L01_00404A10(func_L20_003D6F30, m);
            fe_func_003C2F58(m, 9, sp0);
            p30 = sp30;
            *(u128_t *)sp30 = 0;
            *(u128_t *)sp40 = *(u128_t *)sp0;
            sp30[0] = 0.3f;
            sp30[1] = -1.0f;
            sp30[3] = 1.0f;
            *(u128_t *)sp70 = m->q[0xC0/16];
            *(u128_t *)sp80 = m->q[0xD0/16];
            fe_func_0038D890(sp30, sp70, sp80, 0.34906584f);
            qzero(sp90);
            *(u128_t *)sp20 = *(u128_t *)sp30;
            fe_func_0038CE20(spA0, sp70, 0.4f);
            vec_add_ab(sp40, sp40, spA0);
            ang = 0.0f;
            k = 0x13;
            do {
                s32 n;
                s32 c;
                u8 *p;
                f32 r;
                ang = fe_func_0038DAB8(ang, fe_func_003824E0(0.0f, 0.62831855f));
                fe_func_0038CE20(sp50, sp20, fe_func_003824E0(0.24000001f, 0.32000002f));
                vec_add_ab(sp50, sp50, sp90);
                sp60[0] = sp40[0] + func_L01_00443A18(0.0f, 0.3f);
                sp60[1] = sp40[1] + func_L01_00443A18(0.0f, 0.3f);
                sp60[2] = sp40[2] + func_L01_00443A18(0.0f, 0.3f);
                n = func_L01_00443A18(1.0f, 2.0f);
                p = func_L01_004669B0(0.0f, 1.0f, 1.01f, fe_func_003824E0(0.2f, 0.75f) * 210000.0f, sp60, n, D_L20_001D66B0, 0x7F000000, 0);
                if (p != 0) {
                    u8 *q;
                    p[3] = 0x44;
                    *(s16 *)(p + 0xA) = 0x32;
                    p[9] = 0x44;
                    q = p + 0x20;
                    *(f32 *)(q + 0x1C) = 4.0f;
                    *(s32 *)(q + 4) = 3;
                    q[0xA] = 0x30;
                    q[0xB] = p[0xA];
                }
                sp60[0] = sp40[0] + func_L01_00443A18(0.0f, 0.6f);
                sp60[1] = sp40[1] + func_L01_00443A18(0.0f, 0.6f);
                sp60[2] = sp40[2] + func_L01_00443A18(0.0f, 0.6f);
            c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                } else if (pv->i[0x5E0/4] == 1) {
                    c = 0x6065C;
                } else if (pv->i[0x5E0/4] == 2) {
                    c = 0x7C30;
                }
                r = fe_func_003824E0(0.2f, 1.75f);
                vec_sub_ab(sp60, sp60, sp50);
                p = func_L01_0046A610(sp60, sp50, 5, 0x7F, c, n, r * 210000.0f, 500.0f, 0.95f, 0.0f, 0.0f);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0x16C/4][1];
                }
                if (fabs_asm(ang) > 1e-05f) {
                    fe_func_003C4840(sp10, sp70, ang);
                    fe_func_0038D850(sp20, p30, sp10);
                }
            } while (--k >= 0);
        }
        if (func_L01_0044E1B8(m, 127.0f) != 0) {
            if (pv->i[0x62C/4] != -1) {
                func_L01_00424D88(pv->i[0x62C/4]);
            }
            pv->i[0x62C/4] = -1;
            if (m->b[0x43] != 2) {
                fe_func_003C3A10(m, 2, 0, 0x15);
            }
            func_L01_004450F0(m, 0x18, -1);
        }
        f = func_L01_004395E0(m);
        if ((m->b[0x42] != 0x11) || (f < 114.0f)) {
            {
            f32 e;
            f32 t;
            s32 i;
            u8 *p;
            t = pv->f[0x2E8/4] + 0.030000001f;
            e = t * 262500.0f;
            pv->f[0x2E8/4] = t;
            fe_func_003C2F58(m, 1, sp0);
            if (fe_func_00382468(2) != 0) {
                s32 n;
                s32 c;
                c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                }
                n = func_L01_00443A18(1.0f, -1.0f);
                p = func_L01_0046A610(sp0, D_L20_001D66B0, 0xC, 6, c, n, e * 6.0f, 500.0f, 1.0f, 0.0f, 0.0f);
                if (p != 0) {
                    p[2] = D_L20_00220258[0x170/4][1];
                }
            }
            sp10[0] = sp0[0] + func_L01_00443A18(0.0f, 0.04f);
            sp10[1] = sp0[1] + func_L01_00443A18(0.0f, 0.04f);
            sp10[2] = sp0[2] + func_L01_00443A18(0.0f, 0.04f);
            if (fe_func_00382468(2) != 0) {
                s32 n;
                s32 c;
                f32 *q;
                c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                }
                q = sp10;
                n = func_L01_00443A18(1.0f, -1.0f);
                p = func_L01_0046A610(q, D_L20_001D66B0, 0xC, 0x7F, c, n, e * 2.4f, 500.0f, 1.0f, 0.0f, 0.0f);
                if (p != 0) {
                    p[3] = (fe_func_00382468(2) != 0) ? 0x48 : 0x44;
                    p[2] = D_L20_00220258[0x170/4][0];
                }
            }
            for (i = 0; i < 6; i++) {
                s32 n;
                u8 *p;
                fe_func_00382580(sp20, pv->f[0x2E8/4] * 0.10000001f, pv->f[0x2E8/4] * 0.14000002f);
                n = func_L01_00443A18(2.0f, 5.0f);
                p = func_L01_004713C8(sp0, sp20, 0xC, fe_func_003824E0(0.8f, 1.25f) * 210000.0f * pv->f[0x2E8/4], 0, n, 0x7F, 0x7F, pv->f[0x2E8/4] * 2100.0f, 0.00584f, 6);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0xD4/4][0];
                }
                n = func_L01_00443A18(2.0f, 5.0f);
                p = func_L01_004713C8(sp0, sp20, 0xC, fe_func_003824E0(0.8f, 1.25f) * 210000.0f * 3.0f * pv->f[0x2E8/4], 0, n, 0x30, 0x30, pv->f[0x2E8/4] * 4200.0f, 0.00584f, 0);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0xD4/4][0];
                }
            }
            }
        }
        if ((f < 112.0f) || (m->b[0x42] != 0x11)) {
            m->f[0x48/4] = 0.5f;
        } else {
            m->f[0x48/4] = 1.0f;
        }
        if (func_L01_0044E1B8(m, 114.0f) != 0) {
            u8 *pos;
            s32 i;
            fe_func_003C2F58(m, 1, sp0);
            pos = m->b + 0x10;
            for (i = 0; i < 1; i++) {
                f32 w;
                *(u128_t *)sp10 = ((Hero *)D_001A4BE0)->q[0xD0/16];
                if (fe_func_0038CF38(pos, D_001A4BE0 + 0x80) > 6.0f) {
                    vec_sub_ba(sp20, m->b + 0x10, D_001A4BE0 + 0x80);
                    fe_func_0038CF68(sp20, sp20, 5.0f);
                    vec_add_ab(sp10, sp20, sp10);
                }
                w = fe_func_0038CF38(pos, D_001A4BE0 + 0x80) * 3.0f * 0.00040000002f;
                if (w < 0.014f) {
                    w = 0.014f;
                }
                vec_sub_ab(sp20, sp10, sp0);
                sp20[2] = 0.0f;
                fe_func_0038CF68(sp20, sp20, 0.20000002f);
                sp20[2] = func_L01_00447878(sp0, sp10, 0, 0.20000002f, -w);
                fe_func_003A52A0(0x13, 0, m);
                func_L20_003F9C10(m, sp20, sp0, w);
            }
        }
        }
        break;
    case 24:
        if (m->uh[0x96/2] >= 9) {
            if (pv->i[0x634/4] < 5) {
                pv->i[0x634/4] = pv->i[0x634/4] + 1;
                func_L01_004450F0(m, 0x17, -1);
                if (m->b[0x43] != 0x11) {
                    fe_func_003C3A10(m, 0x11, 0, 8);
                }
            } else {
                func_L01_004450F0(m, 0x21, -1);
                if (m->b[0x43] != 3) {
                    fe_func_003C3A10(m, 3, 0, 8);
                }
            }
        }
        break;
    case 33:
        if (m->b[0x60] & 2) {
            pv->i[0x634/4] = 0;
            if (m->b[0x43] != 9) {
                fe_func_003C3A10(m, 9, 0, 8);
            }
            func_L01_004450F0(m, 0x19, -1);
            if (pv->i[0x5CC/4] != 4) {
                func_L01_004450F0(m, 7, -1);
            }
            if ((pv->i[0x638/4] != 0) && (fe_func_00392B20(D_L20_001E9980, 0xBA) != 0)) {
                m->i[0x98/4] = 0;
                m->uh[0x34/2] = (m->uh[0x34/2] | 0x41) & 0xEFFF;
                func_L01_004AA7E8(m, 1);
                func_L01_004450F0(m, 2, 7);
                fe_func_00392C78(D_L20_001E9980);
            }
        }
        break;
    case 17:
        {
        u8 *pos = m->b + 0x10;
        u8 *dst = pv->b + 0x5F0;
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, D_L20_001DEBD0 * 0.00040000002f, D_L20_001DEBCC * 0.020000001f, 0.010053097f, 0.25132743f);
            do {
                f32 a = fe_func_00382538();
                f32 r = fe_func_003824E0(13.0f, 15.0f);
                qzero(sp0);
                sp0[0] = fe_func_0038D098(a) * r;
                sp0[1] = fe_func_0038D0B0(a) * r;
                vec_add_ab(pv->b + 0x5F0, m->b + 0x10, sp0);
                if (pv->i[0x5E8/4] != -1) {
                    vec_add_ba(pv->b + 0x5F0, &D_L20_001E0380[pv->i[0x5E8/4]].pos, sp0);
                }
            } while (!(fe_func_0038CF38(pos, dst) > 8.0f));
        }
        func_L02_00431568(m, dst, fe_func_0038D160(pv->f[0x5F0/4] - m->f[0x10/4], pv->f[0x5F4/4] - m->f[0x14/4]), -1.0f, -1.0f, -1.0f, 0x14);
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if (fe_func_0038CF38(pos, dst) < 0.75f) {
            if (m->b[0x43] != 0xC) {
                fe_func_003C3A10(m, 0xC, 0, 5);
            }
            func_L01_004450F0(m, 0x10, -1);
        }
        if ((pv->f[0x30/4] < 400.0f) && (pv->i[0x610/4] == 0)) {
            if (m->b[0x43] != 0xD) {
                fe_func_003C3A10(m, 0xD, 0, 8);
            }
            func_L01_004450F0(m, 0x12, -1);
        }
        }
        break;
    case 27:
        if (func_L01_004561B8(m) != 0) {
            if (D_L20_001E2E80.x144 == m) {
                D_L20_001E2E80.x144 = 0;
            }
            pv->i[0x638/4] = 0;
            pv->i[0xA8/4] |= 5;
            func_L01_0045BD78(m, D_L20_001DEBD0 * 0.00040000002f, D_L20_001DEBCC * 0.020000001f, 0.010053097f, 0.25132743f);
        }
        pv->h[0x36/2] = 8;
        func_L01_00404808(func_L20_003D7558, m);
        func_L01_00404808(func_L20_003D7950, m);
        func_L01_00404808(func_L20_003D8248, m);
        if (func_L01_0045BDE8(m, pv->i[0x63C/4]) != 0) {
            pv->q[0x5B0/16] = m->q[0x10/16];
            func_L01_004450F0(m, 0x1C, -1);
        }
        break;
    case 28:
        {
        u8 *pos;
        pv->h[0x36/2] = 8;
        func_L01_00404808(func_L20_003D7558, m);
        pos = m->b + 0x10;
        func_L01_00404808(func_L20_003D7950, m);
        func_L01_00404808(func_L20_003D8248, m);
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0xD0/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0xD4/4] - m->f[0x14/4]));
        if ((fe_func_0038CF38(pos, D_001A4BE0 + 0x80) < 20.0f) || ((pv->i[0x640/4] != -1) && (fe_func_00382380(D_001A4BE0 + 0x80, pv->i[0x674/4], 0) != 0))) {
            if (pv->i[0x640/4] != -1) {
                pv->i[0x63C/4] = pv->i[0x640/4];
                pv->i[0x640/4] = -1;
                func_L01_004450F0(m, 0x1B, -1);
            } else {
                func_L01_00456230(&D_L20_001E029C_d[pv->i[0x660/4]], 1);
                if (D_L20_001E2E80.x144 == 0) {
                    D_L20_001E2E80.x144 = m;
                    D_L20_001E2E80.x148 = 0;
                }
                if (m->b[0x43] != 0xD) {
                    fe_func_003C3A10(m, 0xD, 0, 5);
                }
                func_L01_004450F0(m, 0x12, -1);
            }
        } else if ((m->uh[0x96/2] >= 0xE2) && (fe_func_0038CF38(pos, D_001A4BE0 + 0x80) < 60.0f)) {
            func_L01_004450F0(m, 0x1D, -1);
            if (m->b[0x43] != 0xC) {
                fe_func_003C3A10(m, 0xC, 0, 5);
            }
        }
        }
        break;
    case 29:
        {
        f32 f;
        pv->h[0x36/2] = 8;
        func_L01_00404808(func_L20_003D7558, m);
        func_L01_00404808(func_L20_003D7950, m);
        func_L01_00404808(func_L20_003D8248, m);
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if (func_L01_004561B8(m) != 0) {
            pv->f[0x2E8/4] = 0.0f;
            pv->i[0x2EC/4] = 0;
            fe_func_00382468(2);
            pv->i[0x5E0/4] = 0;
            if (pv->i[0x640/4] == -1) {
                pv->i[0x5E0/4] = 1;
            }
            pv->i[0x62C/4] = -1;
        }
        if (pv->i[0x62C/4] == -1) {
            if (func_L01_004395E0(m) < 163.0f) {
                pv->i[0x62C/4] = func_L01_00424CB0(m->b + 0x10, pv->f[0x2E8/4] * 15.0f, 0.0f, 0.45f, 0.2f, 1.0f);
            }
        } else {
            Light *l;
            fe_func_003C2F58(m, 3, sp0);
            l = &D_L20_001F0D00[pv->i[0x62C/4]];
            l->u.pos = *(u128_t *)sp0;
            l->u.v.w = pv->f[0x2E8/4] * 15.0f;
            l->r = 0.45f;
            l->g = 0.2f;
            l->b = 1.0f;
            l->on = 0;
            if (pv->i[0x5E0/4] == 1) {
                l->r = 0.8f;
                l->g = 0.0f;
                l->b = 0.0f;
                l->on = 0;
            }
        }
        if ((pv->f[0x30/4] < 400.0f) && (pv->i[0x610/4] == 0)) {
            if (m->b[0x43] != 0xD) {
                fe_func_003C3A10(m, 0xD, 0, 8);
            }
            func_L01_004450F0(m, 0x12, -1);
        }
        if (fe_func_0038CAD0(pv->b + 0x2EC) == 0) {
            f32 ang;
            s32 k;
            f32 *p30;
            fe_func_0038CAD0(pv->b + 0x2F0);
            func_L01_00404A10(func_L20_003D6F30, m);
            fe_func_003C2F58(m, 3, sp0);
            p30 = sp30;
            *(u128_t *)sp30 = 0;
            *(u128_t *)sp40 = *(u128_t *)sp0;
            sp30[0] = 0.3f;
            sp30[1] = -1.0f;
            sp30[3] = 1.0f;
            *(u128_t *)sp70 = m->q[0xC0/16];
            *(u128_t *)sp80 = m->q[0xD0/16];
            fe_func_0038D890(sp30, sp70, sp80, 0.34906584f);
            qzero(sp90);
            *(u128_t *)sp20 = *(u128_t *)sp30;
            fe_func_0038CE20(spA0, sp70, 0.4f);
            vec_add_ab(sp40, sp40, spA0);
            ang = 0.0f;
            k = 0x13;
            do {
                s32 n;
                s32 c;
                u8 *p;
                f32 r;
                ang = fe_func_0038DAB8(ang, fe_func_003824E0(0.0f, 0.62831855f));
                fe_func_0038CE20(sp50, sp20, fe_func_003824E0(0.24000001f, 0.32000002f));
                vec_add_ab(sp50, sp50, sp90);
                sp60[0] = sp40[0] + func_L01_00443A18(0.0f, 0.3f);
                sp60[1] = sp40[1] + func_L01_00443A18(0.0f, 0.3f);
                sp60[2] = sp40[2] + func_L01_00443A18(0.0f, 0.3f);
                n = func_L01_00443A18(1.0f, 2.0f);
                p = func_L01_004669B0(0.0f, 1.0f, 1.01f, fe_func_003824E0(0.2f, 0.75f) * 210000.0f, sp60, n, D_L20_001D66B0, 0x7F000000, 0);
                if (p != 0) {
                    u8 *q;
                    p[3] = 0x44;
                    *(s16 *)(p + 0xA) = 0x32;
                    p[9] = 0x44;
                    q = p + 0x20;
                    *(f32 *)(q + 0x1C) = 4.0f;
                    *(s32 *)(q + 4) = 3;
                    q[0xA] = 0x30;
                    q[0xB] = p[0xA];
                }
                sp60[0] = sp40[0] + func_L01_00443A18(0.0f, 0.6f);
                sp60[1] = sp40[1] + func_L01_00443A18(0.0f, 0.6f);
                sp60[2] = sp40[2] + func_L01_00443A18(0.0f, 0.6f);
            c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                } else if (pv->i[0x5E0/4] == 1) {
                    c = 0x6065C;
                } else if (pv->i[0x5E0/4] == 2) {
                    c = 0x7C30;
                }
                r = fe_func_003824E0(0.2f, 1.75f);
                vec_sub_ab(sp60, sp60, sp50);
                p = func_L01_0046A610(sp60, sp50, 5, 0x7F, c, n, r * 210000.0f, 500.0f, 0.95f, 0.0f, 0.0f);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0x16C/4][1];
                }
                if (fabs_asm(ang) > 1e-05f) {
                    fe_func_003C4840(sp10, sp70, ang);
                    fe_func_0038D850(sp20, p30, sp10);
                }
            } while (--k >= 0);
        }
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 0xB) {
                fe_func_003C3A10(m, 0xB, 0, 2);
            }
            func_L01_004450F0(m, 0x1C, -1);
        }
        f = func_L01_004395E0(m);
        if ((m->b[0x42] != 0xC) || (f < 156.0f)) {
            {
            f32 e;
            f32 t;
            s32 i;
            u8 *p;
            t = pv->f[0x2E8/4] + 0.030000001f;
            e = t * 262500.0f;
            pv->f[0x2E8/4] = t;
            fe_func_003C2F58(m, 3, sp0);
            if (fe_func_00382468(2) != 0) {
                s32 n;
                s32 c;
                c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                } else if (pv->i[0x5E0/4] == 1) {
                    c = 0x6065C;
                } else if (pv->i[0x5E0/4] == 2) {
                    c = 0x7C30;
                }
                n = func_L01_00443A18(1.0f, -1.0f);
                p = func_L01_0046A610(sp0, D_L20_001D66B0, 0xC, 6, c, n, e * 6.0f, 500.0f, 1.0f, 0.0f, 0.0f);
                if (p != 0) {
                    p[2] = D_L20_00220258[0x170/4][1];
                }
            }
            sp10[0] = sp0[0] + func_L01_00443A18(0.0f, 0.04f);
            sp10[1] = sp0[1] + func_L01_00443A18(0.0f, 0.04f);
            sp10[2] = sp0[2] + func_L01_00443A18(0.0f, 0.04f);
            if (fe_func_00382468(2) != 0) {
                s32 n;
                s32 c;
                f32 *q;
                c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                } else if (pv->i[0x5E0/4] == 1) {
                    c = 0x6065C;
                } else if (pv->i[0x5E0/4] == 2) {
                    c = 0x7C30;
                }
                q = sp10;
                n = func_L01_00443A18(1.0f, -1.0f);
                p = func_L01_0046A610(q, D_L20_001D66B0, 0xC, 0x7F, c, n, e * 2.4f, 500.0f, 1.0f, 0.0f, 0.0f);
                if (p != 0) {
                    p[3] = (fe_func_00382468(2) != 0) ? 0x48 : 0x44;
                    p[2] = D_L20_00220258[0x170/4][0];
                }
            }
            for (i = 0; i < 6; i++) {
                s32 n;
                u8 *p;
                fe_func_00382580(sp20, pv->f[0x2E8/4] * 0.10000001f, pv->f[0x2E8/4] * 0.14000002f);
                n = func_L01_00443A18(2.0f, 5.0f);
                p = func_L01_004713C8(sp0, sp20, 0xC, fe_func_003824E0(0.8f, 1.25f) * 210000.0f * pv->f[0x2E8/4], 0, n, 0x7F, 0x7F, pv->f[0x2E8/4] * 2100.0f, 0.00584f, 6);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0xD4/4][0];
                }
                n = func_L01_00443A18(2.0f, 5.0f);
                p = func_L01_004713C8(sp0, sp20, 0xC, fe_func_003824E0(0.8f, 1.25f) * 210000.0f * 3.0f * pv->f[0x2E8/4], 0, n, 0x30, 0x30, pv->f[0x2E8/4] * 4200.0f, 0.00584f, 0);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0xD4/4][0];
                }
            }
            }
        }
        if ((f < 153.0f) || (m->b[0x42] != 0xC)) {
            m->f[0x48/4] = 0.5f;
        }
        if ((f > 153.0f) && (f < 156.0f) && (m->b[0x42] == 0xC)) {
            m->f[0x48/4] = 0.15f;
        }
        if ((f > 156.0f) && (f < 165.0f) && (m->b[0x42] == 0xC)) {
            m->f[0x48/4] = 3.0f;
        }
        if ((f > 165.0f) && (m->b[0x42] == 0xC)) {
            m->f[0x48/4] = 1.0f;
        }
        if (func_L01_0044E1B8(m, 165.0f) != 0) {
            Mo *o;
            s32 i;
            f32 *p30;
            s32 a;
            s32 b;
            if (pv->i[0x62C/4] != -1) {
                func_L01_00424D88(pv->i[0x62C/4]);
            }
            pv->i[0x62C/4] = -1;
            if (pv->i[0x5E0/4] == 0) {
                a = 0x1AF1;
                b = 0xD90;
            } else if (pv->i[0x5E0/4] == 1) {
                a = 0x1CDA;
                b = 0xD50;
            } else if (pv->i[0x5E0/4] == 2) {
                a = 0x1CDB;
                b = 0xD50;
            } else {
                a = 0x1AF1;
                b = 0xD90;
            }
            o = fe_func_003C24B0(a, b);
            *(u128_t *)sp0 = m->q[0x10/16];
            sp0[2] += 1.0f;
            func_L20_003EAA70(m, D_L20_001D66B0, sp0);
            o->b[0x30] = 0xFF;
            o->uh[0x32/2] = 0xFF;
            o->b[0x31] = 1;
            o->mp[0xB8/4] = m;
            o->q[0x10/16] = m->q[0x10/16];
            o->q[0xF0/16] = m->q[0xF0/16];
            o->f[0x18/4] += 1.5f;
            o->d[0x38/8] = m->d[0x38/8];
            fe_func_0038CF68(sp10, m->b + 0xC0, 2.0f);
            vec_add_ba(o->b + 0x10, sp10, o->b + 0x10);
            pv->i[0x2EC/4] = 0x15;
            pv->i[0x2F0/4] = 5;
            D_L20_001E2E80.x40 = 0.1f;
            D_L20_001E2E80.x48 = 0x4B;
            D_L20_001E2E80.x20 = 0.2f;
            D_L20_001E2E80.x28 = 0x32;
            D_L20_001E2E80.x2C = 0;
            p30 = sp30;
            for (i = 0; i < 300; i++) {
                s32 n;
                s32 c;
                u8 *p;
                fe_func_003C2F58(m, 3, sp20);
                fe_func_00382580(p30, 0.6f, 0.70000005f);
                n = func_L01_00443A18(2.0f, 3.0f);
                p = func_L01_004713C8(sp20, p30, 0x32, fe_func_003824E0(0.8f, 1.25f) * 210000.0f * pv->f[0x2E8/4], 0, n, 0x7F, 0x7F, pv->f[0x2E8/4] * 2100.0f, 0.0f, 6);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0xD4/4][0];
                }
            c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                } else if (pv->i[0x5E0/4] == 1) {
                    c = 0x6065C;
                } else if (pv->i[0x5E0/4] == 2) {
                    c = 0x7C30;
                }
                n = func_L01_00443A18(2.0f, 3.0f);
                p = func_L01_004713C8(sp20, p30, 0x32, fe_func_003824E0(0.8f, 1.25f) * 210000.0f * 1.25f * pv->f[0x2E8/4], c, n, 0x30, 0x30, pv->f[0x2E8/4] * 4200.0f, 0.0f, 0);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0xD4/4][0];
                }
            }
        }
        }
        break;
    case 30:
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 9) {
                fe_func_003C3A10(m, 9, 0, 7);
            }
            func_L01_004450F0(m, 7, -1);
        }
        break;
    case 31:
        if (m->b[0x60] & 2) {
            if (m->b[0x42] == 3) {
                if (m->b[0x43] != 4) {
                    fe_func_003C3A10(m, 4, 0, 7);
                }
            } else if (m->b[0x42] == 4) {
                if (m->b[0x43] != 3) {
                    fe_func_003C3A10(m, 3, 0, 7);
                }
            }
        }
        break;
    case 25:
        {
        u8 *dst;
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, D_L20_001DEBC0 * 0.00040000002f, D_L20_001DEBBC * 0.020000001f, 0.010053097f, 0.25132743f);
        }
        dst = pv->b + 0x5B0;
        func_L01_0045A748(m, dst);
        if (fe_func_0038CF38(m->b + 0x10, dst) <= 0.75f) {
            if (m->b[0x43] != 0xE) {
                fe_func_003C3A10(m, 0xE, 0, 8);
            }
            func_L01_004450F0(m, 0x1A, -1);
        }
        }
        break;
    case 26:
        if (func_L01_004561B8(m) != 0) {
            pv->i[0x610/4] = 1;
        }
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if ((m->b[0x60] & 2) && (m->b[0x43] != 0xF)) {
            fe_func_003C3A10(m, 0xF, 0, 1);
        }
        if ((func_L01_0044E1B8(m, 125.0f) != 0) && (m->b[0x42] == 0xE)) {
            Spot *s;
            fe_func_003A52A0(0xE, 0, m);
            s = &D_L20_001E0380_d[pv->i[0x71C/4]];
            pv->mp[0x304/4] = fe_func_003C24B0(0x1CAF, 0x130);
            func_L01_00456160(pv->mp[0x304/4], m);
            pv->mp[0x304/4]->q[0x10/16] = s->pos;
            fe_func_003C3938(pv->mp[0x304/4], 0, m->b[0x40]);
        }
        if ((func_L01_0044E1B8(m, 115.0f) != 0) && (m->b[0x42] == 0xE)) {
            Spot *s;
            fe_func_003A52A0(0xE, 0, m);
            s = &D_L20_001E0380_d[pv->i[0x720/4]];
            pv->mp[0x308/4] = fe_func_003C24B0(0x1CAF, 0x130);
            func_L01_00456160(pv->mp[0x308/4], m);
            pv->mp[0x308/4]->q[0x10/16] = s->pos;
            fe_func_003C3938(pv->mp[0x308/4], 0, m->b[0x40]);
        }
        if ((m->b[0x42] == 0xF) && ((D_L20_001DFD40_d & 0xF) == (((s32)m >> 8) & 0xF))) {
            Spot *s;
            fe_func_003A52A0(0xE, 0, m);
            s = &D_L20_001E0380_d[pv->i[0x710/4 + fe_func_00382468(0x10)]];
            pv->mp[0x308/4] = fe_func_003C24B0(0x1CAF, 0x130);
            func_L01_00456160(pv->mp[0x308/4], m);
            pv->mp[0x308/4]->q[0x10/16] = s->pos;
            fe_func_003C3938(pv->mp[0x308/4], 0, m->b[0x40]);
        }
        if (m->uh[0x96/2] >= 0x1F5) {
            if (fe_func_00382468(2) != 0) {
                if (m->b[0x43] != 3) {
                    fe_func_003C3A10(m, 3, 0, 6);
                }
            } else {
                if (m->b[0x43] != 4) {
                    fe_func_003C3A10(m, 4, 0, 6);
                }
            }
            func_L01_004450F0(m, 0x1E, -1);
        }
        break;
    }
    func_L20_003D6D18(m);
    if (pv->mp[0x618/4] != 0) {
        pv->mp[0x618/4]->i[0x98/4] = 0;
        fe_func_003C7C38(pv->mp[0x618/4]);
    }
    if (pv->mp[0x67C/4] != 0) {
        pv->mp[0x67C/4]->i[0x98/4] = 0;
        fe_func_003C7C38(pv->mp[0x67C/4]);
    }
}
