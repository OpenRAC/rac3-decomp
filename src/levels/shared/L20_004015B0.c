#include "common.h"

/* localdecomp:start func_L20_004015B0 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x24];
    f32 f24;
} P_004015B0;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 f10;
    u8 pad20[4];
    P_004015B0 *f24;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[0xC0 - 0x30];
    vu0_v4 vC0[1];
} S_004015B0;

extern u8 D_L20_001D66B0[8];
__asm__(".extern D_L20_001D66B0, 16");
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                              f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                              s32 h, s32 k);
extern void func_L05_003DC520(void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L02_00429840(void *, void *, s32, s32, void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);

void func_L20_004015B0(u8 *q, s32 a, s32 i, s32 b, s32 c, f32 x, f32 y, f32 z) {
    S_004015B0 *p = (S_004015B0 *)q;
    s16 k = i;
    vu0_v4 tmp;
    vu0_v4 v;
    vu0_v4 *pt;

    func_003A52A0(0, 0, p);
    func_L01_00451FE0(p, a, D_L20_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f, 0, 3);
    if (b != 0) {
        func_L05_003DC520(p, b);
    }
    pt = &tmp;
    tmp = p->f10;
    v = ((vu0_v4 *)q)[k + 12];
    func_0038CF68(&v, &v, p->f2C / p->f24->f24 * x);
    tmp.z += p->f2C / p->f24->f24 * y;
    vec_add_ab(&tmp, &tmp, &v);
    func_L02_00429840(p, pt, 20, 0, D_L20_001D66B0, c, 0, 75, 0.5f, 20.0f, 0.3f, 0.6f);
    func_L02_003E2E38(p, pt, 1.0f, D_L20_001D66B0, 15, 0, 0.050000004f, 2.5f, 5.0f, 1.0f, 1);
    func_L01_003303B8((u8 *)pt, 0, 0, 0, 0, 2, 5, 0, p->f2C / p->f24->f24 * z, 0.0f, 0.0f, 0.0f,
                      0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x7FD68F, 0xFF8400, 0, 0, 0, 0, 0x7F60A0FF, 0x280000FF, 0, 0);
    func_L01_00451E78(p, 1, 0.0f);
    func_003C2880(p);
}
/* localdecomp:end func_L20_004015B0 */
