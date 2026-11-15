#include "common.h"

/* localdecomp:start func_L20_003F53A8 */
#include "vu0.h"

typedef struct {
    s16 h30;
    s16 h32;
    f32 f34;
    f32 f38;
    f32 f3C;
    f32 f40;
    s32 i44;
    s32 i48;
    s32 n4C;
} S_003F53A8;

extern vu0_q D_L20_001DF500 __attribute__((section(".sdata")));
__asm__(".extern D_L20_001DF500, 8");
extern f32 D_L20_001DF50C __attribute__((section(".sdata")));
extern S_003F53A8 D_L20_001DF510;
typedef struct { u8 pad[0x188]; u8 *p188; } G_003F53A8;
extern G_003F53A8 D_L20_00220258;
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4098(void *, void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_00404808(void *, void *);
extern void func_L10_00407268(void);

void func_L20_003F53A8(u8 *o, s32 arg1, f32 scale) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    S_003F53A8 s;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 f;
    vu0_v4 g;
    vu0_v4 m[4];
    u8 *p;
    s32 i;

    if (o == 0) {
        return;
    }
    if (D_L20_001DF50C == 9999.0f) {
        D_L20_001DF500 = *(vu0_q *)(o + 0x10);
        D_L20_001DF50C = 0.0f;
    }
    *(vu0_q *)&a = 0;
    a.y = -2.0f;
    *(vu0_q *)&c = 0;
    c.y = 1.0f;
    *(vu0_q *)&b = 0;
    s = D_L20_001DF510;
    func_003C2EC0(o, 0, m);
    func_0038D028(&g, &a, m);
    vec_add_ab(&f, &g, &m[3]);
    func_0038D028(&g, &b, m);
    qzero(&d);
    func_0038D028(&d, &c, m);
    func_0038CF68(&d, &d, func_003824E0(s.f40, s.f3C));
    for (i = 0; i < s.n4C; i++) {
        func_003C4098(&e, &D_L20_001DF500, &f, (f32)i / (f32)s.n4C);
        p = func_L01_00475C60(&e, &d, func_00382498(s.h32, s.h30), 0, s.i44, s.i48,
                              (s32)(scale * (s.f34 + func_003824E0(0.0f, 0.1f)) * 210000.0f),
                              (s32)(scale * s.f38 * 210000.0f), 0.0f, 1);
        if (p != 0) {
            p[9] = 0xF2;
            p[2] = D_L20_00220258.p188[4];
        }
    }
    D_L20_001DF500 = *(vu0_q *)&f;
    if (arg1 != 0) {
        func_L01_00404808(func_L10_00407268, o);
    }
}
/* localdecomp:end func_L20_003F53A8 */

INCLUDE_ASM("asm/levels", func_L20_003F5688);
