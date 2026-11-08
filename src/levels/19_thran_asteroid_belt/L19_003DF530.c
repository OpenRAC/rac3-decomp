#include "common.h"

/* localdecomp:start func_L19_003DF530 */
typedef struct {
    u8 pad0[0x156];
    s8 state;
} P_3DF530;

typedef struct {
    u8 pad0[0x70];
    P_3DF530 *params;
    u8 pad74[0x86 - 0x74];
    s16 busy;
} O_3DF530;

typedef struct {
    u8 pad0[0x50];
    O_3DF530 *object;
    u8 pad54[0x460 - 0x54];
} E_3DF530;

extern E_3DF530 D_L19_001E2100[];

/* from rac4-decomp's func_L00_0058E210 */
void func_L19_003DF530(s32 index) {
    E_3DF530 *entry = D_L19_001E2100 + index;
    O_3DF530 *object = entry->object;
    if (object->busy == 0) {
        object->params->state = 4;
    }
}
/* localdecomp:end func_L19_003DF530 */
