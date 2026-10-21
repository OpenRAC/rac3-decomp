#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_0039A6E0(void);
extern void func_0039C410(void);
extern void func_0039ADE0(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_0039EF28();
extern void func_0039AA38(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_0039A6E0 */
extern void func_0038CB78(void *, s32, s32);
extern u8 D_0016C690[];
void func_0039A6E0(void) {
    s32 *p;
    s32 i;
    func_0038CB78(D_0016C690, 0, 0x35840);
    *(s16 *)(D_0016C690 + 0x14) = -1;
    p = (s32 *)(D_0016C690 + 0x3C);
    for (i = 2; i >= 0; i--) {
        *p-- = -1;
    }
}
/* localdecomp:end func_0039A6E0 */

/* localdecomp:start func_0039A748 */
extern s32 D_001D600C;
typedef struct { u8 pad[0x34]; s32 arr[8]; } T_00395958;
extern T_00395958 D_0016C690_0039A748;
typedef struct { s32 f0; s32 f4; } S_00395958;

void func_0039A748(S_00395958 *arg0, s32 arg1) {
    if (arg1 != 0) {
        if (arg0->f4 >= 0) {
            D_0016C690_0039A748.arr[arg0->f4] = arg0->f0;
            if (arg0->f4 == D_001D600C) {
                D_001D600C = arg0->f4 ^ 1;
            }
        }
    }
    arg0->f0 = -1;
}
/* localdecomp:end func_0039A748 */

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } E_003959A8;
typedef struct { u8 pad[0x458C]; s32 g458C; E_003959A8 el[0x30]; } S_003959A8;
typedef struct { s32 w0; s32 w4; s32 w8; s32 wC; } L_003959A8;
typedef struct { s32 f0; s32 f4; u8 *f8; } A_003959A8;
extern S_003959A8 D_160C40_0039A798;
extern void func_11F0A0();
extern s32 func_11F1E0();
extern s32 func_11F1C0();
extern s32 func_003A2630();
/* localdecomp:start func_0039A798 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern s32 D_001D4B38_0039A798;
extern s32 D_001D4B38_0039A798 __attribute__((section(".bss")));
extern void func_0039A748();
void func_0039A798(A_003959A8 *a, s32 flag) {
    s32 t;
    s32 off;
    s32 base;
    s32 h;
    u8 *o;
    s32 *r;
    L_003959A8 l;
    if (flag == 0) {
        a->f0 = -1;
        return;
    }
    t = D_160C40_0039A798.el[a->f0].f10;
    if (t != 0) {
        off = a->f4 * 0xC800;
        o = a->f8;
        base = D_001D4B38_0039A798;
        base = base + off;
        l.w0 = (s32)o;
        l.w4 = base;
        l.w8 = t << 11;
        l.wC = 0;
        r = (s32 *)(o + 0x18);
        *(s32 *)(o + 0x14) = 0xC000;
        r[10] = 0xC000;
        r[11] = 0xC000;
        func_11F0A0(0);
        h = func_11F1E0(&l, 1);
        while (func_11F1C0(h) >= 0) {
        }
    }
    func_003A2630(a->f8, D_160C40_0039A798.el[a->f0].f4 + D_160C40_0039A798.g458C, D_160C40_0039A798.el[a->f0].f8, func_0039A748, a);
}
/* localdecomp:end func_0039A798 */

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } E_00395AC8;
typedef struct { u8 pad[0x458C]; s32 g458C; E_00395AC8 el[0x30]; } S_00395AC8;
extern S_00395AC8 D_160C40_0039A8B8;
typedef struct { u8 pad[0x34]; s32 f34[3]; } T_00395AC8;
extern T_00395AC8 D_16C690_0039A8B8;
extern s32 D_001D6000_0039A8B8;
extern u8 D_001D6004_0039A8B8;
extern u8 D_001D6008_0039A8B8;
extern s32 func_003A2630();
extern void func_0039A798();
INCLUDE_ASM("asm/nonmatchings/text", func_0039A8B8);

