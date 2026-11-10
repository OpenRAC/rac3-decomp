#include "common.h"

typedef struct Obj_003A88E8 {
    u8 pad0[0x94C];
    s16 f94C;
    u8 pad94E[0x0E];
    s32 f95C;
    u8 pad960[0x20];
    s32 f980;
    s32 f984;
} Obj_003A88E8;

/* localdecomp:start func_L24_003A85F0 */
/* m2c3 */
s32 func_L24_003A8530(f32);                         /* extern */

void func_L24_003A85F0(void *arg0) {
    f32 temp_f2;
    f32 var_f12;

    temp_f2 = (f32) (*(u16 *)((u8 *)(arg0) + 0x96));
    if (temp_f2 > 90.0f) {
        var_f12 = (180.0f - temp_f2) / 180.0f;
    } else {
        var_f12 = (temp_f2 / 180.0f) + 1.0f;
    }
    func_L24_003A8530(var_f12);
}
/* localdecomp:end func_L24_003A85F0 */
