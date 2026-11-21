#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003A8050;
typedef struct {
    u8 pad0[0x10];
    s32 w10;
    u8 pad14[0x10];
    f32 f24;
    u8 pad28[0x1C];
    u16 h44;
} C_003A8050;
typedef struct P_003A8050 {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[0xE];
    u8 b44;
    u8 b45;
    u8 b46;
    u8 pad47[0x69];
    V4_003A8050 vB0;
    s32 wC0;
    s16 hC4;
    u8 padC6[0xA];
    V4_003A8050 vD0;
    u8 padE0;
    u8 bE1;
    u8 bE2;
    u8 padE3[0x25];
    s16 h108;
    u8 pad10A[0x9A];
    f32 f1A4;
    f32 f1A8;
    f32 f1AC;
    u8 pad1B0[0x18];
    s32 w1C8;
    u8 pad1CC[0x64];
    V4_003A8050 v230;
    s32 w240;
    f32 v244[4];
    u8 pad254[0xAC];
    s8 b300;
    s8 b301;
    u8 pad302[4];
    s16 h306;
    f32 f308;
    s16 h30C;
    u8 pad30E[0xA];
    f32 f318;
} P_003A8050;
typedef struct M_003A8050 {
    u8 pad0[0x10];
    V4_003A8050 pos;
    u8 state;
    u8 pad21[2];
    u8 b23;
    C_003A8050 *cls;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[4];
    u16 h34;
    u8 pad36[0xD];
    u8 anim;
    u8 pad44[4];
    f32 f48;
    u8 pad4C[0x14];
    u8 b60;
    u8 pad61[7];
    P_003A8050 *pv;
    u8 pad6C[0x28];
    u8 b94;
    u8 b95;
    u8 pad96[2];
    s32 w98;
    u8 pad9C[0xC];
    u8 bA8;
    u8 padA9[0xF];
    s32 wB8;
    u8 padBC[4];
    V4_003A8050 vC0;
    V4_003A8050 vD0;
    u8 padE0[0x18];
    f32 fF8;
} M_003A8050;
typedef struct {
    u8 pad0[0x25C0];
    M_003A8050 *m25C0;
    u8 pad25C4[0x28C];
    s32 w2850;
} H_003A8050;
typedef struct { s32 w0; s32 w4; s32 w8; } G_003A8050;

