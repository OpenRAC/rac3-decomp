#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005D6AE0);

INCLUDE_ASM("asm/levels", func_L39_005D6DC8);

/* localdecomp:start func_L39_005D72E8 */
typedef struct { u8 p0[17664]; } E_005D4D78;

extern E_005D4D78 D_L39_002FB000[];
extern u8 D_L39_001D7EE8[2];
extern s32 D_L39_001D7ED8[2];
extern E_005D4D78 *D_L39_001D7EF0[2];
extern void func_L01_00516AA0(s32, s32, s32);

void func_L39_005D72E8(s32 a0, E_005D4D78 *e) {
    s32 i = e - D_L39_002FB000;
    if (D_L39_001D7EE8[i] != 0) {
        D_L39_001D7ED8[i] = a0;
        D_L39_001D7EF0[i] = e;
        func_L01_00516AA0(0x90000, 1, 1);
    }
}
/* localdecomp:end func_L39_005D72E8 */
