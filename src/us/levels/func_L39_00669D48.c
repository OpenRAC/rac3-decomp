#include "common.h"

/* localdecomp:start func_L39_00669D48 */
typedef struct {
    s32 kind;
    s32 id;
    s32 limit;
    s32 value;
} Command_L39_00669D48;

typedef struct {
    s32 reserved0;
    s32 reserved4;
    Command_L39_00669D48 command;
} State_L39_00669D48;

typedef struct {
    u8 reserved0[0x30];
    u8 active;
    u8 reserved31[11];
    s32 value3C;
    s32 value40;
} Entry_L39_00669D48;

extern Entry_L39_00669D48 *func_L39_006698E8(s32);
extern s32 D_001A5E58[];

void func_L39_00669D48(State_L39_00669D48 *state) {
    Entry_L39_00669D48 *entry;
    Command_L39_00669D48 *command;
    s32 value;
    command = &state->command;
    if (command->kind != 6) {
        return;
    }
    value = command->value;
    entry = func_L39_006698E8(command->id);
    if (entry == 0) {
        return;
    }
    if (entry->value40 < command->limit) {
        entry->value3C = value;
    } else {
        if (entry->value40 != command->limit) {
            return;
        }
        if (entry->value3C == value) {
            return;
        }
        if (entry->value3C < value) {
            return;
        }
        entry->value3C = value;
    }
    if (value == D_001A5E58[0]) {
        entry->active = 1;
    }
    entry->value40 = command->limit;
}
/* localdecomp:end func_L39_00669D48 */
