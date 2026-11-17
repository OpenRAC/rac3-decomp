#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_0039EF28();
extern void func_0039FA88();
extern void func_0039E5E0();
extern void func_0039EED8();
typedef struct {
    s32 port;  s32 slot;  s32 type;  s32 free;
    s32 f10;   s32 f14;   s16 f18;   s16 f1A;   s32 f1C;
    s32 f20;   s32 f24;   s32 f28;   s32 f2C;   s32 f30;
    u8 p34[0x18]; s32 f4C; u8 p50[0x18]; s32 f68; u8 p6C[0x18]; s32 f84; u8 p88[0x18];
} MC_397490;
typedef struct {
    MC_397490 c[2];
    s32 f140, f144, f148, f14C, f150, f154, f158, f15C, f160, f164, f168, f16C, f170, f174, f178, f17C, f180, f184, f188;
} S_397490;
extern S_397490 D_142430_0039C410;
extern s32 func_0039E788();
extern void func_0039E8E0();
extern s32 func_0039E998();
/* --- end of declarations from other files --- */

/* localdecomp:start func_0039E5E0 */
extern u8 D_00332388[];
extern u8 D_00332618[];
extern s32 func_0039E6A8();
extern s32 func_0039E7C8();
void func_0039E5E0(u8 *p) {
    s32 i;
    *(s32 *)p = func_0039E6A8(D_00332388);
    *(s32 *)(p + 4) = func_0039E6A8(D_00332618);
    p += 8;
    p += func_0039E7C8(p, 0, D_00332388);
    for (i = 0; i < 0x25; i++) {
        p += func_0039E7C8(p, i, D_00332618);
    }
}
/* localdecomp:end func_0039E5E0 */

/* localdecomp:start func_0039E688 */
extern void func_12DA60(void);
void func_0039E688(void) {
    func_12DA60();
}
/* localdecomp:end func_0039E688 */

/* localdecomp:start func_0039E6A8 */
s32 func_0039E6A8(s32 *p) {
    s32 n = 8;
    if (p[0] != 0) {
        do {
            n += 8;
            n += p[1];
            p += 4;
            n = (n + 3) & ~3;
        } while (p[0] != 0);
    }
    return n + 8;
}
/* localdecomp:end func_0039E6A8 */

/* localdecomp:start func_0039E6E0 */
extern u8 D_00332388[];
u16 func_0039E6E0(u8 *p, u32 n) {
    u8 *end;
    s32 r;
    s32 k;
    if ((u32)func_0039E6A8((s32 *)D_00332388) < n) return 0;
    end = p + n;
    r = 0xEDB88320;
    for (; p < end; p++) {
        r ^= *p << 8;
        for (k = 7; k >= 0; k--) {
            if (r & 0x8000) r = (r << 1) ^ 0x1F45;
            else r = r << 1;
        }
    }
    return r;
}
/* localdecomp:end func_0039E6E0 */

/* localdecomp:start func_0039E788 */
s32 func_0039E6E0_0039E788(void *, s32);

s32 func_0039E788(s32 *arg0) {
    s32 ret = 0;
    s32 v = arg0[1];
    s32 key = arg0[0];

    if (v != 0) {
        ret = func_0039E6E0_0039E788(arg0 + 2, key) == v;
    }
    return ret;
}
/* localdecomp:end func_0039E788 */

/* localdecomp:start func_0039E7C8 */
extern void func_0038CB78(void *, s32, s32);
extern void func_0038CC88();
extern u16 func_0039E6E0(u8 *p, u32 n);
s32 func_0039E7C8(u8 *dst, s32 n, s32 *e) {
    s32 off = 0;
    u8 *p = dst + 8;
    s32 *q;
    s32 t, u, w;
    if (e[0] != 0) {
        q = e;
        do {
            off += 8;
            w = n * q[1];
            u = q[0];
            t = u + w;
            *(s32 *)p = q[2];
            *(s32 *)(p + 4) = q[1];
            p += 8;
            if (q[2] == 0x1770) {
                func_0038CB78(p, 0, q[1]);
            } else {
                func_0038CC88(p, t, q[1]);
            }
            p += q[1];
            off += q[1];
            q += 4;
            p = (u8 *)((s32)p + 3 & ~3);
            off = (off + 3) & ~3;
        } while (q[0] != 0);
    }
    off += 8;
    *(s32 *)(p + 4) = 0;
    *(s32 *)p = -1;
    *(s32 *)(dst + 4) = func_0039E6E0(dst + 8, off);
    *(s32 *)dst = off;
    return off + 8;
}
/* localdecomp:end func_0039E7C8 */

