#include "common.h"

/* NTSC-U counterpart of func_L07_003304C0 (src/levels/07_annihilation_nation/L07_0032F598.c) */
/* localdecomp:start func_L07_0032FD90 */
typedef struct Hero_3304C0 {
    u8 pad0[0x25C4];
    s32 w25C4;
    u8 pad25C8[0x2850 - 0x25C8];
    union {
        s32 w;
        u8 b;
    } u2850;
} Hero_3304C0;
typedef struct Obj_3304C0 {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x68 - 0x21];
    u8 *vars;
} Obj_3304C0;
typedef struct Vars_3304C0 {
    u8 pad0[0xC0];
    f32 fC0;
    f32 fC4;
    s32 wC8;
    f32 fCC;
    s16 hD0;
    s16 hD2;
    s16 hD4;
    s16 hD6;
    s16 hD8;
    u8 padDA[5];
    u8 bDF;
} Vars_3304C0;
extern Hero_3304C0 D_001A4BE0;
extern s32 D_001D545C_sda_0032FD90;
__asm__(".extern D_001D545C_sda_0032FD90, 4");
extern f32 D_001DA9B0_sda;
__asm__(".extern D_001DA9B0_sda, 4");
extern u8 D_0014275B[];
__asm__(".extern D_0014275B, 16");
extern f32 D_L07_002F3410[];
__asm__(".extern D_L07_002F3410, 16");
extern s32 func_L07_003C01A8(void);
extern f32 func_L07_003C01F0(s32);
extern s32 func_L01_00417EA0(void);
extern void func_L07_00334428(void *);
extern void func_L07_00334468(void *);
extern void func_L07_003344A8(void *);
extern void func_L07_003344E8(void *);
extern s32 func_L07_003A0D08(void);
extern s32 func_L07_00334780(void *);
extern s32 func_0037E1D8(s32);
extern s32 func_003883C8(void *);

void func_L07_0032FD90(Obj_3304C0 *obj) {
    Vars_3304C0 *vars;
    f32 scale;
    f32 f;
    s32 n;
    s32 prev;
    s32 lt;

    vars = (Vars_3304C0 *)obj->vars;
    if (obj->b20 >= 4 && obj->b20 <= 7) {
        if (D_001A4BE0.w25C4 != 0x74) {
            scale = func_L07_003C01F0(func_L07_003C01A8());
            if (func_L01_00417EA0() != 0) {
                n = D_001D545C_sda_0032FD90;
                if (n == 7 && D_0014275B[0] != 0) {
                    f = D_001DA9B0_sda;
                } else {
                    f = D_L07_002F3410[n];
                }
                scale = scale * f;
            }
            if (vars->hD4 == 0 && 3.0f < vars->fCC) {
                func_L07_00334428(obj);
                vars->hD4 = func_0037E1D8(0x4B0) + 0x960;
                vars->fCC = 0.0f;
            }
            if (vars->hD2 == 0 && scale * 20.0f < vars->fC4) {
                func_L07_00334468(obj);
                vars->hD2 = func_0037E1D8(0x4B0) + 0x960;
                vars->fC4 = 0.0f;
            }
            if (vars->hD0 == 0 && (10.0f < (f32)vars->wC8 || scale * 40.0f < vars->fC0)) {
                func_L07_003344A8(obj);
                vars->hD0 = func_0037E1D8(0x4B0) + 0x960;
                vars->wC8 = 0;
                vars->fC0 = 0.0f;
            }
            prev = vars->bDF;
            lt = D_001A4BE0.u2850.w < prev;
            vars->bDF = D_001A4BE0.u2850.b;
            if (vars->hD6 == 0 && lt) {
                func_L07_003344E8(obj);
                vars->hD6 = func_0037E1D8(0x4B0) + 0x960;
            }
            if (vars->hD8 == 0 && func_L07_003A0D08() >= 0x384 && func_L07_00334780(obj) != 0) {
                vars->hD8 = func_0037E1D8(0x4B0) + 0x960;
            }
            vars->fCC = vars->fCC * 0.9f;
            vars->fC4 = vars->fC4 * 0.9f;
            func_003883C8(&vars->hD4);
            func_003883C8(&vars->hD2);
            func_003883C8(&vars->hD0);
            func_003883C8(&vars->hD6);
            func_003883C8(&vars->hD8);
        }
    }
}
/* localdecomp:end func_L07_0032FD90 */
