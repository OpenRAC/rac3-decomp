#include "common.h"
/* localdecomp:start func_L01_004C8A80 */
extern int D_L01_001E1220;
extern float D_L01_001E1224;
extern float D_L01_001E1228;

void func_L01_004C8A80(int a0)
{
    float value;

    D_L01_001E1220 = a0;
    value = 1.076923f;
    if (a0 == 0)
        value = 1.0f;
    D_L01_001E1224 = value;
    value = 0.9f;
    if (a0 == 0)
        value = 1.0f;
    D_L01_001E1228 = value;
}
/* localdecomp:end func_L01_004C8A80 */
