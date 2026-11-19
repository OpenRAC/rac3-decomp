/* functional: medium. 267 instructions differ (scheduling and register use); packet-building order follows retail; gp-relative data named by address; func_00382468 assumed to take only 0xFF. */
#include "vu0.h"
extern s32 D_L01_001DEE5C_003C8400;
__asm__(".extern D_L01_001DEE5C_003C8400, 4");
extern s32 D_L01_001DEE60_003C8400;
__asm__(".extern D_L01_001DEE60_003C8400, 4");
extern s32 D_L01_001DEE64_003C8400;
__asm__(".extern D_L01_001DEE64_003C8400, 4");
extern s32 D_L01_001DEE68_003C8400;
__asm__(".extern D_L01_001DEE68_003C8400, 4");
extern s32 D_L01_001DEE78_003C8400;
__asm__(".extern D_L01_001DEE78_003C8400, 4");
extern s32 D_L01_001DEE7C_003C8400;
__asm__(".extern D_L01_001DEE7C_003C8400, 4");
extern f32 D_L01_001DEE70_003C8400;
__asm__(".extern D_L01_001DEE70_003C8400, 4");
extern f32 D_L01_001DEE74_003C8400;
__asm__(".extern D_L01_001DEE74_003C8400, 4");
extern f32 D_L01_001DEE80_003C8400;
__asm__(".extern D_L01_001DEE80_003C8400, 4");
extern u8 D_L01_001DEE90[];
extern f32 D_L01_001DEEA0[];
extern vu0_v4 D_L01_001DEEB0[];
extern f32 D_L01_001DEEF0[];
extern f32 D_L01_001DEF10[];
extern s32 D_L01_001DFB40;
extern vu0_v4 D_L01_002BB450[];
extern f32 D_L01_001E2240[];
extern s32 D_L01_001E2270[];
extern f32 D_L01_001E2280[];
extern u8 D_L01_001E29C0[];
extern u8 D_L01_001E29E0[];
extern void func_003A9440(s32, unsigned long);
extern void func_0038C750(void);
extern u8 func_00382468(s32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(f32 *, f32 *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_0038CC88(void *, void *, s32);
extern s32 func_00389598(s32);
extern void func_003D3A24(s32, void *, void *, void *, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_00389478(void *, void *, void *);

void func_L01_003C8400(u8 *obj, u8 *s) {
    vu0_v4 base, off, v30, quad, corners[4];
    s32 i, j, k;
    s32 phase0;
    s32 q;
    func_003A9440(8, 5);
    func_003A9440(0x14, 0xFF90UL << 32 | 0x260);
    func_003A9440(0x47, 0x513F1);
    func_0038C750();
    q = D_L01_001DEE78_003C8400 / D_L01_001DEE7C_003C8400;
    phase0 = (D_L01_001DFB40 + q) % D_L01_001DEE78_003C8400;
    phase0 = D_L01_001DFB40 + phase0 / q * q;
    for (i = 0; i < 6; i++) {
        u8 **slot = (u8 **)(s + 0x58) + i;
        vu0_v4 *src = &D_L01_002BB450[i];
        if (*slot) {
            (*slot)[8] = func_00382468(0xFF);
        }
        func_0038D000(&base, src, obj + 0xC0);
        vec_add_ab(&base, &base, obj + 0x10);
        for (j = 0; j < D_L01_001DEE7C_003C8400; j++) {
            f32 phase, fx;
            s32 color;
            f32 w;
            phase = (f32)((phase0 + D_L01_001DEE78_003C8400 / D_L01_001DEE7C_003C8400 * j) % D_L01_001DEE78_003C8400) /
                    (f32)D_L01_001DEE78_003C8400;
            func_0038D000(&off, ((f32 *)src)[1] > 0.0f ? (void *)D_L01_001DEE90 : (void *)D_L01_001DEEA0, obj + 0xC0);
            func_0038CE20((f32 *)&off, (f32 *)&off, phase);
            vec_add_ab(&v30, &base, &off);
            color = func_0038DBD8(D_L01_001DEE5C_003C8400, D_L01_001DEE60_003C8400, phase);
            for (k = 0; k < 4; k++) {
                *(vu0_q *)&quad = *(vu0_q *)&D_L01_001DEEB0[k];
                D_L01_001E2270[k] = color;
                w = D_L01_001DEE80_003C8400 * phase + 1.0f;
                ((f32 *)&quad)[1] *= w;
                ((f32 *)&quad)[2] *= w;
                func_0038D000(&corners[k], &quad, D_L01_001E29E0);
                vec_add_ab(&corners[k], &corners[k], &v30);
                func_0038CC88(&D_L01_001E2240[k * 3], &corners[k], 12);
                D_L01_001E2280[k * 2] = D_L01_001DEEF0[k * 2];
                D_L01_001E2280[k * 2 + 1] = D_L01_001DEEF0[k * 2 + 1];
            }
            func_003A9440(6, func_00389598(0x3B));
            func_003A9440(0x42, 0x8000006AUL);
            func_003D3A24(4, D_L01_001E2240, D_L01_001E2270, D_L01_001E2280, 1);
            fx = D_L01_001DEE70_003C8400 / (func_0038CF00(&v30, D_L01_001E29C0) + 1.0f);
            if (D_L01_001DEE74_003C8400 < fx) fx = D_L01_001DEE74_003C8400;
            else if (fx < -D_L01_001DEE74_003C8400) fx = -D_L01_001DEE74_003C8400;
            color = func_0038DBD8(D_L01_001DEE64_003C8400, D_L01_001DEE68_003C8400, phase);
            for (k = 0; k < 4; k++) {
                D_L01_001E2270[k] = color;
                func_00389478(&corners[k], &D_L01_001E2280[k * 2], &D_L01_001E2280[k * 2 + 1]);
                D_L01_001E2280[k * 2] += D_L01_001DEF10[k * 2] * fx;
                D_L01_001E2280[k * 2 + 1] += D_L01_001DEF10[k * 2 + 1] * fx;
            }
            func_003A9440(6, func_00389598(-1));
            func_003A9440(0x42, 0x80000054UL);
            func_003D3A24(4, D_L01_001E2240, D_L01_001E2270, D_L01_001E2280, 1);
        }
    }
}
