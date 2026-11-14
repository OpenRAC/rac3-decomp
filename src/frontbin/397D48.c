#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00397D48(s32, s32);
extern void func_00397EA8(void);
extern void func_00398E50(void);
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
INCLUDE_ASM("asm/nonmatchings/text", func_00398498);

ASM_FUNC("asm/handwritten", func_003985B8);

typedef struct { unsigned long z; s16 h8; s16 hA; s16 hC; s16 hE; } E_393878;
typedef struct { s16 h0; s16 h2; s16 h4; u8 p6[0x1A]; s32 f20; } F_393878;
typedef struct { u8 p0[4]; s16 h4; s16 h6; u8 p8[4]; s16 hC; u8 pE[2]; s32 f10; s32 f14; s32 f18; s32 f1C; s32 f20[1]; } H_393878;
extern H_393878 *D_001DA5F0;
INCLUDE_ASM("asm/nonmatchings/text", func_00398668);

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
INCLUDE_ASM("asm/nonmatchings/text", func_00398808);

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
INCLUDE_ASM("asm/nonmatchings/text", func_00398BB8);

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
INCLUDE_ASM("asm/nonmatchings/text", func_00398C80);

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
INCLUDE_ASM("asm/nonmatchings/text", func_00398E50);

typedef struct { s32 off; s32 x4; } E_394300;
typedef struct { u8 pad[0x18]; E_394300 e[1]; } H_394300;
typedef struct { u8 pad[0x74]; s32 arr[1]; } G_394300;
extern H_394300 *D_001D4B50;
extern G_394300 *D_001D9EA0;
void func_003A0760(u8 *, u32);
/* localdecomp:start func_003990F0 */
/* declarations of 398040.c's earlier functions (tools/port_from_us.py) */
extern s32 D_001D5F00_fff[];
extern s32 D_001D5EE8_fff[];
extern s32 D_001D9F4C_fff;
extern s32 D_001D9F48_fff;
extern void func_13B0C8_fff();
extern void func_003980A0_f();
typedef struct { u8 pad[0x10]; s32 a; u16 b; u8 pad2[0x1A]; } S_3934E8_fff;
extern void func_00123C90_ff(void);
extern void func_00123C20_ff(void);
extern s32 func_11F1E0_ff();
extern s32 func_11F1C0_ff();
extern s32 func_001240E0_ff();
extern void func_003981B0_f(void);
extern u8 D_00227580_00398288_f[];
extern u8 D_3F3777_f[];
extern u8 D_01FF8000_ff[];
extern u8 D_01FFC000_ff[];
extern u32 D_001DA058_ff;
extern s32 func_0011A264_ff(s32, s32, s32);
extern void func_0038E4C8_f();
extern u8 D_002FD0F0_ff[];
extern s32 D_002FCE98_ff[];
typedef struct { s32 a, b; } P_3936A8_ff;
extern P_3936A8_ff D_002FC840_ff[];
extern s32 D_001DA5D4_ff;
extern void func_0038D068_f();
typedef struct { unsigned long z; s16 h8; s16 hA; s16 hC; s16 hE; } E_393878_ff;
typedef struct { s16 h0; s16 h2; s16 h4; u8 p6[0x1A]; s32 f20; } F_393878_ff;
typedef struct { u8 p0[4]; s16 h4; s16 h6; u8 p8[4]; s16 hC; u8 pE[2]; s32 f10; s32 f14; s32 f18; s32 f1C; s32 f20[1]; } H_393878_ff;
extern H_393878_ff *D_001DA5F0_ff;
typedef struct { s32 a, b, c, d; } E_00393A18_ff;
typedef struct { u8 p0[0x1EB4]; s32 x1EB4; E_00393A18_ff e[1]; } S_160C40_00393A18_ff;
typedef struct { u8 p0[0x10]; s32 x10; u8 p14[0x10]; s32 x24; } S_1A1ED0_00393A18_ff;
typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; } T_00393A18_ff;
extern S_160C40_00393A18_ff D_160C40_00398BE8_f;
extern S_1A1ED0_00393A18_ff D_1A1ED0_00398BE8_f;
extern unsigned long D_1D4B70_ff[1];
extern s32 func_003A2B50(s32);
extern s32 func_003A2AF0(s32, s32, s32);
extern s32 func_00381BC0(void);
extern void func_12C9A0_fff(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_11F0A0_fff(s32);
extern void func_12CCC8_fff(void *, void *);
extern s32 func_12A9F0_fff(s32, s32);
extern unsigned long D_0022CAD0_ff[3];
extern s32 D_002DDC30_ff[];
extern s32 D_002DA740_ff[];
extern s32 D_001D4B64_ff;
extern s32 D_001D4B68_ff;
extern unsigned long D_001D4B70_ff[1];
extern s32 D_001D5F40_ff;
extern s32 D_002DE3B0_ff[];
typedef struct { u8 p0[8]; u8 f8; u8 f9; u8 pa[5]; u8 fF; u8 p10[4]; s32 f14; } S_393C98_ff;
typedef struct { s32 a; s32 b; } E_393C98_ff;
extern E_393C98_ff D_00337480_ff[];
extern void func_00399D08();
extern void func_0038CF58();
extern s32 func_00381BC0();
extern void func_0038D108();
typedef struct { u8 p0[0x18]; s32 f18; u8 p1c[0x1C]; unsigned long f38; } S_16C580_00393DC8_f;
typedef struct { u8 p0[0x1284]; s32 f1284; u8 p1[0xAD8]; struct { s32 a; s32 b; } e[1]; } S_160C40_00393DC8_f;
extern S_16C580_00393DC8_f D_16C580_f;
extern S_160C40_00393DC8_f D_160C40_f;
extern s32 D_002275F0_f[];
extern unsigned long D_0022CAD0_ff[3];
extern s32 D_001D5F30_f;
extern void func_003A96A8(s32);
extern s32 func_003A2AF0(s32, s32, s32);
extern void func_00399E28(s32, s32, void *, s32);
typedef struct { u8 p0[0x30]; s32 x30; u8 p34[4]; unsigned long x38; } S_16C580_00393E90_ff;
typedef struct { u8 p0[0x1284]; s32 f1284; u8 p1[0xAF0]; struct { s32 a; s32 b; } e[1]; } S_160C40_00393E90_ff;
typedef struct { u8 p0[0x18]; s32 x18; u8 p1c[0x10]; s32 x2C; } S_1A1ED0_00393E90_ff;
typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; } T_00393E90_ff;
extern S_16C580_00393E90_ff D_16C580_00399060_f;
extern S_160C40_00393E90_ff D_160C40_00399060_f;
extern S_1A1ED0_00393E90_ff D_1A1ED0_00399060_f;
extern s32 D_001DA05C_ff;
extern s32 D_001DA048_ff[];
extern s32 func_003A2B50(s32);
extern s32 func_003A2AF0(s32, s32, s32);
extern void func_12C9A0_fff(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_11F0A0_fff(s32);
extern void func_12CCC8_fff(void *, void *);
extern s32 func_12A9F0_fff(s32, s32);
typedef struct { s32 off; s32 size; } E_94060_f;
typedef struct { u8 p0[0x18]; s32 f18; s32 f1C; E_94060_f e[5]; } B_94060_f;
typedef struct { u8 p0[4]; s32 f4; s32 f8; s32 fC; s32 f10; u8 p14[0x40]; s32 f54; s32 f58; s32 f5C; s32 f60; s32 f64; u8 p68[0x2C]; s32 f94; u8 p98[4]; s32 f9C; s32 fA0; s32 fA4; } G_94060_f;
typedef struct { u8 p0[0x10]; s32 f10; } Q_94060_f;
extern B_94060_f *D_001D4B50_00399230;
extern int D_001D9EA0_00399230;
extern s32 D_001D9EC8_f[5];
extern u8 D_001D5F50_f[];
extern u8 D_001D5F60_f[];
extern u8 D_001D5F70_f[];
extern u8 D_001D5F80_f[];
extern u8 D_001D5F90_f[];
extern s32 D_001D9EA4_f;
extern s32 D_001D9EA8_f;
extern s32 D_001D9EAC_f;
extern s32 D_001D9EB0_f;
extern Q_94060_f D_00227580_f[];
extern s32 func_003936A0();
extern void func_0038D108();
extern s32 func_003A8A30();
extern void func_00393548();
extern void func_11F0A0_fff();
extern void func_003933B0();
extern void func_00393518();

typedef struct { s32 off; s32 x4; } E_394300_f;
typedef struct { u8 pad[0x18]; E_394300_f e[1]; } H_394300_f;
typedef struct { u8 pad[0x74]; s32 arr[1]; } G_394300_f;
extern H_394300_f *D_001D4B50_f;
extern G_394300_f *D_001D9EA0_f;
void func_003A0760(u8 *, u32);
void func_003990F0(s32 a, u32 b) {
    H_394300_f *h;
    b = (b + 15) & 0xFFFFFFF0;
    if (b) {
        h = D_001D4B50_f;
        func_003A0760((u8 *)(h->e[a + 1].off + (s32)h), b);
    }
    D_001D9EA0_f->arr[a] = 0;
}
/* localdecomp:end func_003990F0 */

INCLUDE_ASM("asm/nonmatchings/text", func_00399158);

extern unsigned long D_001D9F60[];
extern unsigned long D_001D9F78[];
/* localdecomp:start func_00399450 */
/* declarations of 398040.c's earlier functions (tools/port_from_us.py) */
extern s32 D_001D5F00_ffff[];
extern s32 D_001D5EE8_ffff[];
extern s32 D_001D9F4C_ffff;
extern s32 D_001D9F48_ffff;
extern void func_13B0C8_ffff();
extern void func_003980A0_ff();
typedef struct { u8 pad[0x10]; s32 a; u16 b; u8 pad2[0x1A]; } S_3934E8_ffff;
extern void func_00123C90_fff(void);
extern void func_00123C20_fff(void);
extern s32 func_11F1E0_fff();
extern s32 func_11F1C0_fff();
extern s32 func_001240E0_fff();
extern void func_003981B0_ff(void);
extern u8 D_00227580_00398288_ff[];
extern u8 D_3F3777_ff[];
extern u8 D_01FF8000_fff[];
extern u8 D_01FFC000_fff[];
extern u32 D_001DA058_fff;
extern s32 func_0011A264_fff(s32, s32, s32);
extern void func_0038E4C8_ff();
extern u8 D_002FD0F0_fff[];
extern s32 D_002FCE98_fff[];
typedef struct { s32 a, b; } P_3936A8_fff;
extern P_3936A8_fff D_002FC840_fff[];
extern s32 D_001DA5D4_fff;
extern void func_0038D068_ff();
typedef struct { unsigned long z; s16 h8; s16 hA; s16 hC; s16 hE; } E_393878_fff;
typedef struct { s16 h0; s16 h2; s16 h4; u8 p6[0x1A]; s32 f20; } F_393878_fff;
typedef struct { u8 p0[4]; s16 h4; s16 h6; u8 p8[4]; s16 hC; u8 pE[2]; s32 f10; s32 f14; s32 f18; s32 f1C; s32 f20[1]; } H_393878_fff;
extern H_393878_fff *D_001DA5F0_fff;
typedef struct { s32 a, b, c, d; } E_00393A18_fff;
typedef struct { u8 p0[0x1EB4]; s32 x1EB4; E_00393A18_fff e[1]; } S_160C40_00393A18_fff;
typedef struct { u8 p0[0x10]; s32 x10; u8 p14[0x10]; s32 x24; } S_1A1ED0_00393A18_fff;
typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; } T_00393A18_fff;
extern S_160C40_00393A18_fff D_160C40_00398BE8_ff;
extern S_1A1ED0_00393A18_fff D_1A1ED0_00398BE8_ff;
extern unsigned long D_1D4B70_fff[1];
extern s32 func_003A2B50_f(s32);
extern s32 func_003A2AF0_f(s32, s32, s32);
extern s32 func_00381BC0_f(void);
extern void func_12C9A0_ffff(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_11F0A0_ffff(s32);
extern void func_12CCC8_ffff(void *, void *);
extern s32 func_12A9F0_ffff(s32, s32);
extern unsigned long D_0022CAD0_fff[3];
extern s32 D_002DDC30_fff[];
extern s32 D_002DA740_fff[];
extern s32 D_001D4B64_fff;
extern s32 D_001D4B68_fff;
extern unsigned long D_001D4B70_fff[1];
extern s32 D_001D5F40_fff;
extern s32 D_002DE3B0_fff[];
typedef struct { u8 p0[8]; u8 f8; u8 f9; u8 pa[5]; u8 fF; u8 p10[4]; s32 f14; } S_393C98_fff;
typedef struct { s32 a; s32 b; } E_393C98_fff;
extern E_393C98_fff D_00337480_fff[];
extern void func_00399D08_f();
extern void func_0038CF58_f();
extern s32 func_00381BC0_f();
extern void func_0038D108_f();
typedef struct { u8 p0[0x18]; s32 f18; u8 p1c[0x1C]; unsigned long f38; } S_16C580_00393DC8_ff;
typedef struct { u8 p0[0x1284]; s32 f1284; u8 p1[0xAD8]; struct { s32 a; s32 b; } e[1]; } S_160C40_00393DC8_ff;
extern S_16C580_00393DC8_ff D_16C580_ff;
extern S_160C40_00393DC8_ff D_160C40_ff;
extern s32 D_002275F0_ff[];
extern unsigned long D_0022CAD0_fff[3];
extern s32 D_001D5F30_ff;
extern void func_003A96A8_f(s32);
extern s32 func_003A2AF0_f(s32, s32, s32);
extern void func_00399E28_f(s32, s32, void *, s32);
typedef struct { u8 p0[0x30]; s32 x30; u8 p34[4]; unsigned long x38; } S_16C580_00393E90_fff;
typedef struct { u8 p0[0x1284]; s32 f1284; u8 p1[0xAF0]; struct { s32 a; s32 b; } e[1]; } S_160C40_00393E90_fff;
typedef struct { u8 p0[0x18]; s32 x18; u8 p1c[0x10]; s32 x2C; } S_1A1ED0_00393E90_fff;
typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; } T_00393E90_fff;
extern S_16C580_00393E90_fff D_16C580_00399060_ff;
extern S_160C40_00393E90_fff D_160C40_00399060_ff;
extern S_1A1ED0_00393E90_fff D_1A1ED0_00399060_ff;
extern s32 D_001DA05C_fff;
extern s32 D_001DA048_fff[];
extern s32 func_003A2B50_f(s32);
extern s32 func_003A2AF0_f(s32, s32, s32);
extern void func_12C9A0_ffff(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_11F0A0_ffff(s32);
extern void func_12CCC8_ffff(void *, void *);
extern s32 func_12A9F0_ffff(s32, s32);
typedef struct { s32 off; s32 size; } E_94060_ff;
typedef struct { u8 p0[0x18]; s32 f18; s32 f1C; E_94060_ff e[5]; } B_94060_ff;
typedef struct { u8 p0[4]; s32 f4; s32 f8; s32 fC; s32 f10; u8 p14[0x40]; s32 f54; s32 f58; s32 f5C; s32 f60; s32 f64; u8 p68[0x2C]; s32 f94; u8 p98[4]; s32 f9C; s32 fA0; s32 fA4; } G_94060_ff;
typedef struct { u8 p0[0x10]; s32 f10; } Q_94060_ff;
extern B_94060_ff *D_001D4B50_00399230_f;
extern int D_001D9EA0_00399230_f;
extern s32 D_001D9EC8_ff[5];
extern u8 D_001D5F50_ff[];
extern u8 D_001D5F60_ff[];
extern u8 D_001D5F70_ff[];
extern u8 D_001D5F80_ff[];
extern u8 D_001D5F90_ff[];
extern s32 D_001D9EA4_ff;
extern s32 D_001D9EA8_ff;
extern s32 D_001D9EAC_ff;
extern s32 D_001D9EB0_ff;
extern Q_94060_ff D_00227580_ff[];
extern s32 func_003936A0_f();
extern void func_0038D108_f();
extern void func_003994D0();
extern s32 func_003A8A30_f();
extern void func_00393548_f();
extern void func_11F0A0_ffff();
extern void func_003933B0_f();
extern void func_00393518_f();
typedef struct { s32 off; s32 x4; } E_394300_ff;
typedef struct { u8 pad[0x18]; E_394300_ff e[1]; } H_394300_ff;
typedef struct { u8 pad[0x74]; s32 arr[1]; } G_394300_ff;
extern H_394300_ff *D_001D4B50_ff;
extern G_394300_ff *D_001D9EA0_ff;
void func_003A0B60(u8 *, u32);

extern unsigned long D_001D9F60_f[];
extern unsigned long D_001D9F78_f[];
void func_00399450(unsigned long *p, s32 a, s32 b, s32 c, s32 d, s32 idx) {
    unsigned long t0 = D_0022CAD0_fff[idx * 3];
    unsigned long t1 = D_0022CAD0_fff[idx * 3 + 1];
    unsigned long t2 = D_0022CAD0_fff[idx * 3 + 2];
    if (idx >= 0) {
        p[0] = (((t1 & 0x1C) | 0x20) | ((unsigned long)b << 6)) | ((unsigned long)a << 32);
        p += 2;
        p[0] = c | ((unsigned long)d << 2) | ((unsigned long)idx << 24);
        p += 2;
        p[0] = t0;
        p[2] = t2;
        return;
    }
    if (idx < -1) {
        unsigned long *q = D_001D9F60_f;
        if (idx == -3) q = D_001D9F78_f;
        p[0] = (((unsigned long)b << 6) | 0x20) | ((unsigned long)a << 32);
        p += 2;
        p[0] = 5;
        p += 2;
        p[0] = q[0];
        p[2] = q[2];
    } else {
        p[0] = (((unsigned long)b << 6) | 0x20) | ((unsigned long)a << 32);
        p += 2;
        p[0] = 5;
        p += 2;
        p[0] = 0x80000004CC007FFBUL;
        p[2] = 0;
    }
}
/* localdecomp:end func_00399450 */

typedef struct { u8 p0[0x20]; s32 x20; u8 p24[0x10]; s32 x34; } S_1A1ED0_003947B0;
extern S_1A1ED0_003947B0 D_1A1ED0_003995A0;
extern s32 D_001D4BB0;
extern s32 D_001D4BB4;
extern void func_12C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
typedef s32 (*F12C9A0_3947B0)(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003995A0);

/* localdecomp:start func_00399810 */
extern void func_00399158();
extern void func_00399450();
void func_00399810(s32 *a0, u8 *b, u8 *c, s32 n) {
    s32 i, j, cnt, lo, idx;
    s32 *e, *nx;
    s32 *p = a0;
    for (i = 0; i < n; i++) {
        nx = p + 4;
        cnt = p[1] >> 16;
        lo = p[1] & 0xFFFF;
        p[1] = lo;
        e = (s32 *)((u8 *)p[0] + ((lo - cnt) << 4));
        for (j = 0; j < cnt; j += 4) {
            idx = e[8];
            if (idx >= 0) idx = c[idx];
            if (b) {
                func_00399158(e, b + (idx << 4), e[0], e[1], e[4], e[5], idx);
            } else {
                func_00399450((unsigned long *)e, e[0], e[1], e[4], e[5], idx);
            }
            e += 16;
        }
        p = nx;
    }
}
/* localdecomp:end func_00399810 */

/* localdecomp:start func_00399928 */
typedef struct { s32 pad[2]; s32 f8; s32 pad2[8]; } S_227600_00394B38;
extern S_227600_00394B38 D_00227580_00399928;
extern void func_00399810();
void func_00399928(u8 *a, s32 b, u8 *tab) {
    s32 n, i;
    s32 *p, *q, *r, *r0;
    u8 *s;
    n = a[0] + a[1] + a[2];
    p = (s32 *)(a + *(s32 *)(a + 4));
    r0 = (s32 *)(a + *(s32 *)(a + 8));
    q = p;
    for (i = 0; i < n; i++) {
        if (q[0] < D_00227580_00399928.f8) {
            q[0] = q[0] + (s32)a;
            q[2] = q[2] + (s32)a;
        }
        q += 4;
    }
    r = r0;
    for (;;) {
        r[3] = r[3] + (s32)a;
        s = (u8 *)r;
        if (*s != 0xFF) {
            do {
                *s = tab[*s];
                s++;
            } while (*s != 0xFF);
        }
        if (r[3] < 0) break;
        r += 4;
    }
    func_00399810(p, b, tab, n);
}
/* localdecomp:end func_00399928 */

/* localdecomp:start func_00399A08 */
void func_00399A08(u8 *d, u8 *s) {
    d[4] = s[0];
    d[5] = s[1];
    d[6] = s[2];
    d[7] = s[3];
    *(u8 **)d = s + *(s32 *)(s + 4);
    *(u8 **)(d + 0x20) = s + *(s32 *)(s + 8);
}
/* localdecomp:end func_00399A08 */

/* localdecomp:start func_00399A48 */
typedef int u128_394C58 __attribute__((mode(TI)));
typedef struct 
{
  u8 p0[0xA];
  s16 hA;
  u8 pC[4];
} T_394C58;
typedef struct 
{
  u8 p0[0x20];
  s32 x20;
} R_394C58;
typedef struct 
{
  u8 p0[0x10];
  u8 b10;
  u8 p11[3];
  s32 x14;
  u8 p18[4];
  s32 x1C[1];
} O_394C58;
typedef struct 
{
  u8 b0;
  u8 p1[0xB];
  s32 xC;
} E_394C58;
typedef struct 
{
  s32 x0;
  u8 b4;
  u8 b5;
  u8 b6;
  u8 b7;
  u8 b8;
  u8 b9;
  u8 bA;
  u8 bB;
  u8 bC;
  u8 pD[3];
  s32 x10;
  s32 x14;
  s32 x18;
  s32 x1C;
  s32 x20;
  s32 x24;
  s32 x28;
  u8 b2C;
  u8 p2D[0x1A];
  u8 b47;
  s32 x48[1];
} H_394C58;
extern R_394C58 D_1A1ED0_00399A48;
extern u8 D_002DB190[];
extern s32 D_002DE3B0[];
void func_00399A48(s32 a, s32 b, void *cv, s32 d)
{
  H_394C58 *p = (H_394C58 *) a;
  T_394C58 *tbl = (T_394C58 *) b;
  u8 *c = cv;
  u32 n;
  s32 i;
  n = (p->b4 + p->b5) + p->b6;
  if (p->b2C != 0)
  {
    n += (((u8 *) p) + (p->b2C << 4))[1];
  }
  if (p->x0 != 0)
  {
    s32 *q = (s32 *) (p->x0 = ((s32) p) + p->x0);
    if (n != 0)
    {
      u32 k0 = n;
      do
      {
        q[0] = q[0] + ((s32) p);
        q[2] = q[2] + ((s32) p);
        q += 4;
      }
      while (--k0);
    }
  }
  if (p->x10 != 0)
  {
    p->x10 = ((s32) p) + p->x10;
  }
  if (p->x14 != 0)
  {
    p->x14 = ((s32) p) + p->x14;
  }
  if (p->x18 != 0)
  {
    p->x18 = ((s32) p) + p->x18;
  }
  if (p->x1C != 0)
  {
    s32 m;
    p->x1C = ((s32) p) + p->x1C;
    m = *((s32 *) p->x1C);
    for (i = 0; i < m; i++)
    {
      s32 *e = (s32 *) ((i << 2) + p->x1C);
      e[1] = e[1] + ((s32) p);
    }

  }
  if (p->x20 != 0)
  {
    E_394C58 *e = (E_394C58 *) (p->x20 = ((s32) p) + p->x20);
    for (;;)
    {
      u8 *s = &e->b0;
      e->xC = e->xC + ((s32) p);
      if (*s != 0xFF)
      {
        do
        {
          *s = c[*s];
          s++;
        }
        while ((*s) != 0xFF);
      }
      if (e->xC < 0) break;
      e++;
    }
  }
  if (p->bB != 0)
  {
    s32 hi = p->bB >> 4;
    u16 *dst = (u16 *) ((p->x20 - (((p->bB & 0xF) * hi) * 1024)) - 0x10);
    s32 j;
    for (j = 0; j < hi; j++)
    {
      if (tbl != 0)
      {
        s32 t = tbl[c[j]].hA + (D_1A1ED0_00399A48.x20 >> 8);
        dst[j] = t;
      }
      else
      {
        dst[j] = (D_0022CAD0[c[j] * 3] >> 37) & 0x3FFF;
      }
    }
  }
  if (p->x28 != 0)
  {
    p->x28 = ((s32) p) + p->x28;
  }
  for (i = 0; i < p->bC; i++)
  {
    if (p->x48[i] != 0)
    {
      O_394C58 *o = (O_394C58 *) (((s32) p) + p->x48[i]);
      s32 j;
      p->x48[i] = (s32) o;
      if (p->b8 == 0)
      {
        if (o->b10 >= 2)
        {
          o->b10 = 1;
        }
      }
      if (o->x14 != 0)
      {
        o->x14 = ((s32) o) + o->x14;
      }
      for (j = 0; j < o->b10; j++)
      {
        o->x1C[j] = ((s32) p) + o->x1C[j];
      }

    }
  }

  if (d >= 0)
  {
    *(((u128_394C58 *) D_002DE3B0) + (*(D_002DB190 + d))) = *((u128_394C58 *) c);
  }
  if (p->x0 != 0)
  {
    func_00399810((s32 *)p->x0, (u8 *)b, c, n);
  }
  if (p->b47 == 0xFF)
  {
    p->b47 = 0;
  }
}
/* localdecomp:end func_00399A48 */

typedef struct { u8 p[0x2D]; u8 b2D; } S_4F78;
extern u8 D_002DB190[];
extern s16 D_002DAFB0[];
extern s32 D_002DA740[];
extern s32 D_002DDC30[];
extern s32 D_001DA480;
extern s32 D_001DA484;
extern void func_003CCF60();
INCLUDE_ASM("asm/nonmatchings/text", func_00399D68);

LINKER_REMNANT("asm/remnants", func_00399E78);

INCLUDE_ASM("asm/nonmatchings/text", func_00399E80);

LINKER_REMNANT("asm/remnants", func_0039A148);

typedef struct { u8 p0[0x64C]; s32 f64C; u8 p650[0x668 - 0x650]; s32 f668; s32 f66C; } S_395360;
extern S_395360 D_00160C40;
extern s32 *D_001D4B50_0039A150;
extern u8 D_01FF7FF0[];
extern s32 func_003A2680();
INCLUDE_ASM("asm/nonmatchings/text", func_0039A150);
TEXT_PADDING(2);

LINKER_REMNANT("asm/remnants", func_0039A1D8);

typedef struct { u8 p0[0x79A4]; s32 f79A4; u8 p79A8[8]; s32 f79B0; s32 f79B4; u8 p79B8[8]; s32 f79C0; s32 f79C4; } S_160C40_003953F0;
typedef struct { u8 p0[0x90]; u32 f90; u32 f94; } S_1A30B0_003953F0;
extern S_160C40_003953F0 D_160C40_0039A1E0;
extern S_1A30B0_003953F0 D_001A30B0[];
extern s32 D_002275EC[];
extern s32 D_001D4D00;
extern s32 D_001D4D04;
extern s32 D_001D52E0;
extern s32 D_001D4B48;
extern s32 D_001D4B4C;
extern s32 D_001D4B54;
extern void func_13CA28(void);
extern s32 func_13B620(void);
extern s32 func_13CDF0(s32);
extern s32 func_13CEB0(void);
extern s32 func_12BC00(void);
extern void func_003A4260(void);
extern void func_003A1198(void);
extern void func_003A1238(s32);
extern void func_13BED0(void);
/* localdecomp:start func_0039A1E0 */
s32 func_0039A1E0(void) {
    func_13CA28();
    func_13B620();
    if (func_13CDF0(1) != 0) {
        D_001D4D00++;
        if (D_001D52E0 != 1) return 0;
        if (D_001D4D00 < 0x2D1) return 0;
        D_001D4D04 = D_001D52E0;
        D_001D52E0 = 0;
        if (D_001D4B48 < 3) D_001D4B48--;
        func_13CEB0();
        return 0;
    }
    if (func_12BC00() != 0) {
        if (D_001D4D04 == 0) {
            D_001D4D04 = 1;
            D_001D52E0 = 0;
            if (D_001D4B48 < 3) D_001D4B48--;
        }
    }
    switch (D_001D4B48) {
    case 0: {
        S_160C40_003953F0 *b = &D_160C40_0039A1E0;
        u32 m = 0xFFFFF000;
        s32 a, x, c;
        x = ((b->f79C4 << 11) + 0xFFF) & m;
        a = D_002275EC[0] - x;
        D_001D4B54 = a;
        x = ((b->f79B4 << 11) + 0xFFF) & m;
        c = a - x;
        /* D_001D4B50 by address: as a declared scalar, reorg moves this store into the b delay slot */
        *(s32 *)0x1D4B50 = c;
        func_003A2680(c, b->f79B0 + b->f79A4, b->f79B4);
        D_001D4B48++;
        break;
    }
    case 1: {
        S_160C40_003953F0 *b = &D_160C40_0039A1E0;
        func_003A2680(D_001D4B54, b->f79C0 + b->f79A4, b->f79C4);
        D_001D4B48++;
        break;
    }
    case 2:
        if (D_001D4B4C != 0) return 0;
        func_003A4260();
        func_003A1198();
        D_001D4B48++;
        break;
    case 3:
        func_13B620();
        if (D_001A30B0[0].f90 == 0xFFFFFFFF) break;
        D_001D4B48++;
        break;
    case 4:
        func_003A1238(0);
        D_001D4B48++;
        break;
    case 5:
        func_13B620();
        if (D_001A30B0[0].f94 == 0xFFFFFFFF) return 0;
        func_13BED0();
        return 1;
    }
    return 0;
}
/* localdecomp:end func_0039A1E0 */

LINKER_REMNANT("asm/remnants", func_0039A418);

typedef struct { u8 p0[6]; u8 b6; u8 p7[5]; u8 bC; u8 pD[0x3B]; s32 w48[1]; } W_395648;
typedef struct { u8 p0[0x24]; W_395648 *w24; u8 p28[0xA]; u16 h32; u16 h34; u8 p36[2]; long d38; u8 p40[2]; u8 b42; u8 b43; u8 p44[0x1E]; u8 b62; u8 b63; u8 p64[4]; s32 w68; u8 p6C[0x2C]; s32 w98; u8 p9C[0xE]; s16 hAA; u8 pAC[8]; s16 hB4; } O_395648;
typedef struct { u8 p0[0x38]; s32 w38; u8 p3C[4]; s16 h40; u8 p42[2]; s16 h44; u8 p46[2]; s16 h48; u8 p4A[0xA]; s32 w54; u8 p58[0xC]; s32 w64; u8 *w68; s32 w6C; u8 p70[0xC]; s16 h7C; s16 h7E; u8 p80[0x120]; O_395648 *arr[1]; } G_395648;
typedef struct { u8 p0[0x25C0]; u8 *q25C0; } Q_395648;
extern G_395648 D_00225700_0039A438;
extern Q_395648 D_1A4BE0;
extern O_395648 *D_001D9BCC;
extern void func_11F0A0(s32);
extern O_395648 *func_003C24B0_0039A438(s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_0039A438);

/* func_0039A690: from the US C of func_003958A0 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags.

   PAL change: retail reads the word at 0x001DA058 (global D_001DA058) with %hi/%lo
   (lui/lw), not through $gp.  D_001DA058 is declared in func_00397EA8's block, sized with an `.extern X, 16` hint, so the assembler expands the load with lui (see there). */

/* localdecomp:start func_0039A690 */
typedef struct {
    u8 pad0[0x6C];
    u32 f6C;
    u8 pad1[0x20];
    u32 slots[1];
} T_958A0;

extern T_958A0 D_00225700[];
extern u32 D_00227590[];
extern void func_0039A438(void);

void func_0039A690(s32 a0) {
    u32 value = D_00225700[0].slots[a0];

    D_00225700[0].f6C = value;
    func_0039A438();
    D_00225700[0].f6C = D_00227590[0] + D_001DA058;
}
/* localdecomp:end func_0039A690 */
