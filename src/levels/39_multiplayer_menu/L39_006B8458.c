#include "common.h"

/* localdecomp:start func_L39_006B8458 */
extern s32 func_00381FF0(s32);
extern void func_L39_006B8AC8(void *, s32);
extern s32 D_L39_004B1578[];

void func_L39_006B8458(void *p) {
    s32 buf[32];
    s32 *src;
    s32 *dst;
    s32 i;
    void *obj;
    void (*fn)(void *, s32, void *);

    src = D_L39_004B1578;
    dst = buf;
    *(s32 *)((u8 *)p + 0x2AC) = 0;
    i = 0x15;
    do {
        i--;
        *dst = func_00381FF0(*src);
        src++;
        dst++;
    } while (i >= 0);

    obj = *(void **)((u8 *)p + 0x128);
    fn = *(void (**)(void *, s32, void *))(*(u8 **)((u8 *)obj + 0x60) + 0x6C);
    fn(obj, 0x16, buf);
    func_L39_006B8AC8(p, 0);
}
/* localdecomp:end func_L39_006B8458 */

INCLUDE_ASM("asm/levels", func_L39_006B84E8);

INCLUDE_ASM("asm/levels", func_L39_006B8698);

INCLUDE_ASM("asm/levels", func_L39_006B8AC8);

INCLUDE_ASM("asm/levels", func_L39_006B8D48);

INCLUDE_ASM("asm/levels", func_L39_006B8D88);

LINKER_REMNANT("asm/levels", func_L39_006B9000);

INCLUDE_ASM("asm/levels", func_L39_006B9008);

LINKER_REMNANT("asm/levels", func_L39_006B9F50);

/* localdecomp:start func_L39_006B9F58 */
extern u8 D_L39_0047E780[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006B9F58(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047E780;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006B9F58 */

INCLUDE_ASM("asm/levels", func_L39_006B9F80);

/* localdecomp:start func_L39_006BA468 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006BA468(void *);

extern void func_L39_0067F168();
void func_L39_006BA468(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006BA468 */

INCLUDE_ASM("asm/levels", func_L39_006BA498);
