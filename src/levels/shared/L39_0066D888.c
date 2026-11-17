#include "common.h"

/* localdecomp:start func_L39_0066D888 */
typedef struct {
    char pad0[0x44];
    union {
        u8 b;
        s32 w;
    } team;
    char pad48[0x50 - 0x48];
    u8 unk50;
} Obj;

extern s32 func_L39_0061CF78(s32);

s32 func_L39_0066D888(Obj *o, u8 b, u8 c) {
    s32 ret = 0;
    s32 same = 1;

    if (c != o->team.b) {
        same = 0;
        if (func_L39_0061CF78(c) != 0) {
            o->team.w = c;
            ret = 1;
        }
    }
    if (same) {
        if (o->unk50 < b) {
            ret = 1;
        } else if (o->unk50 >= 193 && b <= 63) {
            ret = 1;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_0066D888 */
