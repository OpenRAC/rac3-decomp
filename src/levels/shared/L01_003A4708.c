#include "common.h"
#include "vu0.h"

typedef void (*fn_3A2780)(u8 *);

/* localdecomp:start func_L01_003A4708 */
float func_L01_003A4708(void)
{
    return 0.7f;
}
/* localdecomp:end func_L01_003A4708 */

/* localdecomp:start func_L01_003A4720 */
extern void func_L01_003A3EC8_003A4720(u8 *a0, s32 a1);
extern void func_L01_003A4720(void *p);
extern void func_L01_003A4720(void *);

 
void func_L01_003A4720(void *p) {
    ((void (*)(void *, s32))func_L01_003A3EC8_003A4720)(p, 0);
}
/* localdecomp:end func_L01_003A4720 */

/* localdecomp:start func_L01_003A4740 */
typedef int s128 __attribute__((mode(TI)));
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);

void func_L01_003A4740(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *t;
    *(u8 *)(s + 0x5E) = 0;
    *(u8 *)(s + 0x60) = 0;
    *(u8 *)(s + 0x5F) = 0;
    qzero(a0 + 0xF0);
    t = *(u8 **)(a0 + 0x24);
    *(f32 *)(a0 + 0x2C) = *(f32 *)(t + 0x24);
    *(s128 *)(a0 + 0x10) = *(s128 *)(s + 0x380);
    *(f32 *)(a0 + 0xF8) = *(f32 *)(s + 0x420);
    *(u16 *)(a0 + 0x34) &= 0xFFBE;
    *(u16 *)(a0 + 0x34) |= *(u16 *)(t + 0x44) & 0x1000;
    *(s32 *)(a0 + 0x98) = *(s32 *)(t + 0x10);
    *(u16 *)(a0 + 0x34) &= 0xFFFD;
    func_L01_004450F0(a0, 7, 2);
    if (*(u8 *)(a0 + 0x43) != 8) {
        func_003C3A10(a0, 8, 0, 0);
    }
    if (*(s32 *)(s + 0x2EC) != -1) {
        func_L01_004450F0(a0, 9, -1);
    }
}
/* localdecomp:end func_L01_003A4740 */

INCLUDE_ASM("asm/levels", func_L01_003A4810);

/* localdecomp:start func_L01_003A4910 */
long func_L01_003A4910(u8 *s) {
    long r = 0;

    if (s[0x95] == 6) {
        int t = s[0x20] == 0x10;
        r = t;
    }
    return r;
}
/* localdecomp:end func_L01_003A4910 */
