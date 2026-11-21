#include "common.h"

/* NTSC-U counterpart of func_L14_0035D670 (src/levels/14_koros/L14_0035D670.c) */
/* localdecomp:start func_L14_0035C620 */
#include "vu0.h"
typedef struct {
    u8 pad[0x10];
    u8 *p10;
} S_0035D670;
__asm__(".extern D_L14_001DD720, 4");
__asm__(".extern D_L14_001DD728, 4");
__asm__(".extern D_L14_001DD72C, 4");
__asm__(".extern D_L14_001DD730, 4");
__asm__(".extern D_L14_001DD734, 4");
__asm__(".extern D_L14_001DD738, 4");
__asm__(".extern D_L14_001DD73C, 4");
__asm__(".extern D_L14_001DD740, 4");
__asm__(".extern D_L14_001DD744, 4");
__asm__(".extern D_L14_001DD748, 4");
__asm__(".extern D_L14_001DD74C, 4");
__asm__(".extern D_L14_001DD750, 4");
__asm__(".extern D_L14_001DD754, 4");
__asm__(".extern D_L14_001DD758, 4");
extern s32 D_L14_001DD720;
extern s32 D_L14_001DD728;
extern s32 D_L14_001DD72C;
extern s32 D_L14_001DD730;
extern s32 D_L14_001DD734;
extern s32 D_L14_001DD738;
extern f32 D_L14_001DD73C;
extern f32 D_L14_001DD740;
extern f32 D_L14_001DD744;
extern f32 D_L14_001DD748;
extern f32 D_L14_001DD74C;
extern f32 D_L14_001DD750;
extern f32 D_L14_001DD754;
extern f32 D_L14_001DD758;
extern S_0035D670 D_L14_0021F958_0035C620;
extern void func_003886E8(void *, void *, f32);
extern void func_003888C8(void *, void *, void *);
extern void func_0037E2F0(void *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_0046CF70(void *, void *, s32, f32);
void func_L14_0035C620(u8 *a0, s32 dir) {
    vu0_v4 v;
    vu0_v4 r;
    vu0_v4 d0 = { D_L14_001DD748, 0.0f, D_L14_001DD744 };
    vu0_v4 d1 = { 0.0f, D_L14_001DD748, D_L14_001DD744 };
    vu0_v4 d2 = { -D_L14_001DD748, 0.0f, D_L14_001DD744 };
    vu0_v4 d3 = { 0.0f, -D_L14_001DD748, D_L14_001DD744 };
    vu0_v4 w;
    vu0_v4 d;
    vu0_q qp1, qp2, qv, qw;
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *e;
    f32 t;
    f32 x;
    s32 i;
    s32 k;
    s32 n;
    s32 alpha;
    s32 col;
    switch (dir) {
    case 0:
        v = d0;
        break;
    case 1:
        v = d1;
        break;
    case 2:
        v = d2;
        break;
    case 3:
        v = d3;
        break;
    }
    t = *(f32 *)(a0 + 0x2C) / D_L14_001DD74C;
    func_003886E8(&v, &v, t);
    func_003888C8(&v, &v, a0 + 0xC0);
    __asm__("lqc2 %0, %1" : "=j"(qp1) : "m"(*(vu0_v4 *)(a0 + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(qp2) : "m"(*(vu0_v4 *)(a0 + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(qv) : "m"(v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qv) : "j"(qv), "j"(qp1));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(qv));
    *(vu0_q *)&d = 0;
    d.z = D_L14_001DD744 * t;
    w = d;
    __asm__("lqc2 %0, %1" : "=j"(qw) : "m"(w));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qw) : "j"(qw), "j"(qp2));
    __asm__("sqc2 %1, %0" : "=m"(w) : "j"(qw));
    n = *(s32 *)(s + 0x44);
    if (n < 50) {
        alpha = (u8)(s32)((f32)n * 127.0f / 50.0f);
    } else {
        alpha = 0x7F;
    }
    for (i = 0; i < D_L14_001DD720; i++) {
        vec_sub_ba(&d, &v, &w);
        x = D_L14_001DD750 * t;
        func_0037E2F0(&r, x * 0.5f, x);
        vec_add_ab(&r, &r, &d);
        func_00388830(&r, &r, func_0037E250(D_L14_001DD754 * 0.5f, D_L14_001DD754) * 0.016666668f);
        col = func_0037E1D8(4) ? D_L14_001DD738 : D_L14_001DD730;
        col |= alpha << 24;
        k = func_0037E208(-2, 2);
        e = func_L01_00472438(&v, &r, D_L14_001DD728, k, col, D_L14_001DD734, 0, D_L14_001DD73C * 210000.0f, D_L14_001DD740 * 210000.0f,
                              func_0037E250(D_L14_001DD758 * 0.3f, D_L14_001DD758));
        if (e != 0) {
            e[2] = D_L14_0021F958_0035C620.p10[0];
            e[3] = func_0037E1D8(2) ? 0x48 : 0x44;
        }
    }
    if (func_0037E1D8(6) == 0) {
        func_L01_0046CF70(&v, &r, func_0037E208(D_L14_001DD72C - 5, D_L14_001DD72C), func_0037E250(40.0f, 80.0f) * 0.00027777778f);
    }
}
/* localdecomp:end func_L14_0035C620 */
