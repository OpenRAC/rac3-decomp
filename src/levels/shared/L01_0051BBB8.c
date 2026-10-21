#include "common.h"

typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
typedef struct { u8 b[16]; } V16_003E6F50;

/* localdecomp:start func_L01_0051BBB8 */
extern s32 func_L01_0051BBB8(u8 *p, s32 a, s32 b);
extern void func_003EDAD0(void *, s32, s32);
extern s32 D_L01_001DC1B0;

s32 func_L01_0051BBB8(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC1B0)) {
        func_003EDAD0(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051BBB8 */

/* localdecomp:start func_L01_0051BC20 */
extern s32 func_L01_0051BC20(u8 *p, s32 a, u8 *out);
extern s32 func_003EDAF8();
extern s32 D_L01_001DC1B0_0051BC20;

s32 func_L01_0051BC20(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC1B0_0051BC20)) {
        *out = func_003EDAF8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051BC20 */

/* localdecomp:start func_L01_0051BC88 */
extern s32 func_L01_0051BC88(u8 *p, s32 a, s32 b);
extern void func_003EDB08();
extern s32 D_L01_001DC1B0_0051BC88;

s32 func_L01_0051BC88(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC1B0_0051BC88)) {
        func_003EDB08(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051BC88 */

/* localdecomp:start func_L01_0051BCF0 */
extern s32 func_L01_0051BCF0(u8 *p, s32 a, s32 b);
extern void func_003EDB40();
extern s32 D_L01_001DC1B0_0051BCF0;

s32 func_L01_0051BCF0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC1B0_0051BCF0)) {
        func_003EDB40(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051BCF0 */

INCLUDE_ASM("asm/levels", func_L01_0051BD58);

/* localdecomp:start func_L01_0051BDC0 */
extern s32 func_L01_0051BDC0(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);

extern s32 D_L01_001DC1B0;
extern V16_003E6F50 D_L01_001DC110;
s32 func_L01_0051BDC0(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    V16_003E6F50 v;
    f32 out[4];
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_L01_001DC1B0) != 0) {
        v = D_L01_001DC110;
        (*(s32 (**)(void *, void *, f32 *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x20))(arg0, &v, out, 1);
        *arg1 = out[0];
        *arg2 = out[1];
        *arg3 = out[2];
        *arg4 = out[3];
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051BDC0 */
