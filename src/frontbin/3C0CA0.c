#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_00381FF0(s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u8 pad[6]; u8 f6; u8 pad7[5]; u8 fC; u8 padD[0x48 - 0xD]; void *f48[1]; } T_3A1870;
typedef struct {
    u8 pad[0x24]; T_3A1870 *f24; u8 pad28[0x32 - 0x28]; s16 f32; u16 f34; u8 pad36[2];
    long f38; u8 pad40[2]; u8 f42; u8 f43; u8 pad44[0x62 - 0x44]; u8 f62; u8 f63; u8 pad64[4];
    u8 *f68; u8 pad6C[0x98 - 0x6C]; s32 f98; u8 pad9C[0xAA - 0x9C]; s16 fAA;
} O_3A1870;
extern void func_003C25D8(O_3A1870 *, s32);
extern s32 func_00381FF0();
extern void func_003BBA08(s32, s32);
extern void func_003BC408();
extern s32 func_003BDD38();
extern void func_003BE308();
extern s32 func_003BDD38(void);
extern void func_003BE308(void *);
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_003C2880(s32 p);
typedef int u128_t __attribute__((mode(TI)));
extern void func_003C2DC0(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003C2EC0();
extern void func_003C2DC0();
extern void func_003C0CC0(void);
extern void func_003C2D88();
extern void func_003C29B0();
extern void func_003BDCB0(s32, s32 *, s32);
extern void func_003BDE20();
extern void func_003BDE20(s32);


/* localdecomp:start func_003C0CA0 */
extern void func_003A8220(void *);
extern u8 D_0031D130[];
 
void func_003C0CA0(void) {
    func_003A8220(D_0031D130);
}
/* localdecomp:end func_003C0CA0 */

/* localdecomp:start func_003C0CC0 */
extern u8 D_001D8D20;
void func_003C0CC0(void) {
    D_001D8D20 = 0;
}
/* localdecomp:end func_003C0CC0 */

/* localdecomp:start func_003C0CC8 */
extern s32 D_002D2018[];
extern s32 func_11BB58(void *, s32, s32);
extern u8 D_001D8D20;
void func_003C0CC8(s32 a0) {
    D_001D8D20 = 1;
    func_11BB58(D_002D2018, a0, 0x40);
}
/* localdecomp:end func_003C0CC8 */

/* localdecomp:start func_003C0CF8 */
typedef struct { s32 f0; u8 p4[0x4C]; u8 f50; u8 f51; } S_BB7E8;
typedef struct { s32 a; s32 b; } P_BB7E8;
typedef struct { u8 p[0x68]; s32 f68; } T_BB7E8;
extern S_BB7E8 D_002D2008_003C0CF8[];
extern T_BB7E8 D_00227580[];
extern P_BB7E8 D_0037FA58[];
extern s32 D_0037FA60[];
extern s32 D_0037FA64[];
extern s32 D_001D9030;
extern u8 D_001D9034[];
extern s32 D_0022D8B0[];
extern s32 D_00225700_003C0CF8[];
extern s32 func_003BB7B8();
extern void func_003BC588();
extern void func_003A56F8();
extern void func_003C0F00();
s32 func_003C0CF8(void) {
    s32 r, a, s, tmp;
    s32 *p;
    u8 *d;
    s32 t;
    S_BB7E8 *g;
    g = D_002D2008_003C0CF8;
    g->f50 = 0;
    g->f51 = 0;
    r = func_003BB7B8();
    if (D_001D8D20) {
        D_001D8D20 = 0;
    } else {
        d = (u8 *)g + 0x10;
        if ((u32)(r - 1) < 2 || r == 4 || r == 8 || r == 0x1B || r == 0x1C || r == 9 || r == 0x1D
            || r == 5 || r == 0xD || r == 0x17 || r == 0xA || r == 0x12 || r == 0xE) {
            if (r > 0) a = D_0037FA58[r % 60].b;
            else a = D_0037FA64[0];
        } else {
            if (r > 0) a = D_0037FA58[r % 60].a;
            else a = D_0037FA60[0];
        }
        func_11BB58(d, func_00381FF0(a), 0x40);
    }
    func_003BBA08(1, 0);
    func_003BC408(5, &D_001D9030);
    func_003BDCB0(4, (s32 *)D_001D9034, D_001D9030);
    s = D_00227580[0].f68;
    func_003BC588(r, &tmp, s);
    D_002D2008_003C0CF8[0].f0 = s;
    s = s + tmp;
    D_00227580[0].f68 = s;
    func_003BDE20(func_003BDD38());
    func_003BE308(func_003C0F00);
    { s32 i = 0; while (D_0022D8B0[i]) { D_0022D8B0[i] = 0; i++; } }
    func_003A56F8(D_00225700_003C0CF8[0x15]);
    func_003C0CA0();
    return 1;
}
/* localdecomp:end func_003C0CF8 */

/* localdecomp:start func_003C0F00 */
extern void func_003C1280_003C0F00();
void func_003C0F00(u8 *p) {
    s32 ok = 0;
    switch (*(s16 *)(p + 0xAA)) {
    case 0x1E03:
        *(u16 *)(p + 0x34) |= 1;
        *(void **)(p + 0x64) = func_003C1280_003C0F00;
        ok = 1;
        break;
    case 0xD54:
        *(void **)(p + 0x64) = 0;
        ok = 1;
        break;
    }
    if (ok) *(u16 *)(p + 0x34) &= ~2;
    else *(u16 *)(p + 0x34) |= 2;
}
/* localdecomp:end func_003C0F00 */

typedef struct { u8 p0[0x24]; struct { u8 p[0x24]; f32 f24; } *w24; u8 p28[4]; f32 f2C; u8 p30[0x32]; u8 b62; u8 p63[0x32]; u8 b95; u8 p96[0x14]; s16 hAA; } Q_3BBA50;
typedef struct { u8 p0[0x34]; s32 w34; u8 p38[8]; s16 h40; u8 p42[0x12]; Q_3BBA50 *w54; } G_3BBA50;
extern G_3BBA50 D_00225700_003C0F60[];
extern u8 D_002D2008_003C0F60[];
extern u32 D_001DA49C;
extern u32 D_001DA4A0;
extern f32 D_001D6EF0;
extern Q_3BBA50 *D_001DA008;
extern Q_3BBA50 *D_0022D8B0_003C0F60[];
extern void func_003C7DD8();
extern void func_003A58C0();
INCLUDE_ASM("asm/nonmatchings/text", func_003C0F60);

/* US draft of func_003C1158 (rac3-uya-decomp func_003BBC48, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003C1158 */
extern s32 D_001D9030_003C1158;
extern u8 D_002D2008_003C1158[];
extern u8 D_00225700_003C1158[];
extern void func_003BC768();
extern s32 func_003BDF10();
extern s32 func_003BDF18();
extern void func_003BB968();
extern void func_003BE168();
extern s32 func_003BDD38();
extern void func_003BDE60();
extern void func_003BE308();
extern void func_003BDF40();
extern void func_003C0CA0();
extern void func_003BDF60();
extern void func_003C0F00();
__asm__(".extern D_001D9030_003C1158, 4");
void func_003C1158(s32 a0) {
    s32 v4;
    s32 v5;
    u8 *g;
    if (D_002D2008_003C1158[0x50] != 0) {
        func_003BC768();
        if (func_003BDF10() == 1) {
            func_003BE168();
        }
        if (func_003BDF10() > 0 && func_003BDF18() != 0) {
            func_003BB968();
        }
        if (D_002D2008_003C1158[0x51] == 0) {
            if (func_003BDF10() > 0 && a0 != 0) {
                v4 = D_001D9030_003C1158;
                D_002D2008_003C1158[0x51] = 1;
            } else {
                v4 = func_003BDD38();
            }
            func_003BDE60(v4);
            func_003BE308(func_003C0F00);
            func_003BDF40();
            func_003C0CA0();
        }
    }
    g = D_00225700_003C1158;
    v5 = *(s16 *)(g + 0x40);
    if (D_002D2008_003C1158[0x51] != 0) {
        if (*(s32 *)(g + 0x34) >= 0x1F) v5 += 0x1E;
    }
    func_003BDF60(*(s32 *)(g + 0x34), v5, 6, 6);
}
/* localdecomp:end func_003C1158 */

/* US draft of func_003C1280 (rac3-uya-decomp func_003BBD70, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: unmapped symbols: func_003BBD98. */


/* localdecomp:start func_003C1280 */
extern void func_00389D60(void (*)(), s32);
extern void func_003C12A8();
 
void func_003C1280(s32 a0) {
    func_00389D60(func_003C12A8, a0);
}
/* localdecomp:end func_003C1280 */

INCLUDE_ASM("asm/nonmatchings/text", func_003C12A8);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BBD98;
typedef int Q_3BBD98 __attribute__((mode(TI)));
typedef struct {
    V_3BBD98 l0;
    V_3BBD98 v[4];
    u32 col[4];
    u8 pk[0x20];
    unsigned long g[4];
    V_3BBD98 a0, b0, c0, d0, e0, f0, o100, c110, v120, v130, v140;
} L_3BBD98;
/* PAL candidate for func_003C1490 (frontbin). The US draft called func_003A26D0;
   in PAL that callee is func_003A7AF8 (src/frontbin/3A53E8.c). */

/* localdecomp:start func_003C1490 */
extern void func_003A6790(void *);
extern void func_003A7AF8(void *);
extern void func_003A8450();
void func_003C1490(u8 *p) {
    if (p[0x95] < 11) return;
    func_003A6790(p);
    func_003A7AF8(p);
    func_003A8450();
}
/* localdecomp:end func_003C1490 */

/* localdecomp:start func_003C14D8 */
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 h40; } S_3BBFC8;
extern u8 D_002D2008[];
extern S_3BBFC8 D_00225700_003C14D8;
extern void func_003BCAF8();
extern void func_0038E150(s32);
extern void func_00389240();
extern void func_00389370();
extern void func_0038E7E8_003C14D8(f32, f32, s32, u8 *, s32, f32, f32, s32, s32, unsigned long, f32, f32);
void func_003C14D8(void) {
    s32 v;
    u8 *s;
    S_3BBFC8 *g;
    func_003BCAF8();
    s = D_002D2008;
    if (s[0x51] != 0) {
        func_0038E150(1);
        func_00389240(1);
        g = &D_00225700_003C14D8;
        v = 0xE0 - (g->h40 - g->f34) * 3;
        if (v < 0) v = 0;
        if (v > 0xC0) v = 0xC0;
        if (v > 0) {
            func_0038E7E8_003C14D8(70.0f, (f32)(*(s32 *)0x1D4BC4 - 0x5A), (v << 24) | 0xC37A33, s + 0x10, -1, 1.5f, 1.5f, 0, 1, (unsigned long)(s32)0x80000000, 2.0f, 2.0f);
        }
        func_00389370();
    }
}
/* localdecomp:end func_003C14D8 */

