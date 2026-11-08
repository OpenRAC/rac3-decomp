#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_004117D8);

/* localdecomp:start func_L03_00411BD0 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { float x, y, z, w; } V4_00411BD0;
extern void func_L03_004117D8(void *a, V4_00411BD0 *b);

void func_L03_00411BD0(void *a) {
    V4_00411BD0 v0, v1;
    *(u128_t *)&v0 = 0;
    *(u128_t *)&v1 = 0;
    v0.x = -2.0f;
    v0.y = 0.6f;
    v1.x = -2.0f;
    v1.y = -0.6f;
    func_L03_004117D8(a, &v0);
    func_L03_004117D8(a, &v1);
}
/* localdecomp:end func_L03_00411BD0 */
