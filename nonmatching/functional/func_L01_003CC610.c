/* functional: high. 114 instructions differ (scheduling and register use); same arithmetic, calls and stores. */
#include "vu0.h"
extern u8 D_L01_00221098[];
extern f32 func_003C3D30(void *, s32, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_00382538(void);
extern u8 *func_00382468(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, f32, f32, f32, void *, s32, s32, s32);

void func_L01_003CC610(void *obj, void *other, vu0_q *pt, s32 count) {
    vu0_v4 p0, p1, v;
    f32 above, t;
    s32 n, i;
    u8 *spark, *eff;
    *(vu0_q *)&p0 = *pt;
    *(vu0_q *)&p1 = *pt;
    p1.z = func_003C3D30(&p0, 0, 0, 0.5f);
    above = p0.z - p1.z;
    if (!(0.0f < above)) return;
    if (!(above < 12.0f)) return;
    t = (above - 6.0f) / 6.0f;
    if (1.0f < t) t = 1.0f;
    else if (t < 0.0f) t = 0.0f;
    n = 0x7F - (s32)(t * 127.0f);
    if (n < 15) return;
    if (count <= 0) return;
    do {
        v.x = func_0038D098(func_00382538()) * 0.04000000283122063f;
        v.y = func_0038D0B0(func_00382538()) * 0.04000000283122063f;
        v.z = 0.0060000005178153515f;
        spark = func_00382468(3);
        eff = func_L01_0046FB40(&p1, &v, 0x32, 0x303234, 63000.00390625f, 105000.0f, 0.0f, spark, n, 7, 0);
        if (eff) {
            eff[3] = 0x48;
            eff[2] = **(u8 **)(D_L01_00221098 + 0x5C);
        }
    } while (--count != 0);
}
