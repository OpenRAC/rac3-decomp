#include "common.h"

typedef struct {
    u8 pad0[0x394];
    s32 state;
    u8 pad398[0x3F4 - 0x398];
    s16 mode;
} Vars_L20_003F93A0;

typedef struct {
    u8 pad0[0x68];
    Vars_L20_003F93A0 *vars;
} Object_L20_003F93A0;

/* localdecomp:start func_L20_003F93A0 */
extern s32 func_L20_003F9120(void *);
extern void func_L20_003FCB98(void *, s32, s32, s32);

/* Does nothing when func_L20_003F9120 returns non-zero, else starts func_L20_003FCB98 with 5, 4 or
 * 6 depending on the moby's mode and state. */
void func_L20_003F93A0(Object_L20_003F93A0 *object) {
    Vars_L20_003F93A0 *vars = object->vars;
    if (func_L20_003F9120(object) != 0) {
        return;
    }
    if (vars->mode != 0) {
        if (vars->state != 0) {
            func_L20_003FCB98(object, 5, 0, 10);
        } else {
            func_L20_003FCB98(object, 4, 0, 10);
        }
    } else {
        func_L20_003FCB98(object, 6, 0, 10);
    }
}
/* localdecomp:end func_L20_003F93A0 */
