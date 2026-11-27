#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 39A6E0.c's earlier functions */
typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad1[0x150];
    s32 f164;
    s32 f168;
    u8 pad2[0x10];
    s32 f17c;
} S_142430;
extern S_142430 D_00142430;
extern s32 D_001D4CE8_g;
extern s32 D_001D4CEC_g;
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, rest:17; } F_4CEC;
extern s32 D_00142438[];
extern void func_0039C028(void);
extern u16 D_001D6308;
extern s32 D_001D4CEC[];

typedef struct { u8 p0[8]; s32 f8; u8 p1[4]; s32 f10; u8 p2[0x15C-0x14]; s32 f15C; u8 p3[4]; s32 f164; u8 p4[4]; s32 f16C; u8 p5[0x17C-0x170]; s32 f17C; } S_396CE8;
extern S_396CE8 D_142430_0039BAD8[];
extern s32 D_001D4CE8_0039BAD8;
extern s32 D_001D4CEC_0039BAD8;
#define P D_142430_0039BAD8[0]
/* localdecomp:start func_0039BAD8 */
extern s32 D_001D4CE8_0039BAD8_lui;
__asm__(".extern D_001D4CE8_0039BAD8_lui, 16");
void func_0039BAD8(void) {
    S_396CE8 *p = D_142430_0039BAD8;
    if (p->f15C != 2) return;
    if (p->f164 >= 0) return;
    if (p->f16C != 0 || (p->f8 == 2 && p->f10 != 0)) {
        p->f17C = 0;
        D_001D4CE8_0039BAD8_lui = 3;
        D_001D4CEC_0039BAD8 = (D_001D4CEC_0039BAD8 & 0x40) | 1;
    } else {
        D_142430_0039BAD8[0].f17C = 1;
        D_001D4CE8_0039BAD8_lui = 1;
    }
}
/* localdecomp:end func_0039BAD8 */

typedef struct { u32 b0:5; u32 f5:1; u32 b6:7; u32 f13:1; u32 rest:18; } S_396D70;
extern s32 D_00142438[];
extern s32 D_001D4CE8_0039BB60;
extern union { s32 i; S_396D70 b; } D_001D4CEC_0039BB60;
/* localdecomp:start func_0039BB60 */
/* func_0039BB60: sized small-data scalars through $gp, the two stores through lui/%lo (alias with size hint). */
__asm__(".extern D_001D4CE8_0039BB60, 16");
__asm__(".extern D_001D4CEC_0039BB60, 16");
void func_0039BB60(void) {
    if (D_00142438[0] != 2) { D_001D4CE8_g = 4; return; }
    if (D_001D4CEC_g & 0x2020) {
        D_001D4CE8_0039BB60 = 7;
        D_001D4CEC_0039BB60.i = D_001D4CEC_g & ~0x20;
        D_001D4CEC_0039BB60.i = D_001D4CEC_0039BB60.i & ~0x2000;
    }
}
/* localdecomp:end func_0039BB60 */

/* PAL candidate for func_0039BBB8 (US draft of rac3-uya-decomp func_00396DC8).

   Retail reaches 0x1D4CE8/0x1D4CEC twice each: through $gp in the branch
   delay slots, and with the assembler's lui $at macro for the two stores at
   the end.  One symbol can only have one form, so each address gets two
   names: the sized scalar (D_001D4CE8_g / D_001D4CEC_g) stays in $gp, and
   the per-function alias with the .extern size hint is not small, so the
   assembler expands it to lui $at + sw.  */

/* localdecomp:start func_0039BBB8 */
typedef struct { char pad0[8]; s32 x8; } S_396DC8;
extern S_396DC8 D_00142430_0039BBB8;
extern s32 D_001D4CE8_0039BBB8;
extern s32 D_001D4CEC_0039BBB8;
__asm__(".extern D_001D4CE8_0039BBB8, 16");
__asm__(".extern D_001D4CEC_0039BBB8, 16");
extern s32 D_001D4CE8_g;
extern s32 D_001D4CEC_g;
void func_0039BBB8(void) {
    if (D_00142430_0039BBB8.x8 != 2) { D_001D4CE8_g = 4; return; }
    if (D_001D4CEC_g & 0x2020) {
        D_001D4CE8_0039BBB8 = 0xE;
        D_001D4CEC_0039BBB8 = D_001D4CEC_g & ~0x20;
        D_001D4CEC_0039BBB8 = D_001D4CEC_0039BBB8 & ~0x2000;
    }
}
/* localdecomp:end func_0039BBB8 */

