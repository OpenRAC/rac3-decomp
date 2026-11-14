#include "common.h"

/* NTSC-U counterpart of func_L07_003B37D0 (src/levels/07_annihilation_nation/L07_003AF398.c) */
extern void func_L07_003B1F10(u8 *, s32);

/* localdecomp:start func_L07_003B1F10 */
typedef struct Obj_3B37D0 {
    u8 pad0[0x34];
    u16 h34;
    u8 pad36[0x43 - 0x36];
    u8 b43;
    u8 pad44[0x68 - 0x44];
    u8 *vars;
    u8 pad6C[0x95 - 0x6C];
    u8 b95;
} Obj_3B37D0;
typedef struct Vars_3B37D0 {
    u8 pad0[0xC8];
    f32 fC8;
    u8 padCC[0xD8 - 0xCC];
    s32 wD8;
    u8 padDC[0x658 - 0xDC];
    f32 f658;
    f32 f65C;
    s16 h660;
    u8 pad662[2];
    s16 h664;
    u8 pad666;
    u8 b667;
    u8 pad668[2];
    u8 b66A;
} Vars_3B37D0;
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00452F40(void *, s32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L07_003B1F10(u8 *arg0, s32 state) {
    Obj_3B37D0 *obj = (Obj_3B37D0 *)arg0;
    Vars_3B37D0 *vars = (Vars_3B37D0 *)obj->vars;

    switch (state) {
    case 1:
        break;
    case 2:
        if (obj->b43 != 1) {
            func_003BE4F0(obj, 1, 0, 0);
        }
        break;
    case 3:
        break;
    case 4:
        vars->fC8 = 0.16666667f;
        obj->h34 = obj->h34 | 0x5000;
        break;
    case 5:
        vars->h664 = func_0037E1D8(10) + 0x14;
        if (obj->b95 >= 2) {
            if (obj->b43 != 3) {
                func_003BE4F0(obj, 3, 0, 2);
            }
        } else {
            if (obj->b43 != 1) {
                func_003BE4F0(obj, 1, 0, 2);
            }
        }
        vars->fC8 = 0.16666667f;
        vars->wD8 = vars->wD8 | 0x10;
        break;
    case 6:
        vars->h660 = func_0037E1D8(0x1E) + 0x3C;
        break;
    case 7:
        func_L01_00452F40(obj, 0);
        vars->b66A = 0;
        vars->fC8 = (func_0037E250(0.0f, 1.0f) + 3.0f) * 0.016666668f;
        vars->f658 = func_0037E250(0.0f, 2.0f);
        vars->f65C = func_0037E250(0.0f, 2.0f);
        if (obj->b43 != 0) {
            func_003BE4F0(obj, 0, 0, 4);
        }
        break;
    case 8:
        vars->h660 = 0x32;
        break;
    case 9:
        vars->b667 = 1 << func_0037E208(0, 1);
        vars->h660 = func_0037E1D8(0x1E) + 0x3C;
        break;
    case 10:
        func_L01_00452F40(obj, 0);
        if (obj->b43 != 4) {
            func_003BE4F0(obj, 4, 0, 0);
        }
        break;
    case 11:
        if (obj->b43 != 6) {
            func_003BE4F0(obj, 6, 0, 0);
        }
        break;
    case 12:
        vars->b66A = 0;
        vars->b667 = 3;
        if (obj->b43 != 2) {
            func_003BE4F0(obj, 2, 0, 3);
        }
        break;
    }
    func_L01_00441FB8(obj, state, -1);
}
/* localdecomp:end func_L07_003B1F10 */