/* localdecomp:start func_0039E8E0 */
typedef struct { u8 b[8]; } V8_399948;
typedef struct { s32 f0, f4, f8, fC; V8_399948 f10; s32 f18; } E_399948;
typedef struct { u8 p0[0x30]; E_399948 e[4]; } R_399948;
extern R_399948 D_00142430_0039E8E0[];
extern s32 func_0039E788();
void func_0039E8E0(u8 *a, s32 i, s32 j) {
    s32 r = func_0039E788(a) == 0;
    a += 0x10;
    D_00142430_0039E8E0[i].e[j].f18 = r;
    D_00142430_0039E8E0[i].e[j].f0 = *(s32 *)a;
    a += 0xC;
    D_00142430_0039E8E0[i].e[j].f4 = *(s32 *)a;
    D_00142430_0039E8E0[i].e[j].f8 = a[0x32];
    a += 0x88;
    D_00142430_0039E8E0[i].e[j].fC = *(s32 *)a;
    *(V8_399948 *)((u8 *)D_00142430_0039E8E0 + 0x40 + j * 0x1C + i * 0xA0) = *(V8_399948 *)(a + 0xC);
}
/* localdecomp:end func_0039E8E0 */

/* func_0039E998: from the US C of func_00399A00 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_0039E998 */
typedef struct { u8 *f0; s32 f4, f8, fC; } E_399A00;
extern s32 D_001D6310;
extern s32 func_0039E788();
extern s32 func_0039E6A8();
extern s32 func_0011A01C();
extern void func_0038CC88();
s32 func_0039E998(u8 *p, u8 *end, s32 idx, E_399A00 *tab) {
    s32 fail, total, i, n;
    u8 *dst, *data;
    s32 *slot;
    s32 val;

    if (func_0039E788(p) == 0) return 1;
    p += 8;
    fail = 0;
    total = 8;
    for (i = 0; tab[i].f0 != 0; i++) tab[i].fC = 0;
    while (p < end && *(s32 *)p != -1) {
        for (i = 0; tab[i].f0 != 0; i++) {
            if (tab[i].f8 == *(s32 *)p) break;
        }
        if (tab[i].f0 != 0) {
            dst = tab[i].f0 + idx * tab[i].f4;
            if (((s32 *)p)[1] == tab[i].f4) {
                tab[i].fC = 1;
                n = tab[i].f4;
            } else if (((s32 *)p)[1] < tab[i].f4) {
                n = ((s32 *)p)[1];
                tab[i].fC = -1;
            } else {
                tab[i].fC = -2;
                n = tab[i].f4;
            }
            data = p + 8;
            if (func_0011A01C(dst, data, n)) D_001D6310++;
            if (tab[i].f8 != 0x1770) {
                func_0038CC88(dst, data, n);
                total += 8 + ((n + 3) & ~3);
            } else {
                total += 8 + ((((s32 *)p)[1] + 3) & ~3);
            }
        } else {
            fail++;
        }
        p += 8 + ((((s32 *)p)[1] + 3) & ~3);
    }
    total += 8;
    if (total != func_0039E6A8(tab)) fail++;
    p += 8;
    for (i = 0; tab[i].f0 != 0 && tab[i].f8 != *(s32 *)p; i++) {
        if (tab[i].fC <= 0) fail++;
    }
    slot = &D_142430_0039C410.c[D_142430_0039C410.f14C].f24;
    val = *slot;
    val += fail;
    *slot = val;
    return fail;
}
/* localdecomp:end func_0039E998 */

