#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L10_003C7378);

/* localdecomp:start func_L10_003C75E8 */
#include "vu0.h"
typedef int u128_t_3C75E8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C75E8;
typedef struct { u8 pad0[0x10]; u8 *f10; u8 pad14[0xD4 - 0x14]; u8 *fD4; } S_3C75E8;
__asm__(".extern D_L10_001DE900, 4");
__asm__(".extern D_L10_001DE904, 4");
__asm__(".extern D_L10_001DE908, 4");
__asm__(".extern D_L10_001DE90C, 4");
__asm__(".extern D_L10_001DE910, 4");
__asm__(".extern D_L10_001DE914, 4");
extern f32 D_L10_001DE900;
extern f32 D_L10_001DE904;
extern f32 D_L10_001DE908;
extern f32 D_L10_001DE90C;
extern f32 D_L10_001DE910;
extern f32 D_L10_001DE914;
extern S_3C75E8 D_L10_0021EB98;
extern u8 D_L10_001D66B0[8];
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, f32, s32, f32, s32, s32, s32, s32, s32, s32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
extern void func_00382580(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L10_003C75E8(u8 *m) {
    V4_3C75E8 p;
    V4_3C75E8 z;
    V4_3C75E8 up;
    s32 i;
    s32 col;
    u8 *e;

    if (func_L01_00447490(m, -1, 0) != 0) {
        func_003A52A0(0, 0, m);
        func_L01_00451FE0(m, 0xF, D_L10_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, 0xFF, -1.0f, 0xB4, 0, 0, 0x23, 0, 3, 1.0f, 1.0f);
        *(u128_t_3C75E8 *)&up = 0;
        up.z = 1.0f;
        for (i = 0; i < 10; i++) {
            col = 0x7F00CF88;
            func_00382580(&p, D_L10_001DE900 * 0.2f, D_L10_001DE900);
            vec_add_ab(&p, &p, m + 0x10);
            func_0038CE20(&z, &up, func_003824E0(D_L10_001DE904 * 0.5f, D_L10_001DE904) * 0.020000001f);
            if (func_00382468(2) != 0) {
                col = 0x7F097A46;
            }
            e = func_L01_00475C60(&p, &z, 0x25, func_00382498(-2, 2), col, 0xCF88, 0,
                                  D_L10_001DE908 * 0.5f * 210000.0f, D_L10_001DE908 * 210000.0f, D_L10_001DE910);
            if (e != 0) {
                e[2] = *D_L10_0021EB98.f10;
                e[3] = func_00382468(2) ? 0x48 : 0x44;
            }
            if (func_00382468(3) == 0) {
                e = func_L01_00475C60(&p, &z, 0x25, func_00382498(-2, 2), 0x7F4DBE8A, 0x4DBE8A, 0,
                                      D_L10_001DE90C * 0.7f * 210000.0f, D_L10_001DE90C * 210000.0f, D_L10_001DE914);
                if (e != 0) {
                    e[2] = *D_L10_0021EB98.fD4;
                    e[3] = func_00382468(2) ? 0x48 : 0x44;
                }
            }
        }
        func_L01_00451E78(m, 1, 0.0f);
        func_003C2880(m);
    }
}
/* localdecomp:end func_L10_003C75E8 */

/* localdecomp:start func_L10_003C78B8 */
typedef int u128_t_3C78B8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C78B8;
__asm__(".extern D_L10_001DE918, 4");
extern f32 D_L10_001DE918;
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);

void func_L10_003C78B8(u8 *m) {
    s32 *v = *(s32 **)(m + 0x68);
    V4_3C78B8 b;
    V4_3C78B8 q;
    V4_3C78B8 c;
    V4_3C78B8 w;
    f32 s;
    s32 i;
    s32 r;

    *(u128_t_3C78B8 *)&q = 0;
    q.z = D_L10_001DE918;
    b = q;
    s = 5.05025f;
    func_0038CE20(&b, &b, s);
    for (i = 0; i < 2; i++) {
        func_0038CE20(&c, m + 0xC0, func_003824E0(-1.7f, 1.7f) * s);
        vec_add_ab(&q, &c, &b);
        func_0038CE20(&c, m + 0xD0, func_003824E0(-0.6f, 0.6f) * s);
        vec_add_ab(&q, &c, &q);
        *(u128_t_3C78B8 *)&w = 0;
        w.x = func_003824E0(-1.0f, 1.0f);
        w.y = func_003824E0(-1.0f, 1.0f);
        w.z = func_003824E0(-2.0f, 0.0f);
        c = w;
        func_0038CE20(&w, m + 0xE0, -1.0f);
        vec_add_ab(&c, &w, &c);
        func_0038CF68(&c, &c, func_003824E0(1.5f, 3.0f) * 0.020000001f);
        r = func_00382498(3, 6);
        func_L02_003E2E38(m, &q, 0.0f, &c, r, (i & 1) ? 3 : 0, 0.040000003f, s * 0.5f, 15.0f, 1.0f, 0);
    }
    *v = (func_00382498(0x5A, 0xB4) * 5 + 2) / 6;
}
/* localdecomp:end func_L10_003C78B8 */
