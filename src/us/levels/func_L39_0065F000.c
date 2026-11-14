#include "common.h"

/* localdecomp:start func_L39_0065F000 */
typedef struct {
    f32 first;
    f32 second;
    f32 third;
    u8 flagC;
    u8 flagD;
    u8 flagE;
} Payload_L39_0065F000;

typedef struct {
    u8 reserved0[4];
    s32 value4;
    u8 reserved8[0x128 - 8];
    s32 value128;
    u8 reserved12C[0x170 - 0x12C];
    s32 enabled170;
    u8 reserved174[0x7D4 - 0x174];
    u8 identifier7D4;
} Global_L39_0065F000;

extern Global_L39_0065F000 D_001A5E50;
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

/* Builds a 16-byte payload from the vector, flag bytes of the object and a mode, flags and index,
 * and, when D_001A5E50 offset 0x170 is zero, sends it with func_0014AD08. */
void func_L39_0065F000(u8 *object, f32 *vector, s32 mode, s8 index, s32 flags) {
    Payload_L39_0065F000 payload;
    u8 base_flag;
    payload.flagD = object[0x2544];
    payload.flagC = object[0x44ED];
    base_flag = object[0x44EE];
    payload.flagE = base_flag;
    if (mode != 0) {
        payload.flagE = base_flag | 0x40;
    }
    if (flags != 0) {
        payload.flagE |= 0x20;
    }
    payload.flagD |= (index + 1) << 4;
    payload.first = vector[0];
    payload.second = vector[1];
    payload.third = vector[2];
    if (D_001A5E50.enabled170 == 0) {
        func_0014AD08(D_001A5E50.identifier7D4 | 0x80, D_001A5E50.value4, -1,
                        *(s32 *)0x00240764, 0x10, &payload);
    }
}
/* localdecomp:end func_L39_0065F000 */
