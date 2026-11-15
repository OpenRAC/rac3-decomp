#include "common.h"

/* declared by functions of L39_006B0720.c, which this file was cut from */
void func_L39_00688400(void *, s32);

/* localdecomp:start func_L39_006B15A8 */
void func_L39_00688400(void *, s32);
void func_L39_006CC158(void *, s32);
extern u8 D_L39_0047E210[];

void func_L39_006B15A8(void *arg0, s32 arg1) {
    *(void **)((u8 *)arg0 + 0x60) = D_L39_0047E210;
    func_L39_006CC158(arg0 + 0x2B8, 2);
    func_L39_00688400(arg0, arg1);
}
/* localdecomp:end func_L39_006B15A8 */
