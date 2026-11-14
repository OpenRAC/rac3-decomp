#include "common.h"

/* NTSC-U counterpart of func_L30_00341E38 (src/levels/30_vidcomic_unnamed/L30_003417B8.c) */
/* localdecomp:start func_L30_003411D0 */
typedef int Quad_341E38 __attribute__((mode(TI)));
typedef struct Model_341E38 {
    u8 pad0[0x24];
    f32 f24;
} Model_341E38;
typedef struct Obj_341E38 {
    u8 pad0[0x10];
    Quad_341E38 pos;
    u8 pad20[4];
    Model_341E38 *model;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[0x68 - 0x30];
    u8 *vars;
    u8 pad6C[0x95 - 0x6C];
    u8 b95;
} Obj_341E38;
typedef struct Vars_341E38 {
    u8 pad0[0x38];
    u8 b38;
    u8 pad39[0x70 - 0x39];
    f32 f70, f74, f78, f7C, f80, f84, f88, f8C, f90, f94, f98;
    u8 pad9C[4];
    f32 fA0, fA4;
    s32 wA8;
    u8 padAC[0x170 - 0xAC];
    u8 b170;
    u8 pad171[0x190 - 0x171];
    f32 f190, f194;
    u8 pad198[4];
    f32 f19C;
    u8 pad1A0[8];
    u8 b1A8;
    u8 pad1A9[0x240 - 0x1A9];
    Quad_341E38 q240;
    u8 pad250[0x298 - 0x250];
    s32 w298;
    u8 pad29C[4];
    s32 w2A0;
    u8 pad2A4[0x2B0 - 0x2A4];
    u8 s2B0[0x10];
    u8 s2C0[0x10];
} Vars_341E38;
extern void func_003BDA38(void *, s32, void *);
extern s32 func_L30_003401B0(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32);

void func_L30_003411D0(Obj_341E38 *obj) {
    Vars_341E38 *vars = (Vars_341E38 *)obj->vars;
    f32 t = obj->f2C / obj->model->f24;

    vars->b170 = 3;
    vars->b1A8 = obj->b95;
    vars->b38 = 3;
    vars->fA4 = t * 0.05f;
    vars->f74 = t * 0.25f;
    vars->f194 = 0.5f;
    vars->f84 = 0.20943953f;
    vars->f19C = 0.4f;
    vars->f88 = 0.20943953f;
    vars->f70 = t * 0.5f;
    vars->f78 = 0.4f;
    vars->f7C = 0.4f;
    vars->f80 = 0.7853982f;
    vars->fA0 = 0.5235988f;
    vars->f190 = 0.5f;
    vars->q240 = obj->pos;
    vars->f90 = t * 0.00083333335f;
    vars->f94 = t * 0.00083333335f;
    vars->f84 = 0.0069813174f;
    vars->f98 = t * 0.20000002f;
    vars->f88 = 0.0069813174f;
    vars->f8C = 0.41887906f;
    vars->wA8 |= 0x10;
    func_003BDA38(obj, 2, vars->s2B0);
    func_003BDA38(obj, 3, vars->s2C0);
    vars->w2A0 = func_L30_003401B0(vars->s2B0, obj, vars->s2C0, 0x32, 0x32, 0x14, 5, 0xFF0808, 0xFF0808, 1, -1, 1, 0.2f, 0.22f, 0.1f, 1.3f);
    vars->w298 = 0;
}
/* localdecomp:end func_L30_003411D0 */
