#include "common.h"

/* NTSC-U counterpart of func_L23_003BB8A8 (src/levels/23_holostar_studios_clank/L23_003B94C8.c) */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
#include "vu0.h"
#include "structs/hero.h"
extern s32 D_L23_001DECC0;
extern void func_L01_00402498(void *, void *);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_003BD360(void *);
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);
#include "vu0.h"
#include "structs/hero.h"
extern void func_L01_00402498(void *, void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_003886E8(void *, void *, f32);
extern void func_003BD360(void *);
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
    u8 pad6C[0x2A];
    u16 x96;
    u8 pad98[0x12];
    s16 xAA;
} Moby_3BB7C8;
extern void func_003886E8(void *, void *, f32);
extern s32 D_L23_001DECC0;

/* localdecomp:start func_L23_003B9DC8 */
typedef struct { u8 pad0[0x18]; Moby_3BB7C8 *p18; } H_3BB8A8;
extern H_3BB8A8 D_L23_001E8800;
__asm__(".extern D_L23_001E8800, 16");
__asm__(".extern D_L23_001DE5D0, 4");
__asm__(".extern D_L23_001DE5D4, 4");
extern s32 D_L23_001DE5D0;
extern s32 D_L23_001DE5D4;
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E208(s32, s32);
extern void *func_L01_0046CF70(void *, void *, s32, f32);
extern f32 func_0037E2A8(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern s32 func_003CE740(void *, void *, s32, s32, void *);
extern s32 func_003CF790(void *, s32, f32, s32, void *);
extern s32 func_L01_0032FE90_003B9DC8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);
extern void func_L01_00402498(void *, void *);
void func_L23_003BA1C0(Moby_3BB7C8 *m);

void func_L23_003B9DC8(Moby_3BB7C8 *m)
{
    u8 *v = m->vars;
    V4 a;
    V4 b;
    V4 p;
    V4 w;
    s32 i;
    s32 j;
    s32 r1;
    s32 r2;
    s32 r3;
    f32 f;
    Moby_3BB7C8 *h;

    *(u128_t *)&a = m->pos;
    vec_add_ab(&b, &a, v + 0x40);
    if (m->x96 < 5) {
        for (i = 0; i < D_L23_001DE5D4; i++) {
            func_0037E2F0(&p, m->x2C * 0.0833333358169f, m->x2C * 0.333333343267f);
            vec_add_ab(&p, &p, v + 0x40);
            func_003886E8(&p, &p, 0.8f);
            func_L01_0046CF70(&m->pos, &p, func_0037E208(0x19, 0x28), 0.00405555590987f);
        }
    }
    if (m->x96 < 2) {
        for (j = 0; j < D_L23_001DE5D0; j++) {
            p.x = func_00388960(func_0037E2A8()) * func_0037E250(0.0f, 0.333333343267f);
            p.y = func_00388978(func_0037E2A8()) * func_0037E250(0.0f, 0.333333343267f);
            p.z = 0.0f;
            vec_add_ab(&p, &p, v + 0x40);
            func_003886E8(&p, &p, 0.3f);
            qzero(&w);
            w.z = 0.166666671634f;
            p.w = m->x2C;
            w.w = m->x2C + m->x2C;
            r1 = func_0037E208(5, 10);
            r2 = func_0037E208(10, 20);
            r3 = func_0037E208(8, 12);
            func_L01_0045FEC8(&a, &p, &w, 0x60000030, 0x60101010, r1, r2, r3, -1);
        }
    }
    if (func_003CE740(&a, &b, 0, *(s32 *)v, v + 0x10) != 0 || func_003CF790(&b, 0, 0.2f, *(s32 *)v, v + 0x10) != 0) {
        h = D_L23_001E8800.p18;
        if (h == 0 || h->xAA != 0x1B6A) {
            func_L01_0032FE90_003B9DC8((u8 *)&b, 1, 2, 0, 2, 0x14, 0, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                              1, 1, 1, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_003BD360(m);
            return;
        }
    } else {
        m->pos = *(u128_t *)&b;
    }
    m->x96++;
    if (*(s32 *)(v + 4) < D_L23_001DECC0) {
        func_003BD360(m);
    } else {
        func_L01_00402498(func_L23_003BA1C0, m);
    }
}
/* localdecomp:end func_L23_003B9DC8 */
