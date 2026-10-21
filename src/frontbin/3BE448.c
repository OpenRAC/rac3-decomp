#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
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
/* --- end of declarations from other files --- */

extern s32 D_001DA2D0_003BE448;
extern u8 D_001DA2D4_003BE448;
extern s32 D_001DA2D8_003BE448;
extern s32 D_001DA2DC_003BE448;
extern s32 D_001D8D28_003BE448;
extern s32 D_001D8D40_003BE448;
extern u8 D_001D8D2C_003BE448[8];
extern u8 D_001D8D44_003BE448[8];
extern s32 D_002FCDC4[];
extern void func_003BBA08(s32, s32);
extern void func_003BC408();
extern void func_003BDCB0(s32, s32 *, s32);
extern s32 func_003BDD38();
extern void func_003BDE20();
extern void func_003BE308();
INCLUDE_ASM("asm/nonmatchings/text", func_003BE448);

/* localdecomp:start func_003BE528 */
extern s32 func_003BE588();
extern void func_003BED78();
void func_003BE528(u8 *p) {
    s32 ok = 0;
    switch (*(s16 *)(p + 0xAA)) {
    case 0x19E9:
        ok = 1;
        *(void **)(p + 0x64) = func_003BE588;
        break;
    case 0x1D98:
        ok = 1;
        *(void **)(p + 0x64) = func_003BED78;
        break;
    }
    if (ok) *(u16 *)(p + 0x34) &= ~2;
    else *(u16 *)(p + 0x34) |= 2;
}
/* localdecomp:end func_003BE528 */

/* localdecomp:start func_003BE588 */
s32 func_003BE588(void) {
}
/* localdecomp:end func_003BE588 */

/* localdecomp:start func_003BE590 */
typedef int Q_3B9098 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9098;
typedef struct { f32 f0, f4, f8, fC, f10; u8 b14, b15; } Sub_3B9098;
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 b8;
    u8 pad9;
    u8 hA[2];
    f32 fC;
    V4_3B9098 v10;
    Sub_3B9098 s20;
} S_3B9098;
extern s32 func_0038CB00(void *);
extern void func_003CD250(s32);
void func_003BE590(S_3B9098 *p) {
    Sub_3B9098 *s;
    V4_3B9098 v;
    Q_3B9098 a, b;
    if (func_0038CB00(p->hA)) {
        func_003CD250((s32)p);
        return;
    }
    s = &p->s20;
    p->w4 = (p->w4 & 0xFFFFFF) | (((p->w4 >> 24) + s->b14) << 24);
    v.w = 0;
    v.x = s->f0;
    v.y = s->f4;
    v.z = s->f8;
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(p->v10));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(p->v10) : "j"(a));
    s->f8 -= s->fC;
    p->b8 += s->b15;
    p->fC += s->f10;
}
/* localdecomp:end func_003BE590 */

typedef int u128_3B9160 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, fC, f10;
    u8 b14, b15;
    u8 pad16[6];
    void *f1C;
} Q_3B9160;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 x4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    u128_3B9160 v10;
    Q_3B9160 q;
} P_3B9160;
extern void *func_003CD108(s32);
extern s32 func_00382468(s32);
extern u8 *D_002FCF20[];
INCLUDE_ASM("asm/nonmatchings/text", func_003BE658);

