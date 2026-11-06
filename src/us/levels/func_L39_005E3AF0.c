#include "common.h"

typedef struct {
    u8 pad0[0xC];
    s32 first;
    s32 second;
} State_L39_005E3AF0;

/* localdecomp:start func_L39_005E3AF0 */
extern State_L39_005E3AF0 D_001A5990;
extern void func_L39_005F0E48(s32, s32, s32);

void func_L39_005E3AF0(s32 flags) {
    if ((flags & 0x8000) != 0) {
        s32 value = D_001A5990.second - 30;
        if (value < 0) {
            value = 0;
        }
        D_001A5990.second = value;
        goto send;
    }
    if ((flags & 0x2000) != 0) {
        s32 value = D_001A5990.second + 30;
        s32 limit = 0x400;
        if (value < limit + 1) {
            limit = value;
        }
        D_001A5990.second = limit;
    }
send:
    func_L39_005F0E48(3, 0, 0);
}
/* localdecomp:end func_L39_005E3AF0 */
