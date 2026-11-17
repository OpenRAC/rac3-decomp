#include "common.h"

extern s32 D_001A46DC __attribute__((section(".data")));
extern s16 D_001FC4E8 __attribute__((section(".data")));
extern s32 D_001D4D58_sda;
extern void func_L39_005992A8(s32, s32);

/* localdecomp:start func_L39_005F9608 */
/* Sets three globals to 1 and calls func_L39_005992A8 with 1 and 1. */
void func_L39_005F9608(void) {
    D_001FC4E8 = (D_001A46DC = 1);
    D_001D4D58_sda = 1;
    func_L39_005992A8(1, 1);
}
/* localdecomp:end func_L39_005F9608 */
