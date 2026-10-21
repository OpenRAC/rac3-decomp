#include "common.h"

/* localdecomp:start func_L04_003FDF80 */
typedef struct {
    u8 pad[1120];
} Ent1120;
extern Ent1120 D_L04_001E2840[];

void func_L04_003FDF80(s32 i) {
    u8 *e = (u8 *)&D_L04_001E2840[i];
    (*(u8 **)(e + 80))[136] = 1;
}
/* localdecomp:end func_L04_003FDF80 */
