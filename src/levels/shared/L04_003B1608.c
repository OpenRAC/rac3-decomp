#include "common.h"

/* localdecomp:start func_L04_003B1608 */
extern s32 D_L04_001DE418;
extern s32 D_L04_001DE438;
extern s32 D_L04_001DE448;

s32 func_L04_003B1608(s32 a0, s32 kind, s32 *out) {
    switch (kind) {
    case 5:
        *out = 0xC;
        return (s32)&D_L04_001DE448;
    case 1:
        *out = 0x1C;
        return (s32)&D_L04_001DE418;
    case 2:
        *out = 0xC;
        return (s32)&D_L04_001DE438;
    default:
        return 0;
    }
}
/* localdecomp:end func_L04_003B1608 */
