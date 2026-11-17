#include "common.h"

/* localdecomp:start func_L39_00505BC8 */
s32 *func_0011A6E0(void);
s32 func_L39_00505C08(s32);

s32 func_L39_00505BC8(s32 arg0) {
    s32 ret;
    if (arg0 == 0 || arg0 == -1) {
        ret = func_L39_00505C08(*func_0011A6E0());
    } else {
        ret = 0;
    }
    return ret;
}
/* localdecomp:end func_L39_00505BC8 */

/* localdecomp:start func_L39_00505C08 */
s32 func_L39_00505C08(s32 arg0) {
    switch (arg0) {
    case 4:
    case 0xB:
    case 0x47:
    case 0x77:
    case 0x78:
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00505C08 */
