#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L30_00345A58 */
extern void func_L01_00443628(u8 *, u8 *, s32, f32 *, f32);
extern s32 func_003CF790(u8 *, s32, u8 *, u8 *, f32);
extern f32 D_L30_001DCF78;
extern s32 D_L30_001ED080_00345A58[];
extern u8 D_001A4BE0[];
__asm__(".extern D_L30_001DCF78, 4");

static __inline__ s32 CurWord(s32 off) {
    return *(s32 *)(D_001A4BE0 + off);
}

void func_L30_00345A58(u8 *a0) {
    f32 vec[4];
    u8 buf[0x30];
    s32 n;
    s32 i;

    qzero(vec);
    vec[2] = -1.0f;
    vec[3] = 1.0f;
    func_L01_00443628(buf, a0, 1, vec, 1.0f);
    *(s32 *)(buf + 0x20) |= 1;
    n = func_003CF790(a0 + 0x10, 0x10, a0, buf, D_L30_001DCF78);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            s32 w = D_L30_001ED080_00345A58[i];
            if (w == CurWord(0x25C0)) {
                *(s32 *)(a0 + 0x98) = 0;
                break;
            }
        }
        vec[2] += 1.0f;
    }
}
/* localdecomp:end func_L30_00345A58 */
