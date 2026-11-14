#include "common.h"

/* localdecomp:start func_L39_005BF328 */
extern struct {
    u8 pad0[0x79A4];
    s32 base;
    u8 pad79A8[0x10];
    s32 f79B8;
} D_L39_001F0B80;
extern struct {
    u8 pad0[0x90];
    u32 slot[1];
} D_L39_001FE1A0;
extern void func_L39_005BF310(void);
extern void func_00193978(s32, s32, void (*)(void), unsigned long);

void func_L39_005BF328(void) {
    D_L39_001FE1A0.slot[0] = 0xFFFFFFFF;
    func_00193978(D_L39_001F0B80.f79B8 + D_L39_001F0B80.base, 0, func_L39_005BF310, (u32)&D_L39_001FE1A0.slot[0]);
}
/* localdecomp:end func_L39_005BF328 */
