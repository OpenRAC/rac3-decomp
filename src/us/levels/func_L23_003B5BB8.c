#include "common.h"

/* NTSC-U counterpart of func_L23_003B7530 (src/levels/23_holostar_studios_clank/L23_003B7530.c) */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct {
    u8 pad0[0x30]; u8 a30[0x3C]; s32 w6C; f32 f70; s32 w74; s32 w78; u8 pad7C[4]; V4 pos80;
} V_3B7530;
typedef struct { u8 pad0[0x10]; s32 w10; u8 pad14[0x44 - 0x14]; u16 h44; } C_3B7530;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 b20; u8 pad21[3]; C_3B7530 *p24; u8 pad28[0xC]; u16 h34;
    u8 pad36[0x68 - 0x36]; V_3B7530 *vars; u8 pad6C[0x98 - 0x6C]; s32 w98; u8 pad9C[0xF0 - 0x9C]; u8 aF0[0x10];
} M_3B7530;

/* localdecomp:start func_L23_003B5BB8 */
#include "vu0.h"
extern s32 D_L23_001D6694_003B5BB8;
__asm__(".extern D_L23_001D6694_003B5BB8, 16");
extern s32 D_L23_001DECC0;
extern void func_L01_004A6DF8(void *, s32);
extern f32 func_00389410(f32);
extern f32 func_00388978(f32);
extern void func_003BF838(void *, void *, void *, void *);

void func_L23_003B5BB8(M_3B7530 *m)
{
    V_3B7530 *v = m->vars;
    V4 a;
    V4 b;
    V4 c;

    if (D_L23_001D6694_003B5BB8 == 2) {
        m->w98 = 0;
        m->h34 = (m->h34 | 0x41) & ~0x1000;
        func_L01_004A6DF8(m, 1);
    } else {
        m->h34 &= ~0x41;
        m->h34 |= m->p24->h44 & 0x1000;
        m->w98 = m->p24->w10;
    }
    if (m->b20 == 0) {
        if (v->w74 < 10) {
            v->w74 = v->w74 * 60.0f;
        }
        if (v->w78 < 10) {
            v->w78 = v->w78 * 60.0f;
        }
        v->pos80 = m->pos;
        v->w6C |= 1;
        m->b20 = 1;
    }
    a = m->pos;
    b = v->pos80;
    b.z += func_00388978(func_00389410((f32)((D_L23_001DECC0 + v->w78) % v->w74) / (f32)v->w74 * 6.2831855f)) * v->f70;
    m->pos = b;
    vec_sub_ab(&c, &b, &a);
    func_003BF838(v->a30, &c, m->aF0, m->aF0);
}
/* localdecomp:end func_L23_003B5BB8 */
