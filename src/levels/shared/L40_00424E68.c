#include "common.h"

/* declared by functions of L40_00424920.c, which this file was cut from */
extern u8 *func_L39_0066DD30(s32, s32, s32);

/* localdecomp:start func_L40_00424E68 */
extern void func_L39_00662B68(void *, s32, s32);

void func_L40_00424E68(u8 *obj, void *a1, f32 val) {
    u8 *vars = *(u8 **)(obj + 0x68);
    u8 *p = func_L39_0066DD30((s32)obj, 2, 1);
    if (p != 0) {
        f32 t;
        p[0x54] = 0;
        t = val;
        func_L39_00662AA0((s32)p, &t, 4);
        func_L39_00662AA0((s32)p, a1, 8);
    } else {
        f32 t2;
        p = (u8 *)func_L39_0066DCC8((s32)obj, 2, 0, 250);
        t2 = val;
        func_L39_00662AA0((s32)p, &t2, 4);
        func_L39_00662AA0((s32)p, a1, 8);
    }
    if ((f32)*(s16 *)(vars + 0x34) * 0.05f <= val) {
        func_L39_00662B68(p, 0, 250);
    } else {
        func_L39_00662B68(p, 250, 250);
    }
}
/* localdecomp:end func_L40_00424E68 */
