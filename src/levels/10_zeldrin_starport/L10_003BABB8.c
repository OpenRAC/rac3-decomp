#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L10_003BABB8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BABB8;
typedef struct {
    s32 period;
    f32 strength;
    s32 chance;
    s32 timer;
    s32 count;
    s32 dist;
} E_3BABB8;
extern u8 D_001426E0[];
extern u8 D_L10_001E1B40[];
extern void func_0038D308(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_00382498(s32, s32);
extern s32 func_L01_0040F5B8(void *, void *, void *);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00443B88(void *, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);

void func_L10_003BABB8(u8 *m) {
    E_3BABB8 *v = *(E_3BABB8 **)(m + 0x68);
    V4_3BABB8 p;
    V4_3BABB8 r;
    V4_3BABB8 q;
    s32 i;
    s16 a;
    s16 b;
    s16 c;
    f32 f;
    s32 col;

    if (D_001426E0[2] == 0 || D_001426E0[0x7A] != 0) {
        return;
    }
    switch (m[0x20]) {
    case 0:
        func_0038D308(m + 0xC0, m + 0xF0);
        func_L01_004450F0(m, 1, -1);
    case 1:
        if (func_0038CAD0(&v->timer) == 0) {
            return;
        }
        v->timer = (func_00382498(v->period >> 1, v->period << 1) * 5 + 2) / 6;
        if (func_L01_0040F5B8(m + 0x10, D_L10_001E1B40, D_L10_001E1B40 + 0x20) == 0) {
            return;
        }
        if (func_00382468(v->chance - 1) == 0) {
            f = v->strength * func_003824E0(0.5f, 2.0f);
            a = func_00382468(2);
            b = func_00382468(2);
            c = func_00382468(2);
            func_L01_003303B8(m + 0x10, 1, 5, 5, 5, 5, 0x14, 1, f, 0.0f, 0.0f, 0.0f,
                              0, a, b, c, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_003A52A0(1, 0, m);
        } else {
            func_003A52A0(0, 0, m);
        }
        for (i = 0; i < v->count; i++) {
            func_0038CF68(&p, m + 0xC0, -((f32)v->dist * 0.020000001f));
            func_L01_00443B88(&q, 0.0f, (f32)v->dist * 0.65f * 0.020000001f);
            vec_add_ab(&p, &p, &q);
            p.w = v->strength * func_003824E0(0.1f, 0.4f);
            qzero(&r);
            r.z = -(func_003824E0(9.8f, 19.6f) * 0.00040000002f) * 150.0f;
            vec_add_ab(&r, &r, &p);
            col = func_0038DBD8(0x804080FF, 0x80F02050, func_003824E0(0.0f, 1.0f));
            func_L01_00463378(m + 0x10, &p, &r, col, col & 0xFFFFFF, 5, 0x64, 0x32, 0x1003C);
        }
        break;
    }
}
/* localdecomp:end func_L10_003BABB8 */
