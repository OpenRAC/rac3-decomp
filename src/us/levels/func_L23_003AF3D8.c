#include "common.h"

/* NTSC-U counterpart of func_L23_003B0CE0 (src/levels/23_holostar_studios_clank/L23_003AD800.c) */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef int u128_t __attribute__((mode(TI)));
#include "vu0.h"
#include "structs/hero.h"
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);

/* localdecomp:start func_L23_003AF3D8 */
extern s32 D_L23_001DECC0_3B0CE0;
__asm__(".extern D_L23_001DECC0_3B0CE0, 4");
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_004084B0(u128_t *a, u128_t *b, s32 c, s32 d, u32 c0, u32 c1, u32 c2, u32 c3,
                          f32 f0, f32 f1, f32 f2);
extern void func_003D3FA0(void *, s32, u32, s32, f32, f32, f32);
extern void func_L01_0045FEC8(void *, void *, void *, u32, u32, s32, s32, s32, s32);

void func_L23_003AF3D8(u8 *o)
{
    V4 pos;
    V4 dir;
    V4 *pp = &pos;
    V4 *pd = &dir;
    V4 a;
    V4 b;
    u8 *v;
    V4 *t;
    f32 s;

    *pp = *(V4 *)(o + 0x10);
    v = *(u8 **)(o + 0x68);
    t = (V4 *)(v + 0x10);
    s = 0.1f;
    if (*(s32 *)(v + 0xC) != 0)
        s = 0.5f;
    func_00388830(pd, t, s);
    vec_sub_ab(pd, pp, pd);
    func_L01_004084B0((u128_t *)pp, (u128_t *)pd, 0x16, 0, 0x60606080, 0x60606080, 0x60606080, 0x60606080, 0.05f, 1.0f, 0.0f);
    func_003D3FA0(pd, 6, 0x80002080, 1, 0.2f, 0.0f, 0.0f);
    if (*(s32 *)(v + 0xC) != 0) {
        if (D_L23_001DECC0_3B0CE0 & 1) {
            func_003886E8(&a, t, 0.5f);
            func_L01_0045FEC8(pd, &a, &a, 0xFF008080, 0xFF404080, 5, 5, 5, -1);
        } else {
            qzero(&b);
            qzero(&a);
            a.w = 0.4f;
            b.z = 0.01f;
            b.w = 0.8f;
            func_L01_0045FEC8(pd, &a, &b, 0x60406060, 0x60808080, 5, 0x14, 0x14, -1);
        }
    }
}
/* localdecomp:end func_L23_003AF3D8 */
