#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x28];
    s32 w28;
} S_311A18m;
typedef struct {
    u8 pad0[0x10];
    s128 q10;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    S_311A18m *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} S_311A18;


/* localdecomp:start func_L01_003113E8 */
s32 func_L01_003113E8(s32 x) {
    s32 d = 16;
    if (x % d) {
        x = ((s32)((f32)x / (f32)d) + 1) << 4;
    }
    return x;
}
/* localdecomp:end func_L01_003113E8 */
