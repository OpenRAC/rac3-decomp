#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L09_003BD360.c, which this file was cut from */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003D4D00(void *, s32, void *, void *, f32);

/* localdecomp:start func_L09_003BE228 */
extern void func_L01_00446760(void *, void *, s32, void *, f32);

void func_L09_003BE228(u8 *obj) {
    vu0_v4 v;
    vu0_v4 w;
    vu0_v4 u;
    u8 buf[0x30];
    u8 *p = *(u8 **)(obj + 0x68);
    v = *(vu0_v4 *)(obj + 0x10);
    w.x = func_0038D098(*(f32 *)(obj + 0xF8));
    w.y = func_0038D0B0(*(f32 *)(obj + 0xF8));
    w.z = 1.5f;
    vec_add_ab(&v, &v, &w);
    u.x = func_0038D098(*(f32 *)(obj + 0xF8)) * 3.0f;
    u.y = func_0038D0B0(*(f32 *)(obj + 0xF8)) * 3.0f;
    u.z = 0.5f;
    u.w = 5627.9248f;
    func_L01_00446760(buf, obj, 0x10001, &u, p[0x44]);
    func_003D4D00(&v, 0, obj, buf, 3.5f);
}
/* localdecomp:end func_L09_003BE228 */
