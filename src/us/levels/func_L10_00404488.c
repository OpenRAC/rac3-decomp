#include "common.h"

/* NTSC-U counterpart of func_L10_004077E0 (src/levels/shared/L10_004077E0.c) */
extern void func_003BDA38(void *, s32, void *);
extern void func_003BF6A8(void *, f32);

/* localdecomp:start func_L10_00404488 */
#include "vu0.h"
typedef struct { u8 pad[0x168]; u8 *f168; } G_004077E0;
typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 pad3[0xD];
    vu0_v4 pos;
    vu0_v4 org;
} P_004077E0;
extern f32 func_0037E250(f32, f32);
extern void func_003BDA38(void *, s32, void *);
extern void func_003BF6A8(void *, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern P_004077E0 *func_L01_004708F8(void *, void *, s32, f32, f32, f32, f32, s32, s32, s32, s32);
extern G_004077E0 D_L10_0021EC18;
typedef struct {
    s16 lifeMax;
    s16 lifeMin;
    f32 size;
    f32 alpha;
    f32 speedMax;
    f32 speedMin;
    s32 color0;
    s32 color1;
} Cfg_004077E0;
extern Cfg_004077E0 D_L10_001D6CE8_00404488 __attribute__((section(".sdata")));

void func_L10_00404488(void *obj) {
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 v2;
    vu0_v4 v3;
    P_004077E0 *r;
    s32 i;
    s32 n;
    f32 sp;

    sp = func_0037E250(D_L10_001D6CE8_00404488.speedMin, D_L10_001D6CE8_00404488.speedMax) * 0.016666668f;
    if (obj == 0) {
        return;
    }
    func_003BDA38(obj, 0, &v0);
    qzero(&v1);
    func_003BF6A8(&v1, 0.2f);
    v1.z *= 0.25f;
    v3 = v1;
    vec_add_ab(&v1, &v0, &v1);
    for (i = 29; i >= 0; i--) {
        qzero(&v2);
        func_00388830(&v2, &v3, sp);
        func_003BF6A8(&v2, 0.0033333337f);
        n = func_0037E208(D_L10_001D6CE8_00404488.lifeMin, D_L10_001D6CE8_00404488.lifeMax);
        r = func_L01_004708F8(&v1, &v2, n, D_L10_001D6CE8_00404488.alpha, 1.0f, D_L10_001D6CE8_00404488.size, 1.0f,
                              D_L10_001D6CE8_00404488.color0, D_L10_001D6CE8_00404488.color1, n, 0);
        if (r != 0) {
            r->b2 = D_L10_0021EC18.f168[func_0037E1D8(2)];
            r->org = v1;
            func_00388830(&v2, &v2, D_L10_001D6CE8_00404488.size);
            vec_add_ab(&r->pos, &v1, &v2);
            r->pos.w = D_L10_001D6CE8_00404488.alpha;
            r->org.w = 1.0f;
        }
    }
}
/* localdecomp:end func_L10_00404488 */
