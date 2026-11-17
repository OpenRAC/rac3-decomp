#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003DDB90 */
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00443B88(void *, f32, f32);
extern s32 func_00382468(s32);
extern void func_L01_0046C470(void *, void *, s32, s32, s32, s32, s32, s32, f32);

void func_L05_003DDB90(u8 *a0) {
    vu0_v4 p;
    vu0_v4 v;
    vu0_v4 w;
    s32 i;

    if (a0[0x42] == 1) {
        func_003C2F58(a0, 0, &p);
    } else {
        func_0038CE20(&p, a0, 0.0009765625f);
    }
    func_L01_00443B88(&v, 0.020000001f, 0.040000003f);
    func_L01_0046C470(&p, &v, 0x50808080, 0x1E, func_00382468(0xFF) & 0xFF, 0, 0x40, 0, 0.5f);
    for (i = 0; i < 3; i++) {
        func_L01_00443B88(&w, 0.0f, 0.0066600004f);
        vec_add_ab(&v, &v, &w);
        func_L01_0046C470(&p, &v, 0x40807070, 0x1E, func_00382468(0xFF) & 0xFF, 0, 0x40, 0, 0.3f);
    }
}
/* localdecomp:end func_L05_003DDB90 */
