#include "common.h"

/* localdecomp:start func_L39_005BF380 */
typedef struct {
    s32 offset;
    s32 pad;
} Ent_L39_005BF380;
extern struct {
    u8 pad0[0x79A4];
    s32 base;
    u8 pad79A8[0x40];
    Ent_L39_005BF380 tab[1];
} D_L39_001F0B80;
extern struct {
    u8 pad0[0x90];
    u32 slot[1];
} D_L39_001FE1A0;
extern void func_L39_005BF310(void);
extern void func_00193978(s32, s32, void (*)(void), unsigned long);

void func_L39_005BF380(s32 idx) {
    s32 off = D_L39_001F0B80.tab[idx].offset;

    if (off != 0) {
        D_L39_001FE1A0.slot[idx + 1] = 0xFFFFFFFF;
        func_00193978(off + D_L39_001F0B80.base, 0, func_L39_005BF310, (u32)&D_L39_001FE1A0.slot[idx + 1]);
    } else {
        D_L39_001FE1A0.slot[idx + 1] = 0;
    }
}
/* localdecomp:end func_L39_005BF380 */