/* localdecomp:start func_0039A9B0 */
typedef struct { s32 k; u8 pad[0x10]; } E_395BC0;
typedef struct { u8 pad[0x4590]; E_395BC0 e[0x30]; } S_395BC0;
typedef struct { u8 d[0xC800]; } B_395BC0;
typedef struct { u8 pad[0x34]; s32 f34[3]; B_395BC0 blk[1]; } S_395BC0b;
extern S_395BC0 D_160C40_0039A9B0;
extern S_395BC0b D_16C690_0039A9B0;
void func_0039A9B0(s32 a, s32 b) {
    s32 i;
    for (i = 0; i < 0x30; i++) {
        if (D_160C40_0039A9B0.e[i].k == a) break;
    }
    if (i == 0x30) return;
    if (D_16C690_0039A9B0.f34[b] == i) return;
    func_0039A8B8(i, b, &D_16C690_0039A9B0.blk[b], 0);
}
/* localdecomp:end func_0039A9B0 */

/* localdecomp:start func_0039AA38 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern s32 D_001D4C40_0039AA38;
extern s32 D_001D4C40_0039AA38 __attribute__((section(".bss")));
typedef struct { u8 pad[0x10]; s32 f10; u8 pad2[0xDC]; } E_395C48;
typedef struct { s32 id; s32 pad[4]; } F_395C48;
typedef struct { u8 pad[0x4590]; F_395C48 e[0x30]; } S_395C48;
typedef struct { u8 pad[0x34]; s32 v[3]; } T_395C48;
typedef struct { u8 pad[0x25F8]; s32 f25F8; u8 pad2[0x18]; s32 f2614; } A_395C48;
extern A_395C48 D_1A4BE0;
extern u8 D_001425C0[];
extern s32 D_00142674[];
extern s16 D_001CCFD4[];
extern E_395C48 D_001DAA40[];
extern S_395C48 D_160C40_0039AA38;
extern T_395C48 D_16C690_0039AA38;
extern s32 func_0039AC08(s32);
static __inline__ s32 get_395C48(s32 n) {
    E_395C48 *e = &D_001DAA40[D_001425C0[n]];
    return e->f10;
}
void func_0039AA38(s32 id) {
    s32 a, b, x, y, i, t, k;
    if (func_0039AC08(id) != 0) return;
    if (D_001CCFD4[0] != 0) return;
    i = 0;
    a = get_395C48(D_1A4BE0.f2614);
    b = get_395C48(D_001D4C40_0039AA38); /* through $gp (a plain sized extern) it schedules differently */
    if (b == a) {
        b = get_395C48(D_00142674[0]);
    }
    y = -1;
    if (a == id) a = -1;
    if (b == id) b = -1;
    x = -1;
    for (; i < 3; i++) {
        s32 e = D_160C40_0039AA38.e[D_16C690_0039AA38.v[i]].id;
        if (a == e) x = i;
        if (b == e) y = i;
    }
    for (i = 0; i == x || i == y; i++);
    t = D_1A4BE0.f25F8;
    if (t != 0) {
        k = D_16C690_0039AA38.v[i];
        if (k != -1) {
            if (get_395C48(t) == D_160C40_0039AA38.e[k].id) {
                D_1A4BE0.f25F8 = 0;
            }
        }
    }
    func_0039A9B0(id, i);
}
/* localdecomp:end func_0039AA38 */

LINKER_REMNANT("asm/remnants", func_0039AC00);

/* localdecomp:start func_0039AC08 */
typedef struct { s32 id; s32 pad[4]; } E_395E18;
typedef struct { u8 pad[0x4590]; E_395E18 e[0x30]; } S_395E18;
typedef struct { u8 pad[0x34]; s32 v[3]; } T_395E18;
extern S_395E18 D_160C40[];
extern T_395E18 D_16C690[];
s32 func_0039AC08(s32 id) {
    s32 i, j;
    for (i = 0; i < 0x30; i++) if (D_160C40[0].e[i].id == id) break;
    if (i == 0x30) return 1;
    for (j = 0; j < 3; j++) if (D_16C690[0].v[j] == i) break;
    return j != 3;
}
/* localdecomp:end func_0039AC08 */

LINKER_REMNANT("asm/remnants", func_0039AC98);

