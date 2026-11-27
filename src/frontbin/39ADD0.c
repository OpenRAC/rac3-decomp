#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_0039ADE0(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/remnants", func_0039ADD0);

/* localdecomp:start func_0039ADD8 */
void func_0039ADD8(void) {
}
/* localdecomp:end func_0039ADD8 */

typedef struct { u8 p0[8]; s32 f8; u8 pC[4]; s32 f10; u8 p14[0x10]; s32 f24; u8 p28[0x144]; s32 f16C; } S_395FF0;
extern S_395FF0 D_00142430_0039ADE0[];
extern u8 D_001D9FA8_0039ADE0;
extern s32 D_001D4CE8_g_0039ADE0;
extern s32 D_001D4CE8_0039ADE0;
extern volatile s32 D_001D4CEC_0039ADE0;
extern s32 D_001D9FA4_g_0039ADE0;
extern s32 D_001D9FA4;
extern void (*D_003322F8[])(void);
/* localdecomp:start func_0039ADE0 */
extern s32 D_001D4CEC_l_0039ADE0;
extern s32 D_001D4CE8_l_0039ADE0;
extern s32 D_001D9FA4_l_0039ADE0;
__asm__(".extern D_001D4CEC_l_0039ADE0, 16");
__asm__(".extern D_001D4CE8_l_0039ADE0, 16");
__asm__(".extern D_001D9FA4_l_0039ADE0, 16");
__asm__(".extern D_001D9FA8_0039ADE0, 16");
void func_0039ADE0(void) {
    S_395FF0 *s = D_00142430_0039ADE0;
    s32 old;
    if (s->f16C != 0 || (s->f8 == 2 && s->f10 != 0) || s->f24 > 0) {
        D_001D9FA8_0039ADE0 = 1;
    }
    old = D_001D4CE8_g_0039ADE0;
    if (D_001D4CEC_l_0039ADE0 & 0x80) {
        D_001D4CE8_l_0039ADE0 = 0x18;
        D_001D4CEC_l_0039ADE0 = (D_001D4CEC_l_0039ADE0 & ~0x80) | 0x40;
    }
    if (D_001D4CEC_l_0039ADE0 & 0x100) {
        D_001D4CE8_l_0039ADE0 = 0x16;
        D_001D4CEC_l_0039ADE0 = (D_001D4CEC_l_0039ADE0 & ~0x100) | 0x40;
    }
    D_003322F8[D_001D4CE8_l_0039ADE0]();
    D_001D9FA4_g_0039ADE0 = D_001D9FA4_l_0039ADE0 + 1;
    if (D_001D4CE8_l_0039ADE0 != old) {
        D_001D9FA4_l_0039ADE0 = 0;
    }
}
/* localdecomp:end func_0039ADE0 */

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
extern s32 D_001D4CE8[];
typedef struct { 
    u8 pad[0x10]; 
    s32 f10; 
    u8 pad2[0x150]; 
    s32 f164; 
    s32 f168; 
    u8 pad3[0x10]; 
    s32 f17C; 
} S_142430x;
extern S_142430x D_142430;
extern s32 D_001D4CE8_g;
/* localdecomp:start func_0039AEF0 */
/* Adapted from the NTSC decomp draft (GPL-3.0; THIRD_PARTY_NOTICES.md).
 * The fixed-address flag store must remain a full-address assembler macro. */
void func_0039AEF0(void)
{
    S_142430x *p = &D_142430;
    *(s32 *)0x001D4CE8 = 4;
    p->f17C = 0;
    p->f10 = 0;
}
/* localdecomp:end func_0039AEF0 */

