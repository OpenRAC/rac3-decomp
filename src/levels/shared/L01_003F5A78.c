#include "common.h"

typedef struct {
    s32 f0;
    u8 pad[16];
} S_003F38D0;

/* localdecomp:start func_L01_003F5A78 */
extern S_003F38D0 D_L01_002F7680[];
s32 func_L01_003F5A78(s32 id) {
    s32 i;
    for (i = 0; D_L01_002F7680[i].f0 != -1 && D_L01_002F7680[i].f0 != id; i++) {
    }
    return i;
}
/* localdecomp:end func_L01_003F5A78 */

INCLUDE_ASM("asm/levels", func_L01_003F5AC0);

INCLUDE_ASM("asm/levels", func_L01_003F5BE0);

INCLUDE_ASM("asm/levels", func_L01_003F5E88);

INCLUDE_ASM("asm/levels", func_L01_003F5EE0);

INCLUDE_ASM("asm/levels", func_L01_003F5F10);

INCLUDE_ASM("asm/levels", func_L01_003F5FC0);

INCLUDE_ASM("asm/levels", func_L01_003F6048);

LINKER_REMNANT("asm/levels", func_L01_003F6208);
