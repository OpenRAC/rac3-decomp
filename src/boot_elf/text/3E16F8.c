#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003E17A8();
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E16F8);

/* func_003E1728: from the US C of func_003E15E0 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_003E1728 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern s32 D_001D5520_003E1728;
__asm__(".extern D_001D5520_003E1728, 16");
extern void func_003A96A8(s32);
extern void func_00391708(void);
extern void func_00391A58(s32, s32, s32, s32, s32, s32);
extern void func_003D96F0(void);
void func_003E1728(void) {   /* same as func_003B67F0 plus the call below */
    func_003A96A8(1);
    func_00391708();
    if (D_001D5520_003E1728 != 0) {
        func_00391A58(0x200, 0x1A0, 0x280, 0x1C0, 0, 0);
    } else {
        func_00391A58(0x200, 0x1A0, 0x200, 0x1C0, 0, 0);
    }
    func_003D96F0();
}
/* localdecomp:end func_003E1728 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E17A0);

/* localdecomp:start func_003E17A8 */
extern s32 D_00306D40[];
 
s32 func_003E17A8(void) {
    return D_00306D40[0];
}
/* localdecomp:end func_003E17A8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E17B8);
