#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_003D8640(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003D8640();


INCLUDE_ASM("asm/nonmatchings/text", func_003D78E0);

/* func_003D7D30: from the US C of func_003D27C0 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags.

   PAL: retail reaches D_001D5608/D_001D5610/D_001D5614/D_001D561C through $gp and
   D_001D5624/D_001D560C/D_001D5620/D_001D55EC with lui/%lo, so the second group is declared
   to the assembler as not small data (the same trick the matched func_003D9100 of this
   file uses for its own globals). */


/* localdecomp:start func_003D7D30 */
extern s32 func_003D6A20_003D7D30(s32 *, s32);
extern void func_003D7DE8(void);
extern void func_003D8500(void);
__asm__(".extern D_001D5608, 4");
__asm__(".extern D_001D5610, 4");
__asm__(".extern D_001D5614, 4");
__asm__(".extern D_001D561C, 4");
__asm__(".extern D_001D5624, 16");
__asm__(".extern D_001D560C, 16");
__asm__(".extern D_001D5620, 16");
__asm__(".extern D_001D55EC, 16");
extern s32 D_001D5608, D_001D5610, D_001D5614, D_001D561C;
extern s32 D_001D5624, D_001D560C, D_001D5620, D_001D55EC;
extern s32 D_001A1ED4[];
void func_003D7D30(void) {
    s32 p, r1, r2, r3;
    D_001D5608 = 0x3FA000;
    D_001D560C = 0x3FE000;
    D_001D5624 = 0x400000;
    p = 0x379000;
    r1 = func_003D6A20_003D7D30(&p, 0x40000);
    p = 0x379000;
    D_001D5614 = r1;
    r2 = func_003D6A20_003D7D30(&p, 0x40000);
    D_001D561C = r2;
    r3 = func_003D6A20_003D7D30(&p, 0x40000);
    D_001D5620 = r3;
    D_001D5610 = D_001A1ED4[0];
    func_003D7DE8();
    func_003D8500();
    D_001D55EC = D_001D55EC | 1;
}
/* localdecomp:end func_003D7D30 */

