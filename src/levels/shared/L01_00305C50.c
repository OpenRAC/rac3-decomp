#include "common.h"

/* localdecomp:start func_L01_00305C50 */
void func_L01_00305C50(char *packet)
{
    *(long *)(packet + 112) = 0;
    *(float *)(packet + 8) = -1.0f;
    *(float *)(packet + 24) = 1.0f;
    *(float *)(packet + 40) = -1.0f;
    *(float *)(packet + 56) = 1.0f;
    *(float *)(packet + 4) = -1.0f;
    *(float *)(packet + 36) = 1.0f;
    *(float *)(packet + 52) = 1.0f;
    *(int *)(packet + 0) = 0;
    *(int *)(packet + 16) = 0;
    *(int *)(packet + 32) = 0;
    *(int *)(packet + 48) = 0;
    *(float *)(packet + 12) = 1.0f;
    *(float *)(packet + 28) = 1.0f;
    *(float *)(packet + 44) = 1.0f;
    *(long *)(packet + 128) = 0x0000FF9000000260L;
    *(float *)(packet + 20) = -1.0f;
    *(float *)(packet + 60) = 1.0f;
}
/* localdecomp:end func_L01_00305C50 */

/* localdecomp:start func_L01_00305CB8 */
/* Ported from rac2-decomp rac2-decomp/src/levels/shared/L00_0041ABB8.c:180-200. */

void func_L01_00305CB8(char *packet)
{
    *(long *)(packet + 112) = 0L;
    *(int *)(packet + 8) = 0;
    *(float *)(packet + 24) = 2.0f;
    *(int *)(packet + 40) = 0;
    *(float *)(packet + 4) = -1.0f;
    *(float *)(packet + 36) = 1.0f;
    *(float *)(packet + 52) = 1.0f;
    *(int *)(packet + 0) = 0;
    *(int *)(packet + 16) = 0;
    *(int *)(packet + 32) = 0;
    *(int *)(packet + 48) = 0;
    *(float *)(packet + 12) = 1.0f;
    *(float *)(packet + 28) = 1.0f;
    *(float *)(packet + 44) = 1.0f;
    *(long *)(packet + 128) = 0x0000FF9000000260L;
    *(float *)(packet + 56) = 2.0f;
    *(float *)(packet + 20) = -1.0f;
    *(float *)(packet + 60) = 1.0f;
}

/* localdecomp:end func_L01_00305CB8 */

LINKER_REMNANT("asm/levels", func_L01_00305D28);
