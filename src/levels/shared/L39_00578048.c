#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00578048);

INCLUDE_ASM("asm/levels", func_L39_00578118);

/* localdecomp:start func_L39_005782F0 */
__asm__(".extern D_001FC48C, 16");
__asm__(".extern D_L39_00240460, 16");
typedef struct { char pad[0x64C]; int base; int offset; int count; } S_5782F0;
extern S_5782F0 D_001F0A00;
extern char D_L39_00269500[];
extern int D_001FC48C[];
extern long D_L39_00240460;
extern int func_003A26F0(char *, int, int);
extern void func_L39_00578118(char *, long *, int, int);

/* from rac2-decomp's func_0026FE48 */
void func_L39_005782F0(void)
{
    long local[4];
    char *data = D_L39_00269500;
    func_003A26F0(data, D_001F0A00.offset + D_001F0A00.base, D_001F0A00.count);
    func_L39_00578118(data, local, D_001FC48C[0], 0x3FFC00);
    D_L39_00240460 = local[0];
}
/* localdecomp:end func_L39_005782F0 */
