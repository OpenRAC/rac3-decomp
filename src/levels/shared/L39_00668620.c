#include "common.h"

/* localdecomp:start func_L39_00668620 */
typedef struct { s32 id; u8 p4[0x2CC]; s32 w2D0; u8 p2D4[0x340 - 0x2D4]; } E_665D48;
extern s32 D_L39_002461F8;
extern E_665D48 D_L39_00337700[];
E_665D48 *func_L39_00668620(s32 a0) {
    s32 i;
    E_665D48 *p;
    for (i = 0; i < D_L39_002461F8; i++) {
        p = &D_L39_00337700[i];
        if (p->w2D0 == a0) return p;
    }
    return 0;
}
/* localdecomp:end func_L39_00668620 */
