#include "common.h"

/* localdecomp:start func_L40_003D61D8 */
typedef struct { s32 id; s32 pad[5]; } Ent_003D6040;
extern Ent_003D6040 D_L40_003A0F60[];
Ent_003D6040 *func_L40_003D61D8(s32 id) {
    Ent_003D6040 *r = 0;
    s32 i;
    for (i = 0; D_L40_003A0F60[i].id != -1; i++) {
        if (D_L40_003A0F60[i].id == id) {
            r = &D_L40_003A0F60[i];
            break;
        }
    }
    return r;
}
/* localdecomp:end func_L40_003D61D8 */

INCLUDE_ASM("asm/levels", func_L40_003D6248);

INCLUDE_ASM("asm/levels", func_L40_003D65A8);
