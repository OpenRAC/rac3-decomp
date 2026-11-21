#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern unsigned long D_0022CAD0[3];
extern void func_00399A48(s32, s32, void *, s32);
extern void func_003990F0();
/* --- end of declarations from other files --- */

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

/* localdecomp:start func_00399158 */
#include "vu0.h"
typedef struct { s32 x0; s16 h4; s16 h6; s16 h8; s16 hA; s16 hC; s16 hE; } T_00399158;
typedef struct { u8 p0[0x20]; s32 x20; u8 p24[0x10]; s32 x34; } S_1A1ED0_00399158;
extern S_1A1ED0_00399158 D_1A1ED0_00399158;
extern unsigned long D_001D9F60[];
extern unsigned long D_001D9F78[];

void func_00399158(unsigned long *p, T_00399158 *t, s32 a, s32 b, s32 c, s32 d, s32 idx) {
    s32 cb = D_1A1ED0_00399158.x20;
    s32 h8 = t->h8;
    s32 w = t->h4;
    s32 h6 = t->h6;
    s32 hC = t->hC;
    s32 hA = t->hA;
    s32 hE = t->hE;
    s32 tw, th, bw, bw2;
    s32 cbE, cbA, cbC;
    cb >>= 8;
    cbE = hE + cb;
    cbC = hC + cb;
    cbA = hA + cb;
    bw = w >> 6;
    if (bw <= 0) bw = 1;
    bw2 = w >> 7;
    if (bw2 <= 0) bw2 = 1;
    tw = 30 - plzcw_asm(w);
    th = 30 - plzcw_asm(h6);
    if (idx >= 0) {
        if (h8 == 0) {
            s32 tbp = t->x0;
            tbp = (D_1A1ED0_00399158.x34 + tbp * 4) >> 8;
            p[0] = ((unsigned long)1 << 5) | ((unsigned long)b << 6) | ((unsigned long)a << 32);
            p += 2;
            p[0] = (unsigned long)c | ((unsigned long)d << 2) | ((unsigned long)idx << 24);
            p += 2;
            p[0] = (unsigned long)tbp | ((unsigned long)bw << 14) | ((unsigned long)0x1B << 20) | ((unsigned long)tw << 26)
                 | ((unsigned long)th << 30) | ((unsigned long)1 << 34) | ((unsigned long)cbA << 37) | ((unsigned long)4 << 61);
            p[2] = ((unsigned long)1 << 14) | ((unsigned long)1 << 34) | ((unsigned long)1 << 54);
        } else {
            p[0] = ((unsigned long)(h8 - 1) << 2) | ((unsigned long)1 << 5) | ((unsigned long)b << 6) | ((unsigned long)a << 32);
            p += 2;
            p[0] = (unsigned long)c | ((unsigned long)d << 2) | ((unsigned long)idx << 24);
            p += 2;
            p[0] = ((unsigned long)bw << 14) | ((unsigned long)0x13 << 20) | ((unsigned long)tw << 26)
                 | ((unsigned long)th << 30) | ((unsigned long)1 << 34) | ((unsigned long)cbA << 37) | ((unsigned long)4 << 61);
            p[2] = ((unsigned long)bw2 << 14) | ((unsigned long)cbC << 20) | ((unsigned long)1 << 34)
                 | ((unsigned long)cbE << 40) | ((unsigned long)1 << 54);
        }
    } else if (idx < -1) {
        unsigned long *q = D_001D9F60;
        if (idx == -3) q = D_001D9F78;
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
/* localdecomp:end func_00399158 */

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
/* localdecomp:start func_003995A0 */
void func_003995A0(u8 *base, s32 n, s32 m, s32 *e) {
    u8 buf[0x60];
    s32 x, r, i, j;
    { S_1A1ED0_003947B0 *g = &D_1A1ED0_003995A0; x = g->x20; }
    D_001D4BB0 = x;
    D_001D4BB4 = x;
    if (n > 0) {
        s32 one = 1;
        i = n;
        do {
            u8 *off = base + e[3];
            s32 lo = e[1] & 0xFFFF;
            s32 hi = e[1] >> 16;
            s32 cur = D_001D4BB0;
            if (e[0] == 0x13) {
                s32 t = lo >> 6;
                s32 k;
                if (t == 0) t = one;
                ((F12C9A0_3947B0)func_12C9A0)(buf, cur >> 8, t, 0x13, 0, 0, lo, hi);
                k = lo * hi;
                if (k <= 0xFF) k = 0x100;
                D_001D4BB0 += k;
            } else if (e[0] == 2) {
                ((F12C9A0_3947B0)func_12C9A0)(buf, cur >> 8, 1, 2, 0, 0, 0x10, 0x10);
                D_001D4BB0 += 0x200;
            } else if (e[0] == 0) {
                ((F12C9A0_3947B0)func_12C9A0)(buf, cur >> 8, 1, 0, 0, 0, 0x10, 0x10);
                D_001D4BB0 += 0x400;
            }
            func_11F0A0(0);
            i--;
            e += 4;
            func_12CCC8(buf, off);
            func_12A9F0(0, 0);
        } while (i != 0);
    }
    r = D_1A1ED0_003995A0.x34;
    D_001D4BB4 = D_001D4BB0;
    if (m > 0) {
        j = m;
        do {
            s32 lo = e[1] & 0xFFFF;
            s32 hi = e[1] >> 16;
            u8 *off = base + e[2];
            s32 t = lo >> 6;
            if (t == 0) t = 1;
            ((F12C9A0_3947B0)func_12C9A0)(buf, r >> 8, t, 0x1B, 0, 0, lo, hi);
            j--;
            e += 4;
            r += lo * hi * 4;
            func_11F0A0(0);
            func_12CCC8(buf, off);
            func_12A9F0(0, 0);
        } while (j != 0);
    }
}
/* localdecomp:end func_003995A0 */

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
/* localdecomp:start func_00399D68 */
extern int D_001DA480;
extern int D_001DA484;
extern unsigned char D_002DB190[];
extern short D_002DAFB0[];
extern char *D_002DA740_00399D68[];
extern int D_002DDC30[];
extern void func_003CCF60(int, int);


void func_00399D68(char *object, s32 a, void *b, s32 id)
{
    if (object == 0) {
        func_003CCF60(id, 1);
        D_002DB190[id] = *(unsigned char *)&D_001DA484;
        D_001DA484 = D_001DA484 + 1;
    } else {
        D_002DAFB0[D_001DA480] = id;
        D_002DB190[id] = *(unsigned char *)&D_001DA480;
        D_002DA740_00399D68[D_001DA480] = object;
        D_002DDC30[D_001DA480] = (unsigned char)object[0x2D] << 10;
        if ((unsigned char)object[0x2D] == 255)
            D_002DDC30[D_001DA480] = 0x100000;
        func_00399A48((s32)object, a, b, id);
        func_003CCF60(id, 0);
        ++D_001DA480;
    }
}
/* localdecomp:end func_00399D68 */

LINKER_REMNANT("asm/remnants", func_00399E78);

/* localdecomp:start func_00399E80 */
#include "vu0.h"
typedef struct { u8 p0[0x10]; s32 x10; u8 p14[8]; u16 x1C; u8 p1E[0xA]; u8 x28; u8 p29[0x17]; } E_00399E80;
typedef struct { s32 x0; s32 x4; f32 x8; s32 xC; } H_00399E80;
typedef struct { s32 w; s32 p4[3]; s32 x10; s32 x14; s32 p18[2]; s32 x20; s32 x24; } R_00399E80;
typedef struct { u8 p0[4]; s16 h4; s16 h6; s16 h8; s16 hA; s16 hC; s16 hE; } T_00399E80;
typedef struct { u8 p0[0x20]; s32 x20; } S_1A1ED0_00399E80;
extern S_1A1ED0_00399E80 D_1A1ED0_00399E80;
extern E_00399E80 *D_001DA660;
extern s32 D_001DA664;
extern f32 D_001DA66C;
extern f32 D_001DA670[];
extern s32 D_0022CC68[];
extern void func_003CEDF8(void);

void func_00399E80(s32 *h, u8 *tab) {
    E_00399E80 *base;
    s32 i, j, n;
    f32 f;
    D_001DA664 = h[1];
    f = *(f32 *)&h[2];
    D_001DA66C = f;
    D_0022CC68[0] = h[3];
    D_001DA670[0] = f * 6.0f;
    D_001DA670[1] = f * 4.0f;
    D_001DA670[2] = f + f;
    func_003CEDF8();
    base = (E_00399E80 *)((u8 *)h + h[0]);
    D_001DA660 = base;
    for (n = 0; n < D_001DA664; n++) {
        base[n].x10 = (s32)base + base[n].x10;
    }
    for (i = 0; i < D_001DA664; i++) {
        for (j = 0; j < D_001DA660[i].x28; j++) {
            unsigned long *p = (unsigned long *)(D_001DA660[i].x10 + D_001DA660[i].x1C + j * 0x50);
            R_00399E80 *r = (R_00399E80 *)p;
            s32 cb = D_1A1ED0_00399E80.x20 >> 8;
            s32 k = r->w;
            T_00399E80 *t = (T_00399E80 *)(tab + (k << 4));
            s32 a = r->x10;
            s32 b = r->x14;
            s32 c = r->x20;
            s32 d = r->x24;
            s32 h8 = t->h8;
            s32 w = t->h4;
            s32 cbE = t->hE + cb;
            s32 cbC = t->hC + cb;
            s32 cbA = t->hA + cb;
            s32 tw, th, bw, bw2;
            bw2 = w >> 7;
            if (bw2 <= 0) bw2 = 1;
            bw = w >> 6;
            if (bw <= 0) bw = 1;
            th = 30 - plzcw_asm((s32)t->h6);
            tw = 30 - plzcw_asm(w);
            p[0] = (unsigned long)0 | ((unsigned long)bw << 14) | ((unsigned long)0x13 << 20) | ((unsigned long)tw << 26)
                 | ((unsigned long)th << 30) | ((unsigned long)1 << 34) | ((unsigned long)cbA << 37) | ((unsigned long)4 << 61);
            p += 2;
            p[0] = 0 | ((unsigned long)(h8 - 1) << 2) | ((unsigned long)1 << 5) | ((unsigned long)b << 6) | ((unsigned long)a << 32);
            p += 2;
            p[0] = (unsigned long)c | ((unsigned long)d << 2) | ((unsigned long)k << 24);
            p += 2;
            p[2] = 0;
            p[0] = 0 | ((unsigned long)bw2 << 14) | ((unsigned long)cbC << 20) | ((unsigned long)1 << 34)
                | ((unsigned long)cbE << 40) | ((unsigned long)1 << 54);
        }
    }
}
/* localdecomp:end func_00399E80 */

LINKER_REMNANT("asm/remnants", func_0039A148);

typedef struct { u8 p0[0x64C]; s32 f64C; u8 p650[0x668 - 0x650]; s32 f668; s32 f66C; } S_395360;
extern S_395360 D_00160C40;
extern s32 *D_001D4B50_0039A150;
extern u8 D_01FF7FF0[];
extern s32 func_003A2680();
/* localdecomp:start func_0039A150 */
s32 func_0039A150(void)
{
    S_395360 *toc = &D_00160C40;
    s32 *p = (s32 *)((s32)(D_01FF7FF0 - (((toc->f66C << 11) + 0x1057) & 0xFFFFF000)) & -16);
    D_001D4B50_0039A150 = p;
    *p = 0x60;
    func_003A2680((u8 *)D_001D4B50_0039A150 + *D_001D4B50_0039A150, toc->f668 + toc->f64C, toc->f66C);
    return 1;
}
/* localdecomp:end func_0039A150 */
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
/* localdecomp:start func_0039A438 */
extern void func_003C25D8();
void func_0039A438(void) {
    u8 *h;
    s32 *tp;
    s32 *e;
    s32 i, k, kind, b, x;
    s32 off;
    O_395648 *o;
    func_11F0A0(0);
    func_003A0760((u8 *)D_00225700_0039A438.w6C, (u32)D_00225700_0039A438.w68);
    func_11F0A0(0);
    h = D_00225700_0039A438.w68;
    D_00225700_0039A438.w38 = 0;
    tp = (s32 *)(h + 0x14);
    D_00225700_0039A438.h40 = *(u16 *)(h + 0);
    x = *(s32 *)(h + 4);
    D_00225700_0039A438.h48 = *(u16 *)(h + 8);
    D_00225700_0039A438.h44 = *(u16 *)(h + 0xC);
    D_00225700_0039A438.w64 = (s32)h + *(s32 *)(h + 0x10);
    if (x != 0) {
        D_00225700_0039A438.h7C = x;
        D_00225700_0039A438.h7E = (x >> 16) + 1;
    }
    for (i = 0; i < D_00225700_0039A438.h44; i++) {
        e = (s32 *)(h + *tp++);
        kind = *e;
        e += 3;
        off = (s32)h + *e++;
        if (kind == 0x215 || kind == 0x10D1) kind = 0xD54;
        o = D_00225700_0039A438.arr[i];
        if (o == 0) {
            if (kind == 0) {
                o = D_001D9BCC;
                func_003C25D8(o, 0);
            } else {
                o = func_003C24B0_0039A438(kind, 0);
            }
            o->h32 = 0x1FF;
            o->b62 = 0xFF;
            o->h34 |= 6;
            o->w98 = 0;
            o->hB4 = 0;
            if (D_1A4BE0.q25C0 == 0) {
                o->d38 = 0xE0E0E000UL << 22;
            } else {
                o->d38 = *(long *)(D_1A4BE0.q25C0 + 0x38);
            }
            if (o->w24->b6 != 0) o->b63 = 0x18;
            b = o->w24->bC;
            o->w24->bC = b + 1;
            o->b42 = b;
            o->b43 = b;
            D_00225700_0039A438.arr[i] = o;
            if (o->hAA == 0xD54) D_00225700_0039A438.w54 = (s32)o;
        }
        o->w68 = off;
        o->w24->w48[o->b42] = (s32)e;
        for (k = 0; k < ((u8 *)e)[0x10]; k++) {
            s32 *q = (s32 *)((u8 *)e + 0x1C);
            q[k] = (s32)e + q[k];
        }
    }
}
/* localdecomp:end func_0039A438 */

/* func_0039A690: from the US C of func_003958A0 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags.

   PAL change: retail reads the word at 0x001DA058 (global D_001DA058) with %hi/%lo
   (lui/lw), not through $gp.  D_001DA058 is declared sized, with an `.extern X, 16` hint, as in
   func_00397EA8's block (src/frontbin/397D48.c, the file this code was in before the cut at
   0x00398E50), so the assembler expands the load with lui (see there). */

/* localdecomp:start func_0039A690 */
extern u32 D_001DA058;
__asm__(".extern D_001DA058, 16");
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
