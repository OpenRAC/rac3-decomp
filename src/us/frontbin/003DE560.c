#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_003E3AB0, with its regional timing coefficients. */
/* localdecomp:start func_U_003DE560 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E2258;
typedef struct { V4_003E2258 position; V4_003E2258 angles; f32 matrix[16]; } Cam_003E2258;
extern Cam_003E2258 D_U_00222480_003E2258;
extern void func_U_00388830(void *, void *, f32);
extern void func_U_003886C0(void *, void *, void *, f32);
extern void func_U_003DE4A0(f32 *position);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E3AB0;
typedef struct {
    V4_003E3AB0 v0;
    V4_003E3AB0 v10;
    V4_003E3AB0 v20;
    V4_003E3AB0 v30;
    f32 f40;
    f32 f44;
    f32 f48;
    f32 f4C;
    s32 f50;
    f32 f54;
} S_003E3AB0;
__asm__(".extern D_U_001D9D8C_003E3AB0, 16");
__asm__(".extern D_U_001D9D90_003E3AB0, 16");
extern f32 D_U_001D9D8C_003E3AB0;
extern f32 D_U_001D9D90_003E3AB0;
extern u8 D_001D5470[8];
__asm__(".extern D_001D5470, 16");
extern S_003E3AB0 D_U_00302E20;
extern f32 D_001A4C60[];
extern f32 func_U_00389410(f32);
extern void func_U_00389158(void *, void *, void *, f32);
extern s32 func_U_003DE8A0(void);

void func_U_003DE560(void) {
    V4_003E3AB0 axis;
    V4_003E3AB0 p1;
    V4_003E3AB0 p0;
    f32 scale;
    s32 i;
    S_003E3AB0 *s;

    if (1.0f < D_U_001D9D8C_003E3AB0 || 1.0f < D_U_001D9D90_003E3AB0)
        scale = 2.0f;
    else
        scale = 1.0f;
    vec_sub_ab(&axis, &D_U_00222480_003E2258, &D_U_00302E20.v10);
    func_U_00388830(&axis, &axis, D_U_00302E20.f54);
    for (i = 0; i < 10; i++) {
        func_U_00389158(&p0, &axis, &D_U_00302E20.v30, func_U_00389410((f32)i * 6.2831855f / 10.0f));
        vec_add_ba(&p0, &p0, &D_U_00302E20.v10);
        func_U_00389158(&p1, &axis, &D_U_00302E20.v30, func_U_00389410((f32)(i + 1) * 6.2831855f / 10.0f));
        vec_add_ab(&p1, &p1, &D_U_00302E20.v10);
    }
    if (!func_U_003DE8A0() || !D_001D5470[4] || D_U_00302E20.f50)
        return;
    if (D_U_00302E20.f48 < 0.0261799414f)
        D_U_00302E20.f48 += scale * 0.000145444108f;
    else
        D_U_00302E20.f48 = 0.0261799414f;
    s = &D_U_00302E20;
    s->f4C = s->f48 / 0.0261799414f;
    {
        f32 d = s->f54 - s->f40;
        if (fabs_asm(d) > 0.1f) {
            vec_sub_ba(&D_U_00222480_003E2258, &D_U_00222480_003E2258, &s->v10);
            s->f40 = s->f40 + s->f4C * 0.0350000262f * d;
            func_U_00388830(&D_U_00222480_003E2258, &D_U_00222480_003E2258, s->f40);
            vec_add_ab(&D_U_00222480_003E2258, &D_U_00222480_003E2258, &s->v10);
        }
    }
    vec_sub_ba(&D_U_00222480_003E2258, &D_U_00222480_003E2258, &s->v10);
    func_U_00389158(&D_U_00222480_003E2258, &D_U_00222480_003E2258, &s->v30, scale * s->f48 * s->f44);
    vec_add_ba(&D_U_00222480_003E2258, &D_U_00222480_003E2258, &s->v10);
    func_U_003886C0(s, s, D_001A4C60, s->f4C * 0.0199999809f);
    func_U_003DE4A0((f32 *)s);
}
/* localdecomp:end func_U_003DE560 */
