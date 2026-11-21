#include "common.h"

/* NTSC-U counterpart of func_L08_003AA088 (src/levels/shared/L08_003AA088.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L08_003A81D8 */
typedef struct S_003AA088 {
    u8 pad0[0x10];
    u128_t pos;
    u8 b20;
    u8 pad21[2];
    u8 b23;
    u8 *p24;
    u8 pad28[4];
    f32 f2C;
    u8 b30;
    u8 b31;
    u16 h32;
    u16 h34;
    u8 pad36[0x68 - 0x36];
    u8 *p68;
    u8 pad6C[0xB8 - 0x6C];
    u8 *pB8;
    u8 padBC[0xF0 - 0xBC];
    f32 rot[3];
    s32 fFC;
} S_003AA088;

typedef struct T_003AA088 {
    u128_t pos;
    s32 i10;
    s32 i14;
    s32 i18;
    s32 pad1C;
    f32 f20;
    s32 pad24;
    f32 f28;
} T_003AA088;

extern S_003AA088 *func_003BCFB0(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_003C26C8(S_003AA088 *);
extern s32 D_L08_001DE2F0_003A81D8;
__asm__(".extern D_L08_001DE2F0_003A81D8, 4");
extern s32 D_L08_001DE2E8_003A81D8;
__asm__(".extern D_L08_001DE2E8_003A81D8, 4");

S_003AA088 *func_L08_003A81D8(u8 *a0, u8 *a1, u8 *a2, f32 f12, f32 f13) {
    S_003AA088 *m = func_003BCFB0(0x1A98, 0x80);
    T_003AA088 *d;
    s32 t;

    if (m != 0) {
        m->b30 = 0xFF;
        m->h32 = 0x1FF;
        m->b23 = 0x70;
        m->h34 |= 0x2000;
        m->b31 = 1;
        m->b20 = 0;
        d = (T_003AA088 *)m->p68;
        m->f2C = *(f32 *)(m->p24 + 0x24) * 0.35f;
        if (a2 != 0) {
            m->pB8 = a2;
        }
        m->pos = *(u128_t *)a0;
        *(u128_t *)d = *(u128_t *)a1;
        t = D_L08_001DE2F0_003A81D8;
        d->f28 = f13;
        d->i10 = t;
        d->i18 = D_L08_001DE2E8_003A81D8;
        d->f20 = f12;
        d->i14 = 0;
        m->rot[0] = func_0037E250(-3.14159274f, 3.14159274f);
        m->rot[1] = func_0037E250(-3.14159274f, 3.14159274f);
        m->rot[2] = func_0037E250(-3.14159274f, 3.14159274f);
        m->fFC = 0;
        func_003C26C8(m);
    }
    return m;
}
/* localdecomp:end func_L08_003A81D8 */
