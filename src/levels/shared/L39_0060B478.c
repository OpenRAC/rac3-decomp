#include "common.h"

/* declared by functions of L39_0060B428.c, which this file was cut from */
extern void func_L39_0060B478(void);

/* localdecomp:start func_L39_0060B478 */
extern void func_003A9440(s32, unsigned long);
extern void func_L39_0058B1B8(s32, s32, s32, s32);
__asm__(".extern D_001DA140_sda, 4");
extern f32 D_001DA140_sda;

void func_L39_0060B478(void)
{
    func_003A9440(0x42, 0x8000000044UL);
    func_L39_0058B1B8(0, 0, 0, (s32)(D_001DA140_sda * 128.0f));
}
/* localdecomp:end func_L39_0060B478 */

INCLUDE_ASM("asm/levels", func_L39_0060B4C8);
