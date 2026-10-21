#include "common.h"

INCLUDE_ASM("asm/levels", func_L04_003E6018);

INCLUDE_ASM("asm/levels", func_L04_003E6038);

/* localdecomp:start func_L04_003E6308 */
typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3E4368;

extern S_3E4368 *func_L01_0043B548(s32, s32);
extern void func_003C2880(void *);

void func_L04_003E6308(u8 *m, s32 b) {
    if (*(s32 *)(*(u8 **)(m + 0x68) + 0x150) != 0) {
        S_3E4368 *v = func_L01_0043B548(6625, 108);
        v->f0(m);
        if (b) {
            v->f4(m);
        }
    } else {
        func_003C2880(m);
    }
}
/* localdecomp:end func_L04_003E6308 */