typedef struct { u8 *data; u8 *clut; u8 pad8[0xC]; s32 f14; u8 pad18[0x34]; s32 tw; s32 th; u8 pad54[4]; } T_395EB8;
typedef struct { u8 *data; s16 f4; s16 f6; u8 *clut; u8 tw; u8 th; s16 fE; } E_395EB8;
extern s32 D_001D4BB0;
extern s32 D_001D9BFC;
extern E_395EB8 D_00225C00[];
INCLUDE_ASM("asm/nonmatchings/text", func_0039ACA8);

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
INCLUDE_ASM("asm/nonmatchings/text", func_0039ADE0);

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
INCLUDE_ASM("asm/nonmatchings/text", func_0039AEF0);

typedef struct { u8 p0[8]; s32 f8; u8 pC[4]; s32 f10; u8 p14[0x168]; s32 f17C; } S_142430_00396120;
extern S_142430_00396120 D_142430_0039AF10;
extern s32 D_001D4CE8_00396122;
extern s32 D_001D4CEC_00396122;
extern s32 D_001D4CE8_0039AF10;
extern s32 D_001D4CEC_0039AF10;
INCLUDE_ASM("asm/nonmatchings/text", func_0039AF10);

/* func_0039B038 (frontbin).
   The US draft (rac3-uya-decomp func_00396248) reached the flag global through
   $gp, as a sized scalar. PAL retail stores it with the compiler's lui/%lo
   pair (lui $at; sw %lo($at)), which a sized scalar cannot produce with this
   file's flags: an unsized array gives gcc's split form (lui $v1; sw %lo($v1))
   and the scheduler hoists that lui into the branch delay slot. Retail's form
   is the assembler's expansion of a store to a global it does not know to be
   small: the store goes through an alias declared sized and again with a section attribute (gcc leaves the access to the assembler as one macro, and without gcc's `.extern` size hint the assembler does not know the global is small and expands it with lui, as SN's single-pass Ps2EeAs did). */

/* localdecomp:start func_0039B038 */
extern s32 D_001D4CE8_0039B038;
extern s32 D_001D4CE8_0039B038 __attribute__((section(".bss")));
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
INCLUDE_ASM("asm/nonmatchings/text", func_0039B088);

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
extern s32 D_001D4CE8_0039B0D8 __attribute__((section(".bss")));
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
INCLUDE_ASM("asm/nonmatchings/text", func_0039B100);

/* PAL candidate for func_0039B168.
   0x1D4CEC and 0x1D4CE8 are read and written with lui/%hi+%lo, through
   an alias declared sized and again with a section attribute (gcc leaves the access to the assembler as one macro, and without gcc's `.extern` size hint the assembler does not know the global is small and expands it with lui, as SN's single-pass Ps2EeAs did); D_001D4CE8_g (a plain s32) stays $gp relative, as retail has it. */

/* localdecomp:start func_0039B168 */
extern s32 D_001D4CEC_0039B168;
extern s32 D_001D4CE8_0039B168;
extern s32 D_001D4CEC_0039B168 __attribute__((section(".bss")));
extern s32 D_001D4CE8_0039B168 __attribute__((section(".bss")));
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
extern s32 D_001D4CEC_0039B1B8 __attribute__((section(".bss")));
extern u8 D_001D5BDC_0039B1B8 __attribute__((section(".bss")));
extern s32 D_001D4CE8_0039B1B8_lui __attribute__((section(".bss")));
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
INCLUDE_ASM("asm/nonmatchings/text", func_0039B278);

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
INCLUDE_ASM("asm/nonmatchings/text", func_0039B328);

/* func_0039B380: from the US C of func_00396590 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_0039B380 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern s32 D_001D4CE8_0039B380_lui;
extern s32 D_001D4CE8_0039B380_lui __attribute__((section(".bss")));
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
   through an alias declared sized and again with a section attribute (gcc leaves the access to the assembler as one macro, and without gcc's `.extern` size hint the assembler does not know the global is small and expands it with lui, as SN's single-pass Ps2EeAs did). */

/* localdecomp:start func_0039B418 */
extern s32 D_001D4CE8_0039B418;
extern s32 D_001D4CEC_0039B418_lui;
extern s32 D_001D4CE8_0039B418 __attribute__((section(".bss")));
extern s32 D_001D4CEC_0039B418_lui __attribute__((section(".bss")));
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
   the D_00142438[0] access, so it goes through an alias declared sized and again with a section attribute (gcc leaves the access to the assembler as one macro, and without gcc's `.extern` size hint the assembler does not know the global is small and expands it with lui, as SN's single-pass Ps2EeAs did). */

