#include "common.h"

/* NTSC-U counterpart of func_L13_003ABD48 (src/levels/shared/L13_003ABD48.c) */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct C_003ABD48 {
    u8 pad0[0x10];
    s32 h10;
    u8 pad14[0x10];
    f32 f24;
    u8 pad28[0x1C];
    u16 h44;
} C_003ABD48;
typedef struct P_003ABD48 {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[0xE];
    u8 b44;
    u8 b45;
    u8 b46;
    u8 pad47[0x18];
    u8 b5F;
    u8 pad60[0xD0];
    f32 tx;
    f32 ty;
    u8 pad138[0x44];
    f32 f17C;
    u8 pad180[0x8];
    s32 w188;
    u8 pad18C[0x78];
    f32 f204;
    u8 pad208[0xC];
    s32 *path;
    s16 h218;
    s16 h21A;
    u8 pad21C[0x164];
    s32 w380;
    s32 w384;
    s32 w388;
    s32 w38C;
    s32 w390;
    s32 w394;
    u8 pad398[0x8];
    f32 f3A0;
    f32 f3A4;
    s16 h3A8;
    u8 pad3AA[0x1];
    u8 b3AB;
    u8 pad3AC[0x1];
    u8 b3AD;
    u8 b3AE;
    u8 b3AF;
    u8 pad3B0[0x8];
    f32 *tgt;
    s16 t3BC;
    s16 t3BE;
    u8 pad3C0[0x4];
    f32 f3C4;
    f32 f3C8;
    s32 w3CC;
    u8 pad3D0[0xC];
    f32 f3DC;
    u8 pad3E0[0xC];
    s32 w3EC;
} __attribute__((aligned(8))) P_003ABD48;
typedef struct M_003ABD48 {
    u8 pad0[0x10];
    V4 pos;
    u8 state;
    u8 pad21[0x2];
    u8 alpha;
    struct C_003ABD48 *cls;
    u8 pad28[0x4];
    f32 scale;
    u8 pad30[0x4];
    u16 flags;
    u8 pad36[0xC];
    u8 anim;
    u8 anim2;
    u8 pad44[0x4];
    f32 f48;
    u8 pad4C[0x14];
    u8 b60;
    u8 pad61[0x7];
    struct P_003ABD48 *pv;
    u8 pad6C[0x28];
    u8 prev;
    u8 b95;
    u16 h96;
    s32 w98;
    u8 pad9C[0xE];
    u16 hAA;
    u8 padAC[0x14];
    V4 vel;
    u8 padD0[0x20];
    f32 fF0;
    f32 fF4;
    f32 fF8;
} M_003ABD48;
typedef struct { u8 pad0[0x18]; u8 b18; u8 b19; u16 h1A; u8 pad1C[0x14]; } Hit_003ABD48;

/* localdecomp:start func_L13_003AA178 */
extern s32 D_001D545C_sda_003AA178;
__asm__(".extern D_001D545C_sda_003AA178, 4");
extern s32 D_001D545C_003AA178;
__asm__(".extern D_001D545C_003AA178, 16");
extern u8 D_0014275C_003AA178[];
extern u8 D_0014275B_003AA178[];
extern s32 D_L13_001D6694;
__asm__(".extern D_L13_001D6694, 4");
extern s32 D_L13_001DE734;
__asm__(".extern D_L13_001DE734, 4");
extern f32 D_L13_001DA930;
__asm__(".extern D_L13_001DA930, 4");
extern f32 D_L13_001DA938;
__asm__(".extern D_L13_001DA938, 4");
extern f32 D_L13_001DE690;
__asm__(".extern D_L13_001DE690, 4");
extern f32 D_L13_001DE694;
__asm__(".extern D_L13_001DE694, 4");
extern f32 D_L13_001DE698;
__asm__(".extern D_L13_001DE698, 4");
extern f32 D_L13_001DE6A8;
__asm__(".extern D_L13_001DE6A8, 4");
extern f32 D_L13_001DE6AC;
__asm__(".extern D_L13_001DE6AC, 4");
extern f32 D_L13_001DE6C0;
__asm__(".extern D_L13_001DE6C0, 4");
extern f32 D_L13_001DE6C4;
__asm__(".extern D_L13_001DE6C4, 4");
extern f32 D_L13_001DE6C8;
__asm__(".extern D_L13_001DE6C8, 4");
extern f32 D_L13_001DE6D0;
__asm__(".extern D_L13_001DE6D0, 4");
extern f32 D_L13_001DE6D4;
__asm__(".extern D_L13_001DE6D4, 4");
extern f32 D_L13_001DE6D8;
__asm__(".extern D_L13_001DE6D8, 4");
extern f32 D_L13_001DE6F0;
__asm__(".extern D_L13_001DE6F0, 4");
extern s32 D_L13_001DE6F4;
__asm__(".extern D_L13_001DE6F4, 4");
extern s32 D_L13_001DE6F8;
__asm__(".extern D_L13_001DE6F8, 4");
extern s32 D_L13_001DE6FC;
__asm__(".extern D_L13_001DE6FC, 4");
extern s32 D_L13_001DE700;
__asm__(".extern D_L13_001DE700, 4");
extern u16 D_L13_001DE704;
__asm__(".extern D_L13_001DE704, 4");
extern s32 D_L13_001DE708;
__asm__(".extern D_L13_001DE708, 4");
extern f32 D_L13_001DE728;
__asm__(".extern D_L13_001DE728, 4");
extern f32 D_L13_001DE72C;
__asm__(".extern D_L13_001DE72C, 4");
extern s32 D_L13_001DE730;
__asm__(".extern D_L13_001DE730, 4");
extern f32 D_L13_002EFE50[];
extern f32 D_L13_002F0030[];
extern s32 *D_L13_0021D5C0[];
extern s32 D_L13_001D66B0_003AA178;

