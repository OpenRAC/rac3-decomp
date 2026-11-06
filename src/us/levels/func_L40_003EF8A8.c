#include "common.h"

/* localdecomp:start func_L40_003EF8A8 */
extern s32 D_001DB70C_sda_b;
extern s32 func_L40_0047EE90(s32);
extern void func_L40_0047F5C0(void *, s32, s32, s32);

void func_L40_003EF8A8(u8 *object) {
    if (object[0x42] < 2) {
        if (object[0x60] & 2) {
            if (func_L40_0047EE90(D_001DB70C_sda_b - 1) == 0) {
                func_L40_0047F5C0(object, 1, 0, 0x14);
            } else if (object[0x42] != 0) {
                func_L40_0047F5C0(object, 0, 0, 0x14);
            }
        }
    }
}
/* localdecomp:end func_L40_003EF8A8 */
