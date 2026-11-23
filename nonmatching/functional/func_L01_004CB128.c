/* functional: high. 3 diff words only (a beqz kept raw in asm to avoid a pad); draft verified vs asm */
#include "common.h"
/* localdecomp:start func_L01_004CB128 */
#include "vu0.h"
s32 func_L01_004CB128(Vec4_004C4AD8 *out, u8 *moby, s32 joint) {
    extern void func_003C2F58(void *, s32, void *);
    extern u8 *func_00382348(void);
    extern void func_0038CE20(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
    u8 *state;
    if (moby != 0) {
        if (joint != 0) {
            func_003C2F58(moby, joint, out);
        } else {
            *(vu0_q *)out = *(vu0_q *)(moby + 16);
            state = func_00382348();
            if (state != 0) {
                func_0038CE20(out, (Vec4_004C4AD8 *)(moby + 224), *(f32 *)(state + 16));
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(*out) : "m"(*out), "m"(*(Vec4_004C4AD8 *)(moby + 16)) : "vf1", "vf2");
                if (*(s16 *)(moby + 170) == 0x1AB8) {
                    func_003C2F58(moby, 4, out);
                }
                if (*(s16 *)(moby + 170) == 0x1C08) {
                    func_003C2F58(moby, 5, out);
                }
            }
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_004CB128 */
