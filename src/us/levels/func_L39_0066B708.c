#include "common.h"

/* localdecomp:start func_L39_0066B708 */
extern u8 D_001A5E50[];
extern u8 *func_L39_00619D10(s32);
extern s32 *func_L39_00665D48(s32);
extern s32 *func_L39_00669930(s32);
extern s32 func_L39_0066B7F8(s32, s32, s32, s32, s32, s32, s32, s32);

static __inline__ s32 PadWord(s32 off) {
    return *(s32 *)(D_001A5E50 + off);
}

s32 func_L39_0066B708(u8 *obj, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 key;
    u8 *p;
    s32 *q;

    if (PadWord(8) < 0 || PadWord(0x170) != 0) {
        return -1;
    }
    key = 0;
    p = func_L39_00619D10(a3);
    if (p != 0) {
        key = *(s32 *)(*(u8 **)(*(u8 **)(p + 0x2558) + 4) + 0x38);
    } else {
        q = func_L39_00665D48(a3);
        if (q != 0) {
            key = *q;
        } else {
            q = func_L39_00669930(a3);
            if (q != 0) {
                key = *q;
            }
        }
    }
    return func_L39_0066B7F8(*(s32 *)(*(u8 **)(*(u8 **)(obj + 0x2558) + 4) + 0x38), key, a1, 1, 0, 0, a2, a4);
}
/* localdecomp:end func_L39_0066B708 */
