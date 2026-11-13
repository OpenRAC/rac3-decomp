#include "common.h"

/* localdecomp:start func_L39_00533790 */
typedef int u128_00533790 __attribute__((mode(TI)));

typedef struct C_00533790 {
    u128_00533790 v0;
    f32 f10;
    s32 x14;
    f32 f18;
    s32 x1C;
    s32 x20;
    s32 x24;
    s32 *x28;
    u8 b2C;
    u8 b2D;
    u8 pad2E[0x12];
    u128_00533790 v40;
} C_00533790;

typedef struct O_00533790 {
    u8 pad0[0x10];
    u128_00533790 v10;
    u8 b20;
    u8 pad21[0xF];
    u8 b30;
    u8 pad31;
    s16 h32;
    u16 h34;
    u8 pad36[0x32];
    C_00533790 *x68;
    u8 pad6C[0x24];
    s32 x90;
    u8 pad94[4];
    s32 x98;
    u8 pad9C[0x1C];
    void *xB8;
} O_00533790;

extern u8 *func_003C24B0(s32, s32);
extern f32 func_L39_005B44C8(void);
extern void func_L39_005F2FF8(void *, s32);
extern void func_L39_00533600(void *);

O_00533790 *func_L39_00533790(void *a0, s32 *a1, u128_00533790 *a2, u128_00533790 *a3, f32 f, s32 a4, s32 a5) {
    O_00533790 *o;
    C_00533790 *c;
    s32 ff;

    o = (O_00533790 *)func_003C24B0(0x1095, 0x80);
    if (o != 0) {
        o->xB8 = a0;
        ff = 0xFF;
        o->h32 = ff;
        o->b30 = ff;
        o->b20 = 0;
        c = o->x68;
        o->v10 = *a2;
        {
            u128_00533790 w = *a3;
            c->x1C = a4;
            c->v0 = w;
        }
        c->f10 = func_L39_005B44C8();
        c->f18 = f;
        c->x14 = 0;
        c->x20 = a5;
        c->b2C = 0xA0;
        c->x24 = 0;
        c->x28 = a1;
        c->b2D = 0;
        c->v40 = *a2;
        o->x98 = 0;
        o->h34 = (o->h34 | 0x41) & 0xEFFF;
        func_L39_005F2FF8(o, 1);
        o->x90 = *a1;
        func_L39_00533600(o);
    }
    return o;
}
/* localdecomp:end func_L39_00533790 */

INCLUDE_ASM("asm/levels", func_L39_005338A8);
