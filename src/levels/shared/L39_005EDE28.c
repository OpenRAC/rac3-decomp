#include "common.h"

/* localdecomp:start func_L39_005EDE28 */
__asm__(".extern D_L39_0024CAD0, 16");
__asm__(".extern D_L39_0024C910, 16");
__asm__(".extern D_002402F4, 16");
__asm__(".extern D_002402F0, 16");
__asm__(".extern D_L39_0024CAD0_b, 4");
extern char *D_L39_0024CAD0;
extern char *D_L39_0024CAD0_b;
extern char *D_L39_0024C910;
extern int D_002402F0;
extern int D_002402F4;
extern char D_L39_002B85A0[];
extern void func_001264E0(int);
extern void func_003DEF90(void);
extern void func_0038CD80(void *first, int second, int third);
extern void func_003DED18(void);

void func_L39_005EDE28(void)
{
    char *pointer = D_L39_0024CAD0;
    int other = D_002402F4;
    D_L39_0024C910 = pointer;
    pointer += 0x10;
    D_002402F0 = other;
    D_L39_0024CAD0_b = pointer;
    func_001264E0(0);
    func_003DEF90();
    func_0038CD80(D_L39_002B85A0, 0x3200, 0x40);
    func_003DED18();
}
/* localdecomp:end func_L39_005EDE28 */
