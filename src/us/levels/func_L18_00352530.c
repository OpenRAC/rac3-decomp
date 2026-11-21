#include "common.h"

/* NTSC-U counterpart of func_L18_00353138 (src/levels/shared/L18_00353138.c): 0.0244346 -> 0.0203622; 0.00977384 -> 0.00814487; 0.0446804 -> 0.0372337 */
#include "vu0.h"

/* localdecomp:start func_L18_00352530 */
typedef int Q_00353138 __attribute__((mode(TI)));

typedef struct G_00353138 {
    u8 pad0[0x19E0];
    void *x19E0;
    u8 pad19E4[0x25C4 - 0x19E4];
    s32 x25C4;
} G_00353138;

extern G_00353138 D_001A4BE0_00352530;
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_0044B920(void *, void *, void *, f32, f32, f32);
extern void func_L18_0045DD38(void *, void *, void *, f32, f32, f32);

void func_L18_00352530(void *arg0) {
    u8 *a0 = arg0;
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 v[4];
    f32 t;
    f32 w;

    t = func_00389380(*(f32 *)(s + 0x358), 0.020362176f);
    *(f32 *)(s + 0x358) = t;
    w = func_00388978(t) * 0.02f;
    *(f32 *)(s + 0x35C) = w;
    if (*(s32 *)(s + 0x3BC) != 0) {
        *(f32 *)(a0 + 0x18) = *(f32 *)(s + 0x368) + w;
        *(Q_00353138 *)v = *(Q_00353138 *)(a0 + 0xF0);
        func_L01_0044B920(a0, s + 0x360, s + 0x364, 0.02617994f, 0.0081448704f, 0.0372336917f);
        if (D_001A4BE0_00352530.x25C4 == 0x31 && D_001A4BE0_00352530.x19E0 == a0) {
            *(f32 *)(a0 + 0xF0) = func_00389380(*(f32 *)(a0 + 0xF0), v[0]);
            *(f32 *)(a0 + 0xF4) = func_00389380(*(f32 *)(a0 + 0xF4), v[1]);
        }
    } else {
        func_003886E8(v, s + 0x3C0, w);
        vec_add_ab(a0 + 0x10, s + 0x420, v);
        func_L18_0045DD38(a0, s + 0x360, s + 0x364, 0.02617994f, 0.0081448704f, 0.0372336917f);
    }
}
/* localdecomp:end func_L18_00352530 */
