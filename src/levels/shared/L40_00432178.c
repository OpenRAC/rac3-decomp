#include "common.h"

/* localdecomp:start func_L40_00432178 */
#include "vu0.h"
typedef struct {
    vu0_v4 p0;
    vu0_v4 p10;
    vu0_v4 p20;
    vu0_v4 p30;
    s32 i40;
    u8 pad44[8];
    f32 f4C;
} S_00432178;
extern s32 D_L40_00247A60;
__asm__(".extern D_L40_00247A60, 4");
extern s32 D_L40_00247A80;
__asm__(".extern D_L40_00247A80, 4");
extern s32 D_L40_00247A84;
__asm__(".extern D_L40_00247A84, 4");
extern s32 D_L40_00247A88;
__asm__(".extern D_L40_00247A88, 4");
extern s32 D_L40_00247A8C;
__asm__(".extern D_L40_00247A8C, 4");
extern s32 D_L40_00247A90;
__asm__(".extern D_L40_00247A90, 4");
extern s32 D_L40_00247A64[];
extern s32 D_L40_00247A68[];
extern s32 D_L40_00247A6C[];
extern s32 D_L40_00247A70[];
extern s32 D_L40_00247A74[];
extern s32 D_L40_00247A78[];
extern s32 D_L40_00247A7C[];
extern f32 func_0038D0B0(f32);
extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_L39_005B44C8(void);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern void func_003C2F58(s32, s32, void *);
extern void func_L01_0040A8C0(void *, void *, s32, s32, f32, f32, f32, s32, s32, s32, s32);

void func_L40_00432178(u8 *a0) {
    S_00432178 *s = *(S_00432178 **)(a0 + 0x68);
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 v2;
    vu0_v4 v3;
    f32 c;
    s32 col;

    c = func_0038D0B0(s->f4C * 3.1415927f);
    vec_add_ba(&v0, &s->p0, &s->p10);
    func_0038CDF8((f32 *)&v0, (f32 *)&s->p0, (f32 *)&v0, c);
    vec_add_ba(&v1, &s->p20, &s->p30);
    func_0038CDF8((f32 *)&v1, (f32 *)&s->p20, (f32 *)&v1, c);
    func_0038CDF8((f32 *)&v2, (f32 *)&v0, (f32 *)&v1, s->f4C);
    col = func_0038DBD8(D_L40_00247A60, D_L40_00247A64[0], func_L39_005B4410(0.0f, 1.0f));
    func_003D9508(&v2, 0x31, col, 1, 1.0f, 0.0f, func_L39_005B44C8());
    col = func_0038DBD8(D_L40_00247A68[0], D_L40_00247A6C[0], func_L39_005B4410(0.0f, 1.0f));
    func_003D9508(&v2, 0x31, col, 1, 0.6f, 0.0f, func_L39_005B44C8());
    col = func_0038DBD8(D_L40_00247A70[0], D_L40_00247A74[0], func_L39_005B4410(0.0f, 1.0f));
    func_003D9508(&v2, 0xB, col, 1, 1.4f, 0.0f, func_L39_005B44C8());
    col = func_0038DBD8(D_L40_00247A78[0], D_L40_00247A7C[0], func_L39_005B4410(0.0f, 1.0f));
    func_003D9508(&v2, 0xB, col, 1, 0.9f, 0.0f, func_L39_005B44C8());
    func_003C2F58(s->i40, 0, &v3);
    func_L01_0040A8C0(&v3, &v2, D_L40_00247A90, 1, 0.05f, 0.5f, 0.0f,
                      D_L40_00247A80, D_L40_00247A84, D_L40_00247A88, D_L40_00247A8C);
}
/* localdecomp:end func_L40_00432178 */
