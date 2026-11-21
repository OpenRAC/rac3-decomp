#include "common.h"

/* NTSC-U counterpart of func_L05_003BDB68 (src/levels/shared/L05_003BD078.c): the count test is < 10, not < 8 */
/* localdecomp:start func_L05_003BBBC8 */
typedef struct {
    u8 pad0[0x10];
    s32 x10;
    u8 pad14[0x60 - 0x14];
    s32 x60;
} M_003BBBC8;

typedef struct {
    u8 pad0[0x68];
    M_003BBBC8 *x68;
    u8 pad6C[0xB8 - 0x6C];
    u8 *xB8;
} O_003BBBC8;

extern u8 D_L05_002A4C40[];

extern void func_L05_003BC1F0(void *, s32, s32, f32, f32, f32, s32, s32, s32);

void func_L05_003BBBC8(O_003BBBC8 *o) {
    s32 c1 = 0xFF1010;
    s32 c2 = 0xFF2020;
    f32 half = 0.5f;
    M_003BBBC8 *m;
    s32 kind;
    s32 n;

    kind = *(s16 *)(o->xB8 + 0xAA);
    m = o->x68;
    if (kind == 0x1BF6 || kind == 0x1BDC || kind == 0x1B6C) {
        c1 = 0x1010FF;
        c2 = 0x2020FF;
    }
    if (m->x10 < 10) {
        n = m->x10 * 3;
        func_L05_003BC1F0((D_L05_002A4C40 + m->x60 * 0x280 + 0), n, n, half * 0.12f, half * 0.22f, 0.2f, 10, 0x7F7F7F, c2);
        func_L05_003BC1F0((D_L05_002A4C40 + m->x60 * 0x280 + 160), m->x10 * 2, m->x10 * 2, half * 0.1f, half * 0.19f, 0.2f, 10, 0x7F7F7F, c1);
        func_L05_003BC1F0((D_L05_002A4C40 + m->x60 * 0x280 + 320), m->x10 * 2, m->x10 * 2, half * 0.1f, half * 0.19f, 0.2f, 10, 0x7F7F7F, c1);
        func_L05_003BC1F0((D_L05_002A4C40 + m->x60 * 0x280 + 480), m->x10 * 2, m->x10 * 2, 0.03f, 0.09f, 0.2f, 10, 0x7F7F7F, c1);
        return;
    }
    if (*(s16 *)(o->xB8 + 0xAA) == 0x1BF6) {
        func_L05_003BC1F0((D_L05_002A4C40 + m->x60 * 0x280 + 0), 0x80, 0x80, 0.2f, 0.4f, 0.5f, 10, 0x7F7F7F, c1);
        func_L05_003BC1F0((D_L05_002A4C40 + m->x60 * 0x280 + 160), 0x40, 0x40, 0.15f, 0.2f, 0.5f, 10, 0x7F7F7F, c1);
        func_L05_003BC1F0((D_L05_002A4C40 + m->x60 * 0x280 + 320), 0x40, 0x40, 0.15f, 0.2f, 0.5f, 10, 0x7F7F7F, c1);
        func_L05_003BC1F0((D_L05_002A4C40 + m->x60 * 0x280 + 480), 0x40, 0x40, 0.15f, 0.2f, 0.5f, 10, 0x7F7F7F, c1);
    } else {
        func_L05_003BC1F0((D_L05_002A4C40 + m->x60 * 0x280 + 0), 0x32, 0x32, 0.04f, 0.15f, 0.2f, 10, 0x7F7F7F, c1);
        func_L05_003BC1F0((D_L05_002A4C40 + m->x60 * 0x280 + 160), 0xF, 0xF, 0.03f, 0.09f, 0.2f, 10, 0x7F7F7F, c1);
        func_L05_003BC1F0((D_L05_002A4C40 + m->x60 * 0x280 + 320), 0xF, 0xF, 0.03f, 0.09f, 0.2f, 10, 0x7F7F7F, c1);
        func_L05_003BC1F0((D_L05_002A4C40 + m->x60 * 0x280 + 480), 0xF, 0xF, 0.03f, 0.09f, 0.2f, 10, 0x7F7F7F, c1);
    }
}
/* localdecomp:end func_L05_003BBBC8 */
