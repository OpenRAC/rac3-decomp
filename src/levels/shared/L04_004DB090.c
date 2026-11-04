#include "common.h"

typedef struct {
    u8 pad[0xAA];
    s16 key;
} Obj_004DB090;
typedef struct {
    s32 entries[64];
    s32 count;
} Tab_004DB090;

/* localdecomp:start func_L04_004DB090 */
extern Tab_004DB090 D_L04_0024EB70;

void func_L04_004DB090(Obj_004DB090 *object)
{
    s32 found = 0;
    s32 i;

    for (i = 0; i < D_L04_0024EB70.count; i++) {
        if (D_L04_0024EB70.entries[i] == object->key) {
            found = 1;
            break;
        }
    }
    if (found == 0) {
        D_L04_0024EB70.entries[D_L04_0024EB70.count] = object->key;
        D_L04_0024EB70.count++;
    }
}
/* localdecomp:end func_L04_004DB090 */
