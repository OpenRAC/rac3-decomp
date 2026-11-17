#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L09_003BD860 */
s32 func_L09_003BD860(void *arg0) {
    s32 var_a0;
    void *temp_v0;

    temp_v0 = *(void **)((u8 *)arg0 + 0x68);
    var_a0 = 1;
    if (!(((*(f32 *)((u8 *)temp_v0 + 0x30)) + 1.0f) <= ((f32) (*(s16 *)((u8 *)temp_v0 + 0x34)) * (*(f32 *)((u8 *)temp_v0 + 0xD4C))))) {
        var_a0 = 0;
    }
    return var_a0;
}
/* localdecomp:end func_L09_003BD860 */
