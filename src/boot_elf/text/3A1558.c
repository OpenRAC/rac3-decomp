#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_003A2998(s32, s32, s32);
extern void func_003A15F0(s32 a, s32 idx);
extern void func_003A2330();
extern s32 func_003A2AF0(s32, s32, s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003A2958(void);
extern void func_003A2028(void);
extern void func_003A16D0(void);
extern s32 func_003A2A80();
extern void func_003A1598(void);
extern void func_003A1638(s32);
extern s32 func_003A2A30();
extern s32 func_003A2AF0();
/* --- end of declarations from other files --- */

/* declarations of 3A0EC0.c's earlier functions (tools/port_from_us.py) */
extern s32 D_001D5B94_003A1148;
extern s32 D_001D5B90_003A1148;
extern s32 D_001D5B8C;
extern s32 D_001D6D98;
extern s32 D_001D6D9C_003A1148;
extern s32 D_001D6DA0_003A1148;
extern u8 *D_001D6DA8_003A1148;
extern f32 D_002259B0[];
extern void func_003A8E10(void);
extern void func_00382BF0(s32, s32, s32, f32, f32, f32, f32);
extern void func_003877A0();
extern void func_003A8C70();
extern void func_003B35D0();
extern s32 D_001D6D98;
extern s32 D_001D5B90[];
extern s32 D_001D5B90[];
extern s32 D_001D5B94[];
extern s32 D_001D4CEC[];
extern u8  D_001D5B78[];
extern s32 D_001D9FD0[];
extern s32 D_001A7430[];
extern s32 D_001D6DA4[];
extern s32 D_001D6D9C[];
extern s32 D_001D6DA0[];
extern s32 D_001D6DA8[];
extern s32 D_001D5B90[];
extern s32 D_001D5B94[];
extern s32 D_001D4CEC[];
extern u8  D_001D5B78[];
extern s32 D_001D9FD0[];
extern s32 D_001A7430[];
extern s32 D_001D6DA4[];
extern s32 D_001D6D9C[];
extern s32 D_001D6DA0[];
extern s32 D_001D6DA8[];
extern u8 D_001D5B78[];
extern s32 D_001A7430[];
extern s32 D_001D9FD0_003A12C0[1];
extern s32 D_001D5B90_003A12C0;
extern s32 D_001D5B94_003A12C0;
extern s32 D_001D4CEC_003A12C0;
extern s32 D_001D6DA4_003A12C0;
extern s32 D_001D6D9C_003A12C0;
extern s32 D_001D6DA0_003A12C0;
extern s32 D_001D6DA8_003A12C0;
extern s32 D_001D5B90_003A1398;
extern s32 D_001D5B94_003A1398;
extern s32 D_001A7430_003A1398[];
extern s32 D_001D9FD0_003A1398[1];
extern s32 D_001D6DA4_003A1398;
extern s32 D_001D6D9C_003A1398;
extern s32 D_001D6DA0_003A1398;
extern s32 D_001D6DA8_003A1398;
extern u32 *D_001DA050_003A1428;
extern u32 *D_001DA050_0039C02A;
extern s32 D_00227400_003A1428[];
extern s32 D_00225700_003A1428[];
extern u32 D_001D4CF8_003A1428;
extern u8 D_001D0560[];
extern void func_0038A798();

/* localdecomp:start func_003A1558 */
extern s32 func_0013CA30(s32, s32, s32, s32);
void func_003A1558(void) {
    func_0013CA30(7, 0xA000, 0, 1);
}
/* localdecomp:end func_003A1558 */

/* localdecomp:start func_003A1580 */
void func_003A1580(s32 a0, long a1) {

    s32 *p = (s32 *)(u32)a1;
    if (p != 0) {
        *p = a0;
    }
}
/* localdecomp:end func_003A1580 */

/* localdecomp:start func_003A1598 */
extern s32 func_003A1580_003A1598();
extern void func_0013BAB8(s32, s32, void *, unsigned long, s32);
typedef struct { u8 p0[0x79A4]; s32 f79A4; u8 p1[0x10]; s32 f79B8; } S_C170a;
typedef struct { u8 p0[0x90]; u32 f90; } S_C170b;
extern S_C170a D_00160C40[];
extern S_C170b D_001A30B0_003A1598[];
void func_003A1598(void) {
    D_001A30B0_003A1598[0].f90 = 0xFFFFFFFF;
    func_0013BAB8(D_00160C40[0].f79B8 + D_00160C40[0].f79A4, 0, &func_003A1580_003A1598, (unsigned long) ((long) &D_001A30B0_003A1598[0].f90 << 0x20) >> 0x20, D_00160C40[0].f79A4);
}
/* localdecomp:end func_003A1598 */

/* localdecomp:start func_003A15F0 */
typedef struct { u8 pad[0x90]; u32 a[1]; } S_39C1C8;
extern S_39C1C8 D_001A30B0_003A15F0[];
extern void func_003A1580();
extern void func_13BC30(s32, void *, unsigned long);
void func_003A15F0(s32 a, s32 idx) {
    S_39C1C8 *s = D_001A30B0_003A15F0;
    u32 *q = s->a;
    u32 *p = q + idx;
    *p = 0xFFFFFFFF;
    func_13BC30(a, func_003A1580, (u32)p);
}
/* localdecomp:end func_003A15F0 */

/* localdecomp:start func_003A1638 */
typedef struct { u8 pad[0x90]; u32 a[1]; u32 b[1]; } S_3A14F8;
typedef struct { s32 v; s32 w; } E_3A14F8;
typedef struct { u8 pad0[0x79A4]; s32 f79A4; u8 pad1[0x79E8 - 0x79A8]; E_3A14F8 e[1]; } G_3A14F8;
extern S_3A14F8 D_001A30B0_003A1638[];
extern G_3A14F8 D_00160C40_003A1638[];
extern void func_003A1580();
void func_003A1638(s32 idx) {
    G_3A14F8 *g = D_00160C40_003A1638;
    s32 v = g->e[idx].v;
    S_3A14F8 *s;
    u32 *q;
    if (v) {
        s = D_001A30B0_003A1638;
        q = s->b;
        s->a[idx + 1] = 0xFFFFFFFF;
        ((void (*)(s32, s32, void *, unsigned long))func_0013BAB8)(v + g->f79A4, 0, func_003A1580, (u32)(q + idx));
    } else {
        D_001A30B0_003A1638->a[idx + 1] = 0;
    }
}
/* localdecomp:end func_003A1638 */

/* localdecomp:start func_003A16D0 */
typedef struct {
    u8 p0[0x24];
    s32 f24;
    u8 p28[0x3C - 0x28];
    s16 f3C;
    u8 p3E[2];
    u8 f40;
    u8 f41;
    u8 f42;
    u8 f43;
    s32 f44;
    u8 p48[0x4E - 0x48];
    s16 f4E;
    u8 p50[0x6C - 0x50];
    s32 f6C;
    u8 p70[0x76 - 0x70];
    s16 f76;
    u8 p78[0xBC - 0x78];
    s32 fBC;
    u8 pC0[0xC6 - 0xC0];
    s16 fC6;
} S_1CCFD0_003A1590;
extern S_1CCFD0_003A1590 D_1CCFD0_003A16D0;
extern void func_003A1558(void);
extern void func_003A1730(void);

void func_003A16D0(void) {
    s32 m = -1;
    D_1CCFD0_003A16D0.f40 = 0x20;
    D_1CCFD0_003A16D0.f41 = 0;
    D_1CCFD0_003A16D0.f42 = 0;
    D_1CCFD0_003A16D0.f43 = 0;
    D_1CCFD0_003A16D0.f44 = 0;
    D_1CCFD0_003A16D0.f4E = 0;
    D_1CCFD0_003A16D0.f6C = 0;
    D_1CCFD0_003A16D0.f76 = 0;
    D_1CCFD0_003A16D0.fBC = 0;
    D_1CCFD0_003A16D0.fC6 = 0;
    D_1CCFD0_003A16D0.f24 = m;
    D_1CCFD0_003A16D0.f3C = m;
    func_003A1558();
    func_003A1730();
}
/* localdecomp:end func_003A16D0 */

/* localdecomp:start func_003A1730 */
extern void func_13CF40(void (*)());
extern void func_003A2BF8();
 
void func_003A1730(void) {
    func_13CF40(func_003A2BF8);
}
/* localdecomp:end func_003A1730 */

/* localdecomp:start func_003A1750 */
void func_003A1750(s32 a0, s32 *a1) {
    if (a0 >= 0x1770) {
        *a1 = 6;
    } else {
        *a1 = 2;
    }
}
/* localdecomp:end func_003A1750 */

/* localdecomp:start func_003A1770 */
typedef struct { s32 a, b; } P_39C2E8;
typedef struct { P_39C2E8 l[0x29]; s32 pad; } R_39C2E8;
typedef union {
    struct { u8 p[0x1284]; s32 base; } d;
    struct { u8 p[0x1E78]; P_39C2E8 t[1]; } c;
    struct { u8 p[0x224C]; s32 base; s32 t[1]; } g;
    struct { u8 p[0x2648]; s32 t[1][400]; } a;
    struct { u8 p[0x7A04]; s32 base; P_39C2E8 e[1]; } b;
    struct { u8 p[0x921C]; s32 base; } h;
} S_160C40_39C2E8;
typedef struct { u8 p[0xB7]; u8 fB7; } S_143950_39C2E8;
extern S_160C40_39C2E8 D_160C40_003A1770;
extern R_39C2E8 D_1DBC0[];
extern R_39C2E8 D_169E60[];
extern R_39C2E8 D_169E64[];
extern R_39C2E8 D_1DBC4[];
extern S_143950_39C2E8 D_00143950_003A1770;
void func_003A1770(s32 id, s32 *out1, s32 *out2) {
    *out1 = 0;
    *out2 = 0;
    if (id >= 7000) {
        s32 v;
        s32 l = D_00143950_003A1770.fB7;
        if (l) l--;
        v = *(D_160C40_003A1770.a.t[l] - 7000 + id);
        if (v) *out1 = v + D_160C40_003A1770.g.base;
    } else if (id >= 6000) {
        s32 v;
        s32 l = D_00143950_003A1770.fB7;
        if (l) l--;
        l -= 6000;
        v = D_160C40_003A1770.b.e[id + l].a;
        if (v) *out1 = D_160C40_003A1770.b.base + v;
    } else if (id >= 5000) {
        s32 v;
        v = D_160C40_003A1770.c.t[id - 5000].a;
        if (v) *out1 = D_160C40_003A1770.d.base + v;
    } else if (id >= 4000) {
        s32 v;
        v = *(s32 *)((u8 *)&D_1DBC0[id] + D_00143950_003A1770.fB7 * 8);
        if (v) {
            s32 w;
            *out1 = D_160C40_003A1770.d.base + v;
            w = D_1DBC4[id].l[D_00143950_003A1770.fB7].a;
            if (w) *out2 = D_160C40_003A1770.d.base + w;
        }
    } else if (id >= 3000) {
        s32 v;
        v = D_160C40_003A1770.b.e[id - 3000].a;
        if (v) *out1 = D_160C40_003A1770.b.base + v;
    } else if (id >= 2000) {
        s32 v;
        s32 l = D_00143950_003A1770.fB7;
        if (l) l--;
        l -= 2000;
        v = D_160C40_003A1770.b.e[id + l].a;
        if (v) *out1 = D_160C40_003A1770.b.base + v;
    } else if (id >= 1000) {
        s32 v;
        s32 l = D_00143950_003A1770.fB7;
        if (l) l--;
        l -= 1000;
        v = D_160C40_003A1770.g.t[id + l];
        if (v) *out1 = D_160C40_003A1770.g.base + v;
    } else {
        s32 v;
        v = *(s32 *)((u8 *)&D_169E60[id] + D_00143950_003A1770.fB7 * 8);
        if (v) {
            s32 w;
            *out1 = D_160C40_003A1770.h.base + v;
            w = D_169E64[id].l[D_00143950_003A1770.fB7].a;
            if (w) *out2 = D_160C40_003A1770.h.base + w;
        }
    }
}
/* localdecomp:end func_003A1770 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A19D0);

/* localdecomp:start func_003A1B98 */
extern void func_0038CF58(void *, s32, s32);
extern void func_0038D068(u8 *, u8 *, s32);
extern void func_0013CC40(s32);
typedef struct {
    u8 pad0[0x6C];
    s32 f6C;
    u8 pad1[0x76 - 0x70];
    s16 f76;
    u8 pad2[0x94 - 0x78];
    s32 f94;
    s16 f98;
    u8 pad3[0x9E - 0x9A];
    s16 f9E;
    u8 pad4[0xB4 - 0xA0];
    s32 fB4;
} S_001CCFD0_0039C710;
extern S_001CCFD0_0039C710 D_001CCFD0_003A1B98[];
s32 func_003A1B98(void) {
    S_001CCFD0_0039C710 *p = D_001CCFD0_003A1B98;

    if (p->f76 == 0 && p->f9E == 3) {
        if (p->f94 != 0) {
            func_0038D068((u8 *)&p->f6C, (u8 *)&p->f94, 0x28);
            func_0038CF58(&p->f94, 0, 0x28);
            p->f98 = -1;
            p->fB4 = -1;
            func_0013CC40(p->f6C);
            p->f76 = 4;
            return 1;
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_003A1B98 */

/* localdecomp:start func_003A1C38 */
typedef struct { u8 pad0[0x44]; u32 f44; s16 f48; s16 f4A; s16 f4C; s16 f4E; u8 pad50[4]; s16 f54; u8 pad56[2]; s32 f58; s32 f5C; } S_1CCFD0_0039C7B0;
typedef struct { u8 pad[0x7A04]; s32 base; struct { s32 a; s32 b; } e[1]; } S_160C40_0039C7B0;
extern S_1CCFD0_0039C7B0 D_1CCFD0_003A1C38;
extern S_160C40_0039C7B0 D_160C40_003A1C38;
extern void func_003A2D38(s32, long);
extern void func_13CB20(long,long,s32,s32,s16,s32,s32,s32,s32,s32,void*,unsigned long);
void func_003A1C38(s32 a0, s32 a1, s32 a2) {
 long y4, y5;
 if (D_1CCFD0_003A1C38.f44 == 0) {
 if (D_160C40_003A1C38.e[a0].a != 0) {
D_1CCFD0_003A1C38.f44 = 0xFFFFFFFF;
D_1CCFD0_003A1C38.f4E = 1;
D_1CCFD0_003A1C38.f48 = a0;
D_1CCFD0_003A1C38.f4A = a2;
y5 = D_160C40_003A1C38.e[a0 + 1].a + D_160C40_003A1C38.base;
y4 = D_160C40_003A1C38.e[a0].a + D_160C40_003A1C38.base;
D_1CCFD0_003A1C38.f4C = a1;
D_1CCFD0_003A1C38.f58 = 10;
D_1CCFD0_003A1C38.f5C = 0xBB80;
D_1CCFD0_003A1C38.f54 = 0;
func_13CB20((s32)y4, (s32)y5, 0, 0, (s16)a2, 0, 1, 0, 0, 1, func_003A2D38, (u32)&D_1CCFD0_003A1C38.f44);
}}}
/* localdecomp:end func_003A1C38 */

/* localdecomp:start func_003A1D30 */
typedef struct { u8 p0[0x44]; u32 f44; s16 f48; s16 f4A; s16 f4C; s16 f4E; u8 p50[4]; s16 f54; u8 p56[2]; s32 f58; s32 f5C; } S_CFD0_8A8;
typedef struct { u8 p0[0x7A04]; s32 f7A04; s32 t[1]; } S_160_8A8;
extern S_CFD0_8A8 D_1CCFD0_003A1D30;
extern S_160_8A8 D_00160C40_003A1D30;
extern void func_003A2E50();
extern void func_13CB20(long,long,s32,s32,s16,s32,s32,s32,s32,s32,void*,unsigned long);
void func_003A1D30(s32 a, s32 b, s32 c) {
 long x, y; s32 t;
 if (a >= 0) { if (D_1CCFD0_003A1D30.f44 == 0) { t = D_00160C40_003A1D30.t[a*2]; if (t != 0) {
D_1CCFD0_003A1D30.f48 = a;
x = t + D_00160C40_003A1D30.f7A04;
D_1CCFD0_003A1D30.f44 = 0xFFFFFFFF;
D_1CCFD0_003A1D30.f4E = 1;
D_1CCFD0_003A1D30.f4C = b;
D_1CCFD0_003A1D30.f58 = 10;
D_1CCFD0_003A1D30.f4A = c;
D_1CCFD0_003A1D30.f5C = 0xBB80;
D_1CCFD0_003A1D30.f54 = 0;
y = D_00160C40_003A1D30.t[(a+1)*2] + D_00160C40_003A1D30.f7A04;
func_13CB20((s32)x, (s32)y, 0, 0, c, 0, 1, 0, 0, 0, func_003A2E50, (unsigned long)((long)&D_1CCFD0_003A1D30.f44 << 0x20) >> 0x20);
}}}}
/* localdecomp:end func_003A1D30 */

/* localdecomp:start func_003A1E28 */
typedef struct { u8 p0[0x44]; u32 f44; s16 f48; s16 f4A; s16 f4C; s16 f4E; u8 p50[4]; s16 f54; u8 p56[2]; s32 f58; s32 f5C; } S_1CCFD0_39C9A0;
typedef struct { u8 p0[0x7A04]; s32 base; struct { s32 a; s32 b; } e[1]; } S_160C40_39C9A0;
extern S_1CCFD0_39C9A0 D_1CCFD0_003A1E28;
extern S_160C40_39C9A0 D_160C40_003A1E28;
extern void func_003A2DF8();
extern void func_13CB20(long,long,s32,s32,s16,s32,s32,s32,s32,s32,void*,unsigned long);
void func_003A1E28(s32 a0, s32 a1, s32 a2) {
    u32 t; long x, y;
    if (D_1CCFD0_003A1E28.f4E != 9) {
        t = D_1CCFD0_003A1E28.f44;
        if (t != 0) {
          if (t != 0xFFFFFFFFu) {
            if (D_160C40_003A1E28.e[a0 + 1].a != 0) {
                D_1CCFD0_003A1E28.f48 = a0;
                y = D_160C40_003A1E28.e[a0 + 2].a + D_160C40_003A1E28.base;
                D_1CCFD0_003A1E28.f4E = 9;
                x = D_160C40_003A1E28.e[a0 + 3].a + D_160C40_003A1E28.base;
                D_1CCFD0_003A1E28.f58 = 10;
                D_1CCFD0_003A1E28.f5C = 0xBB80;
                D_1CCFD0_003A1E28.f4A = a2;
                D_1CCFD0_003A1E28.f4C = a1;
                D_1CCFD0_003A1E28.f54 = 0;
                func_13CB20((s32)x, (s32)y, 0, 0, (s16)a2, 0, 1, t, 0, (a1 & 1) << 2, func_003A2DF8, (u32)&D_1CCFD0_003A1E28.f44);
            }
          }
        }
    }
}
/* localdecomp:end func_003A1E28 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A1F40);

typedef struct {
    u8 p0[0x2C]; s16 f2C; u8 p2E[0xE]; s16 f3C; s16 f3E; u8 p40[4];
    s32 f44; s16 f48; u8 p4A[2]; s16 f4C; s16 f4E; u8 p50[0x1C];
    s32 f6C; u8 p70[4]; s16 f74; s16 f76; u8 p78[0x1C];
    s32 f94; u8 p98[4]; s16 f9C; s16 f9E; u8 pA0[0x1C];
    s32 fBC; u8 pC0[4]; s16 fC4; s16 fC6;
} S_1CCFD0_39CBA0;
extern S_1CCFD0_39CBA0 D_1CCFD0_003A2028;
extern s32 D_001D6DB8_003A2028;
extern s32 D_001D9FF0_003A2028;
extern s32 func_13B620_003A2028();
extern void func_13CA28(void);
extern void func_13CAE8();
extern s32 func_12C908(s32);
extern void func_13CD00();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A2028);

LINKER_REMNANT("asm/boot_elf/remnants", func_003A20F8);

typedef struct {
    u8 pad0[0x24];
    s32 f24;
    s32 f28;
    u8 pad1[0x24];
    u16 f50;
    u8 pad2[0x78 - 0x52];
    u16 f78;
    u8 pad3[0xc8 - 0x7a];
    u16 fc8;
} S_1CCFD0;
extern S_1CCFD0 D_001CCFD0;

/* localdecomp:start func_003A2100 */

// Apply a single-zero address suffix identity here
extern S_1CCFD0 D_1CCFD0_003A2100;

void func_003A2100(void) {
    // Route assignments to point directly to the single-zero alias target
    D_1CCFD0_003A2100.f50 = 4;
    D_1CCFD0_003A2100.fc8 = 4;
    D_1CCFD0_003A2100.f78 = 4;
}
/* localdecomp:end func_003A2100 */

/* localdecomp:start func_003A2120 */
typedef struct { u32 f0; s16 f4; s16 f6; s16 f8; s16 fA; s16 fC; u8 fE[2]; } S_39CC98;
extern void func_13C118(s32);
extern void func_13CC10(s32);
extern void func_13CC40(s32);
extern void func_13CC70(s32, void *, unsigned long);
extern void func_13CCA0(s32, void *, unsigned long);
extern void func_13C200(s32, void *, unsigned long);
extern void func_13CCD0(s32, void *, unsigned long);
extern s32 func_0038CEE0(void *);
extern void func_003A2ED0(s32, long);
extern void func_003A2EE8(s32, long);
extern void func_003A2E90(s32, long);
extern void func_003A2C88(s32, long);
void func_003A2120(S_39CC98 *s) {
    s32 h;
    if (s->fA != 9 && s->f0 != 0 && s->f0 != 0xFFFFFFFF) {
        if (s->fA == 5) {
            if (s->f0 == 0) {
                s->fA = 0;
            } else {
                func_13C118(s->f0);
                s->fA = 6;
            }
        } else if (s->fA == 6) {
            if (s->f0 == 0) s->fA = 0;
        }
        if (s->f0 != 0) {
            if (s->fC & 0x8000) {
                if (!(s->fA & 0x8000)) {
                    func_13CC10(s->f0);
                    s->fA |= 0x8000;
                }
                if (func_0038CEE0(s->fE) == 2) s->fC = 4;
            } else if (s->fA & 0x8000) {
                func_13CC40(s->f0);
                s->fA ^= 0x8000;
            }
            if (!(s->fA & 0x8000)) {
                if (s->fA == 1 || s->fA == 8 || s->fA == 9) {
                } else if (s->fA != 2 && s->fA != 3) {
                    h = s->f0;
                    s->f0 = 0xFFFFFFFF;
                    func_13CC70(h, func_003A2ED0, (u32)s);
                    func_13CCA0(h, func_003A2EE8, (u32)s);
                    func_13C200(h, func_003A2E90, (u32)s);
                } else if (s->f0 != 0xFFFFFFFF && s->fA == 2) {
                    func_13CCD0(s->f0, func_003A2C88, (u32)s);
                }
            }
        }
    } else if (s->fA == 7 || s->f0 == 0) {
        s->fA = 0;
    }
    if (s->fA == 0) s->f4 = -1;
}
/* localdecomp:end func_003A2120 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A2330);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C4E0);

/* localdecomp:start func_003A2958 */
typedef struct { u8 pad0[4]; s16 h4; u8 b6; } S_39D4D0;
extern S_39D4D0 D_001CCFD0_003A2958[];
extern s32 func_13CEB0(void);
void func_003A2958(void) {
    if (D_001CCFD0_003A2958->h4 != 0) {
        func_13CEB0();
        D_001CCFD0_003A2958->b6 = 1;
    }
}
/* localdecomp:end func_003A2958 */

/* localdecomp:start func_003A2998 */
s32 func_13CD28(s32, s32, s32, void *);             /* extern */
typedef struct { u8 pad0[0x4]; s16 f4; u8 pad6[0x2]; s32 f8; u8 padC[0x4]; s32 f10; s32 f14; s32 f18; s32 f1C; } S_001CCFD0_0039D510_0039D510;
extern S_001CCFD0_0039D510_0039D510 D_001CCFD0_003A2998[];

s32 func_003A2998(s32 arg0, s32 arg1, s32 arg2) {
    if ((D_001CCFD0_003A2998->f4 == 0) && (arg2 != 0)) {
        D_001CCFD0_003A2998->f18 = 0;
        D_001CCFD0_003A2998->f1C = 0;
        if (func_13CD28(arg1, arg2, arg0, (u8 *)D_001CCFD0_003A2998 + 0x40) != 0) {
            D_001CCFD0_003A2998->f14 = arg0;
            D_001CCFD0_003A2998->f4 = 1;
            D_001CCFD0_003A2998->f8 = arg1;
            D_001CCFD0_003A2998->f10 = arg2;
            return arg2 << 0xB;
        }
    }
    return 0;
}
/* localdecomp:end func_003A2998 */

/* localdecomp:start func_003A2A30 */
extern s32 func_003A2998(s32, s32, s32);
extern s32 D_001CCFD0_003A2A30[];
s32 func_003A2A30(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 r = func_003A2998(a0, a1, a2);
    if (r != 0) {
    D_001CCFD0_003A2A30[6] = a3;
    D_001CCFD0_003A2A30[7] = a4;
    }
    return r;
}
/* localdecomp:end func_003A2A30 */

typedef struct { u8 b[4]; } B4_0039D5F8;
extern B4_0039D5F8 D_001CD010[];
extern u8 D_001D52E0;
extern s32 D_001D4D00;
extern s32 D_001D4D04;
extern void func_0013CD28();
extern void func_0013CA28();
extern void func_0013B620();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A2A80);

/* localdecomp:start func_003A2AF0 */
extern s32 func_003A2B50(s32);
extern s32 func_003A2998(s32, s32, s32);
s32 func_003A2AF0(s32 a, s32 b, s32 c) {
    s32 r;
    func_003A2B50(1);
    r = func_003A2998(a, b, c);
    func_003A2B50(1);
    return r;
}
/* localdecomp:end func_003A2AF0 */

/* localdecomp:start func_003A2B50 */
typedef struct { u8 pad[4]; s16 s; u8 pad2[0x10]; } S_39D6C8;
extern S_39D6C8 D_1CCFD0_003A2B50;
extern void func_003A2330();
extern void func_13CA28();
extern s32 func_13B620(void);
extern void func_13CA20();
extern void func_0038CF30();
s32 func_003A2B50(s32 a) {
    if (a) {
        do {
            func_003A2330();
            func_13CA28();
            func_13B620();
            func_13CA20();
            if (D_1CCFD0_003A2B50.s == 0) break;
            func_0038CF30(0x2710);
        } while (D_1CCFD0_003A2B50.s != 0);
    } else {
        func_003A2330();
        func_13CA28();
        func_13B620();
        func_13CA20();
    }
    return D_1CCFD0_003A2B50.s;
}
/* localdecomp:end func_003A2B50 */

/* localdecomp:start func_003A2BF8 */
s32 func_0011F0A0(s32);                       /* extern */
s32 func_13CEF8();                                  /* extern */
typedef struct { s32 x0; s16 h4; u8 b6; u8 b7; u8 pad[0x10]; void *f18; s32 f1C; } S_39D770;
extern S_39D770 D_001CCFD0_003A2BF8[];

void func_003A2BF8(s32 arg0) {
    s32 (*temp_v1)(s32, s32);
    s32 temp_a0;
    s32 temp_a1;

    if (arg0 == 1) {
        if (D_001CCFD0_003A2BF8->h4 == 0) {
            D_001CCFD0_003A2BF8->f18 = 0;
            D_001CCFD0_003A2BF8->f1C = 0;
            return;
        }
        if (func_13CEF8() != 0) {
            D_001CCFD0_003A2BF8->h4 = 2;
            return;
        }
        func_0011F0A0(0);
        temp_v1 = (s32 (*)(s32, s32))D_001CCFD0_003A2BF8->f18;
        D_001CCFD0_003A2BF8->h4 = 0;
        temp_a1 = D_001CCFD0_003A2BF8->b6 == 0;
        D_001CCFD0_003A2BF8->b6 = 0U;
        if (temp_v1 != 0) {
            temp_a0 = D_001CCFD0_003A2BF8->f1C;
            D_001CCFD0_003A2BF8->f18 = 0;
            D_001CCFD0_003A2BF8->f1C = 0;
            temp_v1(temp_a0, temp_a1);
        }
    }
}
/* localdecomp:end func_003A2BF8 */

/* localdecomp:start func_003A2C88 */
void func_003A2C88(s32 a, long l) {
    s16 *p = (s16 *)(u32)l; 
    if (p != 0 && a != 0 && p[5] == 2) {
        p[5] = 3;
    }
}
/* localdecomp:end func_003A2C88 */

/* localdecomp:start func_003A2CB8 */
typedef struct { u8 pad[0x48]; s16 f48, f4A, f4C; u8 pad2[0x46]; s32 f94; s16 f98, f9A, f9C; u8 pad3[0x12]; s32 fB0; } S_1CCFD0b;
extern S_1CCFD0b D_1CCFD0;
extern u8 D_001A30B0[];
extern void func_003A19D0(s32, s32, s32, s32 *, s32);
void func_003A2CB8(s32 a, long l) {
    u8 *p = (u8 *)(s32)l;
    s32 i;
    if (p == 0) return;
    i = *(s32 *)(p + 0x20);
    *(s32 *)p = a;
    if (i >= 0) { u8 *e = D_001A30B0 + (i << 7); *(s32 *)(e + 0xC0) = a; };
    if (a != 0) {
        if (*(s16 *)(p + 0xA) == 1) *(s16 *)(p + 0xA) = 2;
    } else {
        func_003A19D0(D_1CCFD0.f98, D_1CCFD0.f9C, D_1CCFD0.fB0, &D_1CCFD0.f94, D_1CCFD0.f9A);
    }
}
/* localdecomp:end func_003A2CB8 */

/* localdecomp:start func_003A2D38 */
extern s32 D_001D6DB8;
extern void func_003A1C38(s32, s32, s32);
void func_003A2D38(s32 a, long l) {
    u8 *p = (u8 *)(s32)l;
    if (p == 0) return;
    *(s32 *)p = a;
    if (a != 0) {
        if (*(s16 *)(p + 0xA) == 1) *(s16 *)(p + 0xA) = 2;
    } else if (D_001D6DB8 == 0) {
        func_003A1C38(D_1CCFD0.f48, D_1CCFD0.f4C, D_1CCFD0.f4A);
    } else {
        *(s16 *)(p + 0xA) = 0;
    }
}
/* localdecomp:end func_003A2D38 */

/* localdecomp:start func_003A2DA8 */
extern s16 D_001CCFFC[];
void func_003A2DA8(s32 a0, long a1) {
    u8 *p = (u8 *)(s32)a1;
    if (p != 0) {
        *(s32 *)p = a0;
        if (a0 != 0) {
            if (*(s16 *)(p + 0xA) == 1) {
                *(s16 *)(p + 0xA) = 4;
                if (*(s16 *)(p + 0x10) != 0) {
                    D_001CCFFC[0] = 1;
                }
            }
        } else {
            *(s16 *)(p + 0xA) = 0;
        }
    }
}
/* localdecomp:end func_003A2DA8 */

/* localdecomp:start func_003A2DF8 */
typedef struct { s32 x0; s16 pad4; s16 pad6; s16 pad8; s16 hA; s16 padC; s16 padE; s16 h10; } S_39D970;
extern s16 D_001CCFFC[];
void func_003A2DF8(s32 a, long b) {
    S_39D970 *p = (S_39D970 *)(s32)b;
    if (p) {
        if (a < 0) p->x0 = a;
        if (a != 0) {
            if (p->hA == 9) {
                p->hA = 4;
                if (p->h10) D_001CCFFC[0] = 1;
            }
        } else {
            p->hA = 0;
        }
    }
}
/* localdecomp:end func_003A2DF8 */

/* localdecomp:start func_003A2E50 */
void func_003A2E50(s32 a, long l) {
    u8 *p = (u8 *)(s32)l;
    if (p == 0) return;
    *(s32 *)p = a;
    if (a != 0) {
        if (*(s16 *)(p + 0xA) == 1) *(s16 *)(p + 0xA) = 8;
    } else {
        *(s16 *)(p + 0xA) = 0;
    }
}
/* localdecomp:end func_003A2E50 */

/* localdecomp:start func_003A2E90 */
void func_003A2E90(s32 a, long l) {
    u8 *p = (u8 *)(s32)l;
    if (p == 0) return;
    if (*(u32 *)p == 0xFFFFFFFF) {
        *(s32 *)p = a;
        if (a == 0) *(s16 *)(p + 0xA) = 7;
    }
}
/* localdecomp:end func_003A2E90 */

/* localdecomp:start func_003A2ED0 */
void func_003A2ED0(s32 a0, long a1) {

    s32 *p = (s32 *)(u32)a1;
    if (p != 0) {
        p[5] = a0;
    }
}
/* localdecomp:end func_003A2ED0 */

/* localdecomp:start func_003A2EE8 */
typedef struct { u8 pad[0x10]; s16 h10; u8 pad2[6]; s32 x18; } S_39DA60;
typedef struct { u8 pad[0x2C]; s16 h2C; s16 pad2; s32 x30; s32 x34; } S2_39DA60;
extern S2_39DA60 D_001CCFD0_003A2EE8[];
void func_003A2EE8(s32 a, long b) {
    S_39DA60 *p = (S_39DA60 *)(s32)b;
    if (p) {
        p->x18 = a;
        if (p->h10) {
            S2_39DA60 *d = D_001CCFD0_003A2EE8;
            if (d->h2C == 1 && a != 0) {
                d->h2C = 2;
                d->x30 = p->x18;
                d->x34 = p->x18 / 4;
            }
        }
    }
}
/* localdecomp:end func_003A2EE8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003A2F58);

extern s32 D_001D6DE8[];

/* localdecomp:start func_003A2F68 */
typedef struct {
    u8 pad0[0x24];
    s32 f24;
    s32 f28;
} S_1CCFD0u;
extern S_1CCFD0u D_001CCFD0_003A2F68;
extern s32 D_001D6DE8_003A2F68;
void func_003A2F68(s32 a0, s32 a1) {
    if (D_001D6DE8_003A2F68 == 0) {
        D_001CCFD0_003A2F68.f24 = a0;
        D_001CCFD0_003A2F68.f28 = a1;
    }
}
/* localdecomp:end func_003A2F68 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003A2F88);
