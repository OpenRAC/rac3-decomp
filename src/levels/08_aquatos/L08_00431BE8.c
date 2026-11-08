#include "common.h"

/* localdecomp:start func_L08_00431BE8 */
extern void func_L03_0043BE98(int, void *, int, int, int);
void func_L08_00431BE8(int a, int *b, int c, int d)
{
    func_L03_0043BE98(a, b, c, d, b[0x12c / 4] != 0);
}
/* localdecomp:end func_L08_00431BE8 */