/* localdecomp:start func_0039BC10 */
extern s32 D_00142438_0039BC10[];
extern u32 D_001D4CEC_0039BC10;
extern s32 D_001D4CE8_0039BC10;
extern void func_0039C028(void);
__asm__(".extern D_001D4CEC_0039BC10, 16");
__asm__(".extern D_001D4CE8_0039BC10, 16");
void func_0039BC10(void) {
    s32 v;
    if (D_00142438_0039BC10[0] != 2) {
        v = 4;
    } else {
        u32 f = D_001D4CEC_0039BC10;
        if (f & 0x20) {
            func_0039C028();
            v = 0x12;
        } else if (f & 0x2000) {
            v = 0x1D;
        } else {
            return;
        }
    }
    D_001D4CE8_0039BC10 = v;
}
/* localdecomp:end func_0039BC10 */

/* func_0039BC70: from the US C of func_00396E80 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags.

   PAL candidate.  Retail reaches 0x1D4CEC through $gp for the load but through lui/%lo for
   the store, and reaches 0x1D9FA8 through lui/%lo too: the load keeps a sized (small data)
   declaration; the stores go through `lui $at`, the assembler's expansion of a store to a
   global it does not know to be small (SN's single-pass Ps2EeAs had not seen their sizes
   yet). Those globals are declared sized (gcc leaves the store to the assembler as one macro)
   with an `.extern X, 16` hint before its first use (docs/wiki/Matching-Patterns.md). */


/* localdecomp:start func_0039BC70 */
typedef struct { u8 pad0[0x10]; s32 f10; u8 pad14[0x148 - 0x14]; s32 f148; } S_396E80;
extern S_396E80 D_00142430_0039BC70[];
__asm__(".extern D_001D62FC_0039BC70, 4");
__asm__(".extern D_001D6300_0039BC70, 4");
__asm__(".extern D_001D62F4, 4");
__asm__(".extern D_001D62F8_0039BC70, 4");
__asm__(".extern D_001D6304_0039BC70, 4");
__asm__(".extern D_001D9FA0, 1");
extern s32 D_001D62FC_0039BC70;
extern s32 D_001D6300_0039BC70;
extern s32 D_001D62F4;
extern s32 D_001D62F8_0039BC70;
extern s32 D_001D6304_0039BC70;
extern s8 D_001D9FA0;
extern s32 D_001D4CEC_g;
extern s32 D_001D4CEC_0039BC70;
extern s8 D_001D9FA8;
__asm__(".extern D_001D4CEC_0039BC70, 16");
__asm__(".extern D_001D9FA8, 16");
extern s32 func_0039BE48();
extern void func_0039C028(void);
s32 func_0039BC70(s32 a, s32 b) {
    s32 r = func_0039BE48(a);
    if (r) {
        S_396E80 *p = D_00142430_0039BC70;
        s32 f = D_001D4CEC_g;
        f |= 0x10;
        f &= -5;
        f &= -3;
        f &= -0x41;
        D_001D4CEC_0039BC70 = f;
        D_001D6304_0039BC70 = b;
        p->f148 = 0;
        p->f10 = 0;
        D_001D62F4 = 0;
        D_001D62F8_0039BC70 = 0;
        D_001D62FC_0039BC70 = 0;
        D_001D6300_0039BC70 = 0;
        D_001D9FA8 = 0;
        D_001D9FA0 = 0;
        func_0039C028();
    }
    return r;
}
/* localdecomp:end func_0039BC70 */

