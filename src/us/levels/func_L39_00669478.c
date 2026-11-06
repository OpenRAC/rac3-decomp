#include "common.h"

/* localdecomp:start func_L39_00669478 */
extern u8 D_001A5E50[];
extern s32 *D_L39_0024D06C;
extern s32 *D_L39_0024D06C_b;
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);
extern void func_L39_00669808(s32, s32, s32, s32 *);
extern s32 *func_L39_00669A08(s32 *);

void func_L39_00669478(s32 n) {
    u8 *global;
    s32 *q;
    s32 i;

    q = D_L39_0024D06C;
    i = 0;
    if (q != 0) {
        global = D_001A5E50;
        do {
            if (*(s32 *)(global + 0x170) == 0) {
                func_0014AD08(global[0x7D4] | 0x50, *(s32 *)(global + 4), -1,
                              *(s32 *)0x00240744, q[0], q);
            }
            func_L39_00669808(0, 0, 0, q);
            i++;
            q = func_L39_00669A08(q);
            if (i >= n) {
                D_L39_0024D06C_b = q;
                break;
            }
        } while (q != 0);
    }
}
/* localdecomp:end func_L39_00669478 */
