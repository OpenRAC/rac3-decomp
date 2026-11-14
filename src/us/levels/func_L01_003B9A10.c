#include "common.h"

typedef struct {
    u8 pad0[0x84];
    s16 mode;
    u8 pad86[0x9C - 0x86];
    s32 active;
} Vars_L01_003B9A10;

typedef struct {
    u8 pad0[0x68];
    Vars_L01_003B9A10 *vars;
    u8 pad6C[0x78 - 0x6C];
    s32 value;
    u8 pad7C[0xAA - 0x7C];
    s16 kind;
} Object_L01_003B9A10;

/* localdecomp:start func_L01_003B9A10 */
extern s32 func_L01_0040BAC0(void *);
extern s32 func_L01_0040D020(s32, s32, f32);

/* Updates a class 0x9B0 object: when its timer helper fires it resets the timer to 0x32 and flips
 * an active flag, and fades its color value toward a bright or dim gray. */
void func_L01_003B9A10(Object_L01_003B9A10 *object) {
    Vars_L01_003B9A10 *vars = object->vars;
    if (object->kind != 0x9B0) {
        return;
    }
    if (func_L01_0040BAC0(&vars->mode) != 0) {
        vars->mode = 0x32;
        vars->active = vars->active == 0;
    }
    object->value = func_L01_0040D020(object->value,
                                       vars->active != 0 ? 0x50787878 : 0x50141414, 0.15f);
}
/* localdecomp:end func_L01_003B9A10 */
