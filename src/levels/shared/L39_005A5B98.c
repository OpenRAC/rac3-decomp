#include "common.h"

/* localdecomp:start func_L39_005A5B98 */
typedef struct G_005A5B98 {
    u8 pad0[0x24];
    s32 w24;
    u8 pad28[0x15C - 0x28];
    s32 w15C;
    u8 pad160[4];
    s32 w164;
    u8 pad168[4];
    s32 w16C;
} G_005A5B98;

extern G_005A5B98 D_001A43E0;
extern s32 D_L39_002403FC;
extern s32 D_L39_002403F8;
__asm__(".extern D_001D7998_sda, 4");
extern void (*D_001D7998_sda)(void);

void func_L39_005A5B98(void) {
    s32 v = D_L39_002403FC & ~2;

    D_L39_002403FC = v;
    if (D_001A43E0.w15C == 2) {
        if (D_001A43E0.w164 < 0) {
            if (D_001A43E0.w16C != 0 || D_001A43E0.w24 != 0) {
                D_L39_002403FC = v | 0x40;
                D_L39_002403F8 = 0x18;
            } else {
                D_L39_002403F8 = 1;
            }
            if (D_001D7998_sda != 0) {
                D_001D7998_sda();
                D_001D7998_sda = 0;
            }
        }
    }
}
/* localdecomp:end func_L39_005A5B98 */
