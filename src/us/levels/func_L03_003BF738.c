#include "common.h"

#include "vu0.h"

/* localdecomp:start func_L03_003BF738 */
extern s32 D_L03_001DF540;
extern u8 D_L03_001E24C0_003BF738[];
extern f32 D_001DECB4_sda;
__asm__(".extern D_001DECB4_sda, 4");
extern f32 D_001DECB8_sda;
__asm__(".extern D_001DECB8_sda, 4");
extern f32 D_001DECBC_sda;
__asm__(".extern D_001DECBC_sda, 4");
extern f32 D_001DECC0_sda;
__asm__(".extern D_001DECC0_sda, 4");
extern s32 D_001DECC4_sda;
__asm__(".extern D_001DECC4_sda, 4");
extern s32 D_001DECC8_sda;
__asm__(".extern D_001DECC8_sda, 4");
extern s32 D_001DECCC_sda;
__asm__(".extern D_001DECCC_sda, 4");
extern f32 D_001DECD0_sda;
__asm__(".extern D_001DECD0_sda, 4");
extern f32 D_001DECD4_sda;
__asm__(".extern D_001DECD4_sda, 4");
extern s32 D_001DECD8_sda;
__asm__(".extern D_001DECD8_sda, 4");
extern s32 D_001DECDC_sda;
__asm__(".extern D_001DECDC_sda, 4");
extern f32 D_001DECE0_sda;
__asm__(".extern D_001DECE0_sda, 4");
extern f32 D_001DECE4_sda;
__asm__(".extern D_001DECE4_sda, 4");
extern s32 D_001DECE8_sda;
__asm__(".extern D_001DECE8_sda, 4");
extern s32 D_001DECEC_sda;
__asm__(".extern D_001DECEC_sda, 4");
extern s32 D_001DECF0_sda;
__asm__(".extern D_001DECF0_sda, 4");
extern void func_003888C8(void *, void *, void *);
extern s32 func_0037E1D8(s32);
extern void func_L01_00440A88(void *, f32, f32);
extern void func_L01_00468DC0(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_00388830(void *, void *, f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_00468C38(void *, s32, s32, s32, s32, s32, s32, s32, f32);

typedef struct { u8 pad0[0x24]; u8 *p24; u8 pad28[4]; f32 f2C; } S_003BF738;

void func_L03_003BF738(S_003BF738 *self) {
    vu0_v4 pos;
    vu0_v4 vel;
    vu0_v4 w;
    vu0_v4 q;
    vu0_v4 r;
    s32 i;
    s32 j;
    s32 v;

    func_003888C8(&pos, &D_001DECF0_sda, (u8 *)self + 0xC0);
    vec_add_ab(&pos, &pos, (u8 *)self + 0x10);
    if (func_0037E1D8(4) == 0) {
        func_L01_00440A88(&vel, D_001DECB4_sda * 0.0166666675f, D_001DECB8_sda * 0.0166666675f);
        func_L01_00468DC0(&pos, &vel, D_001DECC8_sda, D_001DECD0_sda, D_001DECC4_sda, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
        for (i = 0; i < 3; i++) {
            func_L01_00440A88(&w, D_001DECBC_sda * 0.0166666675f, D_001DECC0_sda * 0.0166666675f);
            vec_add_ab(&vel, &vel, &w);
            func_L01_00468DC0(&pos, &vel, D_001DECCC_sda, D_001DECD4_sda, D_001DECC4_sda, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
        }
    }
    vec_sub_ba(&q, D_L03_001E24C0_003BF738, &pos);
    func_00388830(&q, &q, -0.300000012f);
    func_00388830(&r, &q, 0.100000001f);
    vec_add_ab(&q, &q, &pos);
    for (j = 0; j < 4; j++) {
        s32 col = func_003894A0(D_001DECD8_sda, D_001DECDC_sda,
                                fabs_asm(0.5f - (f32)(0xFF - ((D_L03_001DF540 + j * 20) & 0xFF)) / 255.0f));
        v = (u8)D_L03_001DF540;
        if (j & 2) v = v << 1;
        if (j & 1) v = 0xFF - v;
        func_L01_00468C38(&q, col, v & 0xFF, D_001DECEC_sda, D_001DECE8_sda, 2, 0, 0,
                          (D_001DECE0_sda + (f32)j * D_001DECE4_sda) * (self->f2C / *(f32 *)(self->p24 + 0x24)));
        vec_add_ab(&q, &q, &r);
    }
}
/* localdecomp:end func_L03_003BF738 */
