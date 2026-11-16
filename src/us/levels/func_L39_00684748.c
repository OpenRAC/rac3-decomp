#include "common.h"

typedef struct {
    u8 reserved[0xE8];
    void (*callback)(void *);
} State_L39_00684748;

typedef struct {
    u8 reserved0[0x60];
    State_L39_00684748 *state;
    u8 reserved64[0x210];
    s32 counter;
    u8 reserved278[0x14];
    s32 selection;
} Actor_L39_00684748;

extern void func_L39_00684320(Actor_L39_00684748 *);
extern void func_L39_00685798(s32, s32, s32);
extern void func_00195500(void);

/* localdecomp:start func_L39_00684748 */
/* Sets the actor's selection, then loops calling the current state's callback and func_00195500
 * until the actor's counter returns to its starting value, bracketed by func_L39_00685798 calls
 * with 21 and 20. */
void func_L39_00684748(Actor_L39_00684748 *actor, s32 selection) {
    s32 previous;
    previous = actor->counter;
    actor->selection = selection;
    func_L39_00684320(actor);
    func_L39_00685798(21, 0, 0);
    do {
        func_00195500();
        actor->state->callback(actor);
        func_L39_00684320(actor);
    } while (actor->counter != previous);
    func_L39_00685798(20, 0, 0);
}
/* localdecomp:end func_L39_00684748 */
