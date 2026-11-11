#include "common.h"
typedef struct { f32 v[4]; } __attribute__((aligned(16))) V4_4C2CE8;
typedef struct { V4_4C2CE8 m[4]; } Mtx_4C2CE8;
typedef struct { u8 p0[0x10]; u8 b10; } A_4C2CE8;
typedef struct { u8 p0[0x48]; A_4C2CE8 *a48[1]; } C_4C2CE8;
typedef struct {
    u8 p0[0x10];
    V4_4C2CE8 v10;
    u8 p20[4];
    C_4C2CE8 *p24;
    u8 p28[0xC];
    u16 h34;
    u8 p36[0xA];
    u8 b40, b41, b42, b43;
    f32 f44, f48, f4C;
    u8 p50[8];
    s32 w58;
    s32 w5C;
    u8 p60[0xF];
    u8 b6F;
    u8 p70[0x50];
    u8 aC0[0x30];
    u8 aF0[0x10];
} M_4C2CE8;
typedef struct {
    u8 p0[0xBF8];
    M_4C2CE8 *wBF8;
    u8 pBFC[0x25C0 - 0xBFC];
    M_4C2CE8 *w25C0;
} G_4C2CE8;

/* localdecomp:start func_L23_004C2CE8 */
extern G_4C2CE8 D_001A4BE0;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_L23_00254D40[];
extern void func_003C2EC0(void *, s32, Mtx_4C2CE8 *);
extern void func_0038D590(void *, void *);
extern void func_003C48A8(void *, void *);
extern s32 func_L01_004DFCC8(M_4C2CE8 *, s32, s32, void *);
extern void func_0038CC88(void *, void *, s32);
extern void func_003C7C38(void *);

void func_L23_004C2CE8(void)
{
    Mtx_4C2CE8 mtx;
    M_4C2CE8 *m;

    if (D_001D545C == 0x17) {
        return;
    }
    m = D_001A4BE0.wBF8;
    m->b6F = 0;
    if ((*(u8 *)&D_001A4BE0.w25C0->h34 ^ 1) & 1) {
        func_003C2EC0(D_001A4BE0.w25C0, 5, &mtx);
        m->v10 = mtx.m[3];
        func_0038D590(m->aC0, &mtx);
        func_003C48A8(m->aC0, m->aF0);
        m->h34 &= ~0x41;
        if (m->b43 != 0x65) {
            m->b42 = 0x65;
            m->b43 = 0x65;
            m->b40 = 1;
            m->w58 = func_L01_004DFCC8(m, 0x65, 1, D_L23_00254D40);
            m->w5C = func_L01_004DFCC8(m, m->b43, m->b41, D_L23_00254D40 + 0x600);
        } else if (m->b42 == m->b43) {
            m->f44 += m->f48 * m->f4C;
        } else {
            m->f44 += m->f4C;
        }
        if (m->f44 >= 1.0f) {
            m->b40 = m->b41;
            m->w58 = (s32)D_L23_00254D40;
            func_0038CC88(D_L23_00254D40, D_L23_00254D40 + 0x600, 0x600);
            m->b41++;
            if (m->b41 >= m->p24->a48[m->b43]->b10) {
                m->b41 = 0;
            }
            m->w5C = func_L01_004DFCC8(m, m->b43, m->b41, D_L23_00254D40 + 0x600);
            m->f44 = (m->f44 - 1.0f) / m->f4C;
            m->f4C = *(f32 *)m->w58;
            m->f44 *= m->f4C;
        }
        func_003C7C38(m);
    } else {
        m->h34 |= 0x41;
    }
}
/* localdecomp:end func_L23_004C2CE8 */

INCLUDE_ASM("asm/levels", func_L23_004C2EF0);

INCLUDE_ASM("asm/levels", func_L23_004C3330);
