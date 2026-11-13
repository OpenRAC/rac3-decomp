#include "common.h"

/* localdecomp:start func_L31_00347868 */
typedef int u128_t __attribute__((mode(TI)));

extern void func_003C2880(u8 *a0);
extern void func_L01_004AA7E8(u8 *a0, s32 a1);

s32 func_L31_00347868(u8 *moby, u8 *info) {
    s32 flags = *(s32 *)(info + 32);
    *(s32 *)(info + 32) = flags & ~4;
    if ((flags & 2) || (info[32] ^ 1) & 1) {
        func_003C2880(moby);
        return 1;
    }
    *(u128_t *)(moby + 16) = *(u128_t *)info;
    *(u16 *)(moby + 52) = (*(u16 *)(moby + 52) | 0x41) & 0xEFFF;
    *(s32 *)(moby + 152) = 0;
    func_L01_004AA7E8(moby, 1);
    return 0;
}
/* localdecomp:end func_L31_00347868 */

/* localdecomp:start func_L31_003478E8 */
#include "vu0.h"

extern void func_L31_00347938(void *, void *, s32, vu0_v4 *, f32, f32, f32, f32, f32, f32, f32, s32);

void func_L31_003478E8(void *a0, void *a1, s32 a2, s32 a3, f32 z, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g) {
    vu0_v4 v;

    qzero(&v);
    v.z = z;
    func_L31_00347938(a0, a1, a2, &v, b, c, d, e, f, g, b, 0);
}
/* localdecomp:end func_L31_003478E8 */
