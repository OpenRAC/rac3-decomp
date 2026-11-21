#include "common.h"

typedef struct { u8 pad[0x34]; s32 frame; } S_Game;
typedef struct { u8 pad[0xB0]; } S_Rec;

/* declared by functions of L10_00407268.c, which this file was cut from */
extern s32 D_L10_001D6C50;

/* declared by functions of L10_00407750.c, which this file was cut from */
extern void func_003C2F58(void *, s32, void *);
extern void func_003C4C18(void *, f32);

/* localdecomp:start func_L10_004077E0 */
#include "vu0.h"
typedef struct { u8 pad[0x168]; u8 *f168; } G_004077E0;
typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 pad3[0xD];
    vu0_v4 pos;
    vu0_v4 org;
} P_004077E0;
extern f32 func_003824E0(f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_003C4C18(void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern P_004077E0 *func_L01_00474078(void *, void *, s32, f32, f32, f32, f32, s32, s32, s32, s32);
extern G_004077E0 D_L10_0021EB98;
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
extern Cfg_004077E0 D_L10_001D6CE8 __attribute__((section(".sdata")));

void func_L10_004077E0(void *obj) {
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 v2;
    vu0_v4 v3;
    P_004077E0 *r;
    s32 i;
    s32 n;
    f32 sp;

    sp = func_003824E0(D_L10_001D6CE8.speedMin, D_L10_001D6CE8.speedMax) * 0.020000001f;
    if (obj == 0) {
        return;
    }
    func_003C2F58(obj, 0, &v0);
    qzero(&v1);
    func_003C4C18(&v1, 0.2f);
    v1.z *= 0.25f;
    v3 = v1;
    vec_add_ab(&v1, &v0, &v1);
    for (i = 29; i >= 0; i--) {
        qzero(&v2);
        func_0038CF68(&v2, &v3, sp);
        func_003C4C18(&v2, 0.004f);
        n = (func_00382498(D_L10_001D6CE8.lifeMin, D_L10_001D6CE8.lifeMax) * 5 + 2) / 6;
        r = func_L01_00474078(&v1, &v2, n, D_L10_001D6CE8.alpha, 1.0f, D_L10_001D6CE8.size, 1.0f,
                              D_L10_001D6CE8.color0, D_L10_001D6CE8.color1, n, 0);
        if (r != 0) {
            r->b2 = D_L10_0021EB98.f168[func_00382468(2)];
            r->org = v1;
            func_0038CF68(&v2, &v2, D_L10_001D6CE8.size);
            vec_add_ab(&r->pos, &v1, &v2);
            r->pos.w = D_L10_001D6CE8.alpha;
            r->org.w = 1.0f;
        }
    }
}
/* localdecomp:end func_L10_004077E0 */
