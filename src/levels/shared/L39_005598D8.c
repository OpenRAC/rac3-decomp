#include "common.h"

typedef struct Obj_00559980 {
    u8 pad0[0x10];
    u8 *ptr[5];
    u8 pad1[0xE0 - 0x24];
    u8 item[5][0x10];
} Obj_00559980;

/* localdecomp:start func_L39_005598D8 */
extern f32 D_L39_0024B394;
extern f32 func_0038CF38(u8 *, u8 *);
s32 func_L39_005598D8(u8 *a0, u8 *a1) {
    u8 *s = *(u8 **)(a0 + 104);
    u8 *e;
    s32 i;
    if (a1 == 0) {
        return 0;
    }
    for (i = 0; i < *(s32 *)s; i++) {
        e = ((u8 **)(s + 16))[i];
        if (e != 0 && e != a1 && func_0038CF38(e + 16, a1 + 16) < D_L39_0024B394) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_005598D8 */

/* localdecomp:start func_L39_00559980 */
extern s32 func_L39_005B4398(s32);
extern void func_L01_00443B88(u8 *, f32, f32);
extern s32 func_L39_005598D8(u8 *, u8 *);
extern f32 func_0038CEA8(u8 *);
extern void func_0038CF68(u8 *, u8 *, f32);
extern f32 D_L39_0024B38C;
extern f32 D_L39_0024B390;

void func_L39_00559980(u8 *a0) {
    Obj_00559980 *o = *(Obj_00559980 **)(a0 + 0x68);
    f32 half = 0.5f;
    s32 i;

    for (i = 0; i < 5; i++) {
        if (func_L39_005B4398(10) == 0) {
            func_L01_00443B88(o->item[i], D_L39_0024B38C, D_L39_0024B390);
        }
        if (func_L39_005598D8(a0, o->ptr[i]) != 0) {
            f32 f = func_0038CEA8(o->item[i]) * half;
            func_0038CF68(o->item[i], o->item[i], f);
        }
    }
}
/* localdecomp:end func_L39_00559980 */

INCLUDE_ASM("asm/levels", func_L39_00559A38);
