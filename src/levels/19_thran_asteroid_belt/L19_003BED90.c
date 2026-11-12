#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 pad[0x1A50]; void *x1A50; } S_3BED90;

/* localdecomp:start func_L19_003BED90 */
extern S_3BED90 D_001A4BE0;
extern void func_L10_003B0940(void *);
extern void func_L10_003A7160(void *);

void func_L19_003BED90(u8 *a, u128_t *b, u128_t *c) {
    *(u128_t *)(a + 0x10) = *b;
    *(u128_t *)(a + 0xF0) = *c;
    func_L10_003B0940(a);
    if (D_001A4BE0.x1A50 != 0) {
        func_L10_003A7160(D_001A4BE0.x1A50);
        D_001A4BE0.x1A50 = 0;
    }
}
/* localdecomp:end func_L19_003BED90 */
