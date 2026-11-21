/* functional: medium. Compiles (cc1 -S) but the stock ee-as rejects the lqc2 helper on a constant address, so no byte diff; read against retail block by block: gp slots, constants (210000.0, 1.2, 0.99, 0.1, 0.8), the rand(16) then rand(2) negate, (n*5+2)/6 life, particle field pokes and the 1-in-3 early return. vadd.xyz w lane of the 2nd/3rd vector depends on VU0 reg allocation. */
#include "vu0.h"
extern u8 D_L01_001E29C0[];
extern u8 D_001D66B0[];
extern f32 D_001DD05C_sda;
extern s32 D_001DD060_sda;
extern s32 D_001DD064_sda;
extern f32 D_001DD068_sda;
extern f32 D_001DD06C_sda;
extern s32 D_001DD070_sda;
extern s32 D_001DD074_sda;
extern f32 func_00382538(void);
extern s32 func_00382468(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern u8 *func_L01_004669B0(void *, s32, void *, u32, s32, f32, f32, f32, f32);

void func_L01_0033EF90(u8 *m) {
    vu0_v4 z;
    vu0_v4 t;
    vu0_v4 u;
    vu0_v4 pos;
    vu0_v4 vel;
    s32 side;
    s32 life;
    u8 *r;
    u8 *e;

    qzero(&z);
    z.z = D_001DD068_sda;
    { u8 *c = D_L01_001E29C0; vec_sub_ab(&t, c, m + 0x10); };
    func_0038D890(&u, &z, &t, func_00382538());
    vec_add_ba(&pos, m + 0x10, &u);
    side = func_00382468(16);
    if (func_00382468(2) != 0) {
        side = -side;
    }
    life = (D_001DD064_sda * 5 + 2) / 6;
    func_0038CF68(&vel, &u, -(D_001DD068_sda / (f32)life * 1.2f));
    r = func_L01_004669B0(&pos, side, &vel, D_001DD060_sda, 0, 0.5f, 1.0f, 0.99f, D_001DD05C_sda * 210000.0f);
    if (r != 0) {
        *(s16 *)(r + 0xA) = life;
        e = r + 0x20;
        *(s32 *)(e + 4) = 3;
        e[0xA] = 0x7F;
        e[0xB] = r[0xA];
    }
    if (func_00382468(3) != 0) {
        return;
    }
    func_0038CF68(&t, &t, -0.5f);
    vec_add_ba(&pos, &t, m + 0x10);
    r = func_L01_004669B0(&pos, side, D_001D66B0,
                          (D_001DD070_sda & 0xFFFFFF) | ((u32)D_001DD074_sda << 24), 0, 0.1f, 1.0f, 0.8f,
                          D_001DD06C_sda * 210000.0f);
    if (r != 0) {
        *(s16 *)(r + 0xA) = 0x32;
        r[3] = 0x44;
        e = r + 0x20;
        *(s32 *)(e + 4) = 3;
        e[0xA] = *(u8 *)&D_001DD074_sda;
        e[0xB] = r[0xA];
    }
}