/* localdecomp:start func_0039B570 */
extern s32 D_001D4CE8_0039B570;
extern s32 D_001D4CE8_0039B570 __attribute__((section(".bss")));
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
extern u8 D_001D5BDC_0039B5B0 __attribute__((section(".bss")));
extern s32 D_001D4CE8_0039B5B0_lui __attribute__((section(".bss")));
/* PAL candidate for func_0039B5B0.
   The retail code reaches two of the globals through lui + offset instead of
   $gp, so those two accesses go through an alias declared sized and again with a section attribute (gcc leaves the access to the assembler as one macro, and without gcc's `.extern` size hint the assembler does not know the global is small and expands it with lui, as SN's single-pass Ps2EeAs did). */

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
INCLUDE_ASM("asm/nonmatchings/text", func_0039B620);

typedef struct { u8 pad[0x18]; s16 f18; u8 padA[0x12E]; s32 f148; u8 padB[0x10]; s32 f15C; u8 pad2[4]; s32 f164; u8 pad3[4]; s32 f16C; } S_396890;
extern S_396890 D_142430_0039B680;
extern s32 D_001D4CEC_0039B680;
extern s32 D_001D4CE8_0039B680;
INCLUDE_ASM("asm/nonmatchings/text", func_0039B680);

/* PAL candidate for func_0039B6E8 (US draft func_003968F8).
   Retail reaches 0x1D4CEC and 0x1D4CE8 both through $gp and through lui,
   so the two forms need two spellings of the same address. */

/* localdecomp:start func_0039B6E8 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern s32 D_001D4CEC_0039B6E8_lui;
extern s32 D_001D4CE8_0039B6E8_lui;
extern s32 D_001D4CEC_0039B6E8_lui __attribute__((section(".bss")));
extern s32 D_001D4CE8_0039B6E8_lui __attribute__((section(".bss")));
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
extern s32 D_001D4CE8_0039B7A8 __attribute__((section(".bss")));
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
   the absolute accesses go through an alias declared sized and again with a section attribute (gcc leaves the access to the assembler as one macro, and without gcc's `.extern` size hint the assembler does not know the global is small and expands it with lui, as SN's single-pass Ps2EeAs did), and the two $gp ones through the
   sized scalar aliases (D_001D4CE8_g / D_001D4CEC_g, small data). */

/* localdecomp:start func_0039B818 */
extern s32 D_001D4CEC_0039B818;
extern s32 D_001D4CE8_0039B818;
extern s32 D_001D4CEC_0039B818 __attribute__((section(".bss")));
extern s32 D_001D4CE8_0039B818 __attribute__((section(".bss")));
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
extern s32 D_001D4CEC_0039B8D0 __attribute__((section(".bss")));
extern s32 D_001D4CE8_0039B8D0 __attribute__((section(".bss")));
extern s32 D_001D4CEC[];
extern s32 D_001D4CE8[];

/* Retail reads the flag through the address register itself
   (lui $v0,0x1D / lw $v0,0x4CEC($v0)) and writes the state through $at
   (lui $at,0x1D / sw $v0,0x4CE8($at)): the assembler's expansions. Under this
   file's flags (split addresses) unsized globals give gcc's split form instead
   (lui $v1 / lw $v0,0x4CEC($v1)), which is what the US needed
   -mno-split-addresses for; both go through an alias declared sized and again with a section attribute (gcc leaves the access to the assembler as one macro, and without gcc's `.extern` size hint the assembler does not know the global is small and expands it with lui, as SN's single-pass Ps2EeAs did). */
void func_0039B8D0(void) {
    if (!(D_001D4CEC_0039B8D0 & 0x40)) {
        D_001D4CE8_0039B8D0 = 4;
    }
}
/* localdecomp:end func_0039B8D0 */

