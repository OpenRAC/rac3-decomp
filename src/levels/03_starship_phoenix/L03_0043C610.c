#include "common.h"

/* localdecomp:start func_L03_0043C610 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 p0[0x10]; f32 x, y, z; u8 p1c[0x18]; u16 fl34; u8 p36[0x42]; s32 w78; u8 p7c[0x78]; f32 f4, f8; } A_0043C610;
typedef struct { u8 p0[0x14]; f32 f14, f18; u8 p1c[4]; s32 s20, s24, s28; s16 h2c, h2e; } B_0043C610;
typedef struct { u8 p0[0x30]; f32 x, y, z; u8 p3c[4]; } E_0043C610;
extern s32 func_L03_0043C438(void *, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_0038D308(void *, void *);
extern void func_L01_004B3338(s32, s32);
extern void func_L01_004B7FE8(void *, s32, s32, s32);
extern E_0043C610 *D_L03_001E085C; __asm__(".extern D_L03_001E085C, 16");
extern s32 D_001DF4C0_sda; __asm__(".extern D_001DF4C0_sda, 4");
extern u8 *D_001E0854_sda; __asm__(".extern D_001E0854_sda, 4");

void func_L03_0043C610(A_0043C610 *a, B_0043C610 *b, s32 c) {
    s32 moved, diff, k, m;
    E_0043C610 *e;
    if (b->s20 == 0) {
        k = func_L03_0043C438(a, c);
        if (k != -1) {
            b->s24 = k;
            b->s20 = 1;
        }
        if (b->s20 != 0) {
            a->fl34 |= 0x41;
            b->h2c = 8;
            b->h2e = func_00382498(0, 7);
        } else {
            b->s20 = -1;
            return;
        }
    } else {
        if (b->s20 == -1) return;
        moved = func_0038CF00((u8 *)a + 0x10, b) > 0.0001f;
        moved |= (a->f8 != b->f18 || a->f4 != b->f14);
        diff = a->w78 != b->s28;
        if (moved == 0) {
            if (diff == 0) return;
        } else {
            e = D_L03_001E085C + b->s24;
            e->x = a->x;
            e->y = a->y;
            e->z = a->z;
            func_0038D308(e, (u8 *)a + 0xF0);
            if (b->h2c == 0) m = 1; else m = (D_001DF4C0_sda % b->h2c) == b->h2e;
            func_L01_004B3338(b->s24, m);
        }
        if (diff) {
            func_L01_004B7FE8(D_001E0854_sda + b->s24 * 32, ((u8 *)a)[0x78], ((u8 *)a)[0x79], ((u8 *)a)[0x7A]);
        }
    }
    *(u128_t *)b = *(u128_t *)((u8 *)a + 0x10);
    *(u128_t *)((u8 *)b + 0x10) = *(u128_t *)((u8 *)a + 0xF0);
    b->s28 = a->w78;
}
/* localdecomp:end func_L03_0043C610 */
