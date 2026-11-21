#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_00381FF0(s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
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
/* localdecomp:start func_003C1600 */
__asm__(".extern D_001D4B4C, 16");
s32 func_003C1600(s32 arg0, s32 arg1) {
    S_BC0F0 *p = D_002D2060;
    S_BC0F0b *q;
    func_0011B754(p->n0, func_00381FF0(0x1645));
    func_0011B754(p->n1, func_00381FF0(0x1646));
    func_0011B754(p->n2, func_00381FF0(0xF07));
    p->f30 = 0;
    q = D_001A4BE0;
    p->f34 = q->f1B14;
    p->f38 = q->f1B1C;
    p->f3C = q->f1B18;
    p->f40 = arg1;
    if (arg1 != 0 && q->f1AF8 != 0) {
        p->f40 = 0;
    }
    D_002D2060->f44 = arg0;
    D_002D2060->f60 = 0;
    func_003BBA08(0, 0);
    if (D_002D2060->f40 == 0) {
        D_002D2060->f48 = 0;
        D_002D2060->f4C = 0x32;
        D_002D2060->f50 = 0;
        D_001D4B4C = 0;
    } else {
        D_002D2060->f48 = 0;
        D_002D2060->f4C = 0x32;
        func_003BC408(3, (s32)&D_001D9088);
    }
    return 1;
}
/* localdecomp:end func_003C1600 */

INCLUDE_ASM("asm/nonmatchings/text", func_003C1728);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C9A0);
