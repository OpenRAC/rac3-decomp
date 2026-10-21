#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00530B00);

/* localdecomp:start func_L39_00530DE0 */
typedef int Q_00530798 __attribute__((mode(TI)));

extern void func_003C2EC0();

typedef struct {
    char pad[48];
    Q_00530798 q;
} S_00530798;

void func_L39_00530DE0(int a0, Q_00530798 *a1) {
    S_00530798 s;
    func_003C2EC0(a0, 14, &s);
    *a1 = s.q;
}
/* localdecomp:end func_L39_00530DE0 */

INCLUDE_ASM("asm/levels", func_L39_00530E18);

/* localdecomp:start func_L39_00531640 */
s32 func_L39_00531640(s32 a0) {
    s32 p = *(s32 *)(*(s32 *)(*(s32 *)(a0 + 104) + 1744) + 728);
    s32 r = 0;
    if (p != 0) {
        r = *(u8 *)(p + 6676) != 0;
    }
    return r;
}
/* localdecomp:end func_L39_00531640 */

INCLUDE_ASM("asm/levels", func_L39_00531668);