/* localdecomp:start func_0039AF10 */
typedef struct { u8 p0[8]; s32 f8; u8 pC[4]; s32 f10; u8 p14[0x168]; s32 f17C; } S_142430_00396120;
__asm__(".extern D_001D4CE8_00396122, 4");
__asm__(".extern D_001D4CEC_00396122, 4");
extern S_142430_00396120 D_142430_0039AF10;
extern s32 D_001D4CE8_00396122;
extern s32 D_001D4CEC_00396122;
extern s32 D_001D4CE8_0039AF10;
extern s32 D_001D4CEC_0039AF10;
__asm__(".extern D_001D4CE8_0039AF10, 16");
__asm__(".extern D_001D4CEC_0039AF10, 16");
void func_0039AF10(void) {
    if (D_142430_0039AF10.f17C == 0 && D_142430_0039AF10.f8 != 2) {
        D_001D4CE8_00396122 = 4;
        return;
    }
    if (D_142430_0039AF10.f17C != 0 && D_142430_0039AF10.f8 != 2) {
        D_142430_0039AF10.f17C = 0;
        D_001D4CE8_0039AF10 = 3;
        D_001D4CEC_00396122 = D_001D4CEC_00396122 | 1;
        return;
    }
    if (D_001D4CEC_0039AF10 & 4) {
        D_001D4CE8_00396122 = 0x1E;
        return;
    }
    if (D_001D4CEC_0039AF10 & 2) {
        D_001D4CE8_00396122 = 0x1D;
        return;
    }
    if (D_142430_0039AF10.f17C == 0 || (D_142430_0039AF10.f8 == 2 && D_142430_0039AF10.f10 != 0)) {
        D_001D4CE8_00396122 = 5;
        return;
    }
    if (D_001D4CEC_0039AF10 & 0x80) {
        D_001D4CE8_0039AF10 = 0x18;
        D_001D4CEC_00396122 = (D_001D4CEC_0039AF10 ^ 0x80) | 0x40;
        return;
    }
    if (D_001D4CEC_0039AF10 & 0x100) {
        D_001D4CE8_0039AF10 = 0x16;
        D_001D4CEC_00396122 = (D_001D4CEC_0039AF10 ^ 0x100) | 0x40;
        return;
    }
    if (D_001D4CEC_0039AF10 & 0x200) {
        D_001D4CEC_0039AF10 = D_001D4CEC_0039AF10 ^ 0x200;
        D_001D4CE8_0039AF10 = 0x1C;
    }
}
/* localdecomp:end func_0039AF10 */

/* func_0039B038 (frontbin).
   The US draft (rac3-uya-decomp func_00396248) reached the flag global through
   $gp, as a sized scalar. PAL retail stores it with the compiler's lui/%lo
   pair (lui $at; sw %lo($at)), which a sized scalar cannot produce with this
   file's flags: an unsized array gives gcc's split form (lui $v1; sw %lo($v1))
   and the scheduler hoists that lui into the branch delay slot. Retail's form
   is the assembler's expansion of a store to a global it does not know to be
   small: the store goes through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did). */

/* localdecomp:start func_0039B038 */
extern s32 D_001D4CE8_0039B038;
__asm__(".extern D_001D4CE8_0039B038, 16");
extern s32 (*D_001D6300_0039B038)();
typedef struct { u8 pad0[0x16C]; s32 f16C; u8 pad170[0xC]; s32 f17C; } S_00142430_00396248_00396248;
extern S_00142430_00396248_00396248 D_00142430_0039B038[];

void func_0039B038(void) {
    if (D_001D6300_0039B038 != 0) {
        D_001D6300_0039B038();
        D_001D6300_0039B038 = 0;
    }
    if (D_00142430_0039B038->f16C == 0) {
        D_00142430_0039B038->f17C = 1;
    }
    D_001D4CE8_0039B038 = 1; /* D_001D4CE8 */
}
/* localdecomp:end func_0039B038 */

extern u8 D_001D4CEC_0039B088;
extern s32 D_001D4CE8_0039B088;
/* localdecomp:start func_0039B088 */
/* Fixed addresses preserve the two independent assembler address macros. */
void func_0039B088(void)
{
    if ((*(u8 *)0x001D4CEC ^ 1) & 1) {
        *(s32 *)0x001D4CE8 = 4;
    }
}
/* localdecomp:end func_0039B088 */

/* PAL candidate for func_0039B0B0 (frontbin), from the US draft of
   rac3-uya-decomp func_003962C0.

   Retail reaches 0x1D4CE8 through lui/%lo here (the assembler expands the
   $gp-relative reference of a symbol it is told is not small), while the
   same variable is reached through $gp later in the file (func_0039B248).
   The per-function alias plus the .extern size hint give that form; see
   docs/wiki/Matching-Patterns.md ("Mixed access in one function"). */

extern s32 D_001D4CE8[];
/* localdecomp:start func_0039B0B0 */

extern S_142430x D_142430;
extern s32 D_001D4CE8_0039B0B0;
/* Ps2EeAs/ee-as only use $gp for a symbol it knows is small before the use. */
__asm__(".extern D_001D4CE8_0039B0B0, 16");

void func_0039B0B0(void) {
    S_142430x *p = &D_142430;
    p->f164 = -1;
    D_001D4CE8_0039B0B0 = 6;
    p->f168 = -1;
}
/* localdecomp:end func_0039B0B0 */

/* PAL candidate for func_0039B0D8.
   The draft wrote the game global at 0x001D4CE8 through the sized alias
   D_001D4CE8_g, which is small data, so gcc addressed it relative to $gp
   ("sw $v1, -0x7bc8($gp)").  Retail builds that address with lui + offset
   ("lui $at, 0x1d" / "sw $v1, 0x4ce8($at)"), i.e. the address is a plain
   constant there, so it is written as one here. */

