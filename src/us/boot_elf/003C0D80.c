#include "common.h"

typedef struct {
    u8 pad[0x40];
    s32 timer;
    s32 phase;
} MenuTransition;

extern MenuTransition D_U_002D2040[];
extern s32 func_U_0038CDF8(s32 *timer);
extern void func_U_003BE2D0(f32);
extern s32 func_U_003BE1E0(void);
extern void func_U_003BBC48(void);

/* localdecomp:start func_U_003C0D80 */
s32 func_U_003C0D80(s32 advance) {
    MenuTransition *transition = D_U_002D2040;
    s32 finished = 0;

    switch (transition->phase) {
    case 0:
        if (func_U_0038CDF8(&transition->timer) == 1) {
            transition->timer = 15;
            transition->phase = transition->phase + 1;
        }
        break;
    case 1:
        if (func_U_0038CDF8(&transition->timer) == 1) {
            transition->timer = 90;
            transition->phase = transition->phase + 1;
        }
        func_U_003BE2D0((f32)transition->timer / 15.0f);
        break;
    case 2:
        if (func_U_003BE1E0()) {
            func_U_003BBC48();
        }
        if (func_U_0038CDF8(&transition->timer) == 1 && advance != 0) {
            transition->timer = 15;
            transition->phase = transition->phase + 1;
        }
        break;
    case 3:
        if (func_U_0038CDF8(&transition->timer) == 1) {
            finished = 1;
        }
        func_U_003BE2D0(1.0f - (f32)transition->timer / 15.0f);
        break;
    }
    return finished;
}
/* localdecomp:end func_U_003C0D80 */
