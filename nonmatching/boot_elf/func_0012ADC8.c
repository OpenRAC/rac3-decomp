/* NTSC-U draft (Claude wave E): C of func_0012ADC8 as NTSC-U has it, with NTSC-U names and addresses.
 * flags: byte-exact on NTSC-U only with "@ee29 -O2 -G0" (its file's line: "@ee29 @eeas -O2 -G0") (NTSC-U twin "func_0012ADC8").
 * Study aid: it uses inline asm for EE instructions (lw move), which matched C may not (nonmatching/README.md); plain C is still needed.
 * Worker's note: MATCH with `@ee29 -O2 -G0` (16-byte slots, $ra reload first; file 12AD28.c has SN flags) AND two gp-switching asm statements (outside the AGENTS asm list: coordinator decides): `__asm__ __volatile__("move %0, $28
 */
#include "common.h"

/* localdecomp:start func_0012ADC8 */
extern void (*D_15A148)(s32);
extern s32 D_15A14C;
extern s32 D_15A150;
extern s32 D_0013F924;
void func_0012ADC8(void) {
    void (*fn)(s32) = D_15A148;
    if (fn != 0 && D_0013F924 == 0) {
        s32 old;
        __asm__ __volatile__("move %0, $28\n\tlw $28, %1" : "=&r"(old) : "m"(D_15A14C));
        fn(D_15A150);
        __asm__ __volatile__("move $28, %0" : : "r"(old));
    }
}
/* localdecomp:end func_0012ADC8 */
