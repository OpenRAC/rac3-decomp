#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0060A228);

INCLUDE_ASM("asm/levels", func_L39_0060A330);

/* localdecomp:start func_L39_0060A4C8 */
extern int func_L39_0060AA28(void *, int *);
extern int func_003B2A00(void);
extern int func_L01_004D5A50(void);
extern int func_L01_004D5A78(void);
extern int func_003B2A80(void *, void *);
extern void func_003B25E0(u8 *);
extern void func_00142728(void *);
extern void func_00143388(void *, int, void *, int);
extern void func_L39_006096D0(void *, int, int, int, int, int);

/* from rac2-decomp's func_00351720, renamed */
int func_L39_0060A4C8(char *object, int unused1, int unused2, int a, int b, int c, int d, int e)
{
    func_00142728(object);
    func_00143388(object, 0, func_L39_0060AA28, 0);
    func_00143388(object, 1, func_003B2A00, 0);
    func_00143388(object, 2, func_L01_004D5A50, 0);
    func_00143388(object, 3, func_L01_004D5A78, 0);
    func_00143388(object, 5, func_003B2A80, 0);
    func_003B25E0((u8 *)object);
    func_L39_006096D0(object + 0x48, a, b, c, d, e);
    return 1;
}
/* localdecomp:end func_L39_0060A4C8 */
