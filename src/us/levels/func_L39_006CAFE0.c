#include "common.h"

typedef struct {
    u8 enabled;
    u8 pad1[7];
    u8 active;
    u8 pad9[3];
    s32 value;
} State_L39_006CAFE0;

/* localdecomp:start func_L39_006CAFE0 */
extern u16 D_L39_00249D00[];
extern u8 D_00197830[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_0017F8C8(u16 *, u8 *, s32);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);

s32 func_L39_006CAFE0(u8 *object) {
    State_L39_006CAFE0 *state = (State_L39_006CAFE0 *)object;
    s32 result = 1;
    u16 buffer[16];

    if (state->enabled != 0) {
        buffer[0] = D_L39_00249D00[0];
        state->active = 1;
        state->value = (s32)func_00130760(func_0012DCB0(), 0x24000);
        func_001962D8(func_0017F8C8(buffer, D_00197830, 0));
        if (func_001962E8() != 0) {
            state->active = 0;
            result = 0;
        }
    }
    return result;
}
/* localdecomp:end func_L39_006CAFE0 */
