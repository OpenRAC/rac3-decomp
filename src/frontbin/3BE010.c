#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u8 p0[0x44]; s16 n; u8 p1[0x15A]; void *slot[1]; } S_B7288;
extern S_B7288 D_00225700;
extern void func_003BE200(void);


extern u32 D_00142BA0[];
extern s32 D_001D6E90;
/* localdecomp:start func_003BE010 */
/* D_001D6E90 is reached through the absolute (lui %hi / %lo) form in the retail, not through $gp.
   That is the form the assembler picks for a global it may not reach through $gp, so the global is
   declared with a size above the -G8 small-data limit through an .extern hint (as the file's other
   block for D_001D6E90 does), so the assembler expands the store into "lui $at, %hi(sym)" /
   "sw .., %lo(sym)($at)" like the retail. */


extern u32 D_00142BA0[];
__asm__(".extern D_001D6E90, 16");
extern s32 D_001D6E90;
extern s32 func_003BB7C0();
extern s32 func_003BB7B8();
s32 func_003BE010(s32 a, s32 b, s32 c) {
    u32 w;
    if (a == -1 || func_003BB7C0() == a) {
        if (b == -1 || func_003BB7B8() == b) {
            w = (u32)c >> 2;
            if (!(D_00142BA0[w] & (1 << (c & 0x1F)))) {
                D_001D6E90 = c;
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_003BE010 */

/* func_003BE0C0 (frontbin, PAL).

   The retail bytes read the flag byte with the destination register reused as
   the address base:

       lui   $v0, 0x1d
       lbu   $v0, 0x558c($v0)

   That is the assembler's expansion of a load from a global.  With an unsized
   symbol, split addresses (this file's flags) give gcc's own shape, with a
   second register for the loaded byte:

       lui   $v0, 0x1d
       lbu   $v1, 0x558c($v0)

   so the flag is declared sized (gcc leaves the load to the
   assembler as one macro), with an `.extern X, 16` hint before its first use (docs/wiki/Matching-Patterns.md), so the assembler expands the macro
   with `lui` (as SN's single-pass Ps2EeAs did for a global whose size it had
   not seen yet). */

/* localdecomp:start func_003BE0C0 */
extern s32 func_003BE010(s32, s32, s32);
extern u8 D_001D558C;
__asm__(".extern D_001D558C, 16");
void func_003BE0C0(void) {
    if (func_003BE010(0x1C, 8, 0)) return;
    if (func_003BE010(8, 8, 0)) return;
    if (func_003BE010(8, 0x1B, 0)) return;
    if (func_003BE010(8, 0x1C, 0)) return;
    if (func_003BE010(-1, 8, 0x11)) return;
    if (D_001D558C != 0) func_003BE010(8, -1, 0x12);
}
/* localdecomp:end func_003BE0C0 */

void func_003A7480(s32);
void func_003A7618(s32);
extern s32 D_001D5B94;
extern s32 D_001D6E90;
typedef struct { u8 pad0[0x7]; s8 f7; } S_001CCFD0_003B8C70_003B8C70;
extern S_001CCFD0_003B8C70_003B8C70 D_001CCFD0_003BE168[];
/* localdecomp:start func_003BE168 */
void func_003A7480(s32);
void func_003A7618(s32);
__asm__(".extern D_001D6E90, 16");
__asm__(".extern D_001D5B94, 16");

void func_003BE168(void) {
    s32 v = D_001D6E90;
    if (v != 0) {
        D_001CCFD0_003BE168->f7 = 0;
        switch (v) {
        case 17:
            func_003A7480(0x11);
            break;
        case 18:
            func_003A7618(0x12);
            break;
        }
        D_001CCFD0_003BE168->f7 = 1;
        D_001D5B94 = 6;
        D_001D6E90 = 0;
    }
}
/* localdecomp:end func_003BE168 */

/* localdecomp:start func_003BE1F8 */
extern u8 D_001D8CF4;
void func_003BE1F8(s32 a) {
    D_001D8CF4 = a;
}
/* localdecomp:end func_003BE1F8 */

/* localdecomp:start func_003BE200 */
__asm__(".extern D_001D8D00, 4");
extern u32 *D_001DA050;
extern u8 D_001D02D0[];
extern u8 D_001D7300[];
extern s32 D_001D8D00;
void func_003BE200(void) {
    D_001DA050[0] = 0x30000002;
    D_001DA050[1] = (u32)&D_001D8D00;
    D_001DA050[2] = 0;
    D_001DA050[3] = 0x50000002;
    D_001DA050 += 4;
    D_001DA050[0] = 0x30000029;
    D_001DA050[1] = (u32)D_001D02D0;
    D_001DA050[2] = 0;
    D_001DA050[3] = 0x50000029;
    D_001DA050 += 4;
    D_001DA050[0] = 0x30000003;
    D_001DA050[1] = (u32)D_001D7300;
    D_001DA050[2] = 0;
    D_001DA050[3] = 0x50000003;
    D_001DA050 += 4;
}
/* localdecomp:end func_003BE200 */

/* localdecomp:start func_003BE300 */
extern u8 D_001D8CD1;
u8 func_003BE300(void) {
    return D_001D8CD1;
}
/* localdecomp:end func_003BE300 */

/* PAL candidate for func_003BE308 (frontbin).
 *
 * Retail reaches D_001DA49C and D_001DA4A0 through lui/lw, not through $gp:
 *     lui $2, %hi(D_001DA4A0) ; lw $2, %lo(D_001DA4A0)($2)
 *     lui $16, %hi(D_001DA49C) ; lw $16, %lo(D_001DA49C)($16)
 * With the file's assembler a sized scalar extern is small data, so the
 * default assembler reaches it through $gp. The project's way to get retail's
 * lui/lw form with the default assembler is the size hint .extern SYM, 16,
 * which keeps the symbol out of the small data area. Both globals are used by
 * this function only, so the hint changes nothing else in the file.
 */

/* localdecomp:start func_003BE308 */
extern u32 D_001DA49C;
extern u32 D_001DA4A0;
__asm__(".extern D_001DA49C, 16");
__asm__(".extern D_001DA4A0, 16");
void func_003BE308(void (*cb)(u32)) {
    u32 p;
    s32 i;
    for (p = D_001DA49C; p != D_001DA4A0; p += 0x100) {
        cb(p);
    }
    for (i = 0; i < D_00225700.n; i++) {
        if (D_00225700.slot[i] != 0) {
            ((void (*)(void *))cb)(D_00225700.slot[i]);
        }
    }
}
/* localdecomp:end func_003BE308 */

/* func_003BE3B8 (frontbin, PAL).
   Based on the US draft (rac3-uya-decomp func_003B8EC0, commit 13cf5c5), names moved to PAL
   addresses where known. PAL differs in the two constants: 5 instead of 6, 250 instead of 300.

   Retail reaches the global in the "no-split" shape (`lui $at, %hi(sym)` +
   `sw $v1, %lo(sym)($at)`), the one the US matched with `-mno-split-addresses`. With this
   file's own flags (split addresses) an unsized global gets a general register as the
   base (`lui $v1, %hi(sym)` + `sw $v0, %lo(sym)($v1)`). So it is declared sized
   (gcc leaves the store to the assembler as one macro), with an `.extern X, 16` hint before its first use (docs/wiki/Matching-Patterns.md), so the assembler expands the macro with
   `lui $at` (as SN's single-pass Ps2EeAs did for a global whose size it had not seen yet). */


/* localdecomp:start func_003BE3B8 */
extern void func_003BBA08(s32, s32);
extern void func_0038A238(s32);
extern s32 D_001DA2C0;
__asm__(".extern D_001DA2C0, 16");
s32 func_003BE3B8(void) {
    func_003BBA08(0, 0);
    func_0038A238(5);
    D_001DA2C0 = 250;
    return 1;
}
/* localdecomp:end func_003BE3B8 */

extern s16 D_0016C5A2[];
extern s32 func_0038CAD0(s32 *);
extern u8 D_001DA2C0_003BE3F0;
/* localdecomp:start func_003BE3F0 */
/* US draft of func_003BE3F0 (rac3-uya-decomp func_003BE6B8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


extern s16 D_0016C5A2_003BE3F0[];
extern s32 func_0038CAD0_003BE3F0(s32 *);
void func_003BDF60(s16, s32, s32, s32);
extern u8 D_001DA2C0_003BE3F0_003BE3F0;

s32 func_003BE3F0(void) {
    s32 temp_s0;

    temp_s0 = func_0038CAD0_003BE3F0(&D_001DA2C0_003BE3F0_003BE3F0) != 0;
    func_003BDF60(D_0016C5A2_003BE3F0[0], 0xFA, 0xC, 0xC);
    return temp_s0;
}
/* localdecomp:end func_003BE3F0 */

/* localdecomp:start func_003BE440 */
s32 func_003BE440(void) {
}
/* localdecomp:end func_003BE440 */
