#include "common.h"

/* localdecomp:start func_L39_00674398 */
typedef union {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_00674398;

typedef struct {
    u8 pad0[0x68];
    s32 s68;
} Z_00674398;

typedef struct {
    u8 pad0[0x68];
    struct {
        u8 pad0[0x3D4];
        s32 s3D4;
        u8 pad3D8[4];
        s32 s3DC;
    } *p68;
} Q_00674398;

typedef struct {
    u8 pad0[0x2D0];
    Q_00674398 *p2D0;
    s32 s2D4;
    s32 s2D8;
    s32 s2DC;
    u8 pad2E0[0x2FC - 0x2E0];
    s16 h2FC;
} Obj_00674398;

typedef struct {
    u8 pad0[0x1A4];
    s32 s1A4;
    u8 pad1A8[0x1C0 - 0x1A8];
    s32 s1C0;
    s32 s1C4;
} Aux_00674398;

typedef struct {
    u8 pad0[0x19E4];
    u8 b19E4;
    u8 pad19E5[0x1A32 - 0x19E5];
    u8 b1A32[3];
    u8 pad1A35[0x1A41 - 0x1A35];
    u8 b1A41;
    u8 pad1A42[0x1A52 - 0x1A42];
    u8 b1A52[10];
    u8 pad1A5C[0x24C9 - 0x1A5C];
    u8 b24C9;
    u8 pad24CA[0x2514 - 0x24CA];
    s32 s2514;
    u8 b2518;
    u8 pad2519[0x2528 - 0x2519];
    Obj_00674398 *p2528;
    u8 pad252C[0x2534 - 0x252C];
    Aux_00674398 *p2534;
    u8 pad2538[0x254C - 0x2538];
    s32 s254C;
    u8 pad2550[0x44F0 - 0x2550];
    u8 b44F0;
} P_00674398;

typedef struct {
    u8 pad0[8];
    u8 b8;
    u8 pad9[0x12 - 9];
    u16 h12;
    u8 pad14[0x1E - 0x14];
    s16 h1E;
    u8 pad20;
    s8 b21;
    u8 pad22[0x80 - 0x22];
} E_00674398;

typedef struct {
    u8 pad0[0x108];
    f32 f108[2];
    u8 pad110[0x128 - 0x110];
    f32 f128[2];
    u8 pad130[0x148 - 0x130];
    f32 f148[2];
} T_00674398;

typedef struct {
    s32 s0;
    u8 pad4[0x20C - 4];
    T_00674398 *p20C;
    struct {
        u8 pad0[8];
        s32 s8;
        s32 sC;
    } *p210;
} G_00674398;

typedef struct {
    u8 pad0[0x180];
    s32 s180;
    u8 pad184[0x198 - 0x184];
    s8 b198;
} H_00674398;

typedef struct {
    u8 pad0[0x4D];
    u8 b4D;
    u8 pad4E[0x1F0 - 0x4E];
} R_00674398;

extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00241120, 16");
extern H_00674398 *D_L39_00241640;
__asm__(".extern D_L39_00241640, 16");
extern G_00674398 D_L39_00352940;
extern E_00674398 D_L39_0049C890[];
extern u8 D_L39_00483A00[];
extern u8 D_L39_004997E0[];
extern s32 D_L39_00240370[] __attribute__((section(".sdata")));
extern R_00674398 D_001FC6B0[];
extern s32 D_L39_002464A8[2];
extern s32 D_L39_00246488[2];
extern s32 D_L39_002464C8;
extern s32 D_L39_002464CC;
__asm__(".extern D_L39_002464A8, 8");
__asm__(".extern D_L39_00246488, 8");
__asm__(".extern D_L39_002464C8, 4");
__asm__(".extern D_L39_002464CC, 4");

extern P_00674398 *func_L39_0061BF38_00674398(s32);
extern s32 func_L39_006212E8(void *);
extern s32 func_L39_00648AE0(void *, s32);
extern void func_L39_005D72E8(s32, void *);
extern void func_L39_005DA870(s32, s32, s32, s32);
extern void func_L39_005DADF8(s32, s32, s32);
extern void func_L39_005DA7A8(s32, s32);
extern void func_L39_005DAC98(s32, s32, s32);
extern void func_L39_005DAEB8(s32, void *);
extern s32 func_L01_0040E020(void *);
extern void func_0038CAD0(s32 *);
extern s32 func_L39_00677398(s32);
extern void func_L39_006773E0(s32, s32);
extern s32 func_L39_00677430(s32);
extern void func_L39_00677478(s32, s32);
extern void func_L39_005E04A0(s32, s32);
extern void func_L39_005E20A8(s32, s32);
extern void func_L39_005E2010(void);
extern void func_L39_005D8D18(s32, f32 *, f32 *);
extern void func_L39_005DEBD0(s32);
extern void func_L39_005DEC68(s32);

static inline u8 DecB_00674398(u8 *qp) {
    u8 *q;
    Buf_00674398 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    q = qp;
    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        s32 row;

        row = ((k + i) & 7) * 209;
        *d++ = D_L39_00483A00[row + m];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.b[4];
}

static inline u16 DecH_00674398(u8 *qp) {
    u8 *q;
    Buf_00674398 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    q = qp;
    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        s32 row;

        row = ((k + i) & 7) * 209;
        *d++ = D_L39_00483A00[row + m];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

static inline u32 DecW_00674398(u8 *qp) {
    u8 *q;
    Buf_00674398 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    q = qp;
    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

void func_L39_00674398(void) {
    f32 a[2];
    f32 b[2];
    s32 found;
    s32 ok;
    s32 i;
    s32 j;
    s32 k;
    s16 v;

    found = 0;
    for (i = 0; i < *D_L39_00241120; i++) {
        P_00674398 *p;
        s32 idx;
        E_00674398 *e;
        Obj_00674398 *obj;

        p = func_L39_0061BF38_00674398(i);
        if (p->b2518 != 0) {
            func_L39_005D72E8(0, p);
            found = 1;
            continue;
        }
        idx = func_L39_006212E8(p);
        e = 0;
        if (idx != -1) {
            e = &D_L39_0049C890[idx];
        }
        obj = p->p2528;
        if (obj != 0) {
            s32 x;
            s32 y;
            s32 z;

            y = 5;
            x = 0xED36;
            if (obj->h2FC == 1) {
                x = 0xED37;
                if (p->s254C == 5 || p->s254C == 3) {
                    y = 8;
                    z = obj->p2D0->p68->s3D4;
                } else {
                    z = obj->p2D0->p68->s3DC;
                }
            } else if (obj->h2FC == 2) {
                x = 0xED4B;
                z = 5;
            } else {
                z = 5;
            }
            func_L39_005DA870(x, 0, 0, p->b24C9);
            func_L39_005DA870(-1, 0, 1, p->b24C9);
            func_L39_005DADF8(z, y, p->b24C9);
            func_L39_005DA7A8(p->b24C9, 8);
            func_L39_005D72E8(8, p);
            func_L39_005DAC98(x, p->p2528->s2D8 != 0, p->p2528->s2DC != 0);
        } else if (e != 0) {
            for (k = 0; k < 3; k++) {
                if ((v = DecB_00674398(&p->b1A32[k])) != 0) {
                    E_00674398 *e2;

                    if (func_L39_00648AE0(p, v)) {
                        e2 = &D_L39_0049C890[D_L39_0049C890[v].b21];
                    } else {
                        e2 = &D_L39_0049C890[v];
                    }
                    func_L39_005DA870(e2->h12, ((s16)DecH_00674398(&p->b1A41) >> v) & 1, k, p->b24C9);
                    if (k == 0) {
                        if (v != 9) {
                            s16 w;
                            E_00674398 *e3;

                            w = DecH_00674398(&p->b1A52[v]);
                            if (func_L39_00648AE0(p, v)) {
                                e3 = &D_L39_0049C890[D_L39_0049C890[v].b21];
                            } else {
                                e3 = &D_L39_0049C890[v];
                            }
                            func_L39_005DADF8(w, e3->h1E, p->b24C9);
                        }
                        func_L39_005DAEB8(v, p);
                        if (D_L39_0049C890[idx].b8 != 0 || idx == 12) {
                            func_L39_005DA7A8(p->b24C9, 8);
                        }
                    }
                } else {
                    func_L39_005DA870(0, 0, k, p->b24C9);
                }
            }
        }
        if (p->s2514 == 0) {
            if (p->p2534->s1A4 & 0x200) {
                if ((DecW_00674398(&p->b19E4) ^ 0x31) != 0) {
                    p->s2514 = 300;
                }
            }
        }
        if (p->b2518 == 0) {
            R_00674398 *r;
            s32 t;
            s32 flag;

            if (p->s2514 > 0) {
                func_L39_005D72E8(p->s2514, p);
                p->s2514 = 0;
            }
            t = D_L39_00240370[p->b24C9];
            r = D_001FC6B0;
            flag = 0;
            switch (r[t].b4D) {
            case 0:
                flag = (p->p2534->s1C4 >> 8) & 1;
                break;
            case 1:
                flag = (p->p2534->s1C4 >> 10) & 1;
                break;
            case 2:
                flag = (*(unsigned long *)&p->p2534->s1C0 & 0x50000000000) != 0;
                break;
            }
            if (flag) {
                p->b44F0 = 8;
                if (p->p2534->s1C4 & 0x100) {
                    func_L39_006773E0(i, (func_L39_00677398(i) ^ 1) & 0xFF);
                }
            } else if (func_L01_0040E020(&p->b44F0) == 2) {
                if (p->p2534->s1C0 & 0x400) {
                    func_L39_006773E0(i, (func_L39_00677398(i) ^ 1) & 0xFF);
                }
            }
            if (func_L39_00677430(i) == 0) {
                func_L39_005E04A0(i, 10);
                if (D_L39_00352940.s0 != -1) {
                    func_L39_005E20A8(i, 10);
                }
            } else {
                func_L39_00677478(i, 10);
            }
        }
    }
    ok = 1;
    if (D_L39_00241640->s180 == 0) {
        for (j = 0; j < 2; j++) {
            if (D_L39_00352940.p20C->f128[j] != D_L39_00352940.p20C->f148[j]) {
                D_L39_002464A8[j] = (D_L39_002464C8 * 5 + 2) / 6;
                D_L39_00352940.p20C->f128[j] = D_L39_00352940.p20C->f148[j];
            }
            if (D_L39_002464A8[j] > 0 && D_L39_00246488[j] <= 0) {
                D_L39_00246488[j] = (D_L39_002464CC * 5 + 2) / 6;
            }
            b[j] = D_L39_00246488[j] / ((D_L39_002464CC * 5 + 2) / 6);
            a[j] = D_L39_00352940.p20C->f128[j] / D_L39_00352940.p20C->f108[j];
            if (a[j] > 1.0f) {
                a[j] = 1.0f;
            }
            if (a[j] < 0.0f) {
                a[j] = 0.0f;
            }
            func_0038CAD0(&D_L39_00246488[j]);
            func_0038CAD0(&D_L39_002464A8[j]);
        }
    } else if (D_L39_00241640->s180 == 1) {
        f32 f;
        f32 x;

        f = 3.0f;
        if (D_L39_00241640->b198 > 0) {
            f = D_L39_00241640->b198;
        } else {
            x = D_L39_00352940.p210->s8;
            f = x < f ? f : x;
            x = D_L39_00352940.p210->sC;
            f = x < f ? f : x;
        }
        a[0] = D_L39_00352940.p210->s8 / f;
        a[1] = D_L39_00352940.p210->sC / f;
        b[0] = 0.0f;
        b[1] = 0.0f;
        if (a[0] > 1.0f) {
            a[0] = 1.0f;
        }
        if (a[0] < 0.0f) {
            a[0] = 0.0f;
        }
        if (a[1] > 1.0f) {
            a[1] = 1.0f;
        }
        if (a[1] < 0.0f) {
            a[1] = 0.0f;
        }
    } else {
        ok = 0;
    }
    if (ok) {
        if (found == 0 || *D_L39_00241120 == 2) {
            func_L39_005D8D18(10, a, b);
        }
    }
    if (*D_L39_00241120 == 2) {
        func_L39_005DEBD0(10);
    } else if (*D_L39_00241120 == 3) {
        func_L39_005DEC68(10);
    }
    if (D_L39_00352940.s0 != -1 && (found == 0 || *D_L39_00241120 == 2) && *D_L39_00241120 < 3) {
        func_L39_005E20A8(0, 10);
    } else {
        func_L39_005E2010();
    }
}
/* localdecomp:end func_L39_00674398 */

/* localdecomp:start func_L39_00674E08 */
typedef struct {
    u8 pad0[0x18A0];
    u8 arr[4][0xB50];
} Rooms_00674E08;
typedef struct {
    u8 pad0[0x1FCA8];
    Rooms_00674E08 rooms;
} World_00674E08;
typedef struct {
    u8 pad0[0x2544];
    s32 f2544;
} Obj_00674E08;
typedef struct {
    s32 f0;
    u8 pad4[0x18];
} Ent_00674E08;
__asm__(".extern D_L39_002464D4, 4");
__asm__(".extern D_L39_002464D8, 4");
extern s32 D_L39_00241118;
extern s32 *D_L39_00241120;
extern World_00674E08 *D_L39_00242A50;
extern Ent_00674E08 D_L39_004840A0[];
extern s32 D_L39_002464D4;
extern s32 D_L39_002464D8;
extern Obj_00674E08 *func_L39_0061BF38(s32);
extern void func_L39_00605878(void *);
extern void func_L39_006068A0(void *, s32);
extern u32 func_L01_004D0CB0(void *);
extern void func_L39_006070C0(void *, s32, s32, s32, u32);

s32 func_L39_00674E08(void) {
    Obj_00674E08 *p = func_L39_0061BF38(D_L39_00241118);
    s32 i;
    u32 r;
    Rooms_00674E08 *rooms;
    Rooms_00674E08 *r2;
    if (*D_L39_00241120 >= 2) {
        for (i = 0; i < 4; i++) {
            Rooms_00674E08 *r1 = &D_L39_00242A50->rooms;
            func_L39_00605878(&r1->arr[i]);
        }
    }
    r2 = &D_L39_00242A50->rooms;
    func_L39_006068A0(&r2->arr[D_L39_00241118], D_L39_00241118);
    if (D_L39_004840A0[p->f2544].f0 == 0) {
        if (*D_L39_00241120 == 1) {
            rooms = &D_L39_00242A50->rooms;
            r = func_L01_004D0CB0(&rooms->arr[D_L39_00241118]);
            func_L39_006070C0(rooms, D_L39_00241118, D_L39_002464D4, D_L39_002464D8, r >> 24);
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00674E08 */

/* localdecomp:start func_L39_00674F50 */
typedef union Buf_00674F50 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_00674F50;

typedef struct S_00674F50 {
    u8 pad0[0x1A11];
    u8 b1A11;
    u8 pad1A12[0x1A40 - 0x1A12];
    u8 b1A40;
    u8 pad1A41[0x24C9 - 0x1A41];
    u8 b24C9;
} S_00674F50;

typedef struct E_00674F50 {
    s32 w0;
    u8 pad4[0x14];
    s32 w18;
} E_00674F50;

typedef struct G_00674F50 {
    E_00674F50 e[8];
} G_00674F50;

extern s32 D_L39_0024BD40[] __attribute__((section(".sdata")));
extern s32 *D_L39_0024BD48[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_00246500, 8");
__asm__(".extern D_L39_00246510, 8");
__asm__(".extern D_L39_00246518, 8");
extern s32 D_L39_00246500[] __attribute__((section(".sdata")));
extern u8 D_L39_00246510[] __attribute__((section(".sdata")));
extern s32 D_L39_00246518[] __attribute__((section(".sdata")));
extern G_00674F50 D_L39_0049D510[];
extern u8 D_L39_00483A00[];
extern u16 D_L39_0049C922[];
extern u16 D_L39_0049C9A2[];
extern u16 D_L39_0049CA22[];
extern u16 D_L39_0049CAA2[];
extern u16 D_L39_0049CB22[];
extern u16 D_L39_0049CBA2[];
extern u16 D_L39_0049CC22[];
extern u16 D_L39_0049CD22[];
extern u16 D_L39_0049CE22[];
extern u16 D_L39_0049CEA2[];

static __inline__ u16 Dec2_00674F50(u8 *q) {
    Buf_00674F50 buf;
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
        *d++ = D_L39_00483A00[((k + i) & 7) * 209 + m];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

void func_L39_00674F50(u8 *p) {
    S_00674F50 *s = (S_00674F50 *)p;
    s32 i = s->b24C9;
    s32 j;
    unsigned long t;

    D_L39_00246500[i] = 0;
    D_L39_0024BD48[i] = &D_L39_00246518[i];
    D_L39_0024BD40[0] = 8;
    for (j = 0; j < 8; j++) {
        D_L39_0049D510[i].e[j].w0 = 0;
        D_L39_0049D510[i].e[j].w18 = 0;
    }
    if (D_L39_00246510[i] != 0) {
        if ((Dec2_00674F50(&s->b1A40) >> 11) & 1) {
            D_L39_0049D510[i].e[0].w0 = D_L39_0049CE22[0];
            D_L39_0049D510[i].e[0].w18 = 11;
        }
        if ((Dec2_00674F50(&s->b1A40) >> 12) & 1) {
            D_L39_0049D510[i].e[1].w0 = D_L39_0049CEA2[0];
            D_L39_0049D510[i].e[1].w18 = 12;
        }
        D_L39_0049D510[i].e[2].w0 = 0xED49;
        D_L39_0049D510[i].e[2].w18 = -2;
        D_L39_0049D510[i].e[4].w0 = 0xED4C;
        D_L39_0049D510[i].e[4].w18 = -4;
        if (s->b1A11 != 0) {
            D_L39_0049D510[i].e[5].w0 = 0xED3A;
            D_L39_0049D510[i].e[5].w18 = -1;
        }
        D_L39_0049D510[i].e[6].w0 = 0xED4E;
        D_L39_0049D510[i].e[6].w18 = -3;
    } else {
        t = Dec2_00674F50(&s->b1A40);
        if (((t >> 1) & 1) == 1) {
            D_L39_0049D510[i].e[0].w0 = D_L39_0049C922[0];
            D_L39_0049D510[i].e[0].w18 = 1;
        }
        t = Dec2_00674F50(&s->b1A40);
        if (((t >> 5) & 1) == 1) {
            D_L39_0049D510[i].e[1].w0 = D_L39_0049CB22[0];
            D_L39_0049D510[i].e[1].w18 = 5;
        }
        t = Dec2_00674F50(&s->b1A40);
        if (((t >> 4) & 1) == 1) {
            D_L39_0049D510[i].e[2].w0 = D_L39_0049CAA2[0];
            D_L39_0049D510[i].e[2].w18 = 4;
        }
        t = Dec2_00674F50(&s->b1A40);
        if (((t >> 7) & 1) == 1) {
            D_L39_0049D510[i].e[3].w0 = D_L39_0049CC22[0];
            D_L39_0049D510[i].e[3].w18 = 7;
        }
        t = Dec2_00674F50(&s->b1A40);
        if (((t >> 2) & 1) == 1) {
            D_L39_0049D510[i].e[4].w0 = D_L39_0049C9A2[0];
            D_L39_0049D510[i].e[4].w18 = 2;
        }
        t = Dec2_00674F50(&s->b1A40);
        if (((t >> 6) & 1) == 1) {
            D_L39_0049D510[i].e[5].w0 = D_L39_0049CBA2[0];
            D_L39_0049D510[i].e[5].w18 = 6;
        }
        t = Dec2_00674F50(&s->b1A40);
        if (((t >> 3) & 1) == 1) {
            D_L39_0049D510[i].e[6].w0 = D_L39_0049CA22[0];
            D_L39_0049D510[i].e[6].w18 = 3;
        }
        if ((Dec2_00674F50(&s->b1A40) >> 9) & 1) {
            D_L39_0049D510[i].e[7].w0 = D_L39_0049CD22[0];
            D_L39_0049D510[i].e[7].w18 = 9;
        }
    }
}
/* localdecomp:end func_L39_00674F50 */
