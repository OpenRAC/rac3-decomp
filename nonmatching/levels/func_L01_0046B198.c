/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_00467AE8, the NTSC-U twin of func_L01_0046B198, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_0046A938.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_0046B198 (src/levels/shared/L01_0046A938.c) */
#include "vu0.h"

/* localdecomp:start func_L01_00467AE8 */
extern void func_00388700(void *, void *, f32);
extern s32 func_003883C8(void *);
extern void func_003C7CE0(void *);

void func_L01_00467AE8(u8 *p) {
    vu0_v4 v;
    vu0_q qa;
    vu0_q qb;
    vu0_q qr;
    u32 x;
    f32 *q = (f32 *)(p + 0x20);

    func_00388700(&v, q, 0.95f);
    q[2] += 0.00138888892f;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(p + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(p + 0x20)));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(p + 0x10)) : "j"(qr));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(qr));
    x = *(u32 *)(p + 4) + 0xFE000000;
    *(u32 *)(p + 4) = x;
    if ((x & 0xFF000000) - 1 > 0x5EFFFFFF || func_003883C8(p + 0xA) != 0) {
        func_003C7CE0(p);
    } else {
        f32 f = *(f32 *)(p + 0xC);
        p[8]++;
        *(f32 *)(p + 0xC) = f + (210000.0f - f) * 0.07f;
    }
}
/* localdecomp:end func_L01_00467AE8 */
