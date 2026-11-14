#include "common.h"

/* NTSC-U counterpart of func_L04_003ECF50 (src/levels/04_marcadia/L04_003ECC40.c) */
#include "vu0.h"
typedef struct { u8 pad0[0x10]; u8 *p10; u8 pad14[0x170 - 0x14]; u8 *p170; } T_3ECC40;
extern T_3ECC40 D_L04_0021FC98;
extern void func_0037E2F0(void *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);

/* localdecomp:start func_L04_003EADD8 */
typedef int u128_t_3ECF50 __attribute__((mode(TI)));
extern T_3ECC40 D_L04_0021FC98;
__asm__(".extern D_L04_001DF444, 4");
__asm__(".extern D_L04_001DF448, 4");
__asm__(".extern D_L04_001DF44C, 4");
extern f32 D_L04_001DF444;
extern f32 D_L04_001DF448;
extern f32 D_L04_001DF44C;
extern void func_0037E2F0(void *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L04_003EADD8(void *self, void *pos, void *off) {
    vu0_v4 c;
    vu0_v4 v;
    vu0_v4 w;
    vu0_v4 *pw;
    u8 *p;
    f32 s;
    s32 i;

    vec_add_ab(&c, pos, off);
    for (i = 0; i < 15; i++) {
        pw = &w;
        s = *(f32 *)((u8 *)self + 0x2C) / 0.080859996f;
        func_0037E2F0(&v, D_L04_001DF444 * s * 0.2f, D_L04_001DF444 * s);
        *(u128_t_3ECF50 *)&w = *(u128_t_3ECF50 *)&v;
        func_00388830(&w, &w, func_0037E250(s * D_L04_001DF448 * 0.5f, s * D_L04_001DF448) * 0.016666668f);
        vec_add_ab(&v, &v, &c);
        p = func_L01_00472438(&v, pw, 0x41, func_0037E208(-2, 2), 0x7F202B31, 0x202B31, 315000.0f, 420000.0f, -1.5f, 0);
        if (p != 0) {
            p[2] = D_L04_0021FC98.p10[0];
            p[3] = func_0037E1D8(2) != 0 ? 0x48 : 0x44;
        }
        func_00388830(&w, &w, func_0037E250(s * D_L04_001DF44C * 0.6f, s * D_L04_001DF44C) * 0.016666668f);
        p = func_L01_00472438(&v, &w, 0x2D, func_0037E208(-2, 2), 0x7F171F23, 0x171F23, 42000.0f, 42000.0f, 20.0f, 0);
        if (p != 0) {
            p[2] = D_L04_0021FC98.p170[1];
            p[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L04_003EADD8 */