extern S_142430x D_142430;
/* localdecomp:start func_0039B0D8 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern s32 D_001D4CE8_0039B0D8;
__asm__(".extern D_001D4CE8_0039B0D8, 16");
extern S_142430x D_142430;
void func_0039B0D8(void) {
    S_142430x *p = &D_142430;
    p->f164 = -1;
    D_001D4CE8_0039B0D8 = 6;
    p->f168 = -1;
}
/* localdecomp:end func_0039B0D8 */

extern s32 D_00142430_0039B100[];
extern s32 D_001D4CE8_0039B100;
extern s32 D_001D4CEC_0039B100;
/* localdecomp:start func_0039B100 */
extern s32 D_00142430_0039B100[];
extern s32 D_001D4CE8_g;
extern s32 D_001D4CEC_g;
extern volatile s32 D_001D4CEC_0039B100;
extern s32 D_001D4CE8_0039B100;
__asm__(".extern D_001D4CEC_0039B100, 16");
__asm__(".extern D_001D4CE8_0039B100, 16");

void func_0039B100(void) {
    s32 *s;
    D_001D4CEC_g = D_001D4CEC_0039B100 & ~0x20;
    s = D_00142430_0039B100;
    if (*(volatile s32 *)&s[2] == 2) {
        if (s[5] == 0) {
            D_001D4CE8_g = 7;
            return;
        }
        if (s[4]) {
            s[4] = 0;
            D_001D4CE8_g = 0xB;
            return;
        }
        D_001D4CE8_0039B100 = 0xB;
    }
}
/* localdecomp:end func_0039B100 */

/* PAL candidate for func_0039B168.
   0x1D4CEC and 0x1D4CE8 are read and written with lui/%hi+%lo, through
   an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did); D_001D4CE8_g (a plain s32) stays $gp relative, as retail has it. */

/* localdecomp:start func_0039B168 */
extern s32 D_001D4CEC_0039B168;
extern s32 D_001D4CE8_0039B168;
__asm__(".extern D_001D4CEC_0039B168, 16");
__asm__(".extern D_001D4CE8_0039B168, 16");
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, rest:17; } F_4CEC;
extern s32 D_00142438[];
extern u8 D_001D5BDD;
extern s32 D_001D4CE8_g;
void func_0039B168(void) {
    if (D_00142438[0] != 2) {
        D_001D4CE8_g = 4;
        return;
    }
    if (D_001D5BDD != 0 || (D_001D4CEC_0039B168 & 0x12)) D_001D4CE8_0039B168 = 8;
}
/* localdecomp:end func_0039B168 */

/* PAL candidate for func_0039B1B8 (US draft: rac3-uya-decomp func_003963C8, commit 13cf5c5).
   The US matched it with `@ps2as`; here the file's own flags must do it, so the globals are
   reached the way retail reaches them: the writes of 0x001D4CE8 that retail does through $gp
   stay on a sized declaration, the others are plain addresses, so the compiler splits them
   into lui/lo the way retail does. */

/* localdecomp:start func_0039B1B8 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern s32 D_001D4CEC_0039B1B8;
extern u8 D_001D5BDC_0039B1B8;
extern s32 D_001D4CE8_0039B1B8_lui;
__asm__(".extern D_001D4CEC_0039B1B8, 16");
__asm__(".extern D_001D5BDC_0039B1B8, 16");
__asm__(".extern D_001D4CE8_0039B1B8_lui, 16");
extern s32 D_00142430_0039B1B8[];
extern s32 D_001D4CE8_0039B1B8;
extern void func_0039C028(void);
void func_0039B1B8(void) {
    s32 v;
    if (D_00142430_0039B1B8[2] != 2) {
        D_001D4CE8_0039B1B8 = 4;
        return;
    }
    v = D_001D4CEC_0039B1B8;
    if (v & 0x20) {
        func_0039C028();
        if (D_001D5BDC_0039B1B8) D_001D4CE8_0039B1B8 = 0x1A;
        else D_001D4CE8_0039B1B8 = 7;
    } else if (v & 8) {
        D_001D4CEC_0039B1B8 = v ^ 8;
        D_001D4CE8_0039B1B8_lui = 9;
    }
}
/* localdecomp:end func_0039B1B8 */

/* localdecomp:start func_0039B248 */
extern S_142430x D_142430;
extern s32 D_001D4CE8_g;
void func_0039B248(void) {
    S_142430x *p = &D_142430;
    p->f10 = 0;
    if (p->f164 < 0) {
        p->f168 = 0;
        p->f164 = 3;
    }
    D_001D4CE8_g = 10;
}
/* localdecomp:end func_0039B248 */

