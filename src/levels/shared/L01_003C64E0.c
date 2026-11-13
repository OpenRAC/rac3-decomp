#include "common.h"

typedef struct {
    u8 pad0[257];
    u8 unk101;
    u8 pad102[1724 - 258];
    s32 unk6BC;
} V3C4E78;
typedef struct {
    u8 pad0[32];
    u8 state;
    u8 pad21[104 - 33];
    V3C4E78 *pVars;
} M3C4E78;

typedef struct {
    u8 pad0[0x700];
    s32 tbl[16];
} T_003C67A0;

INCLUDE_ASM("asm/levels", func_L01_003C64E0);

/* localdecomp:start func_L01_003C6628 */
typedef struct {
    u8 pad0[0x6B0];
    s32 x6B0;
    u8 pad6B4[4];
    s32 x6B8;
    s32 x6BC;
} V_003C6628;
typedef struct {
    u8 pad0[0x68];
    V_003C6628 *v;
} M_003C6628;

s32 func_L01_003C6628(M_003C6628 *m) {
    V_003C6628 *v = m->v;
    if (v->x6BC == v->x6B0) return 1;
    if (v->x6B8 != -1 && v->x6BC == v->x6B8) return 1;
    return 0;
}
/* localdecomp:end func_L01_003C6628 */

/* localdecomp:start func_L01_003C6668 */
extern int D_L01_001F3F40[];
int func_L01_003C6668(char *a) {
    a = *(char **)(a + 104);
    if (*(int *)(a + 204) == -1) {
        return 0;
    }
    return D_L01_001F3F40[0] == *(int *)(a + 224);
}
/* localdecomp:end func_L01_003C6668 */

/* localdecomp:start func_L01_003C6698 */
extern int func_L01_003C5698(char *, char *);
int func_L01_003C6698(char *m)
{
    char *p = *(char **)(m + 104);
    int v = func_L01_003C5698(m, p);
    int r = -1;
    if (*(int *)(p + 1724) != v) {
        r = *(int *)(p + 1724);
    }
    return r;
}
/* localdecomp:end func_L01_003C6698 */

/* localdecomp:start func_L01_003C66D8 */
extern int func_L01_003C5698(char *, char *);
void func_L01_003C66D8(void *p) {
    ((void (*)(void *, s32))func_L01_003C5698)(p, *(s32 *)((u8 *)p + 0x68));
}
/* localdecomp:end func_L01_003C66D8 */

/* localdecomp:start func_L01_003C66F8 */
extern void func_L01_003C6EF0(s32 unused, u8 *s);
extern int func_L01_003C5698(char *, char *);


extern s32 D_L01_001DEE54;
extern void func_L01_003C76A0(M3C4E78 *, V3C4E78 *, s32);
extern void func_L01_004450F0(M3C4E78 *, s32, s32);
extern void func_L01_003C5290(M3C4E78 *, V3C4E78 *);

void func_L01_003C66F8(M3C4E78 *m, s32 id, s32 b) {
    V3C4E78 *v = m->pVars;
    s32 old;

    if (id < 0) {
        id = ((s32 (*)(M3C4E78 *, V3C4E78 *))func_L01_003C5698)(m, v);
    }
    old = v->unk6BC;
    v->unk6BC = id;
    D_L01_001DEE54 = id;
    v->unk101 = b;
    func_L01_003C76A0(m, v, id != old);
    if ((u32)(m->state - 4) >= 2) {
        func_L01_004450F0(m, 3, -1);
        ((void (*)(M3C4E78 *, V3C4E78 *))func_L01_003C6EF0)(m, v);
        func_L01_003C5290(m, v);
    }
}
/* localdecomp:end func_L01_003C66F8 */

/* localdecomp:start func_L01_003C67A0 */
extern void func_L01_003C54E8(void *, V3C4E78 *);


void func_L01_003C67A0(M3C4E78 *m) {
    V3C4E78 *v;

    if (m->state == 4) {
        v = m->pVars;
        if (((T_003C67A0 *)v)->tbl[v->unk6BC] != -1) {
            func_L01_004450F0(m, 5, -1);
        } else {
            func_L01_003C54E8(m, v);
        }
    }
}
/* localdecomp:end func_L01_003C67A0 */

/* localdecomp:start func_L01_003C6808 */
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern void func_L01_0043B510(s32);
void func_L01_003C6808(u8 *a0) {
    if (a0[176] != 255) {
        if (!(D_001BBC40[a0[176] + D_001D545C * 16] & 0x80)) {
            func_L01_0043B510(a0[176]);
        }
    }
}
/* localdecomp:end func_L01_003C6808 */

/* localdecomp:start func_L01_003C6860 */
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern s32 func_00382380(void *, s32, s32);

