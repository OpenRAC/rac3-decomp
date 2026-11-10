#include "common.h"

/* localdecomp:start func_L02_003C14B8 */
extern u8 D_L02_001E1300[];

/* from rac4-decomp's func_L00_0058E0B0 */
void func_L02_003C14B8(s32 index, f32 value) {
    u8 *entry = D_L02_001E1300 + index * 0x460;
    u8 *object = *(u8 **)(entry + 0x50);
    if (*(s16 *)(object + 0x86) == 0) {
        u8 *target = *(u8 **)(object + 0x70);
        *(f32 *)(target + 0x204) = value;
    }
}
/* localdecomp:end func_L02_003C14B8 */