typedef struct { f32 f0, f4, f8, fC, f10; u8 b14, b15; u8 pad16[6]; void *f1C; } Sub_3B9160;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    u16 hA;
    f32 fC;
    Q_3B9160 q10;
    Sub_3B9160 s20;
} S_3B9160;
typedef int Q_3B92B8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B92B8;
extern void func_0038CF68(s32, s32, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE38(void *, void *, f32);
extern f32 func_0038D098(f32);
extern s32 func_00382468();
extern f32 func_003824E0(f32, f32);
extern S_3B9160 *func_003BE658(Q_3B9160 *, f32 *, s32, s32, s32, s32, s32, f32, f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003BE7B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEC28);

/* localdecomp:start func_003BED78 */
extern void func_003BEDB0_003BED78();
extern void func_00389F18();
extern void func_003BEC28(void *);
void func_003BED78(void *p) {
    func_00389F18(func_003BEDB0_003BED78, p);
    func_003BEC28(p);
}
/* localdecomp:end func_003BED78 */

/* func_003BEDB0: from the US C of func_003B98B8 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_003BEDB0 */
extern s32 D_001D9348_003BEDB0;
__asm__(".extern D_001D9348_003BEDB0, 16");
typedef struct { u8 b[8]; } V8_3B98B8;
typedef struct { u128_t q[4]; } M4_3B98B8;
extern V8_3B98B8 D_001D8D80[];
extern M4_3B98B8 D_001D8D90[];
__asm__(".extern D_001D8DD0, 1");
extern u8 D_001D8DD0;
extern s32 D_001D9348;
/* Retail writes this address through lui $at/lo, not through $gp: the store
   goes through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did); the read keeps the sized global, through $gp. */
extern void func_003C2FE8();
extern void func_003D9450();
extern void func_003D2DA0();
void func_003BEDB0(void *p) {
    V8_3B98B8 v;
    u8 buf[0x80];
    M4_3B98B8 m;
    u8 out[0x90];
    s32 i;
    u8 *r;
    u8 *b = buf;
    v = D_001D8D80[0];
    func_003C2FE8(p, 2, &v, b);
    r = b;
    m = D_001D8D90[0];
    for (i = 1; i >= 0; i--) {
        func_003D9450(out, 0x16, 0x80808080, &D_001D8DD0, &m, 1);
        func_003D2DA0(out, r, 0);
        r += 0x40;
    }
    D_001D9348_003BEDB0 = D_001D9348 | 1;
}
/* localdecomp:end func_003BEDB0 */

extern u8 D_001DA2D4[];
extern u8 D_001DA300[];
extern s32 D_001D9364[];
u8 func_003BDBF8(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003BEE98);

extern u8 D_001DA2D4_003BEF00;
extern volatile u8 D_001DA300_003BEF00;
extern s32 D_001DA2D0;
extern s32 D_001D8D28;
extern s32 D_001D8D40;
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 h40; } S_3B9A08;
extern S_3B9A08 D_00225700_003BEF00;
extern void func_003BC768();
extern s32 func_003BDF10();
extern s32 func_003BDF18();
extern void func_003BE168();
extern void func_003BB968();
extern s32 func_003BDD38();
extern void func_003BDE60();
extern void func_003BE308();
extern void func_003BDF40();
extern void func_00387EF0();
extern void func_003BDF60();
INCLUDE_ASM("asm/nonmatchings/text", func_003BEF00);

/* localdecomp:start func_003BF030 */
extern void func_003BDF40();
extern void func_003BC768();
 
void func_003BF030(void) {
    func_003BDF40();
    func_003BC768();
}
/* localdecomp:end func_003BF030 */

extern u8 D_001DA310;
extern u8 D_001DA311;
extern s32 D_001D8DF0;
extern s32 D_001D8DF4;
extern void *D_002FCC40;
extern void func_003BBA08(s32, s32);
extern void func_003BC408();
extern void func_003BDCB0(s32, s32 *, s32);
extern s32 func_003BDD38(void);
extern void func_003BDE20(s32);
extern void func_003BF2A0();
extern void func_003BF0E0();
extern void func_003BE308(void *);
extern void func_003BE1F8(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003BF058);

typedef struct { u8 pad[0x34]; u16 h34; u8 pad2[0x74]; s16 hAA; } S_3B9BE8;
extern s32 D_001D4B60[];
extern u8 func_00381CB0(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003BF0E0);

