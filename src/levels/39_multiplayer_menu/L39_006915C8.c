#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006915C8);

/* localdecomp:start func_L39_006918A8 */
void func_L39_006918A8(u8 *self) {
    u8 **p = (u8 **)(self + 0x124);
    s32 i = 5;
    u8 *obj;
    void (*fn)(u8 *);

    *(s32 *)(self + 0x27C4) = -1;
    do {
        obj = *p;
        i--;
        fn = *(void (**)(u8 *))(*(u8 **)(obj + 0x60) + 0xB4);
        fn(obj);
        p++;
    } while (i >= 0);
}
/* localdecomp:end func_L39_006918A8 */

INCLUDE_ASM("asm/levels", func_L39_00691900);

LINKER_REMNANT("asm/levels", func_L39_00691E48);

INCLUDE_ASM("asm/levels", func_L39_00691E60);

LINKER_REMNANT("asm/levels", func_L39_006921B0);

INCLUDE_ASM("asm/levels", func_L39_006921B8);

INCLUDE_ASM("asm/levels", func_L39_006921E0);

/* localdecomp:start func_L39_006923F0 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006923F0(void *);

extern void func_L39_0067F168();
void func_L39_006923F0(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006923F0 */

INCLUDE_ASM("asm/levels", func_L39_00692420);
