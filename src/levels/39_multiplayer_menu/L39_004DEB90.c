#include "common.h"

typedef struct { int n; int *items; } L;

INCLUDE_ASM("asm/levels", func_L39_004DEB90);

INCLUDE_ASM("asm/levels", func_L39_004DEBB8);

INCLUDE_ASM("asm/levels", func_L39_004DEC08);

INCLUDE_ASM("asm/levels", func_L39_004DED48);

/* localdecomp:start func_L39_004DEE38 */
int func_L39_004DEE38(L **a, int idx) {
    L *l = *a;
    if (l == 0 || idx >= l->n) return 0;
    return l->items[idx];
}
/* localdecomp:end func_L39_004DEE38 */

INCLUDE_ASM("asm/levels", func_L39_004DEE70);

INCLUDE_ASM("asm/levels", func_L39_004DEF48);

INCLUDE_ASM("asm/levels", func_L39_004DF010);

INCLUDE_ASM("asm/levels", func_L39_004DF0E0);