typedef struct { u8 pad[0x15C]; s32 x15C; s32 x160; s32 x164; s32 x168; s32 x16C; } S_396488;
extern S_396488 D_00142430_0039B278[];
extern s32 D_001D4CEC_0039B278;
extern s32 D_001D4CE8_0039B278;
/* localdecomp:start func_0039B278 */
extern s32 D_001D4CE8_0039B278;
extern s32 D_001D4CEC_0039B278_lui;
__asm__(".extern D_001D4CE8_0039B278, 16");
__asm__(".extern D_001D4CEC_0039B278_lui, 16");

void func_0039B278(void) {
    S_396488 *p = D_00142430_0039B278;
    if (p->x15C == 2 && p->x164 < 0) {
        if (p->x16C) {
            s32 f = D_001D4CEC_0039B278_lui;
            D_001D4CE8_0039B278 = 0x13;
            D_001D4CEC_0039B278 = f | 0x40;
        } else {
            D_001D4CE8_0039B278 = 0x10;
        }
    }
}
/* localdecomp:end func_0039B278 */

/* PAL candidate for func_0039B2D8 (US draft of rac3-uya-decomp func_003964E8).
   Retail reaches the flag at 0x1D4CE8 through $gp for the two stores that sit in
   a branch delay slot and through %hi/%lo for the third one.  With the default
   assembler that mix comes from telling the assembler, before the function, that
   the third store's symbol is not small data (the .extern size hint); the two
   delay-slot stores keep a symbol whose size the assembler does not know yet. */

extern s32 D_00142438[];
extern s32 D_001D4CEC_0039B2D8;
extern s32 D_001D4CE8_g;
extern s32 D_001D4CE8_0039B2D8;
__asm__(".extern D_001D4CE8_0039B2D8, 16");

/* localdecomp:start func_0039B2D8 */
extern s32 D_00142438[];
extern s32 D_001D4CEC_0039B2D8;
extern s32 D_001D4CE8_0039B2D8;
void func_0039B2D8(void) {
    s32 v;
    if (D_00142438[0] != 2) {
        D_001D4CE8_g = 4;
        return;
    }
    v = D_001D4CEC_0039B2D8;
    if (v & 0x806) {
        D_001D4CE8_g = 0xC;
        return;
    }
    if (v & 0x200) {
        D_001D4CE8_0039B2D8 = 0x1C;
    }
}
/* localdecomp:end func_0039B2D8 */

typedef struct { u32 b0:11; u32 f11:1; u32 rest:20; } S_396538;
extern s32 D_00142430_0039B328[];
extern s32 D_001D4CE8_0039B328;
extern union { s32 i; S_396538 b; } D_001D4CEC_0039B328;
/* localdecomp:start func_0039B328 */
/* func_0039B328: the flag word at 0x1D4CEC is read through $gp (sized global D_001D4CEC_g)
   and written through lui (an alias declared sized with an `.extern X, 16` hint, as the file's
   other lui-form accesses do); 0x1D4CE8 is written through lui the same way. */
extern s32 D_001D4CEC_g;
extern s32 D_00142430_0039B328[];
extern s32 D_001D4CE8_0039B328;
__asm__(".extern D_001D4CE8_0039B328, 16");
__asm__(".extern D_001D4CEC_0039B328, 16");

void func_0039B328(void) {
    s32 *p = D_00142430_0039B328;
    if (p[0x15C / 4] == 2 && p[0x164 / 4] < 0) {
        p[4] = 0;
        p[0x164 / 4] = 7;
        p[0x168 / 4] = 0;
        D_001D4CE8_0039B328 = 0xD;
        D_001D4CEC_0039B328.i = D_001D4CEC_g & ~0x800;
    }
}
/* localdecomp:end func_0039B328 */

/* func_0039B380: from the US C of func_00396590 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_0039B380 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern s32 D_001D4CE8_0039B380_lui;
__asm__(".extern D_001D4CE8_0039B380_lui, 16");
typedef struct { u8 p0[8]; s32 f8; s32 fC; u8 p10[8]; s16 h18; u8 p1A[6]; s32 f20; u8 p24[0x15C - 0x24]; s32 f15C; u8 p160[4]; s32 f164; u8 p168[4]; s32 f16C; } S_396590;
extern S_396590 D_00142430_0039B380[];
extern s32 D_001D4CE8_0039B380;
void func_0039B380(void) {
    S_396590 *s = D_00142430_0039B380;
    if (s->f15C != 2) return;
    if (s->f164 >= 0) return;
    if (s->f16C != 0) {
        D_001D4CE8_0039B380 = 0xE;
        return;
    }
    if (s->f8 != 2) {
        D_001D4CE8_0039B380 = 4;
        return;
    }
    if (s->h18 == -2) {
        if (s->fC + s->f20 >= 0x258) {
            D_001D4CE8_0039B380 = 0xE;
            return;
        }
        D_001D4CE8_0039B380 = 0x15;
        return;
    }
    if (s->h18 >= -1) {
        D_001D4CE8_0039B380_lui = 0x12;
    }
}
/* localdecomp:end func_0039B380 */

