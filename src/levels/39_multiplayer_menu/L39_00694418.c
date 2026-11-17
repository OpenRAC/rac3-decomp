#include "common.h"

/* localdecomp:start func_L39_00694418 */
typedef struct { s32 f0; u8 pad[0x30]; u8 f34; } S_00694418b;
typedef struct { u8 pad[0x38]; S_00694418b *f38; } S_00694418a;
typedef struct { u8 pad[0x288]; s32 state; } S_00694418c;
extern S_00694418a *D_L39_0024D760_00694418;
extern S_00694418c *D_L39_00247914;
extern S_00694418c *D_001DC204_sda;
extern char D_L39_00247EE0[];
extern void *func_00381FF0(s32);
extern s32 func_L39_006872E8(S_00694418c *, void *, char *, s32, s32, f32);
s32 func_L39_00694418(void)
{
    S_00694418b *p = D_L39_0024D760_00694418->f38;
    if (p->f34 != 0) {
        D_001DC204_sda->state = 9;
        return 1;
    }
    if (p->f0 < 0) {
        S_00694418c *o = D_L39_00247914;
        func_L39_006872E8(o, func_00381FF0(0x1732), D_L39_00247EE0, 4, 0, 0.6f);
        D_L39_00247914->state = 0x19;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00694418 */

INCLUDE_ASM("asm/levels", func_L39_006944B0);
