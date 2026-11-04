#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_00353EA0);

INCLUDE_ASM("asm/levels", func_L01_00355D88);

INCLUDE_ASM("asm/levels", func_L01_00356050);

/* localdecomp:start func_L01_003564D0 */
typedef struct {
    void (*fn0)(void *);
    void (*fn1)(void *);
} Vt_003564D0;

extern Vt_003564D0 *func_L01_0043B548(s32, s32);
extern void func_003C2880(void *);

void func_L01_003564D0(u8 *obj, s32 a1) {
    u8 *p = *(u8 **)(obj + 0x68);

    if (*(void **)(p + 0x360) != 0) {
        func_003C2880(*(void **)(p + 0x360));
        *(void **)(p + 0x360) = 0;
        *(s32 *)(p + 0x240) = 0;
    }
    if (*(s32 *)(p + 0x250) != 0) {
        Vt_003564D0 *t = func_L01_0043B548(6625, 108);
        t->fn0(obj);
        if (a1 != 0) {
            t->fn1(obj);
        }
    } else {
        func_003C2880(obj);
    }
}
/* localdecomp:end func_L01_003564D0 */
