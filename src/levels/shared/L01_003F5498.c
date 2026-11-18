#include "common.h"

/* localdecomp:start func_L01_003F5498 */
typedef struct { char pad[0x128]; float f128; int f12c; char pad2[0x460 - 0x130]; } E_003F5498;
extern float D_L01_001DF950_003F5498[2];
extern E_003F5498 D_L01_001E2A40_003F5498[];

void func_L01_003F5498(int i, float x)
{
    E_003F5498 *e = D_L01_001E2A40_003F5498 + i;
    float *f = D_L01_001DF950_003F5498 + i;
    float r = 1.0f / x;
    *f = 1.0f;
    e->f12c = 0;
    e->f128 = r;
}
/* localdecomp:end func_L01_003F5498 */
