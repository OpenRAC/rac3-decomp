#include "common.h"

typedef struct {
    u8 pad[0x40];
    s32 timer;
    s32 phase;
} MenuTransition;

extern MenuTransition D_U_002CE040[];
extern s32 func_U_00388398(s32 *timer);
extern void func_U_003B8B10(f32);
extern s32 func_U_003B8A20(void);
extern void func_U_003B6488(void);

/* localdecomp:start func_U_003BB5C0 */
s32 func_U_003BB5C0(s32 advance) {
    MenuTransition *transition = D_U_002CE040;
    s32 finished = 0;

    switch (transition->phase) {
    case 0:
        if (func_U_00388398(&transition->timer) == 1) {
            transition->timer = 15;
            transition->phase = transition->phase + 1;
        }
        break;
    case 1:
        if (func_U_00388398(&transition->timer) == 1) {
            transition->timer = 90;
            transition->phase = transition->phase + 1;
        }
        func_U_003B8B10((f32)transition->timer / 15.0f);
        break;
    case 2:
        if (func_U_003B8A20()) {
            func_U_003B6488();
        }
        if (func_U_00388398(&transition->timer) == 1 && advance != 0) {
            transition->timer = 15;
            transition->phase = transition->phase + 1;
        }
        break;
    case 3:
        if (func_U_00388398(&transition->timer) == 1) {
            finished = 1;
        }
        func_U_003B8B10(1.0f - (f32)transition->timer / 15.0f);
        break;
    }
    return finished;
}
/* localdecomp:end func_U_003BB5C0 */
