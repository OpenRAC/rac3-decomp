#include "common.h"

/* localdecomp:start func_L39_005720D8 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x20];
    u8 *a20[4];
    u8 pad30[0x10];
    s32 a40[4];
    s32 a50[4];
    u8 pad60[0x40];
    f32 aA0[4];
    u8 padB0[0x30];
    f32 aE0[4];
    s32 aF0[4];
} I_005720D8;
__asm__(".extern D_L39_0024B850, 16");
extern u8 *D_L39_0024B850;
extern vu0_v4 D_L39_00474840[];
extern u8 D_L39_0025F740[];
__asm__(".extern D_L39_0024B778, 8");
extern f32 D_L39_0024B778[] __attribute__((section(".sdata")));
extern u8 *func_L39_0061BF38(s32);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern u8 *func_00382348(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern f32 func_0038CED8(void *);
extern void func_0038CE90(void *, void *, void *);

void func_L39_005720D8(u8 *a0) {
    s32 idx;
    u8 *p;
    u8 *m;
    I_005720D8 *info;
    u8 *v;
    u8 *t;
    u8 *r;
    u8 *g;
    u8 *e;
    f32 *h;
    vu0_v4 mat[4];
    vu0_v4 d;
    vu0_v4 pos;
    vu0_v4 up;

    idx = *(s32 *)(a0 + 0x94);
    *(vu0_q *)&up = 0;
    up.z = 1.0f;
    up.w = 1.0f;
    p = func_L39_0061BF38(idx);
    m = *(u8 **)(a0 + 0x70);
    h = (f32 *)(m + 0x90);
    info = *(I_005720D8 **)(D_L39_0024B850 + *(s16 *)(a0 + 0x84) * 0x20 + 0x1C);
    *(s32 *)(m + 0x94) = 0;
    *(s32 *)(m + 0x98) = 0;
    info->aA0[idx] = 90.0f;
    v = m + 0x70;
    if (*(u8 **)(p + 0x2528) != 0) {
        t = *(u8 **)(*(u8 **)(p + 0x2528) + 0x2D0);
        info->a20[idx] = t;
        *(vu0_v4 *)(m + 0x70) = D_L39_00474840[*(s16 *)(*(u8 **)(p + 0x2528) + 0x2FC)];
        *h = D_L39_0024B778[*(s16 *)(*(u8 **)(p + 0x2528) + 0x2FC)];
        *(f32 *)(v + 0x10) = func_0038CEA8(v);
    } else {
        qzero(m + 0x70);
        *(f32 *)(v + 0x10) = 0.0f;
        *h = 0.0f;
        t = *(u8 **)(p + 0x2524);
    }
    func_0038CE20(&mat[0], t + 0xC0, -1.0f);
    func_0038CE20(&mat[1], t + 0xD0, -1.0f);
    e = t + 0xE0;
    mat[2] = *(vu0_v4 *)e;
    mat[3] = *(vu0_v4 *)(t + 0x10);
    info->aE0[idx] = *(f32 *)(t + 0x18);
    info->aF0[idx] = 0;
    func_0038D028(a0 + 0x30, v, mat);
    qzero(&pos);
    r = func_00382348(t);
    if (r != 0) {
        func_0038CE20(&pos, e, *(f32 *)(r + 0x10));
    }
    vec_add_ab(&pos, &pos, t + 0x10);
    if (func_003D3CB0(&pos, a0 + 0x30, 4, 0, 0) != 0) {
        g = D_L39_0025F740;
        if (*(u8 **)(g + 0x18) == 0 || *(s16 *)(*(u8 **)(g + 0x18) + 0xAA) == 0x1AD6) {
            vec_sub_ba(&d, &pos, g + 0x20);
            func_0038CF68(&up, &d, 0.02f);
            vec_add_ab(a0 + 0x30, g + 0x20, &up);
        }
    }
    if (func_L01_003FB640(a0 + 0x30, 4, 0, 0.15f) != 0) {
        u8 *g2 = D_L39_0025F740;
        if (*(u8 **)(g2 + 0x18) == 0 || *(s16 *)(*(u8 **)(g2 + 0x18) + 0xAA) == 0x1AD6) {
            *(vu0_v4 *)(a0 + 0x30) = *(vu0_v4 *)(g2 + 0x30);
        }
    }
    vec_sub_ba(v, a0 + 0x30, t + 0x10);
    *(f32 *)(v + 0x10) = func_0038CED8(v);
    d = *(vu0_v4 *)(t + 0x10);
    d.z = d.z + *h;
    vec_sub_ba(a0, &d, a0 + 0x30);
    func_0038CF68(a0, a0, 1.0f);
    func_0038CE90(a0 + 0x10, a0, &up);
    func_0038CF68(a0 + 0x10, a0 + 0x10, 1.0f);
    func_0038CE90(a0 + 0x20, a0 + 0x10, a0);
    info->a40[idx] = 0;
    info->a50[idx] = 0;
}
/* localdecomp:end func_L39_005720D8 */
