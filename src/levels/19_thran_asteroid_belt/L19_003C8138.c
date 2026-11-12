#include "common.h"
#include "vu0.h"

typedef struct { f32 x, y, z, w; } V_3C8138 __attribute__((aligned(16)));

/* localdecomp:start func_L19_003C8138 */
extern u8 *func_L01_00447490(u8 *, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003A52A0(s32, s32, u8 *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_003C2880(void *);

void func_L19_003C8138(u8 *obj) {
    V_3C8138 s[3];
    V_3C8138 c;

    if (func_L01_00447490(obj, -1, 0) != 0) {
        func_0038CE20(&s[0], obj + 0xC0, 0.02f);
        func_0038CE20(&s[1], obj + 0xE0, 0.02f);
        vec_add_ab(&c, &s[0], &s[1]);
        s[2] = c;
        s[0] = c;
        func_003A52A0(0, 0, obj);
        func_L01_00451FE0(obj, 0xFF, s, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        func_003C2880(obj);
    }
}
/* localdecomp:end func_L19_003C8138 */
