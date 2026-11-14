#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_00399D30);

INCLUDE_ASM("asm/levels", func_L03_00399F38);

INCLUDE_ASM("asm/levels", func_L03_0039A118);

/* localdecomp:start func_L03_0039A1F8 */
#include "vu0.h"
typedef struct { f32 ang; f32 spin; f32 h; f32 dh; } E_0039A1F8;
typedef struct { E_0039A1F8 e[4]; u8 pad40[0x7F - 0x40]; u8 b7F; u8 b80; } S_0039A1F8;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; S_0039A1F8 *p68; } A_0039A1F8;
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern void func_L03_0039A5D0(void *, void *);
extern void func_L03_0039A4C8(void *);

void func_L03_0039A1F8(void *arg) {
    A_0039A1F8 *a = arg;
    S_0039A1F8 *s = a->p68;
    vu0_v4 pos;
    int i;
    pos = a->pos;
    pos.z += 1.7f;
    func_003D9508(&pos, 0x29, 0x20404040, 1, 0.8f, 0.0f, 0.0f);
    func_003D9508(&pos, 0x31, 0x80802020, 1, 1.0f, 0.0f, func_00382538());
    func_003D9508(&pos, 0x2C, 0xA0A0A0A0, 1, 0.2f, 0.0f, func_00382538());
    for (i = 0; i < 4; i++) {
        E_0039A1F8 *e = &s->e[i];
        vu0_v4 w;
        vu0_v4 v;
        if (((s->b80 >> i) ^ 1) & 1) {
            if (((s->b7F >> i) & 1) || func_00382468(0x5A) == 0) {
                e->h = func_003824E0(-0.95f, 1.15f);
                e->dh = func_003824E0(-4.0f, 4.0f) * 0.020000001f;
                e->ang = func_00382538();
                e->spin = func_003824E0(-90.0f, 90.0f) * 0.017453292f * 0.020000001f;
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
            e->ang = func_0038DAB8(e->ang, e->spin);
            *(vu0_q *)&v = 0;
            v.x = func_0038D0B0(e->ang) * 2.2f;
            v.y = func_0038D098(e->ang) * 2.2f;
            v.z = e->h;
            w = v;
            vec_add_ab(&w, &w, &pos);
            func_L03_0039A5D0(&pos, &w);
        }
    }
    if (s->b80 != 0) func_L03_0039A4C8(a);
}
/* localdecomp:end func_L03_0039A1F8 */

/* localdecomp:start func_L03_0039A4C8 */
#include "vu0.h"
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; u8 *p68; } A_0039A4C8;
typedef struct { u8 pad0[0x44]; f32 f44; u8 pad48[0x28]; f32 f70; f32 f74; u8 pad78[8]; u8 b80; u8 b81; } P_0039A4C8;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L03_0039A5D0(void *, void *);
void func_L03_0039A4C8(void *arg) {
    A_0039A4C8 *a = arg;
    P_0039A4C8 *p = (P_0039A4C8 *)a->p68;
    f32 ang = p->f74;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (((p->b80 & ~p->b81) >> i) & 1) {
            vu0_v4 pos;
            vu0_v4 w;
            vu0_v4 u = {0, 0, 0, 0};
            pos = a->pos;
            pos.z += 1.7f;
            u.x = p->f70 * func_0038D0B0(ang);
            u.y = p->f70 * func_0038D098(ang);
            w = u;
            vec_add_ab(&w, &pos, &w);
            w.z = p->f44;
            func_L03_0039A5D0(&pos, &w);
        }
        ang = func_0038DAB8(ang, 1.5707964f);
    }
}
/* localdecomp:end func_L03_0039A4C8 */

/* localdecomp:start func_L03_0039A5D0 */
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4C18(f32 *v, f32 r);
extern void func_L01_00409658(void *, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L03_0039A5D0(void *from, void *to) {
    vu0_v4 cur;
    vu0_v4 step;
    f32 pts[5][4];
    int i;
    vec_sub_ba(&step, to, from);
    func_0038CE20(&step, &step, 0.25f);
    cur = *(vu0_v4 *)from;
    for (i = 0; i < 5; i++) {
        *(vu0_v4 *)pts[i] = cur;
        if (i != 0 && i != 4) {
            func_003C4C18(pts[i], 0.3f);
        }
        pts[i][3] = 0.05f;
        vec_add_ab(&cur, &cur, &step);
    }
    func_L01_00409658(pts, 0.05f, 4.0f, 0.0f, 0x17, 0x17, 6, -1, 0x80802020, 0);
    func_003D9508(to, 0x31, -1, 1, 0.15f, 0.0f, func_00382538());
    func_003D9508(to, 0x31, 0x80802020, 1, 0.6f, 0.0f, func_00382538());
}
/* localdecomp:end func_L03_0039A5D0 */

INCLUDE_ASM("asm/levels", func_L03_0039A780);
