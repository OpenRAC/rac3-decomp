#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00397D48(s32, s32);
extern void func_00397EA8(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

extern s32 D_001D5F00[];
extern s32 D_001D5EE8[];
extern s32 D_001D9F4C;
extern s32 D_001D9F48;
extern void func_13B0C8();
extern void func_00397CC0();
typedef struct { u8 pad[0x10]; s32 a; u16 b; u8 pad2[0x1A]; } S_3934E8;
/* localdecomp:start func_00397D48 */
__asm__(".extern D_001D9F48_f, 4");
extern s32 D_001D5F00_f[];
extern s32 D_001D5EE8_f[];
extern s32 D_001D9F4C_f;
extern s32 D_001D9F48_f;
extern void func_13B0C8_f();
extern void func_00397CC0_f();
typedef struct { u8 pad[0x10]; s32 a; u16 b; u8 pad2[0x1A]; } S_3934E8_f;
void func_00397D48(s32 x, s32 y) {
    S_3934E8_f s;
    s32 *p;
    s32 *q;
    p = D_001D5EE8_f;
    q = &s.a;
    D_001D9F4C_f = (s32)q;
    s.a = D_001D5F00_f[0];
    s.b = ((u16 *)D_001D5F00_f)[2];
    D_001D9F48_f = (s32)&s;
    func_13B0C8_f((u8 *)q + 5);
    func_00397CC0_f(p, 2, &D_001D9F48_f);
}
/* localdecomp:end func_00397D48 */

INCLUDE_ASM("asm/nonmatchings/text", func_00397DB0);

/* localdecomp:start func_00397DD0 */
extern void func_00123C90(void);
extern void func_00123C20(void);

void func_00397DD0(void) {
    func_00123C90();
    func_00123C20();
}
/* localdecomp:end func_00397DD0 */

/* localdecomp:start func_00397DF8 */
extern s32 func_11F1E0();
extern s32 func_11F1C0();
extern s32 func_001240E0();
extern void func_00397DD0_00397DF8(void);
s32 func_00397DF8(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 s[4];
    s32 h;
    s32 r;
    r = -1;
    s[0] = a;
    s[1] = c;
    s[2] = b;
    s[3] = 0;
    h = func_11F1E0(s, 1);
    if (h != 0) {
        do {} while (func_11F1C0(h) >= 0);
        r = func_001240E0(c, d, e);
    }
    func_00397DD0_00397DF8();
    return r;
}
/* localdecomp:end func_00397DF8 */

/* func_00397EA8: from the US C of func_00393580 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_00397EA8 */
extern u8 D_00227580_00397EA8[];
extern u8 D_3F33BF[];
extern u8 D_01FF8000[];
extern u8 D_01FFC000[];
/* Retail reaches D_001DA058 with lui/lw in one register (the low half folded into the load
   offset), not through $gp: the assembler's expansion of a load from a global it does not know
   to be small (SN's single-pass Ps2EeAs had not seen its size yet). It is declared sized (gcc
   leaves the load to the assembler as one macro) with an `.extern X, 16` hint before its first use (docs/wiki/Matching-Patterns.md). */
extern u32 D_001DA058;
__asm__(".extern D_001DA058, 16");
extern s32 func_0011A264(s32, s32, s32);
void func_00397EA8(void) {
    u32 *s = (u32 *)D_00227580_00397EA8;
    u32 c;
    func_0011A264((s32)s, 0, 0xA0);
    c = (u32)D_01FFC000;
    s[0] = 0;
    s[1] = 0x100000;
    s[2] = (u32)D_3F33BF & 0xFFFFF000;
    s[3] = s[2];
    s[4] = s[3] + D_001DA058;
    s[5] = s[4] + D_001DA058;
    s[6] = s[5] + 0x100000;
    s[0x22] = (u32)D_01FF8000;
    s[0x21] = s[0x22] - 0x40000;
    s[0x20] = s[0x21] - 0x64000;
    s[0x1F] = s[0x20];
    s[0x1E] = s[0x1F] - 0x2C000;
    s[0x1D] = s[0x1E] - 0x8000;
    s[0x1C] = s[0x1D] - 0x14000;
    s[0x1A] = s[6];
    s[0x23] = c;
    s[0x1B] = s[0x1C];
    s[0x24] = 0x7000000;
    s[0x25] = 0x7100000;
    s[0x26] = 0x7180000;
    s[0x27] = 0x7200000;
}
/* localdecomp:end func_00397EA8 */

/* localdecomp:start func_00397FC8 */
extern void func_12BD50(s32);

void func_00397FC8(void) {
	func_12BD50(2);
}
/* localdecomp:end func_00397FC8 */

INCLUDE_ASM("asm/nonmatchings/text", func_00397FE8);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C0F0);

