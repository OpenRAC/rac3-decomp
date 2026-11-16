#include "common.h"

/* localdecomp:start func_L39_006DAA58 */
extern u8 D_001B34B1[];

/* Converts the zero-terminated string text to upper case in place, using a character class table
 * (bit 2 marks lower case letters). */
void func_L39_006DAA58(void *unused, u8 *text) {
    u8 *cursor = text;
    if (*cursor != 0) {
        u8 *table = D_001B34B1;
        do {
            s32 letter = *cursor;
            u8 *entry = (u8 *)((s32)letter + (s32)table);
            s32 upper = letter - 0x20;
            if ((*entry & 2) == 0) {
                upper = letter;
            }
            *cursor = upper;
            cursor++;
        } while (*cursor != 0);
    }
}
/* localdecomp:end func_L39_006DAA58 */
