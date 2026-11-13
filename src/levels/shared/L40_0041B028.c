#include "common.h"

/* localdecomp:start func_L40_0041B028 */
typedef struct { u8 pad[12]; s16 a; s16 b; } S_0041A7F0;
typedef struct { u8 pad[104]; S_0041A7F0 *p; } T_0041A7F0;
void func_L40_0041B028(T_0041A7F0 *t, int v) {
    S_0041A7F0 *p = t->p;
    p->a = 4;
    p->b = v;
}
/* localdecomp:end func_L40_0041B028 */

/* localdecomp:start func_L40_0041B040 */
extern char D_L40_00247648[8];
extern char D_L40_00247650[8];
/* from rac4-decomp's func_L41_00411728 */
s32 func_L40_0041B040(s32 arg0, s32 arg1, s32 *arg2) {
    s32 ret = 0;
    switch (arg1) {
    case 0x4027571:
        ret = (s32)D_L40_00247648;
        *arg2 = 4;
        break;
    case 0x4027572:
        ret = (s32)D_L40_00247650;
        *arg2 = 4;
        break;
    }
    return ret;
}
/* localdecomp:end func_L40_0041B040 */

INCLUDE_ASM("asm/levels", func_L40_0041B090);
