#include "common.h"

/* localdecomp:start func_L09_00405450 */
typedef struct {
    u8 p0[0x1C];
    u8 *p1C;
} E_00405450;
extern u8 *D_001E2BD0[];
extern E_00405450 *D_001DF884;
__asm__(".extern D_001DF884, 16");

void func_L09_00405450(s32 i) {
    u8 *e = D_001DF884[i].p1C;

    if (*(s16 *)(D_001E2BD0[0] + 0x86) == 0x13) {
        e[0x39] = 1;
    }
}
/* localdecomp:end func_L09_00405450 */