typedef struct S_003A80D0 {
    u8 pad00[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[0xD0 - 0x36];
    u8 bD0[0x11];
    u8 bE1;
    u8 bE2;
    u8 padE3[0x280 - 0xE3];
    u8 b280[0x84];
    s16 h304;
    u8 pad306[8];
    s16 h30E;
} S_003A80D0;
typedef struct T_003A80D0 {
    u8 pad00[0x20];
    s32 w20;
    u8 pad24[8];
    f32 f2C;
} T_003A80D0;

/* localdecomp:start func_L21_003A8050 */
#include "vu0.h"

extern H_003A8050 D_001A4BE0;

extern G_003A8050 D_00142660;
extern s32 D_001A7430[];
extern M_003A8050 *D_001A71A0[];
extern V4_003A8050 D_001D66B0;
extern f32 D_L21_001DCF40;
__asm__(".extern D_L21_001DCF40, 16");
extern f32 D_L21_001DCF44;
__asm__(".extern D_L21_001DCF44, 16");
extern s32 D_L21_001EC4C0[];
extern s32 D_001D6694;
extern s32 D_L21_001E1030;
__asm__(".extern D_L21_001E1030, 4");
extern s32 D_L21_001E1034;
__asm__(".extern D_L21_001E1034, 4");

extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern s32 func_0038CB00(void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_00404A10(void *, void *);
extern f32 func_L01_004395E0(void *);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_004443E8(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00445170(void *, s32);
extern s32 func_L01_004468C8(void *, s32, f32, s32, f32, f32, s32, s32, s32);
extern s32 func_L01_00448070(s32, s32, f32);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern s32 func_L01_0044E1B8(f32, void *);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_004561E0(void *);
extern void func_L01_0045A748(void *, void *);
extern void func_L01_0045A7A8(f32, void *, void *);
extern void func_L01_0045AA30(void *, void *);
extern void func_L01_0045BD78(f32, f32, f32, f32, void *);
extern void func_L01_0046C470(void *, void *, s32, s32, f32, s32, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L01_004BA800(void);
extern void func_L21_00339190(void *, void *, s32);
extern s32 func_L21_00339248(s32);
extern s32 func_L21_00339258(s32, s32, s32);
extern void func_L21_003392E0(s32);
extern s32 func_L21_003393C0(s32);
extern s32 func_L21_003A97E8(u8 *arg0);
extern void func_L21_003A9B20(void *o_);
extern void func_L21_003A9E88(u8 *);
extern s32 func_L21_003AA068(void *);
extern void func_L21_003B1118(void *, s32, void *, void *, f32, f32);
extern void func_L21_003B1518(void *, s32, void *, void *, f32, f32);
extern void func_L21_003B1A00(void *, void *, f32, f32);

#define FRAMES(x) (((x) * 5 + 2) / 6)

void func_L21_003A8050(M_003A8050 *m) {
    V4_003A8050 pos0;
    V4_003A8050 a;
    V4_003A8050 b;
    P_003A8050 *p;
    s32 n;

    if (func_L21_003A97E8(m) != 0) {
        return;
    }
    if (m->b95 != 9) {
        if (D_001D6694 == 2) {
            m->w98 = 0;
            m->h34 = (m->h34 | 0x41) & 0xEFFF;
            func_L01_004AA7E8(m, 1);
            return;
        }
        if (func_L01_004BA800() == 0) {
            C_003A8050 *c = m->cls;
            m->h34 &= 0xFFBE;
            m->h34 |= c->h44 & 0x1000;
            m->w98 = c->w10;
        }
    }
    func_L21_003A9B20(m);
    pos0 = m->pos;
    p = m->pv;
    if (D_L21_001E1034 == 0) {
        D_L21_001E1034 = 1;
        D_L21_001E1030 = D_001A7430[0];
    }
    switch (m->b95) {
    case 0:
    case 1:
        if (m->state == 0x18 || func_L21_003AA068(m) != 0) {
            break;
        }
        if (func_L01_004561E0(m) != 0 || m->state == 1) {
            if (func_00382468(10) != 0) {
                func_L01_004450F0(m, 4, -1);
            } else {
                func_L01_004450F0(m, 5, -1);
            }
            if (m->wB8 != 0 && func_L21_00339248(m->wB8) == 0) {
                p->h306 = 100;
            }
        }
        break;
    case 2:
        if (m->state == 0x18 || func_L21_003AA068(m) != 0) {
            break;
        }
        if (func_L01_004561E0(m) != 0 || m->state == 1) {
            p->h306 = 100;
            func_L01_004450F0(m, 0x13, -1);
        }
        if (m->state == 0x13 && func_0038CB00(&p->h306) != 0) {
            func_L01_004450F0(m, 1, 0);
        }
        break;
    case 3:
        if (m->state == 0x18 || func_L21_003AA068(m) != 0) {
            break;
        }
        if (func_L01_004561E0(m) != 0 || m->state == 1) {
            p->h306 = 0x32;
            func_L01_004450F0(m, 0x12, -1);
        }
        if (m->state == 0x12 && func_0038CB00(&p->h306) != 0) {
            func_L01_004450F0(m, 1, 0);
        }
        break;
    case 4:
        if (m->state == 0x18 || func_L21_003AA068(m) != 0) {
            break;
        }
        if (func_L01_004561E0(m) != 0 || m->state == 1) {
            p->h306 = 0x25;
            func_L01_004450F0(m, 0x11, -1);
        }
        if (m->state == 0x11 && func_0038CB00(&p->h306) != 0) {
            func_L01_004450F0(m, 1, 0);
        }
        break;
    case 5:
        if (func_L21_003AA068(m) != 0) {
            break;
        }
        if (m->state == 0x18) {
            if (m->b94 == 0x15 || m->b94 == 0x16 || m->b94 == 0x10 || m->b94 == 0xB) {
                func_L01_00445170(m, 0);
            }
            break;
        }
        if (func_L01_004561E0(m) != 0) {
            p->h30C = 0;
            p->h306 = 500;
            func_L01_004450F0(m, 0x14, -1);
        } else {
            if (m->state == 1) {
                func_L01_004450F0(m, 0x14, -1);
            } else if (m->state == 0xD) {
                if (func_0038CB00(&p->h306) != 0) {
                    func_L01_004450F0(m, 0x10, -1);
                }
                func_L01_0045A748(m, &p->vB0);
                if (func_0038CF38(&m->pos, &p->vB0) <= 5.0f) {
                    func_L01_004450F0(m, 0x14, -1);
                }
            } else if (m->state == 0x14 && m->anim == 9 && (m->b60 & 2)) {
                func_L01_004450F0(m, 0x10, -1);
            } else if (m->state == 0x10 && (m->b60 & 2)) {
                if (p->h30C != 0) {
                    func_L01_004450F0(m, 0xB, -1);
                } else {
                    func_L01_004450F0(m, 1, 0);
                }
            } else if (m->state == 0xB && (m->b60 & 2)) {
                func_L01_004450F0(m, 1, 0);
            } else if ((m->b94 == 0xE || m->b94 == 0xF) && m->state == 1) {
                func_L01_004450F0(m, 0xD, -1);
            }
        }
        break;
    case 7:
        if (m->state == 0x18 || func_L21_003AA068(m) != 0) {
            break;
        }
        if (func_L01_004561E0(m) != 0 || m->state == 1) {
            p->h306 = 0x32;
            p->f308 = 0.02f;
            m->h34 |= 0x808;
            p->bE1 = 0xFF;
            p->bE2 = 0xFF;
            func_L01_004450F0(m, 0x17, -1);
        }
        if (func_0038CB00(&p->h306) != 0) {
            s8 c;
            m->b23 = 0;
            m->f2C = m->cls->f24;
            p->bE1 = 0x15;
            p->bE2 = 0x17;
            m->w98 = 0;
            m->h34 = (m->h34 | 0x41) & 0xEFFF;
            func_L01_004AA7E8(m, 1);
            m->h34 |= 2;
            c = p->b301;
            if (c == 0) {
                p->b300 = 0;
            } else if (c == 1) {
                p->b300 = c;
            }
            m->bA8 = 0xFF;
            p->h108 = 0;
            func_L01_004450F0(m, 1, 9);
            return;
        }
        m->b23 = func_L01_00448070(0, 0x80, p->h306 * p->f308);
        break;
    case 8:
        if (m->state == 0x18 || func_L21_003AA068(m) != 0) {
            break;
        }
        if (func_L01_004561E0(m) != 0 || m->state == 1) {
            p->h306 = 100;
            p->f308 = 0.01f;
            m->h34 |= 0x808;
            p->bE1 = 0xFF;
            p->bE2 = 0xFF;
            D_L21_001E1030 = D_001A7430[0];
            func_L01_004450F0(m, 0x17, -1);
        }
        {
            C_003A8050 *c = m->cls;
            m->h34 &= 0xFFBE;
            m->h34 |= c->h44 & 0x1000;
            m->w98 = c->w10;
        }
        if (func_0038CB00(&p->h306) != 0) {
            s8 c;
            m->b23 = 0x80;
            p->bE1 = 0x15;
            p->bE2 = 0x17;
            c = p->b301;
            if (c == 2) {
                p->b300 = c;
            } else if (c == 3) {
                p->b300 = c;
            }
            m->bA8 = 0xFF;
            p->h108 = 0;
            func_L01_004450F0(m, 1, 0);
        } else {
            m->b23 = func_L01_00448070(0x80, 0, p->h306 * p->f308);
        }
        break;
    }
    switch (m->state) {
    case 3:
        if (func_L01_004561B8(m) != 0) {
            func_003C3A10(m, 0, 0, 8);
        }
        if (m->b60 & 2) {
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(m) != 0) {
            func_L21_00339258(m->wB8, func_00382498(10, 0x10), 1);
            func_003C3A10(m, 1, 0, 8);
        }
        if (func_0038CB00(&p->h306) != 0 || (m->b60 & 2)) {
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 5:
        if (func_L01_004561B8(m) != 0) {
            func_L21_00339258(m->wB8, func_00382498(10, 0x10), 1);
            func_003C3A10(m, 2, 0, 8);
        }
        if (m->b60 & 2) {
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 9:
        if (func_L01_004561B8(m) != 0) {
            func_003C3A10(m, 3, 0, 8);
        }
        break;
    case 10:
        if (func_L01_004561B8(m) != 0) {
            func_003C3A10(m, 3, 0, 8);
        }
        break;
    case 11:
        if (func_L01_004561B8(m) != 0) {
            func_003C3A10(m, 3, 0, 8);
        }
        break;
    case 12:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(0.0036000002f, 0.060000002f, 0.010053097f, 1.0053097f, m);
            func_003C3A10(m, 5, 0, 8);
        }
        break;
    case 13:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(0.0108f, 0.18f, 0.010053097f, 1.0053097f, m);
            func_003C3A10(m, 6, 0, 8);
        }
        break;
    case 14:
        {
            f32 t;
            if (func_L01_004561B8(m) != 0) {
                func_003C3A10(m, 0x19, 6, 8);
            }
            t = func_L01_004395E0(m);
            if (t >= 6.0f && t <= 10.0f) {
                func_0038CF68(&a, &m->vD0, 0.13333334f);
                func_L01_0045AA30(m, &a);
            } else if (func_L01_0044E1B8(11.0f, m) != 0) {
                func_L01_004450F0(m, 1, -1);
            }
        }
        break;
    case 15:
        {
            f32 t;
            if (func_L01_004561B8(m) != 0) {
                func_003C3A10(m, 0x1A, 6, 8);
            }
            t = func_L01_004395E0(m);
            if (t >= 6.0f && t <= 10.0f) {
                func_0038CF68(&a, &m->vD0, 0.13333334f);
                vec_neg(&a, &a);
                func_L01_0045AA30(m, &a);
            } else if (func_L01_0044E1B8(11.0f, m) != 0) {
                func_L01_004450F0(m, 1, -1);
            }
        }
        break;
    case 16:
        {
            f32 t;
            if (func_L01_004561B8(m) != 0) {
                func_003C3A10(m, 0x14, 0, 8);
                p->v230 = D_001D66B0;
                p->w240 = 0;
            }
            t = func_L01_004395E0(m);
            if (9.0f < t && t < 19.0f) {
                func_0038CF68(&a, &m->vC0, 0.16f);
                vec_neg(&a, &a);
                func_L01_0045AA30(m, &a);
            }
        }
        break;
    case 17:
        if (func_L01_004561B8(m) != 0) {
            func_003C3A10(m, 10, 0, 8);
        }
        func_L01_00448890(&m->fF8, func_0038D160(D_001A71A0[0]->pos.x - m->pos.x, D_001A71A0[0]->pos.y - m->pos.y),
                          &p->v244, p->f1A4 * 5.0f, p->f1A8 * 5.0f, p->f1AC + p->f1AC, 0);
        if (m->anim == 10 && func_L01_0044E1B8(12.0f, m) != 0) {
            func_003C2F58(m, 3, &a);
            if (p->hC4 == 1) {
                vec_sub_ab(&b, &p->vB0, &a);
                func_0038CF68(&b, &b, 0.40000004f);
            } else {
                b.x = func_0038D098(m->fF8) * 0.40000004f;
                b.y = func_0038D0B0(m->fF8) * 0.40000004f;
                b.z = 0.0f;
            }
            func_L21_003B1118(m, p->wC0, &a, &b, 0.0f, p->b45);
        }
        if (m->b60 & 2) {
            func_003C3A10(m, 0, 0, 8);
        }
        break;
    case 18:
        if (func_L01_004561B8(m) != 0) {
            func_003C3A10(m, 11, 0, 8);
        }
        func_L01_00448890(&m->fF8, func_0038D160(D_001A71A0[0]->pos.x - m->pos.x, D_001A71A0[0]->pos.y - m->pos.y),
                          &p->v244, p->f1A4 * 5.0f, p->f1A8 * 5.0f, p->f1AC + p->f1AC, 0);
        if (m->anim == 11 && func_L01_0044E1B8(13.0f, m) != 0) {
            func_003C2F58(m, 3, &a);
            a.z -= 0.5f;
            if (p->hC4 == 1) {
                b.x = func_0038D098(func_0038D160(p->vB0.x - a.x, p->vB0.y - a.y)) * 0.40000004f;
                b.y = func_0038D0B0(func_0038D160(p->vB0.x - a.x, p->vB0.y - a.y)) * 0.40000004f;
                b.z = 0.0f;
            } else {
                b.x = func_0038D098(m->fF8) * 0.40000004f;
                b.y = func_0038D0B0(m->fF8) * 0.40000004f;
                b.z = 0.0f;
            }
            func_L21_003B1518(m, p->wC0, &a, &b, 0.0f, p->b45);
        }
        if (m->b60 & 2) {
            func_003C3A10(m, 0, 0, 8);
        }
        break;
    case 19:
        if (func_L01_004561B8(m) != 0) {
            func_003C3A10(m, 0x1B, 0, 8);
        }
        func_L01_00448890(&m->fF8, func_0038D160(D_001A71A0[0]->pos.x - m->pos.x, D_001A71A0[0]->pos.y - m->pos.y),
                          &p->v244, p->f1A4 * 5.0f, p->f1A8 * 5.0f, p->f1AC + p->f1AC, 0);
        if (m->anim == 0x1B && func_L01_0044E1B8(15.0f, m) != 0) {
            f32 ang;
            func_003C2F58(m, 3, &a);
            a.z -= 0.2f;
            if (p->hC4 != 1) {
                ang = func_0038D160(D_L21_001DCF40 - a.x, D_L21_001DCF44 - a.y);
            } else {
                ang = m->fF8;
            }
            func_L21_003B1A00(m, &a, ang, p->b46);
        }
        if (m->b60 & 2) {
            func_003C3A10(m, 0, 0, 8);
        }
        break;
    case 20:
        if (func_L01_004561B8(m) != 0) {
            p->w1C8 &= ~0x10;
            func_L01_0045BD78(0.0108f, 0.18f, 0.010053097f, 1.0053097f, m);
            p->f318 = func_L01_00443A18(10.0f, 35.0f) * 0.017453292f;
            p->h30C = 0;
            p->h306 = 0x96;
            func_003C3A10(m, 7, 0, 4);
        }
        if (m->anim == 7 && (m->b60 & 2)) {
            func_003C3A10(m, 8, 0, 2);
        } else if (m->anim == 8) {
            s32 i;
            n = func_L01_004468C8(m, 4, 0.3f, 1, p->b44, 1.0f, 0, 1, 0);
            for (i = 0; i < n; i++) {
                if (D_L21_001EC4C0[i] == (s32)D_001A4BE0.m25C0) {
                    p->h30C = 1;
                }
            }
            func_L01_0045A7A8(p->f318, m, &p->vB0);
            func_L01_00404A10(func_L21_003A9E88, m);
            if ((func_0038CB00(&p->h306) != 0 || p->h30C != 0) && (m->b60 & 2)) {
                func_003C3A10(m, 9, 0, 2);
            }
        }
        break;
    case 21:
        {
            f32 t;
            if (func_L01_004561B8(m) != 0) {
                p->h30C = 0;
                func_003C3A10(m, 0xF, 0, 8);
            }
            t = func_L01_004395E0(m);
            if (12.0f < t && t < 18.0f) {
                s32 i;
                n = func_L01_004468C8(m, 3, 0.3f, 1, p->b44, 1.0f, 0, 1, 0);
                for (i = 0; i < n; i++) {
                    if (D_L21_001EC4C0[i] == (s32)D_001A4BE0.m25C0) {
                        p->h30C = 1;
                    }
                }
            }
        }
        break;
    case 22:
        {
            f32 t;
            if (func_L01_004561B8(m) != 0) {
                p->h30C = 0;
                func_003C3A10(m, 0x10, 0, 8);
            }
            t = func_L01_004395E0(m);
            if (13.0f < t && t < 16.0f) {
                s32 i;
                n = func_L01_004468C8(m, 1, 0.3f, 1, p->b44, 1.0f, 0, 1, 0);
                for (i = 0; i < n; i++) {
                    if (D_L21_001EC4C0[i] == (s32)D_001A4BE0.m25C0) {
                        p->h30C = 1;
                    }
                }
            }
        }
        break;
    case 23:
        {
            s32 i;
            if (func_L01_004561B8(m) != 0) {
                func_003C3A10(m, 4, 0, 8);
            }
            for (i = 0; i < 5; i++) {
                f32 ang;
                f32 r;
                f32 sz;
                s32 col;
                s32 life;
                qzero(&b);
                col = 0xFF4B2FFF;
                b.z = func_003824E0(3.0f, 4.0f) * 0.020000001f;
                ang = func_00382538();
                r = func_003824E0(0.25f, 0.5f);
                a.x = func_0038D098(ang) * r;
                a.y = func_0038D0B0(ang) * r;
                a.z = 0.0f;
                vec_add_ba(&a, &a, &m->pos);
                life = FRAMES(func_00382498(0x1E, 0x3C));
                sz = func_003824E0(0.1f, 0.3f);
                if (func_00382468(2) != 0) {
                    col = 0xFF4E2BFF;
                }
                func_L01_0046C470(&a, &b, col, life, sz, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
            }
        }
        break;
    case 24:
        {
            s32 r;
            if (func_L01_004561B8(m) != 0) {
                m->b23 = 0x80;
                if (p->f30 <= 0.0f) {
                    func_L21_003392E0(m->wB8);
                    func_L21_00339258(m->wB8, 0, 1);
                } else if (p->f30 < p->h34 * 0.1f) {
                    func_L21_00339258(m->wB8, 1, 0);
                } else if (func_00382468(5) == 0) {
                    func_L21_00339258(m->wB8, func_00382498(5, 9), 1);
                }
            }
            r = func_L01_00454370(m, &p->vD0);
            if (p->f30 <= 0.0f) {
                func_L01_00448890(&m->fF8,
                                  func_0038DB00(func_0038D160(D_L21_001DCF40 - m->pos.x, D_L21_001DCF44 - m->pos.y), 0.5235988f),
                                  &p->v244, p->f1A4 * 3.0f, p->f1A8 * 3.0f, p->f1AC * 3.0f, 0);
            }
            if (r & 1) {
                func_L01_004443E8(m, 0, 3);
                if (m->b60 & 2) {
                    m->f48 = 0.0f;
                }
                func_L01_004450F0(m, 0x19, -1);
            } else if (r & 2) {
                if (m->anim != 0) {
                    func_003C3A10(m, 0, 0, 2);
                }
                func_L01_004450F0(m, 1, -1);
            }
        }
        break;
    case 25:
        if (func_L21_003393C0(m->wB8) != 0) {
            m->w98 = 0;
        }
        if (m->b60 & 2) {
            m->f48 = 0.0f;
        }
        break;
    }
    {
        if (m->state != 0x18 && m->state != 0x19) {
            if (D_00142660.w8 * 0.1f <= D_L21_001E1030 - D_001A4BE0.w2850 && m->b94 != 0x17 && m->state != 0x17) {
                func_L21_00339258(m->wB8, func_00382498(0x11, 0x12), 1);
                D_L21_001E1030 = D_001A4BE0.w2850;
            } else if (D_001A4BE0.w2850 < D_00142660.w8 * 0.1f && m->b94 != 0x17 && m->state != 0x17) {
                func_L21_00339258(m->wB8, 4, 0);
            }
        }
    }
    if (p->b300 == 3) {
        func_L21_00339190(m, &pos0, m->state == 0x18);
    }
}
/* localdecomp:end func_L21_003A8050 */

/* localdecomp:start func_L21_003A97E8 */
extern u8 D_001426E0[];
extern void func_0039EF28(void);
extern void func_003C3A10(void *, s32, s32, s32);
void func_L01_004450F0(void *, s32, s32);

s32 func_L21_003A97E8(u8 *arg0) {
    u8 *v;
    s32 i;
    u8 *arr;

    if (arg0[0x20] != 0) {
        return 0;
    }
    v = *(u8 **)(arg0 + 0x68);
    *(s16 *)(v + 0x108) = 0;
    *(s32 *)(arg0 + 0x98) = *(s32 *)(*(u8 **)(arg0 + 0x24) + 0x10);
    v[0xE0] = 0x18;
    v[0x118] = 0xFF;
    v[0xE1] = 0x15;
    v[0xE2] = 0x17;
    v[0xE6] = 0x18;
    *(f32 *)(v + 0x10C) = 0.15f;
    v[0x147] = 1;
    *(f32 *)(v + 0xEC) = 0.3f;
    *(f32 *)(v + 0xF0) = 0.0200000014f;
    *(f32 *)(v + 0xF4) = 0.0100000007f;
    *(f32 *)(v + 0xF8) = 0.014f;
    *(f32 *)(v + 0xFC) = 0.00080000004f;
    v[0x14B] = 0xFF;
    *(f32 *)(v + 0x100) = 0.5f;
    *(f32 *)(v + 0x104) = 0.5f;
    v[0x148] = 0;
    v[0x149] = 0;
    v[0x14A] = 0;
    v[0x142] = 0;
    v[0x143] = 0;
    *(f32 *)(v + 0x110) = *(f32 *)(arg0 + 0x18) - 10.0f;
    *(f32 *)(v + 0x180) = 1.0f;
    *(f32 *)(v + 0x190) = 0.1f;
    *(f32 *)(v + 0x12C) = 0.2f;
    *(f32 *)(v + 0x194) = 0.2f;
    *(f32 *)(v + 0x128) = 0.01f;
    *(f32 *)(v + 0x17C) = 0.5f;
    *(f32 *)(v + 0x198) = 2.0f;
    *(f32 *)(v + 0x19C) = 2.0f;
    *(f32 *)(v + 0x1A0) = 1.30899692f;
    *(f32 *)(v + 0x1C0) = 3.14159274f;
    *(f32 *)(v + 0x1BC) = 0.00392f;
    *(f32 *)(v + 0x1C4) = 0.5f;
    *(f32 *)(v + 0x40) = 1.2f;
    v[0x3E] = 3;
    v[0x39] = 0;
    v[0x3F] = 0;
    v[0x64] = 0;

    if (D_001426E0[0xD5] == 0) {
        D_001426E0[0xD5] |= 1;
        func_0039EF28();
    }
    i = 0;
    arr = v + 0x310;
    for (; i < 8; i++) {
        if ((u32)i < 8 && ((D_001426E0[0xD5] >> i) & 1)) {
            *(f32 *)(v + 0x30) = *(f32 *)(v + 0x30) * ((f32)arr[i] * 0.01f);
            *(s16 *)(v + 0x34) = *(f32 *)(v + 0x30);
            break;
        }
    }
    if (*(s16 *)(v + 0x34) == 0 || *(f32 *)(v + 0x30) <= 0.0f) {
        *(s16 *)(v + 0x34) = 300;
        *(f32 *)(v + 0x30) = 300.0f;
    }
    if (v[0x44] == 0) {
        v[0x44] = 2;
    }
    if (v[0x45] == 0) {
        v[0x45] = 3;
    }
    if (v[0x46] == 0) {
        v[0x46] = 5;
    }
    v[0x58] = 0x28;
    v[0x5A] = 0x60;
    v[0x300] = 3;
    if (arg0[0x43] != 0) {
        func_003C3A10(arg0, 0, 0, 0);
    }
    func_L01_004450F0(arg0, 1, 0);
    return 1;
}
/* localdecomp:end func_L21_003A97E8 */

/* localdecomp:start func_L21_003A9B20 */
/* PAL port of the NTSC-U match src/us/levels/func_L21_003A80D0.c */


extern u8 D_1426E0[];
extern u8 D_L21_001E1700[];
extern f32 D_L21_001DCF40;
extern f32 D_L21_001DCF50;

extern void func_0039EF28(void);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern T_003A80D0 *func_L01_00447490(void *, s32, s32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern s32 func_0038CB00(void *);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);

void func_L21_003A9B20(void *o_) {
    u8 *o = o_;
    S_003A80D0 *s;
    T_003A80D0 *t;
    s32 i;
    f32 d;
    f32 k;

    s = *(S_003A80D0 **)(o + 0x68);
    if ((*(unsigned long *)(o + 0x90) & 0xFFFF00FF00000000UL) == 0) {
        for (i = 0; i < 7; i++) {
            if ((u32)i < 8 && ((D_1426E0[0xD5] >> i) & 1)) {
                u32 j;
                D_1426E0[0xD5] &= ~(1 << i);
                func_0039EF28();
                j = i + 1;
                if (j < 8) {
                    D_1426E0[0xD5] |= 1 << j;
                }
                func_0039EF28();
                break;
            }
        }
    }
    if (o[0x31] != 0) {
        if (func_L01_0040E548(D_L21_001E1700, o + 0x10) < 1024.0f) {
            func_L01_004472C0(o);
            o[0x6F] = 0x1E;
        }
    }
    t = func_L01_00447490(o, -1, 0);
    if (t != 0) {
        f32 f3 = s->f30;
        f32 diff = f3 - t->f2C;
        f32 scaled = (f32)(s->h34 * s->h304) * 0.01f;
        if (diff < scaled) {
            t->f2C = (f3 - scaled) + 1.0f;
        }
    }
    if (o[0x20] == 0xD && t != 0) {
        if (func_00382468(4) == 0) {
            o[0xA8] = 0xFF;
            func_L01_004450F0(o, func_00382498(14, 15), -1);
        }
    }
    if (o[0x20] != 0x17) {
        if (s->h30E != 0) {
            s->bE1 = 0xFF;
            s->bE2 = 0xFF;
        } else {
            s->bE1 = 0x15;
            s->bE2 = 0x17;
        }
    }
    if (s->f30 <= 0.0f) {
        s->bE1 = 0x15;
        s->bE2 = 0x17;
    }
    if (o[0x20] != 0x17 || s->f30 <= 0.0f) {
        func_L01_00452FB0(o, s->bD0, 0, 0, 0);
    }
    if (t != 0 && t->w20 != 0 && s->h30E == 0) {
        s->h30E = 75;
    } else {
        func_0038CB00(&s->h30E);
    }
    if ((*(unsigned long *)(o + 0x30) & 0x104100000000UL) == 0x4100000000UL && *(s32 *)(o + 0x98) == 0) {
    } else {
        if (0.0f < s->f30) {
            func_L01_00456BD0(o, 3);
        }
    }
    func_L01_00456C98(o, -1, &D_L21_001DCF40, 0, 0, 0, 2, 0, 0, 0, D_L21_001DCF50, 10.0f, 1.0f);
    if (*(u16 *)(o + 0x96) <= 0xFFFE) {
        *(u16 *)(o + 0x96) += 1;
    }
    func_L01_00451DF8(o, s->b280, 5, 1, 2.5f);
}
/* localdecomp:end func_L21_003A9B20 */

/* localdecomp:start func_L21_003A9E88 */
#include "vu0.h"

typedef int u128_003A9E88 __attribute__((mode(TI)));

typedef struct {
    u128_003A9E88 m[4];
    s32 c40, c44, c48, c4C;
    s32 x50, x54;
    f32 x58;
    s32 x5C, x60;
    f32 x64, x68, x6C;
    long x70, x78, x80, x88;
} S_003A9E88;

extern long func_00389598(s32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003D2DA0(void *, void *, s32);

void func_L21_003A9E88(u8 *a0) {
    S_003A9E88 s;
    f32 t[4] __attribute__((aligned(16)));
    f32 base[4] __attribute__((aligned(16)));
    f32 pts[4][4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    s32 i;
    s32 k;
    f32 *out;

    s.x78 = func_00389598(0x65);
    s.x80 = 0xFF9000000260L;
    s.x88 = 0xFF00000048L;
    s.x70 = 0;
    s.x58 = 1.0f;
    s.x64 = 1.0f;
    s.x68 = 1.0f;
    s.x6C = 1.0f;
    s.c4C = 0xFFFF20FF;
    s.c48 = 0xFFFF20FF;
    s.c44 = 0xFFFF20FF;
    s.c40 = 0xFFFF20FF;
    s.x50 = 0;
    s.x54 = 0;
    s.x5C = 0;
    s.x60 = 0;
    func_003C2F58(a0, 0, t);
    *(u128_003A9E88 *)base = *(u128_003A9E88 *)(a0 + 0x10);
    base[2] = t[2];
    out = pts[0];
    k = 0;
    for (i = 0; i < 4; i++) {
        d[0] = func_0038D098(func_0038DAB8(func_0038D160(t[0] - *(f32 *)(a0 + 0x10), t[1] - *(f32 *)(a0 + 0x14)), (f32)k * 0.0174532924f)) * 1.8f;
        d[1] = func_0038D0B0(func_0038DAB8(func_0038D160(t[0] - *(f32 *)(a0 + 0x10), t[1] - *(f32 *)(a0 + 0x14)), (f32)k * 0.0174532924f)) * 1.8f;
        d[2] = 0.0f;
        vec_add_ab(out, base, d);
        out += 4;
        k += 90;
    }
    s.m[0] = *(u128_003A9E88 *)pts[0];
    s.m[2] = *(u128_003A9E88 *)pts[1];
    s.m[3] = *(u128_003A9E88 *)pts[2];
    s.m[1] = *(u128_003A9E88 *)pts[3];
    func_003D2DA0(&s, 0, 0);
}
/* localdecomp:end func_L21_003A9E88 */
