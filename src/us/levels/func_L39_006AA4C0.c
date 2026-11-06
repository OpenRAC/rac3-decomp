#include "common.h"

typedef struct {
    u8 reserved0[0x78];
    s32 (*check)(void *);
    u8 reserved7C[0x10];
    s32 (*get)(void *);
} Vtable_L39_006AA4C0;

typedef struct {
    u8 reserved[0x60];
    Vtable_L39_006AA4C0 *vtable;
} Interface_L39_006AA4C0;

typedef struct {
    u8 reserved0[0x114];
    Interface_L39_006AA4C0 *interface;
    u8 reserved118[0x190];
    s32 count;
    u8 reserved2AC[8];
    s32 status;
    u8 reserved2B8[0x2C];
    u8 active;
} Actor_L39_006AA4C0;

extern void func_0019AFD0(s32);

/* localdecomp:start func_L39_006AA4C0 */
void func_L39_006AA4C0(Actor_L39_006AA4C0 *actor) {
    Interface_L39_006AA4C0 *interface = actor->interface;
    s32 result;
    actor->count = interface->vtable->get(interface);
    interface = actor->interface;
    result = interface->vtable->check(interface);
    if (result - 1 != 2) {
        ++actor->count;
    }
    if (actor->count == 2) {
        actor->status = 0;
        actor->active = 0;
    } else {
        s32 active = 1;
        actor->active = (actor->status = active);
    }
    func_0019AFD0(actor->count);
}
/* localdecomp:end func_L39_006AA4C0 */
