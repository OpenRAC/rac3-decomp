#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_003E3E68, with its regional timing coefficients. */
/* localdecomp:start func_U_003E3D20 */
extern f32 D_U_00222480_003E37B0[];
extern void func_U_0038D290(void *, void *, f32);
extern void func_U_0038D120(void *, void *, void *, f32);
extern void func_U_003E3C60(f32 *position);

typedef struct {
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    f32 f40;
    f32 f44;
    f32 f48;
    f32 f4C;
    s32 f50;
    f32 f54;
} S_003E3E68;
extern S_003E3E68 D_U_00306E20;
extern f32 D_U_001D9D8C;
extern f32 D_U_001D9D90;
extern u8 D_001D5471[6]; /* 0x1D5471..0x1D5476; [3] is the byte at 0x1D5474 */
extern f32 D_001A4C60[];
extern f32 func_U_0038DE70(f32);
extern void func_U_0038DBB8(void *, void *, void *, f32);
extern s32 func_U_003E4060(void);

void func_U_003E3D20(void) {
    vu0_v4 dir;
    vu0_v4 b;
    vu0_v4 a;
    f32 scale;
    s32 i;
    S_003E3E68 *p;
    f32 d;

    if (D_U_001D9D8C > 1.0f || D_U_001D9D90 > 1.0f) {
        scale = 2.0f;
    } else {
        scale = 1.0f;
    }
    vec_sub_ab(&dir, D_U_00222480_003E37B0, &D_U_00306E20.v10);
    func_U_0038D290(&dir, &dir, D_U_00306E20.f54);
    for (i = 0; i < 10; i++) {
        func_U_0038DBB8(&a, &dir, &D_U_00306E20.v30, func_U_0038DE70(i * 6.2831855f / 10.0f));
        vec_add_ba(&a, &a, &D_U_00306E20.v10);
        func_U_0038DBB8(&b, &dir, &D_U_00306E20.v30, func_U_0038DE70((i + 1) * 6.2831855f / 10.0f));
        vec_add_ab(&b, &b, &D_U_00306E20.v10);
    }
    if (func_U_003E4060() != 0 && D_001D5471[3] != 0 && D_U_00306E20.f50 == 0) {
        if (D_U_00306E20.f48 < 0.0261799414f) {
            D_U_00306E20.f48 = D_U_00306E20.f48 + scale * 0.000145444108f;
        } else {
            D_U_00306E20.f48 = 0.0261799414f;
        }
        p = &D_U_00306E20;
        p->f4C = p->f48 / 0.0261799414f;
        d = p->f54 - p->f40;
        if (fabs_asm(d) > 0.1f) {
            vec_sub_ba(D_U_00222480_003E37B0, D_U_00222480_003E37B0, &p->v10);
            p->f40 = p->f40 + p->f4C * 0.0350000262f * d;
            func_U_0038D290(D_U_00222480_003E37B0, D_U_00222480_003E37B0, p->f40);
            vec_add_ab(D_U_00222480_003E37B0, D_U_00222480_003E37B0, &p->v10);
        }
        vec_sub_ba(D_U_00222480_003E37B0, D_U_00222480_003E37B0, &p->v10);
        func_U_0038DBB8(D_U_00222480_003E37B0, D_U_00222480_003E37B0, &p->v30, scale * p->f48 * p->f44);
        vec_add_ab(D_U_00222480_003E37B0, D_U_00222480_003E37B0, &p->v10);
        func_U_0038D120(p, p, D_001A4C60, p->f4C * 0.0199999809f);
        func_U_003E3C60((f32 *)p);
    }
}
/* localdecomp:end func_U_003E3D20 */
