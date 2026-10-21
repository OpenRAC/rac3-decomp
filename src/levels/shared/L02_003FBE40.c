#include "common.h"

/* localdecomp:start func_L02_003FBE40 */
extern void func_0038DA10(char *, char *);
extern void func_0038D810(char *, void *);
void func_L02_003FBE40(char *a, void *b)
{
    char buf[48];
    func_0038DA10(*(char **)(a + 88) + 16, buf);
    func_0038D810(buf, b);
}
/* localdecomp:end func_L02_003FBE40 */
