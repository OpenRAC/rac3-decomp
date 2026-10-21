#include "common.h"

/* localdecomp:start func_L04_00379410 */
typedef int u128_00378010 __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_L04_00379690(u8 *);
extern void func_003C7C38(u8 *);
u8 *func_L04_00379410(u128_00378010 *a0) {
    u8 *m = func_003C24B0(6239, 128);
    if (m != 0) {
        *(s16 *)(m + 50) = 64;
        m[48] = 40;
        m[32] = 0;
        *(u128_00378010 *)(m + 16) = *a0;
        func_L04_00379690(m);
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L04_00379410 */