/* localdecomp:start func_003C15C8 */
extern s16 D_0016C5AC[];
 
void func_003C15C8(void) {
    func_003BDF40();
    func_003BC768();
    func_003C0CA0();
    D_0016C5AC[0] = 1;
}
/* localdecomp:end func_003C15C8 */

extern s32 func_00381FF0(s32);
extern void func_003BBA08(s32, s32);
extern void func_003BC408(s32, s32);
extern s32 func_0011B754(void *, s32);
extern u8 D_001D9088;
extern volatile s32 D_001D4B4C;
typedef struct { u8 n0[0x10]; u8 n1[0x10]; u8 n2[0x10]; s32 f30, f34, f38, f3C, f40, f44, f48, f4C, f50; u8 p54[0xC]; s8 f60; } S_BC0F0;
extern S_BC0F0 D_002D2060[];
typedef struct { u8 pad[0x1AF8]; s32 f1AF8; u8 p2[0x1B14-0x1AFC]; s32 f1B14, f1B18, f1B1C; } S_BC0F0b;
extern S_BC0F0b D_001A4BE0[];
INCLUDE_ASM("asm/nonmatchings/text", func_003C1600);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1728);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C9A0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C1A80);
TEXT_PADDING(2);

typedef struct {
    char n0[0x10];
    char n1[0x10];
    char n2[0x10];
    f32 f30;
    s32 f34, f38, f3C, f40, f44, f48, f4C;
    f32 f50;
} S_3BC568;
extern S_3BC568 D_002D2060_003BC568;
extern f32 D_001D9048, D_001D904C, D_001D9050, D_001D9054, D_001D9058, D_001D905C;
extern f32 D_001D9060, D_001D9064, D_001D9068, D_001D906C, D_001D9070, D_001D9074;
extern s32 D_001D9078;
extern f32 D_001D907C, D_001D9080;
extern s32 D_001D4BC4;
extern char D_001D9098[], D_001D90A0[], D_001D90A8[];
extern long func_00389598(s32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
extern void func_0038B120(s32, s32, s32, s32, s32, s32, s32, s32, f32, long, long);
extern void func_0038AF30(s32, s32, s32, s32, long);
extern void func_11B2E8();
extern s32 func_11B868(char *);
extern s32 func_00390D48(char *, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
typedef struct { u8 p0[0x20]; u8 f20; u8 p21[0x47]; s32 f68; u8 p6c[0x34]; u32 fA0; u8 pa4[0x5C]; } O_3BCFB0;
extern u32 D_001DA4A0;
extern u32 D_001DA4A4;
extern s32 D_001D9D00;
extern s32 D_001DA3C0;
extern volatile u8 D_001D90C8;
extern s32 func_003C7310();
extern void func_0038CB78();
extern int func_003C38E0();
INCLUDE_ASM("asm/nonmatchings/text", func_003C24B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003C25D8);

typedef struct { u8 p0[0x6]; u8 b6; u8 p7[5]; u8 bC; u8 pD; u8 bE; u8 bF; s32 w10; u8 p14[0x10]; f32 f24; u8 p28[0x18]; s32 w40; u16 h44; u8 p46; u8 b47; struct { u8 p[0x10]; u8 b10; s8 b11; } *w48; } S_3BD0D8;
typedef struct {
    u8 p0[0x21]; u8 b21; u8 b22; u8 b23; S_3BD0D8 *w24; u8 p28[4]; f32 f2C; u8 p30[4]; u16 h34; s16 h36; u8 d38[8]; u8 p40[8]; s32 w48; f32 f4C; u8 p50[0x11]; u8 b61; u8 b62; u8 b63; s32 w64; u8 p68[4]; u8 b6C; u8 b6D; u8 b6E; u8 b6F; s32 w70; s32 w74; s32 w78; u8 p7C[2]; u8 b7E; u8 p7F[0x19]; s32 w98; u8 p9C[8]; u8 bA4; u8 bA5; u8 bA6; u8 bA7; u8 bA8; u8 pA9; s16 hAA; s32 wAC; u8 pB0[0xD]; u8 bBD;
} P_3BD0D8;
extern u8 D_002DB190[];
extern s16 D_002DAFB0[];
extern s32 D_002DD190[];
extern s32 D_002DAB00[];
extern S_3BD0D8 *D_002DA740[];
extern u32 D_001DA49C;

/* localdecomp:start func_003C2880 */
__asm__(".extern D_001DA4A0, 16");
__asm__(".extern D_001DA4B0, 16");
__asm__(".extern D_001DA4B4, 16");
__asm__(".extern D_001D9D00, 16");
typedef struct { u8 pad[0x20]; u8 b20; u8 pad21[0x33]; s32 f54; u8 pad58[0x10]; s32 f68; u8 pad6C[0x34]; s32 fA0; } O_3BD360;
extern u32 D_001DA4A0; 
extern s32 D_001DA4B0; 
extern s32 D_001DA4B4; 
extern s32 D_001D9D00; 
extern void func_003C7480();
extern void func_003C2C98();
extern void func_003C7958();
void func_003C2880(s32 arg) {
    O_3BD360 *o = (O_3BD360 *)arg;
    s32 p;
    if ((u32)o < D_001DA4A0) {
        o->b20 = 0xFD;
    } else {
        o->b20 = 0xFE;
        p = o->f68;
        if (p) {
            if (p >= D_001DA4B0 && p < D_001DA4B0 + D_001DA4B4 * 64) {
                func_003C7480(p);
                o->f68 = 0;
            }
        }
        while (o->f54) {
            func_003C2C98(o, o->f54);
        }
    }
    o->fA0 = D_001D9D00 + 2;
    func_003C7958(o, 0x80807F7F);
}
/* localdecomp:end func_003C2880 */

extern int D_001DA4CC;
extern int D_001DA4BC;
extern int D_001DA4C8;
extern int D_001DA4C0;
extern int D_001DA4C4;
extern void func_0038CB78(void *, int, int);
INCLUDE_ASM("asm/nonmatchings/text", func_003C2948);

/* localdecomp:start func_003C29B0 */
typedef struct { u8 p0[0x48]; u8 *tbl[1]; } C_3BD490;
typedef struct { u8 p0[0x24]; C_3BD490 *f24; u8 p28[0x18]; u8 b40; u8 b41; u8 b42; u8 b43; u8 p44[0x14]; s32 f58; s32 f5C; u8 p60[0xC]; u8 b6C; u8 p6D; u8 b6E; } S_3BD490;
extern u8 D_002D2100[];
void func_003C29B0(S_3BD490 *s)
{
  u8 *new_var2;
  int new_var;
  if (s->b42 != 0xFF)
  {
    new_var2 = s->f24->tbl[s->b42] + (s->b40 * 4);
    s->f58 = *((s32 *) (new_var2 + 0x1C));
    s->b6E = s->f24->tbl[s->b42][0x12];
    s->b6C = s->f24->tbl[s->b42][0x11];
  }
  else
  {
    s->b6C = s->b42;
    s->b6E = 0;
    s->f58 = (s32) (D_002D2100 + (s->b40 << 11));
  }
  s->f5C = *((s32 *) ((s->f24->tbl[s->b43] + (new_var = s->b41 * 4)) + 0x1C));
}
/* localdecomp:end func_003C29B0 */

/* localdecomp:start func_003C2A70 */
typedef struct { u8 p0[0x24]; void *f24; u8 p28[0xC]; u16 h34; u8 p36[0x36]; u8 b6C; u8 b6D; u8 p6E[0xE]; u16 h7C; } S_3BD550;
extern u8 D_1A30B0[];
extern void func_003A4F28(u32);
extern s32 func_003A52A0();
void func_003C2A70(S_3BD550 *p) {
    u8 *e;
    if (p->b6D != 0xFF) {
        e = D_1A30B0 + p->b6D * 128;
        if (*(S_3BD550 **)(e + 0xDC) != p) {
            p->b6D = 0xFF;
            return;
        }
        if (*(s16 *)(e + 0xCA) != p->b6C || (p->h34 & 0x40) || (p->h7C & 0x8000)) {
            func_003A4F28(p->b6D);
            p->b6D = 0xFF;
        }
    } else {
        if (p->b6C == 0xFF) return;
        if (p->h34 & 0x40) return;
        if (*(unsigned long *)((u8 *)p + 0x78) & 0x4800000000000UL) return;
        p->b6D = func_003A52A0(p->b6C, 4, p);
    }
}
/* localdecomp:end func_003C2A70 */

LINKER_REMNANT("asm/remnants", func_003C2B50);

/* localdecomp:start func_003C2B88 */
/* MATCH */
extern s32 D_002FC020[];
extern s32 D_001DA4E0;
__asm__(".extern D_001DA4E0, 16");
extern void func_003D1708();
s32 func_003C2B88(u8 *obj, u8 *dst) {
    u8 *out = (u8 *)0x70000000;
    u8 *src;
    s32 i;
    s32 *cnt = (s32 *)0x70002000;
    if (dst != 0) out = dst;
    if (obj == 0) goto fail;
    if (*(u8 **)(obj + 0x24) == 0) return 0;
    if ((*(u8 **)(obj + 0x24))[0xF] == 0) goto fail;
    D_002FC020[0] = (s32)obj;
    D_001DA4E0 = 1;
    D_002FC020[1] = 0x1000;
    func_003D1708(cnt, 0x2000);
    if (*cnt == 0) {
fail:
        return 0;
    }
    src = (u8 *)0x70002030;
    i = 0;
    while (i < *cnt) {
        if (*(s16 *)src == 0) {
            u128_t v = *(u128_t *)(src + 0x10);
            __asm__("sq $0,%0" : "=m"(*(u128_t *)(out + 0x10)));
            src += 0x20;
            *(u128_t *)out = v;
            out += 0x20;
        } else if (*(s16 *)src == 1) {
            *(u128_t *)out = *(u128_t *)(src + 0x10);
            *(u128_t *)(out + 0x10) = *(u128_t *)(src + 0x20);
            src += 0x30;
            out += 0x20;
        }
        i++;
    }
    return *cnt;
}
/* localdecomp:end func_003C2B88 */

LINKER_REMNANT("asm/remnants", func_003C2C88);

/* localdecomp:start func_003C2C98 */
typedef struct N_BD778 { u8 p0[8]; struct N_BD778 *next; } N_BD778;
typedef struct { u8 p0[0x54]; N_BD778 *head; } L_BD778;
extern void func_0038CB78(void *, s32, s32);
void func_003C2C98(L_BD778 *l, N_BD778 *n) {
    N_BD778 *p;
    N_BD778 *h;
    if (n != 0) {
        h = l->head;
        if (h == n) {
            l->head = n->next;
        } else if (h != 0) {
            p = h;
            while (p->next != 0 && p->next != n) {
                p = p->next;
            }
            if (p->next == n) {
                p->next = n->next;
            }
        }
        func_0038CB78(n, 0, 0x40);
    }
}
/* localdecomp:end func_003C2C98 */

/* localdecomp:start func_003C2D30 */
extern s32 D_001DA400[];
extern s32 D_001DA440[];
s32 func_003C2D30(s32 x) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_001DA400[i] == 0 || D_001DA400[i] == x) {
            D_001DA400[i] = x;
            D_001DA440[i] = 0;
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_003C2D30 */

/* localdecomp:start func_003C2D88 */
extern s32 D_001DA400[];
extern s32 D_001DA440[];
void func_003C2D88(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        D_001DA400[i] = 0;
        D_001DA440[i] = 0;
    }
}
/* localdecomp:end func_003C2D88 */

/* US draft of func_003C2DC0 (rac3-uya-decomp func_003BD8A0, commit 13cf5c5), names moved to PAL addresses
   where known. The US callee was the unmapped symbol func_003C1A90; in PAL the retail call
   target is func_003C6FE0 (src/frontbin/3C6FB0.c), which takes the same struct pointer. */


/* localdecomp:start func_003C2DC0 */
typedef struct { u8 p0[0x13]; u8 f13; } S_BDb;
typedef struct { u8 p0[0x48]; S_BDb *arr[1]; } S_BDt;
typedef struct { u8 p0[0x20]; u8 f20; u8 p21[3]; S_BDt *f24; u8 p28[9]; u8 f31; u8 p32[0x10]; u8 f42; u8 f43; f32 f44; u8 p48[4]; f32 f4C; } S_BDa;
extern S_BDa *D_001DA400_003C2DC0[16];
extern s32 D_001DA440_003C2DC0[16];
extern void func_003C6FE0();
void func_003C2DC0(void) {
    s32 i = 0;
    S_BDa *p;
    do {
        p = D_001DA400_003C2DC0[i];
        if (p != 0) {
            if (p->f20 & 0x80) { D_001DA400_003C2DC0[i] = 0; goto z; }
            if (p->f42 != 0xFF) { D_001DA400_003C2DC0[i] = 0; goto z; }
            if (p->f31 == 0 && D_001DA440_003C2DC0[i] >= 20) {
                if (p->f24->arr[p->f43]->f13 == p->f42) {
                    p->f44 = 1.0f - p->f4C;
                    func_003C6FE0(D_001DA400_003C2DC0[i]);
                }
            } else {
                D_001DA440_003C2DC0[i]++;
            }
        } else {
z:
            D_001DA440_003C2DC0[i] = 0;
        }
        i++;
    } while (i < 16);
}
/* localdecomp:end func_003C2DC0 */

/* localdecomp:start func_003C2EC0 */
typedef struct { f32 x, y, z, w; } V4_3BD9A0;
typedef int Q_3BD9A0 __attribute__((mode(TI)));
extern void func_003CA4A0();
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038D570();
extern void func_0038D640();
void func_003C2EC0(u8 *a, s32 b, u8 *out) {
    s32 loc;
    f32 buf[16];
    f32 scale;
    Q_3BD9A0 x, y;
    loc = b;
    scale = *(f32 *)(a + 0x2C) * 0.0009765625f;
    func_003CA4A0(a, 1, &loc, out);
    func_0038CE20((f32 *)(out + 0x30), out + 0x30, scale);
    func_0038D570(buf, a + 0xC0);
    func_0038D640(out, buf, out);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_3BD9A0 *)(a + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3BD9A0 *)(out + 0x30)));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_3BD9A0 *)(out + 0x30)) : "j"(x));

}
/* localdecomp:end func_003C2EC0 */

/* localdecomp:start func_003C2F58 */
typedef struct { f32 x, y, z, w; } V4_3BDA38;
typedef int Q_3BDA38 __attribute__((mode(TI)));
extern void func_003CA4A0();
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038D000(void *, void *, void *);
void func_003C2F58(u8 *a, s32 b, f32 *out) {
    s32 loc;
    f32 buf[12];
    f32 v[4];
    f32 scale;
    Q_3BDA38 x, y;
    loc = b;
    scale = *(f32 *)(a + 0x2C) * 0.0009765625f;
    func_003CA4A0(a, 1, &loc, buf);
    func_0038CE20(out, v, scale);
    func_0038D000(out, out, a + 0xC0);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_3BDA38 *)(a + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3BDA38 *)out));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_3BDA38 *)out) : "j"(x));

}
/* localdecomp:end func_003C2F58 */
