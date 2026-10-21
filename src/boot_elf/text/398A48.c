#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003A96A8(s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 398040.c's earlier functions (tools/port_from_us.py) */
extern s32 D_001D5F00[];
extern s32 D_001D5EE8[];
extern s32 D_001D9F4C;
extern s32 D_001D9F48;
extern void func_13B0C8();
extern void func_003980A0();
typedef struct { u8 pad[0x10]; s32 a; u16 b; u8 pad2[0x1A]; } S_3934E8;
extern void func_00123C90(void);
extern void func_00123C20(void);
extern s32 func_11F1E0();
extern s32 func_11F1C0();
extern s32 func_001240E0();
extern void func_003981B0(void);
extern u8 D_00227580_00398288[];
extern u8 D_3F3777[];
extern u8 D_01FF8000[];
extern u8 D_01FFC000[];
extern u32 D_001DA058;
extern s32 func_0011A264(s32, s32, s32);
extern void func_0038E4C8();
extern u8 D_002FD0F0[];
extern s32 D_002FCE98[];
typedef struct { s32 a, b; } P_3936A8;
extern P_3936A8 D_002FC840[];
extern s32 D_001DA5D4;
extern void func_0038D068();

/* localdecomp:start func_00398A48 */
typedef struct { unsigned long z; s16 h8; s16 hA; s16 hC; s16 hE; } E_393878;
typedef struct { s16 h0; s16 h2; s16 h4; u8 p6[0x1A]; s32 f20; } F_393878;
typedef struct { u8 p0[4]; s16 h4; s16 h6; u8 p8[4]; s16 hC; u8 pE[2]; s32 f10; s32 f14; s32 f18; s32 f1C; s32 f20[1]; } H_393878;
extern H_393878 *D_001DA5F0;
void func_00398A48(H_393878 *p) {
    H_393878 *q;
    s32 i, k;
    D_001DA5F0 = p;
    p->h4 = 1;
    p->f10 += (s32)p;
    p->f14 += (s32)p;
    p->f18 += (s32)p;
    if (p->f1C) p->f1C += (s32)p;
    q = D_001DA5F0;
    {
        s32 *src = (s32 *)q->f10;
        for (i = 0; i < q->hC; i++) {
            s32 a = *src++ >> 4;
            s32 b = *src++ >> 4;
            s32 c, d;
            { s32 r; __asm__("plzcw %0, %1" : "=r"(r) : "r"(*src++)); c = 30 - r; }
            { s32 r; __asm__("plzcw %0, %1" : "=r"(r) : "r"(*src++)); d = 30 - r; }
            ((E_393878 *)q->f10)[i].hA = a;
            ((E_393878 *)q->f10)[i].h8 = b;
            ((E_393878 *)q->f10)[i].hC = c;
            ((E_393878 *)q->f10)[i].hE = d;
            ((E_393878 *)q->f10)[i].z = 0;
        }
    }
    for (k = 0; k < D_001DA5F0->h6; k++) {
        F_393878 *e = (F_393878 *)(D_001DA5F0->f20[k] + (s32)p);
        s32 j;
        if (!(e->h2 & 1)) {
            if (e->h4) {
                e->h2 = e->h4;
                e->h4 = 0;
            }
        }
        D_001DA5F0->f20[k] = (s32)e;
        for (j = 0; j < e->h0; j++) {
            ((F_393878 *)((u8 *)e + j * 0x20))->f20 += (s32)p;
        }
    }
}
/* localdecomp:end func_00398A48 */

