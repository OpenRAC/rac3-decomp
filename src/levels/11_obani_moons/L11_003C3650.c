#include "common.h"

/* localdecomp:start func_L11_003C3650 */
typedef struct { u8 pad0[0x50]; u8 *object; u8 pad54[0x40C]; } E_L11_003C3650;
extern E_L11_003C3650 D_L11_001E1780[];
void func_L11_003C3650(s32 index, f32 x, f32 y) {
    E_L11_003C3650 *entry = (E_L11_003C3650 *)((u8 *)D_L11_001E1780 + index * 0x460);
    u8 *object = entry->object;
    if (*(s16 *)(object + 0x86) == 0) {
        u8 *p = *(u8 **)(object + 0x70) + 0x20;
        if (x != 0.0f) {
            *(f32 *)(p + 0x1C) = x;
        }
        if (y != 0.0f) {
            *(f32 *)(p + 0x20) = y;
        }
    }
}
/* localdecomp:end func_L11_003C3650 */