/* PAL candidate for func_0039B418 (frontbin).

   Retail reaches D_001D4CEC through $gp for the load but through lui/%lo for
   the store: the load keeps the sized (small data) declaration, the stores go
   through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did). */

/* localdecomp:start func_0039B418 */
extern s32 D_001D4CE8_0039B418;
extern s32 D_001D4CEC_0039B418_lui;
__asm__(".extern D_001D4CE8_0039B418, 16");
__asm__(".extern D_001D4CEC_0039B418_lui, 16");
typedef struct { u8 pad0[0x10]; s32 x10; u8 pad[0x15C-0x14]; s32 x15C; s32 x160; s32 x164; s32 x168; s32 x16C; } S_396628;
extern S_396628 D_00142430_0039B418[];
extern s32 D_001D4CEC_0039B418;
void func_0039B418(void) {
    S_396628 *p = D_00142430_0039B418;
    if (p->x15C == 2 && p->x164 < 0) {
        p->x164 = 7;
        p->x10 = 0;
        p->x168 = 0;
        D_001D4CE8_0039B418 = 0x20;
        D_001D4CEC_0039B418_lui = D_001D4CEC_0039B418 & ~0x800;
    }
}
/* localdecomp:end func_0039B418 */

/* PAL retail bytes for func_0039B470 (frontbin), with this source file's own flags.
   The US draft (rac3-uya-decomp func_00396680) matched with @ps2as; with the default
   assembler the address form of a scalar extern is chosen by the size hint the assembler is
   given: a small symbol is reached through $gp, a bigger one through the assembler's
   lui/%lo macro (docs/wiki/Matching-Patterns.md, "Size hints choose the address form of a
   scalar extern"). Retail reaches D_001D4CEC through $gp in one place and through
   lui/%lo in the other two, and D_001D4CE8 only through lui/%lo, so each global gets the
   hint its accesses need, before its first use. */

/* localdecomp:start func_0039B470 */
typedef struct { u8 p0[8]; s32 f8; s32 fC; u8 p10[8]; s16 f18; u8 p1A[2]; s32 f1C; s32 f20; u8 p24[0x138]; s32 f15C; u8 p160[4]; s32 f164; u8 p168[4]; s32 f16C; } S_142430_00396680;
__asm__(".extern D_001D4CEC_00396682, 4");
__asm__(".extern D_001D4CEC_0039B470, 16");
__asm__(".extern D_001D4CE8_0039B470, 16");
__asm__(".extern D_001D62F0_0039B470, 4");
__asm__(".extern D_001D6304_0039B470, 4");
extern S_142430_00396680 D_142430_0039B470;
extern s32 D_001D4CEC_00396682;
extern s32 D_001D4CEC_0039B470;
extern s32 D_001D4CE8_0039B470;
extern void (*D_001D6304_0039B470)(void);
extern s32 D_001D62F0_0039B470;
void func_0039B470(void) {
    s32 c;
    s32 a;
    s32 u;
    s32 w;
    a = D_142430_0039B470.f15C;
    if (a == 2 && D_142430_0039B470.f164 < 0) {
        if (D_142430_0039B470.f16C != 0) {
            u = D_001D4CEC_00396682;
            c = 0x18; D_001D4CE8_0039B470 = c; D_001D4CEC_00396682 = u | 0x40;
            goto cb;
        }
        if (D_142430_0039B470.f8 != a) {
            D_001D4CE8_0039B470 = 4;
        } else {
            a = D_142430_0039B470.f18;
            if (a == -2) {
                if (D_142430_0039B470.fC + D_142430_0039B470.f20 >= 0x258) {
                    u = D_001D4CEC_0039B470;
                    c = 0x18; D_001D4CE8_0039B470 = c; D_001D4CEC_00396682 = u | 0x40;
                } else {
                    D_001D4CE8_0039B470 = 0x15;
                }
            } else if (a < -1) {
            } else if (a != -1) {
                D_001D4CE8_0039B470 = 0x12;
            } else {
                w = D_001D4CEC_0039B470;
                if (w & 0x1000) {
                    s32 t = *(u16 *)&D_001D62F0_0039B470;
                    D_001D62F0_0039B470 = a;
                    D_142430_0039B470.f18 = t;
                    D_001D4CEC_0039B470 = w & ~0x1000;
                }
                D_001D4CE8_0039B470 = 0x12;
            }
        }
    cb:
        if (D_001D6304_0039B470 != 0) {
            D_001D6304_0039B470();
            D_001D6304_0039B470 = 0;
        }
    }
}
/* localdecomp:end func_0039B470 */

