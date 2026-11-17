#include "common.h"

/* localdecomp:start func_L24_0035A470 */
typedef int Q_0035A470 __attribute__((mode(TI)));
extern f32 D_L24_001DD5C8;
__asm__(".extern D_L24_001DD5C8, 4");
extern f32 func_0038CF38(void *, void *);
extern f32 func_L24_0035AA18(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

s32 func_L24_0035A470(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));

    if (*(s16 *)(p + 0x144) != 1) return 0;
    if (*(u8 **)(p + 0x140) == 0) return 0;
    if (*(s32 *)(p + 0x180) != -1) {
        f32 d = func_0038CF38(p + 0x130, a0 + 0x10);
        if (func_L24_0035AA18(a0) < d) return 0;
    }
    *(Q_0035A470 *)a = *(Q_0035A470 *)(a0 + 0x10);
    a[2] += D_L24_001DD5C8;
    *(Q_0035A470 *)b = *(Q_0035A470 *)(*(u8 **)(p + 0x140) + 0x10);
    b[2] += 0.4f;
    return func_003D3CB0(a, b, 2, 0, 0) == 0;
}
/* localdecomp:end func_L24_0035A470 */
