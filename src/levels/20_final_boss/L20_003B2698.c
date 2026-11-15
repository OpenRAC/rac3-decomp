#include "common.h"

/* localdecomp:start func_L20_003B2698 */
#include "vu0.h"
typedef int q_003B2698 __attribute__((mode(TI)));
typedef struct { vu0_v4 pos; u8 pad1[0x1910 - 0x10]; u8 *x1910; } H_003B2698;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad1[0xE0]; } M_003B2698;
extern H_003B2698 D_001A4CB0;
extern M_003B2698 *D_L20_001E029C;
__asm__(".extern D_L20_001E029C, 16");
extern vu0_v4 D_L20_001E9BE0;
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4098(void *, void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0040A8C0(void *, void *, s32, s32, f32, f32, f32, u32, u32, u32, u32);
extern f32 func_00382538(void);
extern void func_003D9508(void *p, s32 a, u32 color, s32 b, f32 f0, f32 f1, f32 f2);

void func_L20_003B2698(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 pos;
    vu0_v4 mtx[4];
    vu0_v4 off;
    vu0_v4 res;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 tgt;
    u8 *p;
    f32 s;

    func_003C2EC0(*(void **)(v + 0x2E0), 1, mtx);
    func_0038CF68(&off, mtx, 3.0f);
    vec_add_ab(&pos, &mtx[3], &off);
    tgt = D_001A4CB0.pos;
    p = D_001A4CB0.x1910;
    if (p == 0) {
        M_003B2698 *m = &D_L20_001E029C[*(s32 *)(v + 0x2DC)];
        tgt = m->pos;
    }
    vec_sub_ba(&d, v + 0x300, &pos);
    vec_sub_ab(&e, &tgt, &pos);
    if (p != 0 && *(s16 *)(p + 0xAA) == 0x107E) {
        func_003C4098(&d, &d, &e, 0.06f);
    } else {
        func_003C4098(&d, &d, &e, 0.1f);
    }
    func_0038CF68(&d, &d, *(f32 *)(v + 0x2F8) * 120.0f);
    vec_add_ab(&d, &d, &pos);
    if (func_003D3CB0(&pos, &d, 2, a0, 0)) {
        res = D_L20_001E9BE0;
        *(vu0_v4 *)(v + 0x300) = res;
    } else {
        res = d;
        *(vu0_v4 *)(v + 0x300) = res;
    }
    *(f32 *)(v + 0x2F0) -= func_003824E0(0.025f, 0.035f);
    if (*(f32 *)(v + 0x2F0) <= -8.0f) {
        *(f32 *)(v + 0x2F0) += 8.0f;
    }
    func_L01_0040A8C0(&pos, &res, 14, 0, *(f32 *)(v + 0x2FC), 0.5f, *(f32 *)(v + 0x2F0),
                      0x4F802060, 0x4F802060, 0x4F802060, 0x4F802060);
    func_L01_0040A8C0(&pos, &res, 14, 3, *(f32 *)(v + 0x2FC) * 0.5f, 0.5f, -*(f32 *)(v + 0x2F0),
                      0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF);
    s = *(f32 *)(v + 0x2F4) * 0.5f;
    func_003D9508(&res, 0x31, 0x60808080, 3, s, 0.08f, func_00382538());
    *(vu0_v4 *)(v + 0x310) = res;
}
/* localdecomp:end func_L20_003B2698 */
