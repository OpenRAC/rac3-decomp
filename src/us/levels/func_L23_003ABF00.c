#include "common.h"
#include "vu0.h"
#include "structs/hero.h"

/* NTSC-U counterpart of func_L23_003AD800 with regional timing. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B0200;
typedef struct { u8 pad0[0x12]; s16 count; u8 pad14[0xC]; s32 *ids; u8 pad24[0xC]; } Path_3B0200;
typedef struct { s32 count; u8 pad4[0x1C]; Path_3B0200 paths[1]; } Paths_3B0200;
typedef struct { u8 pad0[0x30]; V4_3B0200 pos; u8 pad40[0x40]; } Node_3B0200;



/* localdecomp:start func_L23_003ABF00 */
typedef struct { u8 pad0[0x10]; u8 b10; } Sub_AD;
typedef struct {
    u8 pad0[0x10]; s32 i10; u8 pad14[0x30]; u16 h44; u8 pad46[2];
    Sub_AD *p48; Sub_AD *p4C; u8 pad50[0x10]; Sub_AD *p60; Sub_AD *p64;
} Cls_AD;
typedef struct {
    u8 pad0[0x30]; f32 f30; s16 h34; u8 pad36[0xA4 - 0x36]; f32 fA4;
    u8 padA8[0xF4 - 0xA8]; s32 iF4;
    u8 padF8[0x170 - 0xF8]; f32 f170; f32 f174; u8 pad178[0x184 - 0x178]; s16 h184;
    u8 pad186[0x210 - 0x186]; s32 i210; s32 i214; s32 i218; s32 i21C; s32 i220; f32 f224;
    s32 i228; s32 i22C; f32 f230; f32 f234; u8 pad238[4]; s32 i23C; s32 i240; s32 i244;
    u8 pad248[4]; f32 f24C; V4 v250; V4 v260; V4 v270; u8 pad280[0x10]; V4 v290;
    u8 pad2A0[0x10]; s32 i2B0; f32 f2B4; f32 f2B8; s32 i2BC;
} Vars_AD;
typedef struct {
    u8 pad0[0x10]; V4 pos;
    u8 b20; u8 b21; u8 pad22[2]; Cls_AD *cls; u8 pad28[8];
    union { unsigned long q; u8 b[8]; u16 h[4]; } f30;
    u8 pad38[8];
    u8 b40[2]; u8 b42; u8 b43; u8 pad44[4]; f32 f48; u8 pad4C[0x60 - 0x4C];
    u8 b60; u8 pad61[7]; Vars_AD *vars; u8 pad6C[0x94 - 0x6C];
    u8 b94; u8 b95; s16 h96; s32 i98; u8 pad9C[0xF0 - 0x9C]; V4 vF0;
} Moby_AD;

extern f32 D_L23_001DE230[6] __attribute__((section(".sdata"))); __asm__(".extern D_L23_001DE230, 4");
extern f32 D_L23_001DE248_003ABF00[6] __attribute__((section(".sdata"))); __asm__(".extern D_L23_001DE248_003ABF00, 4");
extern f32 D_L23_001DE260; __asm__(".extern D_L23_001DE260, 4");
extern f32 D_L23_001DE264; __asm__(".extern D_L23_001DE264, 4");
extern f32 D_L23_001DE268; __asm__(".extern D_L23_001DE268, 4");
extern f32 D_L23_001DE26C; __asm__(".extern D_L23_001DE26C, 4");
extern f32 D_L23_001DE274_003ABF00; __asm__(".extern D_L23_001DE274_003ABF00, 4");
extern f32 D_L23_001DE278; __asm__(".extern D_L23_001DE278, 4");
extern f32 D_L23_001DE27C; __asm__(".extern D_L23_001DE27C, 4");
extern f32 D_L23_001DE280; __asm__(".extern D_L23_001DE280, 4");
extern f32 D_L23_001DE288_003ABF00; __asm__(".extern D_L23_001DE288_003ABF00, 4");
extern f32 D_L23_001DE294_003ABF00; __asm__(".extern D_L23_001DE294_003ABF00, 4");
extern f32 D_L23_001DE298; __asm__(".extern D_L23_001DE298, 4");
extern f32 D_L23_001DE29C; __asm__(".extern D_L23_001DE29C, 4");
extern f32 D_L23_001DE2A4; __asm__(".extern D_L23_001DE2A4, 4");
extern f32 D_L23_001DE2A8_003ABF00; __asm__(".extern D_L23_001DE2A8_003ABF00, 4");
extern f32 D_L23_001DE2AC; __asm__(".extern D_L23_001DE2AC, 4");
extern f32 D_L23_001DE2B0_003ABF00; __asm__(".extern D_L23_001DE2B0_003ABF00, 4");
extern s32 D_L23_001DE2B8; __asm__(".extern D_L23_001DE2B8, 4");
extern Moby_AD *D_L23_001DE310;
extern s32 D_001A7430[];
extern s32 D_001A71A0[];

