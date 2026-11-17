#include "common.h"

/* localdecomp:start func_L39_005E74C8 */
extern s32 D_001D84F0_sda;
__asm__(".extern D_001D84F0_sda, 4");
extern f32 D_001D84EC_sda;
__asm__(".extern D_001D84EC_sda, 4");
extern f32 D_001D84E8_sda;
__asm__(".extern D_001D84E8_sda, 4");
extern s32 D_L39_0024B9C8;

void func_L39_005E74C8(void) {
    if (D_001D84F0_sda != D_L39_0024B9C8) {
        D_001D84E8_sda += D_001D84EC_sda * 0.05f;
        D_001D84EC_sda = (D_001D84E8_sda > 1.0f || D_001D84E8_sda < 0.0f) ? -D_001D84EC_sda : D_001D84EC_sda;
        D_001D84E8_sda = D_001D84E8_sda > 1.0f ? 1.0f : D_001D84E8_sda;
        D_001D84E8_sda = D_001D84E8_sda < 0.0f ? 0.0f : D_001D84E8_sda;
        D_001D84F0_sda = D_L39_0024B9C8;
    }
}
/* localdecomp:end func_L39_005E74C8 */

LINKER_REMNANT("asm/levels", func_L39_005E7588);

INCLUDE_ASM("asm/levels", func_L39_005E7598);
