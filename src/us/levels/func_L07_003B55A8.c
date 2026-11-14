#include "common.h"

/* NTSC-U counterpart of func_L07_003B6E98 (src/levels/07_annihilation_nation/L07_003AF398.c) */
/* localdecomp:start func_L07_003B55A8 */
typedef struct V4_3B6E98 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_3B6E98;
typedef struct Obj_3B6E98 {
    u8 pad0[0x68];
    u8 *vars;
    u8 pad6C[0xF8 - 0x6C];
    f32 fF8;
} Obj_3B6E98;
typedef struct Vars_3B6E98 {
    u8 pad0[0x44];
    u8 b44;
    u8 pad45[0x80 - 0x45];
    V4_3B6E98 q80;
    u8 pad90[0x31A - 0x90];
    s16 h31A;
    u8 pad31C;
    u8 b31D;
} Vars_3B6E98;
extern void func_003BDA38(void *, s32, void *);
extern f32 func_L07_003B54D8(void *, void *);
extern f32 func_00389468(f32, f32);
extern f32 func_003BE6A8(f32, f32, f32);
extern f32 func_00388800(void *, void *);
extern f32 func_00388A28(f32, f32);
extern s32 func_L07_003B00A0(void *, void *, f32, f32, u8);
extern void func_L07_00470548(void *, s32, u32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L07_003B55A8(Obj_3B6E98 *obj, s32 arg1) {
    V4_3B6E98 a;
    V4_3B6E98 b;
    Vars_3B6E98 *vars = (Vars_3B6E98 *)obj->vars;
    s32 id = (u8)(arg1 + 2);
    f32 one;
    f32 ratio;
    f32 ang;
    f32 s;
    f32 t;

    func_003BDA38(obj, id, &a);
    one = 1.0f;
    ratio = func_00389468(func_L07_003B54D8(obj, &vars->q80), obj->fF8) / 0.5235988f;
    if (ratio > one) {
        ratio = one;
    }
    s = -0.5f;
    t = func_003BE6A8(s, -2.0f, ratio);
    b = vars->q80;
    b.z = b.z + t;
    ang = func_00388A28(func_00388800(&a, &b), b.z - a.z);
    if (vars->h31A != 0) {
        ang = ang * ((f32)vars->h31A / 90.0f + one);
    }
    func_L07_003B00A0(obj, &a, obj->fF8, -ang, vars->b44);
    if ((u8)(vars->b31D - 1) < 2) {
        s = 0.5f;
    }
    func_L07_00470548(obj, id, 0xBF804020, 0, 8, 0, 1, 0x35, 0, 735000.0f, 21000.0f, s);
    func_L07_00470548(obj, id, 0xBFA04020, 0, 8, 0, 1, 0x35, 0, 525000.0f, 21000.0f, s);
    func_L07_00470548(obj, id, 0xC0FFFFFF, 0, 8, 0, 1, 0x35, 0, 367500.0f, 21000.0f, s);
    func_L07_00470548(obj, id, 0xB0FFFFFF, 0, 8, 0, 1, 0x35, 0, 262500.0f, 21000.0f, s);
}
/* localdecomp:end func_L07_003B55A8 */
