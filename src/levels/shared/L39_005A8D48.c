#include "common.h"

/* localdecomp:start func_L39_005A8D48 */
extern s32 D_L01_001D67C8;
typedef struct { s32 a; s32 b; } GePair_L39;
typedef struct { u8 pad[0x24DE0]; GePair_L39 e[3]; } GeBig_L39;
s32 func_L39_005A8D48(s32 a, s32 b, u32 i) {
    GeBig_L39 *p = (GeBig_L39 *)D_L01_001D67C8;
    if (p != 0 && i < 3) {
        p->e[i].a = a;
        p->e[i].b = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_005A8D48 */

/* localdecomp:start func_L39_005A8D90 */
extern s32 D_L01_001D67C8;
__asm__(".extern D_L01_001D67C8, 4");

typedef struct { s32 a; s32 b; } P8_L39;
typedef struct { u8 pad[0x24DE0]; P8_L39 arr[3]; } Big_L39;

void func_L39_005A8D90(u32 i) {
    if (i < 3) {
        Big_L39 *b = (Big_L39 *)D_L01_001D67C8;
        b->arr[i].a = 0;
        b->arr[i].b = 0;
    }
}
/* localdecomp:end func_L39_005A8D90 */
