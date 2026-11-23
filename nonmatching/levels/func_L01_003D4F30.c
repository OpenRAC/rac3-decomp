/* PAL near miss (haiku-w4): 59 words differ with the file's flags; frame and s-register set now match (0x70, no spill of p+0xB0), remaining diffs are register allocation of base/index/loop counter (retail s5=base, s6=index, s3 loop, s4=divisor 6) and call scheduling around the vector adds. */
#include "common.h"
/* localdecomp:start func_L01_003D4F30 */
#include "vu0.h"
typedef struct { u8 pad[0xB0]; vu0_v4 position; u8 tail[0x20]; } Row_003D4F30;
extern vu0_v4 D_L01_001EAA20[];
void func_L01_003D4F30(u8 *self, s32 index)
{
    extern void func_L01_003D4EE0(void *, u8 *);
    extern s32 func_L01_003FB640(void *, f32, s32, u8 *);
    extern f32 func_0038CF00(void *, void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_00382580(void *, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_00474078(f32, f32, f32, f32, void *, void *, s32, u32, u32, s32, s32);
    extern void func_L01_0040C8A0(void *, s32);
    extern s32 func_0038CAD0(s32 *);
    vu0_v4 previous, direction, velocity;
    u8 *base = *(u8 **)(self + 0x68);
    {
        u8 *p = base + index * 0xE0;
        func_L01_003D4EE0(p, *(u8 **)(p + 0xD0));
        if (*(s32 *)(p + 0xC0) <= 0) {
            if (func_L01_003FB640(p, 4.0f, 0, *(u8 **)(p + 0xD0))) {
                *(u128_t *)&previous = *(u128_t *)((u8 *)p + 0xB0);
                *(u128_t *)((u8 *)p + 0xB0) = *(u128_t *)&D_L01_001EAA20[0];
                *(s32 *)(p + 0xC8) = 0;
                *(s32 *)(p + 0xC0) = *(s32 *)(p + 0xC4);
                if (func_0038CF00(&previous, (u8 *)p + 0xB0) > 1.6f) {
                    s32 i;
                    { f32 sc = func_003824E0(1.5f, 1.7f) * 0.020000001415610313f; func_0038CF68(&direction, &D_L01_001EAA20[2], sc); }
                    for (i = 4; i >= 0; --i) {
                        func_00382580(&velocity, 0.03f, 0.045f);
                        vec_add_ab(&velocity, &velocity, &direction);
                        func_L01_00474078(0.07f, 0.25f, 0.6f, 0.5f, (u8 *)p + 0xB0, &velocity,
                            (func_00382498(20, 30) * 5 + 2) / 6, *(u32 *)(p + 0x20), *(u32 *)(p + 0x28), 0, 0);
                    }
                }
            }
        }
    }
    {
        u8 *p = index * 0xE0 + base;
        if (*(u8 **)(p + 0xC8) == 0) *(vu0_v4 *)(p + 0x10) = *(vu0_v4 *)(&((Row_003D4F30 *)p)->position);
        else func_L01_003D4EE0(p + 0x10, *(u8 **)(p + 0xC8));
    }
    {
        u8 *p = index * 0xE0 + base;
        if (func_0038CF00(p, p + 0x10) > 2.8f) *(s32 *)(p + 0xC0) = 0;
        else *(s32 *)(p + 0xC0) = *(s32 *)(p + 0xC4);
    }
    {
        u8 *p = index * 0xE0 + base;
        func_L01_0040C8A0(p, *(s32 *)(base + 0x2A0));
        if (*(s32 *)(p + 0xC0) > 0) func_0038CAD0((s32 *)(p + 0xC0));
    }
}
/* localdecomp:end func_L01_003D4F30 */
