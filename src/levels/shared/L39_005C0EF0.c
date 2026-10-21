#include "common.h"

/* localdecomp:start func_L39_005C0EF0 */
typedef struct { s32 id; s32 a; s32 b; } E_5BEF30;
extern E_5BEF30 D_L39_004B2500[];
s32 func_L39_005C0EF0(s32 a0) {
    s32 i;
    for (i = 0; D_L39_004B2500[i].id != -1; i++) {
        if (D_L39_004B2500[i].id == a0) return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_005C0EF0 */
