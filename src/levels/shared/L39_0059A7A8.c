#include "common.h"

/* localdecomp:start func_L39_0059A7A8 */
extern u8 D_001A58C7 __attribute__((section(".data")));
extern u8 D_001F3048[];
extern u8 D_001F3688[];
extern u8 D_001F3CC8[];
extern u8 D_001F4308[];
extern u8 D_001F4948[];

void *func_L39_0059A7A8(void) {
    switch (D_001A58C7) {
    case 0:
    case 1:
    default:
        return D_001F3048;
    case 2:
        return D_001F3688;
    case 3:
        return D_001F3CC8;
    case 4:
        return D_001F4308;
    case 5:
        return D_001F4948;
    }
}
/* localdecomp:end func_L39_0059A7A8 */
