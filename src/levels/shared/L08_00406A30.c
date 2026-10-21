#include "common.h"

/* localdecomp:start func_L08_00406A30 */
typedef struct { u8 p0[0xAA]; s16 hAA; u8 pad[0x100 - 0xAC]; } M_403828;
extern M_403828 *D_L08_001DF21C;
extern M_403828 *D_L08_001DF224;

M_403828 *func_L08_00406A30(s32 id) {
    M_403828 *p;
    for (p = D_L08_001DF21C; p < D_L08_001DF224; p++) {
        if (p->hAA == id) return p;
    }
    return 0;
}
/* localdecomp:end func_L08_00406A30 */
