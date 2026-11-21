#include "common.h"

/* localdecomp:start func_L39_00554A70 */
#include "vu0.h"
extern u8 D_L39_00296818[];
extern u8 *D_L39_002968EC __attribute__((section(".data")));
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern s32 func_0019D510(void);
extern f32 func_L39_005B4468(f32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern s32 func_L39_005B4398(s32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern u8 *func_L39_005C7B40(void *, void *, u32, s32, s32, s32, s32, s32, s32, f32);

void func_L39_00554A70(u8 *self, vu0_v4 *a1, vu0_v4 *a2) {
    vu0_v4 from;
    vu0_v4 to;
    vu0_v4 off;
    vu0_v4 pos;
    vu0_v4 step;
    vu0_v4 p;
    u8 *m;
    u8 *h;
    f32 len;
    f32 spd;
    s32 n;
    s32 i;
    s32 life;
    s32 r;
    s32 size;
    s32 col;
    u32 c;
    u8 *e;
    vu0_q qa, qb;

    from = *a1;
    m = *(u8 **)(self + 0x68);
    to = *a2;
    h = *(u8 **)(m + 0x2C);
    len = func_0038CEA8(m);
    n = len / 0.1f;
    pos = to;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(from));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(to));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(step) : "j"(qa));
    func_0038CF68(&step, &step, len / (f32)n);
    for (i = 0; i < n; i++) {
        u8 *g = D_L39_00296818;

        life = func_L39_005B4468(1.0f, 3.0f);
        spd = func_L39_005B4410(0.1f, 0.2f) * 0.020000001f;
        func_0038CE20(&off, h + 0x250, -spd);
        r = func_L39_005B43C8(3, 6);
        if (func_0019D510() & 2) {
            size = 0x40;
            col = 0xFF7F40;
        } else {
            size = 0x60;
            col = 0xFF4040;
        }
        e = func_L01_0046A610(&pos, &off, (r * 5 + 2) / 6, size, col, life, 63000.004f, 10000.0f, 1.0f, 0.0f, 0.0f);
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(step));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(qa));
        if (e != 0) {
            e[2] = **(u8 **)(g + 0x5C);
            e[3] = size == 0x40 ? 0x48 : 0x44;
        }
    }
    if (*(s32 *)(m + 0x14) >= 0x32) {
        return;
    }
    if (func_L39_005B4398(2) != 0) {
        func_0038CE20(&p, m, -0.040000003f);
        func_003C4C18(&p, 0.120000005f);
        p.z += 0.060000002f;
        c = 0x7F80DFFF;
        if (func_L39_005B4398(2) != 0) {
            c = 0x7F407FFF;
        }
        e = func_L39_005C7B40(self + 0x10, &p, c, 0xFF, func_L39_005B43C8(8, 0x11), 0, -1, -1, 0, 94500.0f);
        if (e != 0) {
            *(f32 *)(e + 0x2C) = 0.0024f;
            e[2] = *D_L39_002968EC;
        }
    }
}
/* localdecomp:end func_L39_00554A70 */