/* localdecomp:start func_00398470 */
extern void func_0038E0E8();
s32 func_00398470(s32 p) {
    func_0038E0E8(p);
    return p;
}
/* localdecomp:end func_00398470 */

extern u8 D_002FD0F0[];
extern s32 D_002FCE98[];
typedef struct { s32 a, b; } P_3936A8;
extern P_3936A8 D_002FC840[];
extern s32 D_001DA5D4;
extern void func_0038CC88();
/* localdecomp:start func_00398498 */
#include "vu0.h"
/* from boot_elf's func_00398878 (src/boot_elf/text/398190.c), its twin */
void func_00398498(s32 *hdr, s32 base, s32 *src, s32 n) {
    s32 *list = hdr + 4;
    s32 cnt = hdr[0];
    s32 off = hdr[2];
    s32 size = hdr[3];
    s32 i;
    for (i = 0; i < cnt; i++, list++) {
        s32 v = *list;
        if (v == 0) D_002FCE98[i] = (s32)D_002FD0F0;
        else D_002FCE98[i] = v - (off - (s32)D_002FD0F0);
    }
    func_0038CC88(D_002FD0F0, (u8 *)hdr + off, size);
    for (D_001DA5D4 = 0; D_001DA5D4 < n; D_001DA5D4++) {
        s32 a = *src++;
        s32 b = *src++;
        s32 c = *src++;
        s32 d = *src++;
        s32 e;
        e = plzcw_asm(d);
        e = 30 - e;
        D_002FC840[D_001DA5D4].a = ((base + a) << 4) + b;
        D_002FC840[D_001DA5D4].b = ((base + c) << 4) + e;
    }
}
/* localdecomp:end func_00398498 */

ASM_FUNC("asm/handwritten", func_003985B8);

typedef struct { unsigned long z; s16 h8; s16 hA; s16 hC; s16 hE; } E_393878;
typedef struct { s16 h0; s16 h2; s16 h4; u8 p6[0x1A]; s32 f20; } F_393878;
typedef struct { u8 p0[4]; s16 h4; s16 h6; u8 p8[4]; s16 hC; u8 pE[2]; s32 f10; s32 f14; s32 f18; s32 f1C; s32 f20[1]; } H_393878;
extern H_393878 *D_001DA5F0;
/* localdecomp:start func_00398668 */
/* from the boot_elf twin func_00398A48 (src/boot_elf/text/398A48.c); types from 397D48.c */
void func_00398668(H_393878 *p) {
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
            c = 30 - plzcw_asm(*src++);
            d = 30 - plzcw_asm(*src++);
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
/* localdecomp:end func_00398668 */

typedef struct { s32 a, b, c, d; } E_00393A18;
typedef struct { u8 p0[0x1EB4]; s32 x1EB4; E_00393A18 e[1]; } S_160C40_00393A18;
typedef struct { u8 p0[0x10]; s32 x10; u8 p14[0x10]; s32 x24; } S_1A1ED0_00393A18;
typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; } T_00393A18;
extern S_160C40_00393A18 D_160C40_00398808;
extern S_1A1ED0_00393A18 D_1A1ED0_00398808;
extern unsigned long D_1D4B70[1];
extern s32 func_003A2750(s32);
extern s32 func_003A26F0(s32, s32, s32);
extern s32 func_00381CB0(void);
extern void func_12C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
/* localdecomp:start func_00398808 */
#include "vu0.h"
/* from boot_elf's func_00398BE8 (src/boot_elf/text/398A48.c), its twin */
typedef struct { s32 x0; u8 *buf; s32 count; s32 xC; unsigned long regs[1]; } G_00398808;
extern G_00398808 D_001D4B60_00398808 __attribute__((section(".sdata")));
extern void func_003A92F0(s32);
void func_00398808(s32 n0) {
    s32 n;
    u8 buf[0x60];
    u8 *p;
    s32 *list;
    S_160C40_00393A18 *b;
    S_1A1ED0_00393A18 *r;
    s32 i, a, c;
    func_003A92F0(1);
    n = n0;
    p = D_001D4B60_00398808.buf;
    func_003A2750(1);
    if (func_00381CB0() > 0) n = func_00381CB0();
    b = &D_160C40_00398808;
    func_003A26F0((s32)p, b->e[n].c + b->x1EB4, b->e[n].d);
    list = (s32 *)(p + 4);
    r = &D_1A1ED0_00398808;
    c = r->x24;
    a = r->x10;
    D_001D4B60_00398808.count = *(s32 *)p;
    for (i = 0; i < D_001D4B60_00398808.count; i++) {
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
            lz = plzcw_asm(w);
            k = 30 - lz;
            h = w >> 6;
            if (h <= 0) h = 1;
            func_12C9A0(buf, cbp, h, 0x1B, 0, 0, ((T_00393A18 *)q)->h8, ((T_00393A18 *)q)->hC);
            func_11F0A0(0);
            func_12CCC8(buf, q + 0x420);
            func_12A9F0(0, 0);
            D_001D4B60_00398808.regs[i] = (unsigned long)cbp | ((unsigned long)h << 14) | ((unsigned long)0x1B << 20)
                | ((unsigned long)k << 26) | ((unsigned long)k << 30) | ((unsigned long)1 << 34)
                | ((unsigned long)tbp << 37) | ((unsigned long)4 << 61);
            c += *(s32 *)(q + 8) * *(s32 *)(q + 0xC) * 4;
        }
    }
    func_003A26F0((s32)p, D_160C40_00398808.e[n].a + D_160C40_00398808.x1EB4, D_160C40_00398808.e[n].b);
}
/* localdecomp:end func_00398808 */

