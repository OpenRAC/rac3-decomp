#include "common.h"

/* localdecomp:start func_L39_004F5340 */
extern void func_L39_004F7310(s32, s32, s32);

/* Calls func_L39_004F7310 with the fields 1, 0 and 3 of the array p and returns 0. */
s32 func_L39_004F5340(s32 *p) {
    func_L39_004F7310(p[1], p[0], p[3]);
    do {
        return 0;
    } while (0);
}
/* localdecomp:end func_L39_004F5340 */
