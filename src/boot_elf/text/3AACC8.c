#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AACC8 */
extern s32 func_003F2738();
extern u8 D_001D8190[];
void func_003AACC8(u8 *p, s32 f) {
    *(void **)(p + 4) = D_001D8190;
    if (f & 1) func_003F2738(p);
}
/* localdecomp:end func_003AACC8 */

extern void func_00116F98(s32 *a0, s32 a1, s32 *a2);
extern char D_001D80B0[];
extern char D_001D80C8[];
extern void func_116F98(char *, s32, char *);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003AACF8);

extern char D_001D8160[];
extern void func_003AACC8();

LINKER_REMNANT("asm/boot_elf/remnants", func_003AAD70);
