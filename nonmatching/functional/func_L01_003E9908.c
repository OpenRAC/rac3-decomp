/* functional: high. Camera spring length step: when follow-block halfword +0x10 is positive, pulls the spring vector (+0x180) toward the look-minus-base vector by the per-player gain D_001D5FE8[player] (func_0038CDF8), then clamps its length to [spring[0x2C] - steer[0x30], spring[0x2C]] and stores steer+0x30 = spring[0x2C] - length. Branches, constants and callee args checked against retail; only VU0 scheduling differs */
#include "vu0.h"
extern f32 D_L01_001D5FE8[];
void func_L01_003E9908(u8 *obj) {
    extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
    extern f32 func_0038CEA8(f32 *);
    extern void func_0038CF68(f32 *, f32 *, f32);
    vu0_v4 v;
    u8 *p = *(u8 **)(obj + 0x70);
    u8 *q = p + 0x210;
    f32 *s = (f32 *)(p + 0x180);
    f32 len;
    if (*(s16 *)(p + 0x10) > 0) {
        f32 gain = D_L01_001D5FE8[*(s32 *)(obj + 0x94)];
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(v) : "m"(*(vu0_v4 *)p), "m"(*(vu0_v4 *)(p + 0xB0)) : "vf1", "vf2");
        func_0038CDF8(s, s, (f32 *)&v, gain);
        len = func_0038CEA8(s);
        if (s[0x2C/4] < len) {
            len = s[0x2C/4];
            func_0038CF68(s, s, len);
        } else if (len < s[0x2C/4] - *(f32 *)(q + 0x30)) {
            len = s[0x2C/4] - *(f32 *)(q + 0x30);
            func_0038CF68(s, s, len);
        }
        *(f32 *)(q + 0x30) = s[0x2C/4] - len;
    }
}
