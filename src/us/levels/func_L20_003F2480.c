#include "common.h"

/* NTSC-U counterpart of func_L20_003F45B8 (src/levels/20_final_boss/L20_003F45B8.c) */
/* localdecomp:start func_L20_003F2480 */
#include "vu0.h"
typedef int u128_003F45B8 __attribute__((mode(TI)));
__asm__(".extern D_L20_001DF498_003F2480, 1");
__asm__(".extern D_L20_001DF499, 1");
__asm__(".extern D_L20_001DF49A, 1");
__asm__(".extern D_L20_001DF49B, 1");
__asm__(".extern D_L20_001DF49C_003F2480, 4");
__asm__(".extern D_L20_001DF4A0_003F2480, 4");
extern u8 D_L20_001DF498_003F2480;
extern u8 D_L20_001DF499;
extern u8 D_L20_001DF49A;
extern u8 D_L20_001DF49B;
extern f32 D_L20_001DF49C_003F2480;
extern s32 D_L20_001DF4A0_003F2480;
extern u8 D_L20_00220258_003F2480[];
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_L20_003F23E8(s32 *, s32 *, s32 *, s32 *);
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
void func_L20_003F2480(vu0_v4 *pos, s32 life, s32 count, s32 sel, void *dir, f32 speed, f32 sx, f32 sy, f32 sz, f32 spread) {
    vu0_v4 w;
    vu0_v4 v;
    vu0_v4 u;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 alt;
    u8 r0;
    u8 r1;
    s32 i;
    s32 col;
    u8 *e;
    r0 = D_L20_001DF498_003F2480;
    r1 = D_L20_001DF499;
    alt = func_0037E1D8(D_L20_001DF4A0_003F2480) == 0;
    if (alt) {
        sel = 4;
        sx *= D_L20_001DF49C_003F2480;
        sy *= D_L20_001DF49C_003F2480;
        r0 = D_L20_001DF49A;
        r1 = D_L20_001DF49B;
    }
    func_L20_003F23E8(&sel, &c0, &c1, &c2);
    *(u128_003F45B8 *)&v = 0;
    v.x = 1.0f;
    for (i = 0; i < count; i++) {
        u8 *g = D_L20_00220258_003F2480;
        func_00388830(&w, dir, speed * 0.0166666675f);
        func_003886E8(&u, &v, func_0037E250(0.2f, spread) * 0.0166666675f);
        vec_add_ab(&w, &u, &w);
        col = func_0037E1D8(2) ? c1 : c0;
        e = func_L01_0046DCB8(pos, &w, life, col, func_0037E208(-2, 2), r0, r1, 4, sx * 210000.0f, sy * 210000.0f, sz * 0.00027777778450399637f);
        if (e != 0) {
            e[2] = alt ? (*(u8 **)(g + 0x184))[4] : (*(u8 **)(g + 0x10))[0];
            e[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L20_003F2480 */
