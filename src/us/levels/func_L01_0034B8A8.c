#include "common.h"

typedef struct {
    u8 pad0[0x228];
    s32 zero228;
    f32 scaled22C;
    u8 pad230[8];
    f32 max238;
    f32 hundred23C;
    u8 pad240[0x10];
    s32 value250;
    s32 value254;
    s32 value258;
} Global_L01_0034B8A8;

/* localdecomp:start func_L01_0034B8A8 */
extern Global_L01_0034B8A8 D_L01_001E7600;
extern void func_L01_003FFAC8(void);

/* Stores a 30-frame timer and the given angle into the object, then sets a block of global effect
 * parameters (scaled angle, 255 and 100 limits, 255 values) and calls func_L01_003FFAC8. */
void func_L01_0034B8A8(u8 *object, f32 angle) {
    f32 scaled;
    *(s32 *)(object + 0x4C) = 30;
    *(f32 *)(object + 0x48) = angle;
    scaled = angle * 1024.0f * 0.4f;


    D_L01_001E7600.max238 = 255.0f;
    D_L01_001E7600.scaled22C = scaled;
    D_L01_001E7600.hundred23C = 100.0f;
    D_L01_001E7600.zero228 = 0;
    D_L01_001E7600.value250 = 255;
    D_L01_001E7600.value254 = 255;
    D_L01_001E7600.value258 = 255;
    func_L01_003FFAC8();
}
/* localdecomp:end func_L01_0034B8A8 */
