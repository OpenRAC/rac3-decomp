#include "common.h"

/* localdecomp:start func_L39_005D3E98 */
extern u8 D_L39_00242B2E;
__asm__(".extern D_L39_00242B2E, 16");
extern s32 D_001D5C98_sda_005D3E98;
__asm__(".extern D_001D5C98_sda_005D3E98, 4");
extern s32 D_L39_00241528;
__asm__(".extern D_L39_00241528, 16");
extern s32 D_001A5990[];

/* When D_L39_00242B2E is 0, increments a frame counter and on every 50th tick sets D_L39_00241528
 * to the counter plus 10 if a flag byte is set. */
void func_L39_005D3E98(void) {
    s32 n;
    if (D_L39_00242B2E == 0) {
        n = D_001D5C98_sda_005D3E98;
        D_001D5C98_sda_005D3E98 = n + 1;
        if ((n + 1) % 50 == 0) {
            if (D_001A5990[0] != 0) {
                D_L39_00241528 = n + 11;
            }
        }
    }
}
/* localdecomp:end func_L39_005D3E98 */
