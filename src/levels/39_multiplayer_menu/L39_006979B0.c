#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006979B0);

/* localdecomp:start func_L39_00697B28 */
__asm__(".extern D_L39_0024D760, 16");
__asm__(".extern D_L39_00247914, 16");

typedef struct {
    s32 f0;
    char pad[0x30];
    u8 f34;
} S_00697B28_inner;

typedef struct {
    char pad[0x38];
    S_00697B28_inner *f38;
} S_00697B28_outer;

typedef struct {
    char pad[0x288];
    s32 f288;
} S_00697B28_slot;

extern S_00697B28_outer *D_L39_0024D760;
extern S_00697B28_slot *D_L39_00247914;
extern S_00697B28_slot *D_001DC204_sda;

s32 func_L39_00697B28(void)
{
    S_00697B28_inner *inner = D_L39_0024D760->f38;

    if (inner->f0 == -1) {
        D_L39_00247914->f288 = 8;
        return 1;
    }
    if (inner->f34 == 0) {
        D_001DC204_sda->f288 = 6;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00697B28 */

INCLUDE_ASM("asm/levels", func_L39_00697B80);
