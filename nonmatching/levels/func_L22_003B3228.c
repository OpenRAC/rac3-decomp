/* func_L22_003B3228: near miss (Opus agent B, 2026-11-13). 11,472 bytes, 2 places (22 27),
   file src/levels/shared/L22_003B3228.c. Rewritten by hand from retail (the m2c draft lost the cases).
   Needs `-mvu0-use-vf0-vf2 ... @ps2as` on the file's line (li.s constants, vec_add/vec_sub/qzero from
   include/vu0.h). Data names are level 27's; check with --target level_27.
   Stock checker, level 27: 2594 of 2871 instructions equal when aligned, 2811 by opcode. Frame 0xC0 and
   the saved registers equal retail; both switches (on 0x95 and on the state) and every case are in place.
   Shapes found:
   - The hero block is a struct (H_003B3228, D_001A4BE0.field): retail keeps &D_001A4BE0 split as
     lui/addiu + offset, which u8-pointer arithmetic folds into %lo(sym+off).
   - D_001A7E18 is a struct too (base kept in $s3); D_001BBE90 is indexed with (mode << 10) even inside
     `if (mode == 0x16)` (retail adds the folded 0x5800 to the index, not to the symbol).
   - Case 21's search loop writes D_L27_001E0F3C directly (loop.c promotes it to $t0; a local `best`
     makes p->w49C loop-invariant, which retail reloads).
   - Every global reached through $gp is reached only in branch delay slots: one `.extern X, 16` name
     each, and Ps2EeAs picks $gp there.
   - func_003C41A0 takes (out, f, f, f, f, p): retail computes &a.z before the nested call.
   - Locals as one V4 vv[7]; case 13's matrix is &vv[3], case 16's &vv[0].
   Left: register choice in case 21's search loop (the w44 reads go through the w84 pointer giv in retail),
   case 6 and 24's column reads (retail copies the column pointer twice), the dead lw of D_L27_001DFEA0
   before func_L22_0041FCC8 (retail's branch on DFEA0 == 1 is merged after flow; not reproduced), the
   hero lui shared with the tail in case 4/13/19, and assorted beql/bnel choices. */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003B3228;
typedef struct { u8 pad0[0x10]; u8 b10; } A_003B3228;
typedef struct { u8 pad0[0x48]; A_003B3228 *p48; u8 pad4C[8]; A_003B3228 *p54; A_003B3228 *p58; } C_003B3228;

typedef struct M_003B3228 {
    u8 pad0[0x10];
    V4_003B3228 pos;
    u8 state;
    u8 pad21[3];
    C_003B3228 *cls;
    u8 pad28[0x1A];
    u8 anim;
    u8 anim2;
    u8 pad44[4];
    f32 f48;
    u8 pad4C[0x14];
    u8 b60;
    u8 pad61[7];
    struct P_003B3228 *pv;
    u8 pad6C[0x28];
    u8 prev;
    u8 b95;
    u16 h96;
    u8 pad98[0x12];
    s16 hAA;
    u8 padAC[6];
    u16 hB2;
    u8 padB4[0xC];
    V4_003B3228 vel;
    u8 padD0[0x28];
    f32 fF8;
} __attribute__((aligned(16))) M_003B3228;

typedef struct P_003B3228 {
    u8 pad0[0x3E];
    u8 b3E;
    u8 pad3F[0x20];
    u8 b5F;
    u8 pad60[0x1C0];
    V4_003B3228 v220;
    M_003B3228 *m230;
    s16 h234;
    u8 pad236[0x152];
    s32 w388;
    u8 pad38C[0x10];
    s32 w39C;
    u8 pad3A0[0xA0];
    s32 w440;
    f32 f444;
    f32 f448;
    u8 pad44C[4];
    s32 w450;
    s32 w454;
    s32 w458;
    s32 w45C;
    s32 w460;
    u8 pad464[4];
    s32 w468;
    u8 pad46C[4];
    s32 w470;
    s32 w474;
    u8 pad478[4];
    M_003B3228 *m47C;
    s32 w480;
    s32 w484;
    u8 pad488[8];
    s32 w490;
    s32 w494;
    s32 w498;
    s32 w49C;
    s32 w4A0;
    s32 w4A4;
    s32 w4A8;
    s32 w4AC;
    s32 w4B0;
    s32 w4B4;
    s32 w4B8;
    s32 w4BC;
    s32 w4C0[8];
    u8 pad4E0[8];
    f32 f4E8;
    u8 pad4EC[0x24];
    V4_003B3228 v510;
    u8 pad520[8];
    f32 f528;
    u8 pad52C[8];
    s32 w534;
    s32 w538;
} P_003B3228;

typedef struct {
    s32 w0;
    s32 w4[16];
    s32 w44[16];
    s32 w84[16];
    s32 wC4;
    s32 wC8[16];
    s32 w108[16];
    s32 w148[16];
} S_003B3228;

typedef struct { u8 pad0[0x30]; V4_003B3228 v30; u8 pad40[0x40]; } R_003B3228;

