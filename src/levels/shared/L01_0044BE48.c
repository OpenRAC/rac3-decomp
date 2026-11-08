#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_0044BE48);

/* localdecomp:start func_L01_0044BE50 */
__asm__(".extern D_L01_001E001C, 16");
extern int D_L01_001E001C;

/* from rac4-decomp's func_00477A98 */
void func_L01_0044BE50(void *p, short *a, short n)
{
    short k = ((int)p - D_L01_001E001C) >> 8;
    int i;
    for (i = 1; i <= a[0]; i++)
        if (a[i] == k)
            return;
    if (a[0] < n) {
        a[0]++;
        a[a[0]] = k;
    }
}
/* localdecomp:end func_L01_0044BE50 */

/* localdecomp:start func_L01_0044BEC8 */
extern int D_L01_001E001C __attribute__((section(".sdata")));
extern int D_L01_001E001C __attribute__((section(".data")));

/* from rac2-decomp's func_002ACAD0, renamed */
void func_L01_0044BEC8(int param_1, unsigned short *param_2)
{
    int i;
    for (i = 1; i <= (short)param_2[0]; i++) {
        if (D_L01_001E001C + ((short)param_2[i] << 8) == param_1) {
            param_2[i] = param_2[(short)param_2[0]];
            param_2[0] = param_2[0] - 1;
            return;
        }
    }
}
/* localdecomp:end func_L01_0044BEC8 */

LINKER_REMNANT("asm/levels", func_L01_0044BF40);
