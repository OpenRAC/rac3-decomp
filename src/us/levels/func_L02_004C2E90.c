#include "common.h"

/* NTSC-U counterpart of func_L02_004C7118 (src/levels/shared/L02_004C7118.c) */
typedef int u128_004C7118 __attribute__((mode(TI)));
typedef union { u8 b[0x2900]; s8 c[0x2900]; s16 h[0x1480]; u16 uh[0x1480]; s32 i[0xA40]; f32 f[0xA40]; u128_004C7118 q[0x290]; } Hero_004C7118;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_004C7118;
typedef struct { u8 x0[0x18]; f32 x18; u8 x1C[0x364]; u128_004C7118 x380; } S_1E22C0_004C7118;

/* localdecomp:start func_L02_004C2E90 */
#include "vu0.h"


extern char D_001A4BE0[];
extern char D_001A4CD0[];
extern char D_001A508C[];
extern s32 D_L02_001D673C_004C2E90;
extern f32 D_L02_001DBD18_004C2E90;

extern S_1E22C0_004C7118 D_L02_001E1380;

extern void func_L01_004EAA78(s32, f32);
extern void func_L01_004ED448(f32);
extern void func_L01_004EC780(f32, f32);
extern void func_L01_004EB350(f32, f32);
extern void func_L01_004EAFF8(s32, f32, f32, f32);
extern void func_L01_004EA5B0(void);
extern void func_L01_004EB918_004C2E90(void *, void *, f32, f32, s32);
extern void func_L01_0050D5B0(void *, void *, f32);
extern void func_L01_0050D1A0(void *, void *, f32);
extern f32 func_L01_0050D430(void *);
extern void func_L01_0050D530(void *, void *, f32);
extern void func_L01_004E14C8(f32, f32, f32);
extern void func_00388880(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388730(void *, void *);
extern void func_003888C8(void *, void *, void *);
extern s32 func_L01_0045D358(s32, s32, s32, s32);
extern f32 func_00389468(f32, f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_L01_004455F0(f32 *, f32, void *, f32, f32, f32, s32);
extern f32 func_003893C8(f32, f32);
extern s32 func_003D00C0(void);

void func_L02_004C2E90(void) {
    V4_004C7118 v0;
    V4_004C7118 v10;
    V4_004C7118 v20;
    V4_004C7118 v30;
    V4_004C7118 v40;
    f32 a50;
    f32 a54;
    s32 state = ((Hero_004C7118 *)D_001A4BE0)->i[0x25C4 / 4];

    if (state == 0xA2) {
        func_L01_004EAA78(0, 0.16166668f);
        ((Hero_004C7118 *)D_001A4BE0)->f[0x1A0 / 4] = ((Hero_004C7118 *)D_001A4BE0)->f[0x98 / 4];
        func_L01_004ED448(0.019444445f);
        ((Hero_004C7118 *)D_001A4BE0)->f[0x1B4 / 4] = ((Hero_004C7118 *)D_001A4BE0)->f[0x174 / 4];
    } else if (state == 0xA) {
        func_L01_004EC780(0.7f, 0.0f);
        ((Hero_004C7118 *)D_001A4BE0)->q[0x160 / 16] = ((Hero_004C7118 *)D_001A4BE0)->q[0x9E0 / 16];
        ((Hero_004C7118 *)D_001A4BE0)->f[0x1B4 / 4] = ((Hero_004C7118 *)D_001A4BE0)->f[0x174 / 4];
    } else if (state == 0x10) {
        if (((Hero_004C7118 *)D_001A4BE0)->i[0x1B8 / 4] >= 55) {
            func_003BEBF8(&((Hero_004C7118 *)D_001A4BE0)->f[0x4F0 / 4], 0.0069444445f, 0.0019444445f);
        }
        if (((Hero_004C7118 *)D_001A4BE0)->i[0x1B8 / 4] < 55) {
            ((Hero_004C7118 *)D_001A4BE0)->f[0x1B0 / 4] = ((Hero_004C7118 *)D_001A4BE0)->f[0x424 / 4];
        } else {
            ((Hero_004C7118 *)D_001A4BE0)->f[0x1B0 / 4] = 0.058333337f;
        }
        func_L01_004EB350(0.012222223f, 0.0125f);
        func_L01_0050D5B0(D_001A4CD0, D_001A4CD0, 0.0f);
        func_L01_0050D1A0(D_001A4CD0, D_001A4CD0, ((Hero_004C7118 *)D_001A4CD0)->f[0xC4 / 4]);
    } else if (state == 0x1B) {
        f32 d;

        if (((Hero_004C7118 *)D_001A4BE0)->i[0x1B8 / 4] >= 41) {
            func_L01_004EAFF8(0, 0.04f, 0.2f, 0.25016388f);
            func_L01_004ED448(0.0055555557f);
        }
        d = ((Hero_004C7118 *)D_001A4BE0)->f[0xC18 / 4];
        if (13.0f <= d && d <= 30.0f) {
            if (d > 27.0f) {
                func_003BEBF8(&((Hero_004C7118 *)D_001A4BE0)->f[0x48C / 4], 0.0f, 0.0022222223f);
            } else {
                func_003BEBF8(&((Hero_004C7118 *)D_001A4BE0)->f[0x48C / 4], 0.033333335f, 0.0022222223f);
            }
        }
        v0.y = 0.0f;
        v0.x = ((Hero_004C7118 *)D_001A4BE0)->f[0x48C / 4];
        v0.z = func_00388730(D_001A4BE0 + 0xF0, D_001A4BE0 + 0x20);
        func_003888C8(D_001A4BE0 + 0xF0, &v0, D_001A4BE0);
    } else if (state == 0xB) {
        s32 blocked;

        if (((Hero_004C7118 *)D_001A4BE0)->h[0x1434 / 2] != 0
            || (((Hero_004C7118 *)D_001A4BE0)->i[0x16B0 / 4] == 1 && func_L01_0045D358(0x28, 2, 0, 0) != 0)) {
            func_L01_004EA5B0();
        } else {
            ((Hero_004C7118 *)D_001A4BE0)->f[0x1A0 / 4] = ((Hero_004C7118 *)D_001A4BE0)->f[0x494 / 4];
            ((Hero_004C7118 *)D_001A4BE0)->q[0x190 / 16] = ((Hero_004C7118 *)D_001A4BE0)->q[0x450 / 16];
            func_L01_004EAFF8(0, 0.04f, 0.2f, 0.11635529f);
        }
        if (((Hero_004C7118 *)D_001A4BE0)->i[0x4A4 / 4] != 3) {
            ((Hero_004C7118 *)D_001A4BE0)->f[0x1B4 / 4] = ((Hero_004C7118 *)D_001A4BE0)->f[0x4A8 / 4];
        } else {
            ((Hero_004C7118 *)D_001A4BE0)->f[0x1B4 / 4] = 0.0f;
        }
        blocked = 0;
        if (D_L02_001D673C_004C2E90 == 0 && ((Hero_004C7118 *)D_001A4BE0)->f[0x33C / 4] < 3.0f
            && ((Hero_004C7118 *)D_001A4BE0)->i[0x1B8 / 4] >= 14) {
            func_00388880(&v0, D_001A4BE0 + 0x110, 0.57f);
            vec_add_ab(&v0, &v0, D_001A4BE0 + 0x80);
            v0.z = ((Hero_004C7118 *)D_001A4BE0)->f[0x308 / 4];
            v10 = v0;
            v20 = v0;
            v10.z += 2.0f;
            v20.z -= 3.0f;
            if (func_003CE740(&v10, &v20, 2, 0, 0) == 0) {
                func_00388880(&v0, D_001A4BE0 + 0x110, 5.5f);
                vec_add_ab(&v0, &v0, D_001A4BE0 + 0x80);
                v0.z = ((Hero_004C7118 *)D_001A4BE0)->f[0x308 / 4];
                v30 = v0;
                v40 = v0;
                v30.z += 2.0f;
                v40.z -= 3.0f;
                if (func_003CE740(&v30, &v40, 2, 0, 0) == 0) {
                    ((Hero_004C7118 *)D_001A4BE0)->f[0x4AC / 4] = 0.0f;
                    blocked = 1;
                }
            }
        }
        if (((Hero_004C7118 *)D_001A4BE0)->b[0x4FD] != 0) {
            if (blocked == 0) {
                f32 k = ((Hero_004C7118 *)D_001A4BE0)->f[0x2838 / 4] * 0.09166667f;
                if (k < 0.033333335f) {
                    k = 0.033333335f;
                }
                func_003BEBF8(&((Hero_004C7118 *)D_001A4BE0)->f[0x4AC / 4], k, 0.0130555555f);
                ((Hero_004C7118 *)D_001A4BE0)->f[0x1B4 / 4] = ((Hero_004C7118 *)D_001A4BE0)->f[0x174 / 4];
            }
        } else if (((Hero_004C7118 *)D_001A4BE0)->b[0x46E] != 0 && ((Hero_004C7118 *)D_001A4BE0)->h[0x47E / 2] < 12) {
            func_003BEBF8(&((Hero_004C7118 *)D_001A4BE0)->f[0x4AC / 4], 0.0f, 0.0022222223f);
        } else if (blocked == 0) {
            func_003BEBF8((f32 *)D_001A508C, 0.07f, 0.0022222223f);
        }
        if (((Hero_004C7118 *)D_001A4BE0)->b[0x25F4] == 0) {
            ((Hero_004C7118 *)D_001A4BE0)->f[0xF0 / 4] = func_00388960(((Hero_004C7118 *)D_001A4BE0)->f[0x490 / 4]) * ((Hero_004C7118 *)D_001A4BE0)->f[0x4AC / 4];
            ((Hero_004C7118 *)D_001A4BE0)->f[0xF4 / 4] = func_00388978(((Hero_004C7118 *)D_001A4BE0)->f[0x490 / 4]) * ((Hero_004C7118 *)D_001A4BE0)->f[0x4AC / 4];
        } else {
            func_L01_0050D5B0(&v0, D_001A4BE0 + 0x440, ((Hero_004C7118 *)D_001A4BE0)->f[0x4AC / 4]);
            func_L01_0050D530(&v0, &v0, 0.0f);
            func_L01_0050D5B0(D_001A4BE0 + 0xF0, D_001A4BE0 + 0xF0, 0.0f);
            vec_add_ab(D_001A4BE0 + 0xF0, D_001A4BE0 + 0xF0, &v0);
        }
        if (((Hero_004C7118 *)D_001A4BE0)->b[0x25F4] == 0 && ((Hero_004C7118 *)D_001A4BE0)->b[0x4FD] == 0) {
            f32 s = ((Hero_004C7118 *)D_001A4BE0)->f[0x4A8 / 4]
                  * func_00388978(func_00389468(((Hero_004C7118 *)D_001A4BE0)->f[0x494 / 4], ((Hero_004C7118 *)D_001A4BE0)->f[0x490 / 4]));
            ((Hero_004C7118 *)D_001A4BE0)->f[0xF0 / 4] += func_00388960(((Hero_004C7118 *)D_001A4BE0)->f[0x494 / 4]) * s;
            ((Hero_004C7118 *)D_001A4BE0)->f[0xF4 / 4] += func_00388978(((Hero_004C7118 *)D_001A4BE0)->f[0x494 / 4]) * s;
        }
        func_L01_004EC780(0.7f, 0.0f);
        *(u128_004C7118 *)(D_001A4BE0 + 0x160) = *(u128_004C7118 *)(D_001A4BE0 + 0x160 + 0x880);
    } else if (state == 0x11) {
        char *target = D_001A4BE0 + 0x190;

        ((Hero_004C7118 *)D_001A4BE0)->f[0x1A0 / 4] = ((Hero_004C7118 *)D_001A4BE0)->f[0x4CC / 4];
        ((Hero_004C7118 *)D_001A4BE0)->q[0x190 / 16] = ((Hero_004C7118 *)D_001A4BE0)->q[0x4C0 / 16];
        if (((Hero_004C7118 *)D_001A4BE0)->i[0x1B8 / 4] >= 10) {
            func_L01_004EAFF8(-1, 0.042f, 0.2f, 0.19780399f);
        }
        if (((Hero_004C7118 *)D_001A4BE0)->i[0x1B8 / 4] >= 9) {
            if (((Hero_004C7118 *)D_001A4BE0)->h[0x368 / 2] == 0) {
                ((Hero_004C7118 *)D_001A4BE0)->f[0xF0 / 4] = func_00388960(((Hero_004C7118 *)D_001A4BE0)->f[0x1A0 / 4]) * 0.08166667f;
                ((Hero_004C7118 *)D_001A4BE0)->f[0xF4 / 4] = func_00388978(((Hero_004C7118 *)D_001A4BE0)->f[0x1A0 / 4]) * 0.08166667f;
            } else {
                    func_L01_0050D5B0(D_001A4BE0 + 0xF0, D_001A4BE0 + 0xF0, 0.0f);
                func_00388830(&v0, target, 0.08166667f);
                vec_add_ab(D_001A4BE0 + 0xF0, D_001A4BE0 + 0xF0, &v0);
            }
        }
        ((Hero_004C7118 *)D_001A4BE0)->f[0x1B4 / 4] = ((Hero_004C7118 *)D_001A4BE0)->f[0x174 / 4];
    } else if (state == 0x86 && D_L02_001D673C_004C2E90 == 0) {
        func_L01_004EAFF8(0, 0.04f, 0.2f, ((Hero_004C7118 *)D_001A4BE0)->f[0x464 / 4]);
        ((Hero_004C7118 *)D_001A4BE0)->f[0x1B4 / 4] = 0.0f;
    } else {
        f32 speed;

        if (((Hero_004C7118 *)D_001A4BE0)->i[0x25C4 / 4] == 0x2C) {
            f32 r;

            a50 = ((Hero_004C7118 *)D_001A4BE0)->f[0x98 / 4];
            ((Hero_004C7118 *)D_001A4BE0)->f[0x1A8 / 4] = func_L01_004455F0(&a50, ((Hero_004C7118 *)D_001A4BE0)->f[0x1A0 / 4], D_001A4BE0 + 0x1A4, 0.018f, 0.2f, 0.122173056f, 0);
            r = func_003893C8(a50, ((Hero_004C7118 *)D_001A4BE0)->f[0x98 / 4]);
            func_L01_004E14C8(0.0f, 0.0f, r);
        } else {
            f32 a;

            v0 = *(V4_004C7118 *)(D_001A4BE0 + 0x190);
            a = ((Hero_004C7118 *)D_001A4BE0)->f[0x1A0 / 4];

            if (((Hero_004C7118 *)D_001A4BE0)->h[0x1434 / 2] != 0
                || (((Hero_004C7118 *)D_001A4BE0)->i[0x16B0 / 4] == 1 && func_L01_0045D358(0x28, 2, 0, 0) != 0)) {
                ((Hero_004C7118 *)D_001A4BE0)->f[0x1A0 / 4] = D_L02_001E1380.x18;
                ((Hero_004C7118 *)D_001A4BE0)->q[0x190 / 16] = D_L02_001E1380.x380;
            }
            func_L01_004EAFF8(0, 0.04f, 0.2f, ((Hero_004C7118 *)D_001A4BE0)->f[0x464 / 4]);
            if (((Hero_004C7118 *)D_001A4BE0)->h[0x1434 / 2] != 0
                || (((Hero_004C7118 *)D_001A4BE0)->i[0x16B0 / 4] == 1 && func_L01_0045D358(0x28, 2, 0, 0) != 0)) {
                ((Hero_004C7118 *)D_001A4BE0)->f[0x1438 / 4] = a;
                ((Hero_004C7118 *)D_001A4BE0)->q[0x1420 / 16] = *(u128_004C7118 *)&v0;
                ((Hero_004C7118 *)D_001A4BE0)->f[0x1A0 / 4] = a;
                ((Hero_004C7118 *)D_001A4BE0)->q[0x190 / 16] = *(u128_004C7118 *)&v0;
            }
        }
        speed = 0.0055555557f;
        func_L01_004EC780(0.7f, 0.0f);
        *(u128_004C7118 *)(D_001A4BE0 + 0x160) = *(u128_004C7118 *)(D_001A4BE0 + 0x160 + 0x880);
        if (((Hero_004C7118 *)D_001A4BE0)->f[0x1B0 / 4] < D_L02_001DBD18_004C2E90 * 0.016666668f * 0.2f) {
            if (((Hero_004C7118 *)D_001A4BE0)->i[0x25CC / 4] == 2) {
                f32 rate;

                rate = ((Hero_004C7118 *)D_001A4BE0)->f[0xA04 / 4];
                if (((Hero_004C7118 *)D_001A4BE0)->b[0x1474] != 0) {
                    rate = 4.7222224e-05f;
                }
                a54 = func_L01_0050D430(D_001A4BE0 + 0xF0);
                func_003BEBF8(&a54, 0.0f, rate);
                func_L01_0050D5B0(D_001A4BE0 + 0xF0, D_001A4BE0 + 0xF0, a54);
                return;
            }
            if (((Hero_004C7118 *)D_001A4BE0)->h[0x36A / 2] != 0) {
                speed = 0.0030555557f;
            } else if (((Hero_004C7118 *)D_001A4BE0)->h[0x4F4 / 2] != 0) {
                speed = 0.00055555557f;
            } else {
                speed = 0.0022222223f;
            }
        }
        if (((Hero_004C7118 *)D_001A4BE0)->h[0x4F8 / 2] != 0 && ((Hero_004C7118 *)D_001A4BE0)->b[0x1474] != 0) {
            speed = 0.00013888889f;
            if (((Hero_004C7118 *)D_001A4BE0)->f[0x2838 / 4] > 0.9f) {
                func_L01_004EB918_004C2E90(&v0, &v10, 0.5f, -1.5f, 0);
                v0.x += func_00388960(((Hero_004C7118 *)D_001A4BE0)->f[0x1A0 / 4]) * 0.7f;
                v0.y += func_00388978(((Hero_004C7118 *)D_001A4BE0)->f[0x1A0 / 4]) * 0.7f;
                v10.x += func_00388960(((Hero_004C7118 *)D_001A4BE0)->f[0x1A0 / 4]) * 0.7f;
                v10.y += func_00388978(((Hero_004C7118 *)D_001A4BE0)->f[0x1A0 / 4]) * 0.7f;
                if (func_003CE740(&v0, &v10, 2, 0, 0) != 0 && func_003D00C0() != 7) {
                    ((Hero_004C7118 *)D_001A4BE0)->f[0x1B0 / 4] = 0.083333336f;
                    speed = 0.0027777778f;
                }
            }
            if (((Hero_004C7118 *)D_001A4BE0)->i[0x25C4 / 4] == 0xF) {
                speed = 0.00083333335f;
                func_L01_004EAA78(0, 0.041666668f);
            }
            if (((Hero_004C7118 *)D_001A4BE0)->f[0x340 / 4] > 0.2617994f) {
                ((Hero_004C7118 *)D_001A4BE0)->f[0x1B0 / 4] = 0.0f;
                speed = ((Hero_004C7118 *)D_001A4BE0)->f[0x340 / 4] * 0.0025f / 0.7853982f;
            }
        }
        func_L01_004ED448(speed);
    }
}
/* localdecomp:end func_L02_004C2E90 */
