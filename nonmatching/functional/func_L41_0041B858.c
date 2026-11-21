/* functional: high. VU0 vector adds via the shared vu0.h helpers (vadd.xyz); 106 instructions differ (frame size, gp slot array not addressed through $gp, alignment guards). */
#include "common.h"
/* localdecomp:start func_L41_0041B858 */
#include "vu0.h"
extern s32 D_L41_00247748 __attribute__((section(".sdata")));
extern f32 D_L41_0024774C[11] __attribute__((section(".sdata")));
extern vu0_v4 D_L41_00242930;
extern f32 func_L39_005B4410(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L39_005BE900(void *, s32, f32);
extern void func_L41_0041B350(void *, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L41_0041B6F0(void *);

void func_L41_0041B858(u8 *obj) {
    vu0_v4 probe;
    vu0_v4 pos;
    vu0_v4 acc;
    vu0_v4 tmp;
    s32 i;
    vec_copy(&probe, obj + 0x10);
    probe.w = 5.0f;
    if (func_L39_005BE900(&probe, 0, 128.0f) != -1 && D_L41_00247748 > 0) {
        i = 0;
        do {
            i++;
            func_0038CE20(&tmp, obj + 0xC0, D_L41_0024774C[7] + func_L39_005B4410(-D_L41_0024774C[8], D_L41_0024774C[8]));
            vec_add_ab(&acc, &tmp, &D_L41_00242930);
            func_0038CE20(&tmp, obj + 0xD0, func_L39_005B4410(-D_L41_0024774C[9], D_L41_0024774C[9]));
            vec_add_ba(&acc, &tmp, &acc);
            func_0038CE20(&tmp, obj + 0xE0, D_L41_0024774C[6] + func_L39_005B4410(-D_L41_0024774C[10], D_L41_0024774C[10]));
            vec_add_ba(&acc, &tmp, &acc);
            vec_add_ba(&pos, obj + 0x10, &acc);
            func_L41_0041B350(&pos, 3, 16.0f, D_L41_0024774C[0], D_L41_0024774C[1], D_L41_0024774C[2], D_L41_0024774C[3], D_L41_0024774C[4], D_L41_0024774C[5]);
            func_L41_0041B6F0(&pos);
        } while (i < D_L41_00247748);
    }
}
/* localdecomp:end func_L41_0041B858 */
