#include "common.h"

/* localdecomp:start func_L01_00425978 */
extern s32 D_L01_001FD180[];
extern s32 D_L01_001EA9B8[];
extern s32 D_001D4B60;
extern u8 *D_001A5E80[];
extern u8 D_00142660[];
extern void func_00398808(s32);
extern void func_00398A88(s32);
extern void func_00399A08(s32, s32);

void func_L01_00425978(s32 a0)
{
    u8 *p;
    u8 *q;
    s32 v;

    func_00398808(a0);
    func_00398A88(a0);
    func_00399A08(D_L01_001FD180[0], D_L01_001EA9B8[0]);
    D_001D4B60 = a0;
    p = D_001A5E80[0];
    if (p != 0) {
        q = D_00142660;
        v = p[126] & 0x8F;
        p[126] = v;
        if ((u32)(*(s32 *)(q + 120) - 1) < 3) {
            p[126] = v | ((*(s32 *)(q + 120) << 4) | 0x80);
        }
    }
}
/* localdecomp:end func_L01_00425978 */

/* localdecomp:start func_L01_00425A08 */
extern void func_00399A08(s32, s32);
extern s32 D_L01_001FD180[];
typedef int s128_422C60 __attribute__((mode(TI)));

extern u8 D_L01_001FFB0A[];
extern s32 D_L01_00200670[];
extern s128_422C60 D_L01_00200DF0[];
extern s32 D_L01_001EA9B8[];
extern void func_0038CB78(void *, s32, s32);

void func_L01_00425A08(s32 restore) {
    u8 idx;

    if (restore) {
        idx = D_L01_001FFB0A[0];
        *(s32 *)((u8 * *)&D_L01_001FD180)[0] = *(s32 *)((u8 * *)&D_L01_001FD180)[idx];
        ((u8 * *)&D_L01_001FD180)[0][4] = ((u8 * *)&D_L01_001FD180)[idx][4];
        ((u8 * *)&D_L01_001FD180)[0][5] = ((u8 * *)&D_L01_001FD180)[idx][5];
        ((u8 * *)&D_L01_001FD180)[0][6] = ((u8 * *)&D_L01_001FD180)[idx][6];
        ((u8 * *)&D_L01_001FD180)[0][7] = ((u8 * *)&D_L01_001FD180)[idx][7];
        *(s32 *)(((u8 * *)&D_L01_001FD180)[0] + 32) = *(s32 *)(((u8 * *)&D_L01_001FD180)[idx] + 32);
        D_L01_00200670[0] = D_L01_00200670[idx];
        D_L01_00200DF0[0] = D_L01_00200DF0[idx];
    } else {
        ((void (*)(u8 *, s32))func_00399A08)(((u8 * *)&D_L01_001FD180)[0], D_L01_001EA9B8[0]);
        D_L01_00200670[0] = 0xFFFC0000;
        func_0038CB78(D_L01_00200DF0, -1, 16);
    }
    ((u8 * *)&D_L01_001FD180)[0][9] = ((u8 * *)&D_L01_001FD180)[0][8];
}
/* localdecomp:end func_L01_00425A08 */

INCLUDE_ASM("asm/levels", func_L01_00425B18);

INCLUDE_ASM("asm/levels", func_L01_00425CD0);

LINKER_REMNANT("asm/levels", func_L01_00425D40);
