#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

ASM_FUNC("asm/boot_elf/handwritten", func_0012A950);

/* localdecomp:start func_0012A9F0 */
s32 func_0012A9F0(void) {
    s32 r;
    do {
        u32 vpu;
        r = 0;
        if (*(volatile u32 *)0x10009000 & 0x100) {
            r = 1;
        }
        if (*(volatile u32 *)0x1000A000 & 0x100) {
            r |= 2;
        }
        if (*(volatile u32 *)0x10003C00 & 3) {
            r |= 4;
        }
        __asm__ __volatile__(".set push\n\t.set noreorder\n\tcfc2.ni %0, $vi29\n\t.set pop" : "=r"(vpu));
        if (vpu & 0x100) {
            r |= 8;
        }
        if (*(volatile u32 *)0x10003020 & 0xC00) {
            r |= 0x10;
        }
    } while (r != 0);
    return 0;
}
/* localdecomp:end func_0012A9F0 */
