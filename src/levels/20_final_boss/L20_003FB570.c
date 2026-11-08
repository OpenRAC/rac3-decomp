#include "common.h"

/* localdecomp:start func_L20_003FB570 */
extern void func_L01_0045A9F0(void);
extern void func_L01_0045D218(char *, char *);

void func_L20_003FB570(char *arg0)
{
    if (*(short *)(*(char **)(arg0 + 0x68) + 0x3DA) == 0) {
        func_L01_0045A9F0();
    } else {
        func_L01_0045D218(arg0, arg0 + 0x10);
    }
}
/* localdecomp:end func_L20_003FB570 */
