#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { char prefix[0x10]; u128_t q; char rest[0xE0]; } Rec11_100;
typedef struct { char prefix[0x30]; u128_t q; char rest[0x40]; } Rec11_80;
typedef struct { int a; int b; } Choice11;

/* localdecomp:start func_L11_00348EA0 */
extern Rec11_100 *D_L11_001DEE1C;
extern Rec11_80 *D_L11_001DEF00;
__asm__(".extern D_L11_001DEF00, 16");
void func_L11_00348EA0(u8 *obj, u128_t *dst) {
    Choice11 *c = *(Choice11 **)(obj + 0x68);
    int i = c->b;
    if (i == -1)
        *dst = D_L11_001DEF00[c->a].q;
    else
        *dst = D_L11_001DEE1C[i].q;
}
/* localdecomp:end func_L11_00348EA0 */
