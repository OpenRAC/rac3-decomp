/* functional: high. bbit/branch scheduling only */
#include "common.h"
/* localdecomp:start func_L01_004C7D98 */
__asm__(".extern D_L01_001D6740, 4");
__asm__(".extern D_L01_001D673C, 4");
extern S_4C4A18 D_001A4BE0;
extern s32 D_L01_001D6740;
extern s32 D_L01_001D673C;
extern Vec4_004C4AD8 D_L01_001D6750_004C7D98;
void func_L01_004C7D98(Vec4_004C4AD8 *position, Vec4_004C4AD8 *out) {
    extern void func_0038CF68(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
    f32 sign;
    s32 mode;
    if (D_001A4BE0.x368 != 0) {
        mode = D_L01_001D6740;
        if (mode == 0) {
            *(u128_4C4A18 *)out = *(u128_4C4A18 *)(D_001A4BE0.x25C0 + 0xE0);
            return;
        }
    } else {
        mode = D_L01_001D6740;
    }
    if (mode != 0) {
        __asm__ __volatile__("lqc2 $vf2, %1\n\tlqc2 $vf1, D_L01_001D6750_004C7D98\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(*out) : "m"(*position) : "vf1", "vf2", "memory");
        out->z = 0.0f;
        func_0038CF68(out, out, 1.0f);
    } else if (D_L01_001D673C != 0) {
        sign = 1.0f;
        if (*(f32 *)((u8 *)&D_001A4BE0 + 0xBC) > 0.0f) sign = -1.0f;
        __asm__ __volatile__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(*out) : "m"(*position), "m"(*(Vec4_004C4AD8 *)((u8 *)&D_001A4BE0 + 0xB0)) : "vf1", "vf2");
        func_0038CF68(out, out, sign);
    } else {
        __asm__ __volatile__("vmr32.xyzw $vf1, $vf0\n\tsqc2 $vf1, %0" : "=m"(*out) : : "vf1");
    }
}
/* localdecomp:end func_L01_004C7D98 */