/* Candidate for func_0039B570 (PAL retail).
   The second store (value 15) is addressed with %hi/%lo (lui $at + sw), like
   the D_00142438[0] access, so it goes through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did). */

/* localdecomp:start func_0039B570 */
extern s32 D_001D4CE8_0039B570;
__asm__(".extern D_001D4CE8_0039B570, 16");
extern s32 D_00142438[];
extern s32 D_001D4CE8_g;
extern s32 D_001D4CEC_g;
void func_0039B570(void) {
    if (D_00142438[0] != 2) {
        D_001D4CE8_g = 4;
        return;
    }
    if (D_001D4CEC_g & 0x12) D_001D4CE8_0039B570 = 15;
}
/* localdecomp:end func_0039B570 */

/* localdecomp:start func_0039B5B0 */
extern u8 D_001D5BDC_0039B5B0;
extern s32 D_001D4CE8_0039B5B0_lui;
__asm__(".extern D_001D5BDC_0039B5B0, 16");
__asm__(".extern D_001D4CE8_0039B5B0_lui, 16");
/* PAL candidate for func_0039B5B0.
   The retail code reaches two of the globals through lui + offset instead of
   $gp, so those two accesses go through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did). */

extern s32 D_00142438[];
extern s32 D_001D4CEC_0039B5B0;
extern s32 D_001D4CE8_0039B5B0;

void func_0039B5B0(void) {
    s32 f;
    if (D_00142438[0] != 2) { D_001D4CE8_0039B5B0 = 4; return; }
    f = D_001D4CEC_0039B5B0;
    if (f & 0x20) {
        D_001D4CEC_0039B5B0 = f ^ 0x20;
        if (D_001D5BDC_0039B5B0 != 0) { D_001D4CE8_0039B5B0 = 0x1B; } else { D_001D4CE8_0039B5B0 = 0xE; }
        return;
    }
    if (f & 0x2000) { D_001D4CE8_0039B5B0_lui = 0x10; }
}
/* localdecomp:end func_0039B5B0 */

typedef struct { u8 pad[0x15C]; s32 x15C; s32 x160; s32 x164; s32 x168; s32 x16C; } S_396830;
extern S_396830 D_00142430_0039B620[];
extern s32 D_001D4CEC_0039B620;
extern s32 D_001D4CE8_0039B620;
/* localdecomp:start func_0039B620 */
extern s32 D_001D4CEC_g;
__asm__(".extern D_001D4CEC_0039B620, 16");
__asm__(".extern D_001D4CE8_0039B620, 16");

void func_0039B620(void) {
    S_396830 *p = D_00142430_0039B620;
    s32 v;
    if (p->x15C == 2 && p->x164 < 0) {
        v = D_001D4CEC_g;
        v &= ~2;
        p->x164 = 9;
        v &= ~0x10;
        D_001D4CEC_0039B620 = v;
        p->x168 = 0;
        D_001D4CE8_0039B620 = 0x11;
    }
}
/* localdecomp:end func_0039B620 */

typedef struct { u8 pad[0x18]; s16 f18; u8 padA[0x12E]; s32 f148; u8 padB[0x10]; s32 f15C; u8 pad2[4]; s32 f164; u8 pad3[4]; s32 f16C; } S_396890;
extern S_396890 D_142430_0039B680;
extern s32 D_001D4CEC_0039B680;
extern s32 D_001D4CE8_0039B680;
/* localdecomp:start func_0039B680 */
extern s32 D_001D4CEC_0039B680_lui;
extern s32 D_001D4CE8_0039B680_lui;
__asm__(".extern D_001D4CEC_0039B680_lui, 16");
__asm__(".extern D_001D4CE8_0039B680_lui, 16");

void func_0039B680(void) {
    S_396890 *s = &D_142430_0039B680;
    if (s->f15C == 2 && s->f164 < 0) {
        if (s->f16C != 0) {
            D_001D4CE8_0039B680_lui = 0x14;
            D_001D4CEC_0039B680 = D_001D4CEC_0039B680_lui | 0x40;
        } else {
            s->f18 = 0;
            D_001D4CE8_0039B680_lui = 0x1F;
            do { s->f148 = 0; } while (0);
        }
    }
}
/* localdecomp:end func_0039B680 */

