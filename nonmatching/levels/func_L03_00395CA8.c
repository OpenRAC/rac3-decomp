/* near miss (level 3, Starship Phoenix): 24 differences, one cause: needs @ps2as for the inline float constants (L03_00395808.c has none) and even then retail has two nops between cvt.s.w and div.s that the assembler does not emit; looks like an assembler-version effect, not reachable from C */
#include "common.h"

/* localdecomp:start func_L03_00395CA8 */
typedef struct S_00395CA8 {
    char pad[0x30];
    float f30;
    char pad2[0x8];
    int n;
} S_00395CA8;
typedef struct T_00395CA8 {
    char pad[0x68];
    S_00395CA8 *p;
} T_00395CA8;
extern void func_L03_00396190(void *, float);
extern void func_L03_00395D60(void *, float);
extern float func_0038DAB8(float, float);
void func_L03_00395CA8(T_00395CA8 *a) {
    S_00395CA8 *s = a->p;
    float f, step;
    int i;
    func_L03_00396190(a, 0.15f);
    step = 6.2831855f / (float)s->n;
    f = s->f30;
    for (i = 0; i < s->n; i++) {
        func_L03_00395D60(a, f);
        f = func_0038DAB8(f, step);
    }
}
/* localdecomp:end func_L03_00395CA8 */
