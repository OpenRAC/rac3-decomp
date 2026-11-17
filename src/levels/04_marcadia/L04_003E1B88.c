#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_003E1B88 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E1B88;
typedef struct { u8 pad[0x5C]; u8 *p5C; } S_003E1B88;

extern S_003E1B88 D_L04_0021FC18;
__asm__(".extern D_L04_0021FC18, 16");
extern f32 func_003C3D30(void *, s32, void *, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L04_003E1B88(s32 a0, s32 a1, V4_003E1B88 *a2, s32 a3) {
    V4_003E1B88 s;
    V4_003E1B88 p;
    V4_003E1B88 q;
    V4_003E1B88 *pp;
    V4_003E1B88 *qq;
    f32 d;
    f32 r;
    f32 t;
    s32 n;
    u8 *b;

    s = *a2;
    p = *a2;
    t = func_003C3D30(&s, 0, 0, 0.5f);
    d = s.z - t;
    p.z = t;
    if (d > 0.0f && d < 12.0f) {
        r = (d - 6.0f) / 6.0f;
        if (r > 1.0f) {
            r = 1.0f;
        } else if (r < 0.0f) {
            r = 0.0f;
        }
        n = 127 - (s32)(r * 127.0f);
        if (n >= 15 && a3 > 0) {
            pp = &p;
            qq = &q;
            do {
                q.x = func_0038D098(func_00382538()) * 0.040000003f;
                q.y = func_0038D0B0(func_00382538()) * 0.040000003f;
                q.z = 0.0060000005f;
                b = func_L01_0046FB40(pp, qq, 0x32, 0x303234, func_00382468(3), n, 7, 0, 63000.004f, 105000.0f, 0.0f);
                if (b != 0) {
                    b[2] = *D_L04_0021FC18.p5C;
                    b[3] = 0x48;
                }
                a3--;
            } while (a3 != 0);
        }
    }
}
/* localdecomp:end func_L04_003E1B88 */

/* localdecomp:start func_L04_003E1D80 */
extern s32 D_L04_001DF940;
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L04_003E1B88(s32, s32, V4_003E1B88 *, s32);

void func_L04_003E1D80(u8 *a0, s32 a1) {
    vu0_v4 p;
    vu0_v4 d;
    s32 i;

    if (((*(s16 *)(a0 + 0xB2) + D_L04_001DF940) & 1) == 0) {
        func_0038CE20(&d.x, a0 + 0xC0, -0.1f);
        d.z -= 0.15f;
        for (i = 0; i < 2; i++) {
            func_003C2F58(a0, i + 1, &p);
            vec_add_ab(&p, &p, &d);
            func_L04_003E1B88((s32)a0, a1, (V4_003E1B88 *)&p, 1);
        }
    }
}
/* localdecomp:end func_L04_003E1D80 */
