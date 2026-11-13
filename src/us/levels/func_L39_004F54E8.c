#include "common.h"

/* localdecomp:start func_L39_004F54E8 */
/* func_L39_004F6220 is the DES key-schedule setup (destination schedule, 8-byte key) */
extern void func_L39_004F6220(void *schedule, void *key);

s32 func_L39_004F54E8(void *schedule, void *key) {
    func_L39_004F6220(schedule, key);
    return 0;
}
/* localdecomp:end func_L39_004F54E8 */
