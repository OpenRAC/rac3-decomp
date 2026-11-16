/* PAL near miss (Codex wave 10): near miss: 83 words differ with the file's flags.
 * Worker's note: 83 aligned instruction diffs (660 vs 672 bytes), 00467B20-04.log: threshold selection hoists 0.15 and removes retail branch; later code shifted by 12 bytes. Three equivalent threshold wordings retain wrong selection shape.
 */
#include "common.h"
/* localdecomp:start func_L01_00467B20 */
#include "vu0.h"
extern u8 *D_L01_0022110C[];
extern vu0_v4 D_L01_001E29C0;
void func_L01_00467B20(u8 *self)
{
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern void func_003C2F58(void *, s32, void *);
    extern void func_0038CF68(void *, void *, f32);
    u8 *vars;
    vu0_v4 pos, delta;
    f32 limit;
    if (self) {
        vars = self + 0x20;
        if (func_0038CB00(self + 0xA) || !*(u8 **)(self + 0x20) || *(s8 *)(*(u8 **)(self + 0x20) + 0x20) < 0)
            goto destroy;
        *(s16 *)(vars + 0xC) = (*(s16 *)(vars + 0xC) + 1) & 15;
        if (*(f32 *)(self + 0xC) < 159600.0f) {
            *(f32 *)(self + 0xC) += 4788.0f;
            if (*(f32 *)(self + 0xC) > 159600.0f) *(f32 *)(self + 0xC) = 159600.0f;
        } else if (*(f32 *)(self + 0xC) > 159600.0f) {
            *(f32 *)(self + 0xC) -= 19152.0f;
            if (*(f32 *)(self + 0xC) < 159600.0f) *(f32 *)(self + 0xC) = 159600.0f;
        }
        *(f32 *)(vars + 8) += 0.0012f;
        self[8] = (s32)(*(f32 *)(vars + 8) * 255.0f);
        self[2] = D_L01_0022110C[0][*(s16 *)(vars + 0xC)];
        if (*(f32 *)(self + 0xC) <= 159600.0f || *(f32 *)(vars + 0x10) > 0.0f)
            *(f32 *)(vars + 4) += *(f32 *)(vars + 0x10);
        limit = *(f32 *)(self + 0xC) <= 159600.0f ? 0.3 : 0.15;
        if (*(f32 *)(vars + 4) > limit) goto reverse;
        if (*(f32 *)(vars + 4) < 0.0f) {
 destroy:
            func_003CD250(self);
            return;
        }
        goto updated;
 reverse:
        *(f32 *)(vars + 0x10) = -*(f32 *)(vars + 0x10);
        *(f32 *)(vars + 4) += *(f32 *)(vars + 0x10);
 updated:
        *(u32 *)(self + 4) = (*(u32 *)(self + 4) & 0xFFFFFF) + ((s32)(*(f32 *)(vars + 4) * 256.0f) << 24);
        *(f32 *)(vars + 0x14) += (1.0f - *(f32 *)(vars + 0x14)) * 0.21000000834465027f;
        if (*(s16 *)(vars + 0xE) != -1) {
            func_003C2F58(*(void **)vars, *(s16 *)(vars + 0xE), &pos);
            vec_sub_ba(&delta, &D_L01_001E29C0, &pos);
            func_0038CF68(&delta, &delta, *(f32 *)(vars + 0x14));
            vec_add_ab(self + 0x10, &pos, &delta);
        }
    }
}
/* localdecomp:end func_L01_00467B20 */
