#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006A04F8);

INCLUDE_ASM("asm/levels", func_L39_006A0540);

LINKER_REMNANT("asm/levels", func_L39_006A05F0);

INCLUDE_ASM("asm/levels", func_L39_006A05F8);

LINKER_REMNANT("asm/levels", func_L39_006A0948);

/* localdecomp:start func_L39_006A0950 */
extern int D_L39_0047D628[];
extern void func_L39_00688400(char *, int);
void func_L39_006A0950(char *a0, int a1)
{
    *(int *)(a0 + 0x60) = (int)D_L39_0047D628;
    *(int *)(a0 + 0x2B0) = -1;
    *(int *)(a0 + 0x2B4) = -1;
    *(int *)(a0 + 0x2B8) = -1;
    *(int *)(a0 + 0x2BC) = -1;
    *(int *)(a0 + 0x2C4) = -1;
    *(int *)(a0 + 0x2C8) = -1;
    *(int *)(a0 + 0x2C0) = -1;
    func_L39_00688400(a0, a1);
}
/* localdecomp:end func_L39_006A0950 */

INCLUDE_ASM("asm/levels", func_L39_006A0998);

INCLUDE_ASM("asm/levels", func_L39_006A0AC0);

/* localdecomp:start func_L39_006A0BC8 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006A0BC8(void *);

extern void func_L39_0067F168();
void func_L39_006A0BC8(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006A0BC8 */

INCLUDE_ASM("asm/levels", func_L39_006A0BF8);
