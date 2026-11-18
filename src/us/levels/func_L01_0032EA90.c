#include "common.h"
#include "vu0.h"
extern f32 D_L01_001DCEF0;
__asm__(".extern D_L01_001DCEF0, 4");
extern void func_L01_004C4190(void *, void *, f32);
extern s32 func_L01_003F8448(void *, void *, s32, void *, s32);
/* localdecomp:start func_L01_0032EA90 */
void func_L01_0032EA90(u8 *object) {
    vu0_q previous = *(vu0_q *)(object + 0x10);
    u8 *vars = *(u8 **)(object + 0x68);
    vec_add_ba(object + 0x10, object + 0x10, vars);
    func_L01_004C4190(object + 0x10, vars, D_L01_001DCEF0 * 0.000277777785f * 0.1f);
    if (func_L01_003F8448(&previous, object + 0x10, 16, object, 0)) object[0x20] = 8;
}

/* localdecomp:end func_L01_0032EA90 */
