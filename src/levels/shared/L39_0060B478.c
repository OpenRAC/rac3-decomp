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

/* localdecomp:start func_L39_0060B4C8 */
typedef struct {
    u16 a, count;
} State_0060B4C8;
extern State_0060B4C8 D_001FC340[];
extern s32 D_00241128, D_0024112C;
__asm__(".extern D_001DA108_sda, 4");
__asm__(".extern D_001DA10C_sda, 4");
__asm__(".extern D_001DA124_sda, 4");
extern s32 (*D_001DA108_sda)(s32);
extern void (*D_001DA10C_sda)(s32);
extern u32 D_001DA124_sda;
extern void func_003CD350(void);

s32 func_L39_0060B4C8(s32 value)
{
    s32 result;
    D_00241128 = 6;
    D_001FC340[8].count++;
    result = D_001DA108_sda(value);
    if (D_001DA124_sda & 16)
        func_003CD350();
    if (D_001DA10C_sda)
        D_001DA10C_sda(value);
    D_0024112C++;
    return result;
}
/* localdecomp:end func_L39_0060B4C8 */
