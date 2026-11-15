#include "common.h"

/* declared by functions of L40_00430928.c, which this file was cut from */
extern u8 *func_L39_0066DD30(s32, s32, s32);

/* localdecomp:start func_L40_004313A0 */
extern u8 *func_L39_0066DD30(s32 a0, s32 a1, s32 a2);
extern u8 *func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_L39_00662AA0(u8 *a0, s32 a1, s32 a2);
extern void func_L39_00662B68(u8 *a0, s32 a1, s32 a2);

void func_L40_004313A0(u8 *m, s32 a1, f32 f) {
    u8 *v = *(u8 **)(m + 0x68);
    u8 *o;

    o = func_L39_0066DD30((s32)m, 1, 1);
    if (o != 0) {
        f32 t0;

        o[0x54] = 0;
        t0 = f;
        func_L39_00662AA0(o, (s32)&t0, 4);
        func_L39_00662AA0(o, a1, 8);
    } else {
        f32 t1;

        o = func_L39_0066DCC8((s32)m, 1, 0, 250);
        t1 = f;
        func_L39_00662AA0(o, (s32)&t1, 4);
        func_L39_00662AA0(o, a1, 8);
    }
    if (*(s16 *)(v + 0x34) * 0.1f <= f) {
        func_L39_00662B68(o, 0, 250);
    } else {
        func_L39_00662B68(o, 250, 250);
    }
}
/* localdecomp:end func_L40_004313A0 */
