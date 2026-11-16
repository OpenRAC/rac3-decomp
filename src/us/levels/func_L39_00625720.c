#include "common.h"

/* localdecomp:start func_L39_00625720 */
typedef struct {
    f32 first;
    f32 second;
    f32 third;
    u8 flagC;
    u8 flagD;
    u8 flagE;
} Payload_L39_00625720;

extern u8 D_001A5E50[];
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

/* Sends a message with func_0014AD08 (type 16) carrying a 3-float vector, bytes from the object and
 * its inner block, and an enabled flag (0x40) unless the global block's flag at +0x170 is set. */
void func_L39_00625720(u8 *object, f32 *vector, s32 enabled) {
    Payload_L39_00625720 payload;
    u8 *inner;
    u8 *global;
    payload.flagD = object[0x2544];
    inner = *(u8 **)(object + 0x2558);
    payload.flagC = inner[0xC34];
    payload.flagE = inner[0xC31];
    if (enabled != 0) {
        payload.flagE |= 0x40;
    }
    global = D_001A5E50;
    payload.first = vector[0];
    payload.second = vector[1];
    payload.third = vector[2];
    if (*(s32 *)(global + 0x170) == 0) {
        s32 value = *(s32 *)(global + 4);
        u8 identifier = global[0x7D4];
        func_0014AD08(identifier | 0x80, value, -1, *(s32 *)0x00240764, 16, &payload);
    }
}
/* localdecomp:end func_L39_00625720 */
