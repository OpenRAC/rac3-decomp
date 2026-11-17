#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L09_003BD8A8 */
extern u8 D_001A4C60[];
__asm__(".extern D_001A4C60, 16");
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00445188(u8 *, u8);
extern void func_L09_003BC450(u8 *, s32, s32, s32, s32);

void func_L09_003BD8A8(u8 *obj, s32 a1, s32 a2, s32 a3) {
    vu0_v4 t;
    vu0_v4 w1;
    vu0_v4 w2;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 n;
    vu0_q q;

    if (func_0038CF38(obj + 0x10, D_001A4C60) > 16.0f) {
        return;
    }
    vec_sub_ba(&t, D_001A4C60, obj + 0x10);
    t.z = 0.0f;
    if (func_0038CE68(obj + 0xC0, &t) > 0.0f) {
        w1.x = func_0038D098(func_0038DB00(*(f32 *)(obj + 0xF8), 1.5707964f)) * 5.0f;
        w1.y = func_0038D0B0(func_0038DB00(*(f32 *)(obj + 0xF8), 1.5707964f)) * 5.0f;
        w1.z = 0.0f;
        w2.x = func_0038D098(func_0038DAB8(*(f32 *)(obj + 0xF8), 1.5707964f)) * 5.0f;
        w2.y = func_0038D0B0(func_0038DAB8(*(f32 *)(obj + 0xF8), 1.5707964f)) * 5.0f;
        w2.z = 0.0f;
        vec_sub_ab(&d, &t, &w2);
        if (func_0038CE68(obj + 0xD0, &d) > 0.0f) {
            return;
        }
        vec_sub_ba(&e, &t, &w1);
        __asm__("lqc2 %0, %1" : "=j"(q) : "m"(*(vu0_v4 *)(obj + 0xD0)));
        __asm__("vsub.xyz %0, $vf0, %1" : "=j"(q) : "j"(q));
        __asm__("sqc2 %1, %0" : "=m"(n) : "j"(q));
        if (func_0038CE68(&n, &e) > 0.0f) {
            return;
        }
        func_L01_004450F0(obj, 0x15, -1);
        func_L01_00445188(obj, 1);
    } else {
        w1.x = func_0038D098(func_0038DB00(*(f32 *)(obj + 0xF8), 1.5707964f)) * 5.0f;
        w1.y = func_0038D0B0(func_0038DB00(*(f32 *)(obj + 0xF8), 1.5707964f)) * 5.0f;
        w1.z = 0.0f;
        w2.x = func_0038D098(func_0038DAB8(*(f32 *)(obj + 0xF8), 1.5707964f)) * 5.0f;
        w2.y = func_0038D0B0(func_0038DAB8(*(f32 *)(obj + 0xF8), 1.5707964f)) * 5.0f;
        w2.z = 0.0f;
        vec_sub_ab(&d, &t, &w2);
        if (func_0038CE68(obj + 0xD0, &d) < 0.0f) {
            return;
        }
        vec_sub_ba(&e, &t, &w1);
        __asm__("lqc2 %0, %1" : "=j"(q) : "m"(*(vu0_v4 *)(obj + 0xD0)));
        __asm__("vsub.xyz %0, $vf0, %1" : "=j"(q) : "j"(q));
        __asm__("sqc2 %1, %0" : "=m"(n) : "j"(q));
        if (func_0038CE68(&n, &e) < 0.0f) {
            return;
        }
        func_L09_003BC450(obj, a1, a2, a3, 0);
    }
}
/* localdecomp:end func_L09_003BD8A8 */
