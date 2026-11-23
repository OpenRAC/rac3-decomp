#include "common.h"

/* NTSC-U counterpart of func_L39_0066AFA0 (src/levels/shared/L39_0066AFA0.c) */
typedef struct { s32 id; u8 p4[0x2CC]; s32 w2D0; u8 p2D4[0x340 - 0x2D4]; } E_665D48;
extern s32 D_L39_00246378;
extern E_665D48 D_L39_00337800[];
extern s32 D_L39_00246378;
extern u8 D_L39_004998A0[];

/* localdecomp:start func_L39_00668698 */
#include "vu0.h"
typedef struct Vt_0066AFA0 { u8 pad0[0x34]; void (*f34)(void *, s32, s32, s32, s32); } Vt_0066AFA0;
typedef struct Sub_0066AFA0 { u8 pad0[0x10]; s32 w10; } Sub_0066AFA0;
typedef struct Ply_0066AFA0 {
    u8 pad0[0x14];
    Vt_0066AFA0 *vt;
    u8 pad18[0x320 - 0x18];
    s16 h320;
    u8 pad322[0x19E4 - 0x322];
    u8 b19E4;
    u8 pad19E5[0x1A0A - 0x19E5];
    u8 b1A0A;
    u8 pad1A0B[0x2548 - 0x1A0B];
    s32 w2548;
} Ply_0066AFA0;
typedef struct Obj_0066AFA0 {
    u8 pad0[0x10];
    vu0_q v10;
    u8 pad20[4];
    Sub_0066AFA0 *p24;
    u8 pad28[0x34 - 0x28];
    u16 h34;
    u8 pad36[0x78 - 0x36];
    s32 w78;
    u8 pad7C[0x96 - 0x7C];
    u16 h96;
    s32 w98;
    u8 pad9C[0xA8 - 0x9C];
    u8 bA8;
    u8 padA9;
    s16 hAA;
    u8 padAC[0xBC - 0xAC];
    u8 bBC;
    u8 padBD[0xF0 - 0xBD];
    vu0_q qF0;
} Obj_0066AFA0;
typedef struct Slf_0066AFA0 {
    u8 pad0[0x20];
    u8 v20[0x1F0 - 0x20];
    vu0_q q1F0;
    vu0_q q200;
    u8 pad210[0x290 - 0x210];
    vu0_q q290;
    vu0_q q2A0;
    u8 pad2B0[0x2D0 - 0x2B0];
    Obj_0066AFA0 *o2D0;
    u8 pad2D4[4];
    Ply_0066AFA0 *p2D8;
    Ply_0066AFA0 *p2DC;
    u8 pad2E0[0x2EC - 0x2E0];
    s32 w2EC;
    s32 w2F0;
    s32 w2F4;
    s32 w2F8;
    s16 h2FC;
    u8 pad2FE[0x308 - 0x2FE];
    f32 f308;
    u8 pad30C[0x314 - 0x30C];
    f32 f314;
    u8 pad318[0x31C - 0x318];
    s32 w31C;
    s32 w320;
    s32 w324;
    u8 pad328[0x32C - 0x328];
    s32 w32C;
    s32 w330;
    u8 pad334[0x340 - 0x334];
} Slf_0066AFA0;
typedef struct G_0066AFA0 { u8 pad0[0x128]; s32 w128; u8 pad12C[0x168 - 0x12C]; u8 b168; u8 pad169[3]; s32 w16C; } G_0066AFA0;
typedef void (*Fn_0066AFA0)(void *);
typedef struct Tbl_0066AFA0 { Fn_0066AFA0 f0; s32 w4, w8, wC; Fn_0066AFA0 f10; s32 w14, w18; } Tbl_0066AFA0;
typedef union Buf_0066AFA0 { u8 b[8]; u32 w[2]; } Buf_0066AFA0;

