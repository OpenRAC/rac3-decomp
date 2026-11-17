#include "common.h"

/* localdecomp:start func_L39_0061E118 */
typedef struct S_0061E118 {
    u32 key;
    struct S_0061E118 *next;
} S_0061E118;

extern s32 D_L39_00245FD0[8] __attribute__((section(".sdata")));
extern s32 D_L39_0024CEE0[8] __attribute__((section(".sdata")));
extern S_0061E118 *D_L39_0024CEA0_0061E118[8] __attribute__((section(".sdata")));

S_0061E118 *func_L39_0061E118(u32 a)
{
    s32 i = (a >> 24) & 0xF;
    S_0061E118 *p = (S_0061E118 *)(D_L39_0024CEE0[i] + (a & 0xFFF) * D_L39_00245FD0[i]);
    if (p->key == a) return p;
    for (p = D_L39_0024CEA0_0061E118[i]; p != 0; p = p->next) {
        if (p->key == a) return p;
    }
    return 0;
}
/* localdecomp:end func_L39_0061E118 */

LINKER_REMNANT("asm/levels", func_L39_0061E1A0);
