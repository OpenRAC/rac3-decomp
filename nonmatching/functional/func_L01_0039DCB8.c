/* functional: medium. Codex PAL draft re-checked in context: 193 words (retail uses gp-relative _sda, draft lui; same jal list) differs only in scheduling/register allocation/addressing, same calls in the same order.  */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec4_0039E0C8;
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
extern f32 D_001DE1D8_sda[4];
extern f32 D_001DE1E8_sda[4];
extern f32 D_001DE1F8_sda[4];
extern s32 D_001DE1BC_sda, D_001DE1C0_sda;
extern s32 D_001DE1C4_sda, D_001DE1C8_sda;
extern s32 D_001DE1CC_sda, D_001DE1D0_sda;
extern s32 D_001DE16C_sda;
extern u8 *D_L01_00221098[];
__asm__(".extern D_001DE1D8_sda, 16");
__asm__(".extern D_001DE1E8_sda, 16");
__asm__(".extern D_001DE1F8_sda, 16");
__asm__(".extern D_001DE1BC_sda, 4");
__asm__(".extern D_001DE1C0_sda, 4");
__asm__(".extern D_001DE1C4_sda, 4");
__asm__(".extern D_001DE1C8_sda, 4");
__asm__(".extern D_001DE1CC_sda, 4");
__asm__(".extern D_001DE1D0_sda, 4");
__asm__(".extern D_001DE16C_sda, 4");
s32 func_L01_0039DCB8(u8 *obj) {
    extern void func_0038CF68(Vec4_0039E0C8 *, Vec4_0039E0C8 *, f32);
    extern s32 func_0038CB00(u8 *);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern u8 *func_L01_0046C2E8(void *, s32, s32, s32, s32, s32, s32, s32, f32);
    Vec4_0039E0C8 pos, step;
    s32 result;
    u8 *state = *(u8 **)(obj + 0x68);
    s32 i;
    f32 z;
    f32 blend;
    s32 color, alpha;
    u8 *particle;
    vec_sub_ab(&pos, &D_L01_001E29C0, obj + 0x10);
    func_0038CF68(&pos, &pos, -0.3f);
    result = 0;
    func_0038CF68(&step, &pos, 0.1f);
    vec_add_ba(&pos, &pos, obj + 0x10);
    z = pos.v[2];
    for (i = 0; i < 4; i++) {
        if (func_0038CB00(state + 0x48 + i * 2) == 0) {
            f32 *angle = (f32 *)(state + 0x50);
            s16 *time = (s16 *)(state + 0x48);
            angle[i] += D_001DE1D8_sda[i];
            if (time[i] >= 41) result = 1;
            if (angle[i] >= 255.0f) angle[i] -= 255.0f;
            else if (angle[i] <= 0.0f) angle[i] += 255.0f;
            blend = fabs_asm(0.5f - (212 - time[i]) / 212.0f);
            if (state[0x47]) color = func_0038DBD8(D_001DE1C4_sda, D_001DE1C8_sda, blend);
            else color = func_0038DBD8(D_001DE1BC_sda, D_001DE1C0_sda, blend);
            pos.v[2] = z + D_001DE1F8_sda[i];
            blend = 1.0f - (f32)time[i] / (f32)((D_001DE16C_sda * 5 + 2) / 6);
            alpha = (s32)((f32)(color >> 24) * (1.0f - blend)) << 24;
            particle = func_L01_0046C2E8(&pos, alpha | (color & 0xFFFFFF), (u8)(s32)angle[i], D_001DE1D0_sda, 0, 2, 1, 0, D_001DE1E8_sda[i] * blend);
            if (particle) particle[2] = *D_L01_00221098[62];
            particle = func_L01_0046C2E8(&pos, alpha | 0xFFFFFF, (u8)(s32)angle[i], D_001DE1D0_sda, D_001DE1CC_sda, 2, 1, 0, D_001DE1E8_sda[i] * (blend * 0.7f));
            if (particle) particle[2] = *D_L01_00221098[62];
            vec_add_ab(&pos, &pos, &step);
        }
    }
    return result;
}
