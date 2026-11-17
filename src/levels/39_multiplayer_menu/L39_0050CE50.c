#include "common.h"

/* localdecomp:start func_L39_0050CE50 */
typedef struct T_0050CE50 { s32 pos; } T_0050CE50;
void func_L39_0050CE50(T_0050CE50 *self, u32 *entries) {
    s32 depth = 0;
    self->pos = 0;
    for (;;) {
        s32 i = self->pos;
        u32 flags = entries[i * 5];
        u32 kind;
        self->pos = i + 1;
        kind = flags & 0xFFFF75FF;
        if (flags & 0x20) {
            if (kind - 0x30 < 2 || (flags & 0x1400) == 0x1000) depth++;
            else continue;
        } else if (kind == 0x103) {
            depth--;
        }
        if (depth <= 0) break;
    }
}
/* localdecomp:end func_L39_0050CE50 */
