#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0068F810);

/* localdecomp:start func_L39_0068FA28 */
void func_L39_0068FA28(char *arg0) {
    char **p = (char **)(arg0 + 0x124);
    s32 i;

    *(s32 *)(arg0 + 0x3B8) = -1;
    i = 5;
    do {
        char *v;
        i--;
        v = *p;
        (*(void (**)(char *))((*(char **)(v + 0x60)) + 0xB4))(v);
        p++;
    } while (i >= 0);
}
/* localdecomp:end func_L39_0068FA28 */

INCLUDE_ASM("asm/levels", func_L39_0068FA80);

LINKER_REMNANT("asm/levels", func_L39_0068FFC8);

INCLUDE_ASM("asm/levels", func_L39_0068FFD8);

LINKER_REMNANT("asm/levels", func_L39_00690860);

/* localdecomp:start func_L39_00690868 */
extern u8 D_L39_0047C820[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_00690868(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047C820;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_00690868 */

INCLUDE_ASM("asm/levels", func_L39_00690890);

/* localdecomp:start func_L39_00690DB8 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_00690DB8(void *);

extern void func_L39_0067F168();
void func_L39_00690DB8(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_00690DB8 */

INCLUDE_ASM("asm/levels", func_L39_00690DE8);