typedef struct { u8 pad[0x10]; s32 x10; u8 padA[0x134]; s32 x148; } S_a;
extern void func_0039C028(void);
extern s32 D_001D62F4;
extern s32 D_001D62F8_0039BD08;
extern s32 D_001D6308_0039BD08;
extern s32 D_001D62FC_0039BD08;
extern s32 D_001D6300_0039BD08;
extern s32 D_001D6304_0039BD08;
extern s8 D_001D9FA0;
extern s32 D_001D4CEC_0039BD08;
extern s8 D_001D9FA8;
extern S_a D_00142430_0039BD08[];
/* localdecomp:start func_0039BD08 */
__asm__(".extern D_001D62F4, 4");
__asm__(".extern D_001D62F8_0039BD08, 4");
__asm__(".extern D_001D6308_0039BD08, 4");
__asm__(".extern D_001D62FC_0039BD08, 4");
__asm__(".extern D_001D6300_0039BD08, 4");
__asm__(".extern D_001D6304_0039BD08, 4");
__asm__(".extern D_001D9FA0, 1");
__asm__(".extern D_001D4CEC_0039BD08, 16");
extern u8 D_001D9FA8_0039BEA8;
__asm__(".extern D_001D9FA8_0039BEA8, 16");
void func_0039BD08(s32 arg0, s32 arg1, s32 arg2) {
    S_a *p = D_00142430_0039BD08;
    s32 v;
    D_001D62F4 = arg0;
    D_001D62F8_0039BD08 = arg2;
    D_001D6308_0039BD08 = arg1;
    p->x148 = 0;
    D_001D62FC_0039BD08 = 0;
    D_001D6300_0039BD08 = 0;
    D_001D6304_0039BD08 = 0;
    D_001D9FA8_0039BEA8 = 0;
    D_001D9FA0 = 0;
    func_0039C028();
    v = D_001D4CEC_0039BD08;
    v &= ~4;
    p->x10 = 0;
    v |= 2;
    v &= ~0x40;
    v &= ~0x10;
    v &= ~0x4000;
    D_001D4CEC_0039BD08 = v;
}
/* localdecomp:end func_0039BD08 */

/* localdecomp:start func_0039BD90 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern s32 D_001D4CEC_0039BD90_lui;
__asm__(".extern D_001D4CEC_0039BD90_lui, 16");
/* PAL candidate for func_0039BD90 (frontbin).

   Retail reaches the flags word at 0x001D4CEC with lui/%lo on both sides:
   the load with the high half in the register it loads into (the assembler's
   expansion, as in func_0039BE90 / func_0039C060), the store with lui $at
   (the .extern size hint keeps the global out of the small data area, so the
   assembler expands the reference, as in func_0039BBB8 / func_0039BC70). */

extern void func_0039BD08();
extern s32 D_001D4CEC_0039BD90;
__asm__(".extern D_001D4CEC_0039BD90, 16");
void func_0039BD90(void *a, s32 b, void *c) {
    s32 t;
    func_0039BD08(a, b, c);
    t = D_001D4CEC_0039BD90_lui;
    D_001D4CEC_0039BD90 = t | 0x4000;
}
/* localdecomp:end func_0039BD90 */

