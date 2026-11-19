#include "common.h"

typedef struct S_L02_003532F0 {
    f32 x;
    f32 y;
    u8 pad08[0xC];
    s32 state;
    f32 t18;
    f32 t1C;
} S_L02_003532F0;
typedef struct T_L02_003532F0 {
    f32 thr;
    f32 pad[6];
} T_L02_003532F0;
typedef struct O_L02_003532F0 {
    u8 pad00[0x20];
    s32 count;
    u8 pad24[0xC];
    f32 vx;
    f32 vy;
} O_L02_003532F0;

typedef struct B_L02_00352C80 {
    s32 id;
    u8 pad04[0x1C];
    s32 cnt20;
    s32 a24;
    s32 a28;
    s32 r2C;
    u8 pad30[0x10];
    s32 cnt40;
    s32 a44;
    s32 a48;
    s32 r4C;
    s32 flag50;
    f32 f54;
    f32 f58;
} B_L02_00352C80;
typedef struct A_L02_00352C80 {
    u8 pad00[0x20];
    u8 b20;
    u8 pad21[0x47];
    B_L02_00352C80 *sub;
} A_L02_00352C80;

/* declared by functions of L02_00352C80.c, which this file was cut from */
extern void func_L02_00352DF0(A_L02_00352C80 *, B_L02_00352C80 *);

INCLUDE_ASM("asm/levels", func_L02_00352DF0);

/* localdecomp:start func_L02_00352F60 */
#include "vu0.h"
typedef struct {
    u8 pad00[4];
    f32 range;
    u16 flags;
    u8 pad0A[6];
    s32 rec;
    f32 radius;
} S_00352F60;
typedef struct {
    u8 v00[0x10];
    u8 v10[0x20];
    u8 v30[8];
    f32 f38;
} R_00352F60;
__asm__(".extern D_L02_001DCF8C, 4");
extern f32 D_L02_001DCF8C;
extern u8 *D_L02_001DEA80;
typedef struct {
    vu0_v4 pos;
    vu0_v4 v10;
    vu0_v4 dir;
} C_00352F60;
extern C_00352F60 D_L02_001E1280;
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_L01_0040E4C0(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern s32 func_003D5630(void);
extern s32 func_L02_003E6F38(f32, f32, f32);

s32 func_L02_00352F60(A_L02_00352C80 *a, B_L02_00352C80 *b, void *out, f32 scale) {
    S_00352F60 *s = (S_00352F60 *)b;
    R_00352F60 *rec;
    vu0_v4 d;
    vu0_v4 tmp;
    f32 range;
    f32 y;
    f32 h;
    s32 r;

    rec = 0;
    h = 0.0f;
    range = scale * s->range;
    if (s->rec != -1) {
        rec = (R_00352F60 *)(D_L02_001DEA80 + (s->rec << 7));
        y = fabs_asm(((f32 *)&D_L02_001E1280.pos)[2] - rec->f38);
    } else {
        y = fabs_asm(((f32 *)&D_L02_001E1280.pos)[2] - *(f32 *)((u8 *)a + 0x18));
    }
    if (range < y) {
        return 0;
    }
    if (s->rec != -1) {
        func_0038CE20(out, rec->v00, func_003824E0(-1.0f, 1.0f));
        func_0038CE20(&tmp, rec->v10, func_003824E0(-1.0f, 1.0f));
        vec_add_ba(out, &tmp, out);
        vec_add_ab(out, out, rec->v30);
    } else {
        ((f32 *)out)[0] = func_0038D098(func_00382538()) * s->radius;
        ((f32 *)out)[1] = func_0038D0B0(func_00382538()) * s->radius;
        ((s32 *)out)[2] = 0;
        vec_add_ab(out, out, (u8 *)a + 0x10);
    }
    vec_sub_ab(&d, out, &D_L02_001E1280.pos);
    if (func_L01_0040E4C0(&d) > range * range) {
        return -1;
    }
    func_0038CF68(&d, &d, 1.0f);
    if (func_0038CE68(&d, &D_L02_001E1280.dir) < D_L02_001DCF8C) {
        return -1;
    }
    if (s->flags != 0) {
        h = func_003C3D30(out, 0, 0, 0.5f);
    }
    if (((u8 *)&s->flags)[0] != 0) {
        r = func_003D5630();
        switch (r) {
        case 0:
        case 1:
        case 3:
        case 11:
            break;
        default:
            return 0;
        }
    }
    if (((u8 *)&s->flags)[1] != 0 && func_L02_003E6F38(h, *(f32 *)((u8 *)a + 0x18), 0.01f) == 0) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L02_00352F60 */
