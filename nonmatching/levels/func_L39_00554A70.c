/* NTSC-U draft (2026-11-14, Claude worker): C of func_L39_00554120, the NTSC-U twin of func_L39_00554A70, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L39_00554888.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses @ps2as").
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L39_00554120 */
typedef struct V_00554120 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00554120;

extern u8 *D_L39_00296918[];

extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_L39_005B2568(f32, f32);
extern f32 func_L39_005B2510(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_L39_005B24C8(s32, s32);
extern s32 func_0019D650(void);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_L39_005B2498(s32);
extern void func_003BF6A8(f32 *, f32);
extern u8 *func_L39_005C5838(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);

void func_L39_00554120(u8 *m, V_00554120 *pa, V_00554120 *pb) {
    V_00554120 a;
    V_00554120 b;
    V_00554120 v30;
    V_00554120 c;
    V_00554120 d;
    V_00554120 v70;
    u8 *vel;
    u8 *obj;
    f32 len;
    s32 n;
    s32 i;

    a = *pa;
    vel = *(u8 **)(m + 0x68);
    b = *pb;
    obj = *(u8 **)(vel + 0x2C);
    len = func_00388770(vel);
    n = (s32)(len / 0.1f);
    c = b;
    vec_sub_ab(&d, &a, &b);
    func_00388830(&d, &d, len / (f32)n);
    for (i = 0; i < n; i++) {
        s32 life = (s32)func_L39_005B2568(1.0f, 3.0f);
        s32 r;
        s32 size;
        s32 color;
        u8 *p;
        f32 s = func_L39_005B2510(0.1f, 0.2f) * 0.016666668f;
        func_003886E8(&v30, obj + 0x250, -s);
        r = func_L39_005B24C8(3, 6);
        if (func_0019D650() & 2) {
            size = 0x40;
            color = 0xFF7F40;
        } else {
            size = 0x60;
            color = 0xFF4040;
        }
        p = func_L01_00466F98(&c, &v30, r, size, color, life, 63000.004f, 10000.0f, 1.0f, 0.0f, 0.0f);
        vec_add_ab(&c, &c, &d);
        if (p != 0) {
            p[2] = *D_L39_00296918[0x5C / 4];
            p[3] = (size == 0x40) ? 0x48 : 0x44;
        }
    }
    if (*(s32 *)(vel + 0x14) < 0x3C) {
        if (func_L39_005B2498(2) != 0) {
            s32 color;
            s32 x;
            u8 *p;
            func_003886E8(&v70, vel, -0.033333335f);
            color = 0x7F80DFFF;
            func_003BF6A8(&v70.x, 0.10000001f);
            v70.z += 0.050000004f;
            if (func_L39_005B2498(2) != 0) {
                color = 0x7F407FFF;
            }
            x = func_L39_005B24C8(10, 20);
            p = func_L39_005C5838(m + 0x10, &v70, color, 0xFF, x, 0, -1, -1, 0, 94500.0f);
            if (p != 0) {
                *(f32 *)(p + 0x2C) = 0.0016666667f;
                p[2] = *D_L39_00296918[0xD4 / 4];
            }
        }
    }
}
/* localdecomp:end func_L39_00554120 */
