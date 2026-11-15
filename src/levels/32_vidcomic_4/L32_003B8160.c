#include "common.h"

/* localdecomp:start func_L32_003B8160 */
void func_003C2880(void *);
void func_L32_003B8230(void *);

void func_L32_003B8160(void *arg0) {
    u8 *p;
    s32 *slot;
    s32 i;

    p = *(u8 **)((u8 *)arg0 + 0x68);
    *(s32 *)(p + 0x8C) = 0;
    slot = (s32 *)p;
    i = 31;
    do {
        if (*slot != 0) {
            if (*(u8 *)(*(u8 **)slot + 0x20) >= 0xFD) {
                *slot = 0;
            } else {
                *(s32 *)(p + 0x8C) = *(s32 *)(p + 0x8C) + 1;
            }
        }
        i--;
        slot++;
    } while (i >= 0);
    if (*(s32 *)(p + 0x88) == 0 && *(s32 *)(p + 0x8C) == 0) {
        func_003C2880(arg0);
    } else {
        func_L32_003B8230(arg0);
    }
}
/* localdecomp:end func_L32_003B8160 */

/* localdecomp:start func_L32_003B81F0 */
void func_L32_003B81F0(u8 *arg0, s32 arg1) {
    s32 i;
    s32 done;
    s32 *p;

    p = *(s32 **)(arg0 + 0x68);
    done = 0;
    i = 0;
    do {
        if (*p == 0) {
            *p = arg1;
            done = 1;
        }
        i++;
        p++;
    } while (i < 32 && done == 0);
}
/* localdecomp:end func_L32_003B81F0 */
