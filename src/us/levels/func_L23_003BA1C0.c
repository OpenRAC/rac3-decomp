#include "common.h"

/* NTSC-U counterpart of func_L23_003BBCB0 (src/levels/23_holostar_studios_clank/L23_003B94C8.c) */
typedef int u128_t __attribute__((mode(TI)));
#include "vu0.h"
#include "structs/hero.h"
extern s32 D_L23_001DECC0;
#include "vu0.h"
extern void func_003D3FA0(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);
extern void func_00388830(void *, void *, f32);
#include "vu0.h"
typedef struct {
    u8 pad0[0x10];
    u128_t pos;
    u8 x20;
    u8 pad21[0xB];
    f32 x2C;
    u8 x30;
    u8 pad31[0x37];
    u8 *vars;
    u8 pad6C[0x3E];
    u16 xAA;
} Moby_3BB7C8;
extern void func_003D3FA0(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);
extern s32 D_L23_001DECC0;

/* localdecomp:start func_L23_003BA1C0 */
extern void func_00388830(void *, void *, f32);
extern void func_L01_004084B0(u128_t *a, u128_t *b, s32 c, s32 d, u32 c0, u32 c1, u32 c2, u32 c3,
                              f32 e, f32 f, f32 g);
__asm__(".extern D_L23_001DE5D8, 4");
__asm__(".extern D_L23_001DE5DC, 4");
extern f32 D_L23_001DE5D8;
extern u32 D_L23_001DE5DC;

void func_L23_003BA1C0(Moby_3BB7C8 *m)
{
    u128_t a;
    u128_t b;
    u8 *v;
    f32 ang;

    ang = (f32)(D_L23_001DECC0 % 60) / 60.0f * 6.2831855f - 1.5707964f;
    v = m->vars;
    func_003D3FA0(&m->pos, 0x67, 0x40003080, 1, m->x2C, 0.0f, ang);
    func_003D3FA0(&m->pos, 0x67, 0x40005080, 1, m->x2C * 1.2f, 0.0f, -ang);
    func_003D3FA0(&m->pos, 0x68, 0x80002080, 1, m->x2C * 0.4f, 0.0f, ang);
    func_003D3FA0(&m->pos, 7, 0x40008080, 1, m->x2C * 0.4f, 0.0f, ang);
    func_00388830(&a, v + 0x40, m->x2C);
    vec_add_ba(&a, &m->pos, &a);
    func_00388830(&b, v + 0x40, m->x2C * -4.0f * D_L23_001DE5D8);
    vec_add_ba(&b, &m->pos, &b);
    func_L01_004084B0(&b, &a, 0x69, 1, D_L23_001DE5DC, D_L23_001DE5DC, D_L23_001DE5DC, D_L23_001DE5DC,
                      m->x2C * D_L23_001DE5D8, 1.0f, 0.0f);
}
/* localdecomp:end func_L23_003BA1C0 */
