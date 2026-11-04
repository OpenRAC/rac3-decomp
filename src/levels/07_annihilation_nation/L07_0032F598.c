#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_0032F598);

INCLUDE_ASM("asm/levels", func_L07_0032F988);

INCLUDE_ASM("asm/levels", func_L07_0032FDC8);

INCLUDE_ASM("asm/levels", func_L07_003303B0);

INCLUDE_ASM("asm/levels", func_L07_003304C0);

INCLUDE_ASM("asm/levels", func_L07_00330748);

INCLUDE_ASM("asm/levels", func_L07_00330828);

INCLUDE_ASM("asm/levels", func_L07_003309A0);

INCLUDE_ASM("asm/levels", func_L07_00330AA0);

INCLUDE_ASM("asm/levels", func_L07_00330F30);

/* localdecomp:start func_L07_00330F98 */
extern void func_L07_003328D0(s32);
extern void func_L01_004AA760(s32, s32);
extern void func_L01_004596E8(s32, void (*)(void));
extern void func_L07_00331890(s32);
extern void func_L07_003332B8(void);
extern s32 D_L07_001D7B20;

void func_L07_00330F98(s32 arg0) {
    void (*deflt)(void);

    func_L07_003328D0(arg0);
    func_L01_004AA760(0, arg0);
    func_L01_004AA760(1, arg0);
    func_L01_004AA760(2, arg0);
    deflt = func_L07_003332B8;
    D_L07_001D7B20 = -1;
    func_L01_004596E8(0, deflt);
    func_L07_00331890(arg0);
}
/* localdecomp:end func_L07_00330F98 */

INCLUDE_ASM("asm/levels", func_L07_00331008);

INCLUDE_ASM("asm/levels", func_L07_003310E8);

INCLUDE_ASM("asm/levels", func_L07_00331158);

/* localdecomp:start func_L07_00331288 */
extern void func_L07_003312E8(s32, s32);

void func_L07_00331288(s32 a0)
{
    s32 i;

    for (i = 0; i < 6; i++) {
        if (i < 3 || i > 4) {
            func_L07_003312E8(a0, i);
        }
    }
}
/* localdecomp:end func_L07_00331288 */

INCLUDE_ASM("asm/levels", func_L07_003312E8);
