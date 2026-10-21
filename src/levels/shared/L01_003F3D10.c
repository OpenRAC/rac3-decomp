#include "common.h"

/* localdecomp:start func_L01_003F3D10 */
typedef struct { s32 a, b, c, d, e; } S_37D000;
extern S_37D000 D_L01_002F7680[];
void func_L01_003F3D10(u8 *p) {
    void (*f)(u8 *) = (void (*)(u8 *))D_L01_002F7680[*(s16 *)(p + 0x8C)].e;
    if (f != 0) {
        f(p);
    }
}
/* localdecomp:end func_L01_003F3D10 */