/* localdecomp:start func_0039BDC0 */
typedef struct { u8 pad0[0x10]; s32 f10; u8 pad14[0x148 - 0x14]; s32 f148; } S_396FD0;
extern S_396FD0 D_00142430_0039BDC0[];
extern s32 D_001D62FC_0039BDC0;
extern s32 D_001D6300_0039BDC0;
extern s32 D_001D6308_0039BDC0;
extern s32 D_001D62F4;
extern s32 D_001D62F8_0039BDC0;
extern s32 D_001D6304_0039BDC0;
extern s8 D_001D9FA8_g_0039BDC0;
extern s8 D_001D9FA0_0039BDC0;
extern s32 D_001D4CEC_r_0039BDC0;
extern s32 D_001D4CEC_w_0039BDC0;
extern void func_0039C028(void);
__asm__(".extern D_001D9FA8_g_0039BDC0, 4");
__asm__(".extern D_001D9FA0_0039BDC0, 16");
__asm__(".extern D_001D4CEC_r_0039BDC0, 16");
__asm__(".extern D_001D4CEC_w_0039BDC0, 16");
void func_0039BDC0(s32 a, s32 b, s32 c) {
    S_396FD0 *p = D_00142430_0039BDC0;
    s32 v;
    D_001D62FC_0039BDC0 = a;
    D_001D6300_0039BDC0 = c;
    p->f148 = 0;
    p->f10 = 0;
    D_001D6308_0039BDC0 = b;
    D_001D62F4 = 0;
    D_001D62F8_0039BDC0 = 0;
    D_001D6304_0039BDC0 = 0;
    D_001D9FA8_g_0039BDC0 = 0;
    func_0039C028();
    D_001D9FA0_0039BDC0 = 1;
    v = D_001D4CEC_r_0039BDC0;
    v |= 4;
    v &= ~2;
    v &= ~0x40;
    v &= ~0x10;
    v &= ~0x4000;
    D_001D4CEC_w_0039BDC0 = v;
}
/* localdecomp:end func_0039BDC0 */

/* localdecomp:start func_0039BE48 */
extern s32 D_001D4CEC_g;
extern s32 D_001D62F0;
s32 func_0039BE48(u32 a) {
    if (a >= 4) return 0;
    D_001D62F0 = a;
    D_001D4CEC_g |= 0x1000;
    return 1;
}
/* localdecomp:end func_0039BE48 */

/* func_0039BE70: from the US C of func_00397080 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


extern s32 D_001D4CEC[];
extern s32 D_00142578[];
/* localdecomp:start func_0039BE70 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern s32 D_001D4CEC_0039BE70_lui;
__asm__(".extern D_001D4CEC_0039BE70_lui, 16");
extern s32 D_001D4CEC_0039BE70;
extern s32 D_00142578[];
void func_0039BE70(void) {
    s32 t = D_001D4CEC_0039BE70_lui;
    D_00142578[0] = 0;
    D_001D4CEC_0039BE70 = t | 0x800;
}
/* localdecomp:end func_0039BE70 */

/* func_0039BE90: from the US C of func_003970A0 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_0039BE90 */
extern s32 D_001D4CEC_0039BE90_lui;
__asm__(".extern D_001D4CEC_0039BE90_lui, 16");
extern s32 D_001D4CEC_0039BE90;
void func_0039BE90(void) {
    /* retail reaches the flag through lui/lw for the read and through $gp for
       the write; the read's alias (sized, with an `.extern X, 16` hint) gives the assembler's reused-register
       load, the sized alias keeps the store in the small data area. */
    D_001D4CEC_0039BE90 = D_001D4CEC_0039BE90_lui | 0x2000;
}
/* localdecomp:end func_0039BE90 */

/* func_0039BEA8: from the US C of func_003970B8 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */

/* Retail reads the byte through lui/%lo and writes it through $gp: the read is a constant
   address (base and destination are the same register), the write a sized (small data) global. */

/* localdecomp:start func_0039BEA8 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern u8 D_001D9FA8_g;
/* the load is the assembler's `lui` expansion (one register), see func_0039BC70 */
extern u8 D_001D9FA8_0039BEA8;
__asm__(".extern D_001D9FA8_0039BEA8, 16");
u8 func_0039BEA8(void) {
    u8 v = D_001D9FA8_0039BEA8;
    D_001D9FA8_g = 0;
    return v;
}
/* localdecomp:end func_0039BEA8 */

LINKER_REMNANT("asm/remnants", func_0039BEB8);

/* localdecomp:start func_0039BEC0 */
extern S_142430 D_00142430;
void func_0039BEC0(s16 v) {
    u8 *b = (u8 *)&D_00142430;
    s32 t = *(s32 *)(b + 0x164);
    *(s16 *)(b + 0x18) = v;
    *(s32 *)(b + 0x148) = 0;
    if (t < 0) {
        *(s32 *)(b + 0x168) = 0;
        *(s32 *)(b + 0x164) = 0xD;
    }
}
/* localdecomp:end func_0039BEC0 */

