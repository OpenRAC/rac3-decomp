#include "common.h"

/* localdecomp:start func_L39_0067C078 */
extern void func_00137520(void);
extern s32 func_L39_0067A390(void);
extern s32 D_001A5F70[];
extern s32 D_001DB148_sda;

/* Stores the result of func_L39_0067A390 in a global, calls func_00137520, sets the first byte of
 * D_001A5F70 to 2, and returns 0. */
s32 func_L39_0067C078(void) {
    D_001DB148_sda = func_L39_0067A390();
    func_00137520();
    D_001A5F70[0] = 2;
    return 0;
}
/* localdecomp:end func_L39_0067C078 */
