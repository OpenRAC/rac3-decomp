#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L23_003098F8 */
extern s32 D_001A71A0[];
extern s32 D_L23_001DC5F0;
extern s32 D_L23_001DC5F4;
extern void func_003A4F28(s32);
extern void func_003C2880(s32);
extern void func_L01_00424D88(s32);

void func_L23_003098F8(s32 a0)
{
    s32 g = D_001A71A0[0];
    s32 *slot = &D_L23_001DC5F4;
    char *object;

    if (a0 == g) {
        if (D_L23_001DC5F0 != -1) {
            func_003A4F28(D_L23_001DC5F0);
            D_L23_001DC5F0 = -1;
        }
    }
    object = (char *)*slot;
    if (object == 0)
        return;
    if (*(short *)(object + 0xAA) != 0x5F3) {
        *slot = 0;
        return;
    }
    if (*(unsigned char *)(object + 0x20) != 0)
        return;
    {
        char *inner = *(char **)(object + 0x68);
        s32 index;

        *(u8 *)0x001D6160 = 0;
        *(u8 *)0x001D6170 = 0;
        index = *(s16 *)(inner + 0x2C);
        if (index != -1)
            func_L01_00424D88(index);
    }
    func_003C2880(*slot);
    *slot = 0;
}
/* localdecomp:end func_L23_003098F8 */

/* localdecomp:start func_L23_003099A8 */
extern s32 D_001A71A0[];
extern s32 D_L23_001DC5F4;
extern s32 D_L23_001DC5F8;

s32 func_L23_003099A8(s32 arg0) {
    return *(((arg0 ^ D_001A71A0[0]) == 0) ? &D_L23_001DC5F4 : &D_L23_001DC5F8) != 0;
}
/* localdecomp:end func_L23_003099A8 */

INCLUDE_ASM("asm/levels", func_L23_003099D0);
