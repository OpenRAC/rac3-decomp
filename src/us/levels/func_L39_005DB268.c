#include "common.h"

/* NTSC-U counterpart of func_L39_005DD810 (src/levels/shared/L39_005DD3C0.c) */
extern u8 *D_L39_0024C05C;
extern void func_L01_0044E108(u8 *, s32 *, s32 *);
typedef struct {
    u8 pad40[0x40];
    s32 f40[8];
    s32 f60[8];
    u8 pad80[0x28];
    s32 fA8[8];
} S_005DD290_e;
typedef struct {
    u8 pad[0x20C];
    S_005DD290_e *f20C;
} S_005DD290_t;
extern S_005DD290_t D_L39_00352A40;
extern long func_L39_005DACB0(u8 *);
#include "vu0.h"
extern s32 D_L39_0024C500_005DB268[2];

/* localdecomp:start func_L39_005DB268 */
typedef union {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_005DD810;

typedef struct {
    u8 pad0[0xC60];
    s32 fC60;
    s32 fC64;
} G_005DD810;

typedef struct {
    u8 pad0[0xAA];
    s16 fAA;
    u8 padAC[0x10];
    u8 fBC;
} M_005DD810;

typedef struct P_005DD810 {
    u8 pad0[0x2D0];
    M_005DD810 *f2D0;
    u8 pad2D4[4];
    struct P_005DD810 *f2D8;
    struct P_005DD810 *f2DC;
    u8 pad2E0[0x31C - 0x2E0];
    u8 b31C;
    u8 pad31D[0x19E4 - 0x31D];
    u8 b19E4;
    u8 pad19E5;
    u8 b19E6;
    u8 pad19E7[0x2524 - 0x19E7];
    u8 *f2524;
    struct P_005DD810 *f2528;
    u8 pad252C[0x2548 - 0x252C];
    s32 f2548;
    u8 pad254C[0x2558 - 0x254C];
    G_005DD810 *f2558;
} P_005DD810;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8[4];
} Q_005DD810;

typedef struct {
    u8 pad0[8];
    u8 *vt;
    u8 pad0C[0x2F];
    u8 f3B;
} Obj_005DD810;

extern u8 D_L39_004998A0[];
__asm__(".extern D_001D8180_sda, 4");
__asm__(".extern D_001D8190_sda, 1");
extern s32 D_001D8180_sda[] __attribute__((section(".sdata")));
extern u8 D_001D8190_sda[] __attribute__((section(".sdata")));
extern s32 D_001DA5F0_sda_005DB268;
extern s32 D_001D5A1C_sda_005DB268;
__asm__(".extern D_L39_0024C4F8_005DB268, 16");
extern u8 D_L39_0024C4F8_005DB268[8];
__asm__(".extern D_L39_0024C520_005DB268, 16");
__asm__(".extern D_L39_0024C530, 16");
extern u32 D_L39_0024C520_005DB268[2];
extern u32 D_L39_0024C530[2];
extern Q_005DD810 D_L39_0024CE50;
__asm__(".extern D_L39_002412A0, 16");
extern s32 *D_L39_002412A0;
extern u8 D_L39_0049A0C0[];
extern u8 D_L39_0049A0C8[];
extern u8 D_L39_0049A0D0[];
extern u8 D_L39_0049A0B0[];
extern u8 D_L39_0049A0B8[];
extern u8 D_L39_002B59B0_005DB268[];
extern u8 D_L39_00243A30[];
extern u8 *D_L39_0024C05C;
__asm__(".extern D_L39_0024CF20, 32");
extern P_005DD810 *D_L39_0024CF20[] __attribute__((section(".sdata")));

