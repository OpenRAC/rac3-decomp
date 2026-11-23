/* functional: high. Same behaviour as retail; only scheduling of one move differs. */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L07_003A5D80 */
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0045A748(u8 *, f32 *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_00448890(u8 *, u8 *, s32, f32, f32, f32, f32);
extern f32 func_0038CF38(u8 *, u8 *);
extern void func_L07_00333DB8(s32, f32, u8 *, u8 *, u8 *);

void func_L07_003A5D80(u8 *a0, u8 a1) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *rot;
    u8 *pos;
    f32 v[4];
    f32 k;
    f32 ang;

    k = -1.0f;
    if (a1 == 0) {
        k = 1.0f;
    }
    pos = a0 + 0x10;
    rot = a0 + 0xF8;
    func_0038CF68(v, a0 + 0xD0, k * 50.0f * 0.040000003f);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)v) : "m"(*(vu0_v4 *)pos), "m"(*(vu0_v4 *)v) : "vf1", "vf2");
    func_L01_0045A748(a0, v);
    ang = func_0038D160(*(f32 *)(s + 0x130) - *(f32 *)(a0 + 0x10), *(f32 *)(s + 0x134) - *(f32 *)(a0 + 0x14));
    func_L01_00448890(rot, s + 0x204, 0, ang, *(f32 *)(s + 0x164), *(f32 *)(s + 0x168), *(f32 *)(s + 0x16C));
    if ((*(u16 *)(a0 + 0x96) & 7) == 0) {
        if (a1 == 0) {
            func_L07_00333DB8(*(s32 *)(s + 0x270), func_0038CF38(pos, s + 0x130), a0, s + 0x4A0, 0);
        } else {
            func_L07_00333DB8(*(s32 *)(s + 0x270), func_0038CF38(pos, s + 0x130), a0, 0, s + 0x4A0);
        }
    }
    *(u16 *)(a0 + 0x96) += 1;
}
/* localdecomp:end func_L07_003A5D80 */