extern s32 func_0039EC28(s32, s32);
typedef struct { u8 b[8]; } V8_399C90;
typedef struct { s32 f0, f4, f8, fC; V8_399C90 f10; s32 f18; } E_399C90;
typedef struct { u8 p0[0x18]; s16 h18; u8 p1a[0x16]; E_399C90 e[4]; u8 pA0[0xA8]; s32 f148; s32 f14C; s32 f150; u8 p154[8]; s32 f15C; u8 p160[4]; s32 f164; s32 f168; u8 p16C[0x10]; s32 f17C; } S_399C90;
typedef struct { s32 f0; u8 p4[0x2E]; u8 b32; } T_399C90;
extern S_399C90 D_142430_0039EC28;
extern T_399C90 D_142660_0039EC28;
extern s32 D_001D4CF0;
extern u32 D_001D545C;
extern s32 D_001D5528;
extern s32 D_001D4CEC_0039EC28;
extern V8_399C90 D_1D4BE0;
extern u8 D_1A9318[];
extern u8 D_001D5570[8];
extern u8 D_001C5BD0[];
extern u8 D_001CBBD0[];
extern u8 D_00332388[];
extern u8 D_00332618[];
extern void func_003A0090();
INCLUDE_ASM("asm/nonmatchings/text", func_0039EC28);

extern s32 D_001D4B60[];
extern s32 D_001D4B90[];
extern s32 D_001D4BA0[];
extern u8 D_0016C580[];
/* localdecomp:start func_0039EED8 */
typedef struct { u8 pad[0x18]; s32 a; u8 pad2[0x14]; s32 b; } T_0039EED8;
extern T_0039EED8 D_0016C580_0039EED8;
extern s32 D_001D4B60_0039EED8;
extern s32 D_001D4B90_0039EED8;
extern s32 D_001D4BA0_0039EED8;
__asm__(".extern D_001D4B60_0039EED8, 16");
__asm__(".extern D_001D4B90_0039EED8, 16");
__asm__(".extern D_001D4BA0_0039EED8, 16");
void func_0039EED8(void) {
    s32 m = -1;
    D_001D4B60_0039EED8 = m;
    D_001D4B90_0039EED8 = m;
    D_001D4BA0_0039EED8 = m;
    D_0016C580_0039EED8.b = m;
    D_0016C580_0039EED8.a = m;
}
/* localdecomp:end func_0039EED8 */

/* localdecomp:start func_0039EF08 */
extern u8 D_001D6580;
u8 func_0039EF08(void) { return D_001D6580; }
/* localdecomp:end func_0039EF08 */

/* localdecomp:start func_0039EF10 */
extern u8 D_001D6580;
void func_0039EF10(void) {
    D_001D6580 = 0;
}
/* localdecomp:end func_0039EF10 */

/* localdecomp:start func_0039EF18 */
extern u8 D_001D6580;
void func_0039EF18(void) {
    D_001D6580 = 1;
}
/* localdecomp:end func_0039EF18 */

/* localdecomp:start func_0039EF28 */
typedef struct { u8 pad[0x410]; s32 f410; } S_399F90;
extern S_399F90 D_0022CF80;
extern s32 func_0039F108();
extern s32 func_0039F0C8();
s32 func_0039EF28(void) {
    s32 i = 5;
    s32 j;
    s32 k;
    s32 r;
    for (;;) {
        j = i - 1;
        func_0039EF10();
        r = func_0039F108(D_0022CF80.f410);
        for (k = 0; k < 60; k++) {
            if (k != D_0022CF80.f410) func_0039F108(k);
        }
        i = j;
        if (i < 0) break;
        if (func_0039EF08() == 0) break;
    }
    func_0039F0C8(D_0022CF80.f410);
    return r;
}
/* localdecomp:end func_0039EF28 */

/* localdecomp:start func_0039EFD8 */
typedef struct { s16 f0; u8 p0[0x16]; u16 f18; u8 p1[0x12]; s16 f2c; u8 p2[2]; } E39A040;
extern E39A040 *D_00333AC8_0039EFD8[];
extern u8 D_143B30_0039EFD8[];
extern u8 D_143BF0_0039EFD8[];
extern u8 D_143CB0_0039EFD8[];
extern s32 func_0039F790(u8 *, s32, s32);
extern s32 func_0039F918(u8 *, s32, s32);
void func_0039EFD8(s32 a, s32 b) {
    E39A040 *p = &D_00333AC8_0039EFD8[a][b];
    if (!(p->f18 & 2)) {
        if (p->f2c == 1) {
            func_0039F790(((p->f0 & 0xFF00) >> 8) == 1 ? D_143B30_0039EFD8 : D_143BF0_0039EFD8, a, b);
        } else if (p->f2c == 2) {
            func_0039F918(((p->f0 & 0xFF00) >> 8) == 1 ? D_143B30_0039EFD8 : D_143BF0_0039EFD8, a, b);
            func_0039F790(D_143CB0_0039EFD8, a, b);
        }
    }
}
/* localdecomp:end func_0039EFD8 */