/* Candidate for func_0039BEF0 (PAL retail, frontbin).
   The retail reaches the globals at 0x1D4BE0, 0x1D545C and 0x1A9318 with
   adjacent lui/%hi-%lo pairs (the assembler's `la`/`lw` macro form), so each is
   declared with a size hint above the small-data limit, which is what steers
   the compiler to that form; 0x1A9318 stays an array so that the pointer is
   the left operand of the sum, as in retail.  0x1D6308 is reached through $gp
   in the retail (a 2-byte object for the sh, a 4-byte object for the index),
   so it keeps a small size.  The retail rebuilds the 0x1D4BE0 and 0x1D545C
   addresses at every use, so each use gets its own alias. */

/* localdecomp:start func_0039BEF0 */
__asm__(".extern D_001D6308, 2");
__asm__(".extern D_001D6308_0039BD08, 4");
__asm__(".extern D_001D545C_0039BEF0b, 16");
__asm__(".extern D_001D545C_0039BEF0c, 16");
__asm__(".extern D_001D4BE0_0039BEF0b, 16");
__asm__(".extern D_001D4BE0_0039BEF0c, 16");
__asm__(".extern D_001A9318_0039BEF0b, 16");
typedef struct { u8 pad[0x18]; u16 h18; u8 pad2[0x148 - 0x1A]; s32 f148; u8 p14C[0x18]; s32 f164; s32 f168; u8 p16C[8]; s32 f174; } S_00397100;
extern S_00397100 D_00142430_0039BEF0[];
extern u16 D_001D6308;
extern s32 D_001D6308_0039BD08;
extern s32 D_001D545C_0039BEF0b;
extern s32 D_001D545C_0039BEF0c;
extern s32 D_001D4BE0_0039BEF0b;
extern s32 D_001D4BE0_0039BEF0c;
extern u8 D_001A9318_0039BEF0b[];
extern void func_12BE28();
extern void func_13AD58();
extern void func_0039FA88();
extern void func_0039E5E0();
void func_0039BEF0(s32 a, s32 b) {
    S_00397100 *p = D_00142430_0039BEF0;
    func_12BE28(&D_001D4BE0_0039BEF0b);
    func_13AD58(&D_001D4BE0_0039BEF0c);
    func_0039FA88(D_001A9318_0039BEF0b + (D_001D545C_0039BEF0b << 11));
    func_0039E5E0(a);
    p->f174 = a;
    p->h18 = D_001D6308;
    p->f148 = 0;
    if (b == -1) {
        *(s32 *)((u8 *)p + D_001D6308_0039BD08 * 0x1C + 0x30) = D_001D545C_0039BEF0c;
    } else {
        *(s32 *)((u8 *)p + D_001D6308_0039BD08 * 0x1C + 0x30) = b;
    }
    if (D_00142430_0039BEF0->f164 < 0) {
        D_00142430_0039BEF0->f168 = 0;
        D_00142430_0039BEF0->f164 = 0x13;
    }
}
/* localdecomp:end func_0039BEF0 */

/* PAL candidate for func_0039BFD8.
   Retail reads the flags word with a compiler lui/lw pair whose high half
   lands in the same register as the loaded value (the assembler's expansion,
   through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did)), and writes the word back through $gp (a sized scalar). */

/* localdecomp:start func_0039BFD8 */
extern s32 D_001D4CEC_0039BFD8;
__asm__(".extern D_001D4CEC_0039BFD8, 16");
extern s32 D_001D4CEC_g;
void func_0039BFD8(void) {
    D_001D4CEC_g = D_001D4CEC_0039BFD8 | 0x20;
}
/* localdecomp:end func_0039BFD8 */

/* localdecomp:start func_0039BFF0 */
extern s32 D_001D4CEC_0039BFF0;
__asm__(".extern D_001D4CEC_0039BFF0, 16");
/* func_0039BFF0: clears five bits of the flag word at 0x001D4CEC.
   The word is read with lui/lw (the assembler's expansion, through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did))
   and written back through the global (gp-relative). */

typedef union { s32 i; F_4CEC b; } U_4CEC;

