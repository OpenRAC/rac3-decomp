#include "common.h"
#include "vu0.h"




/* localdecomp:start func_L01_00461E08 */
typedef int Q_004653B8 __attribute__((mode(TI)));
extern u8 *D_L01_0022114C_00461E08[];
u8 *func_L01_00461E08(Q_004653B8 *pos, s32 spin, s32 color, f32 jitter, f32 low, f32 high, f32 rate, f32 size) {
    extern u8 *func_L01_0045E438(s32);
    extern f32 func_L01_00440918(f32, f32);
    extern s32 func_L01_00440848(s32);
    extern f32 func_L01_004408C0(f32, f32);
    u8 *p = func_L01_0045E438(13);
    if (p != 0) {
        u8 *vars;
        *(Q_004653B8 *)(p + 0x10) = *pos;
        p[9] = 0x44;
        p[3] = 0x48;
        *(f32 *)(p + 0xC) = size;
        *(s32 *)(p + 4) = color;
        p[1] = 0;
        p[8] = 0;
        p[2] = *D_L01_0022114C_00461E08[0];
        vars = p + 0x20;
        *(f32 *)(p + 0x10) += func_L01_00440918(0.0f, jitter);
        *(f32 *)(p + 0x14) += func_L01_00440918(0.0f, jitter);
        *(f32 *)(p + 0x18) += func_L01_00440918(0.0f, jitter);
        *(s16 *)(p + 0xA) = 10;
        *(s32 *)(vars + 4) = 0;
        if (func_L01_00440848(2)) *(s32 *)(vars + 8) = spin;
        else *(s32 *)(vars + 8) = -spin;
        *(s32 *)(vars + 0x14) = color & 0xFFFFFF;
        *(f32 *)(vars + 0xC) = func_L01_004408C0(low, high);
        *(f32 *)(vars + 0x10) = rate;
    }
    return p;
}
/* localdecomp:end func_L01_00461E08 */
