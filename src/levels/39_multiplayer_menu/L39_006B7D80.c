#include "common.h"

/* localdecomp:start func_L39_006B7D80 */
__asm__(".extern D_001DDA64_sda, 4");
extern char *D_L39_00247914;
extern int D_001DDA64_sda;
extern void func_L39_0067CE08(void);
int func_L39_006B7D80(void)
{
    *(int *)(D_L39_00247914 + 0x284) = 0;
    func_L39_0067CE08();
    D_001DDA64_sda = 0;
    return 1;
}
/* localdecomp:end func_L39_006B7D80 */
