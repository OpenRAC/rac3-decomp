#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3BB530.c's earlier functions */
extern void func_003BB5D0();
extern f32 D_001D8C2C;

extern f32 D_001D8C30;
extern f32 D_001D8C2C;
/* localdecomp:start func_003BB5D0 */
__asm__(".extern D_001D8C30, 4");
__asm__(".extern D_001D8C2C, 4");
void func_003BB5D0(void) {
    f32 speed;
    D_001D8C2C += D_001D8C30 * 0.05f;
    speed = D_001D8C30;
    if (D_001D8C2C > 1.0f || D_001D8C2C < 0.0f) {
        speed = -speed;
    }
    D_001D8C30 = speed;
    D_001D8C2C = (D_001D8C2C > 1.0f) ? 1.0f : D_001D8C2C;
    D_001D8C2C = (D_001D8C2C < 0.0f) ? 0.0f : D_001D8C2C;
}
/* localdecomp:end func_003BB5D0 */
