#include "common.h"

typedef struct {
    u8 pad0[0x3EC];
    u8 *object;
    u8 pad3F0[4];
    s16 mode;
} Vars_L05_00354EB0;

typedef struct {
    u8 pad0[0x68];
    Vars_L05_00354EB0 *vars;
} Object_L05_00354EB0;

/* localdecomp:start func_L05_00354EB0 */
extern s32 func_L05_00354AF8(u8 *);
extern void func_L05_00359930(void *, s32, s32, s32);
extern void func_L05_0043A7B8(void *, s32, s32, s32);

/* Starts an animation: if func_L05_00354AF8 returns 0 it plays animation 5 or 6 on the moby
 * depending on vars mode, otherwise it plays animation 5 on the moby stored in vars. */
void func_L05_00354EB0(Object_L05_00354EB0 *object) {
    Vars_L05_00354EB0 *vars = object->vars;
    if (func_L05_00354AF8((u8 *)object) == 0) {
        if (vars->mode != 0) {
            func_L05_00359930(object, 5, 0, 10);
        } else {
            func_L05_00359930(object, 6, 0, 10);
        }
    } else {
        func_L05_0043A7B8(vars->object, 5, 0, 10);
    }
}
/* localdecomp:end func_L05_00354EB0 */
