#include "common.h"

/* localdecomp:start func_L01_004DF000 */
extern u8 D_001A4BE0[];
extern void func_L01_0044B860(void *, void *, void *, f32, f32, f32);

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
