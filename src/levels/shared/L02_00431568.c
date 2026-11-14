#include "common.h"

/* localdecomp:start func_L02_00431568 */
extern u8 *func_L01_0045B958(void *);
extern s32 func_L01_0045A898(void *, void *, f32);

s32 func_L02_00431568(void *a0, void *a1, s32 a2, f32 f12, f32 f13, f32 f14, f32 f15) {
    u8 *rec;
    s32 old38;
    f32 old28;
    f32 old20;
    f32 old24;

    rec = func_L01_0045B958(a0);
    if (rec == 0)
        return 8;
    old38 = *(s32 *)(rec + 0x38);
    old28 = *(f32 *)(rec + 0x28);
    *(s32 *)(rec + 0x38) = a2;
    if (0.0f < f13)
        *(f32 *)(rec + 0x28) = f13;
    old20 = *(f32 *)(rec + 0x20);
    if (0.0f < f14)
        *(f32 *)(rec + 0x20) = f14;
    old24 = *(f32 *)(rec + 0x24);
    if (0.0f < f15)
        *(f32 *)(rec + 0x24) = f15;
    {
        s32 ret = func_L01_0045A898(a0, a1, f12);
        *(s32 *)(rec + 0x38) = old38;
        *(f32 *)(rec + 0x28) = old28;
        *(f32 *)(rec + 0x20) = old20;
        *(f32 *)(rec + 0x24) = old24;
        return ret;
    }
}
/* localdecomp:end func_L02_00431568 */
