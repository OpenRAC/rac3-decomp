#include "common.h"

/* NTSC-U counterpart of func_L07_003AF398 (src/levels/07_annihilation_nation/L07_003AF398.c) */
/* localdecomp:start func_L07_003ADB20 */
typedef struct Obj_3AF398 {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x68 - 0x21];
    u8 *vars;
    u8 pad6C[0x96 - 0x6C];
    u16 h96;
} Obj_3AF398;
typedef struct Vars_3AF398 {
    u8 pad0[0xD4];
    f32 fD4;
    u8 padD8[0xE8 - 0xD8];
    s16 hE8;
} Vars_3AF398;
extern void func_L07_003ADD88(void *);
extern void func_L07_003ADE00(void *);
extern s32 func_L07_003ADEE0(void *);
extern void func_0039FE80(s32, s32, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L07_003ADF80(void *);
extern void func_L07_003ADF40(void *, f32);
extern s32 func_L01_00452EC8(void *);
extern void func_L07_003AE0A8(void *);
extern s32 func_003883C8(void *);
extern void func_L01_004A6D70(s32, void *);

void func_L07_003ADB20(Obj_3AF398 *obj) {
    Vars_3AF398 *vars;

    func_L07_003ADD88(obj);
    func_L07_003ADE00(obj);
    vars = (Vars_3AF398 *)obj->vars;
    switch (obj->b20) {
    case 1:
        if (func_L07_003ADEE0(obj) != 0) {
            func_0039FE80(1, 4, obj);
            func_L01_00441FB8(obj, 2, -1);
        }
        break;
    case 2:
        vars->fD4 = vars->fD4 + 0.0069813174f;
        if (vars->fD4 > 0.20943953f) {
            vars->fD4 = 0.20943953f;
            func_L01_00441FB8(obj, 3, -1);
        }
        func_L07_003ADF80(obj);
        func_L07_003ADF40(obj, vars->fD4);
        if (func_L07_003ADEE0(obj) == 0) {
            func_L01_00441FB8(obj, 4, -1);
        }
        break;
    case 3:
        if (func_L01_00452EC8(obj) != 0) {
            vars->hE8 = 0x12C;
        }
        obj->h96 = obj->h96 + 1;
        if (obj->h96 >= 7) {
            func_0039FE80(0, 0, obj);
            func_L07_003AE0A8(obj);
            obj->h96 = 0;
        }
        func_L07_003ADF80(obj);
        func_L07_003ADF40(obj, vars->fD4);
        if (func_003883C8(&vars->hE8) != 0 || func_L07_003ADEE0(obj) == 0) {
            func_L01_00441FB8(obj, 4, -1);
        }
        break;
    case 4:
        vars->fD4 = vars->fD4 - 0.0069813174f;
        if (vars->fD4 <= 0.0f) {
            vars->fD4 = 0.0f;
            if (func_L07_003ADEE0(obj) != 0) {
                func_L01_00441FB8(obj, 5, -1);
            } else {
                func_L01_004A6D70(1, obj);
                func_L01_00441FB8(obj, 1, -1);
            }
        }
        func_L07_003ADF40(obj, vars->fD4);
        break;
    case 5:
        if (func_L01_00452EC8(obj) != 0) {
            vars->hE8 = 0x78;
        }
        if (func_L07_003ADEE0(obj) == 0) {
            func_L01_004A6D70(1, obj);
            func_L01_00441FB8(obj, 1, -1);
        } else if (func_003883C8(&vars->hE8) != 0) {
            func_L01_00441FB8(obj, 2, -1);
        }
        break;
    }
}
/* localdecomp:end func_L07_003ADB20 */
