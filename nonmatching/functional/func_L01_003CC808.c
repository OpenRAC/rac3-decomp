/* functional: high. 10 instructions differ (scheduling only); same calls and arguments. */
#include "vu0.h"
extern void func_0038CE20(f32 *, f32 *, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_003CC610(void *, void *, void *, s32);
extern s32 D_L01_001DFB40;

void func_L01_003CC808(u8 *obj, u8 *other) {
    vu0_v4 pt, off;
    s32 i;
    if (((*(s16 *)(obj + 0xB2) + D_L01_001DFB40) & 1) == 0) {
        func_0038CE20((f32 *)&off, (f32 *)(obj + 0xC0), -0.10000000149011612f);
        off.z -= 0.15000000596046448f;
        for (i = 1; i < 3; i++) {
            func_003C2F58(obj, i, &pt);
            vec_add_ba(&pt, &pt, &off);
            func_L01_003CC610(obj, other, &pt, 1);
        }
    }
}
