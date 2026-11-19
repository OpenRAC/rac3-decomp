#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003B35E0(void *);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003B35D0();
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/boot_elf/remnants", func_003B35C8);

extern s32 D_001D8888;
extern s32 D_001D888C;

/* localdecomp:start func_003B35D0 */
extern s32 D_001D8888;
extern s32 D_001D888C;
void func_003B35D0(s32 a) { D_001D8888 = a; D_001D888C = 0; }
/* localdecomp:end func_003B35D0 */

/* localdecomp:start func_003B35E0 */
extern void *D_001D8890;
void func_003B35E0(void *a) {
    D_001D8890 = a;
}
/* localdecomp:end func_003B35E0 */

/* localdecomp:start func_003B35E8 */
extern void *D_001D8890;
extern void func_003B3610(void *, s32);
void func_003B35E8(void) {
    if (D_001D8890 != 0) func_003B3610(D_001D8890, 0);
}
/* localdecomp:end func_003B35E8 */
