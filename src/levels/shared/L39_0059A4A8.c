#include "common.h"

typedef struct {
    u8 pad0[0x60];
    s32 active;
    u8 flag64;
    u8 pad65[3];
    s32 mode68;
    u8 flag6C;
} Object_005991D8;

/* localdecomp:start func_L39_0059A4A8 */

extern s32 D_L39_00241128[];
extern void func_00392A80(Object_005991D8 *, s32 *, s32 *);
extern s32 func_L39_005BF798(s32, s32, s32, s32, u8 *);
extern void func_L01_0047C518_0059A4A8(s32 *);

s32 func_L39_0059A4A8(Object_005991D8 *object) {
    s32 result;
    s32 values[2];
    s32 mode;

    if (object->active == 0) {
        goto inactive;
    }
    object->flag64 = 0;
    object->flag6C = 1;
    values[0] = 0;
    result = 0;
    values[1] = 0;
    func_00392A80(object, &values[0], &values[1]);

    mode = 1;
    if ((u32)(D_L39_00241128[0] - 1) < 2) {
        mode = 2;
    }
    object->mode68 = mode;

    if (values[1] == 0) {
        result = func_L39_005BF798(1, mode, 0, values[0], 0);
    } else if (values[1] == 1) {
        result = func_L39_005BF798(2, mode, values[0], 0, 0);
    }
    if (result < 0) {
        func_L01_0047C518_0059A4A8((s32 *)object);
    }
    return result == 0;
inactive:
    return 0;
}
/* localdecomp:end func_L39_0059A4A8 */
