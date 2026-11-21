#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
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
typedef struct { unsigned long z; s16 h8; s16 hA; s16 hC; s16 hE; } E_393878;
typedef struct { s16 h0; s16 h2; s16 h4; u8 p6[0x1A]; s32 f20; } F_393878;
typedef struct { u8 p0[4]; s16 h4; s16 h6; u8 p8[4]; s16 hC; u8 pE[2]; s32 f10; s32 f14; s32 f18; s32 f1C; s32 f20[1]; } H_393878;
extern H_393878 *D_001DA5F0;
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
extern void func_00399D08();
extern void func_0038CF58();
extern s32 func_00381BC0();
extern void func_0038D108();
typedef struct { u8 p0[0x18]; s32 f18; u8 p1c[0x1C]; unsigned long f38; } S_16C580_00393DC8;
typedef struct { u8 p0[0x1284]; s32 f1284; u8 p1[0xAD8]; struct { s32 a; s32 b; } e[1]; } S_160C40_00393DC8;
extern S_16C580_00393DC8 D_16C580;
extern S_160C40_00393DC8 D_160C40;
extern s32 D_002275F0[];
extern unsigned long D_0022CAD0[3];
extern s32 D_001D5F30;
extern void func_003A96A8(s32);
extern s32 func_003A2AF0(s32, s32, s32);
extern void func_00399E28(s32, s32, void *, s32);
typedef struct { u8 p0[0x30]; s32 x30; u8 p34[4]; unsigned long x38; } S_16C580_00393E90;
typedef struct { u8 p0[0x1284]; s32 f1284; u8 p1[0xAF0]; struct { s32 a; s32 b; } e[1]; } S_160C40_00393E90;
typedef struct { u8 p0[0x18]; s32 x18; u8 p1c[0x10]; s32 x2C; } S_1A1ED0_00393E90;
typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; } T_00393E90;
extern S_16C580_00393E90 D_16C580_00399060;
extern S_160C40_00393E90 D_160C40_00399060;
extern S_1A1ED0_00393E90 D_1A1ED0_00399060;
extern s32 D_001DA05C;
extern s32 D_001DA048[];
extern s32 func_003A2B50(s32);
extern s32 func_003A2AF0(s32, s32, s32);
extern void func_12C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
typedef struct { s32 off; s32 size; } E_94060;
typedef struct { u8 p0[0x18]; s32 f18; s32 f1C; E_94060 e[5]; } B_94060;
typedef struct { u8 p0[4]; s32 f4; s32 f8; s32 fC; s32 f10; u8 p14[0x40]; s32 f54; s32 f58; s32 f5C; s32 f60; s32 f64; u8 p68[0x2C]; s32 f94; u8 p98[4]; s32 f9C; s32 fA0; s32 fA4; } G_94060;
typedef struct { u8 p0[0x10]; s32 f10; } Q_94060;
extern B_94060 *D_001D4B50_00399230;
extern int D_001D9EA0_00399230;
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
extern s32 func_003936A0();
extern void func_0038D108();
extern void func_003994D0();
extern s32 func_003A8A30();
extern void func_00393548();
extern void func_11F0A0();
extern void func_003933B0();
extern void func_00393518();
typedef struct { s32 off; s32 x4; } E_394300;
typedef struct { u8 pad[0x18]; E_394300 e[1]; } H_394300;
typedef struct { u8 pad[0x74]; s32 arr[1]; } G_394300;
extern H_394300 *D_001D4B50;
extern G_394300 *D_001D9EA0;
void func_003A0B60(u8 *, u32);

/* localdecomp:start func_00399538 */
#include "vu0.h"
/* func_00399538 log:
 * - straight port of rac1-decomp's build_indexed_resident_render_packet (plus the count == 0 arm with the
 *   tbp from D_1A1ED0+0x34): 179 diff; header/format sub-expressions as rac1's locals: 154
 * - per-arm w0/w1 with the stores in each arm (the shared tail is cross-jumping): 4 diff
 * - tbp = t->f0 first, then rebased (one pseudo, retail's $t4): one swap left; the TEX0 word as one
 *   chain tbp|bw<<14|0x1B<<20|tw<<26|th<<30: MATCH with --as ps2as
 * - BLOCKED: plzcw (log2dim, twice) is an MMI instruction the compiler never emits; asm for it is not
 *   allowed now (Matching-Patterns.md), and the file's flags lack @ps2as (Ps2EeAs constant expansion).
 */
