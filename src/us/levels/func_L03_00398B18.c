#include "common.h"

/* NTSC-U counterpart of func_L03_0039A1F8 (src/levels/03_starship_phoenix/L03_00399D30.c): 0.02 -> 0.0166667 */
/* localdecomp:start func_L03_00398B18 */
#include "vu0.h"
typedef struct { f32 ang; f32 spin; f32 h; f32 dh; } E_0039A1F8;
typedef struct { E_0039A1F8 e[4]; u8 pad40[0x7F - 0x40]; u8 b7F; u8 b80; } S_0039A1F8;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; S_0039A1F8 *p68; } A_0039A1F8;
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00389380(f32, f32);
extern void func_003D3FA0(void *, s32, s32, s32, f32, f32, f32);
extern void func_L03_00398EF0(void *, void *);
extern void func_L03_00398DE8(void *);

void func_L03_00398B18(void *arg) {
    A_0039A1F8 *a = arg;
    S_0039A1F8 *s = a->p68;
    vu0_v4 pos;
    int i;
    pos = a->pos;
    pos.z += 1.7f;
    func_003D3FA0(&pos, 0x29, 0x20404040, 1, 0.8f, 0.0f, 0.0f);
    func_003D3FA0(&pos, 0x31, 0x80802020, 1, 1.0f, 0.0f, func_0037E2A8());
    func_003D3FA0(&pos, 0x2C, 0xA0A0A0A0, 1, 0.2f, 0.0f, func_0037E2A8());
    for (i = 0; i < 4; i++) {
        E_0039A1F8 *e = &s->e[i];
        vu0_v4 w;
        vu0_v4 v;
        if (((s->b80 >> i) ^ 1) & 1) {
            if (((s->b7F >> i) & 1) || func_0037E1D8(0x5A) == 0) {
                e->h = func_0037E250(-0.95f, 1.15f);
                e->dh = func_0037E250(-4.0f, 4.0f) * 0.0166666675f;
                e->ang = func_0037E2A8();
                e->spin = func_0037E250(-90.0f, 90.0f) * 0.017453292f * 0.0166666675f;
                s->b7F &= ~(1 << i);
            }
            e->h = e->h + e->dh;
            if (e->h > 1.15f) {
                e->h = 1.15f;
                e->dh = -e->dh;
            } else if (e->h < -0.95f) {
                e->h = -0.95f;
                e->dh = -e->dh;
            }
            e->ang = func_00389380(e->ang, e->spin);
            *(vu0_q *)&v = 0;
            v.x = func_00388978(e->ang) * 2.2f;
            v.y = func_00388960(e->ang) * 2.2f;
            v.z = e->h;
            w = v;
            vec_add_ab(&w, &w, &pos);
            func_L03_00398EF0(&pos, &w);
        }
    }
    if (s->b80 != 0) func_L03_00398DE8(a);
}
/* localdecomp:end func_L03_00398B18 */