/* localdecomp:start func_0039B8F8 */
extern s32 D_001D4CEC_0039B8F8;
extern s32 D_001D4CE8_0039B8F8;
extern s32 D_001D4CEC_0039B8F8 __attribute__((section(".bss")));
extern s32 D_001D4CE8_0039B8F8 __attribute__((section(".bss")));
/* PAL candidate for func_0039B8F8.
   With an unsized symbol gcc splits the address over two registers ($v1 for
   the high half, $v0 for the loaded word); the assembler's expansion puts the
   high half in the load's own register and uses $at for the store. Retail does
   the latter (see func_0039BA10, func_0039B278, func_0039C048), so the two
   globals go through an alias declared sized and again with a section attribute (gcc leaves the access to the assembler as one macro, and without gcc's `.extern` size hint the assembler does not know the global is small and expands it with lui, as SN's single-pass Ps2EeAs did). */

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
 * goes through an alias declared sized and again with a section attribute (gcc leaves the access to the assembler as one macro, and without gcc's `.extern` size hint the assembler does not know the global is small and expands it with lui, as SN's single-pass Ps2EeAs did).
 */

/* localdecomp:start func_0039B940 */
extern s32 D_001D4CE8_0039B940;
extern s32 D_001D4CE8_0039B940 __attribute__((section(".bss")));
extern s32 D_00142438[];
void func_0039B940(void) {
    if (D_00142438[0] != 2) {
        D_001D4CE8_0039B940 = 4;
    }
}
/* localdecomp:end func_0039B940 */

/* PAL candidate for func_0039B968.
   The D_001D4CEC / D_001D4CE8 accesses go through an alias declared sized and again with a section attribute (gcc leaves the access to the assembler as one macro, and without gcc's `.extern` size hint the assembler does not know the global is small and expands it with lui, as SN's single-pass Ps2EeAs did): with an unsized
   symbol gcc splits the address into lui $v1 / lw $v0, the retail wants the high half
   in the destination register. */


/* localdecomp:start func_0039B968 */
extern s32 D_001D4CEC_0039B968;
extern s32 D_001D4CE8_0039B968;
extern s32 D_001D4CEC_0039B968 __attribute__((section(".bss")));
extern s32 D_001D4CE8_0039B968 __attribute__((section(".bss")));
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

typedef struct { u8 pad[0x15C]; s32 f15C; u8 pad2[4]; s32 f164; u8 pad3[4]; s32 f16C; } S_396BC0;
extern S_396BC0 D_142430_0039B9B0;
extern s32 D_001D4CEC_0039B9B0;
extern s32 D_001D4CE8_0039B9B0;
INCLUDE_ASM("asm/nonmatchings/text", func_0039B9B0);

/* Candidate for func_0039BA10 (PAL retail).
   The retail accesses both globals in the assembler's "lui + 16-bit offset"
   form with the destination reused: through an alias declared sized and again with a section attribute (gcc leaves the access to the assembler as one macro, and without gcc's `.extern` size hint the assembler does not know the global is small and expands it with lui, as SN's single-pass Ps2EeAs did). */

/* localdecomp:start func_0039BA10 */
extern s32 D_001D4CEC_0039BA10;
extern s32 D_001D4CE8_0039BA10;
extern s32 D_001D4CEC_0039BA10 __attribute__((section(".bss")));
extern s32 D_001D4CE8_0039BA10 __attribute__((section(".bss")));
void func_0039BA10(void) {
    if (!(D_001D4CEC_0039BA10 & 0x40)) D_001D4CE8_0039BA10 = 4;
}
/* localdecomp:end func_0039BA10 */

typedef struct { u8 pad0[0x24]; s32 f24; u8 pad28[0x15C - 0x28]; s32 f15C; s32 pad160; s32 f164; s32 pad168; s32 f16C; u8 pad170[0xC]; s32 f17C; } S_00396C48;
extern S_00396C48 D_00142430_0039BA38[];
extern void (*D_001D62F8)();
extern s32 D_001D4CE8_0039BA38;
extern s32 D_001D4CEC_0039BA38;
INCLUDE_ASM("asm/nonmatchings/text", func_0039BA38);

typedef struct { u8 p0[8]; s32 f8; u8 p1[4]; s32 f10; u8 p2[0x15C-0x14]; s32 f15C; u8 p3[4]; s32 f164; u8 p4[4]; s32 f16C; u8 p5[0x17C-0x170]; s32 f17C; } S_396CE8;
extern S_396CE8 D_142430_0039BAD8[];
extern s32 D_001D4CE8_0039BAD8;
extern s32 D_001D4CEC_0039BAD8;
#define P D_142430_0039BAD8[0]
INCLUDE_ASM("asm/nonmatchings/text", func_0039BAD8);

