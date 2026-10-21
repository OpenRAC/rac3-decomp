#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_004601F8);

/* localdecomp:start func_L01_00460200 */
extern float D_L01_001D7DEC;

void func_L01_00460200(float f)
{
    float x = 1.0f;
    if (f < x) x = f;
    D_L01_001D7DEC = x;
}
/* localdecomp:end func_L01_00460200 */

/* localdecomp:start func_L01_00460228 */
extern s32 D_L01_001D7E20;
s32 func_L01_00460228(void) {
    if (D_L01_001D7E20 == 0) {
        D_L01_001D7E20 = 1;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_00460228 */

/* localdecomp:start func_L01_00460248 */
extern s32 D_L01_001D7E20;

void func_L01_00460248(void) { D_L01_001D7E20 = 0; }
/* localdecomp:end func_L01_00460248 */
