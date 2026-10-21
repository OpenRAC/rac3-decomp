#include "common.h"

typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
typedef struct { u8 b[16]; } V16_003E6F50;

/* localdecomp:start func_L01_0051C2A0 */
extern s32 func_L01_0051C2A0(u8 *p, s32 a, s32 b);
extern void func_003EDAD0(void *, s32, s32);
extern s32 D_L01_001DC180_0051C2A0;

s32 func_L01_0051C2A0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC180_0051C2A0)) {
        func_003EDAD0(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051C2A0 */

/* localdecomp:start func_L01_0051C308 */
extern s32 func_L01_0051C308(u8 *p, s32 a, u8 *out);
extern s32 func_003EDAF8();
extern s32 D_L01_001DC180_0051C308;

s32 func_L01_0051C308(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC180_0051C308)) {
        *out = func_003EDAF8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051C308 */

/* localdecomp:start func_L01_0051C370 */
extern s32 func_L01_0051C370(u8 *p, s32 a, s32 b);
extern void func_003EDB08();
extern s32 D_L01_001DC180_0051C370;

s32 func_L01_0051C370(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC180_0051C370)) {
        func_003EDB08(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051C370 */

/* localdecomp:start func_L01_0051C3D8 */
extern s32 func_L01_0051C3D8(u8 *p, s32 a, s32 b);
extern void func_003EDB40();
extern s32 D_L01_001DC180_0051C3D8;

s32 func_L01_0051C3D8(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC180_0051C3D8)) {
        func_003EDB40(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051C3D8 */

INCLUDE_ASM("asm/levels", func_L01_0051C440);

/* localdecomp:start func_L01_0051C4A8 */
extern s32 func_L01_0051C4A8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);

extern s32 D_L01_001DC180_0051C4A8;
extern V16_003E6F50 D_L01_001DC110;
s32 func_L01_0051C4A8(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    V16_003E6F50 v;
    f32 out[4];
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_L01_001DC180_0051C4A8) != 0) {
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
/* localdecomp:end func_L01_0051C4A8 */
