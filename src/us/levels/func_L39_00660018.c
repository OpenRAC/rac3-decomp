#include "common.h"

/* localdecomp:start func_L39_00660018 */
extern u8 D_001A5E50[];
extern u8 *func_L39_00660120(void);
extern void func_00388550(void *, void *, s32);
extern void func_L39_00660308(u8 *);

/* Copies a variable-length packet (length from its header) into a new entry from func_L39_00660120
 * when the kind differs from the current one, marks the entry's +0x50 as -1, calls
 * func_L39_00660308 if it is already due, and returns the length. */
u32 func_L39_00660018(s32 first, s32 second, s32 kind, u32 *source) {
    u8 *entry;
    u8 *state = D_001A5E50;
    u32 first_word;
    u32 length = ((*source >> 4) & 0x3F) + 12;
    if (*(s32 *)(state + 8) != kind) {
        entry = func_L39_00660120();
        func_00388550(entry, source, length);
        first_word = *(u32 *)entry;
        *(s32 *)(entry + 0x50) = -1;
        if (*(s32 *)(entry + 4) + (s32)(first_word >> 13) - *(s32 *)(state + 0x128) < 0) {
            if (first_word & 0xFFFFE000) {
                func_L39_00660308(entry);
            }
        }
    }
    return length;
}
/* localdecomp:end func_L39_00660018 */
