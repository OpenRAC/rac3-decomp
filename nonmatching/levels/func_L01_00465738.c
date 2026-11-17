#include "common.h"
/* localdecomp:start func_L01_00465738 */
typedef int Q_00465738 __attribute__((mode(TI)));
extern u8 *D_L01_002210D4[];
u8 *func_L01_00465738(Q_00465738 *pos, Q_00465738 *vel, s32 color, s32 spin, s32 life, s32 growth, s32 texture, s32 render, f32 size, s32 w) {
    extern u8 *func_L01_004618E0(s32);
    extern u8 func_0013D3E0(void);
    u8 *p;
    u8 *v;
    if (life == 0) return 0;
    p = func_L01_004618E0(15);
    if (p != 0) {
        *(Q_00465738 *)(p + 0x10) = *pos;
        *(s32 *)(p + 4) = color;
        *(f32 *)(p + 0x1C) = w;
        p[9] = 0xA4;
        if (render != -1) p[3] = render;
        else p[3] = 0x48;
        p[1] = 0;
        *(f32 *)(p + 0xC) = size;
        p[8] = func_0013D3E0();
        if (texture == -1) p[2] = *D_L01_002210D4[0];
        else p[2] = texture;
        *(s16 *)(p + 0xA) = life;
        v = p + 0x20;
        *(s16 *)(v + 0x18) = life;
        *(f32 *)(v + 0x1C) = size;
        *(s32 *)(v + 0x10) = color;
        *(s32 *)(v + 0x14) = spin;
        *(s16 *)(v + 0x1A) = growth;
        *(Q_00465738 *)(p + 0x20) = *vel;
        *(f32 *)(v + 0xC) = 0.0058400002f;
    }
    return p;
}
/* localdecomp:end func_L01_00465738 */
