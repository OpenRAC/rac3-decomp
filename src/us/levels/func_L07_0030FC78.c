#include "vu0.h"

/* NTSC-U counterpart of PAL func_L07_0030FFE8. */
/* localdecomp:start func_L07_0030FC78 */
extern u8 *func_003BCFB0(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_004A72A8(s32, s32, void *, s32);

extern void func_L07_0030FDF0(void *, void *);

u8 *func_L07_0030FC78(u8 *parent, vu0_q *pos, u8 b, f32 x) {
    vu0_v4 tmp;
    u8 *m;
    u8 *v;
    f32 *p;
    s32 i;

    *(vu0_q *)&tmp = *pos;
    m = func_003BCFB0(0xABE, 0x80);
    if (m != 0) {
        m[0x30] = 0x7F;
        *(s16 *)(m + 0x32) = 0x7F;
        m[0x31] = 1;
        *(long *)(m + 0x38) = *(long *)(parent + 0x38);
        v = *(u8 **)(m + 0x68);
        *(vu0_q *)(m + 0x10) = *(vu0_q *)&tmp;
        qzero(m + 0xF0);
        *(f32 *)(m + 0xF8) = x;
        *(f32 *)(m + 0x18) += 0.5f;
        *(f32 *)(v + 0x70) = 0.5f;
        *(u8 **)(m + 0xB8) = parent;
        v[0x7C] = b;
        *(s32 *)(v + 0x74) = 0;
        *(s32 *)(v + 0x78) = 0;
        p = (f32 *)v;
        for (i = 0; i < 28; i++) {
            p[i] = func_0037E250(-4.0f, 4.0f) * 0.4f / 120.0f;
            if (i == 0 || i == 27) {
                p[i] = 0.0f;
            }
        }
        func_L01_004A72A8(0x10, 4, m, 0x1A1F);
        func_L07_0030FDF0(m, v);
    }
    return m;
}
/* localdecomp:end func_L07_0030FC78 */
