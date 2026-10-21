#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003A1148(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003A1000 */
void func_003A1000(void) {
    __asm__ volatile (
        "lui $3, 0x8\n"
        "addi $3, $3, 0x200\n"
        "mtc0 $3, $25\n"
    );
}
/* localdecomp:end func_003A1000 */

ASM_FUNC("asm/boot_elf/handwritten", func_003A1018);

ASM_FUNC("asm/boot_elf/handwritten", func_003A1040);

ASM_FUNC("asm/boot_elf/handwritten", func_003A1070);

ASM_FUNC("asm/boot_elf/handwritten", func_003A1080);

/* localdecomp:start func_003A1090 */
void func_003A1090(void) {
    __asm__ __volatile__(
        "sync.p\n"
    );
}
/* localdecomp:end func_003A1090 */

/* localdecomp:start func_003A10A0 */
void func_003A10A0(void) {
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
/* localdecomp:end func_003A10A0 */

ASM_FUNC("asm/boot_elf/handwritten", func_003A10C8);

ASM_FUNC("asm/boot_elf/handwritten", func_003A1108);

/* localdecomp:start func_003A1140 */
s32 func_003A1140(void) {
}
/* localdecomp:end func_003A1140 */

extern s32 D_001D5B94_003A1148;
extern s32 D_001D5B90_003A1148;
extern s32 D_001D5B8C;
extern s32 D_001D6D98;
extern s32 D_001D6D9C_003A1148;
extern s32 D_001D6DA0_003A1148;
extern u8 *D_001D6DA8_003A1148;
extern f32 D_002259B0[];
extern void func_003A8E10(void);
extern void func_00382BF0(s32, s32, s32, f32, f32, f32, f32);
extern void func_003877A0();
extern void func_003A8C70();
extern void func_003B35D0();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A1148);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C440);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C490);

LINKER_REMNANT("asm/boot_elf/remnants", func_003A1290);

/* localdecomp:start func_003A12A0 */
extern s32 D_001D6D98;
void func_003A12A0(s32 a) {
    D_001D6D98 = a;
}
/* localdecomp:end func_003A12A0 */
