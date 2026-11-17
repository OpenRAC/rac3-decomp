/* func_L36_0037CA40: near miss, level 36 (Vidcomic 1 Special Edition). 218 differences (file L36_0037BDF0.c, -mvu0-use-vf0-vf2 @ps2as; needs the divs_nops row 'func_L36_0037CA40 2 2', not committed). Twin of func_L01_003773C0 (masked, unmatched). Every call, constant and global access is retail's; the frame is 0x20 too big because gcc's first scheduling pass moves the second loop's second lqc2 of a0+0x10 (vec_sub_ab) above the vec_add_ab, so a third VU0 value is live and two are spilled (with -fno-schedule-insns the frame is right, 172 differences); retail keeps the loads in source order. Also left: the saved-register roles (a0 $s6, the state $s7, &d $s5, &vel $fp) and the first loop's count-down placement. vec_*_ba variants and a block-local q tried */
#include "vu0.h"
__asm__(".extern D_L36_001DE1A0, 4");
__asm__(".extern D_L36_001DE1D0, 4");
__asm__(".extern D_L36_001DE1D4, 4");
__asm__(".extern D_L36_001DE1E0, 4");
extern vu0_v4 D_001A4EC0;
extern vu0_v4 D_L36_001DE1A0;
extern f32 D_L36_001DE1D0;
extern f32 D_L36_001DE1D4;
extern f32 D_L36_001DE1E0;
extern f32 D_L36_001DE1E4;
extern f32 D_L36_001DE1E8;
extern f32 D_L36_001E1BE0;
extern f32 D_L36_001E1BE4;
extern f32 D_L36_001E1BE8;
extern u8 D_L36_0021F4D8[];
extern u8 *D_L36_0021F5AC[];
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D308(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern s32 func_0013D3E0(void);
extern void func_003C4C18(void *, f32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern u8 *func_L01_00465738(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, f32, f32, f32, s32, s32, s32);
void func_L36_0037CA40(u8 *a0, vu0_v4 *a1, vu0_v4 *a2) {
    vu0_v4 from;
    vu0_v4 to;
    vu0_v4 vel;
    vu0_v4 pos;
    vu0_v4 step;
    vu0_v4 d;
    vu0_v4 m[3];
    vu0_v4 q;
    u8 *s;
    vu0_v4 *t;
    f32 len;
    s32 n;
    s32 i;
    s32 spin;
    s32 life;
    s32 alpha;
    s32 rgb;

    from = *a1;
    s = *(u8 **)(a0 + 0x68);
    to = *a2;
    len = func_0038CEA8(s);
    pos = to;
    vec_sub_ab(&step, &from, &to);
    n = len / 0.1f;
    func_0038CF68(&step, &step, len / (f32)n);
    for (i = 0; i < n; i++) {
        u8 *p;
        spin = func_L01_00443A18(1.0f, 3.0f);
        func_0038CE20(&vel, &D_001A4EC0, -(func_003824E0(0.1f, 0.2f) * 0.020000001f));
        life = func_00382498(3, 6);
        if (func_0013D3E0() & 2) {
            alpha = 0x40;
            rgb = 0x407FFF;
        } else {
            alpha = 0x60;
            rgb = 0x4040FF;
        }
        p = func_L01_0046A610(&pos, &vel, (life * 5 + 2) / 6, alpha, rgb, spin, 63000.004f, 10000.0f, 1.0f, 0.0f, 0.0f);
        vec_add_ab(&pos, &pos, &step);
        if (p != 0) {
            p[2] = **(u8 **)(D_L36_0021F4D8 + 0x5C);
            if (alpha == 0x40) {
                p[3] = 0x48;
            } else {
                p[3] = 0x44;
            }
        }
    }
    if (*(s32 *)(s + 0x34) < 0x32 && func_00382468(2)) {
        s32 c;
        u8 *p;
        func_0038CE20(&d, s, -0.040000003f);
        c = 0x7F80DFFF;
        func_003C4C18(&d, 0.120000005f);
        d.z += 0.060000002f;
        if (func_00382468(2)) {
            c = 0x7F407FFF;
        }
        p = func_L01_00465738(a0 + 0x10, &d, c, 0xFF, func_00382498(8, 0x11), 0, -1, -1, 0, 94500.0f);
        if (p != 0) {
            *(f32 *)(p + 0x2C) = 0.0024f;
            p[2] = *D_L36_0021F5AC[0];
        }
    }
    D_L36_001E1BE0 = func_0038DAB8(D_L36_001E1BE0, D_L36_001DE1E0 * 0.017453292f * 0.020000001f);
    D_L36_001E1BE4 = func_0038DAB8(D_L36_001E1BE4, D_L36_001DE1E4 * 0.017453292f * 0.020000001f);
    D_L36_001E1BE8 = func_0038DAB8(D_L36_001E1BE8, D_L36_001DE1E8 * 0.017453292f * 0.020000001f);
    func_0038D308(m, &D_L36_001E1BE0);
    t = &D_L36_001DE1A0;
    for (i = 2; i >= 0; i--) {
        u8 *p;
        func_0038D000(&q, t, m);
        if (*(s32 *)(s + 0x34) < 6) {
            func_0038CF68(&q, &q, 0.0f);
        } else {
            func_0038CF68(&q, &q, D_L36_001DE1D0);
        }
        vec_add_ab(&q, &q, a0 + 0x10);
        vec_sub_ab(&d, &q, a0 + 0x10);
        func_0038CF68(&d, &d, D_L36_001DE1D4 * 0.020000001f);
        p = func_L01_004713C8(&q, &d, 0xC, 0x204080, (s32)func_L01_00443A18(2.0f, 5.0f), 63000.004f,
                              func_003824E0(0.119999997f, 0.180000007f) * 210000.0f, 0.0f, 0x6F, 0, 6);
        if (p != 0) {
            p[3] = func_00382468(4) ? 0x48 : 0x44;
        }
        t++;
    }
}
