/* NTSC-U draft (Claude wave C3): C of func_L07_003DB748, the NTSC-U twin of func_L07_003DD3C8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L07_003DB748", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (native MATCH, 528 B) only with an extra @ps2as on the PAL counterpart file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division): its float constants are lui/ori/mtc1 in retail, gp-relative .lit4 loads with plain ee-as. 528 B six-state ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L07_003DD3C8 (src/levels/07_annihilation_nation/L07_003DCB60.c) */
/* localdecomp:start func_L07_003DB748 */
typedef struct Link_3DD3C8 {
    u8 pad0[0xF0];
    f32 fF0;
} Link_3DD3C8;
typedef struct Obj_3DD3C8 {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x68 - 0x21];
    u8 *vars;
    u8 pad6C[0xF0 - 0x6C];
    f32 fF0;
} Obj_3DD3C8;
typedef struct Vars_3DD3C8 {
    u8 pad0[8];
    u8 b8;
    u8 pad9[0x20 - 9];
    u8 s20[0x30];
    u8 s50[0x10];
    Link_3DD3C8 *p60;
    f32 f64;
} Vars_3DD3C8;
extern void func_L07_003DB958(void *);
extern s32 func_L01_00452EC8(void *);
extern void func_0039FE80(s32, s32, void *);
extern void func_00388F50(void *, void *, void *);
extern void func_L07_003DBAD0(void *);
extern void func_L01_004A6D70(s32, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_003BE6A8(f32, f32, f32);
extern void func_003C26C8(void *);

void func_L07_003DB748(Obj_3DD3C8 *obj) {
    Vars_3DD3C8 *vars;
    f32 f;

    func_L07_003DB958(obj);
    vars = (Vars_3DD3C8 *)obj->vars;
    switch (obj->b20) {
    case 0:
        break;
    case 1:
        if (vars->b8 == 2) {
            func_L01_00441FB8(obj, 4, -1);
        }
        break;
    case 2:
        if (func_L01_00452EC8(obj) != 0) {
            func_0039FE80(1, 4, obj);
        }
        func_00388F50(vars->s20, vars->s20, vars->s50);
        func_L07_003DBAD0(obj);
        if (vars->b8 == 1) {
            func_L01_004A6D70(1, obj);
            func_L01_00441FB8(obj, 5, -1);
        }
        break;
    case 3:
        break;
    case 4:
        if (func_L01_00452EC8(obj) != 0) {
            func_0039FE80(0, 4, obj);
        }
        vars->f64 = vars->f64 + 0.01f;
        if (vars->f64 >= 1.0f) {
            vars->f64 = 1.0f;
            func_L01_004A6D70(0, obj);
            func_L01_00441FB8(obj, 2, -1);
        }
        f = func_003BE6A8(3.1415927f, 0.0f, vars->f64);
        obj->fF0 = f;
        vars->p60->fF0 = f;
        func_003C26C8(vars->p60);
        break;
    case 5:
        if (func_L01_00452EC8(obj) != 0) {
            func_0039FE80(0, 4, obj);
        }
        vars->f64 = vars->f64 - 0.01f;
        if (vars->f64 <= 0.0f) {
            vars->f64 = 0.0f;
            func_L01_004A6D70(0, obj);
            func_L01_00441FB8(obj, 1, -1);
        }
        f = func_003BE6A8(3.1415927f, 0.0f, vars->f64);
        obj->fF0 = f;
        vars->p60->fF0 = f;
        func_003C26C8(vars->p60);
        break;
    }
}
/* localdecomp:end func_L07_003DB748 */
