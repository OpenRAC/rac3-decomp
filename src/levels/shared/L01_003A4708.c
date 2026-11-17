#include "common.h"

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

INCLUDE_ASM("asm/levels", func_L01_003A4740);

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
