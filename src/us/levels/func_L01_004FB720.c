#include "common.h"

/* localdecomp:start func_L01_004FB720 */
extern s32 func_L01_004FB758(void);

/* hero_flip_window: returns 0 when hero_strafe_side returns 2, else 12. */
s32 func_L01_004FB720(void) {
    s32 result = 12;
    s32 choice = func_L01_004FB758();

    goto evaluate;
clear:
    result = 0;
    goto done;
evaluate:
    if (choice == 2) {
        goto clear;
    }
done:
    return result;
}
/* localdecomp:end func_L01_004FB720 */