extern s32 D_001D0A50[];
extern s32 D_001D5600, D_001D5604, D_001D5608_003D7DE8, D_001D5610_003D7DE8, D_001D5614_003D7DE8, D_001D561C_003D7DE8, D_001D5620, D_001D55F0;
extern u8 D_001D936C;
extern s32 D_001D9350, D_001D9354, D_001D9358, D_001D935C;
extern void func_003D6EE8(long **, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003D78E0(long **, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003D7DE8);

extern s32 D_001D5608_003D8500, D_001D5620, D_001D561C_003D8500, D_001D9360, D_001D55F4;
extern u8 D_001D2A50[];
extern void func_003D6BC0(u8 **, s32, s32, s32, s32, s32, s32);
/* localdecomp:start func_003D8500 */
__asm__(".extern D_001D9360, 4");
extern s32 D_001D5608_003D8500, D_001D5620, D_001D561C_003D8500, D_001D9360, D_001D55F4;
extern u8 D_001D2A50[];
extern void func_003D72B0(u8 **, s32, s32, s32, s32, s32, s32);
extern void func_003D7850();
extern void func_003D6BC0(u8 **, s32, s32, s32, s32, s32, s32);
void func_003D8500(void) {
    u8 *p = D_001D2A50;
    func_003D72B0(&p, D_001D5608_003D8500, 0x40, 0x40, D_001D5620, 0x80, 0x80);
    func_003D72B0(&p, D_001D5620, 0x80, 0x80, D_001D561C_003D8500, 0x100, 0x100);
    func_003D7850(&p, D_001D561C_003D8500, D_001D5620);
    func_003D6BC0(&p, D_001D561C_003D8500, 0x100, 0x100, 1, 0, D_001D9360);
    D_001D55F4 = p - D_001D2A50;
}
/* localdecomp:end func_003D8500 */

extern s32 D_001D55F0;
extern u32 *D_001DA050;
extern s32 D_001D934C;
extern s32 D_001D0A50[];
/* localdecomp:start func_003D85C0 */
extern s32 D_001D55F0_003D85C0;
extern u32 *D_001DA050_003D85C0;
__asm__(".extern D_001D934C_003D85C0, 4");
extern s32 D_001D934C_003D85C0;
extern s32 D_001D0A50_003D85C0[];
void func_003D85C0(void) {
    D_001D934C_003D85C0 = 0x6000;
    D_001DA050_003D85C0[0] = (D_001D55F0_003D85C0 >> 4) | 0x30000000;
    D_001DA050_003D85C0[1] = (u32)D_001D0A50_003D85C0;
    D_001DA050_003D85C0[2] = 0;
    D_001DA050_003D85C0[3] = (D_001D55F0_003D85C0 >> 4) | 0x50000000;
    D_001DA050_003D85C0 += 4;
}
/* localdecomp:end func_003D85C0 */

/* localdecomp:start func_003D8640 */
__asm__(".extern D_001D934C, 4");
extern u32 *D_001DA050;
extern s32 D_001D55F4;
extern u8 D_001D2A50[];
extern s32 D_001D934C;
void func_003D8640(void) {
    D_001DA050[0] = (D_001D55F4 >> 4) | 0x30000000;
    D_001DA050[1] = (u32)D_001D2A50;
    D_001DA050[2] = 0;
    D_001DA050[3] = (D_001D55F4 >> 4) | 0x50000000;
    D_001D934C = 0;
    D_001DA050 += 4;
}
/* localdecomp:end func_003D8640 */

extern s32 D_001A1ED0[];
/* localdecomp:start func_003D86B8 */
extern s32 D_001A1ED0_003D86B8[];
void func_003D86B8(unsigned long **pp, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    *(*pp)++ = 0x7000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = 0;
    *(*pp)++ = 0x19;
    *(*pp)++ = ((long)(a1 - 1) << 16) | ((long)(a2 - 1) << 48);
    *(*pp)++ = 0x41;
    *(*pp)++ = ((long)D_001A1ED0_003D86B8[2] >> 13) | ((long)a3 << 16) | 0xFF00000001000000UL;
    *(*pp)++ = 0x4D;
    *(*pp)++ = 0x30802;
    *(*pp)++ = 0x48;
    *(*pp)++ = (D_001A1ED0_003D86B8[2] >> 13) | 0x31000000 | 0x100000000UL;
    *(*pp)++ = 0x4F;
    *(*pp)++ = 0x80000000A4UL;
    *(*pp)++ = 0x43;
    *(*pp)++ = 0x4400000000000001UL;
    *(*pp)++ = 0x5510;
    *(*pp)++ = 0x346;
    *(*pp)++ = 0xFFFFFFFFUL;
    *(*pp)++ = (long)a4 | ((long)a5 << 16);
    *(*pp)++ = (long)a6 | ((long)a7 << 16);
    *(*pp)++ = 0x3000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = (D_001A1ED0_003D86B8[2] >> 13) | 0x31000000;
    *(*pp)++ = 0x4F;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
}
/* localdecomp:end func_003D86B8 */

extern s32 D_001A1ED0[];
/* localdecomp:start func_003D8998 */
extern s32 D_001A1ED0_003D8998[];
void func_003D8998(unsigned long **pp, s32 a1) {
    s32 i;
    s32 x0, x1;
    long step0, step1; /* steps kept in registers, not folded into the adds */
    *(*pp)++ = 0x8000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = (D_001A1ED0_003D8998[1] >> 13) | 0x2080000 | 0x3FFF00000000UL;
    *(*pp)++ = 0x4D;
    *(*pp)++ = (D_001A1ED0_003D8998[2] >> 13) | 0x31000000 | 0x100000000UL;
    *(*pp)++ = 0x4F;
    *(*pp)++ = 0x30000;
    *(*pp)++ = 0x48;
    *(*pp)++ = 0;
    *(*pp)++ = 0x19;
    *(*pp)++ = 0x33F000001FF0000UL;
    *(*pp)++ = 0x41;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = 0;
    *(*pp)++ = 0x15;
    if (a1) {
        *(*pp)++ = (D_001A1ED0_003D8998[2] >> 8) | 0x2B220000 | 0x680000000UL;
        *(*pp)++ = 7;
    } else {
        *(*pp)++ = 7;
        *(*pp)++ = (D_001A1ED0_003D8998[2] >> 8) | 0x2B220000 | 0xE80000000UL;
    }
    *(*pp)++ = 0x2400000000000001UL;
    *(*pp)++ = 1;
    if (a1) {
        *(*pp)++ = 0x3F80000040808080UL;
    } else {
        *(*pp)++ = 0x3F80000080808080UL;
    }
    *(*pp)++ = 0x316;
    *(*pp)++ = 0x4400000000008020UL;
    *(*pp)++ = 0x5353;
    x0 = 8;
    x1 = 8;
    step0 = 0x10;
    step1 = 0x10;
    for (i = 0; i < 32; i++) {
        *(*pp)++ = ((x0 << 4) - 0x78) | 0x80000;
        *(*pp)++ = x1 << 4;
        *(*pp)++ = ((x0 << 4) + 8) | 0x34080000;
        *(*pp)++ = ((x1 << 4) + 0x80) | 0x34000000;
        x0 += step0;
        x1 += step1;
    }
}
/* localdecomp:end func_003D8998 */

typedef struct { s32 f0; s32 f4; s32 f8; } T_3D3780;
extern T_3D3780 D_001A1ED0_003D8CF0;
INCLUDE_ASM("asm/nonmatchings/text", func_003D8CF0);

extern s32 D_001D5600_003D8FC0;
extern s32 D_001D5604_003D8FC0;
extern s32 D_001D5628_003D8FC0;
extern s32 D_001D5630_003D8FC0;
extern s32 D_001D5634_003D8FC0;
extern s32 D_001D55F8_003D8FC0;
extern u8 D_001D3650_003D8FC0[];
/* localdecomp:start func_003D8FC0 */
__asm__(".extern D_001D5634_003D8FC0_003D8FC0, 4");
extern s32 D_001D5600_003D8FC0_003D8FC0;
extern s32 D_001D5604_003D8FC0_003D8FC0;
extern s32 D_001D5628_003D8FC0_003D8FC0;
extern s32 D_001D5630_003D8FC0_003D8FC0;
extern s32 D_001D5634_003D8FC0_003D8FC0;
extern s32 D_001D55F8_003D8FC0_003D8FC0;
extern u8 D_001D3650_003D8FC0_003D8FC0[];
extern void func_003D72B0_003D8FC0(u8 **, s32, s32, s32, s32, s32, s32);
extern void func_003D7850_003D8FC0();
void func_003D8FC0(void) {
    u8 *p;
    unsigned long *q = (unsigned long *)D_001D3650_003D8FC0_003D8FC0;
    q[0] = 0x5000000000000001UL;
    q[1] = 0xEEEEEEEEEEEEEEEEUL;
    q[2] = 0;
    q[3] = 0x3F;
    q[4] = 0xA0000000A0UL;
    q[5] = 0x19;
    q[6] = 0x100000000UL;
    q[7] = 0x4F;
    q[8] = 0x60;
    q[9] = 0x15;
    q[10] = 5;
    q[11] = 9;
    p = D_001D3650_003D8FC0_003D8FC0 + 0x60;
    func_003D72B0_003D8FC0(&p, D_001D5630_003D8FC0_003D8FC0, D_001D5600_003D8FC0_003D8FC0, D_001D5604_003D8FC0_003D8FC0, D_001D5628_003D8FC0_003D8FC0, 0x100, 0x100);
    func_003D7850_003D8FC0(&p, D_001D5628_003D8FC0_003D8FC0, D_001D5634_003D8FC0_003D8FC0);
    func_003D7850_003D8FC0(&p, D_001D5628_003D8FC0_003D8FC0, D_001D5634_003D8FC0_003D8FC0);
    D_001D55F8_003D8FC0_003D8FC0 = p - D_001D3650_003D8FC0_003D8FC0;
}
/* localdecomp:end func_003D8FC0 */

/* localdecomp:start func_003D9100 */
extern s32 D_001D5600_003D9100;
__asm__(".extern D_001D5600_003D9100, 16");
extern s32 D_001D5604_003D9100;
__asm__(".extern D_001D5604_003D9100, 16");
extern s32 D_001D5628_003D9100;
__asm__(".extern D_001D5628_003D9100, 16");
extern s32 D_001D55FC_003D9100;
__asm__(".extern D_001D55FC_003D9100, 16");
extern u8 D_001D3EF0[];
extern s32 func_003D86B8();
extern s32 func_003D8998();
extern s32 func_003D8CF0();
extern void func_003D6BC0(u8 **, s32, s32, s32, s32, s32, s32);
void func_003D9100(void) {
    u8 *p;
    p = D_001D3EF0;
    func_003D86B8(&p, D_001D5600_003D9100, D_001D5604_003D9100, D_001D5600_003D9100 >> 6, 0, 0, (D_001D5600_003D9100 + 1) << 4, (D_001D5604_003D9100 + 1) << 4);
    func_003D8998(&p, 1);
    func_003D8CF0(&p, D_001D5600_003D9100, D_001D5604_003D9100, D_001D5600_003D9100 >> 6, 0, 0, (D_001D5600_003D9100 + 1) << 4, (D_001D5604_003D9100 + 1) << 4, 0xFF82FF);
    func_003D6BC0(&p, D_001D5628_003D9100, 0x100, 0x100, 0, 1, 0x80);
    D_001D55FC_003D9100 = (s32)p - (s32)D_001D3EF0;
}
/* localdecomp:end func_003D9100 */

extern void func_003D8FC0(void);
extern s32 D_001D5634;
extern s32 D_001D5630;
extern s32 D_001D5628;
extern s32 D_001A1ED4[];
extern s32 D_001D55EC;
/* localdecomp:start func_003D91F0 */
__asm__(".extern D_001D5634_003D91F0, 4");
__asm__(".extern D_001D5630_003D91F0, 4");
extern s32 func_003D6A20_003D91F0();
extern void func_003D8FC0_003D91F0(void);
extern void func_003D9100_003D91F0(void);
extern s32 D_001D5634_003D91F0;
extern s32 D_001D5630_003D91F0;
extern s32 D_001D5628_003D91F0;
extern s32 D_001A1ED4_003D91F0[];
extern s32 D_001D55EC_003D91F0;
void func_003D91F0(void) {
    s32 spv[4];
    spv[0] = 0x37C000;
    D_001D5634_003D91F0 = func_003D6A20_003D91F0(spv, 0x40000);
    D_001D5628_003D91F0 = func_003D6A20_003D91F0(spv, 0x40000);
    D_001D5630_003D91F0 = D_001A1ED4_003D91F0[0];
    func_003D8FC0_003D91F0();
    func_003D9100_003D91F0();
    D_001D55EC_003D91F0 |= 2;
}
/* localdecomp:end func_003D91F0 */

/* localdecomp:start func_003D9260 */
/* PAL candidate for func_003D9260 (frontbin).
 *
 * Retail reaches D_001D55F8, D_001D55FC and D_001DA050 through lui/lo, not
 * through $gp: the .extern size hints tell the assembler the globals are not
 * small data, so it expands the $gp access into lui + lw (or lui $at + sw).
 * The last store of the pointer is the one retail reaches through $gp (it
 * sits in the delay slot of the jr), so it uses a second name for the same
 * address, without a size hint.
 */

extern u32 *D_001DA050;
__asm__(".extern D_001DA050, 16");
extern u32 *D_001DA050_003D9260;
extern s32 D_001D55F8;
__asm__(".extern D_001D55F8, 16");
extern s32 D_001D55FC;
__asm__(".extern D_001D55FC, 16");
extern u8 D_001D3650[];
extern u8 D_001D3EF0[];

void func_003D9260(void) {
    D_001DA050[0] = (D_001D55F8 >> 4) | 0x30000000;
    D_001DA050[1] = (u32)D_001D3650;
    D_001DA050[2] = 0;
    D_001DA050[3] = (D_001D55F8 >> 4) | 0x50000000;
    D_001DA050 += 4;
    D_001DA050[0] = (D_001D55FC >> 4) | 0x30000000;
    D_001DA050[1] = (u32)D_001D3EF0;
    D_001DA050[2] = 0;
    D_001DA050[3] = (D_001D55FC >> 4) | 0x50000000;
    D_001DA050_003D9260 = D_001DA050 + 4;
}
/* localdecomp:end func_003D9260 */

/* func_003D9338: from the US C of func_003D3DC8 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_003D9338 */
extern s32 D_001D5604_003D9338;
__asm__(".extern D_001D5604_003D9338, 16");
typedef struct { u8 pad[0x150]; s16 h150; s16 h152; } S_1CFEC0;
extern S_1CFEC0 D_1CFEC0;
extern s32 D_001D5604;
extern s32 D_001D5600;
extern void func_003D7D30_003D9338();
extern void func_003D91F0();
void func_003D9338(void) {
    S_1CFEC0 *p = &D_1CFEC0;
    D_001D5600 = p->h150;
    /* retail reaches 0x001D5604 with lui $at + sw (not through $gp): with the
       default assembler no single declaration gives that mixed access, so the
       store goes through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did). */
    D_001D5604_003D9338 = p->h152;
    func_003D7D30_003D9338();
    func_003D91F0();
}
/* localdecomp:end func_003D9338 */