typedef struct { s32 f0; s16 width; s16 height; s16 count; s16 cbp; s16 mip0; s16 mip1; } T_00399538;
typedef struct { u8 p0[0x20]; s32 x20; u8 p24[0x10]; s32 x34; } S_1A1ED0_00399538;
extern S_1A1ED0_00399538 D_001A1ED0_00399538;
extern unsigned long D_001D9F60[];
extern unsigned long D_001D9F78[];
static __inline__ s32 log2dim_00399538(s32 x) {
    return 30 - plzcw_asm(x);
}
/* the same function as rac1-decomp's build_indexed_resident_render_packet, with log2dim inlined */
void func_00399538(unsigned long *p, T_00399538 *t, s32 a, s32 b, s32 c, s32 d, s32 idx) {
    S_1A1ED0_00399538 *r = &D_001A1ED0_00399538;
    s32 bw64, bw128, tw, th, base, mip1, cbp, mip0, n;
    unsigned long *q;

    bw64 = t->width >> 6;
    bw128 = t->width >> 7;
    if (bw64 <= 0) bw64 = 1;
    if (bw128 <= 0) bw128 = 1;
    tw = log2dim_00399538(t->width);
    th = log2dim_00399538(t->height);
    base = r->x20 >> 8;
    cbp = t->cbp + base;
    mip0 = t->mip0 + base;
    mip1 = t->mip1 + base;
    n = t->count;
    if (idx >= 0) {
        if (n == 0) {
            unsigned long w0, w1;
            s32 tbp = t->f0;
            tbp = (r->x34 + tbp * 4) >> 8;
            {
                unsigned long v = (unsigned long)b << 6;
                unsigned long u = ((unsigned long)a << 32) | 0x20;
                p[0] = v | u;
            }
            p += 2;
            p[0] = c | ((unsigned long)d << 2) | ((unsigned long)idx << 24);
            p += 2;
            {
                unsigned long adr;
                w0 = ((((unsigned long)tbp | ((unsigned long)bw64 << 14)) | ((unsigned long)0x1B << 20)) | ((unsigned long)tw << 26)) | ((unsigned long)th << 30);
                adr = ((unsigned long)cbp << 37) | ((unsigned long)0x8000 << 19);
                w0 |= adr;
                w0 |= (unsigned long)-1 << 63;
            }
            w1 = 0x40000400004000;
            p[0] = w0;
            p[2] = w1;
        } else {
            unsigned long w0, w1;
            unsigned long filter, hdr, fmt, adr, madr;
            filter = ((unsigned long)b << 6) | 0x20;
            hdr = ((unsigned long)(n - 1) << 2) | filter;
            hdr |= (unsigned long)a << 32;
            p[0] = hdr;
            p += 2;
            p[0] = c | ((unsigned long)d << 2) | ((unsigned long)idx << 24);
            p += 2;
            fmt = ((unsigned long)tw << 26) | 0x1300000;
            w0 = (((unsigned long)bw64 << 14) | fmt) | ((unsigned long)th << 30);
            adr = ((unsigned long)0x8000 << 19) | ((unsigned long)cbp << 37);
            w1 = ((unsigned long)bw128 << 14) | ((unsigned long)mip0 << 20);
            madr = ((unsigned long)mip1 << 40) | ((unsigned long)0x8000 << 19);
            w1 |= madr;
            w0 |= adr;
            w0 |= (unsigned long)-1 << 63;
            w1 |= (unsigned long)0x8000 << 39;
            p[0] = w0;
            p[2] = w1;
        }
    } else if (idx < -1) {
        q = D_001D9F60;
        if (idx == -3) q = D_001D9F78;
        {
            unsigned long v = (unsigned long)b << 6;
            unsigned long u = ((unsigned long)a << 32) | 0x20;
            p[0] = v | u;
        }
        p += 2;
        p[0] = 5;
        p += 2;
        p[0] = q[0];
        p[2] = q[2];
    } else {
        {
            unsigned long v = (unsigned long)b << 6;
            unsigned long u = ((unsigned long)a << 32) | 0x20;
            p[0] = v | u;
        }
        p += 2;
        p[0] = 5;
        p += 2;
        p[0] = 0x80000004CC007FFBUL;
        p[2] = 0;
    }
}
/* localdecomp:end func_00399538 */
