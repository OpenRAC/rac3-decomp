/* exact: matches at level_01. Functional meaning: Light/colour emitter update: in modes 0x30 and 0x15 it simply applies the setting with a0=0; otherwise it transforms the hero position into the emitter's box and, while inside (|x|,|y|,|z| <= 1), applies func_L01_004AB188 scaled by (x+1)/2 clamped to the max, else on leaving applies it with the full value (hero in front, x>0) or clears it, resetting the active byte */
#include "vu0.h"
extern s32 D_001D545C;
extern u8 D_001A4C60[];
extern void func_0038D000(void *, void *, void *);
extern void func_L01_004AB188(s32, s32, s32, s32, s32);
void func_L01_003EF140(u8 *self) {
    f32 a[4] __attribute__((aligned(16)));
    f32 r[4] __attribute__((aligned(16)));
    f32 h[4] __attribute__((aligned(16)));
    u8 *sub = *(u8 **)(self + 8);
    s32 vol, w4;
    f32 t;

    if (D_001D545C == 0x30 || D_001D545C == 0x15) {
        func_L01_004AB188(0, sub[0], *(s32 *)(sub + 4), sub[1], sub[2]);
        return;
    }
    *(vu0_q *)h = *(vu0_q *)D_001A4C60;
    vec_sub_ab(a, h, self + 0x40);
    a[3] = 0.0f;
    func_0038D000(r, a, self + 0x50);
    if (fabs_asm(r[0]) <= 1.0f && fabs_asm(r[1]) <= 1.0f && fabs_asm(r[2]) <= 1.0f) {
        w4 = *(s32 *)(sub + 4);
        t = (r[0] + 1.0f) * 0.5f;
        vol = (s32)((f32)w4 * t);
        if (w4 < vol) vol = w4;
        func_L01_004AB188((s32)self, sub[0], vol, sub[1], sub[2]);
        sub[3] = 1;
    } else if (sub[3] != 0) {
        if (0.0f < r[0]) {
            func_L01_004AB188(0, sub[0], *(s32 *)(sub + 4), sub[1], sub[2]);
        } else {
            func_L01_004AB188((s32)self, 0, 0, 0, 0);
        }
        sub[3] = 0;
    }
}
