/* functional: high. PAL twin of the NTSC draft: same fire-trail loop and ember spawn, with PAL constants (0.02 step scale, 50 threshold, -0.04/0.12/0.06 ember vector, (r*5+2)/6 size arg). Particle helper prototypes taken from the disassembly. */
#include "common.h"
#include "vu0.h"

typedef struct V_00554A70 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00554A70;

extern u8 *D_L39_00296818[];

extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L39_005B4468(f32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern s32 func_0019D510(void);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_L39_005B4398(s32);
extern void func_003C4C18(f32 *, f32);
extern u8 *func_L39_005C7B40(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);

void func_L39_00554A70(u8 *m, V_00554A70 *pa, V_00554A70 *pb) {
    V_00554A70 a;
    V_00554A70 b;
    V_00554A70 v30;
    V_00554A70 c;
    V_00554A70 d;
    V_00554A70 v60;
    u8 *vel;
    u8 *obj;
    f32 len;
    s32 n;
    s32 i;

    a = *pa;
    vel = *(u8 **)(m + 0x68);
    b = *pb;
    obj = *(u8 **)(vel + 0x2C);
    len = func_0038CEA8(vel);
    n = (s32)(len / 0.1f);
    c = b;
    vec_sub_ab(&d, &a, &b);
    func_0038CF68(&d, &d, len / (f32)n);
    for (i = 0; i < n; i++) {
        s32 life = (s32)func_L39_005B4468(1.0f, 3.0f);
        s32 r;
        s32 size;
        s32 color;
        u8 *p;
        f32 s = func_L39_005B4410(0.1f, 0.2f) * 0.020000001f;
        func_0038CE20(&v30, obj + 0x250, -s);
        r = func_L39_005B43C8(3, 6);
        if (func_0019D510() & 2) {
            size = 0x40;
            color = 0xFF7F40;
        } else {
            size = 0x60;
            color = 0xFF4040;
        }
        p = func_L01_0046A610(&c, &v30, (r * 5 + 2) / 6, size, color, life, 63000.004f, 10000.0f, 1.0f, 0.0f, 0.0f);
        vec_add_ab(&c, &c, &d);
        if (p != 0) {
            p[2] = *D_L39_00296818[0x5C / 4];
            p[3] = (size == 0x40) ? 0x48 : 0x44;
        }
    }
    if (*(s32 *)(vel + 0x14) < 0x32) {
        if (func_L39_005B4398(2) != 0) {
            s32 color;
            s32 x;
            u8 *p;
            func_0038CE20(&v60, vel, -0.040000003f);
            color = 0x7F80DFFF;
            func_003C4C18(&v60.x, 0.120000005f);
            v60.z += 0.060000002f;
            if (func_L39_005B4398(2) != 0) {
                color = 0x7F407FFF;
            }
            x = func_L39_005B43C8(8, 0x11);
            p = func_L39_005C7B40(m + 0x10, &v60, color, 0xFF, x, 0, -1, -1, 0, 94500.0f);
            if (p != 0) {
                *(f32 *)(p + 0x2C) = 0.0024f;
                p[2] = *D_L39_00296818[0xD4 / 4];
            }
        }
    }
}
