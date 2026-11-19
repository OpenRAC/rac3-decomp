#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

typedef struct { u8 p0[4]; f32 *f4; u8 p8[0x28]; u32 f30; u32 f34; } O_A6640;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003ABFA0);

/* localdecomp:start func_003AC0C8 */
void func_003AC0C8(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x2C) = value;
}
/* localdecomp:end func_003AC0C8 */

/* localdecomp:start func_003AC0D0 */
void func_003AC0D0(void *a0, s32 a1) {
    f32 result;
    void *p;
    __asm__ volatile (
        "mtc1 %2, %0\n"
        "nop\n"
        "cvt.s.w %0, %0\n"
        "lw %1, 4(%3)\n"
        : "=f"(result), "=r"(p)
        : "r"(a1), "r"(a0)
    );
    *(f32 *)((u8 *)p + 4) = result;
}
/* localdecomp:end func_003AC0D0 */

/* localdecomp:start func_003AC0E8 */
void func_003AC0E8(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x38) = value;
}
/* localdecomp:end func_003AC0E8 */
