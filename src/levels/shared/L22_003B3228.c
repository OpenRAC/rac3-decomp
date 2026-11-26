#include "common.h"

/* localdecomp:start func_L22_003B3228 */
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
typedef struct { s32 v[16]; } L_003B3228;

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
extern H_003B3228 D_001A4BE0_003B3228;
extern V4_003B3228 D_001A4C60;
typedef struct { u8 pad0[0x2AC]; u16 h2AC; u8 pad2AE[6]; s32 w2B4; } G_003B3228;
extern G_003B3228 D_001A7E18;
extern u8 D_001BBE90[];
extern s32 D_001CCFD0[];
extern s32 D_L22_002E79F0[];
extern S_003B3228 D_L22_002BA430[];
extern s32 D_L22_001E1FC0[2];
extern s32 D_L22_001E2000[2];
extern s32 D_L22_001E2040[2];
extern s32 D_L22_001DE528[2];
extern s32 D_001D545C_003B3228;
__asm__(".extern D_001D545C_003B3228, 16");
extern u8 *D_001D52FC_003B3228;
__asm__(".extern D_001D52FC_003B3228, 16");
extern M_003B3228 *D_001A71A0_003B3228;
__asm__(".extern D_001A71A0_003B3228, 16");
extern s32 D_001D6694;
__asm__(".extern D_001D6694, 16");
extern u8 *D_L22_001DFD9C;
__asm__(".extern D_L22_001DFD9C, 16");
extern R_003B3228 *D_L22_001DFE80;
__asm__(".extern D_L22_001DFE80, 16");
extern s32 D_L22_001E1FB8;
__asm__(".extern D_L22_001E1FB8, 16");
extern s32 D_L22_001E2080;
__asm__(".extern D_L22_001E2080, 16");
extern s32 D_L22_001E2084;
__asm__(".extern D_L22_001E2084, 16");
extern f32 D_L22_001E0F24;
__asm__(".extern D_L22_001E0F24, 16");
extern s32 D_L22_001E0F20;
__asm__(".extern D_L22_001E0F20, 16");

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
extern void func_L01_004028B0_003B3228(M_003B3228 *);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern void func_L01_00404808(void *, M_003B3228 *);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_0041A5B0(s32, s32);
extern void func_L01_0041A6E0(void);
extern f32 func_L01_004395E0(M_003B3228 *);
extern void func_L01_00444F38(M_003B3228 *, s32, s32, s32, s32);
extern void func_L01_004450F0(M_003B3228 *, s32, s32);
extern s32 func_L01_00446058(M_003B3228 *, s32, s32);
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
extern s32 func_L01_0045AA10(f32, M_003B3228 *);
extern void func_L01_0045AA30(M_003B3228 *, void *);
extern void func_L01_0045BD10(f32, M_003B3228 *);
extern void func_L01_0045BD78(f32, f32, f32, f32, M_003B3228 *);
extern s32 func_L01_0045BDE8(M_003B3228 *, s32);
extern void func_L01_0050FB40(f32, s32, s32);
extern s32 func_L01_00511A98(void);
extern void func_L02_003A5010_003B3228(M_003B3228 *);
extern f32 func_L05_00441508(f32, f32, f32);
extern s32 func_L22_003B5EF8(u8 *);
extern void func_L22_003B6B90(M_003B3228 *);
extern s32 func_L22_003B6D30(M_003B3228 *, M_003B3228 *);
extern void func_L22_003B6EE8(M_003B3228 *, s32);
extern void func_L22_003B7150(void);
extern s32 func_L22_003B71D0(M_003B3228 *, M_003B3228 *);
extern void func_L22_003B8100(M_003B3228 *);
extern void func_L22_003B83A0(M_003B3228 *);
extern void func_L22_0041FCC8(s32, s32);
extern void func_L01_005003D0_003B3228(s32, s32);


