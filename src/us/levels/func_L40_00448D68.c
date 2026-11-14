#include "common.h"

extern s32 D_001D6D24_sda;
extern s32 D_001A6C00[];
extern s32 func_L40_0047EE90(s32);

/* localdecomp:start func_L40_00448D68 */
/* Returns the Nth nonzero entry (N from func_L40_0047EE90 of a global) in a table of 0xC0 words
 * starting at word 3 of D_001A6C00, or 0 if there are fewer. */
s32 func_L40_00448D68(void) {
    s32 remaining = func_L40_0047EE90(D_001D6D24_sda);
    s32 *cursor = D_001A6C00;
    s32 index;
    cursor += 3;
    for (index = 0; index < 0xC0; ++index, ++cursor) {
        s32 value = *cursor;
        if (value != 0 && --remaining == 0) {
            return value;
        }
    }
    return 0;
}
/* localdecomp:end func_L40_00448D68 */
