#include "common.h"

/* localdecomp:start func_L39_00561158 */
typedef struct {
    u8 pad0[0x68];
    s32 x68;
} func_005606A8_t;

s32 func_L39_00561158(func_005606A8_t *a, s32 *b, s32 *c) {
    s32 v = a->x68;
    *c = 16;
    *b = v;
    return 0;
}
/* localdecomp:end func_L39_00561158 */

/* localdecomp:start func_L39_00561170 */
extern void func_L39_0066CA98(u8 *);
void func_L39_00561170(u8 *a0) {
    if (a0[32] == 5) {
        func_L39_0066CA98(a0);
    }
}
/* localdecomp:end func_L39_00561170 */
