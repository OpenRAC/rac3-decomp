#include "common.h"

typedef struct {
    u8 reserved[0x4D4];
    s16 state;
    u8 reserved4D6;
    u8 active;
} Child_L07_003C7270;

typedef struct {
    u8 reserved[0x68];
    Child_L07_003C7270 *child;
} Actor_L07_003C7270;

extern void func_L07_003B9748(Actor_L07_003C7270 *);
extern void func_L07_003C6D58(Actor_L07_003C7270 *, s32);
extern void func_L07_003C71A0(Actor_L07_003C7270 *);

/* localdecomp:start func_L07_003C7270 */
/* Calls func_L07_003B9748, sets the child data's state to 45, then calls func_L07_003C6D58(actor,
 * 22) if the child is active, else func_L07_003C71A0. */
void func_L07_003C7270(Actor_L07_003C7270 *actor) {
    Child_L07_003C7270 *child = actor->child;
    func_L07_003B9748(actor);
    child->state = 45;
    if (child->active != 0) {
        func_L07_003C6D58(actor, 22);
    } else {
        func_L07_003C71A0(actor);
    }
}
/* localdecomp:end func_L07_003C7270 */
