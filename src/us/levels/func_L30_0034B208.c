#include "common.h"

/* NTSC-U counterpart of func_L30_0034C0E8 (src/levels/shared/L30_0034C0E8.c) */
/* localdecomp:start func_L30_0034B208 */
#include "vu0.h"
extern f32 D_001DD4B8_sda;
__asm__(".extern D_001DD4B8_sda, 4");
extern f32 D_001DD4BC_sda;
__asm__(".extern D_001DD4BC_sda, 4");
extern f32 D_001DD4C0_sda;
__asm__(".extern D_001DD4C0_sda, 4");
extern s32 D_001DD4C4_sda;
__asm__(".extern D_001DD4C4_sda, 4");
extern f32 D_001DD4C8_sda;
__asm__(".extern D_001DD4C8_sda, 4");
extern f32 D_001DD4CC_sda;
__asm__(".extern D_001DD4CC_sda, 4");
extern f32 D_001DD4D0_sda;
__asm__(".extern D_001DD4D0_sda, 4");
extern f32 D_001DD4D4_sda;
__asm__(".extern D_001DD4D4_sda, 4");
extern s32 D_001DD4D8_sda;
__asm__(".extern D_001DD4D8_sda, 4");
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern s32 func_003894A0(s32, s32, f32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_00467DA8(f32 *, s32, s32, s32, s32, void *, f32, f32, f32, s32);

typedef struct Vars_34C0E8 {
    u8 pad0[0x20];
    s32 w20;
    s32 w24;
    u8 pad28[4];
    f32 w2C;
} Vars_34C0E8;

void func_L30_0034B208(void *arg0) {
    u8 *obj = (u8 *)arg0;
    Vars_34C0E8 *vars = *(Vars_34C0E8 **)(obj + 0x68);
    f32 lv[4];
    f32 vel[4];
    s32 dir;

    vars->w2C = vars->w2C + D_001DD4D4_sda;
    if (vars->w2C > 1.0f) {
        do {
            f32 size;
            s32 col;
            vars->w2C = vars->w2C - 1.0f;
            qzero(lv);
            lv[0] = func_0037E250(-D_001DD4C8_sda, D_001DD4C8_sda);
            lv[2] = func_0037E250(-D_001DD4C8_sda, D_001DD4C8_sda);
            vec_add_ba(lv, lv, obj + 0x10);
            qzero(vel);
            col = func_003894A0(vars->w20, vars->w24, func_0037E250(0.0f, 1.0f));
            size = func_0037E250(D_001DD4CC_sda, D_001DD4D0_sda);
            func_L01_0046DCB8(lv, vel, D_001DD4C4_sda, col, func_0037E208(-4, 4), 0x80, 0, size, 0.0f, D_001DD4C0_sda, D_001DD4D8_sda);
        } while (vars->w2C > 1.0f);
    }
    if (func_0037E1D8(2) == 0) {
        f32 size = func_0037E250(D_001DD4B8_sda, D_001DD4BC_sda);
        dir = func_0037E1D8(2);
        if (dir == 0) {
            dir--;
        }
        func_L01_00467DA8((f32 *)(obj + 0x10), 5, 0x7F7F2020, 0, dir, (f32 *)vars, size * 0.1f, size, 0.0f, 0);
        func_L01_00467DA8((f32 *)(obj + 0x10), 5, 0x7F7F7F7F, 1, -dir, (f32 *)vars, size * 0.07f, size * 0.7f, 0.0f, 0);
    }
}
/* localdecomp:end func_L30_0034B208 */
