#include "common.h"

/* localdecomp:start func_L39_006B7E90 */
__asm__(".extern D_L39_0024D25C, 16");
extern s32 D_L39_0024D25C;
extern s32 D_001DDBDC_sda;
extern s32 D_001DDBE0_sda;
extern s32 D_001DDBE4_sda;
extern s32 D_001DDBE8_sda;

void func_L39_006B7E90(s32 a, s32 b, s32 c, s32 d, s32 e) {
    D_L39_0024D25C = a;
    D_001DDBDC_sda = b;
    D_001DDBE0_sda = c;
    D_001DDBE4_sda = d;
    D_001DDBE8_sda = e;
}
/* localdecomp:end func_L39_006B7E90 */

INCLUDE_ASM("asm/levels", func_L39_006B7EB0);