/* localdecomp:start func_00398BE8 */
typedef struct { s32 a, b, c, d; } E_00393A18;
typedef struct { u8 p0[0x1EB4]; s32 x1EB4; E_00393A18 e[1]; } S_160C40_00393A18;
typedef struct { u8 p0[0x10]; s32 x10; u8 p14[0x10]; s32 x24; } S_1A1ED0_00393A18;
typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; } T_00393A18;
extern S_160C40_00393A18 D_160C40_00398BE8;
extern S_1A1ED0_00393A18 D_1A1ED0_00398BE8;
extern unsigned long D_1D4B70[1];
extern s32 func_003A2B50(s32);
extern s32 func_003A2AF0(s32, s32, s32);
extern s32 func_00381BC0(void);
extern void func_12C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
void func_00398BE8(s32 n0) {
    s32 n;
    u8 buf[0x60];
    u8 *p;
    s32 *list;
    S_160C40_00393A18 *b;
    S_1A1ED0_00393A18 *r;
    s32 i, a, c;
    func_003A96A8(1);
    n = n0;
    p = *(u8 **)0x1D4B64;
    func_003A2B50(1);
    if (func_00381BC0() > 0) n = func_00381BC0();
    b = &D_160C40_00398BE8;
    func_003A2AF0((s32)p, b->e[n].c + b->x1EB4, b->e[n].d);
    list = (s32 *)(p + 4);
    r = &D_1A1ED0_00398BE8;
    c = r->x24;
    a = r->x10;
    *(s32 *)0x1D4B68 = *(s32 *)p;
    for (i = 0; i < *(s32 *)0x1D4B68; i++) {
        {
            s32 tbp = a >> 8;
            u8 *q = p + *list;
            u8 *q20 = q + 0x20;
            s32 cbp, w, h, k, lz;
            func_12C9A0(buf, tbp, 1, 0, 0, 0, 0x10, 0x10);
            cbp = c >> 8;
            a += 0x400;
            func_11F0A0(0);
            list++;
            func_12CCC8(buf, q20);
            func_12A9F0(0, 0);
            w = *(s32 *)(q + 8);
            __asm__("plzcw %0, %1" : "=r"(lz) : "r"(w));
            k = 30 - lz;
            h = w >> 6;
            if (h <= 0) h = 1;
            func_12C9A0(buf, cbp, h, 0x1B, 0, 0, ((T_00393A18 *)q)->h8, ((T_00393A18 *)q)->hC);
            func_11F0A0(0);
            func_12CCC8(buf, q + 0x420);
            func_12A9F0(0, 0);
            D_1D4B70[i] = (unsigned long)cbp | ((unsigned long)h << 14) | ((unsigned long)0x1B << 20)
                | ((unsigned long)k << 26) | ((unsigned long)k << 30) | ((unsigned long)1 << 34)
                | ((unsigned long)tbp << 37) | ((unsigned long)4 << 61);
            c += *(s32 *)(q + 8) * *(s32 *)(q + 0xC) * 4;
        }
    }
    func_003A2AF0((s32)p, D_160C40_00398BE8.e[n].a + D_160C40_00398BE8.x1EB4, D_160C40_00398BE8.e[n].b);
}
/* localdecomp:end func_00398BE8 */

/* localdecomp:start func_00398E68 */
extern unsigned long D_0022CAD0[3];
extern s32 D_002DDC30[];
extern s32 D_002DA740[];
extern s32 D_001D4B64;
extern s32 D_001D4B68;
extern unsigned long D_001D4B70[1];
__asm__(".extern D_001D5F40, 4");
extern s32 D_001D5F40;
extern s32 D_002DE3B0[];
typedef struct { u8 p0[8]; u8 f8; u8 f9; u8 pa[5]; u8 fF; u8 p10[4]; s32 f14; } S_393C98;
typedef struct { s32 a; s32 b; } E_393C98;
extern E_393C98 D_00337480[];
extern void func_00399D08();
extern void func_0038CF58();
extern s32 func_00381BC0();
extern void func_0038D108();
void func_00398E68(s32 a) {
    s32 i, n;
    S_393C98 *p;
    n = D_001D4B68;
    for (i = 0; i < n; i++) {
        D_0022CAD0[i * 3] = D_001D4B70[i];
        D_0022CAD0[i * 3 + 1] = 0xFFA0000000E0;
        D_0022CAD0[i * 3 + 2] = 0x40000400004000;
    }
    func_00399D08(D_001D4B64, 0, &D_001D5F40);
    D_002DDC30[0] = 0xFFFC0000;
    func_0038CF58(D_002DE3B0, -1, 0x10);
    {
        S_393C98 *p1 = ((S_393C98 **)D_002DA740)[0];
        p1->f9 = p1->f8;
    }
    if (func_00381BC0() > 0) a = func_00381BC0();
    p = ((S_393C98 **)D_002DA740)[0];
    func_0038D108(p->f14 - (p->fF << 4), D_00337480[a].a, D_00337480[a].b);
}
/* localdecomp:end func_00398E68 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00398F80);

/* localdecomp:start func_00398F98 */
typedef struct { u8 p0[0x18]; s32 f18; u8 p1c[0x1C]; unsigned long f38; } S_16C580_00393DC8;
typedef struct { u8 p0[0x1284]; s32 f1284; u8 p1[0xAD8]; struct { s32 a; s32 b; } e[1]; } S_160C40_00393DC8;
extern S_16C580_00393DC8 D_16C580;
extern S_160C40_00393DC8 D_160C40;
extern s32 D_002275F0[];
extern unsigned long D_0022CAD0[3];
__asm__(".extern D_001D5F30, 4");
extern s32 D_001D5F30;
extern void func_003A96A8(s32);
extern s32 func_003A2AF0(s32, s32, s32);
extern void func_00399E28(s32, s32, void *, s32);
void func_00398F98(s32 n) {
    S_160C40_00393DC8 *b;
    s32 h;
    D_16C580.f18 = n;
    func_003A96A8(1);
    b = &D_160C40;
    h = D_002275F0[0];
    func_003A2AF0(h, b->e[n].a + b->f1284, b->e[n].b);
    D_0022CAD0[0] = D_16C580.f38;
    D_0022CAD0[1] = 0xFFA0000000E0;
    D_0022CAD0[2] = 0x40000400004000;
    func_00399E28(h, 0, &D_001D5F30, -1);
}
/* localdecomp:end func_00398F98 */

