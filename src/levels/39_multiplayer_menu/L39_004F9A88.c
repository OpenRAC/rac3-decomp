#include "common.h"

/* localdecomp:start func_L39_004F9A88 */
extern void func_L39_004BEF28(void *);

void func_L39_004F9A88(u8 *p) {
    if (p == 0) {
        return;
    }
    if (*(s32 *)(p + 0x14) & 4) {
        if (*(void **)p != 0) {
            func_L39_004BEF28(*(void **)p);
        }
        if (*(void **)(p + 4) != 0) {
            func_L39_004BEF28(*(void **)(p + 4));
        }
        *(s32 *)(p + 4) = 0;
        *(s32 *)p = 0;
    }
    if (*(s32 *)(p + 0x14) & 8) {
        if (*(void **)(p + 0x10) != 0) {
            func_L39_004BEF28(*(void **)(p + 0x10));
        }
        *(s32 *)(p + 0x10) = 0;
        *(s32 *)(p + 0xC) = 0;
    }
    if (*(s32 *)(p + 0x14) & 1) {
        func_L39_004BEF28(p);
    }
}
/* localdecomp:end func_L39_004F9A88 */
