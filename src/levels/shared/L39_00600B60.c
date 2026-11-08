#include "common.h"

/* localdecomp:start func_L39_00600B60 */
extern void func_00118E98(char *, int, char *);
extern char D_L39_00245110[];
extern char D_L39_00245128[];

/* from rac2-decomp's func_003358A0 */
void func_L39_00600B60(void *unused, char *out, float factor) {
    if (out == 0)
        func_00118E98(D_L39_00245110, 61, D_L39_00245128);
    *(float *)(out + 0x0) = factor;
    *(float *)(out + 0x4) = factor * 0.5f;
    *(float *)(out + 0x8) = 1.0f - factor;
    *(float *)(out + 0xC) = (1.0f - factor) * 0.5f;
}
/* localdecomp:end func_L39_00600B60 */
