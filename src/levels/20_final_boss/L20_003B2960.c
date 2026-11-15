#include "common.h"

/* localdecomp:start func_L20_003B2960 */
extern void func_003C2F58(s32 a, s32 b, void *c);
extern void func_003D9508(void *p, s32 a, u32 color, s32 b, f32 f0, f32 f1, f32 f2);

void func_L20_003B2960(u8 *arg0) {
    u8 *v = *(u8 **)(arg0 + 0x68);
    s32 buf[4];

    func_003C2F58(*(s32 *)(v + 0x2E0), 1, buf);
    func_003D9508(buf, 0xB, 0x6F0000FF, 1, 4.0f, 2.5f, 0.0f);
}
/* localdecomp:end func_L20_003B2960 */
