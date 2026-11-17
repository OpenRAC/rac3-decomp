#include "common.h"

extern s32 fe_func_0038CB00(u8 *);
extern void fe_func_003CD250(u8 *);
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    s128 v;
    s32 w16;
    s32 w20;
    s16 h24;
    s16 h26;
    f32 f28;
} Sub_00462578;
extern s32 fe_func_00382468(s32);
/* localdecomp:start func_L01_004629D8 */
extern s32 func_003883C8(u8 *);
extern void func_003C7CE0(u8 *);

/* Per-frame update of a fading particle: steps its fade value, frees it with particle_free when the
 * fade runs out or timer_tick_short expires, else flips the fade direction at 0.22, moves it up and
 * sets its alpha, frame and size. */
void func_L01_004629D8(u8 *o)
{
    f32 *p = (f32 *)(o + 32);
    f32 f;
    f32 y;

    f = p[1] + p[3] * 0.0130000003f;
    p[1] = f;
    if (f <= 0.0f || func_003883C8(o + 10) != 0) {
        func_003C7CE0(o);
    } else {
        f = p[1];
        if (0.22f <= f) {
            y = p[3];
            y = -y;
            p[3] = y;
            p[1] = f + y * 0.0130000003f;
        }
        *(f32 *)(o + 12) = *(f32 *)(o + 12) + 8190.0f;
        *(u32 *)(o + 4) = (*(u32 *)(o + 4) & 0xFFFFFFu) | ((s32)(p[1] * 255.0f) << 24);
        p[2] = p[2] + 0.0120000001f;
        if (p[2] > 1.0f)
            p[2] = p[2] - 1.0f;
        *(u8 *)(o + 8) = (u8)(p[2] * 255.0f);
        *(f32 *)(o + 24) = *(f32 *)(o + 24) - 0.02f;
    }
}
/* localdecomp:end func_L01_004629D8 */