void func_0039BFF0(void) {
    U_4CEC u;
    u.i = D_001D4CEC_0039BFF0;
    u.b.b1 = 0;
    u.b.b2 = 0;
    u.b.b12 = 0;
    u.b.b3 = 0;
    u.b.b4 = 0;
    D_001D4CEC_g = u.i;
}
/* localdecomp:end func_0039BFF0 */

/* localdecomp:start func_0039C028 */
extern s32 D_001D4CEC_0039C028;
__asm__(".extern D_001D4CEC_0039C028, 16");
/* PAL candidate for func_0039C028.
 *
 * Retail reads the flags word with lui/lw (the assembler's expansion, through
 * an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did)) and writes it
 * through $gp (the sized global D_001D4CEC_g), so the read and the write use
 * different address forms. The two cleared bits are 5 and 13 (0x20, 0x2000).
 */

void func_0039C028(void) {
    s32 v;
    v = D_001D4CEC_0039C028;
    v &= -33;
    v &= -8193;
    D_001D4CEC_g = v;
}
/* localdecomp:end func_0039C028 */

/* func_0039C048: from the US C of func_00397258 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags.

   PAL fix: with the file's flags (split addresses) an extern symbol makes the compiler emit
   `lui $v1, %hi(D)` + `lw $v0, %lo(D)($v1)`, but retail has the high part in the destination
   register (`lui $v0, %hi(D)` + `lw $v0, %lo(D)($v0)`): the assembler's expansion, through
   an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did). */

/* localdecomp:start func_0039C048 */
extern s32 D_001D4CEC_0039C048;
__asm__(".extern D_001D4CEC_0039C048, 16");
extern s32 D_001D4CEC[];

s32 func_0039C048(void) {
    return (D_001D4CEC_0039C048 >> 6) & 1;
}
/* localdecomp:end func_0039C048 */

/* func_0039C060 (PAL frontbin) - matched with this file's own flags.
 *
 * US draft: rac3-uya-decomp func_00397270, commit 13cf5c5:
 *     D_001D4CEC_f.b6 = 0;
 * The US matched it with `-mno-split-addresses` `@ps2as`; here the file's flags
 * (split addresses, default ee-as) must do it, so the C changed, not the flags.
 *
 * Retail:
 *     lui   $v0, 0x1d
 *     lw    $v0, 0x4cec($v0)      <- read the word at 0x001D4CEC
 *     addiu $v1, $zero, -0x41     <- ~0x40
 *     and   $v0, $v0, $v1
 *     jr    $ra
 *     sw    $v0, -0x7bc4($gp)      <- write it back (same word, $gp relative)
 *
 * The read goes through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did);
 * the write is a plain sized global, so it goes through $gp. One word, two
 * address forms.
 */

extern s32 D_001D4CEC_g;
/* localdecomp:start func_0039C060 */
extern s32 D_001D4CEC_0039C060;
__asm__(".extern D_001D4CEC_0039C060, 16");
void func_0039C060(void) {
    D_001D4CEC_g = D_001D4CEC_0039C060 & ~0x40;
}
/* localdecomp:end func_0039C060 */

/* localdecomp:start func_0039C078 */
extern char D_001D5360[];
extern char D_001D5378[], D_001D5390[], D_001D53A8[], D_001D53C8[], D_001D53E8[];
extern char D_001D5418[], D_001D5438[];
extern void func_0011BB58(char *, void *, s32);
void func_0039C078(u8 *p) {
    s32 i;
    u8 c;

    func_0011BB58(D_001D5360, p + 8, 0x15);
    c = p[0x12];
    if (c == 'E') {
        D_001D5378[2] = 'E';
    } else if (c == 'P') {
        D_001D5378[2] = 'I';
    } else if (c == 'K') {
        D_001D5378[2] = 'K';
    }
    for (i = 3; i < 7; i++) D_001D5378[i] = p[i + 0xD];
    for (i = 8; i < 11; i++) D_001D5378[i] = p[i + 0xD];
    for (i = 11; i < 13; i++) D_001D5378[i] = p[i + 0xE];
    func_0011BB58(D_001D5390, D_001D5378, 0xD);
    func_0011BB58(D_001D53A8, D_001D5378, 0xD);
    func_0011BB58(D_001D53C8, D_001D5378, 0xD);
    func_0011BB58(D_001D53E8, D_001D5378, 0xD);
    func_0011BB58(D_001D53E8 + 0x14, D_001D5378, 0xD);
    func_0011BB58(D_001D5418, D_001D5378, 0xD);
    func_0011BB58(D_001D5438, D_001D5378, 0xD);
}
/* localdecomp:end func_0039C078 */