typedef int Q_3B9C50 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9C50;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    u8 padA[2];
    s32 wC;
    Q_3B9C50 q10;
    V4_3B9C50 v20;
    Q_3B9C50 q30;
} S_3B9C50;
typedef struct { u8 pad[4]; u8 b4; } T_3B9C50;
extern f32 D_001D8E00;
extern f32 D_001D8E04;
extern s32 D_001D8E08;
extern s32 D_001D8E0C;
extern s32 D_001D8E10;
extern s32 D_001D8E14;
extern s32 D_001D8E18;
extern s32 D_001D8E1C;
extern f32 D_001D8E20;
extern u8 D_001D8E24;
extern u8 D_001D8E28;
extern T_3B9C50 *D_002FD004[];
extern void *func_003CD108(s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CF68(s32, s32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003BF148);

typedef int Q_3B9DA8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9DA8;
typedef struct {
    u8 pad0[0x10];
    V4_3B9DA8 v10;
    V4_3B9DA8 v20;
    V4_3B9DA8 v30;
} S_3B9DA8;
extern void func_003CD250(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003BF2A0);

typedef int Q_3B9E98 __attribute__((mode(TI)));
typedef struct { V4_3B9C50 a; V4_3B9C50 b; } E_3B9E98;
extern s32 func_003C2B88_003BF390(void *, s32);
extern S_3B9C50 *func_003BF148(V4_3B9C50 *, V4_3B9C50 *);
extern void func_00382580(V4_3B9C50 *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CDF8(void *, void *, void *, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003BF390);

/* localdecomp:start func_003BF5B0 */
extern s32 func_003BDEF0(void);
extern void func_003BF390(void *a);
void func_003BF5B0(void *a) {
    if (func_003BDEF0() == 2) return;
    if (func_003BDEF0() == 3) return;
    func_003BF390(a);
}
/* localdecomp:end func_003BF5B0 */

/* func_003BF600 (PAL), from the US draft of rac3-uya-decomp func_003BA108 (commit 13cf5c5).
   PAL fixes over the US draft: the byte global is at 0x1DA311 (US 0x1DA391), and the
   last two arguments of func_003BDF60 are 12, 12 (US 15, 15). */


/* localdecomp:start func_003BF600 */
/* The flag pair at 0x1DA310: retail reaches the second byte with `lui` (the assembler's
   expansion), so the pair is declared sized (gcc leaves the accesses to the assembler as
   macros) with an `.extern X, 16` hint before its first use (docs/wiki/Matching-Patterns.md). The first byte goes through $gp, as the plain D_001DA310. */
extern u8 D_001DA310_003BF600[2];
__asm__(".extern D_001DA310_003BF600, 16");
typedef struct { u8 p0[0x34]; s32 w34; u8 p38[8]; s16 h40; u8 p42[0x15E]; s32 w1A0; } S_3BA108;
extern S_3BA108 D_00225700_003BF600[];
extern u32 D_001DA49C;
extern u32 D_001DA4A0;
extern u8 D_001DA310;
extern s32 D_001D8DF0;
extern void func_003C7DD8();
extern void func_003BC768();
extern s32 func_003BDF10();
extern s32 func_003BDF18();
extern void func_003BB968();
extern void func_003BE168();
extern s32 func_003BDD38();
extern void func_003BDE60();
extern void func_003BE308();
extern void func_003BDF40();
extern void func_00387EF0();
extern void func_003BF0E0();
extern void func_003BDF60();
extern void func_003BF5B0();
__asm__(".extern D_001DA49C, 16");
__asm__(".extern D_001DA4A0, 16");
s32 func_003BF600(s32 a) {
    u32 p;
    s32 r;
    u8 t;
    S_3BA108 *g;
    r = 0;
    for (p = D_001DA49C; p < D_001DA4A0; p += 0x100) {
        func_003C7DD8(p);
    }
    D_001DA310 = func_003BDBF8();
    if (D_001DA310 != 0) {
        func_003BC768();
        if (func_003BDF10() == 1) {
            func_003BE168();
        }
        if (func_003BDF10() > 0 && func_003BDF18() != 0) {
            func_003BB968();
        }
        t = D_001DA310_003BF600[1];
        if (a != 0) { if (t != 0) r = 1; }
        if (t == 0) {
            s32 v4;
            if (func_003BDF10() > 0 && a != 0) {
                v4 = D_001D8DF0;
                D_001DA310_003BF600[1] = 1;
            } else {
                v4 = func_003BDD38();
            }
            func_003BDE60(v4);
            func_003BE308(func_003BF0E0);
            func_003BDF40();
            func_00387EF0();
        }
    }
    g = D_00225700_003BF600;
    if (g->w1A0 != 0) func_003BF5B0(g->w1A0);
    func_003BDF60(g->w34, g->h40, 12, 12);
    return r;
}
/* localdecomp:end func_003BF600 */

/* localdecomp:start func_003BF778 */
extern void func_003BDF40();
extern void func_003BC768();
 
void func_003BF778(void) {
    func_003BDF40();
    func_003BC768();
}
/* localdecomp:end func_003BF778 */

extern f32 D_001DA340;
extern s32 D_001DA338;
extern u8 D_001DA33C;
extern u8 D_001DA344[2];
extern s32 D_001D8E30;
extern u8 D_001D8E34[];
extern void *D_002FCDA4[];
extern void func_003BBA08(s32, s32);
extern void func_003BC408();
extern s32 func_003BDD38(void);
extern void func_003BDE20(s32);
extern void func_003BE308(void *);
extern void func_003BF860();
extern void func_003BFC58();
INCLUDE_ASM("asm/nonmatchings/text", func_003BF7A0);

/* localdecomp:start func_003BF848 */
extern s32 D_0016C5E4[];
s32 func_003BF848(void) {
    return D_0016C5E4[0] == 1;
}
/* localdecomp:end func_003BF848 */

/* US draft of func_003BF860 (rac3-uya-decomp func_003BA368, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: unmapped symbols: func_003BB210. */


/* localdecomp:start func_003BF860 */
typedef struct { u8 pad[0x34]; u16 h34; u8 pad2[0x2E]; void *x64; u8 pad3[0x42]; s16 hAA; } S_3BA368;
extern void func_003C0720();
extern void func_003BFD60(S_3BA368 *p);
void func_003BF860(S_3BA368 *p) {
    s32 r = 0;
    if (p->hAA == 0x1E01) {
        p->x64 = func_003C0720;
        func_003BFD60(p);
        r = 1;
    }
    if (r) p->h34 &= ~2;
    else p->h34 |= 2;
}
/* localdecomp:end func_003BF860 */

/* localdecomp:start func_003BF8C0 */
extern void func_003A8220(void *);
extern u8 D_0031D130[];
 
void func_003BF8C0(void) {
    func_003A8220(D_0031D130);
}
/* localdecomp:end func_003BF8C0 */

/* localdecomp:start func_003BF8E0 */
extern u8 *D_001D6EEC[];
void func_003BF8E0(s32 a0, u8 *src) {
    u8 *p;
    s32 i;
    if (D_001D6EEC[0] == 0) return;
    p = D_001D6EEC[0];
    i = 0;
    do {
        i++;
        if (*(s32 *)(p + 0x48) == 0) {
            *(s32 *)(p + 0x38) = *(s32 *)(src + 0x38);
            *(s32 *)(p + 0x3C) = *(s32 *)(src + 0x3C);
            *(s32 *)(p + 0x30) = *(s32 *)(src + 0x30);
            *(s32 *)(p + 0x44) = *(s32 *)(src + 0x44);
            *(f32 *)(p + 0x24) = *(f32 *)(src + 0x24);
            *(f32 *)(p + 0x20) = *(f32 *)(src + 0x20);
            *(f32 *)(p + 0x28) = *(f32 *)(src + 0x28);
            *(s32 *)(p + 0x34) = *(s32 *)(src + 0x34);
            *(s32 *)(p + 0x2C) = *(s32 *)(src + 0x2C);
            *(s32 *)(p + 0x40) = *(s32 *)(src + 0x40);
            *(s32 *)(p + 0x4C) = *(s32 *)(src + 0x4C);
            *(u128_t *)(p + 0) = *(u128_t *)(src + 0);
            *(u128_t *)(p + 0x10) = *(u128_t *)(src + 0x10);
            *(s32 *)(p + 0x48) = a0;
            return;
        }
        p += 0x50;
    } while (i < 0x15E);
}
/* localdecomp:end func_003BF8E0 */

INCLUDE_ASM("asm/nonmatchings/text", func_003BF988);

typedef int u128_3BA490 __attribute__((mode(TI)));
typedef struct {
    u128_3BA490 a;
    u128_3BA490 b;
    f32 f20, f24, f28;
    s32 x2C, x30, x34, x38, x3C, x40, x44, x48, x4C;
} P_3BA490;
extern void func_003A8308(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern s32 func_0038DBD8(s32, s32, f32);
typedef int Q_3BA5B8 __attribute__((mode(TI)));
typedef struct { u8 pad[0x10]; Q_3BA5B8 q10; u8 pad20[0x12]; s16 h32; } B_3BA5B8;
typedef struct {
    B_3BA5B8 *b;
    s32 w4;
    f32 f8;
    u8 bC, bD, bE, bF;
    union { Q_3BA5B8 q; f32 f[4]; } q10;
} Sub_3BA5B8;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    u16 hA;
    f32 fC;
    Q_3BA5B8 q10;
    Sub_3BA5B8 s20;
} S_3BA5B8;
extern void *func_003CD108(s32);
extern s32 func_00382468();
extern u8 *D_002FCFFC[];
extern void func_0038D000(void *, void *, void *);
INCLUDE_ASM("asm/nonmatchings/text", func_003BFAC8);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BA748;
typedef int Q_3BA748 __attribute__((mode(TI)));
typedef struct { s8 p0[0x20]; s8 b20; } O_3BA748;
typedef struct { O_3BA748 *obj; s32 f4; u8 p8[5]; u8 b0D; u8 pE[2]; V_3BA748 v10; } B_3BA748;
typedef struct { u8 p0[4]; s32 f4; u8 b8; u8 p9; s16 h0A; f32 fC; V_3BA748 v10; B_3BA748 b; } P_3BA748;
extern s32 func_0038CB00();
extern void func_003CD250(s32);
extern void func_0038D000(void *, void *, void *);
INCLUDE_ASM("asm/nonmatchings/text", func_003BFC58);

extern u8 *D_001DA31C_003BFD60[2];
extern u8 D_00380060[];
typedef struct { u8 p[0x1C]; f32 f1C; } S_3BA850;
extern u8 D_001DA318[8];
extern f32 D_001D8E64;
extern s32 D_001D8E68;
extern f32 D_001D8E6C;
extern f32 D_001D8E70;
extern u8 *func_003BFAC8(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003BFD60);

extern s32 D_001DA31C[];
extern void func_003CD250(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003BFE58);

typedef int Q_3BA9A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BA9A0;
typedef struct { f32 x, y; } V2_3BA9A0;
typedef struct { f32 v[3]; } V3_3BA9A0;
typedef struct { u8 pad[8]; u8 b8; } O_3BA9A0;
extern s32 D_001D8ED8;
extern s32 D_001D8EDC;
extern s32 D_001D8EF0;
extern s32 D_001D8EC0;
extern s32 D_001D8EC4;
extern s32 D_001D8F10;
extern f32 D_001D8EE0;
extern s32 D_001D8F50;
extern f32 D_001D8ED0;
extern f32 D_001D8ED4;
extern s32 D_001D8EC8;
extern s32 D_001D8ECC;
extern s32 D_001D8F70;
extern s32 D_001D8F00_003BFEB0;
extern V4_3BA9A0 D_003800C0[];
extern O_3BA9A0 *D_001DA318_003BFEB0;
extern V2_3BA9A0 D_001DA390_003BFEB0;
extern s32 D_001DA348_003BFEB0;
extern s32 D_001DA378_003BFEB0;
extern V4_3BA9A0 D_00222420[];
extern V4_3BA9A0 D_00222400[];
extern s32 D_001D9D00;
extern f32 D_001DA340;
extern void func_003A9440(s32, unsigned long);
extern void func_0038C750(void);
extern s32 func_00382468();
extern void func_0038D028();
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(f32 *, void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_0038CC88();
extern long func_00389598(s32);
extern void func_003D3A24();
extern f32 func_0038CF00(void *, void *);
INCLUDE_ASM("asm/nonmatchings/text", func_003BFEB0);

typedef int Q_3BAE98 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BAE98;
extern f32 D_001D8E60;
extern f32 D_001D8FC8;
extern s32 D_001D8F94;
extern s32 D_001D8E80;
extern s32 D_001D8F9C;
extern s32 D_001D8F98;
extern f32 D_001D8FA0;
extern f32 D_001D8FA4;
extern f32 D_001D8FA8;
extern f32 D_001D8FAC;
extern f32 D_001D8FB8;
extern f32 D_001D8FBC;
extern f32 D_001D8FC0;
extern f32 D_001D8FC4;
extern s32 D_001D8FB0;
extern s32 D_001D8FB4;
extern s32 D_001D8F90;
extern f32 D_001DA334;
extern s32 D_001D9D00;
extern void func_003A9440(s32, unsigned long);
extern void func_0038C750(void);
extern void func_0038D028();
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003D9740(void *, s32, s32, s32, s32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003C03A8);

INCLUDE_ASM("asm/nonmatchings/text", func_003C0720);

/* US draft of func_003C08A8 (rac3-uya-decomp func_003BB398, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003C08A8 */
/* The flag pair at 0x1DA344: retail reaches both bytes with `lui` (the assembler's
   expansion), so the pair is declared sized (gcc leaves the accesses to the assembler as
   macros) with an `.extern X, 16` hint before its first use (docs/wiki/Matching-Patterns.md). The first byte's store stays a literal address: as a plain symbol gcc counts
   it as one instruction and moves it into the following branch's delay slot, where retail
   (and gcc, for a constant address) keeps the two-instruction `lui $at` store before it. */
extern u8 D_001DA344_003C08A8[2];
__asm__(".extern D_001DA344_003C08A8, 16");
__asm__(".extern D_001DA338_003C08A8, 16");
extern s32 D_001DA338_003C08A8;
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 f40; } T_3BB398;
extern T_3BB398 D_00225700[];
extern void func_003BC768();
extern void func_003BE168();
extern void func_003BB968();
extern void func_003BDE60();
extern void func_003BDF40();
extern void func_003BFE58();
extern s32 func_003BDF10();
extern s32 func_003BDF18();
u8 func_003BDBF8(void);
s32 func_003C08A8(s32 a) {
    s32 r = 0;
    s32 arg;
    u8 t;
    s32 v;
    v = func_003BDBF8();
    *(u8 *)0x1DA344 = v;
    if ((v & 0xFF) != 0) {
        func_003BC768();
        if (func_003BDF10() == 1) func_003BE168();
        if (func_003BDF10() > 0 && func_003BDF18() != 0) func_003BB968();
        t = D_001DA344_003C08A8[1];
        if (a) { if (t != 0) r = 1; }
        if (t == 0) {
            if (func_003BDF10() > 0 && a) {
                arg = D_001D8E30;
                D_001DA344_003C08A8[1] = 1;
            } else {
                arg = func_003BDD38();
            }
            func_003BDE60(arg);
            func_003BDF40();
            func_003BF8C0();
            func_003BFE58();
            func_003BE308(func_003BF860);
        }
    }
    func_003BDF60(D_00225700[0].f34, D_00225700[0].f40, 12, 12);
    D_001DA338_003C08A8 = D_001DA338_003C08A8 + 1;
    return r;
}
/* localdecomp:end func_003C08A8 */

/* localdecomp:start func_003C09E8 */
extern void func_003A8450();
extern s32 func_003BF848(void);
extern void func_003BFEB0(void *);
extern void func_003C03A8(void *);
void func_003C09E8(void *p) {
    func_003A8450(p);
    if (func_003BF848()) func_003BFEB0(p);
    func_003C03A8(p);
}
/* localdecomp:end func_003C09E8 */

/* localdecomp:start func_003C0A30 */
extern void func_003BDF40();
extern void func_003BC768();
extern void func_003BFE58();
 
void func_003C0A30(void) {
    func_003BDF40();
    func_003BC768();
    func_003BFE58();
    func_003BF8C0();
}
/* localdecomp:end func_003C0A30 */

/* US draft of func_003C0A68 (rac3-uya-decomp func_003BB558, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003C0A68 */
typedef struct { u8 pad[0x40]; s32 w40; s32 w44; } S_3BB558;
extern S_3BB558 D_002D1FC0[];
extern void func_003BBA08(s32, s32);
extern s32 func_00381FF0(s32); extern s32 func_11BB58(void *, s32, s32);
extern void func_003BE008(f32);
s32 func_003C0A68(void) {
    func_003BBA08(0, 0);
    func_11BB58(D_002D1FC0, func_00381FF0(0x14D7), 0x40);
    D_002D1FC0[0].w40 = 0x96;
    D_002D1FC0[0].w44 = 0;
    func_003BE008(1.0f);
    return 1;
}
/* localdecomp:end func_003C0A68 */

extern s32 func_0038CAD0();
extern s32 func_003BDF18();
extern void func_003BB968();
INCLUDE_ASM("asm/nonmatchings/text", func_003C0AD0);

extern s32 D_001D4BC0;
extern u8 D_002D1FC0_003C0C40[];
extern void func_00389240();
extern void func_00390F50(s32, s32, unsigned long, u8 *, s32, f32);
extern void func_00389370();
INCLUDE_ASM("asm/nonmatchings/text", func_003C0C40);

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
