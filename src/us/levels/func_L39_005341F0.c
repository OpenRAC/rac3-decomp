#include "common.h"

/* NTSC-U counterpart of func_L39_00534880 (src/levels/shared/L39_00534030.c) */
#include "vu0.h"
extern f32 func_L39_005B2510(f32, f32);
extern void func_00388830(void *, void *, f32);
typedef struct S_00534220 {
    u8 pad0[0x10];
    f32 f10;
    u8 pad14[0xC];
    s32 f20;
    f32 f24;
} S_00534220;
extern f32 func_00388770(S_00534220 *);
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern s32 func_0019D650(void);
extern f32 func_L39_005B2568(f32, f32);
extern f32 func_L39_005B2510(f32, f32);
extern s32 func_L39_005B24C8(s32, s32);
extern s32 func_L39_005B2498(s32);
extern u8 *func_L39_005C5838(void *, void *, u32, s32, s32, s32, s32, s32, f32, s32);
extern u8 D_L39_00296918[];
extern u8 *D_L39_002969EC[];

/* localdecomp:start func_L39_005341F0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00534880;
extern void func_00388830(void *, void *, f32);
extern f32 func_L39_005B2568(f32, f32);
extern f32 func_L39_005B2510(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_L39_005B24C8(s32, s32);
extern s32 func_0019D650(void);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_L39_005B2498(s32);
extern void func_003BF6A8(void *, f32);
extern u8 *func_L39_005C5838(void *, void *, u32, s32, s32, s32, s32, s32, f32, s32);
extern u8 D_L39_00296918[];
extern u8 *D_L39_002969EC[];

void func_L39_005341F0(void *arg0, void *arg1, void *arg2) {
    u8 *o = arg0;
    V4_00534880 a = *(V4_00534880 *)arg1;
    V4_00534880 b = *(V4_00534880 *)arg2;
    V4_00534880 vel;
    V4_00534880 pos;
    V4_00534880 step;
    V4_00534880 v;
    u8 *m;
    u8 *p;
    u8 *g;
    u8 *r;
    u8 *q;
    f32 len;
    f32 speed;
    s32 n;
    s32 i;
    s32 spin;
    s32 life;
    s32 alpha;
    s32 rgb;
    u32 col;

    if (o == 0 || o[0x20] == 0xFE || o[0x20] == 0xFD) {
        return;
    }
    m = *(u8 **)(o + 0x68);
    p = *(u8 **)(m + 0x28);
    len = func_00388770((S_00534220 *)m);
    n = (s32)(len / 0.1f);
    pos = b;
    vec_sub_ab(&step, &a, &b);
    func_00388830(&step, &step, len / (f32)n);
    for (i = 0; i < n; i++) {
        g = D_L39_00296918;
        spin = (s32)func_L39_005B2568(1.0f, 3.0f);
        speed = func_L39_005B2510(0.1f, 0.3f) * 0.016666668f;
        func_003886E8(&vel, p + 0x250, -speed);
        life = func_L39_005B24C8(3, 6);
        if (func_0019D650() & 2) {
            alpha = 0x40;
            rgb = 0x407FFF;
        } else {
            alpha = 0x60;
            rgb = 0x4040FF;
        }
        r = func_L01_00466F98(&pos, &vel, life, alpha, rgb, spin, 42000.0f, 1000.0f, 1.0f, 0.0f, 0.0f);
        vec_add_ab(&pos, &pos, &step);
        if (r != 0) {
            if (func_L39_005B2498(2)) {
                r[2] = (*(u8 **)(g + 0x184))[4];
            } else {
                r[2] = (*(u8 **)(g + 0x184))[5];
            }
            r[3] = alpha == 0x40 ? 0x48 : 0x44;
        }
    }
    func_003886E8(&v, m, -0.033333335f);
    func_003BF6A8(&v, 0.10000000894069672f);
    v.z += 0.05000000447034836f;
    col = func_L39_005B2498(2) ? 0x7F407FFF : 0x7F80DFFF;
    q = func_L39_005C5838(o + 0x10, &v, col, 0xFF, func_L39_005B24C8(10, 0x14), 0, -1, -1, 94500.0f, 0);
    if (q != 0) {
        *(f32 *)(q + 0x2C) = 0.0016666667070239782f;
        q[2] = *D_L39_002969EC[0];
    }
}
/* localdecomp:end func_L39_005341F0 */
