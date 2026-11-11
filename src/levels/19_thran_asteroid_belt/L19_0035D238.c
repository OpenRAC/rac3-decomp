#include "common.h"

typedef struct { u8 pad[0x23]; u8 x23; } E_35D238;
typedef struct { u8 pad[0x25C0]; E_35D238 *x25C0; } G_35D238;

/* localdecomp:start func_L19_0035D238 */
extern G_35D238 D_001A4BE0;

void func_L19_0035D238(s32 a) {
    s32 i;

    D_001A4BE0.x25C0->x23 += a;
    for (i = 0; i < 0x230; i += 0x50) {
        E_35D238 **p = (E_35D238 **)((u8 *)&D_001A4BE0 + i);

        if (p[0x480])
            p[0x480]->x23 += a;
        if (p[0x481])
            p[0x481]->x23 += a;
        if (p[0x482])
            p[0x482]->x23 += a;
    }
}
/* localdecomp:end func_L19_0035D238 */

INCLUDE_ASM("asm/levels", func_L19_0035D2B8);

INCLUDE_ASM("asm/levels", func_L19_0035D7D0);
