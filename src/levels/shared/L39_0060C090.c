#include "common.h"

/* localdecomp:start func_L39_0060C090 */
__asm__(".extern D_L39_00243E90, 16");
extern u32 D_001A4B50[];
extern u32 D_L39_00243E90;
extern s32 func_L01_003F08C0(void);
extern s32 func_L01_003D9540(void);

s32 func_L39_0060C090(s32 a, s32 b, u32 c) {
    s32 any = -1;
    u32 w;
    if (a != any && func_L01_003F08C0() != a) {
        return 0;
    }
    if (b != any && func_L01_003D9540() != b) {
        return 0;
    }
    w = c >> 2;
    if (D_001A4B50[w] & (1 << (c & 0x1F))) {
        return 0;
    }
    D_L39_00243E90 = c;
    return 1;
}
/* localdecomp:end func_L39_0060C090 */
