#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L31_003A5888 */
extern s32 D_L31_001DF340;
extern void func_L30_0034CCD0(s32 a0, f32 *a1, f32 *a2, f32 *a3, f32 *t0);
s32 func_L31_003A5888(u8 *a0, f32 r) {
    f32 b[4];
    func_L30_0034CCD0(*(s32 *)(*(u8 **)(a0 + 104) + 436), &b[0], &b[1], &b[2], &b[3]);
    if (b[1] + r < *(f32 *)(a0 + 16) || *(f32 *)(a0 + 16) < b[0] - r
        || b[3] + r < *(f32 *)(a0 + 24) || *(f32 *)(a0 + 24) < b[2] - r) {
        if (D_L31_001DF340 >= 6) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L31_003A5888 */

/* localdecomp:start func_L31_003A5948 */
void func_L31_003A5948(void *arg0) {
    *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x1C4) = 0;
}
/* localdecomp:end func_L31_003A5948 */
