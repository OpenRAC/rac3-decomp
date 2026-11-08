#include "common.h"

/* localdecomp:start func_L14_0035F9B0 */
extern void func_L01_004450F0(void *, int, int);

void func_L14_0035F9B0(char *arg0)
{
    char *p = *(char **)(arg0 + 0x24);
    *(unsigned short *)(arg0 + 0x34) &= 0xFFBE;
    *(unsigned short *)(arg0 + 0x34) |= *(unsigned short *)(p + 0x44) & 0x1000;
    *(int *)(arg0 + 0x98) = *(int *)(p + 0x10);
    func_L01_004450F0(arg0, 1, 5);
}
/* localdecomp:end func_L14_0035F9B0 */

/* localdecomp:start func_L14_0035FA00 */
void func_003C3A10(void *, s32, s32, s32);

void func_L14_0035FA00(void *arg0) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x2D0) = 2;
    if ((*(u8 *)((u8 *)arg0 + 0x43)) != 0) {
        func_003C3A10(arg0, 0, 0, 0);
    }
}
/* localdecomp:end func_L14_0035FA00 */
