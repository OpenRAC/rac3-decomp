#include "common.h"

/* localdecomp:start func_L30_004C0028 */
#include "vu0.h"

typedef int u128_004C0028 __attribute__((mode(TI)));
typedef union { u8 b[0x2900]; s8 c[0x2900]; s16 h[0x1480]; u16 uh[0x1480]; s32 i[0xA40]; f32 f[0xA40]; u128_004C0028 q[0x290]; } Hero_004C0028;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_004C0028;

extern char D_001A4BE0[];
extern char D_001A4CD0[];
extern char D_001A4D40[];
extern char D_001A508C[];
extern s32 D_L30_001D673C;
extern f32 D_L30_001DBCA8;
typedef struct { u8 x0[0x18]; f32 x18; u8 x1C[0x364]; u128_004C0028 x380; } S_1E22C0_004C0028;
extern S_1E22C0_004C0028 D_L30_001E22C0;

extern void func_L30_004BCB20(s32, f32);
extern void func_L01_004F1220(f32);
extern void func_L01_004F0558(f32, f32);
extern void func_L01_004EF128(f32, f32);
extern void func_L01_004EEDD0(s32, f32, f32, f32);
extern void func_L01_004EE388(void);
extern void func_L01_004EF6F0(void *, void *, f32, f32, s32);
extern void func_L01_00511588(void *, void *, f32);
extern void func_L01_00511178(void *, void *, f32);
extern f32 func_L01_00511408(void *);
extern void func_L01_00511508(void *, void *, f32);
extern void func_L01_004E5290(f32, f32, f32);
extern void func_0038CFB8(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern f32 func_0038DBA0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_00448728(f32 *, f32, void *, f32, f32, f32, s32);
extern f32 func_0038DB00(f32, f32);
extern s32 func_003D5630(void);

void func_L30_004C0028(void) {
    V4_004C0028 v0;
    V4_004C0028 v10;
    V4_004C0028 v20;
    V4_004C0028 v30;
    V4_004C0028 v40;
    f32 a50;
    f32 a54;
    s32 state = ((Hero_004C0028 *)D_001A4BE0)->i[0x25C4 / 4];

    if (state == 0xA2) {
        func_L30_004BCB20(0, 0.194f);
        ((Hero_004C0028 *)D_001A4BE0)->f[0x1A0 / 4] = ((Hero_004C0028 *)D_001A4BE0)->f[0x98 / 4];
        func_L01_004F1220(0.028f);
        ((Hero_004C0028 *)D_001A4BE0)->f[0x1B4 / 4] = ((Hero_004C0028 *)D_001A4BE0)->f[0x174 / 4];
    } else if (state == 0xA7) {
        func_L30_004BCB20(0, 0.18f);
        if (((Hero_004C0028 *)D_001A4BE0)->i[0x1B8 / 4] < 30) {
            ((Hero_004C0028 *)D_001A4BE0)->f[0x1A0 / 4] = ((Hero_004C0028 *)D_001A4BE0)->f[0x4B8 / 4];
        } else if (((Hero_004C0028 *)D_001A4BE0)->f[0x2838 / 4] < 0.2f) {
            ((Hero_004C0028 *)D_001A4BE0)->f[0x1A0 / 4] = ((Hero_004C0028 *)D_001A4BE0)->f[0x98 / 4];
        }
        if (((Hero_004C0028 *)D_001A4BE0)->i[0x1B8 / 4] >= 8) {
            ((Hero_004C0028 *)D_001A4BE0)->f[0x1B0 / 4] = 0.26000002f;
            func_L01_004F1220(0.108f);
        } else {
            f32 k = 0.020000001f;
            if (((Hero_004C0028 *)D_001A4BE0)->f[0x2838 / 4] > 0.2f) {
                k = 0.068f;
            }
            func_L01_004F1220(k);
        }
        ((Hero_004C0028 *)D_001A4BE0)->f[0x1B4 / 4] = ((Hero_004C0028 *)D_001A4BE0)->f[0x174 / 4];
    } else if (state == 0xA) {
        func_L01_004F0558(0.7f, 0.0f);
        ((Hero_004C0028 *)D_001A4BE0)->q[0x160 / 16] = ((Hero_004C0028 *)D_001A4BE0)->q[0x9E0 / 16];
        ((Hero_004C0028 *)D_001A4BE0)->f[0x1B4 / 4] = ((Hero_004C0028 *)D_001A4BE0)->f[0x174 / 4];
    } else if (state == 0x10) {
        if (((Hero_004C0028 *)D_001A4BE0)->i[0x1B8 / 4] >= 46) {
            func_003C4138(&((Hero_004C0028 *)D_001A4BE0)->f[0x4F0 / 4], 0.010000001f, 0.0028000001f);
        }
        if (((Hero_004C0028 *)D_001A4BE0)->i[0x1B8 / 4] < 46) {
            ((Hero_004C0028 *)D_001A4BE0)->f[0x1B0 / 4] = ((Hero_004C0028 *)D_001A4BE0)->f[0x424 / 4];
        } else {
            ((Hero_004C0028 *)D_001A4BE0)->f[0x1B0 / 4] = 0.07000001f;
        }
        func_L01_004EF128(0.0176f, 0.018000001f);
        func_L01_00511588(D_001A4CD0, D_001A4CD0, 0.0f);
        func_L01_00511178(D_001A4CD0, D_001A4CD0, ((Hero_004C0028 *)D_001A4CD0)->f[0xC4 / 4]);
    } else if (state == 0x1B) {
        f32 d;

        if (((Hero_004C0028 *)D_001A4BE0)->i[0x1B8 / 4] >= 34) {
            func_L01_004EEDD0(0, 0.057600003f, 0.28800002f, 0.30019665f);
            func_L01_004F1220(0.008f);
        }
        d = ((Hero_004C0028 *)D_001A4BE0)->f[0xC18 / 4];
        if (13.0f <= d && d <= 30.0f) {
            if (d > 27.0f) {
                func_003C4138(&((Hero_004C0028 *)D_001A4BE0)->f[0x48C / 4], 0.0f, 0.0032000002f);
            } else {
                func_003C4138(&((Hero_004C0028 *)D_001A4BE0)->f[0x48C / 4], 0.040000003f, 0.0032000002f);
            }
        }
        v0.y = 0.0f;
        v0.x = ((Hero_004C0028 *)D_001A4BE0)->f[0x48C / 4];
        v0.z = func_0038CE68(D_001A4BE0 + 0xF0, D_001A4BE0 + 0x20);
        func_0038D000(D_001A4BE0 + 0xF0, &v0, D_001A4BE0);
    } else if (state == 0x48) {
        f32 d;

        d = ((Hero_004C0028 *)D_001A4BE0)->f[0xC18 / 4];
        if (5.0f <= d && d <= 18.0f) {
            if (d > 15.0f) {
                func_003C4138(&((Hero_004C0028 *)D_001A4BE0)->f[0x48C / 4], 0.0f, 0.0032000002f);
            } else {
                func_003C4138(&((Hero_004C0028 *)D_001A4BE0)->f[0x48C / 4], 0.025000002f, 0.0032000002f);
            }
        }
        v0.y = 0.0f;
        v0.x = ((Hero_004C0028 *)D_001A4BE0)->f[0x48C / 4];
        v0.z = func_0038CE68(D_001A4BE0 + 0xF0, D_001A4BE0 + 0x20);
        func_0038D000(D_001A4BE0 + 0xF0, &v0, D_001A4BE0);
    } else if (state == 0xB) {
        s32 blocked;

        if (((Hero_004C0028 *)D_001A4BE0)->h[0x1434 / 2] != 0
            || (((Hero_004C0028 *)D_001A4BE0)->i[0x16B0 / 4] == 1 && func_L01_004606E8(0x28, 2, 0, 0) != 0)) {
            func_L01_004EE388();
        } else {
            ((Hero_004C0028 *)D_001A4BE0)->f[0x1A0 / 4] = ((Hero_004C0028 *)D_001A4BE0)->f[0x494 / 4];
            ((Hero_004C0028 *)D_001A4BE0)->q[0x190 / 16] = ((Hero_004C0028 *)D_001A4BE0)->q[0x450 / 16];
            func_L01_004EEDD0(0, 0.057600003f, 0.28800002f, 0.13962635f);
        }
        if (((Hero_004C0028 *)D_001A4BE0)->i[0x4A4 / 4] != 3) {
            ((Hero_004C0028 *)D_001A4BE0)->f[0x1B4 / 4] = ((Hero_004C0028 *)D_001A4BE0)->f[0x4A8 / 4];
        } else {
            ((Hero_004C0028 *)D_001A4BE0)->f[0x1B4 / 4] = 0.0f;
        }
        blocked = 0;
        if (D_L30_001D673C == 0 && ((Hero_004C0028 *)D_001A4BE0)->f[0x33C / 4] < 3.0f
            && ((Hero_004C0028 *)D_001A4BE0)->i[0x1B8 / 4] >= 12) {
            func_0038CFB8(&v0, D_001A4BE0 + 0x110, 0.57f);
            vec_add_ab(&v0, &v0, D_001A4BE0 + 0x80);
            v0.z = ((Hero_004C0028 *)D_001A4BE0)->f[0x308 / 4];
            v10 = v0;
            v20 = v0;
            v10.z += 2.0f;
            v20.z -= 3.0f;
            if (func_003D3CB0(&v10, &v20, 2, 0, 0) == 0) {
                func_0038CFB8(&v0, D_001A4BE0 + 0x110, 5.5f);
                vec_add_ab(&v0, &v0, D_001A4BE0 + 0x80);
                v0.z = ((Hero_004C0028 *)D_001A4BE0)->f[0x308 / 4];
                v30 = v0;
                v40 = v0;
                v30.z += 2.0f;
                v40.z -= 3.0f;
                if (func_003D3CB0(&v30, &v40, 2, 0, 0) == 0) {
                    ((Hero_004C0028 *)D_001A4BE0)->f[0x4AC / 4] = 0.0f;
                    blocked = 1;
                }
            }
        }
        if (((Hero_004C0028 *)D_001A4BE0)->b[0x4FD] != 0) {
            if (blocked == 0) {
                f32 k = ((Hero_004C0028 *)D_001A4BE0)->f[0x2838 / 4] * 0.11000001f;
                if (k < 0.040000003f) {
                    k = 0.040000003f;
                }
                func_003C4138(&((Hero_004C0028 *)D_001A4BE0)->f[0x4AC / 4], k, 0.018800002f);
                ((Hero_004C0028 *)D_001A4BE0)->f[0x1B4 / 4] = ((Hero_004C0028 *)D_001A4BE0)->f[0x174 / 4];
            }
        } else if (((Hero_004C0028 *)D_001A4BE0)->b[0x46E] != 0 && ((Hero_004C0028 *)D_001A4BE0)->h[0x47E / 2] < 10) {
            func_003C4138(&((Hero_004C0028 *)D_001A4BE0)->f[0x4AC / 4], 0.0f, 0.0032000002f);
        } else if (blocked == 0) {
            func_003C4138((f32 *)D_001A508C, 0.084f, 0.0032000002f);
        }
        if (((Hero_004C0028 *)D_001A4BE0)->b[0x25F4] == 0) {
            ((Hero_004C0028 *)D_001A4BE0)->f[0xF0 / 4] = func_0038D098(((Hero_004C0028 *)D_001A4BE0)->f[0x490 / 4]) * ((Hero_004C0028 *)D_001A4BE0)->f[0x4AC / 4];
            ((Hero_004C0028 *)D_001A4BE0)->f[0xF4 / 4] = func_0038D0B0(((Hero_004C0028 *)D_001A4BE0)->f[0x490 / 4]) * ((Hero_004C0028 *)D_001A4BE0)->f[0x4AC / 4];
        } else {
            func_L01_00511588(&v0, D_001A4BE0 + 0x440, ((Hero_004C0028 *)D_001A4BE0)->f[0x4AC / 4]);
            func_L01_00511508(&v0, &v0, 0.0f);
            func_L01_00511588(D_001A4BE0 + 0xF0, D_001A4BE0 + 0xF0, 0.0f);
            vec_add_ab(D_001A4BE0 + 0xF0, D_001A4BE0 + 0xF0, &v0);
        }
        if (((Hero_004C0028 *)D_001A4BE0)->b[0x25F4] == 0 && ((Hero_004C0028 *)D_001A4BE0)->b[0x4FD] == 0) {
            f32 s = ((Hero_004C0028 *)D_001A4BE0)->f[0x4A8 / 4]
                  * func_0038D0B0(func_0038DBA0(((Hero_004C0028 *)D_001A4BE0)->f[0x494 / 4], ((Hero_004C0028 *)D_001A4BE0)->f[0x490 / 4]));
            ((Hero_004C0028 *)D_001A4BE0)->f[0xF0 / 4] += func_0038D098(((Hero_004C0028 *)D_001A4BE0)->f[0x494 / 4]) * s;
            ((Hero_004C0028 *)D_001A4BE0)->f[0xF4 / 4] += func_0038D0B0(((Hero_004C0028 *)D_001A4BE0)->f[0x494 / 4]) * s;
        }
        func_L01_004F0558(0.7f, 0.0f);
        *(u128_004C0028 *)(D_001A4BE0 + 0x160) = *(u128_004C0028 *)(D_001A4BE0 + 0x160 + 0x880);
    } else if (state == 0x11) {
        char *target = D_001A4BE0 + 0x190;

        ((Hero_004C0028 *)D_001A4BE0)->f[0x1A0 / 4] = ((Hero_004C0028 *)D_001A4BE0)->f[0x4CC / 4];
        ((Hero_004C0028 *)D_001A4BE0)->q[0x190 / 16] = ((Hero_004C0028 *)D_001A4BE0)->q[0x4C0 / 16];
        if (((Hero_004C0028 *)D_001A4BE0)->i[0x1B8 / 4] >= 8) {
            func_L01_004EEDD0(-1, 0.060480002f, 0.28800002f, 0.23736478f);
        }
        if (((Hero_004C0028 *)D_001A4BE0)->i[0x1B8 / 4] >= 7) {
            if (((Hero_004C0028 *)D_001A4BE0)->h[0x368 / 2] == 0) {
                ((Hero_004C0028 *)D_001A4BE0)->f[0xF0 / 4] = func_0038D098(((Hero_004C0028 *)D_001A4BE0)->f[0x1A0 / 4]) * 0.09800001f;
                ((Hero_004C0028 *)D_001A4BE0)->f[0xF4 / 4] = func_0038D0B0(((Hero_004C0028 *)D_001A4BE0)->f[0x1A0 / 4]) * 0.09800001f;
            } else {
                    func_L01_00511588(D_001A4BE0 + 0xF0, D_001A4BE0 + 0xF0, 0.0f);
                func_0038CF68(&v0, target, 0.09800001f);
                vec_add_ab(D_001A4BE0 + 0xF0, D_001A4BE0 + 0xF0, &v0);
            }
        }
        ((Hero_004C0028 *)D_001A4BE0)->f[0x1B4 / 4] = ((Hero_004C0028 *)D_001A4BE0)->f[0x174 / 4];
    } else if (state == 0x86 && D_L30_001D673C == 0) {
        func_L01_004EEDD0(0, 0.057600003f, 0.28800002f, ((Hero_004C0028 *)D_001A4BE0)->f[0x464 / 4]);
        ((Hero_004C0028 *)D_001A4BE0)->f[0x1B4 / 4] = 0.0f;
    } else {
        f32 speed;

        if (((Hero_004C0028 *)D_001A4BE0)->i[0x25C4 / 4] == 0x2C) {
            f32 r;

            a50 = ((Hero_004C0028 *)D_001A4BE0)->f[0x98 / 4];
            ((Hero_004C0028 *)D_001A4BE0)->f[0x1A8 / 4] = func_L01_00448728(&a50, ((Hero_004C0028 *)D_001A4BE0)->f[0x1A0 / 4], D_001A4BE0 + 0x1A4, 0.02592f, 0.28800002f, 0.14660767f, 0);
            r = func_0038DB00(a50, ((Hero_004C0028 *)D_001A4BE0)->f[0x98 / 4]);
            func_L01_004E5290(0.0f, 0.0f, r);
        } else {
            f32 a;

            v0 = *(V4_004C0028 *)(D_001A4BE0 + 0x190);
            a = ((Hero_004C0028 *)D_001A4BE0)->f[0x1A0 / 4];

            if (((Hero_004C0028 *)D_001A4BE0)->h[0x1434 / 2] != 0
                || (((Hero_004C0028 *)D_001A4BE0)->i[0x16B0 / 4] == 1 && func_L01_004606E8(0x28, 2, 0, 0) != 0)) {
                ((Hero_004C0028 *)D_001A4BE0)->f[0x1A0 / 4] = D_L30_001E22C0.x18;
                ((Hero_004C0028 *)D_001A4BE0)->q[0x190 / 16] = D_L30_001E22C0.x380;
            }
            func_L01_004EEDD0(0, 0.057600003f, 0.28800002f, ((Hero_004C0028 *)D_001A4BE0)->f[0x464 / 4]);
            if (((Hero_004C0028 *)D_001A4BE0)->h[0x1434 / 2] != 0
                || (((Hero_004C0028 *)D_001A4BE0)->i[0x16B0 / 4] == 1 && func_L01_004606E8(0x28, 2, 0, 0) != 0)) {
                ((Hero_004C0028 *)D_001A4BE0)->f[0x1438 / 4] = a;
                ((Hero_004C0028 *)D_001A4BE0)->q[0x1420 / 16] = *(u128_004C0028 *)&v0;
                ((Hero_004C0028 *)D_001A4BE0)->f[0x1A0 / 4] = a;
                ((Hero_004C0028 *)D_001A4BE0)->q[0x190 / 16] = *(u128_004C0028 *)&v0;
            }
        }
        speed = 0.008f;
        func_L01_004F0558(0.7f, 0.0f);
        *(u128_004C0028 *)(D_001A4BE0 + 0x160) = *(u128_004C0028 *)(D_001A4BE0 + 0x160 + 0x880);
        if (((Hero_004C0028 *)D_001A4BE0)->f[0x1B0 / 4] < D_L30_001DBCA8 * 0.020000001f * 0.2f) {
            if (((Hero_004C0028 *)D_001A4BE0)->i[0x25CC / 4] == 2) {
                f32 rate;

                rate = ((Hero_004C0028 *)D_001A4BE0)->f[0xA04 / 4];
                if (((Hero_004C0028 *)D_001A4BE0)->b[0x1474] != 0) {
                    rate = 6.8e-05f;
                }
                a54 = func_L01_00511408(D_001A4BE0 + 0xF0);
                func_003C4138(&a54, 0.0f, rate);
                func_L01_00511588(D_001A4BE0 + 0xF0, D_001A4BE0 + 0xF0, a54);
                return;
            }
            if (((Hero_004C0028 *)D_001A4BE0)->h[0x36A / 2] != 0) {
                speed = 0.0044f;
            } else if (((Hero_004C0028 *)D_001A4BE0)->h[0x4F4 / 2] != 0) {
                speed = 0.00080000004f;
            } else {
                speed = 0.0032000002f;
            }
        }
        if (((Hero_004C0028 *)D_001A4BE0)->h[0x4F8 / 2] != 0 && ((Hero_004C0028 *)D_001A4BE0)->b[0x1474] != 0) {
            speed = 0.00020000001f;
            if (((Hero_004C0028 *)D_001A4BE0)->f[0x2838 / 4] > 0.9f) {
                func_L01_004EF6F0(&v0, &v10, 0.5f, -1.5f, 0);
                v0.x += func_0038D098(((Hero_004C0028 *)D_001A4BE0)->f[0x1A0 / 4]) * 0.7f;
                v0.y += func_0038D0B0(((Hero_004C0028 *)D_001A4BE0)->f[0x1A0 / 4]) * 0.7f;
                v10.x += func_0038D098(((Hero_004C0028 *)D_001A4BE0)->f[0x1A0 / 4]) * 0.7f;
                v10.y += func_0038D0B0(((Hero_004C0028 *)D_001A4BE0)->f[0x1A0 / 4]) * 0.7f;
                if (func_003D3CB0(&v0, &v10, 2, 0, 0) != 0 && func_003D5630() != 7) {
                    ((Hero_004C0028 *)D_001A4BE0)->f[0x1B0 / 4] = 0.10000001f;
                    speed = 0.004f;
                }
            }
            if (((Hero_004C0028 *)D_001A4BE0)->i[0x25C4 / 4] == 0xF) {
                speed = 0.0012f;
                func_L30_004BCB20(0, 0.050000004f);
            }
            if (((Hero_004C0028 *)D_001A4BE0)->f[0x340 / 4] > 0.2617994f) {
                ((Hero_004C0028 *)D_001A4BE0)->f[0x1B0 / 4] = 0.0f;
                speed = ((Hero_004C0028 *)D_001A4BE0)->f[0x340 / 4] * 0.0036000002f / 0.7853982f;
            }
        }
        func_L01_004F1220(speed);
    }
}
/* localdecomp:end func_L30_004C0028 */
