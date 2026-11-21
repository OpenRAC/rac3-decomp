#include "common.h"

/* NTSC-U counterpart of func_L01_003D8E60 (src/levels/shared/L01_003D8DA0.c) */
/* localdecomp:start func_L01_003D72E0 */
#include "vu0.h"

extern f32 D_L01_001DF520_003D72E0;
__asm__(".extern D_L01_001DF520_003D72E0, 4");
extern f32 D_L01_001DF524_003D72E0;
__asm__(".extern D_L01_001DF524_003D72E0, 4");
extern u8 D_L01_001DF52C_003D72E0;
__asm__(".extern D_L01_001DF52C_003D72E0, 1");
extern s32 D_L01_001DF530_003D72E0;
__asm__(".extern D_L01_001DF530_003D72E0, 4");
extern u8 *D_L01_00221118_003D72E0[];
extern s32 func_L01_004562A0_003D72E0(void *, s32, f32);
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern u8 *func_L01_0046C468_003D72E0(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern u8 *func_L01_00472438_003D72E0(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_003D7220_003D72E0(void *);
extern void func_L01_003D7100_003D72E0(void *);

void func_L01_003D72E0(void *pos, void *vel, s32 a2, s32 a3, s32 a4, s32 count, s32 size, s32 a7, f32 height, f32 r, f32 f) {
    vu0_v4 sphere;
    vu0_v4 p;
    vu0_v4 v;
    u8 *e;
    vu0_q qv;
    s32 tag;
    s32 i;
    f32 s;

    *(vu0_q *)&sphere = *(vu0_q *)pos;
    sphere.w = r + r;
    s = 128.0f;
    if (size > 0x40) {
        s = size;
    }
    if (func_L01_004562A0_003D72E0(&sphere, 0, s) < 0) {
        return;
    }
    if (count > 0) {
        tag = (size >> 5) * 16 + 2;
        for (i = count; i != 0; i--) {
            vu0_q qa;

            func_0037E2F0(&p, r * 0.15f, r * 0.4f);
            vec_add_ab(&p, &p, pos);
            __asm__("lqc2 %0, %1" : "=j"(qv) : "m"(*(vu0_v4 *)vel));
            qzero(&v);
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(v));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qv));
            __asm__("sqc2 %1, %0" : "=m"(v) : "j"(qa));
            if (a7 == 0 || func_0037E1D8(a7)) {
                e = func_L01_0046C468_003D72E0(&p, &v, a2, 0x808080, func_0037E208(-5, 5), D_L01_001DF52C_003D72E0, 0, 0,
                                      D_L01_001DF520_003D72E0 * r * 210000.0f, D_L01_001DF524_003D72E0 * r * 210000.0f,
                                      func_0037E250(f * 0.00027777778f, -0.00055555557f));
                if (e != 0) {
                    e[9] = tag;
                    if (a7 == 0 && func_0037E1D8(D_L01_001DF530_003D72E0)) {
                        e[2] = D_L01_00221118_003D72E0[91][0];
                        e[3] = 0x48;
                    } else {
                        e[2] = D_L01_00221118_003D72E0[91][4];
                        e[3] = func_0037E1D8(4) ? 0x44 : 0x48;
                    }
                }
            } else {
                u8 *e2;

                r *= 0.8f;
                e2 = func_L01_00472438_003D72E0(&p, &v, a2, func_0037E208(-1, 2), 0x7F407FFF, 0x407FFF,
                                      D_L01_001DF524_003D72E0 * r * 210000.0f, D_L01_001DF524_003D72E0 * r * 210000.0f,
                                      func_0037E250(f * 1.5f, f), 0);
                if (e2 != 0) {
                    e2[9] = tag;
                    e2[2] = D_L01_00221118_003D72E0[97][3];
                }
            }
        }
    }
    if (height == -100000.0f || height + 2.0f < ((f32 *)pos)[2]) {
        if (a3 != 0 && !func_0037E1D8(10 - a3)) {
            func_L01_003D7220_003D72E0(pos);
        }
        if (a4 != 0 && !func_0037E1D8(20 - a4)) {
            func_L01_003D7100_003D72E0(pos);
        }
    }
}
/* localdecomp:end func_L01_003D72E0 */
