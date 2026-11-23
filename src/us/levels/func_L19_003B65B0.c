#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L19_003B8260, with a 120-frame lifetime. */
/* localdecomp:start func_L19_003B65B0 */
extern char *func_003BCFB0(s32, s32);
extern s32 D_L19_001DF240;
__asm__(".extern D_L19_001DF240, 16");

char *func_L19_003B65B0(s32 a0, void *a1, void *a2, s32 a3, s32 t0, s32 t1) {
    char *n = func_003BCFB0(0x1AEA, 0x80);
    char *st;

    if (n != 0) {
        *(u8 *)(n + 0x20) = 0;
        *(u8 *)(n + 0x30) = 0xFF;
        st = *(char **)(n + 0x68);
        *(vu0_q *)(n + 0x10) = *(vu0_q *)a1;
        *(vu0_q *)st = *(vu0_q *)a1;
        *(vu0_q *)(st + 0x10) = *(vu0_q *)a2;
        *(s32 *)(st + 0x2C) = t1;
        *(s32 *)(st + 0x20) = a3;
        *(s32 *)(st + 0x24) = D_L19_001DF240 + 120;
        *(s32 *)(st + 0x28) = a0;
    }
    return n;
}
/* localdecomp:end func_L19_003B65B0 */
