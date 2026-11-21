#include "common.h"

/* NTSC-U counterpart of func_L01_003D80D0 (src/levels/shared/L01_003D0D48.c): v->x14 is 0x28 (PAL 0x21) */
/* localdecomp:start func_L01_003D6578 */
typedef int s128_3D6578 __attribute__((mode(TI)));
typedef struct {
    s128_3D6578 dir;
    s32 x10;
    s32 x14;
    s32 x18;
    s32 x1C;
    u8 p20[4];
    s32 x24;
    u8 p28[4];
    s32 x2C;
    u8 p30[0x110];
    f32 x140;
    f32 x144;
    f32 x148;
    f32 x14C;
    f32 x150;
    f32 x154;
    f32 x158;
    f32 x15C;
} V_3D6578;
typedef struct {
    u8 p0[0x10];
    s128_3D6578 pos;
    u8 p20;
    u8 pad21[2];
    u8 x23;
    u8 p24[8];
    f32 x2C;
    u8 x30;
    u8 x31;
    u16 x32;
    u16 x34;
    u8 p36[0x32];
    V_3D6578 *x68;
    u8 p6C[0x54];
    u8 xC0[0x10];
    u8 xD0[0x20];
    f32 xF0;
    f32 xF4;
    f32 xF8;
} M_3D6578;
extern void func_003BFC18(void *, void *, s32);
extern f32 func_00388A28(f32 a, f32 b);
extern f32 func_00389380(f32 a, f32 b);
extern void func_00388BD0(void *a, void *b);
extern void func_L01_00438908(void *, s32, s32, s32);
extern u8 *func_003BCFB0(s32, s32);
extern void func_00388830(void *dst, void *src, f32 s);
extern f32 func_003887A0(void *);
extern s32 func_L01_004C4A18(void *, f32, f32, f32, s32);

/* quantum_whip_wave_spawn: spawns the Quantum Whip cutting wave (class 0x1CB8, 0.5 u/frame, 40 frames) at pos, flying along dir. */
M_3D6578 *func_L01_003D6578(void *unused_a0, s128_3D6578 *pos, f32 *dir) {
    f32 tmp[4];
    f32 scaled[4];
    f32 hdg;
    M_3D6578 *m;
    V_3D6578 *v;
    func_003BFC18(pos, tmp, 1);
    m = (M_3D6578 *)func_003BCFB0(0x1CB8, 0x200);
    if (m) {
        m->x30 = 0xFF;
        m->x32 = 0xFF;
        m->x31 = 1;
        m->p20 = 0;
        v = m->x68;
        m->pos = *pos;
        *(s128_3D6578 *)v = *(s128_3D6578 *)dir;
        m->x2C = 0.1f;
        v->x10 = 0;
        v->x14 = 0x28;
        func_00388830(scaled, dir, 1.0f);
        v->x150 = -2.25f;
        v->x2C = -1;
        v->x140 = 2.25f;
        v->x144 = 0;
        v->x148 = 0;
        v->x14C = 1.0f;
        v->x154 = 0;
        v->x158 = 0;
        v->x15C = 1.0f;
        v->x24 = 0;
        hdg = func_00388A28(dir[0], dir[1]);
        m->xF8 = func_00389380(hdg, 1.5707964f);
        m->xF0 = -func_00388A28(func_003887A0(dir), dir[2]);
        func_00388BD0(m->xC0, &m->xF0);
        func_00388830(v, v, 0.5f);
        func_00388830(m->xD0, m->xD0, 3.0f);
        m->x34 = (m->x34 | 0x100) & 0xFDFF;
        m->x23 = 0x40;
        func_L01_00438908(m, 0, 0, 0);
        v->x1C = func_L01_004C4A18(m, 1.0f, 1.0f, 1.0f, 0);
    }
    return m;
}
/* localdecomp:end func_L01_003D6578 */