extern G_0066AFA0 D_001A5E50;
extern Tbl_0066AFA0 D_L39_0033AC08[];
extern Obj_0066AFA0 *D_L39_002638C0 __attribute__((section(".data")));
extern s32 *D_L39_0024CF20[8] __attribute__((section(".sdata")));
extern s32 func_00388398(void *);
extern f32 func_00388730(void *, void *);
extern void func_L01_00438908(void *, s32, s32, s32);
extern s32 func_003CF790(void *, s32, s32, s32, f32);
extern void func_L39_006683A0(void *, s32);
extern void func_L39_00664930(void *, u32, s32, s32);
extern void func_L39_0061C568(void *, void *, s32);
extern void func_L39_00666488(void *);
extern void func_L39_00667DB8(void *, s32);
extern void func_L39_006669C8(void *, u8 *);
extern void func_L39_00664E28(void *, void *, s32);
extern void func_L39_00664B10(void *, void *, s32);
extern void func_L39_00625860(void *, s32);
extern void func_L39_00667750(void *, u8);

/* reads an encrypted u32 (the same sequence as func_L39_0066ADA0's) */
static __inline__ u32 decrypt_0066AFA0(u8 *q) {
    Buf_0066AFA0 buf;
    u32 a;
    s32 n;
    s32 k;
    s32 m;
    s32 j;
    u8 *dp;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    dp = buf.b;
    for (j = 0; j < 40; j += 5) {
        *dp++ = D_L39_004998A0[m + ((k + j) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    buf.w[0] = a;
    buf.w[1] ^= a;
    return buf.w[1];
}

void func_L39_00668698(void) {
    s32 i;
    s32 k;
    u8 flag;
    s32 t;
    Slf_0066AFA0 *e;
    Ply_0066AFA0 *pl;
    Obj_0066AFA0 *o;
    u8 b;
    s32 v;

    flag = 0;
    t = D_001A5E50.w128;
    for (i = 0; i < D_L39_00246378; i++) {
        e = (Slf_0066AFA0 *)&D_L39_00337800[i];
        if (e != 0 && e->o2D0 != 0) {
            if (++e->w330 > 100) {
                e->w330 = 100;
            }
            if (e->w330 > 60 && e->f308 <= 0.0f && e->w324 != 0) {
                b = e->o2D0->bBC;
                if (b != 9) {
                    if (b != 10) {
                        if (b != 11) {
                            if (b != 7) {
                                if (b != 8) {
                                    if (e->p2D8 != 0) {
                                        e->p2D8->h320 = 2;
                                    }
                                    if (e->p2DC != 0) {
                                        e->p2D8->h320 = 2;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (D_001A5E50.b168 != 0) {
                func_00388398(&e->w31C);
                func_00388398(&e->w320);
            }
            e->w32C = -1;
            if (e->p2D8 != 0) {
                u32 dec = decrypt_0066AFA0(&e->p2D8->b19E4);
                if ((dec ^ 0x31) != 0 && e->o2D0->hAA != 0x10C2) {
                    e->p2D8->vt->f34(e->p2D8, 0x31, 1, 0, 1);
                    if (!(e->w2F8 & 0x4000000)) {
                        e->p2D8->b1A0A = 1;
                    }
                }
            }
            if (e->p2DC != 0) {
                u32 dec = decrypt_0066AFA0(&e->p2DC->b19E4);
                if ((dec ^ 0x31) != 0) {
                    e->p2DC->vt->f34(e->p2DC, 0x31, 1, 0, 1);
                    if (!(e->w2F8 & 0x4000000)) {
                        e->p2DC->b1A0A = 1;
                    }
                }
            }
            if (e->p2D8 != 0) {
                v = e->p2D8->w2548;
                func_L39_006683A0(e, v);
                e->w32C = v;
                e->w2EC = 0;
            } else if (e->p2DC != 0) {
                v = e->p2DC->w2548;
                func_L39_006683A0(e, v);
                e->w32C = v;
                e->w2EC = 0;
            } else {
                s32 f = e->w2F8;
                if (f & 0x400) {
                    if (f & 0x100) {
                        func_L39_006683A0(e, 0);
                        e->w32C = 0;
                    } else if (f & 0x200) {
                        func_L39_006683A0(e, 1);
                        e->w32C = 1;
                    }
                } else if (e->h2FC == 0) {
                    e->o2D0->w78 = 0x787878;
                } else {
                    func_L01_00438908(e->o2D0, 0x80, 0x80, 0x80);
                }
                if (e->o2D0->bBC == 0) {
                    vu0_v4 d;
                    vec_sub_ba(&d, &e->q290, &e->o2D0->v10);
                    if (func_00388730(&d, &d) > 10.0f) {
                        if (++e->w2EC > 7200) {
                            e->f308 = 0.0f;
                            func_L39_00664930(e, 0xFFFFFFFF, 6, D_001A5E50.w16C);
                        }
                    }
                }
            }
            o = e->o2D0;
            if (o->bBC == 7) {
                o->w98 = 0;
                e->o2D0->h34 |= 0x41;
                func_00388398(&e->w2F0);
                if (e->w2F0 <= 0) {
                    s32 r = func_003CF790(&e->q290, 1, 0, 0, e->f314 * 1.75f);
                    if (r == 0 || (r == 1 && D_L39_002638C0->hAA == 0x1981)) {
                        Fn_0066AFA0 fn;
                        e->o2D0->v10 = e->q290;
                        e->o2D0->qF0 = e->q2A0;
                        e->q1F0 = e->q290;
                        e->q200 = e->q2A0;
                        fn = D_L39_0033AC08[e->h2FC].f0;
                        if (fn != 0) {
                            fn(e->o2D0);
                        }
                        func_L39_0061C568(e->v20, &e->o2D0->v10, D_001A5E50.w128);
                        e->w324 = 0;
                        e->o2D0->bA8 = 0xFF;
                        e->w2F8 |= 8;
                        if (e->w2F8 & 0x300) {
                            e->w2F8 |= 0x400;
                        }
                        e->o2D0->w98 = e->o2D0->p24->w10;
                        e->o2D0->h34 &= 0xFFBE;
                        e->o2D0->bBC = 0;
                    }
                }
            } else if (o->bBC == 8) {
                o->w98 = 0;
                e->o2D0->h34 |= 0x41;
            } else if (o->bBC != 10) {
                func_L39_00666488(e);
                func_L39_00667DB8(e, t);
                func_L39_006669C8(e, &flag);
                if (D_L39_0033AC08[e->h2FC].f10 != 0) {
                    (D_L39_0033AC08 + e->h2FC)->f10(e->o2D0);
                }
            } else if (o->h96 > 180) {
                o->bBC = 7;
                e->w2F0 = e->w2F4;
                e->o2D0->h96 = 0;
                if (e->p2D8 != 0) {
                    pl = e->p2D8;
                    if (!(e->w2F8 & 0x4000000)) {
                        pl->vt->f34(e->p2D8, 0x76, 0, 0, 0);
                        pl->b1A0A = 1;
                    }
                    func_L39_00664E28(e, pl, 0);
                    if (!(e->w2F8 & 0x4000000)) {
                        func_L39_00625860(pl, 0);
                        pl->b1A0A = 1;
                    }
                }
                if (e->p2DC != 0) {
                    pl = e->p2DC;
                    if (!(e->w2F8 & 0x4000000)) {
                        pl->vt->f34(e->p2DC, 0x76, 0, 0, 0);
                        pl->b1A0A = 1;
                    }
                    func_L39_00664B10(e, pl, 0);
                    if (!(e->w2F8 & 0x4000000)) {
                        func_L39_00625860(pl, 0);
                        pl->b1A0A = 1;
                    }
                }
            }
            e->o2D0->h96++;
        }
    }
    for (k = 0; k < 8; k++) {
        pl = (Ply_0066AFA0 *)D_L39_0024CF20[k];
        if (pl != 0) {
            func_L39_00667750(pl, flag);
        }
    }
}
/* localdecomp:end func_L39_00668698 */
