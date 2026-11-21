#include "common.h"

/* NTSC-U counterpart of func_L03_00396320 (src/levels/03_starship_phoenix/L03_00395808.c): 0.02 -> 0.0166667; 0.00392 -> 0.00272222 */
#include "vu0.h"
extern void func_L03_00394CA8(void *);
#include "vu0.h"
#include "vu0.h"
extern f32 func_0037E250(f32, f32);

/* localdecomp:start func_L03_00394CA8 */
typedef struct { u8 pad0[2]; u8 b2; u8 pad1[5]; u8 b8; } S_00396320;
typedef struct { u8 pad[0x164]; u8 *p; } G_00396320;
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
__asm__(".extern D_L03_001D66B0_00394CA8, 16");
extern u8 D_L03_001D66B0_00394CA8;
extern G_00396320 D_L03_0021F318;
static __inline__ f32 size_00396320(f32 x)
{
    return x * 210000.0f;
}
void func_L03_00394CA8(void *arg) {
    f32 v[4];
    f32 t;
    s32 c = 0;
    s32 i;
    S_00396320 *s;
    s = (S_00396320 *)func_L01_0046C468(arg, &D_L03_001D66B0_00394CA8, 15, 0xFFFFFF, 1, 127, 127, size_00396320(4.0f), size_00396320(2.0f), 0.0f, 0);
    if (s) {
        s->b2 = *D_L03_0021F318.p;
        c = s->b8 + 0x20;
    }
    s = (S_00396320 *)func_L01_0046C468(arg, &D_L03_001D66B0_00394CA8, 15, 0x40FF40, 1, 64, 32, size_00396320(6.0f), size_00396320(6.0f), 0.0f, 0);
    if (s) {
        s->b2 = *D_L03_0021F318.p;
        s->b8 = c;
    }
    for (i = 0; i < 20; i++) {
        s32 n;
        f32 a, b, u;
        u = (func_0037E250(-1.0f, 1.0f) + 4.0f) * 0.0166666675f;
        a = func_0037E2A8();
        b = func_0037E2A8();
        func_0037E4B8(v, u, a, b);
        n = func_0037E208(-10, 10) + 30;
        t = func_0037E250(-0.4f, 0.4f) + 0.8f;
        s = (S_00396320 *)func_L01_0046C468(arg, v, n, 0x40FF40, func_0037E1D8(2) ? -1 : 1, 64, 32, size_00396320(t), size_00396320(t), 0.00272222236f, 0);
        if (s) {
            s->b2 = *D_L03_0021F318.p;
            c = s->b8 + 0x20;
        }
        s = (S_00396320 *)func_L01_0046C468(arg, v, n, 0xF7F7F7, func_0037E1D8(2) ? -1 : 1, 48, 48, size_00396320(t * 0.6f), size_00396320(t * 0.6f), 0.00272222236f, 0);
        if (s) {
            s->b2 = *D_L03_0021F318.p;
            s->b8 = c;
        }
    }
}
/* localdecomp:end func_L03_00394CA8 */