extern s32 func_0037E1D8(s32);
extern s32 func_003883C8(s16 *);
extern void func_003886E8(f32, void *, void *);
extern f32 func_00388800(void *, void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern void func_003BD9A0(M_003ABD48 *, s32, void *);
extern void func_003BDA38(M_003ABD48 *, s32, void *);
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern f32 func_003BE7F0(f32, void *, s32, s32);
extern void func_003CF790(f32, void *, s32, M_003ABD48 *, void *);
extern void func_L01_003154D8(M_003ABD48 *, s32, void *);
extern s32 func_L01_00417EA0(void);
extern f32 func_L01_00436500(M_003ABD48 *);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_L01_00442F20(M_003ABD48 *, s32, s32);
extern void func_L01_00443628(f32, void *, M_003ABD48 *, s32, void *);
extern s32 func_L01_0044AF40(f32, M_003ABD48 *);
extern void func_L01_0044E010(M_003ABD48 *, void *, s32);
extern void func_L01_0044E358(void *, void *, s32);
extern s32 func_L01_00451078(M_003ABD48 *, void *);
extern s32 func_L01_00452EC8(M_003ABD48 *);
extern s32 func_L01_00457440(M_003ABD48 *, void *);
extern s32 func_L01_004576E8(M_003ABD48 *);
extern void func_L01_00457708(f32, M_003ABD48 *);
extern void func_L01_00458A08(f32, M_003ABD48 *);
extern void func_L01_00458A70(f32, f32, f32, f32, M_003ABD48 *);
extern s32 func_L01_00458AE0(M_003ABD48 *, s32);
extern void func_L01_00458E48(M_003ABD48 *, s32 *, s32, s32);
extern void func_L01_004A6DF8(M_003ABD48 *, s32);
extern s32 func_L01_004B6C68(void);
extern s16 func_L06_00455BC0(void *, s32 *, s32);
extern void func_L13_003ABCB0(u8 *, u8 *);
extern s32 func_L13_003ABCE8(M_003ABD48 *);
extern s32 func_L13_003AC018(M_003ABD48 *);
extern void func_L13_003AC720(M_003ABD48 *);
extern void func_L13_003AC810(u8 *, s32);
extern void func_L13_003AC890_003AA178(u8 *);
extern void func_L13_003ACA98(u8 *);
extern void func_L13_003ACAE0(u8 *);
extern void func_L13_003ACBA8(M_003ABD48 *);
extern void func_L13_003ACC28(u8 *);
extern void func_L13_003ACCB0(u8 *);
extern void func_L13_003ACD60(void *);
extern void func_L13_003ACDE0(void *);
extern void func_L13_003ACE60(M_003ABD48 *);
extern s32 func_L13_003ACEF8(M_003ABD48 *, void *);
extern s32 func_L13_003ACFF0(M_003ABD48 *, s32);
extern void func_L13_003AD260(u8 *, f32, f32, f32);
extern void func_L13_003AD2C8(void *, f32, f32, f32);
extern f32 *func_L13_003AD300(M_003ABD48 *, s32, s32);
extern s32 func_L13_003AD478(u8 *);
extern void func_L13_003AD510(M_003ABD48 *);
extern void func_L13_003AD5D0(M_003ABD48 *);
extern void func_L13_003AD800(M_003ABD48 *);
extern void func_L13_003B2720(M_003ABD48 *, void *, void *, s32, s32);


void func_L13_003AA178(M_003ABD48 *m) {
    P_003ABD48 *p = m->pv;
    V4 buf[4];
    V4 d;

    if (m->state == 0 && func_L13_003ABCE8(m) == 0) {
        return;
    }
    if (func_L13_003AC018(m) == 0) {
        func_L13_003AC810((u8 *)m, 1);
        return;
    }
    if (D_L13_001D6694 == 2) {
        if (((u8)m->flags ^ 1) & 1) {
            m->w98 = 0;
            m->flags = (m->flags | 0x41) & 0xEFFF;
            func_L01_004A6DF8(m, 1);
            p->w3EC = 1;
        }
        return;
    }
    if (p->w3EC != 0) {
        C_003ABD48 *c = m->cls;
        m->flags &= 0xFFBE;
        m->flags |= c->h44 & 0x1000;
        m->w98 = c->h10;
        p->w3EC = 0;
    }
    if ((D_L13_001DE734 != 0 || D_0014275C_003AA178[0] != 0 || D_001D545C_003AA178 == 0x16) && p->w3CC == 0) {
        if (D_001D545C_sda_003AA178 != 0x16) {
            func_L01_00442F20(m, 0x1BA3, 0x1B39);
            if (D_001D545C_003AA178 == 0x10 || D_001D545C_003AA178 == 4 || D_001D545C_003AA178 == 9) {
                p->h34 = 0x46;
                p->b44 = 0x2D;
                if (func_L01_00417EA0() != 0) {
                    p->h34 = p->h34 * ((D_001D545C_003AA178 == 7 && D_0014275B_003AA178[0] != 0) ? D_L13_001DA930 : D_L13_002EFE50[D_001D545C_003AA178]);
                    p->b44 = p->b44 * ((D_001D545C_003AA178 == 7 && D_0014275B_003AA178[0] != 0) ? D_L13_001DA938 : D_L13_002F0030[D_001D545C_003AA178]);
                }
                p->b45 = p->b44;
                p->b46 = p->b44;
                p->f30 = p->h34;
            }
        } else {
            func_L01_00442F20(m, 0x1F07, 0x1B39);
        }
        m->hAA = 0x1B39;
        p->w3CC = 1;
    } else if (D_L13_001DE734 == 0 && D_0014275C_003AA178[0] == 0) {
        func_L01_00442F20(m, 0x1B39, 0x1B39);
    }
    if (p->b3AD != 0 && func_L01_004B6C68() != 0) {
        return;
    }
    switch (m->state) {
    case 35:
        if (func_L01_0044AF40(0.0f, m) != 0 && m->anim == 0xB) {
            func_003BD9A0(m, 2, buf);
            vec_sub_ab(&d, &p->tx, &buf[3]);
            func_00388830(&d, &m->vel, 0.5f);
            d.z -= 0.04f;
            func_L13_003B2720(m, &buf[3], &d, p->b44, p->b5F ? 0x8010001 : 0x8000001);
        }
        break;
    case 1:
        if (func_L01_00452EC8(m) != 0) {
            p->t3BC = (p->h3A8);
        }
        func_L13_003ACE60(m);
        if (func_L13_003AD478((u8 *)m) != 0 && func_003883C8(&p->t3BC) != 0) {
            func_L13_003ACA98((u8 *)m);
        }
        break;
    case 2:
        if (func_L01_00452EC8(m) != 0) {
            s32 *path;
            func_L13_003AD260((u8 *)p + 0x150, D_L13_001DE690 * 0.0166666675f, D_L13_001DE694 * 0.00027777778450399637f, D_L13_001DE698 * 0.00027777778450399637f);
            path = D_L13_0021D5C0[p->w384];
            p->path = path;
            buf[0] = m->pos;
            p->h218 = func_L06_00455BC0(buf, path, 1);
            if (*path >> 1 < p->h218) {
                p->h21A = 0;
            } else {
                p->h21A = *path - 1;
            }
            if (m->prev != m->state) {
                p->t3BC = (p->h3A8);
            }
        }
        if (func_L13_003AD478((u8 *)m) != 0) {
            if (func_003883C8(&p->t3BC) != 0) {
                func_L13_003ACA98((u8 *)m);
            }
        } else if (func_L13_003ACFF0(m, p->w384) != 0) {
            func_L01_00441FB8((u8 *)m, 2, -1);
            break;
        }
        break;
    case 3:
        if (func_L01_00452EC8(m) != 0) {
            s32 *path;
            func_L13_003AD260((u8 *)p + 0x150, p->f3A0 * 0.0166666675f, p->f3A0 * 0.00027777778450399637f, p->f3A0 * 0.00027777778450399637f);
            path = D_L13_0021D5C0[p->w380];
            p->path = path;
            buf[0] = m->pos;
            p->h218 = func_L06_00455BC0(buf, path, 1);
            p->h21A = 0;
        }
        if (func_L13_003AD478((u8 *)m) != 0) {
            func_L13_003ACAE0((u8 *)m);
        } else if (func_L13_003ACFF0(m, p->w380) != 0) {
            func_L01_00441FB8((u8 *)m, 2, -1);
            break;
        }
        break;
    case 4:
        func_L01_004576E8(m);
        if (func_L01_00452EC8(m) != 0) {
            p->t3BC = (D_L13_001DE6F4 + func_0037E1D8((f32)(D_L13_001DE6F4) * D_L13_001DE6F0));
            if (m->prev != m->state) {
                p->t3BE = (p->h3A8);
            }
        }
        if (func_L13_003AD478((u8 *)m) != 0) {
            if (func_003883C8(&p->t3BE) != 0) {
                func_L13_003ACBA8(m);
            }
        } else if (m->anim == m->anim2) {
            if (m->anim == 0) {
                if (func_003883C8(&p->t3BC) != 0 && m->anim2 != 1) {
                    func_003BE4F0((u8 *)m, 1, 0, 3);
                }
            } else if (m->b60 & 2) {
                func_003BE4F0((u8 *)m, 0, 0, 3);
                func_L01_00441FB8((u8 *)m, 4, -1);
            }
        }
        break;
    case 5:
        if (func_L01_00452EC8(m) != 0) {
            s32 *path = D_L13_0021D5C0[p->w384];
            f32 d;
            func_L01_00458A70(D_L13_001DE6AC * 0.00027777778450399637f, D_L13_001DE6A8 * 0.0166666675f, 0.0069813174195587635f, 0.20943953096866608f, m);
            d = func_00388800(&m->pos, path + 4);
            if (func_00388800(&m->pos, path + *path * 4) < d) {
                func_L01_00458E48(m, path, 0, *path - 1);
            } else {
                func_L01_00458E48(m, path, *path - 1, 0);
            }
            p->t3BC = (p->h3A8);
        }
        if (func_L13_003AD478((u8 *)m) != 0) {
            if (func_003883C8(&p->t3BC) != 0) {
                func_L13_003ACBA8(m);
            }
        } else if (func_L01_00458AE0(m, p->w384) != 0) {
            func_L01_00441FB8((u8 *)m, 5, -1);
            break;
        }
        break;
    case 6:
        if (func_L01_00452EC8(m) != 0) {
            s32 *path = D_L13_0021D5C0[p->w380];
            p->path = path;
            buf[0] = m->pos;
            p->h218 = func_L06_00455BC0(buf, path, 1);
            p->h21A = 0;
        }
        if (func_L13_003AD478((u8 *)m) != 0) {
            func_L13_003ACC28((u8 *)m);
        } else if (func_L01_00458AE0(m, p->w380) != 0) {
            func_L01_00441FB8((u8 *)m, 5, -1);
            break;
        }
        break;
    case 7:
        if (func_L01_00452EC8(m) != 0) {
            s32 *path = D_L13_0021D5C0[p->w388];
            p->path = path;
            buf[0] = m->pos;
            p->h218 = func_L06_00455BC0(buf, path, 1);
            p->h21A = *path - 1;
        }
        if (func_L01_00458AE0(m, p->w388) != 0) {
            m->b95 = 1;
            func_L13_003ACBA8(m);
        }
        break;
    case 8:
        if (func_L01_00452EC8(m) != 0) {
            s32 *path;
            func_L13_003AD260((u8 *)p + 0x150, p->f3A0 * 0.0166666675f, p->f3A0 * 0.00027777778450399637f, p->f3A0 * 0.00027777778450399637f);
            path = D_L13_0021D5C0[p->w380];
            p->path = path;
            buf[0] = m->pos;
            p->h218 = func_L06_00455BC0(buf, path, 1);
            p->h21A = *path - 1;
        }
        if (func_L13_003AD478((u8 *)m) == 0) {
            func_L01_00441FB8((u8 *)m, 9, -1);
            break;
        }
        if (func_L13_003ACFF0(m, p->w380) != 0) {
            func_L13_003ACAE0((u8 *)m);
        }
        break;
    case 9:
        func_L13_003ACE60(m);
        if (func_L01_00452EC8(m) != 0) {
            p->t3BC = (D_L13_001DE6F8 + func_0037E1D8((f32)(D_L13_001DE6F8) * D_L13_001DE6F0));
        }
        if (func_L13_003AD478((u8 *)m) != 0) {
            func_L13_003ACA98((u8 *)m);
        } else if (func_003883C8(&p->t3BC) != 0) {
            if (p->w384 != -1) {
                if (p->w380 != -1) {
                    func_L01_00441FB8((u8 *)m, 3, -1);
                } else {
                    func_L01_00441FB8((u8 *)m, 2, -1);
                }
            } else {
                if (m->anim2 != 0x18) {
                    func_003BE4F0((u8 *)m, 0x18, 0, 0xA);
                }
                func_L01_00441FB8((u8 *)m, 1, -1);
            }
        }
        break;
    case 10:
        if (func_L01_00452EC8(m) != 0) {
            func_L13_003AD260((u8 *)p + 0x150, p->f3A4 * 0.0166666675f, p->f3A4 * 0.00027777778450399637f, p->f3A4 * 0.00027777778450399637f);
            p->tgt = func_L13_003AD300(m, p->w390, 1);
        }
        if (func_L13_003AD478((u8 *)m) == 0) {
            func_L01_00441FB8((u8 *)m, 9, -1);
            break;
        }
        if ((func_L13_003ACEF8(m, p->tgt + 12) & 0x80) || func_00388800(&m->pos, p->tgt + 12) < 0.5f) {
            if (m->anim2 != 0x1A) {
                func_003BE4F0((u8 *)m, 0x1A, 0, 0xC);
            }
            func_L01_00441FB8((u8 *)m, 0xD, -1);
            break;
        }
        break;
    case 11:
        func_L01_00458A08(func_00388A28(p->tx - m->pos.x, p->ty - m->pos.y), m);
        func_L13_003ACE60(m);
        if (m->b60 & 2) {
            if (m->anim2 != 0xA) {
                func_003BE4F0((u8 *)m, 0xA, 0, 0);
            }
            func_L01_00441FB8((u8 *)m, 0xC, -1);
            break;
        }
        break;
    case 12:
        func_L01_00458A08(func_00388A28(p->tx - m->pos.x, p->ty - m->pos.y), m);
        func_L13_003ACE60(m);
        if (func_L01_00452EC8(m) != 0) {
            p->t3BC = (D_L13_001DE700 + func_0037E1D8((f32)(D_L13_001DE700) * D_L13_001DE6F0));
        }
        if (func_003883C8(&p->t3BC) != 0) {
            if (m->anim2 != 0xB) {
                func_003BE4F0((u8 *)m, 0xB, 0xC, 0);
            }
            func_L01_00441FB8((u8 *)m, 0xD, -1);
            break;
        }
        break;
    case 13:
        func_L01_00458A08(func_00388A28(p->tx - m->pos.x, p->ty - m->pos.y), m);
        if (func_L01_00452EC8(m) != 0) {
            p->t3BC = D_L13_001DE704 + 1;
        }
        if ((m->b60 & 2) && func_003883C8(&p->t3BC) != 0) {
            if (m->anim2 != 0x18) {
                func_003BE4F0((u8 *)m, 0x18, 0, 0x10);
            }
            func_L01_00441FB8((u8 *)m, 0xF, -1);
        }
        if (func_L01_0044AF40(57.0f, m) != 0 && m->anim == 0x1A) {
            func_L13_003AD5D0(m);
        }
        break;
    case 14:
        func_L01_00458A08(func_00388A28(p->tx - m->pos.x, p->ty - m->pos.y), m);
        func_L13_003ACE60(m);
        if (m->b60 & 2) {
            if (m->anim2 != 0xA) {
                func_003BE4F0((u8 *)m, 0xA, 0, 0);
            }
            func_L01_00441FB8((u8 *)m, 0xF, -1);
            break;
        }
        break;
    case 15:
        func_L01_00458A08(func_00388A28(p->tx - m->pos.x, p->ty - m->pos.y), m);
        func_L13_003ACE60(m);
        if (m->b60 & 2) {
            if (func_L13_003AD478((u8 *)m) == 0) {
                if (m->anim2 != 0x18) {
                    func_003BE4F0((u8 *)m, 0x18, 0, 6);
                }
                func_L01_00441FB8((u8 *)m, 9, -1);
            } else {
                func_L13_003ACAE0((u8 *)m);
            }
        }
        break;
    case 16:
        if (func_L01_00452EC8(m) != 0) {
            m->b95 = 1;
            p->w188 &= ~0x414;
            p->f17C = 0.011111111380159855f;
            p->f3C8 = 0.13333334028720856f;
        }
        if (p->b3AE != 0) {
            func_L01_004576E8(m);
            func_L01_00443628(1.0f, (Hit_003ABD48 *)buf, m, 0x08000000, &D_L13_001D66B0_003AA178);
            ((Hit_003ABD48 *)buf)->b18 = 0;
            ((Hit_003ABD48 *)buf)->b19 = 1;
            ((Hit_003ABD48 *)buf)->h1A = m->hAA;
            func_003BDA38(m, 0, &buf[3]);
            func_003CF790(1.5f, &buf[3], 0x10, m, (Hit_003ABD48 *)buf);
            if (m->pos.z <= func_003BE7F0(0.5f, &m->pos, 0, 0)) {
                p->f17C = 0.0027222223579883575f;
                func_L01_0044E010(m, &d, 1);
                func_L01_0044E358(&m->vel, &d, 0);
                m->fF0 = 0.0f;
                m->fF4 = 0.0f;
                if (m->anim2 != 4) {
                    func_003BE4F0((u8 *)m, 4, 1, 4);
                }
                func_L01_00441FB8((u8 *)m, 0x11, -1);
                if (p->b3AE != 0 && m->anim2 != 0x19) {
                    func_003BE4F0((u8 *)m, 0x19, 0, 4);
                }
            }
        } else if (func_L01_00451078(m, (u8 *)p + 0x70) & 2) {
            p->f17C = 0.0027222223579883575f;
            func_L01_0044E010(m, buf, 1);
            func_L01_0044E358(&m->vel, buf, 0);
            m->fF0 = 0.0f;
            m->fF4 = 0.0f;
            func_L13_003AD2C8((u8 *)p + 0x150, D_L13_001DE6C0 * 0.017453292f * 0.0166666675f, D_L13_001DE6C4 * 0.017453292f * 0.00027777778450399637f, D_L13_001DE6C8 * 0.017453292f * 0.00027777778450399637f);
            func_L13_003ACC28((u8 *)m);
        }
        break;
    case 17:
        func_L01_004576E8(m);
        if (func_L01_0044AF40(20.0f, m) != 0) {
            func_L13_003AD2C8((u8 *)p + 0x150, D_L13_001DE6C0 * 0.017453292f * 0.0166666675f, D_L13_001DE6C4 * 0.017453292f * 0.00027777778450399637f, D_L13_001DE6C8 * 0.017453292f * 0.00027777778450399637f);
            func_L13_003ACC28((u8 *)m);
        }
    case 18:
        if (m->b60 & 2) {
            func_L13_003AD2C8((u8 *)p + 0x150, D_L13_001DE6C0 * 0.017453292f * 0.0166666675f, D_L13_001DE6C4 * 0.017453292f * 0.00027777778450399637f, D_L13_001DE6C8 * 0.017453292f * 0.00027777778450399637f);
            func_L13_003ACC28((u8 *)m);
        }
        break;
    case 19:
        if (func_L01_00452EC8(m) != 0) {
            s32 *path = D_L13_0021D5C0[p->w380];
            p->path = path;
            buf[0] = m->pos;
            p->h218 = func_L06_00455BC0(buf, path, 0);
            p->h21A = *path - 1;
        }
        if (func_L13_003AD478((u8 *)m) == 0) {
            goto walk;
        }
        if (func_L01_00458AE0(m, p->w380) != 0) {
            func_L13_003ACC28((u8 *)m);
        }
        break;
    case 20:
        func_L01_004576E8(m);
        if (func_L01_00452EC8(m) != 0) {
            if (m->prev != m->state) {
                p->t3BC = (D_L13_001DE6F8 + func_0037E1D8((f32)(D_L13_001DE6F8) * D_L13_001DE6F0));
            }
            p->t3BE = (D_L13_001DE6FC + func_0037E1D8((f32)(D_L13_001DE6FC) * D_L13_001DE6F0));
        }
        if (func_L13_003AD478((u8 *)m) != 0) {
            func_L13_003ACBA8(m);
            break;
        }
        if (func_003883C8(&p->t3BC) != 0) {
            if (p->w384 != -1 && m->b95 != 0) {
                func_L13_003ACD60(m);
                if (p->w380 != -1) {
                    func_L01_00441FB8((u8 *)m, 6, -1);
                } else {
                    func_L01_00441FB8((u8 *)m, 5, -1);
                }
            } else {
                func_L01_00441FB8((u8 *)m, 4, -1);
            }
            break;
        }
        if (m->anim == m->anim2) {
            if (m->anim == 0) {
                if (func_003883C8(&p->t3BE) != 0 && m->anim2 != 1) {
                    func_003BE4F0((u8 *)m, 1, 0, 3);
                }
            } else if (m->b60 & 2) {
                func_003BE4F0((u8 *)m, 0, 0, 3);
                func_L01_00441FB8((u8 *)m, 0x14, -1);
            }
        }
        break;
    case 21:
        if (func_L01_00452EC8(m) != 0) {
            p->tgt = func_L13_003AD300(m, p->w394, 0);
        }
        if (func_L13_003AD478((u8 *)m) == 0) {
            goto walk;
        }
        if (func_L01_00457440(m, p->tgt + 12) & 0x80) {
            if (func_00389468(func_00388A28(p->tx - m->pos.x, p->ty - m->pos.y), m->fF8) > D_L13_001DE6D0 * 0.017453292f) {
                func_L01_00441FB8((u8 *)m, 0x16, -1);
                break;
            }
            func_L13_003ACCB0((u8 *)m);
        }
        break;
    case 23:
        if (func_L01_00452EC8(m) != 0) {
            p->tgt = func_L13_003AD300(m, p->w38C, 0);
        }
        if (func_L13_003AD478((u8 *)m) == 0) {
            goto walk;
        }
        if (func_L01_00457440(m, p->tgt + 12) & 0x80) {
            f32 deg = 0.017453292f;
            if (func_00389468(func_00388A28(p->tx - m->pos.x, p->ty - m->pos.y), m->fF8) > D_L13_001DE6D0 * deg) {
                if (m->anim2 != 2) {
                    func_003BE4F0((u8 *)m, 2, 0, 4);
                }
                func_L01_00441FB8((u8 *)m, 0x18, -1);
                break;
            }
                if (func_00389468(m->fF8, func_00388A28(p->tgt[0], p->tgt[1]) > D_L13_001DE6D4 * deg ? 1.0f : 0.0f) == 0.0f) {
                if (m->anim2 != 6) {
                    func_003BE4F0((u8 *)m, 6, 0, 4);
                }
                func_L01_00441FB8((u8 *)m, 0x19, -1);
                break;
            }
            func_L13_003ACCB0((u8 *)m);
        }
        break;
    case 24:
        {
            f32 deg = 0.017453292f;
            u8 *q = (u8 *)p + 0x150;
            f32 a = func_00388A28(p->tx - m->pos.x, p->ty - m->pos.y);
            func_L01_00457708(a, m);
            m->f48 = *(f32 *)(q + 0xB4) * D_L13_001DE6D8;
            if (func_00389468(m->fF8, a) < D_L13_001DE6D0 * 0.5f * deg) {
                if (func_00389468(m->fF8, func_00388A28(p->tgt[0], p->tgt[1]) > D_L13_001DE6D4 * deg ? 1.0f : 0.0f) == 0.0f) {
                    if (m->anim2 != 6) {
                        func_003BE4F0((u8 *)m, 6, 0, 4);
                    }
                    func_L01_00441FB8((u8 *)m, 0x19, -1);
                    break;
                }
                func_L13_003ACCB0((u8 *)m);
            }
        }
        break;
    case 25:
        func_L01_004576E8(m);
        if (m->b60 & 2) {
            if (m->anim2 != 7) {
                func_003BE4F0((u8 *)m, 7, 0, 4);
            }
            func_L01_00441FB8((u8 *)m, 0x1A, -1);
            break;
        }
        break;
    case 26:
        func_L01_004576E8(m);
        if (func_L01_00452EC8(m) != 0) {
            p->t3BC = (D_L13_001DE708 + func_0037E1D8((f32)(D_L13_001DE708) * D_L13_001DE6F0));
        }
        if (func_003883C8(&p->t3BC) != 0) {
            if (m->anim2 != 8) {
                func_003BE4F0((u8 *)m, 8, 0, 4);
            }
            func_L01_00441FB8((u8 *)m, 0x1B, -1);
            break;
        }
        break;
    case 27:
        func_L01_004576E8(m);
        if (m->b60 & 2) {
            func_L13_003ACD60(m);
            func_L01_00441FB8((u8 *)m, 0x16, -1);
            break;
        }
        break;
    case 22:
        {
            f32 a = func_00388A28(p->tx - m->pos.x, p->ty - m->pos.y);
            func_L01_00457708(a, m);
            if (func_00389468(m->fF8, a) < D_L13_001DE6D0 * 0.5f * 0.017453292f) {
                func_L13_003ACCB0((u8 *)m);
            }
        }
        break;
    case 28:
        func_L01_004576E8(m);
        func_L13_003AD510(m);
        if (m->b60 & 2) {
            if (m->anim2 != 0xA) {
                func_003BE4F0((u8 *)m, 0xA, 0, 0);
            }
            func_L01_00441FB8((u8 *)m, 0x1D, -1);
            break;
        }
        break;
    case 29:
        func_L01_004576E8(m);
        func_L13_003AD510(m);
        if (func_L01_00452EC8(m) != 0) {
            p->t3BC = (D_L13_001DE700 + func_0037E1D8((f32)(D_L13_001DE700) * D_L13_001DE6F0));
        }
        if (func_003883C8(&p->t3BC) != 0) {
            if (m->anim2 != 0xB) {
                func_003BE4F0((u8 *)m, 0xB, 0xC, 0);
            }
            func_L01_00441FB8((u8 *)m, 0x1E, -1);
            break;
        }
        break;
    case 30:
        func_L01_004576E8(m);
        func_L13_003AD510(m);
        if (func_L01_00452EC8(m) != 0) {
            p->t3BC = D_L13_001DE704 + 1;
        }
        if (m->b60 & 2) {
            if (func_003883C8(&p->t3BC) != 0) {
                if (m->anim2 != 0xC) {
                    func_003BE4F0((u8 *)m, 0xC, 0, 0);
                }
                func_L01_00441FB8((u8 *)m, 0x1F, -1);
                break;
            }
            func_L13_003AD5D0(m);
        }
        break;
    case 31:
        func_L01_004576E8(m);
        func_L13_003AD510(m);
        if (func_L01_0044AF40(33.0f, m) != 0) {
            if (m->b95 == 2) {
                func_L13_003ACDE0(m);
                func_L01_00441FB8((u8 *)m, 7, -1);
                break;
            }
            goto back;
        }
        break;
    case 32:
        func_L01_004576E8(m);
        func_L13_003AD510(m);
        if (m->b60 & 2) {
            if (m->b95 == 2) {
                func_L13_003ACDE0(m);
                func_L01_00441FB8((u8 *)m, 7, -1);
                break;
            }
            goto back;
        }
        break;
    case 33:
        {
            f32 t;
            func_L01_004576E8(m);
            t = func_L01_00436500(m);
            if (t > 17.0f && t < 24.0f) {
                func_L13_003AD800(m);
            }
            if (m->b60 & 2) {
            back:
                if (func_L13_003AD478((u8 *)m) != 0) {
                    func_L13_003ACC28((u8 *)m);
                } else {
                walk:
                    if (m->anim2 != 1) {
                        func_003BE4F0((u8 *)m, 1, 0, 4);
                    }
                    func_L01_00441FB8((u8 *)m, 0x14, -1);
                    break;
                }
            }
        }
        break;
    case 34:
        {
            s32 r;
            func_L01_004576E8(m);
            r = func_L01_00451078(m, (u8 *)p + 0x70);
            if (r & 1) {
                func_L13_003AC720(m);
                func_L01_003154D8(m, 0, func_L13_003AC890_003AA178);
            } else if (r & 2) {
                if (p->b3AB == 0 && p->b3AF == 0 && p->w388 != -1 && p->f30 < p->h34 * p->f3C4) {
                    func_L13_003ACDE0(m);
                    m->b95 = 2;
                    func_L01_00441FB8((u8 *)m, 7, -1);
                    p->b3AF = 1;
                } else {
                    func_L13_003ACC28((u8 *)m);
                }
            }
        }
        break;
    case 38:
        {
            if (func_L01_00452EC8(m) != 0) {
                func_L13_003AD260((u8 *)p + 0x150, D_L13_001DE690 * 0.0166666675f, D_L13_001DE694 * 0.00027777778450399637f, D_L13_001DE698 * 0.00027777778450399637f);
            }
            if (p->f3DC < 1.0f) {
                p->f3DC += D_L13_001DE728 * 0.0166666675f;
                if (p->f3DC > 1.0f) {
                    p->f3DC = 1.0f;
                }
                m->scale = m->cls->f24 * p->f3DC;
            }
            if (m->alpha < 0x7F) {
                m->alpha += (s32)(D_L13_001DE72C * 0.0166666675f * 127.0f);
                if ((s8)m->alpha < 0) {
                    m->alpha = 0x7F;
                }
                if (m->alpha == 0x7F) {
                    m->flags &= 0xD7FF;
                }
            }
            func_003886E8(10.0f, buf, &m->vel);
            vec_add_ab(buf, buf, &m->pos);
            func_L13_003ACEF8(m, buf);
            m->h96++;
            if ((D_L13_001DE730) < m->h96) {
                m->scale = m->cls->f24;
                m->alpha = 0x7F;
                m->flags &= 0xD7FF;
                func_L13_003ABCB0((u8 *)m, (u8 *)p);
            }
        }
        break;
    }
}
/* localdecomp:end func_L13_003AA178 */
