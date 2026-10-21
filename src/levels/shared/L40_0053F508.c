#include "common.h"

/* localdecomp:start func_L40_0053F508 */
typedef struct {
    s32 w0;
    u8 pad4[24];
    s32 w28;
    u8 pad32[17];
    u8 b49;
    u8 pad50[18];
} E_0053CC58;
extern E_0053CC58 D_L40_0033F2E0[];
extern void func_L39_0066C470(s32);
s32 func_L40_0053F508(s32 a0) {
    E_0053CC58 *e;
    s32 i;
    for (i = 0; i < 50; i++) {
        e = &D_L40_0033F2E0[i];
        if (e->b49 == 1 && e->w28 == a0) {
            e->b49 = 0;
            func_L39_0066C470(e->w0);
            return e->w0;
        }
    }
    return -1;
}
/* localdecomp:end func_L40_0053F508 */

INCLUDE_ASM("asm/levels", func_L40_0053F570);

INCLUDE_ASM("asm/levels", func_L40_0053F6E0);
