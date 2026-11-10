/* near miss (level 3, Starship Phoenix): 4 differences: retail keeps a loop copy `move $a3,$a1` that the C drops (srav reads $a1) and puts cnt-n in $v1 where the C uses $v0; do-while/for loops, separate locals, helper-style expressions all give 4 or more */
#include "common.h"

/* localdecomp:start func_L03_003B0238 */
extern int D_001DE858_sda;
__asm__(".extern D_001DE858_sda, 4");

int func_L03_003B0238(void) {
    int m = D_001DE858_sda;
    int x = m;
    int cnt = 0;
    int i = 0;
    int a, b, n, d;
    do {
        cnt += (x >> i) & 1;
        i++;
    } while (i < 6);
    a = m & 1;
    b = m & 2;
    n = a + (b != 0);
    if (n == 0) {
        return 0;
    }
    d = cnt - n;
    return d >= 2;
}
/* localdecomp:end func_L03_003B0238 */
