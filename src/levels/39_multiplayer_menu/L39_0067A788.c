#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0067A788);

INCLUDE_ASM("asm/levels", func_L39_0067A7E0);

INCLUDE_ASM("asm/levels", func_L39_0067A888);

INCLUDE_ASM("asm/levels", func_L39_0067AB38);

INCLUDE_ASM("asm/levels", func_L39_0067ABC8);

INCLUDE_ASM("asm/levels", func_L39_0067BBE8);

INCLUDE_ASM("asm/levels", func_L39_0067BC58);

INCLUDE_ASM("asm/levels", func_L39_0067BCA8);

INCLUDE_ASM("asm/levels", func_L39_0067BE08);

INCLUDE_ASM("asm/levels", func_L39_0067C408);

INCLUDE_ASM("asm/levels", func_L39_0067C8E8);

INCLUDE_ASM("asm/levels", func_L39_0067C948);

INCLUDE_ASM("asm/levels", func_L39_0067C9C0);

INCLUDE_ASM("asm/levels", func_L39_0067CA48);

INCLUDE_ASM("asm/levels", func_L39_0067CAC0);

INCLUDE_ASM("asm/levels", func_L39_0067CCB0);

/* localdecomp:start func_L39_0067CE08 */
void func_001953B8(void *);
void func_001953D0(void *);
extern u8 D_L39_0067CAC0[];

void func_L39_0067CE08(void) {
    func_001953B8(D_L39_0067CAC0);
    func_001953D0(D_L39_0067CAC0);
}
/* localdecomp:end func_L39_0067CE08 */

/* localdecomp:start func_L39_0067CE40 */
u8 func_L39_0067CE40(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x9D));
}
/* localdecomp:end func_L39_0067CE40 */

INCLUDE_ASM("asm/levels", func_L39_0067CE48);

INCLUDE_ASM("asm/levels", func_L39_0067CEA0);

INCLUDE_ASM("asm/levels", func_L39_0067CED8);

INCLUDE_ASM("asm/levels", func_L39_0067CF68);

INCLUDE_ASM("asm/levels", func_L39_0067D410);

/* localdecomp:start func_L39_0067D658 */
void func_L39_006121B0(s32);
void func_L39_00681470();

void func_L39_0067D658(void) {
    func_L39_006121B0(0);
    func_L39_006121B0(1);
    func_L39_00681470();
}
/* localdecomp:end func_L39_0067D658 */

INCLUDE_ASM("asm/levels", func_L39_0067D688);

INCLUDE_ASM("asm/levels", func_L39_0067D758);

/* localdecomp:start func_L39_0067EB98 */
void func_00137520();
s32 func_L39_0067CEA0();
extern s32 D_001A5DF0[];
extern s32 D_001DB168;

s32 func_L39_0067EB98(void) {
    D_001DB168 = func_L39_0067CEA0();
    func_00137520();
    D_001A5DF0[0] = 2;
    return 0;
}
/* localdecomp:end func_L39_0067EB98 */

INCLUDE_ASM("asm/levels", func_L39_0067EBD0);

INCLUDE_ASM("asm/levels", func_L39_0067EC00);

INCLUDE_ASM("asm/levels", func_L39_0067EC30);

INCLUDE_ASM("asm/levels", func_L39_0067ED40);

INCLUDE_ASM("asm/levels", func_L39_0067ED90);

LINKER_REMNANT("asm/levels", func_L39_0067EDD8);
