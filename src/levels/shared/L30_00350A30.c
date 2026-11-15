#include "common.h"

/* declared by functions of L30_0034EB98.c, which this file was cut from */
extern void func_L01_004450F0(void *, s32, s32);
typedef struct { u8 pad[0x4]; s32 x4; f32 x8; f32 xC; u8 pad10[0x30 - 0x10]; u8 x30[1]; } V_3501B0;
typedef struct { u8 pad[0x10]; u8 x10[0x10]; u8 x20; u8 pad21[0x34 - 0x21]; u16 x34; u8 pad36[0x68 - 0x36]; V_3501B0 *x68; u8 pad6C[0x98 - 0x6C]; s32 x98; } O_3501B0;
extern void func_L30_003509A8(O_3501B0 *);

/* localdecomp:start func_L30_00350A30 */
#include "vu0.h"
typedef struct {
    f32 x0;
    s32 x4;
    f32 x8;
    f32 xC;
    u8 p10[0x20];
    u8 x30[0x10];
} V_00350A30;
typedef struct {
    u8 p0[0x10];
    u8 x10[0x10];
    u8 p20[0x48];
    V_00350A30 *x68;
    u8 p6C[0x84];
    f32 xF0;
    f32 xF4;
} O_00350A30;
__asm__(".extern D_L30_001DD74C, 4");
__asm__(".extern D_L30_001DD75C, 4");
__asm__(".extern D_L30_001DD760, 4");
__asm__(".extern D_L30_001DD764, 4");
__asm__(".extern D_L30_001DD768, 4");
__asm__(".extern D_L30_001DD76C, 4");
__asm__(".extern D_L30_001DD770, 4");
__asm__(".extern D_L30_001DD774, 4");
__asm__(".extern D_L30_001DD778, 4");
__asm__(".extern D_L30_001DD77C, 4");
__asm__(".extern D_L30_001DD780, 4");
__asm__(".extern D_L30_001DD784, 4");
__asm__(".extern D_L30_001DD788, 4");
__asm__(".extern D_L30_001DD78C, 4");
__asm__(".extern D_L30_001DD790, 4");
__asm__(".extern D_L30_001DD794, 4");
__asm__(".extern D_L30_001DD798, 4");
__asm__(".extern D_L30_001DD79C, 4");
__asm__(".extern D_L30_001DD7A0, 4");
__asm__(".extern D_L30_001DD7A4, 4");
__asm__(".extern D_L30_001DD7A8, 1");
__asm__(".extern D_L30_001DD7AC, 4");
__asm__(".extern D_L30_001DD7B0, 4");
__asm__(".extern D_L30_001DD7B4, 4");
__asm__(".extern D_L30_001DD7B8, 4");
__asm__(".extern D_L30_001DD7BC, 4");
__asm__(".extern D_L30_001DD7C0, 4");
__asm__(".extern D_L30_001DD7C4, 4");
__asm__(".extern D_L30_001DD7C8, 4");
__asm__(".extern D_L30_001DD7CC, 4");
__asm__(".extern D_L30_001DD7D0, 4");
extern f32 D_L30_001DD74C;
extern s32 D_L30_001DD75C;
extern s32 D_L30_001DD760;
extern s32 D_L30_001DD764;
extern s32 D_L30_001DD768;
extern s32 D_L30_001DD76C;
extern s32 D_L30_001DD770;
extern s32 D_L30_001DD774;
extern f32 D_L30_001DD778;
extern f32 D_L30_001DD77C;
extern f32 D_L30_001DD780;
extern f32 D_L30_001DD784;
extern s32 D_L30_001DD788;
extern f32 D_L30_001DD78C;
extern f32 D_L30_001DD790;
extern f32 D_L30_001DD794;
extern f32 D_L30_001DD798;
extern s32 D_L30_001DD79C;
extern s32 D_L30_001DD7A0;
extern s32 D_L30_001DD7A4;
extern u8 D_L30_001DD7A8;
extern s32 D_L30_001DD7AC;
extern s32 D_L30_001DD7B0;
extern s32 D_L30_001DD7B4;
extern f32 D_L30_001DD7B8;
extern f32 D_L30_001DD7BC;
extern f32 D_L30_001DD7C0;
extern f32 D_L30_001DD7C4;
extern s32 D_L30_001DD7C8;
extern f32 D_L30_001DD7CC;
extern f32 D_L30_001DD7D0;
extern u8 *D_L30_0021F098[];
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_0038DBD8(s32, s32, f32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D0B0(f32);

void func_L30_00350A30(O_3501B0 *arg) {
    O_00350A30 *o = (O_00350A30 *)arg;
    V_00350A30 *v = o->x68;

    o->xF4 = -v->x0;
    o->xF0 = func_0038DAB8(o->xF0, D_L30_001DD74C);
    v->x8 += D_L30_001DD784;
    if (v->x8 > 1.0f) {
        do {
            f32 a[4] __attribute__((aligned(16)));
            f32 b[4] __attribute__((aligned(16)));
            s32 c0;
            s32 c1;
            s32 c2;
            s32 c3;
            f32 t;
            u8 *r;

            v->x8 -= 1.0f;
            func_0038CF68(a, v->x30, func_003824E0(D_L30_001DD794, D_L30_001DD790));
            vec_add_ab(a, a, o->x10);
            func_0038CE20(b, v->x30, D_L30_001DD78C);
            c0 = func_00382498(D_L30_001DD770, D_L30_001DD76C);
            c1 = func_00382498(-D_L30_001DD774, D_L30_001DD774);
            t = func_003824E0(0.0f, 1.0f);
            c2 = func_0038DBD8(D_L30_001DD760, D_L30_001DD768, t);
            c3 = func_0038DBD8(D_L30_001DD75C, D_L30_001DD764, t);
            r = func_L01_00475C60(a, b, c0, c1, c2, c3,
                                  D_L30_001DD778, D_L30_001DD778 * func_003824E0(D_L30_001DD780, D_L30_001DD77C), 0.0f, 0);
            if (r != 0) {
                r[2] = D_L30_0021F098[117][D_L30_001DD788];
                r[3] = 0x48;
            }
        } while (v->x8 > 1.0f);
    }
    v->xC += D_L30_001DD7C4;
    if (v->xC > 1.0f) {
        do {
            f32 a[4] __attribute__((aligned(16)));
            f32 b[4] __attribute__((aligned(16)));
            s32 c0;
            s32 c1;
            s32 c2;
            f32 ang;
            f32 scale;
            u8 *r;

            v->xC -= 1.0f;
            ang = func_0038DAB8(v->x0, func_003824E0(-D_L30_001DD798, D_L30_001DD798));
            func_0038CF68(a, v->x30, D_L30_001DD7D0);
            vec_add_ab(a, a, o->x10);
            b[0] = func_0038D098(ang) * func_0038CEA8(v->x30) * D_L30_001DD7CC;
            b[2] = func_0038D0B0(ang) * func_0038CEA8(v->x30) * D_L30_001DD7CC;
            b[1] = 0.0f;
            c0 = func_00382498(D_L30_001DD7B0, D_L30_001DD7AC);
            c1 = func_00382498(-D_L30_001DD7B4, D_L30_001DD7B4);
            c2 = func_0038DBD8(D_L30_001DD79C, D_L30_001DD7A0, func_003824E0(0.0f, 1.0f));
            scale = func_003824E0(D_L30_001DD7C0, D_L30_001DD7BC);
            r = func_L01_00475C60(a, b, c0, c1, c2, D_L30_001DD7A4, D_L30_001DD7B8, D_L30_001DD7B8 * scale, 0.0f, 0);
            if (r != 0) {
                r[2] = D_L30_0021F098[117][D_L30_001DD7C8];
                r[3] = D_L30_001DD7A8;
            }
        } while (v->xC > 1.0f);
    }
}
/* localdecomp:end func_L30_00350A30 */

INCLUDE_ASM("asm/levels", func_L30_00350DB0);
