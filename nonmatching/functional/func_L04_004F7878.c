/* functional: high. Checked at L04: control flow, constants, offsets and callee-saved registers match (accesses use the Hero-union cast style so the $gp/D_001A4BE0 base is rematerialised like retail); the 233 diff lines are one dead load retail keeps (lw 0x360 of the hero block, result unused) and the 1-instruction shift it causes. Needs #include vu0.h for fabs_asm. */
/* localdecomp:start func_L04_004F7878 */
#include "vu0.h"
typedef union { u8 b[0x2900]; s8 c[0x2900]; s16 h[0x1480]; s32 i[0xA40]; f32 f[0xA40]; } Hero;
extern u8 D_001A4BE0[];
extern u8 D_00142CAD[];
extern s32 D_00142660[];
extern void func_0038CBA0(void *, s32);
extern void func_L01_004DFEA0(s32);
extern s32 func_L04_0050CB28(s32, s32);
extern void func_L01_004E7C88(void);

void func_L04_004F7878(void) {
    s16 s;
    u8 t;
    s32 w;
    s = ((Hero *)D_001A4BE0)->h[0xA38];
    t = ((Hero *)D_001A4BE0)->b[0x147F];
    func_0038CBA0(((Hero *)D_001A4BE0)->b + 0x1470, 0x10);
    ((Hero *)D_001A4BE0)->b[0x147F] = t;
    ((Hero *)D_001A4BE0)->h[0xA38] = s;
    ((Hero *)D_001A4BE0)->b[0x25EA] = 0;
    ((Hero *)D_001A4BE0)->h[0x1B4] = 0;
    if (((Hero *)D_001A4BE0)->b[0x25EE] != 0) {
        return;
    }
    if (s == -1) {
        return;
    }
    if (s == 2 || s == 0x11 || s == 0x12) {
        if (((Hero *)D_001A4BE0)->h[0xEF] == 0) {
            if (((Hero *)D_001A4BE0)->h[0x1B6] == 0 || ((Hero *)D_001A4BE0)->f[0xCF] < 2.5f) {
                ((Hero *)D_001A4BE0)->b[0x1479] = 1;
                if (((Hero *)D_001A4BE0)->b[0x25E4] == 0) {
                    if (D_00142CAD[0] != 0) {
                        ((Hero *)D_001A4BE0)->h[0x1B4] = 1;
                    }
                }
            }
        }
    }
    if (s == 0x11) {
        if (((Hero *)D_001A4BE0)->h[0xEE] == 0 && ((Hero *)D_001A4BE0)->h[0x1B6] == 0) {
            if (((Hero *)D_001A4BE0)->i[0x973] != 7) {
                func_L01_004DFEA0(D_00142660[2] / 8);
                ((Hero *)D_001A4BE0)->h[0xEE] = 0x4B;
                func_L04_0050CB28(0xB1, 1);
            }
        }
    }
    if (s == 0xE) {
        f32 a;
        f32 b;
        a = 0.2f;
        b = ((Hero *)D_001A4BE0)->f[0xCE];
        ((Hero *)D_001A4BE0)->b[0x1476] = 1;
        ((Hero *)D_001A4BE0)->f[0xA12] = a;
        ((Hero *)D_001A4BE0)->f[0xD4] = b + a;
    }
    if (s == 0) {
        f32 d = ((Hero *)D_001A4BE0)->f[0xD4] - ((Hero *)D_001A4BE0)->f[0xCE];
        ((Hero *)D_001A4BE0)->f[0xA12] = d;
        if (d < 0.85f && 0.25f < d) {
            ((Hero *)D_001A4BE0)->b[0x25EA] = 1;
        }
        ((Hero *)D_001A4BE0)->b[0x1476] = 1;
    }
    if (s == 3) {
        ((Hero *)D_001A4BE0)->b[0x1478] = 1;
    }
    if (s == 0xB) {
        ((Hero *)D_001A4BE0)->b[0x147D] = 1;
    }
    if (s == 8 || s == 0x12) {
        ((Hero *)D_001A4BE0)->b[0x147C] = 1;
    }
    if (s == 0xC) {
        ((Hero *)D_001A4BE0)->b[0x147C] = 1;
    }
    if (((Hero *)D_001A4BE0)->b[0x1478] != 0) {
        w = ((Hero *)D_001A4BE0)->i[0x971];
        if (w != 0x6A && w != 0x7D) {
            f32 f3 = ((Hero *)D_001A4BE0)->f[0x22];
            f32 f2 = ((Hero *)D_001A4BE0)->f[0xD5];
            if (fabs_asm(f2 - (f3 + 0.25f)) < 1.0f) {
                if (0.0f < f2 - f3) {
                    if (w != 0x6B || ((Hero *)D_001A4BE0)->b[0x46E] != 0) {
                        if (((Hero *)D_001A4BE0)->f[0x46] < 0.0f || w == 0x80) {
                            func_L01_004E7C88();
                            func_L04_0050CB28(((Hero *)D_001A4BE0)->i[0xA14] != 0 ? 0x6A : 0x7D, 1);
                            return;
                        }
                    }
                }
            }
        }
    }
    if (((Hero *)D_001A4BE0)->b[0x147D] != 0) {
        w = ((Hero *)D_001A4BE0)->i[0x971];
        if (w == 0x7D) {
            return;
        }
        if (w == 0x79) {
            return;
        }
        {
            f32 f3 = ((Hero *)D_001A4BE0)->f[0x22];
            f32 f2 = ((Hero *)D_001A4BE0)->f[0xD5];
            if (fabs_asm(f2 - (f3 + 0.25f)) < 1.0f) {
                if (0.0f < f2 - f3) {
                    if (((Hero *)D_001A4BE0)->f[0x46] < 0.0f || w == 0x80) {
                        func_L01_004E7C88();
                        func_L04_0050CB28(0x7D, 1);
                    }
                }
            }
        }
    }
}
/* localdecomp:end func_L04_004F7878 */
