/* functional: high. Read against asm; all constants and 30 effect args match the L36 call; remaining diff is scheduling and gp addressing. */
#include "vu0.h"
extern s32 D_L31_001DD250;
extern f32 D_L31_001DD1FC;
extern s32 D_L31_001E12D0[];
extern u8 D_L31_00284130[];
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L31_0034ADF0(void *, void *, s32);

/* Vid-comic 1: spawns the path-following glow effect at the interpolated position for the current
 * timer and fills the 30 colour rows of D_L31_00284130 (white up to the current point, fading after). */
void func_L31_0034BCA8(u8 *obj) {
    u8 *v = *(u8 **)(obj + 0x68);
    u8 *child = *(u8 **)(v + 0x158);
    u8 *cv = *(u8 **)(child + 0x68);
    f32 p;
    f32 pos;
    f32 frac;
    s32 idx;
    s32 seg;
    s32 i;
    vu0_v4 a, b;
    vu0_v4 col;
    vu0_q q;

    p = 1.0f - (f32)*(s32 *)(v + 0xD4) / (f32)D_L31_001DD250;
    idx = (s32)(p / 0.07142859697f);
    pos = (1.0f - p) * 30.0f;
    /* retail reads *cv even when cv is 0 */
    if (cv == 0 || D_L31_001E12D0[idx] != 0) {
        if (*(u8 **)cv != obj || *(s32 *)(cv + 8) != 0) {
            goto colours;
        }
    }
    seg = (s32)pos;
    func_003C2F58(obj, seg, &a);
    func_003C2F58(obj, seg + 1, &b);
    if (pos - (f32)(s32)pos != 0.0f) {
        frac = pos - (f32)seg;
        func_0038CE20(&b, &b, frac);
        func_0038CE20(&a, &a, 1.0f - frac);
        vec_add_ab(&a, &a, &b);
    }
    func_L01_003303B8((u8 *)&a, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 1, 0.9f, 0.0f, 0.0f, 2.0f,
                      1, 1, 0, 0, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                      0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_L31_0034ADF0(obj, &a, idx);
colours:
    for (i = 0; i < 30; i++) {
        f32 d = (f32)i;
        if (pos < d) {
            q = *(vu0_q *)D_L31_001D66B0;
        } else {
            d = fabs_asm(d - pos) / D_L31_001DD1FC;
            if (1.0f < d) {
                d = 1.0f;
            }
            col.x = d;
            col.y = d;
            col.z = d;
            q = *(vu0_q *)&col; /* col.w is left unset, as retail does */
        }
        *(vu0_q *)(D_L31_00284130 + i * 0x40) = q;
    }
}
