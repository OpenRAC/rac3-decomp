/* near miss (level 3, Starship Phoenix): 29 differences, all from one instruction: retail has a bare `sq $zero` for the quadword zero store, gcc emits `por` + `sq` (known out of reach from plain C) and that shifts the rest; needs @ps2as for the inline float constants (L03_0039E470.c has none) */
#include "common.h"

/* localdecomp:start func_L03_003A1C60 */
typedef int u128_t __attribute__((mode(TI)));
extern float func_0038DAB8(float, float);
void func_L03_003A1C60(char *a, float *b, float *c) {
    *(u128_t *)c = 0;
    c[2] = func_0038DAB8(*(float *)(a + 0xF8), 3.1415927f);
    *(u128_t *)b = *(u128_t *)(a + 0x10);
    b[2] += 0.2f;
}
/* localdecomp:end func_L03_003A1C60 */
