#include "common.h"

/* localdecomp:start func_L39_00665B20 */
typedef struct {
    u8 reserved0[0x2D8];
    s32 field2D8;
    s32 field2DC;
    u8 reserved2E0[0x2F8 - 0x2E0];
    s32 field2F8;
} Entry_L39_00665B20;

typedef struct {
    u8 reserved0[0x2528];
    Entry_L39_00665B20 *entry;
    u8 reserved252C[0x254C - 0x252C];
    s32 mode;
} Owner_L39_00665B20;

extern s32 D_001A5E58[];

/* Detaches the owner's linked entry: advances the selection index (wraps at 8), clears the entry's
 * field by mode (2D8 for modes 3 and 5, 2DC for 4 and 6) and sets flag bits when the selection
 * matches, then clears the owner's entry and mode. */
void func_L39_00665B20(Owner_L39_00665B20 *owner, s32 selection) {
    Entry_L39_00665B20 *entry;
    s32 mode;
    selection = selection + 1;
    if (selection >= 8) {
        selection = 0;
    }
    entry = owner->entry;
    if (entry == 0) {
        return;
    }
    mode = owner->mode;
    if (mode == 5 || mode == 3) {
        entry->field2D8 = 0;
        if (D_001A5E58[0] == selection) {
            owner->entry->field2F8 |= 4;
            owner->entry->field2F8 |= 2;
            owner->entry->field2F8 &= 0xFFFFFFDF;
        }
    } else if (mode == 6 || mode == 4) {
        entry->field2DC = 0;
    }
    owner->entry = 0;
    owner->mode = 0;
}
/* localdecomp:end func_L39_00665B20 */