/* localdecomp:start func_00399060 */
/* MATCH */
typedef struct { u8 p0[0x30]; s32 x30; u8 p34[4]; unsigned long x38; } S_16C580_00393E90;
typedef struct { u8 p0[0x1284]; s32 f1284; u8 p1[0xAF0]; struct { s32 a; s32 b; } e[1]; } S_160C40_00393E90;
typedef struct { u8 p0[0x18]; s32 x18; u8 p1c[0x10]; s32 x2C; } S_1A1ED0_00393E90;
typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; } T_00393E90;
extern S_16C580_00393E90 D_16C580_00399060;
extern S_160C40_00393E90 D_160C40_00399060;
extern S_1A1ED0_00393E90 D_1A1ED0_00399060;
__asm__(".extern D_001DA05C, 16");
extern s32 D_001DA05C;
extern s32 D_001DA048[];
extern s32 func_003A2B50(s32);
extern s32 func_003A2AF0(s32, s32, s32);
extern void func_12C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
void func_00399060(s32 n) {
    u8 buf[0x60];
    S_16C580_00393E90 *g = &D_16C580_00399060;
    S_160C40_00393E90 *b;
    S_1A1ED0_00393E90 *r;
    u8 *t;
    u8 *q;
    s32 w, h, k, lz;
    g->x30 = n;
    func_003A96A8(1);
    t = (u8 *)D_001DA048[1 - D_001DA05C];
    func_003A2B50(1);
    b = &D_160C40_00399060;
    q = t + 0x20;
    func_003A2AF0((s32)t, b->e[n].a + b->f1284, b->e[n].b);
    r = &D_1A1ED0_00399060;
    func_12C9A0(buf, r->x18 >> 8, 1, 0, 0, 0, 0x10, 0x10);
    func_11F0A0(0);
    func_12CCC8(buf, q);
    func_12A9F0(0, 0);
    w = *(s32 *)(t + 8);
    __asm__("plzcw %0, %1" : "=r"(lz) : "r"(w));
    k = 30 - lz;
    h = w >> 6;
    if (h <= 0) h = 1;
    func_12C9A0(buf, r->x2C >> 8, h, 0x1B, 0, 0, ((T_00393E90 *)t)->h8, ((T_00393E90 *)t)->hC);
    func_11F0A0(0);
    func_12CCC8(buf, t + 0x420);
    func_12A9F0(0, 0);
    g->x38 = (unsigned long)(r->x2C >> 8) | ((unsigned long)h << 14) | ((unsigned long)0x1B << 20)
           | ((unsigned long)k << 26) | ((unsigned long)k << 30) | ((unsigned long)1 << 34)
           | ((unsigned long)(r->x18 >> 8) << 37) | ((unsigned long)4 << 61);
}
/* localdecomp:end func_00399060 */
