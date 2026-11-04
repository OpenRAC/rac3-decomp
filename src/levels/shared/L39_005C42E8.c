#include "common.h"

typedef struct { u8 pad[0xA4]; u8 flag[0x100]; } S_001A5810_005C42E8;

/* localdecomp:start func_L39_005C42E8 */
extern S_001A5810_005C42E8 D_001A5810;

s32 func_L39_005C42E8(s32 value, u32 idx) {
    if (D_001A5810.flag[idx] != 0) {
        switch (value) {
        case 0x40:
            return 0x44;
        case 4:
            return 1;
        case 8:
            return 2;
        }
    }
    return value;
}
/* localdecomp:end func_L39_005C42E8 */
