#include "common.h"
#include "vu0.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3AC810;

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

/* localdecomp:start func_L13_003ABD48 */
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern s32 D_001D545C_003ABD48;
__asm__(".extern D_001D545C_003ABD48, 16");
extern u8 D_0014275C_003ABD48[];
extern u8 D_0014275B_003ABD48[];
extern s32 D_L16_001D6694;
__asm__(".extern D_L16_001D6694, 4");
extern s32 D_L16_001DF014;
__asm__(".extern D_L16_001DF014, 4");
extern f32 D_L16_001DAA30;
__asm__(".extern D_L16_001DAA30, 4");
extern f32 D_L16_001DAA38;
__asm__(".extern D_L16_001DAA38, 4");
extern f32 D_L16_001DEF70;
__asm__(".extern D_L16_001DEF70, 4");
extern f32 D_L16_001DEF74;
__asm__(".extern D_L16_001DEF74, 4");
extern f32 D_L16_001DEF78;
__asm__(".extern D_L16_001DEF78, 4");
extern f32 D_L16_001DEF88;
__asm__(".extern D_L16_001DEF88, 4");
extern f32 D_L16_001DEF8C;
__asm__(".extern D_L16_001DEF8C, 4");
extern f32 D_L16_001DEFA0;
__asm__(".extern D_L16_001DEFA0, 4");
extern f32 D_L16_001DEFA4;
__asm__(".extern D_L16_001DEFA4, 4");
extern f32 D_L16_001DEFA8;
__asm__(".extern D_L16_001DEFA8, 4");
extern f32 D_L16_001DEFB0;
__asm__(".extern D_L16_001DEFB0, 4");
extern f32 D_L16_001DEFB4;
__asm__(".extern D_L16_001DEFB4, 4");
extern f32 D_L16_001DEFB8;
__asm__(".extern D_L16_001DEFB8, 4");
extern f32 D_L16_001DEFD0;
__asm__(".extern D_L16_001DEFD0, 4");
extern s32 D_L16_001DEFD4;
__asm__(".extern D_L16_001DEFD4, 4");
extern s32 D_L16_001DEFD8;
__asm__(".extern D_L16_001DEFD8, 4");
extern s32 D_L16_001DEFDC;
__asm__(".extern D_L16_001DEFDC, 4");
extern s32 D_L16_001DEFE0;
__asm__(".extern D_L16_001DEFE0, 4");
extern u16 D_L16_001DEFE4;
__asm__(".extern D_L16_001DEFE4, 4");
extern s32 D_L16_001DEFE8;
__asm__(".extern D_L16_001DEFE8, 4");
extern f32 D_L16_001DF008;
__asm__(".extern D_L16_001DF008, 4");
extern f32 D_L16_001DF00C;
__asm__(".extern D_L16_001DF00C, 4");
extern s32 D_L16_001DF010;
__asm__(".extern D_L16_001DF010, 4");
extern f32 D_L16_002FCF10[];
extern f32 D_L16_002FD0F0[];
extern s32 *D_L16_0021ED00[];
extern s32 D_L16_001D66B0;

