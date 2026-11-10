#include "common.h"

/* localdecomp:start func_L03_003B1198 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { char pad[0x10]; u128_t v; } S_003B1198;
typedef struct { char pad[0x68]; S_003B1198 *p; } T_003B1198;
void func_L03_003B1198(T_003B1198 *a, u128_t *b) {
    a->p->v = *b;
}
/* localdecomp:end func_L03_003B1198 */
