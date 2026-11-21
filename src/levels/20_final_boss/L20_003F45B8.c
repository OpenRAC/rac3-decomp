#include "common.h"

typedef struct Vars_3F4A78 {
    u8 pad0[0x10];
    u8 slot[2][0x10];
    u8 pad30[0xA0 - 0x30];
    s32 wA0;
} Vars_3F4A78;

/* localdecomp:start func_L20_003F45B8 */
#include "vu0.h"
typedef int u128_003F45B8 __attribute__((mode(TI)));
__asm__(".extern D_L20_001DF458, 1");
__asm__(".extern D_L20_001DF459, 1");
__asm__(".extern D_L20_001DF45A, 1");
__asm__(".extern D_L20_001DF45B, 1");
__asm__(".extern D_L20_001DF45C, 4");
__asm__(".extern D_L20_001DF460, 4");
extern u8 D_L20_001DF458;
extern u8 D_L20_001DF459;
extern u8 D_L20_001DF45A;
extern u8 D_L20_001DF45B;
extern f32 D_L20_001DF45C;
extern s32 D_L20_001DF460;
extern u8 D_00220258[];
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L20_003F4520(s32 *, s32 *, s32 *, s32 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
void func_L20_003F45B8(vu0_v4 *pos, s32 life, s32 count, s32 sel, void *dir, f32 speed, f32 sx, f32 sy, f32 sz, f32 spread) {
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
    r0 = D_L20_001DF458;
    r1 = D_L20_001DF459;
    alt = func_00382468(D_L20_001DF460) == 0;
    if (alt) {
        sel = 4;
        sx *= D_L20_001DF45C;
        sy *= D_L20_001DF45C;
        r0 = D_L20_001DF45A;
        r1 = D_L20_001DF45B;
    }
    func_L20_003F4520(&sel, &c0, &c1, &c2);
    *(u128_003F45B8 *)&v = 0;
    v.x = 1.0f;
    for (i = 0; i < count; i++) {
        u8 *g = D_00220258;
        func_0038CF68(&w, dir, speed * 0.020000001f);
        func_0038CE20(&u, &v, func_003824E0(0.2f, spread) * 0.020000001f);
        vec_add_ab(&w, &u, &w);
        col = func_00382468(2) ? c1 : c0;
        e = func_L01_004713C8(pos, &w, life, col, func_00382498(-2, 2), r0, r1, 4, sx * 210000.0f, sy * 210000.0f, sz * 0.00040000002f);
        if (e != 0) {
            e[2] = alt ? (*(u8 **)(g + 0x184))[4] : (*(u8 **)(g + 0x10))[0];
            e[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L20_003F45B8 */

/* localdecomp:start func_L20_003F47E8 */
#include "vu0.h"
typedef int u128_003F47E8 __attribute__((mode(TI)));
extern f32 func_003824E0(f32, f32);
extern void func_L20_003F45B8(vu0_v4 *, s32, s32, s32, void *, f32, f32, f32, f32, f32);
void func_L20_003F47E8(void *pos, s32 a1, s32 a2, s32 a3, void *a4, f32 f0, f32 f1, f32 f2, f32 spread, f32 height, f32 f3, f32 f4) {
    vu0_v4 w;
    vu0_v4 v;
    *(u128_003F47E8 *)&v = 0;
    v.x = func_003824E0(-spread, spread);
    v.y = func_003824E0(-spread, spread);
    v.z = func_003824E0(0.0f, height);
    w = v;
    vec_add_ba(&w, &w, pos);
    func_L20_003F45B8(&w, a1, a2, a3, a4, f0, f1, f2, f3, f4);
}
/* localdecomp:end func_L20_003F47E8 */

/* localdecomp:start func_L20_003F4918 */
#include "vu0.h"
extern void func_L01_00443B88(f32 *, f32, f32);
__asm__(".extern D_L20_001DF02C, 4");
__asm__(".extern D_L20_001DF030, 4");
extern u32 D_L20_001DF02C;
extern u32 D_L20_001DF030;
/* from rac3-decomp's func_L01_00395288 (its `high` branch, one rock, colours of case 0x2A) */
void func_L20_003F4918(void *a0) {
    vu0_v4 v;
    f32 size;
    u32 col;
    u8 *e;
    func_L01_00443B88(&v.x, 0.020000001f, 0.050000004f);
    v.z = fabs_asm(v.z) + func_003824E0(7.0f, 10.5f) * 0.020000001f;
    size = func_003824E0(0.06f, 0.22f);
    col = func_00382468(3) ? D_L20_001DF02C : D_L20_001DF030;
    col = func_00382468(3) ? 0x263438 : 0x273538;
    e = ((u8 *(*)(void *, void *, s32, u32, s32, s32, s32, f32, f32, s32, f32))func_L01_004713C8)(
        a0, &v, (func_00382498(90, 150) * 5 + 2) / 6, col, -2, 0x7F, 0x7F, size * 210000.0f, size * 210000.0f, 0, 0.0062400005f);
    if (e != 0) {
        e[2] = (*(u8 **)(D_00220258 + 0x184))[func_00382468(3) + 10];
        e[3] = 0x44;
    }
}
/* localdecomp:end func_L20_003F4918 */
