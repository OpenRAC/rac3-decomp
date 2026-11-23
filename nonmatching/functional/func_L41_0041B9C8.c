/* functional: high. 38 instructions differ (scheduling only); level-slot floats as a small-data array. */
#include "common.h"
/* localdecomp:start func_L41_0041B9C8 */
#include "vu0.h"
extern s32 *D_00241120;
extern s32 D_002412DC;
extern s32 D_L41_002476F8 __attribute__((section(".sdata")));
extern f32 D_L41_00247704[6] __attribute__((section(".sdata")));
extern s32 func_L39_005BE900(void *, s32, f32);
extern s32 func_L39_005B4398(s32);
extern void func_L41_0041B350(void *, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L41_0041B578(void *, f32, f32, f32);

void func_L41_0041B9C8(u8 *pos, s32 count, f32 scale, f32 lo, f32 hi) {
    vu0_v4 probe;
    s32 mode = 0;
    *(vu0_q *)&probe = *(vu0_q *)pos;
    probe.w = 5.0f;
    if (func_L39_005BE900(&probe, 0, 128.0f) != -1) {
        if (D_002412DC == 0x2D || D_002412DC == 0x37) {
            mode = 1;
        }
        if (!(*D_00241120 < 3)) {
            mode = 1;
        }
        if (count > 0) {
            do {
                if (mode == 0 && func_L39_005B4398(4) == 0) {
                    func_L41_0041B578(pos, scale, lo, hi);
                } else {
                    func_L41_0041B350(pos, D_L41_002476F8, 15.6f, D_L41_00247704[0], D_L41_00247704[1], D_L41_00247704[2], D_L41_00247704[3], D_L41_00247704[4], D_L41_00247704[5]);
                }
                count--;
            } while (count != 0);
        }
    }
}
/* localdecomp:end func_L41_0041B9C8 */
