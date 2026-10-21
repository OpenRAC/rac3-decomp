#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0061C460);

/* localdecomp:start func_L39_0061C488 */
typedef s32 (*Fn_00619D10)(void *);
extern Fn_00619D10 *func_L39_005C1018(void);
s32 func_L39_0061C488(void *a0) {
    s32 r;
    if (a0) {
        r = func_L39_005C1018()[0](a0);
    } else {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_0061C488 */

/* localdecomp:start func_L39_0061C4D0 */
typedef struct { s32 w0; u8 pad[0x44C]; void *owner; } E_619D58;
typedef struct { u8 pad[0x90]; s32 w90; } M_619D58;
extern E_619D58 *D_L39_0024CE20[];
void func_L39_0061C4D0(M_619D58 *m, E_619D58 **out) {
    s32 i;
    for (i = 0; i < 8; i++) {
        E_619D58 *p = D_L39_0024CE20[i];
        if (p != 0 && p->owner == m) {
            *out = p;
            m->w90 = p->w0;
            return;
        }
    }
    *out = 0;
}
/* localdecomp:end func_L39_0061C4D0 */

INCLUDE_ASM("asm/levels", func_L39_0061C520);
