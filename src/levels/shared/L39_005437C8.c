#include "common.h"

/* localdecomp:start func_L39_005437C8 */
extern s32 D_L39_0024AEA0;
extern void func_L39_00545498(u8 *a);
extern void func_L39_00545028(u8 *a);
extern void func_L39_0066AA50(int a, u8 *b, int c, void *d);

void func_L39_005437C8(u8 *a0)
{
    int v = *(int *)(*(u8 **)(a0 + 104) + 900);
    func_L39_00545498(a0);
    func_L39_00545028(a0);
    func_L39_0066AA50(v, a0, 6, &D_L39_0024AEA0);
}
/* localdecomp:end func_L39_005437C8 */
