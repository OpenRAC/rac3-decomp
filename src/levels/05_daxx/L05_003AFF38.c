#include "common.h"
#include "vu0.h"

/* declared by functions of L05_003AFC08.c, which this file was cut from */
extern void func_00382580(void *, f32, f32);

/* localdecomp:start func_L05_003AFF38 */
extern s32 func_0038DC20(void *, f32);
extern void func_L05_003AFC08(f32, u8 *, s32, u8 *, s32);
extern void func_00382580(void *, f32, f32);

void func_L05_003AFF38(u8 *obj, f32 x, f32 y, f32 z, f32 w, s32 arg, s32 color, s32 cnt) {
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 v2;
    f32 r;
    s32 i;

    color = (color == 0x1FF) ? 0xFF : color;
    *(vu0_q *)&v0 = *(vu0_q *)(obj + 0x10);
    v0.w = w + w;
    r = 128.0f;
    if (color > 128) {
        r = color;
    }
    if (func_0038DC20(&v0, r) < 0) {
        return;
    }
    func_00382580(&v1, y * 0.8f, y * 1.2f);
    v1.z += x;
    vec_add_ba(&v1, &v1, obj + 0x10);
    for (i = 0; i < 2; i++) {
        func_00382580(&v2, z * 0.75f, z * 1.25f);
        vec_add_ab(&v2, &v1, &v2);
        func_L05_003AFC08(w * 0.75f, (u8 *)&v2, arg, (u8 *)color, cnt);
    }
}
/* localdecomp:end func_L05_003AFF38 */

INCLUDE_ASM("asm/levels", func_L05_003B00A8);
