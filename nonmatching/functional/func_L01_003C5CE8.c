/* functional: high. VU0 vector add/sub and qzero kept as in the near-miss; only instruction scheduling differs from retail (14 words), behaviour identical, all callees/offsets/gp globals re-checked against PAL asm. */
#include "common.h"
/* localdecomp:start func_L01_003C5CE8 */
#include "vu0.h"
__asm__(".extern D_001DECF0_sda, 4");
extern f32 D_001DECF0_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DECEC_sda, 4");
extern f32 D_001DECEC_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DECF4_sda, 4");
extern f32 D_001DECF4_sda __attribute__((section(".sdata")));
extern vu0_v4 D_L01_001E2A40;
extern char *D_L01_001E0100;
typedef struct { u8 pad[0x30]; vu0_v4 pos; u8 tail[0x40]; } Node_003C5CE8;
void func_L01_003C5CE8(u8 *m, u8 *v) {
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    extern void func_L01_003EB3C0(s32, void *);
    extern void func_L01_003EB350(s32, void *);
    vu0_v4 a, b, rot;
    vu0_v4 origin;
    s32 index;
    func_0038CE20(&a, m + 0xC0, D_001DECEC_sda + D_001DECF0_sda * *(f32 *)(v + 0xC8));
    a.z += D_001DECF4_sda;
    __asm__(
        "lqc2 $vf2, %4\n\t"
        "lqc2 $vf1, %3\n\t"
        "sqc2 $vf1, %2\n\t"
        "lqc2 $vf1, %0\n\t"
        "vadd.xyz $vf1, $vf1, $vf2\n\t"
        "sqc2 $vf1, %0\n\t"
        "lqc2 $vf2, %0\n\t"
        "lqc2 $vf1, %2\n\t"
        "vsub.xyz $vf2, $vf2, $vf1\n\t"
        "sqc2 $vf2, %1"
        : "+m"(a), "=m"(b), "=m"(origin)
        : "m"(D_L01_001E2A40), "m"(*(vu0_v4 *)(m + 0x10))
        : "vf1", "vf2");
    qzero(&rot);
    rot.y = -func_0038D160(func_0038CED8(&b), b.z);
    rot.z = func_0038D160(b.x, b.y);
    func_L01_003EB3C0(0, &rot);
    if ((u32)(m[0x20] - 11) < 2) index = *(s32 *)(v + 0x104);
    else index = *(s32 *)(v + 0x6BC);
    {
        char *base = D_L01_001E0100;
        s32 entry = *(s32 *)((s32)v + (index << 2) + 0x760);
        Node_003C5CE8 *p = (Node_003C5CE8 *)(base + (entry << 7));
        func_L01_003EB350(0, &p->pos);
    }
}
/* localdecomp:end func_L01_003C5CE8 */
