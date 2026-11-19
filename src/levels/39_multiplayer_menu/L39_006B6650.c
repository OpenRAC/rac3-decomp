#include "common.h"

/* localdecomp:start func_L39_006B6650 */
extern u8 D_L39_0047E540[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006B6650(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047E540;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006B6650 */

/* localdecomp:start func_L39_006B6678 */
/* Same shape as func_L39_0069E768 (task 4); constants from the $gp slots 0x111C..0x112C. */
extern f32 D_001DD9CC_sda;
extern f32 D_001DD9D0_sda;
extern f32 D_001DD9D4_sda;
extern f32 D_001DD9D8_sda;
extern f32 D_001DD9DC_sda;
extern void func_L39_00688460(void *a0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, void *p1, void *p2, void *p3, void *p4, void *p5);

void func_L39_006B6678(void *a0)
{
    s32 v[4];
    func_L39_00688460(a0, D_001DD9CC_sda, D_001DD9D0_sda, D_001DD9D4_sda, D_001DD9D8_sda, D_001DD9DC_sda, v, v, v, v, v);
}
/* localdecomp:end func_L39_006B6678 */
