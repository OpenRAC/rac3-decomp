#include "common.h"

/* NTSC-U counterpart of func_L12_003D5210 (src/levels/shared/L12_003D5210.c): the last particle call's frame count is the random 0x19..0x1E itself, without PAL's 50 Hz rescaling (n * 5 + 2) / 6 */
/* localdecomp:start func_L12_003D3578 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003D3578;
__asm__(".extern D_L12_001DEFAC_003D3578, 4");
extern f32 D_L12_001DEFAC_003D3578;
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388770(void *);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern u8 *func_L01_004633E8(void *, s32, void *, u32, s32, f32, f32, f32, f32);
extern void func_L01_004632D8(void *, void *, s32, s32, s32, f32);

void func_L12_003D3578(u8 *m, void *dir, V4_003D3578 *at) {
    V4_003D3578 pos;
    V4_003D3578 vel;
    V4_003D3578 p;
    V4_003D3578 d;
    s32 r;
    u32 color;
    f32 speed;
    f32 s;

    pos = *at;
    p = *(V4_003D3578 *)(m + 0x10);
    func_003886E8(&p, m + 0xC0, -1.2f);
    vec_add_ab(&p, &p, m + 0x10);
    speed = func_00388770(dir) * D_L12_001DEFAC_003D3578;
    func_003886E8(&vel, m + 0xC0, speed);
    r = func_0037E208(0x20, 0x40);
    color = 0x7F000000 | ((r + 8) << 16) | (r << 8) | r;
    func_L01_004633E8(&p, func_0037E208(0, 2) - 1, &vel, color, 0, 0.25f, 0.8f, 1.01f, func_0037E250(0.75f, 1.0f) * 210000.0f);
    vec_sub_ba(&d, m + 0x10, &pos);
    func_003886E8(&d, &d, 0.5f);
    vec_add_ab(&p, &p, &d);
    r = func_0037E208(0x40, 0x80);
    color = 0x40000000 | (r << 16) | (r << 8) | r;
    s = func_0037E250(1.25f, 1.75f) * 210000.0f;
    func_L01_004632D8(&p, &vel, color, 0x101010, func_0037E208(0x19, 0x1E), s);
}
/* localdecomp:end func_L12_003D3578 */
