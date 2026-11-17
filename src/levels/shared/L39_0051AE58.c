#include "common.h"

/* localdecomp:start func_L39_0051AE58 */
typedef int q_0051AE58 __attribute__((mode(TI)));
typedef struct {
    char _p0[0x10];
    f32 f10;
    f32 f14;
    f32 f18;
    char _p1C[0x1C - 0x1C];
    s32 f1C;
    f32 f20;
    s32 f24;
    f32 f28;
    f32 f2C;
} V_0051AE58;
typedef struct {
    char _p0[0x10];
    f32 f10;
    f32 f14;
    f32 f18;
    char _p1C[0x20 - 0x1C];
    u8 f20;
    char _p21[0x2C - 0x21];
    f32 f2C;
    u8 f30;
    u8 f31;
    s16 f32;
    u16 f34;
    char _p36[0x68 - 0x36];
    V_0051AE58 *f68;
    char _p6C[0xBC - 0x6C];
    u8 fBC;
    char _pBD[0xD0 - 0xBD];
    f32 fD0[4];
    char _pE0[0xF0 - 0xE0];
    f32 fF0;
    f32 fF4;
    f32 fF8;
} M_0051AE58;

extern void *func_003C24B0(s32, s32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern s32 func_0019D510(void);
extern f32 func_L39_005B44C8(void);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C7C38(void *);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern s32 D_L39_0024A83C;
extern f32 D_L39_0024A838;
__asm__(".extern D_L39_0024A83C, 4");
__asm__(".extern D_L39_0024A838, 4");

M_0051AE58 *func_L39_0051AE58(void *a0, void *pos, f32 *vel) {
    M_0051AE58 *m;
    V_0051AE58 *v;

    m = func_003C24B0(0x1AC, 0x80);
    if (m != 0) {
        m->f30 = 0x40;
        m->f32 = 0x20;
        m->f31 = 1;
        m->f34 |= 0x1000;
        m->f20 = 0;
        m->fBC = 0;
        *(q_0051AE58 *)&m->f10 = *(q_0051AE58 *)pos;
        v = m->f68;
        m->f18 += func_L39_005B4410(0.2f, 0.7f);
        m->f10 += vel[0] * 3.0f;
        m->f14 += vel[1] * 3.0f;
        *(q_0051AE58 *)v = *(q_0051AE58 *)vel;
        m->fF4 = func_L39_005B4468(0.17453292f, 0.5235988f);
        m->fF0 = func_L39_005B4410(0.17453292f, 0.7853982f);
        v->f2C = func_L39_005B4410(200.0f, 370.0f) * 0.017453292f * 0.020000001f;
        v->f24 = -1;
        if (func_0019D510() & 1) {
            v->f24 = 1;
            m->fF4 = -m->fF4;
        }
        m->fF8 = func_L39_005B44C8();
        v->f28 = -(func_L39_005B4410(200.0f, 550.0f) * 0.017453292f * 0.020000001f);
        v->f10 = func_L39_005B44C8();
        v->f14 = func_L39_005B44C8();
        v->f1C = (func_L39_005B43C8((f32)D_L39_0024A83C * 0.7f, (f32)D_L39_0024A83C * 1.2f) * 5 + 2) / 6;
        m->f2C *= D_L39_0024A838;
        v->f20 = func_L39_005B4410(-1.2f, -0.4f) * 0.020000001f;
        func_0038CE20(m->fD0, m->fD0, 0.5f);
        func_003C7C38(m);
        func_L01_0043B9E8(m, 0x90, 0x90, 0);
    }
    return m;
}
/* localdecomp:end func_L39_0051AE58 */