typedef struct { u32 b0:5; u32 f5:1; u32 b6:7; u32 f13:1; u32 rest:18; } S_396D70;
extern s32 D_00142438[];
extern s32 D_001D4CE8_0039BB60;
extern union { s32 i; S_396D70 b; } D_001D4CEC_0039BB60;
INCLUDE_ASM("asm/nonmatchings/text", func_0039BB60);

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

extern s32 D_00142438[];
extern u32 D_001D4CEC_0039BC10;
extern s32 D_001D4CE8_0039BC10;
extern void func_0039C028(void);
INCLUDE_ASM("asm/nonmatchings/text", func_0039BC10);

/* func_0039BC70: from the US C of func_00396E80 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags.

   PAL candidate.  Retail reaches 0x1D4CEC through $gp for the load but through lui/%lo for
   the store, and reaches 0x1D9FA8 through lui/%lo too: the load keeps a sized (small data)
   declaration; the stores go through `lui $at`, the assembler's expansion of a store to a
   global it does not know to be small (SN's single-pass Ps2EeAs had not seen their sizes
   yet). Those globals are declared sized (gcc leaves the store to the assembler as one macro)
   and again with a section attribute, which keeps gcc's `.extern` size hint out of the
   assembly. */


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
extern s32 D_001D4CEC_0039BC70 __attribute__((section(".bss")));
extern s8 D_001D9FA8 __attribute__((section(".bss")));
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
INCLUDE_ASM("asm/nonmatchings/text", func_0039BD08);

/* localdecomp:start func_0039BD90 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern s32 D_001D4CEC_0039BD90_lui;
extern s32 D_001D4CEC_0039BD90_lui __attribute__((section(".bss")));
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

typedef struct { u8 pad0[0x10]; s32 f10; u8 pad14[0x148 - 0x14]; s32 f148; } S_396FD0;
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, rest:17; } F_4CEC_396FD0;
extern S_396FD0 D_00142430_0039BDC0[];
extern s32 D_001D62FC_0039BDC0;
extern s32 D_001D6300_0039BDC0;
extern s32 D_001D6308_0039BDC0;
extern s32 D_001D62F4;
extern s32 D_001D62F8_0039BDC0;
extern s32 D_001D6304_0039BDC0;
extern s8 D_001D9FA8;
extern F_4CEC_396FD0 D_001D4CEC_f_396FD0;
extern s8 D_001D9FA0;
extern void func_0039C028(void);
INCLUDE_ASM("asm/nonmatchings/text", func_0039BDC0);

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
extern s32 D_001D4CEC_0039BE70_lui __attribute__((section(".bss")));
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
extern s32 D_001D4CEC_0039BE90_lui __attribute__((section(".bss")));
extern s32 D_001D4CEC_0039BE90;
void func_0039BE90(void) {
    /* retail reaches the flag through lui/lw for the read and through $gp for
       the write; the read's alias (sized, then with a section attribute that
       keeps gcc's .extern size hint out) gives the assembler's reused-register
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
extern u8 D_001D9FA8_0039BEA8 __attribute__((section(".bss")));
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
   through an alias declared sized and again with a section attribute (gcc leaves the access to the assembler as one macro, and without gcc's `.extern` size hint the assembler does not know the global is small and expands it with lui, as SN's single-pass Ps2EeAs did)), and writes the word back through $gp (a sized scalar). */

/* localdecomp:start func_0039BFD8 */
extern s32 D_001D4CEC_0039BFD8;
extern s32 D_001D4CEC_0039BFD8 __attribute__((section(".bss")));
extern s32 D_001D4CEC_g;
void func_0039BFD8(void) {
    D_001D4CEC_g = D_001D4CEC_0039BFD8 | 0x20;
}
/* localdecomp:end func_0039BFD8 */

