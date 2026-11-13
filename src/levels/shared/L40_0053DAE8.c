#include "common.h"

/* localdecomp:start func_L40_0053DAE8 */
typedef struct { s32 id; s32 b; s32 c; } S_0053DAE8;
extern S_0053DAE8 D_L40_003478D0_0053DAE8[];
extern u8 *func_L39_0066C1F0(s32);

s32 func_L40_0053DAE8(s32 id, s32 team) {
    s32 i;
    u8 *m;

    for (i = 0; i < 40; i++) {
        if (D_L40_003478D0_0053DAE8[i].id == 0) {
            break;
        }
    }
    if (i == 40) {
        return -1;
    }
    m = func_L39_0066C1F0(id);
    D_L40_003478D0_0053DAE8[i].c = (s32)m;
    if (m == 0) {
        return -1;
    }
    if (team == 0) {
        (*(u8 **)(m + 0x1C))[0xBE] |= 0x10;
        (*(u8 **)(*(u8 **)&D_L40_003478D0_0053DAE8[i].c + 0x1C))[0xBE] &= ~8;
    } else if (team == 1) {
        (*(u8 **)(m + 0x1C))[0xBE] |= 8;
        (*(u8 **)(*(u8 **)&D_L40_003478D0_0053DAE8[i].c + 0x1C))[0xBE] &= ~0x10;
    } else {
        (*(u8 **)(m + 0x1C))[0xBE] &= ~8;
        (*(u8 **)(*(u8 **)&D_L40_003478D0_0053DAE8[i].c + 0x1C))[0xBE] &= ~0x10;
    }
    D_L40_003478D0_0053DAE8[i].b = team;
    D_L40_003478D0_0053DAE8[i].id = id;
    return 1;
}
/* localdecomp:end func_L40_0053DAE8 */

/* localdecomp:start func_L40_0053DC18 */
typedef struct { s32 id; s32 b; s32 c; } S_0053B368;
extern S_0053B368 D_L40_003478D0[];

s32 func_L40_0053DC18(s32 id) {
    s32 i;
    for (i = 0; i < 40; i++) {
        if (D_L40_003478D0[i].id == id) {
            D_L40_003478D0[i].id = 0;
            return 1;
        }
    }
    return -1;
}
/* localdecomp:end func_L40_0053DC18 */
