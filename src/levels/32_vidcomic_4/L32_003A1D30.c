#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L32_003A1D30 */
extern s32 func_00382498(s32, s32);

void func_L32_003A1D30(void *arg0) {
    u8 *v = *(u8 **)((u8 *)arg0 + 0x68);
    s32 n;
    s32 i;
    s32 r;

    n = 0;
    for (i = 0; i < 4; i++) {
        s32 *ids = (s32 *)(v + 0x90);
        if (ids[i] != -1) {
            n++;
        }
    }
    if (n >= 2) {
        if (n == 2) {
            for (i = 0; i < 4; i++) {
                s32 *ids = (s32 *)(v + 0x90);
                if (ids[i] != -1 && i != *(s32 *)(v + 0xF0)) {
                    *(s16 *)(v + 0x22A) = i;
                }
            }
            return;
        }
        r = func_00382498(0, n - 3);
        for (i = 0; i < 4; i++) {
            for (i = 0; i < 4; i++) {
                s32 *ids = (s32 *)(v + 0x90);
                if (ids[i] != -1 && i != *(s32 *)(v + 0xF0) && i != *(s16 *)(v + 0x22A)) {
                    if (r == 0) {
                        *(s16 *)(v + 0x22A) = i;
                        return;
                    }
                    r--;
                }
            }
        }
    }
    *(s16 *)(v + 0x22A) = *(s32 *)(v + 0xF0);
}
/* localdecomp:end func_L32_003A1D30 */