extern s32 func_00382468(s32);
extern s32 func_0038CB00(s16 *);
extern void func_0038CE20(f32, void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_003C2EC0(M_003ABD48 *, s32, void *);
extern void func_003C2F58(M_003ABD48 *, s32, void *);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern f32 func_003C3D30(f32, void *, s32, s32);
extern void func_003D4D00(f32, void *, s32, M_003ABD48 *, void *);
extern void func_L01_00315900(M_003ABD48 *, s32, void *);
extern s32 func_L01_0041A4F0(void);
extern f32 func_L01_004395E0(M_003ABD48 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L01_00446058(M_003ABD48 *, s32, s32);
extern void func_L01_00446760(f32, void *, M_003ABD48 *, s32, void *);
extern s32 func_L01_0044E1B8(f32, M_003ABD48 *);
extern void func_L01_00451290(M_003ABD48 *, void *, s32);
extern void func_L01_004515D8(void *, void *, s32);
extern s32 func_L01_00454370(M_003ABD48 *, void *);
extern s32 func_L01_004561B8(M_003ABD48 *);
extern s32 func_L01_0045A748(M_003ABD48 *, void *);
extern s32 func_L01_0045A9F0(M_003ABD48 *);
extern void func_L01_0045AA10(f32, M_003ABD48 *);
extern void func_L01_0045BD10(f32, M_003ABD48 *);
extern void func_L01_0045BD78(f32, f32, f32, f32, M_003ABD48 *);
extern s32 func_L01_0045BDE8(M_003ABD48 *, s32);
extern void func_L01_0045C150(M_003ABD48 *, s32 *, s32, s32);
extern void func_L01_004AA7E8(M_003ABD48 *, s32);
extern s32 func_L01_004BA800(void);
extern s16 func_L06_004591F8(void *, s32 *, s32);
extern void func_L13_003ADA98(u8 *, u8 *);
extern s32 func_L13_003ADAD0(M_003ABD48 *);
extern s32 func_L13_003ADE00(M_003ABD48 *);
extern void func_L13_003AE508(M_003ABD48 *);
extern void func_L13_003AE5F8(u8 *, s32);
extern void func_L13_003AE678_003ABD48(u8 *);
extern void func_L13_003AE880(u8 *);
extern void func_L13_003AE8C8(u8 *);
extern void func_L13_003AE990(M_003ABD48 *);
extern void func_L13_003AEA10(u8 *);
extern void func_L13_003AEA98(u8 *);
extern void func_L13_003AEB48(void *);
extern void func_L13_003AEBC8(void *);
extern void func_L13_003AEC48(M_003ABD48 *);
extern s32 func_L13_003AECE0(M_003ABD48 *, void *);
extern s32 func_L13_003AEDD8(M_003ABD48 *, s32);
extern void func_L13_003AF048(u8 *, f32, f32, f32);
extern void func_L13_003AF0B0(void *, f32, f32, f32);
extern f32 *func_L13_003AF0E8(M_003ABD48 *, s32, s32);
extern s32 func_L13_003AF260(u8 *);
extern void func_L13_003AF2F8(M_003ABD48 *);
extern void func_L13_003AF3B8(M_003ABD48 *);
extern void func_L13_003AF5E8(M_003ABD48 *);
extern void func_L13_003B4618(M_003ABD48 *, void *, void *, s32, s32);

#define FRAMES(x) (((x) * 5 + 2) / 6)
#define RFRAMES(t) (FRAMES(t) + func_00382468(FRAMES((f32)(t) * D_L16_001DEFD0)))
#define DEG 0.017453292f

void func_L13_003ABD48(M_003ABD48 *m) {
    P_003ABD48 *p = m->pv;
    V4 buf[4];
    V4 d;

    if (m->state == 0 && func_L13_003ADAD0(m) == 0) {
        return;
    }
    if (func_L13_003ADE00(m) == 0) {
        func_L13_003AE5F8((u8 *)m, 1);
        return;
    }
    if (D_L16_001D6694 == 2) {
        if (((u8)m->flags ^ 1) & 1) {
            m->w98 = 0;
            m->flags = (m->flags | 0x41) & 0xEFFF;
            func_L01_004AA7E8(m, 1);
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
    if ((D_L16_001DF014 != 0 || D_0014275C_003ABD48[0] != 0 || D_001D545C_003ABD48 == 0x16) && p->w3CC == 0) {
        if (D_001D545C_sda != 0x16) {
            func_L01_00446058(m, 0x1BA3, 0x1B39);
            if (D_001D545C_003ABD48 == 0x10 || D_001D545C_003ABD48 == 4 || D_001D545C_003ABD48 == 9) {
                p->h34 = 0x46;
                p->b44 = 0x2D;
                if (func_L01_0041A4F0() != 0) {
                    p->h34 = p->h34 * ((D_001D545C_003ABD48 == 7 && D_0014275B_003ABD48[0] != 0) ? D_L16_001DAA30 : D_L16_002FCF10[D_001D545C_003ABD48]);
                    p->b44 = p->b44 * ((D_001D545C_003ABD48 == 7 && D_0014275B_003ABD48[0] != 0) ? D_L16_001DAA38 : D_L16_002FD0F0[D_001D545C_003ABD48]);
                }
                p->b45 = p->b44;
                p->b46 = p->b44;
                p->f30 = p->h34;
            }
        } else {
            func_L01_00446058(m, 0x1F07, 0x1B39);
        }
        m->hAA = 0x1B39;
        p->w3CC = 1;
    } else if (D_L16_001DF014 == 0 && D_0014275C_003ABD48[0] == 0) {
        func_L01_00446058(m, 0x1B39, 0x1B39);
    }
    if (p->b3AD != 0 && func_L01_004BA800() != 0) {
        return;
    }
    switch (m->state) {
    case 35:
        if (func_L01_0044E1B8(0.0f, m) != 0 && m->anim == 0xB) {
            func_003C2EC0(m, 2, buf);
            vec_sub_ab(&d, &p->tx, &buf[3]);
            func_0038CF68(&d, &m->vel, 0.6f);
            d.z -= 0.04f;
            func_L13_003B4618(m, &buf[3], &d, p->b44, p->b5F ? 0x8010001 : 0x8000001);
        }
        break;
    case 1:
        if (func_L01_004561B8(m) != 0) {
            p->t3BC = FRAMES(p->h3A8);
        }
        func_L13_003AEC48(m);
        if (func_L13_003AF260((u8 *)m) != 0 && func_0038CB00(&p->t3BC) != 0) {
            func_L13_003AE880((u8 *)m);
        }
        break;
    case 2:
        if (func_L01_004561B8(m) != 0) {
            s32 *path;
            func_L13_003AF048((u8 *)p + 0x150, D_L16_001DEF70 * 0.020000001f, D_L16_001DEF74 * 0.00040000002f, D_L16_001DEF78 * 0.00040000002f);
            path = D_L16_0021ED00[p->w384];
            p->path = path;
            buf[0] = m->pos;
            p->h218 = func_L06_004591F8(buf, path, 1);
            if (*path >> 1 < p->h218) {
                p->h21A = 0;
            } else {
                p->h21A = *path - 1;
            }
            if (m->prev != m->state) {
                p->t3BC = FRAMES(p->h3A8);
            }
        }
        if (func_L13_003AF260((u8 *)m) != 0) {
            if (func_0038CB00(&p->t3BC) != 0) {
                func_L13_003AE880((u8 *)m);
            }
        } else if (func_L13_003AEDD8(m, p->w384) != 0) {
            func_L01_004450F0((u8 *)m, 2, -1);
            break;
        }
        break;
    case 3:
        if (func_L01_004561B8(m) != 0) {
            s32 *path;
            func_L13_003AF048((u8 *)p + 0x150, p->f3A0 * 0.020000001f, p->f3A0 * 0.00040000002f, p->f3A0 * 0.00040000002f);
            path = D_L16_0021ED00[p->w380];
            p->path = path;
            buf[0] = m->pos;
            p->h218 = func_L06_004591F8(buf, path, 1);
            p->h21A = 0;
        }
        if (func_L13_003AF260((u8 *)m) != 0) {
            func_L13_003AE8C8((u8 *)m);
        } else if (func_L13_003AEDD8(m, p->w380) != 0) {
            func_L01_004450F0((u8 *)m, 2, -1);
            break;
        }
        break;
    case 4:
        func_L01_0045A9F0(m);
        if (func_L01_004561B8(m) != 0) {
            p->t3BC = RFRAMES(D_L16_001DEFD4);
            if (m->prev != m->state) {
                p->t3BE = FRAMES(p->h3A8);
            }
        }
        if (func_L13_003AF260((u8 *)m) != 0) {
            if (func_0038CB00(&p->t3BE) != 0) {
                func_L13_003AE990(m);
            }
        } else if (m->anim == m->anim2) {
            if (m->anim == 0) {
                if (func_0038CB00(&p->t3BC) != 0 && m->anim2 != 1) {
                    func_003C3A10((u8 *)m, 1, 0, 2);
                }
            } else if (m->b60 & 2) {
                func_003C3A10((u8 *)m, 0, 0, 2);
                func_L01_004450F0((u8 *)m, 4, -1);
            }
        }
        break;
    case 5:
        if (func_L01_004561B8(m) != 0) {
            s32 *path = D_L16_0021ED00[p->w384];
            f32 d;
            func_L01_0045BD78(D_L16_001DEF8C * 0.00040000002f, D_L16_001DEF88 * 0.020000001f, 0.010053097f, 0.25132743f, m);
            d = func_0038CF38(&m->pos, path + 4);
            if (func_0038CF38(&m->pos, path + *path * 4) < d) {
                func_L01_0045C150(m, path, 0, *path - 1);
            } else {
                func_L01_0045C150(m, path, *path - 1, 0);
            }
            p->t3BC = FRAMES(p->h3A8);
        }
        if (func_L13_003AF260((u8 *)m) != 0) {
            if (func_0038CB00(&p->t3BC) != 0) {
                func_L13_003AE990(m);
            }
        } else if (func_L01_0045BDE8(m, p->w384) != 0) {
            func_L01_004450F0((u8 *)m, 5, -1);
            break;
        }
        break;
    case 6:
        if (func_L01_004561B8(m) != 0) {
            s32 *path = D_L16_0021ED00[p->w380];
            p->path = path;
            buf[0] = m->pos;
            p->h218 = func_L06_004591F8(buf, path, 1);
            p->h21A = 0;
        }
        if (func_L13_003AF260((u8 *)m) != 0) {
            func_L13_003AEA10((u8 *)m);
        } else if (func_L01_0045BDE8(m, p->w380) != 0) {
            func_L01_004450F0((u8 *)m, 5, -1);
            break;
        }
        break;
    case 7:
        if (func_L01_004561B8(m) != 0) {
            s32 *path = D_L16_0021ED00[p->w388];
            p->path = path;
            buf[0] = m->pos;
            p->h218 = func_L06_004591F8(buf, path, 1);
            p->h21A = *path - 1;
        }
        if (func_L01_0045BDE8(m, p->w388) != 0) {
            m->b95 = 1;
            func_L13_003AE990(m);
        }
        break;
    case 8:
        if (func_L01_004561B8(m) != 0) {
            s32 *path;
            func_L13_003AF048((u8 *)p + 0x150, p->f3A0 * 0.020000001f, p->f3A0 * 0.00040000002f, p->f3A0 * 0.00040000002f);
            path = D_L16_0021ED00[p->w380];
            p->path = path;
            buf[0] = m->pos;
            p->h218 = func_L06_004591F8(buf, path, 1);
            p->h21A = *path - 1;
        }
        if (func_L13_003AF260((u8 *)m) == 0) {
            func_L01_004450F0((u8 *)m, 9, -1);
            break;
        }
        if (func_L13_003AEDD8(m, p->w380) != 0) {
            func_L13_003AE8C8((u8 *)m);
        }
        break;
    case 9:
        func_L13_003AEC48(m);
        if (func_L01_004561B8(m) != 0) {
            p->t3BC = RFRAMES(D_L16_001DEFD8);
        }
        if (func_L13_003AF260((u8 *)m) != 0) {
            func_L13_003AE880((u8 *)m);
        } else if (func_0038CB00(&p->t3BC) != 0) {
            if (p->w384 != -1) {
                if (p->w380 != -1) {
                    func_L01_004450F0((u8 *)m, 3, -1);
                } else {
                    func_L01_004450F0((u8 *)m, 2, -1);
                }
            } else {
                if (m->anim2 != 0x18) {
                    func_003C3A10((u8 *)m, 0x18, 0, 8);
                }
                func_L01_004450F0((u8 *)m, 1, -1);
            }
        }
        break;
    case 10:
        if (func_L01_004561B8(m) != 0) {
            func_L13_003AF048((u8 *)p + 0x150, p->f3A4 * 0.020000001f, p->f3A4 * 0.00040000002f, p->f3A4 * 0.00040000002f);
            p->tgt = func_L13_003AF0E8(m, p->w390, 1);
        }
        if (func_L13_003AF260((u8 *)m) == 0) {
            func_L01_004450F0((u8 *)m, 9, -1);
            break;
        }
        if ((func_L13_003AECE0(m, p->tgt + 12) & 0x80) || func_0038CF38(&m->pos, p->tgt + 12) < 0.5f) {
            if (m->anim2 != 0x1A) {
                func_003C3A10((u8 *)m, 0x1A, 0, 0xC);
            }
            func_L01_004450F0((u8 *)m, 0xD, -1);
            break;
        }
        break;
    case 11:
        func_L01_0045BD10(func_0038D160(p->tx - m->pos.x, p->ty - m->pos.y), m);
        func_L13_003AEC48(m);
        if (m->b60 & 2) {
            if (m->anim2 != 0xA) {
                func_003C3A10((u8 *)m, 0xA, 0, 0);
            }
            func_L01_004450F0((u8 *)m, 0xC, -1);
            break;
        }
        break;
    case 12:
        func_L01_0045BD10(func_0038D160(p->tx - m->pos.x, p->ty - m->pos.y), m);
        func_L13_003AEC48(m);
        if (func_L01_004561B8(m) != 0) {
            p->t3BC = RFRAMES(D_L16_001DEFE0);
        }
        if (func_0038CB00(&p->t3BC) != 0) {
            if (m->anim2 != 0xB) {
                func_003C3A10((u8 *)m, 0xB, 0xC, 0);
            }
            func_L01_004450F0((u8 *)m, 0xD, -1);
            break;
        }
        break;
    case 13:
        func_L01_0045BD10(func_0038D160(p->tx - m->pos.x, p->ty - m->pos.y), m);
        if (func_L01_004561B8(m) != 0) {
            p->t3BC = D_L16_001DEFE4 + 1;
        }
        if ((m->b60 & 2) && func_0038CB00(&p->t3BC) != 0) {
            if (m->anim2 != 0x18) {
                func_003C3A10((u8 *)m, 0x18, 0, 0xD);
            }
            func_L01_004450F0((u8 *)m, 0xF, -1);
        }
        if (func_L01_0044E1B8(57.0f, m) != 0 && m->anim == 0x1A) {
            func_L13_003AF3B8(m);
        }
        break;
    case 14:
        func_L01_0045BD10(func_0038D160(p->tx - m->pos.x, p->ty - m->pos.y), m);
        func_L13_003AEC48(m);
        if (m->b60 & 2) {
            if (m->anim2 != 0xA) {
                func_003C3A10((u8 *)m, 0xA, 0, 0);
            }
            func_L01_004450F0((u8 *)m, 0xF, -1);
            break;
        }
        break;
    case 15:
        func_L01_0045BD10(func_0038D160(p->tx - m->pos.x, p->ty - m->pos.y), m);
        func_L13_003AEC48(m);
        if (m->b60 & 2) {
            if (func_L13_003AF260((u8 *)m) == 0) {
                if (m->anim2 != 0x18) {
                    func_003C3A10((u8 *)m, 0x18, 0, 5);
                }
                func_L01_004450F0((u8 *)m, 9, -1);
            } else {
                func_L13_003AE8C8((u8 *)m);
            }
        }
        break;
    case 16:
        if (func_L01_004561B8(m) != 0) {
            m->b95 = 1;
            p->w188 &= ~0x414;
            p->f17C = 0.016f;
            p->f3C8 = 0.16000001f;
        }
        if (p->b3AE != 0) {
            func_L01_0045A9F0(m);
            func_L01_00446760(1.0f, (Hit_003ABD48 *)buf, m, 0x08000000, &D_L16_001D66B0);
            ((Hit_003ABD48 *)buf)->b18 = 0;
            ((Hit_003ABD48 *)buf)->b19 = 1;
            ((Hit_003ABD48 *)buf)->h1A = m->hAA;
            func_003C2F58(m, 0, &buf[3]);
            func_003D4D00(1.5f, &buf[3], 0x10, m, (Hit_003ABD48 *)buf);
            if (m->pos.z <= func_003C3D30(0.5f, &m->pos, 0, 0)) {
                p->f17C = 0.00392f;
                func_L01_00451290(m, &d, 1);
                func_L01_004515D8(&m->vel, &d, 0);
                m->fF0 = 0.0f;
                m->fF4 = 0.0f;
                if (m->anim2 != 4) {
                    func_003C3A10((u8 *)m, 4, 1, 3);
                }
                func_L01_004450F0((u8 *)m, 0x11, -1);
                if (p->b3AE != 0 && m->anim2 != 0x19) {
                    func_003C3A10((u8 *)m, 0x19, 0, 3);
                }
            }
        } else if (func_L01_00454370(m, (u8 *)p + 0x70) & 2) {
            p->f17C = 0.00392f;
            func_L01_00451290(m, buf, 1);
            func_L01_004515D8(&m->vel, buf, 0);
            m->fF0 = 0.0f;
            m->fF4 = 0.0f;
            func_L13_003AF0B0((u8 *)p + 0x150, D_L16_001DEFA0 * DEG * 0.020000001f, D_L16_001DEFA4 * DEG * 0.00040000002f, D_L16_001DEFA8 * DEG * 0.00040000002f);
            func_L13_003AEA10((u8 *)m);
        }
        break;
    case 17:
        func_L01_0045A9F0(m);
        if (func_L01_0044E1B8(20.0f, m) != 0) {
            func_L13_003AF0B0((u8 *)p + 0x150, D_L16_001DEFA0 * DEG * 0.020000001f, D_L16_001DEFA4 * DEG * 0.00040000002f, D_L16_001DEFA8 * DEG * 0.00040000002f);
            func_L13_003AEA10((u8 *)m);
        }
    case 18:
        if (m->b60 & 2) {
            func_L13_003AF0B0((u8 *)p + 0x150, D_L16_001DEFA0 * DEG * 0.020000001f, D_L16_001DEFA4 * DEG * 0.00040000002f, D_L16_001DEFA8 * DEG * 0.00040000002f);
            func_L13_003AEA10((u8 *)m);
        }
        break;
    case 19:
        if (func_L01_004561B8(m) != 0) {
            s32 *path = D_L16_0021ED00[p->w380];
            p->path = path;
            buf[0] = m->pos;
            p->h218 = func_L06_004591F8(buf, path, 0);
            p->h21A = *path - 1;
        }
        if (func_L13_003AF260((u8 *)m) == 0) {
            goto walk;
        }
        if (func_L01_0045BDE8(m, p->w380) != 0) {
            func_L13_003AEA10((u8 *)m);
        }
        break;
    case 20:
        func_L01_0045A9F0(m);
        if (func_L01_004561B8(m) != 0) {
            if (m->prev != m->state) {
                p->t3BC = RFRAMES(D_L16_001DEFD8);
            }
            p->t3BE = RFRAMES(D_L16_001DEFDC);
        }
        if (func_L13_003AF260((u8 *)m) != 0) {
            func_L13_003AE990(m);
            break;
        }
        if (func_0038CB00(&p->t3BC) != 0) {
            if (p->w384 != -1 && m->b95 != 0) {
                func_L13_003AEB48(m);
                if (p->w380 != -1) {
                    func_L01_004450F0((u8 *)m, 6, -1);
                } else {
                    func_L01_004450F0((u8 *)m, 5, -1);
                }
            } else {
                func_L01_004450F0((u8 *)m, 4, -1);
            }
            break;
        }
        if (m->anim == m->anim2) {
            if (m->anim == 0) {
                if (func_0038CB00(&p->t3BE) != 0 && m->anim2 != 1) {
                    func_003C3A10((u8 *)m, 1, 0, 2);
                }
            } else if (m->b60 & 2) {
                func_003C3A10((u8 *)m, 0, 0, 2);
                func_L01_004450F0((u8 *)m, 0x14, -1);
            }
        }
        break;
    case 21:
        if (func_L01_004561B8(m) != 0) {
            p->tgt = func_L13_003AF0E8(m, p->w394, 0);
        }
        if (func_L13_003AF260((u8 *)m) == 0) {
            goto walk;
        }
        if (func_L01_0045A748(m, p->tgt + 12) & 0x80) {
            if (func_0038DBA0(func_0038D160(p->tx - m->pos.x, p->ty - m->pos.y), m->fF8) > D_L16_001DEFB0 * DEG) {
                func_L01_004450F0((u8 *)m, 0x16, -1);
                break;
            }
            func_L13_003AEA98((u8 *)m);
        }
        break;
    case 23:
        if (func_L01_004561B8(m) != 0) {
            p->tgt = func_L13_003AF0E8(m, p->w38C, 0);
        }
        if (func_L13_003AF260((u8 *)m) == 0) {
            goto walk;
        }
        if (func_L01_0045A748(m, p->tgt + 12) & 0x80) {
            f32 deg = DEG;
            if (func_0038DBA0(func_0038D160(p->tx - m->pos.x, p->ty - m->pos.y), m->fF8) > D_L16_001DEFB0 * deg) {
                if (m->anim2 != 2) {
                    func_003C3A10((u8 *)m, 2, 0, 3);
                }
                func_L01_004450F0((u8 *)m, 0x18, -1);
                break;
            }
                if (func_0038DBA0(m->fF8, func_0038D160(p->tgt[0], p->tgt[1]) > D_L16_001DEFB4 * deg ? 1.0f : 0.0f) == 0.0f) {
                if (m->anim2 != 6) {
                    func_003C3A10((u8 *)m, 6, 0, 3);
                }
                func_L01_004450F0((u8 *)m, 0x19, -1);
                break;
            }
            func_L13_003AEA98((u8 *)m);
        }
        break;
    case 24:
        {
            f32 deg = DEG;
            u8 *q = (u8 *)p + 0x150;
            f32 a = func_0038D160(p->tx - m->pos.x, p->ty - m->pos.y);
            func_L01_0045AA10(a, m);
            m->f48 = *(f32 *)(q + 0xB4) * D_L16_001DEFB8;
            if (func_0038DBA0(m->fF8, a) < D_L16_001DEFB0 * 0.5f * deg) {
                if (func_0038DBA0(m->fF8, func_0038D160(p->tgt[0], p->tgt[1]) > D_L16_001DEFB4 * deg ? 1.0f : 0.0f) == 0.0f) {
                    if (m->anim2 != 6) {
                        func_003C3A10((u8 *)m, 6, 0, 3);
                    }
                    func_L01_004450F0((u8 *)m, 0x19, -1);
                    break;
                }
                func_L13_003AEA98((u8 *)m);
            }
        }
        break;
    case 25:
        func_L01_0045A9F0(m);
        if (m->b60 & 2) {
            if (m->anim2 != 7) {
                func_003C3A10((u8 *)m, 7, 0, 3);
            }
            func_L01_004450F0((u8 *)m, 0x1A, -1);
            break;
        }
        break;
    case 26:
        func_L01_0045A9F0(m);
        if (func_L01_004561B8(m) != 0) {
            p->t3BC = RFRAMES(D_L16_001DEFE8);
        }
        if (func_0038CB00(&p->t3BC) != 0) {
            if (m->anim2 != 8) {
                func_003C3A10((u8 *)m, 8, 0, 3);
            }
            func_L01_004450F0((u8 *)m, 0x1B, -1);
            break;
        }
        break;
    case 27:
        func_L01_0045A9F0(m);
        if (m->b60 & 2) {
            func_L13_003AEB48(m);
            func_L01_004450F0((u8 *)m, 0x16, -1);
            break;
        }
        break;
    case 22:
        {
            f32 a = func_0038D160(p->tx - m->pos.x, p->ty - m->pos.y);
            func_L01_0045AA10(a, m);
            if (func_0038DBA0(m->fF8, a) < D_L16_001DEFB0 * 0.5f * DEG) {
                func_L13_003AEA98((u8 *)m);
            }
        }
        break;
    case 28:
        func_L01_0045A9F0(m);
        func_L13_003AF2F8(m);
        if (m->b60 & 2) {
            if (m->anim2 != 0xA) {
                func_003C3A10((u8 *)m, 0xA, 0, 0);
            }
            func_L01_004450F0((u8 *)m, 0x1D, -1);
            break;
        }
        break;
    case 29:
        func_L01_0045A9F0(m);
        func_L13_003AF2F8(m);
        if (func_L01_004561B8(m) != 0) {
            p->t3BC = RFRAMES(D_L16_001DEFE0);
        }
        if (func_0038CB00(&p->t3BC) != 0) {
            if (m->anim2 != 0xB) {
                func_003C3A10((u8 *)m, 0xB, 0xC, 0);
            }
            func_L01_004450F0((u8 *)m, 0x1E, -1);
            break;
        }
        break;
    case 30:
        func_L01_0045A9F0(m);
        func_L13_003AF2F8(m);
        if (func_L01_004561B8(m) != 0) {
            p->t3BC = D_L16_001DEFE4 + 1;
        }
        if (m->b60 & 2) {
            if (func_0038CB00(&p->t3BC) != 0) {
                if (m->anim2 != 0xC) {
                    func_003C3A10((u8 *)m, 0xC, 0, 0);
                }
                func_L01_004450F0((u8 *)m, 0x1F, -1);
                break;
            }
            func_L13_003AF3B8(m);
        }
        break;
    case 31:
        func_L01_0045A9F0(m);
        func_L13_003AF2F8(m);
        if (func_L01_0044E1B8(33.0f, m) != 0) {
            if (m->b95 == 2) {
                func_L13_003AEBC8(m);
                func_L01_004450F0((u8 *)m, 7, -1);
                break;
            }
            goto back;
        }
        break;
    case 32:
        func_L01_0045A9F0(m);
        func_L13_003AF2F8(m);
        if (m->b60 & 2) {
            if (m->b95 == 2) {
                func_L13_003AEBC8(m);
                func_L01_004450F0((u8 *)m, 7, -1);
                break;
            }
            goto back;
        }
        break;
    case 33:
        {
            f32 t;
            func_L01_0045A9F0(m);
            t = func_L01_004395E0(m);
            if (t > 17.0f && t < 24.0f) {
                func_L13_003AF5E8(m);
            }
            if (m->b60 & 2) {
            back:
                if (func_L13_003AF260((u8 *)m) != 0) {
                    func_L13_003AEA10((u8 *)m);
                } else {
                walk:
                    if (m->anim2 != 1) {
                        func_003C3A10((u8 *)m, 1, 0, 3);
                    }
                    func_L01_004450F0((u8 *)m, 0x14, -1);
                    break;
                }
            }
        }
        break;
    case 34:
        {
            s32 r;
            func_L01_0045A9F0(m);
            r = func_L01_00454370(m, (u8 *)p + 0x70);
            if (r & 1) {
                func_L13_003AE508(m);
                func_L01_00315900(m, 0, func_L13_003AE678_003ABD48);
            } else if (r & 2) {
                if (p->b3AB == 0 && p->b3AF == 0 && p->w388 != -1 && p->f30 < p->h34 * p->f3C4) {
                    func_L13_003AEBC8(m);
                    m->b95 = 2;
                    func_L01_004450F0((u8 *)m, 7, -1);
                    p->b3AF = 1;
                } else {
                    func_L13_003AEA10((u8 *)m);
                }
            }
        }
        break;
    case 38:
        {
            if (func_L01_004561B8(m) != 0) {
                func_L13_003AF048((u8 *)p + 0x150, D_L16_001DEF70 * 0.020000001f, D_L16_001DEF74 * 0.00040000002f, D_L16_001DEF78 * 0.00040000002f);
            }
            if (p->f3DC < 1.0f) {
                p->f3DC += D_L16_001DF008 * 0.020000001f;
                if (p->f3DC > 1.0f) {
                    p->f3DC = 1.0f;
                }
                m->scale = m->cls->f24 * p->f3DC;
            }
            if (m->alpha < 0x7F) {
                m->alpha += (s32)(D_L16_001DF00C * 0.020000001f * 127.0f);
                if ((s8)m->alpha < 0) {
                    m->alpha = 0x7F;
                }
                if (m->alpha == 0x7F) {
                    m->flags &= 0xD7FF;
                }
            }
            func_0038CE20(10.0f, buf, &m->vel);
            vec_add_ab(buf, buf, &m->pos);
            func_L13_003AECE0(m, buf);
            m->h96++;
            if (FRAMES(D_L16_001DF010) < m->h96) {
                m->scale = m->cls->f24;
                m->alpha = 0x7F;
                m->flags &= 0xD7FF;
                func_L13_003ADA98((u8 *)m, (u8 *)p);
            }
        }
        break;
    }
}
/* localdecomp:end func_L13_003ABD48 */