/* localdecomp:start func_0039BFF0 */
extern s32 D_001D4CEC_0039BFF0;
extern s32 D_001D4CEC_0039BFF0 __attribute__((section(".bss")));
/* func_0039BFF0: clears five bits of the flag word at 0x001D4CEC.
   The word is read with lui/lw (the assembler's expansion, through an alias declared sized and again with a section attribute (gcc leaves the access to the assembler as one macro, and without gcc's `.extern` size hint the assembler does not know the global is small and expands it with lui, as SN's single-pass Ps2EeAs did))
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
extern s32 D_001D4CEC_0039C028 __attribute__((section(".bss")));
/* PAL candidate for func_0039C028.
 *
 * Retail reads the flags word with lui/lw (the assembler's expansion, through
 * an alias declared sized and again with a section attribute (gcc leaves the access to the assembler as one macro, and without gcc's `.extern` size hint the assembler does not know the global is small and expands it with lui, as SN's single-pass Ps2EeAs did)) and writes it
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
   an alias declared sized and again with a section attribute (gcc leaves the access to the assembler as one macro, and without gcc's `.extern` size hint the assembler does not know the global is small and expands it with lui, as SN's single-pass Ps2EeAs did). */

/* localdecomp:start func_0039C048 */
extern s32 D_001D4CEC_0039C048;
extern s32 D_001D4CEC_0039C048 __attribute__((section(".bss")));
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
 * The read goes through an alias declared sized and again with a section attribute (gcc leaves the access to the assembler as one macro, and without gcc's `.extern` size hint the assembler does not know the global is small and expands it with lui, as SN's single-pass Ps2EeAs did);
 * the write is a plain sized global, so it goes through $gp. One word, two
 * address forms.
 */

extern s32 D_001D4CEC_g;
/* localdecomp:start func_0039C060 */
extern s32 D_001D4CEC_0039C060;
extern s32 D_001D4CEC_0039C060 __attribute__((section(".bss")));
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

typedef struct { u8 pad[0x64C]; s32 f64C; u8 p650[0x10]; s32 f660; s32 f664; } S_160C40_00397380;
typedef struct { u8 pad[0x18]; s16 f18; u8 p1A[0x162]; s32 f17C; } S_142430_00397380;
typedef struct { u8 pad[0x18]; s32 f18; u8 p1C[0x14]; s32 f30; } S_16C580_00397380;
extern S_160C40_00397380 D_160C40_0039C300;
extern S_142430_00397380 D_142430_0039C300;
extern S_16C580_00397380 D_16C580_0039C300;
extern u8 D_00143950_0039C300[];
extern s32 D_001D545C_0039C300;
extern s32 D_001D4B60_0039C300, D_001D4CEC_0039C300, D_001D4B90_0039C300, D_001D4BA0_0039C300;
extern void func_00392F08();
extern s32 func_003A2750();
extern s32 func_003A26F0();
extern void func_0038CC88();
INCLUDE_ASM("asm/nonmatchings/text", func_0039C300);

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
typedef struct { u8 p0[0x10]; s32 size; u8 p14[0xC]; u8 name[0x20]; } DE_397490;
typedef struct { s32 type; s32 size; u8 d[0x40]; } E_397490;
typedef struct { u8 p0[0x48]; s32 f48; } S_142660_397490;
extern S_397490 D_142430_0039C410;
extern S_142660_397490 D_142660;
extern DE_397490 D_0022CCC0[];
extern u8 D_0022CCE0[];
extern char D_001D5378[], D_001D5390[], D_001D53A8[], D_001D53BD[], D_001D53C8[], D_001D53DD[], D_001D53E8[];
extern char D_001D53FD[], D_001D5418[], D_001D542D[], D_001D5438[];
extern u32 D_001D545C;
extern char D_001D6348[], D_001D6350[], D_001D6358[], D_001D6360[], D_001D6380[], D_001D63A0[];
extern char D_001D63C0[], D_001D63E0[], D_001D6400[], D_001D6420[];
extern s32 D_001D6318;
extern s16 D_001CCFD4[];
extern u8 D_001C5BD0[], D_001C5BD8[], D_001CBBD0[];
extern s32 func_12E2E0(s32, s32 *, s32 *);
extern s32 func_12E400(s32, s32, s32 *, s32 *, s32 *);
extern s32 func_12E6D8(s32, s32);
extern s32 func_12E8D8(s32, s32);
extern s32 func_12E580(s32, s32, char *, s32, s32, void *);
extern s32 func_0011A264(s32, s32, s32);
extern s32 func_11B610(u8 *, char *);
extern s32 func_11B9A0(u8 *, char *, s32);
extern void func_11B754();
extern s32 func_11B2E8();
extern s32 func_12DCA0(s32, s32, char *, s32);
extern s32 func_12E050(s32, void *, s32);
extern s32 func_12E168(s32, void *, s32);
extern s32 func_12DE00(s32);
extern s32 func_12DDC8(s32, s32, char *);
extern s32 func_12E7A8(s32, s32, char *);
extern s32 func_12DEC0(s32, s32, s32);
extern s32 func_003A2598(s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_0039C410);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C130);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C1B0);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C1D0);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C240);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C290);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C2E0);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C300);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C330);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C360);

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