extern struct Hero D_001A4BE0;
extern Paths_3B0200 *D_L23_001DEDCC; __asm__(".extern D_L23_001DEDCC, 16");
extern Node_3B0200 *D_L23_001DF2C0; __asm__(".extern D_L23_001DF2C0, 16");
extern u16 *D_L23_0021C160[];
extern u8 *D_L23_001DF1DC;
extern s32 D_L23_001DF218;
extern u8 D_L23_001E1AC0[];
extern s32 func_L01_00452EC8(void *);
extern s32 func_L01_00452EF0(void *);
extern s32 func_L01_00448E90(void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00389468(f32, f32);
extern f32 func_00389410(f32);
extern f32 func_L01_0040C040(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_00388398(void *);
extern s32 func_L01_0044AF40(void *, f32);
extern s32 func_L01_00443790(void *, s32, f32, s32, f32, f32, s32, s32, s32);
extern void func_L01_00443648(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern void func_003BEC60(f32 *, void *, f32, f32, f32, f32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern f32 func_L01_00436500(void *);
extern void func_L01_004A6DF8(void *, s32);
extern void func_003BD360(void *);
extern void func_003BDA38(void *, s32, void *);
extern void func_L01_00457728(void *, void *);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_0045FEC8(void *, void *, void *, u32, u32, s32, s32, s32, s32);
extern int func_0037E0F0(void *, int, int);
extern void func_L06_003577D0(f32, void *, void *, void *, void *, s32, s32);
extern void func_L23_003ADDE8();
extern void func_L23_003AE510(u8 *);
extern void func_L23_003AE340();
extern void func_L23_003AE1F0();
extern void func_L23_003AEFE0(void *);
extern s32 func_L23_003AE810(u8 *, V4 *, f32, s32);


void func_L23_003ABF00(Moby_AD *m)
{
    Vars_AD *v;
    Cls_AD *c;
    V4 t;
    V4 u;
    f32 d;
    f32 dist;
    f32 ratio;
    f32 r;
    f32 dsq;
    f32 dist5;
    f32 ang5;
    f32 dist6;
    f32 dist10;
    f32 ang10;
    f32 dir2;
    f32 spd2;
    f32 step19;
    s32 i;
    s32 j;
    s32 ok;
    s32 id;
    u16 *p;
    u8 *e;
    Path_3B0200 *path;
    Node_3B0200 *n;

    if (func_L01_00448E90(&m->pos) == 0) {
        return;
    }
    v = m->vars;
    if (m->b20 == 1) {
        return;
    }
    func_L23_003ADDE8(m);
    switch (m->b95) {
    case 2:
        if (func_L01_00452EF0(m) != 0) {
            if (v->i244 != 0) {
                func_L01_00441FB8(m, 10, -1);
            }
        }
        if (v->h184 == 1) {
            func_L01_00441FB8(m, 5, 3);
        }
        break;
    case 3:
        if (func_L01_00452EF0(m) != 0) {
            if (v->i244 != 0) {
                func_L01_00441FB8(m, 10, -1);
            }
        }
        if (v->h184 == 1) {
            func_L01_00441FB8(m, 11, 4);
        }
        break;
    case 4:
        if (func_L01_00452EF0(m) != 0) {
            v->i240 = 0;
            v->i21C = 0;
        }
        if (v->h184 == 1) {
            t.x = func_00388960(func_00388A28(m->pos.x - v->f170, m->pos.y - v->f174)) * D_L23_001DE268;
            t.y = func_00388978(func_00388A28(m->pos.x - v->f170, m->pos.y - v->f174)) * D_L23_001DE268;
            t.z = 0.0f;
            vec_add_ab(&v->v250, &v->f170, &t);
            v->f24C = func_00388A28(v->f170 - m->pos.x, v->f174 - m->pos.y);
        } else if (v->h184 == 0) {
            if (func_L01_00452EF0(m) == 0) {
                if (D_001A7430[0] <= 0) {
                    func_L01_00441FB8(m, 0x13, 2);
                } else {
                    func_L01_00441FB8(m, 5, 3);
                }
            }
        }
        if (D_L23_001DE310 != 0) {
            if (D_L23_001DE310->vars->f30 <= 0.0f) {
                func_L23_003AE510((u8 *)m);
                func_003BD360(m);
                return;
            }
        }
        break;
    case 0:
        m->i98 = 0;
        m->f30.h[2] = (m->f30.h[2] | 0x41) & 0xEFFF;
        func_L01_004A6DF8(m, 1);
        break;
    }
    switch (m->b20) {
    case 1:
        break;
    case 4:
        if (func_L01_00452EC8(m) != 0) {
            if (m->b43 != 0) {
                func_003BE4F0(m, 0, func_0037E1D8(m->cls->p48->b10), 10);
            }
            v->i214 = func_0037E208(0x12C, 0x258);
        }
        if (v->i214 > 0) {
        } else if (m->b43 != 1) {
            func_003BE4F0(m, 1, 0, 10);
        }
        if (m->b42 == m->b43 && m->b42 == 1 && (m->b60 & 2) != 0) {
            func_003BE4F0(m, 0, func_0037E1D8(m->cls->p48->b10), 10);
            v->i214 = func_0037E208(0x12C, 0x258);
        }
        break;
    case 2:
        if ((m->f30.q & 0x104100000000UL) == 0x4100000000UL && m->i98 == 0 &&
            func_L01_0040C040(&m->pos, &D_001A4BE0.pos) < 100.0f) {
            break;
        }
        if (func_L01_00452EC8(m) != 0) {
            m->h96 = 0;
            m->f30.h[2] &= 0xFFBE;
            c = m->cls;
            m->f30.h[2] |= c->h44 & 0x1000;
            m->i98 = c->i10;
            if (m->b43 != 0x20) {
                func_003BE4F0(m, 0x20, 0, 0);
            }
        }
        if ((m->b60 & 2) != 0 && m->b42 == m->b43) {
            func_L01_00441FB8(m, 4, 2);
        }
        if (m->f30.b[1] != 0) {
            for (i = 0; i < 5; i++) {
                dir2 = func_0037E2A8();
                spd2 = func_0037E250(0.0f, 0.10000001f);
                t.x = spd2 * func_00388960(dir2);
                t.y = spd2 * func_00388978(dir2);
                t.z = func_0037E250(0.10000001f, 0.26666668f) - spd2;
                t.w = 1.5f;
                func_003886E8(&u, &t, 0.3f);
                u.w = 2.0f;
                func_L01_0045FEC8(&m->pos, &t, &u, 0x80808080, 0x60808080, 15, 30, 15, -1);
            }
        }
        break;
    case 3:
        if (func_L01_00452EC8(m) != 0) {
            if (v->i2B0 == 0) {
                func_003BD360(m);
                return;
            }
            v->i2B0 = v->i2B0 - 1;
        }
        func_00388398(&v->i210);
        if (v->i210 != 0) {
            break;
        }
        t = v->v290;
        path = &D_L23_001DEDCC->paths[v->i23C];
        for (j = 0; j < path->count; j++) {
            id = path->ids[j];
            n = &D_L23_001DF2C0[id];
            if (j == D_L23_001DE2B8) {
                continue;
            }
            dsq = func_L01_0040C040(&n->pos, &D_001A4BE0.pos);
            if (dsq < D_L23_001DE2AC * D_L23_001DE2AC) {
                continue;
            }
            if (D_L23_001DE2B0_003ABF00 * D_L23_001DE2B0_003ABF00 < dsq) {
                continue;
            }
            if (fabs_asm(func_003893C8(D_001A4BE0.rot.z, func_00388A28(n->pos.x - D_001A4BE0.pos.x, n->pos.y - D_001A4BE0.pos.y))) > 1.5707964f) {
                continue;
            }
            ok = 1;
            p = D_L23_0021C160[m->b21];
            while (m->b21 != 0xFF && m->b21 <= D_L23_001DF218 && p != 0 &&
                   ((s16)p[-1] >= 0 || p == D_L23_0021C160[m->b21])) {
                e = D_L23_001DF1DC + ((*p & 0x7FFF) << 8);
                if (e == 0) {
                    break;
                }
                if ((Moby_AD *)e != m) {
                    if (func_0037E0F0(e + 0x10, id, 0) != 0) {
                        ok = 0;
                        break;
                    }
                }
                p++;
            }
            if (ok != 0) {
                t = *(V4 *)&n->pos;
                t.z = func_003BE7F0(&t, 0, 0, 0.5f);
                break;
            }
        }
        qzero(&m->vF0);
        m->pos = t;
        v->v250 = t;
        v->f30 = (f32)v->h34;
        v->f24C = func_00388A28(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y);
        v->i218 = 0;
        v->i244 = 0;
        v->i21C = 0;
        v->i240 = 0;
        v->i228 = 0;
        v->i2BC = 0;
        func_L01_00441FB8(m, 2, 1);
        break;
    case 5:
        if (func_L01_00452EC8(m) != 0) {
            if (m->b43 != 1) {
                func_003BE4F0(m, 1, func_0037E1D8(m->cls->p4C->b10), 10);
            }
        }
        break;
    case 6:
        if (func_L01_00452EC8(m) != 0) {
            if (v->i218 == 0) {
                dist5 = func_L01_0040C040(&m->pos, &v->v250);
                ang5 = func_00388A28(m->pos.x - *(f32 *)&D_L23_001E1AC0[0], m->pos.y - *(f32 *)&D_L23_001E1AC0[4]);
                ang5 = fabs_asm(func_00389468(*(f32 *)&D_L23_001E1AC0[0x18], ang5));
                if (v->i220 != 0) {
                    if (dist5 > 200.0f) {
                        v->i218 = func_0037E1D8(2) ? 5 : 4;
                    } else if (ang5 > 0.5235988f) {
                        v->i218 = 1;
                    } else {
                        v->i218 = func_0037E1D8(2) ? (v->i244 ? 5 : 2) : 4;
                    }
                } else if (dist5 > 100.0f) {
                    v->i218 = 4;
                } else {
                    v->i218 = 3;
                }
                v->f224 = dist5;
            }
            func_L01_00458A70(m, D_L23_001DE248_003ABF00[v->i218], D_L23_001DE230[v->i218], 0.0034906587f, 0.104719765f);
            switch (v->i218) {
            case 1:
                if (m->b43 != 8) {
                    func_003BE4F0(m, 8, 0, 6);
                }
                break;
            case 2:
                if (m->b43 != 0x1D) {
                    func_003BE4F0(m, 0x1D, 0, 6);
                }
                break;
            case 3:
            case 4:
                func_L01_00441FB8(m, 7, -1);
                break;
            case 5:
                if (m->b43 != 0xB) {
                    func_003BE4F0(m, 0xB, 0, 6);
                }
                break;
            }
        } else if (m->b42 == m->b43 && (m->b60 & 2) != 0) {
            func_L01_00441FB8(m, 7, -1);
        }
        func_L23_003AE810((u8 *)m, &v->v250, v->f24C, v->i218);
        break;
    case 7:
        if (func_L01_00452EC8(m) != 0) {
            if (m->b94 != 6) {
                func_L01_00441FB8(m, 6, -1);
                break;
            }
            switch (v->i218) {
            case 1:
                if (m->b43 != 9) {
                    func_003BE4F0(m, 9, 0, 0);
                }
                break;
            case 2:
                if (m->b43 != 0x1E) {
                    func_003BE4F0(m, 0x1E, 0, 0);
                }
                break;
            case 3:
                if (m->b43 != 6) {
                    func_003BE4F0(m, 6, func_0037E1D8(m->cls->p60->b10), 6);
                }
                break;
            case 4:
                if (m->b43 != 7) {
                    func_003BE4F0(m, 7, func_0037E1D8(m->cls->p64->b10), 6);
                }
                break;
            case 5:
                if (m->b43 != 0xC) {
                    func_003BE4F0(m, 0xC, 0, 0);
                }
                break;
            }
        }
        if (func_L23_003AE810((u8 *)m, &v->v250, v->f24C, v->i218) == 0) {
            func_L01_00441FB8(m, 0xF, 4);
        }
        dist6 = func_L01_0040C040(&m->pos, &v->v250);
        if (v->iF4 == D_001A71A0[0] || dist6 < v->fA4 * v->fA4) {
            func_L01_00441FB8(m, 8, -1);
        } else if (dist6 - v->f224 > 16.0f) {
            func_L01_00441FB8(m, 8, -1);
        }
        break;
    case 8:
        if ((v->i218 == 2 || v->i218 == 5) && (m->b60 & 2) == 0) {
            break;
        }
        if (func_L01_00452EC8(m) != 0) {
            switch (v->i218) {
            case 1:
                if (m->b43 != 0xA) {
                    func_003BE4F0(m, 0xA, 0, 6);
                }
                break;
            case 2:
                if (m->b43 != 0x1F) {
                    func_003BE4F0(m, 0x1F, 0, 0);
                }
                break;
            case 5:
                if (m->b43 != 0xD) {
                    func_003BE4F0(m, 0xD, 0, 0);
                }
                break;
            case 3:
            case 4:
                break;
            }
            v->i218 = 0;
        } else if (m->b42 == m->b43) {
            if ((m->b60 & 2) != 0) {
                switch (m->b95) {
                case 2:
                    func_L01_00441FB8(m, 4, -1);
                    break;
                case 3:
                    func_L01_00441FB8(m, 5, -1);
                    break;
                case 4:
                    func_L01_00441FB8(m, 0xB, -1);
                    break;
                default:
                    func_L01_00441FB8(m, 4, 2);
                    break;
                }
            }
        }
        func_L23_003AE810((u8 *)m, &m->pos, v->f24C, v->i218);
        break;
    case 9:
        if (func_L01_00452EC8(m) != 0) {
            if (m->b43 != 0xE) {
                func_003BE4F0(m, 0xE, 0, 10);
            }
            v->i240 = 0;
        }
        func_L23_003AE810((u8 *)m, &m->pos, v->f24C, v->i218);
        if (m->b42 != m->b43) {
            break;
        }
        if (func_L01_0044AF40(m, 12.0f) != 0) {
            v->i244 = 1;
        }
        if (m->b42 == m->b43 && (m->b60 & 2) != 0) {
            switch (m->b95) {
            case 2:
                func_L01_00441FB8(m, 4, -1);
                break;
            case 3:
                func_L01_00441FB8(m, 5, -1);
                break;
            case 4:
                func_L01_00441FB8(m, 0xB, -1);
                break;
            default:
                func_L01_00441FB8(m, 4, 2);
                break;
            }
        }
        break;
    case 10:
        if (func_L01_00452EC8(m) != 0) {
            if (m->b43 != 0x12) {
                func_003BE4F0(m, 0x12, 0, 10);
            }
            v->i240 = 0;
        }
        if (m->b42 != m->b43) {
            break;
        }
        if (func_L01_0044AF40(m, 27.0f) != 0) {
            v->i244 = 0;
        }
        if (m->b42 == m->b43 && (m->b60 & 2) != 0) {
            switch (m->b95) {
            case 2:
                func_L01_00441FB8(m, 4, -1);
                break;
            case 3:
                func_L01_00441FB8(m, 5, -1);
                break;
            case 4:
                func_L01_00441FB8(m, 0xB, -1);
                break;
            default:
                func_L01_00441FB8(m, 4, 2);
                break;
            }
        }
        break;
    case 11:
        if (func_L01_00452EC8(m) != 0) {
            v->i240 = v->i21C;
            v->i22C = 0;
            dist10 = func_L01_0040C040(&m->pos, &v->v250);
            ang10 = func_00389468(D_001A4BE0.rot.z, func_00388A28(m->pos.x - D_001A4BE0.pos.x, m->pos.y - D_001A4BE0.pos.y));
            if (dist10 > 40.0f && v->i244 == 0 && func_0037E1D8(3) != 0) {
                func_L01_00441FB8(m, 0x10, -1);
            } else if (D_L23_001DE26C * D_L23_001DE26C < dist10) {
                if (v->i244 != 0 || func_0037E1D8(2) != 0) {
                    func_L01_00441FB8(m, 6, -1);
                } else {
                    func_L01_00441FB8(m, 9, -1);
                }
            } else if (v->i244 != 0) {
                if (v->i220 != 0 && ang10 < 0.5235988f && func_0037E1D8(2) != 0 && v->i240 != 2) {
                    func_L01_00441FB8(m, 0x11, -1);
                } else if (v->i240 == 0 && func_0037E1D8(2) != 0) {
                    func_L01_00441FB8(m, 0x12, -1);
                } else if (func_0037E1D8(3) != 0) {
                    func_L01_00441FB8(m, 0xE, -1);
                } else if (v->i240 != 6) {
                    func_L01_00441FB8(m, 0xF, -1);
                } else {
                    func_L01_00441FB8(m, 0xA, -1);
                }
            } else {
                if (v->i220 != 0 && ang10 < 0.5235988f && func_0037E1D8(2) != 0 && v->i240 != 2) {
                    func_L01_00441FB8(m, 0x11, -1);
                } else if (v->i240 == 0 && func_0037E1D8(2) != 0) {
                    func_L01_00441FB8(m, 0x12, -1);
                } else if (func_0037E1D8(3) != 0) {
                    func_L01_00441FB8(m, 0xC, -1);
                } else if (v->i240 != 4) {
                    func_L01_00441FB8(m, 0xD, -1);
                } else {
                    func_L01_00441FB8(m, 9, -1);
                }
            }
        }
        func_L23_003AE810((u8 *)m, &v->v250, v->f24C, v->i218);
        break;
    case 12:
        if (func_L01_00452EC8(m) != 0) {
            v->i21C = 3;
            if (m->b43 != 0x13) {
                func_003BE4F0(m, 0x13, 0, 6);
            }
        }
        func_L23_003AE810((u8 *)m, &v->v250, v->f24C, v->i218);
        if (func_L01_00436500(m) < 20.0f && m->b42 == m->b43) {
            func_L01_00443790(m, 4, D_L23_001DE274_003ABF00, 3, D_L23_001DE278 + (v->i220 != 0 ? D_L23_001DE280 : 0.0f), 1.0f, 0, 1, 0);
        }
        if (func_L01_0044AF40(m, 21.0f) != 0 && m->b42 == m->b43) {
            func_L01_00441FB8(m, 0xB, -1);
        }
        break;
    case 13:
        if (func_L01_00452EC8(m) != 0) {
            v->i21C = 4;
            if (m->b43 != 0x1C) {
                func_003BE4F0(m, 0x1C, 0, 6);
            }
        }
        func_L23_003AE810((u8 *)m, &v->v250, v->f24C, v->i218);
        if (func_L01_00436500(m) > 12.0f && m->b42 == m->b43) {
            func_L01_00443790(m, 9, D_L23_001DE274_003ABF00, 7, D_L23_001DE278 + (v->i220 != 0 ? D_L23_001DE280 : 0.0f), 1.0f, 0, 1, 0);
            func_L01_00443790(m, 10, D_L23_001DE274_003ABF00, 7, D_L23_001DE278 + (v->i220 != 0 ? D_L23_001DE280 : 0.0f), 1.0f, 0, 1, 0);
            func_L01_00443790(m, 8, D_L23_001DE274_003ABF00, 7, D_L23_001DE278 + (v->i220 != 0 ? D_L23_001DE280 : 0.0f), 1.0f, 0, 1, 0);
        }
        if (func_L01_0044AF40(m, 30.0f) != 0 && m->b42 == m->b43) {
            func_L01_00441FB8(m, 0xB, -1);
        }
        break;
    case 14:
        if (func_L01_00452EC8(m) != 0) {
            v->i21C = 5;
            if (m->b43 != 0xF) {
                func_003BE4F0(m, 0xF, 0, 6);
            }
        }
        func_L23_003AE810((u8 *)m, &v->v250, v->f24C, v->i218);
        if (m->b42 == m->b43) {
            func_L23_003AE340(m);
        }
        if (func_L01_0044AF40(m, 20.0f) != 0 && m->b42 == m->b43) {
            func_L01_00441FB8(m, 0xB, -1);
        }
        break;
    case 15:
        if (func_L01_00452EC8(m) != 0) {
            v->f230 = 0.0f;
            v->i21C = 5;
            v->f234 = 0.0f;
            if (m->b43 != 0x1B) {
                func_003BE4F0(m, 0x1B, 0, 6);
            }
        }
        func_L23_003AE810((u8 *)m, &v->v250, v->f24C, v->i218);
        if (m->b42 != m->b43) {
            break;
        }
        d = func_L01_00436500(m);
        if (d > 16.0f) {
            func_L23_003AE340(m);
        }
        if (func_L01_0044AF40(m, 16.0f) != 0) {
            v->f230 = 0.0f;
        }
        if (func_L01_0044AF40(m, 33.0f) != 0) {
            func_L01_00441FB8(m, 0xB, -1);
        }
        if (d > 8.0f && d < 16.0f) {
            func_003BEC60(&v->f234, &v->f230, 5.0f, 1.5625f, 0.25f, 1.0625f);
        }
        if (d > 16.0f && d < 24.0f) {
            func_003BEC60(&v->f234, &v->f230, 0.0f, 0.052083332f, 0.3125f, 0.9375f);
        }
        if (d > 8.0f && d < 24.0f) {
            t = m->pos;
            t.z = func_003BE7F0(&t, 0, 0, 0.5f) + v->f234;
            vec_sub_ab(&u, &t, &m->pos);
            func_L01_00457728(m, &u);
        }
        break;
    case 16:
        if (func_L01_00452EC8(m) != 0) {
            if (m->b43 != 0x14) {
                func_003BE4F0(m, 0x14, 0, 6);
            }
        }
        func_L23_003AE810((u8 *)m, &m->pos, func_00388A28(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y), 0);
        if (func_L01_0044AF40(m, 15.5f) != 0 && m->b42 == m->b43) {
            func_003BDA38(m, 4, &u);
            vec_sub_ab(&t, &v->v250, &u);
            func_00388830(&t, &t, 0.4166667f);
            func_L06_003577D0(D_L23_001DE27C, m, &t, &u, &m->vF0, 1, 0);
        }
        if (func_L01_0044AF40(m, 21.0f) != 0 && m->b42 == m->b43) {
            func_L01_00441FB8(m, 0xB, -1);
        }
        break;
    case 18:
        if (func_L01_00452EC8(m) != 0) {
            v->i21C = 1;
            if (v->i244 != 0) {
                if (m->b43 != 0x10) {
                    func_003BE4F0(m, 0x10, 0, 6);
                }
            } else if (m->b43 != 0x15) {
                func_003BE4F0(m, 0x15, 0, 6);
            }
        }
        func_L23_003AE810((u8 *)m, &m->pos, m->vF0.z, 0);
        if ((m->b60 & 2) != 0 && m->b42 == m->b43) {
            func_L01_00441FB8(m, 0xB, -1);
        }
        break;
    case 19:
        if (func_L01_00452EC8(m) != 0) {
            if (m->b43 != 2) {
                func_003BE4F0(m, 2, 0, 10);
            }
        }
        if ((m->b60 & 2) != 0 && m->b42 == m->b43) {
            func_L01_00441FB8(m, 4, 2);
        }
        func_L23_003AE810((u8 *)m, &m->pos, func_00388A28(D_001A4BE0.pos.x - m->pos.x, D_001A4BE0.pos.y - m->pos.y), 0);
        break;
    case 17:
        if (func_L01_00452EC8(m) != 0) {
            switch (func_0037E1D8(4)) {
            case 0:
            case 1:
                if (m->b43 != 4) {
                    func_003BE4F0(m, 4, 0, 6);
                }
                v->v260.x = func_00388960(func_00389380(1.5707964f, m->vF0.z)) * D_L23_001DE2A4;
                v->v260.y = func_00388978(func_00389380(1.5707964f, m->vF0.z)) * D_L23_001DE2A4;
                v->v260.z = 0.0f;
                vec_add_ab(&v->v260, &v->v260, &m->pos);
                v->v260.z = func_003BE7F0(&v->v260, 0, 0, 0.5f);
                break;
            case 2:
            case 3:
                if (m->b43 != 3) {
                    func_003BE4F0(m, 3, 0, 6);
                }
                v->v260.x = func_00388960(func_003893C8(1.5707964f, m->vF0.z)) * D_L23_001DE2A4;
                v->v260.y = func_00388978(func_003893C8(1.5707964f, m->vF0.z)) * D_L23_001DE2A4;
                v->v260.z = 0.0f;
                vec_add_ab(&v->v260, &v->v260, &m->pos);
                v->v260.z = func_003BE7F0(&v->v260, 0, 0, 0.5f);
                break;
            case 4:
                if (m->b43 != 5) {
                    func_003BE4F0(m, 5, 0, 6);
                }
                v->v260.x = func_00388960(func_00389380(3.1415927f, m->vF0.z)) * D_L23_001DE2A4;
                v->v260.y = func_00388978(func_00389380(3.1415927f, m->vF0.z)) * D_L23_001DE2A4;
                v->v260.z = 0.0f;
                vec_add_ab(&v->v260, &v->v260, &m->pos);
                v->v260.z = func_003BE7F0(&v->v260, 0, 0, 0.5f);
                break;
            }
            if (__builtin_fabsf(v->v260.z - m->pos.z) > 2.0f) {
                func_L01_00441FB8(m, 0xB, -1);
                break;
            }
            v->f230 = 0.0f;
            v->i21C = 2;
            v->f234 = 0.0f;
            v->v270 = m->pos;
        }
        if (m->b42 != m->b43) {
            break;
        }
        dist = func_L01_00436500(m);
        ratio = (dist - D_L23_001DE294_003ABF00) / (D_L23_001DE29C - D_L23_001DE294_003ABF00);
        if (ratio > 1.0f) {
            ratio = 1.0f;
        } else if (ratio < 0.0f) {
            ratio = 0.0f;
        }
        if (D_L23_001DE294_003ABF00 < dist && dist <= D_L23_001DE298) {
            v->f234 = D_L23_001DE2A8_003ABF00 * sqrt_asm((dist - D_L23_001DE294_003ABF00) / (D_L23_001DE298 - D_L23_001DE294_003ABF00));
        } else if (D_L23_001DE298 < dist && dist <= D_L23_001DE29C) {
            r = (dist - D_L23_001DE298) / (D_L23_001DE29C - D_L23_001DE298);
            v->f234 = D_L23_001DE2A8_003ABF00 * (1.0f - r * r);
        }
        if (v->f234 > 0.0f) {
            vec_sub_ab(&t, &v->v260, &v->v270);
            func_003886E8(&t, &t, ratio);
            vec_add_ba(&t, &t, &v->v270);
            t.z = v->v260.z + v->f234;
            vec_sub_ab(&u, &t, &m->pos);
            func_L01_00457728(m, &u);
        } else {
            func_L23_003AE810((u8 *)m, &v->v250, v->f24C, 0);
        }
        if (func_L01_0044AF40(m, 34.0f) != 0) {
            func_L01_00441FB8(m, 0xB, -1);
        }
        break;
    case 20:
        if (func_L01_00452EC8(m) != 0) {
            if (v->f30 <= 0.0f) {
                func_L23_003AE510((u8 *)m);
                func_L01_00441FB8(m, 3, 0);
                return;
            }
            if (v->f2B8 >= D_L23_001DE260) {
                if (m->b43 != 0x18) {
                    func_003BE4F0(m, 0x18, 0, 4);
                }
            } else if (m->b43 != 0x18) {
                func_003BE4F0(m, 0x18, 0, 4);
            }
            if (v->i220 != 0) {
                m->f48 = 1.5f;
            }
        }
        if (v->f2B8 < D_L23_001DE264) {
            step19 = v->f2B8;
        } else {
            step19 = D_L23_001DE264;
        }
        v->f2B8 = v->f2B8 - step19;
        t.x = func_00388960(v->f2B4) * step19;
        t.y = func_00388978(v->f2B4) * step19;
        t.z = 0.0f;
        func_L01_00457728(m, &t);
        u.x = func_00388960(v->f2B4) * D_L23_001DE288_003ABF00;
        u.y = func_00388978(v->f2B4) * D_L23_001DE288_003ABF00;
        u.z = 0.0f;
        vec_add_ba(&u, &u, &m->pos);
        u.z += D_L23_001DE288_003ABF00;
        func_L01_00443648((u8 *)m, (u8 *)&u, 3, 0, 1, 0, D_L23_001DE288_003ABF00, 20.0f, 1.0f);
        if (m->b42 == m->b43) {
            if ((m->b60 & 2) != 0) {
                func_L01_00441FB8(m, 5, 3);
            }
        }
        func_L23_003AE810((u8 *)m, &m->pos, func_00389410(v->f2B4 + 3.1415927f), 0);
        break;
    }
    func_L23_003AE1F0(m);
    func_L23_003AEFE0(m);
}
/* localdecomp:end func_L23_003ABF00 */
