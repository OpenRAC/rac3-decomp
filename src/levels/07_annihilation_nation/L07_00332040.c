#include "common.h"

/* localdecomp:start func_L07_00332040 */
extern u8 *D_L07_001DF41C_00332040;
extern void func_L02_003A0200(u8 *);

void func_L07_00332040(u8 *a0) {
    s32 *p = (s32 *)(*(u8 **)(a0 + 0x68) + 0x50);
    s32 i;

    for (i = 7; i >= 0; i--) {
        func_L02_003A0200(D_L07_001DF41C_00332040 + ((*p) << 8));
        p++;
    }
}
/* localdecomp:end func_L07_00332040 */
