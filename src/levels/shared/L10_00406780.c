#include "common.h"

/* localdecomp:start func_L10_00406780 */
typedef struct {
    u8 pad0[170];
    s16 id;
} Item403490;

typedef struct {
    u8 pad0[68];
    s16 count;
    u8 pad46[416 - 70];
    Item403490 *items[1];
} List403490;

extern List403490 D_L10_001E5F00;

Item403490 *func_L10_00406780(s32 id) {
    s32 i;
    for (i = 0; i < D_L10_001E5F00.count; i++) {
        Item403490 *item = D_L10_001E5F00.items[i];
        if (item != 0 && item->id == id) {
            return item;
        }
    }
    return 0;
}
/* localdecomp:end func_L10_00406780 */
