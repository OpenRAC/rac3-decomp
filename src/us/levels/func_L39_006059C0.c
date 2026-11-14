#include "common.h"

/* localdecomp:start func_L39_006059C0 */
typedef struct {
    s32 f0;
    s32 f4;
    u8 p8[0x28];
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3C;
    s32 f40;
    s32 f44;
    s32 f48;
    s32 f4C;
    s32 f50;
    u8 p54[4];
    s32 f58;
    s32 f5C;
} Obj_L39_006059C0;

extern s32 func_00194DB8(s32, s32, s32, s32, s32, s32);

s32 func_L39_006059C0(Obj_L39_006059C0 *o, s32 a1, s32 a2, s32 mode) {
    s32 z = 0;
    o->f34 = a1;
    o->f40 = a2;
    o->f0 = 0;
    o->f4 = mode;
    o->f30 = 0;
    o->f38 = 0;
    o->f3C = 0;
    o->f44 = 0;
    o->f50 = 0;
    o->f58 = 0;
    o->f5C = 0;
    if (mode == 2) {
        o->f4C = 0x6000;
    } else if (mode == 3) {
        o->f4C = 0x400;
    } else {
        o->f4C = 0xC000;
    }
    o->f48 = func_00194DB8(o->f4C, 0x1000, 0x400, 0, 2, o->f4);
    return o->f48 >= z;
}
/* localdecomp:end func_L39_006059C0 */
