/* functional: high. scheduling/register allocation differ only (15 words); same stores, calls, VU0 add, loop of 48 spawns. */
#include "common.h"
/* localdecomp:start func_L01_00393C80 */
extern u8 *D_L01_001E2018;
void func_L01_00393C80(u8 *owner, s32 id, V_003919E0 *pos, V_003919E0 *vel, f32 scale) {
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(f32 *, f32 *, f32 *);
    extern f32 func_00382538(void);
    extern void func_L01_00393EF8(void *, s32, f32, f32, s32);
    extern f32 func_0038DAB8(f32, f32);
    V_003919E0 temp;
    u8 *base = D_L01_001E2018;
    s32 i = 0, j;
    f32 angle;
    for (i = 0; i <= 0; i++) {
        u8 *p = base + i * 0x50;
        if (*(u8 **)(p + 0x30) == 0) {
            *(u8 **)(p + 0x30) = owner;
            *(s32 *)(p + 0x34) = id;
            *(f32 *)(p + 0x3C) = scale;
            *(s32 *)(p + 0x38) = 0;
            *(s128 *)p = vel->q;
            *(s128 *)(p + 0x20) = pos->q;
            *(f32 *)(p + 0x28) = *(f32 *)(owner + 0x18);
            func_0038CF68(&temp, vel, 2.0f);
            __asm__("lqc2 $vf2, %0\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "+m"(temp) : "m"(*(V_003919E0 *)(p + 0x20)) : "vf1", "vf2");
            func_0038CE90((f32 *)(p + 0x10), (f32 *)(p + 0x20), temp.f);
            angle = func_00382538();
            for (j = 47; j >= 0; j--) {
                func_L01_00393EF8(p, 2, angle, 0.0f, 0);
                angle = func_0038DAB8(angle, 0.13368479907512665f);
            }
            *(s32 *)(p + 0x40) = 0;
            *(s32 *)(p + 0x44) = 0;
            return;
        }
    }
}
/* localdecomp:end func_L01_00393C80 */