LINKER_REMNANT("asm/remnants", func_0039C208);

/* localdecomp:start func_0039C220 */
extern u8 D_00332388[];
extern u8 D_00332618[];
extern s32 func_0039E6A8();
extern s32 func_0039E998_0039C220();
extern void func_0039EED8();
void func_0039C220(u8 *arg) {
    s32 a, b, t, i;
    u8 *q;
    a = func_0039E6A8(D_00332388);
    b = func_0039E6A8(D_00332618);
    t = *(s32 *)arg;
    if (t == a) {
        if (*(s32 *)(arg + 4) == b) {
            arg += 8;
            q = arg + t;
            func_0039E998_0039C220(arg, q, 0, D_00332388);
            arg = q;
            for (i = 0; i < 0x25; i++) {
                func_0039E998_0039C220(arg, arg + b, i, D_00332618);
                arg += b;
            }
            func_0039EED8();
        }
    }
}
/* localdecomp:end func_0039C220 */

/* localdecomp:start func_0039C300 */
typedef struct { u8 pad[0x64C]; s32 f64C; u8 p650[0x10]; s32 f660; s32 f664; } S_160C40_00397380;
typedef struct { u8 pad[0x18]; s16 f18; u8 p1A[0x162]; s32 f17C; } S_142430_00397380;
typedef struct { u8 pad[0x18]; s32 f18; u8 p1C[0x14]; s32 f30; } S_16C580_00397380;
extern S_160C40_00397380 D_160C40_0039C300;
extern S_142430_00397380 D_142430_0039C300;
extern S_16C580_00397380 D_16C580_0039C300;
extern u8 D_00143950_0039C300[];
extern s32 D_001D545C_0039C300;
extern s32 D_001D4B60_0039C300, D_001D4CEC_0039C300, D_001D4B90_0039C300, D_001D4BA0_0039C300;
__asm__(".extern D_001D545C_0039C300, 16");
__asm__(".extern D_001D4B60_0039C300, 16");
__asm__(".extern D_001D4CEC_0039C300, 16");
__asm__(".extern D_001D4B90_0039C300, 16");
__asm__(".extern D_001D4BA0_0039C300, 16");
extern void func_00392F08();
extern s32 func_003A2750();
extern s32 func_003A26F0();
extern void func_0038CC88();
extern void func_0039C220();
void func_0039C300(void) {
    u8 buf[0xBC];
    u8 *p;
    u8 *q;
    func_00392F08(D_160C40_0039C300.f664 << 11, &p);
    func_003A2750(1);
    func_003A26F0(p, D_160C40_0039C300.f660 + D_160C40_0039C300.f64C, D_160C40_0039C300.f664);
    q = p + *(s32 *)(p + 0x10);
    func_0038CC88(buf, D_00143950_0039C300, 0xBC);
    func_0039C220(q);
    func_0038CC88(D_00143950_0039C300, buf, 0xBC);
    D_001D545C_0039C300 = 1;
    if (D_142430_0039C300.f17C != 0) D_142430_0039C300.f17C = 0;
    if (D_142430_0039C300.f18 >= 0) D_142430_0039C300.f18 = -1;
    D_001D4CEC_0039C300 &= ~0x200;
    D_001D4B60_0039C300 = -1;
    D_001D4B90_0039C300 = -1;
    D_001D4BA0_0039C300 = -1;
    D_16C580_0039C300.f30 = -1;
    D_16C580_0039C300.f18 = -1;
}
/* localdecomp:end func_0039C300 */
