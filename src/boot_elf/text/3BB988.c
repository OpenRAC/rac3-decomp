#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003BB988();
/* --- end of declarations from other files --- */

/* declarations of 3BB948.c's earlier functions */
extern f32 D_001D8C2C;

extern f32 D_001D8C30;
extern f32 D_001D8C2C;
/* localdecomp:start func_003BB988 */
__asm__(".extern D_001D8C30, 4");
__asm__(".extern D_001D8C2C, 4");
extern f32 D_001D8C30;
extern f32 D_001D8C2C;
void func_003BB988(void) {
    f32 x, a;
    D_001D8C2C += D_001D8C30 * 0.05f;
    a = D_001D8C30;
    if (D_001D8C2C > 1.0f || D_001D8C2C < 0.0f) a = -a;
    D_001D8C30 = a;
    x = (D_001D8C2C > 1.0f) ? 1.0f : D_001D8C2C;
    D_001D8C2C = x;
    {
        f32 z = 0.0f;
        if (!(x < z)) z = x;
        D_001D8C2C = z;
    }
}
/* localdecomp:end func_003BB988 */