/* localdecomp:start func_0039F0C8 */
/* PAL candidate for func_0039F0C8.
   Retail reaches the destination global through lui $at/sw, not $gp: the
   assembler's expansion of a store to a global it does not know to be small.
   It is declared sized (gcc leaves the store to the assembler as one macro)
   with an `.extern X, 16` hint before its first use (docs/wiki/Matching-Patterns.md) (see func_0039BC70). */

extern s32 D_00333AC8[];
extern s32 D_001D9FC0;
__asm__(".extern D_001D9FC0, 16");

s32 func_0039F0C8(u32 i) {
    s32 r = 0;
    if (i < 0x3C) {
        s32 v = D_00333AC8[i];
        if (v != 0) {
            D_001D9FC0 = v;
            r = 1;
        }
    }
    return r;
}
/* localdecomp:end func_0039F0C8 */

typedef struct { u8 p0[0x8]; s16 h8; s16 hA; s32 fC; s16 h10; u8 p1[2]; s32 f14; u16 f18; u8 p2[0xA]; s32 (*f24)(s32); s32 f28; s16 f2c; s16 f2e; } E_39A170;
extern E_39A170 *D_00333AC8_0039F108[];
extern E_39A170 *D_001D9FC0_0039F108;
extern s32 D_001D9FBC;
extern u8 D_001D5570[8];
extern s32 func_0039F348(s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_0039F108);

/* localdecomp:start func_0039F348 */
typedef struct { s32 p[3]; s32 fC; } E_39A3B0;
extern u8 D_1D5530_0039F348[8];
__asm__(".extern D_1D5530_0039F348, 16");
extern u8 D_142CA0[];
extern u8 D_142D40[];
extern E_39A3B0 D_143230_0039F348[];
extern u8 D_1426E0[];
extern u32 D_142BA0[];
extern u8 D_1BBB18[];
extern u8 D_1D5570[];
extern s32 func_00381D48_0039F348(s32, s32);
s32 func_0039F348(a0, kind, a2)
    s32 a0;
    s16 kind;
    s32 a2;
{
    switch (kind) {
    case 1:
        return D_1D5530_0039F348[a2] != 0;
    case 2:
        return D_142CA0[a2] != 0;
    case 3:
        return D_142D40[a2] != 0;
    case 4:
        if (a2 < 0x72) return D_143230_0039F348[a2].fC != 0;
        return 0;
    case 5:
        if (a2 < 0x72) return D_143230_0039F348[a2].fC >= 2;
        return 0;
    case 6:
        return D_1426E0[a2] != 0;
    case 7:
        if (a2 != 0) return ((s32 (*)())a2)() != 0;
    case 9:
        { u32 w = D_142BA0[(u32)a2 >> 2]; return (w & (1 << (a2 & 0x1F))) != 0; }
    case 8:
        return D_1BBB18[(a2 & 0xFFFF) + (a2 >> 16) * 8] != 0;
    case 10:
        return func_00381D48_0039F348(a0, a2);
    case 11:
        return D_1D5570[a2] != 0;
    case 12:
        break;
    }
    return 0;
}
/* localdecomp:end func_0039F348 */

/* localdecomp:start func_0039F4B0 */
s32 func_0039F4B0(u8 *p) {
    return *p == 0;
}
/* localdecomp:end func_0039F4B0 */

LINKER_REMNANT("asm/remnants", func_0039F4C0);

/* localdecomp:start func_0039F4E8 */
extern u8 D_00142734[];

