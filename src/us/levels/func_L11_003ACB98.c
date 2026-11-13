#include "common.h"

/* NTSC-U counterpart of func_L11_003AE938 (src/levels/11_obani_moons/L11_003AE1B0.c) */
#include "vu0.h"

/* localdecomp:start func_L11_003ACB98 */
typedef int q_3AE938 __attribute__((mode(TI)));
__asm__(".extern D_L11_001DE168, 4");
__asm__(".extern D_L11_001DE16C, 4");
__asm__(".extern D_L11_001DE170, 4");
__asm__(".extern D_L11_001DE174, 4");
__asm__(".extern D_L11_001DE178, 4");
__asm__(".extern D_L11_001DE17C, 4");
__asm__(".extern D_L11_001DE180, 4");
extern s32 D_L11_001DE168;
extern s32 D_L11_001DE16C;
extern f32 D_L11_001DE170;
extern f32 D_L11_001DE174;
extern f32 D_L11_001DE178;
extern f32 D_L11_001DE17C;
extern f32 D_L11_001DE180;
extern void func_003886E8(void *, void *, f32);
extern void func_003D41E0(void *, s32, s32, f32, s32, s32);

void func_L11_003ACB98(u8 *a0)
{
    q_3AE938 m[4];
    q_3AE938 p;
    u8 *v;
    f32 t;

    p = *(q_3AE938 *)(a0 + 0x10);
    m[0] = *(q_3AE938 *)(a0 + 0xC0);
    m[1] = *(q_3AE938 *)(a0 + 0xD0);
    m[2] = *(q_3AE938 *)(a0 + 0xE0);
    m[3] = p;
    v = *(u8 **)(a0 + 0x68);
    func_003886E8(&m[0], &m[0], D_L11_001DE170);
    func_003886E8(&m[1], &m[1], D_L11_001DE174);
    func_003886E8(&m[2], &m[2], D_L11_001DE178);
    t = D_L11_001DE17C + D_L11_001DE180;
    D_L11_001DE17C = t;
    if (1.0f < t) {
        D_L11_001DE17C = t - 1.0f;
    }
    func_003D41E0(m, D_L11_001DE168, (*(s32 *)(v + 0xC) << 24) | 0x20AF20, D_L11_001DE17C, D_L11_001DE16C, 1);
}
/* localdecomp:end func_L11_003ACB98 */
