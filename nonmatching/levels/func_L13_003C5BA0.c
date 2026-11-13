/* near miss (level 13: 74 diff with @ps2as and -mvu0-use-vf0-vf2) */
#include "common.h"

/* localdecomp:start func_L13_003C5BA0 */#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C5BA0;
typedef struct {
    char _p0[0x24];
    f32 f24;
} C_3C5BA0;
typedef struct {
    char _p0[0x10];
    V4_3C5BA0 v10;
    char _p20[4];
    C_3C5BA0 *f24;
    char _p28[4];
    f32 f2C;
    char _p30[0xC0 - 0x30];
    V4_3C5BA0 vC0;
} M_3C5BA0;

extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_0038D000(s32, s32, s32);
extern void func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
extern u8 D_001D66B0[];
extern f32 D_L13_001DEBA4 __attribute__((section(".sdata")));
extern f32 D_L13_001DEBA0 __attribute__((section(".sdata")));

void func_L13_003C5BA0(M_3C5BA0 *m) {
    V4_3C5BA0 v;
    V4_3C5BA0 w;
    f32 inv;

    if (func_L01_00447490(m, -1, 0) == 0) {
        return;
    }
    func_003A52A0(0, 0, m);
    func_L01_00451FE0(m, 0xF, D_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
    inv = 1.0f / m->f24->f24;
    *(vu0_q *)&v = 0;
    v.y = -0.64f;
    v.z = 15.1f;
    v.x = -2.2f;
    func_0038CE20(&v, &v, inv);
    *(vu0_q *)&w = 0;
    w.z = -0.14000002f;
    func_L02_003E2E38(m, &v, 0.1f, &w, 0x14, 0, 0, 0.18f, D_L13_001DEBA4 * inv * m->f2C, 20.0f, 1.0f);
    func_0038CE20(&v, &v, m->f2C);
    func_0038D000((s32)&v, (s32)&v, (s32)&m->vC0);
    vec_add_ab(&v, &v, &m->v10);
    func_L01_003303B8((u8 *)&v, 0, 0, 0, 0, 2, 5, 0, D_L13_001DEBA0 * inv * m->f2C, 0.0f, 0.0f, 0.0f,
                      0, 1, 0, 0, 0, 0, 0x1000000, 0, 0xFFA939, 0xFFD092, 0, 0, 0, 0, 0x7FFFA939, 0x28FFD092, 0, 0);
    func_L01_00451E78(m, 1, 0.0f);
    func_003C2880(m);
}
/* localdecomp:end func_L13_003C5BA0 */
