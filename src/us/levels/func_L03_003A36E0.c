#include "common.h"

/* NTSC-U counterpart of func_L03_003A4FC8. */
/* localdecomp:start func_L03_003A36E0 */
typedef int Quad_3A36E0 __attribute__((mode(TI)));
typedef struct Vars_3A36E0 {
    s32 w0;
    f32 f4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
} Vars_3A36E0;
typedef struct Rec_3A36E0 {
    u8 pad0[0x10];
    f32 e10[4];
    f32 e20[4];
    Quad_3A36E0 pos;
    u8 pad40[0x40];
} Rec_3A36E0;
extern Rec_3A36E0 *D_L03_001DFB00;
__asm__(".extern D_L03_001DFB00, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001BBC40[];
extern void func_00388550(void *, void *, s32);
extern f32 func_00388770(void *);
extern void func_003886E8(void *, void *, f32);
extern void func_003C26C8(void *);
extern void func_003BD360(void *);
extern void func_L01_003F3CE0(void *);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L03_003A36E0(void *arg0) {
    u8 *obj = (u8 *)arg0;
    Vars_3A36E0 *vars = *(Vars_3A36E0 **)(obj + 0x68);
    f32 a;
    f32 b;
    u8 *dir;
    Rec_3A36E0 *tbl;

    vars->f4 = 1.0f;
    vars->w14 = -1;
    vars->w8 = 0;
    vars->w10 = 0;
    if (vars->w18 < 10) {
        vars->w18 = (s32)((f32)vars->w18 * 60.0f);
    }
    dir = obj + 0xC0;
    tbl = D_L03_001DFB00;
    *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 0x145;
    *(Quad_3A36E0 *)(obj + 0x10) = tbl[vars->w0].pos;
    func_00388550(dir, &D_L03_001DFB00[vars->w0], 0x30);
    a = func_00388770(D_L03_001DFB00[vars->w0].e10);
    b = func_00388770(D_L03_001DFB00[vars->w0].e20);
    if (b < a) {
        *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * a;
        func_003886E8(obj + 0xD0, obj + 0xD0, b / a);
    } else {
        *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * b;
        func_003886E8(obj + 0xD0, obj + 0xD0, a / b);
    }
    func_003C26C8(obj);
    if (D_001BBC40[obj[0xB0] + (D_001D545C << 4)] & 0x80) {
        func_003BD360(obj);
        return;
    }
    func_L01_003F3CE0(obj);
    if (vars->wC != 0) {
        vars->f4 = 0.0f;
        func_L01_00441FB8(obj, 1, 1);
    } else {
        vars->f4 = 1.0f;
        func_L01_00441FB8(obj, 2, 1);
    }
}
/* localdecomp:end func_L03_003A36E0 */
