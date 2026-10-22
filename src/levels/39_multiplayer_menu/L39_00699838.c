#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00699838);

/* localdecomp:start func_L39_0069A120 */
void func_L39_00688400(void *, s32);
void func_L39_006CC158(void *, s32);
extern u8 D_L39_0047CFD8[];

void func_L39_0069A120(void *arg0, s32 arg1) {
    *(void **)((u8 *)arg0 + 0x60) = D_L39_0047CFD8;
    func_L39_006CC158(arg0 + 0x384, 2);
    func_L39_00688400(arg0, arg1);
}
/* localdecomp:end func_L39_0069A120 */

INCLUDE_ASM("asm/levels", func_L39_0069A170);

/* localdecomp:start func_L39_0069A600 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_0069A600(void *);

extern void func_L39_0067F168();
void func_L39_0069A600(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_0069A600 */

INCLUDE_ASM("asm/levels", func_L39_0069A630);

INCLUDE_ASM("asm/levels", func_L39_0069AEF0);
