#include "common.h"

/* NTSC-U counterpart of func_L20_003F4A78 (src/levels/20_final_boss/L20_003F45B8.c) */
/* localdecomp:start func_L20_003F2928 */
typedef struct Vars_3F4A78 {
    u8 pad0[0x10];
    u8 slot[2][0x10];
    u8 pad30[0xA0 - 0x30];
    s32 wA0;
} Vars_3F4A78;
extern s32 D_001DF4A4_sda;
__asm__(".extern D_001DF4A4_sda, 4");
extern s32 D_001DF4A8_sda;
__asm__(".extern D_001DF4A8_sda, 4");
extern s32 D_001DF4AC_sda;
__asm__(".extern D_001DF4AC_sda, 4");
extern s32 D_001DF4B0_sda;
__asm__(".extern D_001DF4B0_sda, 4");
extern s32 D_001DF4B4_sda;
__asm__(".extern D_001DF4B4_sda, 4");
extern f32 D_001DF4B8_sda;
__asm__(".extern D_001DF4B8_sda, 4");
extern f32 D_001DF4BC_sda;
__asm__(".extern D_001DF4BC_sda, 4");
extern f32 D_001DF4C0_sda_003F2928;
__asm__(".extern D_001DF4C0_sda_003F2928, 4");
extern f32 D_001DF4C4_sda;
__asm__(".extern D_001DF4C4_sda, 4");
extern f32 D_001DF4C8_sda;
__asm__(".extern D_001DF4C8_sda, 4");
extern f32 D_001DF4CC_sda;
__asm__(".extern D_001DF4CC_sda, 4");
extern s32 D_001DF4D0_sda;
__asm__(".extern D_001DF4D0_sda, 4");
extern s32 D_001DF4D4_sda;
__asm__(".extern D_001DF4D4_sda, 4");
extern f32 D_001DF4D8_sda;
__asm__(".extern D_001DF4D8_sda, 4");
extern f32 D_001DF4DC_sda_003F2928;
__asm__(".extern D_001DF4DC_sda_003F2928, 4");
extern f32 D_001DF4E0_sda;
__asm__(".extern D_001DF4E0_sda, 4");
extern f32 D_001DF4E4_sda;
__asm__(".extern D_001DF4E4_sda, 4");
extern f32 D_001DF4E8_sda;
__asm__(".extern D_001DF4E8_sda, 4");
extern f32 D_001DF4EC_sda;
__asm__(".extern D_001DF4EC_sda, 4");
extern void func_L20_003F2298(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E1D8(s32);
extern void func_L20_003F27E0(void *);
extern void func_L20_003F26B0(void *, s32, s32, s32, void *, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_00388398(void *);
extern void func_003BD360(void *);

void func_L20_003F2928(void *arg0) {
    u8 *obj = (u8 *)arg0;
    Vars_3F4A78 *vars = *(Vars_3F4A78 **)(obj + 0x68);
    s32 i;
    s32 j;
    f32 k;
    s32 *tm;

    switch (obj[0x20]) {
    case 0:
        func_L20_003F2298(obj);
        func_L01_00441FB8(obj, 1, -1);
        vars->wA0 = D_001DF4A4_sda;
        break;
    case 1:
        i = 0;
        tm = &vars->wA0;
        for (; i < 2; i++) {
            if (i <= 0) {
                if (func_0037E1D8(D_001DF4AC_sda) == 0) {
                    func_L20_003F27E0(vars->slot[i]);
                }
            }
            if (func_0037E1D8(D_001DF4B0_sda) == 0) {
                func_L20_003F26B0(vars->slot[i], D_001DF4B4_sda, 2, 3, vars, D_001DF4B8_sda, D_001DF4BC_sda, D_001DF4C0_sda_003F2928, 2.0f, D_001DF4C4_sda, D_001DF4C8_sda, D_001DF4CC_sda);
            }
        }
        if (func_00388398(tm) != 0) {
            func_L01_00441FB8(obj, 2, -1);
            vars->wA0 = D_001DF4A8_sda;
        }
        break;
    case 2:
        k = 0.75f;
        tm = &vars->wA0;
        for (j = 1; j >= 0; j--) {
            if (func_0037E1D8(D_001DF4D0_sda) == 0) {
                if (func_0037E1D8(2) != 0) {
                    func_L20_003F26B0(obj + 0x10, D_001DF4D4_sda, 2, 3, vars, D_001DF4D8_sda, D_001DF4DC_sda_003F2928, D_001DF4E0_sda, 0.25f, D_001DF4E4_sda, D_001DF4E8_sda, D_001DF4EC_sda);
                } else {
                    func_L20_003F26B0(obj + 0x10, D_001DF4D4_sda, 2, 3, vars, D_001DF4D8_sda, D_001DF4DC_sda_003F2928, D_001DF4E0_sda, 0.5f, D_001DF4E4_sda * k, D_001DF4E8_sda, D_001DF4EC_sda);
                }
            }
        }
        if (func_00388398(tm) != 0) {
            func_L01_00441FB8(obj, 4, -1);
        }
        break;
    case 3:
        break;
    case 4:
        func_003BD360(obj);
        break;
    }
}
/* localdecomp:end func_L20_003F2928 */
