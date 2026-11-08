#include "common.h"

/* localdecomp:start func_L39_005F3760 */
extern unsigned char D_001FE020[];

int func_L39_005F3760(unsigned int arg0, int arg1) {
    unsigned char *p;
    if (arg0 < 0x34) {
        p = D_001FE020 + (arg0 << 7);
        *(short *)(p + 0xCC) = arg1;
    }
    return 1;
}
/* localdecomp:end func_L39_005F3760 */

/* localdecomp:start func_L39_005F3788 */
int func_L39_005F3788(unsigned int a0, int a1)
{
    char *p;
    if (a0 < 0x34) {
        p = D_001FE020 + a0 * 128;
        *(int *)(p + 0xD8) = a1;
    }
    return 1;
}
/* localdecomp:end func_L39_005F3788 */