void func_L22_003B3228(M_003B3228 *m) {
    P_003B3228 *p = m->pv;
    V4_003B3228 vv[7];
    s32 n;

    if (func_L22_003B5EF8((u8 *)m) != 0) {
        func_L01_004028B0_003B3228(m);
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
        if (func_L01_00456250(D_L22_001DFD9C + (p->w470 << 8)) != 0) {
            func_L01_004450F0(m, 4, 1);
            if (m->anim2 != 0) {
                func_003C3A10(m, 0, func_00382468(m->cls->p48->b10), 8);
            }
        }
        break;
    case 1:
        if (func_L01_004561E0(m) != 0 && p->w458 == 0) {
            p->w458 = (func_00382498(0, 20) * 5 + 2) / 6;
        }
        if (p->h234 == 1 && func_0038CAD0(&p->w458) != 0 && D_001D545C_003B3228 != 0x16) {
            if (m->anim2 != 4) {
                func_003C3A10(m, 4, func_00382468(m->cls->p58->b10), 8);
            }
            func_L01_004450F0(m, 8, 3);
            if (p->w474 != -1) {
                func_L01_004450F0(m, 5, -1);
            }
        } else if (p->w45C != 0 && func_0038CAD0(&p->w458) != 0) {
            func_L01_004450F0(m, m->state, 2);
            p->w45C = 0;
            if (p->w450 < 0xFA) {
                p->w450 = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
            }
        }
        {
            s32 ok = 1;
            if (p->w534 != -1 && D_001D545C_003B3228 == 0x16) {
                if (*(s32 *)(*(u8 **)(D_L22_001DFD9C + (p->w534 << 8) + 0x68) + 0x130) != 0) {
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
                func_003C3A10(m, 4, func_00382468(m->cls->p58->b10), 8);
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
            p->w450 = (func_00382498(0x30C, 0x384) * 5 + 2) / 6;
        }
        break;
    case 4:
        {
            s32 r = func_L01_00454370(m, (u8 *)p + 0x160);
            if (r & 1) {
                func_L02_003A5010_003B3228(m);
                func_L01_00315900(m, 0, func_L01_004028B0_003B3228);
                return;
            }
            if (r & 2) {
                if (p->h234 == 1) {
                    func_L01_004450F0(m, 8, 3);
                } else {
                    func_L01_004450F0(m, 7, 2);
                    p->w450 = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
                }
            }
        }
        break;
    case 5:
            {
            if (p->h234 == 1 || D_001A4BE0_003B3228.m25C0 == 0
                || (D_001A4BE0_003B3228.m25C0->hAA != 0x173B && D_001A4BE0_003B3228.m25C0->hAA != 0x1A4E)
                || (D_001A4BE0_003B3228.w25C4 == 0x52 && m->state >= 0x15)) {
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
                func_003C3A10(m, 0, func_00382468(m->cls->p48->b10), 8);
            }
        }
        func_L01_0045AA10(m->fF8, m);
        if (m->anim == m->anim2 && (m->b60 & 2)) {
                {
                if (p->m230 != 0 && (D_001A4BE0_003B3228.m25C0 == 0
                    || (D_001A4BE0_003B3228.m25C0->hAA != 0x173B && D_001A4BE0_003B3228.m25C0->hAA != 0x1A4E))) {
                    s32 x;
                    func_00382468(2);
                    x = func_00382468(2) ? 1 : 2;
                    func_003C3A10(m, x, 0, (func_00382498(6, 12) * 5 + 2) / 6);
                } else if (m->anim2 != 0) {
                    func_003C3A10(m, 0, func_00382468(m->cls->p48->b10), 8);
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
                func_0038CF68(&vv[2], &m->vel, 0.0f);
                vec_add_ba(&vv[0], &m->pos, &vv[2]);
            }
            if (t > 2.0f) {
                func_003C41A0(&vv[0].z, p->f4E8 + 1.2f, 0.112500004f, 0.1875f, 0.075f, &p->w440);
            }
            if (t > 2.0f && t < 10.0f) {
                vec_sub_ab(&vv[1], &vv[0], &m->pos);
                func_L01_0045AA30(m, &vv[1]);
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
                func_0038CF68(&vv[2], &m->vel, 0.0f);
                vec_add_ba(&vv[0], &m->pos, &vv[2]);
            }
            if (t < 15.0f) {
                func_L01_0045BD10(func_0038D160(p->v220.x - m->pos.x, p->v220.y - m->pos.y), m);
                func_003C41A0(&vv[0].z, func_003C3D30(0.5f, &m->pos, 0, 0), 0.060000002f, 0.50000006f, 0.060000002f, &p->w440);
            }
            if (t < 22.0f) {
                vec_sub_ab(&vv[1], &vv[0], &m->pos);
                func_L01_0045AA30(m, &vv[1]);
            }
            if (m->b60 & 2) {
                p->w440 = 0;
                func_L01_004450F0(m, 8, -1);
                if (m->anim2 != 4) {
                    func_003C3A10(m, 4, func_00382468(m->cls->p58->b10), 7);
                }
            }
        }
        break;
    case 5:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(0.0032000002f, 0.050000004f, 0.010053097f, 0.25132743f, m);
        }
        func_L01_0045BD78(0.0032000002f, 0.050000004f, 0.010053097f, 0.25132743f, m);
        if (func_L01_0045BDE8(m, p->w474) != 0 || func_0038CF38(&m->pos, &p->v220) < 6.0f) {
            func_L01_004450F0(m, 8, -1);
        }
        break;
    case 8:
        {
            V4_003B3228 *tgt;
            if (func_L01_004561B8(m) != 0) {
                func_L01_0045BD78(0.0032000002f, 0.050000004f, 0.010053097f, 0.25132743f, m);
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
                func_0038CF68(&vv[2], &m->vel, 0.09375f);
                vec_add_ba(&vv[0], &m->pos, &vv[2]);
            }
            if (t > 5.0f) {
                vv[2] = m->pos;
                if (p->b5F != 0) {
                    func_L01_004468C8(0.5f, 1.0f, 0.75f, m, 1, 0x10000, 0, 1, 0);
                } else {
                    func_L01_004468C8(0.5f, 1.0f, 0.75f, m, 1, 1, 0, 1, 0);
                }
                func_003C41A0(&vv[0].z, p->f4E8 + 0.6f, 0.112500004f, 0.1875f, 0.075f, &p->w440);
            }
            if (t > 2.0f && t < 10.0f) {
                vec_sub_ab(&vv[1], &vv[0], &m->pos);
                func_L01_0045AA30(m, &vv[1]);
            } else {
                func_L01_0045AA10(m->fF8, m);
            }
        } else {
            func_L01_0045AA10(m->fF8, m);
        }
        if (m->b60 & 2) {
            p->w440 = 0;
                {
                if (D_001A4BE0_003B3228.m2808 == m) {
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
                func_0038CF68(&vv[2], &m->vel, p->f444);
                vec_add_ba(&vv[0], &m->pos, &vv[2]);
            }
            if (t < 15.0f) {
                func_003C41A0(&vv[0].z, func_003C3D30(0.5f, &m->pos, 0, 0), 0.060000002f, 0.50000006f, 0.060000002f, &p->w440);
            }
            if (t < 22.0f) {
                vec_sub_ab(&vv[1], &vv[0], &m->pos);
                func_L01_0045AA30(m, &vv[1]);
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
                func_0038CF68(&vv[2], &m->vel, 0.0f);
                vec_add_ba(&vv[0], &m->pos, &vv[2]);
            }
            if (t < 7.0f) {
                func_003C41A0(&vv[0].z, func_003C3D30(0.5f, &m->pos, 0, 0), 0.028571429f, 0.12857144f, 0.057142857f, &p->w440);
            }
            if (t < 7.0f) {
                vec_sub_ab(&vv[1], &vv[0], &m->pos);
                func_L01_0045AA30(m, &vv[1]);
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
                    func_0038CF68(&vv[2], &m->vel, -0.084375f);
                    vec_add_ba(&vv[0], &m->pos, &vv[2]);
                }
            }
            if (t > 2.0f && t < 12.0f) {
                func_003C41A0(&vv[0].z, p->f4E8 + 1.0f, 0.1f, 0.2f, 0.1f, &p->w440);
            }
            if (t == 12.0f) {
                p->w440 = 0;
            }
            if (t > 12.0f && t < 18.0f) {
                func_003C41A0(&vv[0].z, func_003C3D30(0.5f, &m->pos, 0, 0), 0.027777778f, 0.33333334f, 0.25f, &p->w440);
            }
            if (t > 2.0f && t < 18.0f) {
                vec_sub_ab(&vv[1], &vv[0], &m->pos);
                func_L01_0045AA30(m, &vv[1]);
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
                func_003C3A10(m, 4, func_00382468(m->cls->p58->b10), 5);
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
                if ((p->w458 != 0 && m->h96 == p->w458) || D_001A4BE0_003B3228.f174 > 0.040000003f) {
                    if (m->anim2 != 4) {
                        func_003C3A10(m, 4, func_00382468(m->cls->p58->b10), 5);
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
                if (p->h234 == 1 && ((p->w458 != 0 && m->h96 == p->w458) || D_001A4BE0_003B3228.f174 > 0.040000003f)) {
                    if (m->anim2 != 4) {
                        func_003C3A10(m, 4, func_00382468(m->cls->p58->b10), 5);
                    }
                    func_L01_004450F0(m, 8, -1);
                }
            }
        }
        if (m->b60 & 2) {
            if (m->anim2 != 0) {
                func_003C3A10(m, 0, func_00382468(m->cls->p48->b10), 7);
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
                    func_003C3A10(m, 3, func_00382468(m->cls->p54->b10), 8);
                }
            } else if (m->anim2 != 0) {
                func_003C3A10(m, 0, func_00382468(m->cls->p48->b10), 8);
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
                func_003C3A10(m, 0, func_00382468(m->cls->p48->b10), 7);
                func_L22_003B6EE8(m, 1);
                func_L01_004450F0(m, 0x14, -1);
            }
        } else if (m->anim2 == 0x17 && m->anim == m->anim2 && (m->b60 & 2)) {
            func_003C3A10(m, 0, func_00382468(m->cls->p48->b10), 7);
            func_L01_004450F0(m, 4, 1);
        }
        break;
    case 20:
        {
            s32 cnt;
            u32 v;
            vv[0] = D_L22_001DFE80[p->w4B4].v30;
            cnt = 1;
            vv[1] = D_L22_001DFE80[p->w4B8].v30;
            if ((D_001A7E18.w2B4 & (cnt << D_001D545C_003B3228)) == 0) {
                func_L01_0041A5B0(0xB96, 0x39);
            }
            {
                f32 off = D_L22_001E0F24 * -80.0f + 0.5f;
                f32 z = 0.0f;
                if (D_L22_001E0F20 != 0) {
                    off = off + z;
                } else {
                    off = off + z;
                }
                func_L22_0041FCC8(off, 1);
            }
            if (func_L01_004561B8(m) != 0) {
                p->w4AC = 0;
                p->w4A4 = 0;
                break;
            }
            cnt = 0;
            if (m->anim2 == 0x17) {
                if (m->anim == m->anim2 && (m->b60 & 2)) {
                    func_003C3A10(m, 0, func_00382468(m->cls->p48->b10), 7);
                }
            } else if (func_L01_0040E570(&vv[0], &m->pos) < 0.1f) {
                R_003B3228 *r = D_L22_001DFE80;
                f32 f;
                vv[2] = r[p->w4B4].v30;
                vv[3] = r[p->w4B8].v30;
                vv[4] = r[p->w4BC].v30;
                f = func_0038D160(vv[3].x - vv[2].x, vv[3].y - vv[2].y);
                f = func_L05_00441508(f, func_0038D160(vv[4].x - vv[2].x, vv[4].y - vv[2].y), 0.25f);
                if (m->anim2 != 0) {
                    func_003C3A10(m, 0, func_00382468(m->cls->p48->b10), 7);
                }
                func_L01_0045AA10(f, m);
                cnt = 1;
            } else {
                if (m->anim2 != 3) {
                    func_003C3A10(m, 3, func_00382468(m->cls->p54->b10), 7);
                }
                func_L01_0045A748(m, &vv[0]);
            }
                {
                if (D_001A4BE0_003B3228.w25C4 == 0x58) {
                    cnt++;
                } else if (func_L01_00511A98() == 2) {
                    func_L01_005003D0_003B3228(0x58, 1);
                }
            }
            v = *(u32 *)(D_001D52FC_003B3228 + 0x1A0);
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
            S_003B3228 *s = &D_L22_002BA430[p->w4C0[p->w498]];
            if (func_L01_004561B8(m) != 0) {
                vv[0] = D_L22_001DFE80[p->w4BC].v30;
                vv[3] = m->pos;
                vv[4] = D_001A4C60;
                func_003C4098(0.75f, &vv[2], &vv[3], &vv[4]);
                vv[2].z += 0.25f;
                qzero(&vv[1]);
                vv[1].y = -func_0038D160(func_0038CF38(&vv[0], &vv[2]), vv[2].z - vv[0].z);
                vv[1].z = func_0038D160(vv[2].x - vv[0].x, vv[2].y - vv[0].y);
                func_L01_003EB350(0, &vv[0]);
                func_L01_003EB3C0(0, &vv[1]);
                p->w490 = 0;
                p->w49C = -100;
                p->w484 = 1;
                D_L22_001E2084 = -1;
                D_L22_001E1FB8 = -1;
                D_L22_001E2080 = -1;
                func_L22_003B8100(m);
            }
            if (++p->w49C >= -24) {
                s32 r = func_L22_003B71D0(m, p->m230);
                s32 nw = r;
                s32 k;
                if (r >= 0 && D_L22_001E2080 <= 0 && D_L22_001E1FB8 >= 0) {
                    if (p->w49C < D_L22_001E2000[D_L22_001E1FB8] + 8) {
                        s32 t = D_L22_001E2080;
                        nw = t;
                    }
                }
                if (nw != D_L22_001E2080) {
                    if (nw > 0) {
                        s32 i = D_L22_001E1FB8 + 1;
                        p->w480 = 1;
                        D_L22_001E1FC0[i] = p->w49C;
                        D_L22_001E2000[i] = p->w49C;
                        D_L22_001E2040[i] = nw;
                        D_L22_001E1FB8 = i;
                        if (s->w84[i] == 0) {
                            if (nw == s->w4[i]) {
                                func_003A52A0(D_L22_001DE528[nw - 1], 0, m);
                            }
                        }
                    } else if (s->w84[D_L22_001E1FB8] > 0) {
                        if (D_L22_001E2080 > 0) {
                            func_003A52A0(D_L22_001DE528[D_L22_001E2080 - 1], 0, m);
                        }
                    }
                    D_L22_001E2080 = nw;
                } else if (nw > 0 && s->w84[D_L22_001E1FB8] != 0) {
                    D_L22_001E2000[D_L22_001E1FB8] = p->w49C;
                }
                k = 0;
                if (s->w4[0] > 0) {
                    do {
                        if (D_L22_001E1FB8 < k) {
                            D_L22_001E2084 = (s->w44[k] < p->w49C - 10) ? k : D_L22_001E2084;
                        } else {
                            s32 c0 = D_L22_001E1FC0[k];
                            s32 t2 = D_L22_001E2000[k];
                            L_003B3228 *w = (L_003B3228 *)s->w44;
                            if (c0 + 10 < *(s32 *)((u8 *)s + 0x44 + k * 4)) {
                                D_L22_001E2084 = k;
                            }
                            if (t2 != p->w49C) {
                                if (t2 + 10 < s->w44[k] + s->w84[k]) {
                                    D_L22_001E2084 = k;
                                }
                            }
                            if (D_L22_001E2000[k] - 10 > w->v[k] + *(s32 *)((u8 *)s + 0x84 + k * 4)) {
                                D_L22_001E2084 = k;
                            }
                            if (D_L22_001E2040[k] != s->w4[k]) {
                                D_L22_001E2084 = k;
                            }
                        }
                        k++;
                    } while (s->w4[k] > 0);
                }
                if (D_L22_001E2084 >= 0) {
                    func_003A52A0(0x24, 0, m);
                    func_L01_004450F0(m, 0x17, -1);
                } else if (D_L22_001E2080 == 0 && D_L22_001E1FB8 + 1 >= k) {
                    func_L01_004450F0(m, 0x16, -1);
                }
            }
        }
        break;
    case 22:
        {
            S_003B3228 *s = &D_L22_002BA430[p->w4C0[p->w498]];
            u8 *v;
            if (func_L01_004561B8(m) != 0) {
                if (m->anim2 != 0) {
                    func_003C3A10(m, 0, func_00382468(m->cls->p48->b10), 8);
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
                    m->h96 = (func_00382498(0, 0x1E) * 5 + 2) / 6;
                } else {
                    func_L01_0050FB40(10.0f, 1, 0);
                }
            }
            v = D_001D52FC_003B3228;
            p->w49C++;
            if ((*(u32 *)(v + 0x1A0) & 0x40) && !(*(u32 *)(v + 0x1AC) & 0x40)) {
                func_L01_004450F0(m, 0x18, -1);
            }
        }
        break;
    case 25:
        {
            S_003B3228 *s = &D_L22_002BA430[p->w4C0[p->w498]];
            u8 *v;
            if (func_L01_004561B8(m) != 0) {
                func_L01_0050FB40(10.0f, 1, 0);
                if (m->anim2 != 0) {
                    func_003C3A10(m, 0, func_00382468(m->cls->p48->b10), 8);
                }
                p->w4AC = s->wC4;
                func_L22_003B8100(m);
            }
            v = D_001D52FC_003B3228;
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
                    func_003C3A10(m, 0, func_00382468(m->cls->p48->b10), 8);
                }
                p->w4AC = func_00382498(0, 8) + 0xA28;
                func_L22_003B8100(m);
            } else {
                                if (((D_001A4BE0_003B3228.wC08 & 2) && D_001A4BE0_003B3228.m25C0->anim2 != 0) || ((m->b60 & 2) && m->anim2 != 0)) {
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
                            func_003C3A10(m, 0, func_00382468(m->cls->p48->b10), 8);
                        }
                    }
                }
            }
            v = D_001D52FC_003B3228;
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
                    func_003C3A10(m, 0, func_00382468(m->cls->p48->b10), 8);
                }
                p->w4AC = 0x15F3;
                func_L22_003B8100(m);
                if ((p->w4A4 + 1) % 5 == 0 && p->w4C0[p->w498] < 4 && D_L22_002E79F0[0] == 0
                    && D_L22_002E79F0[9] == -1 && D_001CCFD0[0x1B] == 0 && D_001CCFD0[9] == D_L22_002E79F0[9]
                    && D_001CCFD0[0x25] == 0) {
                    D_L22_002E79F0[9] = 0xB96;
                    D_L22_002E79F0[10] = 0x39;
                }
            }
            if ((*(u32 *)(D_001D52FC_003B3228 + 0x1A0) & 0x40) && !(*(u32 *)(D_001D52FC_003B3228 + 0x1AC) & 0x40)) {
                func_L01_004450F0(m, 0x1B, -1);
            } else if ((*(u32 *)(D_001D52FC_003B3228 + 0x1A0) & 0x10) && !(*(u32 *)(D_001D52FC_003B3228 + 0x1AC) & 0x10)) {
                func_L01_004450F0(m, 0x1D, -1);
            }
        }
        break;
    case 24:
        {
            S_003B3228 *s = &D_L22_002BA430[p->w4C0[p->w498]];
            s32 k;
            s32 t;
            s32 x;
            if (func_L01_004561B8(m) != 0) {
                func_L01_0050FB40(10.0f, 1, 0);
                p->w4AC = s->wC4;
                vv[0] = D_L22_001DFE80[p->w4BC].v30;
                vv[3] = m->pos;
                vv[4] = D_001A4C60;
                func_003C4098(0.25f, &vv[2], &vv[3], &vv[4]);
                vv[2].z += 0.25f;
                qzero(&vv[1]);
                vv[1].y = -func_0038D160(func_0038CF38(&vv[0], &vv[2]), vv[2].z - vv[0].z);
                vv[1].z = func_0038D160(vv[2].x - vv[0].x, vv[2].y - vv[0].y);
                func_L01_003EB350(0, &vv[0]);
                func_L01_003EB3C0(0, &vv[1]);
                p->w494 = 0;
                p->w49C = 0;
                func_L22_003B8100(m);
            }
            k = 0;
            n = p->w49C + 1;
            p->w49C = n;
            {
                s32 dur = s->w148[p->w494];
                s32 val;
                s32 end;
                t = s->w108[p->w494];
                val = s->wC8[p->w494];
                end = t + dur;
                if (t <= n && n <= end) {
                    k = val;
                } else if (end < n) {
                    p->w494++;
                }
            }
            x = 0;
            if (k) {
                x = k + 10;
            }
            if (m->anim2 != x) {
                func_003C3A10(m, x, 0, 0xA);
            }
            if (m->h96 >= 0x65 && (*(u32 *)(D_001D52FC_003B3228 + 0x1A0) & 0x40)) {
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
            func_003C3A10(m, 0, func_00382468(m->cls->p48->b10), 8);
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
                func_L01_00456230(D_L22_001DFD9C + (p->w4A8 << 8), 1);
            }
            func_L01_004450F0(m, 0x1D, -1);
        }
        break;
    case 29:
        func_L22_003B6EE8(m, 0);
        break;
    case 6:
        if (func_L01_004561B8(m) != 0 && m->anim2 != 0) {
            func_003C3A10(m, 0, func_00382468(m->cls->p48->b10), 5);
        }
        if (fabs_asm(p->f528 - m->fF8) < 0.08726646f) {
            S_003B3228 *s = &D_L22_002BA430[p->w498];
            s32 k = 0;
            s32 t;
            s32 x;
            s32 fl;
            s32 st;
            n = p->w49C + 1;
            p->w49C = n;
            {
                s32 dur = s->w84[p->w494];
                s32 val;
                s32 end;
                t = s->w44[p->w494];
                val = s->w4[p->w494];
                end = t + dur;
                if (t <= n && n <= end) {
                    k = val;
                } else if (end < n) {
                    p->w494++;
                }
            }
            if (!(1 < (u32)(D_001D6694 - 1))) {
                k = 0;
            }
            x = 0;
            if (k) {
                x = k + 10;
            }
            st = D_001A4BE0_003B3228.w25C4;
            fl = 0;
            if (st != 0x58) {
                if (st != 0x74) {
                    fl = 1;
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
            func_003C3A10(m, 3, func_00382468(m->cls->p54->b10), 8);
        }
        if (func_L01_0045A748(m, &p->v510) == 0x80) {
            func_L01_004450F0(m, 0x1F, -1);
        }
        break;
    case 31:
        if (func_L01_004561B8(m) != 0 && m->anim2 != 3) {
            func_003C3A10(m, 3, func_00382468(m->cls->p54->b10), 8);
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
            func_003C3A10(m, 0, func_00382468(m->cls->p48->b10), 7);
        }
        func_L01_0045A9F0(m);
        func_L01_004450F0(m, 4, 1);
        break;
    }
    {
        H_003B3228 *h = &D_001A4BE0_003B3228;
        f32 f = func_0038D160(D_L22_001DFE80[p->w4B8].v30.x - m->pos.x, D_L22_001DFE80[p->w4B8].v30.y - m->pos.y);
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
/* localdecomp:end func_L22_003B3228 */

/* localdecomp:start func_L22_003B5EF8 */
#include "vu0.h"

typedef int Q_003B5EF8 __attribute__((mode(TI)));
typedef union {
    Q_003B5EF8 q;
    f32 f[4];
} V_003B5EF8;
typedef struct { u8 pad[0x464]; u8 spent[1]; } S_003B5EF8;
typedef struct { V_003B5EF8 r[4]; } M_003B5EF8;
typedef struct { u8 pad[0x4A0]; s32 n4A0; } P_003B5EF8;

extern s32 func_L22_003B6698(u8 *);
extern void func_L03_0043BE98(void *, void *, s32, s32, s32);
extern s32 func_L01_00452860(void *, void *, s32);
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_L22_003B72F0(u8 *, V_003B5EF8 *, s32, f32);
extern void func_L01_0044FD88(void *, void *, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D570(void *, void *);
extern void func_0038D328(void *, void *);
extern void func_0038D640(void *, void *, void *);
extern void func_0038D590(void *, void *);
extern s32 func_L01_00452F78(void *, s32, s32, s32);
extern void func_L22_003B6C58_003B5EF8(u8 *);
extern void func_L02_003A5010(s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

extern S_003B5EF8 D_L22_00236640_003B5EF8;
extern u8 D_001BBE90[];
typedef struct { u8 pad[0x80]; f32 x; f32 y; } H_003B5EF8;
extern H_003B5EF8 D_001A4BE0;
extern s32 D_001D545C;
extern s32 D_L22_001DF8C0;
extern u8 *D_L22_001DFD9C;
extern s32 D_L22_001E9858[];
extern V_003B5EF8 D_L22_001DE460 __attribute__((section(".sdata")));
__asm__(".extern D_L22_001DE460, 4");
extern V_003B5EF8 D_L22_001DE470 __attribute__((section(".sdata")));
__asm__(".extern D_L22_001DE470, 4");

s32 func_L22_003B5EF8(u8 *m) {
    u8 *p;
    u8 *q;
    u16 id;
    u16 id3;
    u16 id4;
    s32 b;
    s32 was;

    p = *(u8 **)(m + 0x68);
    if (m[0x20] == 0 && func_L22_003B6698(m)) {
        return 1;
    }
    func_L03_0043BE98(m, p + 0x240, 0, 4, m[0x20] != 6);
    id = *(u16 *)(m + 0xB2);
    if (!D_L22_00236640_003B5EF8.spent[(s16)id]) {
        b = D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)];
        if (!(((id & 1) ? b >> 4 : b) & 7) && D_001D545C != 22) {
            func_L01_00452860(m, p + 0x30, 0);
        }
    }
    if (((P_003B5EF8 *)p)->n4A0 > 0 && *(s32 *)(p + 0x464) != -1 && m[0x95] == 1
        && (D_L22_001DF8C0 & 0x1F) == (((s32)m >> 8) & 0x1F)) {
        q = D_L22_001DFD9C + (*(s32 *)(p + 0x464) << 8);
        if (func_L01_0040E570(m + 0x10, q + 0x10) > 0.1f) {
            V_003B5EF8 v;
            v = *(V_003B5EF8 *)(q + 0x10);
            func_L22_003B72F0(m, &v, 1, func_0038D160(D_001A4BE0.x - *(f32 *)(q + 0x10),
                                                      D_001A4BE0.y - *(f32 *)(q + 0x14)));
        }
        if (*(s32 *)(p + 0x530)) {
            u16 k = *(u16 *)(m + 0xB2);
            if (k & 1) {
                u8 *c = &D_001BBE90[((s16)k >> 1) + (D_001D545C << 10)];
                if (((*c >> 4) & 7) != 7) {
                    *c += 0x10;
                }
            } else {
                u8 *c = &D_001BBE90[((s16)k >> 1) + (D_001D545C << 10)];
                if ((*c & 7) != 7) {
                    *c += 1;
                }
            }
        }
    }
    if (*(s32 *)(p + 0x530)) {
        id = *(u16 *)(m + 0xB2);
        if (D_L22_00236640_003B5EF8.spent[(s16)id]
            || (b = D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)], ((id & 1) ? b >> 4 : b) & 7)) {
            if (m[0x95] == 1) {
                ((P_003B5EF8 *)p)->n4A0++;
                q = D_L22_001DFD9C + (*(s32 *)(p + 0x464) << 8);
                if (func_L01_0040E570(m + 0x10, q + 0x10) > 0.1f) {
                    V_003B5EF8 v;
                    v = *(V_003B5EF8 *)(q + 0x10);
                    func_L22_003B72F0(m, &v, 1, func_0038D160(D_001A4BE0.x - *(f32 *)(q + 0x10),
                                                              D_001A4BE0.y - *(f32 *)(q + 0x14)));
                }
            }
        }
    }
    if (*(u8 **)(p + 0x48C)) {
        func_L01_0044FD88(m, *(u8 **)(p + 0x48C), 3, 0);
        {
            V_003B5EF8 v;
            M_003B5EF8 m2;
            M_003B5EF8 m3;

            func_0038CE20(&v, *(u8 **)(p + 0x48C) + 0xC0, D_L22_001DE460.f[0]);
            vec_add_ba(*(u8 **)(p + 0x48C) + 0x10, *(u8 **)(p + 0x48C) + 0x10, &v);
            func_0038CE20(&v, *(u8 **)(p + 0x48C) + 0xD0, D_L22_001DE460.f[1]);
            vec_add_ba(*(u8 **)(p + 0x48C) + 0x10, *(u8 **)(p + 0x48C) + 0x10, &v);
            func_0038CE20(&v, *(u8 **)(p + 0x48C) + 0xE0, D_L22_001DE460.f[2]);
            vec_add_ba(*(u8 **)(p + 0x48C) + 0x10, *(u8 **)(p + 0x48C) + 0x10, &v);
            func_0038D570(&m2, *(u8 **)(p + 0x48C) + 0xC0);
            func_0038D328(&m3, &D_L22_001DE470);
            func_0038D640(&m2, &m2, &m3);
            func_0038D590(*(u8 **)(p + 0x48C) + 0xC0, &m2);
        }
    }
    if (D_001D545C != 22 || (*(s32 *)(p + 0x53C)
        && (D_L22_00236640_003B5EF8.spent[(s16)(id3 = *(u16 *)(m + 0xB2))]
            || (b = D_001BBE90[((s16)id3 >> 1) + (D_001D545C << 10)], ((id3 & 1) ? b >> 4 : b) & 7)))) {
        if (func_L01_00452F78(m, 0, 0, 0)) {
            func_L22_003B6C58_003B5EF8(m);
        }
    }
    if (D_001D545C == 22) {
        id4 = *(u16 *)(m + 0xB2);
        if (!D_L22_00236640_003B5EF8.spent[(s16)id4]) {
            b = D_001BBE90[((s16)id4 >> 1) + (D_001D545C << 10)];
            if (!(((id4 & 1) ? b >> 4 : b) & 7)) {
                m[0xA8] = 0xFF;
            }
        }
    }
    if (p[0x3E] == 2 || p[0x5E] || p[0x60]) {
        func_L02_003A5010((s32)m);
        return 1;
    }
    if (p[0x5F]) {
        func_L01_00456BD0(m, 5);
    } else if (*(f32 *)(p + 0x30) > 0.0f) {
        func_L01_00456BD0(m, 3);
    }
    if ((*(s16 *)(m + 0xB2) + 8) % 8 != D_L22_001DF8C0 % 8) {
        return 0;
    }
    was = *(s16 *)(p + 0x234) == 1;
    if (p[0x5F]) {
        if (m[0x95] == 1) {
            func_L01_00456C98(m, *(s32 *)(p + 0x430), (s32)(p + 0x4F0), 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x434), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(m, *(s32 *)(p + 0x438), (s32)(p + 0x4F0), 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x43C), 10.0f, 1.0f);
        }
    } else {
        if (m[0x95] == 1) {
            func_L01_00456C98(m, *(s32 *)(p + 0x430), (s32)(p + 0x4F0), 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x434), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(m, *(s32 *)(p + 0x438), (s32)(p + 0x4F0), 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x43C), 10.0f, 1.0f);
        }
    }
    if (*(s16 *)(p + 0x234) == 1 && !was) {
        V_003B5EF8 a;
        V_003B5EF8 to;

        a = *(V_003B5EF8 *)(m + 0x10);
        a.f[2] += 1.0f;
        to = *(V_003B5EF8 *)(p + 0x220);
        to.f[2] += 1.0f;
        if (func_003D3CB0(&a, &to, 0, m, 0) && D_L22_001E9858[0] != *(s32 *)(p + 0x230)) {
            *(s16 *)(p + 0x234) = 0;
        }
    }
    return 0;
}
/* localdecomp:end func_L22_003B5EF8 */
