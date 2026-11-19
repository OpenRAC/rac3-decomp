#include "common.h"

/* localdecomp:start func_L39_00695FC0 */
__asm__(".extern D_L39_0024D760, 16");
__asm__(".extern D_L39_00247914, 16");
typedef struct S_00695FC0_T { s32 f0; u8 pad[0x30]; u8 f34; } S_00695FC0_T;
typedef struct S_00695FC0_G { u8 pad[0x38]; S_00695FC0_T *f38; } S_00695FC0_G;
typedef struct S_00695FC0_O { u8 pad[0x288]; s32 f288; } S_00695FC0_O;
extern S_00695FC0_G *D_L39_0024D760;
extern S_00695FC0_O *D_L39_00247914;
extern S_00695FC0_O *D_001DC204_sda;
s32 func_L39_00695FC0(void)
{
    S_00695FC0_T *t = D_L39_0024D760->f38;
    if (t->f34 != 0) {
        D_L39_00247914->f288 = 9;
        return 1;
    }
    if (t->f0 >= 0) {
        D_001DC204_sda->f288 = 6;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00695FC0 */
