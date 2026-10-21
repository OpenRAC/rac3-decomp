#include "common.h"

/* localdecomp:start func_L01_0051CC68 */
typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;

extern u8 D_L01_001E2458;
extern void *func_L01_00519D98(HT_8 *, u32);
s32 func_L01_0051CC68(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_L01_00519D98(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_L01_001E2458) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0051CC68 */