s32 func_0039F4E8(s32 k) {
    if ((u32)(k - 0x1F) < 5) {
        k -= 0x1E;
        if ((u32)k < 8) {
            return (D_00142734[0] >> k) & 1;
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_0039F4E8 */

/* localdecomp:start func_0039F528 */
extern u8 D_00142734[];
s32 func_0039F528(void) {
    s32 v = D_00142734[0] & 0x1e;
    return v == 0x1e;
}
/* localdecomp:end func_0039F528 */

/* localdecomp:start func_0039F540 */
extern s32 func_0039F4E8();
void func_0039F540(void) {
    func_0039F4E8(0x21);
}
/* localdecomp:end func_0039F540 */

/* localdecomp:start func_0039F560 */
extern s32 func_0039F4E8();
s32 func_0039F560(void) {
    return func_0039F4E8(0x22);
}
/* localdecomp:end func_0039F560 */

extern u8 D_001D5550[];
/* localdecomp:start func_0039F580 */
extern u8 D_001D5550_0039F580;
__asm__(".extern D_001D5550_0039F580, 16");
extern s32 func_0039F560();
s32 func_0039F580(void) {
    s32 r = 0;
    if (D_001D5550_0039F580 != 0) r = func_0039F560() != 0;
    return r;
}
/* localdecomp:end func_0039F580 */

/* localdecomp:start func_0039F5B8 */
extern s32 func_0039F4E8();
void func_0039F5B8(void) {
    func_0039F4E8(0x20);
}
/* localdecomp:end func_0039F5B8 */

/* localdecomp:start func_0039F5D8 */
extern s32 D_001D68B8[2];
extern u8 D_00142CA0[];
extern u32 D_00142C34[];
extern s32 func_0039F678();
extern s32 func_00381C88(s32, s32);
s32 func_0039F5D8(void) {
    s32 i;
    s32 *p;
    if ((D_00142C34[0] & 0x200000) == 0) return 0;
    if (func_0039F678()) return 1;
    i = 0;
    p = D_001D68B8;
    for (; i < 5; i++, p++) {
        if (func_00381C88(*p, -1) && D_00142CA0[*p] == 0) return 1;
    }
    return 0;
}
/* localdecomp:end func_0039F5D8 */

/* localdecomp:start func_0039F678 */
extern u8 D_142CA0[];
extern s32 D_001D68B8[2];
s32 func_0039F678(void) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (D_142CA0[D_001D68B8[i]] == 0) return 0;
    }
    return 1;
}
/* localdecomp:end func_0039F678 */

/* localdecomp:start func_0039F6B8 */
extern u8 D_001427B2[];
 
s32 func_0039F6B8(void) {
    return D_001427B2[0] & 1;
}
/* localdecomp:end func_0039F6B8 */

/* localdecomp:start func_0039F6C8 */
extern u8 D_001427B2[];
 
s32 func_0039F6C8(void) {
    return D_001427B2[0] & 2;
}
/* localdecomp:end func_0039F6C8 */

/* localdecomp:start func_0039F6D8 */
typedef struct { u8 pad[0x25]; u8 f25; u8 pad2[0x0d]; u8 f33; } S_1426E0;
extern S_1426E0 D_001426E0;
s32 func_0039F6D8(void) {
    return D_001426E0.f25 != 0 && D_001426E0.f33 != 0;
}
/* localdecomp:end func_0039F6D8 */

/* localdecomp:start func_0039F700 */
extern s32 D_00142C4C[];
s32 func_0039F700(void) {
    s32 v = D_00142C4C[0] & 0x4000;
    return v != 0;
}
/* localdecomp:end func_0039F700 */

/* localdecomp:start func_0039F718 */
extern u16 D_001A8E74[];
extern u8 D_00142CBF[];
s32 func_0039F718(void) {
    if (D_001A8E74[0] != 0) {
        return D_00142CBF[0] == 0;
    }
    return 0;
}
/* localdecomp:end func_0039F718 */

LINKER_REMNANT("asm/remnants", func_0039F740);

/* localdecomp:start func_0039F748 */
s32 func_0039F748(u8 *p, s32 a, s32 b, s32 i) {
    for (; i < 0x60; i++) {
        if (p[i * 2] - 1 == a && p[i * 2 + 1] == b) return i;
    }
    return -1;
}
/* localdecomp:end func_0039F748 */

/* localdecomp:start func_0039F790 */
extern s32 func_0039F4B0(u8 *);
extern s32 func_0039F748(u8 *, s32, s32, s32);
extern void func_0038CC88(u8 *, u8 *, s32);
s32 func_0039F790(u8 *p, s32 a, s32 b) {
    s32 i;
    s32 j;
    u8 *q;
    for (i = 0; i < 0x5F && !(p[i * 2] - 1 == a && p[i * 2 + 1] == b); i++) {
        j = i * 2;
        q = p + j;
        if (func_0039F4B0(q) == 0) {
            if (func_0039F4B0(q) != 0) continue;
            if ((D_00333AC8_0039EFD8[q[0] - 1][q[1]].f0 & 0xFF) < (D_00333AC8_0039EFD8[a][b].f0 & 0xFF)) continue;
        }
        if (func_0039F748(p, a, b, i) != -1) continue;
        func_0038CC88((u8 *)0x70000000, q, (0x5F - i) * 2);
        q[1] = b;
        q[0] = a + 1;
        func_0038CC88(&p[j + 2], (u8 *)0x70000000, (0x5F - i) * 2);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_0039F790 */

/* localdecomp:start func_0039F918 */
extern s32 func_0039F748(u8 *, s32, s32, s32);
extern void func_0038CC88(u8 *, u8 *, s32);
s32 func_0039F918(u8 *p, s32 a, s32 b) {
    s32 r = func_0039F748(p, a, b, 0);
    if (r >= 0) {
        func_0038CC88(&p[r * 2], &p[r * 2 + 2], (0x5F - r) * 2);
        p[0xBE] = 0;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_0039F918 */

/* localdecomp:start func_0039F978 */
extern u8 D_001426E0_0039F978[];
extern s32 func_0039EF28();
s32 func_0039F978(s32 bit) {
    s32 b = bit % 8;
    s32 i = bit / 8;
    s32 r;
    if ((u32)b < 8) { r = (D_001426E0_0039F978[0x40 + i] >> b) & 1; } else { r = 0; }
    if ((u32)b < 8) { D_001426E0_0039F978[0x40 + i] |= 1 << b; }
    func_0039EF28();
    return r;
}
/* localdecomp:end func_0039F978 */

LINKER_REMNANT("asm/remnants", func_0039FA18);

typedef struct { u8 p0[0xC]; s32 fC; s32 f10; s32 f14; u8 p1[0x10]; s32 f28; } S_39AAF0;
extern S_39AAF0 D_0022CF80_0039FA88;
extern u32 D_001D545C;
extern s32 D_00143140[];
extern void func_0039FB48();
INCLUDE_ASM("asm/nonmatchings/text", func_0039FA88);

LINKER_REMNANT("asm/remnants", func_0039FB38);

/* PAL candidate for func_0039FB48 (US draft rac3-uya-decomp func_0039ABB0).
   The packing loop builds the byte with each new element on the LEFT of the
   OR, like retail: acc[m] | acc[m+1], then acc[m+2] | that, acc[m+3] | that,
   ...  Written as a right-nested expression so gcc keeps the accumulator in
   the right-hand operand (retail: "or $2, $2, $5"). */


/* localdecomp:start func_0039FB48 */
typedef struct { u8 b[0x40]; } T_39ABB0;
extern T_39ABB0 D_001D6CF8;
extern u8 *D_0022CF8C[];
void func_0039FB48(u8 *out) {
    s32 acc[0x80];
    s32 tbl2[16];
    u8 *src;
    u8 *o;
    s32 i, j, k, m;
    src = D_0022CF8C[0];
    o = out;
    *(T_39ABB0 *)tbl2 = D_001D6CF8;
    for (i = 0; i < 0x200; i++) {
        if (i % 4 == 0) func_0038CB78(acc, 0, 0x200);
        for (k = 0; k < 0x80; k += 2) {
            u8 b = *src++;
            acc[k] += tbl2[b & 0xF];
            acc[k + 1] += tbl2[b >> 4];
        }
        if (i % 4 == 3) {
            for (j = 0; j < 0x80; j++) {
                if (acc[j] < 8) acc[j] = 0;
                else acc[j] = 1 << (j % 8);
            }
            for (m = 0; m < 0x80; m += 8) {
                *o++ = (u8)((u8)acc[m + 7] | ((u8)acc[m + 6] | ((u8)acc[m + 5] | ((u8)acc[m + 4] | ((u8)acc[m + 3] | ((u8)acc[m + 2] | ((u8)acc[m] | (u8)acc[m + 1])))))));
            }
        }
    }
    out[0] &= 0xFE;
}
/* localdecomp:end func_0039FB48 */
TEXT_PADDING(2);
