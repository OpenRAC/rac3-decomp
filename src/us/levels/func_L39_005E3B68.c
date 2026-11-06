#include "common.h"

/* localdecomp:start func_L39_005E3B68 */
extern u8 D_001A5990[];
extern void func_L39_005F0E48(s32, s32, s32);

void func_L39_005E3B68(s32 flags) {
    if ((flags & 0xA040) != 0) {
        func_L39_005F0E48(4, 0, 0);
        D_001A5990[5] = D_001A5990[5] == 0;
    }
}
/* localdecomp:end func_L39_005E3B68 */
