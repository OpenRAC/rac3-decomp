#include "common.h"

/* declared by functions of L16_003E91B0.c, which this file was cut from */
extern void func_L16_003E9068(void *a0, void *a1, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4, s32 a2, s32 a3, u8 a4, u8 a5, s32 a6);

/* localdecomp:start func_L16_003E92B8 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003E92B8;

extern void func_0038CE20(void *, void *, f32);
__asm__(".extern D_L16_001DF63C, 4");
extern f32 D_L16_001DF63C;
__asm__(".extern D_L16_001DF640, 4");
extern f32 D_L16_001DF640;
__asm__(".extern D_L16_001DF650, 1");
extern u8 D_L16_001DF650;

void func_L16_003E92B8(void *a0, u8 *p, f32 *t) {
    V_003E92B8 *v = (V_003E92B8 *)p;
    u8 *m = *(u8 **)((u8 *)a0 + 0x68);
    V_003E92B8 pos;
    V_003E92B8 ofs;
    f32 d, h, z;
    u8 a;

    v->w += 0.01f;
    d = v->w - D_L16_001DF63C;
    h = D_L16_001DF640 * 0.5f;
    a = (s32)(D_L16_001DF650 * (h - fabs_asm(d - h)) / h);
    z = *t - d * 4.0f;
    pos = *v;
    func_0038CE20(&ofs, m + 0x40, *(f32 *)(m + 0x64) * 0.2f);
    vec_add_ba(&pos, &ofs, v);
    ((void (*)(void *, void *, f32, f32, f32, f32, s32, s32, u8, u8, s32, f32))func_L16_003E9068)(
        &pos, m + 0x40, 0.0f, v->w, 1.0f, z, 0x3ED8FF, 0x446876, a, a, m[0x6F] + 1, 0.0f);
}
/* localdecomp:end func_L16_003E92B8 */
