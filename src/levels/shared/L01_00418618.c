#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00418618 */
typedef int u128_00418618 __attribute__((mode(TI)));
typedef struct {
    vu0_v4 v0;
    vu0_v4 v10;
    u8 pad20[0x10];
    vu0_v4 axis;
    f32 f40;
    f32 f44;
    s32 w48;
    u8 pad4C[4];
    s32 w50;
    f32 f54;
} Probe_00418618;

extern s32 func_003E3DF0(void);
extern u8 D_001D5470[8];
__asm__(".extern D_001D5470, 16");
extern Probe_00418618 D_L01_001EA760_00418618;
extern u8 D_L01_001D66B0[8];
__asm__(".extern D_L01_001D66B0, 16");
extern vu0_v4 D_001A4C60;
extern vu0_v4 D_L01_001E29C0_00418618[];
extern void func_L01_004C7D98(void *, void *);
extern s32 func_L01_00513EF0(void);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00510AD0(void);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038DB48(f32);
extern void func_0038D890(void *, void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);

void func_L01_00418618(void) {
    Probe_00418618 *o;
    vu0_v4 t;
    vu0_v4 r0;
    vu0_v4 r1;
    vu0_v4 d;
    f32 len;
    f32 f;
    s32 i;
    s32 k;

    if (func_003E3DF0() == 0) {
        return;
    }
    if (D_001D5470[4] == 0) {
        return;
    }
    o = &D_L01_001EA760_00418618;
    *(u128_00418618 *)o = *(u128_00418618 *)D_L01_001D66B0;
    f = -o->f44;
    o->w48 = 0;
    o->f44 = f;
    if (f == *(f32 *)&o->w48) {
        o->f44 = 1.0f;
    }
    o->w50 = 0;
    func_L01_004C7D98(&D_001A4C60, &o->axis);
    if (func_L01_00513EF0() == 2) {
        func_0038CF68(&t, *(u8 **)((u8 *)&D_001A4C60 + 0x2540) + 0xC0, -4.0f);
        vec_add_ab(&D_L01_001E29C0_00418618[0], &D_L01_001E29C0_00418618[0], &t);
        func_L01_00510AD0();
    }
    vec_sub_ba(&t, &D_001A4C60, &D_L01_001E29C0_00418618[0]);
    len = func_0038CE68(&D_L01_001E29C0_00418618[2], &t);
    func_0038CF68(o, &D_L01_001E29C0_00418618[2], len);
    len = func_0038CEA8(o);
    vec_add_ba(&D_L01_001EA760_00418618.v0, &D_L01_001EA760_00418618.v0, &D_L01_001E29C0_00418618[0]);
    D_L01_001EA760_00418618.f40 = len;
    D_L01_001EA760_00418618.v10 = D_L01_001EA760_00418618.v0;
    for (i = 0; i < 4; i++) {
        D_L01_001EA760_00418618.f54 = len * (1.0f - (f32)i / 7.0f);
        vec_sub_ab(&d, &D_L01_001E29C0_00418618[0], &D_L01_001EA760_00418618.v10);
        func_0038CF68(&d, &d, D_L01_001EA760_00418618.f54);
        D_L01_001EA760_00418618.w50 = 0;
        for (k = 0; k < 15; k++) {
            func_0038D890(&r0, &d, &D_L01_001EA760_00418618.axis, func_0038DB48((f32)k * 6.2831855f / 15.0f));
            vec_add_ba(&r0, &r0, &D_L01_001EA760_00418618.v10);
            func_0038D890(&r1, &d, &D_L01_001EA760_00418618.axis, func_0038DB48((f32)(k + 1) * 6.2831855f / 15.0f));
            vec_add_ba(&r1, &r1, &D_L01_001EA760_00418618.v10);
            if (func_003D3CB0(&r0, &r1, 0x80, 0, 0) != 0) {
                D_L01_001EA760_00418618.w50 = 1;
                break;
            }
        }
        if (D_L01_001EA760_00418618.w50 == 0) {
            break;
        }
    }
}
/* localdecomp:end func_L01_00418618 */
