#include "common.h"

/* declared by functions of L40_00420998.c, which this file was cut from */
extern f32 func_L39_005B4410(void);

/* localdecomp:start func_L40_00420A38 */
#include "vu0.h"

__asm__(".extern D_L40_002476EC, 4");
__asm__(".extern D_L40_00247694, 4");
__asm__(".extern D_L40_002476E0, 4");
__asm__(".extern D_L40_002476E4, 4");
__asm__(".extern D_L40_002476E8, 4");
__asm__(".extern D_L40_002476B0, 8");
extern s32 D_L40_002476EC;
extern s32 D_L40_00247694;
extern f32 D_L40_002476E0;
extern f32 D_L40_002476E4;
extern f32 D_L40_002476E8;
extern vu0_v4 D_L40_002476B0[] __attribute__((section(".sdata")));
extern void func_003C2F58(void *, s32, void *);
extern void func_L40_00420998(f32 *out);
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_005CF720(void *, void *, void *, void *, s32);

void func_L40_00420A38(u8 *self) {
    vu0_v4 pos;
    vu0_v4 off;
    vu0_v4 vel;
    vu0_v4 tmp;
    s32 i;

    if (self[0x31] != 0) {
        for (i = 0; i < D_L40_002476EC; i++) {
            *(vu0_q *)&tmp = 0;
            tmp.z = -(((f32 (*)(f32, f32))func_L39_005B4410)(1.5f, 2.5f) * 0.020000001f);
            vel = tmp;
            func_003C2F58(self, D_L40_00247694, &pos);
            pos.z -= D_L40_002476E0;
            ((void (*)(f32 *, f32, f32))func_L40_00420998)(&off.x, D_L40_002476E4, D_L40_002476E4 + D_L40_002476E8);
            vec_add_ab(&pos, &pos, &off);
            func_L39_005CF720(self, &pos, &vel, &D_L40_002476B0[func_L39_005B4398(3)], 1);
        }
    }
}
/* localdecomp:end func_L40_00420A38 */