typedef struct {
    u8 pad0[0x80];
    f32 x80;
    f32 y84;
    u8 pad88[0xEC];
    f32 f174;
    u8 pad178[0xA90];
    s32 wC08;
    u8 padC0C[0x19B4];
    M_003B3228 *m25C0;
    s32 w25C4;
    u8 pad25C8[0x240];
    M_003B3228 *m2808;
} H_003B3228;
extern H_003B3228 D_001A4BE0;
extern V4_003B3228 D_001A4C60;
typedef struct { u8 pad0[0x2AC]; u16 h2AC; u8 pad2AE[6]; s32 w2B4; } G_003B3228;
extern G_003B3228 D_001A7E18;
extern u8 D_001BBE90[];
extern s32 D_001CCFD0[];
extern s32 D_L27_002E8830[];
extern S_003B3228 D_L27_002BBA00[];
extern s32 D_L27_001E0E78[];
extern s32 D_L27_001E0EB8[];
extern s32 D_L27_001E0EF8[];
extern s32 D_L27_001DE038[];
extern s32 D_001D545C_003B3228;
__asm__(".extern D_001D545C_003B3228, 16");
extern u8 *D_001D52FC_003B3228;
__asm__(".extern D_001D52FC_003B3228, 16");
extern M_003B3228 *D_001A71A0_003B3228;
__asm__(".extern D_001A71A0_003B3228, 16");
extern s32 D_L27_001D6694;
__asm__(".extern D_L27_001D6694, 16");
extern u8 *D_L27_001DED1C;
__asm__(".extern D_L27_001DED1C, 16");
extern R_003B3228 *D_L27_001DEE00;
__asm__(".extern D_L27_001DEE00, 16");
extern s32 D_L27_001E0E70;
__asm__(".extern D_L27_001E0E70, 16");
extern s32 D_L27_001E0F38;
__asm__(".extern D_L27_001E0F38, 16");
extern s32 D_L27_001E0F3C;
__asm__(".extern D_L27_001E0F3C, 16");
extern f32 D_L27_001DFEA4;
__asm__(".extern D_L27_001DFEA4, 16");
extern s32 D_L27_001DFEA0;
__asm__(".extern D_L27_001DFEA0, 16");

extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038CAD0(s32 *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_003A52A0(s32, s32, M_003B3228 *);
extern void func_003C2EC0(M_003B3228 *, s32, void *);
extern void func_003C3A10(M_003B3228 *, s32, s32, s32);
extern f32 func_003C3D30(f32, void *, s32, s32);
extern void func_003C4098(f32, void *, void *, void *);
extern void func_003C41A0(void *, f32, f32, f32, f32, void *);
extern void func_L01_00315900(M_003B3228 *, s32, void *);
extern void func_L01_003B2DC8(M_003B3228 *);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern void func_L01_00404808(void *, M_003B3228 *);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_0041A5B0(s32, s32);
extern void func_L01_0041A6E0(void);
extern f32 func_L01_004395E0(M_003B3228 *);
extern void func_L01_00444F38(M_003B3228 *, s32, s32, s32, s32);
extern void func_L01_004450F0(M_003B3228 *, s32, s32);
extern void func_L01_00446058(M_003B3228 *, s32, s32);
extern void func_L01_004468C8(f32, f32, f32, M_003B3228 *, s32, s32, s32, s32, s32);
extern s32 func_L01_0044E1B8(f32, M_003B3228 *);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_00454370(M_003B3228 *, void *);
extern s32 func_L01_004561B8(M_003B3228 *);
extern s32 func_L01_004561E0(M_003B3228 *);
extern void func_L01_00456230(void *, s32);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_0045A748(M_003B3228 *, void *);
extern void func_L01_0045A7A8(f32, M_003B3228 *, void *);
extern void func_L01_0045A9F0(M_003B3228 *);
extern void func_L01_0045AA10(f32, M_003B3228 *);
extern void func_L01_0045AA30(M_003B3228 *, void *);
extern void func_L01_0045BD10(f32, M_003B3228 *);
extern void func_L01_0045BD78(f32, f32, f32, f32, M_003B3228 *);
extern s32 func_L01_0045BDE8(M_003B3228 *, s32);
extern void func_L01_0050FB40(f32, s32, s32);
extern s32 func_L01_00511A98(void *, s32);
extern void func_L02_003A5010(M_003B3228 *);
extern f32 func_L05_00441508(f32, f32, f32);
extern s32 func_L22_003B5EF8(void);
extern void func_L22_003B6B90(M_003B3228 *);
extern s32 func_L22_003B6D30(M_003B3228 *, M_003B3228 *);
extern void func_L22_003B6EE8(M_003B3228 *, s32);
extern void func_L22_003B7150(void);
extern s32 func_L22_003B71D0(M_003B3228 *, M_003B3228 *);
extern void func_L22_003B8100(M_003B3228 *);
extern void func_L22_003B83A0(M_003B3228 *);
extern void func_L22_0041FCC8(s32, s32);
extern void func_L27_004D1568(s32, s32);

#define a vv[0]
#define b vv[1]
#define c vv[2]
#define d vv[3]
#define e vv[4]
static const f32 Z1_003B3228 = 0.0f;
static const f32 Z2_003B3228 = 0.0f;
#define FRAMES(x) (((x) * 5 + 2) / 6)
#define RND48(m) func_00382468((m)->cls->p48->b10)
#define RND54(m) func_00382468((m)->cls->p54->b10)
#define RND58(m) func_00382468((m)->cls->p58->b10)

#define PAD_003B3228 D_001D52FC_003B3228

void func_L22_003B3228(M_003B3228 *m) {
    P_003B3228 *p = m->pv;
    V4_003B3228 vv[7];
    s32 n;

    if (func_L22_003B5EF8() != 0) {
        func_L01_003B2DC8(m);
        return;
    }
    if (D_001D545C_003B3228 == 0x16 && p->w538 == 0) {
        func_L01_00446058(m, 0x1BA0, 0x1A4E);
        p->w538 = 1;
    }
    if (p->w460 == 0 && p->h234 == 1) {
        M_003B3228 *o = D_001A71A0_003B3228;
        if (o != 0 && (o->hAA == 0x173B || o->hAA == 0x1A4E)) {
            p->h234 = 0;
        }
    }
    switch (m->b95) {
    case 0:
        if (func_L01_00456250(D_L27_001DED1C + (p->w470 << 8)) != 0) {
            func_L01_004450F0(m, 4, 1);
            if (m->anim2 != 0) {
                func_003C3A10(m, 0, RND48(m), 8);
            }
        }
        break;
    case 1:
        if (func_L01_004561E0(m) != 0 && p->w458 == 0) {
            p->w458 = FRAMES(func_00382498(0, 20));
        }
        if (p->h234 == 1 && func_0038CAD0(&p->w458) != 0 && D_001D545C_003B3228 != 0x16) {
            if (m->anim2 != 4) {
                func_003C3A10(m, 4, RND58(m), 8);
            }
            func_L01_004450F0(m, 8, 3);
            if (p->w474 != -1) {
                func_L01_004450F0(m, 5, -1);
            }
        } else if (p->w45C != 0 && func_0038CAD0(&p->w458) != 0) {
            func_L01_004450F0(m, m->state, 2);
            p->w45C = 0;
            if (p->w450 < 0xFA) {
                p->w450 = FRAMES(func_00382498(0x1E0, 0x258));
            }
        }
        {
            s32 ok = 1;
            if (p->w534 != -1 && D_001D545C_003B3228 == 0x16) {
                if (*(s32 *)(*(u8 **)(D_L27_001DED1C + (p->w534 << 8) + 0x68) + 0x130) != 0) {
                    ok = 0;
                }
            }
            if (func_L22_003B6D30(m, p->m230) != 0 && ok) {
                if (D_001D545C_003B3228 == 0x16) {
                    func_L01_0041A6E0();
                }
                func_L01_004450F0(m, 0x12, 5);
            }
        }
        break;
    case 2:
        if (p->h234 == 1) {
            if (m->anim2 != 4) {
                func_003C3A10(m, 4, RND58(m), 8);
            }
            func_L01_004450F0(m, 8, 3);
        } else if (p->w450 == 0) {
            func_L01_004450F0(m, m->state, 1);
        }
        if (func_L22_003B6D30(m, p->m230) != 0) {
            if (D_001D545C_003B3228 == 0x16) {
                func_L01_0041A6E0();
            }
            func_L01_004450F0(m, 0x12, 5);
        }
        break;
    case 3:
        if (p->h234 != 1 && func_L01_004561E0(m) == 0) {
            func_L01_004450F0(m, 0x10, 2);
            if (m->anim2 != 1) {
                func_003C3A10(m, 1, 0, 8);
            }
            p->w450 = FRAMES(func_00382498(0x30C, 0x384));
        }
        break;
    case 4:
        {
            s32 r = func_L01_00454370(m, (u8 *)p + 0x160);
            if (r & 1) {
                func_L02_003A5010(m);
                func_L01_00315900(m, 0, func_L01_003B2DC8);
                return;
            }
            if (r & 2) {
                if (p->h234 == 1) {
                    func_L01_004450F0(m, 8, 3);
                } else {
                    func_L01_004450F0(m, 7, 2);
                    p->w450 = FRAMES(func_00382498(0x244, 0x258));
                }
            }
        }
        break;
    case 5:
            {
            if (p->h234 == 1 || D_001A4BE0.m25C0 == 0
                || (D_001A4BE0.m25C0->hAA != 0x173B && D_001A4BE0.m25C0->hAA != 0x1A4E)
                || (D_001A4BE0.w25C4 == 0x52 && m->state >= 0x15)) {
                func_L01_004450F0(m, 0x1D, -1);
            }
        }
        p->w39C = p->w388;
        func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
        break;
    }
    switch (m->state) {
    case 4:
        if (func_L01_004561B8(m) != 0) {
            if (m->prev == 0x1D) {
                if (m->anim2 != 2) {
                    func_003C3A10(m, 2, 0, 8);
                }
            } else if (m->anim2 != 0) {
                func_003C3A10(m, 0, RND48(m), 8);
            }
        }
        func_L01_0045AA10(m->fF8, m);
        if (m->anim == m->anim2 && (m->b60 & 2)) {
                {
                if (p->m230 != 0 && (D_001A4BE0.m25C0 == 0
                    || (D_001A4BE0.m25C0->hAA != 0x173B && D_001A4BE0.m25C0->hAA != 0x1A4E))) {
                    s32 x;
                    func_00382468(2);
                    x = func_00382468(2) ? 1 : 2;
                    func_003C3A10(m, x, 0, FRAMES(func_00382498(6, 12)));
                } else if (m->anim2 != 0) {
                    func_003C3A10(m, 0, RND48(m), 8);
                }
            }
        }
        break;
    case 2:
        if (func_L01_004561E0(m) != 0) {
            p->f4E8 = m->pos.z;
        }
        if (m->anim == 5) {
            f32 t = func_L01_004395E0(m);
            if (t > 2.0f && t < 10.0f) {
                func_0038CF68(&c, &m->vel, 0.0f);
                vec_add_ba(&a, &m->pos, &c);
            }
            if (t > 2.0f) {
                func_003C41A0(&a.z, p->f4E8 + 1.2f, 0.1125f, 0.1875f, 0.075f, &p->w440);
            }
            if (t > 2.0f && t < 10.0f) {
                vec_sub_ab(&b, &a, &m->pos);
                func_L01_0045AA30(m, &b);
                func_L01_0045BD10(func_0038D160(p->v220.x - m->pos.x, p->v220.y - m->pos.y), m);
            }
        }
        if (m->b60 & 2) {
            p->w440 = 0;
            func_L01_004450F0(m, 3, -1);
            if (m->anim2 != 8) {
                func_003C3A10(m, 8, 0, 0);
            }
        }
        break;
    case 3:
        {
            f32 t = func_L01_004395E0(m);
            if (t < 22.0f) {
                func_0038CF68(&c, &m->vel, 0.0f);
                vec_add_ba(&a, &m->pos, &c);
            }
            if (t < 15.0f) {
                func_L01_0045BD10(func_0038D160(p->v220.x - m->pos.x, p->v220.y - m->pos.y), m);
                func_003C41A0(&a.z, func_003C3D30(0.5f, &m->pos, 0, 0), 0.060000002f, 0.50000006f, 0.060000002f, &p->w440);
            }
            if (t < 22.0f) {
                vec_sub_ab(&b, &a, &m->pos);
                func_L01_0045AA30(m, &b);
            }
            if (m->b60 & 2) {
                p->w440 = 0;
                func_L01_004450F0(m, 8, -1);
                if (m->anim2 != 4) {
                    func_003C3A10(m, 4, RND58(m), 7);
                }
            }
        }
        break;
    case 5:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(0.0032f, 0.050000004f, 0.010053097f, 0.25132743f, m);
        }
        func_L01_0045BD78(0.0032f, 0.050000004f, 0.010053097f, 0.25132743f, m);
        if (func_L01_0045BDE8(m, p->w474) != 0 || func_0038CF38(&m->pos, &p->v220) < 6.0f) {
            func_L01_004450F0(m, 8, -1);
        }
        break;
    case 8:
        {
            V4_003B3228 *tgt;
            if (func_L01_004561B8(m) != 0) {
                func_L01_0045BD78(0.0032f, 0.050000004f, 0.010053097f, 0.25132743f, m);
            }
            tgt = &p->v220;
            func_L01_0045A7A8(p->f448, m, tgt);
            if (func_0038CF38(&m->pos, tgt) < 1.85f) {
                if (func_0038DBA0(m->fF8, func_0038D160(p->v220.x - m->pos.x, p->v220.y - m->pos.y)) < 0.34906584f) {
                    func_L01_004450F0(m, 0xA, -1);
                    if (m->anim2 != 5) {
                        func_003C3A10(m, 5, 1, 3);
                    }
                }
            }
        }
        break;
    case 10:
        if (func_L01_004561E0(m) != 0) {
            p->f4E8 = m->pos.z;
        }
        if (m->anim == 5) {
            f32 t = func_L01_004395E0(m);
            if (t > 2.0f && t < 10.0f) {
                func_0038CF68(&c, &m->vel, 0.09375f);
                vec_add_ba(&a, &m->pos, &c);
            }
            if (t > 5.0f) {
                c = m->pos;
                if (p->b5F != 0) {
                    func_L01_004468C8(0.5f, 1.0f, 0.75f, m, 1, 0x10000, 0, 1, 0);
                } else {
                    func_L01_004468C8(0.5f, 1.0f, 0.75f, m, 1, 1, 0, 1, 0);
                }
                func_003C41A0(&a.z, p->f4E8 + 0.6f, 0.1125f, 0.1875f, 0.075f, &p->w440);
            }
            if (t > 2.0f && t < 10.0f) {
                vec_sub_ab(&b, &a, &m->pos);
                func_L01_0045AA30(m, &b);
            } else {
                func_L01_0045AA10(m->fF8, m);
            }
        } else {
            func_L01_0045AA10(m->fF8, m);
        }
        if (m->b60 & 2) {
            p->w440 = 0;
                {
                if (D_001A4BE0.m2808 == m) {
                    func_L01_004450F0(m, 0xC, -1);
                    if (m->anim2 != 6) {
                        func_003C3A10(m, 6, 0, 0);
                    }
                } else {
                    func_L01_004450F0(m, 0xB, -1);
                    if (m->anim2 != 8) {
                        func_003C3A10(m, 8, 0, 0);
                    }
                }
            }
        }
        break;
    case 11:
        {
            f32 t;
            if (func_L01_004561B8(m) != 0) {
                p->f444 = 0.083333336f;
            }
            t = func_L01_004395E0(m);
            if (t > 15.0f) {
                p->f444 -= 0.004f;
            }
            if (t < 22.0f) {
                func_0038CF68(&c, &m->vel, p->f444);
                vec_add_ba(&a, &m->pos, &c);
            }
            if (t < 15.0f) {
                func_003C41A0(&a.z, func_003C3D30(0.5f, &m->pos, 0, 0), 0.060000002f, 0.50000006f, 0.060000002f, &p->w440);
            }
            if (t < 22.0f) {
                vec_sub_ab(&b, &a, &m->pos);
                func_L01_0045AA30(m, &b);
            } else {
                func_L01_0045AA10(m->fF8, m);
            }
            if (m->b60 & 2) {
                p->w440 = 0;
                func_L01_004450F0(m, 0xD, -1);
                if (m->anim2 != 1) {
                    func_003C3A10(m, 1, 8, 7);
                }
            }
        }
        break;
    case 12:
        {
            f32 t = func_L01_004395E0(m);
            if (t < 7.0f) {
                func_0038CF68(&c, &m->vel, 0.0f);
                vec_add_ba(&a, &m->pos, &c);
            }
            if (t < 7.0f) {
                func_003C41A0(&a.z, func_003C3D30(0.5f, &m->pos, 0, 0), 0.028571429f, 0.12857144f, 0.057142857f, &p->w440);
            }
            if (t < 7.0f) {
                vec_sub_ab(&b, &a, &m->pos);
                func_L01_0045AA30(m, &b);
            } else {
                func_L01_0045AA10(m->fF8, m);
            }
            if (func_L01_0044E1B8(10.0f, m) != 0) {
                p->w440 = 0;
                func_L01_004450F0(m, 0xE, -1);
                if (m->anim2 != 7) {
                    func_003C3A10(m, 7, 1, 3);
                }
            }
        }
        break;
    case 14:
        if (func_L01_004561B8(m) != 0) {
            p->f4E8 = m->pos.z;
        }
        if (m->anim == 7) {
            f32 t = func_L01_004395E0(m);
            if (t > 2.0f) {
                if (t < 18.0f) {
                    func_0038CF68(&c, &m->vel, -0.084375f);
                    vec_add_ba(&a, &m->pos, &c);
                }
            }
            if (t > 2.0f && t < 12.0f) {
                func_003C41A0(&a.z, p->f4E8 + 1.0f, 0.1f, 0.2f, 0.1f, &p->w440);
            }
            if (t == 12.0f) {
                p->w440 = 0;
            }
            if (t > 12.0f && t < 18.0f) {
                func_003C41A0(&a.z, func_003C3D30(0.5f, &m->pos, 0, 0), 0.027777778f, 0.33333334f, 0.25f, &p->w440);
            }
            if (t > 2.0f && t < 18.0f) {
                vec_sub_ab(&b, &a, &m->pos);
                func_L01_0045AA30(m, &b);
            } else {
                func_L01_0045AA10(m->fF8, m);
            }
            if (m->b60 & 2) {
                if (func_00382468(10) == 0) {
                    if (m->anim2 != 0xD) {
                        func_003C3A10(m, 0xD, 0, 7);
                    }
                    func_L01_004450F0(m, 0xF, -1);
                } else {
                    func_L01_004450F0(m, 8, -1);
                    if (m->anim2 != 4) {
                        func_003C3A10(m, 4, 0, 5);
                    }
                }
            }
        }
        break;
    case 15:
        func_L01_0045AA10(m->fF8, m);
        if (m->b60 & 2) {
            func_L01_004450F0(m, 8, -1);
            if (m->anim2 != 4) {
                func_003C3A10(m, 4, RND58(m), 5);
            }
        }
        break;
    case 13:
        if (func_L01_004561B8(m) != 0) {
            p->w458 = 0;
        }
        func_L01_0045AA10(m->fF8, m);
        if (m->anim == 1) {
            f32 f;
            func_003C2EC0(m, 0, &vv[3]);
            f = func_0038D160(vv[5].x, vv[5].y);
            if (func_0038DBA0(f, func_0038D160(p->v220.x - m->pos.x, p->v220.y - m->pos.y)) < 0.43633232f) {
                p->w458 = m->h96 + 5;
            }
                {
                if ((p->w458 != 0 && m->h96 == p->w458) || D_001A4BE0.f174 > 0.040000003f) {
                    if (m->anim2 != 4) {
                        func_003C3A10(m, 4, RND58(m), 5);
                    }
                    func_L01_004450F0(m, 8, -1);
                }
            }
        }
        if (m->b60 & 2) {
            if (m->anim2 != 2) {
                func_003C3A10(m, 2, 0, 5);
            }
            func_L01_004450F0(m, 0x10, -1);
        }
        break;
    case 16:
        if (func_L01_004561B8(m) != 0) {
            p->w458 = 0;
        }
        func_L01_0045AA10(m->fF8, m);
        if (m->anim == 2) {
            f32 f;
            func_003C2EC0(m, 0, &vv[0]);
            f = func_0038D160(vv[2].x, vv[2].y);
            if (func_0038DBA0(f, func_0038D160(p->v220.x - m->pos.x, p->v220.y - m->pos.y)) < 0.43633232f) {
                p->w458 = m->h96 + 5;
            }
                {
                if (p->h234 == 1 && ((p->w458 != 0 && m->h96 == p->w458) || D_001A4BE0.f174 > 0.040000003f)) {
                    if (m->anim2 != 4) {
                        func_003C3A10(m, 4, RND58(m), 5);
                    }
                    func_L01_004450F0(m, 8, -1);
                }
            }
        }
        if (m->b60 & 2) {
            if (m->anim2 != 0) {
                func_003C3A10(m, 0, RND48(m), 7);
            }
            func_L01_004450F0(m, 4, -1);
        }
        break;
    case 18:
        {
            f32 f;
            if (func_L01_004561B8(m) != 0) {
                p->w454 = func_00382498(0x19, 0x2A);
            }
            f = func_0038D160(p->m230->pos.x - m->pos.x, p->m230->pos.y - m->pos.y);
            func_L01_0045AA10(func_0038D160(p->m230->pos.x - m->pos.x, p->m230->pos.y - m->pos.y), m);
            if (func_0038DBA0(f, m->fF8 > 0.08726646f ? 1.0f : 0.0f) != 0.0f) {
                if (m->anim2 != 3) {
                    func_003C3A10(m, 3, RND54(m), 8);
                }
            } else if (m->anim2 != 0) {
                func_003C3A10(m, 0, RND48(m), 8);
            }
            if (func_0038CAD0(&p->w454) != 0) {
                func_L01_004450F0(m, 0x13, -1);
            }
        }
        break;
    case 19:
        if (func_L01_004561B8(m) != 0) {
            if (m->anim2 != 0x17) {
                func_003C3A10(m, 0x17, 0, 8);
            }
            m->f48 = func_003824E0(0.8f, 1.2f);
        }
        func_L01_0045AA10(func_0038D160(p->m230->pos.x - m->pos.x, p->m230->pos.y - m->pos.y), m);
        if (p->w4C0[0] > 0 && p->w4A0 == 0) {
            if (m->anim2 == 0x17 && m->anim == m->anim2 && (m->b60 & 2)) {
                func_003C3A10(m, 0, RND48(m), 7);
                func_L22_003B6EE8(m, 1);
                func_L01_004450F0(m, 0x14, -1);
            }
        } else if (m->anim2 == 0x17 && m->anim == m->anim2 && (m->b60 & 2)) {
            func_003C3A10(m, 0, RND48(m), 7);
            func_L01_004450F0(m, 4, 1);
        }
        break;
    case 20:
        {
            s32 cnt;
            u32 v;
            a = D_L27_001DEE00[p->w4B4].v30;
            cnt = 1;
            b = D_L27_001DEE00[p->w4B8].v30;
            if ((D_001A7E18.w2B4 & (cnt << D_001D545C_003B3228)) == 0) {
                func_L01_0041A5B0(0xB96, 0x39);
            }
            {
                f32 off;
                if (D_L27_001DFEA0 == 1) {
                    off = Z1_003B3228;
                } else {
                    off = Z2_003B3228;
                }
                func_L22_0041FCC8(D_L27_001DFEA4 * -80.0f + 0.5f + off, 1);
            }
            if (func_L01_004561B8(m) != 0) {
                p->w4AC = 0;
                p->w4A4 = 0;
                break;
            }
            cnt = 0;
            if (m->anim2 == 0x17) {
                if (m->anim == m->anim2 && (m->b60 & 2)) {
                    func_003C3A10(m, 0, RND48(m), 7);
                }
            } else if (func_L01_0040E570(&a, &m->pos) < 0.1f) {
                R_003B3228 *r = D_L27_001DEE00;
                f32 f;
                c = r[p->w4B4].v30;
                d = r[p->w4B8].v30;
                e = r[p->w4BC].v30;
                f = func_0038D160(d.x - c.x, d.y - c.y);
                f = func_L05_00441508(f, func_0038D160(e.x - c.x, e.y - c.y), 0.25f);
                if (m->anim2 != 0) {
                    func_003C3A10(m, 0, RND48(m), 7);
                }
                func_L01_0045AA10(f, m);
                cnt = 1;
            } else {
                if (m->anim2 != 3) {
                    func_003C3A10(m, 3, RND54(m), 7);
                }
                func_L01_0045A748(m, &a);
            }
                {
                if (D_001A4BE0.w25C4 == 0x58) {
                    cnt++;
                } else if (func_L01_00511A98(&D_001A4BE0, 0x58) == 2) {
                    func_L27_004D1568(0x58, 1);
                }
            }
            v = *(u32 *)(PAD_003B3228 + 0x1A0);
            if (v & 0x10) {
                D_001A7E18.h2AC = 0xFFFF;
                func_L01_0041A6E0();
                func_L01_004450F0(m, 0x1D, -1);
            } else if ((v & 0x40) && cnt >= 2) {
                D_001A7E18.h2AC = 0xFFFF;
                func_L01_0041A6E0();
                p->w498 = 0;
                func_L01_004450F0(m, 0x15, -1);
            }
        }
        break;
    case 21:
        {
            S_003B3228 *s = &D_L27_002BBA00[p->w4C0[p->w498]];
            if (func_L01_004561B8(m) != 0) {
                a = D_L27_001DEE00[p->w4BC].v30;
                d = m->pos;
                e = D_001A4C60;
                func_003C4098(0.75f, &c, &d, &e);
                c.z += 0.25f;
                qzero(&b);
                b.y = -func_0038D160(func_0038CF38(&a, &c), c.z - a.z);
                b.z = func_0038D160(c.x - a.x, c.y - a.y);
                func_L01_003EB350(0, &a);
                func_L01_003EB3C0(0, &b);
                p->w484 = 1;
                p->w49C = -100;
                p->w490 = 0;
                D_L27_001E0F38 = -1;
                D_L27_001E0F3C = -1;
                D_L27_001E0E70 = -1;
                func_L22_003B8100(m);
            }
            if (++p->w49C >= -24) {
                s32 r = func_L22_003B71D0(m, p->m230);
                s32 nw = r;
                s32 k;
                if (r >= 0 && D_L27_001E0F38 <= 0 && D_L27_001E0E70 >= 0) {
                    nw = p->w49C < D_L27_001E0EB8[D_L27_001E0E70] + 8 ? D_L27_001E0F38 : r;
                }
                if (nw != D_L27_001E0F38) {
                    if (nw > 0) {
                        s32 i = D_L27_001E0E70 + 1;
                        p->w480 = 1;
                        D_L27_001E0E78[i] = p->w49C;
                        D_L27_001E0EB8[i] = p->w49C;
                        D_L27_001E0EF8[i] = nw;
                        D_L27_001E0E70 = i;
                        if (s->w84[i] == 0) {
                            if (nw == s->w4[i]) {
                                func_003A52A0(D_L27_001DE038[nw - 1], 0, m);
                            }
                        }
                        D_L27_001E0F38 = nw;
                    } else if (s->w84[D_L27_001E0E70] <= 0) {
                        D_L27_001E0F38 = nw;
                    } else {
                        if (D_L27_001E0F38 > 0) {
                            func_003A52A0(D_L27_001DE038[D_L27_001E0F38 - 1], 0, m);
                        }
                        D_L27_001E0F38 = nw;
                    }
                } else if (nw > 0 && s->w84[D_L27_001E0E70] != 0) {
                    D_L27_001E0EB8[D_L27_001E0E70] = p->w49C;
                }
                k = 0;
                if (s->w4[0] > 0) {
                    do {
                        if (D_L27_001E0E70 < k) {
                            if (s->w44[k] < p->w49C - 10) {
                                D_L27_001E0F3C = k;
                            }
                        } else {
                            s32 t2 = D_L27_001E0EB8[k];
                            if (D_L27_001E0E78[k] + 10 < s->w44[k]) {
                                D_L27_001E0F3C = k;
                            }
                            if (t2 != p->w49C && t2 + 10 < s->w44[k] + s->w84[k]) {
                                D_L27_001E0F3C = k;
                            }
                            if (s->w44[k] + s->w84[k] < t2 - 10) {
                                D_L27_001E0F3C = k;
                            }
                            if (D_L27_001E0EF8[k] != s->w4[k]) {
                                D_L27_001E0F3C = k;
                            }
                        }
                        k++;
                    } while (s->w4[k] > 0);
                }
                if (D_L27_001E0F3C >= 0) {
                    func_003A52A0(0x24, 0, m);
                    func_L01_004450F0(m, 0x17, -1);
                } else if (D_L27_001E0F38 == 0 && D_L27_001E0E70 + 1 >= k) {
                    func_L01_004450F0(m, 0x16, -1);
                }
            }
        }
        break;
    case 22:
        {
            S_003B3228 *s = &D_L27_002BBA00[p->w4C0[p->w498]];
            u8 *v;
            if (func_L01_004561B8(m) != 0) {
                if (m->anim2 != 0) {
                    func_003C3A10(m, 0, RND48(m), 8);
                }
                p->w4B0 = func_00382468(2) + 1;
                p->w4AC = s->w0;
                func_L22_003B8100(m);
            }
            if (m->h96 == 0x32) {
                func_L22_003B8100(m);
                if (p->w4B0 > 0) {
                    func_L01_0050FB40(10.0f, func_00382468(8) + 6, 0);
                    p->w4B0--;
                    m->h96 = FRAMES(func_00382498(0, 0x1E));
                } else {
                    func_L01_0050FB40(10.0f, 1, 0);
                }
            }
            v = PAD_003B3228;
            p->w49C++;
            if ((*(u32 *)(v + 0x1A0) & 0x40) && !(*(u32 *)(v + 0x1AC) & 0x40)) {
                func_L01_004450F0(m, 0x18, -1);
            }
        }
        break;
    case 25:
        {
            S_003B3228 *s = &D_L27_002BBA00[p->w4C0[p->w498]];
            u8 *v;
            if (func_L01_004561B8(m) != 0) {
                func_L01_0050FB40(10.0f, 1, 0);
                if (m->anim2 != 0) {
                    func_003C3A10(m, 0, RND48(m), 8);
                }
                p->w4AC = s->wC4;
                func_L22_003B8100(m);
            }
            v = PAD_003B3228;
            if ((*(u32 *)(v + 0x1A0) & 0x40) && !(*(u32 *)(v + 0x1AC) & 0x40)) {
                func_L01_004450F0(m, 0x1C, -1);
            }
        }
        break;
    case 23:
        {
            u8 *v;
            if (func_L01_004561B8(m) != 0) {
                p->w4B0 = func_00382468(2) + 1;
                func_L01_0050FB40(10.0f, func_00382498(0, 3) + 0xE, 0);
                if (m->anim2 != 0) {
                    func_003C3A10(m, 0, RND48(m), 8);
                }
                p->w4AC = func_00382498(0, 8) + 0xA28;
                func_L22_003B8100(m);
            } else {
                                if (((D_001A4BE0.wC08 & 2) && D_001A4BE0.m25C0->anim2 != 0) || ((m->b60 & 2) && m->anim2 != 0)) {
                    if (p->w4B0 >= 2) {
                        func_L01_0050FB40(10.0f, func_00382498(0, 3) + 0xE, 0);
                        p->w4B0--;
                    } else if (p->w4B0 == 1) {
                        func_L01_0050FB40(10.0f, 1, 0);
                        if (m->anim2 != func_00382498(0x13, 0x16)) {
                            func_003C3A10(m, func_00382498(0x13, 0x16), 0, 8);
                        }
                        p->w4B0--;
                    } else {
                        func_L01_0050FB40(10.0f, 1, 0);
                        if (m->anim2 != 0) {
                            func_003C3A10(m, 0, RND48(m), 8);
                        }
                    }
                }
            }
            v = PAD_003B3228;
            if ((*(u32 *)(v + 0x1A0) & 0x40) && !(*(u32 *)(v + 0x1AC) & 0x40)) {
                func_L01_004450F0(m, 0x1A, -1);
            }
        }
        break;
    case 26:
        {
            u8 *v;
            if (func_L01_004561B8(m) != 0) {
                func_L01_0050FB40(10.0f, 1, 0);
                if (m->anim2 != 0) {
                    func_003C3A10(m, 0, RND48(m), 8);
                }
                p->w4AC = 0x15F3;
                func_L22_003B8100(m);
                if ((p->w4A4 + 1) % 5 == 0 && p->w4C0[p->w498] < 4 && D_L27_002E8830[0] == 0
                    && D_L27_002E8830[9] == -1 && D_001CCFD0[0x1B] == 0 && D_001CCFD0[9] == D_L27_002E8830[9]
                    && D_001CCFD0[0x25] == 0) {
                    D_L27_002E8830[10] = 0x39;
                    D_L27_002E8830[9] = 0xB96;
                }
            }
            v = PAD_003B3228;
            if ((*(u32 *)(v + 0x1A0) & 0x40) && !(*(u32 *)(v + 0x1AC) & 0x40)) {
                func_L01_004450F0(m, 0x1B, -1);
            } else if ((*(u32 *)(v + 0x1A0) & 0x10) && !(*(u32 *)(v + 0x1AC) & 0x10)) {
                func_L01_004450F0(m, 0x1D, -1);
            }
        }
        break;
    case 24:
        {
            S_003B3228 *s = &D_L27_002BBA00[p->w4C0[p->w498]];
            s32 k;
            s32 t;
            s32 x;
            if (func_L01_004561B8(m) != 0) {
                func_L01_0050FB40(10.0f, 1, 0);
                p->w4AC = s->wC4;
                a = D_L27_001DEE00[p->w4BC].v30;
                d = m->pos;
                e = D_001A4C60;
                func_003C4098(0.25f, &c, &d, &e);
                c.z += 0.25f;
                qzero(&b);
                b.y = -func_0038D160(func_0038CF38(&a, &c), c.z - a.z);
                b.z = func_0038D160(c.x - a.x, c.y - a.y);
                func_L01_003EB350(0, &a);
                func_L01_003EB3C0(0, &b);
                p->w494 = 0;
                p->w49C = 0;
                func_L22_003B8100(m);
            }
            k = 0;
            n = ++p->w49C;
            {
                s32 dur = s->w148[p->w494];
                s32 val;
                t = s->w108[p->w494];
                val = s->wC8[p->w494];
                if (t <= n && n <= t + dur) {
                    k = val;
                } else if (t + dur < n) {
                    p->w494++;
                }
            }
            x = k ? k + 10 : 0;
            if (m->anim2 != x) {
                func_003C3A10(m, x, 0, 0xA);
            }
            if (m->h96 >= 0x65 && (*(u32 *)(PAD_003B3228 + 0x1A0) & 0x40)) {
                func_L01_004450F0(m, 0x1C, -1);
            }
        }
        break;
    case 27:
        if (func_L01_004561B8(m) != 0) {
            p->w4A4++;
            func_L01_0050FB40(17.0f, 1, 0);
            func_L22_003B8100(m);
        }
        if (p->w468 == 0 && p->w4A4 >= 5) {
            func_L01_004450F0(m, 0x1D, -1);
        } else {
            func_L01_004450F0(m, 0x15, -1);
        }
        break;
    case 28:
        if (func_L01_004561B8(m) != 0 && m->anim2 != 0) {
            func_003C3A10(m, 0, RND48(m), 8);
        }
        func_L01_0050FB40(17.0f, 1, 0);
        func_L22_003B8100(m);
        p->w4A4 = 0;
        if (++p->w498 < 8 && p->w4C0[p->w498] > 0) {
            func_L01_004450F0(m, 0x15, -1);
        } else {
            p->w4A0++;
            if (m->hB2 & 1) {
                u8 *q = &D_001BBE90[((s16)m->hB2 >> 1) + (D_001D545C_003B3228 << 10)];
                if (((*q >> 4) & 7) != 7) {
                    *q += 0x10;
                }
            } else {
                u8 *q = &D_001BBE90[((s16)m->hB2 >> 1) + (D_001D545C_003B3228 << 10)];
                if ((*q & 7) != 7) {
                    *q += 1;
                }
            }
            if (D_001D545C_003B3228 == 0x16) {
                if (m->hB2 & 1) {
                    u8 *q = &D_001BBE90[((s16)m->hB2 >> 1) + (D_001D545C_003B3228 << 10)];
                    if (((*q >> 4) & 7) != 7) {
                        *q += 0x10;
                    }
                } else {
                    u8 *q = &D_001BBE90[((s16)m->hB2 >> 1) + (D_001D545C_003B3228 << 10)];
                    if ((*q & 7) != 7) {
                        *q += 1;
                    }
                }
            }
            p->b3E = 1;
            if (p->w4A8 >= 0) {
                func_L01_00456230(D_L27_001DED1C + (p->w4A8 << 8), 1);
            }
            func_L01_004450F0(m, 0x1D, -1);
        }
        break;
    case 29:
        func_L22_003B6EE8(m, 0);
        break;
    case 6:
        if (func_L01_004561B8(m) != 0 && m->anim2 != 0) {
            func_003C3A10(m, 0, RND48(m), 5);
        }
        if (fabs_asm(p->f528 - m->fF8) < 0.08726646f) {
            S_003B3228 *s = &D_L27_002BBA00[p->w498];
            s32 k = 0;
            s32 t;
            s32 x;
            s32 fl;
            s32 st;
            n = ++p->w49C;
            {
                s32 dur = s->w84[p->w494];
                s32 val;
                t = s->w44[p->w494];
                val = s->w4[p->w494];
                if (t <= n && n <= t + dur) {
                    k = val;
                } else if (t + dur < n) {
                    p->w494++;
                }
            }
            if (!(1 < (u32)(D_L27_001D6694 - 1))) {
                k = 0;
            }
            x = k ? k + 10 : 0;
            st = D_001A4BE0.w25C4;
            fl = 0;
            if (st != 0x58) {
                fl = 1;
                if (st == 0x74) {
                    fl = 0;
                }
            }
            if (m->anim2 != x) {
                func_L01_00444F38(m, x, 0, 0xA, fl ? 0 : 0x10);
            }
            if (s->w4[p->w494] < 0 || (p->m47C != 0 && p->m47C->b95 != 1)) {
                func_L01_004450F0(m, 4, -1);
            }
        } else {
            func_L01_0045BD10(p->f528, m);
        }
        break;
    case 30:
        if (func_L01_004561B8(m) != 0 && m->anim2 != 3) {
            func_003C3A10(m, 3, RND54(m), 8);
        }
        if (func_L01_0045A748(m, &p->v510) == 0x80) {
            func_L01_004450F0(m, 0x1F, -1);
        }
        break;
    case 31:
        if (func_L01_004561B8(m) != 0 && m->anim2 != 3) {
            func_003C3A10(m, 3, RND54(m), 8);
        }
        if (fabs_asm(p->f528 - m->fF8) < 0.08726646f) {
            func_L01_004450F0(m, 0x21, -1);
        } else {
            func_L01_0045BD10(p->f528, m);
        }
        break;
    case 32:
        if (m->h96 >= 0x19) {
            func_L01_00456230(m, 1);
            func_L01_004450F0(m, 0x21, -1);
        }
        break;
    case 33:
        if (m->anim2 != 0) {
            func_003C3A10(m, 0, RND48(m), 7);
        }
        func_L01_0045A9F0(m);
        func_L01_004450F0(m, 4, 1);
        break;
    }
    {
        H_003B3228 *h = &D_001A4BE0;
        f32 f = func_0038D160(D_L27_001DEE00[p->w4B8].v30.x - m->pos.x, D_L27_001DEE00[p->w4B8].v30.y - m->pos.y);
        f32 g = func_0038D160(h->x80 - m->pos.x, h->y84 - m->pos.y);
        if ((u32)(m->b95 - 1) < 2 && p->w4C0[0] > 0 && p->w4A0 == 0 && h->m25C0 != 0
            && ((h->m25C0)->hAA == 0x173B || (h->m25C0)->hAA == 0x1A4E)) {
            if (func_0038DBA0(g, f) < 2.0943952f && func_0038CF38(&m->pos, &(h->m25C0)->pos) < 5.0f) {
                func_L01_00404808(func_L22_003B7150, m);
            }
        }
        if (m->b95 == 5) {
            func_L22_003B83A0(m);
        }
        func_L22_003B6B90(m);
    }
}
