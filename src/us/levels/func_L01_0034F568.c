#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0034F568 */
extern void func_003BD9A0(void *, s32, void *);
extern u8 *func_L01_003AFF80(u8 *, void *, void *, s32, s32, s32, s32, f32, f32);

void func_L01_0034F568(u8 *a0) {
    f32 m[16] __attribute__((aligned(16)));
    f32 p[4] __attribute__((aligned(16)));
    f32 q[4] __attribute__((aligned(16)));
    func_003BD9A0(a0, 0, m);
    *(vu0_q *)p = *(vu0_q *)&m[12];
    *(vu0_q *)q = *(vu0_q *)&m[4];
    func_L01_003AFF80(a0, p, q, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, 0.0f, 0.65f);
}
/* localdecomp:end func_L01_0034F568 */
