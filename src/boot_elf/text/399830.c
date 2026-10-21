#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
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

/* localdecomp:start func_00399830 */
extern unsigned long D_001D9F60[];
extern unsigned long D_001D9F78[];
void func_00399830(unsigned long *p, s32 a, s32 b, s32 c, s32 d, s32 idx) {
    unsigned long t0 = D_0022CAD0[idx * 3];
    unsigned long t1 = D_0022CAD0[idx * 3 + 1];
    unsigned long t2 = D_0022CAD0[idx * 3 + 2];
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
/* localdecomp:end func_00399830 */

/* localdecomp:start func_00399980 */
typedef struct { u8 p0[0x20]; s32 x20; u8 p24[0x10]; s32 x34; } S_1A1ED0_003947B0;
extern S_1A1ED0_003947B0 D_1A1ED0_00399980;
extern s32 D_001D4BB0;
extern s32 D_001D4BB4;
extern void func_12C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
typedef s32 (*F12C9A0_3947B0)(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
void func_00399980(u8 *base, s32 n, s32 m, s32 *e) {
    u8 buf[0x60];
    s32 x, r, i, j;
    { S_1A1ED0_003947B0 *g = &D_1A1ED0_00399980; x = g->x20; }
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
    r = D_1A1ED0_00399980.x34;
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
/* localdecomp:end func_00399980 */
