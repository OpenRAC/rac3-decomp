#include "common.h"

/* localdecomp:start func_L39_0066C788 */
typedef struct { u8 v[1]; } B_0066C788;
extern B_0066C788 D_L39_002462A8;
extern B_0066C788 D_L39_002462A9;
extern B_0066C788 D_L39_002462AA;
__asm__(".extern D_L39_002462A9, 16");
__asm__(".extern D_L39_002462AA, 16");

u32 func_L39_0066C788(s32 i) {
    s32 o = i * 3;
    return 0x80000000 | (D_L39_002462AA.v[o] << 16) | (D_L39_002462A9.v[o] << 8) | D_L39_002462A8.v[o];
}
/* localdecomp:end func_L39_0066C788 */
