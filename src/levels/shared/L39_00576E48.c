#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00576E48);

/* localdecomp:start func_L39_00577148 */
extern s32 D_L39_00242A00[];
extern u8 *D_L39_0024CE20[];
extern void func_L01_00461818(void);
extern void func_L39_005C3E30(s32);
extern void func_L39_005FBF18(void);
extern void func_L39_00578048(void);

void func_L39_00577148(void)
{
    s32 i;
    u8 *p;

    if (D_L39_00242A00[0] != 0) {
        func_L01_00461818();
    } else {
        for (i = 0; i < 8; i++) {
            p = D_L39_0024CE20[i];
            if (p != 0 && *(s32 *)(p + 9524) != 0) {
                func_L39_005C3E30(*(s32 *)(p + 9524));
            }
        }
    }
    func_L39_005FBF18();
    func_L39_00578048();
}
/* localdecomp:end func_L39_00577148 */

INCLUDE_ASM("asm/levels", func_L39_005771D0);
