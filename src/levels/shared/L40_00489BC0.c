#include "common.h"

/* localdecomp:start func_L40_00489BC0 */
/* from func_L03_0043C610 (the story levels' copy), with the multiplayer loops */
typedef int u128_t_00489BC0 __attribute__((mode(TI)));
typedef struct { u8 p0[0x10]; f32 x, y, z; u8 p1c[0x18]; u16 fl34; u8 p36[0x42]; s32 w78; u8 p7c[0x78]; f32 f4, f8; } A_00489BC0;
typedef struct { u8 p0[0x14]; f32 f14, f18; u8 p1c[4]; s32 s20, s24, s28; s16 h2c, h2e; } B_00489BC0;
typedef struct { u8 p0[0x30]; f32 x, y, z; u8 p3c[4]; } E_00489BC0;
extern s32 func_L03_0043C438(void *, s32);
extern s32 func_L39_005B43C8(s32, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_0038D308(void *, void *);
extern void func_L39_005F62A0(s32, s32);
extern void func_L01_004B7FE8(void *, s32, s32, s32);
extern E_00489BC0 *D_L40_00248EFC;
extern s32 D_L40_0024112C;
__asm__(".extern D_L40_0024112C, 4");
extern u8 *D_L40_00248EF4;
__asm__(".extern D_L40_00248EF4, 4");
extern u8 *D_L40_00248EF4_00489BC0;
extern s32 *D_00241120;
extern u8 *D_L40_00248F48[];
extern s32 D_L40_00248F68[];
extern s32 D_L40_00248F04;

void func_L40_00489BC0(A_00489BC0 *a, B_00489BC0 *b, s32 c) {
    s32 moved, diff, k, m, i, j;
    s32 *n;
    u8 r, g, bl;
    E_00489BC0 *e;

    if (b->s20 == 0) {
        k = func_L03_0043C438(a, c);
        if (k != -1) {
            b->s24 = k;
            b->s20 = 1;
        }
        if (b->s20 != 0) {
            a->fl34 |= 0x41;
            b->h2c = 8;
            b->h2e = func_L39_005B43C8(0, 7);
            *(u128_t_00489BC0 *)b = *(u128_t_00489BC0 *)((u8 *)a + 0x10);
            *(u128_t_00489BC0 *)((u8 *)b + 0x10) = *(u128_t_00489BC0 *)((u8 *)a + 0xF0);
            b->s28 = a->w78;
        } else {
            b->s20 = -1;
        }
    } else if (b->s20 != -1) {
        moved = func_0038CF00((u8 *)a + 0x10, b) > 0.0001f;
        moved |= (a->f8 != b->f18 || a->f4 != b->f14);
        diff = a->w78 != b->s28;
        if (moved || diff) {
            if (moved) {
                e = D_L40_00248EFC + b->s24;
                e->x = a->x;
                e->y = a->y;
                e->z = a->z;
                func_0038D308(e, (u8 *)a + 0xF0);
                if (b->h2c == 0) m = 1; else m = (D_L40_0024112C % b->h2c) == b->h2e;
                func_L39_005F62A0(b->s24, m);
            }
            if (diff) {
                bl = ((u8 *)a)[0x7A];
                g = ((u8 *)a)[0x79];
                r = ((u8 *)a)[0x78];
                func_L01_004B7FE8(D_L40_00248EF4 + b->s24 * 32, r, g, bl);
                if (*D_00241120 >= 2) {
                    for (i = 1; i < *D_00241120; i++) {
                        D_L40_00248F04 = D_L40_00248F68[i];
                        func_L01_004B7FE8(D_L40_00248F48[i] + b->s24 * 32, r, g, bl);
                    }
                    D_L40_00248F04 = D_L40_00248F68[0];
                }
            }
            *(u128_t_00489BC0 *)b = *(u128_t_00489BC0 *)((u8 *)a + 0x10);
            *(u128_t_00489BC0 *)((u8 *)b + 0x10) = *(u128_t_00489BC0 *)((u8 *)a + 0xF0);
            b->s28 = a->w78;
        }
    }
    n = D_00241120;
    *(s16 *)(D_L40_00248EF4_00489BC0 + b->s24 * 32 + 0x10) = 0x7F80;
    if (*n >= 2) {
        for (j = 1; j < *n; j++) {
            *(s16 *)(D_L40_00248F48[j] + b->s24 * 32 + 0x10) = 0x7F80;
        }
    }
}
/* localdecomp:end func_L40_00489BC0 */

LINKER_REMNANT("asm/levels", func_L40_00489ED8);
