#include "common.h"

typedef int Q87e __attribute__((mode(TI)));
typedef struct { float x,y,z,w; } __attribute__((aligned(16))) V87e;
typedef struct { char pad[32]; float rate; int pad24, timer, count; } G87e;

/* localdecomp:start func_L09_003F1600 */
#include "vu0.h"

typedef struct { u8 _p0[0x10]; u8 *p10; } G_003F1600;

extern G_003F1600 D_L09_00220018;
extern void func_0038CE20(void *, void *, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003824E0(f32, f32);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L09_003F1600(void *arg) {
    u8 *self = arg;
    vu0_v4 v;
    vu0_v4 c;
    vu0_v4 w;
    f32 scale;
    s32 i;

    scale = *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24);
    func_0038CE20(&w, self + 0xE0, 4.0f);
    for (i = 9; i >= 0; i--) {
        s32 color = 0x7F668A90;
        f32 a = func_00382538();
        f32 size = scale * 210000.0f;
        f32 hi, lo, t, sn, len;
        s32 k;
        u8 *p;

        sn = func_0038D098(a);
        hi = scale * 4.0f;
        lo = hi * 0.5f;
        v.x = sn * func_003824E0(lo, hi);
        v.y = func_0038D0B0(a) * func_003824E0(lo, hi);
        v.z = func_003824E0(-3.0f, 3.0f) * scale;
        *(s32 *)&v.w = 0;
        vec_add_ab(&v, self + 0x10, &v);
        vec_add_ab(&v, &w, &v);
        func_00382580(&c, 0.00375000015f, 0.00625000056f);
        if (func_00382468(4) != 0) {
            color = 0x7F426066;
        }
        k = func_00382498(-2, 2);
        len = scale * 2.5f * 210000.0f;
        t = func_003824E0(-0.3f, -1.0f);
        p = func_L01_00475C60(&v, &c, 0x3A, k, color, 0x426066, size, len, t, 0);
        if (p != 0) {
            p[2] = *D_L09_00220018.p10;
            p[3] = func_00382468(2) ? 0x48 : 0x44;
        }
    }
}
/* localdecomp:end func_L09_003F1600 */
