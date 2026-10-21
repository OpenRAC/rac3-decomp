#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_0042CE68);

INCLUDE_ASM("asm/levels", func_L01_0042D110);

/* localdecomp:start func_L01_0042D330 */
typedef struct {
    s32 id;
    u8 pad[16];
} E_42A520;

typedef struct {
    u8 pad[17808];
    E_42A520 e[48];
} T_160C40;

extern T_160C40 D_00160C40;
extern s16 D_0016C6A4[];
extern void func_0039A8B8(s32, s32, s32, s32);

void func_L01_0042D330(s32 a0, s32 a1) {
    s32 i;
    for (i = 0; i < 48; i++) {
        if (D_00160C40.e[i].id == a0) {
            break;
        }
    }
    if (i != 48) {
        D_0016C6A4[0] = i;
        func_0039A8B8(i, -1, a1, 1);
    }
}
/* localdecomp:end func_L01_0042D330 */

LINKER_REMNANT("asm/levels", func_L01_0042D3A0);

INCLUDE_ASM("asm/levels", func_L01_0042D3A8);

INCLUDE_ASM("asm/levels", func_L01_0042D798);
