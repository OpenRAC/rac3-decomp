#include "common.h"

typedef void (*fn_3A2780)(u8 *);

/* localdecomp:start func_L01_003A4938 */
extern s32 D_L01_001DE2C0;
extern s32 D_L01_001DE2E0;
s32 *func_L01_003A4938(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 5:
        *a2 = 12;
        return &D_L01_001DE2E0;
    case 1:
        *a2 = 28;
        return &D_L01_001DE2C0;
    }
    return 0;
}
/* localdecomp:end func_L01_003A4938 */
