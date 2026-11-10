#include "common.h"

/* localdecomp:start func_L03_003B19B8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { char pad[0x100]; u128_t v; int pad2[5]; int f; } S_003B19B8;
void func_L03_003B19B8(void *a, void *b) {
    S_003B19B8 *s = *(S_003B19B8 **)((char *)a + 0x68);
    if (b == 0) {
        s->f = 0;
    } else {
        s->f = 1;
        s->v = *(u128_t *)((char *)b + 0x10);
    }
}
/* localdecomp:end func_L03_003B19B8 */
