#include "common.h"

/* localdecomp:start func_L39_005088D0 */
extern u8 D_L39_0046F010[];

s32 func_L39_005088D0(void ***list, void ***arr, void *key, s32 *out) {
    s32 i;
    s32 found;
    void *t;

    i = 0;
    found = 0;
    for (; *list != 0; list++, i++) {
        t = **list;
        if (t == key) {
            found++;
        }
        if (t == D_L39_0046F010) {
            break;
        }
    }
    if (found == 0) {
        return 0;
    }
    found += i + 2;
    i = 0;
    if (arr != 0) {
        for (; arr[i] != 0; i++) {
        }
        if (*arr[i - 1] == D_L39_0046F010) {
            return 0;
        }
    }
    *out = i;
    return found;
}
/* localdecomp:end func_L39_005088D0 */
