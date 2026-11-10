#include "common.h"

/* localdecomp:start func_L39_00695B28 */
extern void *D_0024D760[];
extern void *D_001E2050_sda;
s32 func_L39_006D6E50(void *, s32, s32, void *);
void func_L39_006D6E30(void *, s32, void *);
void func_L39_0067F168(void);
void func_L39_0068ADC8(void *);
void func_L39_00695B28(void *object)
{
    u8 buf[0x190];
    u8 *g;
    u8 *s;

    g = (u8 *)D_0024D760[0];
    if (func_L39_006D6E50(*(void **)(g + 0x44), *(s32 *)*(void **)(g + 0x30), 0, buf)) {
        s = (u8 *)D_001E2050_sda;
        *(s32 *)(buf + 0x30) = *(s32 *)*(void **)(s + 0x38);
        func_L39_006D6E30(*(void **)(s + 0x44), 0, buf);
    }
    func_L39_0067F168();
    func_L39_0068ADC8(object);
}
/* localdecomp:end func_L39_00695B28 */

INCLUDE_ASM("asm/levels", func_L39_00695BA0);