INCLUDE_ASM("asm/nonmatchings/text", func_0039E688);

LINKER_REMNANT("asm/remnants", func_0039E6A0);

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
INCLUDE_ASM("asm/nonmatchings/text", func_0039EED8);

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
   and again with a section attribute, which keeps gcc's `.extern` size hint
   out of the assembly (see func_0039BC70). */

extern s32 D_00333AC8[];
extern s32 D_001D9FC0;
extern s32 D_001D9FC0 __attribute__((section(".bss")));

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

typedef struct { s32 p[3]; s32 fC; } E_39A3B0;
extern u8 D_1D5530[8];
extern u8 D_142CA0[];
extern u8 D_142D40[];
extern E_39A3B0 D_143230_0039F348[];
extern u8 D_1426E0[];
extern u32 D_142BA0[];
extern u8 D_1BBB18[];
extern u8 D_1D5570[];
extern s32 func_00381D48_0039F348(s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_0039F348);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C380);

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
INCLUDE_ASM("asm/nonmatchings/text", func_0039F580);

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

typedef struct { u8 b[0x20]; } R_39AE08;
typedef struct { u8 p0[0x80]; f32 f80; f32 f84; f32 f88; } S_39AE08;
extern u8 D_001D68E0[8];
extern u8 D_001D6900[8];
extern u8 D_001D6920[8];
extern u8 D_001D6960[8];
extern u8 D_001D6980[8];
extern u8 D_001D69A0[8];
extern u8 D_001D69C0[8];
extern u8 D_001D69E0[8];
extern u8 D_001D6A00[8];
extern u8 D_001D6A20[8];
extern u8 D_001D6A40[8];
extern u8 D_001D6A60[8];
extern R_39AE08 D_00333BB8[];
extern R_39AE08 D_00334398;
extern R_39AE08 D_00334378;
extern R_39AE08 D_00334358;
extern R_39AE08 D_00333CD8;
extern R_39AE08 D_00333E18;
extern R_39AE08 D_00333E58;
extern R_39AE08 D_00333E98;
extern s32 D_0022CC50[];
extern f32 D_001A4C60[];
extern S_39AE08 D_1A4BE0_0039FDA0;
extern u8 D_001A71C4[];
INCLUDE_ASM("asm/nonmatchings/text", func_0039FDA0);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C3B0);

LINKER_REMNANT("asm/remnants", func_003A0080);

/* func_003A0090: from the US C of func_0039B0F8 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_003A0090 */
extern u32 D_001D545C_003A0090;
extern u32 D_001D545C_003A0090 __attribute__((section(".bss")));
typedef struct { u8 pad[0x10]; f32 f10; f32 f14; u8 pad2[0xE0]; f32 fF8; } O_39B0F8;
typedef struct { f32 x, y, z, w; } V_39B0F8;
/* retail reaches 0x1D545C with lui/lw (destination reused), not through $gp:
   the load goes through an alias declared sized and again with a section attribute (gcc leaves the access to the assembler as one macro, and without gcc's `.extern` size hint the assembler does not know the global is small and expands it with lui, as SN's single-pass Ps2EeAs did) */
extern s32 D_003374F0[];
extern O_39B0F8 *D_0022C8E0[];
extern V_39B0F8 D_143230[];
void func_003A0090(void) {
    u32 idx = D_001D545C_003A0090;
    s32 i;
    if (idx < 0x13) {
        for (i = D_003374F0[idx]; i < D_003374F0[idx + 1]; i++) {
            O_39B0F8 *o = D_0022C8E0[i];
            if (o) {
                D_143230[i].x = o->f10;
                D_143230[i].y = o->f14;
                D_143230[i].z = o->fF8;
            }
        }
    }
}
/* localdecomp:end func_003A0090 */

INCLUDE_ASM("asm/nonmatchings/text", func_003A0130);
TEXT_PADDING(8);