s32 func_L01_003C6860(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 *e = (s32 *)(p + 0x40);
    s32 i = 0;
    s32 v;
    s32 cc;
    s32 r;
    u8 *base = D_001A4BE0;

    while (i < 6) {
        v = *e;
        i++;
        if (v != 0 && *(s32 *)(base + 0x35C) == v) {
            return 1;
        }
        e++;
    }
    cc = *(s32 *)(p + 0xCC);
    if (cc != -1) {
        r = func_00382380(D_001A4C60, cc, 0);
        if (r != 0) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_003C6860 */

INCLUDE_ASM("asm/levels", func_L01_003C68E8);

INCLUDE_ASM("asm/levels", func_L01_003C69F8);

/* localdecomp:start func_L01_003C6B98 */
s32 func_L01_003C6B98(u8 *p) {
    u32 one = 1;
    return one < (u8)(p[32] - 8);
}
/* localdecomp:end func_L01_003C6B98 */

INCLUDE_ASM("asm/levels", func_L01_003C6BB0);

/* localdecomp:start func_L01_003C6D00 */
s32 func_L01_003C6D00(u8 *obj) {
    return obj[32] != 11;
}
/* localdecomp:end func_L01_003C6D00 */

/* localdecomp:start func_L01_003C6D10 */
extern void func_L01_003C55B8(void *, s32);
void func_L01_003C6D10(void *p) {
    func_L01_003C55B8(p, *(s32 *)((u8 *)p + 0x68));
}
/* localdecomp:end func_L01_003C6D10 */

INCLUDE_ASM("asm/levels", func_L01_003C6D30);

/* localdecomp:start func_L01_003C6E78 */
void func_L01_003C6E78(void *a, s32 *b) {
    switch (b[0xB0 / 4]) {
    case 0:
        b[0xB0 / 4] = 1;
        break;
    case 1:
    case 2:
        break;
    case 3:
        b[0xB0 / 4] = 1;
        break;
    }
}
/* localdecomp:end func_L01_003C6E78 */

/* localdecomp:start func_L01_003C6EC0 */
extern int D_L01_001DFB40;
void func_L01_003C6EC0(int a0, unsigned char *s) { int v = *(int *)(s + 0xB0); if (v < 3) { if (v > 0) { int g = D_L01_001DFB40; *(int *)(s + 0xB0) = 3; *(int *)(s + 0xA4) = g; } } }
/* localdecomp:end func_L01_003C6EC0 */

/* localdecomp:start func_L01_003C6EF0 */
extern u8 D_001A30B0[];
extern void func_003A4F28(s32 a0);
void func_L01_003C6EF0(s32 unused, u8 *s) {
    s32 idx;
    u8 *e;

    *(s32 *)(s + 1652) = 0;
    idx = *(s32 *)(s + 160);
    *(s32 *)(s + 1684) = 0;
    *(s32 *)(s + 1704) = 0;
    *(s32 *)(s + 176) = 0;
    if (idx != -1) {
        e = D_001A30B0 + idx * 128;
        if (*(s32 *)(e + 220) == *(s32 *)(s + 76) && e[208] != 0) {
            func_003A4F28(idx);
        }
    }
    *(s32 *)(s + 160) = -1;
}
/* localdecomp:end func_L01_003C6EF0 */

INCLUDE_ASM("asm/levels", func_L01_003C6F68);

INCLUDE_ASM("asm/levels", func_L01_003C7000);

INCLUDE_ASM("asm/levels", func_L01_003C7560);

INCLUDE_ASM("asm/levels", func_L01_003C76A0);

INCLUDE_ASM("asm/levels", func_L01_003C7810);

/* localdecomp:start func_L01_003C7A68 */
extern void func_L01_00477ED0(int, int, float, float, float);
void func_L01_003C7A68(void *a, char *b, float f) {
    func_L01_00477ED0(*(int *)(b + 192), 1, *(float *)(b + 332), *(float *)(b + 196), f);
}
/* localdecomp:end func_L01_003C7A68 */

INCLUDE_ASM("asm/levels", func_L01_003C7A98);

INCLUDE_ASM("asm/levels", func_L01_003C7BC0);

INCLUDE_ASM("asm/levels", func_L01_003C7C80);

INCLUDE_ASM("asm/levels", func_L01_003C7D38);

INCLUDE_ASM("asm/levels", func_L01_003C8400);

INCLUDE_ASM("asm/levels", func_L01_003C88E0);

/* localdecomp:start func_L01_003C8D60 */
extern void func_L01_003C8400(u8 *, u8 *);
extern void func_L01_003C88E0(u8 *, u8 *);
extern void func_003A9440(s32, unsigned long);

void func_L01_003C8D60(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 104);

    func_L01_003C8400(a0, s);
    func_L01_003C88E0(a0, s);
    func_003A9440(8, 0);
    func_003A9440(71, 0x5360B);
}
/* localdecomp:end func_L01_003C8D60 */
