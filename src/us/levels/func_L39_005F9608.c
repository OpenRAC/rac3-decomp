#include "common.h"

/* localdecomp:start func_L39_005F9608 */
extern u8 D_001A46D0[0x20];
extern u8 D_001FC4E0[0x20];
extern s32 D_001D4D58_sda;
extern void func_L39_005992A8(s32, s32);

void func_L39_005F9608(void) {
    *(s16 *)(D_001FC4E0 + 8) = (*(s32 *)(D_001A46D0 + 0xC) = 1);
    D_001D4D58_sda = 1;
    func_L39_005992A8(1, 1);
}
/* localdecomp:end func_L39_005F9608 */
