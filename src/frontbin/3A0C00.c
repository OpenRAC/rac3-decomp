#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003A0D48(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern s32 func_003A0EA8(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003A0C00 */
void func_003A0C00(void) {
    __asm__ volatile (
        "lui $3, 0x8\n"
        "addi $3, $3, 0x200\n"
        "mtc0 $3, $25\n"
    );
}
/* localdecomp:end func_003A0C00 */

ASM_FUNC("asm/handwritten", func_003A0C18);

ASM_FUNC("asm/handwritten", func_003A0C40);

ASM_FUNC("asm/handwritten", func_003A0C70);

ASM_FUNC("asm/handwritten", func_003A0C80);

/* localdecomp:start func_003A0C90 */
#include "cpu.h"
void func_003A0C90(void) {
    CpuSyncP();
}
/* localdecomp:end func_003A0C90 */

/* localdecomp:start func_003A0CA0 */
void func_003A0CA0(void) {
    __asm__ volatile (
        "sync.p\n"
        "mfc0 $8, $24\n"
        "lui $9, 0x7fff\n"
        "ori $9, $9, 0xffff\n"
        "and $8, $8, $9\n"
        "mtc0 $8, $24\n"
        "sync.p\n"
    );
}
/* localdecomp:end func_003A0CA0 */

ASM_FUNC("asm/handwritten", func_003A0CC8);

ASM_FUNC("asm/handwritten", func_003A0D08);

/* localdecomp:start func_003A0D40 */
s32 func_003A0D40(void) {
}
/* localdecomp:end func_003A0D40 */

extern s32 D_001D5B94_003A0D48;
extern s32 D_001D5B90_003A0D48;
extern s32 D_001D5B8C;
extern s32 D_001D6D98;
extern s32 D_001D6D9C_003A0D48;
extern s32 D_001D6DA0_003A0D48;
extern u8 *D_001D6DA8_003A0D48;
extern f32 D_002259B0[];
extern void func_003A8A58(void);
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);
extern void func_003873C0();
extern void func_003A88B8();
extern void func_003B3218();
/* localdecomp:start func_003A0D48 */
void func_003A0D48(void) {
    s32 a = D_001D5B94_003A0D48;
    s32 t;
    u8 *v;
    s32 s;
    D_001D5B8C = a;
    if (D_001D5B90_003A0D48 == -2) return;
    t = D_001D6D98;
    if (t > 0) {
        D_001D6D98 = t - 1;
        return;
    }
    switch (a) {
    case 1:
        func_003A8A58();
        D_002259B0[0] = 0.62f;
        func_00382810(0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
        func_003873C0();
        break;
    case 0:
    case 2:
    case 4:
    case 18:
        break;
    }
    switch (D_001D5B90_003A0D48) {
    case 1:
        func_003A88B8(D_001D6DA0_003A0D48);
        v = D_001D6DA8_003A0D48;
        break;
    case 18:
        func_003B3218(D_001D6D9C_003A0D48);
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    default:
        v = D_001D6DA8_003A0D48;
        break;
    }
    if (v) *v = 1;
    s = D_001D5B90_003A0D48;
    D_001D5B90_003A0D48 = -2;
    D_001D5B94_003A0D48 = s;
    D_001D6DA8_003A0D48 = 0;
}
/* localdecomp:end func_003A0D48 */

LINKER_REMNANT("asm/remnants", func_003A0E90);

/* localdecomp:start func_003A0EA0 */
extern s32 D_001D6D98;
void func_003A0EA0(s32 a) {
    D_001D6D98 = a;
}
/* localdecomp:end func_003A0EA0 */

/* PAL candidate for func_003A0EA8 (US draft rac3-uya-decomp func_0039BEA8).
 *
 * Retail bytes (frontbin 0x003A0EA8):
 *   lui  $v0, %hi(D_001D5B90)
 *   lw   $v0, %lo(D_001D5B90)($v0)   <- hi half and loaded value share $v0
 *   xor  $v0, $v0, $a0
 *   jr   $ra
 *   sltiu $v0, $v0, 1
 *
 * The file's own flags are split-address (no -mno-split-addresses), and with a
 * symbol reference gcc 2.95.3 always splits the address into a separate base
 * register (lui $v1 / lw $v0, lo($v1)); the no-split form retail used is what
 * the assembler expands for `lw $v0, sym`.  So the word is read through
 * an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did),
 * giving retail's lui/lw pair.
 */

extern s32 D_001D5B90[];
/* localdecomp:start func_003A0EA8 */
extern s32 D_001D5B90_003A0EA8;
__asm__(".extern D_001D5B90_003A0EA8, 16");
extern s32 D_001D5B90[];

s32 func_003A0EA8(s32 a0) {
    return D_001D5B90_003A0EA8 == a0;
}
/* localdecomp:end func_003A0EA8 */
