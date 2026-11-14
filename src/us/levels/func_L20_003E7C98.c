#include "common.h"

/* NTSC-U counterpart of func_L20_003E9BA8 (src/levels/20_final_boss/L20_003E6150.c) */
#include "vu0.h"

/* localdecomp:start func_L20_003E7C98 */
typedef struct Vars_3E9BA8 {
    f32 f0;
    f32 f4;
    u8 pad8[0x2C - 0x8];
    f32 f2C;
    u8 pad30[0xC50 - 0x30];
    vu0_v4 vecs[12];
    f32 rot[12];
    f32 fD40;
} Vars_3E9BA8;
extern f32 D_001DF260_sda;
__asm__(".extern D_001DF260_sda, 4");
extern s32 D_001DF258_sda;
__asm__(".extern D_001DF258_sda, 4");
extern s32 D_001DF25C_sda;
__asm__(".extern D_001DF25C_sda, 4");
extern f32 D_001DF264_sda;
__asm__(".extern D_001DF264_sda, 4");
extern f32 D_001DF268_sda;
__asm__(".extern D_001DF268_sda, 4");
extern f32 D_001DF26C_sda;
__asm__(".extern D_001DF26C_sda, 4");
extern u32 D_001DF270_sda_003E7C98;
__asm__(".extern D_001DF270_sda_003E7C98, 4");
extern u32 D_001DF274_sda;
__asm__(".extern D_001DF274_sda, 4");
extern vu0_v4 D_L20_001E2E00;
extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_003D3FA0(void *, s32, u32, s32, f32, f32, f32);
extern void func_00389158(void *, void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_004084B0(void *, void *, u32, s32, u32, u32, u32, u32, f32, f32, f32);

void func_L20_003E7C98(u8 *obj) {
    vu0_v4 w;
    vu0_v4 p;
    vu0_v4 q;
    Vars_3E9BA8 *vars;
    s32 i;
    s32 col;

    vars = *(Vars_3E9BA8 **)(obj + 0x68);
    col = func_003894A0(D_001DF258_sda, D_001DF25C_sda, func_00388978(D_001DF260_sda) * 0.5f + 0.5f);
    D_001DF260_sda = func_00389380(D_001DF260_sda, func_0037E250(D_001DF264_sda, D_001DF268_sda) * 0.017453292f * 0.016666668f);
    func_003D3FA0(obj + 0x10, 0x43, col, 1, 2.25f, -0.1f, vars->f0);
    func_003D3FA0(obj + 0x10, 0x31, 0x7FFFFFFF, 1, 1.0f, 0.0f, -vars->f4);
    func_003D3FA0(obj + 0x10, 0x4B, 0xDFFFFFFF, 3, 2.0f, 0.025f, -vars->f0);
    for (i = 0; i < 12; i++) {
        vec_sub_ab(&w, &D_L20_001E2E00, obj + 0x10);
        func_00389158(&vars->vecs[i], &vars->vecs[i], &w, vars->rot[i]);
        vars->f2C = vars->f2C + 0.03f;
        if (vars->f2C > 2.5f) {
            vars->f2C = 2.5f;
        }
        func_00388830(&vars->vecs[i], &vars->vecs[i], vars->f2C);
        vec_add_ab(&p, &vars->vecs[i], obj + 0x10);
        q = *(vu0_v4 *)(obj + 0x10);
        func_L01_004084B0(&p, &q, 0x12, 1, D_001DF270_sda_003E7C98, D_001DF270_sda_003E7C98, D_001DF274_sda, D_001DF274_sda, D_001DF26C_sda, 3.0f, vars->fD40);
    }
    vars->fD40 = vars->fD40 - func_0037E250(0.025f, 0.035f);
    if (vars->fD40 <= -8.0f) {
        vars->fD40 = vars->fD40 + 8.0f;
    }
}
/* localdecomp:end func_L20_003E7C98 */
