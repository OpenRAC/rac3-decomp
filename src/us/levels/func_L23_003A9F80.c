#include "common.h"

#include "vu0.h"
#include "structs/hero.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;

extern struct Hero D_001A4BE0;
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern u8 *func_L23_003AF078(s32, vu0_q *, vu0_q *, s32, s32, s32);
extern s32 D_L23_001DE220_003A9F80;
__asm__(".extern D_L23_001DE220_003A9F80, 4");

/* localdecomp:start func_L23_003A9F80 */
void func_L23_003A9F80(u8 *self)
{
    u8 *s = *(u8 **)(self + 0x68);
    V4 a, d, w, c;
    s32 i;
    s32 r1, r2;

    a.x = func_00388960(*(f32 *)(self + 0xF8)) * 0.1f;
    a.y = func_00388978(*(f32 *)(self + 0xF8)) * 0.1f;
    a.z = 1.0f;
    vec_add_ba(&a, &a, self + 0x10);
    vec_sub_ab(&d, &D_001A4BE0.pickup_point, self + 0x10);
    func_00388830(&d, &d, 1.0f);
    for (i = 9; i >= 0; i--) {
        w = d;
        w.x += func_0037E250(-0.333333343f, 0.333333343f);
        w.y += func_0037E250(-0.333333343f, 0.333333343f);
        w.z += func_0037E250(-0.333333343f, 0.333333343f);
        func_003886E8(&w, &w, 0.25f);
        w.w = func_0037E250(0.5f, 1.0f);
        qzero(&c);
        c.z = 0.01f;
        c.w = 1.2f;
        r1 = func_0037E208(20, 30);
        r2 = func_0037E208(10, 20);
        func_L01_0045FEC8(&a, &w, &c, 0x80406060, 0x80808080, 1, r1, r2, -1);
    }
    func_L23_003AF078((s32)self, (vu0_q *)&a, (vu0_q *)&d, (s32)D_001A4BE0.hero_moby, 180, 0);
    *(s32 *)s = D_L23_001DE220_003A9F80;
}
/* localdecomp:end func_L23_003A9F80 */
