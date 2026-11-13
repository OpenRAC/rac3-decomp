#include "common.h"

/* localdecomp:start func_L39_004E0F28 */
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern s32 func_L39_004E1060(s32 *);
extern s32 func_L39_004FC580(s32);
extern void func_L39_004FC228(s32);

typedef struct S_004E0F28 {
    s32 f0;
    s32 _p4[2];
    s32 *fC;
} S_004E0F28;

s32 func_L39_004E0F28(S_004E0F28 *arg0, S_004E0F28 *arg1) {
    s32 n;

    if (arg0->f0 != arg1->f0) {
        func_L39_004BC6C8(6, 0x68, 0x66, 0, 0);
        goto err;
    }
    if (func_L39_004E1060((s32 *)arg1) != 0) {
        func_L39_004BC6C8(6, 0x68, 0x73, 0, 0);
        goto err;
    }
    if (arg0->f0 == 0x74) {
        n = func_L39_004FC580(arg1->fC[3]);
        if (n == 0) {
            goto err;
        }
        if (arg0->fC[3] != 0) {
            func_L39_004FC228(arg0->fC[3]);
        }
        arg0->fC[3] = n;
        n = func_L39_004FC580(arg1->fC[4]);
        if (n == 0) {
            goto err;
        }
        if (arg0->fC[4] != 0) {
            func_L39_004FC228(arg0->fC[4]);
        }
        arg0->fC[4] = n;
        n = func_L39_004FC580(arg1->fC[5]);
        if (n == 0) {
            goto err;
        }
        if (arg0->fC[5] != 0) {
            func_L39_004FC228(arg0->fC[5]);
        }
        arg0->fC[5] = n;
    }
    return 1;
err:
    return 0;
}
/* localdecomp:end func_L39_004E0F28 */

INCLUDE_ASM("asm/levels", func_L39_004E1060);

INCLUDE_ASM("asm/levels", func_L39_004E10B0);

INCLUDE_ASM("asm/levels", func_L39_004E1138);
