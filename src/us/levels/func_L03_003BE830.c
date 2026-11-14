#include "common.h"

/* NTSC-U counterpart of func_L03_003C0608 (src/levels/03_starship_phoenix/L03_003C0608.c) */
#include "vu0.h"

/* localdecomp:start func_L03_003BE830 */
extern s32 D_L03_001DF540;
extern u8 D_L03_001E24C0_003BE830[];
extern f32 D_001DEC64_sda;
__asm__(".extern D_001DEC64_sda, 4");
extern f32 D_001DEC68_sda;
__asm__(".extern D_001DEC68_sda, 4");
extern f32 D_001DEC6C_sda;
__asm__(".extern D_001DEC6C_sda, 4");
extern f32 D_001DEC70_sda;
__asm__(".extern D_001DEC70_sda, 4");
extern s32 D_001DEC74_sda;
__asm__(".extern D_001DEC74_sda, 4");
extern s32 D_001DEC78_sda;
__asm__(".extern D_001DEC78_sda, 4");
extern s32 D_001DEC7C_sda;
__asm__(".extern D_001DEC7C_sda, 4");
extern f32 D_001DEC80_sda;
__asm__(".extern D_001DEC80_sda, 4");
extern f32 D_001DEC84_sda;
__asm__(".extern D_001DEC84_sda, 4");
extern s32 D_001DEC88_sda;
__asm__(".extern D_001DEC88_sda, 4");
extern s32 D_001DEC8C_sda;
__asm__(".extern D_001DEC8C_sda, 4");
extern f32 D_001DEC90_sda;
__asm__(".extern D_001DEC90_sda, 4");
extern f32 D_001DEC94_sda;
__asm__(".extern D_001DEC94_sda, 4");
extern s32 D_001DEC98_sda;
__asm__(".extern D_001DEC98_sda, 4");
extern s32 D_001DEC9C_sda;
__asm__(".extern D_001DEC9C_sda, 4");
extern s32 D_001DECA0_sda;
__asm__(".extern D_001DECA0_sda, 4");
extern void func_003888C8(void *, void *, void *);
extern s32 func_0037E1D8(s32);
extern void func_L01_00440A88(void *, f32, f32);
extern void func_L01_00468DC0(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_00388830(void *, void *, f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_00468C38(void *, s32, s32, s32, s32, s32, s32, s32, f32);

typedef struct { u8 pad0[0x24]; u8 *p24; u8 pad28[4]; f32 f2C; } S_003BE830;

void func_L03_003BE830(S_003BE830 *self) {
    vu0_v4 pos;
    vu0_v4 vel;
    vu0_v4 w;
    vu0_v4 q;
    vu0_v4 r;
    s32 i;
    s32 j;
    s32 v;

    func_003888C8(&pos, &D_001DECA0_sda, (u8 *)self + 0xC0);
    vec_add_ab(&pos, &pos, (u8 *)self + 0x10);
    if (func_0037E1D8(4) == 0) {
        func_L01_00440A88(&vel, D_001DEC64_sda * 0.0166666675f, D_001DEC68_sda * 0.0166666675f);
        func_L01_00468DC0(&pos, &vel, D_001DEC78_sda, D_001DEC80_sda, D_001DEC74_sda, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
        for (i = 0; i < 3; i++) {
            func_L01_00440A88(&w, D_001DEC6C_sda * 0.0166666675f, D_001DEC70_sda * 0.0166666675f);
            vec_add_ab(&vel, &vel, &w);
            func_L01_00468DC0(&pos, &vel, D_001DEC7C_sda, D_001DEC84_sda, D_001DEC74_sda, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
        }
    }
    vec_sub_ba(&q, D_L03_001E24C0_003BE830, &pos);
    func_00388830(&q, &q, -0.300000012f);
    func_00388830(&r, &q, 0.100000001f);
    vec_add_ab(&q, &q, &pos);
    for (j = 0; j < 4; j++) {
        s32 col = func_003894A0(D_001DEC88_sda, D_001DEC8C_sda,
                                fabs_asm(0.5f - (f32)(0xFF - ((D_L03_001DF540 + j * 20) & 0xFF)) / 255.0f));
        v = (u8)D_L03_001DF540;
        if (j & 2) v = v << 1;
        if (j & 1) v = 0xFF - v;
        func_L01_00468C38(&q, col, v & 0xFF, D_001DEC9C_sda, D_001DEC98_sda, 2, 0, 0,
                          (D_001DEC90_sda + (f32)j * D_001DEC94_sda) * (self->f2C / *(f32 *)(self->p24 + 0x24)));
        vec_add_ab(&q, &q, &r);
    }
}
/* localdecomp:end func_L03_003BE830 */