extern unsigned long D_0022CAD0[3];
extern s32 D_002DDC30[];
extern s32 D_002DA740[];
extern s32 D_001D4B64;
extern s32 D_001D4B68;
extern unsigned long D_001D4B70[1];
extern s32 D_001D5F40;
extern s32 D_002DE3B0[];
typedef struct { u8 p0[8]; u8 f8; u8 f9; u8 pa[5]; u8 fF; u8 p10[4]; s32 f14; } S_393C98;
typedef struct { s32 a; s32 b; } E_393C98;
extern E_393C98 D_00337480[];
extern void func_0038CB78();
extern s32 func_00381CB0();
extern void func_0038CD28();
/* localdecomp:start func_00398A88 */
extern unsigned long D_0022CAD0_f[3];
extern s32 D_002DDC30_f[];
extern s32 D_002DA740_f[];
extern s32 D_001D4B64_f;
extern s32 D_001D4B68_f;
extern unsigned long D_001D4B70_f[1];
__asm__(".extern D_001D5F40_f, 4");
extern s32 D_001D5F40_f;
extern s32 D_002DE3B0_f[];
typedef struct { u8 p0[8]; u8 f8; u8 f9; u8 pa[5]; u8 fF; u8 p10[4]; s32 f14; } S_393C98_f;
typedef struct { s32 a; s32 b; } E_393C98_f;
extern E_393C98_f D_00337480_f[];
extern void func_00399928_f();
extern void func_0038CB78_f();
extern s32 func_00381CB0_ff();
extern void func_0038CD28_f();
void func_00398A88(s32 a) {
    s32 i, n;
    S_393C98_f *p;
    n = D_001D4B68_f;
    for (i = 0; i < n; i++) {
        D_0022CAD0_f[i * 3] = D_001D4B70_f[i];
        D_0022CAD0_f[i * 3 + 1] = 0xFFA0000000E0;
        D_0022CAD0_f[i * 3 + 2] = 0x40000400004000;
    }
    func_00399928_f(D_001D4B64_f, 0, &D_001D5F40_f);
    D_002DDC30_f[0] = 0xFFFC0000;
    func_0038CB78_f(D_002DE3B0_f, -1, 0x10);
    {
        S_393C98_f *p1 = ((S_393C98_f **)D_002DA740_f)[0];
        p1->f9 = p1->f8;
    }
    if (func_00381CB0_ff() > 0) a = func_00381CB0_ff();
    p = ((S_393C98_f **)D_002DA740_f)[0];
    func_0038CD28_f(p->f14 - (p->fF << 4), D_00337480_f[a].a, D_00337480_f[a].b);
}
/* localdecomp:end func_00398A88 */

LINKER_REMNANT("asm/remnants", func_00398BA0);

typedef struct { u8 p0[0x18]; s32 f18; u8 p1c[0x1C]; unsigned long f38; } S_16C580_00393DC8;
typedef struct { u8 p0[0x1284]; s32 f1284; u8 p1[0xAD8]; struct { s32 a; s32 b; } e[1]; } S_160C40_00393DC8;
extern S_16C580_00393DC8 D_16C580;
extern S_160C40_00393DC8 D_160C40;
extern s32 D_002275F0[];
extern unsigned long D_0022CAD0[3];
extern s32 D_001D5F30;
extern void func_003A92F0(s32);
extern s32 func_003A26F0(s32, s32, s32);
/* localdecomp:start func_00398BB8 */
typedef struct {
    u8 p0[0x18];
    s32 f18;
    u8 p1c[0x1C];
    unsigned long f38;
} SelectState;
typedef struct {
    u8 p0[0x1284];
    s32 base;
    u8 p3e28[0x1D60 - 0x1288];
    struct {
        s32 a;
        s32 b;
    } e[1];
} SelectTable;
extern SelectState D_0016C580_00398BB8;
extern SelectTable D_00160C40_00398BB8;
extern s32 D_002275F0[];
extern unsigned long D_0022CAD0[3];
__asm__(".extern D_001D5F30, 4");
extern s32 D_001D5F30;
extern void func_003A92F0(s32);
extern s32 func_003A26F0(s32, s32, s32);
extern void func_00399A48(s32, s32, void *, s32);

