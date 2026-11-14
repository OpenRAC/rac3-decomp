#include "common.h"

/* NTSC-U counterpart of func_L07_003C0458 (src/levels/07_annihilation_nation/L07_003C0458.c) */
/* localdecomp:start func_L07_003BEB08 */
typedef struct Hero_3C0458 {
    u8 pad0[0x35C];
    void *w35C;
    s32 w360;
} Hero_3C0458;
typedef struct Vars_3C0458 {
    s32 w0;
    s32 w4;
    f32 f8;
    u8 padC[4];
    s32 w10;
    s32 w14;
} Vars_3C0458;
extern Hero_3C0458 D_001A4BE0;
extern s32 D_001DE578_sda;
__asm__(".extern D_001DE578_sda, 4");
extern s32 D_001DE57C_sda;
__asm__(".extern D_001DE57C_sda, 4");
extern f32 D_001DE580_sda;
__asm__(".extern D_001DE580_sda, 4");
extern u8 *D_L07_001DF41C_003BEB08;
__asm__(".extern D_L07_001DF41C_003BEB08, 16");
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_004A72A8(s32, s32, void *, s32);
extern s32 func_00388398(void *);
extern f32 func_00388978(f32);
extern s32 func_L01_0040D068(s32, u32);
extern s32 func_003894A0(s32, f32, s32);

void func_L07_003BEB08(void *arg0) {
    u8 *obj = (u8 *)arg0;
    Vars_3C0458 *vars = *(Vars_3C0458 **)(obj + 0x68);
    f32 pulse;
    f32 t;
    f32 u;
    s32 c;
    u8 *e;

    if (obj[0x20] == 0) {
        vars->f8 = *(f32 *)(obj + 0x18);
        *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 0x10;
        func_L01_00441FB8(obj, 1, -1);
    }
    switch (obj[0x20]) {
    case 1:
        vars->w10 = D_001DE578_sda;
        break;
    case 2:
        if (D_001A4BE0.w360 != 0 && D_001A4BE0.w35C == obj) {
            vars->w10 = D_001DE57C_sda;
            u = vars->f8;
            t = D_001DE580_sda;
            *(f32 *)(obj + 0x18) = u - t;
            func_L01_00441FB8(obj, 3, -1);
        }
        break;
    case 3:
        func_L01_004A72A8(0, 0, obj, 0x1ACF);
        e = D_L07_001DF41C_003BEB08 + (vars->w0 << 8);
        e[0xBE] |= 4;
        if (vars->w4 != -1) {
            e = D_L07_001DF41C_003BEB08 + (vars->w4 << 8);
            e[0xBE] |= 4;
        }
        func_L01_00441FB8(obj, 4, -1);
        break;
    }
    if (func_00388398(&vars->w14) != 0) {
        vars->w14 = 0x3C;
    }
    pulse = func_00388978((f32)vars->w14 * 6.2831855f / 60.0f) * 0.5f + 0.5f;
    c = func_L01_0040D068(vars->w10, 0x80B0B0B0);
    *(s32 *)(obj + 0x78) = func_003894A0(c, pulse, func_L01_0040D068(vars->w10, 0x80505050));
}
/* localdecomp:end func_L07_003BEB08 */
