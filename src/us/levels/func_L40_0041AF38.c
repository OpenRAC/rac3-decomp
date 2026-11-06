#include "common.h"

/* localdecomp:start func_L40_0041AF38 */
extern void *func_L39_0066B3C0(void *, s32, s32, s32);
extern void func_L39_006601C8(void *, s32 *, s32);
extern s32 D_001A5F78[];

void func_L40_0041AF38(void *object, s32 type) {
    s32 values[2];
    void *message;
    if (type == -1) {
        message = func_L39_0066B3C0(object, 1, 0, 250);
    } else {
        message = func_L39_0066B3C0(object, 1, 0, -1);
    }
    values[0] = type;
    func_L39_006601C8(message, &values[0], 4);
    values[1] = D_001A5F78[0];
    func_L39_006601C8(message, &values[1], 4);
}
/* localdecomp:end func_L40_0041AF38 */
