#include "common.h"

/* NTSC-U counterpart of func_L21_003B2688 (src/levels/21_obani_draco/L21_003B1A00.c) */
#include "vu0.h"
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E250(f32, f32);

/* localdecomp:start func_L21_003B0AD0 */
extern s32 D_L21_001D6694_003B0AD0;
extern u8 D_001A30B0[];
extern s32 func_L01_004A72A8(s32, s32, void *, s32);
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern s32 func_L01_00443648(void *, void *, s32, s32, s32, s32, f32, f32, f32);
extern void func_0039FB08(s32);
extern void func_003BD360(void *);

typedef struct {
    vu0_v4 dir;
    s32 sound;
    s32 life;
} S_003B2688;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0x68 - 0x20];
    S_003B2688 *pvar;
    u8 pad6C[0x96 - 0x6C];
    u16 age;
} M_003B2688;

void func_L21_003B0AD0(M_003B2688 *m) {
    S_003B2688 *s;
    u8 *e;
    s32 idx;
    vu0_v4 v;
    vu0_v4 w[2];
    vu0_v4 p;

    s = m->pvar;
    if (s->sound == -1) {
        goto spawn;
    }
    e = D_001A30B0 + (s->sound << 7);
    if (*(M_003B2688 **)(e + 0xDC) != m || e[0xD0] == 0) {
spawn:
        if (D_L21_001D6694_003B0AD0 != 2) {
            s->sound = func_L01_004A72A8(0, 4, m, 0x1A9C);
        }
    }
    func_00388830(&v, s, 0.25f);
    vec_add_ba(&m->pos, &m->pos, &v);
    func_003886E8(&w[0], &v, -0.5f);
    qzero(&w[1]);
    func_L01_0046C468(&m->pos, w, 5, 0x808080, 3, 0x4F, 0,
                      func_0037E250(0.5f, 0.75f) * 210000.0f, func_0037E250(0.2f, 0.4f) * 210000.0f, 0.0f, 0);
    p = m->pos;
    p.x += func_L01_00440918(0.0f, 0.15f);
    p.y += func_L01_00440918(0.0f, 0.15f);
    p.z += func_L01_00440918(0.0f, 0.15f);
    func_L01_0046C468(&p, w, 5, 0x808080, 7, 0x5F, 0,
                      func_0037E250(0.5f, 0.75f) * 210000.0f, func_0037E250(0.1f, 0.3f) * 210000.0f, 0.0f, 0);
    p.x += func_L01_00440918(0.0f, 0.15f);
    p.y += func_L01_00440918(0.0f, 0.15f);
    p.z += func_L01_00440918(0.0f, 0.15f);
    func_L01_0046C468(&p, w, 5, 0x808080, 0xC, 0x7F, 0,
                      func_0037E250(0.5f, 0.75f) * 210000.0f, func_0037E250(0.2f, 0.4f) * 210000.0f, 0.0f, 0);
    func_L01_00443648(m, &m->pos, 1, 0, 1, 0, 0.2f, 20.0f, 0.5f);
    m->age++;
    if (s->life < m->age) {
        idx = s->sound;
        if (idx != -1) {
            e = D_001A30B0 + (idx << 7);
            if (*(M_003B2688 **)(e + 0xDC) == m && e[0xD0] != 0) {
                func_0039FB08(idx);
            }
        }
        s->sound = -1;
        func_003BD360(m);
    }
}
/* localdecomp:end func_L21_003B0AD0 */
