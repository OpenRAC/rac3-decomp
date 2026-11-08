#include "common.h"

typedef void (*FnVt_006C7F08)(void *, s32, s32);

/* localdecomp:start func_L39_006C69B8 */
void func_L39_006C69B8(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x2A8) = arg1;
}
/* localdecomp:end func_L39_006C69B8 */

INCLUDE_ASM("asm/levels", func_L39_006C69C0);

INCLUDE_ASM("asm/levels", func_L39_006C6B30);

INCLUDE_ASM("asm/levels", func_L39_006C7128);

INCLUDE_ASM("asm/levels", func_L39_006C7800);

INCLUDE_ASM("asm/levels", func_L39_006C7B40);

INCLUDE_ASM("asm/levels", func_L39_006C7C40);

INCLUDE_ASM("asm/levels", func_L39_006C7CE8);

INCLUDE_ASM("asm/levels", func_L39_006C7D28);

INCLUDE_ASM("asm/levels", func_L39_006C7E10);

INCLUDE_ASM("asm/levels", func_L39_006C7E98);

/* localdecomp:start func_L39_006C7F08 */
void func_L39_006C7F08(u8 *arg0) {
    s32 **p = (s32 **)(arg0 + 0x174);
    s32 i;

    for (i = 9; i >= 0; i--) {
        s32 *v = p[-10];
        ((FnVt_006C7F08)(*(s32 *)(*(s32 *)((u8 *)v + 0x60) + 0x1C)))(v, 3, 0);
        v = *p;
        ((FnVt_006C7F08)(*(s32 *)(*(s32 *)((u8 *)v + 0x60) + 0x1C)))(v, 3, 0);
        p++;
    }
}
/* localdecomp:end func_L39_006C7F08 */

/* localdecomp:start func_L39_006C7F78 */
void func_L39_0068B2F8(s32, s32, s32);
void func_L39_006C7F78(void *arg0) {
    func_L39_0068B2F8((s32) arg0, (*(s32 *)((u8 *)arg0 + 0xB68)) + 0xF, 0);
}
/* localdecomp:end func_L39_006C7F78 */

INCLUDE_ASM("asm/levels", func_L39_006C7FA0);

/* localdecomp:start func_L39_006C8020 */
s32 func_L39_006C8020(void *arg0) {
    return (u32) ((*(s32 *)((u8 *)arg0 + 0x290)) - 0xF) < 0xAU;
}
/* localdecomp:end func_L39_006C8020 */

LINKER_REMNANT("asm/levels", func_L39_006C8030);

INCLUDE_ASM("asm/levels", func_L39_006C8050);

LINKER_REMNANT("asm/levels", func_L39_006C8248);

/* localdecomp:start func_L39_006C8250 */
extern u8 D_L39_0047EBA0[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006C8250(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047EBA0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006C8250 */

INCLUDE_ASM("asm/levels", func_L39_006C8278);

INCLUDE_ASM("asm/levels", func_L39_006C82C8);

/* localdecomp:start func_L39_006C8490 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_0067F168();

void func_L39_006C8490(void *arg0) {
    func_L39_0067F168(arg0);
    func_L39_0068ADC8(arg0);
    *(s32 *)((u8 *)arg0 + 0x380) = -1;
    *(s32 *)((u8 *)arg0 + 0x384) = -1;
    *(s32 *)((u8 *)arg0 + 0x388) = -1;
    *(s32 *)((u8 *)arg0 + 0x38C) = -1;
    *(s32 *)((u8 *)arg0 + 0x398) = -1;
    *(s32 *)((u8 *)arg0 + 0x390) = -1;
    *(s32 *)((u8 *)arg0 + 0x39C) = -1;
    *(s32 *)((u8 *)arg0 + 0x3A0) = -1;
    *(s32 *)((u8 *)arg0 + 0x3A4) = -1;
}
/* localdecomp:end func_L39_006C8490 */

INCLUDE_ASM("asm/levels", func_L39_006C84E8);
