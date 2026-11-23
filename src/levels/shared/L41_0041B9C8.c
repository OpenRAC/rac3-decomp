#include "common.h"

/* localdecomp:start func_L41_0041B9C8 */
#include "vu0.h"
extern s32 *D_00241120;
extern s32 D_002412DC;
__asm__(".extern D_L41_002476F8, 4");
__asm__(".extern D_L41_00247704, 4");
__asm__(".extern D_L41_00247708, 4");
__asm__(".extern D_L41_0024770C, 4");
__asm__(".extern D_L41_00247710, 4");
__asm__(".extern D_L41_00247714, 4");
__asm__(".extern D_L41_00247718, 4");
extern s32 D_L41_002476F8;
extern f32 D_L41_00247704;
extern f32 D_L41_00247708;
extern f32 D_L41_0024770C;
extern f32 D_L41_00247710;
extern f32 D_L41_00247714;
extern f32 D_L41_00247718;
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
                if (mode != 0 || func_L39_005B4398(4) != 0) {
                    func_L41_0041B350(pos, D_L41_002476F8, 15.6f, D_L41_00247704, D_L41_00247708, D_L41_0024770C, D_L41_00247710, D_L41_00247714, D_L41_00247718);
                } else {
                    func_L41_0041B578(pos, scale, lo, hi);
                }
                count--;
            } while (count != 0);
        }
    }
}
/* localdecomp:end func_L41_0041B9C8 */

INCLUDE_ASM("asm/levels", func_L41_0041BAF8);
