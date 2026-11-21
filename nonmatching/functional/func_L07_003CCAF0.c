/* functional: high. Rewritten from PAL asm; every float constant checked bit for bit (retail 0x3D4CCCCE and 0x3BA4B5BF are one ulp off 0.05f and 0.005026549f). */
#include "common.h"
typedef int Quad_3CCAF0 __attribute__((mode(TI)));
typedef struct Obj_3CCAF0 {
    u8 pad0[0x10];
    Quad_3CCAF0 pos;
    u8 pad20[0x68 - 0x20];
    u8 *vars;
    u8 pad6C[0xF0 - 0x6C];
    Quad_3CCAF0 qF0;
} Obj_3CCAF0;
typedef struct Vars_3CCAF0 {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[0x44 - 0x36];
    u8 b44, b45, b46;
    u8 pad47[0x150 - 0x47];
    f32 f150, f154, f158, f15C, f160;
    u8 pad164[0x17C - 0x164];
    f32 f17C, f180, f184;
    u8 pad188[0x280 - 0x188];
    Quad_3CCAF0 q280;
    Quad_3CCAF0 q290;
    u8 pad2A0[0x400 - 0x2A0];
    s32 w400;
    u8 pad404[0x40C - 0x404];
    s32 w40C;
} Vars_3CCAF0;
extern void func_L01_00445F40(void *, s32);
extern s32 func_L07_003C1AF8(void *);
extern f32 func_L07_003C1B40(s32);
extern void func_L01_00446058(void *, s32, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L07_003CCDF8(void *);

void func_L07_003CCAF0(Obj_3CCAF0 *obj) {
    Vars_3CCAF0 *vars = (Vars_3CCAF0 *)obj->vars;
    u8 *p;
    u8 *q;
    s32 k;
    f32 scale;

    func_L01_00445F40(obj, 0x1769);
    k = func_L07_003C1AF8(obj);
    p = (u8 *)vars + 0x30;
    scale = func_L07_003C1B40(k);
    *(s16 *)(p + 4) = (f32)vars->h34 * scale;
    vars->f30 = (f32) * (s16 *)(p + 4);
    p[0x14] = (f32)vars->b44 * scale;
    p[0x15] = (f32)vars->b45 * scale;
    p[0x16] = (f32)vars->b46 * scale;
    if (k == 1) {
        func_L01_00446058(obj, 0x1D8B, 0x1769);
    }
    q = (u8 *)vars + 0x70;
    p[0x28] = 0x14;
    p[0x2A] = 0xE;
    *(f32 *)(p + 0x10) = 1.25f;
    p[0xF] = 0;
    p[9] = 0;
    q[0x48] = 0xFF;
    q[0x10] = 2;
    *(f32 *)(q + 0x30) = 0.5f;
    *(f32 *)(q + 0x34) = 0.5f;
    *(f32 *)(q + 0x3C) = 0.15f;
    if (vars->w40C != -1) {
        q[0x7B] = 0x1A;
        q[0x12] = 0x12;
        q[0x6F] = 0;
        q[0x11] = 0x12;
        q[0x78] = 0;
        q[0x6C] = 0;
        q[0x6D] = 0;
        q[0x79] = 0;
        q[0x6E] = 0;
    }
    vars->f150 = 0.65f;
    vars->f154 = 0.15f;
    vars->f158 = 0.5f;
    vars->f15C = 1.5f;
    vars->f160 = 1.4835298f;
    vars->f180 = 0.34906584f;
    vars->f17C = 0.00392f;
    vars->f184 = 0.2f;
    func_L01_0045BD78(obj, 0.0032000002f, 0.0500000045f, 0.00502654864f, 0.12566371f);
    vars->w400 = 0;
    vars->q280 = obj->pos;
    vars->q290 = obj->qF0;
    func_L07_003CCDF8(obj);
}
