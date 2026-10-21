#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_0044C638);

/* localdecomp:start func_L01_0044C790 */
typedef int s128 __attribute__((mode(TI)));

extern u8 *func_003C4D58(u8 *);
extern void func_0038D328(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D000(void *, void *, void *);

s32 func_L01_0044C790(s32 a0, u8 *a1, s128 *a2, s128 *a3) {
    s128 m0[4];
    s128 m1[4];
    s128 m2[4];
    u8 *p = func_003C4D58(a1);
    if (p == 0) {
        *a3 = *a2;
        return 0;
    }
    func_0038D328(m0, p);
    if (*(s32 *)(p + 60) & 2) {
        func_0038D328(m2, p + 32);
        func_0038D5B0(m1, m2);
        func_0038D000(a3, a2, m1);
        func_0038D000(a3, a3, a1 + 192);
    } else {
        func_0038D000(a3, a2, m0);
    }
    return 1;
}
/* localdecomp:end func_L01_0044C790 */

INCLUDE_ASM("asm/levels", func_L01_0044C870);

INCLUDE_ASM("asm/levels", func_L01_0044C998);

INCLUDE_ASM("asm/levels", func_L01_0044CB18);
