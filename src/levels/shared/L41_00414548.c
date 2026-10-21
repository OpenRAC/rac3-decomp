#include "common.h"

INCLUDE_ASM("asm/levels", func_L41_00414548);

/* localdecomp:start func_L41_00414900 */
typedef struct {
    s32 x0;
    u8 pad[0x2D];
    u8 x31;
} S_414050;

extern S_414050 *func_L39_0066C1F0(s32);

void func_L41_00414900(S_414050 **p, s32 *id) {
    if (*p != 0) {
        if ((*p)->x0 != *id) {
            *p = 0;
        }
        if (*p != 0 && (*p)->x31 == 0) {
            *p = 0;
            *id = 0;
        }
    }
    if (*p == 0 && *id != 0) {
        *p = func_L39_0066C1F0(*id);
    }
}
/* localdecomp:end func_L41_00414900 */

INCLUDE_ASM("asm/levels", func_L41_00414980);

/* localdecomp:start func_L41_004149E0 */
int func_L41_004149E0(char *a) {
    int i;
    for (i = 0; i < 5; i++) {
        if (((int *)(a + 112))[i] != 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L41_004149E0 */

INCLUDE_ASM("asm/levels", func_L41_00414A10);
