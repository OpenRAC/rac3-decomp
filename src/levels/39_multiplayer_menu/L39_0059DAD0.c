#include "common.h"

/* localdecomp:start func_L39_0059DAD0 */
typedef struct { s32 a; u16 b; } S_0059DAD0;
extern S_0059DAD0 D_L39_00242B90 __attribute__((section(".data")));
extern void *D_L39_0024BD94;
extern void *D_001E0680_sda;
__asm__(".extern D_001E0680_sda, 4");
extern u8 D_L39_002411E0[];
extern void func_00193038(void *);
extern void func_L39_0059D978(void *, s32, void *);

void func_L39_0059DAD0(void)
{
    void *argv[4];
    u8 buf[0x20];
    u8 *name = D_L39_002411E0;

    D_L39_0024BD94 = buf;
    *(s32 *)buf = D_L39_00242B90.a;
    *(u16 *)(buf + 4) = D_L39_00242B90.b;
    D_001E0680_sda = argv;
    func_00193038(buf + 5);
    func_L39_0059D978(name, 2, &D_001E0680_sda);
}
/* localdecomp:end func_L39_0059DAD0 */
