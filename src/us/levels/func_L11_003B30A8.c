#include "common.h"

/* NTSC-U counterpart of func_L11_003B4FB0 (src/levels/shared/L11_003B4870.c) */
/* localdecomp:start func_L11_003B30A8 */
typedef int Quad_3B4FB0 __attribute__((mode(TI)));
typedef struct Vars_3B4FB0 {
    s32 w0;
    f32 f4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18;
} Vars_3B4FB0;
typedef struct Rec_3B4FB0 {
    u8 pad0[0x10];
    f32 e10[4];
    f32 e20[4];
    Quad_3B4FB0 pos;
    u8 pad40[0x40];
} Rec_3B4FB0;
extern Rec_3B4FB0 *D_L11_001DEF00_003B30A8;
__asm__(".extern D_L11_001DEF00_003B30A8, 16");
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

void func_L11_003B30A8(void *arg0) {
    u8 *obj = (u8 *)arg0;
    Vars_3B4FB0 *vars = *(Vars_3B4FB0 **)(obj + 0x68);
    f32 one = 1.0f;
    f32 inv;
    f32 a;
    f32 b;
    f32 m;
    u8 *dir;
    Rec_3B4FB0 *tbl;

    vars->w14 = -1;
    vars->f4 = one;
    vars->w8 = 0;
    vars->w10 = 0;
    if (vars->w18 < 10) {
        vars->w18 = (s32)((f32)vars->w18 * 60.0f);
    }
    dir = obj + 0xC0;
    tbl = D_L11_001DEF00_003B30A8;
    *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 0x145;
    *(Quad_3B4FB0 *)(obj + 0x10) = tbl[vars->w0].pos;
    func_00388550(dir, &D_L11_001DEF00_003B30A8[vars->w0], 0x30);
    a = func_00388770(D_L11_001DEF00_003B30A8[vars->w0].e10);
    b = func_00388770(D_L11_001DEF00_003B30A8[vars->w0].e20);
    m = b < a ? a : b;
    inv = one / m;
    *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * m;
    func_003886E8(dir, dir, inv);
    func_003886E8(obj + 0xD0, obj + 0xD0, inv);
    func_003886E8(obj + 0xE0, obj + 0xE0, inv);
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
        vars->f4 = one;
        func_L01_00441FB8(obj, 2, 1);
    }
}
/* localdecomp:end func_L11_003B30A8 */
