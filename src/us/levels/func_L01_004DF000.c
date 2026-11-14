#include "common.h"

/* localdecomp:start func_L01_004DF000 */
extern u8 D_001A4BE0[];
extern void func_L01_0044B860(void *, void *, void *, f32, f32, f32);

/* Does nothing unless the hero's mode is 0x81 or 0x50; then calls func_L01_0044B860 with the hero's
 * object and two of its fields and fixed constants. */
void func_L01_004DF000(void) {
    u8 *base = D_001A4BE0;
    s32 mode = *(s32 *)(base + 0x25C4);
    if (mode != 0x81 && mode != 0x50) {
        return;
    }
    func_L01_0044B860(*(void **)(base + 0x25C0), base + 0x738, base + 0x73C,
                       0.3f, 0.1163552925f, -1.0f);
}
/* localdecomp:end func_L01_004DF000 */
