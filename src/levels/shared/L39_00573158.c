#include "common.h"

/* localdecomp:start func_L39_00573158 */
typedef struct {
    u8 pad0[0x460];
} Ent_00573158;

extern Ent_00573158 D_L39_0024DE80[];
extern s32 D_L39_00241128;
__asm__(".extern D_L39_00241128, 16");
extern s32 D_L39_0024BB44;

s32 func_L39_00573158(u8 *a, u8 *b) {
    u8 *ent = (u8 *)&D_L39_0024DE80[*(s32 *)(a + 0x94)];
    u8 *st = ent + 0x150;

    if (D_L39_00241128 == 0 && *(s32 *)(st + 0xFC) == 0x20 && *(s16 *)(b + 0x86) == 0) {
        if (D_L39_0024BB44 < 2) {
            *(s32 *)(ent + 0x458) = 1;
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00573158 */
