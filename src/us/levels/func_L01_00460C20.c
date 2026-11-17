#include "common.h"

/* localdecomp:start func_L01_00460C20 */
typedef struct {
    s32 value;
    f32 rate;
} Timer_460C20;
typedef struct {
    u8 pad0[4];
    u32 word4;
    u8 pad8[4];
    f32 f0C;
    u8 pad10[0x10];
    Timer_460C20 timer;
} Obj_460C20;

extern s32 func_00388398(void *);
extern void func_003C7CE0(void *);

void func_L01_00460C20(Obj_460C20 *obj) {
    Timer_460C20 *t = &obj->timer;
    if (func_00388398(t) != 0) {
        func_003C7CE0(obj);
        return;
    }
    obj->f0C += t->rate;
    if (obj->timer.value < 6) {
        obj->word4 = (obj->word4 & 0xFFFFFF) | (((obj->timer.value * 127) / 6) << 24);
    }
}
/* localdecomp:end func_L01_00460C20 */
