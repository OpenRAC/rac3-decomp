#include "common.h"

/* localdecomp:start func_L39_0067C078 */
extern void func_00137520(void);
extern s32 func_L39_0067A390(void);
extern s32 D_001A5F70[];
extern s32 D_001DB148_sda;

s32 func_L39_0067C078(void) {
    D_001DB148_sda = func_L39_0067A390();
    func_00137520();
    D_001A5F70[0] = 2;
    return 0;
}
/* localdecomp:end func_L39_0067C078 */