/* PAL candidate for func_0039B6E8 (US draft func_003968F8).
   Retail reaches 0x1D4CEC and 0x1D4CE8 both through $gp and through lui,
   so the two forms need two spellings of the same address. */

/* localdecomp:start func_0039B6E8 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern s32 D_001D4CEC_0039B6E8_lui;
extern s32 D_001D4CE8_0039B6E8_lui;
__asm__(".extern D_001D4CEC_0039B6E8_lui, 16");
__asm__(".extern D_001D4CE8_0039B6E8_lui, 16");
typedef struct { u8 pad[0x18]; u16 h18; u8 pad2[0x15C - 0x1A]; s32 x15C; s32 pad4; s32 x164; } S_3968F8;
extern S_3968F8 D_00142430_0039B6E8[];
extern void (*D_001D62F4_0039B6E8)(void);
extern u16 D_001D6308;
extern s32 D_001D4CE8_0039B6E8;
extern s32 D_001D4CEC_0039B6E8;
extern void func_0039C028(void);
void func_0039B6E8(void) {
    S_3968F8 *p = D_00142430_0039B6E8;
    if (p->x15C == 2 && p->x164 < 0) {
        if (*(s32 *)((u8 *)p + *(s32 *)&D_001D6308 * 0x1C + 0x30) == -1 || (D_001D4CEC_0039B6E8 & 0x6000) != 0) {
            func_0039C028();
            D_001D4CEC_0039B6E8 = D_001D4CEC_0039B6E8_lui & ~0x4000;
            if (D_001D62F4_0039B6E8) {
                D_001D62F4_0039B6E8();
                D_001D62F4_0039B6E8 = 0;
            }
            p->h18 = D_001D6308;
            D_001D4CE8_0039B6E8_lui = 0x19;
        } else {
            D_001D4CE8_0039B6E8_lui = 0x21;
        }
    }
}
/* localdecomp:end func_0039B6E8 */

/* func_0039B7A8 (frontbin) -- PAL retail, matched with the flags of
   src/frontbin/39A6E0.c (-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
   -mno-check-zero-division -fno-force-mem).

   The declarations this block needs (S_3969B8, D_00142430_0039B7A8,
   D_001D62FC, D_001D6308) are the ones the file already has above the
   block, so only the body belongs here.

   Retail reaches the global at 0x1D4CE8 through %hi/%lo here
   (lui $at,0x1d ; sw $v1,0x4ce8($at)), while other functions of this file
   reach the same address through $gp (sw $v2,-0x7BC8($gp)).  With -G8 the
   compiler reaches a global whose size it knows through $gp, so the store
   here goes through a plain address instead: the compiler then splits the
   address into %hi/%lo and keeps the high half in $at. */

/* localdecomp:start func_0039B7A8 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern s32 D_001D4CE8_0039B7A8;
__asm__(".extern D_001D4CE8_0039B7A8, 16");
typedef struct { u8 pad[0x18]; u16 h18; u8 pad2[0x148 - 0x1A]; s32 x148; u8 pad3[0x10]; s32 x15C; s32 pad4; s32 x164; } S_3969B8;
extern S_3969B8 D_00142430_0039B7A8[];
extern void (*D_001D62FC)(void);
extern u16 D_001D6308;
void func_0039B7A8(void) {
    S_3969B8 *p = D_00142430_0039B7A8;
    if (p->x15C == 2 && p->x164 < 0) {
        if (D_001D62FC) {
            D_001D62FC();
            D_001D62FC = 0;
        }
        p->h18 = D_001D6308;
        p->x148 = 0;
        D_001D4CE8_0039B7A8 = 0x17;
    }
}
/* localdecomp:end func_0039B7A8 */

/* PAL candidate for func_0039B818 (frontbin).
   The PAL retail reaches the two globals at 0x001D4CE8 / 0x001D4CEC with
   absolute addressing (lui + lw/sw), and with $gp-relative addressing for the
   two stores in the return delay slots.  Under this file's flags an unsized
   global gives gcc's split form (lui $v1 / lw $v0, 0x4CEC($v1)) instead.  So
   the absolute accesses go through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did), and the two $gp ones through the
   sized scalar aliases (D_001D4CE8_g / D_001D4CEC_g, small data). */

