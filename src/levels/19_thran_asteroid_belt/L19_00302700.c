#include "common.h"

typedef struct Settings_00302700 {
    u8 pad[0x7C];
    s8 x;
    s8 y;
    s8 z;
    s8 w;
} Settings_00302700;
typedef struct Obj_00302700 {
    u8 pad[0x100];
} Obj_00302700;

/* localdecomp:start func_L19_00302700 */
extern Obj_00302700 *D_L19_001DF71C;

void func_L19_00302700(int index, Settings_00302700 *settings, int enable) {
    u8 *obj = (u8 *)(D_L19_001DF71C + index);

    if (!obj)
        return;
    if (enable) {
        if (settings->x > 0)
            *(u16 *)(obj + 0x34) &= ~2;
        else if (settings->x < 0)
            *(u16 *)(obj + 0x34) |= 2;
        if (settings->y > 0 && (!obj || !*(u8 **)(obj + 0x24) ||
            *(u8 *)(*(u8 **)(obj + 0x24) + 0x46) != 18)) {
            obj[0x31] = 1;
            *(u16 *)(obj + 0x34) &= ~1;
        } else if (settings->y < 0 && (!obj || !*(u8 **)(obj + 0x24) ||
                   *(u8 *)(*(u8 **)(obj + 0x24) + 0x46) != 18)) {
            obj[0x31] = 0;
            *(u16 *)(obj + 0x34) |= 1;
        }
        if (settings->w > 0 && *(u8 **)(obj + 0x24))
            *(int *)(obj + 0x98) = *(int *)(*(u8 **)(obj + 0x24) + 0x10);
        else if (settings->w < 0 && *(u8 **)(obj + 0x24))
            *(int *)(obj + 0x98) = 0;
    } else {
        if (settings->x > 0 && (!*(u8 **)(obj + 0x24) ||
            *(u8 *)(*(u8 **)(obj + 0x24) + 0x46) != 18))
            *(u16 *)(obj + 0x34) |= 2;
        else if (settings->x < 0 && (!obj || !*(u8 **)(obj + 0x24) ||
                 *(u8 *)(*(u8 **)(obj + 0x24) + 0x46) != 18))
            *(u16 *)(obj + 0x34) &= ~2;
        if (settings->y > 0 && (!obj || !*(u8 **)(obj + 0x24) ||
            *(u8 *)(*(u8 **)(obj + 0x24) + 0x46) != 18)) {
            obj[0x31] = 0;
            *(u16 *)(obj + 0x34) |= 1;
        } else if (settings->y < 0 && (!obj || !*(u8 **)(obj + 0x24) ||
                   *(u8 *)(*(u8 **)(obj + 0x24) + 0x46) != 18)) {
            obj[0x31] = 1;
            *(u16 *)(obj + 0x34) &= ~1;
        }
        if (settings->w > 0)
            *(int *)(obj + 0x98) = 0;
        else if (settings->w < 0)
            *(int *)(obj + 0x98) = *(int *)(*(u8 **)(obj + 0x24) + 0x10);
    }
}
/* localdecomp:end func_L19_00302700 */
