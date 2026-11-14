#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00674398);

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
