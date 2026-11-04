#include "common.h"

/* localdecomp:start func_L18_004614F8 */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C4840(f32 *q, void *axis, f32 angle);
extern void func_0038D850(void *out, void *a, void *b);

void func_L18_004614F8(u8 *obj, f32 *p, f32 *q, f32 k1, f32 k2, f32 k3) {
    f32 tmp[4];
    f32 s;

    s = k1 * func_0038D0B0(*p) * func_0038D0B0(*q);
    func_003C4840(tmp, obj + 0xC0, s);
    func_0038D850(obj + 0xD0, obj + 0xD0, tmp);
    func_0038D850(obj + 0xE0, obj + 0xE0, tmp);
    s = k1 * func_0038D0B0(*p) * func_0038D098(*q);
    func_003C4840(tmp, obj + 0xD0, s);
    func_0038D850(obj + 0xC0, obj + 0xC0, tmp);
    func_0038D850(obj + 0xE0, obj + 0xE0, tmp);
    *p = func_0038DAB8(*p, k2);
    *q = func_0038DAB8(*q, k3);
}
/* localdecomp:end func_L18_004614F8 */
