/* functional: high. Checked at L04 with -mvu0-use-vf0-vf2 added (file's flag line lacks it; needs #include vu0.h): block bodies, calls, constants (0.10000001f, 0.02f, 1.5, 3.0) and offsets match the assembly; ~243 diff lines come from block layout (retail puts the state-1/2 setup in the dispatch delay slot) and one callee-saved register (s2 vs s1) shifting everything. The NTSC-U draft nonmatching/levels/func_L04_00500298.c is a different-code twin; this C is rewritten from the PAL assembly (callees are func_0038D098/D0B0, 0038CED8, L01_00511508/408/588, 0038CFB8 here). */
/* localdecomp:start func_L04_00500298 */
#include "vu0.h"
typedef int s128_00500298 __attribute__((mode(TI)));
typedef union { u8 b[0x2700]; s16 h[0x1380]; s32 i[0x9C0]; f32 f[0x9C0]; } Hero_00500298;
extern u8 D_001A4BE0[];
extern u8 D_001A4CD0[];
extern u8 D_001A4D70[];
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CED8(void *);
extern void func_0038CFB8(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_L01_004F05F0(void *);
extern void func_L01_00511508(void *, void *, f32);
extern f32 func_L01_00511408(void *);
extern void func_L01_00511588(void *, void *, f32);
extern s32 func_L01_004606E8(s32, s32, s32, s32);

void func_L04_00500298(f32 amount) {
    vu0_v4 v;
    vu0_v4 tmp;
    vu0_v4 v2;
    f32 angle;
    f32 speed;
    f32 dot;
    f32 l1;
    f32 l2;
    s32 state = ((Hero_00500298 *)D_001A4BE0)->b[0x25F4];
    if (state == 0) {
        angle = ((Hero_00500298 *)D_001A4BE0)->f[0x1A0 / 4];
        speed = ((Hero_00500298 *)D_001A4BE0)->f[0x1B0 / 4];
        if (((Hero_00500298 *)D_001A4BE0)->i[0x25CC / 4] == 4) {
            if (((Hero_00500298 *)D_001A4BE0)->h[0x4F4 / 2] != 0 && ((Hero_00500298 *)D_001A4BE0)->b[0x2A7] != 0) {
                speed = 0.100000009f;
            }
        }
        if (((Hero_00500298 *)D_001A4BE0)->h[0x36A / 2] != 0) {
            if (((Hero_00500298 *)D_001A4BE0)->i[0x25C4 / 4] == 0xE) {
                if (0.020000001f < speed) {
                    speed = 0.020000001f;
                }
            }
        }
        v.x = func_0038D098(angle) * speed;
        v.y = func_0038D0B0(angle) * speed;
        v.z = ((Hero_00500298 *)D_001A4BE0)->f[0xF8 / 4];
        dot = -(((Hero_00500298 *)D_001A4BE0)->f[0xF0 / 4] * v.x + ((Hero_00500298 *)D_001A4BE0)->f[0xF4 / 4] * v.y);
        l1 = func_0038CED8(&v);
        l2 = func_0038CED8(D_001A4BE0 + 0xF0);
        if (l1 == 0.0f || l2 == 0.0f) {
            dot = 0.0f;
        } else {
            dot = dot / l1 / l2;
        }
        if (((Hero_00500298 *)D_001A4BE0)->i[0x25C4 / 4] == 0xB0) {
            dot = dot + 0.5f;
        } else {
            dot = (dot + 1.0f) * 1.5f;
        }
        if (3.0f < dot) {
            dot = 3.0f;
        }
        if (dot < 1.0f) {
            dot = 1.0f;
        }
        amount = amount * dot;
        vec_sub_ab(&v, &v, D_001A4CD0);
        if (amount < func_0038CED8(&v)) {
            func_0038CFB8(&v, &v, amount);
        }
        vec_add_ab(D_001A4CD0, D_001A4CD0, &v);
        *(s128_00500298 *)&tmp = *(s128_00500298 *)(D_001A4BE0 + 0x9E0);
        ((Hero_00500298 *)D_001A4BE0)->f[0x1B4 / 4] = ((Hero_00500298 *)D_001A4BE0)->f[0x178 / 4] - func_L01_004F05F0(&tmp);
    } else if (state >= 0 && state < 3) {
        *(s128_00500298 *)&tmp = *(s128_00500298 *)D_001A4D70;
        speed = *(f32 *)(D_001A4D70 + 0x20);
        func_L01_00511508(&v, &tmp, 0.0f);
        func_0038CF68(&v, &v, speed);
        func_L01_00511508(&v2, D_001A4D70 - 0xA0, 0.0f);
        dot = -func_0038CE68(&v2, &v);
        l1 = func_L01_00511408(&v);
        l2 = func_L01_00511408(D_001A4D70 - 0xA0);
        if (l1 == 0.0f || l2 == 0.0f) {
            dot = 0.0f;
        } else {
            dot = dot / l1 / l2;
        }
        dot = (dot + 1.0f) * 1.5f;
        if (3.0f < dot) {
            dot = 3.0f;
        }
        if (dot < 1.0f) {
            dot = 1.0f;
        }
        vec_sub_ab(&v, &v, D_001A4CD0);
        func_L01_00511508(&v, &v, 0.0f);
        amount = amount * dot;
        if (amount < func_L01_00511408(&v)) {
            func_L01_00511588(&v, &v, amount);
        }
        vec_add_ab(D_001A4CD0, D_001A4CD0, &v);
        ((Hero_00500298 *)D_001A4BE0)->f[0x1B4 / 4] = ((Hero_00500298 *)D_001A4BE0)->f[0x178 / 4];
    } else {
        return;
    }
    if (((Hero_00500298 *)D_001A4BE0)->h[0x1434 / 2] != 0) {
        ((Hero_00500298 *)D_001A4BE0)->f[0x1B4 / 4] = ((Hero_00500298 *)D_001A4BE0)->f[0x174 / 4];
    } else if (((Hero_00500298 *)D_001A4BE0)->i[0x16B0 / 4] == 1) {
        if (func_L01_004606E8(0x28, 2, 0, 0) != 0) {
            ((Hero_00500298 *)D_001A4BE0)->f[0x1B4 / 4] = ((Hero_00500298 *)D_001A4BE0)->f[0x174 / 4];
        }
    }
}
/* localdecomp:end func_L04_00500298 */
