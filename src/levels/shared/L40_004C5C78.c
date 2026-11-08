#include "common.h"

/* localdecomp:start func_L40_004C5C78 */
extern s32 D_L40_00248068;
__asm__(".extern D_L40_00248068, 16");
extern s32 D_L40_0024806C;
__asm__(".extern D_L40_0024806C, 16");
extern s32 D_L40_00242918;
__asm__(".extern D_L40_00242918, 16");
extern char D_001FE020[];
extern s32 func_L39_005F3138(void *a, s32 b, s32 c, s32 d, s32 e);

s32 func_L40_004C5C78(s32 index, s32 a1, s32 a2, s32 a3) {
    s32 r;
    char *p;
    if (D_L40_0024806C == 0) {
        return -1;
    }
    index = index + D_L40_00242918;
    if (index >= D_L40_00248068) {
        return -1;
    }
    r = func_L39_005F3138((char *)D_L40_0024806C + index * 32, a1, a2, 0, 0x400);
    if (r >= 0) {
        p = D_001FE020 + r * 128;
        *(s32 *)(p + 0xDC) = a2;
        *(s16 *)(p + 0xCA) = index;
        *(s32 *)(p + 0x114) = a3;
    }
    return r;
}
/* localdecomp:end func_L40_004C5C78 */
