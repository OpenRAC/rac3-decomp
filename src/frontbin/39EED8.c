#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_0039EF28();
extern void func_0039EED8();
/* --- end of declarations from other files --- */

/* declarations of 39E5E0.c's earlier functions */
extern void func_0038CC88();
extern u8 D_001D5570[8];

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
/* localdecomp:start func_0039F108 */
extern void func_0039EF18();
__asm__(".extern D_001D9FC0_0039F108, 16");
__asm__(".extern D_001D5570, 16");
typedef struct { s32 f0; s32 f4; } S_0039F108;
extern S_0039F108 D_001D9FB8_0039F108;
__asm__(".extern D_001D9FB8_0039F108, 16");
static __inline__ u8 isEnd_0039F108(E_39A170 *e) {
    s32 r = 1;
    if (e != 0 && e->h8 != 0) r = 0;
    return r;
}
/* from boot_elf's func_0039F4E8 */
s32 func_0039F108(u32 i) {
    E_39A170 *e, *f, *g;
    s32 j;
    s32 r;
    if (i >= 0x3C) return 0;
    if (D_00333AC8_0039F108[i] == 0) return 0;
    func_0039F0C8(i);
    if (D_001D9FC0_0039F108 == 0) return 0;
    for (j = 0; isEnd_0039F108(e = &D_00333AC8_0039F108[i][j]) == 0; j++) {
        if ((e->f18 & 4) && D_001D5570[i] == 0) {
            e->f2c = 0;
            continue;
        }
        if (func_0039F348(i, e->hA, e->fC) == 0) {
            if (e->f2c != 0) func_0039EF18();
            e->f2c = 0;
            continue;
        }
        if (func_0039F348(i, e->h10, e->f14) == 0) {
            if (e->f2c != 1) {
                e->f2c = 1;
                func_0039EFD8(i, j);
                func_0039EF18();
            }
            continue;
        }
        if (e->f2c != 2) {
            func_0039EF18();
            e->f2c = 2;
            func_0039EFD8(i, j);
        }
    }
    for (j = 0; isEnd_0039F108(f = &D_001D9FC0_0039F108[j]) == 0; j++) {
        if (f->f24 != 0) {
            r = f->f24(f->f28);
            D_001D9FC0_0039F108[j].f2e = r;
        }
    }
    D_001D9FB8_0039F108.f4 = 0;
    for (g = D_001D9FC0_0039F108; isEnd_0039F108(g) == 0; g++) {
        if (g->f2c == 1 && !(g->f18 & 2)) D_001D9FB8_0039F108.f4++;
    }
    return D_001D9FB8_0039F108.f4 == 0;
}
/* localdecomp:end func_0039F108 */

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
