#include "common.h"

/* localdecomp:start func_L12_003D90A8 */
extern u8 *func_L01_00449050(void);
u8 func_L12_003D90A8(u8 *a0) {
    u8 *p;
    if (*(s32 *)(*(u8 **)(a0 + 104) + 372) != 0) {
        return 0;
    }
    p = func_L01_00449050();
    if (p[13] != 255) {
        return p[13];
    }
    return 2;
}
/* localdecomp:end func_L12_003D90A8 */
