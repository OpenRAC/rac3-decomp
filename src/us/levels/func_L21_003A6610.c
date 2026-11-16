#include "common.h"

/* NTSC-U counterpart of func_L21_003A8050 (src/levels/21_obani_draco/L21_003A8050.c) */
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

/* localdecomp:start func_L21_003A6610 */
#include "vu0.h"

extern H_003A8050 D_001A4BE0;

extern G_003A8050 D_00142660;
extern s32 D_001A7430[];
extern M_003A8050 *D_001A71A0[];
extern V4_003A8050 D_L21_001D66B0_003A6610;
extern f32 D_L21_001DCF70;
__asm__(".extern D_L21_001DCF70, 16");
extern f32 D_L21_001DCF74;
__asm__(".extern D_L21_001DCF74, 16");
extern s32 D_L21_001EC540[];
extern s32 D_L21_001D6694_003A6610;
extern s32 D_L21_001E10B0;
__asm__(".extern D_L21_001E10B0, 4");
extern s32 D_L21_001E10B4;
__asm__(".extern D_L21_001E10B4, 4");

extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern s32 func_003883C8(void *);
extern f32 func_00388800(void *, void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_003893C8(f32, f32);
extern void func_003BDA38(void *, s32, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_004026A0(void *, void *);
extern f32 func_L01_00436500(void *);
extern f32 func_L01_00440918(f32, f32);
extern void func_L01_004412D0(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00442038(void *, s32);
extern s32 func_L01_00443790(f32, f32, f32, void *, s32, s32, s32, s32, s32);
extern s32 func_L01_00444F38_003A6610(s32, s32, f32);
extern f32 func_L01_00445758(void *, f32, void *, f32, f32, f32, s32);
extern s32 func_L01_0044AF40(f32, void *);
extern s32 func_L01_00451078(void *, void *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_L01_00452EF0(void *);
extern void func_L01_00457440(void *, void *);
extern void func_L01_004574A0(f32, void *, void *);
extern void func_L01_00457728(void *, void *);
extern void func_L01_00458A70(f32, f32, f32, f32, void *);
extern void func_L01_00468DC0(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_L01_004A6DF8(void *, s32);
extern s32 func_L01_004B6C68(void);
extern void func_L21_003387D8(void *, void *, s32);
extern s32 func_L21_00338890(s32);
extern s32 func_L21_003388A0(s32, s32, s32);
extern void func_L21_00338928(s32);
extern s32 func_L21_00338A08(s32);
extern s32 func_L21_003A7D98(u8 *arg0);
extern void func_L21_003A80D0(void *o_);
extern void func_L21_003A8438(u8 *);
extern s32 func_L21_003A8618(void *);
extern void func_L21_003AF560(void *, s32, void *, void *, f32, f32);
extern void func_L21_003AF960(void *, s32, void *, void *, f32, f32);
extern void func_L21_003AFE48(void *, void *, f32, f32);


void func_L21_003A6610(M_003A8050 *m) {
    V4_003A8050 pos0;
    V4_003A8050 a;
    V4_003A8050 b;
    P_003A8050 *p;
    s32 n;

    if (func_L21_003A7D98(m) != 0) {
        return;
    }
    if (m->b95 != 9) {
        if (D_L21_001D6694_003A6610 == 2) {
            m->w98 = 0;
            m->h34 = (m->h34 | 0x41) & 0xEFFF;
            func_L01_004A6DF8(m, 1);
            return;
        }
        if (func_L01_004B6C68() == 0) {
            C_003A8050 *c = m->cls;
            m->h34 &= 0xFFBE;
            m->h34 |= c->h44 & 0x1000;
            m->w98 = c->w10;
        }
    }
    func_L21_003A80D0(m);
    pos0 = m->pos;
    p = m->pv;
    if (D_L21_001E10B4 == 0) {
        D_L21_001E10B4 = 1;
        D_L21_001E10B0 = D_001A7430[0];
    }
    switch (m->b95) {
    case 0:
    case 1:
        if (m->state == 0x18 || func_L21_003A8618(m) != 0) {
            break;
        }
        if (func_L01_00452EF0(m) != 0 || m->state == 1) {
            if (func_0037E1D8(10) != 0) {
                func_L01_00441FB8(m, 4, -1);
            } else {
                func_L01_00441FB8(m, 5, -1);
            }
            if (m->wB8 != 0 && func_L21_00338890(m->wB8) == 0) {
                p->h306 = 120;
            }
        }
        break;
    case 2:
        if (m->state == 0x18 || func_L21_003A8618(m) != 0) {
            break;
        }
        if (func_L01_00452EF0(m) != 0 || m->state == 1) {
            p->h306 = 120;
            func_L01_00441FB8(m, 0x13, -1);
        }
        if (m->state == 0x13 && func_003883C8(&p->h306) != 0) {
            func_L01_00441FB8(m, 1, 0);
        }
        break;
    case 3:
        if (m->state == 0x18 || func_L21_003A8618(m) != 0) {
            break;
        }
        if (func_L01_00452EF0(m) != 0 || m->state == 1) {
            p->h306 = 60;
            func_L01_00441FB8(m, 0x12, -1);
        }
        if (m->state == 0x12 && func_003883C8(&p->h306) != 0) {
            func_L01_00441FB8(m, 1, 0);
        }
        break;
    case 4:
        if (m->state == 0x18 || func_L21_003A8618(m) != 0) {
            break;
        }
        if (func_L01_00452EF0(m) != 0 || m->state == 1) {
            p->h306 = 45;
            func_L01_00441FB8(m, 0x11, -1);
        }
        if (m->state == 0x11 && func_003883C8(&p->h306) != 0) {
            func_L01_00441FB8(m, 1, 0);
        }
        break;
    case 5:
        if (func_L21_003A8618(m) != 0) {
            break;
        }
        if (m->state == 0x18) {
            if (m->b94 == 0x15 || m->b94 == 0x16 || m->b94 == 0x10 || m->b94 == 0xB) {
                func_L01_00442038(m, 0);
            }
            break;
        }
        if (func_L01_00452EF0(m) != 0) {
            p->h30C = 0;
            p->h306 = 600;
            func_L01_00441FB8(m, 0x14, -1);
        } else {
            if (m->state == 1) {
                func_L01_00441FB8(m, 0x14, -1);
            } else if (m->state == 0xD) {
                if (func_003883C8(&p->h306) != 0) {
                    func_L01_00441FB8(m, 0x10, -1);
                }
                func_L01_00457440(m, &p->vB0);
                if (func_00388800(&m->pos, &p->vB0) <= 5.0f) {
                    func_L01_00441FB8(m, 0x14, -1);
                }
            } else if (m->state == 0x14 && m->anim == 9 && (m->b60 & 2)) {
                func_L01_00441FB8(m, 0x10, -1);
            } else if (m->state == 0x10 && (m->b60 & 2)) {
                if (p->h30C != 0) {
                    func_L01_00441FB8(m, 0xB, -1);
                } else {
                    func_L01_00441FB8(m, 1, 0);
                }
            } else if (m->state == 0xB && (m->b60 & 2)) {
                func_L01_00441FB8(m, 1, 0);
            } else if ((m->b94 == 0xE || m->b94 == 0xF) && m->state == 1) {
                func_L01_00441FB8(m, 0xD, -1);
            }
        }
        break;
    case 7:
        if (m->state == 0x18 || func_L21_003A8618(m) != 0) {
            break;
        }
        if (func_L01_00452EF0(m) != 0 || m->state == 1) {
            p->h306 = 60;
            p->f308 = 0.016666668f;
            m->h34 |= 0x808;
            p->bE1 = 0xFF;
            p->bE2 = 0xFF;
            func_L01_00441FB8(m, 0x17, -1);
        }
        if (func_003883C8(&p->h306) != 0) {
            s8 c;
            m->b23 = 0;
            m->f2C = m->cls->f24;
            p->bE1 = 0x15;
            p->bE2 = 0x17;
            m->w98 = 0;
            m->h34 = (m->h34 | 0x41) & 0xEFFF;
            func_L01_004A6DF8(m, 1);
            m->h34 |= 2;
            c = p->b301;
            if (c == 0) {
                p->b300 = 0;
            } else if (c == 1) {
                p->b300 = c;
            }
            m->bA8 = 0xFF;
            p->h108 = 0;
            func_L01_00441FB8(m, 1, 9);
            return;
        }
        m->b23 = func_L01_00444F38_003A6610(0, 0x80, p->h306 * p->f308);
        break;
    case 8:
        if (m->state == 0x18 || func_L21_003A8618(m) != 0) {
            break;
        }
        if (func_L01_00452EF0(m) != 0 || m->state == 1) {
            p->h306 = 120;
            p->f308 = 0.008333334f;
            m->h34 |= 0x808;
            p->bE1 = 0xFF;
            p->bE2 = 0xFF;
            D_L21_001E10B0 = D_001A7430[0];
            func_L01_00441FB8(m, 0x17, -1);
        }
        {
            C_003A8050 *c = m->cls;
            m->h34 &= 0xFFBE;
            m->h34 |= c->h44 & 0x1000;
            m->w98 = c->w10;
        }
        if (func_003883C8(&p->h306) != 0) {
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
            func_L01_00441FB8(m, 1, 0);
        } else {
            m->b23 = func_L01_00444F38_003A6610(0x80, 0, p->h306 * p->f308);
        }
        break;
    }
    switch (m->state) {
    case 3:
        if (func_L01_00452EC8(m) != 0) {
            func_003BE4F0(m, 0, 0, 10);
        }
        if (m->b60 & 2) {
            func_L01_00441FB8(m, 1, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(m) != 0) {
            func_L21_003388A0(m->wB8, func_0037E208(10, 0x10), 1);
            func_003BE4F0(m, 1, 0, 10);
        }
        if (func_003883C8(&p->h306) != 0 || (m->b60 & 2)) {
            func_L01_00441FB8(m, 1, -1);
        }
        break;
    case 5:
        if (func_L01_00452EC8(m) != 0) {
            func_L21_003388A0(m->wB8, func_0037E208(10, 0x10), 1);
            func_003BE4F0(m, 2, 0, 10);
        }
        if (m->b60 & 2) {
            func_L01_00441FB8(m, 1, -1);
        }
        break;
    case 9:
        if (func_L01_00452EC8(m) != 0) {
            func_003BE4F0(m, 3, 0, 10);
        }
        break;
    case 10:
        if (func_L01_00452EC8(m) != 0) {
            func_003BE4F0(m, 3, 0, 10);
        }
        break;
    case 11:
        if (func_L01_00452EC8(m) != 0) {
            func_003BE4F0(m, 3, 0, 10);
        }
        break;
    case 12:
        if (func_L01_00452EC8(m) != 0) {
            func_L01_00458A70(0.0025f, 0.050000004f, 0.0069813174195587635f, 0.8377581238746643f, m);
            func_003BE4F0(m, 5, 0, 10);
        }
        break;
    case 13:
        if (func_L01_00452EC8(m) != 0) {
            func_L01_00458A70(0.007500000298023224f, 0.15f, 0.0069813174195587635f, 0.8377581238746643f, m);
            func_003BE4F0(m, 6, 0, 10);
        }
        break;
    case 14:
        {
            f32 t;
            if (func_L01_00452EC8(m) != 0) {
                func_003BE4F0(m, 0x19, 6, 10);
            }
            t = func_L01_00436500(m);
            if (t >= 6.0f && t <= 10.0f) {
                func_00388830(&a, &m->vD0, 0.13333334f);
                func_L01_00457728(m, &a);
            } else if (func_L01_0044AF40(11.0f, m) != 0) {
                func_L01_00441FB8(m, 1, -1);
            }
        }
        break;
    case 15:
        {
            f32 t;
            if (func_L01_00452EC8(m) != 0) {
                func_003BE4F0(m, 0x1A, 6, 10);
            }
            t = func_L01_00436500(m);
            if (t >= 6.0f && t <= 10.0f) {
                func_00388830(&a, &m->vD0, 0.13333334f);
                vec_neg(&a, &a);
                func_L01_00457728(m, &a);
            } else if (func_L01_0044AF40(11.0f, m) != 0) {
                func_L01_00441FB8(m, 1, -1);
            }
        }
        break;
    case 16:
        {
            f32 t;
            if (func_L01_00452EC8(m) != 0) {
                func_003BE4F0(m, 0x14, 0, 10);
                p->v230 = D_L21_001D66B0_003A6610;
                p->w240 = 0;
            }
            t = func_L01_00436500(m);
            if (9.0f < t && t < 19.0f) {
                func_00388830(&a, &m->vC0, 0.16f);
                vec_neg(&a, &a);
                func_L01_00457728(m, &a);
            }
        }
        break;
    case 17:
        if (func_L01_00452EC8(m) != 0) {
            func_003BE4F0(m, 10, 0, 10);
        }
        func_L01_00445758(&m->fF8, func_00388A28(D_001A71A0[0]->pos.x - m->pos.x, D_001A71A0[0]->pos.y - m->pos.y),
                          &p->v244, p->f1A4 * 5.0f, p->f1A8 * 5.0f, p->f1AC + p->f1AC, 0);
        if (m->anim == 10 && func_L01_0044AF40(12.0f, m) != 0) {
            func_003BDA38(m, 3, &a);
            if (p->hC4 == 1) {
                vec_sub_ab(&b, &p->vB0, &a);
                func_00388830(&b, &b, 0.33333334f);
            } else {
                b.x = func_00388960(m->fF8) * 0.33333334f;
                b.y = func_00388978(m->fF8) * 0.33333334f;
                b.z = 0.0f;
            }
            func_L21_003AF560(m, p->wC0, &a, &b, 0.0f, p->b45);
        }
        if (m->b60 & 2) {
            func_003BE4F0(m, 0, 0, 10);
        }
        break;
    case 18:
        if (func_L01_00452EC8(m) != 0) {
            func_003BE4F0(m, 11, 0, 10);
        }
        func_L01_00445758(&m->fF8, func_00388A28(D_001A71A0[0]->pos.x - m->pos.x, D_001A71A0[0]->pos.y - m->pos.y),
                          &p->v244, p->f1A4 * 5.0f, p->f1A8 * 5.0f, p->f1AC + p->f1AC, 0);
        if (m->anim == 11 && func_L01_0044AF40(13.0f, m) != 0) {
            func_003BDA38(m, 3, &a);
            a.z -= 0.5f;
            if (p->hC4 == 1) {
                b.x = func_00388960(func_00388A28(p->vB0.x - a.x, p->vB0.y - a.y)) * 0.33333334f;
                b.y = func_00388978(func_00388A28(p->vB0.x - a.x, p->vB0.y - a.y)) * 0.33333334f;
                b.z = 0.0f;
            } else {
                b.x = func_00388960(m->fF8) * 0.33333334f;
                b.y = func_00388978(m->fF8) * 0.33333334f;
                b.z = 0.0f;
            }
            func_L21_003AF960(m, p->wC0, &a, &b, 0.0f, p->b45);
        }
        if (m->b60 & 2) {
            func_003BE4F0(m, 0, 0, 10);
        }
        break;
    case 19:
        if (func_L01_00452EC8(m) != 0) {
            func_003BE4F0(m, 0x1B, 0, 10);
        }
        func_L01_00445758(&m->fF8, func_00388A28(D_001A71A0[0]->pos.x - m->pos.x, D_001A71A0[0]->pos.y - m->pos.y),
                          &p->v244, p->f1A4 * 5.0f, p->f1A8 * 5.0f, p->f1AC + p->f1AC, 0);
        if (m->anim == 0x1B && func_L01_0044AF40(15.0f, m) != 0) {
            f32 ang;
            func_003BDA38(m, 3, &a);
            a.z -= 0.2f;
            if (p->hC4 != 1) {
                ang = func_00388A28(D_L21_001DCF70 - a.x, D_L21_001DCF74 - a.y);
            } else {
                ang = m->fF8;
            }
            func_L21_003AFE48(m, &a, ang, p->b46);
        }
        if (m->b60 & 2) {
            func_003BE4F0(m, 0, 0, 10);
        }
        break;
    case 20:
        if (func_L01_00452EC8(m) != 0) {
            p->w1C8 &= ~0x10;
            func_L01_00458A70(0.007500000298023224f, 0.15f, 0.0069813174195587635f, 0.8377581238746643f, m);
            p->f318 = func_L01_00440918(10.0f, 35.0f) * 0.017453292f;
            p->h30C = 0;
            p->h306 = 180;
            func_003BE4F0(m, 7, 0, 5);
        }
        if (m->anim == 7 && (m->b60 & 2)) {
            func_003BE4F0(m, 8, 0, 3);
        } else if (m->anim == 8) {
            s32 i;
            n = func_L01_00443790(0.3f, p->b44, 1.0f, m, 4, 1, 0, 1, 0);
            for (i = 0; i < n; i++) {
                if (D_L21_001EC540[i] == (s32)D_001A4BE0.m25C0) {
                    p->h30C = 1;
                }
            }
            func_L01_004574A0(p->f318, m, &p->vB0);
            func_L01_004026A0(func_L21_003A8438, m);
            if ((func_003883C8(&p->h306) != 0 || p->h30C != 0) && (m->b60 & 2)) {
                func_003BE4F0(m, 9, 0, 3);
            }
        }
        break;
    case 21:
        {
            f32 t;
            if (func_L01_00452EC8(m) != 0) {
                p->h30C = 0;
                func_003BE4F0(m, 0xF, 0, 10);
            }
            t = func_L01_00436500(m);
            if (12.0f < t && t < 18.0f) {
                s32 i;
                n = func_L01_00443790(0.3f, p->b44, 1.0f, m, 3, 1, 0, 1, 0);
                for (i = 0; i < n; i++) {
                    if (D_L21_001EC540[i] == (s32)D_001A4BE0.m25C0) {
                        p->h30C = 1;
                    }
                }
            }
        }
        break;
    case 22:
        {
            f32 t;
            if (func_L01_00452EC8(m) != 0) {
                p->h30C = 0;
                func_003BE4F0(m, 0x10, 0, 10);
            }
            t = func_L01_00436500(m);
            if (13.0f < t && t < 16.0f) {
                s32 i;
                n = func_L01_00443790(0.3f, p->b44, 1.0f, m, 1, 1, 0, 1, 0);
                for (i = 0; i < n; i++) {
                    if (D_L21_001EC540[i] == (s32)D_001A4BE0.m25C0) {
                        p->h30C = 1;
                    }
                }
            }
        }
        break;
    case 23:
        {
            s32 i;
            if (func_L01_00452EC8(m) != 0) {
                func_003BE4F0(m, 4, 0, 10);
            }
            for (i = 0; i < 5; i++) {
                f32 ang;
                f32 r;
                f32 sz;
                s32 col;
                s32 life;
                qzero(&b);
                col = 0xFF4B2FFF;
                b.z = func_0037E250(3.0f, 4.0f) * 0.016666668f;
                ang = func_0037E2A8();
                r = func_0037E250(0.25f, 0.5f);
                a.x = func_00388960(ang) * r;
                a.y = func_00388978(ang) * r;
                a.z = 0.0f;
                vec_add_ba(&a, &a, &m->pos);
                life = func_0037E208(0x1E, 0x3C);
                sz = func_0037E250(0.1f, 0.3f);
                if (func_0037E1D8(2) != 0) {
                    col = 0xFF4E2BFF;
                }
                func_L01_00468DC0(&a, &b, col, sz, life, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
            }
        }
        break;
    case 24:
        {
            s32 r;
            if (func_L01_00452EC8(m) != 0) {
                m->b23 = 0x80;
                if (p->f30 <= 0.0f) {
                    func_L21_00338928(m->wB8);
                    func_L21_003388A0(m->wB8, 0, 1);
                } else if (p->f30 < p->h34 * 0.1f) {
                    func_L21_003388A0(m->wB8, 1, 0);
                } else if (func_0037E1D8(5) == 0) {
                    func_L21_003388A0(m->wB8, func_0037E208(5, 9), 1);
                }
            }
            r = func_L01_00451078(m, &p->vD0);
            if (p->f30 <= 0.0f) {
                func_L01_00445758(&m->fF8,
                                  func_003893C8(func_00388A28(D_L21_001DCF70 - m->pos.x, D_L21_001DCF74 - m->pos.y), 0.5235988f),
                                  &p->v244, p->f1A4 * 3.0f, p->f1A8 * 3.0f, p->f1AC * 3.0f, 0);
            }
            if (r & 1) {
                func_L01_004412D0(m, 0, 3);
                if (m->b60 & 2) {
                    m->f48 = 0.0f;
                }
                func_L01_00441FB8(m, 0x19, -1);
            } else if (r & 2) {
                if (m->anim != 0) {
                    func_003BE4F0(m, 0, 0, 3);
                }
                func_L01_00441FB8(m, 1, -1);
            }
        }
        break;
    case 25:
        if (func_L21_00338A08(m->wB8) != 0) {
            m->w98 = 0;
        }
        if (m->b60 & 2) {
            m->f48 = 0.0f;
        }
        break;
    }
    {
        if (m->state != 0x18 && m->state != 0x19) {
            if (D_00142660.w8 * 0.1f <= D_L21_001E10B0 - D_001A4BE0.w2850 && m->b94 != 0x17 && m->state != 0x17) {
                func_L21_003388A0(m->wB8, func_0037E208(0x11, 0x12), 1);
                D_L21_001E10B0 = D_001A4BE0.w2850;
            } else if (D_001A4BE0.w2850 < D_00142660.w8 * 0.1f && m->b94 != 0x17 && m->state != 0x17) {
                func_L21_003388A0(m->wB8, 4, 0);
            }
        }
    }
    if (p->b300 == 3) {
        func_L21_003387D8(m, &pos0, m->state == 0x18);
    }
}
/* localdecomp:end func_L21_003A6610 */
