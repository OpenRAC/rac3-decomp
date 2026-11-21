#include "common.h"

/* NTSC-U counterpart of func_L01_0038E9C8 (src/levels/shared/L01_0038BB10.c): 4 -> 5 */
#include "vu0.h"

/* localdecomp:start func_L01_0038D640 */
#include "vu0.h"
extern s32 D_L01_0029EED0[];
extern u8 D_L01_0038D7F8[];
void func_L01_0038D640(u8 *obj) {
    extern void func_L01_0038E070(u8 *);
    extern s32 func_00388398(s32 *);
    extern f32 func_0037E250(f32, f32);
    extern u8 *func_L01_00462B40(void *, void *);
    extern void func_00388830(void *, void *, f32);
    extern void func_L01_004026A0_0038D640(void *, void *);
    vu0_v4 v;
    u8 *p;
    u8 *vars = *(u8 **)(obj + 0x68);
    s32 i;
    if (!obj[0x20]) {
        func_L01_0038E070(obj);
        obj[0x20] = 1;
        D_L01_0029EED0[0] = 5;
        *(f32 *)(vars + 4) = 0.5f;
    }
    if (!func_00388398(D_L01_0029EED0) && !*(s32 *)(vars + 8)) {
        u8 *pos = obj + 0x10;
        for (i = 9; i >= 0; i--) {
            v.x = func_0037E250(-0.3f, 0.3f) * *(f32 *)(vars + 4);
            v.y = func_0037E250(-0.3f, 0.3f) * *(f32 *)(vars + 4);
            v.z = func_0037E250(-0.3f, 0.3f) * *(f32 *)(vars + 4);
            v.w = 0.0f;
            p = func_L01_00462B40(pos, &v);
            if (p) {
                u8 *q = p + 0x30;
                func_00388830(&v, &v, 1.0f);
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(*(vu0_v4 *)(p + 0x10))
                    : "m"(*(vu0_v4 *)(obj + 0x10)), "m"(v) : "vf1", "vf2");
                *(vu0_q *)(p + 0x20) = *(vu0_q *)(obj + 0x10);
                *(f32 *)(q + 0xC) = 1.0f;
                *(f32 *)(p + 0x1C) = 0.05f;
                *(f32 *)(p + 0x2C) = 0.25f;
            }
        }
    }
    func_L01_004026A0_0038D640(D_L01_0038D7F8, obj);
}
/* localdecomp:end func_L01_0038D640 */
