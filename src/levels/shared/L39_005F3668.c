#include "common.h"

typedef struct {
    u8 pad0[0x1C];
    u8 *f1C;
    u8 pad20[0x38];
    s32 f58;
    u8 pad5C[0x24];
} E_005F2FF8;


/* localdecomp:start func_L39_005F3668 */
extern s32 D_L39_00242918;
extern s32 D_L39_0024BB68;
extern u8 *D_L39_0024BB6C;
extern u8 D_001FE020[];
extern s32 func_003A4FF8(u8 *, s32, s32, s32, s32);

s32 func_L39_005F3668(u32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 idx;
    s32 r;
    u8 *p;

    if (a == 0xFFFFFFFF) {
        return -1;
    }
    idx = a * 4 + b * 2 + c + D_L39_00242918;
    if (idx >= D_L39_0024BB68) {
        return -1;
    }
    r = func_003A4FF8(D_L39_0024BB6C + idx * 32, d, e, 0, f);
    if (r >= 0) {
        p = D_001FE020 + (r << 7);
        *(s32 *)(p + 220) = e;
        *(s16 *)(p + 202) = idx;
    }
    return r;
}
/* localdecomp:end func_L39_005F3668 */
