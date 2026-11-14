#include "common.h"

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

INCLUDE_ASM("asm/levels", func_L11_003B4870);

/* localdecomp:start func_L11_003B4FB0 */
/* PAL port of the NTSC-U match src/us/levels/func_L11_003B30A8.c */

extern Rec_3B4FB0 *D_L11_001DEF00_003B30A8;
__asm__(".extern D_L11_001DEF00_003B30A8, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001BBC40[];
extern void func_0038CC88(void *, void *, s32);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C7C38(void *);
extern void func_003C2880(void *);
extern void func_L01_003F5E88(void *);
extern void func_L01_004450F0(void *, s32, s32);

void func_L11_003B4FB0(void *arg0) {
    u8 *obj = (u8 *)arg0;
    Vars_3B4FB0 *vars = *(Vars_3B4FB0 **)(obj + 0x68);
    f32 inv;
    f32 a;
    f32 b;
    f32 m;
    u8 *dir;
    Rec_3B4FB0 *tbl;

    vars->f4 = 1.0f;
    vars->w14 = -1;
    vars->w8 = 0;
    vars->w10 = 0;
    if (vars->w18 < 10) {
        vars->w18 = (s32)((f32)vars->w18 * 50.0f);
    } else {
        vars->w18 = (vars->w18 * 5 + 2) / 6;
    }
    dir = obj + 0xC0;
    tbl = D_L11_001DEF00_003B30A8;
    *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 0x145;
    *(Quad_3B4FB0 *)(obj + 0x10) = tbl[vars->w0].pos;
    func_0038CC88(dir, &D_L11_001DEF00_003B30A8[vars->w0], 0x30);
    a = func_0038CEA8(D_L11_001DEF00_003B30A8[vars->w0].e10);
    b = func_0038CEA8(D_L11_001DEF00_003B30A8[vars->w0].e20);
    m = b < a ? a : b;
    inv = 1.0f / m;
    *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * m;
    func_0038CE20(dir, dir, inv);
    func_0038CE20(obj + 0xD0, obj + 0xD0, inv);
    func_0038CE20(obj + 0xE0, obj + 0xE0, inv);
    func_003C7C38(obj);
    if (D_001BBC40[obj[0xB0] + (D_001D545C << 4)] & 0x80) {
        func_003C2880(obj);
        return;
    }
    func_L01_003F5E88(obj);
    if (vars->wC != 0) {
        vars->f4 = 0.0f;
        func_L01_004450F0(obj, 1, 1);
    } else {
        vars->f4 = 1.0f;
        func_L01_004450F0(obj, 2, 1);
    }
}
/* localdecomp:end func_L11_003B4FB0 */
