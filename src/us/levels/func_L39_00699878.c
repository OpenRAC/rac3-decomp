#include "common.h"

typedef struct Vtable_L39_00699878 Vtable_L39_00699878;
typedef struct Object_L39_00699878 Object_L39_00699878;
typedef struct Self_L39_00699878 Self_L39_00699878;

struct Vtable_L39_00699878 {
    u8 pad0[0x78];
    s32 (*mode)(void *);
    u8 pad7C[0x10];
    s32 (*count)(void *);
};
struct Object_L39_00699878 {
    u8 pad0[0x60];
    Vtable_L39_00699878 *vtable;
};
struct Self_L39_00699878 {
    u8 pad0[0x118];
    Object_L39_00699878 *object;
    u8 pad11C[0x2A8 - 0x11C];
    s32 current_mode;
    s32 count;
    u8 pad2B0[0x2B8 - 0x2B0];
    s32 flag;
    u8 pad2BC[0x2C4 - 0x2BC];
    s32 active;
    u8 pad2C8[0x2E8 - 0x2C8];
    u8 menu;
};

/* localdecomp:start func_L39_00699878 */
extern void func_0019AFD0(s32);

/* Reads a count from its object's vtable (adding 1 unless the mode result is 3), then sets the
 * menu, flag and active fields from that count and the current mode and calls func_0019AFD0 with
 * the count. */
void func_L39_00699878(Self_L39_00699878 *self) {
    Object_L39_00699878 *object;
    s32 value;
    s32 count;
    object = self->object;
    self->count = object->vtable->count(object);
    object = self->object;
    value = object->vtable->mode(object);
    if (value - 1 != 2) {
        self->count++;
    }
    count = self->count;
    if (count == 2) {
        self->menu = 0;
        value = self->current_mode == 3;
    } else {
        value = 1;
        self->menu = value;
    }
    do {
        self->flag = value;
    } while (0);
    if (self->count == 1) {
        self->active = 0;
    } else {
        self->active = 1;
    }
    func_0019AFD0(self->count);
}
/* localdecomp:end func_L39_00699878 */
