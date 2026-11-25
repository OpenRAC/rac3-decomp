#include "common.h"

/* NTSC-U counterpart of func_L40_0042CE98. */

/* localdecomp:start func_U_L40_0042C490 */
typedef int u128_0042CE98 __attribute__((mode(TI)));

typedef struct V4_0042CE98 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_0042CE98;

typedef struct S2_0042CE98 {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    s32 f10;
    f32 f14;
    u8 pad18[0x1C - 0x18];
    s32 f1C;
    u8 pad20[0x30 - 0x20];
    V4_0042CE98 f30;
} S2_0042CE98;

typedef struct Moby_0042CE98 {
    u8 pad0[0x10];
    V4_0042CE98 pos;
    u8 state;
    u8 pad21[0x30 - 0x21];
    u8 f30;
    u8 f31;
    u16 f32;
    u8 pad34[0x68 - 0x34];
    S2_0042CE98 *f68;
    u8 pad6C[0xB8 - 0x6C];
    void *fB8;
    u8 padBC[0xF0 - 0xBC];
    f32 fF0;
    f32 fF4;
    f32 fF8;
} Moby_0042CE98;

extern s32 D_L40_00247AA0;
__asm__(".extern D_L40_00247AA0, 4");
extern s16 D_L40_00249B40[] __attribute__((section(".sdata")));
extern s16 D_L40_00249B50[] __attribute__((section(".sdata")));

extern u8 *func_003BCFB0(s32, s32);
extern f32 func_U_L39_005B25C8(void);

void *func_U_L40_0042C490(void *pos, void *parent, s32 a2, void *home, s32 a4, f32 f) {
    Moby_0042CE98 *m;
    S2_0042CE98 *v;
    s32 n;
    s32 i;

    m = (Moby_0042CE98 *)func_003BCFB0(0x1B3A, 0x80);
    if (m != 0) {
        m->f30 = 0xFF;
        m->f32 = 0xFF;
        m->f31 = 1;
        m->state = 0;
        m->fB8 = parent;
        v = m->f68;
        *(u128_0042CE98 *)&v->f30 = *(u128_0042CE98 *)home;
        *(u128_0042CE98 *)&m->pos = *(u128_0042CE98 *)pos;
        n = D_L40_00247AA0;
        v->f1C = a4;
        v->f10 = n;
        v->f14 = 1.0f / n;
        m->fF0 = func_U_L39_005B25C8();
        m->fF4 = func_U_L39_005B25C8();
        m->fF8 = func_U_L39_005B25C8();
        v->f0 = func_U_L39_005B25C8();
        v->f4 = func_U_L39_005B25C8();
        v->f8 = func_U_L39_005B25C8();
        m->fB8 = parent;
        v->fC = f;
        for (i = 0; i < 3; i++) {
            D_L40_00249B40[i] = -1;
            D_L40_00249B50[i] = 0x18;
        }
        m->state = 0;
    }
    return m;
}
/* localdecomp:end func_U_L40_0042C490 */
