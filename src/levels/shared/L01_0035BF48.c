#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_38C110v;

typedef struct {
    s32 a[12];
} S_0035E418;

INCLUDE_ASM("asm/levels", func_L01_0035BF48);

INCLUDE_ASM("asm/levels", func_L01_0035C098);

/* localdecomp:start func_L01_0035C6B0 */
extern void func_L01_004C8668(int);
extern void func_003C2880(void *);
void func_L01_0035C6B0(char *m)
{
    char *v = *(char **)(m + 104);
    if (v != 0) {
        func_L01_004C8668(*(int *)(v + 44));
    }
    func_003C2880(m);
}
/* localdecomp:end func_L01_0035C6B0 */

INCLUDE_ASM("asm/levels", func_L01_0035C6F0);

INCLUDE_ASM("asm/levels", func_L01_0035C8D0);

INCLUDE_ASM("asm/levels", func_L01_0035CAD0);

INCLUDE_ASM("asm/levels", func_L01_0035CFC8);

INCLUDE_ASM("asm/levels", func_L01_0035D358);

INCLUDE_ASM("asm/levels", func_L01_0035D738);

INCLUDE_ASM("asm/levels", func_L01_0035DAF0);

INCLUDE_ASM("asm/levels", func_L01_0035DC18);

INCLUDE_ASM("asm/levels", func_L01_0035DEC8);

INCLUDE_ASM("asm/levels", func_L01_0035E010);