/* localdecomp:start func_0039B818 */
extern s32 D_001D4CEC_0039B818;
extern s32 D_001D4CE8_0039B818;
__asm__(".extern D_001D4CEC_0039B818, 16");
__asm__(".extern D_001D4CE8_0039B818, 16");
typedef struct { u8 pad[8]; s32 f8; u8 pad2[0x170]; s32 f17C; } S_142430_396A28;
extern S_142430_396A28 D_142430_0039B818;
extern s32 D_001D4CE8_g;
extern s32 D_001D4CEC_g;
void func_0039B818(void) {
    s32 f = D_001D4CEC_0039B818;
    if (f & 4) D_001D4CE8_0039B818 = 0x1E;
    if (f & 2) D_001D4CE8_0039B818 = 0x1D;
    if (f & 0x800) D_001D4CE8_0039B818 = 0xC;
    if (f & 0x80) {
        D_001D4CE8_0039B818 = 0x18;
        D_001D4CEC_g = (f ^ 0x80) | 0x40;
        return;
    }
    if (f & 0x100) {
        D_001D4CE8_0039B818 = 0x16;
        D_001D4CEC_g = (f ^ 0x100) | 0x40;
        return;
    }
    if (D_142430_0039B818.f8 != 2) {
        D_001D4CE8_g = 4;
        return;
    }
    if (D_142430_0039B818.f17C) D_001D4CE8_0039B818 = 1;
}
/* localdecomp:end func_0039B818 */

/* func_0039B8D0: from the US C of func_00396AE0 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_0039B8D0 */
extern s32 D_001D4CEC_0039B8D0;
extern s32 D_001D4CE8_0039B8D0;
__asm__(".extern D_001D4CEC_0039B8D0, 16");
__asm__(".extern D_001D4CE8_0039B8D0, 16");
extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];

/* Retail reads the flag through the address register itself
   (lui $v0,0x1D / lw $v0,0x4CEC($v0)) and writes the state through $at
   (lui $at,0x1D / sw $v0,0x4CE8($at)): the assembler's expansions. Under this
   file's flags (split addresses) unsized globals give gcc's split form instead
   (lui $v1 / lw $v0,0x4CEC($v1)), which is what the US needed
   -mno-split-addresses for; both go through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did). */
void func_0039B8D0(void) {
    if (!(D_001D4CEC_0039B8D0 & 0x40)) {
        D_001D4CE8_0039B8D0 = 4;
    }
}
/* localdecomp:end func_0039B8D0 */

/* localdecomp:start func_0039B8F8 */
extern s32 D_001D4CEC_0039B8F8;
extern s32 D_001D4CE8_0039B8F8;
__asm__(".extern D_001D4CEC_0039B8F8, 16");
__asm__(".extern D_001D4CE8_0039B8F8, 16");
/* PAL candidate for func_0039B8F8.
   With an unsized symbol gcc splits the address over two registers ($v1 for
   the high half, $v0 for the loaded word); the assembler's expansion puts the
   high half in the load's own register and uses $at for the store. Retail does
   the latter (see func_0039BA10, func_0039B278, func_0039C048), so the two
   globals go through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did). */

extern void (*D_001D6304)(void);
extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];
void func_0039B8F8(void) {
    if (D_001D6304 != 0) {
        D_001D6304();
        D_001D6304 = 0;
    }
    if (!(D_001D4CEC_0039B8F8 & 0x40)) {
        D_001D4CE8_0039B8F8 = 4;
    }
}
/* localdecomp:end func_0039B8F8 */

/* Candidate for func_0039B940 (PAL frontbin).
 *
 * Retail reaches D_001D4CE8 with `lui $at` + `sw`, i.e. a lui/lw pair with
 * the high half in $at, not the $gp form a sized global would give: the store
 * goes through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did).
 */

/* localdecomp:start func_0039B940 */
extern s32 D_001D4CE8_0039B940;
__asm__(".extern D_001D4CE8_0039B940, 16");
extern s32 D_00142438[];
void func_0039B940(void) {
    if (D_00142438[0] != 2) {
        D_001D4CE8_0039B940 = 4;
    }
}
/* localdecomp:end func_0039B940 */

/* PAL candidate for func_0039B968.
   The D_001D4CEC / D_001D4CE8 accesses go through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did): with an unsized
   symbol gcc splits the address into lui $v1 / lw $v0, the retail wants the high half
   in the destination register. */


/* localdecomp:start func_0039B968 */
extern s32 D_001D4CEC_0039B968;
extern s32 D_001D4CE8_0039B968;
__asm__(".extern D_001D4CEC_0039B968, 16");
__asm__(".extern D_001D4CE8_0039B968, 16");
extern void (*D_001D6300)(void);
extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];
void func_0039B968(void) {
    if (D_001D6300 != 0) {
        D_001D6300();
        D_001D6300 = 0;
    }
    if (!(D_001D4CEC_0039B968 & 0x40)) {
        D_001D4CE8_0039B968 = 4;
    }
}
/* localdecomp:end func_0039B968 */
