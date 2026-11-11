#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { s32 count; s32 pad[3]; V4 points[1]; } Path;
typedef struct {
    u8 pad0[0x30]; u8 a30[0x3C]; s32 w6C; f32 f70; s32 w74; s32 w78; u8 pad7C[4]; V4 pos80;
} V_3B7530;
typedef struct { u8 pad0[0x10]; s32 w10; u8 pad14[0x44 - 0x14]; u16 h44; } C_3B7530;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 b20; u8 pad21[3]; C_3B7530 *p24; u8 pad28[0xC]; u16 h34;
    u8 pad36[0x68 - 0x36]; V_3B7530 *vars; u8 pad6C[0x98 - 0x6C]; s32 w98; u8 pad9C[0xF0 - 0x9C]; u8 aF0[0x10];
} M_3B7530;
typedef struct {
    u8 pad0[0x30];
    u8 x30[0x3C];
    s32 x6C;
    f32 x70;
    s32 x74;
    s32 x78;
    u8 pad7C[4];
    V4 x80;
} Vars_3B7730;

/* localdecomp:start func_L23_003B7530 */
#include "vu0.h"
extern s32 D_L23_001D6694;
__asm__(".extern D_L23_001D6694, 16");
extern s32 D_L23_001DEC40;
extern void func_L01_004AA7E8(void *, s32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D0B0(f32);
extern void func_003C4DA8(void *, void *, void *, void *);

void func_L23_003B7530(M_3B7530 *m)
{
    V_3B7530 *v = m->vars;
    V4 a;
    V4 b;
    V4 c;

    if (D_L23_001D6694 == 2) {
        m->w98 = 0;
        m->h34 = (m->h34 | 0x41) & ~0x1000;
        func_L01_004AA7E8(m, 1);
    } else {
        m->h34 &= ~0x41;
        m->h34 |= m->p24->h44 & 0x1000;
        m->w98 = m->p24->w10;
    }
    if (m->b20 == 0) {
        if (v->w74 < 10) {
            v->w74 = v->w74 * 50.0f;
        } else {
            v->w74 = (v->w74 * 5 + 2) / 6;
        }
        if (v->w78 < 10) {
            v->w78 = v->w78 * 50.0f;
        } else {
            v->w78 = (v->w78 * 5 + 2) / 6;
        }
        v->pos80 = m->pos;
        v->w6C |= 1;
        m->b20 = 1;
    }
    a = m->pos;
    b = v->pos80;
    b.z += func_0038D0B0(func_0038DB48((f32)((D_L23_001DEC40 + v->w78) % v->w74) / (f32)v->w74 * 6.2831855f)) * v->f70;
    m->pos = b;
    vec_sub_ab(&c, &b, &a);
    func_003C4DA8(v->a30, &c, m->aF0, m->aF0);
}
/* localdecomp:end func_L23_003B7530 */

/* localdecomp:start func_L23_003B7730 */
#include "vu0.h"
extern s32 D_L23_001D6694;
__asm__(".extern D_L23_001D6694, 16");
extern s32 D_L23_001DEC40;
__asm__(".extern D_L23_001DEC40, 16");
extern void func_L01_004AA7E8(void *, s32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D0B0(f32);
extern void func_003C4DA8(void *, void *, void *, void *);

void func_L23_003B7730(u8 *a0)
{
    Vars_3B7730 *v = *(Vars_3B7730 **)(a0 + 0x68);
    V4 a;
    V4 b;
    V4 d;

    if (D_L23_001D6694 == 2) {
        *(s32 *)(a0 + 152) = 0;
        *(u16 *)(a0 + 52) = (*(u16 *)(a0 + 52) | 0x41) & ~0x1000;
        func_L01_004AA7E8(a0, 1);
    } else {
        u8 *o = *(u8 **)(a0 + 36);
        *(u16 *)(a0 + 52) &= ~0x41;
        *(u16 *)(a0 + 52) |= *(u16 *)(o + 68) & 0x1000;
        *(s32 *)(a0 + 152) = *(s32 *)(o + 16);
    }
    if (a0[0x20] == 0) {
        if (v->x74 < 10)
            v->x74 = v->x74 * 50.0f;
        else
            v->x74 = (v->x74 * 5 + 2) / 6;
        if (v->x78 < 10)
            v->x78 = v->x78 * 50.0f;
        else
            v->x78 = (v->x78 * 5 + 2) / 6;
        v->x80 = *(V4 *)(a0 + 0x10);
        v->x6C |= 1;
        a0[0x20] = 1;
    }
    a = *(V4 *)(a0 + 0x10);
    b = v->x80;
    b.z += func_0038D0B0(func_0038DB48((f32)((D_L23_001DEC40 + v->x78) % v->x74) / (f32)v->x74 * 6.2831855f)) * v->x70;
    *(V4 *)(a0 + 0x10) = b;
    vec_sub_ab(&d, &b, &a);
    func_003C4DA8(v->x30, &d, a0 + 0xF0, a0 + 0xF0);
}
/* localdecomp:end func_L23_003B7730 */

INCLUDE_ASM("asm/levels", func_L23_003B7930);

INCLUDE_ASM("asm/levels", func_L23_003B7E80);

/* localdecomp:start func_L23_003B7F60 */
extern Path *D_L23_0021D380[];
extern f32 D_L23_002A3B30[];
extern void func_003C4098(void *, void *, void *, f32);

void func_L23_003B7F60(void *out, s32 idx, f32 dist)
{
    Path *path = D_L23_0021D380[idx];
    V4 a = path->points[0];
    V4 b;
    s32 i;

    for (i = 1; i < path->count; i++) {
        b = path->points[i];
        if (dist < D_L23_002A3B30[i - 1]) {
            func_003C4098(out, &a, &b, dist / D_L23_002A3B30[i - 1]);
            return;
        }
        a = b;
        dist -= D_L23_002A3B30[i - 1];
    }
}
/* localdecomp:end func_L23_003B7F60 */

INCLUDE_ASM("asm/levels", func_L23_003B8008);
