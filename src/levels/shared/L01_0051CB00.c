#include "common.h"

typedef struct { u8 b[16]; } V16_003E6F50;

/* localdecomp:start func_L01_0051CB00 */
extern s32 func_L01_0051CB00(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4);

extern s32 D_L01_001DC240_0051CB00;
extern V16_003E6F50 D_L01_001DC110;
s32 func_L01_0051CB00(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    V16_003E6F50 v;
    f32 out[4];
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_L01_001DC240_0051CB00) != 0) {
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
/* localdecomp:end func_L01_0051CB00 */