extern void func_L39_005DAE18(u8 *);
extern s32 func_L01_00513698(void);
extern void func_L39_005D99E8(s32);
extern s32 func_L01_00478B18(s32);
extern s32 func_L39_0060DD90(void *);
extern P_005DD810 *func_L39_006197C0(s32);
extern f32 func_L39_005DADC8(void *);
extern s32 func_L39_005D9F18(s32, s32 *, s32 *);
extern s32 func_00388398(void *);
extern void *func_003E16B8(void *);
extern s32 func_003E1898(void *);
extern s32 func_003E0E28(s32, s32);
extern s32 func_L01_00512AB0(s32, s32, s32);
extern s32 func_L01_00512FE8(s32, s32);
extern s32 func_L01_00513548(s32, f32, f32);
extern s32 func_L01_00512480(s32, f32, f32);
extern s32 func_L01_005130C8(s32, s32);
extern s32 func_L01_00512900(s32, f32);
extern s32 func_L01_005131A0(s32, s32);
extern s32 func_0037DF98(s32);
extern s32 func_001321C8(f32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern s32 func_L39_005D9F60(void *, s32, s32);
extern P_005DD810 *func_L39_006646B0(s32);
extern s32 func_L01_004D2128(void);
extern s32 func_L08_004EA298_005DB268(s32);


static __inline__ u32 Dec_005DD810(u8 *q) {
    Buf_005DD810 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

static __inline__ s16 Dec16_005DD810(u8 *q) {
    Buf_005DD810 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

static __inline__ Obj_005DD810 *Find_005DD810(s32 id) {
    Q_005DD810 *q;
    Obj_005DD810 *p;
    s32 *base;

    q = &D_L39_0024CE50;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E16B8(q);
    }
    p = (Obj_005DD810 *)func_003E0E28(func_003E1898(base), id);
    return (p != 0 && (*(s32 (**)(void *, s32))(p->vt + 0x10))(p, D_001DA5F0_sda_005DB268) != 0) ? p : 0;
}

static __inline__ void Mark_005DD810(s32 id, f32 x, f32 y) {
    func_L01_00512480(id, x + 0.002f, y + 0.001f);
    func_L01_00512AB0(id, 1, 1);
    func_L01_00513548(id, 0.075f, 0.093f);
}

static __inline__ void Size_005DD810(s32 id) {
    s32 lv;

    lv = *D_L39_002412A0;
    if (lv >= 3) {
        func_L01_00513548(id, 0.6f, 0.6f);
    } else if (lv >= 2) {
        func_L01_00513548(id, 0.8f, 0.8f);
    } else {
        func_L01_00513548(id, 1.0f, 1.0f);
    }
}

void func_L39_005DB268(void) {
    s32 i;
    P_005DD810 *g;
    P_005DD810 *g2;
    P_005DD810 *e;
    P_005DD810 *e2;
    P_005DD810 *nv;
    s32 id;
    s32 k;
    s32 c;
    s32 idx;
    s32 fp;
    f32 f;
    f32 v10, v14, v18, v1C, v20, v24, v28, v2C, v30, v34, v38, v3C;

    i = func_L01_00513698();
    if (D_001D8180_sda[i] != 0) {
        D_001D8180_sda[i]--;
    } else {
        func_L39_005D99E8(-1);
        D_001D8190_sda[i] = 1;
    }
    if (D_001D8190_sda[i] != 0) {
        return;
    }
    if (func_L39_0060DD90((void *)func_L01_00478B18(i)) != 1) {
        return;
    }
    g = func_L39_006197C0(i);
    if (*(long *)&g->f2558->fC60 == -1) {
        g->f2558->fC60 = ((s32 (*)(u8 *))func_L39_005DACB0)((u8 *)g);
    }
    if (D_L39_0024C4F8_005DB268[i] != 0) {
        func_00388398(&D_L39_0024C500_005DB268[i]);
        if (D_L39_0024C500_005DB268[i] == 0) {
            func_L39_005DAE18((u8 *)g);
        }
        if ((Dec_005DD810(&g->b19E4) ^ 0x90) == 0) {
            func_L01_00512AB0(0x50023, 1, 1);
            if (Dec16_005DD810(&g->b31C) <= 0) {
                func_L01_00512FE8(0x50023, func_0037DF98(0x12A5));
                Size_005DD810(0x50023);
            } else {
                s16 y = Dec16_005DD810(&g->b31C);
                u8 *buf = D_L39_002B59B0_005DB268 + (i << 6);
                s32 v = func_001321C8((f32)y / 60.0f);
                func_00120048(buf, D_L39_00243A30, v, func_0037DF98(0x12BD));
                func_L01_00512FE8(0x50023, (s32)buf);
                Size_005DD810(0x50023);
            }
        } else {
            func_L01_00512AB0(0x50023, 1, 0);
        }
        {
        Obj_005DD810 *o = Find_005DD810(0x50007);
        if (o != 0) {
            u32 b = o->f3B;
            if (b == 0) {
                D_L39_0024C520_005DB268[i] = 7;
            } else if (b >= 0x80) {
                D_L39_0024C520_005DB268[i] = -7;
            }
            b += D_L39_0024C520_005DB268[i];
            func_L01_005130C8(0x50007, (b << 24) | (D_L39_0049A0C8[2] << 16) |
                                           (D_L39_0049A0C8[1] << 8) | D_L39_0049A0C8[0]);
        }
        }
        idx = g->f2558->fC64;
        if (idx != -1) {
            func_L01_0044E108(D_L39_0024C05C + (D_L39_00352A40.f20C->f60[idx] << 8), (s32 *)&v10, (s32 *)&v14);
            Mark_005DD810(0x50007, v10, v14);
        } else {
            c = g->f2558->fC60;
            if (c != -1) {
                func_L01_0044E108(D_L39_0024C05C + (D_L39_00352A40.f20C->f40[c] << 8), (s32 *)&v18, (s32 *)&v1C);
                Mark_005DD810(0x50007, v18, v1C);
            }
        }
    } else {
        func_L01_00512AB0(0x50023, 1, 0);
        func_L01_00512AB0(0x50007, 1, 0);
    }
    {
    Obj_005DD810 *o = Find_005DD810(0x50008);
    if (o != 0) {
        u32 b = o->f3B;
        if (b == 0) {
            D_L39_0024C530[i] = 7;
        } else if (b >= 0x80) {
            D_L39_0024C530[i] = -7;
        }
        b += D_L39_0024C530[i];
        func_L01_005130C8(0x50008, (b << 24) | (D_L39_0049A0D0[2] << 16) |
                                       (D_L39_0049A0D0[1] << 8) | D_L39_0049A0D0[0]);
    }
    }
    for (id = 0x5000B; id <= 0x50012; id++) {
        s32 j = id - 0x5000B;
        u32 col;

        if (func_L39_005D9F18(D_L39_00352A40.f20C->f60[j], (s32 *)&v20, (s32 *)&v24)) {
            col = 0x60000000 | (D_L39_0049A0C0[2] << 16) | (D_L39_0049A0C0[1] << 8) | D_L39_0049A0C0[0];
            if (func_L08_004EA298_005DB268(j)) {
                if (D_001D5A1C_sda_005DB268 & 0x10) {
                    col = 0x60000000 | (D_L39_0049A0B0[2] << 16) | (D_L39_0049A0B0[1] << 8) | D_L39_0049A0B0[0];
                } else {
                    col = 0x60000000 | (D_L39_0049A0B8[2] << 16) | (D_L39_0049A0B8[1] << 8) | D_L39_0049A0B8[0];
                }
            } else if (D_L39_00352A40.f20C->fA8[j] == 0) {
                col = 0x60000000 | (D_L39_0049A0B0[2] << 16) | (D_L39_0049A0B0[1] << 8) | D_L39_0049A0B0[0];
            } else if (D_L39_00352A40.f20C->fA8[j] == 1) {
                col = 0x60000000 | (D_L39_0049A0B8[2] << 16) | (D_L39_0049A0B8[1] << 8) | D_L39_0049A0B8[0];
            }
            func_L01_00512480(id, v20, v24);
            func_L01_00512AB0(id, 1, 1);
            func_L01_00513548(id, 0.05f, 0.062000003f);
            func_L01_005130C8(id, col);
        } else {
            func_L01_00512AB0(id, 1, 0);
        }
    }
    g2 = func_L39_006197C0(i);
    if (g2->f2528 == 0) {
        func_L01_0044E108(g2->f2524, (s32 *)&v28, (s32 *)&v2C);
    } else {
        func_L01_0044E108((u8 *)g2->f2528->f2D0, (s32 *)&v28, (s32 *)&v2C);
    }
    func_L01_00512480(0x50008, v28 + 0.0035f, v2C + 0.002f);
    func_L01_00512AB0(0x50008, 1, 1);
    func_L01_00513548(0x50008, 0.05f, 0.062000003f);
    fp = g2->f2548;
    for (id = 0x50013; id <= 0x5001A; id++) {
        s32 j = id - 0x50013;
        s32 t = 0;
        u32 col;

        e = D_L39_0024CF20[j];
        if (e != 0 && e->f2528 == 0) {
            t = func_L39_005D9F60((u8 *)e + 0xA0, e->f2548, fp);
            if (D_L39_0024CF20[j]->f2548 != g2->f2548) {
                if (Dec_005DD810(&D_L39_0024CF20[j]->b19E6) == 3) {
                    t = 0;
                }
            }
            if (t != 0) {
                u32 alpha = 0x70000000;
                if (D_L39_0024CF20[j]->f2548 == 0) {
                    col = (D_L39_0049A0B0[2] << 16) | (alpha | (D_L39_0049A0B0[1] << 8)) | D_L39_0049A0B0[0];
                } else {
                    u8 g = D_L39_0049A0B8[1]; u8 b = D_L39_0049A0B8[2]; col = (b << 16) | (alpha | (g << 8)) | D_L39_0049A0B8[0];
                }
                func_L01_0044E108(D_L39_0024CF20[j]->f2524, (s32 *)&v30, (s32 *)&v34);
                func_L01_00512480(id, v30, v34);
                func_L01_00513548(id, 0.035f, 0.0434f);
                func_L01_005130C8(id, col);
                f = func_L39_005DADC8(D_L39_0024CF20[j]->f2524);
                if ((Dec_005DD810(&D_L39_0024CF20[j]->b19E6) ^ 0x14) == 0) {
                    func_L01_005131A0(id, 0xED3B);
                    func_L01_00512900(id, 0.0f);
                } else {
                    func_L01_005131A0(id, 0xED35);
                    func_L01_00512900(id, f);
                }
            }
        }
        func_L01_00512AB0(id, 1, t);
    }
    for (id = 0x5001B; id <= 0x50022; id++) {
        s32 j = id - 0x5001B;
        s32 t = 0;
        u32 col;

        if (j < func_L01_004D2128()) {
            e = func_L39_006646B0(j);
            nv = e;
            if (nv != 0 && nv->f2D0->fBC != 8 && nv->f2D0->fBC != 7) {
                k = -1;
                e2 = nv->f2D8;
                if (e2 == 0) {
                    e2 = nv->f2DC;
                }
                if (e2 != 0) {
                    k = e2->f2548;
                }
                t = func_L39_005D9F60((u8 *)nv->f2D0 + 0x10, k, fp);
                if (t != 0) {
                    col = 0x70000000 | (D_L39_0049A0C0[2] << 16) | (D_L39_0049A0C0[1] << 8) | D_L39_0049A0C0[0];
                    if (k == 0) {
                        col = 0x70000000 | (D_L39_0049A0B0[2] << 16) | (D_L39_0049A0B0[1] << 8) | D_L39_0049A0B0[0];
                    } else if (k == 1) {
                        col = 0x70000000 | (D_L39_0049A0B8[2] << 16) | (D_L39_0049A0B8[1] << 8) | D_L39_0049A0B8[0];
                    }
                    func_L01_0044E108((u8 *)nv->f2D0, (s32 *)&v38, (s32 *)&v3C);
                    func_L01_00512480(id, v38, v3C);
                    func_L01_00513548(id, 0.05f, 0.062000003f);
                    func_L01_005130C8(id, col);
                    f = func_L39_005DADC8(nv->f2D0);
                    func_L01_00512900(id, f);
                    switch (nv->f2D0->fAA) {
                    case 0x107C:
                        func_L01_005131A0(id, 0xED36);
                        break;
                    case 0x107E:
                        func_L01_005131A0(id, 0xED37);
                        break;
                    case 0x10C2:
                        func_L01_005131A0(id, 0xED4B);
                        break;
                    }
                }
            }
        }
        func_L01_00512AB0(id, 1, t);
    }
}
/* localdecomp:end func_L39_005DB268 */
