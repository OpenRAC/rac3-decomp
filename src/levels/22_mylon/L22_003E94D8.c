#include "common.h"

/* localdecomp:start func_L22_003E94D8 */
#include "vu0.h"
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4DA8(void *, void *, void *, void *);
void func_L22_003E94D8(u8 *self) {
    u8 *p = *(u8 **)(self + 0x68);
    f32 a[4];
    f32 b[4];
    func_0038CF68(a, self + 0xD0, -0.120000005f);
    vec_add_ba(a, a, self + 0x10);
    vec_sub_ba(b, a, self + 0x10);
    func_003C4DA8(p + 0x30, b, self + 0xF0, self + 0xF0);
}
/* localdecomp:end func_L22_003E94D8 */
