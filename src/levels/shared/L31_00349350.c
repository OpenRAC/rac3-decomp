#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

/* localdecomp:start func_L31_00349350 */
extern f32 D_L31_001DD018;

s32 func_L31_00349350(void *arg0, void *arg1) {
    s32 var_v0;

    var_v0 = 1;
    if (!((*(f32 *)((u8 *)arg1 + 8)) < ((*(f32 *)((u8 *)arg0 + 0x18)) + D_L31_001DD018))) {
        var_v0 = 0;
    }
    return var_v0;
}
/* localdecomp:end func_L31_00349350 */
