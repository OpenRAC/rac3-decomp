#include "common.h"

/* NTSC-U counterpart of func_L24_003B7A70 (src/levels/24_insomniac_museum/L24_003B7820.c) */
typedef int u128_t __attribute__((mode(TI)));
extern void func_L24_003B5E78(u8 *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);

/* localdecomp:start func_L24_003B5E78 */
typedef struct { u8 p0[0x10]; s32 w10; u8 p14[0x30]; u16 h44; } T_003B7A70;
typedef struct {
    u8 p0[0x24]; T_003B7A70 *p24; u8 p28[0xC]; u16 h34; u8 p36[0xD];
    u8 b43; u8 p44[0x24]; u8 *p68; u8 p6C[0x2C]; s32 w98;
} M_003B7A70;
typedef struct {
    u8 p0[0x30]; f32 f30; f32 f34; f32 f38; f32 f3C; f32 f40; u8 p44[0x18]; f32 f5C; f32 f60;
    u8 p64[0xC0]; s32 w124; f32 f128;
} P_003B7A70;
extern s32 D_L24_001DD5C4_003B5E78;
__asm__(".extern D_L24_001DD5C4_003B5E78, 16");
extern f32 D_L24_001DD5C0_003B5E78;
__asm__(".extern D_L24_001DD5C0_003B5E78, 16");
extern f32 D_L24_001DD5BC;
__asm__(".extern D_L24_001DD5BC, 16");
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L24_003B5E78(u8 *a0) {
    M_003B7A70 *m = (M_003B7A70 *)a0;
    P_003B7A70 *p;
    m->h34 &= ~0x41;
    m->h34 |= m->p24->h44 & 0x1000;
    m->w98 = m->p24->w10;
    p = (P_003B7A70 *)m->p68;
    p->f34 = 0.1f;
    p->f30 = 0.5f;
    p->f38 = 0.5f;
    p->f3C = 1.0f;
    p->f40 = 0.7853982f;
    p->f60 = 0.34906584f;
    p->f5C = 0.0027222223579883575f;
    p->w124 = D_L24_001DD5C4_003B5E78;
    p->f128 = D_L24_001DD5C0_003B5E78;
    *(u128_t *)((u8 *)p + 0x150) = *(u128_t *)(a0 + 0x10);
    func_L01_00458A70(m, D_L24_001DD5BC, D_L24_001DD5BC, 0.41887906193733215f, 0.41887906193733215f);
    if (m->b43 != 0) func_003BE4F0(m, 0, 0, 4);
    func_L01_00441FB8(m, 1, -1);
}
/* localdecomp:end func_L24_003B5E78 */
