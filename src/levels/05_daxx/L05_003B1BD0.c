#include "common.h"

/* localdecomp:start func_L05_003B1BD0 */
extern u16 *D_L05_0021DAE0[];
extern u8 *D_L05_001DFB9C;
__asm__(".extern D_L05_001DFB9C, 16");
extern s32 D_001DFBD8_sda;
__asm__(".extern D_001DFBD8_sda, 4");
extern s32 func_L01_00456250(u8 *);
extern f32 func_L01_0040E570(u8 *, void *);

u8 *func_L05_003B1BD0(u8 *a0, void *a1) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u16 *p = D_L05_0021DAE0[*(s32 *)(s + 0x2AC)];
    u8 *e;
    while ((*(s32 *)(s + 0x2AC) & 0xFF) != 0xFF
        && D_001DFBD8_sda >= *(s32 *)(s + 0x2AC)
        && p != 0
        && ((s16)p[-1] >= 0 || p == D_L05_0021DAE0[*(s32 *)(s + 0x2AC)])) {
        e = D_L05_001DFB9C + ((*p & 0x7FFF) << 8);
        if (e == 0) return 0;
        if (e[0x20] != 0xFE) {
            if (e[0x20] == 0xFD) {
                p++;
                continue;
            }
            if (func_L01_00456250(e) != 0) {
                p++;
                continue;
            }
            if (func_L01_0040E570(e + 0x10, a1) < 4.84f) {
                return e;
            }
        }
        p++;
    }
    return 0;
}
/* localdecomp:end func_L05_003B1BD0 */

INCLUDE_ASM("asm/levels", func_L05_003B1CF8);

/* localdecomp:start func_L05_003B1E80 */
s32 func_L05_003B1E80(s32 arg0, s32 arg1) {
    return (arg1 * 2) + arg0;
}
/* localdecomp:end func_L05_003B1E80 */

INCLUDE_ASM("asm/levels", func_L05_003B1E90);
