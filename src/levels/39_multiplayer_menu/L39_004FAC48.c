#include "common.h"

/* declared by functions of L39_004F9B38.c, which this file was cut from */
void func_L39_0050A098(s32, s32, s32, s32);

/* localdecomp:start func_L39_004FAC48 */
void func_L39_0050A098(s32, s32, s32, s32);
void func_L39_004FAC48(s32 arg0, s32 arg1) {
    func_L39_0050A098(arg0, arg1, 4, 0);
}
/* localdecomp:end func_L39_004FAC48 */

/* localdecomp:start func_L39_004FAC68 */
extern int func_L39_0050A178(int, int, int, int, int);
extern void func_L39_004BC6C8(int, int, int, int, int);
int func_L39_004FAC68(int a0, int a1, int a2)
{
    if (func_L39_0050A178(a0, a1, a2, 4, 0) == 0) {
        func_L39_004BC6C8(0xD, 0x82, 4, 0, 0);
        return 0;
    }
}
/* localdecomp:end func_L39_004FAC68 */
