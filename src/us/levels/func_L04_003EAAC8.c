#include "common.h"

/* NTSC-U counterpart of func_L04_003ECC40 (src/levels/04_marcadia/L04_003ECC40.c): 0.02 -> 0.0166667; 37 -> 45 */
#include "vu0.h"

/* localdecomp:start func_L04_003EAAC8 */
typedef int u128_t_3ECC40 __attribute__((mode(TI)));
typedef struct { u8 pad0[0x10]; u8 *p10; u8 pad14[0x170 - 0x14]; u8 *p170; } T_3ECC40;
extern T_3ECC40 D_L04_0021FC98;
extern void func_0037E2F0(void *, f32, f32);
extern void func_003888C8(void *, void *, void *);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L04_003EAAC8(void *self, void *pos, void *off) {
    vu0_v4 c;
    vu0_v4 v;
    vu0_v4 w;
    vu0_v4 *pv;
    vu0_v4 *pw;
    vu0_v4 *pv2;
    vu0_v4 *pw2;
    u8 *p;
    s32 i;

    vec_add_ab(&c, pos, off);
    for (i = 0; i < 15; i++) {
        pv2 = &v;
        pw2 = &w;
        pv = &v;
        pw = &w;
        func_0037E2F0(pv2, 0.3f, 1.5f);
        v.y = -fabs_asm(v.y);
        func_003888C8(pv2, pv2, (u8 *)self + 0xC0);
        *(u128_t_3ECC40 *)&w = *(u128_t_3ECC40 *)&v;
        func_00388830(pw2, pw2, func_0037E250(0.75f, 1.5f) * 0.0166666675f);
        vec_add_ab(&v, &v, &c);
        p = func_L01_00472438(pv2, pw2, 0x2D, func_0037E208(-2, 2), 0x7F202B31, 0x202B31, 315000.0f, 420000.0f, -1.5f, 0);
        if (p != 0) {
            p[2] = D_L04_0021FC98.p10[0];
        }
        func_00388830(pw, pw, func_0037E250(3.0f, 5.0f) * 0.0166666675f);
        p = func_L01_00472438(pv, pw, 0x2D, func_0037E208(-2, 2), 0x7F171F23, 0x171F23, 42000.0f, 42000.0f, 20.0f, 0);
        if (p != 0) {
            p[2] = D_L04_0021FC98.p170[1];
        }
    }
}
/* localdecomp:end func_L04_003EAAC8 */
