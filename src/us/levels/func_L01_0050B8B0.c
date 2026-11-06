#include "common.h"

/* localdecomp:start func_L01_0050B8B0 */
extern u8 D_001A4BE0[];
extern s32 func_L01_0050B850(s32, s32 *);
extern void func_003BE4F0(void *, s32, s32, s32);

void func_L01_0050B8B0(s32 key, s32 mode, f32 fade) {
    u8 *base = D_001A4BE0;
    s32 value;
    if (*(s32 *)(base + 0x2800) == 0 || *(s32 *)(base + 0x2804) == 0) {
        return;
    }
    if (func_L01_0050B850(key, &value) != 0) {
        func_003BE4F0(*(u8 **)(base + 0x2800), value, mode, (s32)fade);
    } else if (*(*(u8 **)(base + 0x2800) + 0x43) != 0) {
        func_003BE4F0(*(u8 **)(base + 0x2800), 0, 0, 7);
    }
}
/* localdecomp:end func_L01_0050B8B0 */