void func_00398BB8(s32 n) {
    SelectTable *b;
    s32 h;
    D_0016C580_00398BB8.f18 = n;
    func_003A92F0(1);
    b = &D_00160C40_00398BB8;
    h = D_002275F0[0];
    func_003A26F0(h, b->e[n].a + b->base, b->e[n].b);
    D_0022CAD0[0] = D_0016C580_00398BB8.f38;
    D_0022CAD0[1] = 0xFFA0000000E0;
    D_0022CAD0[2] = 0x40000400004000;
    func_00399A48(h, 0, &D_001D5F30, -1);
}
/* localdecomp:end func_00398BB8 */

typedef struct { u8 p0[0x30]; s32 x30; u8 p34[4]; unsigned long x38; } S_16C580_00393E90;
typedef struct { u8 p0[0x1284]; s32 f1284; u8 p1[0xAF0]; struct { s32 a; s32 b; } e[1]; } S_160C40_00393E90;
typedef struct { u8 p0[0x18]; s32 x18; u8 p1c[0x10]; s32 x2C; } S_1A1ED0_00393E90;
typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; } T_00393E90;
extern S_16C580_00393E90 D_16C580_00398C80;
extern S_160C40_00393E90 D_160C40_00398C80;
extern S_1A1ED0_00393E90 D_1A1ED0_00398C80;
extern s32 D_001DA05C;
extern s32 D_001DA048[];
extern s32 func_003A2750(s32);
extern s32 func_003A26F0(s32, s32, s32);
extern void func_12C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
/* localdecomp:start func_00398C80 */
#include "vu0.h"
/* log func_00398C80: from boot_elf twin func_00399060 (398A48.c), callees renamed via frontend_pairs (3A96A8->3A92F0, 3A2B50->3A2750, 3A2AF0->3A26F0), aliases _00398C80. */
/* MATCH */
__asm__(".extern D_001DA05C, 16");
extern s32 D_001DA05C;
void func_00398C80(s32 n) {
    u8 buf[0x60];
    S_16C580_00393E90 *g = &D_16C580_00398C80;
    S_160C40_00393E90 *b;
    S_1A1ED0_00393E90 *r;
    u8 *t;
    u8 *q;
    s32 w, h, k, lz;
    g->x30 = n;
    func_003A92F0(1);
    t = (u8 *)D_001DA048[1 - D_001DA05C];
    func_003A2750(1);
    b = &D_160C40_00398C80;
    q = t + 0x20;
    func_003A26F0((s32)t, b->e[n].a + b->f1284, b->e[n].b);
    r = &D_1A1ED0_00398C80;
    func_12C9A0(buf, r->x18 >> 8, 1, 0, 0, 0, 0x10, 0x10);
    func_11F0A0(0);
    func_12CCC8(buf, q);
    func_12A9F0(0, 0);
    w = *(s32 *)(t + 8);
    lz = plzcw_asm(w);
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
/* localdecomp:end func_00398C80 */

typedef struct { s32 off; s32 size; } E_94060;
typedef struct { u8 p0[0x18]; s32 f18; s32 f1C; E_94060 e[5]; } B_94060;
typedef struct { u8 p0[4]; s32 f4; s32 f8; s32 fC; s32 f10; u8 p14[0x40]; s32 f54; s32 f58; s32 f5C; s32 f60; s32 f64; u8 p68[0x2C]; s32 f94; u8 p98[4]; s32 f9C; s32 fA0; s32 fA4; } G_94060;
typedef struct { u8 p0[0x10]; s32 f10; } Q_94060;
extern B_94060 *D_001D4B50_00398E50;
extern int D_001D9EA0_00398E50;
extern s32 D_001D9EC8[5];
extern u8 D_001D5F50[];
extern u8 D_001D5F60[];
extern u8 D_001D5F70[];
extern u8 D_001D5F80[];
extern u8 D_001D5F90[];
extern s32 D_001D9EA4;
extern s32 D_001D9EA8;
extern s32 D_001D9EAC;
extern s32 D_001D9EB0;
extern Q_94060 D_00227580[];
extern s32 func_003932C0();
extern void func_0038CD28();
extern void func_003990F0();
extern s32 func_003A8678();
extern void func_00393168();
extern void func_11F0A0();
extern void func_00392FD0();
extern void func_00393138();
