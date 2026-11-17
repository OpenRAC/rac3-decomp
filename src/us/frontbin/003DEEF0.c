#include "common.h"

/* NTSC-U counterpart of func_003E4440 (frontbin). */
extern s32 func_U_003E2C88(s32, f32, f32);
typedef struct { u8 pad[0x28B4]; s32 a; s32 b; } S_003DEEF0;
extern S_003DEEF0 D_001A4BE0;
extern s32 D_00142694[];
extern void func_U_0037DCD8();
extern s32 func_U_003E2C88(s32, f32, f32);
extern S_003DEEF0 D_001A4BE0;
extern s32 D_00142694[];
extern void func_U_0037DCD8();
extern s32 func_U_003E2C88(s32, f32, f32);

/* localdecomp:start func_U_003DEEF0 */
s32 func_U_003DEEF0(void) {
    s32 l[3];
    s32 pos;
    f32 den;
    f32 num;
    f32 t;
    pos = D_00142694[0] >> 5;
    l[0] = D_001A4BE0.b;
    l[1] = D_001A4BE0.a;
    if (l[0] == 0) {
        l[2] = 0;
        func_U_0037DCD8(l, l + 1, l + 2);
    }
    num = (f32)(pos - l[0]);
    den = (f32)(l[1] - l[0]);
    t = (den <= 0.0f) ? 0.0f : num / den;
    return func_U_003E2C88(0x90007, t * 0.1285f, 0.008f);
}
/* localdecomp:end func_U_003DEEF0 */
