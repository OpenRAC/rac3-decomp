#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_003D9338(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0038CC88_00391678(void *, void *, s32) __asm__("func_0038CC88");
/* --- end of declarations from other files --- */

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
