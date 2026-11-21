#include "common.h"

/* NTSC-U counterpart of func_L03_0039A780 (src/levels/03_starship_phoenix/L03_00399D30.c): 0.02 -> 0.0166667; 0.00392 -> 0.00272222 */
#include "vu0.h"
extern u8 *D_L03_0021F318[];
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);
#include "vu0.h"
extern u8 *D_L03_0021F318[];
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);
#include "vu0.h"
extern u8 D_L03_001D66B0_003990A0;
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);
#include "vu0.h"
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
#include "vu0.h"
#include "vu0.h"
extern f32 func_0037E2A8(void);

/* localdecomp:start func_L03_003990A0 */
typedef struct S_0039A780 {
    u8 pad0[2];
    u8 b2;
    u8 pad3[5];
    u8 b8;
} S_0039A780;
typedef S_0039A780 *(*Spawn_0039A780)(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_0037E208(s32, s32);

/* -1 or 1 at random */
static __inline__ s32 rsign_0039A780(void) {
    return func_0037E1D8(2) ? -1 : 1;
}

void func_L03_003990A0(void *arg0) {
    S_0039A780 *o;
    s32 col = 0;
    s32 i;

    o = ((Spawn_0039A780)func_L01_0046C468)(arg0, &D_L03_001D66B0_003990A0, 15, 0xFFFFFF, 1, 0x7F, 0x7F, 420000.0f, 210000.0f, 0.0f, 0);
    if (o != 0) {
        col = o->b8 + 0x20;
        o->b2 = *D_L03_0021F318[89];
    }
    o = ((Spawn_0039A780)func_L01_0046C468)(arg0, &D_L03_001D66B0_003990A0, 15, 0x802020, 1, 0x40, 0x20, 630000.0f, 630000.0f, 0.0f, 0);
    if (o != 0) {
        o->b2 = *D_L03_0021F318[89];
        o->b8 = col;
    }
    for (i = 0; i < 20; i++) {
        f32 vec[4];
        s32 id;
        f32 r;
        S_0039A780 *p;

        {
            f32 s = (func_0037E250(-1.0f, 1.0f) + 4.0f) * 0.0166666675f;
            f32 x = func_0037E2A8();
            f32 y = func_0037E2A8();
            func_0037E4B8(vec, s, x, y);
        }
        id = func_0037E208(-10, 10) + 30;
        r = func_0037E250(-0.4f, 0.4f) + 0.8f;
        {
            s32 sign = rsign_0039A780();

            p = ((Spawn_0039A780)func_L01_0046C468)(arg0, vec, id, 0x802020, sign, 0x40, 0x20, r * 210000.0f, r * 210000.0f, 0.00272222236f, 0);
            if (p != 0) {
                col = p->b8 + 0x20;
                p->b2 = *D_L03_0021F318[89];
            }
        }
        {
            s32 sign = rsign_0039A780();

            p = ((Spawn_0039A780)func_L01_0046C468)(arg0, vec, id, 0xF7F7F7, sign, 0x30, 0x30, r * 0.6f * 210000.0f, r * 0.6f * 210000.0f, 0.00272222236f, 0);
            if (p != 0) {
                p->b2 = *D_L03_0021F318[89];
                p->b8 = col;
            }
        }
    }
}
/* localdecomp:end func_L03_003990A0 */
