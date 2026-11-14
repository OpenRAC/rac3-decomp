#include "common.h"

/* NTSC-U counterpart of func_L40_00420A38 (src/levels/shared/L40_00420A38.c): 0.02 -> 0.0166667 */
extern f32 func_L39_005B2510(void);

/* localdecomp:start func_L40_00420198 */
#include "vu0.h"

__asm__(".extern D_L40_0024786C, 4");
__asm__(".extern D_L40_00247814, 4");
__asm__(".extern D_L40_00247860, 4");
__asm__(".extern D_L40_00247864, 4");
__asm__(".extern D_L40_00247868, 4");
__asm__(".extern D_L40_00247830, 8");
extern s32 D_L40_0024786C;
extern s32 D_L40_00247814;
extern f32 D_L40_00247860;
extern f32 D_L40_00247864;
extern f32 D_L40_00247868;
extern vu0_v4 D_L40_00247830[] __attribute__((section(".sdata")));
extern void func_003BDA38(void *, s32, void *);
extern void func_L40_004200F8(f32 *out);
extern s32 func_L39_005B2498(s32);
extern s32 func_L39_005CD310(void *, void *, void *, void *, s32);

void func_L40_00420198(u8 *self) {
    vu0_v4 pos;
    vu0_v4 off;
    vu0_v4 vel;
    vu0_v4 tmp;
    s32 i;

    if (self[0x31] != 0) {
        for (i = 0; i < D_L40_0024786C; i++) {
            *(vu0_q *)&tmp = 0;
            tmp.z = -(((f32 (*)(f32, f32))func_L39_005B2510)(1.5f, 2.5f) * 0.0166666675f);
            vel = tmp;
            func_003BDA38(self, D_L40_00247814, &pos);
            pos.z -= D_L40_00247860;
            ((void (*)(f32 *, f32, f32))func_L40_004200F8)(&off.x, D_L40_00247864, D_L40_00247864 + D_L40_00247868);
            vec_add_ab(&pos, &pos, &off);
            func_L39_005CD310(self, &pos, &vel, &D_L40_00247830[func_L39_005B2498(3)], 1);
        }
    }
}
/* localdecomp:end func_L40_00420198 */
