#include "common.h"

typedef struct {
    u8 pad0[0x68];
    u8 *vars;
} Object_L01_003CA118;

typedef struct {
    u8 pad0[0x491];
    u8 active;
    u8 pad492[0x550 - 0x492];
    u8 *child;
} Vars_L01_003CA118;

/* localdecomp:start func_L01_003CA118 */
extern void func_L01_00407180(u8 *, u8 *, u8 *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);

/* Starts the same two-colour effect on the moby and on its child, sets the active flag in its vars,
 * and switches the moby to state 3. */
void func_L01_003CA118(Object_L01_003CA118 *object) {
    Vars_L01_003CA118 *vars = (Vars_L01_003CA118 *)object->vars;
    func_L01_00407180((u8 *)object, (u8 *)object + 0x10, (u8 *)object + 0xF0,
                       1, 2, 3, 0x2D, 0x2D, 0xFF8040, 0x8F1010);
    func_L01_00407180(vars->child, vars->child + 0x10, vars->child + 0xF0,
                       1, 2, 3, 0x2D, 0x2D, 0xFF8040, 0x8F1010);
    vars->active = 1;
    func_L01_00441FB8(object, 3, -1);
}
/* localdecomp:end func_L01_003CA118 */
