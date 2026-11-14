#include "common.h"

/* localdecomp:start func_L03_0040ED50 */
extern s32 D_L03_001E68B4[];
extern void func_00388830(void *, void *, f32);

void func_L03_0040ED50(u8 *obj, s32 lo, s32 hi) {
    s32 now = D_L03_001E68B4[0];
    f32 t;
    u8 *v;
    u8 *w;
    s32 i;

    if (now < lo) {
        return;
    }
    if (hi < now) {
        return;
    }
    t = (f32)(hi - now) / (f32)(hi - lo);
    if (obj != 0) {
        w = obj + 0xE0;
        v = obj + 0xC0;
        for (i = 0; i < 2; i++) {
            func_00388830(v, v, t);
            v += 0x10;
        }
        func_00388830(w, w, (1.0f - t) + 1.0f);
    }
}
/* localdecomp:end func_L03_0040ED50 */
